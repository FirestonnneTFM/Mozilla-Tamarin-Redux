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

#ifndef __Shared_inlines__
#define __Shared_inlines__

// Inline methods shared across classes


namespace MMgc
{
    // FL* are freelist helpers, put in one place to ease Valgrind support
    REALLY_INLINE void **FLSeed(void **item, void *next)
    {
        VALGRIND_MAKE_MEM_DEFINED(item, sizeof(void*));
        item[0] = next;
        VALGRIND_MAKE_MEM_UNDEFINED(item, sizeof(void*));
        return (void**)next;
    }

    REALLY_INLINE void FLPush(void* &head, const void *next)
    {
        *(void**)next = head;
        head = (void*)next;
    }

    REALLY_INLINE void *FLPop(void* &head)
    {
        void *p = head;
        VALGRIND_MAKE_MEM_DEFINED(p, sizeof(void*));
        head = *(void**)p;
        VALGRIND_MAKE_MEM_UNDEFINED(p, sizeof(void*));
        return p;
    }

    REALLY_INLINE void *FLPopAndZero(void* &head)
    { 
        void *p = FLPop(head);
        VALGRIND_MAKE_MEM_DEFINED(p, sizeof(void*));
        *(void**)p = NULL;
        VALGRIND_MAKE_MEM_UNDEFINED(p, sizeof(void*));
        return p;
    }

    REALLY_INLINE void *FLNext(void *item)
    {
        void **p = (void**)item;
        VALGRIND_MAKE_MEM_DEFINED(p, sizeof(void*));
        void *next = p[0];
        VALGRIND_MAKE_MEM_UNDEFINED(p, sizeof(void*));
        return next;
    }

   template<typename T, int growthIncrement>
    void BasicList<T,growthIncrement>::Add(T item)
    {
        if (holes && iteratorCount == 0)
            Compact();
        if (count == capacity)
        {
            capacity += growthIncrement;
            T* newItems = mmfx_new_array_opt(T,  capacity, kZero);
            if (items)
                VMPI_memcpy(newItems, items, count * sizeof(T));
            mmfx_delete_array(items);
            items = newItems;
        }
        uint32_t numHoles = 0;
        if (holes)
        {
            uint32_t numFound = 0;
            for (uint32_t j = 0; numFound < count && j < capacity; j++)
            {
                if (items[j] == NULL)
                {
                    numHoles++;
                } else {
                    numFound++;
                }
            }
        }
        items[count+numHoles] = item;
        count++;
    }

    template<typename T, int growthIncrement>
    bool BasicList<T,growthIncrement>::TryAdd(T item)
    {
        if (holes && iteratorCount == 0)
            Compact();
        if (count == capacity)
        {
            uint32_t tryCapacity = capacity + growthIncrement;
            T* newItems = mmfx_new_array_opt(T,  tryCapacity, (MMgc::FixedMallocOpts)(kZero|kCanFail));

            if (newItems == NULL)
                return false;

            capacity = tryCapacity;
            if (items)
                VMPI_memcpy(newItems, items, count * sizeof(T));
            mmfx_delete_array(items);
            items = newItems;
        }
        uint32_t numHoles = 0;
        if (holes)
        {
            uint32_t numFound = 0;
            for (uint32_t j = 0; numFound < count && j < capacity; j++)
            {
                if (items[j] == NULL)
                {
                    numHoles++;
                } else {
                    numFound++;
                }
            }
        }
        items[count+numHoles] = item;
        count++;
        return true;
    }

}

#endif /* __Shared_inlines__ */
