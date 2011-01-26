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

#ifndef __avmplus_Container__
#define __avmplus_Container__

namespace avmplus
{
    /**
     * The instances of this utility class hold fixed-size indexed
     * sets of constructor-less structs with a 'void gcTrace(GC*)'
     * method.  The structs will be initialized to all-zero-bits.
     */
    template <class T>
    class ExactStructContainer : public MMgc::GCFinalizedObject
    {
    public:
        static ExactStructContainer* create(MMgc::GC* gc, void (*finalizer)(ExactStructContainer<T>* self), uint32_t capacity) {
            size_t extra = 0;
            if (capacity > 0)
                extra = MMgc::GCHeap::CheckForCallocSizeOverflow(capacity-1, sizeof(T));
			return new (gc, MMgc::kExact, extra) ExactStructContainer<T>(capacity, finalizer);
        }

        ~ExactStructContainer() {
            if (_finalizer != NULL)
                _finalizer(this);
        }

        uint32_t capacity() {
            return _capacity;
        }

        T& get(uint32_t index) {
            AvmAssert(index < capacity());
            return elements[index];
        }

        T& operator[](uint32_t index) {
            return get(index);
        }

        virtual bool gcTrace(MMgc::GC* gc, size_t cursor)
        {
            uint32_t cap = capacity();
            const uint32_t work_increment = 2000/sizeof(void*);
            if (work_increment * cursor >= cap)
                return false;
            size_t work = work_increment;
            bool more = true;
            if (work_increment * (cursor + 1) >= cap) {
                work = cap - (work_increment * cursor);
                more = false;
            }
            for ( size_t i=0 ; i < work ; i++ )
                elements[(work_increment * cursor) + i].gcTrace(gc);
            return more;
        }
        
    private:
        ExactStructContainer(uint32_t capacity, void (*finalizer)(ExactStructContainer* self)) : _capacity(capacity), _finalizer(finalizer) {}

        uint32_t _capacity;
        void     (*_finalizer)(ExactStructContainer* self);
        T        elements[1];     // Actually max(1,capacity())
    };
}

#endif /* __avmplus_Container__ */
