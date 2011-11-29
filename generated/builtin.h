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
const uint32_t abcclass_float = 8;
const uint32_t abcclass_float4 = 9;
const uint32_t abcclass_String = 10;
const uint32_t abcclass_Array = 11;
const uint32_t abcclass___AS3___vec_Vector = 12;
const uint32_t abcclass___AS3___vec_Vector_object = 13;
const uint32_t abcclass___AS3___vec_Vector_int = 14;
const uint32_t abcclass___AS3___vec_Vector_uint = 15;
const uint32_t abcclass___AS3___vec_Vector_double = 16;
const uint32_t abcclass___AS3___vec_Vector_float = 17;
const uint32_t abcclass___AS3___vec_Vector_float4 = 18;
const uint32_t abcclass_private_MethodClosure = 19;
const uint32_t abcclass_Math = 20;
const uint32_t abcclass_Error = 21;
const uint32_t abcclass_DefinitionError = 22;
const uint32_t abcclass_EvalError = 23;
const uint32_t abcclass_RangeError = 24;
const uint32_t abcclass_ReferenceError = 25;
const uint32_t abcclass_SecurityError = 26;
const uint32_t abcclass_SyntaxError = 27;
const uint32_t abcclass_TypeError = 28;
const uint32_t abcclass_URIError = 29;
const uint32_t abcclass_VerifyError = 30;
const uint32_t abcclass_UninitializedError = 31;
const uint32_t abcclass_ArgumentError = 32;
const uint32_t abcclass_flash_errors_IOError = 33;
const uint32_t abcclass_flash_errors_MemoryError = 34;
const uint32_t abcclass_flash_errors_IllegalOperationError = 35;
const uint32_t abcclass_flash_errors_EOFError = 36;
const uint32_t abcclass_Date = 37;
const uint32_t abcclass_RegExp = 38;
const uint32_t abcclass_JSON = 39;
const uint32_t abcclass_Walker = 40;
const uint32_t abcclass_XML = 41;
const uint32_t abcclass_XMLList = 42;
const uint32_t abcclass_QName = 43;
const uint32_t abcclass_flash_utils_IDataInput = 44;
const uint32_t abcclass_flash_utils_IDataOutput = 45;
const uint32_t abcclass_flash_utils_Proxy = 46;
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
const uint32_t Number_abs = 74; // native
const uint32_t Number_acos = 75; // native
const uint32_t Number_asin = 76; // native
const uint32_t Number_atan = 77; // native
const uint32_t Number_ceil = 78; // native
const uint32_t Number_cos = 79; // native
const uint32_t Number_exp = 80; // native
const uint32_t Number_floor = 81; // native
const uint32_t Number_log = 82; // native
const uint32_t Number_round = 83; // native
const uint32_t Number_sin = 84; // native
const uint32_t Number_sqrt = 85; // native
const uint32_t Number_tan = 86; // native
const uint32_t Number_atan2 = 87; // native
const uint32_t Number_pow = 88; // native
const uint32_t Number_max = 89; // native
const uint32_t Number_min = 90; // native
const uint32_t Number_random = 91; // native
const uint32_t Number_private__numberToString = 92; // native
const uint32_t Number_private__convert = 93; // native
const uint32_t Number_private__minValue = 94; // native
const uint32_t Number_AS3_toString = 95; // abc
const uint32_t Number_AS3_valueOf = 96; // abc
const uint32_t Number_AS3_toExponential = 97; // abc
const uint32_t Number_AS3_toPrecision = 98; // abc
const uint32_t Number_AS3_toFixed = 99; // abc
const uint32_t int_AS3_toString = 107; // abc
const uint32_t int_AS3_valueOf = 108; // abc
const uint32_t int_AS3_toExponential = 109; // abc
const uint32_t int_AS3_toPrecision = 110; // abc
const uint32_t int_AS3_toFixed = 111; // abc
const uint32_t uint_AS3_toString = 119; // abc
const uint32_t uint_AS3_valueOf = 120; // abc
const uint32_t uint_AS3_toExponential = 121; // abc
const uint32_t uint_AS3_toPrecision = 122; // abc
const uint32_t uint_AS3_toFixed = 123; // abc
const uint32_t float_abs = 131; // native
const uint32_t float_acos = 132; // native
const uint32_t float_asin = 133; // native
const uint32_t float_atan = 134; // native
const uint32_t float_atan2 = 135; // native
const uint32_t float_ceil = 136; // native
const uint32_t float_cos = 137; // native
const uint32_t float_exp = 138; // native
const uint32_t float_floor = 139; // native
const uint32_t float_log = 140; // native
const uint32_t float_pow = 141; // native
const uint32_t float_random = 142; // native
const uint32_t float_round = 143; // native
const uint32_t float_sin = 144; // native
const uint32_t float_sqrt = 145; // native
const uint32_t float_tan = 146; // native
const uint32_t float_reciprocal = 147; // native
const uint32_t float_rsqrt = 148; // native
const uint32_t float_max = 149; // abc
const uint32_t float_min = 150; // abc
const uint32_t float_private__minValue = 151; // native
const uint32_t float_private__floatToString = 152; // native
const uint32_t float_private__convert = 153; // native
const uint32_t float_AS3_toString = 154; // abc
const uint32_t float_AS3_valueOf = 155; // abc
const uint32_t float_AS3_toExponential = 156; // abc
const uint32_t float_AS3_toPrecision = 157; // abc
const uint32_t float_AS3_toFixed = 158; // abc
const uint32_t float4_isGreater = 163; // native
const uint32_t float4_isGreaterOrEqual = 164; // native
const uint32_t float4_isLess = 165; // native
const uint32_t float4_isLessOrEqual = 166; // native
const uint32_t float4_isEqual = 167; // native
const uint32_t float4_isNotEqual = 168; // native
const uint32_t float4_abs = 169; // native
const uint32_t float4_max = 170; // native
const uint32_t float4_min = 171; // native
const uint32_t float4_reciprocal = 172; // native
const uint32_t float4_rsqrt = 173; // native
const uint32_t float4_sqrt = 174; // native
const uint32_t float4_normalize = 175; // native
const uint32_t float4_cross = 176; // native
const uint32_t float4_dot = 177; // native
const uint32_t float4_dot2 = 178; // native
const uint32_t float4_dot3 = 179; // native
const uint32_t float4_magnitude = 180; // native
const uint32_t float4_magnitude3 = 181; // native
const uint32_t float4_magnitude2 = 182; // native
const uint32_t float4_distance = 183; // native
const uint32_t float4_distance3 = 184; // native
const uint32_t float4_distance2 = 185; // native
const uint32_t float4_private__swizzle = 186; // native
const uint32_t float4_all_get = 188; // abc
const uint32_t float4_any_get = 189; // abc
const uint32_t float4_none_get = 190; // abc
const uint32_t float4_x_get = 191; // native
const uint32_t float4_y_get = 192; // native
const uint32_t float4_z_get = 193; // native
const uint32_t float4_w_get = 194; // native
const uint32_t float4_xxxx_get = 195; // abc
const uint32_t float4_xxxy_get = 196; // abc
const uint32_t float4_xxxz_get = 197; // abc
const uint32_t float4_xxxw_get = 198; // abc
const uint32_t float4_xxyx_get = 199; // abc
const uint32_t float4_xxyy_get = 200; // abc
const uint32_t float4_xxyz_get = 201; // abc
const uint32_t float4_xxyw_get = 202; // abc
const uint32_t float4_xxzx_get = 203; // abc
const uint32_t float4_xxzy_get = 204; // abc
const uint32_t float4_xxzz_get = 205; // abc
const uint32_t float4_xxzw_get = 206; // abc
const uint32_t float4_xxwx_get = 207; // abc
const uint32_t float4_xxwy_get = 208; // abc
const uint32_t float4_xxwz_get = 209; // abc
const uint32_t float4_xxww_get = 210; // abc
const uint32_t float4_xyxx_get = 211; // abc
const uint32_t float4_xyxy_get = 212; // abc
const uint32_t float4_xyxz_get = 213; // abc
const uint32_t float4_xyxw_get = 214; // abc
const uint32_t float4_xyyx_get = 215; // abc
const uint32_t float4_xyyy_get = 216; // abc
const uint32_t float4_xyyz_get = 217; // abc
const uint32_t float4_xyyw_get = 218; // abc
const uint32_t float4_xyzx_get = 219; // abc
const uint32_t float4_xyzy_get = 220; // abc
const uint32_t float4_xyzz_get = 221; // abc
const uint32_t float4_xyzw_get = 222; // abc
const uint32_t float4_xywx_get = 223; // abc
const uint32_t float4_xywy_get = 224; // abc
const uint32_t float4_xywz_get = 225; // abc
const uint32_t float4_xyww_get = 226; // abc
const uint32_t float4_xzxx_get = 227; // abc
const uint32_t float4_xzxy_get = 228; // abc
const uint32_t float4_xzxz_get = 229; // abc
const uint32_t float4_xzxw_get = 230; // abc
const uint32_t float4_xzyx_get = 231; // abc
const uint32_t float4_xzyy_get = 232; // abc
const uint32_t float4_xzyz_get = 233; // abc
const uint32_t float4_xzyw_get = 234; // abc
const uint32_t float4_xzzx_get = 235; // abc
const uint32_t float4_xzzy_get = 236; // abc
const uint32_t float4_xzzz_get = 237; // abc
const uint32_t float4_xzzw_get = 238; // abc
const uint32_t float4_xzwx_get = 239; // abc
const uint32_t float4_xzwy_get = 240; // abc
const uint32_t float4_xzwz_get = 241; // abc
const uint32_t float4_xzww_get = 242; // abc
const uint32_t float4_xwxx_get = 243; // abc
const uint32_t float4_xwxy_get = 244; // abc
const uint32_t float4_xwxz_get = 245; // abc
const uint32_t float4_xwxw_get = 246; // abc
const uint32_t float4_xwyx_get = 247; // abc
const uint32_t float4_xwyy_get = 248; // abc
const uint32_t float4_xwyz_get = 249; // abc
const uint32_t float4_xwyw_get = 250; // abc
const uint32_t float4_xwzx_get = 251; // abc
const uint32_t float4_xwzy_get = 252; // abc
const uint32_t float4_xwzz_get = 253; // abc
const uint32_t float4_xwzw_get = 254; // abc
const uint32_t float4_xwwx_get = 255; // abc
const uint32_t float4_xwwy_get = 256; // abc
const uint32_t float4_xwwz_get = 257; // abc
const uint32_t float4_xwww_get = 258; // abc
const uint32_t float4_yxxx_get = 259; // abc
const uint32_t float4_yxxy_get = 260; // abc
const uint32_t float4_yxxz_get = 261; // abc
const uint32_t float4_yxxw_get = 262; // abc
const uint32_t float4_yxyx_get = 263; // abc
const uint32_t float4_yxyy_get = 264; // abc
const uint32_t float4_yxyz_get = 265; // abc
const uint32_t float4_yxyw_get = 266; // abc
const uint32_t float4_yxzx_get = 267; // abc
const uint32_t float4_yxzy_get = 268; // abc
const uint32_t float4_yxzz_get = 269; // abc
const uint32_t float4_yxzw_get = 270; // abc
const uint32_t float4_yxwx_get = 271; // abc
const uint32_t float4_yxwy_get = 272; // abc
const uint32_t float4_yxwz_get = 273; // abc
const uint32_t float4_yxww_get = 274; // abc
const uint32_t float4_yyxx_get = 275; // abc
const uint32_t float4_yyxy_get = 276; // abc
const uint32_t float4_yyxz_get = 277; // abc
const uint32_t float4_yyxw_get = 278; // abc
const uint32_t float4_yyyx_get = 279; // abc
const uint32_t float4_yyyy_get = 280; // abc
const uint32_t float4_yyyz_get = 281; // abc
const uint32_t float4_yyyw_get = 282; // abc
const uint32_t float4_yyzx_get = 283; // abc
const uint32_t float4_yyzy_get = 284; // abc
const uint32_t float4_yyzz_get = 285; // abc
const uint32_t float4_yyzw_get = 286; // abc
const uint32_t float4_yywx_get = 287; // abc
const uint32_t float4_yywy_get = 288; // abc
const uint32_t float4_yywz_get = 289; // abc
const uint32_t float4_yyww_get = 290; // abc
const uint32_t float4_yzxx_get = 291; // abc
const uint32_t float4_yzxy_get = 292; // abc
const uint32_t float4_yzxz_get = 293; // abc
const uint32_t float4_yzxw_get = 294; // abc
const uint32_t float4_yzyx_get = 295; // abc
const uint32_t float4_yzyy_get = 296; // abc
const uint32_t float4_yzyz_get = 297; // abc
const uint32_t float4_yzyw_get = 298; // abc
const uint32_t float4_yzzx_get = 299; // abc
const uint32_t float4_yzzy_get = 300; // abc
const uint32_t float4_yzzz_get = 301; // abc
const uint32_t float4_yzzw_get = 302; // abc
const uint32_t float4_yzwx_get = 303; // abc
const uint32_t float4_yzwy_get = 304; // abc
const uint32_t float4_yzwz_get = 305; // abc
const uint32_t float4_yzww_get = 306; // abc
const uint32_t float4_ywxx_get = 307; // abc
const uint32_t float4_ywxy_get = 308; // abc
const uint32_t float4_ywxz_get = 309; // abc
const uint32_t float4_ywxw_get = 310; // abc
const uint32_t float4_ywyx_get = 311; // abc
const uint32_t float4_ywyy_get = 312; // abc
const uint32_t float4_ywyz_get = 313; // abc
const uint32_t float4_ywyw_get = 314; // abc
const uint32_t float4_ywzx_get = 315; // abc
const uint32_t float4_ywzy_get = 316; // abc
const uint32_t float4_ywzz_get = 317; // abc
const uint32_t float4_ywzw_get = 318; // abc
const uint32_t float4_ywwx_get = 319; // abc
const uint32_t float4_ywwy_get = 320; // abc
const uint32_t float4_ywwz_get = 321; // abc
const uint32_t float4_ywww_get = 322; // abc
const uint32_t float4_zxxx_get = 323; // abc
const uint32_t float4_zxxy_get = 324; // abc
const uint32_t float4_zxxz_get = 325; // abc
const uint32_t float4_zxxw_get = 326; // abc
const uint32_t float4_zxyx_get = 327; // abc
const uint32_t float4_zxyy_get = 328; // abc
const uint32_t float4_zxyz_get = 329; // abc
const uint32_t float4_zxyw_get = 330; // abc
const uint32_t float4_zxzx_get = 331; // abc
const uint32_t float4_zxzy_get = 332; // abc
const uint32_t float4_zxzz_get = 333; // abc
const uint32_t float4_zxzw_get = 334; // abc
const uint32_t float4_zxwx_get = 335; // abc
const uint32_t float4_zxwy_get = 336; // abc
const uint32_t float4_zxwz_get = 337; // abc
const uint32_t float4_zxww_get = 338; // abc
const uint32_t float4_zyxx_get = 339; // abc
const uint32_t float4_zyxy_get = 340; // abc
const uint32_t float4_zyxz_get = 341; // abc
const uint32_t float4_zyxw_get = 342; // abc
const uint32_t float4_zyyx_get = 343; // abc
const uint32_t float4_zyyy_get = 344; // abc
const uint32_t float4_zyyz_get = 345; // abc
const uint32_t float4_zyyw_get = 346; // abc
const uint32_t float4_zyzx_get = 347; // abc
const uint32_t float4_zyzy_get = 348; // abc
const uint32_t float4_zyzz_get = 349; // abc
const uint32_t float4_zyzw_get = 350; // abc
const uint32_t float4_zywx_get = 351; // abc
const uint32_t float4_zywy_get = 352; // abc
const uint32_t float4_zywz_get = 353; // abc
const uint32_t float4_zyww_get = 354; // abc
const uint32_t float4_zzxx_get = 355; // abc
const uint32_t float4_zzxy_get = 356; // abc
const uint32_t float4_zzxz_get = 357; // abc
const uint32_t float4_zzxw_get = 358; // abc
const uint32_t float4_zzyx_get = 359; // abc
const uint32_t float4_zzyy_get = 360; // abc
const uint32_t float4_zzyz_get = 361; // abc
const uint32_t float4_zzyw_get = 362; // abc
const uint32_t float4_zzzx_get = 363; // abc
const uint32_t float4_zzzy_get = 364; // abc
const uint32_t float4_zzzz_get = 365; // abc
const uint32_t float4_zzzw_get = 366; // abc
const uint32_t float4_zzwx_get = 367; // abc
const uint32_t float4_zzwy_get = 368; // abc
const uint32_t float4_zzwz_get = 369; // abc
const uint32_t float4_zzww_get = 370; // abc
const uint32_t float4_zwxx_get = 371; // abc
const uint32_t float4_zwxy_get = 372; // abc
const uint32_t float4_zwxz_get = 373; // abc
const uint32_t float4_zwxw_get = 374; // abc
const uint32_t float4_zwyx_get = 375; // abc
const uint32_t float4_zwyy_get = 376; // abc
const uint32_t float4_zwyz_get = 377; // abc
const uint32_t float4_zwyw_get = 378; // abc
const uint32_t float4_zwzx_get = 379; // abc
const uint32_t float4_zwzy_get = 380; // abc
const uint32_t float4_zwzz_get = 381; // abc
const uint32_t float4_zwzw_get = 382; // abc
const uint32_t float4_zwwx_get = 383; // abc
const uint32_t float4_zwwy_get = 384; // abc
const uint32_t float4_zwwz_get = 385; // abc
const uint32_t float4_zwww_get = 386; // abc
const uint32_t float4_wxxx_get = 387; // abc
const uint32_t float4_wxxy_get = 388; // abc
const uint32_t float4_wxxz_get = 389; // abc
const uint32_t float4_wxxw_get = 390; // abc
const uint32_t float4_wxyx_get = 391; // abc
const uint32_t float4_wxyy_get = 392; // abc
const uint32_t float4_wxyz_get = 393; // abc
const uint32_t float4_wxyw_get = 394; // abc
const uint32_t float4_wxzx_get = 395; // abc
const uint32_t float4_wxzy_get = 396; // abc
const uint32_t float4_wxzz_get = 397; // abc
const uint32_t float4_wxzw_get = 398; // abc
const uint32_t float4_wxwx_get = 399; // abc
const uint32_t float4_wxwy_get = 400; // abc
const uint32_t float4_wxwz_get = 401; // abc
const uint32_t float4_wxww_get = 402; // abc
const uint32_t float4_wyxx_get = 403; // abc
const uint32_t float4_wyxy_get = 404; // abc
const uint32_t float4_wyxz_get = 405; // abc
const uint32_t float4_wyxw_get = 406; // abc
const uint32_t float4_wyyx_get = 407; // abc
const uint32_t float4_wyyy_get = 408; // abc
const uint32_t float4_wyyz_get = 409; // abc
const uint32_t float4_wyyw_get = 410; // abc
const uint32_t float4_wyzx_get = 411; // abc
const uint32_t float4_wyzy_get = 412; // abc
const uint32_t float4_wyzz_get = 413; // abc
const uint32_t float4_wyzw_get = 414; // abc
const uint32_t float4_wywx_get = 415; // abc
const uint32_t float4_wywy_get = 416; // abc
const uint32_t float4_wywz_get = 417; // abc
const uint32_t float4_wyww_get = 418; // abc
const uint32_t float4_wzxx_get = 419; // abc
const uint32_t float4_wzxy_get = 420; // abc
const uint32_t float4_wzxz_get = 421; // abc
const uint32_t float4_wzxw_get = 422; // abc
const uint32_t float4_wzyx_get = 423; // abc
const uint32_t float4_wzyy_get = 424; // abc
const uint32_t float4_wzyz_get = 425; // abc
const uint32_t float4_wzyw_get = 426; // abc
const uint32_t float4_wzzx_get = 427; // abc
const uint32_t float4_wzzy_get = 428; // abc
const uint32_t float4_wzzz_get = 429; // abc
const uint32_t float4_wzzw_get = 430; // abc
const uint32_t float4_wzwx_get = 431; // abc
const uint32_t float4_wzwy_get = 432; // abc
const uint32_t float4_wzwz_get = 433; // abc
const uint32_t float4_wzww_get = 434; // abc
const uint32_t float4_wwxx_get = 435; // abc
const uint32_t float4_wwxy_get = 436; // abc
const uint32_t float4_wwxz_get = 437; // abc
const uint32_t float4_wwxw_get = 438; // abc
const uint32_t float4_wwyx_get = 439; // abc
const uint32_t float4_wwyy_get = 440; // abc
const uint32_t float4_wwyz_get = 441; // abc
const uint32_t float4_wwyw_get = 442; // abc
const uint32_t float4_wwzx_get = 443; // abc
const uint32_t float4_wwzy_get = 444; // abc
const uint32_t float4_wwzz_get = 445; // abc
const uint32_t float4_wwzw_get = 446; // abc
const uint32_t float4_wwwx_get = 447; // abc
const uint32_t float4_wwwy_get = 448; // abc
const uint32_t float4_wwwz_get = 449; // abc
const uint32_t float4_wwww_get = 450; // abc
const uint32_t float4_length_get = 451; // abc
const uint32_t float4_AS3_toString = 452; // abc
const uint32_t float4_AS3_valueOf = 453; // abc
const uint32_t String_AS3_fromCharCode = 473; // native
const uint32_t String_private__match = 474; // native
const uint32_t String_private__replace = 475; // native
const uint32_t String_private__search = 476; // native
const uint32_t String_private__split = 477; // native
const uint32_t String_length_get = 478; // native
const uint32_t String_private__indexOf = 479; // native
const uint32_t String_AS3_indexOf = 480; // native
const uint32_t String_private__lastIndexOf = 481; // native
const uint32_t String_AS3_lastIndexOf = 482; // native
const uint32_t String_AS3_charAt = 483; // native
const uint32_t String_AS3_charCodeAt = 484; // native
const uint32_t String_AS3_concat = 485; // abc
const uint32_t String_AS3_localeCompare = 486; // native
const uint32_t String_AS3_match = 487; // abc
const uint32_t String_AS3_replace = 488; // abc
const uint32_t String_AS3_search = 489; // abc
const uint32_t String_private__slice = 490; // native
const uint32_t String_AS3_slice = 491; // native
const uint32_t String_AS3_split = 492; // abc
const uint32_t String_private__substring = 493; // native
const uint32_t String_AS3_substring = 494; // native
const uint32_t String_private__substr = 495; // native
const uint32_t String_AS3_substr = 496; // native
const uint32_t String_AS3_toLowerCase = 497; // native
const uint32_t String_AS3_toLocaleLowerCase = 498; // abc
const uint32_t String_AS3_toUpperCase = 499; // native
const uint32_t String_AS3_toLocaleUpperCase = 500; // abc
const uint32_t String_AS3_toString = 501; // abc
const uint32_t String_AS3_valueOf = 502; // abc
const uint32_t Array_private__join = 525; // abc
const uint32_t Array_private__pop = 526; // native
const uint32_t Array_private__reverse = 527; // native
const uint32_t Array_private__concat = 528; // native
const uint32_t Array_private__shift = 529; // native
const uint32_t Array_private__slice = 530; // native
const uint32_t Array_private__unshift = 531; // native
const uint32_t Array_private__splice = 532; // native
const uint32_t Array_private__sort = 533; // native
const uint32_t Array_private__sortOn = 534; // native
const uint32_t Array_private__indexOf = 535; // native
const uint32_t Array_private__lastIndexOf = 536; // native
const uint32_t Array_private__every = 537; // native
const uint32_t Array_private__filter = 538; // native
const uint32_t Array_private__forEach = 539; // native
const uint32_t Array_private__map = 540; // native
const uint32_t Array_private__some = 541; // native
const uint32_t Array_length_get = 542; // native
const uint32_t Array_length_set = 543; // native
const uint32_t Array_private_set_length = 544; // abc
const uint32_t Array_AS3_join = 546; // abc
const uint32_t Array_AS3_pop = 547; // native
const uint32_t Array_AS3_push = 548; // native
const uint32_t Array_AS3_reverse = 549; // abc
const uint32_t Array_AS3_concat = 550; // abc
const uint32_t Array_AS3_shift = 551; // abc
const uint32_t Array_AS3_slice = 552; // abc
const uint32_t Array_AS3_unshift = 553; // native
const uint32_t Array_AS3_splice = 554; // abc
const uint32_t Array_AS3_sort = 555; // abc
const uint32_t Array_AS3_sortOn = 556; // abc
const uint32_t Array_AS3_indexOf = 557; // abc
const uint32_t Array_AS3_lastIndexOf = 558; // abc
const uint32_t Array_AS3_every = 559; // abc
const uint32_t Array_AS3_filter = 560; // abc
const uint32_t Array_AS3_forEach = 561; // abc
const uint32_t Array_AS3_map = 562; // abc
const uint32_t Array_AS3_some = 563; // abc
const uint32_t __AS3___vec_Vector_object_private_castToThisType = 586; // abc
const uint32_t __AS3___vec_Vector_object_private__every = 587; // native
const uint32_t __AS3___vec_Vector_object_private__forEach = 588; // native
const uint32_t __AS3___vec_Vector_object_private__some = 589; // native
const uint32_t __AS3___vec_Vector_object_private__sort = 590; // native
const uint32_t __AS3___vec_Vector_object_private_newThisType = 592; // native
const uint32_t __AS3___vec_Vector_object_length_get = 593; // native
const uint32_t __AS3___vec_Vector_object_length_set = 594; // native
const uint32_t __AS3___vec_Vector_object_fixed_set = 595; // native
const uint32_t __AS3___vec_Vector_object_fixed_get = 596; // native
const uint32_t __AS3___vec_Vector_object_AS3_toString = 597; // abc
const uint32_t __AS3___vec_Vector_object_AS3_toLocaleString = 598; // abc
const uint32_t __AS3___vec_Vector_object_AS3_join = 599; // abc
const uint32_t __AS3___vec_Vector_object_private__concat = 600; // abc
const uint32_t __AS3___vec_Vector_object_AS3_every = 601; // abc
const uint32_t __AS3___vec_Vector_object_AS3_forEach = 602; // abc
const uint32_t __AS3___vec_Vector_object_AS3_map = 603; // abc
const uint32_t __AS3___vec_Vector_object_AS3_push = 604; // native
const uint32_t __AS3___vec_Vector_object_private__reverse = 605; // native
const uint32_t __AS3___vec_Vector_object_AS3_some = 606; // abc
const uint32_t __AS3___vec_Vector_object_private__slice = 607; // abc
const uint32_t __AS3___vec_Vector_object_private__splice = 608; // abc
const uint32_t __AS3___vec_Vector_object_private__spliceHelper = 609; // native
const uint32_t __AS3___vec_Vector_object_AS3_unshift = 610; // native
const uint32_t __AS3___vec_Vector_object_private__filter = 611; // native
const uint32_t __AS3___vec_Vector_object_private__map = 612; // native
const uint32_t __AS3___vec_Vector_object_private_clamp = 613; // abc
const uint32_t __AS3___vec_Vector_object_AS3_concat = 614; // abc
const uint32_t __AS3___vec_Vector_object_AS3_filter = 615; // abc
const uint32_t __AS3___vec_Vector_object_AS3_pop = 616; // native
const uint32_t __AS3___vec_Vector_object_AS3_reverse = 617; // abc
const uint32_t __AS3___vec_Vector_object_AS3_shift = 618; // native
const uint32_t __AS3___vec_Vector_object_AS3_slice = 619; // abc
const uint32_t __AS3___vec_Vector_object_AS3_sort = 620; // abc
const uint32_t __AS3___vec_Vector_object_AS3_splice = 621; // abc
const uint32_t __AS3___vec_Vector_object_AS3_indexOf = 622; // abc
const uint32_t __AS3___vec_Vector_object_AS3_lastIndexOf = 623; // abc
const uint32_t __AS3___vec_Vector_int_private_castToThisType = 644; // abc
const uint32_t __AS3___vec_Vector_int_private__every = 645; // native
const uint32_t __AS3___vec_Vector_int_private__forEach = 646; // native
const uint32_t __AS3___vec_Vector_int_private__some = 647; // native
const uint32_t __AS3___vec_Vector_int_private__sort = 648; // native
const uint32_t __AS3___vec_Vector_int_private_newThisType = 650; // native
const uint32_t __AS3___vec_Vector_int_length_get = 651; // native
const uint32_t __AS3___vec_Vector_int_length_set = 652; // native
const uint32_t __AS3___vec_Vector_int_fixed_set = 653; // native
const uint32_t __AS3___vec_Vector_int_fixed_get = 654; // native
const uint32_t __AS3___vec_Vector_int_AS3_toString = 655; // abc
const uint32_t __AS3___vec_Vector_int_AS3_toLocaleString = 656; // abc
const uint32_t __AS3___vec_Vector_int_AS3_join = 657; // abc
const uint32_t __AS3___vec_Vector_int_private__concat = 658; // abc
const uint32_t __AS3___vec_Vector_int_AS3_every = 659; // abc
const uint32_t __AS3___vec_Vector_int_AS3_forEach = 660; // abc
const uint32_t __AS3___vec_Vector_int_AS3_map = 661; // abc
const uint32_t __AS3___vec_Vector_int_AS3_push = 662; // native
const uint32_t __AS3___vec_Vector_int_private__reverse = 663; // native
const uint32_t __AS3___vec_Vector_int_AS3_some = 664; // abc
const uint32_t __AS3___vec_Vector_int_private__slice = 665; // abc
const uint32_t __AS3___vec_Vector_int_private__splice = 666; // abc
const uint32_t __AS3___vec_Vector_int_private__spliceHelper = 667; // native
const uint32_t __AS3___vec_Vector_int_AS3_unshift = 668; // native
const uint32_t __AS3___vec_Vector_int_private__filter = 669; // native
const uint32_t __AS3___vec_Vector_int_private__map = 670; // native
const uint32_t __AS3___vec_Vector_int_private_clamp = 671; // abc
const uint32_t __AS3___vec_Vector_int_AS3_concat = 672; // abc
const uint32_t __AS3___vec_Vector_int_AS3_filter = 673; // abc
const uint32_t __AS3___vec_Vector_int_AS3_pop = 674; // native
const uint32_t __AS3___vec_Vector_int_AS3_reverse = 675; // abc
const uint32_t __AS3___vec_Vector_int_AS3_shift = 676; // native
const uint32_t __AS3___vec_Vector_int_AS3_slice = 677; // abc
const uint32_t __AS3___vec_Vector_int_AS3_sort = 678; // abc
const uint32_t __AS3___vec_Vector_int_AS3_splice = 679; // abc
const uint32_t __AS3___vec_Vector_int_AS3_indexOf = 680; // abc
const uint32_t __AS3___vec_Vector_int_AS3_lastIndexOf = 681; // abc
const uint32_t __AS3___vec_Vector_uint_private_castToThisType = 702; // abc
const uint32_t __AS3___vec_Vector_uint_private__every = 703; // native
const uint32_t __AS3___vec_Vector_uint_private__forEach = 704; // native
const uint32_t __AS3___vec_Vector_uint_private__some = 705; // native
const uint32_t __AS3___vec_Vector_uint_private__sort = 706; // native
const uint32_t __AS3___vec_Vector_uint_private_newThisType = 708; // native
const uint32_t __AS3___vec_Vector_uint_length_get = 709; // native
const uint32_t __AS3___vec_Vector_uint_length_set = 710; // native
const uint32_t __AS3___vec_Vector_uint_fixed_set = 711; // native
const uint32_t __AS3___vec_Vector_uint_fixed_get = 712; // native
const uint32_t __AS3___vec_Vector_uint_AS3_toString = 713; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_toLocaleString = 714; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_join = 715; // abc
const uint32_t __AS3___vec_Vector_uint_private__concat = 716; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_every = 717; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_forEach = 718; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_map = 719; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_push = 720; // native
const uint32_t __AS3___vec_Vector_uint_private__reverse = 721; // native
const uint32_t __AS3___vec_Vector_uint_AS3_some = 722; // abc
const uint32_t __AS3___vec_Vector_uint_private__slice = 723; // abc
const uint32_t __AS3___vec_Vector_uint_private__splice = 724; // abc
const uint32_t __AS3___vec_Vector_uint_private__spliceHelper = 725; // native
const uint32_t __AS3___vec_Vector_uint_AS3_unshift = 726; // native
const uint32_t __AS3___vec_Vector_uint_private__filter = 727; // native
const uint32_t __AS3___vec_Vector_uint_private__map = 728; // native
const uint32_t __AS3___vec_Vector_uint_private_clamp = 729; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_concat = 730; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_filter = 731; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_pop = 732; // native
const uint32_t __AS3___vec_Vector_uint_AS3_reverse = 733; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_shift = 734; // native
const uint32_t __AS3___vec_Vector_uint_AS3_slice = 735; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_sort = 736; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_splice = 737; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_indexOf = 738; // abc
const uint32_t __AS3___vec_Vector_uint_AS3_lastIndexOf = 739; // abc
const uint32_t __AS3___vec_Vector_double_private_castToThisType = 760; // abc
const uint32_t __AS3___vec_Vector_double_private__every = 761; // native
const uint32_t __AS3___vec_Vector_double_private__forEach = 762; // native
const uint32_t __AS3___vec_Vector_double_private__some = 763; // native
const uint32_t __AS3___vec_Vector_double_private__sort = 764; // native
const uint32_t __AS3___vec_Vector_double_private_newThisType = 766; // native
const uint32_t __AS3___vec_Vector_double_length_get = 767; // native
const uint32_t __AS3___vec_Vector_double_length_set = 768; // native
const uint32_t __AS3___vec_Vector_double_fixed_set = 769; // native
const uint32_t __AS3___vec_Vector_double_fixed_get = 770; // native
const uint32_t __AS3___vec_Vector_double_AS3_toString = 771; // abc
const uint32_t __AS3___vec_Vector_double_AS3_toLocaleString = 772; // abc
const uint32_t __AS3___vec_Vector_double_AS3_join = 773; // abc
const uint32_t __AS3___vec_Vector_double_private__concat = 774; // abc
const uint32_t __AS3___vec_Vector_double_AS3_every = 775; // abc
const uint32_t __AS3___vec_Vector_double_AS3_forEach = 776; // abc
const uint32_t __AS3___vec_Vector_double_AS3_map = 777; // abc
const uint32_t __AS3___vec_Vector_double_AS3_push = 778; // native
const uint32_t __AS3___vec_Vector_double_private__reverse = 779; // native
const uint32_t __AS3___vec_Vector_double_AS3_some = 780; // abc
const uint32_t __AS3___vec_Vector_double_private__slice = 781; // abc
const uint32_t __AS3___vec_Vector_double_private__splice = 782; // abc
const uint32_t __AS3___vec_Vector_double_private__spliceHelper = 783; // native
const uint32_t __AS3___vec_Vector_double_AS3_unshift = 784; // native
const uint32_t __AS3___vec_Vector_double_private__filter = 785; // native
const uint32_t __AS3___vec_Vector_double_private__map = 786; // native
const uint32_t __AS3___vec_Vector_double_private_clamp = 787; // abc
const uint32_t __AS3___vec_Vector_double_AS3_concat = 788; // abc
const uint32_t __AS3___vec_Vector_double_AS3_filter = 789; // abc
const uint32_t __AS3___vec_Vector_double_AS3_pop = 790; // native
const uint32_t __AS3___vec_Vector_double_AS3_reverse = 791; // abc
const uint32_t __AS3___vec_Vector_double_AS3_shift = 792; // native
const uint32_t __AS3___vec_Vector_double_AS3_slice = 793; // abc
const uint32_t __AS3___vec_Vector_double_AS3_sort = 794; // abc
const uint32_t __AS3___vec_Vector_double_AS3_splice = 795; // abc
const uint32_t __AS3___vec_Vector_double_AS3_indexOf = 796; // abc
const uint32_t __AS3___vec_Vector_double_AS3_lastIndexOf = 797; // abc
const uint32_t __AS3___vec_Vector_float_private_castToThisType = 818; // abc
const uint32_t __AS3___vec_Vector_float_private__every = 819; // native
const uint32_t __AS3___vec_Vector_float_private__forEach = 820; // native
const uint32_t __AS3___vec_Vector_float_private__some = 821; // native
const uint32_t __AS3___vec_Vector_float_private__sort = 822; // native
const uint32_t __AS3___vec_Vector_float_private_newThisType = 824; // native
const uint32_t __AS3___vec_Vector_float_length_get = 825; // native
const uint32_t __AS3___vec_Vector_float_length_set = 826; // native
const uint32_t __AS3___vec_Vector_float_fixed_set = 827; // native
const uint32_t __AS3___vec_Vector_float_fixed_get = 828; // native
const uint32_t __AS3___vec_Vector_float_AS3_toString = 829; // abc
const uint32_t __AS3___vec_Vector_float_AS3_toLocaleString = 830; // abc
const uint32_t __AS3___vec_Vector_float_AS3_join = 831; // abc
const uint32_t __AS3___vec_Vector_float_private__concat = 832; // abc
const uint32_t __AS3___vec_Vector_float_AS3_every = 833; // abc
const uint32_t __AS3___vec_Vector_float_AS3_forEach = 834; // abc
const uint32_t __AS3___vec_Vector_float_AS3_map = 835; // abc
const uint32_t __AS3___vec_Vector_float_AS3_push = 836; // native
const uint32_t __AS3___vec_Vector_float_private__reverse = 837; // native
const uint32_t __AS3___vec_Vector_float_AS3_some = 838; // abc
const uint32_t __AS3___vec_Vector_float_private__slice = 839; // abc
const uint32_t __AS3___vec_Vector_float_private__splice = 840; // abc
const uint32_t __AS3___vec_Vector_float_private__spliceHelper = 841; // native
const uint32_t __AS3___vec_Vector_float_AS3_unshift = 842; // native
const uint32_t __AS3___vec_Vector_float_private__filter = 843; // native
const uint32_t __AS3___vec_Vector_float_private__map = 844; // native
const uint32_t __AS3___vec_Vector_float_private_clamp = 845; // abc
const uint32_t __AS3___vec_Vector_float_AS3_concat = 846; // abc
const uint32_t __AS3___vec_Vector_float_AS3_filter = 847; // abc
const uint32_t __AS3___vec_Vector_float_AS3_pop = 848; // native
const uint32_t __AS3___vec_Vector_float_AS3_reverse = 849; // abc
const uint32_t __AS3___vec_Vector_float_AS3_shift = 850; // native
const uint32_t __AS3___vec_Vector_float_AS3_slice = 851; // abc
const uint32_t __AS3___vec_Vector_float_AS3_sort = 852; // abc
const uint32_t __AS3___vec_Vector_float_AS3_splice = 853; // abc
const uint32_t __AS3___vec_Vector_float_AS3_indexOf = 854; // abc
const uint32_t __AS3___vec_Vector_float_AS3_lastIndexOf = 855; // abc
const uint32_t __AS3___vec_Vector_float4_private_castToThisType = 876; // abc
const uint32_t __AS3___vec_Vector_float4_private__every = 877; // native
const uint32_t __AS3___vec_Vector_float4_private__forEach = 878; // native
const uint32_t __AS3___vec_Vector_float4_private__some = 879; // native
const uint32_t __AS3___vec_Vector_float4_private__sort = 880; // native
const uint32_t __AS3___vec_Vector_float4_private_newThisType = 882; // native
const uint32_t __AS3___vec_Vector_float4_length_get = 883; // native
const uint32_t __AS3___vec_Vector_float4_length_set = 884; // native
const uint32_t __AS3___vec_Vector_float4_fixed_set = 885; // native
const uint32_t __AS3___vec_Vector_float4_fixed_get = 886; // native
const uint32_t __AS3___vec_Vector_float4_AS3_toString = 887; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_toLocaleString = 888; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_join = 889; // abc
const uint32_t __AS3___vec_Vector_float4_private__concat = 890; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_every = 891; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_forEach = 892; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_map = 893; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_push = 894; // native
const uint32_t __AS3___vec_Vector_float4_private__reverse = 895; // native
const uint32_t __AS3___vec_Vector_float4_AS3_some = 896; // abc
const uint32_t __AS3___vec_Vector_float4_private__slice = 897; // abc
const uint32_t __AS3___vec_Vector_float4_private__splice = 898; // abc
const uint32_t __AS3___vec_Vector_float4_private__spliceHelper = 899; // native
const uint32_t __AS3___vec_Vector_float4_AS3_unshift = 900; // native
const uint32_t __AS3___vec_Vector_float4_private__filter = 901; // native
const uint32_t __AS3___vec_Vector_float4_private__map = 902; // native
const uint32_t __AS3___vec_Vector_float4_private_clamp = 903; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_concat = 904; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_filter = 905; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_pop = 906; // native
const uint32_t __AS3___vec_Vector_float4_AS3_reverse = 907; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_shift = 908; // native
const uint32_t __AS3___vec_Vector_float4_AS3_slice = 909; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_sort = 910; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_splice = 911; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_indexOf = 912; // abc
const uint32_t __AS3___vec_Vector_float4_AS3_lastIndexOf = 913; // abc
const uint32_t private_MethodClosure_prototype_get = 915; // abc
const uint32_t private_MethodClosure_prototype_set = 916; // abc
const uint32_t Math_private__min = 920; // native
const uint32_t Math_private__max = 921; // native
const uint32_t Math_abs = 922; // native
const uint32_t Math_acos = 923; // native
const uint32_t Math_asin = 924; // native
const uint32_t Math_atan = 925; // native
const uint32_t Math_ceil = 926; // native
const uint32_t Math_cos = 927; // native
const uint32_t Math_exp = 928; // native
const uint32_t Math_floor = 929; // native
const uint32_t Math_log = 930; // native
const uint32_t Math_round = 931; // native
const uint32_t Math_sin = 932; // native
const uint32_t Math_sqrt = 933; // native
const uint32_t Math_tan = 934; // native
const uint32_t Math_atan2 = 935; // native
const uint32_t Math_pow = 936; // native
const uint32_t Math_max = 937; // native
const uint32_t Math_min = 938; // native
const uint32_t Math_random = 939; // native
const uint32_t Error_getErrorMessage = 944; // native
const uint32_t Error_throwError = 946; // abc
const uint32_t Error_getStackTrace = 948; // native
const uint32_t Error_errorID_get = 949; // abc
const uint32_t Date_parse = 1024; // native
const uint32_t Date_UTC = 1025; // native
const uint32_t Date_AS3_valueOf = 1026; // native
const uint32_t Date_private__toString = 1027; // native
const uint32_t Date_private__setTime = 1028; // native
const uint32_t Date_private__get = 1029; // native
const uint32_t Date_AS3_setTime = 1030; // abc
const uint32_t Date_AS3_toString = 1031; // abc
const uint32_t Date_AS3_toDateString = 1032; // abc
const uint32_t Date_AS3_toTimeString = 1033; // abc
const uint32_t Date_AS3_toLocaleString = 1034; // abc
const uint32_t Date_AS3_toLocaleDateString = 1035; // abc
const uint32_t Date_AS3_toLocaleTimeString = 1036; // abc
const uint32_t Date_AS3_toUTCString = 1037; // abc
const uint32_t Date_AS3_getUTCFullYear = 1038; // native
const uint32_t Date_AS3_getUTCMonth = 1039; // native
const uint32_t Date_AS3_getUTCDate = 1040; // native
const uint32_t Date_AS3_getUTCDay = 1041; // native
const uint32_t Date_AS3_getUTCHours = 1042; // native
const uint32_t Date_AS3_getUTCMinutes = 1043; // native
const uint32_t Date_AS3_getUTCSeconds = 1044; // native
const uint32_t Date_AS3_getUTCMilliseconds = 1045; // native
const uint32_t Date_AS3_getFullYear = 1046; // native
const uint32_t Date_AS3_getMonth = 1047; // native
const uint32_t Date_AS3_getDate = 1048; // native
const uint32_t Date_AS3_getDay = 1049; // native
const uint32_t Date_AS3_getHours = 1050; // native
const uint32_t Date_AS3_getMinutes = 1051; // native
const uint32_t Date_AS3_getSeconds = 1052; // native
const uint32_t Date_AS3_getMilliseconds = 1053; // native
const uint32_t Date_AS3_getTimezoneOffset = 1054; // native
const uint32_t Date_AS3_getTime = 1055; // native
const uint32_t Date_private__setFullYear = 1056; // native
const uint32_t Date_private__setMonth = 1057; // native
const uint32_t Date_private__setDate = 1058; // native
const uint32_t Date_private__setHours = 1059; // native
const uint32_t Date_private__setMinutes = 1060; // native
const uint32_t Date_private__setSeconds = 1061; // native
const uint32_t Date_private__setMilliseconds = 1062; // native
const uint32_t Date_private__setUTCFullYear = 1063; // native
const uint32_t Date_private__setUTCMonth = 1064; // native
const uint32_t Date_private__setUTCDate = 1065; // native
const uint32_t Date_private__setUTCHours = 1066; // native
const uint32_t Date_private__setUTCMinutes = 1067; // native
const uint32_t Date_private__setUTCSeconds = 1068; // native
const uint32_t Date_private__setUTCMilliseconds = 1069; // native
const uint32_t Date_AS3_setFullYear = 1070; // abc
const uint32_t Date_AS3_setMonth = 1071; // abc
const uint32_t Date_AS3_setDate = 1072; // abc
const uint32_t Date_AS3_setHours = 1073; // abc
const uint32_t Date_AS3_setMinutes = 1074; // abc
const uint32_t Date_AS3_setSeconds = 1075; // abc
const uint32_t Date_AS3_setMilliseconds = 1076; // abc
const uint32_t Date_AS3_setUTCFullYear = 1077; // abc
const uint32_t Date_AS3_setUTCMonth = 1078; // abc
const uint32_t Date_AS3_setUTCDate = 1079; // abc
const uint32_t Date_AS3_setUTCHours = 1080; // abc
const uint32_t Date_AS3_setUTCMinutes = 1081; // abc
const uint32_t Date_AS3_setUTCSeconds = 1082; // abc
const uint32_t Date_AS3_setUTCMilliseconds = 1083; // abc
const uint32_t Date_fullYear_get = 1084; // abc
const uint32_t Date_fullYear_set = 1085; // abc
const uint32_t Date_month_get = 1086; // abc
const uint32_t Date_month_set = 1087; // abc
const uint32_t Date_date_get = 1088; // abc
const uint32_t Date_date_set = 1089; // abc
const uint32_t Date_hours_get = 1090; // abc
const uint32_t Date_hours_set = 1091; // abc
const uint32_t Date_minutes_get = 1092; // abc
const uint32_t Date_minutes_set = 1093; // abc
const uint32_t Date_seconds_get = 1094; // abc
const uint32_t Date_seconds_set = 1095; // abc
const uint32_t Date_milliseconds_get = 1096; // abc
const uint32_t Date_milliseconds_set = 1097; // abc
const uint32_t Date_fullYearUTC_get = 1098; // abc
const uint32_t Date_fullYearUTC_set = 1099; // abc
const uint32_t Date_monthUTC_get = 1100; // abc
const uint32_t Date_monthUTC_set = 1101; // abc
const uint32_t Date_dateUTC_get = 1102; // abc
const uint32_t Date_dateUTC_set = 1103; // abc
const uint32_t Date_hoursUTC_get = 1104; // abc
const uint32_t Date_hoursUTC_set = 1105; // abc
const uint32_t Date_minutesUTC_get = 1106; // abc
const uint32_t Date_minutesUTC_set = 1107; // abc
const uint32_t Date_secondsUTC_get = 1108; // abc
const uint32_t Date_secondsUTC_set = 1109; // abc
const uint32_t Date_millisecondsUTC_get = 1110; // abc
const uint32_t Date_millisecondsUTC_set = 1111; // abc
const uint32_t Date_time_get = 1112; // abc
const uint32_t Date_time_set = 1113; // abc
const uint32_t Date_timezoneOffset_get = 1114; // abc
const uint32_t Date_day_get = 1115; // abc
const uint32_t Date_dayUTC_get = 1116; // abc
const uint32_t RegExp_source_get = 1123; // native
const uint32_t RegExp_global_get = 1124; // native
const uint32_t RegExp_ignoreCase_get = 1125; // native
const uint32_t RegExp_multiline_get = 1126; // native
const uint32_t RegExp_lastIndex_get = 1127; // native
const uint32_t RegExp_lastIndex_set = 1128; // native
const uint32_t RegExp_dotall_get = 1129; // native
const uint32_t RegExp_extended_get = 1130; // native
const uint32_t RegExp_AS3_exec = 1131; // native
const uint32_t RegExp_AS3_test = 1132; // abc
const uint32_t JSON_private_parseCore = 1136; // native
const uint32_t JSON_private_stringifySpecializedToString = 1137; // native
const uint32_t JSON_parse = 1138; // abc
const uint32_t JSON_stringify = 1139; // abc
const uint32_t JSON_private_computePropertyList = 1140; // abc
const uint32_t Walker_walk = 1144; // abc
const uint32_t XML_ignoreComments_get = 1189; // native
const uint32_t XML_ignoreComments_set = 1190; // native
const uint32_t XML_ignoreProcessingInstructions_get = 1191; // native
const uint32_t XML_ignoreProcessingInstructions_set = 1192; // native
const uint32_t XML_ignoreWhitespace_get = 1193; // native
const uint32_t XML_ignoreWhitespace_set = 1194; // native
const uint32_t XML_prettyPrinting_get = 1195; // native
const uint32_t XML_prettyPrinting_set = 1196; // native
const uint32_t XML_prettyIndent_get = 1197; // native
const uint32_t XML_prettyIndent_set = 1198; // native
const uint32_t XML_AS3_settings = 1199; // abc
const uint32_t XML_AS3_setSettings = 1200; // abc
const uint32_t XML_AS3_defaultSettings = 1201; // abc
const uint32_t XML_AS3_toString = 1202; // native
const uint32_t XML_AS3_hasOwnProperty = 1203; // native
const uint32_t XML_AS3_propertyIsEnumerable = 1204; // native
const uint32_t XML_AS3_addNamespace = 1205; // native
const uint32_t XML_AS3_appendChild = 1206; // native
const uint32_t XML_AS3_attribute = 1207; // native
const uint32_t XML_AS3_attributes = 1208; // native
const uint32_t XML_AS3_child = 1209; // native
const uint32_t XML_AS3_childIndex = 1210; // native
const uint32_t XML_AS3_children = 1211; // native
const uint32_t XML_AS3_comments = 1212; // native
const uint32_t XML_AS3_contains = 1213; // native
const uint32_t XML_AS3_copy = 1214; // native
const uint32_t XML_AS3_descendants = 1215; // native
const uint32_t XML_AS3_elements = 1216; // native
const uint32_t XML_AS3_hasComplexContent = 1217; // native
const uint32_t XML_AS3_hasSimpleContent = 1218; // native
const uint32_t XML_AS3_inScopeNamespaces = 1219; // native
const uint32_t XML_AS3_insertChildAfter = 1220; // native
const uint32_t XML_AS3_insertChildBefore = 1221; // native
const uint32_t XML_AS3_length = 1222; // abc
const uint32_t XML_AS3_localName = 1223; // native
const uint32_t XML_AS3_name = 1224; // native
const uint32_t XML_private__namespace = 1225; // native
const uint32_t XML_AS3_namespace = 1226; // abc
const uint32_t XML_AS3_namespaceDeclarations = 1227; // native
const uint32_t XML_AS3_nodeKind = 1228; // native
const uint32_t XML_AS3_normalize = 1229; // native
const uint32_t XML_AS3_parent = 1230; // native
const uint32_t XML_AS3_processingInstructions = 1231; // native
const uint32_t XML_AS3_prependChild = 1232; // native
const uint32_t XML_AS3_removeNamespace = 1233; // native
const uint32_t XML_AS3_replace = 1234; // native
const uint32_t XML_AS3_setChildren = 1235; // native
const uint32_t XML_AS3_setLocalName = 1236; // native
const uint32_t XML_AS3_setName = 1237; // native
const uint32_t XML_AS3_setNamespace = 1238; // native
const uint32_t XML_AS3_text = 1239; // native
const uint32_t XML_AS3_toXMLString = 1240; // native
const uint32_t XML_AS3_notification = 1241; // native
const uint32_t XML_AS3_setNotification = 1242; // native
const uint32_t XML_AS3_toJSON = 1243; // abc
const uint32_t XML_AS3_valueOf = 1245; // abc
const uint32_t XMLList_AS3_toString = 1286; // native
const uint32_t XMLList_AS3_valueOf = 1287; // abc
const uint32_t XMLList_AS3_hasOwnProperty = 1288; // native
const uint32_t XMLList_AS3_propertyIsEnumerable = 1289; // native
const uint32_t XMLList_AS3_attribute = 1290; // native
const uint32_t XMLList_AS3_attributes = 1291; // native
const uint32_t XMLList_AS3_child = 1292; // native
const uint32_t XMLList_AS3_children = 1293; // native
const uint32_t XMLList_AS3_comments = 1294; // native
const uint32_t XMLList_AS3_contains = 1295; // native
const uint32_t XMLList_AS3_copy = 1296; // native
const uint32_t XMLList_AS3_descendants = 1297; // native
const uint32_t XMLList_AS3_elements = 1298; // native
const uint32_t XMLList_AS3_hasComplexContent = 1299; // native
const uint32_t XMLList_AS3_hasSimpleContent = 1300; // native
const uint32_t XMLList_AS3_length = 1301; // native
const uint32_t XMLList_AS3_name = 1302; // native
const uint32_t XMLList_AS3_normalize = 1303; // native
const uint32_t XMLList_AS3_parent = 1304; // native
const uint32_t XMLList_AS3_processingInstructions = 1305; // native
const uint32_t XMLList_AS3_text = 1306; // native
const uint32_t XMLList_AS3_toXMLString = 1307; // native
const uint32_t XMLList_AS3_addNamespace = 1308; // native
const uint32_t XMLList_AS3_appendChild = 1309; // native
const uint32_t XMLList_AS3_childIndex = 1310; // native
const uint32_t XMLList_AS3_inScopeNamespaces = 1311; // native
const uint32_t XMLList_AS3_insertChildAfter = 1312; // native
const uint32_t XMLList_AS3_insertChildBefore = 1313; // native
const uint32_t XMLList_AS3_nodeKind = 1314; // native
const uint32_t XMLList_private__namespace = 1315; // native
const uint32_t XMLList_AS3_namespace = 1316; // abc
const uint32_t XMLList_AS3_localName = 1317; // native
const uint32_t XMLList_AS3_namespaceDeclarations = 1318; // native
const uint32_t XMLList_AS3_prependChild = 1319; // native
const uint32_t XMLList_AS3_removeNamespace = 1320; // native
const uint32_t XMLList_AS3_replace = 1321; // native
const uint32_t XMLList_AS3_setChildren = 1322; // native
const uint32_t XMLList_AS3_setLocalName = 1323; // native
const uint32_t XMLList_AS3_setName = 1324; // native
const uint32_t XMLList_AS3_setNamespace = 1325; // native
const uint32_t XMLList_AS3_toJSON = 1326; // abc
const uint32_t QName_localName_get = 1330; // native
const uint32_t QName_uri_get = 1331; // native
const uint32_t QName_AS3_valueOf = 1332; // abc
const uint32_t QName_AS3_toString = 1333; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readBytes = 1337; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readBoolean = 1338; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readByte = 1339; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readUnsignedByte = 1340; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readShort = 1341; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readUnsignedShort = 1342; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readInt = 1343; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readUnsignedInt = 1344; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readFloat = 1345; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readDouble = 1346; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readMultiByte = 1347; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readUTF = 1348; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readUTFBytes = 1349; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_bytesAvailable_get = 1350; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_readObject = 1351; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_objectEncoding_get = 1352; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_objectEncoding_set = 1353; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_endian_get = 1354; // abc
const uint32_t flash_utils_IDataInput_flash_utils_IDataInput_endian_set = 1355; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeBytes = 1359; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeBoolean = 1360; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeByte = 1361; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeShort = 1362; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeInt = 1363; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeUnsignedInt = 1364; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeFloat = 1365; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeDouble = 1366; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeMultiByte = 1367; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeUTF = 1368; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeUTFBytes = 1369; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_writeObject = 1370; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_objectEncoding_get = 1371; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_objectEncoding_set = 1372; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_endian_get = 1373; // abc
const uint32_t flash_utils_IDataOutput_flash_utils_IDataOutput_endian_set = 1374; // abc
const uint32_t flash_utils_Proxy_flash_proxy_getProperty = 1378; // abc
const uint32_t flash_utils_Proxy_flash_proxy_setProperty = 1379; // abc
const uint32_t flash_utils_Proxy_flash_proxy_callProperty = 1380; // abc
const uint32_t flash_utils_Proxy_flash_proxy_hasProperty = 1381; // abc
const uint32_t flash_utils_Proxy_flash_proxy_deleteProperty = 1382; // abc
const uint32_t flash_utils_Proxy_flash_proxy_getDescendants = 1383; // abc
const uint32_t flash_utils_Proxy_flash_proxy_nextNameIndex = 1384; // abc
const uint32_t flash_utils_Proxy_flash_proxy_nextName = 1385; // abc
const uint32_t flash_utils_Proxy_flash_proxy_nextValue = 1386; // abc
const uint32_t flash_utils_Proxy_flash_proxy_isAttribute = 1387; // native
const uint32_t flash_utils_ByteArray_defaultObjectEncoding_get = 1394; // native
const uint32_t flash_utils_ByteArray_defaultObjectEncoding_set = 1395; // native
const uint32_t flash_utils_ByteArray_readBytes = 1397; // native
const uint32_t flash_utils_ByteArray_writeBytes = 1398; // native
const uint32_t flash_utils_ByteArray_writeBoolean = 1399; // native
const uint32_t flash_utils_ByteArray_writeByte = 1400; // native
const uint32_t flash_utils_ByteArray_writeShort = 1401; // native
const uint32_t flash_utils_ByteArray_writeInt = 1402; // native
const uint32_t flash_utils_ByteArray_writeUnsignedInt = 1403; // native
const uint32_t flash_utils_ByteArray_writeFloat = 1404; // native
const uint32_t flash_utils_ByteArray_writeFloat4 = 1405; // native
const uint32_t flash_utils_ByteArray_writeDouble = 1406; // native
const uint32_t flash_utils_ByteArray_writeMultiByte = 1407; // native
const uint32_t flash_utils_ByteArray_writeUTF = 1408; // native
const uint32_t flash_utils_ByteArray_writeUTFBytes = 1409; // native
const uint32_t flash_utils_ByteArray_readBoolean = 1410; // native
const uint32_t flash_utils_ByteArray_readByte = 1411; // native
const uint32_t flash_utils_ByteArray_readUnsignedByte = 1412; // native
const uint32_t flash_utils_ByteArray_readShort = 1413; // native
const uint32_t flash_utils_ByteArray_readUnsignedShort = 1414; // native
const uint32_t flash_utils_ByteArray_readInt = 1415; // native
const uint32_t flash_utils_ByteArray_readUnsignedInt = 1416; // native
const uint32_t flash_utils_ByteArray_readFloat = 1417; // native
const uint32_t flash_utils_ByteArray_readFloat4 = 1418; // native
const uint32_t flash_utils_ByteArray_readDouble = 1419; // native
const uint32_t flash_utils_ByteArray_readMultiByte = 1420; // native
const uint32_t flash_utils_ByteArray_readUTF = 1421; // native
const uint32_t flash_utils_ByteArray_readUTFBytes = 1422; // native
const uint32_t flash_utils_ByteArray_length_get = 1423; // native
const uint32_t flash_utils_ByteArray_length_set = 1424; // native
const uint32_t flash_utils_ByteArray_writeObject = 1425; // native
const uint32_t flash_utils_ByteArray_readObject = 1426; // native
const uint32_t flash_utils_ByteArray_deflate = 1427; // abc
const uint32_t flash_utils_ByteArray_private__compress = 1428; // native
const uint32_t flash_utils_ByteArray_compress = 1429; // abc
const uint32_t flash_utils_ByteArray_inflate = 1430; // abc
const uint32_t flash_utils_ByteArray_private__uncompress = 1431; // native
const uint32_t flash_utils_ByteArray_uncompress = 1432; // abc
const uint32_t flash_utils_ByteArray_toString = 1433; // abc
const uint32_t flash_utils_ByteArray_private__toString = 1434; // native
const uint32_t flash_utils_ByteArray_bytesAvailable_get = 1435; // native
const uint32_t flash_utils_ByteArray_position_get = 1436; // native
const uint32_t flash_utils_ByteArray_position_set = 1437; // native
const uint32_t flash_utils_ByteArray_objectEncoding_get = 1438; // native
const uint32_t flash_utils_ByteArray_objectEncoding_set = 1439; // native
const uint32_t flash_utils_ByteArray_endian_get = 1440; // native
const uint32_t flash_utils_ByteArray_endian_set = 1441; // native
const uint32_t flash_utils_ByteArray_clear = 1442; // native

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
extern double Number_abs_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_acos_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_asin_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_atan_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_ceil_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_cos_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_exp_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_floor_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_log_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_round_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_sin_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_sqrt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_tan_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_atan2_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_pow_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_max_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_min_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_random_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Number_private__numberToString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom Number_private__convert_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double Number_private__minValue_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_abs_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_acos_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_asin_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_atan_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_atan2_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_ceil_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_cos_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_exp_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_floor_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_log_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_pow_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_random_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_round_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_sin_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_sqrt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_tan_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_reciprocal_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_rsqrt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float_private__minValue_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom float_private__floatToString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom float_private__convert_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_dot_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_dot2_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_dot3_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_magnitude_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_magnitude3_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_magnitude2_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_distance_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_distance3_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_distance2_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_x_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_y_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_z_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern float float4_w_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
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
    double m_E;
    double m_LN10;
    double m_LN2;
    double m_LOG10E;
    double m_LOG2E;
    double m_PI;
    double m_SQRT1_2;
    double m_SQRT2;
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
    public: \
        REALLY_INLINE double get_E() const { return m_slots_NumberClass.m_E; } \
        REALLY_INLINE void setconst_E(double newVal) { m_slots_NumberClass.m_E = newVal; } \
    public: \
        REALLY_INLINE double get_LN10() const { return m_slots_NumberClass.m_LN10; } \
        REALLY_INLINE void setconst_LN10(double newVal) { m_slots_NumberClass.m_LN10 = newVal; } \
    public: \
        REALLY_INLINE double get_LN2() const { return m_slots_NumberClass.m_LN2; } \
        REALLY_INLINE void setconst_LN2(double newVal) { m_slots_NumberClass.m_LN2 = newVal; } \
    public: \
        REALLY_INLINE double get_LOG10E() const { return m_slots_NumberClass.m_LOG10E; } \
        REALLY_INLINE void setconst_LOG10E(double newVal) { m_slots_NumberClass.m_LOG10E = newVal; } \
    public: \
        REALLY_INLINE double get_LOG2E() const { return m_slots_NumberClass.m_LOG2E; } \
        REALLY_INLINE void setconst_LOG2E(double newVal) { m_slots_NumberClass.m_LOG2E = newVal; } \
    public: \
        REALLY_INLINE double get_PI() const { return m_slots_NumberClass.m_PI; } \
        REALLY_INLINE void setconst_PI(double newVal) { m_slots_NumberClass.m_PI = newVal; } \
    public: \
        REALLY_INLINE double get_SQRT1_2() const { return m_slots_NumberClass.m_SQRT1_2; } \
        REALLY_INLINE void setconst_SQRT1_2(double newVal) { m_slots_NumberClass.m_SQRT1_2 = newVal; } \
    public: \
        REALLY_INLINE double get_SQRT2() const { return m_slots_NumberClass.m_SQRT2; } \
        REALLY_INLINE void setconst_SQRT2(double newVal) { m_slots_NumberClass.m_SQRT2 = newVal; } \
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
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_length() const { return m_slots_Float4Class.m_length; } \
        REALLY_INLINE void setconst_length(int32_t newVal) { m_slots_Float4Class.m_length = newVal; } \
    private: \
        avmplus::NativeID::avmplus_Float4ClassSlots m_slots_Float4Class \

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
