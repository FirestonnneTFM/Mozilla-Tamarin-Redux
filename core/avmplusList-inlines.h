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
    template<>
    REALLY_INLINE bool TracedListData<Atom>::gcTrace(MMgc::GC* gc, size_t cursor)
    {
        const size_t work_increment = 2000/sizeof(void*);
        const size_t work_count = len;
        if (cursor * work_increment >= work_count)
            return false;

        size_t work = work_increment;
        bool more = true;
        if ((cursor + 1) * work_increment >= work_count)
        {
            work = work_count - (cursor * work_increment);
            more = false;
        }

        gc->TraceAtoms(entries + (cursor*work_increment), work);
        return more;
    }

    template<class T>
    inline bool TracedListData<T>::gcTrace(MMgc::GC* gc, size_t cursor)
    {
        const size_t work_increment = 2000/sizeof(void*);
        const size_t work_count = len;
        if (cursor * work_increment >= work_count)
            return false;
        
        size_t work = work_increment;
        bool more = true;
        if ((cursor + 1) * work_increment >= work_count)
        {
            work = work_count - (cursor * work_increment);
            more = false;
        }

        gc->TraceLocations(entries + (cursor*work_increment), work);
        return more;
    }

    // ----------------------------

    template<class T>
    REALLY_INLINE /*static*/ typename DataListHelper<T>::TYPE DataListHelper<T>::load(LISTDATA* data, uint32_t index)
    {
        AvmAssert(data != NULL);
        return data->entries[index];
    }

    template<class T>
    REALLY_INLINE /*static*/ void DataListHelper<T>::store(LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        data->entries[index] = value;
    }

    template<class T>
    REALLY_INLINE /*static*/ void DataListHelper<T>::storeInEmpty(LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        // This is commented out because it's not necessary for safety of a DataList,
        // and it can generate an assert in List::insert(), which uses storeInEmpty() for efficiency;
        // since DataListHelper::moveRange doesn't zero out the cleared space we could get this
        // assertion firing. Better to neuter this assertion than add a unnecessary zeroing-out
        // to moveRange() just to pacify it.
        // AvmAssert(data->entries[index] == 0);
        data->entries[index] = value;
    }

    template<class T>
    REALLY_INLINE /*static*/ void DataListHelper<T>::clearRange(LISTDATA* data, uint32_t start, uint32_t count)
    {
        AvmAssert(count > 0);
        VMPI_memset(&data->entries[start], 0, count*sizeof(T));
    }

    template<class T>
    REALLY_INLINE /*static*/ void DataListHelper<T>::moveRange(LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count)
    {
        VMPI_memmove(&data->entries[dstStart], &data->entries[srcStart], count * sizeof(T));
    }

    template<class T>
    REALLY_INLINE /*static*/ void DataListHelper<T>::gcTrace(MMgc::GC* gc, LISTDATA** loc)
    {
        gc->TraceLocation(loc);
    }

    // ----------------------------

    REALLY_INLINE /*static*/ GCListHelper::TYPE GCListHelper::load(LISTDATA* data, uint32_t index)
    {
        AvmAssert(data != NULL);
        return data->entries[index];
    }

    REALLY_INLINE /*static*/ void GCListHelper::store(LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        WB(data->gc(), data, &data->entries[index], value);
    }

    REALLY_INLINE /*static*/ void GCListHelper::storeInEmpty(LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        AvmAssert(data->entries[index] == 0);
        WB(data->gc(), data, &data->entries[index], value);
    }

    REALLY_INLINE /*static*/ void GCListHelper::clearRange(LISTDATA* data, uint32_t start, uint32_t count)
    {
        AvmAssert(count > 0);
        VMPI_memset(&data->entries[start], 0, count*sizeof(MMgc::GCObject*));
    }

    REALLY_INLINE /*static*/ void GCListHelper::moveRange(LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count)
    {
        AvmAssert(data != NULL);
        data->gc()->movePointersWithinBlock((void**)data,
                                           uint32_t((char*)(&data->entries[dstStart]) - (char*)data),
                                           uint32_t((char*)(&data->entries[srcStart]) - (char*)data),
                                           count,
                                           /*zeroEmptied*/ true);
    }

    REALLY_INLINE /*static*/ void GCListHelper::gcTrace(MMgc::GC* gc, LISTDATA** loc)
    {
        gc->TraceLocation(loc);
    }
    
    // ----------------------------

    REALLY_INLINE /*static*/ RCListHelper::TYPE RCListHelper::load(LISTDATA* data, uint32_t index)
    {
        AvmAssert(data != NULL);
        return data->entries[index];
    }

    REALLY_INLINE /*static*/ void RCListHelper::store(LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        WBRC(data->gc(), data, &data->entries[index], value);
    }

    REALLY_INLINE /*static*/ void RCListHelper::storeInEmpty(LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        AvmAssert(data->entries[index] == 0);
        // We can't use WriteBarrierRC_ctor here, as it will call GetGC() on the address, which might be
        // wrong if the allocation is large. Instead, replicate the necessary code inline (ugh) in
        // the tradition of AvmCore::atomWriteBarrier_ctor...
        if (value)
        {
            if (data->gc()->BarrierActive())
                data->gc()->InlineWriteBarrierTrap(data);
            value->IncrementRef();
            data->entries[index] = value;
        }
    }

    REALLY_INLINE /*static*/ void RCListHelper::clearRange(LISTDATA* data, uint32_t start, uint32_t count)
    {
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

    REALLY_INLINE /*static*/ void RCListHelper::moveRange(LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count)
    {
        AvmAssert(data != NULL);
        data->gc()->movePointersWithinBlock((void**)data,
                                           uint32_t((char*)(&data->entries[dstStart]) - (char*)data),
                                           uint32_t((char*)(&data->entries[srcStart]) - (char*)data),
                                           count,
                                           /*zeroEmptied*/ true);
    }

    REALLY_INLINE /*static*/ void RCListHelper::gcTrace(MMgc::GC* gc, LISTDATA** loc)
    {
        gc->TraceLocation(loc);
    }

    // ----------------------------

    REALLY_INLINE /*static*/ AtomListHelper::TYPE AtomListHelper::load(LISTDATA* data, uint32_t index)
    {
        AvmAssert(data != NULL);
        return data->entries[index];
    }

    REALLY_INLINE /*static*/ void AtomListHelper::store(LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        AvmCore::atomWriteBarrier(data->gc(), data, &data->entries[index], value);
    }

    REALLY_INLINE /*static*/ void AtomListHelper::storeInEmpty(LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        // newly-allocated space clears to 0; clearRange() clears to nullObjectAtom.
        // Both are "empty" as far as AtomList is concerned.
        AvmAssert(data->entries[index] == 0 || data->entries[index] == nullObjectAtom);
        AvmCore::atomWriteBarrier_ctor(data->gc(), data, &data->entries[index], value);
    }

    REALLY_INLINE /*static*/ void AtomListHelper::clearRange(LISTDATA* data, uint32_t start, uint32_t count)
    {
        AvmAssert(count > 0);
        AvmCore::decrementAtomRegion_null(&data->entries[start], count);
    }

    REALLY_INLINE /*static*/ void AtomListHelper::moveRange(LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count)
    {
        AvmAssert(data != NULL);
        data->gc()->movePointersWithinBlock((void**)data,
                                           uint32_t((char*)(&data->entries[dstStart]) - (char*)data),
                                           uint32_t((char*)(&data->entries[srcStart]) - (char*)data),
                                           count,
                                           /*zeroEmptied*/ true);
    }

    REALLY_INLINE /*static*/ void AtomListHelper::gcTrace(MMgc::GC* gc, LISTDATA** loc)
    {
        gc->TraceLocation(loc);
    }

    // ----------------------------

    REALLY_INLINE /*static*/ WeakRefListHelper::TYPE WeakRefListHelper::load(LISTDATA* data, uint32_t index)
    {
        AvmAssert(data != NULL);
        MMgc::GCWeakRef* weak = data->entries[index];
        return weak ? (TYPE)weak->get() : NULL;
    }

    REALLY_INLINE /*static*/ void WeakRefListHelper::store(LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        MMgc::GCWeakRef* weak = value ? value->GetWeakRef() : NULL;
        WB(data->gc(), data, &data->entries[index], weak);
    }

    REALLY_INLINE /*static*/ void WeakRefListHelper::storeInEmpty(LISTDATA* data, uint32_t index, TYPE value)
    {
        AvmAssert(data != NULL);
        AvmAssert(data->entries[index] == 0);
        store(data, index, value);
    }

    REALLY_INLINE /*static*/ void WeakRefListHelper::clearRange(LISTDATA* data, uint32_t start, uint32_t count)
    {
        AvmAssert(count > 0);
        VMPI_memset(&data->entries[start], 0, count*sizeof(STORAGE));
    }

    REALLY_INLINE /*static*/ void WeakRefListHelper::moveRange(LISTDATA* data, uint32_t srcStart, uint32_t dstStart, uint32_t count)
    {
        AvmAssert(data != NULL);
        data->gc()->movePointersWithinBlock((void**)data,
                                           uint32_t((char*)(&data->entries[dstStart]) - (char*)data),
                                           uint32_t((char*)(&data->entries[srcStart]) - (char*)data),
                                           count,
                                           /*zeroEmptied*/ true);
    }

    REALLY_INLINE /*static*/ void WeakRefListHelper::gcTrace(MMgc::GC* gc, LISTDATA** loc)
    {
        gc->TraceLocation(loc);
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
        return uint32_t((ListHelper::LISTDATA::getSize(m_data) - offsetof(typename ListHelper::LISTDATA, entries)) /
                sizeof(typename ListHelper::STORAGE));
    }

    template<class T, class ListHelper>
    REALLY_INLINE T ListImpl<T,ListHelper>::get(uint32_t index) const
    {
        AvmAssert(index < m_data->len);
        return ListHelper::load(m_data, index);
    }

    template<class T, class ListHelper>
    REALLY_INLINE void ListImpl<T,ListHelper>::replace(uint32_t index, T value)
    {
        AvmAssert(index < m_data->len);
        ListHelper::store(m_data, index, value);
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
        ListHelper::store(m_data, index, value);
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
        return removeAt(0);
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
        
        if (ncap > capacity())
        {
            ensureCapacityImpl(ncap);
        }
    }

    template<class T, class ListHelper>
    REALLY_INLINE void ListImpl<T,ListHelper>::ensureCapacity(uint32_t cap)
    {
        AvmAssert(m_data != NULL);
        if (cap > capacity())
        {
            ensureCapacityImpl(cap);
        }
    }

    template<class T, class ListHelper>
    REALLY_INLINE uint64_t ListImpl<T,ListHelper>::bytesUsed() const
    {
        AvmAssert(m_data != NULL);
        return ListHelper::LISTDATA::getSize(m_data);
    }

    template<class T, class ListHelper>
    REALLY_INLINE /*static*/ typename ListHelper::LISTDATA* ListImpl<T,ListHelper>::allocData(MMgc::GC* gc, uint32_t cap)
    {
        AvmAssert(cap <= kListMaxLength);
        typename ListHelper::LISTDATA* newData = ListHelper::LISTDATA::create(gc, cap);
        newData->len = 0;
        return newData;
    }
    
    // ----------------------------


    template<class T>
    REALLY_INLINE GCList<T>::GCList(MMgc::GC* gc, uint32_t capacity, const TYPE* args)
        : m_list(gc, capacity, (MMgc::GCObject* const*)args)
    {
        MMGC_STATIC_ASSERT((TypeSniffer<T>::isGCObject::value == true ||
                            TypeSniffer<T>::isGCFinalizedObject::value == true ||
                            TypeSniffer<T>::isGCTraceableObject::value == true) &&
                            TypeSniffer<T>::isRCObject::value == false);
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isNonPointer::value == true);
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
    REALLY_INLINE typename GCList<T>::TYPE GCList<T>::get(uint32_t index) const
    {
        return reinterpret_cast<TYPE>(m_list.get(index));
    }

    template<class T>
    REALLY_INLINE typename GCList<T>::TYPE GCList<T>::first() const
    {
        return reinterpret_cast<TYPE>(m_list.first());
    }

    template<class T>
    REALLY_INLINE typename GCList<T>::TYPE GCList<T>::last() const
    {
        return reinterpret_cast<TYPE>(m_list.last());
    }

    template<class T>
    REALLY_INLINE void GCList<T>::replace(uint32_t index, TYPE value)
    {
        m_list.replace(index, reinterpret_cast<MMgc::GCObject*>(value));
    }

    template<class T>
    REALLY_INLINE void GCList<T>::set(uint32_t index, TYPE value)
    {
        m_list.set(index, reinterpret_cast<MMgc::GCObject*>(value));
    }

    template<class T>
    REALLY_INLINE void GCList<T>::add(TYPE value)
    {
        m_list.add(reinterpret_cast<MMgc::GCObject*>(value));
    }

    template<class T>
    REALLY_INLINE void GCList<T>::add(const GCList<T>& that)
    {
        m_list.add(that.m_list);
    }

    template<class T>
    REALLY_INLINE void GCList<T>::insert(uint32_t index, TYPE value, uint32_t count)
    {
        m_list.insert(index, reinterpret_cast<MMgc::GCObject*>(value), count);
    }

    template<class T>
    REALLY_INLINE void GCList<T>::insert(uint32_t index, const TYPE* args, uint32_t argc)
    {
        m_list.insert(index, args, argc);
    }

    template<class T>
    REALLY_INLINE void GCList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const TYPE* args)
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
    REALLY_INLINE int32_t GCList<T>::indexOf(TYPE value) const
    {
        return m_list.indexOf(reinterpret_cast<MMgc::GCObject*>(value));
    }

    template<class T>
    REALLY_INLINE int32_t GCList<T>::lastIndexOf(TYPE value) const
    {
        return m_list.lastIndexOf(reinterpret_cast<MMgc::GCObject*>(value));
    }

    template<class T>
    REALLY_INLINE typename GCList<T>::TYPE GCList<T>::removeAt(uint32_t index)
    {
        return reinterpret_cast<TYPE>(m_list.removeAt(index));
    }

    template<class T>
    REALLY_INLINE typename GCList<T>::TYPE GCList<T>::removeFirst()
    {
        return reinterpret_cast<TYPE>(m_list.removeFirst());
    }

    template<class T>
    REALLY_INLINE typename GCList<T>::TYPE GCList<T>::removeLast()
    {
        return reinterpret_cast<TYPE>(m_list.removeLast());
    }

    template<class T>
    REALLY_INLINE typename GCList<T>::TYPE GCList<T>::operator[](uint32_t index) const
    {
        return reinterpret_cast<TYPE>(m_list[index]);
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

    template<class T>
    REALLY_INLINE void GCList<T>::destroy()
    {
        m_list.destroy();
    }

    template<class T>
    REALLY_INLINE bool GCList<T>::isDestroyed() const
    {
        return m_list.isDestroyed();
    }

    template<class T>
    REALLY_INLINE void GCList<T>::gcTrace(MMgc::GC* gc)
    {
        m_list.gcTrace(gc);
    }

    // ----------------------------

    template<class T>
    REALLY_INLINE RCList<T>::RCList(MMgc::GC* gc, uint32_t capacity, const TYPE* args)
        : m_list(gc, capacity, (MMgc::RCObject* const*)args)
    {
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isRCObject::value == true);
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isNonPointer::value == true);
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
    REALLY_INLINE typename RCList<T>::TYPE RCList<T>::get(uint32_t index) const
    {
        return reinterpret_cast<TYPE>(m_list.get(index));
    }

    template<class T>
    REALLY_INLINE typename RCList<T>::TYPE RCList<T>::first() const
    {
        return reinterpret_cast<TYPE>(m_list.first());
    }

    template<class T>
    REALLY_INLINE typename RCList<T>::TYPE RCList<T>::last() const
    {
        return reinterpret_cast<TYPE>(m_list.last());
    }

    template<class T>
    REALLY_INLINE void RCList<T>::replace(uint32_t index, TYPE value)
    {
        m_list.replace(index, value);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::set(uint32_t index, TYPE value)
    {
        m_list.set(index, value);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::add(TYPE value)
    {
        m_list.add(value);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::add(const RCList<T>& that)
    {
        m_list.add(that.m_list);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::insert(uint32_t index, TYPE value, uint32_t count)
    {
        m_list.insert(index, value, count);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::insert(uint32_t index, const TYPE* args, uint32_t argc)
    {
        m_list.insert(index, args, argc);
    }

    template<class T>
    REALLY_INLINE void RCList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const TYPE* args)
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
    REALLY_INLINE int32_t RCList<T>::indexOf(TYPE value) const
    {
        return m_list.indexOf(value);
    }

    template<class T>
    REALLY_INLINE int32_t RCList<T>::lastIndexOf(TYPE value) const
    {
        return m_list.lastIndexOf(value);
    }

    template<class T>
    REALLY_INLINE typename RCList<T>::TYPE RCList<T>::removeAt(uint32_t index)
    {
        return reinterpret_cast<TYPE>(m_list.removeAt(index));
    }

    template<class T>
    REALLY_INLINE typename RCList<T>::TYPE RCList<T>::removeFirst()
    {
        return reinterpret_cast<TYPE>(m_list.removeFirst());
    }

    template<class T>
    REALLY_INLINE typename RCList<T>::TYPE RCList<T>::removeLast()
    {
        return reinterpret_cast<TYPE>(m_list.removeLast());
    }

    template<class T>
    REALLY_INLINE typename RCList<T>::TYPE RCList<T>::operator[](uint32_t index) const
    {
        return reinterpret_cast<TYPE>(m_list[index]);
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

    template<class T>
    REALLY_INLINE void RCList<T>::destroy()
    {
        m_list.destroy();
    }

    template<class T>
    REALLY_INLINE bool RCList<T>::isDestroyed() const
    {
        return m_list.isDestroyed();
    }

    template<class T>
    REALLY_INLINE void RCList<T>::gcTrace(MMgc::GC* gc)
    {
        m_list.gcTrace(gc);
    }
    
    
    // ----------------------------

    template<class T>
    REALLY_INLINE UnmanagedPointerList<T>::UnmanagedPointerList(MMgc::GC* gc, uint32_t capacity, const T* args)
        : m_list(gc, capacity, (const UnmanagedPointer*)args)
    {
        // We must not be a GC/RCObject.
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isGCObject::value == false &&
                            TypeSniffer<T>::isGCFinalizedObject::value == false &&
                            TypeSniffer<T>::isRCObject::value == false &&
                            TypeSniffer<T>::isGCTraceableObject::value == false);

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
    REALLY_INLINE void UnmanagedPointerList<T>::replace(uint32_t index, T value)
    {
        m_list.replace(index, (UnmanagedPointer)value);
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
        m_list.add(that.m_list);
    }

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::insert(uint32_t index, T value, uint32_t count)
    {
        m_list.insert(index, (UnmanagedPointer)value, count);
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
        return m_list.indexOf((UnmanagedPointer)value);
    }

    template<class T>
    REALLY_INLINE int32_t UnmanagedPointerList<T>::lastIndexOf(T value) const
    {
        return m_list.lastIndexOf((UnmanagedPointer)value);
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

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::destroy()
    {
        m_list.destroy();
    }

    template<class T>
    REALLY_INLINE bool UnmanagedPointerList<T>::isDestroyed() const
    {
        return m_list.isDestroyed();
    }

    template<class T>
    REALLY_INLINE void UnmanagedPointerList<T>::gcTrace(MMgc::GC* gc)
    {
        m_list.gcTrace(gc);
    }
    
    // ----------------------------

    template<class T>
    REALLY_INLINE WeakRefList<T>::WeakRefList(MMgc::GC* gc, uint32_t capacity, const TYPE* args)
        : m_list(gc, capacity, (MMgc::GCObject* const*)args)
    {
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isGCObject::value ||
                            TypeSniffer<T>::isGCFinalizedObject::value ||
                            TypeSniffer<T>::isRCObject::value ||
                            TypeSniffer<T>::isGCTraceableObject::value);
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isNonPointer::value == true);
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
    REALLY_INLINE typename WeakRefList<T>::TYPE WeakRefList<T>::get(uint32_t index) const
    {
        return reinterpret_cast<TYPE>(m_list.get(index));
    }

    template<class T>
    REALLY_INLINE typename WeakRefList<T>::TYPE WeakRefList<T>::first() const
    {
        return reinterpret_cast<TYPE>(m_list.first());
    }

    template<class T>
    REALLY_INLINE typename WeakRefList<T>::TYPE WeakRefList<T>::last() const
    {
        return reinterpret_cast<TYPE>(m_list.last());
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::replace(uint32_t index, TYPE value)
    {
        m_list.replace(index, to_gc(value));
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::set(uint32_t index, TYPE value)
    {
        m_list.set(index, reinterpret_cast<MMgc::GCObject*>(value));
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::add(TYPE value)
    {
        m_list.add(reinterpret_cast<MMgc::GCObject*>(value));
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::add(const WeakRefList<T>& that)
    {
        m_list.add(that.m_list);
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::insert(uint32_t index, TYPE value, uint32_t count)
    {
        m_list.insert(index, reinterpret_cast<MMgc::GCObject*>(value), count);
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::insert(uint32_t index, const TYPE* args, uint32_t argc)
    {
        m_list.insert(index, args, argc);
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const TYPE* args)
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
    REALLY_INLINE int32_t WeakRefList<T>::indexOf(TYPE value) const
    {
        return m_list.indexOf(reinterpret_cast<MMgc::GCObject*>(value));
    }

    template<class T>
    REALLY_INLINE int32_t WeakRefList<T>::lastIndexOf(TYPE value) const
    {
        return m_list.lastIndexOf(reinterpret_cast<MMgc::GCObject*>(value));
    }

    template<class T>
    REALLY_INLINE typename WeakRefList<T>::TYPE WeakRefList<T>::removeAt(uint32_t index)
    {
        return reinterpret_cast<TYPE>(m_list.removeAt(index));
    }

    template<class T>
    REALLY_INLINE typename WeakRefList<T>::TYPE WeakRefList<T>::removeFirst()
    {
        return reinterpret_cast<TYPE>(m_list.removeFirst());
    }

    template<class T>
    REALLY_INLINE typename WeakRefList<T>::TYPE WeakRefList<T>::removeLast()
    {
        return reinterpret_cast<TYPE>(m_list.removeLast());
    }

    template<class T>
    REALLY_INLINE typename WeakRefList<T>::TYPE WeakRefList<T>::operator[](uint32_t index) const
    {
        return reinterpret_cast<TYPE>(m_list[index]);
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

    template<class T>
    REALLY_INLINE void WeakRefList<T>::destroy()
    {
        m_list.destroy();
    }

    template<class T>
    REALLY_INLINE bool WeakRefList<T>::isDestroyed() const
    {
        return m_list.isDestroyed();
    }

    template<class T>
    REALLY_INLINE uint32_t WeakRefList<T>::removeCollectedItems()
    {
        return m_list.removeNullItems();
    }

    template<class T>
    REALLY_INLINE void WeakRefList<T>::gcTrace(MMgc::GC* gc)
    {
        m_list.gcTrace(gc);
    }

    // ----------------------------

    template<class T>
    REALLY_INLINE DataList<T>::DataList(MMgc::GC* gc, uint32_t capacity, const T* args)
        : m_list(gc, capacity, args)
    {
        // We must not be a pointer type.
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isNonPointer::value == true);

        // If you make a NonGCObject list that holds GC/RCObjects, you are almost
        // certainly making a mistake. (Redundant to the above check, but left in
        // for emphasis.)
        MMGC_STATIC_ASSERT(TypeSniffer<T>::isGCObject::value == false &&
                           TypeSniffer<T>::isGCFinalizedObject::value == false &&
                           TypeSniffer<T>::isRCObject::value == false &&
                           TypeSniffer<T>::isGCTraceableObject::value == false);
    }

    template<class T>
    REALLY_INLINE bool DataList<T>::isEmpty() const
    {
        return m_list.isEmpty();
    }

    template<class T>
    REALLY_INLINE uint32_t DataList<T>::length() const
    {
        return m_list.length();
    }

    template<class T>
    REALLY_INLINE void DataList<T>::set_length(uint32_t len)
    {
        return m_list.set_length(len);
    }

    template<class T>
    REALLY_INLINE uint32_t DataList<T>::capacity() const
    {
        return m_list.capacity();
    }
    
    template<class T>
    REALLY_INLINE void DataList<T>::set_capacity(uint32_t len)
    {
        return m_list.set_capacity(len);
    }
    
    template<class T>
    REALLY_INLINE typename DataList<T>::TYPE DataList<T>::get(uint32_t index) const
    {
        return m_list.get(index);
    }

    template<class T>
    REALLY_INLINE typename DataList<T>::TYPE DataList<T>::first() const
    {
        return m_list.first();
    }

    template<class T>
    REALLY_INLINE typename DataList<T>::TYPE DataList<T>::last() const
    {
        return m_list.last();
    }

    template<class T>
    REALLY_INLINE void DataList<T>::replace(uint32_t index, TYPE value)
    {
        m_list.replace(index, to_gc(value));
    }

    template<class T>
    REALLY_INLINE void DataList<T>::set(uint32_t index, TYPE value)
    {
        m_list.set(index, value);
    }

    template<class T>
    REALLY_INLINE void DataList<T>::add(TYPE value)
    {
        m_list.add(value);
    }

    template<class T>
    REALLY_INLINE void DataList<T>::add(const DataList<T>& that)
    {
        m_list.add(that.m_list);
    }

    template<class T>
    REALLY_INLINE void DataList<T>::insert(uint32_t index, TYPE value, uint32_t count)
    {
        m_list.insert(index, value, count);
    }

    template<class T>
    REALLY_INLINE void DataList<T>::insert(uint32_t index, const TYPE* args, uint32_t argc)
    {
        m_list.insert(index, args, argc);
    }

    template<class T>
    REALLY_INLINE void DataList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const TYPE* args)
    {
        m_list.splice(insertPoint, insertCount, deleteCount, args);
    }

    template<class T>
    REALLY_INLINE void DataList<T>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const DataList<T>& args, uint32_t argsOffset)
    {
        m_list.splice(insertPoint, insertCount, deleteCount, args.m_list, argsOffset);
    }

    template<class T>
    REALLY_INLINE void DataList<T>::reverse()
    {
        m_list.reverse();
    }

    template<class T>
    REALLY_INLINE void DataList<T>::clear()
    {
        m_list.clear();
    }

    template<class T>
    REALLY_INLINE int32_t DataList<T>::indexOf(TYPE value) const
    {
        return m_list.indexOf(value);
    }

    template<class T>
    REALLY_INLINE int32_t DataList<T>::lastIndexOf(TYPE value) const
    {
        return m_list.lastIndexOf(value);
    }

    template<class T>
    REALLY_INLINE typename DataList<T>::TYPE DataList<T>::removeAt(uint32_t index)
    {
        return m_list.removeAt(index);
    }

    template<class T>
    REALLY_INLINE typename DataList<T>::TYPE DataList<T>::removeFirst()
    {
        return m_list.removeFirst();
    }

    template<class T>
    REALLY_INLINE typename DataList<T>::TYPE DataList<T>::removeLast()
    {
        return m_list.removeLast();
    }

    template<class T>
    REALLY_INLINE typename DataList<T>::TYPE& DataList<T>::operator[](uint32_t index)
    {
        AvmAssert(index < m_list.length());
        DataListAccessor<T> acc(this);
        T* entries = acc.addr();
        AvmAssert(entries != NULL);
        return entries[index];
    }

    template<class T>
    REALLY_INLINE typename DataList<T>::TYPE DataList<T>::operator[](uint32_t index) const
    {
        return m_list[index];
    }

    template<class T>
    REALLY_INLINE void DataList<T>::ensureCapacity(uint32_t cap)
    {
        m_list.ensureCapacity(cap);
    }

    template<class T>
    REALLY_INLINE uint64_t DataList<T>::bytesUsed() const
    {
        return m_list.bytesUsed();
    }

    template<class T>
    REALLY_INLINE void DataList<T>::destroy()
    {
        m_list.destroy();
    }

    template<class T>
    REALLY_INLINE bool DataList<T>::isDestroyed() const
    {
        return m_list.isDestroyed();
    }

    template<class T>
    REALLY_INLINE void DataList<T>::gcTrace(MMgc::GC* gc)
    {
        m_list.gcTrace(gc);
    }

    // ----------------------------

    template<class T>
    REALLY_INLINE DataListAccessor<T>::DataListAccessor(DataList<T>* v) : m_list(v)
    {
    }
    
    template<class T>
    REALLY_INLINE T* DataListAccessor<T>::addr()
    {
        return (m_list != NULL) ? m_list->m_list.m_data->entries : (T*)NULL;
    }

    template<class T>
    REALLY_INLINE uint32_t DataListAccessor<T>::length()
    {
        return (m_list != NULL) ? m_list->length() : 0;
    }
    
    // ----------------------------

    template<class T>
    REALLY_INLINE HeapList<T>::HeapList(MMgc::GC* gc, uint32_t capacity, const typename T::TYPE* args)
        : list(gc, capacity, args)
    {
    }
}

#endif /* __avmplus_List_inlines__ */
