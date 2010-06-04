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

#include "MMgc.h"

//#define TESTING_MARKSTACK
#define MARKSTACK_ALLOWANCE  1

namespace MMgc
{
#ifdef TESTING_MARKSTACK
    static int markstack_allowance = 2*MARKSTACK_ALLOWANCE;     // Two stacks!
#endif

    static inline void* AllocStackSegment(bool mustSucceed)
    {
#ifdef TESTING_MARKSTACK
        if (markstack_allowance == 0)
            return NULL;
        --markstack_allowance;
#endif
        if (mustSucceed)
            return GCHeap::GetGCHeap()->Alloc(1, GCHeap::flags_Alloc);
        else
            return GCHeap::GetGCHeap()->AllocNoOOM(1, GCHeap::flags_Alloc | GCHeap::kCanFail);
    }

    static inline void FreeStackSegment(void* p)
    {
#ifdef TESTING_MARKSTACK
        ++markstack_allowance;
#endif
        GCHeap::GetGCHeap()->FreeNoOOM(p);
    }

    GCMarkStack::GCMarkStack()
        : m_base(NULL)
        , m_top(NULL)
        , m_limit(NULL)
        , m_topSegment(NULL)
        , m_hiddenCount(0)
        , m_extraSegment(NULL)
#ifdef MMGC_MARKSTACK_DEPTH
        , m_maxDepth(0)
#endif
    {
        // The value of kMarkStackItems is derived from on a block size of 4096; this
        // assert keeps us honest.  Talk to Lars if you get into trouble here.
        GCAssert(GCHeap::kBlockSize == 4096);
        
        GCAssert(sizeof(GCMarkStack::GCStackSegment) <= GCHeap::kBlockSize);
        PushSegment(true);
        GCAssert(Invariants());
    }

    GCMarkStack::~GCMarkStack()
    {
        while (m_topSegment != NULL)
            PopSegment();
        if (m_extraSegment)
            FreeStackSegment(m_extraSegment);
    }

    void GCMarkStack::Clear()
    {
        // Clear out the elements
        while (m_topSegment->m_prev != NULL)
            PopSegment();
        m_top = m_base;

        // Discard the cached segment
        if (m_extraSegment != NULL) {
            FreeStackSegment(m_extraSegment);
            m_extraSegment = NULL;
        }
        GCAssert(Invariants());
    }

    bool GCMarkStack::PushSegment(bool mustSucceed)
    {
        GCAssert(sizeof(GCStackSegment) <= GCHeap::kBlockSize);
        GCAssert(m_top == m_limit);
        if (m_extraSegment == NULL) {
            void *memory = AllocStackSegment(mustSucceed);
            if (memory == NULL)
                return false;
            m_extraSegment = new (memory) GCStackSegment();
        }
        if (m_topSegment != NULL)
            m_hiddenCount += kMarkStackItems;
        GCStackSegment* seg = m_extraSegment;
        m_extraSegment = NULL;
        seg->m_prev = m_topSegment;
        m_topSegment = seg;
        m_base = m_topSegment->m_items;
        m_limit = m_base + kMarkStackItems;
        m_top = m_base;
        return true;
    }

    void GCMarkStack::PopSegment()
    {
        m_hiddenCount -= kMarkStackItems;
        GCStackSegment* seg = m_topSegment;
        m_topSegment = seg->m_prev;
        m_base = m_topSegment->m_items;
        m_limit = m_base + kMarkStackItems;
        m_top = m_limit;
        if (m_extraSegment == NULL) {
            seg->m_prev = NULL;
            m_extraSegment = seg;
        }
        else
            FreeStackSegment(seg);
    }

    bool GCMarkStack::TransferOneFullSegmentFrom(GCMarkStack& other)
    {
        GCAssert(other.EntirelyFullSegments() > 0);
        GCStackSegment* seg;

        if (other.m_topSegment->m_prev == NULL) {
            // Picking off the only segment
            GCAssert(other.m_top == other.m_limit);
            seg = other.m_topSegment;
            other.m_topSegment = NULL;
            other.m_base = NULL;
            other.m_top = NULL;
            other.m_limit = NULL;
            if (!other.PushSegment()) {
                // Oops: couldn't push it, so undo.  We're out of memory but we
                // don't want to signal OOM here, we want to recover, signal failure,
                // and let the caller handle it.
                other.m_topSegment = seg;
                other.m_base = seg->m_items;
                other.m_top = other.m_limit = other.m_base + kMarkStackItems;
                return false;
            }
        }
        else {
            // Picking off the one below the top always
            seg = other.m_topSegment->m_prev;
            other.m_topSegment->m_prev = seg->m_prev;
            other.m_hiddenCount -= kMarkStackItems;
        }

        // Insert it below our top segment
        seg->m_prev = m_topSegment->m_prev;
        m_topSegment->m_prev = seg;
        m_hiddenCount += kMarkStackItems;

        // Special case that occurs if a segment was inserted into an empty stack.
        if (m_top == m_base)
            PopSegment();
        GCAssert(Invariants());
        GCAssert(other.Invariants());
        return true;
    }

    GCWorkItem *GCMarkStack::GetItemAbove(GCWorkItem *item)
    {
        if(item == Peek())
            return NULL;
        GCStackSegment *seg = m_topSegment;
        GCStackSegment *last = NULL;
        while(seg) {
            if(item >= seg->m_items && item < seg->m_items + kMarkStackItems) {
                if(item+1 == seg->m_items + kMarkStackItems) {
                    // The two items spanned a segment, above is first item in next
                    // segment (or "last" in the backwards traversal sense).
                    return &last->m_items[0];
                } else {
                    return item+1;
                }
            }
            last = seg;
            seg = seg->m_prev;
        }
        GCAssertMsg(false, "Invalid attempt to get the item above an item not in the stack.");
        return NULL;
    }

#ifdef _DEBUG
    bool GCMarkStack::Invariants()
    {
        GCAssert(m_base+kMarkStackItems == m_limit);
        GCAssert(m_top >= m_base);
        GCAssert(m_top <= m_limit);
        GCAssert(m_topSegment->m_prev == NULL || m_top > m_base);
        uint32_t hc = 0;
        uint32_t ns = 0;
        for ( GCStackSegment* seg=m_topSegment->m_prev ; seg != NULL ; seg = seg->m_prev ) {
            hc += kMarkStackItems;
            ns++;
        }
        GCAssert(ns == EntirelyFullSegments() || (m_top == m_limit && ns+1 == EntirelyFullSegments()));
        GCAssert(hc == m_hiddenCount);
        GCAssert(Count() == hc + (m_top - m_base));
        return true;
    }
#endif
}
