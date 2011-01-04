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


#ifndef __avmplus_VectorClass_impl__
#define __avmplus_VectorClass_impl__

namespace avmplus
{
    // ----------------------------

    Atom TypedVectorClassBase::call(int argc, Atom* argv)
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();
        
        if (argc != 1)
            toplevel->throwArgumentError(kCoerceArgumentCountError, core->toErrorString(argc));

        Traits* itraits = ivtable()->traits;
        if (AvmCore::istype(argv[1], itraits))
            return argv[1];

        if (!AvmCore::isObject(argv[1]))
            toplevel->throwTypeError(kCheckTypeFailedError, core->atomToErrorString(argv[1]), core->toErrorString(itraits));

        ScriptObject* so_args = AvmCore::atomToScriptObject(argv[1]);
        uint32_t len = ArrayClass::getLengthHelper(toplevel, so_args);
        return createAndInitVectorFromObject(so_args, len);
    }

    void TypedVectorClassBase::_forEach(Atom thisAtom, ScriptObject* callback, Atom thisObject) 
    { 
        return ArrayClass::generic_forEach(toplevel(), thisAtom, callback, thisObject); 
    }
    
    bool TypedVectorClassBase::_every(Atom thisAtom, ScriptObject* callback, Atom thisObject) 
    { 
        return ArrayClass::generic_every(toplevel(), thisAtom, callback, thisObject); 
    }
    
    bool TypedVectorClassBase::_some(Atom thisAtom, ScriptObject* callback, Atom thisObject) 
    { 
        return ArrayClass::generic_some(toplevel(), thisAtom, callback, thisObject); 
    }
    
    Atom TypedVectorClassBase::_sort(Atom thisAtom, ArrayObject* args) 
    { 
        return ArrayClass::generic_sort(toplevel(), thisAtom, args); 
    }

    // ----------------------------

    template<class OBJ>
    TypedVectorClass<OBJ>::TypedVectorClass(VTable* vtable)
        : TypedVectorClassBase(vtable)
    {
        setPrototypePtr(toplevel()->objectClass->construct());
    }

    template<class OBJ>
    ScriptObject* TypedVectorClass<OBJ>::createInstance(VTable* ivtable, ScriptObject* prototype)
    {
        return OBJ::create(core()->GetGC(), ivtable, prototype, this);
    }

    template<class OBJ>
    OBJ* TypedVectorClass<OBJ>::newVector(uint32_t length)
    {
        OBJ* v = OBJ::create(core()->GetGC(), ivtable(), prototypePtr(), this);
        if (length > 0)
            v->set_length(length);
        return v;
    }

    template<class OBJ>
    Atom TypedVectorClass<OBJ>::createAndInitVectorFromObject(ScriptObject* so_args, uint32_t len)
    {
        OBJ* v = OBJ::create(core()->GetGC(), ivtable(), prototypePtr(), this);
        v->_spliceHelper_so(0, len, 0, so_args, 0);
        return v->atom();
    }

    // ----------------------------

    VectorBaseObject::VectorBaseObject(VTable* ivtable, ScriptObject* delegate, TypedVectorClassBase* vecClass)
        : ScriptObject(ivtable, delegate)
        , m_vecClass(vecClass)
        , m_fixed(false)
    {
    }

    VectorBaseObject* VectorBaseObject::_newVector()
    {
        VectorBaseObject* v = (VectorBaseObject*)m_vecClass->createInstance(m_vecClass->ivtable(), m_vecClass->prototypePtr());
        v->m_vecClass = this->m_vecClass;
        return v;
    }

    void FASTCALL VectorBaseObject::throwFixedError() const
    {
        toplevel()->throwRangeError(kVectorFixedError);
    }

    Atom VectorBaseObject::_mapImpl(ScriptObject* callback, Atom thisObject, VectorBaseObject* r, uint32_t len)
    {
        AvmCore* core = this->core();
        if (callback)
        {
            ScriptObject* d = this;
            for (uint32_t i = 0; i < len; i++)
            {
                // If thisObject is null, the call function will substitute the global object
                // args are modified in place by callee
                Atom args[4] = {
                    thisObject,
                    d->getUintProperty(i), // element
                    core->uintToAtom(i), // index
                    this->atom()
                };
                Atom result = callback->call(3, args);
                r->setUintProperty(i, result);
            }
        }
        return r->atom();
    }

    Atom VectorBaseObject::_filterImpl(ScriptObject* callback, Atom thisObject, VectorBaseObject* r, uint32_t len)
    {
        AvmCore* core = this->core();
        if (callback)
        {
            ScriptObject* d = this;
            for (uint32_t i = 0, k = 0; i < len; i++)
            {
                // If thisObject is null, the call function will substitute the global object
                // args are modified in place by callee
                Atom element = d->getUintProperty(i);
                Atom args[4] = {
                    thisObject,
                    element,
                    core->uintToAtom(i), // index
                    this->atom()
                };
                Atom result = callback->call(3, args);
                if (result == trueAtom)
                    r->setUintProperty(k++, element);
            }
        }
        return r->atom();
    }

    // ----------------------------

    template<class TLIST>
    TypedVectorObject<TLIST>::TypedVectorObject(VTable* ivtable, ScriptObject* delegate, MMgc::GC* gc, TypedVectorClassBase* vecClass)
        : VectorBaseObject(ivtable, delegate, vecClass)
        , m_list(gc, 0)
    {
    }

    template<class TLIST>
    bool TypedVectorObject<TLIST>::hasAtomProperty(Atom name) const
    {
        uint32_t index;
        VectorIndexStatus status = getVectorIndex(name, index);
        if (status == kValidNumber)
        {
            return index < m_list.length();
        }
        else if (status == kInvalidNumber)
        {
            return false;
        }
        else // status == kNotNumber
        {
            return ScriptObject::hasAtomProperty(name);
        }
    }
        
    template<class TLIST>
    void TypedVectorObject<TLIST>::setAtomProperty(Atom name, Atom value)
    {
        uint32_t index;
        VectorIndexStatus status = getVectorIndex(name, index);
        if (status == kValidNumber)
        {
            setUintProperty(index, value);
        }
        else
        {
           toplevel()->throwReferenceError(kWriteSealedError, core()->string(name), traits());
        }
    }
        
    template<class TLIST>
    Atom TypedVectorObject<TLIST>::getAtomProperty(Atom name) const
    {
        uint32_t index;
        VectorIndexStatus status = getVectorIndex(name, index);
        if (status == kValidNumber)
        {
            return getUintProperty(index);
        }
        else if (status == kInvalidNumber)
        {
            // Not a valid indexed name - has a decimal part
            toplevel()->throwReferenceError(kReadSealedError, core()->string(name), traits());
            return undefinedAtom; // not reached
        }
        else // status == kNotNumber
        {
            // Check the prototype chain - that will throw if there is no match
            return getAtomPropertyFromProtoChain(name, getDelegate(), traits());
        }
    }

    template<class TLIST>
    /*virtual*/ uint32_t TypedVectorObject<TLIST>::getLength() const
    {
        return get_length();
    }

    template<class TLIST>
    /*virtual*/ void TypedVectorObject<TLIST>::setLength(uint32_t length)
    {
        set_length(length);
    }

    template<class TLIST>
    void TypedVectorObject<TLIST>::set_length(uint32_t newLength)
    {
        checkFixed();
        // this is what the old code did, so we'll do it too: set the capacity explicitly if we grow
        if (newLength > m_list.capacity())
        {
            m_list.set_capacity(newLength); 
        }
        m_list.set_length(newLength);
    }
        
    template<class TLIST>
    Atom TypedVectorObject<TLIST>::nextName(int index)
    {
        AvmAssert(index > 0);
        if (uint32_t(index) <= m_list.length())
        {
            return core()->intToAtom(index-1);
        }
        else
        {
            return nullStringAtom;
        }
    }
        
    template<class TLIST>
    Atom TypedVectorObject<TLIST>::nextValue(int index)
    {
        AvmAssert(index > 0);
        if (uint32_t(index) <= m_list.length())
        {
            return getUintProperty(index-1);
        }
        else
        {
            return undefinedAtom;
        }
    }
        
    template<class TLIST>
    int TypedVectorObject<TLIST>::nextNameIndex(int index)
    {
        if (uint32_t(index) < m_list.length())
        {
            return index + 1;
        }
        else
        {
            return 0;
        }
    }
        
    template<class TLIST>
    Atom TypedVectorObject<TLIST>::_map(ScriptObject* callback, Atom thisObject)
    {
        TypedVectorObject<TLIST>* r = (TypedVectorObject<TLIST>*)_newVector();
        uint32_t const len = m_list.length();
        r->set_length(len);
        return _mapImpl(callback, thisObject, r, len);
    }

    template<class TLIST>
    Atom TypedVectorObject<TLIST>::_filter(ScriptObject* callback, Atom thisObject)
    {
        TypedVectorObject<TLIST>* r = (TypedVectorObject<TLIST>*)_newVector();
        uint32_t const len = m_list.length();
        return _filterImpl(callback, thisObject, r, len);
    }

    template<class TLIST>
    void TypedVectorObject<TLIST>::_spliceHelper_so(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, ScriptObject* so_args, uint32_t offset)
    {
        AvmAssert(!AvmCore::istype(so_args->atom(), vtable->traits));

        // NB: so_args could be any kind of object, but in practice,
        // it's almost always an ArrayObject; it might be profitable
        // to sniff for that case and optimize appropriately.

        // passing NULL for args inserts the proper space, but leaves the inserted entries empty
        m_list.splice(insertPoint, insertCount, deleteCount, NULL);
        for (uint32_t i = 0; i < insertCount; i++)
        {
            typename TLIST::OPAQUE_TYPE value;
            atomToValue(so_args->getUintProperty(i+offset), value);
            m_list.set(insertPoint+i, (typename TLIST::TYPE)value);
        }
    }

    template<class TLIST>
    void TypedVectorObject<TLIST>::_spliceHelper(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, Atom args, uint32_t offset)
    {
        if (AvmCore::istype(args, vtable->traits))
        {
            TypedVectorObject<TLIST>* vec_args = (TypedVectorObject<TLIST>*)AvmCore::atomToScriptObject(args);
            m_list.splice(insertPoint, insertCount, deleteCount, vec_args->m_list, offset);
        }
        else if (AvmCore::isObject(args))
        {
            ScriptObject* so_args = AvmCore::atomToScriptObject(args);
            _spliceHelper_so(insertPoint, insertCount, deleteCount, so_args, offset);
        }
        else
        {
            AvmAssert(insertCount == 0);
            m_list.splice(insertPoint, 0, deleteCount, NULL);
        }
    }

    template<class TLIST>
    void TypedVectorObject<TLIST>::_splice(uint32_t insertPoint, uint32_t insertCount, uint32_t deleteCount, const Atom* argv)
    {
        // passing NULL for args inserts the proper space, but leaves the inserted entries empty
        m_list.splice(insertPoint, insertCount, deleteCount, NULL);
        for (uint32_t i = 0; i < insertCount; i++)
        {
            typename TLIST::OPAQUE_TYPE value;
            atomToValue(argv[i], value);
            m_list.set(insertPoint+i, (typename TLIST::TYPE)value);
        }
    }

    template<class TLIST>
    uint32_t TypedVectorObject<TLIST>::AS3_push(Atom* argv, int argc)
    {
        checkFixed();
        _splice(m_list.length(), argc, 0, argv);
        return m_list.length();
    }

    template<class TLIST>
    typename TLIST::TYPE TypedVectorObject<TLIST>::AS3_pop()
    {
        checkFixed();
        return m_list.isEmpty() ? 
                (typename TLIST::TYPE)TypedVectorConstants<typename TLIST::OPAQUE_TYPE>::undefinedValue() :
                m_list.removeLast();
    }

    template<class TLIST>
    typename TLIST::TYPE TypedVectorObject<TLIST>::AS3_shift()
    {
        checkFixed();
        return m_list.isEmpty() ? 
                (typename TLIST::TYPE)TypedVectorConstants<typename TLIST::OPAQUE_TYPE>::undefinedValue() :
                m_list.removeFirst();
    }

    template<class TLIST>
    uint32_t TypedVectorObject<TLIST>::AS3_unshift(Atom* argv, int argc)
    {
        checkFixed();
        _splice(0, argc, 0, argv);
        return m_list.length();
    }

    template<class TLIST>
    typename TLIST::TYPE TypedVectorObject<TLIST>::_getNativeIntProperty(int32_t index_i) const
    {
        // Implicitly convert negative values to large uints, which will always be > length
        uint32_t const index = checkReadIndex_u(uint32_t(index_i));
        return m_list.get(index);
    }

    template<class TLIST>
    void TypedVectorObject<TLIST>::_setNativeIntProperty(int32_t index_i, typename TLIST::TYPE value)
    {
        // Implicitly convert negative values to large uints, which will always be > length
        uint32_t const index = checkWriteIndex_u(uint32_t(index_i));
        m_list.set(index, value);
    }

    template<class TLIST>
    typename TLIST::TYPE TypedVectorObject<TLIST>::_getNativeUintProperty(uint32_t index) const
    {
        index = checkReadIndex_u(index);
        return m_list.get(index);
    }

    template<class TLIST>
    void TypedVectorObject<TLIST>::_setNativeUintProperty(uint32_t index, typename TLIST::TYPE value)
    {
        index = checkWriteIndex_u(index);
        m_list.set(index, value);
    }

    template<class TLIST>
    bool TypedVectorObject<TLIST>::_hasUintProperty(uint32_t index) const
    {
        return (index < m_list.length());
    }

    template<class TLIST>
    Atom TypedVectorObject<TLIST>::_getUintProperty(uint32_t index) const
    {
        index = checkReadIndex_u(index);
        return valueToAtom((typename TLIST::OPAQUE_TYPE)m_list.get(index));
    }

    template<class TLIST>
    void TypedVectorObject<TLIST>::_setUintProperty(uint32_t index, Atom value)
    {
        index = checkWriteIndex_u(index);
        typename TLIST::OPAQUE_TYPE tmp;
        atomToValue(value, tmp);
        m_list.set(index, (typename TLIST::TYPE)tmp);
    }

    template<class TLIST>
    Atom TypedVectorObject<TLIST>::_getIntProperty(int32_t index_i) const
    {
        // Implicitly convert negative values to large uints, which will always be > length
        uint32_t const index = uint32_t(index_i);
        return _getUintProperty(index);
    }

    template<class TLIST>
    void TypedVectorObject<TLIST>::_setIntProperty(int32_t index_i, Atom value)
    {
        // Implicitly convert negative values to large uints, which will always be > length
        uint32_t const index = uint32_t(index_i);
        _setUintProperty(uint32_t(index), value);
    }
    
    template<class TLIST>
    void FASTCALL TypedVectorObject<TLIST>::throwRangeError(uint32_t index) const
    {
        toplevel()->throwRangeError(kOutOfRangeError, core()->uintToString(index), core()->uintToString(m_list.length()));
    }

    // ----------------------------
    // ----------------------------
    // ----------------------------

}

#endif /* __avmplus_VectorClass_impl__ */
