/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2009
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

#ifndef __avmplus_FixedHeapUtils__
#define __avmplus_FixedHeapUtils__

namespace avmplus
{

    /*
     * Utility collection, allocated on the stack or as a member field, passed by value.
     */
    template <typename TYPE>
    struct FixedHeapArray {
        TYPE* values;
        int length;
        FixedHeapArray(TYPE* values, int length);
        FixedHeapArray();
        
        bool allocate(int length, bool canFail = false);
        bool resize(int newLength, bool canFail = false);
        void initialize(const TYPE* source);
        void deallocate();
    };


#if defined(WIN32)  // really a MSVC 
#define TYPENAME_KLUDGE typename 
#else 
#define TYPENAME_KLUDGE
#endif


    // HashTable implementation borrowed from the FP runtime.
    template <typename K, typename V>
    class FixedHeapHashTable
    {
    public:
        enum { kDefaultSize = 127 };
        
        FixedHeapHashTable(size_t size = kDefaultSize);
        virtual ~FixedHeapHashTable();
        
        bool InsertItem (K key, V value);
        bool RemoveItem(K key);
        bool LookupItem(K key, V*value);
        int GetNumItems() const;
        void Clear();


        class Iterator 
        {
        public:
            virtual void each(TYPENAME_KLUDGE K key, TYPENAME_KLUDGE V item) = 0;
            virtual ~Iterator();
        };

        void ForEach(TYPENAME_KLUDGE Iterator& iterator);
        
        struct Bucket 
        {
            Bucket *next;
            K key;
            V value;
        };

        // helper methods so subclasses can build/tear down with their vtables (and hence allocator
        // functions in tact)
    protected:
        void Init(size_t size);
    public:
        void Destroy();


    protected:
        virtual Bucket *BucketAlloc();
        virtual void BucketFree(Bucket *b);
        
        virtual Bucket **BucketArrayAlloc(size_t size);
        virtual void BucketArrayFree(Bucket **buckets);
        
        virtual uintptr_t HashKey(K key) const;
        virtual bool KeysEqual(K key1, const K key2) const;
        virtual void DestroyItem(K /*key*/, V /*value*/);

        bool Expand();        

        Bucket **m_buckets;
        int m_numItems;
        int m_size;
#ifdef DEBUG
        bool m_inIteration;
#endif

    };


    


    class FixedHeapRCObject 
    {
    public:
        FixedHeapRCObject();
        
        int32_t IncrementRef();
        int32_t DecrementRef();
        int32_t RefCount();
        
        virtual void destroy() = 0;
        virtual ~FixedHeapRCObject();

        
    protected:
        vmbase::AtomicCounter32 m_rcount;
    };


    template<class T, int TAG = 0>
    class FixedHeapRef
    {
    public:
        
        explicit FixedHeapRef();
        explicit FixedHeapRef(T* valuePtr);
        FixedHeapRef(const FixedHeapRef& other);
        virtual ~FixedHeapRef();

        void operator=(const FixedHeapRef& other);
        void operator=(T* tNew);
        operator T*() const;
        T* operator ->() const;
        T* operator()() const;

    private:
        void set(T* tNew);
        T* value() const;
        T* const* location() const;
        T* t;
    };

}
#endif
