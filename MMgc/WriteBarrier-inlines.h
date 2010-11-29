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
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
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

//
// GCWriteBarrier
//

#ifndef _WRITE_BARRIER_INLINES_H_
#define _WRITE_BARRIER_INLINES_H_

namespace MMgc
{
    /*private*/
    REALLY_INLINE void GC::WriteBarrierWriteRC(const void *address, const void *value)
    {
        RCObject *rc = (RCObject*)Pointer(*(RCObject**)address);
        if(rc != NULL) {
            GCAssert(IsRCObjectSafe(rc));
            rc->DecrementRef();
        }
        GCAssert(IsPointerIntoGCObject(address));
        MMGC_WB_EDGE(address, value);
        *(uintptr_t*)address = (uintptr_t) value;
        rc = (RCObject*)Pointer(value);
        if(rc != NULL) {
            GCAssert(IsRCObjectSafe(rc));
            rc->IncrementRef();
        }
    }

    /*private*/
    REALLY_INLINE void GC::WriteBarrierWriteRC_ctor(const void *address, const void *value)
    {
        // assume existing contents of address are potentially uninitialized,
        // so don't bother even making an assertion.
        GCAssert(IsPointerIntoGCObject(address));
        MMGC_WB_EDGE(address, value);
        *(uintptr_t*)address = (uintptr_t) value;
        RCObject *rc = (RCObject*)Pointer(value);
        if(rc != NULL) {
            GCAssert(IsRCObjectSafe(rc));
            rc->IncrementRef();
        }
    }

    /*private*/
    REALLY_INLINE void GC::WriteBarrierWriteRC_dtor(const void *address)
    {
        GCAssert(IsPointerIntoGCObject(address));
        RCObject *rc = (RCObject*)Pointer(*(RCObject**)address);
        MMGC_WB_EDGE(address, NULL);
        if(rc != NULL) {
            GCAssert(IsRCObjectSafe(rc));
            rc->DecrementRef();
            *(uintptr_t*)address = 0;
        }
    }

    /*private*/
    REALLY_INLINE void GC::WriteBarrierWrite(const void *address, const void *value)
    {
        GCAssert(!IsRCObjectSafe(value));
        GCAssert(IsPointerIntoGCObject(address));
        MMGC_WB_EDGE(address, value);
        *(uintptr_t*)address = (uintptr_t) value;
    }

    /*private*/
    REALLY_INLINE void GC::InlineWriteBarrierTrap(const void *container)
    {
        GCAssert(marking);
        GCAssert(IsPointerToGCPage(container));

        POLICY_PROFILING_ONLY(int stage=0;)
        // If the object is black then it needs to be gray, because we just stored
        // something into it.
        //
        // It's good to check 'marking' because it provides a performance boost if it is
        // true less than maybe 2/3 of the time - it avoids more expensive computation.
        // We don't check 'collecting' because that's much less often true; it's checked
        // inside WriteBarrierHit.  We make it a precondition for this function because
        // some computations can be elided if it is checked earlier.
        //
        // Testing shows that it's /sometimes/ useful to check the right hand side of the
        // assignment for NULL, but this depends on the program and for the time being
        // the right hand side isn't available here and isn't checked.

        if (IsMarkedThenMakeQueued(container))
        {
            POLICY_PROFILING_ONLY(stage=1;)
            WriteBarrierHit(container);
        }
        POLICY_PROFILING_ONLY( policy.signalWriteBarrierWork(stage); )
    }

    REALLY_INLINE void GC::privateInlineWriteBarrier(const void *container, const void *address, const void *value)
    {
        GCAssert(container != NULL);
        GCAssert(IsPointerToGCObject(GetRealPointer(container)));
        GCAssert(((uintptr_t)address & 3) == 0);

        if (marking) {
            GCAssert(address >= container);
            GCAssert(address < (char*)container + Size(container));
            InlineWriteBarrierTrap(container);
        }
        WriteBarrierWrite(address, value);
    }

    REALLY_INLINE void GC::privateInlineWriteBarrier(const void *address, const void *value)
    {
        GCAssert(((uintptr_t)address & 3) == 0);

        if (marking) {
            const void* container = FindBeginningFast(address);

            GCAssert(IsPointerToGCPage(container));
            GCAssert(address >= container);
            GCAssert(address < (char*)container + Size(container));

            InlineWriteBarrierTrap(container);
        }
        WriteBarrierWrite(address, value);
    }

    REALLY_INLINE void GC::privateInlineWriteBarrierRC(const void *container, const void *address, const void *value)
    {
        GCAssert(IsPointerToGCPage(container));
        GCAssert(((uintptr_t)container & 3) == 0);
        GCAssert(((uintptr_t)address & 2) == 0);
        GCAssert(address >= container);
        GCAssert(address < (char*)container + Size(container));

        if (marking)
            InlineWriteBarrierTrap(container);
        WriteBarrierWriteRC(address, value);
    }

    REALLY_INLINE void GC::privateInlineWriteBarrierRC(const void *address, const void *value)
    {
        if (marking) {
            const void* container = FindBeginningFast(address);

            GCAssert(IsPointerToGCPage(container));
            GCAssert(((uintptr_t)container & 3) == 0);
            GCAssert(((uintptr_t)address & 2) == 0);
            GCAssert(address >= container);
            GCAssert(address < (char*)container + Size(container));

            InlineWriteBarrierTrap(container);
        }
        WriteBarrierWriteRC(address, value);
    }

    REALLY_INLINE void GC::ConservativeWriteBarrierNoSubstitute(const void *address, const void *value)
    {
        (void)value;  // Can't get rid of this parameter now; part of an existing API

        if (marking)
            privateConservativeWriteBarrierNoSubstitute(address);
    }

    // Always pay for a single real function call; then inline & optimize massively in WriteBarrier()
    template<class T> 
    REALLY_INLINE T WriteBarrier<T>::set(const T tNew)
    {
        GC::WriteBarrier(&t, (const void*)tNew);    // updates 't'
        return tNew;
    }

    // Always pay for a single real function call; then inline & optimize massively in WriteBarrierRC()
    template<class T>
    REALLY_INLINE T WriteBarrierRC<T>::set(const T tNew)
    {
        GC::WriteBarrierRC(&t, (const void*)tNew);  // updates 't'
        return tNew;
    }
    
    template<class T>
    REALLY_INLINE WriteBarrierRC<T>::WriteBarrierRC(const T _t) // : t(0) -- not necessary, WriteBarrierRC_ctor handles it
    {
        GC::WriteBarrierRC_ctor(&t, (const void*)_t);
    }
    
    template<class T>
    REALLY_INLINE WriteBarrierRC<T>::~WriteBarrierRC()
    {
        GC::WriteBarrierRC_dtor(&t);
    }
    
    template<class T>
    REALLY_INLINE void WriteBarrierRC<T>::set(MMgc::GC* gc, void* container, T newValue)
    {
        WBRC(gc, container, &t, newValue);
    }
    
}

#endif // _WRITE_BARRIER_INLINES_H_
