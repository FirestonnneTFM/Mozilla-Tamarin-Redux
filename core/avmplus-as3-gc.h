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
 * Portions created by the Initial Developer are Copyright (C) 2010
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

/* machine generated file via utils/exactgc.as -- do not edit */

namespace avmplus
{
bool ArgumentErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ArgumentErrorClass
    m_slots_ArgumentErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc, 0);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
    return false;
}

bool ArgumentErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ArgumentErrorObject
    m_slots_ArgumentErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}

bool ArrayClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ArrayClass
    m_slots_ArrayClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool ArrayObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ArrayObject
    m_slots_ArrayObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    m_denseArray.gcTrace(gc);
    return false;
}

bool BooleanClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_BooleanClass
    m_slots_BooleanClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool ByteArrayClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ByteArrayClass
    m_slots_ByteArrayClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool ByteArrayObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ByteArrayObject
    m_slots_ByteArrayObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    m_byteArray.gcTrace(gc);
    return false;
}

bool ClassClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ClassClass
    m_slots_ClassClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool ClassClosure::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ClassClosure
    m_slots_ClassClosure.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    gc->TraceLocation(&m_prototype);
    return false;
}

bool DateClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_DateClass
    m_slots_DateClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool DateObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_DateObject
    m_slots_DateObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}

bool DefinitionErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_DefinitionErrorClass
    m_slots_DefinitionErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc, 0);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
    return false;
}

bool DefinitionErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_DefinitionErrorObject
    m_slots_DefinitionErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}

bool DoubleVectorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_DoubleVectorClass
    m_slots_DoubleVectorClass.gcTracePrivateProperties(gc);
#endif
    TypedVectorClass<DoubleVectorObject>::gcTrace(gc, 0);
    (void)(avmplus_TypedVectorClassXDoubleVectorObjectX_isExactInterlock != 0);
    return false;
}

bool DoubleVectorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_DoubleVectorObject
    m_slots_DoubleVectorObject.gcTracePrivateProperties(gc);
#endif
    TypedVectorObject< DataList<double> >::gcTrace(gc, 0);
    (void)(avmplus_TypedVectorObjectXDataListXdoubleXX_isExactInterlock != 0);
    return false;
}

bool ErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ErrorClass
    m_slots_ErrorClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool ErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ErrorObject
    m_slots_ErrorObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
#ifdef DEBUGGER
    gc->TraceLocation(&stackTrace);
#endif
    return false;
}

bool EvalErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_EvalErrorClass
    m_slots_EvalErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc, 0);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
    return false;
}

bool EvalErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_EvalErrorObject
    m_slots_EvalErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}

bool FunctionClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_FunctionClass
    m_slots_FunctionClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool FunctionObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_FunctionObject
    m_slots_FunctionObject.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    gc->TraceLocation(&_call);
    return false;
}

bool IntClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_IntClass
    m_slots_IntClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool IntVectorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_IntVectorClass
    m_slots_IntVectorClass.gcTracePrivateProperties(gc);
#endif
    TypedVectorClass<IntVectorObject>::gcTrace(gc, 0);
    (void)(avmplus_TypedVectorClassXIntVectorObjectX_isExactInterlock != 0);
    return false;
}

bool IntVectorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_IntVectorObject
    m_slots_IntVectorObject.gcTracePrivateProperties(gc);
#endif
    TypedVectorObject< DataList<int32_t> >::gcTrace(gc, 0);
    (void)(avmplus_TypedVectorObjectXDataListXint32_tXX_isExactInterlock != 0);
    return false;
}

bool MathClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_MathClass
    m_slots_MathClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool MethodClosure::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_MethodClosure
    m_slots_MethodClosure.gcTracePrivateProperties(gc);
#endif
    FunctionObject::gcTrace(gc, 0);
    (void)(avmplus_FunctionObject_isExactInterlock != 0);
    gc->TraceAtom(&_savedThis);
    return false;
}

bool MethodClosureClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_MethodClosureClass
    m_slots_MethodClosureClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool NamespaceClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_NamespaceClass
    m_slots_NamespaceClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool NumberClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_NumberClass
    m_slots_NumberClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool ObjectClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ObjectClass
    m_slots_ObjectClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool ObjectVectorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ObjectVectorClass
    m_slots_ObjectVectorClass.gcTracePrivateProperties(gc);
#endif
    TypedVectorClass<ObjectVectorObject>::gcTrace(gc, 0);
    (void)(avmplus_TypedVectorClassXObjectVectorObjectX_isExactInterlock != 0);
    return false;
}

bool ObjectVectorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ObjectVectorObject
    m_slots_ObjectVectorObject.gcTracePrivateProperties(gc);
#endif
    TypedVectorObject< AtomList >::gcTrace(gc, 0);
    (void)(avmplus_TypedVectorObjectXAtomListX_isExactInterlock != 0);
    return false;
}

bool QNameClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_QNameClass
    m_slots_QNameClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool QNameObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_QNameObject
    m_slots_QNameObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    m_mn.gcTrace(gc);
    return false;
}

bool RangeErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_RangeErrorClass
    m_slots_RangeErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc, 0);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
    return false;
}

bool RangeErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_RangeErrorObject
    m_slots_RangeErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}

bool ReferenceErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ReferenceErrorClass
    m_slots_ReferenceErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc, 0);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
    return false;
}

bool ReferenceErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ReferenceErrorObject
    m_slots_ReferenceErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}

bool RegExpClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_RegExpClass
    m_slots_RegExpClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool RegExpObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_RegExpObject
    m_slots_RegExpObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    gc->TraceLocation(&m_pcreInst);
    gc->TraceLocation(&m_source);
    return false;
}

bool SecurityErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SecurityErrorClass
    m_slots_SecurityErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc, 0);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
    return false;
}

bool SecurityErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SecurityErrorObject
    m_slots_SecurityErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}

bool StringClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_StringClass
    m_slots_StringClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool SyntaxErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SyntaxErrorClass
    m_slots_SyntaxErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc, 0);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
    return false;
}

bool SyntaxErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SyntaxErrorObject
    m_slots_SyntaxErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}

bool TypeErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_TypeErrorClass
    m_slots_TypeErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc, 0);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
    return false;
}

bool TypeErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_TypeErrorObject
    m_slots_TypeErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}

bool UIntClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_UIntClass
    m_slots_UIntClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool UIntVectorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_UIntVectorClass
    m_slots_UIntVectorClass.gcTracePrivateProperties(gc);
#endif
    TypedVectorClass<UIntVectorObject>::gcTrace(gc, 0);
    (void)(avmplus_TypedVectorClassXUIntVectorObjectX_isExactInterlock != 0);
    return false;
}

bool UIntVectorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_UIntVectorObject
    m_slots_UIntVectorObject.gcTracePrivateProperties(gc);
#endif
    TypedVectorObject< DataList<uint32_t> >::gcTrace(gc, 0);
    (void)(avmplus_TypedVectorObjectXDataListXuint32_tXX_isExactInterlock != 0);
    return false;
}

bool URIErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_URIErrorClass
    m_slots_URIErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc, 0);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
    return false;
}

bool URIErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_URIErrorObject
    m_slots_URIErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}

bool UninitializedErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_UninitializedErrorClass
    m_slots_UninitializedErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc, 0);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
    return false;
}

bool UninitializedErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_UninitializedErrorObject
    m_slots_UninitializedErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}

bool VectorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_VectorClass
    m_slots_VectorClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool VerifyErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_VerifyErrorClass
    m_slots_VerifyErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc, 0);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
    return false;
}

bool VerifyErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_VerifyErrorObject
    m_slots_VerifyErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}

bool XMLClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_XMLClass
    m_slots_XMLClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool XMLListClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_XMLListClass
    m_slots_XMLListClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool XMLListObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_XMLListObject
    m_slots_XMLListObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    m_children.gcTrace(gc);
    gc->TraceAtom(&m_targetObject);
    m_targetProperty.gcTrace(gc);
    return false;
}

bool XMLObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_XMLObject
    m_slots_XMLObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    gc->TraceLocation(&m_node);
    gc->TraceLocation(&publicNS);
    return false;
}

}
