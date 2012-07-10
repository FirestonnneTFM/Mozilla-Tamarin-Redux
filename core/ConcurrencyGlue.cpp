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
    InterruptableState::InterruptableState()
    {
    }

    void InterruptableState::destroy()
    {
        // no one could be waiting on any record in the list or we wouldn't
        // be in the destroy method (everyone's ref to this state is NULL).
        // if a wait was interrupted there can be some WaitRecords 
        // remaining in the list.  
        while(m_waitList.Count())
        {
            Isolate::WaitRecord* record = m_waitList.Get(0);
            m_waitList.Remove(record);
            mmfx_delete(record);
        }
        m_waitList.Destroy();
    }

    void InterruptableState::notify()
    {
        // get the first WaitRecord in the list and notify it
        // the list is currently protected by the associated mutex 
        // is is possible that no other thread is waiting on this condition
        // as seen with the following example:
        //    mutex.lock();
        //    condition.notify();
        AvmAssert(lockIsHeld() == true);
        if (m_waitList.Count() > 0)
        {
            Isolate::WaitRecord* record = m_waitList.Get(0);
            VMPI_condVarSignal(&record->condVar);
        }
    }

    void InterruptableState::notifyAll()
    {
        // the list is currently protected by the associated mutex
        AvmAssert(lockIsHeld() == true);
        if (m_waitList.Count()) {
            // notify all waiting records in the list
            MMgc::BasicListIterator<Isolate::WaitRecord*> iter(m_waitList);
            Isolate::WaitRecord* record = iter.next();
            while(record)
            {
                VMPI_condVarSignal(&record->condVar);
                record = iter.next();
            }
        }
    }

    Isolate::WaitRecord* InterruptableState::enterWait(Isolate* isolate)
    {
        // update list of waiting threads with this one
        Isolate::WaitRecord* record = mmfx_new(Isolate::WaitRecord());

        // if the record isn't valid we need to return early
        if (!record->isValid) {
            return record;
        }

        AvmAssert(lockIsHeld() == true);
        // this list is protected by the Mutex currently held
        m_waitList.Add(record);
        if (isolate) {
            isolate->setActiveWaitRecord(record);
        }
        return record;
    }

    bool InterruptableState::wait(Isolate::WaitRecord* record, Isolate* isolate, int32_t millis)
    {
        // we loop to allow the debugger to wake us up and get a 
        // call stack then go back to a waiting state
        bool result = false;
        do {
            VMPI_recursiveMutexLock(&record->privateMutex);
            result = avmplus::SafepointHelper_VMPIWait::wait(&record->condVar, &record->privateMutex, millis) == false;
            VMPI_recursiveMutexUnlock(&record->privateMutex);
        }
        while(isolate && isolate->retryActiveWaitRecord());
        return result;
    }

    void InterruptableState::exitWait(Isolate* isolate, Isolate::WaitRecord* record)
    {
        AvmAssert(lockIsHeld() == true);
        m_waitList.Remove(record);
        if (isolate) {
            isolate->setActiveWaitRecord(NULL);
        }
        mmfx_delete(record);
    }

#ifdef DEBUG
    class EnterMutexStateLock
    {
    public:
        EnterMutexStateLock(MutexObject::State* state)
            : m_state(state)
        {
            m_state->m_lockIsHeld = true;
        }

        ~EnterMutexStateLock()
        {
            m_state->m_lockIsHeld = false;
        }
    private:
        MutexObject::State* m_state;
    };
#endif // DEBUG

    MutexObject::State::State()
        : InterruptableState()
        , m_recursion_count(0)
        , m_ownerThreadID(VMPI_nullThread())
#ifdef DEBUG
        , m_lockIsHeld(false)
#endif // DEBUG
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

        SCOPE_LOCK(m_listLock) {
#ifdef DEBUG
            EnterMutexStateLock enter(this);
#endif // DEBUG
            notifyAll();
        }
        return true;
    }

#ifdef DEBUG
    bool MutexObject::State::lockIsHeld()
    {
        return m_lockIsHeld;
    }
#endif // DEBUG

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
        // we continue to try and get the lock until
        // we are terminated or acquire it
        while(!m_state->tryLock()) {
            Isolate* isolate = core()->getIsolate();
            // if we don't get the lock then we have to wait
            Isolate::WaitRecord* record = NULL;
            SCOPE_LOCK(m_state->m_listLock) {
#ifdef DEBUG
                EnterMutexStateLock enter(m_state);
#endif // DEBUG
                record = m_state->enterWait(isolate);
                if (!record->isValid) {
                    toplevel()->throwError(kMutexCannotBeInitialized);
                }
            }
            
            m_state->wait(record, isolate, -1);

            // if we are terminated then unset the active wait record and exit
            // when the state is destroyed it will clean up all current records.
            if ((isolate && isolate->isInterrupted()) || core()->interruptCheckReason(AvmCore::ExternalInterrupt)) {
                isolate->setActiveWaitRecord(NULL);
                break;
            }

            SCOPE_LOCK(m_state->m_listLock) {
#ifdef DEBUG
                EnterMutexStateLock enter(m_state);
#endif // DEBUG
                m_state->exitWait(isolate, record);
            }
        }
    	TELEMETRY_METHOD_NO_THRESHOLD(core()->getTelemetry(),".player.mutex.lock");
    }
    
    void MutexObject::unlock()
    {
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
	
    ScriptObject* MutexObject::cloneNonSlots(ClassClosure* targetClosure, Cloner&) const
    {
        MutexObject* clone = targetClosure->toplevel()->getInternedObject(m_state).staticCast<MutexObject>();
        if (clone == NULL) {
            clone = new (targetClosure->gc(), MMgc::kExact, targetClosure->ivtable()->getExtraSize()) MutexObject(targetClosure->ivtable(), targetClosure->prototypePtr());
            clone->m_state = this->m_state;
        }
        return clone;
    }

    MutexClass::MutexClass(VTable* cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    ConditionObject::ConditionObject(VTable* cvtable, ScriptObject* delegate) 
        : ScriptObject(cvtable, delegate)
    {
    }

    ConditionObject::State::State(MutexObject::State* mutexState)
        : InterruptableState()
        , m_mutexState(mutexState)
    {
    }

#ifdef DEBUG
    bool ConditionObject::State::lockIsHeld()
    {
        return m_mutexState->m_ownerThreadID != VMPI_nullThread();
    }
#endif

    bool ConditionObject::State::wait(int32_t millis, Isolate* isolate, Toplevel* toplevel)
    {
        // mutex is currently locked protecting enterWait
        Isolate::WaitRecord* record = enterWait(isolate);
        if (!record->isValid) {
            toplevel->throwError(kConditionCannotBeInitialized);
        }

        m_mutexState->m_ownerThreadID = VMPI_nullThread();
        // So we own the mutex.
        int64_t saved_recursion_count = m_mutexState->m_recursion_count;
        m_mutexState->m_recursion_count = 0;
        AvmAssert(vmbase::SafepointRecord::hasCurrent());

        // unlock public mutex
        VMPI_recursiveMutexUnlock(&m_mutexState->m_mutex);
        bool result = InterruptableState::wait(record, isolate, millis);
        // if we have been interrupted do not re-acquire the public lock, just bail
        // when we are destroyed we will clean up all current records.
        if (isolate) {
            if (isolate->isInterrupted() || isolate->targetCore()->interruptCheckReason(AvmCore::ExternalInterrupt)) {
                isolate->setActiveWaitRecord(NULL);
                return false;
            }
        }
        // re-acquire the public mutex in a safepoint
        SafepointHelper_VMPIMutex::lock(&m_mutexState->m_mutex);
        m_mutexState->m_ownerThreadID = VMPI_currentThread();
        m_mutexState->m_recursion_count = saved_recursion_count;
        exitWait(isolate, record);

        if (isolate) {
            // if we are terminating then we should release the public mutex
            if (isolate->targetCore()->interruptCheckReason(AvmCore::ExternalInterrupt) || 
                isolate->getAggregate()->queryState(isolate) == Isolate::TERMINATED) 
            {
                VMPI_recursiveMutexUnlock(&m_mutexState->m_mutex);
            }
        }
        return result;
    }

    void ConditionObject::ctor(GCRef<MutexObject> mutex)
    {
        AvmAssert(mutex != NULL);
        m_state = mmfx_new(ConditionObject::State(mutex->m_state));

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
        return m_state->wait(millis, isolate, toplevel());
    }

    ScriptObject* ConditionObject::cloneNonSlots(ClassClosure* targetClosure, Cloner& ) const
    {
        ConditionObject* clone = targetClosure->toplevel()->getInternedObject(m_state).staticCast<ConditionObject>();
        if (clone == NULL) {
            clone = new (targetClosure->gc(), MMgc::kExact, targetClosure->ivtable()->getExtraSize()) ConditionObject(targetClosure->ivtable(), targetClosure->prototypePtr());
            clone->m_state = this->m_state;
        }
        return clone;
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
        InterruptableState::destroy();
        m_mutexState = NULL;
        mmfx_delete(this);
    }


    GCRef<MutexObject> ConditionObject::get_mutex()
    {
        ScriptObject* prev = toplevel()->getInternedObject(m_state->m_mutexState);
        if (prev) {
            return static_cast<MutexObject*>(prev);
        } else {
            MutexClass* cls = toplevel()->builtinClasses()->get_MutexClass();
            MutexObject* mutex = new (gc(), MMgc::kExact, cls->ivtable()->getExtraSize()) MutexObject(cls->ivtable(), cls->prototypePtr());
            mutex->m_state = m_state->m_mutexState;
            toplevel()->internObject(m_state->m_mutexState, mutex);
            return mutex;
        }
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

