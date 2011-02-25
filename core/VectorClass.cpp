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

#include "VectorClass-impl.h"

namespace avmplus
{
    // Force explicit instantiations for various non-inlined methods;
    // some compilers don't need this, but some do.

    template class TypedVectorClass<IntVectorObject>;
    template class TypedVectorClass<UIntVectorObject>;
    template class TypedVectorClass<DoubleVectorObject>;
    template class TypedVectorClass<ObjectVectorObject>;

    template class TypedVectorObject< DataList<int32_t> >;
    template class TypedVectorObject< DataList<uint32_t> >;
    template class TypedVectorObject< DataList<double> >;
    template class TypedVectorObject< AtomList >;
}

namespace avmplus
{
    // ----------------------------

    // helper method
    // sets index to the uint32_t value of name, if it can be converted
    // isNumber is set to true if name was a number (whether it was a uint32_t value or not)
    VectorBaseObject::VectorIndexStatus VectorBaseObject::getVectorIndex(Atom name, uint32_t& index) const
    {
        if (AvmCore::getIndexFromAtom(name, &index))
        {
            return kValidNumber;
        }
        else if (AvmCore::isString(name))
        {
            Stringp s = core()->string(name);
            wchar c = s->charAt(0);
            // Does it look like a number?
            if (s->length() > 0 && c >= '0' && c <= '9')
            {
                double const index_d = s->toNumber();
                if (!MathUtils::isNaN(index_d))
                {
                    // name is a string that looks like a number
                    // Note: convert using int, not uint, as it's much faster
                    int32_t const index_i = int32_t(index_d);
                    index = uint32_t(index_i);
                    return (double(index_i) == index_d) ? kValidNumber : kInvalidNumber;
                }
            }
        }
        return kNotNumber;
    }

    // ----------------------------

    VectorClass::VectorClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        setPrototypePtr(toplevel()->objectClass->construct());
    }

    /*static*/ Stringp VectorClass::makeVectorClassName(AvmCore* core, Traits* t)
    {
        Stringp s = core->newConstantStringLatin1("Vector.<");
        s = s->append(t->formatClassName());
        s = s->append(core->newConstantStringLatin1(">"));
        // all callers want it interned, so let's do it here
        return core->internString(s);
    }

    ClassClosure* VectorClass::getTypedVectorClass(ClassClosure* typeClass)
    {
        ClassClosure* result = NULL;
        Toplevel* toplevel = this->toplevel();
        if (typeClass == NULL)
        {
            result = toplevel->objectVectorClass();
        }
        else if (typeClass == toplevel->intClass())
        {
            result = toplevel->intVectorClass();
        }
        else if (typeClass == toplevel->uintClass())
        {
            result = toplevel->uintVectorClass();
        }
        else if (typeClass == toplevel->numberClass())
        {
            result = toplevel->doubleVectorClass();
        }
        else
        {
            // if we have an object, we must have an itraits (otherwise the typearg is not a Class)
            Traits* typeTraits = typeClass->vtable->traits->itraits;
            if (!typeTraits)
                toplevel->throwVerifyError(kCorruptABCError);

            Domain* typeDomain = typeClass->traits()->pool->domain;
            if ((result = typeDomain->getParameterizedType(typeClass)) == NULL)
            {
                Stringp fullname = VectorClass::makeVectorClassName(core(), typeTraits);

                VTable* vt = this->vtable->newParameterizedVTable(typeTraits, fullname);

                vt->ivtable->createInstanceProc = ClassClosure::impossibleCreateInstanceProc;
                ObjectVectorClass* parameterizedVector = ObjectVectorClass::create(vt->gc(), vt);
                parameterizedVector->m_typeTraits = typeClass ? typeClass->traits()->itraits : NULL;
                parameterizedVector->setDelegate(toplevel->classClass()->prototypePtr());

                // Is this right?  Should each instantiation get its own prototype?
                parameterizedVector->setPrototypePtr(toplevel->objectVectorClass()->prototypePtr());
                typeDomain->addParameterizedType(typeClass, parameterizedVector);

                result = parameterizedVector;
            }
        }
        AvmAssert(result != NULL);
        return result;
    }

    Atom VectorClass::applyTypeArgs(int argc, Atom* argv)
    {
        Toplevel* toplevel = this->toplevel();

        // Vector only takes 1 type argument
        AvmAssert(argc==1);
        if (argc != 1)
        {
            toplevel->typeErrorClass()->throwError(kWrongTypeArgCountError, traits()->formatClassName(), core()->toErrorString(1), core()->toErrorString(argc));
        }

        Atom const typeAtom = argv[0];

        ClassClosure* typeClass = NULL;
        if (!ISNULL(typeAtom))
        {
            if (atomKind(typeAtom) != kObjectType)
                toplevel->throwVerifyError(kCorruptABCError);

            typeClass = (ClassClosure*)AvmCore::atomToScriptObject(typeAtom);
            if (!typeClass->vtable->traits->itraits)
                toplevel->throwVerifyError(kCorruptABCError);
        }
        return getTypedVectorClass(typeClass)->atom();
    }

    Atom VectorClass::construct(int /*argc*/, Atom* /*argv*/)
    {
        toplevel()->throwTypeError(kConstructOfNonFunctionError);
        return undefinedAtom;
    }

    // FIXME: this could return a non-ObjectVectorObject, so we should really
    // return VectorBaseObject instead.
    ObjectVectorObject* VectorClass::newVector(ClassClosure* type, uint32_t length)
    {
        ClassClosure* vc = getTypedVectorClass(type);
        Atom args[2] = { nullObjectAtom, core()->uintToAtom(length) };
        return (ObjectVectorObject*)AvmCore::atomToScriptObject(vc->construct(1, args));
    }

    // ----------------------------

    IntVectorClass::IntVectorClass(VTable* vtable)
        : TypedVectorClass<IntVectorObject>(vtable)
    {
        // This is an ugly hack: Vector<> doesn't work properly with the ClassManifest setup,
        // because the name it returns for itself isn't the name listed for finddef.
        // To work around this (and maintain legacy internal behavior), we pre-emptively
        // enter the Vector classes into the table upon first creation. (Arguably the name
        // lookup issue should be fixed.)
        toplevel()->builtinClasses()->fillInClass(avmplus::NativeID::abcclass___AS3___vec_Vector_int, this); 
        this->m_typeTraits = toplevel()->intClass()->traits()->itraits;
    }

    Atom IntVectorClass::construct(int argc, Atom* argv)
    {
        return constructImpl(argc, argv);
    }

    // ----------------------------

    UIntVectorClass::UIntVectorClass(VTable* vtable)
        : TypedVectorClass<UIntVectorObject>(vtable)
    {
        // This is an ugly hack: Vector<> doesn't work properly with the ClassManifest setup,
        // because the name it returns for itself isn't the name listed for finddef.
        // To work around this (and maintain legacy internal behavior), we pre-emptively
        // enter the Vector classes into the table upon first creation. (Arguably the name
        // lookup issue should be fixed.)
        toplevel()->builtinClasses()->fillInClass(avmplus::NativeID::abcclass___AS3___vec_Vector_uint, this); 
        this->m_typeTraits = toplevel()->uintClass()->traits()->itraits;
    }

    Atom UIntVectorClass::construct(int argc, Atom* argv)
    {
        return constructImpl(argc, argv);
    }

    // ----------------------------

    DoubleVectorClass::DoubleVectorClass(VTable* vtable)
        : TypedVectorClass<DoubleVectorObject>(vtable)
    {
        // This is an ugly hack: Vector<> doesn't work properly with the ClassManifest setup,
        // because the name it returns for itself isn't the name listed for finddef.
        // To work around this (and maintain legacy internal behavior), we pre-emptively
        // enter the Vector classes into the table upon first creation. (Arguably the name
        // lookup issue should be fixed.)
        toplevel()->builtinClasses()->fillInClass(avmplus::NativeID::abcclass___AS3___vec_Vector_double, this); 
        this->m_typeTraits = toplevel()->numberClass()->traits()->itraits;
    }

    Atom DoubleVectorClass::construct(int argc, Atom* argv)
    {
        return constructImpl(argc, argv);
    }

    // ----------------------------

    ObjectVectorClass::ObjectVectorClass(VTable* vtable)
        : TypedVectorClass<ObjectVectorObject>(vtable)
    {
        // This is an ugly hack: Vector<> doesn't work properly with the ClassManifest setup,
        // because the name it returns for itself isn't the name listed for finddef.
        // To work around this (and maintain legacy internal behavior), we pre-emptively
        // enter the Vector classes into the table upon first creation. (Arguably the name
        // lookup issue should be fixed.)
        toplevel()->builtinClasses()->fillInClass(avmplus::NativeID::abcclass___AS3___vec_Vector_object, this); 
        this->m_typeTraits = toplevel()->objectClass->traits()->itraits;
    }

    Atom ObjectVectorClass::construct(int argc, Atom* argv)
    {
        return constructImpl(argc, argv);
    }

    // ----------------------------

    IntVectorObject::IntVectorObject(VTable* ivtable, ScriptObject* delegate)
        : TypedVectorObject< DataList<int32_t> >(ivtable, delegate)
    {
    }

    IntVectorObject* IntVectorObject::newThisType()
    {
        return (IntVectorObject*)_newVector();
    }

    // ----------------------------

    UIntVectorObject::UIntVectorObject(VTable* ivtable, ScriptObject* delegate)
        : TypedVectorObject< DataList<uint32_t> >(ivtable, delegate)
    {
    }

    UIntVectorObject* UIntVectorObject::newThisType()
    {
        return (UIntVectorObject*)_newVector();
    }

    // ----------------------------

    DoubleVectorObject::DoubleVectorObject(VTable* ivtable, ScriptObject* delegate)
        : TypedVectorObject< DataList<double> >(ivtable, delegate)
    {
    }

    DoubleVectorObject* DoubleVectorObject::newThisType()
    {
        return (DoubleVectorObject*)_newVector();
    }

    // ----------------------------

    ObjectVectorObject::ObjectVectorObject(VTable* ivtable, ScriptObject* delegate)
        : TypedVectorObject< AtomList >(ivtable, delegate)
    {
    }

    ObjectVectorObject* ObjectVectorObject::newThisType()
    {
        return (ObjectVectorObject*)_newVector();
    }
}
