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

#ifndef __MMgc__PageMap__
#define __MMgc__PageMap__

#include "StaticAssert.h"

namespace MMgc
{
    namespace PageMap
    {
        // Goal: address-to-payload mapping, where payload is a
        // small series of bits.  For current PageType enum,
        // payloadbits = 2.

        // Note that 'two bits per page' is ingrained deeply in the GC
        // at this point
        //
        // (at one point occurrences of 33333333 appeared elsewhere in
        //  the code, but now that appears only associated with
        //  blocks, not pages)
        enum PageType
        {
            kNonGC = 0,
            kGCAllocPage = 1,
            kGCLargeAllocPageRest = 2,
            kGCLargeAllocPageFirst = 3
        };

        // Question: should we be using word-oriented operations
        // rather than byte-oriented ones?

        // kPageSize is granularity; ie the portion of address space,
        // in bytes, that each 2-bit payload in pagemap covers.
        // (Compare against kBlockSize, the unit of allocation for the
        // pagemap structures themselves.)
        // Short term: keep PageMap::kPageSize == GCHeap::kBlockSize
        // Long term: allow block size to be multiple of page size.
        const static uint32_t kPageSize  = 4096;

        const static uint32_t kPageShift = 12;
        MMGC_STATIC_ASSERT( (1 << kPageShift) == kPageSize );

        // NOTE: the public methods of the Uniform pagemap class are
        // the interface that client code should be coded against;
        // every pagemap implementation must support the public
        // methods provided by the Uniform implementation (and should
        // eschew adding new public methods in release code).

        // Uniform is the original simple (but poorly scaling) implementation
        class Uniform
        {
        public:
            Uniform();

            /** @return lower bound (inclusive) of page map address range. */
            uintptr_t MemStart() const;

            /** @return upper bound (exclusive) in page map address range. */
            uintptr_t MemEnd() const;

            /** @return true iff addr is in domain of page map. */
            bool AddrIsMappable(uintptr_t addr) const;

            /**
             * Destroy method.  Must invoke before destruction.
             * @param heap that was used for allocation via ExpandSetAll.
             */
            void DestroyPageMapVia(GCHeap *heap);

            /** @return value for addr in page map. */
            PageType AddrToVal(uintptr_t addr) const;

            /**
             * Ensures AddrIsMappable for all addrs in [item,item+numpages),
             * mapping each addr to val.
             * @param h heap from which to allocate new internal state.
             * @param item first address of range added; must be page-aligned.
             * @param numpages breadth of address range added to domain, in pages.
             * @param val to associate with each addr in the range.
             */
            void ExpandSetAll(GCHeap *h, void *item, uint32_t numpages, PageType val);

            /** Clears entry for all addrs in [item,item+numpages). */
            void ClearAddrs(void *item, uint32_t numpages);

        private:
            uintptr_t memStart;
            uintptr_t memEnd;

            // Need to extract the byte (via indexing into byte map),
            // shift it so payload is in low bits, and mask out the
            // payload.
            //
            // Generally, idx = f(addr), where f is appropriate
            // subtract-and-shift to convert addr into byte array index
            // into the pageMap.
            //
            // So:
            //   payload = (pageMap[idx >> IdxShift] >> ByteShift) & Mask
            // where
            //
            // PayloadPerByte = 8/payloadbits
            // IdxShift   = log_2(PayloadPerByte)
            //            = 3 - log_2(payloadbits)
            // ByteShift  = (idx & (PayloadPerByte - 1))*payloadbits
            // Mask       = 2^payloadbits - 1
            //
            // For example:
            //
            // Payload
            // Bits   IdxShift  ByteShift       Mask
            // 1      3         (idx & 0x7)*1   0x1  (trivial case)
            // 2      2         (idx & 0x3)*2   0x3  (relevant case for now)
            // 4      1         (idx & 0x1)*4   0xf
            // 8      0         0               0xff (trivial case)

            /** Ensures AddrIsMappable for all addrs in [item,item+numpages).*/
            void EnsureCapacity(GCHeap *heap, void *item, uint32_t numpages);

            /** Associates val with key addr; requires AddrIsMappable(addr).*/
            void AddrSet(uintptr_t addr, PageType val);

            /** Clears entry for addr; requires AddrIsMappable(addr). */
            void AddrClear(uintptr_t addr);

            /**
             * @param addr key for future lookup; assumes AddrIsMappable.
             * @return abstract index suitable for passing to Index methods.
             * Note that EnsureCapacity invocations invalidate these indexes.
             */
            uintptr_t AddrToIndex(uintptr_t addr) const;

            /** @return payload value for idx in page map. */
            PageType  IndexToVal(uintptr_t idx) const;

            /** Modifies payload at idx to map to val. */
            void IndexSet(uintptr_t idx, PageType val);

            /** @param idx : which value to clear in page map. */
            void IndexClear(uintptr_t idx);

            /** @return ByteShift (see notes above). */
            uint32_t IndexToByteShiftAmt(uintptr_t index) const;

            /** @return byte in page map for index (see notes above). */
            uint8_t IndexToByte(uintptr_t index) const;

            /** @return byte ref in page map for index (see notes above). */
            uint8_t& IndexToByteRef(uintptr_t index);

#ifdef DEBUG
            /** @return true if index is reasonable for host address space. */
            static bool IndexSaneForAddressRange(uintptr_t index);
#endif

            uint8_t *pageMap;
        };

    }
}

#endif
