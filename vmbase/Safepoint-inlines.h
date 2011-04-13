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
 * Portions created by the Initial Developer are Copyright (C) 2009
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

namespace vmbase {

    /**
     * Wraps calls to RecursiveMutex::lock with a register flush and safepoint gate
     */
    class SafepointHelper_RecursiveMutex
    {
    private:
        static void lockInSafepointGate(void* stackPointer, void* mutex)
        {
            SafepointGate gate(stackPointer);
            ((RecursiveMutex*) (mutex))->lock();
        }
    public:
        static void lock(RecursiveMutex& mutex)
        {
            VMPI_callWithRegistersSaved(lockInSafepointGate, (void*)&mutex);
        }
    };

    /**
     * Wraps calls to WaitNotifyMonitor::wait with a register flush and safepoint gate
     */
    class SafepointHelper_WaitNotifyMonitor
    {
    private:
        struct TimedWaitRecord
        {
            TimedWaitRecord(WaitNotifyMonitor* monitor, int32_t timeout_millis)
                : monitor(monitor)
                , timeout_millis(timeout_millis)
                , returnVal(false)
            {
            }
            WaitNotifyMonitor* monitor;
            int32_t timeout_millis;
            bool returnVal;
        };

        static void waitInSafepointGate(void* stackPointer, void* monitor)
        {
            SafepointGate gate(stackPointer);
            ((WaitNotifyMonitor*) (monitor))->wait();
        }

        static void timedWaitInSafepointGate(void* stackPointer, void* timedWaitRecord)
        {
            SafepointGate gate(stackPointer);
            TimedWaitRecord* const _timedWaitRecord = (TimedWaitRecord*) (timedWaitRecord);
            _timedWaitRecord->returnVal = _timedWaitRecord->monitor->wait(_timedWaitRecord->timeout_millis);
        }
    public:
        static void wait(WaitNotifyMonitor& monitor)
        {
            VMPI_callWithRegistersSaved(waitInSafepointGate, (void*) &monitor);
        }

        static bool wait(WaitNotifyMonitor& monitor, int32_t timeout_millis)
        {
            TimedWaitRecord timedWaitRecord(&monitor, timeout_millis);
            VMPI_callWithRegistersSaved(timedWaitInSafepointGate, (void*) &timedWaitRecord);
            return timedWaitRecord.returnVal;
        }
    };

    template <BlockingMode BLOCKING_MODE>
    REALLY_INLINE MutexLocker<BLOCKING_MODE>::MutexLocker(RecursiveMutex& mutex)
        : m_mutex(mutex)
    {
        if (BLOCKING_MODE == IMPLICIT_SAFEPOINT) {
            // We do not need an implicit safepoint if the thread
            // acquires the lock without blocking.
            if (!m_mutex.tryLock()) {
                SafepointRecord* const current = SafepointRecord::current();
                if (current && current->m_status == SafepointRecord::SP_UNSAFE) {
                    SafepointHelper_RecursiveMutex::lock(m_mutex);
                } else {
                    AvmAssert(!SafepointRecord::hasCurrent() || SafepointRecord::current()->m_manager->inSafepointTask());
                    m_mutex.lock();
                }
            }
        } else {
            m_mutex.lock();
        }
    }

    template <BlockingMode BLOCKING_MODE>
    REALLY_INLINE MutexLocker<BLOCKING_MODE>::~MutexLocker()
    {
        m_mutex.unlock();
    }

    template <BlockingMode BLOCKING_MODE>
    REALLY_INLINE MonitorLocker<BLOCKING_MODE>::MonitorLocker(WaitNotifyMonitor& monitor)
        : m_monitor(monitor)
    {
        if (BLOCKING_MODE == IMPLICIT_SAFEPOINT) {
            // We do not need an implicit safepoint if the thread
            // acquires the lock without blocking.
            if (!m_monitor.tryLock()) {
                SafepointRecord* const current = SafepointRecord::current();
                if (current && current->m_status == SafepointRecord::SP_UNSAFE) {
                    SafepointHelper_RecursiveMutex::lock(m_monitor);
                } else {
                    AvmAssert(!SafepointRecord::hasCurrent() || SafepointRecord::current()->m_manager->inSafepointTask());
                    m_monitor.lock();
                }
            }
        } else {
            m_monitor.lock();
        }
    }

    template <BlockingMode BLOCKING_MODE>
    REALLY_INLINE MonitorLocker<BLOCKING_MODE>::~MonitorLocker()
    {
        m_monitor.unlock();
    }

    template <BlockingMode BLOCKING_MODE>
    REALLY_INLINE void MonitorLocker<BLOCKING_MODE>::notify()
    {
        m_monitor.notify();
    }

    template <BlockingMode BLOCKING_MODE>
    REALLY_INLINE void MonitorLocker<BLOCKING_MODE>::notifyAll()
    {
        m_monitor.notifyAll();
    }

    template <BlockingMode BLOCKING_MODE>
    void MonitorLocker<BLOCKING_MODE>::wait()
    {
        if (BLOCKING_MODE == IMPLICIT_SAFEPOINT && SafepointRecord::hasCurrent()) {
            SafepointHelper_WaitNotifyMonitor::wait(m_monitor);
        } else {
            // Thread is not safepointable, so just wait on the monitor.
            m_monitor.wait();

        }
    }

    template <BlockingMode BLOCKING_MODE>
    bool MonitorLocker<BLOCKING_MODE>::wait(int32_t timeout_millis)
    {
        if (BLOCKING_MODE == IMPLICIT_SAFEPOINT && SafepointRecord::hasCurrent()) {
            return SafepointHelper_WaitNotifyMonitor::wait(m_monitor, timeout_millis);
        } else {
            // Thread has no current safepoint context, so just wait on the monitor.
            return m_monitor.wait(timeout_millis);
        }
    }

    REALLY_INLINE SafepointGate::SafepointGate(void* stackPointer)
        : m_safepointRecord(SafepointRecord::current())
    {
        AvmAssert(SafepointRecord::current()->m_status == SafepointRecord::SP_UNSAFE);
        // Record the stack region that is safe
        m_safepointRecord->m_safeRegionEnd = stackPointer;
        // If a SafepointTask submitting thread is busy waiting on
        // m_safepointRecord->m_status then we have to fence this thread's stores
        // before the waiting thread thread observes the update.
        MemoryBarrier::readWrite();
        m_safepointRecord->m_status = SafepointRecord::SP_SAFE;
        // We have to fence this too, to ensure the waiting thread sees
        // the update promptly.
        MemoryBarrier::readWrite();
    }

    REALLY_INLINE SafepointGate::~SafepointGate()
    {
        // To make sure that a safepoint task is not running now
        // that we're heading into unsafe code, we block on the
        // lock that serializes safepoint task requests. After this
        // critical section we are assured that no task is running
        // and that no new task will be started until this thread is next
        // safepointed.
        SCOPE_LOCK_NO_SP(m_safepointRecord->m_manager->m_requestMutex) {
            m_safepointRecord->m_status = SafepointRecord::SP_UNSAFE;
        }
    }

    /*static*/ REALLY_INLINE void SafepointGate::gate(void* stackPointer, void*)
    {
        SafepointGate _gate(stackPointer);
    }

    /*static*/ REALLY_INLINE void SafepointGate::gateWithRegistersSaved()
    {
        VMPI_callWithRegistersSaved(SafepointGate::gate, NULL);
    }

    REALLY_INLINE SafepointRecord::SafepointRecord()
        : m_status(SP_UNSAFE)
        , m_safeRegionEnd(NULL)
        , m_stackPrev(NULL)
        , m_managerPrev(NULL)
        , m_managerNext(NULL)
        , m_manager(NULL)
    {
    }

    REALLY_INLINE const void* SafepointRecord::safeRegionEnd() const
    {
        AvmAssert(m_manager->inSafepointTask());
        return m_safeRegionEnd;
    }

    REALLY_INLINE SafepointManager* SafepointRecord::manager() const
    {
        return m_manager;
    }

    REALLY_INLINE /*static*/bool SafepointRecord::hasCurrent()
    {
        return m_current.get() != NULL;
    }

    REALLY_INLINE /*static*/SafepointRecord* SafepointRecord::current()
    {
        return m_current.get();
    }

    REALLY_INLINE /*static*/void SafepointRecord::setCurrent(SafepointRecord* record)
    {
        m_current.set(record);
    }

    REALLY_INLINE SafepointManager::RecordIterator::RecordIterator(SafepointManager& manager)
        : m_next(manager.m_records)
    {
    }

    REALLY_INLINE SafepointManager::RecordIterator::~RecordIterator()
    {
    }

    REALLY_INLINE const SafepointRecord* SafepointManager::RecordIterator::next()
    {
        SafepointRecord* next = m_next;
        if (m_next) {
            m_next = m_next->m_managerNext;
        }
        return next;
    }

    REALLY_INLINE bool SafepointManager::inSafepointTask()
    {
        return m_requester == VMPI_currentThread();
    }

    REALLY_INLINE bool SafepointManager::hasRequest()
    {
        // Benign race. If we miss an update to m_requester
        // then we just have to wait longer until we reach the next safepoint.
        return m_requester != (vmpi_thread_t) 0;
    }

} // namespace vmbase
