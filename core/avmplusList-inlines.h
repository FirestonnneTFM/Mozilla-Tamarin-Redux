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

#ifndef __avmplus_List_inlines__
#define __avmplus_List_inlines__

namespace avmplus
{
    // ----------------------------

    template<class T>
    REALLY_INLINE /*static*/ MMgc::FixedMallocOpts DataListHelper<T>::allocFlags()
    {
        return MMgc::kNone;
    }

    template<class T>
    REALLY_INLINE /*static*/ typename DataListHelper<T>::ALLOCATOR* DataListHelper<T>::getAllocator(LISTDATA* /*data*/)
    {
        return MMgc::FixedMalloc::GetFixedMalloc();
    }

    template<class T>
    REALLY_INLINE /*static*/ void DataListHelper<T>::wbData(ALLOCATOR* /*allocator*/, const void* /*container*/, LISTDATA** address, LISTDATA* data)
    {
        *address = data;
    }

    template<class T>
    REALLY_INLINE /*static*/ typename DataListHelper<T>::TYPE DataListHelper<T>::load(LISTDATA* data, uint32_t index)
    {
        AvmAssert(data != NULL);
        return data->entries[index];
    }

    template<class T>
    REALLY_INLINE /*static*/ void DataListHelper<T>::store(ALLOCATOR* /*allocator*/, LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        data->entries[index] = value;
    }

    template<class T>
    REALLY_INLINE /*static*/ void DataListHelper<T>::storeEmpty(ALLOCATOR* /*allocator*/, LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        AvmAssert(data->entries[index] == 0);
        data->entries[index] = value;
    }

    template<class T>
    REALLY_INLINE /*static*/ void DataListHelper<T>::clearRange(LISTDATA* data, uint32_t start, uint32_t count)
    {
        AvmAssert(start + count <= data->len);
        AvmAssert(count > 0);
        VMPI_memset(&data->entries[start], 0, count*sizeof(T));
    }

    template<class T>
    REALLY_INLINE /*static*/ void DataListHelper<T>::moveRange(ALLOCATOR* /*allocator*/, LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count)
    {
        VMPI_memmove(&data->entries[dstStart], &data->entries[srcStart], count * sizeof(T));
    }

    // ----------------------------

    REALLY_INLINE /*static*/ MMgc::GC::AllocFlags GCListHelper::allocFlags()
    {
        return (MMgc::GC::AllocFlags)(MMgc::GC::kContainsPointers | MMgc::GC::kZero);
    }

    REALLY_INLINE /*static*/ GCListHelper::ALLOCATOR* GCListHelper::getAllocator(LISTDATA* data)
    {
        AvmAssert(data != NULL);
        return MMgc::GC::GetGC(data);
    }

    REALLY_INLINE /*static*/ void GCListHelper::wbData(ALLOCATOR* allocator, const void* container, LISTDATA** address, LISTDATA* data)
    {
        if (allocator->IsPointerToGCPage(container))
        {
            WB(allocator, allocator->FindBeginningFast(container), address, data);
        }
        else
        {
            *address = data;
        }
    }

    REALLY_INLINE /*static*/ GCListHelper::TYPE GCListHelper::load(LISTDATA* data, uint32_t index)
    {
        AvmAssert(data != NULL);
        return data->entries[index];
    }

    REALLY_INLINE /*static*/ void GCListHelper::store(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        WB(allocator, data, &data->entries[index], value);
    }

    REALLY_INLINE /*static*/ void GCListHelper::storeEmpty(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        AvmAssert(data->entries[index] == 0);
        WB(allocator, data, &data->entries[index], value);
    }

    REALLY_INLINE /*static*/ void GCListHelper::clearRange(LISTDATA* data, uint32_t start, uint32_t count)
    {
        AvmAssert(start + count <= data->len);
        AvmAssert(count > 0);
        VMPI_memset(&data->entries[start], 0, count*sizeof(MMgc::GCObject*));
    }

    REALLY_INLINE /*static*/ void GCListHelper::moveRange(ALLOCATOR* allocator, LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count)
    {
        allocator->movePointersWithinBlock((void**)data,
                                           uint32_t((char*)(&data->entries[dstStart]) - (char*)data),
                                           uint32_t((char*)(&data->entries[srcStart]) - (char*)data),
                                           count,
                                           /*zeroEmptied*/ true);
    }

    // ----------------------------

    REALLY_INLINE /*static*/ MMgc::GC::AllocFlags RCListHelper::allocFlags()
    {
        return (MMgc::GC::AllocFlags)(MMgc::GC::kContainsPointers | MMgc::GC::kZero);
    }

    REALLY_INLINE /*static*/ RCListHelper::ALLOCATOR* RCListHelper::getAllocator(LISTDATA* data)
    {
        AvmAssert(data != NULL);
        return MMgc::GC::GetGC(data);
    }

    REALLY_INLINE /*static*/ void RCListHelper::wbData(ALLOCATOR* allocator, const void* container, LISTDATA** address, LISTDATA* data)
    {
        if (allocator->IsPointerToGCPage(container))
        {
            WB(allocator, allocator->FindBeginningFast(container), address, data);
        }
        else
        {
            *address = data;
        }
    }

    REALLY_INLINE /*static*/ RCListHelper::TYPE RCListHelper::load(LISTDATA* data, uint32_t index)
    {
        AvmAssert(data != NULL);
        return data->entries[index];
    }

    REALLY_INLINE /*static*/ void RCListHelper::store(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        WBRC(allocator, data, &data->entries[index], value);
    }

    REALLY_INLINE /*static*/ void RCListHelper::storeEmpty(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        AvmAssert(data->entries[index] == 0);
        // We can't use WriteBarrierRC_ctor here, as it will call GetGC() on the address, which might be
        // wrong if the allocation is large. Instead, replicate the necessary code inline (ugh) in
        // the tradition of AvmCore::atomWriteBarrier_ctor...
        if (value)
        {
            if (allocator->IncrementalMarking())
                allocator->InlineWriteBarrierTrap(data);
            value->IncrementRef();
            data->entries[index] = value;
        }
    }

    REALLY_INLINE /*static*/ void RCListHelper::clearRange(LISTDATA* data, uint32_t start, uint32_t count)
    {
        AvmAssert(start + count <= data->len);
        AvmAssert(count > 0);
        for (uint32_t i = start, n = start + count; i < n; i++)
        {
            if (data->entries[i])
            {
                data->entries[i]->DecrementRef();
                data->entries[i] = 0;
            }
        }
    }

    REALLY_INLINE /*static*/ void RCListHelper::moveRange(ALLOCATOR* allocator, LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count)
    {
        allocator->movePointersWithinBlock((void**)data,
                                           uint32_t((char*)(&data->entries[dstStart]) - (char*)data),
                                           uint32_t((char*)(&data->entries[srcStart]) - (char*)data),
                                           count,
                                           /*zeroEmptied*/ true);
    }

     // ----------------------------

    REALLY_INLINE /*static*/ MMgc::GC::AllocFlags AtomListHelper::allocFlags()
    {
        return (MMgc::GC::AllocFlags)(MMgc::GC::kContainsPointers | MMgc::GC::kZero);
    }

    REALLY_INLINE /*static*/ RCListHelper::ALLOCATOR* AtomListHelper::getAllocator(LISTDATA* data)
    {
        AvmAssert(data != NULL);
        return MMgc::GC::GetGC(data);
    }

    REALLY_INLINE /*static*/ void AtomListHelper::wbData(ALLOCATOR* allocator, const void* container, LISTDATA** address, LISTDATA* data)
    {
        if (allocator->IsPointerToGCPage(container))
        {
            WB(allocator, allocator->FindBeginningFast(container), address, data);
        }
        else
        {
            *address = data;
        }
    }

    REALLY_INLINE /*static*/ AtomListHelper::TYPE AtomListHelper::load(LISTDATA* data, uint32_t index)
    {
        AvmAssert(data != NULL);
        return data->entries[index];
    }

    REALLY_INLINE /*static*/ void AtomListHelper::store(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        AvmCore::atomWriteBarrier(allocator, data, &data->entries[index], value);
    }

    REALLY_INLINE /*static*/ void AtomListHelper::storeEmpty(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        AvmAssert(data->entries[index] == 0);
        AvmCore::atomWriteBarrier_ctor(allocator, data, &data->entries[index], value);
    }

    REALLY_INLINE /*static*/ void AtomListHelper::clearRange(LISTDATA* data, uint32_t start, uint32_t count)
    {
        AvmAssert(start + count <= data->len);
        AvmAssert(count > 0);
        AvmCore::decrementAtomRegion(&data->entries[start], count);
    }

    REALLY_INLINE /*static*/ void AtomListHelper::moveRange(ALLOCATOR* allocator, LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count)
    {
        allocator->movePointersWithinBlock((void**)data,
                                           uint32_t((char*)(&data->entries[dstStart]) - (char*)data),
                                           uint32_t((char*)(&data->entries[srcStart]) - (char*)data),
                                           count,
                                           /*zeroEmptied*/ true);
    }

    // ----------------------------

    REALLY_INLINE /*static*/ MMgc::GC::AllocFlags WeakRefListHelper::allocFlags()
    {
        return (MMgc::GC::AllocFlags)(MMgc::GC::kContainsPointers | MMgc::GC::kZero);
    }

    REALLY_INLINE /*static*/ WeakRefListHelper::ALLOCATOR* WeakRefListHelper::getAllocator(LISTDATA* data)
    {
        AvmAssert(data != NULL);
        return MMgc::GC::GetGC(data);
    }

   REALLY_INLINE /*static*/ void WeakRefListHelper::wbData(ALLOCATOR* allocator, const void* container, LISTDATA** address, LISTDATA* data)
    {
        if (allocator->IsPointerToGCPage(container))
        {
            WB(allocator, allocator->FindBeginningFast(container), address, data);
        }
        else
        {
            *address = data;
        }
    }

    REALLY_INLINE /*static*/ WeakRefListHelper::TYPE WeakRefListHelper::load(LISTDATA* data, uint32_t index)
    {
        AvmAssert(data != NULL);
        MMgc::GCWeakRef* weak = data->entries[index];
        return weak ? (TYPE)weak->get() : NULL;
    }

    REALLY_INLINE /*static*/ void WeakRefListHelper::store(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        MMgc::GCWeakRef* weak = value ? value->GetWeakRef() : NULL;
        WB(allocator, data, &data->entries[index], weak);
    }

    REALLY_INLINE /*static*/ void WeakRefListHelper::storeEmpty(ALLOCATOR* allocator, LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        AvmAssert(data->entries[index] == 0);
        store(allocator, data, index, value);
    }

    REALLY_INLINE /*static*/ void WeakRefListHelper::clearRange(LISTDATA* data, uint32_t start, uint32_t count)
    {
        AvmAssert(start + count <= data->len);
        AvmAssert(count > 0);
        VMPI_memset(&data->entries[start], 0, count*sizeof(STORAGE));
    }

    REALLY_INLINE /*static*/ void WeakRefListHelper::moveRange(ALLOCATOR* allocator, LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count)
    {
        allocator->movePointersWithinBlock((void**)data,
                                           uint32_t((char*)(&data->entries[dstStart]) - (char*)data),
                                           uint32_t((char*)(&data->entries[srcStart]) - (char*)data),
                                           count,
                                           /*zeroEmptied*/ true);
    }

    // ----------------------------

    template<class T, class ListHelper>
    REALLY_INLINE bool ListImpl<T,ListHelper>::isEmpty() const
    {
        return m_data->len == 0;
    }

    template<class T, class ListHelper>
    REALLY_INLINE uint32_t ListImpl<T,ListHelper>::length() const
    {
        return m_data->len;
    }

    template<class T, class ListHelper>
    REALLY_INLINE uint32_t ListImpl<T,ListHelper>::capacity() const
    {
        return m_data->cap;
    }

    template<class T, class ListHelper>
    REALLY_INLINE T ListImpl<T,ListHelper>::get(uint32_t index) const
    {
        AvmAssert(index < m_data->len);
        return ListHelper::load(m_data, index);
    }

    template<class T, class ListHelper>
    REALLY_INLINE void ListImpl<T,ListHelper>::set(uint32_t index, T value)
    {
        // Yes, this is worth inlining, according to performance testing.
        if (index >= m_data->len)
        {
            ensureCapacityExtra(index, 1);
            m_data->len = index+1;
        }
        ListHelper::store(ListHelper::getAllocator(m_data), m_data, index, value);
    }

    template<class T, class ListHelper>
    REALLY_INLINE T ListImpl<T,ListHelper>::first() const
    {
        AvmAssert(m_data->len > 0);
        return ListHelper::load(m_data, 0);
    }

    template<class T, class ListHelper>
    REALLY_INLINE T ListImpl<T,ListHelper>::last() const
    {
        AvmAssert(m_data->len > 0);
        return ListHelper::load(m_data, m_data->len-1);
    }

    template<class T, class ListHelper>
    REALLY_INLINE T ListImpl<T,ListHelper>::removeFirst()
    {
        AvmAssert(!isEmpty());
        return isEmpty() ? (T)0 : removeAt(0);
    }

    template<class T, class ListHelper>
    REALLY_INLINE T ListImpl<T,ListHelper>::removeLast()
    {
        AvmAssert(!isEmpty());
        return isEmpty() ? (T)0 : removeAt(m_data->len-1);
    }

    template<class T, class ListHelper>
    REALLY_INLINE T ListImpl<T,ListHelper>::operator[](uint32_t index) const
    {
        AvmAssert(index < m_data->len);
        return ListHelper::load(m_data, index);
    }

    template<class T, class ListHelper>
    REALLY_INLINE void ListImpl<T,ListHelper>::ensureCapacityExtra(uint32_t cap, uint32_t extra)
    {
        MMGC_STATIC_ASSERT(0xFFFFFFFF > kListMaxLength);
        uint32_t const ncap = (cap > 0xFFFFFFFF - extra) ?  // if true, cap + extra will overflow a uint32_t...
                              0xFFFFFFFF :                  // ...in that case, choose a size that will definitely fail in ensureCapacityImpl.
                              (cap + extra);                
        
        if (ncap > m_data->cap)
        {
            ensureCapacityImpl(ncap);
        }
    }

    template<class T, class ListHelper>
    REALLY_INLINE void ListImpl<T,ListHelper>::ensureCapacity(uint32_t cap)
    {
        AvmAssert(m_data != NULL);
        if (cap > m_data->cap)
        {
            ensureCapacityImpl(cap);
        }
    }

    template<class T, class ListHelper>
    REALLY_INLINE uint64_t ListImpl<T,ListHelper>::bytesUsed() const
    {
        AvmAssert(m_data != NULL);
        return ListHelper::getAllocator(m_data)->Size(m_data);
    }

    template<class T, class ListHelper>
    REALLY_INLINE /*static*/ typename ListHelper::LISTDATA* ListImpl<T,ListHelper>::allocData(typename ListHelper::ALLOCATOR* allocator, uint32_t cap) 
    {
        AvmAssert(cap <= kListMaxLength);
        
        // Simplify overflow checking by figuring out how many extra T's worth of memory
        // we need to allocate and bumping cap by that much (thus effectively delegating overflow
        // checking to Calloc). We won't overflow because we know cap <= kListMaxLength.
        size_t const ld_minus_t = sizeof(typename ListHelper::LISTDATA) - sizeof(T);
        size_t const extra = (ld_minus_t >= sizeof(T)) ?
                                (ld_minus_t / sizeof(T)) :
                                1;
        typename ListHelper::LISTDATA* newData = (typename ListHelper::LISTDATA*) allocator->Calloc(cap + extra, sizeof(T), ListHelper::allocFlags());
        newData->len = 0;
        newData->cap = cap;
        return newData;
    }
    
    // ----------------------------


    template<class T>
    REALLY_INLINE GCList<T>::GCList(ALLOCATOR* allocator, uint32_t capacity, const T* args)
        : m_list(allocator, capacity, (MMgc::GCObject* const*)args)
    {
        MMGC_STATIC_ASSERT((TypeSniffer<T>::isGCObject::value == true || TypeSniffer<T>::isGCFinalizedObject::value == true) &&
                            TypeSniffer<T>::isRCObject::value == false);
    }

    template<class T>
    REALLY_INLINE bool GCList<T>::isEmpty() const
    {
        return m_list.isEmpty();
    }

    template<class T>
    REALLY_INLINE uint32_t GCList<T>::length() const
    {
        return m_list.length();
    }

    template<class T>
    REALLY_INLINE uint32_t GCList<T>::capacity() const
    {
        return m_list.capacity();
    }

    template<class T>
    REALLY_INLINE T GCList<T>::get(uint32_t index) const
    {
        return (T)m_list.get(index);
    }

    template<class T>
    REALLY_INLINE T GCList<T>::first() const
    {
        return (T)m_list.first();
    }

    template<class T>
    REALLY_INLINE T GCList<T>::last() const
    {
        return (T)m_list.last();
    }

    template<class T>
    REALLY_INLINE void GCList<T>::set(uint32_t index, T value)
    {
        m_list.set(index, to_gc(value));
    }

    template<class T>
    REALLY_INLINE void GCList<T>::add(T value)
    {
        m_list.add(to_gc(value));
    }

    template<class T>
    REALLY_INLINE void GCList<T>::add(const GCList<T>& that)
    {
        m_list.add(*(const LIST*)&that);
    }

    template<class T>
    REALLY_INLINE void GCList<T>::insert(uint32_t index, T value)
    {
        m_list.insert(index, to_gc(value));
    }

    template<class T>
    REALLY_INLINE void GCList<T>::insert(uint32_t index, const T* args, uint32_t argc)
    {
        m_list.insert(index, args, argc);
    }

    template<class T>
    REALLY_INLINE void GCList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const T* args)
    {
        m_list.splice(insertPoint, insertCount, deleteCount, args);
    }

    template<class T>
    REALLY_INLINE void GCList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const GCList<T>& args, uint32_t argsOffset)
    {
        m_list.splice(insertPoint, insertCount, deleteCount, args, argsOffset);
    }

    template<class T>
    REALLY_INLINE void GCList<T>::reverse()
    {
        m_list.reverse();
    }

    template<class T>
    REALLY_INLINE void GCList<T>::clear()
    {
        m_list.clear();
    }

    template<class T>
    REALLY_INLINE int32_t GCList<T>::indexOf(T value) const
    {
        return m_list.indexOf(to_gc(value));
    }

    template<class T>
    REALLY_INLINE int32_t GCList<T>::lastIndexOf(T value) const
    {
        return m_list.lastIndexOf(to_gc(value));
    }

    template<class T>
    REALLY_INLINE T GCList<T>::removeAt(uint32_t index)
    {
        return (T)m_list.removeAt(index);
    }

    template<class T>
    REALLY_INLINE T GCList<T>::removeFirst()
    {
        return (T)m_list.removeFirst();
    }

    template<class T>
    REALLY_INLINE T GCList<T>::removeLast()
    {
        return (T)m_list.removeLast();
    }

    template<class T>
    REALLY_INLINE T GCList<T>::operator[](uint32_t index) const
    {
        return (T)m_list[index];
    }

    template<class T>
    REALLY_INLINE void GCList<T>::ensureCapacity(uint32_t cap)
    {
        m_list.ensureCapacity(cap);
    }

    template<class T>
    REALLY_INLINE uint64_t GCList<T>::bytesUsed() const
    {
        return m_list.bytesUsed();
    }

    // ----------------------------

    template<class T>
    REALLY_INLINE RCList<T>::RCList(ALLOCATOR* allocator, uint32_t capacity, const T* args)
        : m_list(allocator, capacity, (MMgc::RCObject* const*)args)
    {
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isRCObject::value == true);
    }

    template<class T>
    REALLY_INLINE bool RCList<T>::isEmpty() const
    {
        return m_list.isEmpty();
    }

    template<class T>
    REALLY_INLINE uint32_t RCList<T>::length() const
    {
        return m_list.length();
    }

    template<class T>
    REALLY_INLINE uint32_t RCList<T>::capacity() const
    {
        return m_list.capacity();
    }

    template<class T>
    REALLY_INLINE T RCList<T>::get(uint32_t index) const
    {
        return (T)m_list.get(index);
    }

    template<class T>
    REALLY_INLINE T RCList<T>::first() const
    {
        return (T)m_list.first();
    }

    template<class T>
    REALLY_INLINE T RCList<T>::last() const
    {
        return (T)m_list.last();
    }

    template<class T>
    REALLY_INLINE void RCList<T>::set(uint32_t index, T value)
    {
        m_list.set(index, value);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::add(T value)
    {
        m_list.add(value);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::add(const RCList<T>& that)
    {
        m_list.add(*(const LIST*)&that);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::insert(uint32_t index, T value)
    {
        m_list.insert(index, value);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::insert(uint32_t index, const T* args, uint32_t argc)
    {
        m_list.insert(index, args, argc);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const T* args)
    {
        m_list.splice(insertPoint, insertCount, deleteCount, args);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const RCList<T>& args, uint32_t argsOffset)
    {
        m_list.splice(insertPoint, insertCount, deleteCount, args, argsOffset);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::reverse()
    {
        m_list.reverse();
    }

    template<class T>
    REALLY_INLINE void RCList<T>::clear()
    {
        m_list.clear();
    }

    template<class T>
    REALLY_INLINE int32_t RCList<T>::indexOf(T value) const
    {
        return m_list.indexOf(value);
    }

    template<class T>
    REALLY_INLINE int32_t RCList<T>::lastIndexOf(T value) const
    {
        return m_list.lastIndexOf(value);
    }

    template<class T>
    REALLY_INLINE T RCList<T>::removeAt(uint32_t index)
    {
        return (T)m_list.removeAt(index);
    }

    template<class T>
    REALLY_INLINE T RCList<T>::removeFirst()
    {
        return (T)m_list.removeFirst();
    }

    template<class T>
    REALLY_INLINE T RCList<T>::removeLast()
    {
        return (T)m_list.removeLast();
    }

    template<class T>
    REALLY_INLINE T RCList<T>::operator[](uint32_t index) const
    {
        return (T)m_list[index];
    }

    template<class T>
    REALLY_INLINE void RCList<T>::ensureCapacity(uint32_t cap)
    {
        m_list.ensureCapacity(cap);
    }

    template<class T>
    REALLY_INLINE uint64_t RCList<T>::bytesUsed() const
    {
        return m_list.bytesUsed();
    }


    // ----------------------------

    template<class T>
    REALLY_INLINE UnmanagedPointerList<T>::UnmanagedPointerList(ALLOCATOR* allocator, uint32_t capacity, const T* args)
        : m_list(allocator, capacity, (const UnmanagedPointer*)args)
    {
        // We must not be a GC/RCObject.
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isGCObject::value == false &&
                            TypeSniffer<T>::isGCFinalizedObject::value == false &&
                            TypeSniffer<T>::isRCObject::value == false);

        // BUT we MUST be a pointer type.
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isNonPointer::value == false);
    }

    template<class T>
    REALLY_INLINE bool UnmanagedPointerList<T>::isEmpty() const
    {
        return m_list.isEmpty();
    }

    template<class T>
    REALLY_INLINE uint32_t UnmanagedPointerList<T>::length() const
    {
        return m_list.length();
    }

    template<class T>
    REALLY_INLINE uint32_t UnmanagedPointerList<T>::capacity() const
    {
        return m_list.capacity();
    }

    template<class T>
    REALLY_INLINE T UnmanagedPointerList<T>::get(uint32_t index) const
    {
        return (T)m_list.get(index);
    }

    template<class T>
    REALLY_INLINE T UnmanagedPointerList<T>::first() const
    {
        return (T)m_list.first();
    }

    template<class T>
    REALLY_INLINE T UnmanagedPointerList<T>::last() const
    {
        return (T)m_list.last();
    }

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::set(uint32_t index, T value)
    {
        m_list.set(index, (UnmanagedPointer)value);
    }

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::add(T value)
    {
        m_list.add((UnmanagedPointer)value);
    }

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::add(const UnmanagedPointerList<T>& that)
    {
        m_list.add(*(const LIST*)&that);
    }

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::insert(uint32_t index, T value)
    {
        m_list.insert(index, (UnmanagedPointer)value);
    }

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::insert(uint32_t index, const T* args, uint32_t argc)
    {
        m_list.insert(index, args, argc);
    }

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const T* args)
    {
        m_list.splice(insertPoint, insertCount, deleteCount, args);
    }

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const UnmanagedPointerList<T>& args, uint32_t argsOffset)
    {
        m_list.splice(insertPoint, insertCount, deleteCount, args, argsOffset);
    }

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::reverse()
    {
        m_list.reverse();
    }

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::clear()
    {
        m_list.clear();
    }

    template<class T>
    REALLY_INLINE int32_t UnmanagedPointerList<T>::indexOf(T value) const
    {
        return m_list.indexOf(value);
    }

    template<class T>
    REALLY_INLINE int32_t UnmanagedPointerList<T>::lastIndexOf(T value) const
    {
        return m_list.lastIndexOf(value);
    }

    template<class T>
    REALLY_INLINE T UnmanagedPointerList<T>::removeAt(uint32_t index)
    {
        return (T)m_list.removeAt(index);
    }

    template<class T>
    REALLY_INLINE T UnmanagedPointerList<T>::removeFirst()
    {
        return (T)m_list.removeFirst();
    }

    template<class T>
    REALLY_INLINE T UnmanagedPointerList<T>::removeLast()
    {
        return (T)m_list.removeLast();
    }

    template<class T>
    REALLY_INLINE T UnmanagedPointerList<T>::operator[](uint32_t index) const
    {
        return (T)m_list[index];
    }

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::ensureCapacity(uint32_t cap)
    {
        m_list.ensureCapacity(cap);
    }

    template<class T>
    REALLY_INLINE uint64_t UnmanagedPointerList<T>::bytesUsed() const
    {
        return m_list.bytesUsed();
    }

    // ----------------------------

    template<class T>
    REALLY_INLINE WeakRefList<T>::WeakRefList(ALLOCATOR* allocator, uint32_t capacity, const T* args)
        : m_list(allocator, capacity, (MMgc::GCObject* const*)args)
    {
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isGCObject::value ||
                            TypeSniffer<T>::isGCFinalizedObject::value ||
                            TypeSniffer<T>::isRCObject::value);
    }

    template<class T>
    REALLY_INLINE bool WeakRefList<T>::isEmpty() const
    {
        return m_list.isEmpty();
    }

    template<class T>
    REALLY_INLINE uint32_t WeakRefList<T>::length() const
    {
        return m_list.length();
    }

    template<class T>
    REALLY_INLINE uint32_t WeakRefList<T>::capacity() const
    {
        return m_list.capacity();
    }

    template<class T>
    REALLY_INLINE T WeakRefList<T>::get(uint32_t index) const
    {
        return (T)m_list.get(index);
    }

    template<class T>
    REALLY_INLINE T WeakRefList<T>::first() const
    {
        return (T)m_list.first();
    }

    template<class T>
    REALLY_INLINE T WeakRefList<T>::last() const
    {
        return (T)m_list.last();
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::set(uint32_t index, T value)
    {
        m_list.set(index, to_gc(value));
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::add(T value)
    {
        m_list.add(to_gc(value));
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::add(const WeakRefList<T>& that)
    {
        m_list.add(*(const LIST*)&that);
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::insert(uint32_t index, T value)
    {
        m_list.insert(index, to_gc(value));
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::insert(uint32_t index, const T* args, uint32_t argc)
    {
        m_list.insert(index, args, argc);
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const T* args)
    {
        m_list.splice(insertPoint, insertCount, deleteCount, args);
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const WeakRefList<T>& args, uint32_t argsOffset)
    {
        m_list.splice(insertPoint, insertCount, deleteCount, args, argsOffset);
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::reverse()
    {
        m_list.reverse();
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::clear()
    {
        m_list.clear();
    }

    template<class T>
    REALLY_INLINE int32_t WeakRefList<T>::indexOf(T value) const
    {
        return m_list.indexOf(to_gc(value));
    }

    template<class T>
    REALLY_INLINE int32_t WeakRefList<T>::lastIndexOf(T value) const
    {
        return m_list.lastIndexOf(to_gc(value));
    }

    template<class T>
    REALLY_INLINE T WeakRefList<T>::removeAt(uint32_t index)
    {
        return (T)m_list.removeAt(index);
    }

    template<class T>
    REALLY_INLINE T WeakRefList<T>::removeFirst()
    {
        return (T)m_list.removeFirst();
    }

    template<class T>
    REALLY_INLINE T WeakRefList<T>::removeLast()
    {
        return (T)m_list.removeLast();
    }

    template<class T>
    REALLY_INLINE T WeakRefList<T>::operator[](uint32_t index) const
    {
        return (T)m_list[index];
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::ensureCapacity(uint32_t cap)
    {
        m_list.ensureCapacity(cap);
    }

    template<class T>
    REALLY_INLINE uint64_t WeakRefList<T>::bytesUsed() const
    {
        return m_list.bytesUsed();
    }

    // ----------------------------

    template<class T>
    REALLY_INLINE DataList<T>::DataList(ALLOCATOR* allocator, uint32_t capacity, const T* args)
        : ListImpl< T, DataListHelper<T> >(allocator, capacity, args)
    {
        // We must not be a pointer type.
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isNonPointer::value == true);

        // If you make a NonGCObject list that holds GC/RCObjects, you are almost
        // certainly making a mistake. (Redundant to the above check, but left in
        // for emphasis.)
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isGCObject::value == false &&
                            TypeSniffer<T>::isGCFinalizedObject::value == false &&
                            TypeSniffer<T>::isRCObject::value == false);
    }

    // ----------------------------

    template<class T>
    REALLY_INLINE HeapList<T>::HeapList(typename T::ALLOCATOR* allocator, uint32_t capacity, const typename T::TYPE* args)
        : list(allocator, capacity, args)
    {
    }
}

#endif /* __avmplus_List_inlines__ */
