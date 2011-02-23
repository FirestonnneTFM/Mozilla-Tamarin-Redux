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

namespace avmplus
{

REALLY_INLINE Toplevel* Toplevel::create(MMgc::GC* gc, AbcEnv* abcEnv)
{
    return new (gc, MMgc::kExact) Toplevel(abcEnv);
}

REALLY_INLINE GCRef<builtinClassManifest> Toplevel::builtinClasses() const
{
    AvmAssert(_builtinClasses != NULL);
    return GCRef<builtinClassManifest>(_builtinClasses);
}
    
REALLY_INLINE GCRef<ArgumentErrorClass> Toplevel::argumentErrorClass() const { return builtinClasses()->get_ArgumentErrorClass(); }
REALLY_INLINE GCRef<ArrayClass> Toplevel::arrayClass() const { return builtinClasses()->get_ArrayClass(); }
REALLY_INLINE GCRef<BooleanClass> Toplevel::booleanClass() const { return builtinClasses()->get_BooleanClass(); }
REALLY_INLINE GCRef<ByteArrayClass> Toplevel::byteArrayClass() const { return builtinClasses()->get_ByteArrayClass(); }
REALLY_INLINE GCRef<ClassClass> Toplevel::classClass() const { return builtinClasses()->get_ClassClass(); }
REALLY_INLINE GCRef<ClassClosure> Toplevel::eofErrorClass() const { return builtinClasses()->get_EOFErrorClass(); }
REALLY_INLINE GCRef<ClassClosure> Toplevel::ioErrorClass() const { return builtinClasses()->get_IOErrorClass(); }
REALLY_INLINE GCRef<ClassClosure> Toplevel::memoryErrorClass() const { return builtinClasses()->get_MemoryErrorClass(); }
REALLY_INLINE GCRef<DateClass> Toplevel::dateClass() const { return builtinClasses()->get_DateClass(); }
REALLY_INLINE GCRef<DoubleVectorClass> Toplevel::doubleVectorClass() const { return builtinClasses()->get_Vector_doubleClass(); }
REALLY_INLINE GCRef<ErrorClass> Toplevel::errorClass() const { return builtinClasses()->get_ErrorClass(); }
REALLY_INLINE GCRef<EvalErrorClass> Toplevel::evalErrorClass() const { return builtinClasses()->get_EvalErrorClass(); }
REALLY_INLINE GCRef<FunctionClass> Toplevel::functionClass() const { return builtinClasses()->get_FunctionClass(); }
REALLY_INLINE GCRef<IntClass> Toplevel::intClass() const { return builtinClasses()->get_intClass(); }
REALLY_INLINE GCRef<IntVectorClass> Toplevel::intVectorClass() const { return builtinClasses()->get_Vector_intClass(); }
REALLY_INLINE GCRef<MethodClosureClass> Toplevel::methodClosureClass() const { return builtinClasses()->get_MethodClosureClass(); }
REALLY_INLINE GCRef<NamespaceClass> Toplevel::namespaceClass() const { return builtinClasses()->get_NamespaceClass(); }
REALLY_INLINE GCRef<NumberClass> Toplevel::numberClass() const { return builtinClasses()->get_NumberClass(); }
REALLY_INLINE GCRef<ObjectVectorClass> Toplevel::objectVectorClass() const { return builtinClasses()->get_Vector_objectClass(); }
REALLY_INLINE GCRef<QNameClass> Toplevel::qnameClass() const { return builtinClasses()->get_QNameClass(); }
REALLY_INLINE GCRef<RangeErrorClass> Toplevel::rangeErrorClass() const { return builtinClasses()->get_RangeErrorClass(); }
REALLY_INLINE GCRef<ReferenceErrorClass> Toplevel::referenceErrorClass() const { return builtinClasses()->get_ReferenceErrorClass(); }
REALLY_INLINE GCRef<RegExpClass> Toplevel::regexpClass() const { return builtinClasses()->get_RegExpClass(); }
REALLY_INLINE GCRef<SecurityErrorClass> Toplevel::securityErrorClass() const { return builtinClasses()->get_SecurityErrorClass(); }
REALLY_INLINE GCRef<StringClass> Toplevel::stringClass() const { return builtinClasses()->get_StringClass(); }
REALLY_INLINE GCRef<SyntaxErrorClass> Toplevel::syntaxErrorClass() const { return builtinClasses()->get_SyntaxErrorClass(); }
REALLY_INLINE GCRef<TypeErrorClass> Toplevel::typeErrorClass() const { return builtinClasses()->get_TypeErrorClass(); }
REALLY_INLINE GCRef<UIntClass> Toplevel::uintClass() const { return builtinClasses()->get_uintClass(); }
REALLY_INLINE GCRef<UIntVectorClass> Toplevel::uintVectorClass() const { return builtinClasses()->get_Vector_uintClass(); }
REALLY_INLINE GCRef<URIErrorClass> Toplevel::uriErrorClass() const { return builtinClasses()->get_URIErrorClass(); }
REALLY_INLINE GCRef<VectorClass> Toplevel::vectorClass() const { return builtinClasses()->get_VectorClass(); }
REALLY_INLINE GCRef<VerifyErrorClass> Toplevel::verifyErrorClass() const { return builtinClasses()->get_VerifyErrorClass(); }
REALLY_INLINE GCRef<XMLClass> Toplevel::xmlClass() const { return builtinClasses()->get_XMLClass(); }
REALLY_INLINE GCRef<XMLListClass> Toplevel::xmlListClass() const { return builtinClasses()->get_XMLListClass(); }

REALLY_INLINE Atom Toplevel::callproperty(Atom base, const Multiname* name, int argc, Atom* atomv, VTable* vtable)
{
    AssertNotNull(base);
    Binding b = avmplus::getBinding(this, vtable, name);
    return avmplus::callprop_b(this, base, name, argc, atomv, vtable, b);
}

REALLY_INLINE VTable* Toplevel::toVTable(Atom atom)
{
    return avmplus::toVTable(this, atom);
}

REALLY_INLINE Atom Toplevel::op_call(Atom method, int argc, Atom* atomv)
{
    return avmplus::op_call(this, method, argc, atomv);
}

REALLY_INLINE Atom Toplevel::op_construct(Atom ctor, int argc, Atom* atomv)
{
    return avmplus::op_construct(this, ctor, argc, atomv);
}

REALLY_INLINE Binding Toplevel::getBinding(Traits* traits, const Multiname* ref) const
{
    return avmplus::getBinding(this, traits, ref);
}

REALLY_INLINE Atom Toplevel::constructprop(const Multiname *name, int argc, Atom* atomv, VTable* vtable)
{
    return avmplus::constructprop(this, name, argc, atomv, vtable);
}

REALLY_INLINE Atom Toplevel::op_applytype(Atom obj, int argc, Atom* atomv)
{
    return avmplus::op_applytype(this, obj, argc, atomv);
}

REALLY_INLINE QNameObject* Toplevel::ToAttributeName(const Stringp arg)
{
    return ToAttributeName(arg->atom());
}

REALLY_INLINE Atom Toplevel::coerce(Atom atom, Traits* expected) const
{
    return avmplus::coerce(this, atom, expected);
}

// static
REALLY_INLINE bool Toplevel::contains(const uint32_t *uriSet, uint32_t ch)
{
    return (ch<0x80) && (uriSet[ch>>5]&(1<<(ch&0x1f))) != 0;
}

REALLY_INLINE void Toplevel::throwReferenceError(int id, const Multiname& multiname, const Traits* traits) const
{
    throwReferenceError(id, &multiname, traits);
}

REALLY_INLINE void Toplevel::throwReferenceError(int id, const Multiname& multiname) const
{
    throwReferenceError(id, &multiname);
}

#ifndef DEBUGGER
REALLY_INLINE void Toplevel::throwVerifyError(int id, Stringp) const
{
    throwVerifyError(id);
}

REALLY_INLINE void Toplevel::throwVerifyError(int id, Stringp, Stringp) const
{
    throwVerifyError(id);
}
#endif // !DEBUGGER

REALLY_INLINE AbcEnv* Toplevel::abcEnv() const
{
    return _abcEnv;
}

REALLY_INLINE DomainEnv* Toplevel::domainEnv() const
{
    return _abcEnv->domainEnv();
}

REALLY_INLINE AvmCore* Toplevel::core() const
{
    return _abcEnv->pool()->core;
}

REALLY_INLINE MMgc::GC* Toplevel::gc() const
{
    return core()->GetGC();
}

REALLY_INLINE ScriptObject* Toplevel::global() const
{
    AvmAssert(_mainEntryPoint != NULL);
    AvmAssert(_mainEntryPoint->global != NULL);
    return _mainEntryPoint->global;
}

REALLY_INLINE Atom Toplevel::atom() const
{
    AvmAssert(_mainEntryPoint != NULL);
    AvmAssert(_mainEntryPoint->global != NULL);
    return _mainEntryPoint->global->atom();
}

REALLY_INLINE Atom Toplevel::add2(Atom val1, Atom val2)
{
    return avmplus::op_add(this->core(), val1, val2);
}

REALLY_INLINE void Toplevel::init_mainEntryPoint(ScriptEnv* main, builtinClassManifest* builtins)
{
    AvmAssert(_mainEntryPoint == NULL);
    _mainEntryPoint = main;
    _builtinClasses = builtins;
}

REALLY_INLINE ScopeChain* Toplevel::toplevel_scope()
{
    AvmAssert(_mainEntryPoint != NULL);
    return _mainEntryPoint->scope();
}

} // namespace avmplus
