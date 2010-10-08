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

#ifndef __avmplus_List__
#define __avmplus_List__

#include "TypeTraits.h"

namespace avmplus
{
    /*
     * MEMORY MANAGEMENT:
     *
     * The List variants can be instantiated on the stack or embedded as a field in another class.
     * However, they cannot be allocated dynamically (operator new is private/unimplemented):
     * some variants use non-GC memory, and none have a vtable compatible with GCFinalizedObject. 
     * If you need to dynamically allocate a list, use HeapList to wrap an instance.
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
     *
     * Most variants require you to use an MMgc::GC* as the allocator; 
     * the ones that cannot contain GC-allocated data (DataList and UnmanagedPointerList)
     * use FixedMalloc instead.
     *
     */

    template <class T>
    struct TypeSniffer
    {
        typedef typename MMgc::remove_pointer<T>::type                  baseType;

        typedef MMgc::is_same<T, baseType>                              isNonPointer;
        typedef MMgc::is_base_of<MMgc::GCObject, baseType>              isGCObject;
        typedef MMgc::is_base_of<MMgc::GCFinalizedObject, baseType>     isGCFinalizedObject;
        typedef MMgc::is_base_of<MMgc::RCObject, baseType>              isRCObject;
    };
    
    // ----------------------------

    // All Lists will be created with this as a minimum capacity, even if empty.
    // The current value (4) is based on the value from AtomArray, which used it as a minimum.
    const uint32_t kListMinCapacity = 4;

    // Old versions of List<> provided a default initial capacity (of 128) if you did not specify one.
    // This is dubiously large for many cases, so the new ListImpl<> variants don't provide a default
    // and require explicit sizing on creation. For minimal impact on existing code, this constant is provided
    // so that existing usage will have identical behavior until/unless it can be shown that a smaller value
    // is appropriate.
    const uint32_t kListInitialCapacity = 128;

    // The maximum length for a List is the maximum positive int32 value (thus the max index value
    // is one less than that). This may seem odd, as List indices are unsigned ints, but is done
    // mainly to preserve the semantics of indexOf() and lastIndexOf(), which return -1 for "not found".
    // This effectively rules out any indices > 0x7FFFFFFF. To minimize possibilities of off-by-one
    // errors, we also make the maximum *length* positive.
    const uint32_t kListMaxLength = 0x7FFFFFF;
    const uint32_t kListMaxIndexValue = kListMaxLength - 1;

    // ----------------------------
    // Conceptually, ListData<> is private to ListImpl<>, but we make it toplevel and public to avoid
    // friend template class declaration cruft. Since there's no way to extract a ListData from a ListImpl,
    // this is probably safe enough.
    template<class STORAGE>
    struct ListData 
    {
        uint32_t    len;
        uint32_t    cap;
        STORAGE     entries[1];   // lying, really [cap]
    };
        
    // ----------------------------
    // ----------------------------
    template<class T>
    class DataListHelper
    {
    public:
    
        // The allocator to use -- typically either GC or a wrapper around FixedMalloc.
        typedef MMgc::FixedMalloc ALLOCATOR;
        typedef MMgc::FixedMallocOpts ALLOCATORFLAGS;
    
        // TYPE which is the public-facing type seen by users of the ListImpl
        typedef T TYPE;

        // STORAGE is an internal-only type used to store the value.
        typedef T STORAGE;
        
        // (syntactic sugar)
        typedef ListData<STORAGE> LISTDATA;

        // When calling allocator->Calloc(), these are the flags we should use (kZero, etc).
        static ALLOCATORFLAGS allocFlags();

        // Given a pointer to data, return the allocator used to allocate it.
        // data must not be null.
        static ALLOCATOR* getAllocator(LISTDATA* data);

        // Store the data at the address, using WB if necessary.
        // Any pointer already stored there will be overwritten (but not freed); the caller
        // must ensure that old pointers are freed.
        static void wbData(ALLOCATOR* allocator, const void* container, LISTDATA** address, LISTDATA* data);
        
        // Load the item and do any conversion necessary from STORAGE to TYPE.
        static TYPE load(LISTDATA* data, uint32_t index);

        // Store a value at the given index, using WB as necessary and doing any conversion necessary from TYPE to STORAGE.
        static void store(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value);

        // Like store(), but the value at the given index is known to be empty (zeroed),
        // which may allow more efficiency.
        static void storeEmpty(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value);
        
        // Clear a range starting at index and going for count. Count must be > 0.
        // All entries in the range will be zeroed by this call.
        static void clearRange(LISTDATA* data, uint32_t start, uint32_t count);
        
        // Move a range within the given data. It is expected that the caller has
        // already done range checking to ensure that src+count and dst+count constitute
        // valid ranges within data.
        static void moveRange(ALLOCATOR* allocator, LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count);
    };

    // ----------------------------

    class GCListHelper
    {
    public:
        typedef MMgc::GC ALLOCATOR;
        typedef MMgc::GC::AllocFlags ALLOCATORFLAGS;
        typedef MMgc::GCObject* TYPE;
        typedef MMgc::GCObject* STORAGE;
        typedef ListData<STORAGE> LISTDATA;
        
        static ALLOCATORFLAGS allocFlags();
        static ALLOCATOR* getAllocator(LISTDATA* data);
        static void wbData(ALLOCATOR* allocator, const void* container, LISTDATA** address, LISTDATA* data);
        static TYPE load(LISTDATA* data, uint32_t index);
        static void store(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value);
        static void storeEmpty(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value);
        static void clearRange(LISTDATA* data, uint32_t start, uint32_t count);
        static void moveRange(ALLOCATOR* allocator, LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count);
    };

    // ----------------------------

    class RCListHelper
    {
    public:
        typedef MMgc::GC ALLOCATOR;
        typedef MMgc::GC::AllocFlags ALLOCATORFLAGS;
        typedef MMgc::RCObject* TYPE;
        typedef MMgc::RCObject* STORAGE;
        typedef ListData<STORAGE> LISTDATA;
        
        static ALLOCATORFLAGS allocFlags();
        static ALLOCATOR* getAllocator(LISTDATA* data);
        static void wbData(ALLOCATOR* allocator, const void* container, LISTDATA** address, LISTDATA* data);
        static TYPE load(LISTDATA* data, uint32_t index);
        static void store(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value);
        static void storeEmpty(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value);
        static void clearRange(LISTDATA* data, uint32_t start, uint32_t count);
        static void moveRange(ALLOCATOR* allocator, LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count);
    };

    // ----------------------------

    class AtomListHelper
    {
    public:
        typedef MMgc::GC ALLOCATOR;
        typedef MMgc::GC::AllocFlags ALLOCATORFLAGS;
        typedef Atom TYPE;
        typedef Atom STORAGE;
        typedef ListData<STORAGE> LISTDATA;

        static ALLOCATORFLAGS allocFlags();
        static ALLOCATOR* getAllocator(LISTDATA* data);
        static void wbData(ALLOCATOR* allocator, const void* container, LISTDATA** address, LISTDATA* data);
        static TYPE load(LISTDATA* data, uint32_t index);
        static void store(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value);
        static void storeEmpty(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value);
        static void clearRange(LISTDATA* data, uint32_t start, uint32_t count);
        static void moveRange(ALLOCATOR* allocator, LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count);
    };

    // ----------------------------

    class WeakRefListHelper
    {
    public:
        typedef MMgc::GC ALLOCATOR;
        typedef MMgc::GC::AllocFlags ALLOCATORFLAGS;
        typedef MMgc::GCObject* TYPE;
        typedef MMgc::GCWeakRef* STORAGE;
        typedef ListData<STORAGE> LISTDATA;

        static ALLOCATORFLAGS allocFlags();
        static ALLOCATOR* getAllocator(LISTDATA* data);
        static void wbData(ALLOCATOR* allocator, const void* container, LISTDATA** address, LISTDATA* data);
        static TYPE load(LISTDATA* data, uint32_t index);
        static void store(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value);
        static void storeEmpty(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value);
        static void clearRange(LISTDATA* data, uint32_t start, uint32_t count);
        static void moveRange(ALLOCATOR* allocator, LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count);
    };

    // ----------------------------

    template<class T, class ListHelper>
    class ListImpl
    {
    public:
        typedef T TYPE;
        typedef typename ListHelper::ALLOCATOR ALLOCATOR;
        
    public:
        // capacity is the initial capacity to preallocate for the List.
        // 
        // If args is NULL, the new list will have the given capacity, and a length of zero.
        //
        // If args is non-NULL, it is expected to point to an arrray of 'capacity'
        // entries, which will be used to initialize the list. The new list will
        // have length equal to capacity.
        //
        explicit ListImpl(typename ListHelper::ALLOCATOR* allocator, 
                          uint32_t capacity,
                          const T* args = NULL);

        ~ListImpl();

        // Return true if list has no elements. equivalent to length()==0.
        bool isEmpty() const;

        // Return the index+1 for highest-numbered entry that has an item stored. (This can differ
        // from "number of items contained" if set() is called in a nonlinear fashion.)
        uint32_t length() const;
        
        // Return the maximum number of items the ListImpl can contain without needing to allocate
        // more memory.
        uint32_t capacity() const;
        
        // Return the item at the given index. If the index is >= length(), assert. If the index
        // is < length() but has never had an item stored into it, return 0.
        T get(uint32_t index) const;
        
        // Equivalent to get(0).
        T first() const;

        // Equivalent to get(length()-1).
        T last() const;

        // Replace the item at the given index with the new value. 
        // This call will expand the List if necessary, and adjust length() if the new index
        // is >= the old length()
        void set(uint32_t index, T value);
        
        // Append the value to the end of the ListImpl, growing the ListImpl if necessary.
        void add(T value);
        
        // Append the given ListImpl to the end of this ListImpl, growing if necessary.
        void add(const ListImpl<T,ListHelper>& that);

        // Insert the given item at index. The item previously at index will then be at index+1.
        void insert(uint32_t index, T value);

        // Insert the given items at index, shifting entries up.
        // (aka "Array.unshift()" if index == 0, "Array.push()" if index >= len)
        void insert(uint32_t index, const T* args, uint32_t argc);

        // Delete deleteCount entries, starting at insertPoint, then insert insertCount entries from args,
        // starting at insertPoint.
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const T* args);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const ListImpl<T,ListHelper>& args, uint32_t argsOffset);
        
        // Reverse the ListImpl in place.
        void reverse();

        // Remove all items from the ListImpl and minimize capacity; 
        // after this call, isEmpty() == true, length() == 0, capacity() == kListMinCapacity.
        void clear();

        // If the given value is in the ListImpl, return the lowest-numbered index it can be found at. If not, return -1.
        // operator== is used to compare values (overloaded versions will be used, though this isn't currently tested).
        int32_t indexOf(T value) const;

        // If the given value is in the ListImpl, return the highest-numbered index it can be found at. If not, return -1.
        // operator== is used to compare values (overloaded versions will be used, though this isn't currently tested).
        int32_t lastIndexOf(T value) const;

        // Remove the item at index i, shifting all higher-indexed values down 1. Return the value that was at that
        // index. If index >= length(), assert.
        T removeAt(uint32_t index);
        
        // Equivalent to removeAt(0). (aka "Array.shift()")
        T removeFirst();

        // Equivalent to removeAt(length()-1). (aka "Array.pop()")
        T removeLast();

        // Equivalent to get(index).
        T operator[](uint32_t index) const;
        
        // Ensure that the ListImpl can hold at least cap elements. This does not affect length(); 
        // it's primarily useful to reduce redundant allocations when filling in a list.
        void ensureCapacity(uint32_t cap);

        // Return the number of bytes used for the ListImpl's dynamically-allocated storage.
        uint64_t bytesUsed() const; 

    private:
        ListImpl<T,ListHelper>& operator=(const ListImpl<T,ListHelper>& other); // unimplemented
        explicit ListImpl(const ListImpl<T,ListHelper>& other);                 // unimplemented
        void* operator new(size_t size);                                        // unimplemented, use HeapList instead

        void ensureCapacityExtra(uint32_t cap, uint32_t extra);
        
        // This function shouldn't be called directly; it's intended to be called
        // only by ensureCapacity(), which does an inline capacity check
        // before calling (which is a clear performance win).
        void FASTCALL ensureCapacityImpl(uint32_t cap);

        static typename ListHelper::LISTDATA* allocData(typename ListHelper::ALLOCATOR* allocator, uint32_t cap);

    private:
        typename ListHelper::LISTDATA* m_data; // If GC-allocated, this is written with explicit WB
    };

    // ----------------------------

    template<class T>
    class GCList
    {
    private:
        typedef ListImpl<MMgc::GCObject*, GCListHelper> LIST;
        
    public:
        typedef T TYPE;
        typedef typename LIST::ALLOCATOR ALLOCATOR;
        
    public:
        explicit GCList(ALLOCATOR* allocator, 
                        uint32_t capacity,
                        const T* args = NULL);

        bool isEmpty() const;
        uint32_t length() const;
        uint32_t capacity() const;
        T get(uint32_t index) const;
        T first() const;
        T last() const;
        void set(uint32_t index, T value);
        void add(T value);
        void add(const GCList<T>& that);
        void insert(uint32_t index, T value);
        void insert(uint32_t index, const T* args, uint32_t argc);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const T* args);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const GCList<T>& args, uint32_t argsOffset);
        void reverse();
        void clear();
        int32_t indexOf(T value) const;
        int32_t lastIndexOf(T value) const;
        T removeAt(uint32_t index);
        T removeFirst();
        T removeLast();
        T operator[](uint32_t index) const;
        void ensureCapacity(uint32_t cap);
        uint64_t bytesUsed() const; 

    private:
        GCList<T>& operator=(const GCList<T>& other);     // unimplemented
        explicit GCList(const GCList<T>& other);          // unimplemented
        void* operator new(size_t size);                  // unimplemented, use HeapList instead

        // This is a little hackery that is necessary due to the fact that GCFinalizedObject
        // doesn't extend GCObject, but can be treated equivalently in this context.
        REALLY_INLINE static MMgc::GCObject* to_gc(MMgc::GCObject* o) { return o; }
        REALLY_INLINE static MMgc::GCObject* to_gc(MMgc::GCFinalizedObject* o) { return (MMgc::GCObject*)o; }
        REALLY_INLINE static MMgc::GCObject* to_gc(const MMgc::GCObject* o) { return (MMgc::GCObject*)o; }
        REALLY_INLINE static MMgc::GCObject* to_gc(const MMgc::GCFinalizedObject* o) { return (MMgc::GCObject*)o; }

    private:
        LIST m_list;
    };

    // ----------------------------

    template<class T>
    class RCList
    {
    private:
        typedef ListImpl<MMgc::RCObject*, RCListHelper> LIST;
        
    public:
        typedef T TYPE;
        typedef typename LIST::ALLOCATOR ALLOCATOR;
        
    public:
        explicit RCList(ALLOCATOR* allocator, 
                        uint32_t capacity,
                        const T* args = NULL);

        bool isEmpty() const;
        uint32_t length() const;
        uint32_t capacity() const;
        T get(uint32_t index) const;
        T first() const;
        T last() const;
        void set(uint32_t index, T value);
        void add(T value);
        void add(const RCList<T>& that);
        void insert(uint32_t index, T value);
        void insert(uint32_t index, const T* args, uint32_t argc);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const T* args);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const RCList<T>& args, uint32_t argsOffset);
        void reverse();
        void clear();
        int32_t indexOf(T value) const;
        int32_t lastIndexOf(T value) const;
        T removeAt(uint32_t index);
        T removeFirst();
        T removeLast();
        T operator[](uint32_t index) const;
        void ensureCapacity(uint32_t cap);
        uint64_t bytesUsed() const; 

    private:
        RCList<T>& operator=(const RCList<T>& other);     // unimplemented
        explicit RCList(const RCList<T>& other);          // unimplemented
        void* operator new(size_t size);                  // unimplemented, use HeapList instead

    private:
        LIST m_list;
    };

    // ----------------------------
    
    // We can't use "void*" for UnmanagedPointer, as the type-sniffing
    // code will complain that sizeof(void) is illegal (which it is)...
    // so we'll make a synthetic type to use here. We declare it publicly
    // to simplify explicit instantiation of the relevant ListImpl<> type.
    struct Unmanaged { int foo; };
    typedef Unmanaged* UnmanagedPointer;
    
    template<class T>
    class UnmanagedPointerList
    {
    private:
        typedef ListImpl< UnmanagedPointer, DataListHelper<UnmanagedPointer> > LIST;
        
    public:
        typedef T TYPE;
        typedef typename LIST::ALLOCATOR ALLOCATOR;
        
    public:
        explicit UnmanagedPointerList(ALLOCATOR* allocator, 
                                      uint32_t capacity,
                                      const T* args = NULL);

        bool isEmpty() const;
        uint32_t length() const;
        uint32_t capacity() const;
        T get(uint32_t index) const;
        T first() const;
        T last() const;
        void set(uint32_t index, T value);
        void add(T value);
        void add(const UnmanagedPointerList<T>& that);
        void insert(uint32_t index, T value);
        void insert(uint32_t index, const T* args, uint32_t argc);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const T* args);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const UnmanagedPointerList<T>& args, uint32_t argsOffset);
        void reverse();
        void clear();
        int32_t indexOf(T value) const;
        int32_t lastIndexOf(T value) const;
        T removeAt(uint32_t index);
        T removeFirst();
        T removeLast();
        T operator[](uint32_t index) const;
        void ensureCapacity(uint32_t cap);
        uint64_t bytesUsed() const; 

    private:
        UnmanagedPointerList<T>& operator=(const UnmanagedPointerList<T>& other);       // unimplemented
        explicit UnmanagedPointerList(const UnmanagedPointerList<T>& other);            // unimplemented
        void* operator new(size_t size);                                                // unimplemented, use HeapList instead

    private:
        LIST m_list;
    };

    // ----------------------------
    template<class T>
    class WeakRefList
    {
    private:
        typedef ListImpl<MMgc::GCObject*, WeakRefListHelper> LIST;
        
    public:
        typedef T TYPE;
        typedef typename LIST::ALLOCATOR ALLOCATOR;
        
    public:
        explicit WeakRefList(ALLOCATOR* allocator, 
                             uint32_t capacity,
                             const T* args = NULL);

        bool isEmpty() const;
        uint32_t length() const;
        uint32_t capacity() const;
        T get(uint32_t index) const;
        T first() const;
        T last() const;
        void set(uint32_t index, T value);
        void add(T value);
        void add(const WeakRefList<T>& that);
        void insert(uint32_t index, T value);
        void insert(uint32_t index, const T* args, uint32_t argc);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const T* args);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const WeakRefList<T>& args, uint32_t argsOffset);
        void reverse();
        void clear();
        int32_t indexOf(T value) const;
        int32_t lastIndexOf(T value) const;
        T removeAt(uint32_t index);
        T removeFirst();
        T removeLast();
        T operator[](uint32_t index) const;
        void ensureCapacity(uint32_t cap);
        uint64_t bytesUsed() const; 

    private:
        WeakRefList<T>& operator=(const WeakRefList<T>& other);     // unimplemented
        explicit WeakRefList(const WeakRefList<T>& other);          // unimplemented
        void* operator new(size_t size);                            // unimplemented, use HeapList instead

        // This is a little hackery that is necessary due to the fact that GCFinalizedObject
        // doesn't extend GCObject, but can be treated equivalently in this context.
        REALLY_INLINE static MMgc::GCObject* to_gc(MMgc::GCObject* o) { return o; }
        REALLY_INLINE static MMgc::GCObject* to_gc(MMgc::GCFinalizedObject* o) { return (MMgc::GCObject*)o; }
        REALLY_INLINE static MMgc::GCObject* to_gc(const MMgc::GCObject* o) { return (MMgc::GCObject*)o; }
        REALLY_INLINE static MMgc::GCObject* to_gc(const MMgc::GCFinalizedObject* o) { return (MMgc::GCObject*)o; }

    private:
        LIST m_list;
    };

    // ----------------------------

    typedef ListImpl<Atom, AtomListHelper> AtomList;

    // ----------------------------
    template<class T>
    class DataList : public ListImpl< T, DataListHelper<T> >
    {
    private:
        typedef ListImpl< T, DataListHelper<T> > BASE;

    public:
        typedef T TYPE;
        typedef typename BASE::ALLOCATOR ALLOCATOR;
        
    public:
        explicit DataList(ALLOCATOR* allocator, 
                          uint32_t capacity,
                          const T* args = NULL);

    private:
        DataList<T>& operator=(const DataList<T>& other);       // unimplemented
        explicit DataList(const DataList<T>& other);            // unimplemented
        void* operator new(size_t size);                        // unimplemented, use HeapList instead
    };

    // ----------------------------

    template<class T>
    class HeapList : public MMgc::GCFinalizedObject
    {
    public:
        T list;
    public:
        explicit HeapList(typename T::ALLOCATOR* allocator, 
                          uint32_t capacity,
                          const typename T::TYPE* args = NULL);
    };

    // ----------------------------

}

#endif /* __avmplus_List__ */
