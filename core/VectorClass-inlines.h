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


#ifndef __avmplus_VectorClass_inlines__
#define __avmplus_VectorClass_inlines__

namespace avmplus
{
    // ----------------------------

    REALLY_INLINE TypedVectorClassBase::TypedVectorClassBase(VTable* vtable)
        : ClassClosure(vtable)
    {
    }


    REALLY_INLINE Atom TypedVectorClassBase::checkType(Atom a)
    {
        return avmplus::coerce(toplevel(), a, m_typeTraits);
    }

    // ----------------------------

    template<>
    REALLY_INLINE OpaqueAtom TypedVectorConstants<OpaqueAtom>::nullValue()
    {
        return (OpaqueAtom)nullObjectAtom;
    }
    template<>
    REALLY_INLINE OpaqueAtom TypedVectorConstants<OpaqueAtom>::undefinedValue()
    {
        return (OpaqueAtom)undefinedAtom;
    }

    template<class T>
    REALLY_INLINE T TypedVectorConstants<T>::nullValue()
    {
        return 0;
    }
    template<class T>
    REALLY_INLINE T TypedVectorConstants<T>::undefinedValue()
    {
        return 0;
    }

    // ----------------------------

    REALLY_INLINE bool TypedVectorObjectBase::get_fixed() const
    {
        return m_fixed;
    }

    REALLY_INLINE void TypedVectorObjectBase::set_fixed(bool f)
    {
        m_fixed = f;
    }

    REALLY_INLINE void TypedVectorObjectBase::checkFixed() const
    {
        if (m_fixed)
            throwFixedError();
    }

    REALLY_INLINE void TypedVectorObjectBase::atomToValue(Atom atom, int32_t& value)
    {
        value = AvmCore::integer(atom);
    }
    
    REALLY_INLINE Atom TypedVectorObjectBase::valueToAtom(const int32_t& value) const
    {
        return core()->intToAtom(value);
    }

    REALLY_INLINE void TypedVectorObjectBase::atomToValue(Atom atom, uint32_t& value)
    {
        value = AvmCore::toUInt32(atom);
    }
    
    REALLY_INLINE Atom TypedVectorObjectBase::valueToAtom(const uint32_t& value) const
    {
        return core()->uintToAtom(value);
    }

    REALLY_INLINE void TypedVectorObjectBase::atomToValue(Atom atom, double& value)
    {
        value = AvmCore::number(atom);
    }
    
    REALLY_INLINE Atom TypedVectorObjectBase::valueToAtom(const double& value) const
    {
        return core()->doubleToAtom(value);
    }

    REALLY_INLINE void TypedVectorObjectBase::atomToValue(Atom atom, OpaqueAtom& value)
    {
        AvmAssert(m_vecClass != NULL);
        atom = m_vecClass->checkType(atom);
        value = (OpaqueAtom)atom;
    }
    
    REALLY_INLINE Atom TypedVectorObjectBase::valueToAtom(const OpaqueAtom& value) const
    {
        return (Atom)value;
    }

    // ----------------------------

    template<class TLIST>
    REALLY_INLINE uint32_t TypedVectorObject<TLIST>::get_length() const
    {
        return m_list.length();
    }

    template<class TLIST>
    REALLY_INLINE void TypedVectorObject<TLIST>::_reverse()
    {
        m_list.reverse();
    }

    template<class TLIST>
    REALLY_INLINE bool TypedVectorObject<TLIST>::hasUintProperty(uint32_t index) const
    {
        return _hasUintProperty(index);
    }

    template<class TLIST>
    REALLY_INLINE Atom TypedVectorObject<TLIST>::getUintProperty(uint32_t index) const
    {
        return _getUintProperty(index);
    }

    template<class TLIST>
    REALLY_INLINE void TypedVectorObject<TLIST>::setUintProperty(uint32_t index, Atom value)
    {
        _setUintProperty(index, value);
    }

#ifdef DEBUGGER
    template<class TLIST>
    REALLY_INLINE uint64_t TypedVectorObject<TLIST>::bytesUsed() const
    {
        return ScriptObject::bytesUsed() + m_list.bytesUsed();
    }
#endif

    template<class TLIST>
    REALLY_INLINE uint32_t TypedVectorObject<TLIST>::checkReadIndex_u(uint32_t index) const
    {
        uint32_t const limit = m_list.length();
        if (index >= limit)
            throwRangeError(index);
        return index;
    }

    template<class TLIST>
    REALLY_INLINE uint32_t TypedVectorObject<TLIST>::checkWriteIndex_u(uint32_t index) const
    {
        // If we are 'fixed', we can't write past the end.
        // If we are not 'fixed', legal to write exactly 1 past the end, growing as needed.
        uint32_t const limit = m_list.length() + 1 - uint32_t(m_fixed);
        if (index >= limit)
            throwRangeError(index);
        return index;
    }
    
    template<class TLIST>
    REALLY_INLINE uint32_t TypedVectorObject<TLIST>::checkReadIndex_d(double d) const
    {
        int32_t const i = int32_t(d);
        if (i != d)
            throwErrorDouble_read(d);
        // Implicitly convert negative values to large uints, which will always be > length
        return checkReadIndex_u(uint32_t(i));
    }

    template<class TLIST>
    REALLY_INLINE uint32_t TypedVectorObject<TLIST>::checkWriteIndex_d(double d) const
    {
        int32_t const i = int32_t(d);
        if (i != d)
            throwErrorDouble_write(d);
        // Implicitly convert negative values to large uints, which will always be > length
        return checkWriteIndex_u(uint32_t(i));
    }
}

#endif /* __avmplus_VectorClass__ */
