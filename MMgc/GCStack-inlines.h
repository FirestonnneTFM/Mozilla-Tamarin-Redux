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
    REALLY_INLINE uintptr_t GCMarkStack::Top()
    {
        GCAssert(!IsEmpty());
        return uintptr_t(m_top-1);
    }
    
    REALLY_INLINE bool GCMarkStack::Push_GCObject(const void* p)
    {
        uintptr_t* top = allocSpace(1);
        if (top == NULL)
            return false;
        top[0] = uintptr_t(p);
        return true;
    }
    
    REALLY_INLINE const void* GCMarkStack::Pop_GCObject()
    {
        GCAssert(!IsEmpty());
        uintptr_t w = m_top[-1];
        GCAssert(!(w & 1));
        if ((w & 3) == 0) {
            freeSpace(1);
            return (void*)w;
        }
        return NULL;
    }
    
    REALLY_INLINE GCMarkStack::TypeTag GCMarkStack::PeekTypetag()
    {
        GCAssert(!IsEmpty());
        uintptr_t w = m_top[-1];
        GCAssert(!(w & 1));
        if ((w & 3) == 0)
            return kGCObject;
        return GCMarkStack::TypeTag(w >> 2);
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

    REALLY_INLINE uint32_t GCMarkStack::InactiveSegments()
    {
        return m_hiddenSegments;
    }

#ifdef MMGC_MARKSTACK_DEPTH
    REALLY_INLINE uint32_t GCMarkStack::MaxCount()
    {
        return m_maxDepth;
    }
#endif

    REALLY_INLINE uintptr_t* GCMarkStack::allocSpace(size_t nwords)
    {
        GCAssert(Invariants());
        if (m_top+nwords > m_limit)
            if (!PushSegment()) {
                GCAssert(Invariants());
                return NULL;
            }
        m_top += nwords;
#ifdef MMGC_MARKSTACK_DEPTH
        uint32_t depth = Count();
        if (depth > m_maxDepth)
            m_maxDepth = depth;
#endif
        GCAssert(Invariants());
        return m_top-1;
    }

    REALLY_INLINE void GCMarkStack::freeSpace(size_t nwords)
    {
        GCAssert(Invariants());
        GCAssert(m_top-nwords >= m_base);
        m_top -= nwords;
#ifdef _DEBUG
        VMPI_memset(m_top, 0, nwords*sizeof(uintptr_t));
#endif
        if (m_top == m_base) 
            PopSegment_UnlessLast();
        GCAssert(Invariants());
    }

}

#endif /* __GCStack_inlines__ */
