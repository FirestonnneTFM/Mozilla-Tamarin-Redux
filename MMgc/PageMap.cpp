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

#include "MMgc.h"
#include "StaticAssert.h"

namespace MMgc
{
    // For now, too much code assumes these are the same.
    MMGC_STATIC_ASSERT( PageMap::kPageSize == GCHeap::kBlockSize );

    namespace PageMap
    {
        static const uintptr_t MAX_UINTPTR = ~uintptr_t(0);

        Uniform::Uniform()
            : memStart(MAX_UINTPTR)
            , memEnd(0)
            , pageMap(NULL)
        {}

        REALLY_INLINE uint8_t& Uniform::IndexToByteRef(uintptr_t index)
        {
            GCAssert(pageMap != NULL);
            return pageMap[index >> 2];
        }

        REALLY_INLINE void Uniform::IndexSet(uintptr_t index, PageType val)
        {
            IndexToByteRef(index) |= (val << IndexToByteShiftAmt(index));
        }

        REALLY_INLINE void Uniform::IndexClear(uintptr_t index)
        {
            IndexToByteRef(index) &= ~(3 << IndexToByteShiftAmt(index));
        }

        REALLY_INLINE void Uniform::AddrSet(uintptr_t addr, PageType val)
        {
            uintptr_t index = AddrToIndex(addr);
            GCAssert(IndexSaneForAddressRange(index));
            IndexSet(index, val);
        }

        REALLY_INLINE void Uniform::AddrClear(uintptr_t addr)
        {
            IndexClear(AddrToIndex(addr));
        }

        REALLY_INLINE
        void Uniform::EnsureCapacity(GCHeap *heap, void *item, uint32_t numPages)
        {
            // Shift logic below used to depend on pageMap byte
            // corresponding to 16k chunk (16k == kPageSize * 8/2);
            // was dependent on kPageSize == 4096 (and on implicit
            // 2-bit payload size).  Probably no longer the case,
            // but this code is about to be removed anyway, so just
            // assert (more as documentation) equivalence for now.
            // See https://bugzilla.mozilla.org/show_bug.cgi?id=581070
            MMGC_STATIC_ASSERT(PageMap::kPageSize == 4096);

            const static int kByteOffsetShift = PageMap::kPageShift + 2;
            const static int kByteOffsetMask = (1 << kByteOffsetShift)-1;

            // (For the benefit of a reader comparing this code to the
            //  pre-refactored version; derived from above kPageSize.)
            MMGC_STATIC_ASSERT(kByteOffsetShift == 14);
            MMGC_STATIC_ASSERT(kByteOffsetMask == 0x3fff);

            uintptr_t addr = (uintptr_t)item;
            size_t shiftAmount=0;
            uint8_t *dst = pageMap;

            // save the current live range in case we need to move/copy
            size_t numBytesToCopy = (memEnd-memStart)>>kByteOffsetShift;

            if(addr < memStart) {
                // round down to nearest 16k boundary, makes shift logic
                // work because it works in bytes, ie 4-page chunks
                addr &= ~kByteOffsetMask;
                // marking earlier pages
                if(memStart != MAX_UINTPTR) {
                    shiftAmount = (memStart - addr) >> kByteOffsetShift;
                 }
                memStart = addr;
            }

            // FIXME: https://bugzilla.mozilla.org/show_bug.cgi?id=588079
            // use pre-shift addr (keep a copy, or just move this code up)
            // FIXME: https://bugzilla.mozilla.org/show_bug.cgi?id=581070
            // double-check +1 here + below; unnecessary extra page allocated?
            if(addr + (numPages+1)*PageMap::kPageSize > memEnd) {
                // marking later pages
                memEnd = addr + (numPages+1)*PageMap::kPageSize;
                // round up to 16k
                memEnd = (memEnd+kByteOffsetMask)&~kByteOffsetMask;
            }

            uint32_t numBlocksNeeded =
                uint32_t(((memEnd-memStart)>>kByteOffsetShift)
                         / GCHeap::kBlockSize
                         + 1);
            if(numBlocksNeeded > heap->Size(pageMap)) {
                dst = (uint8_t*)heap->AllocNoOOM(numBlocksNeeded);
            }

            if(shiftAmount || dst != pageMap) {
                if (pageMap != NULL)
                    VMPI_memmove(dst + shiftAmount, pageMap, numBytesToCopy);
                if ( shiftAmount ) {
                    VMPI_memset(dst, 0, shiftAmount);
                }
                if(dst != pageMap) {
                    if (pageMap != NULL)
                        heap->FreeNoOOM(pageMap);
                    pageMap = dst;
                }
            }
        }

        void Uniform::ExpandSetAll(GCHeap *heap, void *item,
                                   uint32_t numPages, PageType val)
        {
            EnsureCapacity(heap, item, numPages);
            uintptr_t addr = (uintptr_t)item;
            while(numPages--)
            {
                GCAssert(AddrToVal(addr) == 0);
                AddrSet(addr, val);
                GCAssert(AddrToVal(addr) == val);
                addr += GCHeap::kBlockSize;
            }
        }

        void Uniform::ClearAddrs(void *item, uint32_t numpages)
        {
            uintptr_t addr = (uintptr_t) item;

            while(numpages--)
            {
                AddrClear(addr);
                addr += GCHeap::kBlockSize;
            }
        }

    }
}
