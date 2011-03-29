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
    class FunctionClass; // Function$
    class FunctionObject; // Function
    class IOErrorClass; // flash.errors::IOError$
    class IOErrorObject; // flash.errors::IOError
    class IntClass; // int$
    class IntVectorClass; // __AS3__.vec::Vector$int$
    class IntVectorObject; // __AS3__.vec::Vector$int
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
const uint32_t abcclass_private_MethodClosure = 15;
const uint32_t abcclass_Math = 16;
const uint32_t abcclass_Error = 17;
const uint32_t abcclass_DefinitionError = 18;
const uint32_t abcclass_EvalError = 19;
const uint32_t abcclass_RangeError = 20;
const uint32_t abcclass_ReferenceError = 21;
const uint32_t abcclass_SecurityError = 22;
const uint32_t abcclass_SyntaxError = 23;
const uint32_t abcclass_TypeError = 24;
const uint32_t abcclass_URIError = 25;
const uint32_t abcclass_VerifyError = 26;
const uint32_t abcclass_UninitializedError = 27;
const uint32_t abcclass_ArgumentError = 28;
const uint32_t abcclass_flash_errors_IOError = 29;
const uint32_t abcclass_flash_errors_MemoryError = 30;
const uint32_t abcclass_flash_errors_EOFError = 31;
const uint32_t abcclass_Date = 32;
const uint32_t abcclass_RegExp = 33;
const uint32_t abcclass_XML = 34;
const uint32_t abcclass_XMLList = 35;
const uint32_t abcclass_QName = 36;
const uint32_t abcclass_flash_utils_IDataInput = 37;
const uint32_t abcclass_flash_utils_IDataOutput = 38;
const uint32_t abcclass_flash_utils_CompressionAlgorithm = 39;
const uint32_t abcclass_flash_utils_ByteArray = 40;

/* methods */
const uint32_t native_script_function_avmplus_getQualifiedSuperclassName = 0;
const uint32_t native_script_function_avmplus_getQualifiedClassName = 1;
const uint32_t native_script_function_avmplus_describeTypeJSON = 7;
const uint32_t native_script_function_isXMLName = 8;
const uint32_t native_script_function_unescape = 9;
const uint32_t native_script_function_escape = 10;
const uint32_t native_script_function_parseFloat = 11;
const uint32_t native_script_function_parseInt = 12;
const uint32_t native_script_function_isFinite = 13;
const uint32_t native_script_function_isNaN = 14;
const uint32_t native_script_function_encodeURIComponent = 15;
const uint32_t native_script_function_encodeURI = 16;
const uint32_t native_script_function_decodeURIComponent = 17;
const uint32_t native_script_function_decodeURI = 18;
const uint32_t native_script_function_bugzilla = 19;
const uint32_t Object_private__hasOwnProperty = 21;
const uint32_t Object_private__propertyIsEnumerable = 22;
const uint32_t Object_protected__setPropertyIsEnumerable = 23;
const uint32_t Object_private__isPrototypeOf = 24;
const uint32_t Object_private__toString = 25;
const uint32_t Class_prototype_get = 40;
const uint32_t Function_prototype_get = 48;
const uint32_t Function_prototype_set = 49;
const uint32_t Function_length_get = 50;
const uint32_t Function_AS3_call = 51;
const uint32_t Function_AS3_apply = 52;
const uint32_t Namespace_prefix_get = 57;
const uint32_t Namespace_uri_get = 58;
const uint32_t Number_private__numberToString = 74;
const uint32_t Number_private__convert = 75;
const uint32_t Number_private__minValue = 76;
const uint32_t String_AS3_fromCharCode = 126;
const uint32_t String_private__match = 127;
const uint32_t String_private__replace = 128;
const uint32_t String_private__search = 129;
const uint32_t String_private__split = 130;
const uint32_t String_length_get = 131;
const uint32_t String_private__indexOf = 132;
const uint32_t String_AS3_indexOf = 133;
const uint32_t String_private__lastIndexOf = 134;
const uint32_t String_AS3_lastIndexOf = 135;
const uint32_t String_AS3_charAt = 136;
const uint32_t String_AS3_charCodeAt = 137;
const uint32_t String_AS3_localeCompare = 139;
const uint32_t String_private__slice = 143;
const uint32_t String_AS3_slice = 144;
const uint32_t String_private__substring = 146;
const uint32_t String_AS3_substring = 147;
const uint32_t String_private__substr = 148;
const uint32_t String_AS3_substr = 149;
const uint32_t String_AS3_toLowerCase = 150;
const uint32_t String_AS3_toUpperCase = 152;
const uint32_t Array_private__pop = 179;
const uint32_t Array_private__reverse = 180;
const uint32_t Array_private__concat = 181;
const uint32_t Array_private__shift = 182;
const uint32_t Array_private__slice = 183;
const uint32_t Array_private__unshift = 184;
const uint32_t Array_private__splice = 185;
const uint32_t Array_private__sort = 186;
const uint32_t Array_private__sortOn = 187;
const uint32_t Array_private__indexOf = 188;
const uint32_t Array_private__lastIndexOf = 189;
const uint32_t Array_private__every = 190;
const uint32_t Array_private__filter = 191;
const uint32_t Array_private__forEach = 192;
const uint32_t Array_private__map = 193;
const uint32_t Array_private__some = 194;
const uint32_t Array_length_get = 195;
const uint32_t Array_length_set = 196;
const uint32_t Array_AS3_pop = 199;
const uint32_t Array_AS3_push = 200;
const uint32_t Array_AS3_unshift = 205;
const uint32_t __AS3___vec_Vector_object_private__every = 239;
const uint32_t __AS3___vec_Vector_object_private__forEach = 240;
const uint32_t __AS3___vec_Vector_object_private__some = 241;
const uint32_t __AS3___vec_Vector_object_private__sort = 242;
const uint32_t __AS3___vec_Vector_object_private_newThisType = 244;
const uint32_t __AS3___vec_Vector_object_length_get = 245;
const uint32_t __AS3___vec_Vector_object_length_set = 246;
const uint32_t __AS3___vec_Vector_object_fixed_set = 247;
const uint32_t __AS3___vec_Vector_object_fixed_get = 248;
const uint32_t __AS3___vec_Vector_object_AS3_push = 256;
const uint32_t __AS3___vec_Vector_object_private__reverse = 257;
const uint32_t __AS3___vec_Vector_object_private__spliceHelper = 261;
const uint32_t __AS3___vec_Vector_object_AS3_unshift = 262;
const uint32_t __AS3___vec_Vector_object_private__filter = 263;
const uint32_t __AS3___vec_Vector_object_private__map = 264;
const uint32_t __AS3___vec_Vector_object_AS3_pop = 268;
const uint32_t __AS3___vec_Vector_object_AS3_shift = 270;
const uint32_t __AS3___vec_Vector_int_private__every = 297;
const uint32_t __AS3___vec_Vector_int_private__forEach = 298;
const uint32_t __AS3___vec_Vector_int_private__some = 299;
const uint32_t __AS3___vec_Vector_int_private__sort = 300;
const uint32_t __AS3___vec_Vector_int_private_newThisType = 302;
const uint32_t __AS3___vec_Vector_int_length_get = 303;
const uint32_t __AS3___vec_Vector_int_length_set = 304;
const uint32_t __AS3___vec_Vector_int_fixed_set = 305;
const uint32_t __AS3___vec_Vector_int_fixed_get = 306;
const uint32_t __AS3___vec_Vector_int_AS3_push = 314;
const uint32_t __AS3___vec_Vector_int_private__reverse = 315;
const uint32_t __AS3___vec_Vector_int_private__spliceHelper = 319;
const uint32_t __AS3___vec_Vector_int_AS3_unshift = 320;
const uint32_t __AS3___vec_Vector_int_private__filter = 321;
const uint32_t __AS3___vec_Vector_int_private__map = 322;
const uint32_t __AS3___vec_Vector_int_AS3_pop = 326;
const uint32_t __AS3___vec_Vector_int_AS3_shift = 328;
const uint32_t __AS3___vec_Vector_uint_private__every = 355;
const uint32_t __AS3___vec_Vector_uint_private__forEach = 356;
const uint32_t __AS3___vec_Vector_uint_private__some = 357;
const uint32_t __AS3___vec_Vector_uint_private__sort = 358;
const uint32_t __AS3___vec_Vector_uint_private_newThisType = 360;
const uint32_t __AS3___vec_Vector_uint_length_get = 361;
const uint32_t __AS3___vec_Vector_uint_length_set = 362;
const uint32_t __AS3___vec_Vector_uint_fixed_set = 363;
const uint32_t __AS3___vec_Vector_uint_fixed_get = 364;
const uint32_t __AS3___vec_Vector_uint_AS3_push = 372;
const uint32_t __AS3___vec_Vector_uint_private__reverse = 373;
const uint32_t __AS3___vec_Vector_uint_private__spliceHelper = 377;
const uint32_t __AS3___vec_Vector_uint_AS3_unshift = 378;
const uint32_t __AS3___vec_Vector_uint_private__filter = 379;
const uint32_t __AS3___vec_Vector_uint_private__map = 380;
const uint32_t __AS3___vec_Vector_uint_AS3_pop = 384;
const uint32_t __AS3___vec_Vector_uint_AS3_shift = 386;
const uint32_t __AS3___vec_Vector_double_private__every = 413;
const uint32_t __AS3___vec_Vector_double_private__forEach = 414;
const uint32_t __AS3___vec_Vector_double_private__some = 415;
const uint32_t __AS3___vec_Vector_double_private__sort = 416;
const uint32_t __AS3___vec_Vector_double_private_newThisType = 418;
const uint32_t __AS3___vec_Vector_double_length_get = 419;
const uint32_t __AS3___vec_Vector_double_length_set = 420;
const uint32_t __AS3___vec_Vector_double_fixed_set = 421;
const uint32_t __AS3___vec_Vector_double_fixed_get = 422;
const uint32_t __AS3___vec_Vector_double_AS3_push = 430;
const uint32_t __AS3___vec_Vector_double_private__reverse = 431;
const uint32_t __AS3___vec_Vector_double_private__spliceHelper = 435;
const uint32_t __AS3___vec_Vector_double_AS3_unshift = 436;
const uint32_t __AS3___vec_Vector_double_private__filter = 437;
const uint32_t __AS3___vec_Vector_double_private__map = 438;
const uint32_t __AS3___vec_Vector_double_AS3_pop = 442;
const uint32_t __AS3___vec_Vector_double_AS3_shift = 444;
const uint32_t Math_private__min = 456;
const uint32_t Math_private__max = 457;
const uint32_t Math_abs = 458;
const uint32_t Math_acos = 459;
const uint32_t Math_asin = 460;
const uint32_t Math_atan = 461;
const uint32_t Math_ceil = 462;
const uint32_t Math_cos = 463;
const uint32_t Math_exp = 464;
const uint32_t Math_floor = 465;
const uint32_t Math_log = 466;
const uint32_t Math_round = 467;
const uint32_t Math_sin = 468;
const uint32_t Math_sqrt = 469;
const uint32_t Math_tan = 470;
const uint32_t Math_atan2 = 471;
const uint32_t Math_pow = 472;
const uint32_t Math_max = 473;
const uint32_t Math_min = 474;
const uint32_t Math_random = 475;
const uint32_t Error_getErrorMessage = 480;
const uint32_t Error_getStackTrace = 484;
const uint32_t Date_parse = 557;
const uint32_t Date_UTC = 558;
const uint32_t Date_AS3_valueOf = 559;
const uint32_t Date_private__toString = 560;
const uint32_t Date_private__setTime = 561;
const uint32_t Date_private__get = 562;
const uint32_t Date_AS3_getUTCFullYear = 571;
const uint32_t Date_AS3_getUTCMonth = 572;
const uint32_t Date_AS3_getUTCDate = 573;
const uint32_t Date_AS3_getUTCDay = 574;
const uint32_t Date_AS3_getUTCHours = 575;
const uint32_t Date_AS3_getUTCMinutes = 576;
const uint32_t Date_AS3_getUTCSeconds = 577;
const uint32_t Date_AS3_getUTCMilliseconds = 578;
const uint32_t Date_AS3_getFullYear = 579;
const uint32_t Date_AS3_getMonth = 580;
const uint32_t Date_AS3_getDate = 581;
const uint32_t Date_AS3_getDay = 582;
const uint32_t Date_AS3_getHours = 583;
const uint32_t Date_AS3_getMinutes = 584;
const uint32_t Date_AS3_getSeconds = 585;
const uint32_t Date_AS3_getMilliseconds = 586;
const uint32_t Date_AS3_getTimezoneOffset = 587;
const uint32_t Date_AS3_getTime = 588;
const uint32_t Date_private__setFullYear = 589;
const uint32_t Date_private__setMonth = 590;
const uint32_t Date_private__setDate = 591;
const uint32_t Date_private__setHours = 592;
const uint32_t Date_private__setMinutes = 593;
const uint32_t Date_private__setSeconds = 594;
const uint32_t Date_private__setMilliseconds = 595;
const uint32_t Date_private__setUTCFullYear = 596;
const uint32_t Date_private__setUTCMonth = 597;
const uint32_t Date_private__setUTCDate = 598;
const uint32_t Date_private__setUTCHours = 599;
const uint32_t Date_private__setUTCMinutes = 600;
const uint32_t Date_private__setUTCSeconds = 601;
const uint32_t Date_private__setUTCMilliseconds = 602;
const uint32_t RegExp_source_get = 656;
const uint32_t RegExp_global_get = 657;
const uint32_t RegExp_ignoreCase_get = 658;
const uint32_t RegExp_multiline_get = 659;
const uint32_t RegExp_lastIndex_get = 660;
const uint32_t RegExp_lastIndex_set = 661;
const uint32_t RegExp_dotall_get = 662;
const uint32_t RegExp_extended_get = 663;
const uint32_t RegExp_AS3_exec = 664;
const uint32_t XML_ignoreComments_get = 710;
const uint32_t XML_ignoreComments_set = 711;
const uint32_t XML_ignoreProcessingInstructions_get = 712;
const uint32_t XML_ignoreProcessingInstructions_set = 713;
const uint32_t XML_ignoreWhitespace_get = 714;
const uint32_t XML_ignoreWhitespace_set = 715;
const uint32_t XML_prettyPrinting_get = 716;
const uint32_t XML_prettyPrinting_set = 717;
const uint32_t XML_prettyIndent_get = 718;
const uint32_t XML_prettyIndent_set = 719;
const uint32_t XML_AS3_toString = 723;
const uint32_t XML_AS3_hasOwnProperty = 724;
const uint32_t XML_AS3_propertyIsEnumerable = 725;
const uint32_t XML_AS3_addNamespace = 726;
const uint32_t XML_AS3_appendChild = 727;
const uint32_t XML_AS3_attribute = 728;
const uint32_t XML_AS3_attributes = 729;
const uint32_t XML_AS3_child = 730;
const uint32_t XML_AS3_childIndex = 731;
const uint32_t XML_AS3_children = 732;
const uint32_t XML_AS3_comments = 733;
const uint32_t XML_AS3_contains = 734;
const uint32_t XML_AS3_copy = 735;
const uint32_t XML_AS3_descendants = 736;
const uint32_t XML_AS3_elements = 737;
const uint32_t XML_AS3_hasComplexContent = 738;
const uint32_t XML_AS3_hasSimpleContent = 739;
const uint32_t XML_AS3_inScopeNamespaces = 740;
const uint32_t XML_AS3_insertChildAfter = 741;
const uint32_t XML_AS3_insertChildBefore = 742;
const uint32_t XML_AS3_localName = 744;
const uint32_t XML_AS3_name = 745;
const uint32_t XML_private__namespace = 746;
const uint32_t XML_AS3_namespaceDeclarations = 748;
const uint32_t XML_AS3_nodeKind = 749;
const uint32_t XML_AS3_normalize = 750;
const uint32_t XML_AS3_parent = 751;
const uint32_t XML_AS3_processingInstructions = 752;
const uint32_t XML_AS3_prependChild = 753;
const uint32_t XML_AS3_removeNamespace = 754;
const uint32_t XML_AS3_replace = 755;
const uint32_t XML_AS3_setChildren = 756;
const uint32_t XML_AS3_setLocalName = 757;
const uint32_t XML_AS3_setName = 758;
const uint32_t XML_AS3_setNamespace = 759;
const uint32_t XML_AS3_text = 760;
const uint32_t XML_AS3_toXMLString = 761;
const uint32_t XML_AS3_notification = 762;
const uint32_t XML_AS3_setNotification = 763;
const uint32_t XMLList_AS3_toString = 805;
const uint32_t XMLList_AS3_hasOwnProperty = 807;
const uint32_t XMLList_AS3_propertyIsEnumerable = 808;
const uint32_t XMLList_AS3_attribute = 809;
const uint32_t XMLList_AS3_attributes = 810;
const uint32_t XMLList_AS3_child = 811;
const uint32_t XMLList_AS3_children = 812;
const uint32_t XMLList_AS3_comments = 813;
const uint32_t XMLList_AS3_contains = 814;
const uint32_t XMLList_AS3_copy = 815;
const uint32_t XMLList_AS3_descendants = 816;
const uint32_t XMLList_AS3_elements = 817;
const uint32_t XMLList_AS3_hasComplexContent = 818;
const uint32_t XMLList_AS3_hasSimpleContent = 819;
const uint32_t XMLList_AS3_length = 820;
const uint32_t XMLList_AS3_name = 821;
const uint32_t XMLList_AS3_normalize = 822;
const uint32_t XMLList_AS3_parent = 823;
const uint32_t XMLList_AS3_processingInstructions = 824;
const uint32_t XMLList_AS3_text = 825;
const uint32_t XMLList_AS3_toXMLString = 826;
const uint32_t XMLList_AS3_addNamespace = 827;
const uint32_t XMLList_AS3_appendChild = 828;
const uint32_t XMLList_AS3_childIndex = 829;
const uint32_t XMLList_AS3_inScopeNamespaces = 830;
const uint32_t XMLList_AS3_insertChildAfter = 831;
const uint32_t XMLList_AS3_insertChildBefore = 832;
const uint32_t XMLList_AS3_nodeKind = 833;
const uint32_t XMLList_private__namespace = 834;
const uint32_t XMLList_AS3_localName = 836;
const uint32_t XMLList_AS3_namespaceDeclarations = 837;
const uint32_t XMLList_AS3_prependChild = 838;
const uint32_t XMLList_AS3_removeNamespace = 839;
const uint32_t XMLList_AS3_replace = 840;
const uint32_t XMLList_AS3_setChildren = 841;
const uint32_t XMLList_AS3_setLocalName = 842;
const uint32_t XMLList_AS3_setName = 843;
const uint32_t XMLList_AS3_setNamespace = 844;
const uint32_t QName_localName_get = 848;
const uint32_t QName_uri_get = 849;
const uint32_t flash_utils_ByteArray_defaultObjectEncoding_get = 898;
const uint32_t flash_utils_ByteArray_defaultObjectEncoding_set = 899;
const uint32_t flash_utils_ByteArray_readBytes = 901;
const uint32_t flash_utils_ByteArray_writeBytes = 902;
const uint32_t flash_utils_ByteArray_writeBoolean = 903;
const uint32_t flash_utils_ByteArray_writeByte = 904;
const uint32_t flash_utils_ByteArray_writeShort = 905;
const uint32_t flash_utils_ByteArray_writeInt = 906;
const uint32_t flash_utils_ByteArray_writeUnsignedInt = 907;
const uint32_t flash_utils_ByteArray_writeFloat = 908;
const uint32_t flash_utils_ByteArray_writeDouble = 909;
const uint32_t flash_utils_ByteArray_writeMultiByte = 910;
const uint32_t flash_utils_ByteArray_writeUTF = 911;
const uint32_t flash_utils_ByteArray_writeUTFBytes = 912;
const uint32_t flash_utils_ByteArray_readBoolean = 913;
const uint32_t flash_utils_ByteArray_readByte = 914;
const uint32_t flash_utils_ByteArray_readUnsignedByte = 915;
const uint32_t flash_utils_ByteArray_readShort = 916;
const uint32_t flash_utils_ByteArray_readUnsignedShort = 917;
const uint32_t flash_utils_ByteArray_readInt = 918;
const uint32_t flash_utils_ByteArray_readUnsignedInt = 919;
const uint32_t flash_utils_ByteArray_readFloat = 920;
const uint32_t flash_utils_ByteArray_readDouble = 921;
const uint32_t flash_utils_ByteArray_readMultiByte = 922;
const uint32_t flash_utils_ByteArray_readUTF = 923;
const uint32_t flash_utils_ByteArray_readUTFBytes = 924;
const uint32_t flash_utils_ByteArray_length_get = 925;
const uint32_t flash_utils_ByteArray_length_set = 926;
const uint32_t flash_utils_ByteArray_writeObject = 927;
const uint32_t flash_utils_ByteArray_readObject = 928;
const uint32_t flash_utils_ByteArray_private__compress = 930;
const uint32_t flash_utils_ByteArray_private__uncompress = 933;
const uint32_t flash_utils_ByteArray_private__toString = 936;
const uint32_t flash_utils_ByteArray_bytesAvailable_get = 937;
const uint32_t flash_utils_ByteArray_position_get = 938;
const uint32_t flash_utils_ByteArray_position_set = 939;
const uint32_t flash_utils_ByteArray_objectEncoding_get = 940;
const uint32_t flash_utils_ByteArray_objectEncoding_set = 941;
const uint32_t flash_utils_ByteArray_endian_get = 942;
const uint32_t flash_utils_ByteArray_endian_set = 943;
const uint32_t flash_utils_ByteArray_clear = 944;

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
        REALLY_INLINE avmplus::Atom constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
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
        REALLY_INLINE GCRef<avmplus::ClassClosure> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ClassClosure>((avmplus::ClassClosure*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::FunctionObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::FunctionObject>((avmplus::FunctionObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::Namespace> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::Namespace>(AvmCore::atomToNamespace(result)); \
        } \
        REALLY_INLINE GCRef<avmplus::Namespace> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::Namespace>(AvmCore::atomToNamespace(result)); \
        } \
        REALLY_INLINE GCRef<avmplus::Namespace> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::Namespace>(AvmCore::atomToNamespace(result)); \
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
        REALLY_INLINE GCRef<avmplus::String> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::String>(AvmCore::atomToString(result)); \
        } \
        REALLY_INLINE GCRef<avmplus::String> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::String>(AvmCore::atomToString(result)); \
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
        REALLY_INLINE GCRef<avmplus::ObjectVectorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::ObjectVectorObject> constructObject(uint32_t arg1, bool arg2) \
        { \
            avmplus::AvmCore* const core = ((AvmCore*)(this->core())); \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1), ((arg2) ? trueAtom : falseAtom) }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ObjectVectorObject> constructObject(uint32_t arg1) \
        { \
            avmplus::AvmCore* const core = ((AvmCore*)(this->core())); \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ObjectVectorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ObjectVectorObject>((avmplus::ObjectVectorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::IntVectorObject> constructObject(uint32_t arg1, bool arg2) \
        { \
            avmplus::AvmCore* const core = ((AvmCore*)(this->core())); \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1), ((arg2) ? trueAtom : falseAtom) }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::IntVectorObject>((avmplus::IntVectorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::IntVectorObject> constructObject(uint32_t arg1) \
        { \
            avmplus::AvmCore* const core = ((AvmCore*)(this->core())); \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::IntVectorObject>((avmplus::IntVectorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::IntVectorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::IntVectorObject>((avmplus::IntVectorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::UIntVectorObject> constructObject(uint32_t arg1, bool arg2) \
        { \
            avmplus::AvmCore* const core = ((AvmCore*)(this->core())); \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1), ((arg2) ? trueAtom : falseAtom) }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::UIntVectorObject>((avmplus::UIntVectorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::UIntVectorObject> constructObject(uint32_t arg1) \
        { \
            avmplus::AvmCore* const core = ((AvmCore*)(this->core())); \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::UIntVectorObject>((avmplus::UIntVectorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::UIntVectorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::UIntVectorObject>((avmplus::UIntVectorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::DoubleVectorObject> constructObject(uint32_t arg1, bool arg2) \
        { \
            avmplus::AvmCore* const core = ((AvmCore*)(this->core())); \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1), ((arg2) ? trueAtom : falseAtom) }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::DoubleVectorObject>((avmplus::DoubleVectorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DoubleVectorObject> constructObject(uint32_t arg1) \
        { \
            avmplus::AvmCore* const core = ((AvmCore*)(this->core())); \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::DoubleVectorObject>((avmplus::DoubleVectorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DoubleVectorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::DoubleVectorObject>((avmplus::DoubleVectorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::MethodClosure> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::MethodClosure>((avmplus::MethodClosure*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::ErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ErrorObject>((avmplus::ErrorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::DefinitionErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::DefinitionErrorObject>((avmplus::DefinitionErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DefinitionErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::DefinitionErrorObject>((avmplus::DefinitionErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DefinitionErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::DefinitionErrorObject>((avmplus::DefinitionErrorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::EvalErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::EvalErrorObject>((avmplus::EvalErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::EvalErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::EvalErrorObject>((avmplus::EvalErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::EvalErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::EvalErrorObject>((avmplus::EvalErrorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::RangeErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::RangeErrorObject>((avmplus::RangeErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RangeErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::RangeErrorObject>((avmplus::RangeErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RangeErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::RangeErrorObject>((avmplus::RangeErrorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::ReferenceErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::ReferenceErrorObject>((avmplus::ReferenceErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ReferenceErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::ReferenceErrorObject>((avmplus::ReferenceErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ReferenceErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ReferenceErrorObject>((avmplus::ReferenceErrorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::SecurityErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::SecurityErrorObject>((avmplus::SecurityErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SecurityErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::SecurityErrorObject>((avmplus::SecurityErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SecurityErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::SecurityErrorObject>((avmplus::SecurityErrorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::SyntaxErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::SyntaxErrorObject>((avmplus::SyntaxErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SyntaxErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::SyntaxErrorObject>((avmplus::SyntaxErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::SyntaxErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::SyntaxErrorObject>((avmplus::SyntaxErrorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::TypeErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::TypeErrorObject>((avmplus::TypeErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::TypeErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::TypeErrorObject>((avmplus::TypeErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::TypeErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::TypeErrorObject>((avmplus::TypeErrorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::URIErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::URIErrorObject>((avmplus::URIErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::URIErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::URIErrorObject>((avmplus::URIErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::URIErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::URIErrorObject>((avmplus::URIErrorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::VerifyErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::VerifyErrorObject>((avmplus::VerifyErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::VerifyErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::VerifyErrorObject>((avmplus::VerifyErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::VerifyErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::VerifyErrorObject>((avmplus::VerifyErrorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::UninitializedErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::UninitializedErrorObject>((avmplus::UninitializedErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::UninitializedErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::UninitializedErrorObject>((avmplus::UninitializedErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::UninitializedErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::UninitializedErrorObject>((avmplus::UninitializedErrorObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::ArgumentErrorObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::ArgumentErrorObject>((avmplus::ArgumentErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ArgumentErrorObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::ArgumentErrorObject>((avmplus::ArgumentErrorObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ArgumentErrorObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ArgumentErrorObject>((avmplus::ArgumentErrorObject*)(AvmCore::atomToScriptObject(result))); \
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
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::IOError
//-----------------------------------------------------------
class avmplus_IOErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::IOErrorObject;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::MemoryError$
//-----------------------------------------------------------
class avmplus_MemoryErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::MemoryErrorClass;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::MemoryError
//-----------------------------------------------------------
class avmplus_MemoryErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::MemoryErrorObject;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::EOFError$
//-----------------------------------------------------------
class avmplus_EOFErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EOFErrorClass;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::EOFError
//-----------------------------------------------------------
class avmplus_EOFErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EOFErrorObject;
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
        REALLY_INLINE GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2, avmplus::Atom arg3, avmplus::Atom arg4, avmplus::Atom arg5, avmplus::Atom arg6, avmplus::Atom arg7) \
        { \
            avmplus::Atom args[8] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2, arg3, arg4, arg5, arg6, arg7 }; \
            avmplus::Atom const result = this->construct(7, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2, avmplus::Atom arg3, avmplus::Atom arg4, avmplus::Atom arg5, avmplus::Atom arg6) \
        { \
            avmplus::Atom args[7] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2, arg3, arg4, arg5, arg6 }; \
            avmplus::Atom const result = this->construct(6, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2, avmplus::Atom arg3, avmplus::Atom arg4, avmplus::Atom arg5) \
        { \
            avmplus::Atom args[6] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2, arg3, arg4, arg5 }; \
            avmplus::Atom const result = this->construct(5, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2, avmplus::Atom arg3, avmplus::Atom arg4) \
        { \
            avmplus::Atom args[5] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2, arg3, arg4 }; \
            avmplus::Atom const result = this->construct(4, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2, avmplus::Atom arg3) \
        { \
            avmplus::Atom args[4] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2, arg3 }; \
            avmplus::Atom const result = this->construct(3, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DateObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DateObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::DateObject>((avmplus::DateObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::RegExpObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::RegExpObject>((avmplus::RegExpObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RegExpObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::RegExpObject>((avmplus::RegExpObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::RegExpObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::RegExpObject>((avmplus::RegExpObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::XMLObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::XMLObject>((avmplus::XMLObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::XMLObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::XMLObject>((avmplus::XMLObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::XMLListObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::XMLListObject>((avmplus::XMLListObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::XMLListObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::XMLListObject>((avmplus::XMLListObject*)(AvmCore::atomToScriptObject(result))); \
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
        REALLY_INLINE GCRef<avmplus::QNameObject> constructObject(avmplus::Atom arg1, avmplus::Atom arg2) \
        { \
            avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1, arg2 }; \
            avmplus::Atom const result = this->construct(2, args); \
            return GCRef<avmplus::QNameObject>((avmplus::QNameObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::QNameObject> constructObject(avmplus::Atom arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1 }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::QNameObject>((avmplus::QNameObject*)(AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::QNameObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::QNameObject>((avmplus::QNameObject*)(AvmCore::atomToScriptObject(result))); \
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
// flash.utils::CompressionAlgorithm$
//-----------------------------------------------------------
class avmplus_CompressionAlgorithmClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CompressionAlgorithmClass;
private:
    DRCWB(avmplus::String*) m_ZLIB;
    DRCWB(avmplus::String*) m_DEFLATE;
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::CompressionAlgorithm
//-----------------------------------------------------------
class avmplus_CompressionAlgorithmObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CompressionAlgorithmObject;
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
        REALLY_INLINE GCRef<avmplus::ByteArrayObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::ByteArrayObject>((avmplus::ByteArrayObject*)(AvmCore::atomToScriptObject(result))); \
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
    friend class avmplus::DoubleVectorClass;
    friend class avmplus::ObjectVectorClass;
private:
    REALLY_INLINE builtinClassManifest(avmplus::ScriptEnv* e) : ClassManifestBase(41, e) { }
    REALLY_INLINE static builtinClassManifest* create(avmplus::ScriptEnv* e) { return new (MMgc::GC::GetGC(e), MMgc::kExact, sizeof(ClassClosure*)*40) builtinClassManifest(e); }
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
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_IDataInputClass() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_flash_utils_IDataInput)); }
    REALLY_INLINE GCRef<avmplus::ClassClosure> get_IDataOutputClass() { return (avmplus::ClassClosure*)(lazyInitClass(avmplus::NativeID::abcclass_flash_utils_IDataOutput)); }
    REALLY_INLINE GCRef<avmplus::IOErrorClass> get_IOErrorClass() { return (avmplus::IOErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_errors_IOError)); }
    REALLY_INLINE GCRef<avmplus::MathClass> get_MathClass() { return (avmplus::MathClass*)(lazyInitClass(avmplus::NativeID::abcclass_Math)); }
    REALLY_INLINE GCRef<avmplus::MemoryErrorClass> get_MemoryErrorClass() { return (avmplus::MemoryErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_errors_MemoryError)); }
    REALLY_INLINE GCRef<avmplus::MethodClosureClass> get_MethodClosureClass() { return (avmplus::MethodClosureClass*)(lazyInitClass(avmplus::NativeID::abcclass_private_MethodClosure)); }
    REALLY_INLINE GCRef<avmplus::NamespaceClass> get_NamespaceClass() { return (avmplus::NamespaceClass*)(lazyInitClass(avmplus::NativeID::abcclass_Namespace)); }
    REALLY_INLINE GCRef<avmplus::NumberClass> get_NumberClass() { return (avmplus::NumberClass*)(lazyInitClass(avmplus::NativeID::abcclass_Number)); }
    REALLY_INLINE GCRef<avmplus::ObjectClass> get_ObjectClass() { return (avmplus::ObjectClass*)(lazyInitClass(avmplus::NativeID::abcclass_Object)); }
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
    REALLY_INLINE GCRef<avmplus::IntVectorClass> get_Vector_intClass() { return (avmplus::IntVectorClass*)(lazyInitClass(avmplus::NativeID::abcclass___AS3___vec_Vector_int)); }
    REALLY_INLINE GCRef<avmplus::ObjectVectorClass> get_Vector_objectClass() { return (avmplus::ObjectVectorClass*)(lazyInitClass(avmplus::NativeID::abcclass___AS3___vec_Vector_object)); }
    REALLY_INLINE GCRef<avmplus::UIntVectorClass> get_Vector_uintClass() { return (avmplus::UIntVectorClass*)(lazyInitClass(avmplus::NativeID::abcclass___AS3___vec_Vector_uint)); }
    REALLY_INLINE GCRef<avmplus::VerifyErrorClass> get_VerifyErrorClass() { return (avmplus::VerifyErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_VerifyError)); }
    REALLY_INLINE GCRef<avmplus::XMLClass> get_XMLClass() { return (avmplus::XMLClass*)(lazyInitClass(avmplus::NativeID::abcclass_XML)); }
    REALLY_INLINE GCRef<avmplus::XMLListClass> get_XMLListClass() { return (avmplus::XMLListClass*)(lazyInitClass(avmplus::NativeID::abcclass_XMLList)); }
    REALLY_INLINE GCRef<avmplus::IntClass> get_intClass() { return (avmplus::IntClass*)(lazyInitClass(avmplus::NativeID::abcclass_int)); }
    REALLY_INLINE GCRef<avmplus::UIntClass> get_uintClass() { return (avmplus::UIntClass*)(lazyInitClass(avmplus::NativeID::abcclass_uint)); }
};
}
#endif // _H_nativegen_header_builtin
