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

#ifndef __MMgc__PageMap_inlines__
#define __MMgc__PageMap_inlines__

namespace MMgc
{
    namespace PageMap
    {
        REALLY_INLINE uintptr_t Uniform::MemStart() const
        {
            return memStart;
        }

        REALLY_INLINE uintptr_t Uniform::MemEnd() const
        {
            return memEnd;
        }

        REALLY_INLINE bool Uniform::AddrIsMappable(uintptr_t addr) const
        {
            return addr >= memStart && addr < memEnd;
        }

        REALLY_INLINE void Uniform::DestroyPageMapVia(GCHeap *heap)
        {
            if (pageMap != NULL)
                heap->Free(pageMap);
            pageMap = NULL;
        }

        REALLY_INLINE uintptr_t Uniform::AddrToIndex(uintptr_t addr) const
        {
            return (addr - memStart) >> kPageShift;
        }

        REALLY_INLINE uint8_t Uniform::IndexToByte(uintptr_t index) const
        {
            GCAssert(pageMap != NULL);
            return pageMap[index >> 2];
        }

        REALLY_INLINE uint32_t Uniform::IndexToByteShiftAmt(uintptr_t index) const
        {
            // shift amount to determine position in the byte
            // (times 2 b/c 2 bits per page)
            return (index & 0x3) * 2;
        }

        REALLY_INLINE PageType Uniform::IndexToVal(uintptr_t index) const
        {
            // 3 ... is mask for 2 bits, shifted to the left by shiftAmount
            // finally shift back by shift amount to get the value 0, 1 or 3
            // (further explanation in Uniform class definition.)
            //return (pageMap[addr >> 2] & (3<<shiftAmount)) >> shiftAmount;
            uint8_t v = (IndexToByte(index) >> IndexToByteShiftAmt(index)) & 3;
            return PageType(v);
        }

#if DEBUG
        REALLY_INLINE bool Uniform::IndexSaneForAddressRange(uintptr_t index)
        {
            // The index is amount to shift the address to compute
            // corresponding index of its payload in pageMap.

            // The index value includes 2 bits to extract a 2-bit
            // payload from a byte, so lookup eventually shifts index
            // down by 2 to find offset into the pageMap bytemap.

            // Doing index >> 2 leaves (maxaddrbits - kPageShift - 2)
            // bits usable for the lookup into the bytemap, where
            // maxaddrbits is the maximal number of bits of a *usable*
            // address (e.g. 48 on AMD64, 32 on 32-bit architectures).

            // orig. address falls within: 0..2^maxaddrbits
            // indexes (before >> 2)   in: 0..2^(maxaddrbits - kPageShift)
            // byteoffset (after >> 2) in: 0..2^(maxaddrbits - kPageShift - 2)
            //                         ==  0..2^(maxaddrbits - 2) / kPageSize
#ifdef MMGC_64BIT
            static const uintptr_t maxaddr_div_4 = uintptr_t(1) << 46;
#else
            static const uintptr_t maxaddr_div_4 = uintptr_t(1) << 30;
#endif
            (void)maxaddr_div_4;
            return (index >> 2) < (maxaddr_div_4 / kPageSize);
        }
#endif

        REALLY_INLINE PageType Uniform::AddrToVal(uintptr_t addr) const
        {
            uintptr_t index = AddrToIndex(addr);
            GCAssert(IndexSaneForAddressRange(index));
            return IndexToVal(index);
        }
    }
}

#endif
