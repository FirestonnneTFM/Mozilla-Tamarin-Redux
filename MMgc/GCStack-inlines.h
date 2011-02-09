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

#ifndef __GCStack_inlines__
#define __GCStack_inlines__

namespace MMgc
{
    
    REALLY_INLINE GCWorkItem::GCWorkItem(const void *p, uint32_t s, GCWorkItemType workItemType)
        : ptr(p)
#ifdef MMGC_INTERIOR_PTRS
        , _size(s | uint32_t(kHasInteriorPtrs) | uint32_t(workItemType))
#else
        , _size(s | uint32_t(workItemType))
#endif
    {
        GCAssert((s & 3) == 0);
        // The size is computed on demand for GC objects by GCWorkItem::GetSize(), so
        // should always be passed as zero here.  Long term the size may not be stored
        // in the mark item at all as it will only be needed for conservatively
        // traced objects and for very accurate accounting.
        GCAssert(workItemType != GCWorkItem::kGCObject || s == 0);
        GCAssert(((uintptr_t)p & 3) == 0);
        GCAssert(s != kSentinel1Size && s != kSentinel2Size);
#ifdef _DEBUG
        if (IsGCItem()) {
            GCAssert(GC::GetGC(p)->FindBeginningGuarded(p) == p);
        }
#endif
    }
    
    REALLY_INLINE GCWorkItem::GCWorkItem(const void *p, GCSentinel1ItemType type)
        : iptr(uintptr_t(p) | type),
        _size(kSentinel1Size)
    {
        GCAssert(((uintptr_t)p & 3) == 0);
    }
    
    REALLY_INLINE GCWorkItem::GCWorkItem(const void *p, GCSentinel2ItemType type)
        : iptr(uintptr_t(p) | type),
        _size(kSentinel2Size)
    {
        GCAssert(((uintptr_t)p & 3) == 0);
    }
    
    REALLY_INLINE void GCWorkItem::Clear()
    {
        iptr = kDeadItem;
        // use sentinel so we're skipped off the fast path in MarkItem
        _size = kSentinel1Size;
    }
    
    REALLY_INLINE uint32_t GCWorkItem::GetSize() const
    {
        return uint32_t(IsGCItem() ? GC::Size(ptr) : _size & ~3);
    }
    
    REALLY_INLINE const void* GCWorkItem::Ptr() const
    {
        return ptr;
    }

    REALLY_INLINE void* GCWorkItem::GetEnd() const
    {
        return (void*)(iptr + GetSize());
    }
    
    REALLY_INLINE uint32_t GCWorkItem::IsGCItem() const
    {
        return _size & uint32_t(kGCObject);
    }
    
    REALLY_INLINE uint32_t GCWorkItem::HasInteriorPtrs() const
    {
        return _size & uint32_t(kHasInteriorPtrs);
    }
    
    REALLY_INLINE bool GCWorkItem::IsNull() const
    {
        return ptr == NULL;
    }
    
    REALLY_INLINE bool GCWorkItem::IsClear() const
    {
        return iptr == kDeadItem;
    }
    
    REALLY_INLINE bool GCWorkItem::IsSentinel1Item() const
    {
        return (_size & ~3) == kSentinel1Size;
    }
    
    REALLY_INLINE bool GCWorkItem::IsSentinel2Item() const
    {
        return (_size & ~3) == kSentinel2Size; 
    }
    
    REALLY_INLINE GCWorkItem::GCSentinel1ItemType GCWorkItem::GetSentinel1Type() const
    {
        return (GCSentinel1ItemType)(iptr & 3);
    }
    
    REALLY_INLINE GCWorkItem::GCSentinel2ItemType GCWorkItem::GetSentinel2Type() const
    {
        return (GCSentinel2ItemType)(iptr & 3);
    }
    
    REALLY_INLINE void *GCWorkItem::GetSentinelPointer() const
    {
        return (void*) (iptr & ~3);
    }
    
    REALLY_INLINE bool GCMarkStack::Push(GCWorkItem item)
    {
        GCAssert(!item.IsNull());
        if (m_top == m_limit)
            if (!PushSegment())
                return false;
        GCAssert(m_top < m_limit);
        *m_top++ = item;
#ifdef MMGC_MARKSTACK_DEPTH
        uint32_t depth = Count();
        if (depth > m_maxDepth)
            m_maxDepth = depth;
#endif
        GCAssert(Invariants());
        return true;
    }

    REALLY_INLINE GCWorkItem GCMarkStack::Pop()
    {
        GCAssert(m_top > m_base);
        GCWorkItem t = *--m_top;
        GCAssert(!t.IsNull());
#ifdef _DEBUG
        VMPI_memset(m_top, 0, sizeof(GCWorkItem));
#endif
        if (m_top == m_base)
            if (m_topSegment->m_prev != NULL)
                PopSegment();
        GCAssert(Invariants());
        return t;
    }

    REALLY_INLINE GCWorkItem *GCMarkStack::Peek()
    {
        GCAssert(m_top > m_base);
        return m_top-1;
    }

    REALLY_INLINE bool GCMarkStack::IsEmpty()
    {
        // See Invariants(): m_top == m_base only when there is no older segment
        // and the current segment is empty.
        return m_top == m_base;
    }

    REALLY_INLINE uint32_t GCMarkStack::Count()
    {
        return uint32_t(m_top - m_base) + m_hiddenCount;
    }

    REALLY_INLINE uint32_t GCMarkStack::ElementsPerSegment()
    {
        return kMarkStackItems;
    }

    REALLY_INLINE uint32_t GCMarkStack::EntirelyFullSegments()
    {
        return Count() / kMarkStackItems;
    }

#ifdef MMGC_MARKSTACK_DEPTH
    REALLY_INLINE uint32_t GCMarkStack::MaxCount()
    {
        return m_maxDepth;
    }
#endif
}

#endif /* __GCStack_inlines__ */
