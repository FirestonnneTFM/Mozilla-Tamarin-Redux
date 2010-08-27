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
 *   leon.sha@sun.com
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

#ifndef __MMgc_GCPolicyManager_inlines__
#define __MMgc_GCPolicyManager_inlines__

namespace MMgc
{
    // GCPolicyManager
    // A number of the inline functions for this class are currently in GC.cpp

#ifdef MMGC_POLICY_PROFILING
    REALLY_INLINE void GCPolicyManager::signalWriteBarrierWork(int stage)
    {
        GCAssert(ARRAY_SIZE(barrierStageLastCollection) > size_t(stage));
        barrierStageLastCollection[stage]++;
    }
#endif

#ifdef MMGC_REFCOUNT_PROFILING
    REALLY_INLINE void GCPolicyManager::signalIncrementRef()
    {
        incrementRefLastCollection++;
    }

    REALLY_INLINE void GCPolicyManager::signalDecrementRef()
    {
        decrementRefLastCollection++;
    }

    REALLY_INLINE void GCPolicyManager::signalZCTAdd(bool initial, uint32_t population)
    {
        addZCTLastCollection++;
        if (initial)
            addZCTInitialTotal++;
        if (population > zctPeakSize)
            zctPeakSize = population;
    }

    REALLY_INLINE void GCPolicyManager::signalZCTRemove(bool final)
    {
        removeZCTLastCollection++;
        if (final)
            removeZCTFinalTotal++;
    }
#endif

#ifdef MMGC_POINTINESS_PROFILING
    REALLY_INLINE void GCPolicyManager::signalDemographics(size_t candidate_words, size_t could_be_pointer, size_t actually_is_pointer)
    {
        candidateWords += candidate_words;
        couldBePointer += could_be_pointer;
        actuallyIsPointer += actually_is_pointer;
    }
#endif
    
    REALLY_INLINE bool GCPolicyManager::signalAllocWork(size_t nbytes)
    {
#ifdef MMGC_POLICY_PROFILING
        objectsAllocated++;
        bytesAllocated += nbytes;
#endif
        remainingMinorAllocationBudget -= int32_t(nbytes);

        // Important to use < 0 not <= 0: in greedy mode we set the budget to
        // exactly the object size we're about to allocate.  Using <= 0 would
        // cause the allocation never to succeed.
        return remainingMinorAllocationBudget < 0;
    }

    REALLY_INLINE void GCPolicyManager::signalMarkWork(size_t nbytes)
    {
        objectsScannedLastCollection++;
        bytesScannedLastCollection += uint32_t(nbytes);
    }
    
    REALLY_INLINE void GCPolicyManager::signalFreeWork(size_t nbytes)
    {
        remainingMinorAllocationBudget += int32_t(nbytes);
    }
    
    REALLY_INLINE uint32_t GCPolicyManager::lowerLimitCollectionThreshold() {
        return collectionThreshold;
    }
    
    REALLY_INLINE uint64_t GCPolicyManager::now() {
        return VMPI_getPerformanceCounter();
    }
}

#endif // __MMgc_GCPolicyManager_inlines__
