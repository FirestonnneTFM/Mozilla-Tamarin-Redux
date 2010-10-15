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

#ifndef __GCAlloc_inlines__
#define __GCAlloc_inlines__

// Inline functions for GCAlloc, GCAlloc::GCBlock, and GCAllocIterator

namespace MMgc
{
    REALLY_INLINE GCBlockHeader* GetBlockHeader(const void* item)
    {
        return (GCBlockHeader*)(uintptr_t(item) & GCHeap::kBlockMask);
    }

    /*static*/
    REALLY_INLINE GCAlloc::GCBlock *GCAlloc::GetBlock(const void *item)
    {
        return (GCBlock*)GetBlockHeader(item);
    }

    /*static*/
    REALLY_INLINE GCAlloc::GCBlock* GCAlloc::Next(GCAlloc::GCBlock* b)
    {
        return (GCBlock*)b->next;
    }

#ifndef MMGC_FASTBITS
    /*static*/
    REALLY_INLINE gcbits_t& GCAlloc::GetGCBits(const void* realptr)
    {
        GCBlock *block = GetBlock(realptr);
        return block->bits[GetBitsIndex(block, realptr)];
    }
#endif

    /*static*/
    REALLY_INLINE void *GCAlloc::FindBeginning(const void *item)
    {
        GCBlock *block = GetBlock(item);
        GCAssertMsg(item >= block->items, "Can't call FindBeginning on something pointing to GC header");
        return block->items + block->size * GetObjectIndex(block, item);
    }

    REALLY_INLINE void GCAlloc::SetBlockHasWeakRef(const void *userptr)
    {
        GetBlock(userptr)->slowFlags |= kFlagWeakRefs;
    }

    REALLY_INLINE void GCAlloc::AddToFreeList(GCBlock *b)
    {
        GCAssert(!IsOnEitherList(b) && !b->needsSweeping());
        b->prevFree = NULL;
        b->nextFree = m_firstFree;
        if (m_firstFree) {
            GCAssert(m_firstFree->prevFree == 0 && m_firstFree != b);
            m_firstFree->prevFree = b;
        }
        m_firstFree = b;
    }

    REALLY_INLINE void GCAlloc::RemoveFromFreeList(GCBlock *b)
    {
        GCAssert(m_firstFree == b || b->prevFree != NULL);
        if ( m_firstFree == b )
            m_firstFree = b->nextFree;
        else
            b->prevFree->nextFree = b->nextFree;

        if (b->nextFree)
            b->nextFree->prevFree = b->prevFree;
        b->nextFree = b->prevFree = NULL;
    }

    REALLY_INLINE void GCAlloc::AddToSweepList(GCBlock *b)
    {
        GCAssert(!IsOnEitherList(b) && !b->needsSweeping());
        b->prevFree = NULL;
        b->nextFree = m_needsSweeping;
        if (m_needsSweeping) {
            GCAssert(m_needsSweeping->prevFree == 0);
            m_needsSweeping->prevFree = b;
        }
        m_needsSweeping = b;
        b->setNeedsSweeping(kFlagNeedsSweeping);
    }

    REALLY_INLINE void GCAlloc::RemoveFromSweepList(GCBlock *b)
    {
        GCAssert(m_needsSweeping == b || b->prevFree != NULL);
        if ( m_needsSweeping == b )
            m_needsSweeping = b->nextFree;
        else
            b->prevFree->nextFree = b->nextFree;

        if (b->nextFree)
            b->nextFree->prevFree = b->prevFree;
        b->setNeedsSweeping(0);
        b->nextFree = b->prevFree = NULL;
    }

    REALLY_INLINE uint32_t GCAlloc::GetObjectIndex(const GCBlock *block, const void *item)
    {
        GCAlloc* alloc = (GCAlloc*)block->alloc;
        uint32_t index = (uint32_t)((((char*) item - block->items) * alloc->multiple) >> alloc->shift);
 #ifdef _DEBUG
        GCAssert(((char*) item - block->items) / block->size == index);
 #endif
        return index;
    }           

#ifdef MMGC_FASTBITS

    /*static*/
    REALLY_INLINE uint32_t GCAlloc::GetBitsIndex(const GCBlock *block, const void *item)
    {
        uint32_t index = (uintptr_t(item) & 0xFFF) >> block->bitsShift;
#ifdef _DEBUG
        GCAssert(index < uint32_t(((GCAlloc*)block->alloc)->m_numBitmapBytes));
#endif
        return index;
    }
    
#else // MMGC_FASTBITS
    
    /*static*/
    REALLY_INLINE uint32_t GCAlloc::GetBitsIndex(const GCBlock *block, const void *item)
    {
        return GetObjectIndex(block, item);
    }

#endif // MMGC_FASTBITS

    REALLY_INLINE int GCAlloc::GCBlock::GetCount() const
    {
        return ((GCAlloc*)alloc)->m_itemsPerBlock;
    }

    REALLY_INLINE int GCAlloc::GCBlock::needsSweeping()
    {
        return slowFlags & kFlagNeedsSweeping;
    }

    REALLY_INLINE void GCAlloc::GCBlock::setNeedsSweeping(int v)
    {
        GCAssert(v == 0 || v == kFlagNeedsSweeping);
        slowFlags = (uint8_t)((slowFlags & ~kFlagNeedsSweeping) | v);
    }

    REALLY_INLINE GCAllocIterator::GCAllocIterator(MMgc::GCAlloc* alloc)
        : alloc(alloc)
        , block(alloc->m_firstBlock)
        , idx(0)
        , limit(alloc->m_itemsPerBlock)
        , size(alloc->m_itemSize)
    {
    }

    REALLY_INLINE bool GCAllocIterator::GetNextMarkedObject(void*& out_ptr, uint32_t& out_size)
    {
        for (;;) {
            if (idx == limit) {
                idx = 0;
                block = GCAlloc::Next(block);
            }
            if (block == NULL)
                return false;
            uint32_t i = idx++;
            if ((GC::GetGCBits(block->items + i*size) & (kMark|kQueued)) == kMark) {
                out_ptr = GetUserPointer(block->items + i*size);
                out_size = size - (uint32_t)DebugSize();
                return true;
            }
        }
    }
}

#endif /* __GCAlloc_inlines__ */
