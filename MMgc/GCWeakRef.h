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
// GCWeakRef.h
// GC weak references (aka safe handles) as template classes
//

#ifndef _GC_WEAK_REF_H_
#define _GC_WEAK_REF_H_

namespace MMgc
{
    // new improved weak ref
    class GCWeakRef : public GCFinalizedObject
    {
        friend class GC;
    public:
        // Use 'get' to read the value in almost every situation.
        //
        // In particular use 'get' to read a value that may be stored in a data structure,
        // used as the 'this' value in a call, or may in any other way escape the local
        // context.
        //
        // If you're just checking whether the object is NULL you should use 'isNull'.
        //
        // If you are calling 'get' from a presweep handler and it is important that the
        // value you are reading should not be marked if it has not been marked already,
        // and you're sure you know what that means, then call 'peek' instead.
        //
        // Wizards' technical note:
        //
        // 'get' contains a read barrier that causes the object to be marked if it is read
        // during presweep and is unmarked at that time - see Bugzilla 572331.

        GCObject *get();

        // @return true iff the weak ref has been cleared and no longer holds onto its object.
        
        bool isNull() { return m_obj == NULL; }

        // Wizard API:
        //
        // Use 'peek' to read the value from a presweep handler when it is important that that
        // value not be marked if it is not already marked, because you sincerely want the value
        // to be garbage collected.  You promise not to store the value read by 'peek' into any
        // heap variable or location where it may subsequently be found by, or given to, the garbage
        // collector, and you acknowledge that the storage pointed to by the value (if not NULL
        // and not marked) almost certainly will be reclaimed by the garbage collector once all
        // presweep handlers have run (absent a call to 'get').
        //
        // If you don't know what all that means then you are not sufficiently wizardly, and you
        // should not use 'peek' but 'get'.

        GCObject *peek() { return (GCObject*)m_obj; }

        ~GCWeakRef()
        {
            if(m_obj) {
                GC::GetGC(this)->ClearWeakRef(m_obj);
            }
        }

    private:
        /**
         * When allocating a GCWeakRef, tell the GC we don't contain pointers
         * (overriding the default base-class behavior).
         */
        static void *operator new(size_t size, GC *gc)
        {
            return gc->Alloc(size, GC::kFinalize);
        }

        // private, only GC can access
        GCWeakRef(const void *obj) : m_obj(obj)
        {
#ifdef MMGC_MEMORY_INFO
            obj_creation = obj;
#endif
        }
        const void *m_obj;
#ifdef MMGC_MEMORY_INFO
        const void* obj_creation;
#endif
    };

#if 0
    // something like this would be nice
    template<class T> class GCWeakRefPtr
    {

    public:
        GCWeakRefPtr() {}
        GCWeakRefPtr(T t) {  set(t);}
        ~GCWeakRefPtr() { t = NULL; }

        T operator=(const GCWeakRefPtr<T>& wb)
        {
            return set(wb.t);
        }

        T operator=(T tNew)
        {
            return set(tNew);
        }

        operator T() const { return (T) t->get(); }

        bool operator!=(T other) const { return other != t; }

        T operator->() const
        {
            return (T) t->get();
        }
    private:
        T set(const T tNew)
        {
            t = tNew->GetWeakRef();
        }
        GCWeakRef* t;
    };
#endif
}

#endif // _GC_WEAK_REF_H_
