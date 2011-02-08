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

#define AVMTHUNK_VERSION 5

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
    class DateClass; // Date$
    class DateObject; // Date
    class DefinitionErrorClass; // DefinitionError$
    class DefinitionErrorObject; // DefinitionError
    class DoubleVectorClass; // __AS3__.vec::Vector$double$
    class DoubleVectorObject; // __AS3__.vec::Vector$double
    class ErrorClass; // Error$
    class ErrorObject; // Error
    class EvalErrorClass; // EvalError$
    class EvalErrorObject; // EvalError
    class FunctionClass; // Function$
    class FunctionObject; // Function
    class IntClass; // int$
    class IntVectorClass; // __AS3__.vec::Vector$int$
    class IntVectorObject; // __AS3__.vec::Vector$int
    class MathClass; // Math$
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
const uint32_t abcclass_flash_utils_ByteArray = 39;

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
const uint32_t flash_utils_ByteArray_defaultObjectEncoding_get = 896;
const uint32_t flash_utils_ByteArray_defaultObjectEncoding_set = 897;
const uint32_t flash_utils_ByteArray_readBytes = 899;
const uint32_t flash_utils_ByteArray_writeBytes = 900;
const uint32_t flash_utils_ByteArray_writeBoolean = 901;
const uint32_t flash_utils_ByteArray_writeByte = 902;
const uint32_t flash_utils_ByteArray_writeShort = 903;
const uint32_t flash_utils_ByteArray_writeInt = 904;
const uint32_t flash_utils_ByteArray_writeUnsignedInt = 905;
const uint32_t flash_utils_ByteArray_writeFloat = 906;
const uint32_t flash_utils_ByteArray_writeDouble = 907;
const uint32_t flash_utils_ByteArray_writeMultiByte = 908;
const uint32_t flash_utils_ByteArray_writeUTF = 909;
const uint32_t flash_utils_ByteArray_writeUTFBytes = 910;
const uint32_t flash_utils_ByteArray_readBoolean = 911;
const uint32_t flash_utils_ByteArray_readByte = 912;
const uint32_t flash_utils_ByteArray_readUnsignedByte = 913;
const uint32_t flash_utils_ByteArray_readShort = 914;
const uint32_t flash_utils_ByteArray_readUnsignedShort = 915;
const uint32_t flash_utils_ByteArray_readInt = 916;
const uint32_t flash_utils_ByteArray_readUnsignedInt = 917;
const uint32_t flash_utils_ByteArray_readFloat = 918;
const uint32_t flash_utils_ByteArray_readDouble = 919;
const uint32_t flash_utils_ByteArray_readMultiByte = 920;
const uint32_t flash_utils_ByteArray_readUTF = 921;
const uint32_t flash_utils_ByteArray_readUTFBytes = 922;
const uint32_t flash_utils_ByteArray_length_get = 923;
const uint32_t flash_utils_ByteArray_length_set = 924;
const uint32_t flash_utils_ByteArray_writeObject = 925;
const uint32_t flash_utils_ByteArray_readObject = 926;
const uint32_t flash_utils_ByteArray_private__compress = 928;
const uint32_t flash_utils_ByteArray_private__uncompress = 930;
const uint32_t flash_utils_ByteArray_private__toString = 932;
const uint32_t flash_utils_ByteArray_bytesAvailable_get = 933;
const uint32_t flash_utils_ByteArray_position_get = 934;
const uint32_t flash_utils_ByteArray_position_set = 935;
const uint32_t flash_utils_ByteArray_objectEncoding_get = 936;
const uint32_t flash_utils_ByteArray_objectEncoding_set = 937;
const uint32_t flash_utils_ByteArray_endian_get = 938;
const uint32_t flash_utils_ByteArray_endian_set = 939;
const uint32_t flash_utils_ByteArray_clear = 940;

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

#ifdef VMCFG_INDIRECT_NATIVE_THUNKS

extern avmplus::Atom builtin_a2a_os_optsAvmThunkGetConstantString_0__________thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define RegExp_AS3_exec_thunk  builtin_a2a_os_optsAvmThunkGetConstantString_0__________thunk

extern avmplus::Atom builtin_a2a_oaoa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_private__filter_thunk  builtin_a2a_oaoa_thunk
#define Array_private__map_thunk  builtin_a2a_oaoa_thunk

extern avmplus::Atom builtin_i2a_ssd_optsAvmThunkGetConstantString_58_____undefined_____opti0_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_AS3_indexOf_thunk  builtin_i2a_ssd_optsAvmThunkGetConstantString_58_____undefined_____opti0_thunk

extern double builtin_d2d_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Date_AS3_getDate_thunk  builtin_d2d_o_thunk
#define Date_AS3_getDay_thunk  builtin_d2d_o_thunk
#define Date_AS3_getFullYear_thunk  builtin_d2d_o_thunk
#define Date_AS3_getHours_thunk  builtin_d2d_o_thunk
#define Date_AS3_getMilliseconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getMinutes_thunk  builtin_d2d_o_thunk
#define Date_AS3_getMonth_thunk  builtin_d2d_o_thunk
#define Date_AS3_getSeconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getTime_thunk  builtin_d2d_o_thunk
#define Date_AS3_getTimezoneOffset_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCDate_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCDay_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCFullYear_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCHours_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCMilliseconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCMinutes_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCMonth_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCSeconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_valueOf_thunk  builtin_d2d_o_thunk
#define Math_random_thunk  builtin_d2d_o_thunk
#define Number_private__minValue_thunk  builtin_d2d_o_thunk
#define __AS3___vec_Vector_double_AS3_pop_thunk  builtin_d2d_o_thunk
#define __AS3___vec_Vector_double_AS3_shift_thunk  builtin_d2d_o_thunk
#define flash_utils_ByteArray_readDouble_thunk  builtin_d2d_o_thunk
#define flash_utils_ByteArray_readFloat_thunk  builtin_d2d_o_thunk

extern avmplus::Atom builtin_a2a_oa_optsAvmThunkGetConstantString_516___________thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define XMLList_AS3_descendants_thunk  builtin_a2a_oa_optsAvmThunkGetConstantString_516___________thunk
#define XMLList_AS3_elements_thunk  builtin_a2a_oa_optsAvmThunkGetConstantString_516___________thunk
#define XMLList_AS3_processingInstructions_thunk  builtin_a2a_oa_optsAvmThunkGetConstantString_516___________thunk
#define XML_AS3_descendants_thunk  builtin_a2a_oa_optsAvmThunkGetConstantString_516___________thunk
#define XML_AS3_elements_thunk  builtin_a2a_oa_optsAvmThunkGetConstantString_516___________thunk
#define XML_AS3_processingInstructions_thunk  builtin_a2a_oa_optsAvmThunkGetConstantString_516___________thunk

extern avmplus::Atom builtin_i2a_ssi_opti2147483647_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_private__lastIndexOf_thunk  builtin_i2a_ssi_opti2147483647_thunk

extern avmplus::Atom builtin_v2a_oouu_opti0_opti0_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define flash_utils_ByteArray_readBytes_thunk  builtin_v2a_oouu_opti0_opti0_thunk
#define flash_utils_ByteArray_writeBytes_thunk  builtin_v2a_oouu_opti0_opti0_thunk

extern avmplus::Atom builtin_a2a_osa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_private__match_thunk  builtin_a2a_osa_thunk

extern double builtin_func_d2d_osi_optsAvmThunkGetConstantString_60_____NaN_____opti0_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_parseInt_thunk  builtin_func_d2d_osi_optsAvmThunkGetConstantString_60_____NaN_____opti0_thunk

extern avmplus::Atom builtin_func_b2a_od_optaundefinedAtom_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_isFinite_thunk  builtin_func_b2a_od_optaundefinedAtom_thunk
#define native_script_function_isNaN_thunk  builtin_func_b2a_od_optaundefinedAtom_thunk

extern avmplus::Atom builtin_func_s2a_oa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_avmplus_getQualifiedClassName_thunk  builtin_func_s2a_oa_thunk
#define native_script_function_avmplus_getQualifiedSuperclassName_thunk  builtin_func_s2a_oa_thunk

extern avmplus::Atom builtin_func_b2a_oa_optaundefinedAtom_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_isXMLName_thunk  builtin_func_b2a_oa_optaundefinedAtom_thunk

extern avmplus::Atom builtin_u2a_oao_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_private__unshift_thunk  builtin_u2a_oao_thunk

extern avmplus::Atom builtin_a2a_oo_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define XML_AS3_setNotification_thunk  builtin_a2a_oo_thunk

extern avmplus::Atom builtin_s2a_n_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Namespace_uri_get_thunk  builtin_s2a_n_thunk

extern avmplus::Atom builtin_s2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Error_getStackTrace_thunk  builtin_s2a_o_thunk
#define QName_localName_get_thunk  builtin_s2a_o_thunk
#define RegExp_source_get_thunk  builtin_s2a_o_thunk
#define XMLList_AS3_nodeKind_thunk  builtin_s2a_o_thunk
#define XMLList_AS3_toString_thunk  builtin_s2a_o_thunk
#define XMLList_AS3_toXMLString_thunk  builtin_s2a_o_thunk
#define XML_AS3_nodeKind_thunk  builtin_s2a_o_thunk
#define XML_AS3_toString_thunk  builtin_s2a_o_thunk
#define XML_AS3_toXMLString_thunk  builtin_s2a_o_thunk
#define flash_utils_ByteArray_endian_get_thunk  builtin_s2a_o_thunk
#define flash_utils_ByteArray_private__toString_thunk  builtin_s2a_o_thunk
#define flash_utils_ByteArray_readUTF_thunk  builtin_s2a_o_thunk

extern avmplus::Atom builtin_s2a_odi_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Number_private__numberToString_thunk  builtin_s2a_odi_thunk

extern avmplus::Atom builtin_v2a_ou_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_length_set_thunk  builtin_v2a_ou_thunk
#define __AS3___vec_Vector_double_length_set_thunk  builtin_v2a_ou_thunk
#define __AS3___vec_Vector_int_length_set_thunk  builtin_v2a_ou_thunk
#define __AS3___vec_Vector_object_length_set_thunk  builtin_v2a_ou_thunk
#define __AS3___vec_Vector_uint_length_set_thunk  builtin_v2a_ou_thunk
#define flash_utils_ByteArray_defaultObjectEncoding_set_thunk  builtin_v2a_ou_thunk
#define flash_utils_ByteArray_length_set_thunk  builtin_v2a_ou_thunk
#define flash_utils_ByteArray_objectEncoding_set_thunk  builtin_v2a_ou_thunk
#define flash_utils_ByteArray_position_set_thunk  builtin_v2a_ou_thunk
#define flash_utils_ByteArray_writeUnsignedInt_thunk  builtin_v2a_ou_thunk

extern avmplus::Atom builtin_a2a_oa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_private__pop_thunk  builtin_a2a_oa_thunk
#define Array_private__reverse_thunk  builtin_a2a_oa_thunk
#define Array_private__shift_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_addNamespace_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_appendChild_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_attribute_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_child_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_prependChild_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_removeNamespace_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_setChildren_thunk  builtin_a2a_oa_thunk
#define XML_AS3_addNamespace_thunk  builtin_a2a_oa_thunk
#define XML_AS3_appendChild_thunk  builtin_a2a_oa_thunk
#define XML_AS3_attribute_thunk  builtin_a2a_oa_thunk
#define XML_AS3_child_thunk  builtin_a2a_oa_thunk
#define XML_AS3_prependChild_thunk  builtin_a2a_oa_thunk
#define XML_AS3_removeNamespace_thunk  builtin_a2a_oa_thunk
#define XML_AS3_setChildren_thunk  builtin_a2a_oa_thunk

extern avmplus::Atom builtin_func_a2a_oau_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_avmplus_describeTypeJSON_thunk  builtin_func_a2a_oau_thunk

extern avmplus::Atom builtin_v2a_ouuuau_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define __AS3___vec_Vector_double_private__spliceHelper_thunk  builtin_v2a_ouuuau_thunk
#define __AS3___vec_Vector_int_private__spliceHelper_thunk  builtin_v2a_ouuuau_thunk
#define __AS3___vec_Vector_object_private__spliceHelper_thunk  builtin_v2a_ouuuau_thunk
#define __AS3___vec_Vector_uint_private__spliceHelper_thunk  builtin_v2a_ouuuau_thunk

extern double builtin_d2d_o_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Date_private__setDate_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setFullYear_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setHours_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setMilliseconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setMinutes_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setMonth_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setSeconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCDate_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCFullYear_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCHours_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCMilliseconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCMinutes_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCMonth_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCSeconds_thunk  builtin_d2d_o_rest_thunk

extern avmplus::Atom builtin_v2a_oss_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define flash_utils_ByteArray_writeMultiByte_thunk  builtin_v2a_oss_thunk

extern double builtin_d2d_oaaaaaaa_opti1_opti0_opti0_opti0_opti0_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Date_UTC_thunk  builtin_d2d_oaaaaaaa_opti1_opti0_opti0_opti0_opti0_rest_thunk

extern avmplus::Atom builtin_i2a_s_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_length_get_thunk  builtin_i2a_s_thunk

extern double builtin_d2d_odd_optdMathUtils_kInfinity_optdMathUtils_kInfinity_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Math_min_thunk  builtin_d2d_odd_optdMathUtils_kInfinity_optdMathUtils_kInfinity_rest_thunk

extern avmplus::Atom builtin_b2a_oaa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Object_private__isPrototypeOf_thunk  builtin_b2a_oaa_thunk

extern avmplus::Atom builtin_a2a_oaaa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_private__sortOn_thunk  builtin_a2a_oaaa_thunk

extern avmplus::Atom builtin_u2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_double_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_int_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_object_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_uint_AS3_pop_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_uint_AS3_shift_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_uint_length_get_thunk  builtin_u2a_o_thunk
#define flash_utils_ByteArray_bytesAvailable_get_thunk  builtin_u2a_o_thunk
#define flash_utils_ByteArray_defaultObjectEncoding_get_thunk  builtin_u2a_o_thunk
#define flash_utils_ByteArray_length_get_thunk  builtin_u2a_o_thunk
#define flash_utils_ByteArray_objectEncoding_get_thunk  builtin_u2a_o_thunk
#define flash_utils_ByteArray_position_get_thunk  builtin_u2a_o_thunk
#define flash_utils_ByteArray_readUnsignedByte_thunk  builtin_u2a_o_thunk
#define flash_utils_ByteArray_readUnsignedInt_thunk  builtin_u2a_o_thunk
#define flash_utils_ByteArray_readUnsignedShort_thunk  builtin_u2a_o_thunk

extern avmplus::Atom builtin_i2a_ssd_optsAvmThunkGetConstantString_58_____undefined_____opti2147483647_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_AS3_lastIndexOf_thunk  builtin_i2a_ssd_optsAvmThunkGetConstantString_58_____undefined_____opti2147483647_thunk

extern avmplus::Atom builtin_func_s2a_os_optsAvmThunkGetConstantString_58_____undefined_____thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_decodeURI_thunk  builtin_func_s2a_os_optsAvmThunkGetConstantString_58_____undefined_____thunk
#define native_script_function_decodeURIComponent_thunk  builtin_func_s2a_os_optsAvmThunkGetConstantString_58_____undefined_____thunk
#define native_script_function_encodeURI_thunk  builtin_func_s2a_os_optsAvmThunkGetConstantString_58_____undefined_____thunk
#define native_script_function_encodeURIComponent_thunk  builtin_func_s2a_os_optsAvmThunkGetConstantString_58_____undefined_____thunk
#define native_script_function_escape_thunk  builtin_func_s2a_os_optsAvmThunkGetConstantString_58_____undefined_____thunk
#define native_script_function_unescape_thunk  builtin_func_s2a_os_optsAvmThunkGetConstantString_58_____undefined_____thunk

extern avmplus::Atom builtin_s2a_osaa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_private__replace_thunk  builtin_s2a_osaa_thunk

extern avmplus::Atom builtin_b2a_oas_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Object_private__hasOwnProperty_thunk  builtin_b2a_oas_thunk
#define Object_private__propertyIsEnumerable_thunk  builtin_b2a_oas_thunk

extern avmplus::Atom builtin_i2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Function_length_get_thunk  builtin_i2a_o_thunk
#define RegExp_lastIndex_get_thunk  builtin_i2a_o_thunk
#define XMLList_AS3_childIndex_thunk  builtin_i2a_o_thunk
#define XMLList_AS3_length_thunk  builtin_i2a_o_thunk
#define XML_AS3_childIndex_thunk  builtin_i2a_o_thunk
#define XML_prettyIndent_get_thunk  builtin_i2a_o_thunk
#define __AS3___vec_Vector_int_AS3_pop_thunk  builtin_i2a_o_thunk
#define __AS3___vec_Vector_int_AS3_shift_thunk  builtin_i2a_o_thunk
#define flash_utils_ByteArray_readByte_thunk  builtin_i2a_o_thunk
#define flash_utils_ByteArray_readInt_thunk  builtin_i2a_o_thunk
#define flash_utils_ByteArray_readShort_thunk  builtin_i2a_o_thunk

extern double builtin_func_d2d_os_optsAvmThunkGetConstantString_60_____NaN_____thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_parseFloat_thunk  builtin_func_d2d_os_optsAvmThunkGetConstantString_60_____NaN_____thunk

extern double builtin_d2d_sd_opti0_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_AS3_charCodeAt_thunk  builtin_d2d_sd_opti0_thunk

extern avmplus::Atom builtin_s2a_oa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Object_private__toString_thunk  builtin_s2a_oa_thunk

extern avmplus::Atom builtin_b2a_oaoa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_private__every_thunk  builtin_b2a_oaoa_thunk
#define Array_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_double_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_double_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_int_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_int_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_object_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_object_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_uint_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_uint_private__some_thunk  builtin_b2a_oaoa_thunk

extern avmplus::Atom builtin_v2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define __AS3___vec_Vector_double_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_int_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_object_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_uint_private__reverse_thunk  builtin_v2a_o_thunk
#define flash_utils_ByteArray_clear_thunk  builtin_v2a_o_thunk

extern avmplus::Atom builtin_b2a_oa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define XMLList_AS3_contains_thunk  builtin_b2a_oa_thunk
#define XML_AS3_contains_thunk  builtin_b2a_oa_thunk

extern avmplus::Atom builtin_s2a_sd_opti0_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_AS3_charAt_thunk  builtin_s2a_sd_opti0_thunk

extern avmplus::Atom builtin_v2a_oaoa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_double_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_int_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_object_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_uint_private__forEach_thunk  builtin_v2a_oaoa_thunk

extern avmplus::Atom builtin_s2a_ou_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define flash_utils_ByteArray_readUTFBytes_thunk  builtin_s2a_ou_thunk

extern avmplus::Atom builtin_a2a_ooa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define __AS3___vec_Vector_double_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_double_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_int_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_int_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_object_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_object_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_uint_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_uint_private__map_thunk  builtin_a2a_ooa_thunk

extern avmplus::Atom builtin_a2a_oa_optaundefinedAtom_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Function_AS3_call_thunk  builtin_a2a_oa_optaundefinedAtom_rest_thunk

extern avmplus::Atom builtin_u2a_o_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define Array_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_double_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_double_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_int_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_int_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_object_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_object_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_uint_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_uint_AS3_unshift_thunk  builtin_u2a_o_rest_thunk

extern avmplus::Atom builtin_s2a_s_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_AS3_toLowerCase_thunk  builtin_s2a_s_thunk
#define String_AS3_toUpperCase_thunk  builtin_s2a_s_thunk

extern avmplus::Atom builtin_s2a_sdd_opti0_opti2147483647_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_AS3_slice_thunk  builtin_s2a_sdd_opti0_opti2147483647_thunk
#define String_AS3_substr_thunk  builtin_s2a_sdd_opti0_opti2147483647_thunk
#define String_AS3_substring_thunk  builtin_s2a_sdd_opti0_opti2147483647_thunk

extern double builtin_d2d_odd_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Math_atan2_thunk  builtin_d2d_odd_thunk
#define Math_pow_thunk  builtin_d2d_odd_thunk
#define Math_private__max_thunk  builtin_d2d_odd_thunk
#define Math_private__min_thunk  builtin_d2d_odd_thunk

extern avmplus::Atom builtin_a2a_n_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Namespace_prefix_get_thunk  builtin_a2a_n_thunk

extern avmplus::Atom builtin_a2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_AS3_pop_thunk  builtin_a2a_o_thunk
#define Class_prototype_get_thunk  builtin_a2a_o_thunk
#define Function_prototype_get_thunk  builtin_a2a_o_thunk
#define QName_uri_get_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_attributes_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_children_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_comments_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_copy_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_inScopeNamespaces_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_localName_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_name_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_namespaceDeclarations_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_normalize_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_parent_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_text_thunk  builtin_a2a_o_thunk
#define XML_AS3_attributes_thunk  builtin_a2a_o_thunk
#define XML_AS3_children_thunk  builtin_a2a_o_thunk
#define XML_AS3_comments_thunk  builtin_a2a_o_thunk
#define XML_AS3_copy_thunk  builtin_a2a_o_thunk
#define XML_AS3_inScopeNamespaces_thunk  builtin_a2a_o_thunk
#define XML_AS3_localName_thunk  builtin_a2a_o_thunk
#define XML_AS3_name_thunk  builtin_a2a_o_thunk
#define XML_AS3_namespaceDeclarations_thunk  builtin_a2a_o_thunk
#define XML_AS3_normalize_thunk  builtin_a2a_o_thunk
#define XML_AS3_notification_thunk  builtin_a2a_o_thunk
#define XML_AS3_parent_thunk  builtin_a2a_o_thunk
#define XML_AS3_text_thunk  builtin_a2a_o_thunk
#define __AS3___vec_Vector_double_private_newThisType_thunk  builtin_a2a_o_thunk
#define __AS3___vec_Vector_int_private_newThisType_thunk  builtin_a2a_o_thunk
#define __AS3___vec_Vector_object_AS3_pop_thunk  builtin_a2a_o_thunk
#define __AS3___vec_Vector_object_AS3_shift_thunk  builtin_a2a_o_thunk
#define __AS3___vec_Vector_object_private_newThisType_thunk  builtin_a2a_o_thunk
#define __AS3___vec_Vector_uint_private_newThisType_thunk  builtin_a2a_o_thunk
#define flash_utils_ByteArray_readObject_thunk  builtin_a2a_o_thunk

extern avmplus::Atom builtin_i2a_sa_optaundefinedAtom_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_AS3_localeCompare_thunk  builtin_i2a_sa_optaundefinedAtom_thunk

extern avmplus::Atom builtin_v2a_oasb_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Object_protected__setPropertyIsEnumerable_thunk  builtin_v2a_oasb_thunk

extern avmplus::Atom builtin_a2a_oaa_optaundefinedAtom_optaundefinedAtom_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Function_AS3_apply_thunk  builtin_a2a_oaa_optaundefinedAtom_optaundefinedAtom_thunk

extern avmplus::Atom builtin_a2a_osau_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_private__split_thunk  builtin_a2a_osau_thunk

extern avmplus::Atom builtin_a2a_oai_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define XMLList_private__namespace_thunk  builtin_a2a_oai_thunk
#define XML_private__namespace_thunk  builtin_a2a_oai_thunk

extern avmplus::Atom builtin_s2a_oi_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Date_private__toString_thunk  builtin_s2a_oi_thunk
#define Error_getErrorMessage_thunk  builtin_s2a_oi_thunk

extern avmplus::Atom builtin_i2a_ssi_opti0_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_private__indexOf_thunk  builtin_i2a_ssi_opti0_thunk

extern avmplus::Atom builtin_s2a_o_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_AS3_fromCharCode_thunk  builtin_s2a_o_rest_thunk

extern avmplus::Atom builtin_i2a_oaai_opti0_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_private__lastIndexOf_thunk  builtin_i2a_oaai_opti0_thunk

extern double builtin_d2d_od_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Date_private__setTime_thunk  builtin_d2d_od_thunk
#define Math_abs_thunk  builtin_d2d_od_thunk
#define Math_acos_thunk  builtin_d2d_od_thunk
#define Math_asin_thunk  builtin_d2d_od_thunk
#define Math_atan_thunk  builtin_d2d_od_thunk
#define Math_ceil_thunk  builtin_d2d_od_thunk
#define Math_cos_thunk  builtin_d2d_od_thunk
#define Math_exp_thunk  builtin_d2d_od_thunk
#define Math_floor_thunk  builtin_d2d_od_thunk
#define Math_log_thunk  builtin_d2d_od_thunk
#define Math_round_thunk  builtin_d2d_od_thunk
#define Math_sin_thunk  builtin_d2d_od_thunk
#define Math_sqrt_thunk  builtin_d2d_od_thunk
#define Math_tan_thunk  builtin_d2d_od_thunk

extern avmplus::Atom builtin_v2a_od_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define flash_utils_ByteArray_writeDouble_thunk  builtin_v2a_od_thunk
#define flash_utils_ByteArray_writeFloat_thunk  builtin_v2a_od_thunk

extern avmplus::Atom builtin_s2a_sii_opti0_opti2147483647_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_private__slice_thunk  builtin_s2a_sii_opti0_opti2147483647_thunk
#define String_private__substr_thunk  builtin_s2a_sii_opti0_opti2147483647_thunk
#define String_private__substring_thunk  builtin_s2a_sii_opti0_opti2147483647_thunk

extern avmplus::Atom builtin_v2a_ob_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define XML_ignoreComments_set_thunk  builtin_v2a_ob_thunk
#define XML_ignoreProcessingInstructions_set_thunk  builtin_v2a_ob_thunk
#define XML_ignoreWhitespace_set_thunk  builtin_v2a_ob_thunk
#define XML_prettyPrinting_set_thunk  builtin_v2a_ob_thunk
#define __AS3___vec_Vector_double_fixed_set_thunk  builtin_v2a_ob_thunk
#define __AS3___vec_Vector_int_fixed_set_thunk  builtin_v2a_ob_thunk
#define __AS3___vec_Vector_object_fixed_set_thunk  builtin_v2a_ob_thunk
#define __AS3___vec_Vector_uint_fixed_set_thunk  builtin_v2a_ob_thunk
#define flash_utils_ByteArray_writeBoolean_thunk  builtin_v2a_ob_thunk

extern avmplus::Atom builtin_v2a_oa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Function_prototype_set_thunk  builtin_v2a_oa_thunk
#define XMLList_AS3_setLocalName_thunk  builtin_v2a_oa_thunk
#define XMLList_AS3_setName_thunk  builtin_v2a_oa_thunk
#define XMLList_AS3_setNamespace_thunk  builtin_v2a_oa_thunk
#define XML_AS3_setLocalName_thunk  builtin_v2a_oa_thunk
#define XML_AS3_setName_thunk  builtin_v2a_oa_thunk
#define XML_AS3_setNamespace_thunk  builtin_v2a_oa_thunk
#define flash_utils_ByteArray_writeObject_thunk  builtin_v2a_oa_thunk

extern double builtin_d2d_oa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Date_parse_thunk  builtin_d2d_oa_thunk

extern avmplus::Atom builtin_func_b2a_oi_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define native_script_function_bugzilla_thunk  builtin_func_b2a_oi_thunk

extern avmplus::Atom builtin_v2a_oi_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define RegExp_lastIndex_set_thunk  builtin_v2a_oi_thunk
#define XML_prettyIndent_set_thunk  builtin_v2a_oi_thunk
#define flash_utils_ByteArray_writeByte_thunk  builtin_v2a_oi_thunk
#define flash_utils_ByteArray_writeInt_thunk  builtin_v2a_oi_thunk
#define flash_utils_ByteArray_writeShort_thunk  builtin_v2a_oi_thunk

extern double builtin_d2d_oi_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Date_private__get_thunk  builtin_d2d_oi_thunk

extern avmplus::Atom builtin_a2a_oaa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define XMLList_AS3_insertChildAfter_thunk  builtin_a2a_oaa_thunk
#define XMLList_AS3_insertChildBefore_thunk  builtin_a2a_oaa_thunk
#define XMLList_AS3_replace_thunk  builtin_a2a_oaa_thunk
#define XML_AS3_insertChildAfter_thunk  builtin_a2a_oaa_thunk
#define XML_AS3_insertChildBefore_thunk  builtin_a2a_oaa_thunk
#define XML_AS3_replace_thunk  builtin_a2a_oaa_thunk

extern avmplus::Atom builtin_b2a_o_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define RegExp_dotall_get_thunk  builtin_b2a_o_thunk
#define RegExp_extended_get_thunk  builtin_b2a_o_thunk
#define RegExp_global_get_thunk  builtin_b2a_o_thunk
#define RegExp_ignoreCase_get_thunk  builtin_b2a_o_thunk
#define RegExp_multiline_get_thunk  builtin_b2a_o_thunk
#define XMLList_AS3_hasComplexContent_thunk  builtin_b2a_o_thunk
#define XMLList_AS3_hasSimpleContent_thunk  builtin_b2a_o_thunk
#define XML_AS3_hasComplexContent_thunk  builtin_b2a_o_thunk
#define XML_AS3_hasSimpleContent_thunk  builtin_b2a_o_thunk
#define XML_ignoreComments_get_thunk  builtin_b2a_o_thunk
#define XML_ignoreProcessingInstructions_get_thunk  builtin_b2a_o_thunk
#define XML_ignoreWhitespace_get_thunk  builtin_b2a_o_thunk
#define XML_prettyPrinting_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_double_fixed_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_int_fixed_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_object_fixed_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_uint_fixed_get_thunk  builtin_b2a_o_thunk
#define flash_utils_ByteArray_readBoolean_thunk  builtin_b2a_o_thunk

extern avmplus::Atom builtin_i2a_osa_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define String_private__search_thunk  builtin_i2a_osa_thunk

extern avmplus::Atom builtin_v2a_os_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define flash_utils_ByteArray_endian_set_thunk  builtin_v2a_os_thunk
#define flash_utils_ByteArray_private__compress_thunk  builtin_v2a_os_thunk
#define flash_utils_ByteArray_private__uncompress_thunk  builtin_v2a_os_thunk
#define flash_utils_ByteArray_writeUTF_thunk  builtin_v2a_os_thunk
#define flash_utils_ByteArray_writeUTFBytes_thunk  builtin_v2a_os_thunk

extern avmplus::Atom builtin_a2a_oadd_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_private__slice_thunk  builtin_a2a_oadd_thunk

extern avmplus::Atom builtin_b2a_oa_optaundefinedAtom_u_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define XMLList_AS3_hasOwnProperty_thunk  builtin_b2a_oa_optaundefinedAtom_u_thunk
#define XMLList_AS3_propertyIsEnumerable_thunk  builtin_b2a_oa_optaundefinedAtom_u_thunk
#define XML_AS3_hasOwnProperty_thunk  builtin_b2a_oa_optaundefinedAtom_u_thunk
#define XML_AS3_propertyIsEnumerable_thunk  builtin_b2a_oa_optaundefinedAtom_u_thunk

extern double builtin_d2d_odd_optdMathUtils_kNegInfinity_optdMathUtils_kNegInfinity_rest_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Math_max_thunk  builtin_d2d_odd_optdMathUtils_kNegInfinity_optdMathUtils_kNegInfinity_rest_thunk

extern avmplus::Atom builtin_i2a_oaai_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_private__indexOf_thunk  builtin_i2a_oaai_thunk

extern avmplus::Atom builtin_s2a_odii_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Number_private__convert_thunk  builtin_s2a_odii_thunk

extern avmplus::Atom builtin_s2a_ous_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define flash_utils_ByteArray_readMultiByte_thunk  builtin_s2a_ous_thunk

extern avmplus::Atom builtin_a2a_oao_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
#define Array_private__concat_thunk  builtin_a2a_oao_thunk
#define Array_private__sort_thunk  builtin_a2a_oao_thunk
#define Array_private__splice_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_double_private__sort_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_int_private__sort_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_object_private__sort_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_uint_private__sort_thunk  builtin_a2a_oao_thunk

#endif // VMCFG_INDIRECT_NATIVE_THUNKS

class SlotOffsetsAndAsserts;
// Object$
//-----------------------------------------------------------
class ObjectClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_ObjectClass
};
#define DECLARE_SLOTS_ObjectClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_ObjectClass.get_length(); } \
    private: \
        avmplus::NativeID::ObjectClassSlots m_slots_ObjectClass
//-----------------------------------------------------------

// Class$
//-----------------------------------------------------------
class ClassClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_ClassClass
};
#define DECLARE_SLOTS_ClassClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_ClassClass.get_length(); } \
    private: \
        avmplus::NativeID::ClassClassSlots m_slots_ClassClass
//-----------------------------------------------------------

// Class
//-----------------------------------------------------------
class ClassClosureSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_ClassClosure
};
#define DECLARE_SLOTS_ClassClosure \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::ClassClosureSlots EmptySlotsStruct_ClassClosure
//-----------------------------------------------------------

// Function$
//-----------------------------------------------------------
class FunctionClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_FunctionClass
};
#define DECLARE_SLOTS_FunctionClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_FunctionClass.get_length(); } \
    private: \
        avmplus::NativeID::FunctionClassSlots m_slots_FunctionClass
//-----------------------------------------------------------

// Function
//-----------------------------------------------------------
class FunctionObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_FunctionObject
};
#define DECLARE_SLOTS_FunctionObject \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::FunctionObjectSlots EmptySlotsStruct_FunctionObject
//-----------------------------------------------------------

// Namespace$
//-----------------------------------------------------------
class NamespaceClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::Atom get_length() const { return m_length; }
private:
    ATOM_WB m_length;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceAtom(&m_length);
    }
};
#define DECLARE_SLOTS_NamespaceClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmplus::Atom get_length() const { return m_slots_NamespaceClass.get_length(); } \
    private: \
        avmplus::NativeID::NamespaceClassSlots m_slots_NamespaceClass
//-----------------------------------------------------------

// Boolean$
//-----------------------------------------------------------
class BooleanClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_BooleanClass
};
#define DECLARE_SLOTS_BooleanClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_BooleanClass.get_length(); } \
    private: \
        avmplus::NativeID::BooleanClassSlots m_slots_BooleanClass
//-----------------------------------------------------------

// Number$
//-----------------------------------------------------------
class NumberClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
    REALLY_INLINE int32_t get_private_DTOSTR_FIXED() const { return m_private_DTOSTR_FIXED; }
    REALLY_INLINE int32_t get_private_DTOSTR_PRECISION() const { return m_private_DTOSTR_PRECISION; }
    REALLY_INLINE int32_t get_private_DTOSTR_EXPONENTIAL() const { return m_private_DTOSTR_EXPONENTIAL; }
    REALLY_INLINE double get_NaN() const { return m_NaN; }
    REALLY_INLINE double get_NEGATIVE_INFINITY() const { return m_NEGATIVE_INFINITY; }
    REALLY_INLINE double get_POSITIVE_INFINITY() const { return m_POSITIVE_INFINITY; }
    REALLY_INLINE double get_MIN_VALUE() const { return m_MIN_VALUE; }
    REALLY_INLINE double get_MAX_VALUE() const { return m_MAX_VALUE; }
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
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_NumberClass.get_length(); } \
        REALLY_INLINE int32_t get_private_DTOSTR_FIXED() const { return m_slots_NumberClass.get_private_DTOSTR_FIXED(); } \
        REALLY_INLINE int32_t get_private_DTOSTR_PRECISION() const { return m_slots_NumberClass.get_private_DTOSTR_PRECISION(); } \
        REALLY_INLINE int32_t get_private_DTOSTR_EXPONENTIAL() const { return m_slots_NumberClass.get_private_DTOSTR_EXPONENTIAL(); } \
        REALLY_INLINE double get_NaN() const { return m_slots_NumberClass.get_NaN(); } \
        REALLY_INLINE double get_NEGATIVE_INFINITY() const { return m_slots_NumberClass.get_NEGATIVE_INFINITY(); } \
        REALLY_INLINE double get_POSITIVE_INFINITY() const { return m_slots_NumberClass.get_POSITIVE_INFINITY(); } \
        REALLY_INLINE double get_MIN_VALUE() const { return m_slots_NumberClass.get_MIN_VALUE(); } \
        REALLY_INLINE double get_MAX_VALUE() const { return m_slots_NumberClass.get_MAX_VALUE(); } \
    private: \
        avmplus::NativeID::NumberClassSlots m_slots_NumberClass
//-----------------------------------------------------------

// int$
//-----------------------------------------------------------
class IntClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_MIN_VALUE() const { return m_MIN_VALUE; }
    REALLY_INLINE int32_t get_MAX_VALUE() const { return m_MAX_VALUE; }
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_MIN_VALUE;
    int32_t m_MAX_VALUE;
    int32_t m_length;
#define GC_TRIVIAL_TRACER_IntClass
};
#define DECLARE_SLOTS_IntClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_MIN_VALUE() const { return m_slots_IntClass.get_MIN_VALUE(); } \
        REALLY_INLINE int32_t get_MAX_VALUE() const { return m_slots_IntClass.get_MAX_VALUE(); } \
        REALLY_INLINE int32_t get_length() const { return m_slots_IntClass.get_length(); } \
    private: \
        avmplus::NativeID::IntClassSlots m_slots_IntClass
//-----------------------------------------------------------

// uint$
//-----------------------------------------------------------
class UIntClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE uint32_t get_MIN_VALUE() const { return m_MIN_VALUE; }
    REALLY_INLINE uint32_t get_MAX_VALUE() const { return m_MAX_VALUE; }
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    uint32_t m_MIN_VALUE;
    uint32_t m_MAX_VALUE;
    int32_t m_length;
#define GC_TRIVIAL_TRACER_UIntClass
};
#define DECLARE_SLOTS_UIntClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE uint32_t get_MIN_VALUE() const { return m_slots_UIntClass.get_MIN_VALUE(); } \
        REALLY_INLINE uint32_t get_MAX_VALUE() const { return m_slots_UIntClass.get_MAX_VALUE(); } \
        REALLY_INLINE int32_t get_length() const { return m_slots_UIntClass.get_length(); } \
    private: \
        avmplus::NativeID::UIntClassSlots m_slots_UIntClass
//-----------------------------------------------------------

// String$
//-----------------------------------------------------------
class StringClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_StringClass
};
#define DECLARE_SLOTS_StringClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_StringClass.get_length(); } \
    private: \
        avmplus::NativeID::StringClassSlots m_slots_StringClass
//-----------------------------------------------------------

// Array$
//-----------------------------------------------------------
class ArrayClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE uint32_t get_CASEINSENSITIVE() const { return m_CASEINSENSITIVE; }
    REALLY_INLINE uint32_t get_DESCENDING() const { return m_DESCENDING; }
    REALLY_INLINE uint32_t get_UNIQUESORT() const { return m_UNIQUESORT; }
    REALLY_INLINE uint32_t get_RETURNINDEXEDARRAY() const { return m_RETURNINDEXEDARRAY; }
    REALLY_INLINE uint32_t get_NUMERIC() const { return m_NUMERIC; }
    REALLY_INLINE int32_t get_length() const { return m_length; }
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
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE uint32_t get_CASEINSENSITIVE() const { return m_slots_ArrayClass.get_CASEINSENSITIVE(); } \
        REALLY_INLINE uint32_t get_DESCENDING() const { return m_slots_ArrayClass.get_DESCENDING(); } \
        REALLY_INLINE uint32_t get_UNIQUESORT() const { return m_slots_ArrayClass.get_UNIQUESORT(); } \
        REALLY_INLINE uint32_t get_RETURNINDEXEDARRAY() const { return m_slots_ArrayClass.get_RETURNINDEXEDARRAY(); } \
        REALLY_INLINE uint32_t get_NUMERIC() const { return m_slots_ArrayClass.get_NUMERIC(); } \
        REALLY_INLINE int32_t get_length() const { return m_slots_ArrayClass.get_length(); } \
    private: \
        avmplus::NativeID::ArrayClassSlots m_slots_ArrayClass
//-----------------------------------------------------------

// Array
//-----------------------------------------------------------
class ArrayObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_ArrayObject
};
#define DECLARE_SLOTS_ArrayObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::ArrayObjectSlots EmptySlotsStruct_ArrayObject
//-----------------------------------------------------------

// __AS3__.vec::Vector$
//-----------------------------------------------------------
class VectorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_VectorClass
};
#define DECLARE_SLOTS_VectorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::VectorClassSlots EmptySlotsStruct_VectorClass
//-----------------------------------------------------------

// __AS3__.vec::Vector
//-----------------------------------------------------------
class ObjectVectorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_ObjectVectorObject
};
#define DECLARE_SLOTS_ObjectVectorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::ObjectVectorObjectSlots EmptySlotsStruct_ObjectVectorObject
//-----------------------------------------------------------

// __AS3__.vec::Vector$object$
//-----------------------------------------------------------
class ObjectVectorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_ObjectVectorClass
};
#define DECLARE_SLOTS_ObjectVectorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::ObjectVectorClassSlots EmptySlotsStruct_ObjectVectorClass
//-----------------------------------------------------------

// __AS3__.vec::Vector$int$
//-----------------------------------------------------------
class IntVectorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_IntVectorClass
};
#define DECLARE_SLOTS_IntVectorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::IntVectorClassSlots EmptySlotsStruct_IntVectorClass
//-----------------------------------------------------------

// __AS3__.vec::Vector$int
//-----------------------------------------------------------
class IntVectorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_IntVectorObject
};
#define DECLARE_SLOTS_IntVectorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::IntVectorObjectSlots EmptySlotsStruct_IntVectorObject
//-----------------------------------------------------------

// __AS3__.vec::Vector$uint$
//-----------------------------------------------------------
class UIntVectorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_UIntVectorClass
};
#define DECLARE_SLOTS_UIntVectorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::UIntVectorClassSlots EmptySlotsStruct_UIntVectorClass
//-----------------------------------------------------------

// __AS3__.vec::Vector$uint
//-----------------------------------------------------------
class UIntVectorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_UIntVectorObject
};
#define DECLARE_SLOTS_UIntVectorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::UIntVectorObjectSlots EmptySlotsStruct_UIntVectorObject
//-----------------------------------------------------------

// __AS3__.vec::Vector$double$
//-----------------------------------------------------------
class DoubleVectorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DoubleVectorClass
};
#define DECLARE_SLOTS_DoubleVectorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DoubleVectorClassSlots EmptySlotsStruct_DoubleVectorClass
//-----------------------------------------------------------

// __AS3__.vec::Vector$double
//-----------------------------------------------------------
class DoubleVectorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DoubleVectorObject
};
#define DECLARE_SLOTS_DoubleVectorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DoubleVectorObjectSlots EmptySlotsStruct_DoubleVectorObject
//-----------------------------------------------------------

// private::MethodClosure$
//-----------------------------------------------------------
class MethodClosureClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_MethodClosureClass
};
#define DECLARE_SLOTS_MethodClosureClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::MethodClosureClassSlots EmptySlotsStruct_MethodClosureClass
//-----------------------------------------------------------

// private::MethodClosure
//-----------------------------------------------------------
class MethodClosureSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_MethodClosure
};
#define DECLARE_SLOTS_MethodClosure \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::MethodClosureSlots EmptySlotsStruct_MethodClosure
//-----------------------------------------------------------

// Math$
//-----------------------------------------------------------
class MathClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE double get_E() const { return m_E; }
    REALLY_INLINE double get_LN10() const { return m_LN10; }
    REALLY_INLINE double get_LN2() const { return m_LN2; }
    REALLY_INLINE double get_LOG10E() const { return m_LOG10E; }
    REALLY_INLINE double get_LOG2E() const { return m_LOG2E; }
    REALLY_INLINE double get_PI() const { return m_PI; }
    REALLY_INLINE double get_SQRT1_2() const { return m_SQRT1_2; }
    REALLY_INLINE double get_SQRT2() const { return m_SQRT2; }
    REALLY_INLINE double get_private_NegInfinity() const { return m_private_NegInfinity; }
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
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE double get_E() const { return m_slots_MathClass.get_E(); } \
        REALLY_INLINE double get_LN10() const { return m_slots_MathClass.get_LN10(); } \
        REALLY_INLINE double get_LN2() const { return m_slots_MathClass.get_LN2(); } \
        REALLY_INLINE double get_LOG10E() const { return m_slots_MathClass.get_LOG10E(); } \
        REALLY_INLINE double get_LOG2E() const { return m_slots_MathClass.get_LOG2E(); } \
        REALLY_INLINE double get_PI() const { return m_slots_MathClass.get_PI(); } \
        REALLY_INLINE double get_SQRT1_2() const { return m_slots_MathClass.get_SQRT1_2(); } \
        REALLY_INLINE double get_SQRT2() const { return m_slots_MathClass.get_SQRT2(); } \
        REALLY_INLINE double get_private_NegInfinity() const { return m_slots_MathClass.get_private_NegInfinity(); } \
    private: \
        avmplus::NativeID::MathClassSlots m_slots_MathClass
//-----------------------------------------------------------

// Error$
//-----------------------------------------------------------
class ErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_ErrorClass
};
#define DECLARE_SLOTS_ErrorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_ErrorClass.get_length(); } \
    private: \
        avmplus::NativeID::ErrorClassSlots m_slots_ErrorClass
//-----------------------------------------------------------

// Error
//-----------------------------------------------------------
class ErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_private__errorID() const { return m_private__errorID; }
    REALLY_INLINE void set_private__errorID(int32_t newVal) { m_private__errorID = newVal; }
    REALLY_INLINE avmplus::Atom get_message() const { return m_message; }
    REALLY_INLINE void set_message(avmplus::Atom newVal) { m_message = newVal; }
    REALLY_INLINE avmplus::Atom get_name() const { return m_name; }
    REALLY_INLINE void set_name(avmplus::Atom newVal) { m_name = newVal; }
private:
    int32_t m_private__errorID;
    ATOM_WB m_message;
    ATOM_WB m_name;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceAtom(&m_message);
        gc->TraceAtom(&m_name);
    }
};
#define DECLARE_SLOTS_ErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_private__errorID() const { return m_slots_ErrorObject.get_private__errorID(); } \
        REALLY_INLINE void set_private__errorID(int32_t newVal) { m_slots_ErrorObject.set_private__errorID(newVal); } \
        REALLY_INLINE avmplus::Atom get_message() const { return m_slots_ErrorObject.get_message(); } \
        REALLY_INLINE void set_message(avmplus::Atom newVal) { m_slots_ErrorObject.set_message(newVal); } \
        REALLY_INLINE avmplus::Atom get_name() const { return m_slots_ErrorObject.get_name(); } \
        REALLY_INLINE void set_name(avmplus::Atom newVal) { m_slots_ErrorObject.set_name(newVal); } \
    private: \
        avmplus::NativeID::ErrorObjectSlots m_slots_ErrorObject
//-----------------------------------------------------------

// DefinitionError$
//-----------------------------------------------------------
class DefinitionErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_DefinitionErrorClass
};
#define DECLARE_SLOTS_DefinitionErrorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_DefinitionErrorClass.get_length(); } \
    private: \
        avmplus::NativeID::DefinitionErrorClassSlots m_slots_DefinitionErrorClass
//-----------------------------------------------------------

// DefinitionError
//-----------------------------------------------------------
class DefinitionErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DefinitionErrorObject
};
#define DECLARE_SLOTS_DefinitionErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DefinitionErrorObjectSlots EmptySlotsStruct_DefinitionErrorObject
//-----------------------------------------------------------

// EvalError$
//-----------------------------------------------------------
class EvalErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_EvalErrorClass
};
#define DECLARE_SLOTS_EvalErrorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_EvalErrorClass.get_length(); } \
    private: \
        avmplus::NativeID::EvalErrorClassSlots m_slots_EvalErrorClass
//-----------------------------------------------------------

// EvalError
//-----------------------------------------------------------
class EvalErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_EvalErrorObject
};
#define DECLARE_SLOTS_EvalErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::EvalErrorObjectSlots EmptySlotsStruct_EvalErrorObject
//-----------------------------------------------------------

// RangeError$
//-----------------------------------------------------------
class RangeErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_RangeErrorClass
};
#define DECLARE_SLOTS_RangeErrorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_RangeErrorClass.get_length(); } \
    private: \
        avmplus::NativeID::RangeErrorClassSlots m_slots_RangeErrorClass
//-----------------------------------------------------------

// RangeError
//-----------------------------------------------------------
class RangeErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_RangeErrorObject
};
#define DECLARE_SLOTS_RangeErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::RangeErrorObjectSlots EmptySlotsStruct_RangeErrorObject
//-----------------------------------------------------------

// ReferenceError$
//-----------------------------------------------------------
class ReferenceErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_ReferenceErrorClass
};
#define DECLARE_SLOTS_ReferenceErrorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_ReferenceErrorClass.get_length(); } \
    private: \
        avmplus::NativeID::ReferenceErrorClassSlots m_slots_ReferenceErrorClass
//-----------------------------------------------------------

// ReferenceError
//-----------------------------------------------------------
class ReferenceErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_ReferenceErrorObject
};
#define DECLARE_SLOTS_ReferenceErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::ReferenceErrorObjectSlots EmptySlotsStruct_ReferenceErrorObject
//-----------------------------------------------------------

// SecurityError$
//-----------------------------------------------------------
class SecurityErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_SecurityErrorClass
};
#define DECLARE_SLOTS_SecurityErrorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_SecurityErrorClass.get_length(); } \
    private: \
        avmplus::NativeID::SecurityErrorClassSlots m_slots_SecurityErrorClass
//-----------------------------------------------------------

// SecurityError
//-----------------------------------------------------------
class SecurityErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_SecurityErrorObject
};
#define DECLARE_SLOTS_SecurityErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::SecurityErrorObjectSlots EmptySlotsStruct_SecurityErrorObject
//-----------------------------------------------------------

// SyntaxError$
//-----------------------------------------------------------
class SyntaxErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_SyntaxErrorClass
};
#define DECLARE_SLOTS_SyntaxErrorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_SyntaxErrorClass.get_length(); } \
    private: \
        avmplus::NativeID::SyntaxErrorClassSlots m_slots_SyntaxErrorClass
//-----------------------------------------------------------

// SyntaxError
//-----------------------------------------------------------
class SyntaxErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_SyntaxErrorObject
};
#define DECLARE_SLOTS_SyntaxErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::SyntaxErrorObjectSlots EmptySlotsStruct_SyntaxErrorObject
//-----------------------------------------------------------

// TypeError$
//-----------------------------------------------------------
class TypeErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_TypeErrorClass
};
#define DECLARE_SLOTS_TypeErrorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_TypeErrorClass.get_length(); } \
    private: \
        avmplus::NativeID::TypeErrorClassSlots m_slots_TypeErrorClass
//-----------------------------------------------------------

// TypeError
//-----------------------------------------------------------
class TypeErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_TypeErrorObject
};
#define DECLARE_SLOTS_TypeErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::TypeErrorObjectSlots EmptySlotsStruct_TypeErrorObject
//-----------------------------------------------------------

// URIError$
//-----------------------------------------------------------
class URIErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_URIErrorClass
};
#define DECLARE_SLOTS_URIErrorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_URIErrorClass.get_length(); } \
    private: \
        avmplus::NativeID::URIErrorClassSlots m_slots_URIErrorClass
//-----------------------------------------------------------

// URIError
//-----------------------------------------------------------
class URIErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_URIErrorObject
};
#define DECLARE_SLOTS_URIErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::URIErrorObjectSlots EmptySlotsStruct_URIErrorObject
//-----------------------------------------------------------

// VerifyError$
//-----------------------------------------------------------
class VerifyErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_VerifyErrorClass
};
#define DECLARE_SLOTS_VerifyErrorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_VerifyErrorClass.get_length(); } \
    private: \
        avmplus::NativeID::VerifyErrorClassSlots m_slots_VerifyErrorClass
//-----------------------------------------------------------

// VerifyError
//-----------------------------------------------------------
class VerifyErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_VerifyErrorObject
};
#define DECLARE_SLOTS_VerifyErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::VerifyErrorObjectSlots EmptySlotsStruct_VerifyErrorObject
//-----------------------------------------------------------

// UninitializedError$
//-----------------------------------------------------------
class UninitializedErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_UninitializedErrorClass
};
#define DECLARE_SLOTS_UninitializedErrorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_UninitializedErrorClass.get_length(); } \
    private: \
        avmplus::NativeID::UninitializedErrorClassSlots m_slots_UninitializedErrorClass
//-----------------------------------------------------------

// UninitializedError
//-----------------------------------------------------------
class UninitializedErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_UninitializedErrorObject
};
#define DECLARE_SLOTS_UninitializedErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::UninitializedErrorObjectSlots EmptySlotsStruct_UninitializedErrorObject
//-----------------------------------------------------------

// ArgumentError$
//-----------------------------------------------------------
class ArgumentErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_ArgumentErrorClass
};
#define DECLARE_SLOTS_ArgumentErrorClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_ArgumentErrorClass.get_length(); } \
    private: \
        avmplus::NativeID::ArgumentErrorClassSlots m_slots_ArgumentErrorClass
//-----------------------------------------------------------

// ArgumentError
//-----------------------------------------------------------
class ArgumentErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_ArgumentErrorObject
};
#define DECLARE_SLOTS_ArgumentErrorObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::ArgumentErrorObjectSlots EmptySlotsStruct_ArgumentErrorObject
//-----------------------------------------------------------

// Date$
//-----------------------------------------------------------
class DateClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_DateClass
};
#define DECLARE_SLOTS_DateClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_DateClass.get_length(); } \
    private: \
        avmplus::NativeID::DateClassSlots m_slots_DateClass
//-----------------------------------------------------------

// Date
//-----------------------------------------------------------
class DateObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DateObject
};
#define DECLARE_SLOTS_DateObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DateObjectSlots EmptySlotsStruct_DateObject
//-----------------------------------------------------------

// RegExp$
//-----------------------------------------------------------
class RegExpClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_length() const { return m_length; }
private:
    int32_t m_length;
#define GC_TRIVIAL_TRACER_RegExpClass
};
#define DECLARE_SLOTS_RegExpClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_length() const { return m_slots_RegExpClass.get_length(); } \
    private: \
        avmplus::NativeID::RegExpClassSlots m_slots_RegExpClass
//-----------------------------------------------------------

// RegExp
//-----------------------------------------------------------
class RegExpObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_RegExpObject
};
#define DECLARE_SLOTS_RegExpObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::RegExpObjectSlots EmptySlotsStruct_RegExpObject
//-----------------------------------------------------------

// XML$
//-----------------------------------------------------------
class XMLClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::Atom get_length() const { return m_length; }
private:
    ATOM_WB m_length;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceAtom(&m_length);
    }
};
#define DECLARE_SLOTS_XMLClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmplus::Atom get_length() const { return m_slots_XMLClass.get_length(); } \
    private: \
        avmplus::NativeID::XMLClassSlots m_slots_XMLClass
//-----------------------------------------------------------

// XML
//-----------------------------------------------------------
class XMLObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_XMLObject
};
#define DECLARE_SLOTS_XMLObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::XMLObjectSlots EmptySlotsStruct_XMLObject
//-----------------------------------------------------------

// XMLList$
//-----------------------------------------------------------
class XMLListClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::Atom get_length() const { return m_length; }
private:
    ATOM_WB m_length;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceAtom(&m_length);
    }
};
#define DECLARE_SLOTS_XMLListClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmplus::Atom get_length() const { return m_slots_XMLListClass.get_length(); } \
    private: \
        avmplus::NativeID::XMLListClassSlots m_slots_XMLListClass
//-----------------------------------------------------------

// XMLList
//-----------------------------------------------------------
class XMLListObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_XMLListObject
};
#define DECLARE_SLOTS_XMLListObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::XMLListObjectSlots EmptySlotsStruct_XMLListObject
//-----------------------------------------------------------

// QName$
//-----------------------------------------------------------
class QNameClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::Atom get_length() const { return m_length; }
private:
    ATOM_WB m_length;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceAtom(&m_length);
    }
};
#define DECLARE_SLOTS_QNameClass \
    public: \
        virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmplus::Atom get_length() const { return m_slots_QNameClass.get_length(); } \
    private: \
        avmplus::NativeID::QNameClassSlots m_slots_QNameClass
//-----------------------------------------------------------

// QName
//-----------------------------------------------------------
class QNameObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_QNameObject
};
#define DECLARE_SLOTS_QNameObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::QNameObjectSlots EmptySlotsStruct_QNameObject
//-----------------------------------------------------------

// flash.utils::ByteArray$
//-----------------------------------------------------------
class ByteArrayClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE uint32_t get_private__defaultObjectEncoding() const { return m_private__defaultObjectEncoding; }
    REALLY_INLINE void set_private__defaultObjectEncoding(uint32_t newVal) { m_private__defaultObjectEncoding = newVal; }
private:
    uint32_t m_private__defaultObjectEncoding;
#define GC_TRIVIAL_TRACER_ByteArrayClass
};
#define DECLARE_SLOTS_ByteArrayClass \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE uint32_t get_private__defaultObjectEncoding() const { return m_slots_ByteArrayClass.get_private__defaultObjectEncoding(); } \
        REALLY_INLINE void set_private__defaultObjectEncoding(uint32_t newVal) { m_slots_ByteArrayClass.set_private__defaultObjectEncoding(newVal); } \
    private: \
        avmplus::NativeID::ByteArrayClassSlots m_slots_ByteArrayClass
//-----------------------------------------------------------

// flash.utils::ByteArray
//-----------------------------------------------------------
class ByteArrayObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_ByteArrayObject
};
#define DECLARE_SLOTS_ByteArrayObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )\
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::ByteArrayObjectSlots EmptySlotsStruct_ByteArrayObject
//-----------------------------------------------------------

} }
