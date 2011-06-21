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
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
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

#include "vmbase.h"

#ifdef VMCFG_SAFEPOINTS

namespace vmbase {

// The number of spins a safepoint-task requesting thread will busy-wait
// until yielding. (Only applicable on MP machines)
#define SAFEPOINT_SPINS 128

    VMThreadLocal<SafepointRecord*> SafepointRecord::m_current;

    SafepointRecord::~SafepointRecord()
    {
        assert(m_status == SP_UNSAFE && m_manager == NULL);
    }

    SafepointManager::SafepointManager()
        : m_records(NULL)
        , m_requester((vmpi_thread_t) 0)
        , m_hardwareConcurrency(VMPI_processorQtyAtBoot())
    {
    }

    SafepointManager::~SafepointManager()
    {
        assert(m_records == NULL);
    }

    void SafepointManager::requestSafepointTask(SafepointTask& task)
    {
        assert(SafepointRecord::hasCurrent());
        assert(SafepointRecord::current()->m_manager == this);
        assert(!inSafepointTask());

        // Serialize dispatch of safepoint tasks.
        SCOPE_LOCK_SP(m_requestMutex) {
            SafepointRecord::current()->m_status = SafepointRecord::SP_SAFE;
            // Threads polling this SafepointManager will pass through a
            // SafepointGate when they see m_requester as non-null.
            m_requester = VMPI_currentThread();
            // The current (requesting) thread will busy-wait until it sees all
            // SafepointRecords managed by this SafepointManager as SP_SAFE.
            const SafepointRecord* safepointRecord = m_records;
            if (m_hardwareConcurrency > 1) {
                // MP-machine spin-wait
                while (safepointRecord) {
                    int spinCount = 0;
                    while (safepointRecord->m_status == SafepointRecord::SP_UNSAFE) {
                        if (++spinCount == SAFEPOINT_SPINS) {
                            VMPI_threadYield();
                            spinCount = 0;
                        }
                        VMPI_spinloopPause();
                    }
                    safepointRecord = safepointRecord->m_managerNext;
                }
            } else {
                // UP-machine spin-wait
                while (safepointRecord) {
                    while (safepointRecord->m_status == SafepointRecord::SP_UNSAFE) {
                        VMPI_threadYield();
                    }
                    safepointRecord = safepointRecord->m_managerNext;
                }
            }
            // Run the task, now that all threads are safepointed
            task.run();
            // Cleanup.
            // The safepointed threads that trapped into a SafepointGate are blocked on
            // m_requestMutex, so they will be released after the current thread leaves
            // this critical section.
            SafepointRecord::current()->m_status = SafepointRecord::SP_UNSAFE;
            m_requester = (vmpi_thread_t) 0;
        }
    }

    void SafepointManager::enter(SafepointRecord* record)
    {
        assert(record->m_manager == NULL);
        SafepointRecord* stackPrev = SafepointRecord::current();
        if (stackPrev) {
            // This is a nested entry. Make the previous
            // stack region safe up to the new SafepointRecord.
            stackPrev->m_safeRegionEnd = record;
            MemoryBarrier::readWrite();
            stackPrev->m_status = SafepointRecord::SP_SAFE;
            record->m_stackPrev = stackPrev;
        }

        // We do not need a implicit safepoint at this lock as the
        // current thread is safe in the context of the new SafepointRecord
        // (and the previous one, if we set it to SP_SAFE above).
        SCOPE_LOCK_NO_SP(m_requestMutex) {
            record->m_managerNext = m_records;
            if (m_records != NULL) {
                m_records->m_managerPrev = record;
            }
            m_records = record;
            record->m_manager = this;
        }
        SafepointRecord::setCurrent(record);
    }

    void SafepointManager::leave(SafepointRecord* record)
    {
        assert(record->m_manager == this);
        SafepointRecord* const stackPrev = record->m_stackPrev;
        // Remove the SafepointRecord from this SafepointManager.
        SCOPE_LOCK_SP(m_requestMutex) {
            if (m_records == record) {
                m_records = m_records->m_managerNext;
            } else {
                record->m_managerPrev->m_managerNext = record->m_managerNext;
            }
            if (record->m_managerNext) {
                record->m_managerNext->m_managerPrev = record->m_managerPrev;
            }
            record->m_manager = NULL;
        }

        SafepointRecord::setCurrent(stackPrev);
        if (stackPrev) {
            // We're unwinding into the previous SafepointRecord, so
            // we have to block until no safepoint task is ongoing.
            SCOPE_LOCK_NO_SP(stackPrev->m_manager->m_requestMutex) {
                stackPrev->m_status = SafepointRecord::SP_UNSAFE;
            }
        }
    }
}

#endif // VMCFG_SAFEPOINTS
