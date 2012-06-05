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

    MutexObject::State::State()
        : m_recursion_count(0)
        , m_ownerThreadID(VMPI_nullThread())
    {
        bool success = VMPI_recursiveMutexInit(&m_mutex);
        (void)success; // FIXME test the result
    }

    void MutexObject::State::destroy()
    {
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
        mmfx_delete(this);

    }

    MutexObject::MutexObject(VTable* cvtable, ScriptObject* delegate) 
        : ScriptObject(cvtable, delegate)
        , m_state(NULL)
    {
    }

    void MutexObject::ctor() 
    {
        m_state = mmfx_new(MutexObject::State());
        ScriptObject* prev = toplevel()->lookupInternedObject(m_state, NULL);
        if (prev) {
            AvmAssert(false); 
        } else {
            toplevel()->lookupInternedObject(m_state, this);
        }
    }

    MutexObject::~MutexObject() 
    {
        m_state = NULL;
    }

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
    
    void MutexObject::lock()
    {
        using namespace vmbase;

        if (!this->tryLock()) {
            AvmAssert(SafepointRecord::hasCurrent());
            SafepointHelper_VMPIMutex::lock(&m_state->m_mutex);
        } else {
            // tryLock() succeded and did the bookkeeping.
            return;
        }
        if (m_state->m_recursion_count == 0) {
            AvmAssert(m_state->m_ownerThreadID == VMPI_nullThread());
            m_state->m_ownerThreadID = VMPI_currentThread(); 
        } else {
            AvmAssert(m_state->m_ownerThreadID == VMPI_currentThread());
        }
        m_state->m_recursion_count ++;
    }
    
    bool MutexObject::unlockImpl()
    {
        if (m_state->m_ownerThreadID != VMPI_currentThread())
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
        AvmAssert(m_state->m_recursion_count > 0);
        m_state->m_recursion_count --;

        if (m_state->m_recursion_count == 0) {
            AvmAssert(m_state->m_ownerThreadID == VMPI_currentThread());
            m_state->m_ownerThreadID = VMPI_nullThread(); 
        } 
        VMPI_recursiveMutexUnlock(&m_state->m_mutex); // This one is the one requested by user code.
        return true;
        
    }

    bool MutexObject::tryLock()
    {
        bool result = VMPI_recursiveMutexTryLock(&m_state->m_mutex);

        if (result == true) {
            if (m_state->m_recursion_count == 0) {
                AvmAssert(m_state->m_ownerThreadID == VMPI_nullThread());
                m_state->m_ownerThreadID = VMPI_currentThread(); 
            } else {
                AvmAssert(m_state->m_ownerThreadID == VMPI_currentThread());
            }
            m_state->m_recursion_count ++;
            if (m_state->m_recursion_count == 1)
                m_state->m_ownerThreadID = VMPI_currentThread(); 
        }
        return result;
    }

    ScriptObject* MutexObject::cloneNonSlots(ClassClosure* targetClosure, Cloner&) const
    {
        MutexObject* clone = targetClosure->toplevel()->lookupInternedObject(m_state, NULL).staticCast<MutexObject>();
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
        : m_wait_count(0)
        , m_mutexState(mutexState)
    {
        bool success = VMPI_condVarInit(&m_condVar);
        (void)success; // FIXME test the result
    }

    void ConditionObject::ctor(MutexObject* mutex)
    {
        AvmAssert(mutex != NULL);
        m_state = mmfx_new(ConditionObject::State(mutex->m_state));
        ScriptObject* prev = toplevel()->lookupInternedObject(m_state, NULL);
        if (prev) {
            AvmAssert(false); 
        } else {
            toplevel()->lookupInternedObject(m_state, this);
        }
    }

    bool ConditionObject::notifyImpl()
    {
        if (m_state->m_mutexState->m_ownerThreadID != VMPI_currentThread())
        {
            return false;
        }
        VMPI_condVarSignal(&m_state->m_condVar);
        return true;
    }

    bool ConditionObject::notifyAllImpl()
    {
        // See comments in unlockImpl for correctness of reading m_ownerThreadID
        if (m_state->m_mutexState->m_ownerThreadID != VMPI_currentThread())
        {
            return false;
        }
        VMPI_condVarBroadcast(&m_state->m_condVar);
        return true;
    }

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



    bool ConditionObject::waitImpl(double timeout)
    {
        // See comments in unlockImpl for correctness of reading m_ownerThreadID
        if (m_state->m_mutexState->m_ownerThreadID != VMPI_currentThread())
        {
            return false;
        }
        m_state->m_mutexState->m_ownerThreadID = VMPI_nullThread();
        // So we own the mutex.
        int64_t saved_recursion_count = m_state->m_mutexState->m_recursion_count;
        m_state->m_mutexState->m_recursion_count = 0;
        m_state->m_wait_count ++;
        bool result;
        if (timeout < 0) {
            AvmAssert(timeout == -1); // AS side guarantees this.
        }
        AvmAssert(vmbase::SafepointRecord::hasCurrent());
        int32_t millis = timeout == -1 ? -1 : int32_t(ceil(timeout));
        result = SafepointHelper_VMPIWait::wait(&m_state->m_condVar, &m_state->m_mutexState->m_mutex, millis) == false;
        m_state->m_mutexState->m_ownerThreadID = VMPI_currentThread();
        m_state->m_mutexState->m_recursion_count = saved_recursion_count;
        m_state->m_wait_count --;
        return result;
    }

    ScriptObject* ConditionObject::cloneNonSlots(ClassClosure* targetClosure, Cloner& ) const
    {
        ConditionObject* clone = targetClosure->toplevel()->lookupInternedObject(m_state, NULL).staticCast<ConditionObject>();
        if (clone == NULL) {
            clone = new (targetClosure->gc(), MMgc::kExact, targetClosure->ivtable()->getExtraSize()) ConditionObject(targetClosure->ivtable(), targetClosure->prototypePtr());
            clone->m_state = this->m_state;
        }
        return clone;
    }

    ConditionObject::~ConditionObject()
    {
        m_state = NULL;
    }


    void ConditionObject::State::destroy()
    {
        if (m_wait_count == 0) {
            VMPI_condVarDestroy(&m_condVar);
        } else {
            // We did our best, behavior undefined.
        }
        m_mutexState = NULL;
        mmfx_delete(this);
    }


    MutexObject* ConditionObject::get_mutex()
    {
        ScriptObject* prev = toplevel()->lookupInternedObject(m_state->m_mutexState, NULL);
        if (prev) {
            return static_cast<MutexObject*>(prev);
        } else {
            MutexClass* cls = toplevel()->builtinClasses()->get_MutexClass();
            MutexObject* mutex = new (gc(), MMgc::kExact, cls->ivtable()->getExtraSize()) MutexObject(cls->ivtable(), cls->prototypePtr());
            mutex->m_state = m_state->m_mutexState;
            toplevel()->lookupInternedObject(m_state->m_mutexState, mutex);
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

