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
void ArgumentErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ArgumentErrorClass
    m_slots_ArgumentErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
}

bool ArgumentErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ArgumentErrorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ArgumentErrorObject
    m_slots_ArgumentErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
}

bool ArgumentErrorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ArrayClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ArrayClass
    m_slots_ArrayClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool ArrayClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ArrayObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ArrayObject
    m_slots_ArrayObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    m_denseArray.gcTrace(gc);
}

bool ArrayObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void BooleanClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_BooleanClass
    m_slots_BooleanClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool BooleanClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ByteArrayClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ByteArrayClass
    m_slots_ByteArrayClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool ByteArrayClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ByteArrayObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ByteArrayObject
    m_slots_ByteArrayObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    m_byteArray.gcTrace(gc);
}

bool ByteArrayObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ClassClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ClassClass
    m_slots_ClassClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool ClassClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ClassClosure::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ClassClosure
    m_slots_ClassClosure.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    gc->TraceLocation(&m_prototype);
}

bool ClassClosure::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void DateClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_DateClass
    m_slots_DateClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool DateClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void DateObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_DateObject
    m_slots_DateObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
}

bool DateObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void DefinitionErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_DefinitionErrorClass
    m_slots_DefinitionErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
}

bool DefinitionErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void DefinitionErrorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_DefinitionErrorObject
    m_slots_DefinitionErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
}

bool DefinitionErrorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void DoubleVectorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_DoubleVectorClass
    m_slots_DoubleVectorClass.gcTracePrivateProperties(gc);
#endif
    TypedVectorClass<DoubleVectorObject>::gcTrace(gc);
    (void)(avmplus_TypedVectorClassXDoubleVectorObjectX_isExactInterlock != 0);
}

bool DoubleVectorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void DoubleVectorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_DoubleVectorObject
    m_slots_DoubleVectorObject.gcTracePrivateProperties(gc);
#endif
    TypedVectorObject< DataList<double> >::gcTrace(gc);
    (void)(avmplus_TypedVectorObjectXDataListXdoubleXX_isExactInterlock != 0);
}

bool DoubleVectorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ErrorClass
    m_slots_ErrorClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool ErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ErrorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ErrorObject
    m_slots_ErrorObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
#ifdef DEBUGGER
    gc->TraceLocation(&stackTrace);
#endif
}

bool ErrorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void EvalErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_EvalErrorClass
    m_slots_EvalErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
}

bool EvalErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void EvalErrorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_EvalErrorObject
    m_slots_EvalErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
}

bool EvalErrorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void FunctionClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_FunctionClass
    m_slots_FunctionClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool FunctionClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void FunctionObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_FunctionObject
    m_slots_FunctionObject.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    gc->TraceLocation(&_call);
}

bool FunctionObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void IntClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_IntClass
    m_slots_IntClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool IntClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void IntVectorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_IntVectorClass
    m_slots_IntVectorClass.gcTracePrivateProperties(gc);
#endif
    TypedVectorClass<IntVectorObject>::gcTrace(gc);
    (void)(avmplus_TypedVectorClassXIntVectorObjectX_isExactInterlock != 0);
}

bool IntVectorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void IntVectorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_IntVectorObject
    m_slots_IntVectorObject.gcTracePrivateProperties(gc);
#endif
    TypedVectorObject< DataList<int32_t> >::gcTrace(gc);
    (void)(avmplus_TypedVectorObjectXDataListXint32_tXX_isExactInterlock != 0);
}

bool IntVectorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void MathClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_MathClass
    m_slots_MathClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool MathClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void MethodClosure::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_MethodClosure
    m_slots_MethodClosure.gcTracePrivateProperties(gc);
#endif
    FunctionObject::gcTrace(gc);
    (void)(avmplus_FunctionObject_isExactInterlock != 0);
    gc->TraceAtom(&_savedThis);
}

bool MethodClosure::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void MethodClosureClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_MethodClosureClass
    m_slots_MethodClosureClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool MethodClosureClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void NamespaceClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_NamespaceClass
    m_slots_NamespaceClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool NamespaceClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void NumberClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_NumberClass
    m_slots_NumberClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool NumberClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ObjectClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ObjectClass
    m_slots_ObjectClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool ObjectClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ObjectVectorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ObjectVectorClass
    m_slots_ObjectVectorClass.gcTracePrivateProperties(gc);
#endif
    TypedVectorClass<ObjectVectorObject>::gcTrace(gc);
    (void)(avmplus_TypedVectorClassXObjectVectorObjectX_isExactInterlock != 0);
}

bool ObjectVectorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ObjectVectorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ObjectVectorObject
    m_slots_ObjectVectorObject.gcTracePrivateProperties(gc);
#endif
    TypedVectorObject< AtomList >::gcTrace(gc);
    (void)(avmplus_TypedVectorObjectXAtomListX_isExactInterlock != 0);
}

bool ObjectVectorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void QNameClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_QNameClass
    m_slots_QNameClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool QNameClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void QNameObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_QNameObject
    m_slots_QNameObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    m_mn.gcTrace(gc);
}

bool QNameObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void RangeErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_RangeErrorClass
    m_slots_RangeErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
}

bool RangeErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void RangeErrorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_RangeErrorObject
    m_slots_RangeErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
}

bool RangeErrorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ReferenceErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ReferenceErrorClass
    m_slots_ReferenceErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
}

bool ReferenceErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ReferenceErrorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_ReferenceErrorObject
    m_slots_ReferenceErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
}

bool ReferenceErrorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void RegExpClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_RegExpClass
    m_slots_RegExpClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool RegExpClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void RegExpObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_RegExpObject
    m_slots_RegExpObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    gc->TraceLocation(&m_pcreInst);
    gc->TraceLocation(&m_source);
}

bool RegExpObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void SecurityErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_SecurityErrorClass
    m_slots_SecurityErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
}

bool SecurityErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void SecurityErrorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_SecurityErrorObject
    m_slots_SecurityErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
}

bool SecurityErrorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void StringClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_StringClass
    m_slots_StringClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool StringClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void SyntaxErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_SyntaxErrorClass
    m_slots_SyntaxErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
}

bool SyntaxErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void SyntaxErrorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_SyntaxErrorObject
    m_slots_SyntaxErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
}

bool SyntaxErrorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void TypeErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_TypeErrorClass
    m_slots_TypeErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
}

bool TypeErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void TypeErrorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_TypeErrorObject
    m_slots_TypeErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
}

bool TypeErrorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void UIntClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_UIntClass
    m_slots_UIntClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool UIntClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void UIntVectorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_UIntVectorClass
    m_slots_UIntVectorClass.gcTracePrivateProperties(gc);
#endif
    TypedVectorClass<UIntVectorObject>::gcTrace(gc);
    (void)(avmplus_TypedVectorClassXUIntVectorObjectX_isExactInterlock != 0);
}

bool UIntVectorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void UIntVectorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_UIntVectorObject
    m_slots_UIntVectorObject.gcTracePrivateProperties(gc);
#endif
    TypedVectorObject< DataList<uint32_t> >::gcTrace(gc);
    (void)(avmplus_TypedVectorObjectXDataListXuint32_tXX_isExactInterlock != 0);
}

bool UIntVectorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void URIErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_URIErrorClass
    m_slots_URIErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
}

bool URIErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void URIErrorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_URIErrorObject
    m_slots_URIErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
}

bool URIErrorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void UninitializedErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_UninitializedErrorClass
    m_slots_UninitializedErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
}

bool UninitializedErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void UninitializedErrorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_UninitializedErrorObject
    m_slots_UninitializedErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
}

bool UninitializedErrorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void VectorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_VectorClass
    m_slots_VectorClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool VectorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void VerifyErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_VerifyErrorClass
    m_slots_VerifyErrorClass.gcTracePrivateProperties(gc);
#endif
    NativeErrorClass::gcTrace(gc);
    (void)(avmplus_NativeErrorClass_isExactInterlock != 0);
}

bool VerifyErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void VerifyErrorObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_VerifyErrorObject
    m_slots_VerifyErrorObject.gcTracePrivateProperties(gc);
#endif
    ErrorObject::gcTrace(gc);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
}

bool VerifyErrorObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void XMLClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_XMLClass
    m_slots_XMLClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool XMLClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void XMLListClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_XMLListClass
    m_slots_XMLListClass.gcTracePrivateProperties(gc);
#endif
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool XMLListClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void XMLListObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_XMLListObject
    m_slots_XMLListObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    m_children.gcTrace(gc);
    gc->TraceAtom(&m_targetObject);
    m_targetProperty.gcTrace(gc);
}

bool XMLListObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void XMLObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifndef GC_TRIVIAL_TRACER_XMLObject
    m_slots_XMLObject.gcTracePrivateProperties(gc);
#endif
    ScriptObject::gcTrace(gc);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    gc->TraceLocation(&m_node);
    gc->TraceLocation(&publicNS);
}

bool XMLObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

}
