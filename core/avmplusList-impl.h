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

#ifndef __avmplus_List_impl__
#define __avmplus_List_impl__

namespace avmplus
{
    template<class T, class ListHelper>
    ListImpl<T,ListHelper>::ListImpl(MMgc::GC* gc,
                        uint32_t capacity,
                        const T* args) : m_data(NULL)
    {
        if (capacity > kListMaxLength)
            MMgc::GCHeap::SignalObjectTooLarge();
        uint32_t const allocCap = (capacity < kListMinCapacity) ? kListMinCapacity : capacity;
        typename ListHelper::LISTDATA* newData = allocData(gc, allocCap);
        ListHelper::wbData(this, &m_data, newData);

        if (args != NULL)
        {
            for (uint32_t i = 0; i < capacity; i++)
                ListHelper::storeEmpty(m_data, i, args[i]);
            m_data->len = capacity;
        }
    }

    template<class T, class ListHelper>
    ListImpl<T,ListHelper>::~ListImpl()
    {
        AvmAssert(m_data != NULL);
        if (m_data->len > 0)
            ListHelper::clearRange(m_data, 0, m_data->len);
        ListHelper::free(m_data->gc, m_data);
        m_data = NULL;
    }

    template<class T, class ListHelper>
    void ListImpl<T,ListHelper>::add(T value)
    {
        // OPTIMIZEME, this method may be worth inlining
        AvmAssert(m_data->len <= m_data->cap);
        ensureCapacityExtra(m_data->len, 1);
        ListHelper::store(m_data, m_data->len++, value);
    }

    template<class T, class ListHelper>
    void ListImpl<T,ListHelper>::add(const ListImpl<T,ListHelper>& that)
    {
        uint32_t const n = that.length();
        ensureCapacityExtra(m_data->len, n);
        for (uint32_t i = 0; i < n; ++i)
            ListHelper::store(m_data, m_data->len + i, that.get(i));
        m_data->len += n;
    }

    template<class T, class ListHelper>
    void ListImpl<T,ListHelper>::insert(uint32_t index, T value)
    {
        AvmAssert(m_data->len <= m_data->cap);
        ensureCapacityExtra(m_data->len, 1);
        if (index < m_data->len)
            ListHelper::moveRange(m_data, index, index + 1, m_data->len - index);
        else
            index = m_data->len;
        ListHelper::store(m_data, index, value);
        m_data->len++;
    }

    template<class T, class ListHelper>
    void ListImpl<T,ListHelper>::clear()
    {
        AvmAssert(m_data != NULL);
        if (m_data->len > 0)
        {
            ListHelper::clearRange(m_data, 0, m_data->len);
            m_data->len = 0;
        }
        if (m_data->cap > kListMinCapacity)
        {
            MMgc::GC* const gc = m_data->gc;
            typename ListHelper::LISTDATA* newData = allocData(gc, kListMinCapacity);
            newData->len = 0;
            newData->cap = kListMinCapacity;
            ListHelper::free(gc, m_data);
            ListHelper::wbData(this, &m_data, newData);
        }
    }

    template<class T, class ListHelper>
    int32_t ListImpl<T,ListHelper>::indexOf(T value) const
    {
        for (uint32_t i = 0, n = m_data->len; i < n; i++)
            if (ListHelper::load(m_data, i) == value)
                return int32_t(i);
        return -1;
    }

    template<class T, class ListHelper>
    int32_t ListImpl<T,ListHelper>::lastIndexOf(T value) const
    {
        for (uint32_t i = m_data->len; i > 0; i--)
            if (ListHelper::load(m_data, i-1) == value)
                return int32_t(i);
        return -1;
    }

    template<class T, class ListHelper>
    T ListImpl<T,ListHelper>::removeAt(uint32_t index)
    {
        AvmAssert(index < m_data->len);
        T const old = ListHelper::load(m_data, index);
        if (index < m_data->len-1)
        {
            ListHelper::moveRange(m_data, index+1, index, m_data->len-index-1);
        }
        else
        {
            ListHelper::clearRange(m_data, index, 1);
        }
        m_data->len--;
        return old;
    }

    template<class T, class ListHelper>
    void FASTCALL ListImpl<T,ListHelper>::ensureCapacityImpl(uint32_t cap)
    {
        if (cap > kListMaxLength)
            MMgc::GCHeap::SignalObjectTooLarge();
        
        AvmAssert(m_data != NULL);
        AvmAssert(m_data->cap >= kListMinCapacity);
        AvmAssert(cap > m_data->cap);
        AvmAssert(cap <= kListMaxLength);

        // OPTIMIZEME: this is the growth algorithm used by the old AtomArray... 
        // is this the best algorithm? Not sure, but it's definitely better 
        // in our perf tests than the one used by the old List<> implementation.
        // Note that if you change it, you will probably need to add overflow detection; 
        // this relies on the fact that kListMaxLength+(kListMaxLength/4) <= 0xffffffff.
        MMGC_STATIC_ASSERT(uint64_t(kListMaxLength) + uint64_t(kListMaxLength/4) <= uint64_t(0xFFFFFFFF));
        cap += (cap/4);
        AvmAssert(cap > kListMinCapacity);
        MMgc::GC* const gc = m_data->gc;
        typename ListHelper::LISTDATA* newData = allocData(gc, cap);

        VMPI_memcpy(newData->entries, m_data->entries, m_data->len * sizeof(typename ListHelper::STORAGE));
        newData->len = m_data->len;
        // don't call ListHelper::clearRange here; we want the refCounts to be transferred
        ListHelper::free(gc, m_data);
        ListHelper::wbData(this, &m_data, newData);
    }

    template<class T, class ListHelper>
    void ListImpl<T,ListHelper>::insert(uint32_t index, const T* args, uint32_t argc)
    {
        uint32_t const len = m_data->len;
        ensureCapacityExtra(len, argc);
        if (index < len)
            ListHelper::moveRange(m_data, index, index + argc, len - index);
        else
            index = len;

        for (uint32_t i = 0; i < argc; ++i)
            ListHelper::store(m_data, index + i, args[i]);

        m_data->len += argc;
    }

    template<class T, class ListHelper>
    void ListImpl<T,ListHelper>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const T* args)
    {
        uint32_t const len = m_data->len;
        // We only need to expand if we are inserting more than we are deleting,
        // so don't bother calling it unless that's the case, as it means we don't
        // have to worry about overflow-checking "insertCount - deleteCount"
        if (insertCount > deleteCount)
            ensureCapacityExtra(len, insertCount - deleteCount);
        if (insertCount < deleteCount)
        {
            ListHelper::clearRange(m_data, insertPoint + insertCount, deleteCount - insertCount);
            ListHelper::moveRange(m_data, insertPoint + deleteCount, insertPoint + insertCount, len - insertPoint - deleteCount);
        }
        else if (insertCount > deleteCount)
        {
            ListHelper::moveRange(m_data, insertPoint, insertPoint + insertCount - deleteCount, len - insertPoint);
        }

        for (uint32_t i = 0; i < insertCount; ++i)
        {
            ListHelper::store(m_data, insertPoint + i, args[i]);
        }

        m_data->len = len + insertCount - deleteCount;
    }

    template<class T, class ListHelper>
    void ListImpl<T,ListHelper>::splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const ListImpl<T,ListHelper>& that, uint32_t thatOffset)
    {
        uint32_t const len = m_data->len;
        // We only need to expand if we are inserting more than we are deleting,
        // so don't bother calling it unless that's the case, as it means we don't
        // have to worry about overflow-checking "insertCount - deleteCount"
        if (insertCount > deleteCount)
            ensureCapacityExtra(len, insertCount - deleteCount);
        if (insertCount < deleteCount)
        {
            ListHelper::clearRange(m_data, insertPoint + insertCount, deleteCount - insertCount);
            ListHelper::moveRange(m_data, insertPoint + deleteCount, insertPoint + insertCount, len - insertPoint - deleteCount);
        }
        else if (insertCount > deleteCount)
        {
            ListHelper::moveRange(m_data, insertPoint, insertPoint + insertCount - deleteCount, len - insertPoint);
        }

        for (uint32_t i = 0; i < insertCount; ++i)
        {
            AvmAssert(i + thatOffset < that.length());
            T const value = ListHelper::load(that.m_data, i + thatOffset);
            ListHelper::store(m_data, insertPoint + i, value);
        }

        m_data->len = len + insertCount - deleteCount;
    }

    template<class T, class ListHelper>
    void ListImpl<T,ListHelper>::reverse()
    {
        uint32_t const len = m_data->len;
        if (len > 1)
        {
            if (sizeof(m_data->entries[0]) == sizeof(void*))
            {
                // It's really only necessary to do this for things that
                // might be GC pointers, but it doesn't really hurt to do
                // for other things that just happen to be the same size.
                m_data->gc->reversePointersWithinBlock((void**)&m_data->entries[0], len);
            }
            else
            {
                for (uint32_t i = 0, n = len/2; i < n; i++)
                {
                    uint32_t const i2 = len - i - 1;
                    T const v  = ListHelper::load(m_data, i);
                    T const v2 = ListHelper::load(m_data, i2);
                    ListHelper::store(m_data, i, v2);
                    ListHelper::store(m_data, i2, v);
                }
            }
        }
    }

}

#endif /* __avmplus_List_impl__ */
