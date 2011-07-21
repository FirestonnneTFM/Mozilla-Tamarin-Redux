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
     * The List variants can be instantiated on the stack or embedded as a field in another class
     * if that class is a GCObject or a GCRoot, otherwise an assert will fire.   All lists 
     * use GC memory.
     *
     * Also, keep in mind that since some variants contain RCObject,
     * one MUST ensure the destructor runs, one way or another:
     *
     *   with stack allocation, as long as nobody longjmp's over
     *   the destructor, C++ compiler ensures the destructor is called.
     *
     *   when embedded as a field in another class, normal C++
     *   dtor handling should take care of this (but be wary:
     *   if embedding in a GC-allocated object, the embedder
     *   must be a GCFinalizedObject or RCObject, *not* a plain GCObject)
     *
     * All variants require you to pass in an MMgc::GC*.
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
        typedef MMgc::is_base_of<MMgc::GCTraceableObject, baseType>     isGCTraceableObject;
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
    //
    // ListData *always* allocates via the GC.
    template<class STORAGE>
    struct ListData
    {
        uint32_t    len;
        STORAGE     entries[1];   // lying, really [cap]
        
        // add an empty, inlined ctor to avoid spurious warnings in MSVC2008
        REALLY_INLINE explicit ListData() {}

        REALLY_INLINE static ListData<STORAGE>* create(MMgc::GC* gc, size_t totalElements)
        {
            using namespace MMgc;
            
            size_t bytes = GCHeap::CheckForAllocSizeOverflow(sizeof(ListData<STORAGE>),
                                                             GCHeap::CheckForCallocSizeOverflow(totalElements-1, sizeof(STORAGE)));
            void *mem = gc->Alloc(bytes);
            
            return ::new (mem) ListData<STORAGE>();
        }

        REALLY_INLINE static void free(MMgc::GC* gc, void* mem)
        {
            gc->Free(mem);
        }

        REALLY_INLINE static size_t getSize(void* mem)
        {
            return MMgc::GC::Size(mem);
        }        
        
        REALLY_INLINE MMgc::GC* gc() { return MMgc::GC::GetGC(this); }
        REALLY_INLINE void set_gc(MMgc::GC* _gc) { AvmAssert(_gc == gc()); (void)_gc; }
    };

    // TracedListData *always* allocates via GC.
    template<class STORAGE>
    struct TracedListData : public MMgc::GCTraceableObject
    {
        uint32_t    len;
        STORAGE     entries[1];   // lying, really [cap]
        
        REALLY_INLINE explicit TracedListData() { }

        REALLY_INLINE static TracedListData<STORAGE>* create(MMgc::GC* gc, size_t totalElements)
        {
            return new (gc, MMgc::kExact, MMgc::GCHeap::CheckForCallocSizeOverflow(totalElements-1, sizeof(STORAGE))) TracedListData<STORAGE>();
        }
        
        REALLY_INLINE static void free(MMgc::GC* gc, void* mem)
        {
            gc->Free(mem);
        }
        
        REALLY_INLINE static size_t getSize(void* mem)
        {
            return MMgc::GC::Size(mem);
        }
        
        virtual bool gcTrace(MMgc::GC* gc, size_t cursor);
        
        REALLY_INLINE MMgc::GC* gc() { return MMgc::GC::GetGC(this); }
        REALLY_INLINE void set_gc(MMgc::GC* _gc) { AvmAssert(_gc == gc()); (void)_gc; }
    };
    
    // ----------------------------
    // ----------------------------
    template<class T>
    class DataListHelper
    {
    public:
    
        // TYPE which is the public-facing type seen by users of the ListImpl
        typedef T TYPE;
        
        // OPAQUE_TYPE is the same as TYPE for everything but Atom -- this is a workaround
        // for the fact that Atom is an int32_t, and as such can't be overloaded properly
        // in templated code.
        typedef TYPE OPAQUE_TYPE;

        // STORAGE is an internal-only type used to store the value.
        typedef T STORAGE;
        
        // (syntactic sugar)
        typedef ListData<STORAGE> LISTDATA;

        // Load the item and do any conversion necessary from STORAGE to TYPE.
        static TYPE load(LISTDATA* data, uint32_t index);

        // Store a value at the given index, using WB as necessary and doing any conversion necessary from TYPE to STORAGE.
        static void store(LISTDATA* data, uint32_t index, TYPE value);

        // Like store(), but the value at the given index is known to be empty (zeroed),
        // which may allow more efficiency.
        static void storeInEmpty(LISTDATA* data, uint32_t index, TYPE value);
        
        // Clear a range starting at index and going for count. Count must be > 0.
        // All entries in the range will be zeroed by this call.
        static void clearRange(LISTDATA* data, uint32_t start, uint32_t count);
        
        // Move a range within the given data. It is expected that the caller has
        // already done range checking to ensure that src+count and dst+count constitute
        // valid ranges within data.
        static void moveRange(LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count);
        
        // Trace GC pointers in the data, if appropriate for the data type.
        static void gcTrace(MMgc::GC* gc, LISTDATA** data);
    };

    // ----------------------------

    class GCListHelper
    {
    public:
        typedef MMgc::GCObject* TYPE;
        typedef TYPE OPAQUE_TYPE;
        typedef MMgc::GCObject* STORAGE;
        typedef TracedListData<STORAGE> LISTDATA;
        
        static TYPE load(LISTDATA* data, uint32_t index);
        static void store(LISTDATA* data, uint32_t index, TYPE value);
        static void storeInEmpty(LISTDATA* data, uint32_t index, TYPE value);
        static void clearRange(LISTDATA* data, uint32_t start, uint32_t count);
        static void moveRange(LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count);
        static void gcTrace(MMgc::GC* gc, LISTDATA** loc);
    };

    // ----------------------------

    class RCListHelper
    {
    public:
        typedef MMgc::RCObject* TYPE;
        typedef TYPE OPAQUE_TYPE;
        typedef MMgc::RCObject* STORAGE;
        typedef TracedListData<STORAGE> LISTDATA;
        
        static TYPE load(LISTDATA* data, uint32_t index);
        static void store(LISTDATA* data, uint32_t index, TYPE value);
        static void storeInEmpty(LISTDATA* data, uint32_t index, TYPE value);
        static void clearRange(LISTDATA* data, uint32_t start, uint32_t count);
        static void moveRange(LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count);
        static void gcTrace(MMgc::GC* gc, LISTDATA** loc);
    };

    // ----------------------------

    class AtomListHelper
    {
    public:
        typedef Atom TYPE;
        typedef OpaqueAtom OPAQUE_TYPE;
        typedef Atom STORAGE;
        typedef TracedListData<STORAGE> LISTDATA;

        static TYPE load(LISTDATA* data, uint32_t index);
        static void store(LISTDATA* data, uint32_t index, TYPE value);
        static void storeInEmpty(LISTDATA* data, uint32_t index, TYPE value);
        static void clearRange(LISTDATA* data, uint32_t start, uint32_t count);
        static void moveRange(LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count);
        static void gcTrace(MMgc::GC* gc, LISTDATA** loc);
    };

    // ----------------------------

    class WeakRefListHelper
    {
    public:
        typedef MMgc::GCObject* TYPE;
        typedef TYPE OPAQUE_TYPE;
        typedef MMgc::GCWeakRef* STORAGE;
        typedef TracedListData<STORAGE> LISTDATA;

        static TYPE load(LISTDATA* data, uint32_t index);
        static void store(LISTDATA* data, uint32_t index, TYPE value);
        static void storeInEmpty(LISTDATA* data, uint32_t index, TYPE value);
        static void clearRange(LISTDATA* data, uint32_t start, uint32_t count);
        static void moveRange(LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count);
        static void gcTrace(MMgc::GC* gc, LISTDATA** loc);
    };

    // ----------------------------

    template<class T, class ListHelper>
    class ListImpl : public MMgc::GCInlineObject
    {
        template<class TLIST> friend class VectorAccessor;
        template<class T2> friend class DataListAccessor;

    public:
        typedef T TYPE;
        typedef typename ListHelper::OPAQUE_TYPE OPAQUE_TYPE;
        
    public:
        // capacity is the initial capacity to preallocate for the List.
        //
        // If args is NULL, the new list will have the given capacity, and a length of zero.
        //
        // If args is non-NULL, it is expected to point to an arrray of 'capacity'
        // entries, which will be used to initialize the list. The new list will
        // have length equal to capacity.
        //
        explicit ListImpl(MMgc::GC* gc,
                          uint32_t capacity,
                          const T* args = NULL);

        ~ListImpl();

        // Return true if list has no elements. equivalent to length()==0.
        bool isEmpty() const;

        // Return the index+1 for highest-numbered entry that has an item stored. (This can differ
        // from "number of items contained" if set() is called in a nonlinear fashion.)
        uint32_t length() const;
        
        // Explicitly set the length of the ListImpl, growing or contracting as necessary.
        // If growth is necessary, a List-dependent empty value will be stored in the
        // newly expanded area (typically 0 / null). Note that setting the
        // length to a smaller value will not necessarily reduce the capacity() value.
        // Most code should never need to use this method; it's provided mainly for
        // Array / Vector code that needs this level of control.
        void set_length(uint32_t len);

        // Return the maximum number of items the ListImpl can contain without needing to allocate
        // more memory.
        uint32_t capacity() const;

        // Explicitly set the capacity of the ListImpl, growing or contracting as necessary.
        // If the new capacity is <= length(), the length will be reduced. (length will never
        // increase from this call, however.) Most code should never need to use this method,
        // as the standard growth algorithm is smart enough for typical use; it's provided mainly for
        // Array / Vector code that needs this level of control.
        void set_capacity(uint32_t cap);
        
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
        
        // Replace the item at the given index with the new value.
        // This call *will not* expand the List if necessary; if you specify a value >= length()
        // we will assert, and cause unpredictable behavior in release builds. This is an unsafe
        // call that should be used *only* when the caller has already verified that the index is
        // valid; it's only provided for some superhot code paths where this is the case
        // (e.g., inside the Array implementation). Most code should never use this call;
        // instead, use set(), which is safer and only slightly slower.
        void replace(uint32_t index, T value);

        // Append the value to the end of the ListImpl, growing the ListImpl if necessary.
        void add(T value);
        
        // Append the given ListImpl to the end of this ListImpl, growing if necessary.
        void add(const ListImpl<T,ListHelper>& that);

        // Insert "count" of the the given value at index. The item previously at index will then be at index+count.
        void insert(uint32_t index, T value, uint32_t count = 1);

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

        // This unusual method should only be called if the MMGC instance might be destroyed
        // *before* the List dtor can run, which can happen in some obscure situations
        // in Flash/AIR. This destroys all storage in the List, but renders the List unsafe
        // to use afterwards.
        // *** DANGER*** Most code should never need (or want) to use this call;
        // it renders the list unsafe to use, and calling *any* method on the list afterwards
        // (other than the dtor or isDestroyed()) will result in a crash.
        void destroy();

        // return true iff destroy() has been called for this list.
        bool isDestroyed() const;

        // Trace GC pointers in the owned data, if appropriate for the data type.
        void gcTrace(MMgc::GC* gc);

        // This removes all items from the list that have have a value of null/0.
        // This is currently used only to implement WeakRefList::removeCollectedItems,
        // and is not exposed via other lists.
        // Return the number of items removed.
        uint32_t removeNullItems();
        
    private:
        ListImpl<T,ListHelper>& operator=(const ListImpl<T,ListHelper>& other); // unimplemented
        explicit ListImpl(const ListImpl<T,ListHelper>& other);                 // unimplemented
        void* operator new(size_t size);                                        // unimplemented, use HeapList instead

        void ensureCapacityExtra(uint32_t cap, uint32_t extra);
        
        // null the m_data pointer and free the storage
        void freeData(MMgc::GC* gc);

        // Update ListData pointer using a WriteBarrier if necessary.
        // This will assert if the address of m_data isn't GC or stack
        // memory (ie is unreachable by the GC).  GCRoots count
        // as GC memory.
        void wbData(typename ListHelper::LISTDATA* newData);
 
        // This function shouldn't be called directly; it's intended to be called
        // only by ensureCapacity(), which does an inline capacity check
        // before calling (which is a clear performance win).
        void FASTCALL ensureCapacityImpl(uint32_t cap);

        static typename ListHelper::LISTDATA* allocData(MMgc::GC* gc, uint32_t cap);

    private:
        typename ListHelper::LISTDATA* m_data; // If GC-allocated, this is written with explicit WB
    };

    // ----------------------------

    template<class T>
    class GCList : public MMgc::GCInlineObject
    {
    private:
        typedef ListImpl<MMgc::GCObject*, GCListHelper> LIST;
        
    public:
        typedef T* TYPE;
        
    public:
        explicit GCList(MMgc::GC* gc,
                        uint32_t capacity,
                        const TYPE* args = NULL);

        bool isEmpty() const;
        uint32_t length() const;
        uint32_t capacity() const;
        TYPE get(uint32_t index) const;
        TYPE first() const;
        TYPE last() const;
        void set(uint32_t index, TYPE value);
        void replace(uint32_t index, TYPE value);
        void add(TYPE value);
        void add(const GCList<T>& that);
        void insert(uint32_t index, TYPE value, uint32_t count = 1);
        void insert(uint32_t index, const TYPE* args, uint32_t argc);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const TYPE* args);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const GCList<T>& args, uint32_t argsOffset);
        void reverse();
        void clear();
        int32_t indexOf(TYPE value) const;
        int32_t lastIndexOf(TYPE value) const;
        TYPE removeAt(uint32_t index);
        TYPE removeFirst();
        TYPE removeLast();
        TYPE operator[](uint32_t index) const;
        void ensureCapacity(uint32_t cap);
        uint64_t bytesUsed() const;
        void destroy();
        bool isDestroyed() const;
        void gcTrace(MMgc::GC* gc);

    private:
        GCList<T>& operator=(const GCList<T>& other);     // unimplemented
        explicit GCList(const GCList<T>& other);          // unimplemented
        void* operator new(size_t size);                  // unimplemented, use HeapList instead

    private:
        LIST m_list;
    };

    // ----------------------------

    template<class T>
    class RCList : public MMgc::GCInlineObject
    {
    private:
        typedef ListImpl<MMgc::RCObject*, RCListHelper> LIST;
        
    public:
        typedef T* TYPE;
        
    public:
        explicit RCList(MMgc::GC* gc,
                        uint32_t capacity,
                        const TYPE* args = NULL);

        bool isEmpty() const;
        uint32_t length() const;
        uint32_t capacity() const;
        TYPE get(uint32_t index) const;
        TYPE first() const;
        TYPE last() const;
        void set(uint32_t index, TYPE value);
        void replace(uint32_t index, TYPE value);
        void add(TYPE value);
        void add(const RCList<T>& that);
        void insert(uint32_t index, TYPE value, uint32_t count = 1);
        void insert(uint32_t index, const TYPE* args, uint32_t argc);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const TYPE* args);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const RCList<T>& args, uint32_t argsOffset);
        void reverse();
        void clear();
        int32_t indexOf(TYPE value) const;
        int32_t lastIndexOf(TYPE value) const;
        TYPE removeAt(uint32_t index);
        TYPE removeFirst();
        TYPE removeLast();
        TYPE operator[](uint32_t index) const;
        void ensureCapacity(uint32_t cap);
        uint64_t bytesUsed() const;
        void destroy();
        bool isDestroyed() const;
        void gcTrace(MMgc::GC* gc);

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
    class UnmanagedPointerList : public MMgc::GCInlineObject
    {
    private:
        typedef ListImpl< UnmanagedPointer, DataListHelper<UnmanagedPointer> > LIST;
        
    public:
        typedef T TYPE;
        
    public:
        explicit UnmanagedPointerList(MMgc::GC* gc,
                                      uint32_t capacity,
                                      const T* args = NULL);

        bool isEmpty() const;
        uint32_t length() const;
        uint32_t capacity() const;
        T get(uint32_t index) const;
        T first() const;
        T last() const;
        void set(uint32_t index, T value);
        void replace(uint32_t index, T value);
        void add(T value);
        void add(const UnmanagedPointerList<T>& that);
        void insert(uint32_t index, T value, uint32_t count = 1);
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
        void destroy();
        bool isDestroyed() const;
        void gcTrace(MMgc::GC* gc);

    private:
        UnmanagedPointerList<T>& operator=(const UnmanagedPointerList<T>& other);       // unimplemented
        explicit UnmanagedPointerList(const UnmanagedPointerList<T>& other);            // unimplemented
        void* operator new(size_t size);                                                // unimplemented, use HeapList instead

    private:
        LIST m_list;
    };

    // ----------------------------
    template<class T>
    class WeakRefList : public MMgc::GCInlineObject
    {
    private:
        typedef ListImpl<MMgc::GCObject*, WeakRefListHelper> LIST;
        
    public:
        typedef T* TYPE;
        
    public:
        explicit WeakRefList(MMgc::GC* gc,
                             uint32_t capacity,
                             const TYPE* args = NULL);

        bool isEmpty() const;
        uint32_t length() const;
        uint32_t capacity() const;
        TYPE get(uint32_t index) const;
        TYPE first() const;
        TYPE last() const;
        void set(uint32_t index, TYPE value);
        void replace(uint32_t index, TYPE value);
        void add(TYPE value);
        void add(const WeakRefList<T>& that);
        void insert(uint32_t index, TYPE value, uint32_t count = 1);
        void insert(uint32_t index, const TYPE* args, uint32_t argc);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const TYPE* args);
        void splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const WeakRefList<T>& args, uint32_t argsOffset);
        void reverse();
        void clear();
        int32_t indexOf(TYPE value) const;
        int32_t lastIndexOf(TYPE value) const;
        TYPE removeAt(uint32_t index);
        TYPE removeFirst();
        TYPE removeLast();
        TYPE operator[](uint32_t index) const;
        void ensureCapacity(uint32_t cap);
        uint64_t bytesUsed() const;
        void destroy();
        bool isDestroyed() const;
        void gcTrace(MMgc::GC* gc);

        // This removes all items from the list that have been collected.
        // Return the number of items removed.
        uint32_t removeCollectedItems();

    private:
        WeakRefList<T>& operator=(const WeakRefList<T>& other);     // unimplemented
        explicit WeakRefList(const WeakRefList<T>& other);          // unimplemented
        void* operator new(size_t size);                            // unimplemented, use HeapList instead

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
        
    public:
        explicit DataList(MMgc::GC* gc,
                          uint32_t capacity,
                          const T* args = NULL);

    private:
        DataList<T>& operator=(const DataList<T>& other);       // unimplemented
        explicit DataList(const DataList<T>& other);            // unimplemented
        void* operator new(size_t size);                        // unimplemented, use HeapList instead
    };

    // ----------------------------

    // Some code internal to Flash/AIR needs to directly get/set the contents of DataLists;
    // this class provides an implicit lock/unlock mechanism. We guarantee that
    // the value returned by addr() is valid for reading/writing for the lifespan of
    // the DataListAccessor (but only for entries 0...get_length()-1, of course).
    // length() is identical to DataList::length() but is provided here for symmetry.
    // This should obviously only be used in cases where performance is critical, or
    // other circumstances requires it (eg, to pass an array of numbers to a GPU
    // without intermediate copying). Note that it is explicitly legal to pass
    // a NULL DataList to the ctor (which will cause addr() to also return NULL
    // and length() to return 0). This class must be used only on the stack.
    template<class T>
    class DataListAccessor
    {
    public:
        explicit DataListAccessor(DataList<T>* v);
        T* addr();
        uint32_t length();

    private:
        DataList<T>* m_list;

    private:
        void* operator new(size_t size);                                    // unimplemented
    };

    // ----------------------------

    // A conservatively traced heap-allocated list of managed objects.

    template<class T>
    class HeapList : public MMgc::GCFinalizedObject
    {
    public:
        T list;
    public:
        explicit HeapList(MMgc::GC* gc,
                          uint32_t capacity,
                          const typename T::TYPE* args = NULL);
    };
    
    // ----------------------------

    // An exactly traced heap-allocated list.

    template<class T>
    class ExactHeapList : public HeapList<T>
    {
    private:
        explicit ExactHeapList(MMgc::GC* gc,
                               uint32_t capacity,
                               const typename T::TYPE* args = NULL)
            : HeapList<T>(gc, capacity, args)
        {
        }
            
    public:
        REALLY_INLINE static ExactHeapList* create(MMgc::GC* gc,
                                                   uint32_t capacity,
                                                   const typename T::TYPE* args = NULL)
        {
            return new (gc, MMgc::kExact) ExactHeapList(gc, capacity, args);
        }
        
        virtual bool gcTrace(MMgc::GC* gc, size_t cursor)
        {
            (void)cursor;
            this->list.gcTrace(gc);
            return false;
        }
    };
    
    // ----------------------------

}

#endif /* __avmplus_List__ */
