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
 * Portions created by the Initial Developer are Copyright (C) 2004-2009
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

#ifndef __avmplus_SortedMap__
#define __avmplus_SortedMap__


namespace avmplus
{
    /**
     * The SortedMap<K,T> template implements an object that
     * maps keys to values.   The keys are sorted
     * from smallest to largest in the map. Time of operations
     * is as follows:
     *   put() is O(1) if the key is higher than any existing
     *         key; O(logN) if the key already exists,
     *         and O(N) otherwise.
     *   get() is an O(logN) binary search.
     *
     * no duplicates are allowed.
     *
     * MEMORY MANAGEMENT:
     *
     * SortedMap can be instantiated on the stack or embedded as a field in another class.
     * However, it cannot be allocated dynamically (operator new is private/unimplemented):
     * some variants use non-GC memory, and none have a vtable compatible with GCFinalizedObject. 
     * If you need to dynamically allocate one, use HeapSortedMap to wrap an instance.
     *
     * Also, keep in mind that since some variants allocate using nonGC memory, one MUST
     * ensure the destructor runs, one way or another:
     *
     *   with stack allocation, as long as nobody longjmp's over
     *   the destructor, C++ compiler ensures the destructor is called.
     *
     *   when embedded as a field in another class, normal C++
     *   dtor handling should take care of this (but be wary:
     *   if embedding in a GC-allocated object, the embedder
     *   must be a GCFinalizedObject or RCObject, *not* a plain GCObject)
     */
    template<class KLIST, class TLIST>
    class SortedMap
    {
    private:
        typedef typename KLIST::TYPE K;
        typedef typename TLIST::TYPE T;
    public:
        enum { kInitialCapacity= 64 };

        typedef typename KLIST::ALLOCATOR KALLOCATOR;
        typedef typename TLIST::ALLOCATOR TALLOCATOR;

        SortedMap(KALLOCATOR* kallocator, TALLOCATOR* tallocator, int cap = kInitialCapacity)
            : keys(kallocator, cap), values(tallocator, cap) { }

        bool isEmpty() const
        {
            return keys.length() == 0;
        }
        int length() const
        {
            return keys.length();
        }
        void clear()
        {
            keys.clear();
            values.clear();
        }
        void destroy()
        {
            keys.destroy();
            values.destroy();
        }
        T put(K k, T v)
        {
            if (keys.length() == 0 || k > keys.last())
            {
                keys.add(k);
                values.add(v);
                return (T)v;
            }
            else
            {
                int i = find(k);
                if (i >= 0)
                {
                    T old = values[i];
                    keys.set(i, k);
                    values.set(i, v);
                    return old;
                }
                else
                {
                    i = -i - 1; // recover the insertion point
                    AvmAssert(keys.length() != (uint32_t)i);
                    keys.insert(i, k);
                    values.insert(i, v);
                    return v;
                }
            }
        }
        T get(K k) const
        {
            int i = find(k);
            return i >= 0 ? values[i] : 0;
        }
        bool get(K k, T& v) const
        {
            int i = find(k);
            if (i >= 0)
            {
                v = values[i];
                return true;
            }
            return false;
        }
        bool containsKey(K k) const
        {
            int i = find(k);
            return (i >= 0) ? true : false;
        }
        T remove(K k)
        {
            int i = find(k);
            return removeAt(i);
        }
        T removeAt(int i)
        {
            T old = values.removeAt(i);
            keys.removeAt(i);
            return old;
        }

        T removeFirst() { return isEmpty() ? (T)0 : removeAt(0); }
        T removeLast()  { return isEmpty() ? (T)0 : removeAt(keys.length()-1); }
        T first() const { return isEmpty() ? (T)0 : values[0]; }
        T last()  const { return isEmpty() ? (T)0 : values[keys.length()-1]; }

        K firstKey() const  { return isEmpty() ? 0 : keys[0]; }
        K lastKey() const   { return isEmpty() ? 0 : keys[keys.length()-1]; }

        // iterator
        T   at(int i) const { return values[i]; }
        K   keyAt(int i) const { return keys[i]; }

        int findNear(K k) const {
            int i = find(k);
            return i >= 0 ? i : -i-2;
        }
    protected:
        KLIST keys;
        TLIST values;

        int find(K k) const
        {
            int lo = 0;
            int hi = keys.length()-1;

            while (lo <= hi)
            {
                int i = (lo + hi)/2;
                K m = keys[i];
                if (k > m)
                    lo = i + 1;
                else if (k < m)
                    hi = i - 1;
                else
                    return i; // key found
            }
            return -(lo + 1);  // key not found, low is the insertion point
        }
    private:
        SortedMap<KLIST,TLIST>& operator=(const SortedMap<KLIST,TLIST>& other);       // unimplemented
        explicit SortedMap(const SortedMap<KLIST,TLIST>& other);            // unimplemented
        // private and unimplemented, use HeapSortedMap instead
        void* operator new(size_t size);
    };

    // ----------------------------

    // Don't be confused: this class reads as
    //
    //      "Heap-allocated SortedMap"
    //
    // NOT
    //
    //      "Map sorted using HeapSort"
    //
    template <class KLIST, class TLIST>
    class HeapSortedMap : public MMgc::GCFinalizedObject
    {
    private:
        typedef SortedMap<KLIST, TLIST> MapType;
    public:
        MapType map;
    public:
        explicit HeapSortedMap(typename KLIST::ALLOCATOR* kallocator, 
                                typename TLIST::ALLOCATOR* tallocator, 
                                int _capacity = MapType::kInitialCapacity)
          : map(kallocator, tallocator, _capacity)
        {
        }
    };
}

#endif /* __avmplus_SortedMap__ */
