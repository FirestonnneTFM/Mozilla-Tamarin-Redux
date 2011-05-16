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


#include "avmplus.h"

namespace avmplus
{
    /*
        A dense array is faster and more efficient than a sparse array. Also, most
        Arrays are (mostly) dense in actual usage. Thus we now start with the assumption
        that all Arrays are dense until proven otherwise. The heuristics are largely based
        on SpiderMonkey.
        
        Array objects begin as "dense" arrays, optimized for numeric-only property
        access over a vector of slots (m_denseArray) with high load factor.  Array
        methods optimize for denseness by testing that the object's class is
        Array, and can then directly manipulate the slots for efficiency.

        When an Array is "dense", all properties are stored
        in the dense array, either explicitly or implicitly (see below). Note that
        only dynamic Arrays can be dense. (By definition, a dense array can only
        contain properties with uint keys.)
        
        When an Array is not dense, m_denseArray is unused and all properties
        are stored in the hashtable (as with any other ScriptObject).
        
        In dense mode, the Array has a (possibly zero-length) AtomList (m_denseArray) containing
        all its values; the first item in m_denseArray corresponds to index m_denseStart.
        There can be "holes" in m_denseArray; these are set to the special value atomNotFound
        and indicate an entry that has never been set.
        
        All properties that are less than the dense area start, or greater than the dense area end,
        are implicitly considered to be atomNotFound.
        
        It's perfectly legal (and not unusual) for a dense array to have storage for only the "middle"
        portion of itself; consider a code fragment like
        
            var a = new Array(1000);
            a[123] = 4;
            a[125] = 99;
            a[128] = 8;
        
        In the above case, we'd expect to have a dense Array with

            m_denseStart = 123      (first entry in denseArr)
            m_denseUsed = 3
            m_denseArray.length = 6
            m_denseArray contents = [ 4, HOLE, 99, HOLE, HOLE, 8 ]
            m_length = 1000

        Note that everything less than m_denseStart, and everything between
        (m_denseStart+m_denseArray.length) and m_length, are implicitly considered "atomNotFound".
        
        Arrays are converted to sparse (m_denseArray = 0, all properties in the ht area)
        when any of these conditions are met:
         - the load factor (m_denseUsed / m_denseArray.length()) is less than 0.25, and there are
           more than MIN_SPARSE_INDEX slots total
         - a property is set that is non-numeric (and not "length"); or
         - a hole is filled below m_denseArray.length() (possibly implicitly through methods like
           |reverse| or |splice|).
           
        We currently never attempt to reconvert a sparse Array to a dense Array, except in the
        degenerate case of every property of the Array being removed (in which case it
        becomes a "dense" but empty Array).

        Note that, as before, we do not preserve enumeration-in-insertion-order
        for either dense or sparse arrays.
    */

    // Arrays <= this in length are always dense, regardless of how many slots are used
    static const uint32_t MIN_SPARSE_INDEX = 32;

    /*static*/ REALLY_INLINE bool shouldBeSparse(const uint32_t denseLen, const uint32_t denseUsed)
    {
        // We don't allow dense indices to be negative when interpreted as a signed int32,
        // so let's constrain denseLen to <= 0x7FFFFFFF to ensure that.
        return (denseLen > MIN_SPARSE_INDEX && denseLen > ((denseUsed+1)<<2)) ||
                int32_t(denseLen) < 0;
    }

    REALLY_INLINE uint32_t umin(uint32_t a, uint32_t b) { return a < b ? a : b; }
    REALLY_INLINE uint32_t umax(uint32_t a, uint32_t b) { return a > b ? a : b; }

    Atom ArrayObject::indexToName(uint32_t index) const
    {
        // This is carefully designed to replicate the logic in ScriptObject::getUintProperty;
        // in particular, we must ensure that we create kIntptrType Atoms for indices
        // less than MAX_INTEGER_MASK (rather than interned Strings)
        return (!(index & MAX_INTEGER_MASK)) ?
                atomFromIntptrValue_u(index) :
                core()->internUint32(index)->atom();
    }

    uint32_t ArrayObject::calcDenseUsed() const
    {
        AvmAssert(isDense());
        uint32_t used = 0;
        for (uint32_t u = 0, n = m_denseArray.length(); u < n; u++)
        {
            if (m_denseArray.get(u) != atomNotFound)
                ++used;
        }
        return used;
    }

#ifdef DEBUG_ARRAY_VERIFY
    void ArrayObject::verify() const
    {
        if (m_denseStart == IS_SPARSE)
        {
            AvmAssert(m_denseUsed == 0);
            AvmAssert(m_denseArray.length() == 0);

            uint32_t calc_len = 0;
            InlineHashtable* ht = this->getTable();
            for (int i = ht->next(0); i != 0; i = ht->next(i))
            {
                Atom k = ht->keyAt(i);
                uint32_t index;
                if (AvmCore::getIndexFromAtom(k, &index) && index >= calc_len)
                {
                    calc_len = index + 1;
                }
            }
            AvmAssert(m_length >= calc_len);
        }
        else if (m_denseStart == IS_SEALED)
        {
            AvmAssert(m_denseUsed == 0);
            AvmAssert(m_denseArray.length() == 0);
            AvmAssert(m_length == 0);
        }
        else // isDense
        {
            AvmAssert(int32_t(m_denseStart) >= 0);
            
            // can't use getTable()->getSize() == 0 because getSize()
            // includes deleted items.
            InlineHashtable* ht = this->getTable();
            for (int i = ht->next(0); i != 0; i = ht->next(i))
            {
                Atom k = ht->keyAt(i);
                uint32_t index;
                AvmAssert(!AvmCore::getIndexFromAtom(k, &index));
            }
            AvmAssert(m_length >= m_denseStart + m_denseArray.length());
            AvmAssert(m_denseUsed <= m_denseArray.length());
            AvmAssert(m_denseArray.length() <= 0x7fffffff);
            AvmAssert(m_denseUsed == calcDenseUsed());
            if (m_denseArray.length() == 0)
            {
                AvmAssert(m_denseStart == 0);
                AvmAssert(m_denseUsed == 0);
            }
            AvmAssert(!shouldBeSparse(m_denseArray.length(), m_denseUsed));
        }
    }
#endif

    void ArrayObject::convertToSparse()
    {
        AvmAssert(isDense());
        
        verify();

        for (uint32_t index = 0, n = m_denseArray.length(); index < n; index++)
        {
            Atom value = m_denseArray.get(index);
            if (value != atomNotFound)
            {
                getTable()->add(indexToName(index + m_denseStart), value);
            }
        }

        m_denseArray.clear();
        m_denseStart = IS_SPARSE;
        m_denseUsed = 0;

        verify();
    }

    // ----------------- ctors, dtors

    ArrayObject::ArrayObject(VTable* vtable, ScriptObject* proto, uint32_t capacity)
        : ScriptObject(vtable, proto, 0)
        , m_denseArray(vtable->core()->GetGC(), capacity)
        , m_denseStart(traits()->needsHashtable() ? 0 : IS_SEALED)
        , m_denseUsed(0)
        , m_length(0)
    {
        SAMPLE_FRAME("Array", core());
        AvmAssert(traits()->getSizeOfInstance() >= sizeof(ArrayObject));
    }

    ArrayObject::ArrayObject(VTable* vtable, ScriptObject* proto, Atom* argv, int argc)
        : ScriptObject(vtable, proto, 0)
        , m_denseArray(vtable->core()->GetGC(), argc, argv)
        , m_denseStart(traits()->needsHashtable() ? 0 : IS_SEALED)
        , m_denseUsed(argc)
        , m_length(argc)
    {
    }

    ArrayObject::~ArrayObject()
    {
        m_denseStart = 0;
        m_denseUsed = 0;
        m_length = 0;
    }

#ifdef VMCFG_AOT
    template <typename ADT>
    ArrayObject::ArrayObject(VTable *vtable, ScriptObject* proto, MethodEnv *env, ADT argDesc, uint32_t argc, va_list ap)
        : ScriptObject(vtable, proto, 0),
          m_denseArray(vtable->core()->GetGC(), argc),
          m_length(argc)
    {
        if (m_length > 0)
            argDescArgsToAtomList(m_denseArray, argDesc, env, ap);
    }

    template ArrayObject::ArrayObject(VTable*, ScriptObject*, MethodEnv*, uint32_t, uint32_t, va_list);
    template ArrayObject::ArrayObject(VTable*, ScriptObject*, MethodEnv*, char*, uint32_t, va_list);
#endif // VMCFG_AOT

    // ----------------- "get" methods

    Atom ArrayObject::getAtomProperty(Atom name) const
    {
        uint32_t index;
        if (AvmCore::getIndexFromAtom(name, &index))
        {
            uint32_t const denseIdx = index - m_denseStart;
            if (denseIdx < m_denseArray.length())
            {
                Atom result = m_denseArray.get(denseIdx);
                if (result != atomNotFound)
                    return result;
            }
            // else, outside dense area, or a hole in the dense area:
            // must fall thru and search the proto chain
        }
        else if (isDynamic() && name == core()->klength->atom())
        {
            return core()->intToAtom(getLength());
        }

        return ScriptObject::getAtomProperty(name);
    }

    bool ArrayObject::getAtomPropertyIsEnumerable(Atom name) const
    {
        if (isDense())
        {
            // {DontEnum} is not supported on the dense portion
            // of an array.  Those properties are always enumerable.
            uint32_t index;
            return AvmCore::getIndexFromAtom(name, &index) && index < getLength();
        }
        return ScriptObject::getAtomPropertyIsEnumerable(name);
    }

    Atom ArrayObject::_getIntProperty(int32_t index) const
    {
        if (index >= 0)
            // this is a hot function, but we still must
            // call the virtual function in case it's been overridden
            return getUintProperty(index);
        else // integer is negative - we must intern it
            return getStringProperty(core()->internInt(index));
    }

    Atom ArrayObject::_getUintProperty(uint32_t index) const
    {
        // this is a hot function, but we still must
        // call the virtual function in case it's been overridden
        return getUintProperty(index);
    }

    Atom ArrayObject::_getDoubleProperty(double d) const
    {
        uint32_t index = uint32_t(d);
        if (double(index) == d)
            // this is a hot function, but we still must
            // call the virtual function in case it's been overridden
            return getUintProperty(index);
        else
            // Number is non-integral, negative, or too large to be a valid index, so intern it.
            return getStringProperty(core()->internDouble(d));
    }

#ifdef VMCFG_AOT
    Atom *ArrayObject::getDenseCopy() const
    {
        AvmAssert(m_denseArray.length() == m_length);
        uint32_t const len = m_denseArray.length();
    
        if (!len)
            return NULL;
      
        AvmCore *core = this->core();
        MMgc::GC *gc = core->GetGC();
        Atom *result = (Atom *)gc->Calloc(len, sizeof(Atom), MMgc::GC::kContainsPointers);
        for (uint32_t n = 0; n < len; n++)
            AvmCore::atomWriteBarrier_ctor(gc, result, result + n, m_denseArray.get(n));
    
        return result;
    }

    uint32_t ArrayObject:: getDenseLength() const
    {
        return m_denseArray.length();
    }
#endif // VMCFG_AOT

    // ----------------- "set" methods

    void ArrayObject::setAtomProperty(Atom name, Atom value)
    {
        AvmAssert(value != atomNotFound);
        
        verify();

        if (isDynamic())
        {
            uint32_t index;
            if (AvmCore::getIndexFromAtom(name, &index))
            {
                _setUintProperty(index, value);
                verify();
                return;
            }

            if (name == core()->klength->atom())
            {
                setLength(AvmCore::toUInt32(value));
                verify();
                return;
            }
        }

        // else fall thru and set in dynamic area
        ScriptObject::setAtomProperty(name, value);

        verify();
    }

    void ArrayObject::_setUintProperty(uint32_t index, Atom value)
    {
        AvmAssert(value != atomNotFound);

        verify();

        // The most common case is setting a value in the dense area.
        uint32_t const denseIdx = index - m_denseStart;
        uint32_t const denseLen = m_denseArray.length();
        if (denseIdx < denseLen)
        {
            // This is by far the most common case in typical code.
            // Note that we don't have to adjust m_length; we know it will be unchanged.
            AvmAssert(index >= m_denseStart && index < m_denseStart + m_denseArray.length());
            AvmAssert(index < m_length);
            // It's worth checking to avoid the read.
            if (m_denseUsed < denseLen)
                m_denseUsed += (m_denseArray.get(denseIdx) == atomNotFound);
            // Since we've already verified index, we can use replace() rather than set()...
            // it's minor but will show up on microbenchmarks.
            m_denseArray.replace(denseIdx, value);
        }
        else if (int32_t(index) >= 0 && int32_t(m_denseStart) >= 0) // denseIdx >= denseLen and possibly-dense index
        {
            if (index >= m_length)
            {
                // This is unnecessary if we are sealed,
                // but it's cheaper to do it all cases,
                // and harmless if we are in fact sealed.
                m_length = index + 1;
            }

            if (denseIdx == denseLen)
            {
                AvmAssert(!isSparse());

                // Adding at the end of a nonempty Array.
                m_denseUsed++;
                m_denseArray.add(value);
                // Array was empty.
                if (denseLen == 0)
                    m_denseStart = index;
            }
            else if (denseLen == 0)
            {
                AvmAssert(!isSparse());

                // Adding to an empty Array.
                m_denseStart = index;
                m_denseUsed++;
                m_denseArray.add(value);
            }
            else if (index >= m_denseStart)
            {
                AvmAssert(!isSparse());

                // Adding past the end of a nonempty Array.
                uint32_t const insertCount = denseIdx - denseLen + 1;
                if (shouldBeSparse(denseLen + insertCount, m_denseUsed + 1))
                {
                    goto convert_and_set_sparse;
                }
                else
                {
                    m_denseUsed++;
                    m_denseArray.insert(denseLen, atomNotFound, insertCount);
                    // denseIdx calculated above might be wrong; recalculate it.
                    AvmAssert(index >= m_denseStart);
                    uint32_t const denseIdx = index - m_denseStart;
                    m_denseArray.replace(denseIdx, value);
                }
            }
            else if (int32_t(index) < int32_t(m_denseStart))
            {
                AvmAssert(!isSparse());

                // Adding before the beginning of a nonempty Array.
                uint32_t const insertCount = m_denseStart - index;
                if (shouldBeSparse(denseLen + insertCount, m_denseUsed + 1))
                {
                    goto convert_and_set_sparse;
                }
                else
                {

                    // If we're inserting before the first element, we are probably
                    // growing downward; let's shift over as much as we can within the new
                    // capacity so we can avoid redundant memcpys as we insert downward.
                    m_denseArray.ensureCapacity(denseLen + insertCount);
                    // Actual capacity might be more than we asked for.
                    uint32_t const denseCap = m_denseArray.capacity();
                    // Shift all content over to the "right edge" of the allocated
                    // space, on the assumption that future insertions are
                    // also likely to be at the start rather than the end.
                    // Note that this call should never increase the capacity;
                    // it just shifts entries over in the existing space.
                    uint32_t const shiftAmt = umin(m_denseStart, denseCap - denseLen);
                    m_denseArray.insert(0, atomNotFound, shiftAmt);
                    AvmAssert(denseCap == m_denseArray.capacity());

                    m_denseStart -= shiftAmt;
                    m_denseUsed++;
                    // denseIdx calculated above is probably wrong; recalculate it.
                    AvmAssert(index >= m_denseStart);
                    uint32_t const denseIdx = index - m_denseStart;
                    m_denseArray.replace(denseIdx, value);
                }
            }
            else
            {
                goto sparse_or_sealed;
            }
        }
        else
        {
sparse_or_sealed:
            if (!isDynamic())
                throwWriteSealedError(indexToName(index));

            // Indices > 0x7fffffff aren't candidates for dense arrays; in that case we
            // always revert to sparse. (Note that per ES3 spec, 0xffffffff is not a legal
            // array index, so doesn't affect length, but does get stored as a dynamic prop)

            if (index != 0xffffffff && index >= m_length)
            {
                m_length = index + 1;
            }

            if (isDense())
            {
convert_and_set_sparse:
                convertToSparse();
            }
            
            getTable()->add(indexToName(index), value);
        }

        verify();
    }

    void ArrayObject::_setIntProperty(int32_t index, Atom value)
    {
        AvmAssert(value != atomNotFound);

        if (index >= 0)
            // this is a hot function, but we still must
            // call the virtual function in case it's been overridden
            setUintProperty(index, value);
        else // integer is negative - we must intern it
            setStringProperty(core()->internInt(index), value);
    }

    void ArrayObject::_setDoubleProperty(double d, Atom value)
    {
        uint32_t index = uint32_t(d);
        if (double(index) == d)
            // this is a hot function, but we still must
            // call the virtual function in case it's been overridden
            setUintProperty(index, value);
        else
            // Number is non-integral, negative, or too large to be a valid index, so intern it.
            setStringProperty(core()->internDouble(d), value);
    }

    // ----------------- "del" methods

    bool ArrayObject::delDenseUintProperty(uint32_t index)
    {
        verify();

        AvmAssert(isDense());
           
        uint32_t const denseIdx = index - m_denseStart;
        AvmAssert(denseIdx < m_denseArray.length());

        // Note that delUintProperty does not affect m_length!
        if (m_denseArray.get(denseIdx) != atomNotFound)
        {
            m_denseArray.replace(denseIdx, atomNotFound);
            m_denseUsed--;
            
            // If deleting the last dense item, revert to like-new.
            if (m_denseUsed == 0)
            {
                // Use set_length(0) rather than clear(), so that
                // we don't discard allocated capacity.
                m_denseArray.set_length(0);
                m_denseStart = 0;
            }
        }

        verify();

        if (shouldBeSparse(m_denseArray.length(), m_denseUsed))
        {
            convertToSparse();
        }
        
        return true;
    }

    bool ArrayObject::delUintProperty(uint32_t index)
    {
        bool result;
        
        verify();
        
        uint32_t const denseIdx = index - m_denseStart;
        if (denseIdx < m_denseArray.length())
        {
            delDenseUintProperty(index);
            result = true;
        }
        else
        {
            result = ScriptObject::delUintProperty(index);
        }

        verify();
        
        return result;
    }

    bool ArrayObject::deleteAtomProperty(Atom name)
    {
        bool result;
        
        verify();
        
        uint32_t index, denseIdx;
        if (AvmCore::getIndexFromAtom(name, &index) &&
            (denseIdx = index - m_denseStart) < m_denseArray.length())
        {
            delDenseUintProperty(index);
            result = true;
        }
        else
        {
            result = ScriptObject::deleteAtomProperty(name);
        }

        verify();
        
        return result;
    }

    // ----------------- "has" methods

    bool ArrayObject::hasUintProperty(uint32_t index) const
    {
        uint32_t const denseIdx = index - m_denseStart;
        if (denseIdx < m_denseArray.length())
        {
            return m_denseArray.get(denseIdx) != atomNotFound;
        }
        else
        {
            return ScriptObject::hasUintProperty(index);
        }
    }

    bool ArrayObject::hasAtomProperty(Atom name) const
    {
        bool result;
        
        verify();
        
        uint32_t index, denseIdx;
        if (AvmCore::getIndexFromAtom(name, &index) &&
            (denseIdx = index - m_denseStart) < m_denseArray.length())
        {
            result = m_denseArray.get(denseIdx) != atomNotFound;
        }
        else
        {
            result = ScriptObject::hasAtomProperty(name);
        }

        verify();
        
        return result;
    }

    // ----------------- "next" methods

    Atom ArrayObject::nextName(int index)
    {
        AvmAssert(index > 0);

        int denseLength = (int)m_denseArray.length();
        if (index <= denseLength)
        {
            AvmAssert(isDense());
            return core()->intToAtom(index + m_denseStart - 1);
        }
        else
        {
            return ScriptObject::nextName(index - denseLength);
        }
    }

    Atom ArrayObject::nextValue(int index)
    {
        AvmAssert(index > 0);

        int denseLength = (int)m_denseArray.length();
        if (index <= denseLength)
        {
            AvmAssert(isDense());
            return m_denseArray.get(index-1);
        }
        else
        {
            return ScriptObject::nextValue(index - denseLength);
        }
    }

    int ArrayObject::nextNameIndex(int index)
    {
        int denseLength = (int)m_denseArray.length();
        while (index < denseLength)
        {
            if (m_denseArray.get(index) != atomNotFound)
            {
                return index+1;
            }
            ++index;
        }

        index = ScriptObject::nextNameIndex(index - denseLength);
        if (!index)
            return index;
        return denseLength + index;
    }

#ifdef AVMPLUS_VERBOSE
    PrintWriter& ArrayObject::print(PrintWriter& prw) const
    {
        return prw << "[]@" << asAtomHex(atom());
    }
#endif


    /*virtual*/ void ArrayObject::setLength(uint32_t newLength)
    {
        verify();
        
        if (isDynamic())
        {
            uint32_t oldLength = getLength();
            m_length = newLength;

            // Delete all items between size and newLength
            if (isDense())
            {
                if (m_denseArray.length() == 0 && oldLength == 0)
                {
                    // We are "dense" but actually empty; we usually get
                    // here when constructing a new array with an initial length.
                    // Don't pre-allocate a dense size, since we don't know
                    // if the Array will end up being dense or not, and requests
                    // to pre-allocate large arrays might waste memory.
                    //
                    // OPTIMIZEME: might make sense to preallocate sizes that are
                    // larger than MIN_SPARSE_INDEX but still "small", on the assumption
                    // that most arrays are dense?
                }
                else if (newLength < oldLength)
                {
                    if (newLength > m_denseStart)
                    {
                        m_denseArray.set_length(newLength - m_denseStart);
                        m_denseUsed = calcDenseUsed();
                        // Shouldn't need to check for sparseness if we are reducing length.
                        AvmAssert(!shouldBeSparse(newLength - m_denseStart, m_denseUsed));
                    }
                    else
                    {
                        // use set_length(0) rather than clear(), so that
                        // we don't discard allocated capacity
                        m_denseArray.set_length(0);
                        m_denseStart = 0;
                        m_denseUsed = 0;
                    }
                }
                else if (newLength > oldLength)
                {
                    // Check for sparseness before set_length, so giant requests don't trigger OOM
                    if (shouldBeSparse(newLength - m_denseStart, m_denseUsed))
                    {
                        convertToSparse();
                    }
                    else
                    {
                        m_denseArray.set_length(newLength - m_denseStart);
                        for (uint32_t i = oldLength - m_denseStart, n = m_denseArray.length(); i < n; ++i)
                            m_denseArray.replace(i, atomNotFound);
                    }
                }
            }
            else if (isSparse())
            {
                // All entries are in the hashtable.
                // in theory we need to call delUintProperty on every one of these, but in practice,
                // user AS3 code can't override delUintProperty, and no existing VM/Flash/AIR classes subclass ArrayObject,
                // so we can (and should) short-circuit this and just process the items actually present.
                // (this is MUCH faster if the sole item was at index 0xfffffff0...)
                InlineHashtable* ht = this->getTable();
                for (int i = ht->next(0); i != 0; i = ht->next(i))
                {
                    Atom k = ht->keyAt(i);
                    uint32_t index;
                    if (AvmCore::getIndexFromAtom(k, &index) && index >= newLength)
                    {
                        ht->remove(k);
                    }
                }
            }
        }

        verify();
    }

    // public native function pop(...rest):Object
    Atom ArrayObject::AS3_pop()
    {
        verify();
        Atom result = undefinedAtom;
        uint32_t len = getLength();
        if (len != 0)
        {
            if (isDense())
            {
                // Yes, we can have isDense=true but m_denseArray empty.
                result = !m_denseArray.isEmpty() ? m_denseArray.removeLast() : undefinedAtom;
                if (result == atomNotFound)
                    result = undefinedAtom;
                else
                    m_denseUsed--;
                m_length--;
            }
            else
            {
                result = _getUintProperty(len-1);
                setLength(len-1);
            }
        }
        verify();
        return result;
    }

    uint32_t ArrayObject::AS3_push(Atom* argv, int argc)
    {
        verify();
        if (argc > 0)
        {
            if (isDense())
            {
                uint32_t const curDenseEnd = m_denseStart + m_denseArray.length();
                if (m_length == curDenseEnd)
                {
                    // By far the most common case.
                    // We don't need to check for sparseness, since we aren't inserting any holes.
                    m_denseArray.insert(m_denseArray.length(), argv, argc);
                }
                else
                {
                    AvmAssert(m_length > curDenseEnd);
                    
                    // push() always inserts at m_length, which might be larger than
                    // curDenseEnd. In that case, we might need to become sparse
                    // (or at least insert "holes").
                    uint32_t const newDenseLen = (m_length - m_denseStart) + argc;
                    uint32_t const newDenseUsed = m_denseUsed + argc;
                    if (shouldBeSparse(newDenseLen, newDenseUsed))
                    {
                        convertToSparse();
                        goto push_sparse;
                    }
                    
                    m_denseArray.ensureCapacity(newDenseLen);
                    m_denseArray.insert(m_denseArray.length(), atomNotFound, m_length - curDenseEnd);
                    m_denseArray.insert(m_denseArray.length(), argv, argc);
                    AvmAssert(m_denseArray.length() == newDenseLen);
                }
                m_denseUsed += argc;
                m_length += argc;
            }
            else
            {
push_sparse:
                for (int i=0; i < argc; i++)
                {
                    _setUintProperty(getLength(), argv[i]);
                }
            }
        }
        verify();
        return getLength();
    }

    uint32_t ArrayObject::AS3_unshift(Atom* argv, int argc)
    {
        verify();
        if (argc > 0)
        {
            if (isDense())
            {
                if (m_denseStart > 0)
                {
                    // We only need to check for sparseness if we are inserting holes;
                    // inserting non-holes can't make us any "less dense".
                    if (shouldBeSparse(m_denseArray.length() + m_denseStart + argc, m_denseUsed + argc))
                    {
                        convertToSparse();
                        goto unshift_sparse;
                    }
                    m_denseArray.insert(0, atomNotFound, m_denseStart);
                }

                m_denseArray.insert(0, argv, argc);
                m_denseUsed += argc;
                m_length += argc;
            }
            else
            {
unshift_sparse:
                // First, move all the elements up
                uint32_t len = getLength();
                for (uint32_t i = len; i > 0; --i)
                {
                    _setUintProperty(i-1+argc, _getUintProperty(i-1));
                }

                for (uint32_t i = 0; i < (uint32_t)argc; i++)
                {
                    _setUintProperty(i, argv[i]);
                }

                setLength(len +argc);
            }
        }
        verify();
        return getLength();
    }

#ifdef DEBUGGER
    uint64_t ArrayObject::bytesUsed() const
    {
        return ScriptObject::bytesUsed() + m_denseArray.bytesUsed();
    }
#endif

    bool ArrayObject::try_concat(ArrayObject* that)
    {
        verify();
        that->verify();
        if (this->isDense() &&
            that->isDense() &&
            this->m_length == this->getLengthProperty() &&
            that->m_length == that->getLengthProperty())
        {
            // Adding denseUsed can't overflow a uint32, since each is <= 0x7fffffff,
            // but m_length could, since they could be arbitrary large, so check for overflow.
            uint64_t const totLen = uint64_t(this->m_length) + uint64_t(that->m_length);
            if (totLen != uint32_t(totLen) ||
                shouldBeSparse(uint32_t(totLen), this->m_denseUsed + that->m_denseUsed))
            {
                convertToSparse();
                return false;
            }

            uint32_t extraHoles = that->m_denseStart;
            uint32_t this_denseEnd = this->m_denseStart + this->m_denseArray.length();
            if (this_denseEnd < this->m_length)
                extraHoles += (this->m_length - this_denseEnd);
            if (extraHoles > 0)
                this->m_denseArray.insert(this->m_denseArray.length(), atomNotFound, extraHoles);
            this->m_denseArray.add(that->m_denseArray);
            this->m_denseUsed += that->m_denseUsed;
            this->m_length += that->m_length;

            AvmAssert(!shouldBeSparse(m_denseArray.length(), m_denseUsed));
            verify();
            return true;
        }
        return false;
    }

    bool ArrayObject::try_reverse()
    {
        if (isDense())
        {
            verify();
            m_denseArray.reverse();
            m_denseStart = 0;
            verify();
            return true;
        }
        return false;
    }

    bool ArrayObject::try_shift(Atom& result)
    {
        verify();
        if (isDense() && m_length > 0 && m_length == getLengthProperty())
        {
            if (m_denseStart > 0)
            {
                --m_denseStart;
                result = undefinedAtom;
            }
            else if (m_denseArray.length() > 0)
            {
                // m_length>0 does not imply m_denseArray.length()>0;
                // we could have set the length on a new array to something
                // large, and not yet populated the storage.
                result = m_denseArray.removeFirst();
                --m_denseUsed;
            }
            --m_length;

            verify();
            return true;
        }
        
        return false;
    }

    ArrayObject* ArrayObject::try_splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const ArrayObject* that, uint32_t that_skip)
    {
        verify();

// OPTIMIZEME, probably other dense cases could be handled too
        if (this->isDense() &&
            that != NULL &&
            that->isDense() &&
            insertPoint >= this->m_denseStart &&
            insertPoint <= this->m_denseStart + this->m_denseArray.length() &&
            insertPoint + deleteCount <= this->m_denseStart + this->m_denseArray.length() &&
            that->m_denseStart == 0)
        {
            insertPoint -= this->m_denseStart;

            ArrayObject* deletedItems = toplevel()->arrayClass()->newArray(0);
            deletedItems->m_denseArray.splice(0, deleteCount, 0, this->m_denseArray, insertPoint);
            deletedItems->m_denseStart = 0;
            deletedItems->m_denseUsed = deleteCount;
            deletedItems->m_length = deleteCount;
            
            uint32_t that_len = that->m_denseArray.length();
            if (insertCount > that_len - that_skip)
                insertCount = that_len - that_skip;

            this->m_denseArray.splice(insertPoint, insertCount, deleteCount, that->m_denseArray, that_skip);
            this->m_denseStart = 0;
            this->m_denseUsed = this->calcDenseUsed();
            this->m_length = this->m_length + insertCount - deleteCount;
            
            verify();
            deletedItems->verify();
            return deletedItems;
        }

        return NULL;
    }

    bool ArrayObject::try_unshift(ArrayObject* that)
    {
        verify();
        if (this->isDense() &&
            that->isDense() &&
            this->m_length == this->getLengthProperty() &&
            that->m_length == that->getLengthProperty())
        {
            uint32_t const that_length = that->getLengthProperty();
            uint32_t thisExtraHolesFront = this->m_denseStart;
            uint32_t thatExtraHolesBack = that_length - (that->m_denseStart + that->m_denseArray.length());
            uint32_t extraHoles = thisExtraHolesFront + thatExtraHolesBack;
            if (extraHoles > 0)
            {
                // We only need to check for sparseness if we are inserting holes;
                // inserting non-holes can't make us any "less dense".
                if (shouldBeSparse(this->m_denseArray.length() + extraHoles, this->m_denseUsed + that->m_denseUsed))
                {
                    convertToSparse();
                    verify();
                    return false;
                }
            }

            // OPTIMIZEME, there's a way to add a list to the end of another,
            // but not to insert at an arbitrary spot.
            m_denseArray.insert(0, atomNotFound, that->m_denseArray.length() + extraHoles);
            for (uint32_t i = 0, n = that->m_denseArray.length(); i < n; ++i)
                this->m_denseArray.replace(i, that->m_denseArray.get(i));
            this->m_denseStart = that->m_denseStart;
            this->m_denseUsed += that->m_denseUsed;
            this->m_length += that_length;
            verify();
            return true;
        }
        return false;
    }

    uint32_t ArrayObject::getLengthProperty()
    {
        // If we are an Array object (and NOT a subclass thereof)
        // then we can take this shortcut.
        if (this->traits() == core()->traits.array_itraits)
        {
            return get_length();
        }
        else
        {
            return ScriptObject::getLengthProperty();
        }
    }

    void ArrayObject::setLengthProperty(uint32_t newLen)
    {
        // If we are an Array object (and NOT a subclass thereof)
        // then we can take this shortcut.
        if (this->traits() == core()->traits.array_itraits)
        {
            set_length(newLen);
        }
        else
        {
            ScriptObject::setLengthProperty(newLen);
        }
    }
    
    // --------------

    Atom SemiSealedArrayObject::getAtomProperty(Atom name) const
    {
        return getAtomPropertyFromProtoChain(name, getDelegate(), traits());
    }

    void SemiSealedArrayObject::setAtomProperty(Atom name, Atom)
    {
        throwWriteSealedError(name);
    }

    bool SemiSealedArrayObject::deleteAtomProperty(Atom)
    {
        return false;
    }

    bool SemiSealedArrayObject::hasAtomProperty(Atom) const
    {
        return false;
    }

    Atom SemiSealedArrayObject::getUintProperty(uint32_t i) const
    {
        Stringp interned;
        bool present = core()->isInternedUint(i, &interned);
        return present ? getAtomProperty(interned->atom()) : undefinedAtom;
    }

    void SemiSealedArrayObject::setUintProperty(uint32_t i, Atom)
    {
        throwWriteSealedError(core()->internUint32(i)->atom());
    }

    bool SemiSealedArrayObject::delUintProperty(uint32_t)
    {
        return false;
    }

    bool SemiSealedArrayObject::hasUintProperty(uint32_t) const
    {
        return false;
    }

    bool SemiSealedArrayObject::getAtomPropertyIsEnumerable(Atom) const
    {
        return false;
    }

    void SemiSealedArrayObject::setAtomPropertyIsEnumerable(Atom name, bool)
    {
        throwWriteSealedError(name);
    }


    void SemiSealedArrayObject::setLength(uint32_t)
    {
        // nothing
    }

    ArrayObject* SemiSealedArrayObject::try_splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const ArrayObject* that, uint32_t that_skip)
    {
        if (deleteCount > 0)
            toplevel()->throwReferenceError(kReadSealedError, core()->toErrorString(insertPoint));
        return ArrayObject::try_splice(insertPoint, insertCount, deleteCount, that, that_skip);
    }

    /*static*/ ScriptObject* FASTCALL SemiSealedArrayObject::createInstanceProc(avmplus::ClassClosure* cls)
    {
        return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) SemiSealedArrayObject(cls->ivtable(), cls->prototypePtr());
    }
}
