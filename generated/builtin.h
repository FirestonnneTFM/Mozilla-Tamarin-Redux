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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2008
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

/* machine generated file -- do not edit */

#ifndef _H_nativegen_header_builtin
#define _H_nativegen_header_builtin

namespace avmplus {
    class ArgumentErrorClass; // ArgumentError$
    class ArgumentErrorObject; // ArgumentError
    class ArrayClass; // Array$
    class ArrayObject; // Array
    class BooleanClass; // Boolean$
    class ByteArrayClass; // flash.utils::ByteArray$
    class ByteArrayObject; // flash.utils::ByteArray
    class ClassClass; // Class$
    class ClassClosure; // Class
    class CompressionAlgorithmClass; // flash.utils::CompressionAlgorithm$
    class CompressionAlgorithmObject; // flash.utils::CompressionAlgorithm
    class DateClass; // Date$
    class DateObject; // Date
    class DefinitionErrorClass; // DefinitionError$
    class DefinitionErrorObject; // DefinitionError
    class DoubleVectorClass; // __AS3__.vec::Vector$double$
    class DoubleVectorObject; // __AS3__.vec::Vector$double
    class EOFErrorClass; // flash.errors::EOFError$
    class EOFErrorObject; // flash.errors::EOFError
    class ErrorClass; // Error$
    class ErrorObject; // Error
    class EvalErrorClass; // EvalError$
    class EvalErrorObject; // EvalError
    class Float4Class; // float4$
    class Float4VectorClass; // __AS3__.vec::Vector$float4$
    class Float4VectorObject; // __AS3__.vec::Vector$float4
    class FloatClass; // float$
    class FloatVectorClass; // __AS3__.vec::Vector$float$
    class FloatVectorObject; // __AS3__.vec::Vector$float
    class FunctionClass; // Function$
    class FunctionObject; // Function
    class IDataInputClass; // flash.utils::IDataInput$
    class IDataInputInterface; // flash.utils::IDataInput
    class IDataOutputClass; // flash.utils::IDataOutput$
    class IDataOutputInterface; // flash.utils::IDataOutput
    class IOErrorClass; // flash.errors::IOError$
    class IOErrorObject; // flash.errors::IOError
    class IllegalOperationErrorClass; // flash.errors::IllegalOperationError$
    class IllegalOperationErrorObject; // flash.errors::IllegalOperationError
    class IntClass; // int$
    class IntVectorClass; // __AS3__.vec::Vector$int$
    class IntVectorObject; // __AS3__.vec::Vector$int
    class JSONClass; // JSON$
    class JSONObject; // JSON
    class MathClass; // Math$
    class MemoryErrorClass; // flash.errors::MemoryError$
    class MemoryErrorObject; // flash.errors::MemoryError
    class MethodClosure; // private::MethodClosure
    class MethodClosureClass; // private::MethodClosure$
    class Namespace; // Namespace
    class NamespaceClass; // Namespace$
    class NumberClass; // Number$
    class ObjectClass; // Object$
    class ObjectVectorClass; // __AS3__.vec::Vector$object$
    class ObjectVectorObject; // __AS3__.vec::Vector
    class ObjectVectorObject; // __AS3__.vec::Vector$object
    class ProxyClass; // flash.utils::Proxy$
    class ProxyObject; // flash.utils::Proxy
    class QNameClass; // QName$
    class QNameObject; // QName
    class RangeErrorClass; // RangeError$
    class RangeErrorObject; // RangeError
    class ReferenceErrorClass; // ReferenceError$
    class ReferenceErrorObject; // ReferenceError
    class RegExpClass; // RegExp$
    class RegExpObject; // RegExp
    class SecurityErrorClass; // SecurityError$
    class SecurityErrorObject; // SecurityError
    class String; // String
    class StringClass; // String$
    class SyntaxErrorClass; // SyntaxError$
    class SyntaxErrorObject; // SyntaxError
    class TypeErrorClass; // TypeError$
    class TypeErrorObject; // TypeError
    class UIntClass; // uint$
    class UIntVectorClass; // __AS3__.vec::Vector$uint$
    class UIntVectorObject; // __AS3__.vec::Vector$uint
    class URIErrorClass; // URIError$
    class URIErrorObject; // URIError
    class UninitializedErrorClass; // UninitializedError$
    class UninitializedErrorObject; // UninitializedError
    class VectorClass; // __AS3__.vec::Vector$
    class VerifyErrorClass; // VerifyError$
    class VerifyErrorObject; // VerifyError
    class WalkerClass; // Walker$
    class WalkerObject; // Walker
    class XMLClass; // XML$
    class XMLListClass; // XMLList$
    class XMLListObject; // XMLList
    class XMLObject; // XML
}

namespace avmplus { namespace NativeID {

extern const uint32_t builtin_abc_class_count;
extern const uint32_t builtin_abc_script_count;
extern const uint32_t builtin_abc_method_count;
extern const uint32_t builtin_abc_length;
extern const uint8_t builtin_abc_data[];
extern const char* const builtin_versioned_uris[];
AVMTHUNK_DECLARE_NATIVE_INITIALIZER(builtin)

/* classes */
const uint32_t abcclass_Object = 0;
const uint32_t abcclass_Class = 1;
const uint32_t abcclass_Function = 2;
const uint32_t abcclass_Namespace = 3;
const uint32_t abcclass_Boolean = 4;
const uint32_t abcclass_Number = 5;
const uint32_t abcclass_int = 6;
const uint32_t abcclass_uint = 7;
const uint32_t abcclass_String = 8;
const uint32_t abcclass_Array = 9;
const uint32_t abcclass___AS3___vec_Vector = 10;
const uint32_t abcclass___AS3___vec_Vector_object = 11;
const uint32_t abcclass___AS3___vec_Vector_int = 12;
const uint32_t abcclass___AS3___vec_Vector_uint = 13;
const uint32_t abcclass___AS3___vec_Vector_double = 14;
const uint32_t abcclass___AS3___vec_Vector_float = 15;
const uint32_t abcclass___AS3___vec_Vector_float4 = 16;
const uint32_t abcclass_private_MethodClosure = 17;
const uint32_t abcclass_Math = 18;
const uint32_t abcclass_Error = 19;
const uint32_t abcclass_DefinitionError = 20;
const uint32_t abcclass_EvalError = 21;
const uint32_t abcclass_RangeError = 22;
const uint32_t abcclass_ReferenceError = 23;
const uint32_t abcclass_SecurityError = 24;
const uint32_t abcclass_SyntaxError = 25;
const uint32_t abcclass_TypeError = 26;
const uint32_t abcclass_URIError = 27;
const uint32_t abcclass_VerifyError = 28;
const uint32_t abcclass_UninitializedError = 29;
const uint32_t abcclass_ArgumentError = 30;
const uint32_t abcclass_flash_errors_IOError = 31;
const uint32_t abcclass_flash_errors_MemoryError = 32;
const uint32_t abcclass_flash_errors_IllegalOperationError = 33;
const uint32_t abcclass_flash_errors_EOFError = 34;
const uint32_t abcclass_Date = 35;
const uint32_t abcclass_RegExp = 36;
const uint32_t abcclass_JSON = 37;
const uint32_t abcclass_Walker = 38;
const uint32_t abcclass_XML = 39;
const uint32_t abcclass_XMLList = 40;
const uint32_t abcclass_QName = 41;
const uint32_t abcclass_flash_utils_IDataInput = 42;
const uint32_t abcclass_flash_utils_IDataOutput = 43;
const uint32_t abcclass_flash_utils_Proxy = 44;
const uint32_t abcclass_float = 45;
const uint32_t abcclass_float4 = 46;
const uint32_t abcclass_flash_utils_CompressionAlgorithm = 47;
const uint32_t abcclass_flash_utils_ByteArray = 48;

/* methods */
const uint32_t native_script_function_avmplus_getQualifiedSuperclassName = 0; // native
const uint32_t native_script_function_avmplus_getQualifiedClassName = 1; // native
const uint32_t native_script_function_avmplus_describeTypeJSON = 7; // native
const uint32_t native_script_function_isXMLName = 8; // native
const uint32_t native_script_function_unescape = 9; // native
const uint32_t native_script_function_escape = 10; // native
const uint32_t native_script_function_parseFloat = 11; // native
const uint32_t native_script_function_parseInt = 12; // native
const uint32_t native_script_function_isFinite = 13; // native
const uint32_t native_script_function_isNaN = 14; // native
const uint32_t native_script_function_encodeURIComponent = 15; // native
const uint32_t native_script_function_encodeURI = 16; // native
const uint32_t native_script_function_decodeURIComponent = 17; // native
const uint32_t native_script_function_decodeURI = 18; // native
const uint32_t native_script_function_bugzilla = 19; // native
const uint32_t Object_private__hasOwnProperty = 21; // native
const uint32_t Object_private__propertyIsEnumerable = 22; // native
const uint32_t Object_protected__setPropertyIsEnumerable = 23; // native
const uint32_t Object_private__isPrototypeOf = 24; // native
const uint32_t Object_private__toString = 25; // native
const uint32_t Object_protected__dontEnumPrototype = 26; // abc
const uint32_t Object_init = 27; // abc
const uint32_t Object__init = 34; // abc
const uint32_t Object_AS3_isPrototypeOf = 35; // abc
const uint32_t Object_AS3_hasOwnProperty = 36; // abc
const uint32_t Object_AS3_propertyIsEnumerable = 37; // abc
const uint32_t Class_prototype_get = 40; // native
const uint32_t Function_createEmptyFunction = 47; // abc
const uint32_t Function_prototype_get = 48; // native
const uint32_t Function_prototype_set = 49; // native
const uint32_t Function_length_get = 50; // native
const uint32_t Function_AS3_call = 51; // native
const uint32_t Function_AS3_apply = 52; // native
const uint32_t Namespace_prefix_get = 57; // native
const uint32_t Namespace_uri_get = 58; // native
const uint32_t Namespace_AS3_valueOf = 59; // abc
const uint32_t Namespace_AS3_toString = 60; // abc
const uint32_t Boolean_AS3_toString = 65; // abc
const uint32_t Boolean_AS3_valueOf = 66; // abc
const uint32_t Number_private__numberToString = 74; // native
const uint32_t Number_private__convert = 75; // native
const uint32_t Number_private__minValue = 76; // native
const uint32_t Number_AS3_toString = 77; // abc
const uint32_t Number_AS3_valueOf = 78; // abc
const uint32_t Number_AS3_toExponential = 79; // abc
const uint32_t Number_AS3_toPrecision = 80; // abc
const uint32_t Number_AS3_toFixed = 81; // abc
const uint32_t int_AS3_toString = 89; // abc
const uint32_t int_AS3_valueOf = 90; // abc
const uint32_t int_AS3_toExponential = 91; // abc
const uint32_t int_AS3_toPrecision = 92; // abc
const uint32_t int_AS3_toFixed = 93; // abc
const uint32_t uint_AS3_toString = 101; // abc
const uint32_t uint_AS3_valueOf = 102; // abc
const uint32_t uint_AS3_toExponential = 103; // abc
const uint32_t uint_AS3_toPrecision = 104; // abc
const uint32_t uint_AS3_toFixed = 105; // abc
const uint32_t String_AS3_fromCharCode = 126; // native
const uint32_t String_private__match = 127; // native
const uint32_t String_private__replace = 128; // native
const uint32_t String_private__search = 129; // native
const uint32_t String_private__split = 130; // native
const uint32_t String_length_get = 131; // native
const uint32_t String_private__indexOf = 132; // native
const uint32_t String_AS3_indexOf = 133; // native
const uint32_t String_private__lastIndexOf = 134; // native
const uint32_t String_AS3_lastIndexOf = 135; // native
const uint32_t String_AS3_charAt = 136; // native
const uint32_t String_AS3_charCodeAt = 137; // native
const uint32_t String_AS3_concat = 138; // abc
const uint32_t String_AS3_localeCompare = 139; // native
const uint32_t String_AS3_match = 140; // abc
const uint32_t String_AS3_replace = 141; // abc
const uint32_t String_AS3_search = 142; // abc
const uint32_t String_private__slice = 143; // native
const uint32_t String_AS3_slice = 144; // native
const uint32_t String_AS3_split = 145; // abc
const uint32_t String_private__substring = 146; // native
const uint32_t String_AS3_substring = 147; // native
const uint32_t String_private__substr = 148; // native
const uint32_t String_AS3_substr = 149; // native
const uint32_t String_AS3_toLowerCase = 150; // native
const uint32_t String_AS3_toLocaleLowerCase = 151; // abc
const uint32_t String_AS3_toUpperCase = 152; // native
const uint32_t String_AS3_toLocaleUpperCase = 153; // abc
const uint32_t String_AS3_toString = 154; // abc
const uint32_t String_AS3_valueOf = 155; // abc
const uint32_t Array_private__join = 178; // abc
const uint32_t Array_private__pop = 179; // native
const uint32_t Array_private__reverse = 180; // native
const uint32_t Array_private__concat = 181; // native
const uint32_t Array_private__shift = 182; // native
const uint32_t Array_private__slice = 183; // native
const uint32_t Array_private__unshift = 184; // native
const uint32_t Array_private__splice = 185; // native
const uint32_t Array_private__sort = 186; // native
const uint32_t Array_private__sortOn = 187; // native
const uint32_t Array_private__indexOf = 188; // native
const uint32_t Array_private__lastIndexOf = 189; // native
const uint32_t Array_private__every = 190; // native
const uint32_t Array_private__filter = 191; // native
const uint32_t Array_private__forEach = 192; // native
const uint32_t Array_private__map = 193; // native
const uint32_t Array_private__some = 194; // native
const uint32_t Array_length_get = 195; // native
const uint32_t Array_length_set = 196; // native
const uint32_t Array_private_set_length = 197; // abc
const uint32_t Array_AS3_join = 199; // abc
const uint32_t Array_AS3_pop = 200; // native
const uint32_t Array_AS3_push = 201; // native
const uint32_t Array_AS3_reverse = 202; // abc
const uint32_t Array_AS3_concat = 203; // abc
const uint32_t Array_AS3_shift = 204; // abc
const uint32_t Array_AS3_slice = 205; // abc
const uint32_t Array_AS3_unshift = 206; // native
const uint32_t Array_AS3_splice = 207; // abc
const uint32_t Array_AS3_sort = 208; // abc
const uint32_t Array_AS3_sortOn = 209; // abc
const uint32_t Array_AS3_indexOf = 210; // abc
const uint32_t Array_AS3_lastIndexOf = 211; // abc
const uint32_t Array_AS3_every = 212; // abc
const uint32_t Array_AS3_filter = 213; // abc
const uint32_t Array_AS3_forEach = 214; // abc
const uint32_t Array_AS3_map = 215; // abc
const uint32_t Array_AS3_some = 216; // abc
const uint32_t __AS3___vec_Vector_object_private_castToThisType = 239; // abc
const uint32_t __AS3___vec_Vector_object_private__every = 240; // native
const uint32_t __AS3___vec_Vector_object_private__forEach = 241; // native
const uint32_t __AS3___vec_Vector_object_private__some = 242; // native
const uint32_t __AS3___vec_Vector_object_private__sort = 243; // native
const uint32_t __AS3___vec_Vector_object_private_newThisType = 245; // native
const uint32_t __AS3___vec_Vector_object_length_get = 246; // native
const uint32_t __AS3___vec_Vector_object_length_set = 247; // native
const uint32_t __AS3___vec_Vector_object_fixed_set = 248; // native
const uint32_t __AS3___vec_Vector_object_fixed_get = 249; // native
const uint32_t __AS3___vec_Vector_object_AS3_toString = 250; // abc
const uint32_t __AS3___vec_Vector_object_AS3_toLocaleString = 251; // abc
const uint32_t __AS3___vec_Vector_object_AS3_join = 252; // abc
const uint32_t __AS3___vec_Vector_object_private__concat = 253; // abc
const uint32_t __AS3___vec_Vector_object_AS3_every = 254; // abc
const uint32_t __AS3___vec_Vector_object_AS3_forEach = 255; // abc
const uint32_t __AS3___vec_Vector_object_AS3_map = 256; // abc
const uint32_t __AS3___vec_Vector_object_AS3_push = 257; // native
const uint32_t __AS3___vec_Vector_object_private__reverse = 258; // native
const uint32_t __AS3___vec_Vector_object_AS3_some = 259; // abc
const uint32_t __AS3___vec_Vector_object_private__slice = 260; // abc
const uint32_t __AS3___vec_Vector_object_private__splice = 261; // abc
const uint32_t __AS3___vec_Vector_object_private__spliceHelper = 262; // native
const uint32_t __AS3___vec_Vector_object_AS3_unshift = 263; // native
const uint32_t __AS3___vec_Vector_object_private__filter = 264; // native
const uint32_t __AS3___vec_Vector_object_private__map = 265; // native
const uint32_t __AS3___vec_Vector_object_private_clamp = 266; // abc
const uint32_t __AS3___vec_Vector_object_AS3_concat = 267; // abc
const uint32_t __AS3___vec_Vector_object_AS3_filter = 268; // abc
const uint32_t __AS3___vec_Vector_object_AS3_pop = 269; // native
const uint32_t __AS3___vec_Vector_object_AS3_reverse = 270; // abc
const uint32_t __AS3___vec_Vector_object_AS3_shift = 271; // native
const uint32_t __AS3___vec_Vector_object_AS3_slice = 272; // abc
const uint32_t __AS3___vec_Vector_object_AS3_sort = 273; // abc
const uint32_t __AS3___vec_Vector_object_AS3_splice = 274; // abc
const uint32_t __AS3___vec_Vector_object_AS3_indexOf = 275; // abc
const uint32_t __AS3___vec_Vector_object_AS3_lastIndexOf = 276; // abc
const uint32_t __AS3___vec_Vector_int_private_castToThisType = 297; // abc
const uint32_t __AS3___vec_Vector_int_private__every = 298; // native
const uint32_t __AS3___vec_Vector_int_private__forEach = 299; // native
const uint32_t __AS3___vec_Vector_int_private__some = 300; // native
const uint32_t __AS3___vec_Vector_int_private__sort = 301; // native
const uint32_t __AS3___vec_Vector_int_private_newThisType = 303; // native
const uint32_t __AS3___vec_Vector_int_length_get = 304; // native
const uint32_t __AS3___vec_Vector_int_length_set = 305; // native
const uint32_t __AS3___vec_Vector_int_fixed_set = 306; // native
const uint32_t __AS3___vec_Vector_int_fixed_get = 307; // native
const uint32_t __AS3___vec_Vector_int_AS3_toString = 308; // abc
const uint32_t __AS3___vec_Vector_int_AS3_toLocaleString = 309; // abc
const uint32_t __AS3___vec_Vector_int_AS3_join = 310; // abc
const uint32_t __AS3___vec_Vector_int_private__concat = 311; // abc
const uint32_t __AS3___vec_Vector_int_AS3_every = 312; // abc
const uint32_t __AS3___vec_Vector_int_AS3_forEach = 313; // abc
const uint32_t __AS3___vec_Vector_int_AS3_map = 314; // abc
const uint32_t __AS3___vec_Vector_int_AS3_push = 315; // native
const uint32_t __AS3___vec_Vector_int_private__reverse = 316; // native
const uint32_t __AS3___vec_Vector_int_AS3_some = 317; // abc
const uint32_t __AS3___vec_Vector_int_private__slice = 318; // abc
const uint32_t __AS3___vec_Vector_int_private__splice = 319; // abc
const uint32_t __AS3___vec_Vector_int_private__spliceHelper = 320; // native
const uint32_t __AS3___vec_Vector_int_AS3_unshift = 321; // native
const uint32_t __AS3___vec_Vector_int_private__filter = 322; // native
const uint32_t __AS3___vec_Vector_int_private__map = 323; // native
const uint32_t __AS3___vec_Vector_int_private_clamp = 324; // abc
const uint32_t __AS3___vec_Vector_int_AS3_concat = 325; // abc
const uint32_t __AS3___vec_Vector_int_AS3_filter = 326; // abc
const uint32_t __AS3___vec_Vector_int_AS3_pop = 327; // native
const uint32_t __AS3___vec_Vector_int_AS3_reverse = 328; // abc
const uint32_t __AS3___vec_Vector_int_AS3_shift = 329; // native
const uint32_t __AS3___vec_Vector_int_AS3_slice = 330; // abc
const uint32_t __AS3___vec_Vector_int_AS3_sort = 331; // abc
const uint32_t __AS3___vec_Vector_int_AS3_splice = 332; // abc
const uint32_t __AS3___vec_Vector_int_AS3_indexOf = 333; // abc
const uint32_t __AS3___vec_Vector_int_AS3_lastIndexOf = 334; // abc
const uint32_t __AS3___vec_Vector_uint_private_castToThisType = 355; // abc
const uint32_t __AS3___vec_Vector_uint_private__every = 356; // native
const uint32_t __AS3___vec_Vector_uint_private__forEach = 357; // native
const uint32_t __AS3___vec_Vector_uint_private__some = 358; // native
const uint32_t __AS3___vec_Vector_uint_private__sort = 359; // native
const uint32_t __AS3___vec_Vector_uint_private_newThisType = 361; // native
const uint32_t __AS3___vec_Vector_uint_length_get = 362; // native
const uint32_t __AS3___vec_Vector_uint_length_set = 363; // native
const uint32_t __AS3___vec_Vector_uint_fixed_set = 364; // native
const uint32_t __AS3___vec_Vector_uint_fixed_get = 365; // native
const uint32_t __AS3___vec_Vector_uint_AS3_toString = 366; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_toLocaleString = 367; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_join = 368; // abc
const uint32_t __AS3___vec_Vector_uint_private__concat = 369; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_every = 370; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_forEach = 371; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_map = 372; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_push = 373; // native
const uint32_t __AS3___vec_Vector_uint_private__reverse = 374; // native
const uint32_t __AS3___vec_Vector_uint_AS3_some = 375; // abc
const uint32_t __AS3___vec_Vector_uint_private__slice = 376; // abc
const uint32_t __AS3___vec_Vector_uint_private__splice = 377; // abc
const uint32_t __AS3___vec_Vector_uint_private__spliceHelper = 378; // native
const uint32_t __AS3___vec_Vector_uint_AS3_unshift = 379; // native
const uint32_t __AS3___vec_Vector_uint_private__filter = 380; // native
const uint32_t __AS3___vec_Vector_uint_private__map = 381; // native
const uint32_t __AS3___vec_Vector_uint_private_clamp = 382; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_concat = 383; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_filter = 384; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_pop = 385; // native
const uint32_t __AS3___vec_Vector_uint_AS3_reverse = 386; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_shift = 387; // native
const uint32_t __AS3___vec_Vector_uint_AS3_slice = 388; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_sort = 389; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_splice = 390; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_indexOf = 391; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_lastIndexOf = 392; // abc
const uint32_t __AS3___vec_Vector_double_private_castToThisType = 413; // abc
const uint32_t __AS3___vec_Vector_double_private__every = 414; // native
const uint32_t __AS3___vec_Vector_double_private__forEach = 415; // native
const uint32_t __AS3___vec_Vector_double_private__some = 416; // native
const uint32_t __AS3___vec_Vector_double_private__sort = 417; // native
const uint32_t __AS3___vec_Vector_double_private_newThisType = 419; // native
const uint32_t __AS3___vec_Vector_double_length_get = 420; // native
const uint32_t __AS3___vec_Vector_double_length_set = 421; // native
const uint32_t __AS3___vec_Vector_double_fixed_set = 422; // native
const uint32_t __AS3___vec_Vector_double_fixed_get = 423; // native
const uint32_t __AS3___vec_Vector_double_AS3_toString = 424; // abc
const uint32_t __AS3___vec_Vector_double_AS3_toLocaleString = 425; // abc
const uint32_t __AS3___vec_Vector_double_AS3_join = 426; // abc
const uint32_t __AS3___vec_Vector_double_private__concat = 427; // abc
const uint32_t __AS3___vec_Vector_double_AS3_every = 428; // abc
const uint32_t __AS3___vec_Vector_double_AS3_forEach = 429; // abc
const uint32_t __AS3___vec_Vector_double_AS3_map = 430; // abc
const uint32_t __AS3___vec_Vector_double_AS3_push = 431; // native
const uint32_t __AS3___vec_Vector_double_private__reverse = 432; // native
const uint32_t __AS3___vec_Vector_double_AS3_some = 433; // abc
const uint32_t __AS3___vec_Vector_double_private__slice = 434; // abc
const uint32_t __AS3___vec_Vector_double_private__splice = 435; // abc
const uint32_t __AS3___vec_Vector_double_private__spliceHelper = 436; // native
const uint32_t __AS3___vec_Vector_double_AS3_unshift = 437; // native
const uint32_t __AS3___vec_Vector_double_private__filter = 438; // native
const uint32_t __AS3___vec_Vector_double_private__map = 439; // native
const uint32_t __AS3___vec_Vector_double_private_clamp = 440; // abc
const uint32_t __AS3___vec_Vector_double_AS3_concat = 441; // abc
const uint32_t __AS3___vec_Vector_double_AS3_filter = 442; // abc
const uint32_t __AS3___vec_Vector_double_AS3_pop = 443; // native
const uint32_t __AS3___vec_Vector_double_AS3_reverse = 444; // abc
const uint32_t __AS3___vec_Vector_double_AS3_shift = 445; // native
const uint32_t __AS3___vec_Vector_double_AS3_slice = 446; // abc
const uint32_t __AS3___vec_Vector_double_AS3_sort = 447; // abc
const uint32_t __AS3___vec_Vector_double_AS3_splice = 448; // abc
const uint32_t __AS3___vec_Vector_double_AS3_indexOf = 449; // abc
const uint32_t __AS3___vec_Vector_double_AS3_lastIndexOf = 450; // abc
const uint32_t __AS3___vec_Vector_float_private_castToThisType = 471; // abc
const uint32_t __AS3___vec_Vector_float_private__every = 472; // native
const uint32_t __AS3___vec_Vector_float_private__forEach = 473; // native
const uint32_t __AS3___vec_Vector_float_private__some = 474; // native
const uint32_t __AS3___vec_Vector_float_private__sort = 475; // native
const uint32_t __AS3___vec_Vector_float_private_newThisType = 477; // native
const uint32_t __AS3___vec_Vector_float_length_get = 478; // native
const uint32_t __AS3___vec_Vector_float_length_set = 479; // native
const uint32_t __AS3___vec_Vector_float_fixed_set = 480; // native
const uint32_t __AS3___vec_Vector_float_fixed_get = 481; // native
const uint32_t __AS3___vec_Vector_float_AS3_toString = 482; // abc
const uint32_t __AS3___vec_Vector_float_AS3_toLocaleString = 483; // abc
const uint32_t __AS3___vec_Vector_float_AS3_join = 484; // abc
const uint32_t __AS3___vec_Vector_float_private__concat = 485; // abc
const uint32_t __AS3___vec_Vector_float_AS3_every = 486; // abc
const uint32_t __AS3___vec_Vector_float_AS3_forEach = 487; // abc
const uint32_t __AS3___vec_Vector_float_AS3_map = 488; // abc
const uint32_t __AS3___vec_Vector_float_AS3_push = 489; // native
const uint32_t __AS3___vec_Vector_float_private__reverse = 490; // native
const uint32_t __AS3___vec_Vector_float_AS3_some = 491; // abc
const uint32_t __AS3___vec_Vector_float_private__slice = 492; // abc
const uint32_t __AS3___vec_Vector_float_private__splice = 493; // abc
const uint32_t __AS3___vec_Vector_float_private__spliceHelper = 494; // native
const uint32_t __AS3___vec_Vector_float_AS3_unshift = 495; // native
const uint32_t __AS3___vec_Vector_float_private__filter = 496; // native
const uint32_t __AS3___vec_Vector_float_private__map = 497; // native
const uint32_t __AS3___vec_Vector_float_private_clamp = 498; // abc
const uint32_t __AS3___vec_Vector_float_AS3_concat = 499; // abc
const uint32_t __AS3___vec_Vector_float_AS3_filter = 500; // abc
const uint32_t __AS3___vec_Vector_float_AS3_pop = 501; // native
const uint32_t __AS3___vec_Vector_float_AS3_reverse = 502; // abc
const uint32_t __AS3___vec_Vector_float_AS3_shift = 503; // native
const uint32_t __AS3___vec_Vector_float_AS3_slice = 504; // abc
const uint32_t __AS3___vec_Vector_float_AS3_sort = 505; // abc
const uint32_t __AS3___vec_Vector_float_AS3_splice = 506; // abc
const uint32_t __AS3___vec_Vector_float_AS3_indexOf = 507; // abc
const uint32_t __AS3___vec_Vector_float_AS3_lastIndexOf = 508; // abc
const uint32_t __AS3___vec_Vector_float4_private_castToThisType = 529; // abc
const uint32_t __AS3___vec_Vector_float4_private__every = 530; // native
const uint32_t __AS3___vec_Vector_float4_private__forEach = 531; // native
const uint32_t __AS3___vec_Vector_float4_private__some = 532; // native
const uint32_t __AS3___vec_Vector_float4_private__sort = 533; // native
const uint32_t __AS3___vec_Vector_float4_private_newThisType = 535; // native
const uint32_t __AS3___vec_Vector_float4_length_get = 536; // native
const uint32_t __AS3___vec_Vector_float4_length_set = 537; // native
const uint32_t __AS3___vec_Vector_float4_fixed_set = 538; // native
const uint32_t __AS3___vec_Vector_float4_fixed_get = 539; // native
const uint32_t __AS3___vec_Vector_float4_AS3_toString = 540; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_toLocaleString = 541; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_join = 542; // abc
const uint32_t __AS3___vec_Vector_float4_private__concat = 543; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_every = 544; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_forEach = 545; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_map = 546; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_push = 547; // native
const uint32_t __AS3___vec_Vector_float4_private__reverse = 548; // native
const uint32_t __AS3___vec_Vector_float4_AS3_some = 549; // abc
const uint32_t __AS3___vec_Vector_float4_private__slice = 550; // abc
const uint32_t __AS3___vec_Vector_float4_private__splice = 551; // abc
const uint32_t __AS3___vec_Vector_float4_private__spliceHelper = 552; // native
const uint32_t __AS3___vec_Vector_float4_AS3_unshift = 553; // native
const uint32_t __AS3___vec_Vector_float4_private__filter = 554; // native
const uint32_t __AS3___vec_Vector_float4_private__map = 555; // native
const uint32_t __AS3___vec_Vector_float4_private_clamp = 556; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_concat = 557; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_filter = 558; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_pop = 559; // native
const uint32_t __AS3___vec_Vector_float4_AS3_reverse = 560; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_shift = 561; // native
const uint32_t __AS3___vec_Vector_float4_AS3_slice = 562; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_sort = 563; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_splice = 564; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_indexOf = 565; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_lastIndexOf = 566; // abc
const uint32_t private_MethodClosure_prototype_get = 568; // abc
const uint32_t private_MethodClosure_prototype_set = 569; // abc
const uint32_t Math_private__min = 573; // native
const uint32_t Math_private__max = 574; // native
const uint32_t Math_abs = 575; // native
const uint32_t Math_acos = 576; // native
const uint32_t Math_asin = 577; // native
const uint32_t Math_atan = 578; // native
const uint32_t Math_ceil = 579; // native
const uint32_t Math_cos = 580; // native
const uint32_t Math_exp = 581; // native
const uint32_t Math_floor = 582; // native
const uint32_t Math_log = 583; // native
const uint32_t Math_round = 584; // native
const uint32_t Math_sin = 585; // native
const uint32_t Math_sqrt = 586; // native
const uint32_t Math_tan = 587; // native
const uint32_t Math_atan2 = 588; // native
const uint32_t Math_pow = 589; // native
const uint32_t Math_max = 590; // native
const uint32_t Math_min = 591; // native
const uint32_t Math_random = 592; // native
const uint32_t Error_getErrorMessage = 597; // native
const uint32_t Error_throwError = 599; // abc
const uint32_t Error_getStackTrace = 601; // native
const uint32_t Error_errorID_get = 602; // abc
const uint32_t Date_parse = 677; // native
const uint32_t Date_UTC = 678; // native
const uint32_t Date_AS3_valueOf = 679; // native
const uint32_t Date_private__toString = 680; // native
const uint32_t Date_private__setTime = 681; // native
const uint32_t Date_private__get = 682; // native
const uint32_t Date_AS3_setTime = 683; // abc
const uint32_t Date_AS3_toString = 684; // abc
const uint32_t Date_AS3_toDateString = 685; // abc
const uint32_t Date_AS3_toTimeString = 686; // abc
const uint32_t Date_AS3_toLocaleString = 687; // abc
const uint32_t Date_AS3_toLocaleDateString = 688; // abc
const uint32_t Date_AS3_toLocaleTimeString = 689; // abc
const uint32_t Date_AS3_toUTCString = 690; // abc
const uint32_t Date_AS3_getUTCFullYear = 691; // native
const uint32_t Date_AS3_getUTCMonth = 692; // native
const uint32_t Date_AS3_getUTCDate = 693; // native
const uint32_t Date_AS3_getUTCDay = 694; // native
const uint32_t Date_AS3_getUTCHours = 695; // native
const uint32_t Date_AS3_getUTCMinutes = 696; // native
const uint32_t Date_AS3_getUTCSeconds = 697; // native
const uint32_t Date_AS3_getUTCMilliseconds = 698; // native
const uint32_t Date_AS3_getFullYear = 699; // native
const uint32_t Date_AS3_getMonth = 700; // native
const uint32_t Date_AS3_getDate = 701; // native
const uint32_t Date_AS3_getDay = 702; // native
const uint32_t Date_AS3_getHours = 703; // native
const uint32_t Date_AS3_getMinutes = 704; // native
const uint32_t Date_AS3_getSeconds = 705; // native
const uint32_t Date_AS3_getMilliseconds = 706; // native
const uint32_t Date_AS3_getTimezoneOffset = 707; // native
const uint32_t Date_AS3_getTime = 708; // native
const uint32_t Date_private__setFullYear = 709; // native
const uint32_t Date_private__setMonth = 710; // native
const uint32_t Date_private__setDate = 711; // native
const uint32_t Date_private__setHours = 712; // native
const uint32_t Date_private__setMinutes = 713; // native
const uint32_t Date_private__setSeconds = 714; // native
const uint32_t Date_private__setMilliseconds = 715; // native
const uint32_t Date_private__setUTCFullYear = 716; // native
const uint32_t Date_private__setUTCMonth = 717; // native
const uint32_t Date_private__setUTCDate = 718; // native
const uint32_t Date_private__setUTCHours = 719; // native
const uint32_t Date_private__setUTCMinutes = 720; // native
const uint32_t Date_private__setUTCSeconds = 721; // native
const uint32_t Date_private__setUTCMilliseconds = 722; // native
const uint32_t Date_AS3_setFullYear = 723; // abc
const uint32_t Date_AS3_setMonth = 724; // abc
const uint32_t Date_AS3_setDate = 725; // abc
const uint32_t Date_AS3_setHours = 726; // abc
const uint32_t Date_AS3_setMinutes = 727; // abc
const uint32_t Date_AS3_setSeconds = 728; // abc
const uint32_t Date_AS3_setMilliseconds = 729; // abc
const uint32_t Date_AS3_setUTCFullYear = 730; // abc
const uint32_t Date_AS3_setUTCMonth = 731; // abc
const uint32_t Date_AS3_setUTCDate = 732; // abc
const uint32_t Date_AS3_setUTCHours = 733; // abc
const uint32_t Date_AS3_setUTCMinutes = 734; // abc
const uint32_t Date_AS3_setUTCSeconds = 735; // abc
const uint32_t Date_AS3_setUTCMilliseconds = 736; // abc
const uint32_t Date_fullYear_get = 737; // abc
const uint32_t Date_fullYear_set = 738; // abc
const uint32_t Date_month_get = 739; // abc
const uint32_t Date_month_set = 740; // abc
const uint32_t Date_date_get = 741; // abc
const uint32_t Date_date_set = 742; // abc
const uint32_t Date_hours_get = 743; // abc
const uint32_t Date_hours_set = 744; // abc
const uint32_t Date_minutes_get = 745; // abc
const uint32_t Date_minutes_set = 746; // abc
const uint32_t Date_seconds_get = 747; // abc
const uint32_t Date_seconds_set = 748; // abc
const uint32_t Date_milliseconds_get = 749; // abc
const uint32_t Date_milliseconds_set = 750; // abc
const uint32_t Date_fullYearUTC_get = 751; // abc
const uint32_t Date_fullYearUTC_set = 752; // abc
const uint32_t Date_monthUTC_get = 753; // abc
const uint32_t Date_monthUTC_set = 754; // abc
const uint32_t Date_dateUTC_get = 755; // abc
const uint32_t Date_dateUTC_set = 756; // abc
const uint32_t Date_hoursUTC_get = 757; // abc
const uint32_t Date_hoursUTC_set = 758; // abc
const uint32_t Date_minutesUTC_get = 759; // abc
const uint32_t Date_minutesUTC_set = 760; // abc
const uint32_t Date_secondsUTC_get = 761; // abc
const uint32_t Date_secondsUTC_set = 762; // abc
const uint32_t Date_millisecondsUTC_get = 763; // abc
const uint32_t Date_millisecondsUTC_set = 764; // abc
const uint32_t Date_time_get = 765; // abc
const uint32_t Date_time_set = 766; // abc
const uint32_t Date_timezoneOffset_get = 767; // abc
const uint32_t Date_day_get = 768; // abc
const uint32_t Date_dayUTC_get = 769; // abc
const uint32_t RegExp_source_get = 776; // native
const uint32_t RegExp_global_get = 777; // native
const uint32_t RegExp_ignoreCase_get = 778; // native
const uint32_t RegExp_multiline_get = 779; // native
const uint32_t RegExp_lastIndex_get = 780; // native
const uint32_t RegExp_lastIndex_set = 781; // native
const uint32_t RegExp_dotall_get = 782; // native
const uint32_t RegExp_extended_get = 783; // native
const uint32_t RegExp_AS3_exec = 784; // native
const uint32_t RegExp_AS3_test = 785; // abc
const uint32_t JSON_private_parseCore = 789; // native
const uint32_t JSON_private_stringifySpecializedToString = 790; // native
const uint32_t JSON_parse = 791; // abc
const uint32_t JSON_stringify = 792; // abc
const uint32_t JSON_private_computePropertyList = 793; // abc
const uint32_t Walker_walk = 797; // abc
const uint32_t XML_ignoreComments_get = 842; // native
const uint32_t XML_ignoreComments_set = 843; // native
const uint32_t XML_ignoreProcessingInstructions_get = 844; // native
const uint32_t XML_ignoreProcessingInstructions_set = 845; // native
const uint32_t XML_ignoreWhitespace_get = 846; // native
const uint32_t XML_ignoreWhitespace_set = 847; // native
const uint32_t XML_prettyPrinting_get = 848; // native
const uint32_t XML_prettyPrinting_set = 849; // native
const uint32_t XML_prettyIndent_get = 850; // native
const uint32_t XML_prettyIndent_set = 851; // native
const uint32_t XML_AS3_settings = 852; // abc
const uint32_t XML_AS3_setSettings = 853; // abc
const uint32_t XML_AS3_defaultSettings = 854; // abc
const uint32_t XML_AS3_toString = 855; // native
const uint32_t XML_AS3_hasOwnProperty = 856; // native
const uint32_t XML_AS3_propertyIsEnumerable = 857; // native
const uint32_t XML_AS3_addNamespace = 858; // native
const uint32_t XML_AS3_appendChild = 859; // native
const uint32_t XML_AS3_attribute = 860; // native
const uint32_t XML_AS3_attributes = 861; // native
const uint32_t XML_AS3_child = 862; // native
const uint32_t XML_AS3_childIndex = 863; // native
const uint32_t XML_AS3_children = 864; // native
const uint32_t XML_AS3_comments = 865; // native
const uint32_t XML_AS3_contains = 866; // native
const uint32_t XML_AS3_copy = 867; // native
const uint32_t XML_AS3_descendants = 868; // native
const uint32_t XML_AS3_elements = 869; // native
const uint32_t XML_AS3_hasComplexContent = 870; // native
const uint32_t XML_AS3_hasSimpleContent = 871; // native
const uint32_t XML_AS3_inScopeNamespaces = 872; // native
const uint32_t XML_AS3_insertChildAfter = 873; // native
const uint32_t XML_AS3_insertChildBefore = 874; // native
const uint32_t XML_AS3_length = 875; // abc
const uint32_t XML_AS3_localName = 876; // native
const uint32_t XML_AS3_name = 877; // native
const uint32_t XML_private__namespace = 878; // native
const uint32_t XML_AS3_namespace = 879; // abc
const uint32_t XML_AS3_namespaceDeclarations = 880; // native
const uint32_t XML_AS3_nodeKind = 881; // native
const uint32_t XML_AS3_normalize = 882; // native
const uint32_t XML_AS3_parent = 883; // native
const uint32_t XML_AS3_processingInstructions = 884; // native
const uint32_t XML_AS3_prependChild = 885; // native
const uint32_t XML_AS3_removeNamespace = 886; // native
const uint32_t XML_AS3_replace = 887; // native
const uint32_t XML_AS3_setChildren = 888; // native
const uint32_t XML_AS3_setLocalName = 889; // native
const uint32_t XML_AS3_setName = 890; // native
const uint32_t XML_AS3_setNamespace = 891; // native
const uint32_t XML_AS3_text = 892; // native
const uint32_t XML_AS3_toXMLString = 893; // native
const uint32_t XML_AS3_notification = 894; // native
const uint32_t XML_AS3_setNotification = 895; // native
const uint32_t XML_AS3_toJSON = 896; // abc
const uint32_t XML_AS3_valueOf = 898; // abc
const uint32_t XMLList_AS3_toString = 939; // native
const uint32_t XMLList_AS3_valueOf = 940; // abc
const uint32_t XMLList_AS3_hasOwnProperty = 941; // native
const uint32_t XMLList_AS3_propertyIsEnumerable = 942; // native
const uint32_t XMLList_AS3_attribute = 943; // native
const uint32_t XMLList_AS3_attributes = 944; // native
const uint32_t XMLList_AS3_child = 945; // native
const uint32_t XMLList_AS3_children = 946; // native
const uint32_t XMLList_AS3_comments = 947; // native
const uint32_t XMLList_AS3_contains = 948; // native
const uint32_t XMLList_AS3_copy = 949; // native
const uint32_t XMLList_AS3_descendants = 950; // native
const uint32_t XMLList_AS3_elements = 951; // native
const uint32_t XMLList_AS3_hasComplexContent = 952; // native
const uint32_t XMLList_AS3_hasSimpleContent = 953; // native
const uint32_t XMLList_AS3_length = 954; // native
const uint32_t XMLList_AS3_name = 955; // native
const uint32_t XMLList_AS3_normalize = 956; // native
const uint32_t XMLList_AS3_parent = 957; // native
const uint32_t XMLList_AS3_processingInstructions = 958; // native
const uint32_t XMLList_AS3_text = 959; // native
const uint32_t XMLList_AS3_toXMLString = 960; // native
const uint32_t XMLList_AS3_addNamespace = 961; // native
const uint32_t XMLList_AS3_appendChild = 962; // native
const uint32_t XMLList_AS3_childIndex = 963; // native
const uint32_t XMLList_AS3_inScopeNamespaces = 964; // native
const uint32_t XMLList_AS3_insertChildAfter = 965; // native
const uint32_t XMLList_AS3_insertChildBefore = 966; // native
const uint32_t XMLList_AS3_nodeKind = 967; // native
const uint32_t XMLList_private__namespace = 968; // native
const uint32_t XMLList_AS3_namespace = 969; // abc
const uint32_t XMLList_AS3_localName = 970; // native
const uint32_t XMLList_AS3_namespaceDeclarations = 971; // native
const uint32_t XMLList_AS3_prependChild = 972; // native
const uint32_t XMLList_AS3_removeNamespace = 973; // native
const uint32_t XMLList_AS3_replace = 974; // native
const uint32_t XMLList_AS3_setChildren = 975; // native
const uint32_t XMLList_AS3_setLocalName = 976; // native
const uint32_t XMLList_AS3_setName = 977; // native
const uint32_t XMLList_AS3_setNamespace = 978; // native
const uint32_t XMLList_AS3_toJSON = 979; // abc
const uint32_t QName_localName_get = 983; // native
const uint32_t QName_uri_get = 984; // native
const uint32_t QName_AS3_valueOf = 985; // abc
const uint32_t QName_AS3_toString = 986; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readBytes = 990; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readBoolean = 991; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readByte = 992; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readUnsignedByte = 993; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readShort = 994; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readUnsignedShort = 995; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readInt = 996; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readUnsignedInt = 997; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readFloat = 998; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readDouble = 999; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readMultiByte = 1000; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readUTF = 1001; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readUTFBytes = 1002; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_bytesAvailable_get = 1003; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readObject = 1004; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_objectEncoding_get = 1005; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_objectEncoding_set = 1006; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_endian_get = 1007; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_endian_set = 1008; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeBytes = 1012; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeBoolean = 1013; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeByte = 1014; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeShort = 1015; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeInt = 1016; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeUnsignedInt = 1017; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeFloat = 1018; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeDouble = 1019; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeMultiByte = 1020; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeUTF = 1021; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeUTFBytes = 1022; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeObject = 1023; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_objectEncoding_get = 1024; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_objectEncoding_set = 1025; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_endian_get = 1026; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_endian_set = 1027; // abc
const uint32_t flash_utils_Proxy_flash_proxy_getProperty = 1031; // abc
const uint32_t flash_utils_Proxy_flash_proxy_setProperty = 1032; // abc
const uint32_t flash_utils_Proxy_flash_proxy_callProperty = 1033; // abc
const uint32_t flash_utils_Proxy_flash_proxy_hasProperty = 1034; // abc
const uint32_t flash_utils_Proxy_flash_proxy_deleteProperty = 1035; // abc
const uint32_t flash_utils_Proxy_flash_proxy_getDescendants = 1036; // abc
const uint32_t flash_utils_Proxy_flash_proxy_nextNameIndex = 1037; // abc
const uint32_t flash_utils_Proxy_flash_proxy_nextName = 1038; // abc
const uint32_t flash_utils_Proxy_flash_proxy_nextValue = 1039; // abc
const uint32_t flash_utils_Proxy_flash_proxy_isAttribute = 1040; // native
const uint32_t float_abs = 1049; // abc
const uint32_t float_acos = 1050; // abc
const uint32_t float_asin = 1051; // abc
const uint32_t float_atan = 1052; // abc
const uint32_t float_atan2 = 1053; // abc
const uint32_t float_ceil = 1054; // abc
const uint32_t float_cos = 1055; // abc
const uint32_t float_exp = 1056; // abc
const uint32_t float_floor = 1057; // abc
const uint32_t float_log = 1058; // abc
const uint32_t float_pow = 1059; // abc
const uint32_t float_random = 1060; // abc
const uint32_t float_round = 1061; // abc
const uint32_t float_sin = 1062; // abc
const uint32_t float_sqrt = 1063; // abc
const uint32_t float_tan = 1064; // abc
const uint32_t float_reciprocal = 1065; // native
const uint32_t float_rsqrt = 1066; // native
const uint32_t float_max = 1067; // abc
const uint32_t float_min = 1068; // abc
const uint32_t float_private__minValue = 1069; // native
const uint32_t float_private__floatToString = 1070; // native
const uint32_t float_private__convert = 1071; // native
const uint32_t float_AS3_toString = 1072; // abc
const uint32_t float_AS3_valueOf = 1073; // abc
const uint32_t float_AS3_toExponential = 1074; // abc
const uint32_t float_AS3_toPrecision = 1075; // abc
const uint32_t float_AS3_toFixed = 1076; // abc
const uint32_t float4_isGreater = 1081; // native
const uint32_t float4_isGreaterOrEqual = 1082; // native
const uint32_t float4_isLess = 1083; // native
const uint32_t float4_isLessOrEqual = 1084; // native
const uint32_t float4_isEqual = 1085; // native
const uint32_t float4_isNotEqual = 1086; // native
const uint32_t float4_abs = 1087; // native
const uint32_t float4_max = 1088; // native
const uint32_t float4_min = 1089; // native
const uint32_t float4_reciprocal = 1090; // native
const uint32_t float4_rsqrt = 1091; // native
const uint32_t float4_sqrt = 1092; // native
const uint32_t float4_normalize = 1093; // native
const uint32_t float4_cross = 1094; // native
const uint32_t float4_dot = 1095; // native
const uint32_t float4_dot2 = 1096; // native
const uint32_t float4_dot3 = 1097; // native
const uint32_t float4_magnitude = 1098; // native
const uint32_t float4_magnitude3 = 1099; // native
const uint32_t float4_magnitude2 = 1100; // native
const uint32_t float4_distance = 1101; // native
const uint32_t float4_distance3 = 1102; // native
const uint32_t float4_distance2 = 1103; // native
const uint32_t float4_private__swizzle = 1104; // native
const uint32_t float4_x_get = 1106; // native
const uint32_t float4_y_get = 1107; // native
const uint32_t float4_z_get = 1108; // native
const uint32_t float4_w_get = 1109; // native
const uint32_t float4_xxxx_get = 1110; // abc
const uint32_t float4_xxxy_get = 1111; // abc
const uint32_t float4_xxxz_get = 1112; // abc
const uint32_t float4_xxxw_get = 1113; // abc
const uint32_t float4_xxyx_get = 1114; // abc
const uint32_t float4_xxyy_get = 1115; // abc
const uint32_t float4_xxyz_get = 1116; // abc
const uint32_t float4_xxyw_get = 1117; // abc
const uint32_t float4_xxzx_get = 1118; // abc
const uint32_t float4_xxzy_get = 1119; // abc
const uint32_t float4_xxzz_get = 1120; // abc
const uint32_t float4_xxzw_get = 1121; // abc
const uint32_t float4_xxwx_get = 1122; // abc
const uint32_t float4_xxwy_get = 1123; // abc
const uint32_t float4_xxwz_get = 1124; // abc
const uint32_t float4_xxww_get = 1125; // abc
const uint32_t float4_xyxx_get = 1126; // abc
const uint32_t float4_xyxy_get = 1127; // abc
const uint32_t float4_xyxz_get = 1128; // abc
const uint32_t float4_xyxw_get = 1129; // abc
const uint32_t float4_xyyx_get = 1130; // abc
const uint32_t float4_xyyy_get = 1131; // abc
const uint32_t float4_xyyz_get = 1132; // abc
const uint32_t float4_xyyw_get = 1133; // abc
const uint32_t float4_xyzx_get = 1134; // abc
const uint32_t float4_xyzy_get = 1135; // abc
const uint32_t float4_xyzz_get = 1136; // abc
const uint32_t float4_xyzw_get = 1137; // abc
const uint32_t float4_xywx_get = 1138; // abc
const uint32_t float4_xywy_get = 1139; // abc
const uint32_t float4_xywz_get = 1140; // abc
const uint32_t float4_xyww_get = 1141; // abc
const uint32_t float4_xzxx_get = 1142; // abc
const uint32_t float4_xzxy_get = 1143; // abc
const uint32_t float4_xzxz_get = 1144; // abc
const uint32_t float4_xzxw_get = 1145; // abc
const uint32_t float4_xzyx_get = 1146; // abc
const uint32_t float4_xzyy_get = 1147; // abc
const uint32_t float4_xzyz_get = 1148; // abc
const uint32_t float4_xzyw_get = 1149; // abc
const uint32_t float4_xzzx_get = 1150; // abc
const uint32_t float4_xzzy_get = 1151; // abc
const uint32_t float4_xzzz_get = 1152; // abc
const uint32_t float4_xzzw_get = 1153; // abc
const uint32_t float4_xzwx_get = 1154; // abc
const uint32_t float4_xzwy_get = 1155; // abc
const uint32_t float4_xzwz_get = 1156; // abc
const uint32_t float4_xzww_get = 1157; // abc
const uint32_t float4_xwxx_get = 1158; // abc
const uint32_t float4_xwxy_get = 1159; // abc
const uint32_t float4_xwxz_get = 1160; // abc
const uint32_t float4_xwxw_get = 1161; // abc
const uint32_t float4_xwyx_get = 1162; // abc
const uint32_t float4_xwyy_get = 1163; // abc
const uint32_t float4_xwyz_get = 1164; // abc
const uint32_t float4_xwyw_get = 1165; // abc
const uint32_t float4_xwzx_get = 1166; // abc
const uint32_t float4_xwzy_get = 1167; // abc
const uint32_t float4_xwzz_get = 1168; // abc
const uint32_t float4_xwzw_get = 1169; // abc
const uint32_t float4_xwwx_get = 1170; // abc
const uint32_t float4_xwwy_get = 1171; // abc
const uint32_t float4_xwwz_get = 1172; // abc
const uint32_t float4_xwww_get = 1173; // abc
const uint32_t float4_yxxx_get = 1174; // abc
const uint32_t float4_yxxy_get = 1175; // abc
const uint32_t float4_yxxz_get = 1176; // abc
const uint32_t float4_yxxw_get = 1177; // abc
const uint32_t float4_yxyx_get = 1178; // abc
const uint32_t float4_yxyy_get = 1179; // abc
const uint32_t float4_yxyz_get = 1180; // abc
const uint32_t float4_yxyw_get = 1181; // abc
const uint32_t float4_yxzx_get = 1182; // abc
const uint32_t float4_yxzy_get = 1183; // abc
const uint32_t float4_yxzz_get = 1184; // abc
const uint32_t float4_yxzw_get = 1185; // abc
const uint32_t float4_yxwx_get = 1186; // abc
const uint32_t float4_yxwy_get = 1187; // abc
const uint32_t float4_yxwz_get = 1188; // abc
const uint32_t float4_yxww_get = 1189; // abc
const uint32_t float4_yyxx_get = 1190; // abc
const uint32_t float4_yyxy_get = 1191; // abc
const uint32_t float4_yyxz_get = 1192; // abc
const uint32_t float4_yyxw_get = 1193; // abc
const uint32_t float4_yyyx_get = 1194; // abc
const uint32_t float4_yyyy_get = 1195; // abc
const uint32_t float4_yyyz_get = 1196; // abc
const uint32_t float4_yyyw_get = 1197; // abc
const uint32_t float4_yyzx_get = 1198; // abc
const uint32_t float4_yyzy_get = 1199; // abc
const uint32_t float4_yyzz_get = 1200; // abc
const uint32_t float4_yyzw_get = 1201; // abc
const uint32_t float4_yywx_get = 1202; // abc
const uint32_t float4_yywy_get = 1203; // abc
const uint32_t float4_yywz_get = 1204; // abc
const uint32_t float4_yyww_get = 1205; // abc
const uint32_t float4_yzxx_get = 1206; // abc
const uint32_t float4_yzxy_get = 1207; // abc
const uint32_t float4_yzxz_get = 1208; // abc
const uint32_t float4_yzxw_get = 1209; // abc
const uint32_t float4_yzyx_get = 1210; // abc
const uint32_t float4_yzyy_get = 1211; // abc
const uint32_t float4_yzyz_get = 1212; // abc
const uint32_t float4_yzyw_get = 1213; // abc
const uint32_t float4_yzzx_get = 1214; // abc
const uint32_t float4_yzzy_get = 1215; // abc
const uint32_t float4_yzzz_get = 1216; // abc
const uint32_t float4_yzzw_get = 1217; // abc
const uint32_t float4_yzwx_get = 1218; // abc
const uint32_t float4_yzwy_get = 1219; // abc
const uint32_t float4_yzwz_get = 1220; // abc
const uint32_t float4_yzww_get = 1221; // abc
const uint32_t float4_ywxx_get = 1222; // abc
const uint32_t float4_ywxy_get = 1223; // abc
const uint32_t float4_ywxz_get = 1224; // abc
const uint32_t float4_ywxw_get = 1225; // abc
const uint32_t float4_ywyx_get = 1226; // abc
const uint32_t float4_ywyy_get = 1227; // abc
const uint32_t float4_ywyz_get = 1228; // abc
const uint32_t float4_ywyw_get = 1229; // abc
const uint32_t float4_ywzx_get = 1230; // abc
const uint32_t float4_ywzy_get = 1231; // abc
const uint32_t float4_ywzz_get = 1232; // abc
const uint32_t float4_ywzw_get = 1233; // abc
const uint32_t float4_ywwx_get = 1234; // abc
const uint32_t float4_ywwy_get = 1235; // abc
const uint32_t float4_ywwz_get = 1236; // abc
const uint32_t float4_ywww_get = 1237; // abc
const uint32_t float4_zxxx_get = 1238; // abc
const uint32_t float4_zxxy_get = 1239; // abc
const uint32_t float4_zxxz_get = 1240; // abc
const uint32_t float4_zxxw_get = 1241; // abc
const uint32_t float4_zxyx_get = 1242; // abc
const uint32_t float4_zxyy_get = 1243; // abc
const uint32_t float4_zxyz_get = 1244; // abc
const uint32_t float4_zxyw_get = 1245; // abc
const uint32_t float4_zxzx_get = 1246; // abc
const uint32_t float4_zxzy_get = 1247; // abc
const uint32_t float4_zxzz_get = 1248; // abc
const uint32_t float4_zxzw_get = 1249; // abc
const uint32_t float4_zxwx_get = 1250; // abc
const uint32_t float4_zxwy_get = 1251; // abc
const uint32_t float4_zxwz_get = 1252; // abc
const uint32_t float4_zxww_get = 1253; // abc
const uint32_t float4_zyxx_get = 1254; // abc
const uint32_t float4_zyxy_get = 1255; // abc
const uint32_t float4_zyxz_get = 1256; // abc
const uint32_t float4_zyxw_get = 1257; // abc
const uint32_t float4_zyyx_get = 1258; // abc
const uint32_t float4_zyyy_get = 1259; // abc
const uint32_t float4_zyyz_get = 1260; // abc
const uint32_t float4_zyyw_get = 1261; // abc
const uint32_t float4_zyzx_get = 1262; // abc
const uint32_t float4_zyzy_get = 1263; // abc
const uint32_t float4_zyzz_get = 1264; // abc
const uint32_t float4_zyzw_get = 1265; // abc
const uint32_t float4_zywx_get = 1266; // abc
const uint32_t float4_zywy_get = 1267; // abc
const uint32_t float4_zywz_get = 1268; // abc
const uint32_t float4_zyww_get = 1269; // abc
const uint32_t float4_zzxx_get = 1270; // abc
const uint32_t float4_zzxy_get = 1271; // abc
const uint32_t float4_zzxz_get = 1272; // abc
const uint32_t float4_zzxw_get = 1273; // abc
const uint32_t float4_zzyx_get = 1274; // abc
const uint32_t float4_zzyy_get = 1275; // abc
const uint32_t float4_zzyz_get = 1276; // abc
const uint32_t float4_zzyw_get = 1277; // abc
const uint32_t float4_zzzx_get = 1278; // abc
const uint32_t float4_zzzy_get = 1279; // abc
const uint32_t float4_zzzz_get = 1280; // abc
const uint32_t float4_zzzw_get = 1281; // abc
const uint32_t float4_zzwx_get = 1282; // abc
const uint32_t float4_zzwy_get = 1283; // abc
const uint32_t float4_zzwz_get = 1284; // abc
const uint32_t float4_zzww_get = 1285; // abc
const uint32_t float4_zwxx_get = 1286; // abc
const uint32_t float4_zwxy_get = 1287; // abc
const uint32_t float4_zwxz_get = 1288; // abc
const uint32_t float4_zwxw_get = 1289; // abc
const uint32_t float4_zwyx_get = 1290; // abc
const uint32_t float4_zwyy_get = 1291; // abc
const uint32_t float4_zwyz_get = 1292; // abc
const uint32_t float4_zwyw_get = 1293; // abc
const uint32_t float4_zwzx_get = 1294; // abc
const uint32_t float4_zwzy_get = 1295; // abc
const uint32_t float4_zwzz_get = 1296; // abc
const uint32_t float4_zwzw_get = 1297; // abc
const uint32_t float4_zwwx_get = 1298; // abc
const uint32_t float4_zwwy_get = 1299; // abc
const uint32_t float4_zwwz_get = 1300; // abc
const uint32_t float4_zwww_get = 1301; // abc
const uint32_t float4_wxxx_get = 1302; // abc
const uint32_t float4_wxxy_get = 1303; // abc
const uint32_t float4_wxxz_get = 1304; // abc
const uint32_t float4_wxxw_get = 1305; // abc
const uint32_t float4_wxyx_get = 1306; // abc
const uint32_t float4_wxyy_get = 1307; // abc
const uint32_t float4_wxyz_get = 1308; // abc
const uint32_t float4_wxyw_get = 1309; // abc
const uint32_t float4_wxzx_get = 1310; // abc
const uint32_t float4_wxzy_get = 1311; // abc
const uint32_t float4_wxzz_get = 1312; // abc
const uint32_t float4_wxzw_get = 1313; // abc
const uint32_t float4_wxwx_get = 1314; // abc
const uint32_t float4_wxwy_get = 1315; // abc
const uint32_t float4_wxwz_get = 1316; // abc
const uint32_t float4_wxww_get = 1317; // abc
const uint32_t float4_wyxx_get = 1318; // abc
const uint32_t float4_wyxy_get = 1319; // abc
const uint32_t float4_wyxz_get = 1320; // abc
const uint32_t float4_wyxw_get = 1321; // abc
const uint32_t float4_wyyx_get = 1322; // abc
const uint32_t float4_wyyy_get = 1323; // abc
const uint32_t float4_wyyz_get = 1324; // abc
const uint32_t float4_wyyw_get = 1325; // abc
const uint32_t float4_wyzx_get = 1326; // abc
const uint32_t float4_wyzy_get = 1327; // abc
const uint32_t float4_wyzz_get = 1328; // abc
const uint32_t float4_wyzw_get = 1329; // abc
const uint32_t float4_wywx_get = 1330; // abc
const uint32_t float4_wywy_get = 1331; // abc
const uint32_t float4_wywz_get = 1332; // abc
const uint32_t float4_wyww_get = 1333; // abc
const uint32_t float4_wzxx_get = 1334; // abc
const uint32_t float4_wzxy_get = 1335; // abc
const uint32_t float4_wzxz_get = 1336; // abc
const uint32_t float4_wzxw_get = 1337; // abc
const uint32_t float4_wzyx_get = 1338; // abc
const uint32_t float4_wzyy_get = 1339; // abc
const uint32_t float4_wzyz_get = 1340; // abc
const uint32_t float4_wzyw_get = 1341; // abc
const uint32_t float4_wzzx_get = 1342; // abc
const uint32_t float4_wzzy_get = 1343; // abc
const uint32_t float4_wzzz_get = 1344; // abc
const uint32_t float4_wzzw_get = 1345; // abc
const uint32_t float4_wzwx_get = 1346; // abc
const uint32_t float4_wzwy_get = 1347; // abc
const uint32_t float4_wzwz_get = 1348; // abc
const uint32_t float4_wzww_get = 1349; // abc
const uint32_t float4_wwxx_get = 1350; // abc
const uint32_t float4_wwxy_get = 1351; // abc
const uint32_t float4_wwxz_get = 1352; // abc
const uint32_t float4_wwxw_get = 1353; // abc
const uint32_t float4_wwyx_get = 1354; // abc
const uint32_t float4_wwyy_get = 1355; // abc
const uint32_t float4_wwyz_get = 1356; // abc
const uint32_t float4_wwyw_get = 1357; // abc
const uint32_t float4_wwzx_get = 1358; // abc
const uint32_t float4_wwzy_get = 1359; // abc
const uint32_t float4_wwzz_get = 1360; // abc
const uint32_t float4_wwzw_get = 1361; // abc
const uint32_t float4_wwwx_get = 1362; // abc
const uint32_t float4_wwwy_get = 1363; // abc
const uint32_t float4_wwwz_get = 1364; // abc
const uint32_t float4_wwww_get = 1365; // abc
const uint32_t float4_AS3_toString = 1366; // abc
const uint32_t float4_AS3_valueOf = 1367; // abc
const uint32_t flash_utils_ByteArray_defaultObjectEncoding_get = 1373; // native
const uint32_t flash_utils_ByteArray_defaultObjectEncoding_set = 1374; // native
const uint32_t flash_utils_ByteArray_readBytes = 1376; // native
const uint32_t flash_utils_ByteArray_writeBytes = 1377; // native
const uint32_t flash_utils_ByteArray_writeBoolean = 1378; // native
const uint32_t flash_utils_ByteArray_writeByte = 1379; // native
const uint32_t flash_utils_ByteArray_writeShort = 1380; // native
const uint32_t flash_utils_ByteArray_writeInt = 1381; // native
const uint32_t flash_utils_ByteArray_writeUnsignedInt = 1382; // native
const uint32_t flash_utils_ByteArray_writeFloat = 1383; // native
const uint32_t flash_utils_ByteArray_writeFloat4 = 1384; // native
const uint32_t flash_utils_ByteArray_writeDouble = 1385; // native
const uint32_t flash_utils_ByteArray_writeMultiByte = 1386; // native
const uint32_t flash_utils_ByteArray_writeUTF = 1387; // native
const uint32_t flash_utils_ByteArray_writeUTFBytes = 1388; // native
const uint32_t flash_utils_ByteArray_readBoolean = 1389; // native
const uint32_t flash_utils_ByteArray_readByte = 1390; // native
const uint32_t flash_utils_ByteArray_readUnsignedByte = 1391; // native
const uint32_t flash_utils_ByteArray_readShort = 1392; // native
const uint32_t flash_utils_ByteArray_readUnsignedShort = 1393; // native
const uint32_t flash_utils_ByteArray_readInt = 1394; // native
const uint32_t flash_utils_ByteArray_readUnsignedInt = 1395; // native
const uint32_t flash_utils_ByteArray_readFloat = 1396; // native
const uint32_t flash_utils_ByteArray_readFloat4 = 1397; // native
const uint32_t flash_utils_ByteArray_readDouble = 1398; // native
const uint32_t flash_utils_ByteArray_readMultiByte = 1399; // native
const uint32_t flash_utils_ByteArray_readUTF = 1400; // native
const uint32_t flash_utils_ByteArray_readUTFBytes = 1401; // native
const uint32_t flash_utils_ByteArray_length_get = 1402; // native
const uint32_t flash_utils_ByteArray_length_set = 1403; // native
const uint32_t flash_utils_ByteArray_writeObject = 1404; // native
const uint32_t flash_utils_ByteArray_readObject = 1405; // native
const uint32_t flash_utils_ByteArray_deflate = 1406; // abc
const uint32_t flash_utils_ByteArray_private__compress = 1407; // native
const uint32_t flash_utils_ByteArray_compress = 1408; // abc
const uint32_t flash_utils_ByteArray_inflate = 1409; // abc
const uint32_t flash_utils_ByteArray_private__uncompress = 1410; // native
const uint32_t flash_utils_ByteArray_uncompress = 1411; // abc
const uint32_t flash_utils_ByteArray_toString = 1412; // abc
const uint32_t flash_utils_ByteArray_private__toString = 1413; // native
const uint32_t flash_utils_ByteArray_bytesAvailable_get = 1414; // native
const uint32_t flash_utils_ByteArray_position_get = 1415; // native
const uint32_t flash_utils_ByteArray_position_set = 1416; // native
const uint32_t flash_utils_ByteArray_objectEncoding_get = 1417; // native
const uint32_t flash_utils_ByteArray_objectEncoding_set = 1418; // native
const uint32_t flash_utils_ByteArray_endian_get = 1419; // native
const uint32_t flash_utils_ByteArray_endian_set = 1420; // native
const uint32_t flash_utils_ByteArray_clear = 1421; // native

extern double Math_private__min_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_private__max_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_abs_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_acos_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_asin_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_atan_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_ceil_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_cos_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_exp_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_floor_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_log_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_round_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_sin_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_sqrt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_tan_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_atan2_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_pow_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_max_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_min_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Math_random_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Error_getErrorMessage_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Error_getStackTrace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_parse_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_UTC_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_valueOf_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Date_private__toString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setTime_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getUTCFullYear_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getUTCMonth_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getUTCDate_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getUTCDay_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getUTCHours_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getUTCMinutes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getUTCSeconds_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getUTCMilliseconds_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getFullYear_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getMonth_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getDate_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getDay_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getHours_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getMinutes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getSeconds_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getMilliseconds_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getTimezoneOffset_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_AS3_getTime_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setFullYear_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setMonth_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setDate_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setHours_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setMinutes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setSeconds_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setMilliseconds_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setUTCFullYear_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setUTCMonth_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setUTCDate_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setUTCHours_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setUTCMinutes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setUTCSeconds_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Date_private__setUTCMilliseconds_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom RegExp_source_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom RegExp_global_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom RegExp_ignoreCase_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom RegExp_multiline_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom RegExp_lastIndex_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom RegExp_lastIndex_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom RegExp_dotall_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom RegExp_extended_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom RegExp_AS3_exec_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom JSON_private_parseCore_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom JSON_private_stringifySpecializedToString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_ignoreComments_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_ignoreComments_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_ignoreProcessingInstructions_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_ignoreProcessingInstructions_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_ignoreWhitespace_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_ignoreWhitespace_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_prettyPrinting_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_prettyPrinting_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_prettyIndent_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_prettyIndent_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_toString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_hasOwnProperty_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_propertyIsEnumerable_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_addNamespace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_appendChild_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_attribute_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_attributes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_child_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_childIndex_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_children_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_comments_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_contains_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_copy_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_descendants_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_elements_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_hasComplexContent_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_hasSimpleContent_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_inScopeNamespaces_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_insertChildAfter_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_insertChildBefore_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_localName_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_name_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_private__namespace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_namespaceDeclarations_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_nodeKind_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_normalize_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_parent_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_processingInstructions_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_prependChild_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_removeNamespace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_replace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_setChildren_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_setLocalName_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_setName_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_setNamespace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_text_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_toXMLString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_notification_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XML_AS3_setNotification_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_toString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_hasOwnProperty_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_propertyIsEnumerable_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_attribute_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_attributes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_child_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_children_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_comments_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_contains_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_copy_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_descendants_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_elements_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_hasComplexContent_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_hasSimpleContent_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_length_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_name_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_normalize_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_parent_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_processingInstructions_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_text_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_toXMLString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_addNamespace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_appendChild_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_childIndex_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_inScopeNamespaces_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_insertChildAfter_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_insertChildBefore_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_nodeKind_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_private__namespace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_localName_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_namespaceDeclarations_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_prependChild_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_removeNamespace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_replace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_setChildren_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_setLocalName_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_setName_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom XMLList_AS3_setNamespace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom QName_localName_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom QName_uri_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_Proxy_flash_proxy_isAttribute_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_reciprocal_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_rsqrt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_private__minValue_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom float_private__floatToString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom float_private__convert_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_isGreater_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_isGreaterOrEqual_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_isLess_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_isLessOrEqual_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_isEqual_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_isNotEqual_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_abs_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_max_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_min_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_reciprocal_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_rsqrt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_sqrt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_normalize_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_cross_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_dot_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_dot2_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_dot3_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_magnitude_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_magnitude3_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_magnitude2_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_distance_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_distance3_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_distance2_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t float4_private__swizzle_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_x_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_y_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_z_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_w_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_defaultObjectEncoding_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_defaultObjectEncoding_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_readBytes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeBytes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeBoolean_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeByte_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeShort_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeInt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeUnsignedInt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeFloat_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeFloat4_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeDouble_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeMultiByte_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeUTF_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeUTFBytes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_readBoolean_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_readByte_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_readUnsignedByte_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_readShort_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_readUnsignedShort_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_readInt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_readUnsignedInt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double flash_utils_ByteArray_readFloat_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t flash_utils_ByteArray_readFloat4_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double flash_utils_ByteArray_readDouble_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_readMultiByte_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_readUTF_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_readUTFBytes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_length_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_length_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_writeObject_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_readObject_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_private__compress_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_private__uncompress_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_private__toString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_bytesAvailable_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_position_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_position_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_objectEncoding_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_objectEncoding_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_endian_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_endian_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_utils_ByteArray_clear_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Object_private__hasOwnProperty_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Object_private__propertyIsEnumerable_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Object_protected__setPropertyIsEnumerable_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Object_private__isPrototypeOf_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Object_private__toString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Class_prototype_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Function_prototype_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Function_prototype_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Function_length_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Function_AS3_call_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Function_AS3_apply_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Namespace_prefix_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Namespace_uri_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Number_private__numberToString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Number_private__convert_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_private__minValue_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_AS3_fromCharCode_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_private__match_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_private__replace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_private__search_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_private__split_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_length_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_private__indexOf_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_AS3_indexOf_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_private__lastIndexOf_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_AS3_lastIndexOf_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_AS3_charAt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double String_AS3_charCodeAt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_AS3_localeCompare_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_private__slice_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_AS3_slice_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_private__substring_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_AS3_substring_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_private__substr_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_AS3_substr_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_AS3_toLowerCase_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom String_AS3_toUpperCase_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__pop_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__reverse_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__concat_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__shift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__slice_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__unshift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__splice_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__sort_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__sortOn_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__indexOf_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__lastIndexOf_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__every_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__filter_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__forEach_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__map_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_private__some_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_length_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_length_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_AS3_pop_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_AS3_push_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Array_AS3_unshift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_bugzilla_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_decodeURI_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_decodeURIComponent_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_encodeURI_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_encodeURIComponent_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_isNaN_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_isFinite_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_parseInt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_parseFloat_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_escape_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_unescape_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_isXMLName_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_private__every_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_private__forEach_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_private__some_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_private__sort_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_private_newThisType_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_length_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_length_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_fixed_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_fixed_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_AS3_push_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_private__reverse_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_private__spliceHelper_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_AS3_unshift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_private__filter_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_private__map_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_AS3_pop_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_object_AS3_shift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_private__every_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_private__forEach_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_private__some_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_private__sort_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_private_newThisType_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_length_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_length_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_fixed_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_fixed_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_AS3_push_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_private__reverse_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_private__spliceHelper_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_AS3_unshift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_private__filter_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_private__map_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_AS3_pop_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_int_AS3_shift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_private__every_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_private__forEach_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_private__some_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_private__sort_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_private_newThisType_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_length_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_length_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_fixed_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_fixed_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_AS3_push_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_private__reverse_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_private__spliceHelper_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_AS3_unshift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_private__filter_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_private__map_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_AS3_pop_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_uint_AS3_shift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_private__every_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_private__forEach_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_private__some_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_private__sort_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_private_newThisType_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_length_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_length_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_fixed_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_fixed_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_AS3_push_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_private__reverse_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_private__spliceHelper_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_AS3_unshift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_private__filter_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_double_private__map_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double __AS3___vec_Vector_double_AS3_pop_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double __AS3___vec_Vector_double_AS3_shift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_private__every_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_private__forEach_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_private__some_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_private__sort_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_private_newThisType_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_length_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_length_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_fixed_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_fixed_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_AS3_push_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_private__reverse_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_private__spliceHelper_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_AS3_unshift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_private__filter_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float_private__map_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float __AS3___vec_Vector_float_AS3_pop_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float __AS3___vec_Vector_float_AS3_shift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_private__every_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_private__forEach_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_private__some_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_private__sort_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_private_newThisType_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_length_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_length_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_fixed_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_fixed_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_AS3_push_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_private__reverse_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_private__spliceHelper_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_AS3_unshift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_private__filter_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom __AS3___vec_Vector_float4_private__map_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t __AS3___vec_Vector_float4_AS3_pop_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float4_t __AS3___vec_Vector_float4_AS3_shift_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_avmplus_describeTypeJSON_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_avmplus_getQualifiedClassName_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_avmplus_getQualifiedSuperclassName_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
class SlotOffsetsAndAsserts;
//-----------------------------------------------------------
// Object$
//-----------------------------------------------------------
class avmplus_ObjectClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ObjectClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_ObjectClass
};
#define DECLARE_SLOTS_ObjectClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline avmplus::Atom constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return result; \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE avmplus::Atom asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return result; \
        } \
        REALLY_INLINE avmplus::Atom asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return result; \
        } \
        REALLY_INLINE avmplus::Atom coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return result; \
        } \
        REALLY_INLINE avmplus::Atom coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return result; \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_ObjectClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_ObjectClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_ObjectClassSlots m_slots_ObjectClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Class$
//-----------------------------------------------------------
class avmplus_ClassClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ClassClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_ClassClass
};
#define DECLARE_SLOTS_ClassClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::ClassClosure> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ClassClosure>((avmplus::ClassClosure*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::ClassClosure> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::ClassClosure>((avmplus::ClassClosure*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ClassClosure> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::ClassClosure>((avmplus::ClassClosure*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ClassClosure> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::ClassClosure>((avmplus::ClassClosure*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ClassClosure> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::ClassClosure>((avmplus::ClassClosure*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_ClassClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_ClassClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_ClassClassSlots m_slots_ClassClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Class
//-----------------------------------------------------------
class avmplus_ClassClosureSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ClassClosure;
#define GC_TRIVIAL_TRACER_ClassClosure
};
#define DECLARE_SLOTS_ClassClosure \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Function$
//-----------------------------------------------------------
class avmplus_FunctionClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::FunctionClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_FunctionClass
};
#define DECLARE_SLOTS_FunctionClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::FunctionObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::FunctionObject>((avmplus::FunctionObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::FunctionObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::FunctionObject>((avmplus::FunctionObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::FunctionObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::FunctionObject>((avmplus::FunctionObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::FunctionObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::FunctionObject>((avmplus::FunctionObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::FunctionObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::FunctionObject>((avmplus::FunctionObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        inline GCRef<avmplus::FunctionObject> call_createEmptyFunction() \
        { \
            avmplus::MethodEnv* const method = vtable->methods[5]; \
            avmplus::Atom const result = method->coerceEnter(thisRef.reinterpretCast<avmplus::ScriptObject>()->atom()); \
            return GCRef<avmplus::FunctionObject>((avmplus::FunctionObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_FunctionClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_FunctionClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_FunctionClassSlots m_slots_FunctionClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Function
//-----------------------------------------------------------
class avmplus_FunctionObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::FunctionObject;
#define GC_TRIVIAL_TRACER_FunctionObject
};
#define DECLARE_SLOTS_FunctionObject \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Namespace$
//-----------------------------------------------------------
class avmplus_NamespaceClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NamespaceClass;
private:
    avmplus::AtomWB m_length;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceAtom(&m_length);
    }
};
#define DECLARE_SLOTS_NamespaceClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::Namespace> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::Namespace>(avmplus::AvmCore::atomToNamespace(result)); \
        } \
        inline GCRef<avmplus::Namespace> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::Namespace>(avmplus::AvmCore::atomToNamespace(result)); \
        } \
        inline GCRef<avmplus::Namespace> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::Namespace>(avmplus::AvmCore::atomToNamespace(result)); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::Namespace> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::Namespace>(avmplus::AvmCore::atomToNamespace(result)); \
        } \
        REALLY_INLINE GCRef<avmplus::Namespace> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::Namespace>(avmplus::AvmCore::atomToNamespace(result)); \
        } \
        REALLY_INLINE GCRef<avmplus::Namespace> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::Namespace>(avmplus::AvmCore::atomToNamespace(result)); \
        } \
        REALLY_INLINE GCRef<avmplus::Namespace> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::Namespace>(avmplus::AvmCore::atomToNamespace(result)); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE avmplus::Atom get_length() const { return m_slots_NamespaceClass.m_length; } \
        REALLY_INLINE void setconst_length(avmplus::Atom newVal) { m_slots_NamespaceClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_NamespaceClassSlots m_slots_NamespaceClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Boolean$
//-----------------------------------------------------------
class avmplus_BooleanClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::BooleanClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_BooleanClass
};
#define DECLARE_SLOTS_BooleanClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE bool asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return ((result) != avmplus::falseAtom); \
        } \
        REALLY_INLINE bool asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return ((result) != avmplus::falseAtom); \
        } \
        REALLY_INLINE bool coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return ((result) != avmplus::falseAtom); \
        } \
        REALLY_INLINE bool coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return ((result) != avmplus::falseAtom); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_BooleanClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_BooleanClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_BooleanClassSlots m_slots_BooleanClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Number$
//-----------------------------------------------------------
class avmplus_NumberClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NumberClass;
private:
    int32_t m_length;
    int32_t m_private_DTOSTR_FIXED;
    int32_t m_private_DTOSTR_PRECISION;
    int32_t m_private_DTOSTR_EXPONENTIAL;
    double m_NaN;
    double m_NEGATIVE_INFINITY;
    double m_POSITIVE_INFINITY;
    double m_MIN_VALUE;
    double m_MAX_VALUE;
#define GC_TRIVIAL_TRACER_NumberClass
};
#define DECLARE_SLOTS_NumberClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE double asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return avmplus::AvmCore::number(result); \
        } \
        REALLY_INLINE double asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return avmplus::AvmCore::number(result); \
        } \
        REALLY_INLINE double coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return avmplus::AvmCore::number(result); \
        } \
        REALLY_INLINE double coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return avmplus::AvmCore::number(result); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_NumberClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_NumberClass.m_length = newVal; } \
    protected: \
        REALLY_INLINE int32_t get_DTOSTR_FIXED() const { return m_slots_NumberClass.m_private_DTOSTR_FIXED; } \
        REALLY_INLINE void setconst_DTOSTR_FIXED(int32_t newVal) { m_slots_NumberClass.m_private_DTOSTR_FIXED = newVal; } \
    protected: \
        REALLY_INLINE int32_t get_DTOSTR_PRECISION() const { return m_slots_NumberClass.m_private_DTOSTR_PRECISION; } \
        REALLY_INLINE void setconst_DTOSTR_PRECISION(int32_t newVal) { m_slots_NumberClass.m_private_DTOSTR_PRECISION = newVal; } \
    protected: \
        REALLY_INLINE int32_t get_DTOSTR_EXPONENTIAL() const { return m_slots_NumberClass.m_private_DTOSTR_EXPONENTIAL; } \
        REALLY_INLINE void setconst_DTOSTR_EXPONENTIAL(int32_t newVal) { m_slots_NumberClass.m_private_DTOSTR_EXPONENTIAL = newVal; } \
    public: \
        REALLY_INLINE double get_NaN() const { return m_slots_NumberClass.m_NaN; } \
        REALLY_INLINE void setconst_NaN(double newVal) { m_slots_NumberClass.m_NaN = newVal; } \
    public: \
        REALLY_INLINE double get_NEGATIVE_INFINITY() const { return m_slots_NumberClass.m_NEGATIVE_INFINITY; } \
        REALLY_INLINE void setconst_NEGATIVE_INFINITY(double newVal) { m_slots_NumberClass.m_NEGATIVE_INFINITY = newVal; } \
    public: \
        REALLY_INLINE double get_POSITIVE_INFINITY() const { return m_slots_NumberClass.m_POSITIVE_INFINITY; } \
        REALLY_INLINE void setconst_POSITIVE_INFINITY(double newVal) { m_slots_NumberClass.m_POSITIVE_INFINITY = newVal; } \
    public: \
        REALLY_INLINE double get_MIN_VALUE() const { return m_slots_NumberClass.m_MIN_VALUE; } \
        REALLY_INLINE void setconst_MIN_VALUE(double newVal) { m_slots_NumberClass.m_MIN_VALUE = newVal; } \
    public: \
        REALLY_INLINE double get_MAX_VALUE() const { return m_slots_NumberClass.m_MAX_VALUE; } \
        REALLY_INLINE void setconst_MAX_VALUE(double newVal) { m_slots_NumberClass.m_MAX_VALUE = newVal; } \
    private: \
        avmplus::NativeID::avmplus_NumberClassSlots m_slots_NumberClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// int$
//-----------------------------------------------------------
class avmplus_IntClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::IntClass;
private:
    int32_t m_MIN_VALUE;
    int32_t m_MAX_VALUE;
    int32_t m_length;
#define GC_TRIVIAL_TRACER_IntClass
};
#define DECLARE_SLOTS_IntClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE int32_t asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return avmplus::AvmCore::integer(result); \
        } \
        REALLY_INLINE int32_t asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return avmplus::AvmCore::integer(result); \
        } \
        REALLY_INLINE int32_t coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return avmplus::AvmCore::integer(result); \
        } \
        REALLY_INLINE int32_t coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return avmplus::AvmCore::integer(result); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_MIN_VALUE() const { return m_slots_IntClass.m_MIN_VALUE; } \
        REALLY_INLINE void setconst_MIN_VALUE(int32_t newVal) { m_slots_IntClass.m_MIN_VALUE = newVal; } \
    public: \
        REALLY_INLINE int32_t get_MAX_VALUE() const { return m_slots_IntClass.m_MAX_VALUE; } \
        REALLY_INLINE void setconst_MAX_VALUE(int32_t newVal) { m_slots_IntClass.m_MAX_VALUE = newVal; } \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_IntClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_IntClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_IntClassSlots m_slots_IntClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// uint$
//-----------------------------------------------------------
class avmplus_UIntClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::UIntClass;
private:
    uint32_t m_MIN_VALUE;
    uint32_t m_MAX_VALUE;
    int32_t m_length;
#define GC_TRIVIAL_TRACER_UIntClass
};
#define DECLARE_SLOTS_UIntClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE uint32_t asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return avmplus::AvmCore::toUInt32(result); \
        } \
        REALLY_INLINE uint32_t asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return avmplus::AvmCore::toUInt32(result); \
        } \
        REALLY_INLINE uint32_t coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return avmplus::AvmCore::toUInt32(result); \
        } \
        REALLY_INLINE uint32_t coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return avmplus::AvmCore::toUInt32(result); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE uint32_t get_MIN_VALUE() const { return m_slots_UIntClass.m_MIN_VALUE; } \
        REALLY_INLINE void setconst_MIN_VALUE(uint32_t newVal) { m_slots_UIntClass.m_MIN_VALUE = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_MAX_VALUE() const { return m_slots_UIntClass.m_MAX_VALUE; } \
        REALLY_INLINE void setconst_MAX_VALUE(uint32_t newVal) { m_slots_UIntClass.m_MAX_VALUE = newVal; } \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_UIntClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_UIntClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_UIntClassSlots m_slots_UIntClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// String$
//-----------------------------------------------------------
class avmplus_StringClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::StringClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_StringClass
};
#define DECLARE_SLOTS_StringClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::String> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::String>(avmplus::AvmCore::atomToString(result)); \
        } \
        inline GCRef<avmplus::String> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::String>(avmplus::AvmCore::atomToString(result)); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::String> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::String>(avmplus::AvmCore::atomToString(result)); \
        } \
        REALLY_INLINE GCRef<avmplus::String> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::String>(avmplus::AvmCore::atomToString(result)); \
        } \
        REALLY_INLINE GCRef<avmplus::String> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::String>(avmplus::AvmCore::atomToString(result)); \
        } \
        REALLY_INLINE GCRef<avmplus::String> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::String>(avmplus::AvmCore::atomToString(result)); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_StringClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_StringClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_StringClassSlots m_slots_StringClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Array$
//-----------------------------------------------------------
class avmplus_ArrayClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ArrayClass;
private:
    uint32_t m_CASEINSENSITIVE;
    uint32_t m_DESCENDING;
    uint32_t m_UNIQUESORT;
    uint32_t m_RETURNINDEXEDARRAY;
    uint32_t m_NUMERIC;
    int32_t m_length;
#define GC_TRIVIAL_TRACER_ArrayClass
};
#define DECLARE_SLOTS_ArrayClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::ArrayObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::ArrayObject>((avmplus::ArrayObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ArrayObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::ArrayObject>((avmplus::ArrayObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ArrayObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::ArrayObject>((avmplus::ArrayObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ArrayObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::ArrayObject>((avmplus::ArrayObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE uint32_t get_CASEINSENSITIVE() const { return m_slots_ArrayClass.m_CASEINSENSITIVE; } \
        REALLY_INLINE void setconst_CASEINSENSITIVE(uint32_t newVal) { m_slots_ArrayClass.m_CASEINSENSITIVE = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_DESCENDING() const { return m_slots_ArrayClass.m_DESCENDING; } \
        REALLY_INLINE void setconst_DESCENDING(uint32_t newVal) { m_slots_ArrayClass.m_DESCENDING = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_UNIQUESORT() const { return m_slots_ArrayClass.m_UNIQUESORT; } \
        REALLY_INLINE void setconst_UNIQUESORT(uint32_t newVal) { m_slots_ArrayClass.m_UNIQUESORT = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_RETURNINDEXEDARRAY() const { return m_slots_ArrayClass.m_RETURNINDEXEDARRAY; } \
        REALLY_INLINE void setconst_RETURNINDEXEDARRAY(uint32_t newVal) { m_slots_ArrayClass.m_RETURNINDEXEDARRAY = newVal; } \
    public: \
        REALLY_INLINE uint32_t get_NUMERIC() const { return m_slots_ArrayClass.m_NUMERIC; } \
        REALLY_INLINE void setconst_NUMERIC(uint32_t newVal) { m_slots_ArrayClass.m_NUMERIC = newVal; } \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_ArrayClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_ArrayClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_ArrayClassSlots m_slots_ArrayClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Array
//-----------------------------------------------------------
class avmplus_ArrayObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ArrayObject;
#define GC_TRIVIAL_TRACER_ArrayObject
};
#define DECLARE_SLOTS_ArrayObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector$
//-----------------------------------------------------------
class avmplus_VectorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::VectorClass;
#define GC_TRIVIAL_TRACER_VectorClass
};
#define DECLARE_SLOTS_VectorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::ObjectVectorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::ObjectVectorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ObjectVectorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ObjectVectorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ObjectVectorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector
//-----------------------------------------------------------
class avmplus_ObjectVectorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ObjectVectorObject;
#define GC_TRIVIAL_TRACER_ObjectVectorObject
};
#define DECLARE_SLOTS_ObjectVectorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector$object$
//-----------------------------------------------------------
class avmplus_ObjectVectorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ObjectVectorClass;
#define GC_TRIVIAL_TRACER_ObjectVectorClass
};
#define DECLARE_SLOTS_ObjectVectorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::ObjectVectorObject> constructObject(uint32_t arg1, bool arg2) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1), ((arg2) ? trueAtom : falseAtom) }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::ObjectVectorObject> constructObject(uint32_t arg1) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::ObjectVectorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::ObjectVectorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ObjectVectorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ObjectVectorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ObjectVectorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector$int$
//-----------------------------------------------------------
class avmplus_IntVectorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::IntVectorClass;
#define GC_TRIVIAL_TRACER_IntVectorClass
};
#define DECLARE_SLOTS_IntVectorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::IntVectorObject> constructObject(uint32_t arg1, bool arg2) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1), ((arg2) ? trueAtom : falseAtom) }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::IntVectorObject>((avmplus::IntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::IntVectorObject> constructObject(uint32_t arg1) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::IntVectorObject>((avmplus::IntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::IntVectorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::IntVectorObject>((avmplus::IntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::IntVectorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::IntVectorObject>((avmplus::IntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::IntVectorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::IntVectorObject>((avmplus::IntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::IntVectorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::IntVectorObject>((avmplus::IntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::IntVectorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::IntVectorObject>((avmplus::IntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector$int
//-----------------------------------------------------------
class avmplus_IntVectorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::IntVectorObject;
#define GC_TRIVIAL_TRACER_IntVectorObject
};
#define DECLARE_SLOTS_IntVectorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector$uint$
//-----------------------------------------------------------
class avmplus_UIntVectorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::UIntVectorClass;
#define GC_TRIVIAL_TRACER_UIntVectorClass
};
#define DECLARE_SLOTS_UIntVectorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::UIntVectorObject> constructObject(uint32_t arg1, bool arg2) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1), ((arg2) ? trueAtom : falseAtom) }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::UIntVectorObject>((avmplus::UIntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::UIntVectorObject> constructObject(uint32_t arg1) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::UIntVectorObject>((avmplus::UIntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::UIntVectorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::UIntVectorObject>((avmplus::UIntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::UIntVectorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::UIntVectorObject>((avmplus::UIntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::UIntVectorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::UIntVectorObject>((avmplus::UIntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::UIntVectorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::UIntVectorObject>((avmplus::UIntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::UIntVectorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::UIntVectorObject>((avmplus::UIntVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector$uint
//-----------------------------------------------------------
class avmplus_UIntVectorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::UIntVectorObject;
#define GC_TRIVIAL_TRACER_UIntVectorObject
};
#define DECLARE_SLOTS_UIntVectorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector$double$
//-----------------------------------------------------------
class avmplus_DoubleVectorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DoubleVectorClass;
#define GC_TRIVIAL_TRACER_DoubleVectorClass
};
#define DECLARE_SLOTS_DoubleVectorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::DoubleVectorObject> constructObject(uint32_t arg1, bool arg2) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1), ((arg2) ? trueAtom : falseAtom) }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::DoubleVectorObject>((avmplus::DoubleVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::DoubleVectorObject> constructObject(uint32_t arg1) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::DoubleVectorObject>((avmplus::DoubleVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::DoubleVectorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::DoubleVectorObject>((avmplus::DoubleVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::DoubleVectorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::DoubleVectorObject>((avmplus::DoubleVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DoubleVectorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::DoubleVectorObject>((avmplus::DoubleVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DoubleVectorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::DoubleVectorObject>((avmplus::DoubleVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DoubleVectorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::DoubleVectorObject>((avmplus::DoubleVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector$double
//-----------------------------------------------------------
class avmplus_DoubleVectorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DoubleVectorObject;
#define GC_TRIVIAL_TRACER_DoubleVectorObject
};
#define DECLARE_SLOTS_DoubleVectorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector$float$
//-----------------------------------------------------------
class avmplus_FloatVectorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::FloatVectorClass;
#define GC_TRIVIAL_TRACER_FloatVectorClass
};
#define DECLARE_SLOTS_FloatVectorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::FloatVectorObject> constructObject(uint32_t arg1, bool arg2) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1), ((arg2) ? trueAtom : falseAtom) }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::FloatVectorObject>((avmplus::FloatVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::FloatVectorObject> constructObject(uint32_t arg1) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::FloatVectorObject>((avmplus::FloatVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::FloatVectorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::FloatVectorObject>((avmplus::FloatVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::FloatVectorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::FloatVectorObject>((avmplus::FloatVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::FloatVectorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::FloatVectorObject>((avmplus::FloatVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::FloatVectorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::FloatVectorObject>((avmplus::FloatVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::FloatVectorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::FloatVectorObject>((avmplus::FloatVectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector$float
//-----------------------------------------------------------
class avmplus_FloatVectorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::FloatVectorObject;
#define GC_TRIVIAL_TRACER_FloatVectorObject
};
#define DECLARE_SLOTS_FloatVectorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector$float4$
//-----------------------------------------------------------
class avmplus_Float4VectorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::Float4VectorClass;
#define GC_TRIVIAL_TRACER_Float4VectorClass
};
#define DECLARE_SLOTS_Float4VectorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::Float4VectorObject> constructObject(uint32_t arg1, bool arg2) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1), ((arg2) ? trueAtom : falseAtom) }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::Float4VectorObject>((avmplus::Float4VectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::Float4VectorObject> constructObject(uint32_t arg1) \
        { \
            avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core())); \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::Float4VectorObject>((avmplus::Float4VectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::Float4VectorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::Float4VectorObject>((avmplus::Float4VectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::Float4VectorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::Float4VectorObject>((avmplus::Float4VectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::Float4VectorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::Float4VectorObject>((avmplus::Float4VectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::Float4VectorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::Float4VectorObject>((avmplus::Float4VectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::Float4VectorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::Float4VectorObject>((avmplus::Float4VectorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// __AS3__.vec::Vector$float4
//-----------------------------------------------------------
class avmplus_Float4VectorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::Float4VectorObject;
#define GC_TRIVIAL_TRACER_Float4VectorObject
};
#define DECLARE_SLOTS_Float4VectorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// private::MethodClosure$
//-----------------------------------------------------------
class avmplus_MethodClosureClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::MethodClosureClass;
#define GC_TRIVIAL_TRACER_MethodClosureClass
};
#define DECLARE_SLOTS_MethodClosureClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::MethodClosure> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::MethodClosure>((avmplus::MethodClosure*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::MethodClosure> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::MethodClosure>((avmplus::MethodClosure*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::MethodClosure> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::MethodClosure>((avmplus::MethodClosure*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::MethodClosure> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::MethodClosure>((avmplus::MethodClosure*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::MethodClosure> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::MethodClosure>((avmplus::MethodClosure*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// private::MethodClosure
//-----------------------------------------------------------
class avmplus_MethodClosureSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::MethodClosure;
#define GC_TRIVIAL_TRACER_MethodClosure
};
#define DECLARE_SLOTS_MethodClosure \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Math$
//-----------------------------------------------------------
class avmplus_MathClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::MathClass;
private:
    double m_E;
    double m_LN10;
    double m_LN2;
    double m_LOG10E;
    double m_LOG2E;
    double m_PI;
    double m_SQRT1_2;
    double m_SQRT2;
    double m_private_NegInfinity;
#define GC_TRIVIAL_TRACER_MathClass
};
#define DECLARE_SLOTS_MathClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<double> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<double>((double*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<double> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<double>((double*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<double> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<double>((double*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<double> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<double>((double*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE double get_E() const { return m_slots_MathClass.m_E; } \
        REALLY_INLINE void setconst_E(double newVal) { m_slots_MathClass.m_E = newVal; } \
    public: \
        REALLY_INLINE double get_LN10() const { return m_slots_MathClass.m_LN10; } \
        REALLY_INLINE void setconst_LN10(double newVal) { m_slots_MathClass.m_LN10 = newVal; } \
    public: \
        REALLY_INLINE double get_LN2() const { return m_slots_MathClass.m_LN2; } \
        REALLY_INLINE void setconst_LN2(double newVal) { m_slots_MathClass.m_LN2 = newVal; } \
    public: \
        REALLY_INLINE double get_LOG10E() const { return m_slots_MathClass.m_LOG10E; } \
        REALLY_INLINE void setconst_LOG10E(double newVal) { m_slots_MathClass.m_LOG10E = newVal; } \
    public: \
        REALLY_INLINE double get_LOG2E() const { return m_slots_MathClass.m_LOG2E; } \
        REALLY_INLINE void setconst_LOG2E(double newVal) { m_slots_MathClass.m_LOG2E = newVal; } \
    public: \
        REALLY_INLINE double get_PI() const { return m_slots_MathClass.m_PI; } \
        REALLY_INLINE void setconst_PI(double newVal) { m_slots_MathClass.m_PI = newVal; } \
    public: \
        REALLY_INLINE double get_SQRT1_2() const { return m_slots_MathClass.m_SQRT1_2; } \
        REALLY_INLINE void setconst_SQRT1_2(double newVal) { m_slots_MathClass.m_SQRT1_2 = newVal; } \
    public: \
        REALLY_INLINE double get_SQRT2() const { return m_slots_MathClass.m_SQRT2; } \
        REALLY_INLINE void setconst_SQRT2(double newVal) { m_slots_MathClass.m_SQRT2 = newVal; } \
    protected: \
        REALLY_INLINE double get_NegInfinity() const { return m_slots_MathClass.m_private_NegInfinity; } \
        REALLY_INLINE void setconst_NegInfinity(double newVal) { m_slots_MathClass.m_private_NegInfinity = newVal; } \
    private: \
        avmplus::NativeID::avmplus_MathClassSlots m_slots_MathClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Error$
//-----------------------------------------------------------
class avmplus_ErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ErrorClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_ErrorClass
};
#define DECLARE_SLOTS_ErrorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::ErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::ErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::ErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::ErrorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ErrorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ErrorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_ErrorClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_ErrorClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_ErrorClassSlots m_slots_ErrorClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Error
//-----------------------------------------------------------
class avmplus_ErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ErrorObject;
private:
    int32_t m_private__errorID;
    avmplus::AtomWB m_message;
    avmplus::AtomWB m_name;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceAtom(&m_message);
        gc->TraceAtom(&m_name);
    }
};
#define DECLARE_SLOTS_ErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get__errorID() const { return m_slots_ErrorObject.m_private__errorID; } \
        REALLY_INLINE void set__errorID(int32_t newVal) { m_slots_ErrorObject.m_private__errorID = newVal; } \
    public: \
        REALLY_INLINE avmplus::Atom get_message() const { return m_slots_ErrorObject.m_message; } \
        REALLY_INLINE void set_message(avmplus::Atom newVal) { m_slots_ErrorObject.m_message = newVal; } \
    public: \
        REALLY_INLINE avmplus::Atom get_name() const { return m_slots_ErrorObject.m_name; } \
        REALLY_INLINE void set_name(avmplus::Atom newVal) { m_slots_ErrorObject.m_name = newVal; } \
    private: \
        avmplus::NativeID::avmplus_ErrorObjectSlots m_slots_ErrorObject \

//-----------------------------------------------------------

//-----------------------------------------------------------
// DefinitionError$
//-----------------------------------------------------------
class avmplus_DefinitionErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DefinitionErrorClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_DefinitionErrorClass
};
#define DECLARE_SLOTS_DefinitionErrorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::DefinitionErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::DefinitionErrorObject>((avmplus::DefinitionErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::DefinitionErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::DefinitionErrorObject>((avmplus::DefinitionErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::DefinitionErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::DefinitionErrorObject>((avmplus::DefinitionErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::DefinitionErrorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::DefinitionErrorObject>((avmplus::DefinitionErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DefinitionErrorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::DefinitionErrorObject>((avmplus::DefinitionErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DefinitionErrorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::DefinitionErrorObject>((avmplus::DefinitionErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DefinitionErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::DefinitionErrorObject>((avmplus::DefinitionErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_DefinitionErrorClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_DefinitionErrorClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_DefinitionErrorClassSlots m_slots_DefinitionErrorClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// DefinitionError
//-----------------------------------------------------------
class avmplus_DefinitionErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DefinitionErrorObject;
#define GC_TRIVIAL_TRACER_DefinitionErrorObject
};
#define DECLARE_SLOTS_DefinitionErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// EvalError$
//-----------------------------------------------------------
class avmplus_EvalErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EvalErrorClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_EvalErrorClass
};
#define DECLARE_SLOTS_EvalErrorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::EvalErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::EvalErrorObject>((avmplus::EvalErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::EvalErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::EvalErrorObject>((avmplus::EvalErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::EvalErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::EvalErrorObject>((avmplus::EvalErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::EvalErrorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::EvalErrorObject>((avmplus::EvalErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::EvalErrorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::EvalErrorObject>((avmplus::EvalErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::EvalErrorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::EvalErrorObject>((avmplus::EvalErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::EvalErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::EvalErrorObject>((avmplus::EvalErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_EvalErrorClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_EvalErrorClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_EvalErrorClassSlots m_slots_EvalErrorClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// EvalError
//-----------------------------------------------------------
class avmplus_EvalErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EvalErrorObject;
#define GC_TRIVIAL_TRACER_EvalErrorObject
};
#define DECLARE_SLOTS_EvalErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// RangeError$
//-----------------------------------------------------------
class avmplus_RangeErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::RangeErrorClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_RangeErrorClass
};
#define DECLARE_SLOTS_RangeErrorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::RangeErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::RangeErrorObject>((avmplus::RangeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::RangeErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::RangeErrorObject>((avmplus::RangeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::RangeErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::RangeErrorObject>((avmplus::RangeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::RangeErrorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::RangeErrorObject>((avmplus::RangeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RangeErrorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::RangeErrorObject>((avmplus::RangeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RangeErrorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::RangeErrorObject>((avmplus::RangeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RangeErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::RangeErrorObject>((avmplus::RangeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_RangeErrorClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_RangeErrorClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_RangeErrorClassSlots m_slots_RangeErrorClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// RangeError
//-----------------------------------------------------------
class avmplus_RangeErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::RangeErrorObject;
#define GC_TRIVIAL_TRACER_RangeErrorObject
};
#define DECLARE_SLOTS_RangeErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// ReferenceError$
//-----------------------------------------------------------
class avmplus_ReferenceErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ReferenceErrorClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_ReferenceErrorClass
};
#define DECLARE_SLOTS_ReferenceErrorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::ReferenceErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::ReferenceErrorObject>((avmplus::ReferenceErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::ReferenceErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::ReferenceErrorObject>((avmplus::ReferenceErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::ReferenceErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ReferenceErrorObject>((avmplus::ReferenceErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::ReferenceErrorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::ReferenceErrorObject>((avmplus::ReferenceErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ReferenceErrorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::ReferenceErrorObject>((avmplus::ReferenceErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ReferenceErrorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::ReferenceErrorObject>((avmplus::ReferenceErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ReferenceErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::ReferenceErrorObject>((avmplus::ReferenceErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_ReferenceErrorClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_ReferenceErrorClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_ReferenceErrorClassSlots m_slots_ReferenceErrorClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// ReferenceError
//-----------------------------------------------------------
class avmplus_ReferenceErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ReferenceErrorObject;
#define GC_TRIVIAL_TRACER_ReferenceErrorObject
};
#define DECLARE_SLOTS_ReferenceErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// SecurityError$
//-----------------------------------------------------------
class avmplus_SecurityErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SecurityErrorClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_SecurityErrorClass
};
#define DECLARE_SLOTS_SecurityErrorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::SecurityErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::SecurityErrorObject>((avmplus::SecurityErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::SecurityErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::SecurityErrorObject>((avmplus::SecurityErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::SecurityErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::SecurityErrorObject>((avmplus::SecurityErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::SecurityErrorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::SecurityErrorObject>((avmplus::SecurityErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SecurityErrorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::SecurityErrorObject>((avmplus::SecurityErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SecurityErrorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::SecurityErrorObject>((avmplus::SecurityErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SecurityErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::SecurityErrorObject>((avmplus::SecurityErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_SecurityErrorClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_SecurityErrorClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_SecurityErrorClassSlots m_slots_SecurityErrorClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// SecurityError
//-----------------------------------------------------------
class avmplus_SecurityErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SecurityErrorObject;
#define GC_TRIVIAL_TRACER_SecurityErrorObject
};
#define DECLARE_SLOTS_SecurityErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// SyntaxError$
//-----------------------------------------------------------
class avmplus_SyntaxErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SyntaxErrorClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_SyntaxErrorClass
};
#define DECLARE_SLOTS_SyntaxErrorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::SyntaxErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::SyntaxErrorObject>((avmplus::SyntaxErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::SyntaxErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::SyntaxErrorObject>((avmplus::SyntaxErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::SyntaxErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::SyntaxErrorObject>((avmplus::SyntaxErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::SyntaxErrorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::SyntaxErrorObject>((avmplus::SyntaxErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SyntaxErrorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::SyntaxErrorObject>((avmplus::SyntaxErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SyntaxErrorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::SyntaxErrorObject>((avmplus::SyntaxErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SyntaxErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::SyntaxErrorObject>((avmplus::SyntaxErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_SyntaxErrorClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_SyntaxErrorClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_SyntaxErrorClassSlots m_slots_SyntaxErrorClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// SyntaxError
//-----------------------------------------------------------
class avmplus_SyntaxErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SyntaxErrorObject;
#define GC_TRIVIAL_TRACER_SyntaxErrorObject
};
#define DECLARE_SLOTS_SyntaxErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// TypeError$
//-----------------------------------------------------------
class avmplus_TypeErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::TypeErrorClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_TypeErrorClass
};
#define DECLARE_SLOTS_TypeErrorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::TypeErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::TypeErrorObject>((avmplus::TypeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::TypeErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::TypeErrorObject>((avmplus::TypeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::TypeErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::TypeErrorObject>((avmplus::TypeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::TypeErrorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::TypeErrorObject>((avmplus::TypeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::TypeErrorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::TypeErrorObject>((avmplus::TypeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::TypeErrorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::TypeErrorObject>((avmplus::TypeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::TypeErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::TypeErrorObject>((avmplus::TypeErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_TypeErrorClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_TypeErrorClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_TypeErrorClassSlots m_slots_TypeErrorClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// TypeError
//-----------------------------------------------------------
class avmplus_TypeErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::TypeErrorObject;
#define GC_TRIVIAL_TRACER_TypeErrorObject
};
#define DECLARE_SLOTS_TypeErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// URIError$
//-----------------------------------------------------------
class avmplus_URIErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::URIErrorClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_URIErrorClass
};
#define DECLARE_SLOTS_URIErrorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::URIErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::URIErrorObject>((avmplus::URIErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::URIErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::URIErrorObject>((avmplus::URIErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::URIErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::URIErrorObject>((avmplus::URIErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::URIErrorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::URIErrorObject>((avmplus::URIErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::URIErrorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::URIErrorObject>((avmplus::URIErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::URIErrorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::URIErrorObject>((avmplus::URIErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::URIErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::URIErrorObject>((avmplus::URIErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_URIErrorClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_URIErrorClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_URIErrorClassSlots m_slots_URIErrorClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// URIError
//-----------------------------------------------------------
class avmplus_URIErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::URIErrorObject;
#define GC_TRIVIAL_TRACER_URIErrorObject
};
#define DECLARE_SLOTS_URIErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// VerifyError$
//-----------------------------------------------------------
class avmplus_VerifyErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::VerifyErrorClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_VerifyErrorClass
};
#define DECLARE_SLOTS_VerifyErrorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::VerifyErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::VerifyErrorObject>((avmplus::VerifyErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::VerifyErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::VerifyErrorObject>((avmplus::VerifyErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::VerifyErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::VerifyErrorObject>((avmplus::VerifyErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::VerifyErrorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::VerifyErrorObject>((avmplus::VerifyErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::VerifyErrorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::VerifyErrorObject>((avmplus::VerifyErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::VerifyErrorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::VerifyErrorObject>((avmplus::VerifyErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::VerifyErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::VerifyErrorObject>((avmplus::VerifyErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_VerifyErrorClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_VerifyErrorClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_VerifyErrorClassSlots m_slots_VerifyErrorClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// VerifyError
//-----------------------------------------------------------
class avmplus_VerifyErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::VerifyErrorObject;
#define GC_TRIVIAL_TRACER_VerifyErrorObject
};
#define DECLARE_SLOTS_VerifyErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// UninitializedError$
//-----------------------------------------------------------
class avmplus_UninitializedErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::UninitializedErrorClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_UninitializedErrorClass
};
#define DECLARE_SLOTS_UninitializedErrorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::UninitializedErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::UninitializedErrorObject>((avmplus::UninitializedErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::UninitializedErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::UninitializedErrorObject>((avmplus::UninitializedErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::UninitializedErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::UninitializedErrorObject>((avmplus::UninitializedErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::UninitializedErrorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::UninitializedErrorObject>((avmplus::UninitializedErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::UninitializedErrorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::UninitializedErrorObject>((avmplus::UninitializedErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::UninitializedErrorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::UninitializedErrorObject>((avmplus::UninitializedErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::UninitializedErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::UninitializedErrorObject>((avmplus::UninitializedErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_UninitializedErrorClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_UninitializedErrorClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_UninitializedErrorClassSlots m_slots_UninitializedErrorClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// UninitializedError
//-----------------------------------------------------------
class avmplus_UninitializedErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::UninitializedErrorObject;
#define GC_TRIVIAL_TRACER_UninitializedErrorObject
};
#define DECLARE_SLOTS_UninitializedErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// ArgumentError$
//-----------------------------------------------------------
class avmplus_ArgumentErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ArgumentErrorClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_ArgumentErrorClass
};
#define DECLARE_SLOTS_ArgumentErrorClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::ArgumentErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::ArgumentErrorObject>((avmplus::ArgumentErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::ArgumentErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::ArgumentErrorObject>((avmplus::ArgumentErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::ArgumentErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ArgumentErrorObject>((avmplus::ArgumentErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::ArgumentErrorObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::ArgumentErrorObject>((avmplus::ArgumentErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ArgumentErrorObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::ArgumentErrorObject>((avmplus::ArgumentErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ArgumentErrorObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::ArgumentErrorObject>((avmplus::ArgumentErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ArgumentErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::ArgumentErrorObject>((avmplus::ArgumentErrorObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_ArgumentErrorClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_ArgumentErrorClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_ArgumentErrorClassSlots m_slots_ArgumentErrorClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// ArgumentError
//-----------------------------------------------------------
class avmplus_ArgumentErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ArgumentErrorObject;
#define GC_TRIVIAL_TRACER_ArgumentErrorObject
};
#define DECLARE_SLOTS_ArgumentErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::IOError$
//-----------------------------------------------------------
class avmplus_IOErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::IOErrorClass;
#define GC_TRIVIAL_TRACER_IOErrorClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::IOError
//-----------------------------------------------------------
class avmplus_IOErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::IOErrorObject;
#define GC_TRIVIAL_TRACER_IOErrorObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::MemoryError$
//-----------------------------------------------------------
class avmplus_MemoryErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::MemoryErrorClass;
#define GC_TRIVIAL_TRACER_MemoryErrorClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::MemoryError
//-----------------------------------------------------------
class avmplus_MemoryErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::MemoryErrorObject;
#define GC_TRIVIAL_TRACER_MemoryErrorObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::IllegalOperationError$
//-----------------------------------------------------------
class avmplus_IllegalOperationErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::IllegalOperationErrorClass;
#define GC_TRIVIAL_TRACER_IllegalOperationErrorClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::IllegalOperationError
//-----------------------------------------------------------
class avmplus_IllegalOperationErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::IllegalOperationErrorObject;
#define GC_TRIVIAL_TRACER_IllegalOperationErrorObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::EOFError$
//-----------------------------------------------------------
class avmplus_EOFErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EOFErrorClass;
#define GC_TRIVIAL_TRACER_EOFErrorClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::EOFError
//-----------------------------------------------------------
class avmplus_EOFErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EOFErrorObject;
#define GC_TRIVIAL_TRACER_EOFErrorObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// Date$
//-----------------------------------------------------------
class avmplus_DateClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DateClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_DateClass
};
#define DECLARE_SLOTS_DateClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2, avmplus::Atom arg3, avmplus::Atom arg4, avmplus::Atom arg5, avmplus::Atom arg6, avmplus::Atom arg7) \
        { \
            avmplus::Atom args[8] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2, arg3, arg4, arg5, arg6, arg7 }; \
            avmplus::Atom const result = this->construct(7, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2, avmplus::Atom arg3, avmplus::Atom arg4, avmplus::Atom arg5, avmplus::Atom arg6) \
        { \
            avmplus::Atom args[7] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2, arg3, arg4, arg5, arg6 }; \
            avmplus::Atom const result = this->construct(6, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2, avmplus::Atom arg3, avmplus::Atom arg4, avmplus::Atom arg5) \
        { \
            avmplus::Atom args[6] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2, arg3, arg4, arg5 }; \
            avmplus::Atom const result = this->construct(5, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2, avmplus::Atom arg3, avmplus::Atom arg4) \
        { \
            avmplus::Atom args[5] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2, arg3, arg4 }; \
            avmplus::Atom const result = this->construct(4, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2, avmplus::Atom arg3) \
        { \
            avmplus::Atom args[4] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2, arg3 }; \
            avmplus::Atom const result = this->construct(3, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::DateObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::DateObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DateObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DateObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DateObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_DateClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_DateClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_DateClassSlots m_slots_DateClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// Date
//-----------------------------------------------------------
class avmplus_DateObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DateObject;
#define GC_TRIVIAL_TRACER_DateObject
};
#define DECLARE_SLOTS_DateObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// RegExp$
//-----------------------------------------------------------
class avmplus_RegExpClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::RegExpClass;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_RegExpClass
};
#define DECLARE_SLOTS_RegExpClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::RegExpObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::RegExpObject>((avmplus::RegExpObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::RegExpObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::RegExpObject>((avmplus::RegExpObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::RegExpObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::RegExpObject>((avmplus::RegExpObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::RegExpObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::RegExpObject>((avmplus::RegExpObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RegExpObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::RegExpObject>((avmplus::RegExpObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RegExpObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::RegExpObject>((avmplus::RegExpObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RegExpObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::RegExpObject>((avmplus::RegExpObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_RegExpClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_RegExpClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_RegExpClassSlots m_slots_RegExpClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// RegExp
//-----------------------------------------------------------
class avmplus_RegExpObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::RegExpObject;
#define GC_TRIVIAL_TRACER_RegExpObject
};
#define DECLARE_SLOTS_RegExpObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// JSON$
//-----------------------------------------------------------
class avmplus_JSONClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::JSONClass;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::Namespace> m_private_as3ns;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_private_as3ns);
    }
};
#define DECLARE_SLOTS_JSONClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::JSONObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::JSONObject>((avmplus::JSONObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::JSONObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::JSONObject>((avmplus::JSONObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::JSONObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::JSONObject>((avmplus::JSONObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::JSONObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::JSONObject>((avmplus::JSONObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmplus::Namespace* get_as3ns() const { return m_slots_JSONClass.m_private_as3ns; } \
        REALLY_INLINE void setconst_as3ns(avmplus::Namespace* newVal) { m_slots_JSONClass.m_private_as3ns = newVal; } \
    private: \
        avmplus::NativeID::avmplus_JSONClassSlots m_slots_JSONClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// JSON
//-----------------------------------------------------------
class avmplus_JSONObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::JSONObject;
#define GC_TRIVIAL_TRACER_JSONObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// Walker$
//-----------------------------------------------------------
class avmplus_WalkerClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::WalkerClass;
#define GC_TRIVIAL_TRACER_WalkerClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// Walker
//-----------------------------------------------------------
class avmplus_WalkerObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::WalkerObject;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::FunctionObject> m_reviver;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_reviver);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// XML$
//-----------------------------------------------------------
class avmplus_XMLClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::XMLClass;
private:
    avmplus::AtomWB m_length;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceAtom(&m_length);
    }
};
#define DECLARE_SLOTS_XMLClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::XMLObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::XMLObject>((avmplus::XMLObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::XMLObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::XMLObject>((avmplus::XMLObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::XMLObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::XMLObject>((avmplus::XMLObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::XMLObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::XMLObject>((avmplus::XMLObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::XMLObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::XMLObject>((avmplus::XMLObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::XMLObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::XMLObject>((avmplus::XMLObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE avmplus::Atom get_length() const { return m_slots_XMLClass.m_length; } \
        REALLY_INLINE void setconst_length(avmplus::Atom newVal) { m_slots_XMLClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_XMLClassSlots m_slots_XMLClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// XML
//-----------------------------------------------------------
class avmplus_XMLObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::XMLObject;
#define GC_TRIVIAL_TRACER_XMLObject
};
#define DECLARE_SLOTS_XMLObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// XMLList$
//-----------------------------------------------------------
class avmplus_XMLListClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::XMLListClass;
private:
    avmplus::AtomWB m_length;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceAtom(&m_length);
    }
};
#define DECLARE_SLOTS_XMLListClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::XMLListObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::XMLListObject>((avmplus::XMLListObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::XMLListObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::XMLListObject>((avmplus::XMLListObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::XMLListObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::XMLListObject>((avmplus::XMLListObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::XMLListObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::XMLListObject>((avmplus::XMLListObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::XMLListObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::XMLListObject>((avmplus::XMLListObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::XMLListObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::XMLListObject>((avmplus::XMLListObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE avmplus::Atom get_length() const { return m_slots_XMLListClass.m_length; } \
        REALLY_INLINE void setconst_length(avmplus::Atom newVal) { m_slots_XMLListClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_XMLListClassSlots m_slots_XMLListClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// XMLList
//-----------------------------------------------------------
class avmplus_XMLListObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::XMLListObject;
#define GC_TRIVIAL_TRACER_XMLListObject
};
#define DECLARE_SLOTS_XMLListObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// QName$
//-----------------------------------------------------------
class avmplus_QNameClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::QNameClass;
private:
    avmplus::AtomWB m_length;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceAtom(&m_length);
    }
};
#define DECLARE_SLOTS_QNameClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::QNameObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::QNameObject>((avmplus::QNameObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::QNameObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::QNameObject>((avmplus::QNameObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        inline GCRef<avmplus::QNameObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::QNameObject>((avmplus::QNameObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::QNameObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::QNameObject>((avmplus::QNameObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::QNameObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::QNameObject>((avmplus::QNameObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::QNameObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::QNameObject>((avmplus::QNameObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::QNameObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::QNameObject>((avmplus::QNameObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE avmplus::Atom get_length() const { return m_slots_QNameClass.m_length; } \
        REALLY_INLINE void setconst_length(avmplus::Atom newVal) { m_slots_QNameClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_QNameClassSlots m_slots_QNameClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// QName
//-----------------------------------------------------------
class avmplus_QNameObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::QNameObject;
#define GC_TRIVIAL_TRACER_QNameObject
};
#define DECLARE_SLOTS_QNameObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::Proxy$
//-----------------------------------------------------------
class avmplus_ProxyClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ProxyClass;
#define GC_TRIVIAL_TRACER_ProxyClass
};
#define DECLARE_SLOTS_ProxyClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::ProxyObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ProxyObject>((avmplus::ProxyObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::ProxyObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::ProxyObject>((avmplus::ProxyObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ProxyObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::ProxyObject>((avmplus::ProxyObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ProxyObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::ProxyObject>((avmplus::ProxyObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ProxyObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::ProxyObject>((avmplus::ProxyObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::Proxy
//-----------------------------------------------------------
class avmplus_ProxyObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ProxyObject;
#define GC_TRIVIAL_TRACER_ProxyObject
};
#define DECLARE_SLOTS_ProxyObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// float$
//-----------------------------------------------------------
class avmplus_FloatClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::FloatClass;
private:
    float m_NaN;
    float m_NEGATIVE_INFINITY;
    float m_POSITIVE_INFINITY;
    float m_MIN_VALUE;
    float m_MAX_VALUE;
    float m_E;
    float m_LN10;
    float m_LN2;
    float m_LOG2E;
    float m_PI;
    float m_SQRT1_2;
    float m_SQRT2;
    int32_t m_private_DTOSTR_FIXED;
    int32_t m_private_DTOSTR_PRECISION;
    int32_t m_private_DTOSTR_EXPONENTIAL;
    int32_t m_length;
#define GC_TRIVIAL_TRACER_FloatClass
};
#define DECLARE_SLOTS_FloatClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE float asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return avmplus::AvmCore::singlePrecisionFloat(result); \
        } \
        REALLY_INLINE float asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return avmplus::AvmCore::singlePrecisionFloat(result); \
        } \
        REALLY_INLINE float coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return avmplus::AvmCore::singlePrecisionFloat(result); \
        } \
        REALLY_INLINE float coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return avmplus::AvmCore::singlePrecisionFloat(result); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE float get_NaN() const { return m_slots_FloatClass.m_NaN; } \
        REALLY_INLINE void setconst_NaN(float newVal) { m_slots_FloatClass.m_NaN = newVal; } \
    public: \
        REALLY_INLINE float get_NEGATIVE_INFINITY() const { return m_slots_FloatClass.m_NEGATIVE_INFINITY; } \
        REALLY_INLINE void setconst_NEGATIVE_INFINITY(float newVal) { m_slots_FloatClass.m_NEGATIVE_INFINITY = newVal; } \
    public: \
        REALLY_INLINE float get_POSITIVE_INFINITY() const { return m_slots_FloatClass.m_POSITIVE_INFINITY; } \
        REALLY_INLINE void setconst_POSITIVE_INFINITY(float newVal) { m_slots_FloatClass.m_POSITIVE_INFINITY = newVal; } \
    public: \
        REALLY_INLINE float get_MIN_VALUE() const { return m_slots_FloatClass.m_MIN_VALUE; } \
        REALLY_INLINE void setconst_MIN_VALUE(float newVal) { m_slots_FloatClass.m_MIN_VALUE = newVal; } \
    public: \
        REALLY_INLINE float get_MAX_VALUE() const { return m_slots_FloatClass.m_MAX_VALUE; } \
        REALLY_INLINE void setconst_MAX_VALUE(float newVal) { m_slots_FloatClass.m_MAX_VALUE = newVal; } \
    public: \
        REALLY_INLINE float get_E() const { return m_slots_FloatClass.m_E; } \
        REALLY_INLINE void setconst_E(float newVal) { m_slots_FloatClass.m_E = newVal; } \
    public: \
        REALLY_INLINE float get_LN10() const { return m_slots_FloatClass.m_LN10; } \
        REALLY_INLINE void setconst_LN10(float newVal) { m_slots_FloatClass.m_LN10 = newVal; } \
    public: \
        REALLY_INLINE float get_LN2() const { return m_slots_FloatClass.m_LN2; } \
        REALLY_INLINE void setconst_LN2(float newVal) { m_slots_FloatClass.m_LN2 = newVal; } \
    public: \
        REALLY_INLINE float get_LOG2E() const { return m_slots_FloatClass.m_LOG2E; } \
        REALLY_INLINE void setconst_LOG2E(float newVal) { m_slots_FloatClass.m_LOG2E = newVal; } \
    public: \
        REALLY_INLINE float get_PI() const { return m_slots_FloatClass.m_PI; } \
        REALLY_INLINE void setconst_PI(float newVal) { m_slots_FloatClass.m_PI = newVal; } \
    public: \
        REALLY_INLINE float get_SQRT1_2() const { return m_slots_FloatClass.m_SQRT1_2; } \
        REALLY_INLINE void setconst_SQRT1_2(float newVal) { m_slots_FloatClass.m_SQRT1_2 = newVal; } \
    public: \
        REALLY_INLINE float get_SQRT2() const { return m_slots_FloatClass.m_SQRT2; } \
        REALLY_INLINE void setconst_SQRT2(float newVal) { m_slots_FloatClass.m_SQRT2 = newVal; } \
    protected: \
        REALLY_INLINE int32_t get_DTOSTR_FIXED() const { return m_slots_FloatClass.m_private_DTOSTR_FIXED; } \
        REALLY_INLINE void setconst_DTOSTR_FIXED(int32_t newVal) { m_slots_FloatClass.m_private_DTOSTR_FIXED = newVal; } \
    protected: \
        REALLY_INLINE int32_t get_DTOSTR_PRECISION() const { return m_slots_FloatClass.m_private_DTOSTR_PRECISION; } \
        REALLY_INLINE void setconst_DTOSTR_PRECISION(int32_t newVal) { m_slots_FloatClass.m_private_DTOSTR_PRECISION = newVal; } \
    protected: \
        REALLY_INLINE int32_t get_DTOSTR_EXPONENTIAL() const { return m_slots_FloatClass.m_private_DTOSTR_EXPONENTIAL; } \
        REALLY_INLINE void setconst_DTOSTR_EXPONENTIAL(int32_t newVal) { m_slots_FloatClass.m_private_DTOSTR_EXPONENTIAL = newVal; } \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_FloatClass.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_FloatClass.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_FloatClassSlots m_slots_FloatClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// float4$
//-----------------------------------------------------------
class avmplus_Float4ClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::Float4Class;
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_Float4Class
};
#define DECLARE_SLOTS_Float4Class \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE float4_t asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return avmplus::AvmCore::float4(result); \
        } \
        REALLY_INLINE float4_t asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return avmplus::AvmCore::float4(result); \
        } \
        REALLY_INLINE float4_t coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return avmplus::AvmCore::float4(result); \
        } \
        REALLY_INLINE float4_t coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return avmplus::AvmCore::float4(result); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_Float4Class.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_Float4Class.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_Float4ClassSlots m_slots_Float4Class \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::CompressionAlgorithm$
//-----------------------------------------------------------
class avmplus_CompressionAlgorithmClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CompressionAlgorithmClass;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_ZLIB;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_DEFLATE;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_ZLIB);
        gc->TraceLocation(&m_DEFLATE);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::CompressionAlgorithm
//-----------------------------------------------------------
class avmplus_CompressionAlgorithmObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CompressionAlgorithmObject;
#define GC_TRIVIAL_TRACER_CompressionAlgorithmObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::ByteArray$
//-----------------------------------------------------------
class avmplus_ByteArrayClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ByteArrayClass;
private:
    uint32_t m_private__defaultObjectEncoding;
#define GC_TRIVIAL_TRACER_ByteArrayClass
};
#define DECLARE_SLOTS_ByteArrayClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::ByteArrayObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ByteArrayObject>((avmplus::ByteArrayObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::ByteArrayObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::ByteArrayObject>((avmplus::ByteArrayObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ByteArrayObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::ByteArrayObject>((avmplus::ByteArrayObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ByteArrayObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::ByteArrayObject>((avmplus::ByteArrayObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ByteArrayObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::ByteArrayObject>((avmplus::ByteArrayObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE uint32_t get__defaultObjectEncoding() const { return m_slots_ByteArrayClass.m_private__defaultObjectEncoding; } \
        REALLY_INLINE void set__defaultObjectEncoding(uint32_t newVal) { m_slots_ByteArrayClass.m_private__defaultObjectEncoding = newVal; } \
    private: \
        avmplus::NativeID::avmplus_ByteArrayClassSlots m_slots_ByteArrayClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::ByteArray
//-----------------------------------------------------------
class avmplus_ByteArrayObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ByteArrayObject;
#define GC_TRIVIAL_TRACER_ByteArrayObject
};
#define DECLARE_SLOTS_ByteArrayObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE GCRef<avmplus::IDataInputInterface> as_IDataInputInterface() \
        { \
            return GCRef<avmplus::IDataInputInterface>((avmplus::IDataInputInterface*)this); \
        } \
        REALLY_INLINE GCRef<avmplus::IDataOutputInterface> as_IDataOutputInterface() \
        { \
            return GCRef<avmplus::IDataOutputInterface>((avmplus::IDataOutputInterface*)this); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

} }
namespace avmplus {

class builtinClassManifest : public avmplus::ClassManifestBase
{
    friend class avmplus::AvmCore;
    friend class avmplus::IntVectorClass;
    friend class avmplus::UIntVectorClass;
    FLOAT_ONLY(friend class avmplus::FloatVectorClass;)
    FLOAT_ONLY(friend class avmplus::Float4VectorClass;)
    friend class avmplus::DoubleVectorClass;
    friend class avmplus::ObjectVectorClass;
private:
    REALLY_INLINE builtinClassManifest(avmplus::ScriptEnv* e) : ClassManifestBase(49, e) { }
    REALLY_INLINE static builtinClassManifest* create(avmplus::ScriptEnv* e) { return new (MMgc::GC::GetGC(e), MMgc::kExact, sizeof(ClassClosure*)*48) builtinClassManifest(e); }
public:
    REALLY_INLINE GCRef<avmplus::ArgumentErrorClass> get_ArgumentErrorClass() { return (avmplus::ArgumentErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_ArgumentError)); }
    REALLY_INLINE GCRef<avmplus::ArrayClass> get_ArrayClass() { return (avmplus::ArrayClass*)(lazyInitClass(avmplus::NativeID::abcclass_Array)); }
    REALLY_INLINE GCRef<avmplus::BooleanClass> get_BooleanClass() { return (avmplus::BooleanClass*)(lazyInitClass(avmplus::NativeID::abcclass_Boolean)); }
    REALLY_INLINE GCRef<avmplus::ByteArrayClass> get_ByteArrayClass() { return (avmplus::ByteArrayClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_utils_ByteArray)); }
    REALLY_INLINE GCRef<avmplus::ClassClass> get_ClassClass() { return (avmplus::ClassClass*)(lazyInitClass(avmplus::NativeID::abcclass_Class)); }
    REALLY_INLINE GCRef<avmplus::CompressionAlgorithmClass> get_CompressionAlgorithmClass() { return (avmplus::CompressionAlgorithmClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_utils_CompressionAlgorithm)); }
    REALLY_INLINE GCRef<avmplus::DateClass> get_DateClass() { return (avmplus::DateClass*)(lazyInitClass(avmplus::NativeID::abcclass_Date)); }
    REALLY_INLINE GCRef<avmplus::DefinitionErrorClass> get_DefinitionErrorClass() { return (avmplus::DefinitionErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_DefinitionError)); }
    REALLY_INLINE GCRef<avmplus::EOFErrorClass> get_EOFErrorClass() { return (avmplus::EOFErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_errors_EOFError)); }
    REALLY_INLINE GCRef<avmplus::ErrorClass> get_ErrorClass() { return (avmplus::ErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_Error)); }
    REALLY_INLINE GCRef<avmplus::EvalErrorClass> get_EvalErrorClass() { return (avmplus::EvalErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_EvalError)); }
    REALLY_INLINE GCRef<avmplus::FunctionClass> get_FunctionClass() { return (avmplus::FunctionClass*)(lazyInitClass(avmplus::NativeID::abcclass_Function)); }
    REALLY_INLINE GCRef<avmplus::IDataInputClass> get_IDataInputClass() { return (avmplus::IDataInputClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_utils_IDataInput)); }
    REALLY_INLINE GCRef<avmplus::IDataOutputClass> get_IDataOutputClass() { return (avmplus::IDataOutputClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_utils_IDataOutput)); }
    REALLY_INLINE GCRef<avmplus::IOErrorClass> get_IOErrorClass() { return (avmplus::IOErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_errors_IOError)); }
    REALLY_INLINE GCRef<avmplus::IllegalOperationErrorClass> get_IllegalOperationErrorClass() { return (avmplus::IllegalOperationErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_errors_IllegalOperationError)); }
    REALLY_INLINE GCRef<avmplus::JSONClass> get_JSONClass() { return (avmplus::JSONClass*)(lazyInitClass(avmplus::NativeID::abcclass_JSON)); }
    REALLY_INLINE GCRef<avmplus::MathClass> get_MathClass() { return (avmplus::MathClass*)(lazyInitClass(avmplus::NativeID::abcclass_Math)); }
    REALLY_INLINE GCRef<avmplus::MemoryErrorClass> get_MemoryErrorClass() { return (avmplus::MemoryErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_errors_MemoryError)); }
    REALLY_INLINE GCRef<avmplus::MethodClosureClass> get_MethodClosureClass() { return (avmplus::MethodClosureClass*)(lazyInitClass(avmplus::NativeID::abcclass_private_MethodClosure)); }
    REALLY_INLINE GCRef<avmplus::NamespaceClass> get_NamespaceClass() { return (avmplus::NamespaceClass*)(lazyInitClass(avmplus::NativeID::abcclass_Namespace)); }
    REALLY_INLINE GCRef<avmplus::NumberClass> get_NumberClass() { return (avmplus::NumberClass*)(lazyInitClass(avmplus::NativeID::abcclass_Number)); }
    REALLY_INLINE GCRef<avmplus::ObjectClass> get_ObjectClass() { return (avmplus::ObjectClass*)(lazyInitClass(avmplus::NativeID::abcclass_Object)); }
    REALLY_INLINE GCRef<avmplus::ProxyClass> get_ProxyClass() { return (avmplus::ProxyClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_utils_Proxy)); }
    REALLY_INLINE GCRef<avmplus::QNameClass> get_QNameClass() { return (avmplus::QNameClass*)(lazyInitClass(avmplus::NativeID::abcclass_QName)); }
    REALLY_INLINE GCRef<avmplus::RangeErrorClass> get_RangeErrorClass() { return (avmplus::RangeErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_RangeError)); }
    REALLY_INLINE GCRef<avmplus::ReferenceErrorClass> get_ReferenceErrorClass() { return (avmplus::ReferenceErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_ReferenceError)); }
    REALLY_INLINE GCRef<avmplus::RegExpClass> get_RegExpClass() { return (avmplus::RegExpClass*)(lazyInitClass(avmplus::NativeID::abcclass_RegExp)); }
    REALLY_INLINE GCRef<avmplus::SecurityErrorClass> get_SecurityErrorClass() { return (avmplus::SecurityErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_SecurityError)); }
    REALLY_INLINE GCRef<avmplus::StringClass> get_StringClass() { return (avmplus::StringClass*)(lazyInitClass(avmplus::NativeID::abcclass_String)); }
    REALLY_INLINE GCRef<avmplus::SyntaxErrorClass> get_SyntaxErrorClass() { return (avmplus::SyntaxErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_SyntaxError)); }
    REALLY_INLINE GCRef<avmplus::TypeErrorClass> get_TypeErrorClass() { return (avmplus::TypeErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_TypeError)); }
    REALLY_INLINE GCRef<avmplus::URIErrorClass> get_URIErrorClass() { return (avmplus::URIErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_URIError)); }
    REALLY_INLINE GCRef<avmplus::UninitializedErrorClass> get_UninitializedErrorClass() { return (avmplus::UninitializedErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_UninitializedError)); }
    REALLY_INLINE GCRef<avmplus::VectorClass> get_VectorClass() { return (avmplus::VectorClass*)(lazyInitClass(avmplus::NativeID::abcclass___AS3___vec_Vector)); }
    REALLY_INLINE GCRef<avmplus::DoubleVectorClass> get_Vector_doubleClass() { return (avmplus::DoubleVectorClass*)(lazyInitClass(avmplus::NativeID::abcclass___AS3___vec_Vector_double)); }
    REALLY_INLINE GCRef<avmplus::Float4VectorClass> get_Vector_float4Class() { return (avmplus::Float4VectorClass*)(lazyInitClass(avmplus::NativeID::abcclass___AS3___vec_Vector_float4)); }
    REALLY_INLINE GCRef<avmplus::FloatVectorClass> get_Vector_floatClass() { return (avmplus::FloatVectorClass*)(lazyInitClass(avmplus::NativeID::abcclass___AS3___vec_Vector_float)); }
    REALLY_INLINE GCRef<avmplus::IntVectorClass> get_Vector_intClass() { return (avmplus::IntVectorClass*)(lazyInitClass(avmplus::NativeID::abcclass___AS3___vec_Vector_int)); }
    REALLY_INLINE GCRef<avmplus::ObjectVectorClass> get_Vector_objectClass() { return (avmplus::ObjectVectorClass*)(lazyInitClass(avmplus::NativeID::abcclass___AS3___vec_Vector_object)); }
    REALLY_INLINE GCRef<avmplus::UIntVectorClass> get_Vector_uintClass() { return (avmplus::UIntVectorClass*)(lazyInitClass(avmplus::NativeID::abcclass___AS3___vec_Vector_uint)); }
    REALLY_INLINE GCRef<avmplus::VerifyErrorClass> get_VerifyErrorClass() { return (avmplus::VerifyErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_VerifyError)); }
    REALLY_INLINE GCRef<avmplus::WalkerClass> get_WalkerClass() { return (avmplus::WalkerClass*)(lazyInitClass(avmplus::NativeID::abcclass_Walker)); }
    REALLY_INLINE GCRef<avmplus::XMLClass> get_XMLClass() { return (avmplus::XMLClass*)(lazyInitClass(avmplus::NativeID::abcclass_XML)); }
    REALLY_INLINE GCRef<avmplus::XMLListClass> get_XMLListClass() { return (avmplus::XMLListClass*)(lazyInitClass(avmplus::NativeID::abcclass_XMLList)); }
    REALLY_INLINE GCRef<avmplus::Float4Class> get_float4Class() { return (avmplus::Float4Class*)(lazyInitClass(avmplus::NativeID::abcclass_float4)); }
    REALLY_INLINE GCRef<avmplus::FloatClass> get_floatClass() { return (avmplus::FloatClass*)(lazyInitClass(avmplus::NativeID::abcclass_float)); }
    REALLY_INLINE GCRef<avmplus::IntClass> get_intClass() { return (avmplus::IntClass*)(lazyInitClass(avmplus::NativeID::abcclass_int)); }
    REALLY_INLINE GCRef<avmplus::UIntClass> get_uintClass() { return (avmplus::UIntClass*)(lazyInitClass(avmplus::NativeID::abcclass_uint)); }
};
}
#endif // _H_nativegen_header_builtin
