/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "avmplus.h"

namespace avmplus {

#define DEBUG_CONDITION_MUTEX
#if defined(DEBUG) && defined(DEBUG_CONDITION_MUTEX)
    #define DEBUG_STATE(_x_) do { AvmLog _x_; } while(0)
#else
    #define DEBUG_STATE(_x_) do { } while(0)
#endif

    class SafepointHelper_VMPIMutex
    {
    private:
        static void lockInSafepointGate(void* stackPointer, void* mutex)
        {
            vmbase::SafepointGate gate(stackPointer);
            VMPI_recursiveMutexLock((vmpi_mutex_t*)mutex);
        }
    public:
        static void lock(vmpi_mutex_t* mutex)
        {
            VMPI_callWithRegistersSaved(lockInSafepointGate, (void*)mutex);
        }
    };

	/**
     * Wraps calls to VMPI_condVarWait with a register flush and safepoint gate
     */
    class SafepointHelper_VMPIWait
    {
    private:
        struct WaitRecord
        {
            WaitRecord(vmpi_condvar_t* condVar, vmpi_mutex_t* mutex, int32_t timeout_millis)
                : condVar(condVar)
                , mutex(mutex)
                , timeout_millis(timeout_millis)
                , returnVal(false)
            {
            }
            vmpi_condvar_t* condVar;
            vmpi_mutex_t* mutex;
            int32_t timeout_millis;
            bool returnVal;
        };


        static void timedWaitInSafepointGate(void* stackPointer, void* arg)
        {
            vmbase::SafepointGate gate(stackPointer);
            WaitRecord* const record = (WaitRecord*)arg;
            if (record->timeout_millis != -1) {
                record->returnVal = VMPI_condVarTimedWait(record->condVar, record->mutex, record->timeout_millis);
            } else {
                VMPI_condVarWait(record->condVar, record->mutex);
                record->returnVal = true;
            }

        }
    public:

        static bool wait(vmpi_condvar_t* condVar, vmpi_mutex_t* mutex, int32_t timeout_millis)
        {
            WaitRecord record(condVar, mutex, timeout_millis);
            VMPI_callWithRegistersSaved(timedWaitInSafepointGate, (void*) &record);
            return record.returnVal;
        }
    };

    //
    // InterruptableState 
    //
#ifdef DEBUG
    int InterruptableState::globalId = 0;
#endif // DEBUG


    InterruptableState::EnterWait::EnterWait(Isolate* isolate, InterruptableState* state)
        : interrupted(false)
    {
        Isolate::WaitRecord record;
        SCOPE_LOCK(state->m_lock) {
            state->m_waitList.Add(&record);
            DEBUG_STATE(("thread %d added to (%d) list\n", VMPI_currentThread(), state->gid));
            failed = !record.isValid;

            /*
            if (m_state->m_waitList) {
                m_record->next = m_state->m_waitList;
                m_state->m_waitList->next = m_record;
            }
            else {
                m_state->m_waitList = m_record;
            }
            */

            if (!failed && isolate) {
                isolate->setActiveWaitRecord(&record);
            }
        }
             
        if (!failed) {
            // we loop to allow the debugger to wake us up and get a 
            // call stack then go back to a waiting state
            if (record.isValid) {
                do {
                    VMPI_recursiveMutexLock(&record.privateMutex);
                    if (!record.notified) {
                        DEBUG_STATE(("thread %d sleeping\n", VMPI_currentThread(), state->gid));
                        avmplus::SafepointHelper_VMPIWait::wait(&record.condVar, &record.privateMutex, -1);
                    }
                    VMPI_recursiveMutexUnlock(&record.privateMutex);
                }
                while(isolate && isolate->retryActiveWaitRecord());
            }
        }

        DEBUG_STATE(("thread %d now awake\n", VMPI_currentThread()));
        interrupted = isolate ? isolate->isInterrupted() : false;
        SCOPE_LOCK(state->m_lock) {
            state->m_waitList.Remove(&record);
            if (isolate) {
                isolate->setActiveWaitRecord(NULL);
            }
        }
    }

    InterruptableState::InterruptableState()
        //: m_waitList(NULL)
    {
#ifdef DEBUG
        gid = ++globalId;
#endif // DEBUG
        notified = false;
    }

    void InterruptableState::destroy()
    {
        // no one could be waiting on any record in the list or we wouldn't
        // be in the destroy method (everyone's ref to this state is NULL).
        AvmAssert(m_waitList.Count() == 0);
        m_waitList.Destroy();
    }

    void InterruptableState::notify()
    {
        // get the first WaitRecord in the list and notify it
        // the list is currently protected by the associated mutex 
        // it is possible that no other thread is waiting on this condition
        // as seen with the following example:
        //    mutex.lock();
        //    condition.notify();
        SCOPE_LOCK(m_lock) {
            DEBUG_STATE(("thread %d is calling (%d) state->notify with %d waiting threads\n", VMPI_currentThread(), gid, m_waitList.Count()));
            if (m_waitList.Count()) {
                Isolate::WaitRecord* record = m_waitList.Get(0);
                VMPI_recursiveMutexLock(&record->privateMutex);
                record->notified = true;
                VMPI_recursiveMutexUnlock(&record->privateMutex);
                VMPI_condVarSignal(&record->condVar);
            }
            else {
                notified = true;
            }
        }
    }

    void InterruptableState::notifyAll()
    {
        // the list is currently protected by the associated mutex
        SCOPE_LOCK(m_lock) {
            DEBUG_STATE(("thread %d is calling (%d) state->notifyAll with %d waiting threads\n", VMPI_currentThread(), gid, m_waitList.Count()));
            if (m_waitList.Count()) {
                // notify all waiting records in the list
                MMgc::BasicListIterator<Isolate::WaitRecord*> iter(m_waitList);
                Isolate::WaitRecord* record = iter.next();
                while(record) {
                    AvmAssert(record->isValid == true);
                    VMPI_recursiveMutexLock(&record->privateMutex); 
                    record->notified = true;
                    DEBUG_STATE(("thread %d is notifying thread %d\n", VMPI_currentThread(), record->threadID));
                    VMPI_condVarSignal(&record->condVar);
                    VMPI_recursiveMutexUnlock(&record->privateMutex);
                    record = iter.next();
                }
            }
            else {
                notified = true;
            }
        }
    }

    MutexObject::State::EnterWait::EnterWait(Isolate* isolate, State* state)
        : interrupted(false)
        , result(false)
    {
        Isolate::WaitRecord record;
        SCOPE_LOCK(state->m_lock) {
            if (state->notified && state->m_waitList.Count() == 0) {
                record.notified = true;
                state->notified = false;
            }

            state->m_waitList.Add(&record);
            DEBUG_STATE(("thread %d added to (%d) list\n", VMPI_currentThread(), state->gid));
            // if the record isn't valid we need to return early
            failed = !record.isValid;

            /*
            if (m_state->m_waitList) {
                m_record->next = m_state->m_waitList;
                m_state->m_waitList->next = m_record;
            }
            else {
                m_state->m_waitList = m_record;
            }
            */
            if (!failed && isolate) {
                isolate->setActiveWaitRecord(&record);
            }
        }
             
        if (!failed) {
            // we loop to allow the debugger to wake us up and get a 
            // call stack then go back to a waiting state
            result = false;
            if (record.isValid) {
                do {
                    VMPI_recursiveMutexLock(&record.privateMutex);
                    if (!record.notified) {
                        DEBUG_STATE(("thread %d sleeping\n", VMPI_currentThread(), state->gid));
                        result = avmplus::SafepointHelper_VMPIWait::wait(&record.condVar, &record.privateMutex, -1) == false;
                    }
                    VMPI_recursiveMutexUnlock(&record.privateMutex);
                }
                while(isolate && isolate->retryActiveWaitRecord());
            }
        }

        interrupted = isolate ? isolate->isInterrupted() : false;
        DEBUG_STATE(("thread %d now awake\n", VMPI_currentThread()));
        SCOPE_LOCK(state->m_lock) {
            state->m_waitList.Remove(&record);
            if (isolate) {
                isolate->setActiveWaitRecord(NULL);
            }
        }
    }

    MutexObject::State::State()
        : InterruptableState()
        , m_recursion_count(0)
        , m_ownerThreadID(VMPI_nullThread())
    {
        m_isValid = VMPI_recursiveMutexInit(&m_mutex);
    }

    void MutexObject::State::destroy()
    {
        InterruptableState::destroy();
        if (m_isValid) {
            bool success = VMPI_recursiveMutexTryLock(&m_mutex);
            if (success) {
                // Only access m_recursion_count if we know it's locked.
                int64_t saved_recursion_count = m_recursion_count;
                VMPI_recursiveMutexUnlock(&m_mutex);
                while (saved_recursion_count > 0) {
                    saved_recursion_count = --m_recursion_count;
                    VMPI_recursiveMutexUnlock(&m_mutex);
                }
                VMPI_recursiveMutexDestroy(&m_mutex);
                DEBUG_STATE(("thread %d acquired lock (%d) during destroy\n", VMPI_currentThread(), gid));
            } else {
                // It's locked by a thread but not reachable through GC objecs.
                // The native mutex will be orphaned, but otherwise the memory will be released.
            }
        }
        mmfx_delete(this);
    }

    bool MutexObject::State::tryLock()
    {
        bool result = VMPI_recursiveMutexTryLock(&m_mutex);
        if (result == true) {
            DEBUG_STATE(("thread %d acquired (%d) lock\n", VMPI_currentThread(), gid));
            if (m_recursion_count == 0) {
                AvmAssert(m_ownerThreadID == VMPI_nullThread());
                m_ownerThreadID = VMPI_currentThread(); 
            } else {
                AvmAssert(m_ownerThreadID == VMPI_currentThread());
            }
            m_recursion_count ++;
        }
        return result;
    }

    bool MutexObject::State::unlock()
    {
        DEBUG_STATE(("thread %d calling unlock (%d)\n", VMPI_currentThread(), gid));
        if (m_ownerThreadID != VMPI_currentThread())
        {
            // Non-fenced read of the m_ownerThreadID field possibly outside of a critical section.
            // Writes to m_ownerThreadID occur only in a critical section.
            // If the current thread really holds the lock, then m_ownerThreadID is set accurately.
            // If the current thread doesn't hold the lock, it can't see its own thread id in m_ownerThreadID, because
            // either it never held the lock and never wrote it, or it had held the lock, set 
            // the thread id to null and unlocked (fenced). Only the current thread writes the current
            // thread id to m_ownerThreadID.
            return false;
        }
        // Ok so we own the lock.
        AvmAssert(m_recursion_count > 0);
        m_recursion_count --;

        if (m_recursion_count == 0) {
            AvmAssert(m_ownerThreadID == VMPI_currentThread());
            m_ownerThreadID = VMPI_nullThread(); 
        } 

        VMPI_recursiveMutexUnlock(&m_mutex); // This one is the one requested by user code.
        notifyAll();
        return true;
    }

    MutexObject::MutexObject(VTable* cvtable, ScriptObject* delegate) 
        : ScriptObject(cvtable, delegate)
        , m_state(NULL)
    {
    }

    void MutexObject::ctor() 
    {
        m_state = mmfx_new(MutexObject::State());
        if (!m_state->m_isValid) {
            toplevel()->throwError(kMutexCannotBeInitialized);
        }

        ScriptObject* prev = toplevel()->getInternedObject(m_state);
        if (prev) {
            AvmAssert(false); 
        } else {
            toplevel()->internObject(m_state, this);
        }
    }

    MutexObject::~MutexObject() 
    {
        // if we hold the lock we should unlock
        bool cont = m_state->unlock();
        while(m_state->m_recursion_count && cont)
        {
            cont = m_state->unlock();
        };
        m_state = NULL;
    }
  
    void MutexObject::lock()
    {
        DEBUG_STATE(("thread %d calling Mutex(%d).lock()\n", VMPI_currentThread(), m_state->gid));
        // we continue to try and get the lock until
        // we are terminated or acquire it
        while(!m_state->tryLock()) {
            DEBUG_STATE(("thread %d lock (%d) not acquired\n", VMPI_currentThread(), m_state->gid));
            // if we don't get the lock then we have to wait
            State::EnterWait wait(core()->getIsolate(), m_state);
            if (wait.failed) {
                toplevel()->throwError(kMutexCannotBeInitialized);
            }
            // if we are terminated then unset the active wait record and exit
            // when the state is destroyed it will clean up all current records.
            if (wait.interrupted || core()->interruptCheckReason(AvmCore::ExternalInterrupt)) {
                break;
            }
            DEBUG_STATE(("thread %d attempting lock (%d) again\n", VMPI_currentThread(), m_state->gid));
        }
    	TELEMETRY_METHOD_NO_THRESHOLD(core()->getTelemetry(),".player.mutex.lock");
    }
    
    void MutexObject::unlock()
    {
        DEBUG_STATE(("thread %d is calling Mutex(%d).unlock()\n", VMPI_currentThread(), m_state->gid));
        if (!m_state->unlock()) {
            toplevel()->illegalOperationErrorClass()->throwError(kMutextNotLocked);
        }
    }

    bool MutexObject::tryLock()
    {
        return m_state->tryLock(); 
    }
	
	ChannelItem* MutexObject::makeChannelItem()
	{
        class MutexChannelItem: public ChannelItem
        {
        public:
            MutexChannelItem(MutexObject::State* value)
            {
                m_value = value;
            }

            Atom getAtom(Toplevel* toplevel) const
            {
		        MutexObject* mutexObj = toplevel->getInternedObject(m_value).staticCast<MutexObject>();
		        if (mutexObj == NULL) 
		        {
			        MutexClass* mutexClass = toplevel->builtinClasses()->get_MutexClass();
			        mutexObj = new (toplevel->gc(), MMgc::kExact, mutexClass->ivtable()->getExtraSize()) MutexObject(mutexClass->ivtable(), mutexClass->prototypePtr());
			        // will increment the refcount of m_state
			        mutexObj->m_state = m_value;
			        toplevel->internObject(m_value, mutexObj);
		        }
		        return mutexObj->toAtom();
            }

        private:
            FixedHeapRef<MutexObject::State> m_value;
        };

        MutexChannelItem* item = mmfx_new(MutexChannelItem(m_state));
		return item;
	}
	
    MutexClass::MutexClass(VTable* cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    ConditionObject::ConditionObject(VTable* cvtable, ScriptObject* delegate) 
        : ScriptObject(cvtable, delegate)
        , m_mutex(NULL)
        , m_state(NULL)
    {
    }

    ConditionObject::State::EnterWait::EnterWait(Isolate* isolate, State* state, int32_t millis, MutexObject::State* mutexState, vmpi_mutex_t* mutex)
        : interrupted(false)
        , result(false)
    {
        Isolate::WaitRecord record;
        SCOPE_LOCK(state->m_lock) {
            if (state->notified && state->m_waitList.Count() == 0) {
                record.notified = true;
                state->notified = false;
            }

            state->m_waitList.Add(&record);
            DEBUG_STATE(("thread %d added to (%d) list\n", VMPI_currentThread(), state->gid));
            // if the record isn't valid we need to return early
            failed = !record.isValid;

            /*
            if (m_state->m_waitList) {
                m_record->next = m_state->m_waitList;
                m_state->m_waitList->next = m_record;
            }
            else {
                m_state->m_waitList = m_record;
            }
            */

            if (!failed) {
                if (isolate) {
                    isolate->setActiveWaitRecord(&record);
                }

                VMPI_recursiveMutexUnlock(mutex);
                DEBUG_STATE(("thread %d releasing (%d) lock\n", VMPI_currentThread(), mutexState->gid));
                mutexState->notifyAll();
            }
        }
             
        if (!failed) {
            // we loop to allow the debugger to wake us up and get a 
            // call stack then go back to a waiting state
            result = false;
            if (record.isValid) {
                do {
                    VMPI_recursiveMutexLock(&record.privateMutex);
                    if (!record.notified) {
                        DEBUG_STATE(("thread %d sleeping for %d millis (%d)\n", VMPI_currentThread(), millis, state->gid));
                        result = avmplus::SafepointHelper_VMPIWait::wait(&record.condVar, &record.privateMutex, millis) == false;
                    }
                    VMPI_recursiveMutexUnlock(&record.privateMutex);
                }
                while(isolate && isolate->retryActiveWaitRecord());
            }
        }

        interrupted = isolate ? isolate->isInterrupted() : false;
        DEBUG_STATE(("thread %d now awake\n", VMPI_currentThread()));
        SCOPE_LOCK(state->m_lock) {
            state->m_waitList.Remove(&record);
            if (isolate) {
                isolate->setActiveWaitRecord(NULL);
            }
        }
    }

    ConditionObject::State::State(MutexObject::State* mutexState)
        : InterruptableState()
        , m_mutexState(mutexState)
    {
    }

    bool ConditionObject::State::wait(int32_t millis, Isolate* isolate, Toplevel* toplevel)
    {
        // we own the mutex.
        m_mutexState->m_ownerThreadID = VMPI_nullThread();
        int64_t saved_recursion_count = m_mutexState->m_recursion_count;
        m_mutexState->m_recursion_count = 0;

        AvmAssert(vmbase::SafepointRecord::hasCurrent());

        EnterWait wait(isolate, this, millis, m_mutexState, &m_mutexState->m_mutex);

        if (wait.failed) {
            // restore state before throwing
            m_mutexState->m_ownerThreadID = VMPI_currentThread();
            m_mutexState->m_recursion_count = saved_recursion_count;
            VMPI_recursiveMutexLock(&m_mutexState->m_mutex);
            toplevel->throwError(kConditionCannotBeInitialized);
        }

        // if we have been interrupted do not re-acquire the public lock, just bail
        if (wait.interrupted || 
           (isolate && isolate->targetCore()->interruptCheckReason(AvmCore::ExternalInterrupt))) 
        {
            return false;
        }
        // re-acquire the public mutex in a safepoint
        SafepointHelper_VMPIMutex::lock(&m_mutexState->m_mutex);
        m_mutexState->m_ownerThreadID = VMPI_currentThread();
        m_mutexState->m_recursion_count = saved_recursion_count;

        if (isolate) {
            // if we are terminating then we should release the public mutex
            if (isolate->targetCore()->interruptCheckReason(AvmCore::ExternalInterrupt) || 
                isolate->getAggregate()->queryState(isolate) == Isolate::TERMINATED) 
            {
                VMPI_recursiveMutexUnlock(&m_mutexState->m_mutex);
            }
        }
        return wait.result;
    }

    void ConditionObject::ctor(GCRef<MutexObject> mutex)
    {
        AvmAssert(mutex != NULL);
        m_state = mmfx_new(ConditionObject::State(mutex->m_state));

        m_mutex = mutex;
        ScriptObject* prev = toplevel()->getInternedObject(m_state);
        if (prev) {
            AvmAssert(false); 
        } else {
            toplevel()->internObject(m_state, this);
        }
    }

    bool ConditionObject::notifyImpl()
    {
        if (m_state->m_mutexState->m_ownerThreadID != VMPI_currentThread())
        {
            return false;
        }

        DEBUG_STATE(("thread %d calling Condition(%d).notify\n", VMPI_currentThread(), m_state->gid));
        m_state->notify();
        return true;
    }

    bool ConditionObject::notifyAllImpl()
    {
        // See comments in unlockImpl for correctness of reading m_ownerThreadID
        if (m_state->m_mutexState->m_ownerThreadID != VMPI_currentThread())
        {
            return false;
        }
        DEBUG_STATE(("thread %d calling Condition(%d).notifyAll\n", VMPI_currentThread(), m_state->gid));
        m_state->notifyAll();
        return true;
    }

	ChannelItem* ConditionObject::makeChannelItem()
	{
        class ConditionChannelItem: public ChannelItem
        {
        public:
            ConditionChannelItem(ConditionObject::State* value)
            {
                m_value = value;
            }

            Atom getAtom(Toplevel* toplevel) const
            {
		        ConditionObject* conditionObj  =  toplevel->getInternedObject(m_value).staticCast<ConditionObject>();
		        if (conditionObj == NULL) {
			        ConditionClass* conditionClass = toplevel->builtinClasses()->get_ConditionClass();
			        conditionObj = new (toplevel->gc(), MMgc::kExact, conditionClass->ivtable()->getExtraSize()) ConditionObject(conditionClass->ivtable(), conditionClass->prototypePtr());
			        // will increment the refcount of m_state
			        conditionObj->m_state = m_value;
			        toplevel->internObject(m_value, conditionObj);
		        }
		        return conditionObj->toAtom();		
            }

        private:
            FixedHeapRef<ConditionObject::State> m_value;
        };

        ConditionChannelItem* item = mmfx_new(ConditionChannelItem(m_state));
        return item;
	}
	
    bool ConditionObject::waitImpl(double timeout)
    {
        Isolate* isolate = core()->getIsolate();
        // this is a blocking call and we could already be interrupted return early!
        if ((isolate && isolate->isInterrupted()) || 
            core()->interruptCheckReason(AvmCore::ExternalInterrupt)) {
            return false;
        }
        // See comments in unlockImpl for correctness of reading m_ownerThreadID
        if (m_state->m_mutexState->m_ownerThreadID != VMPI_currentThread())
        {
            toplevel()->throwIllegalOperationError(kConditionCannotWait);
        }
		TELEMETRY_METHOD_NO_THRESHOLD(core()->getTelemetry(),".player.condition.wait");
 		
        AvmAssert(timeout == -1 || timeout >= 0);
        int32_t millis = timeout == -1 ? -1 : int32_t(timeout); // as code calls Math.ceil
        DEBUG_STATE(("thread %d calling Condition(%d).wait(%d)\n", VMPI_currentThread(), m_state->gid, millis));
        return m_state->wait(millis, isolate, toplevel());
    }

    ConditionObject::~ConditionObject()
    {
        // we are going away which cannot happen if we are
        // waiting on this condition, we are releasing our
        // hold on the underlying condition, if we are the 
        // only reference, it will be destroyed, and its
        // reference to the associated mutex will also be given
        // up.
        m_state = NULL;
    }


    void ConditionObject::State::destroy()
    {
        m_mutexState = NULL;
        mmfx_delete(this);
    }


    GCRef<MutexObject> ConditionObject::get_mutex()
    {
        if (m_mutex == NULL)
        {
            ScriptObject* prev = toplevel()->getInternedObject(m_state->m_mutexState);
            if (prev) {
                m_mutex = static_cast<MutexObject*>(prev);
            } else {
                MutexClass* cls = toplevel()->builtinClasses()->get_MutexClass();
                MutexObject* mutex = new (gc(), MMgc::kExact, cls->ivtable()->getExtraSize()) MutexObject(cls->ivtable(), cls->prototypePtr());
                mutex->m_state = m_state->m_mutexState;
                toplevel()->internObject(m_state->m_mutexState, mutex);
                m_mutex = mutex;
            }
        }
        return m_mutex;
    }


    ConditionClass::ConditionClass(VTable* cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }


  int32_t ConcurrentMemory::casi32(ScriptObject *obj, int32_t addr, int32_t expectedVal, int32_t newVal)
  {
    const Toplevel *toplevel = obj->toplevel();

    if(addr % sizeof(int32_t))
      toplevel->throwRangeError(kInvalidRangeError);

    const AvmCore *core = obj->core();
    const CodeContext *cc = core->codeContext();
    const DomainEnv *domainEnv = cc->domainEnv();
    uint32_t domainMemSize = domainEnv->globalMemorySize();
    
    if(uint32_t(addr) > (domainMemSize - sizeof(int32_t)))
      toplevel->throwRangeError(kInvalidRangeError);

    int32_t *p = (int32_t *)(domainEnv->globalMemoryBase() + uint32_t(addr));

    return vmbase::AtomicOps::compareAndSwap32WithBarrierPrev(expectedVal, newVal, p);
  }

  void ConcurrentMemory::mfence(ScriptObject *obj)
  {
    (void)obj;
    vmbase::MemoryBarrier::readWrite();
  }

}

