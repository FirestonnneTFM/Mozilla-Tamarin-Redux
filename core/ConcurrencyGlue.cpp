/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

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
                record->returnVal = false;
            }
            DEBUG_STATE(("thread %d is trying to wake from safepoint\n", VMPI_currentThread()));

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
    // MutexObject
    //

    MutexObject::State::State()
        : FixedHeapRCObject()
        , m_recursionCount(0)
        , m_ownerThreadID(VMPI_nullThread())
        , m_lockWaitListHead(NULL)
        , m_lockWaitListTail(NULL)
    {
        m_isValid = VMPI_recursiveMutexInit(&m_mutex);
    }

    void MutexObject::State::destroy()
    {
        if (m_isValid) {
#ifdef DEBUG
            AvmAssert(m_recursionCount == 0);
            AvmAssert(VMPI_recursiveMutexTryLock(&m_mutex) == true);
            VMPI_recursiveMutexUnlock(&m_mutex);
#endif // DEBUG
            VMPI_recursiveMutexDestroy(&m_mutex);
            DEBUG_STATE(("Mutex(%d) destroyed\n", VMPI_currentThread(), m_interruptibleState.gid));
        }
        mmfx_delete(this);
    }

    void MutexObject::State::lock(Toplevel* toplevel) {
        Isolate* isolate = toplevel->core()->getIsolate();
        if (isolate) {
            Isolate::InterruptibleState::Enter state(&m_interruptibleState, isolate);
            AvmAssert(m_interruptibleState.getMonitor().isLockedByCurrentThread() == true);
            if ((m_lockWaitListHead != NULL) || (VMPI_recursiveMutexTryLock(&m_mutex) == false)) {
                LockWaitRecord record;
                // put the record at the end of the list of lock wait records
                if (m_lockWaitListHead == NULL) {
                    m_lockWaitListHead = &record;
                }
                else {
                    m_lockWaitListTail->next = &record;
                }
                m_lockWaitListTail = &record;

                // we loop here on each wake if we are 
                // not the first thread waiting on the lock
                do {
                    state.wait();
                    // if we are terminated then unset the active wait record and exit
                    // when the state is destroyed it will clean up all current records.
                    if (state.interrupted) {
                        // walk through the list and remove this record from it
                        LockWaitRecord* cur = m_lockWaitListHead;
                        LockWaitRecord* prev = NULL;
                        do {
                            if (cur == &record) {
                                if (prev == NULL) {
                                    m_lockWaitListHead = cur->next;
                                } 
                                else {
                                    prev->next = cur->next;
                                }

                                if (cur->next == NULL) {
                                    m_lockWaitListTail = prev;
                                }
                                
                                goto throw_terminated_exception;
                            } 
                            prev = cur;
                            cur = cur->next;
                        } while(cur);
                        
                        AvmAssert(0); // we should be found in the list!
                        goto throw_terminated_exception;
                    }
                    // must wait again if wait record is not at the head of
                    // the list or the mutex is still owned by another worker.
                } while(m_lockWaitListHead != &record || VMPI_recursiveMutexTryLock(&m_mutex) == false);
                // current waiter now has the lock, remove it from the wait list
                m_lockWaitListHead = record.next;
                if (m_lockWaitListHead == NULL) {
                    m_lockWaitListTail = NULL;
                }
            }
            lockAcquired();
        }
        return;

throw_terminated_exception:
        // because we should not long jump with a InterruptibleState::Enter on the stack
        // we need to destroy the RAII object before throwing
        isolate->getAggregate()->throwWorkerTerminatedException(toplevel);
    }

    bool MutexObject::State::tryLock()
    {
        bool result = false;
        if (m_interruptibleState.hasWaiters() == false) 
        {
            DEBUG_STATE(("thread %d calling Mutex(%d).tryLock()\n", VMPI_currentThread(), m_interruptibleState.gid));
            result = VMPI_recursiveMutexTryLock(&m_mutex);
            if (result) {
                lockAcquired();
            }
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
        DEBUG_STATE(("thread %d unlocking Mutex(%d)\n", VMPI_currentThread(), m_interruptibleState.gid));
        // Ok so we own the lock.
        AvmAssert(m_recursionCount > 0);
        m_recursionCount--;

        if (m_recursionCount == 0) {
            m_ownerThreadID = VMPI_nullThread(); 
        } 

        // we need to unlock the mutex *first* otherwise any waking thread
        // will try the lock and go back to waiting even though they should
        // have acquired the lock
        VMPI_recursiveMutexUnlock(&m_mutex); 
        m_interruptibleState.notifyAll();
        return true;
    }

    MutexObject::MutexObject(VTable* cvtable, ScriptObject* delegate) 
        : ScriptObject(cvtable, delegate)
        , m_state(NULL)
    {
    }

    // There are two ways that a MutexObject can be created 
    //  (1) directly from ActionScript - e.g. var mutex:Mutex = new Mutex();
    //  (2) from native code as a result of deserialization
    // The ctor() method was created to be called only in the first case where 
    // ActionScript is constructing the object directly.
    // The second case occurs when a Mutex is passed to another GC address space
    // either using a MessageChannelObject or the WorkerObject.setSharedProperty
    // and WorkerObject.getSharedProperty methods.  When using either of these
    // two mechanisms the Mutex is serialized on a per-toplevel basis.
    // Each toplevel contains a hash (see Toplevel::internObject) of the 
    // "backing state" of the MutexObject this hash is used to ensure that
    // the "highlander" principle is adhered to (there can be only one!), ensuring
    // that sending the same ActionScript object back and forth between GC address
    // space returns the same object every time.
    // Example:
    //    var mutex:Mutex = new Mutex();
    //    worker.setSharedProperty("foo", mutex) === worker.getSharedProperty("foo") // always true
    //
    void MutexObject::ctor() 
    {
        m_state = mmfx_new(MutexObject::State());
        if (!m_state->m_isValid || (core()->getIsolate() == NULL)) {
            toplevel()->throwError(kMutexCannotBeInitialized);
        }

        AvmAssert(toplevel()->getInternedObject(m_state) == NULL);
        toplevel()->internObject(m_state, this);
    }

    MutexObject::~MutexObject() 
    {
        // if we hold the lock we should unlock
        bool cont = m_state->unlock();
        while(m_state->m_recursionCount && cont)
        {
            cont = m_state->unlock();
        };
        m_state = NULL;
    }
  
    void MutexObject::lock()
    {
        DEBUG_STATE(("thread %d calling Mutex(%d).lock()\n", VMPI_currentThread(), m_state->m_interruptibleState.gid));
        // we continue to try and get the lock until
        // we are terminated or acquire it
        m_state->lock(toplevel());
    	TELEMETRY_METHOD_NO_THRESHOLD(core()->getTelemetry(),".player.mutex.lock");
    }
    
    void MutexObject::unlock()
    {
        DEBUG_STATE(("thread %d calling Mutex(%d).unlock()\n", VMPI_currentThread(), m_state->m_interruptibleState.gid));
        if (!m_state->unlock()) {
            toplevel()->illegalOperationErrorClass()->throwError(kMutextNotLocked);
        }
    }

    bool MutexObject::tryLock()
    {
    	TELEMETRY_METHOD_NO_THRESHOLD(core()->getTelemetry(),".player.mutex.trylock");
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
	
    //
    // MutexClass
    //

    MutexClass::MutexClass(VTable* cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    bool MutexClass::get_isSupported()
    {
        return core()->getIsolate() != NULL;
    }

    //
    // ConditionObject
    //

    ConditionObject::ConditionObject(VTable* cvtable, ScriptObject* delegate) 
        : ScriptObject(cvtable, delegate)
        , m_mutex(NULL)
        , m_state(NULL)
    {
    }

    ConditionObject::State::State(MutexObject::State* mutexState)
        : FixedHeapRCObject()
        , m_mutexState(mutexState)
    {
    }

    void ConditionObject::State::destroy()
    {
        m_mutexState = NULL;
        mmfx_delete(this);
    }

    bool ConditionObject::State::wait(int32_t millis, Isolate* isolate, Toplevel* toplevel)
    {
        volatile bool result = false;
        if (isolate) {
            AvmAssert(m_mutexState->m_ownerThreadID != VMPI_nullThread());
            // protected by mutex
            m_mutexState->m_ownerThreadID = VMPI_nullThread();
            int64_t saved_recursionCount = m_mutexState->m_recursionCount;
            m_mutexState->m_recursionCount = 0;
            {
                Isolate::InterruptibleState::Enter state(&m_interruptibleState, isolate);
                AvmAssert(m_interruptibleState.getMonitor().isLockedByCurrentThread() == true);
                DEBUG_STATE(("thread %d releasing Mutex(%d)\n", VMPI_currentThread(), m_mutexState->m_interruptibleState.gid));
                // unlock the mutex before we notify any other threads otherwise
                // they will immediately go back into a waiting state.
                VMPI_recursiveMutexUnlock(&m_mutexState->m_mutex);
                m_mutexState->m_interruptibleState.notifyAll();
                
                state.wait(millis);

                result = state.result;
                // if we have been interrupted do not re-acquire the public lock, just bail
                if (state.interrupted) {
                    DEBUG_STATE(("thread %d Condition(%d).wait was interrupted!\n", VMPI_currentThread(), m_interruptibleState.gid));
                    goto throw_terminated_exception;
                }
            }

            TRY(toplevel->core(), kCatchAction_Rethrow)
            {
                // re-acquire the public mutex 
                m_mutexState->lock(toplevel);
                DEBUG_STATE(("thread %d Condition(%d) re-acquired Mutex(%d)\n", VMPI_currentThread(), m_interruptibleState.gid, m_mutexState->m_interruptibleState.gid));
                m_mutexState->m_recursionCount = saved_recursionCount;
            }
            CATCH(Exception* e)
            {
                m_mutexState->m_recursionCount = saved_recursionCount;
                toplevel->core()->throwException(e);
            }
            END_TRY;
            END_CATCH;
        }
        return result;

throw_terminated_exception:
        // because we should not long jump with a InterruptibleState::Enter on the stack
        // we need to destroy the RAII object before throwing
        isolate->getAggregate()->throwWorkerTerminatedException(toplevel);
        AvmAssert(false);
        return false;
    }

    // There are two ways that a ConditionObject can be created 
    //  (1) directly from ActionScript - e.g. var condition:Condition= new Condition(new Mutex());
    //  (2) from native code as a result of deserialization
    // The ctor() method was created to be called only in the first case where 
    // ActionScript is constructing the object directly.
    // The second case occurs when a Condition is passed to another GC address space
    // either using a MessageChannelObject or the WorkerObject.setSharedProperty
    // and WorkerObject.getSharedProperty methods.  When using either of these
    // two mechanisms the Condition and its associated mutex is serialized on a per-toplevel basis.
    // Each toplevel contains a hash (see Toplevel::internObject) of the 
    // "backing state" of the ConditionObject, this hash is used to ensure that
    // the "highlander" principle is adhered to (there can be only one!), ensuring
    // that sending the same ActionScript object back and forth between GC address
    // space returns the same object every time.
    // Example:
    //    var mutex:Mutex = new Mutex()
    //    var cond:Condition = new Condition(mutex);
    //    worker.setSharedProperty("foo", cond) === worker.getSharedProperty("foo"); // always true
    //    worker.getSharedProperty("foo").mutex === mutex; // always true
    //
    void ConditionObject::ctor(GCRef<MutexObject> mutex)
    {
        if (mutex == NULL) {
            toplevel()->throwArgumentError(kNullPointerError, core()->newStringLatin1("mutex"));
        }

        m_mutex = mutex;
        m_state = mmfx_new(ConditionObject::State(mutex->m_state));

        AvmAssert(toplevel()->getInternedObject(m_state) == NULL);  
        toplevel()->internObject(m_state, this);
    }

    void ConditionObject::notify()
    {
        if (m_state->m_mutexState->m_ownerThreadID != VMPI_currentThread())
        {
            DEBUG_STATE(("**ERROR*** thread %d calling Condition(%d).notify but doesn't own mutex!\n", VMPI_currentThread(), m_state->m_interruptibleState.gid));
            toplevel()->throwIllegalOperationError(kConditionCannotNotify);
        }

        DEBUG_STATE(("thread %d calling Condition(%d).notify\n", VMPI_currentThread(), m_state->m_interruptibleState.gid));
        m_state->m_interruptibleState.notify();
    }

    void ConditionObject::notifyAll()
    {
        // See comments in unlock for correctness of reading m_ownerThreadID
        if (m_state->m_mutexState->m_ownerThreadID != VMPI_currentThread())
        {
            DEBUG_STATE(("**ERROR*** thread %d calling Condition(%d).notifyAll but doesn't own mutex!\n", VMPI_currentThread(), m_state->m_interruptibleState.gid));
            toplevel()->throwIllegalOperationError(kConditionCannotNotifyAll);
        }
        DEBUG_STATE(("thread %d calling Condition(%d).notifyAll()\n", VMPI_currentThread(), m_state->m_interruptibleState.gid));
        m_state->m_interruptibleState.notifyAll();
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
	
    bool ConditionObject::wait(double timeout)
    {
        if (timeout < 0 && timeout != -1) {
            toplevel()->throwArgumentError(kConditionInvalidTimeout);
        }
        // See comments in unlock() for correctness of reading m_ownerThreadID
        if (m_state->m_mutexState->m_ownerThreadID != VMPI_currentThread()) {
            toplevel()->throwIllegalOperationError(kConditionCannotWait);
        }
		TELEMETRY_METHOD_NO_THRESHOLD(core()->getTelemetry(),".player.condition.wait");
 		

        int32_t millis = timeout == -1 ? -1 : (int32_t)MathUtils::ceil(timeout); 
        DEBUG_STATE(("thread %d calling Condition(%d).wait(%d)\n", VMPI_currentThread(), m_state->m_interruptibleState.gid, millis));
        return m_state->wait(millis, core()->getIsolate(), toplevel());
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
        m_mutex = NULL;
    }

    //
    // when a condition object is serialized using a mechanism like 
    // setSharedProperty or getSharedProperty the condition will not 
    // have a Mutex object serialized with it. this means that we need
    // to lookup the associated mutex if we do not have one. this can
    // only occur with serialization as the actionscript constructor
    // ensures that a valid Mutex has been associated.
    // 
    GCRef<MutexObject> ConditionObject::get_mutex()
    {
        if (m_mutex == NULL)
        {
            // if the same mutex is being referenced by multiple conditions we may 
            // already have one in this toplevel, check for that one first, before
            // creating a new mutex object.
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

    //
    // ConditionClass
    //

    ConditionClass::ConditionClass(VTable* cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    bool ConditionClass::get_isSupported()
    {
        return core()->getIsolate() != NULL;
    }

    //
    // ConcurrenyMemory
    //

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

