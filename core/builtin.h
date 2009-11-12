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

extern const uint32_t builtin_abc_class_count;
extern const uint32_t builtin_abc_script_count;
extern const uint32_t builtin_abc_method_count;
extern const uint32_t builtin_abc_length;
extern const uint8_t builtin_abc_data[];
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
const uint32_t abcclass_Date = 29;
const uint32_t abcclass_RegExp = 30;
const uint32_t abcclass_XML = 31;
const uint32_t abcclass_XMLList = 32;
const uint32_t abcclass_QName = 33;

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
const uint32_t Object_private__hasOwnProperty = 20;
const uint32_t Object_private__propertyIsEnumerable = 21;
const uint32_t Object_protected__setPropertyIsEnumerable = 22;
const uint32_t Object_private__isPrototypeOf = 23;
const uint32_t Object_private__toString = 24;
const uint32_t Class_prototype_get = 38;
const uint32_t Function_prototype_get = 46;
const uint32_t Function_prototype_set = 47;
const uint32_t Function_length_get = 48;
const uint32_t Function_AS3_call = 49;
const uint32_t Function_AS3_apply = 50;
const uint32_t Namespace_prefix_get = 55;
const uint32_t Namespace_uri_get = 56;
const uint32_t Number_private__numberToString = 72;
const uint32_t Number_private__convert = 73;
const uint32_t String_AS3_fromCharCode = 123;
const uint32_t String_private__match = 124;
const uint32_t String_private__replace = 125;
const uint32_t String_private__search = 126;
const uint32_t String_private__split = 127;
const uint32_t String_length_get = 128;
const uint32_t String_private__indexOf = 129;
const uint32_t String_AS3_indexOf = 130;
const uint32_t String_private__lastIndexOf = 131;
const uint32_t String_AS3_lastIndexOf = 132;
const uint32_t String_private__charAt = 133;
const uint32_t String_AS3_charAt = 134;
const uint32_t String_private__charCodeAt = 135;
const uint32_t String_AS3_charCodeAt = 136;
const uint32_t String_AS3_localeCompare = 138;
const uint32_t String_private__slice = 142;
const uint32_t String_AS3_slice = 143;
const uint32_t String_private__substring = 145;
const uint32_t String_AS3_substring = 146;
const uint32_t String_private__substr = 147;
const uint32_t String_AS3_substr = 148;
const uint32_t String_AS3_toLowerCase = 149;
const uint32_t String_AS3_toUpperCase = 151;
const uint32_t Array_private__pop = 178;
const uint32_t Array_private__reverse = 179;
const uint32_t Array_private__concat = 180;
const uint32_t Array_private__shift = 181;
const uint32_t Array_private__slice = 182;
const uint32_t Array_private__unshift = 183;
const uint32_t Array_private__splice = 184;
const uint32_t Array_private__sort = 185;
const uint32_t Array_private__sortOn = 186;
const uint32_t Array_private__indexOf = 187;
const uint32_t Array_private__lastIndexOf = 188;
const uint32_t Array_private__every = 189;
const uint32_t Array_private__filter = 190;
const uint32_t Array_private__forEach = 191;
const uint32_t Array_private__map = 192;
const uint32_t Array_private__some = 193;
const uint32_t Array_length_get = 194;
const uint32_t Array_length_set = 195;
const uint32_t Array_AS3_pop = 198;
const uint32_t Array_AS3_push = 199;
const uint32_t Array_AS3_unshift = 204;
const uint32_t __AS3___vec_Vector_object_private__every = 238;
const uint32_t __AS3___vec_Vector_object_private__forEach = 239;
const uint32_t __AS3___vec_Vector_object_private__some = 240;
const uint32_t __AS3___vec_Vector_object_private__sort = 241;
const uint32_t __AS3___vec_Vector_object_private_type_set = 243;
const uint32_t __AS3___vec_Vector_object_private_type_get = 244;
const uint32_t __AS3___vec_Vector_object_length_get = 246;
const uint32_t __AS3___vec_Vector_object_length_set = 247;
const uint32_t __AS3___vec_Vector_object_fixed_set = 248;
const uint32_t __AS3___vec_Vector_object_fixed_get = 249;
const uint32_t __AS3___vec_Vector_object_AS3_push = 256;
const uint32_t __AS3___vec_Vector_object_private__reverse = 257;
const uint32_t __AS3___vec_Vector_object_private__spliceHelper = 261;
const uint32_t __AS3___vec_Vector_object_AS3_unshift = 263;
const uint32_t __AS3___vec_Vector_object_private__filter = 264;
const uint32_t __AS3___vec_Vector_object_private__map = 265;
const uint32_t __AS3___vec_Vector_object_AS3_pop = 270;
const uint32_t __AS3___vec_Vector_int_private__every = 300;
const uint32_t __AS3___vec_Vector_int_private__forEach = 301;
const uint32_t __AS3___vec_Vector_int_private__some = 302;
const uint32_t __AS3___vec_Vector_int_private__sort = 303;
const uint32_t __AS3___vec_Vector_int_length_get = 305;
const uint32_t __AS3___vec_Vector_int_length_set = 306;
const uint32_t __AS3___vec_Vector_int_fixed_set = 307;
const uint32_t __AS3___vec_Vector_int_fixed_get = 308;
const uint32_t __AS3___vec_Vector_int_AS3_push = 315;
const uint32_t __AS3___vec_Vector_int_private__reverse = 316;
const uint32_t __AS3___vec_Vector_int_private__spliceHelper = 320;
const uint32_t __AS3___vec_Vector_int_AS3_unshift = 322;
const uint32_t __AS3___vec_Vector_int_private__filter = 323;
const uint32_t __AS3___vec_Vector_int_private__map = 324;
const uint32_t __AS3___vec_Vector_int_AS3_pop = 329;
const uint32_t __AS3___vec_Vector_uint_private__every = 359;
const uint32_t __AS3___vec_Vector_uint_private__forEach = 360;
const uint32_t __AS3___vec_Vector_uint_private__some = 361;
const uint32_t __AS3___vec_Vector_uint_private__sort = 362;
const uint32_t __AS3___vec_Vector_uint_length_get = 364;
const uint32_t __AS3___vec_Vector_uint_length_set = 365;
const uint32_t __AS3___vec_Vector_uint_fixed_set = 366;
const uint32_t __AS3___vec_Vector_uint_fixed_get = 367;
const uint32_t __AS3___vec_Vector_uint_AS3_push = 374;
const uint32_t __AS3___vec_Vector_uint_private__reverse = 375;
const uint32_t __AS3___vec_Vector_uint_private__spliceHelper = 379;
const uint32_t __AS3___vec_Vector_uint_AS3_unshift = 381;
const uint32_t __AS3___vec_Vector_uint_private__filter = 382;
const uint32_t __AS3___vec_Vector_uint_private__map = 383;
const uint32_t __AS3___vec_Vector_uint_AS3_pop = 388;
const uint32_t __AS3___vec_Vector_double_private__every = 418;
const uint32_t __AS3___vec_Vector_double_private__forEach = 419;
const uint32_t __AS3___vec_Vector_double_private__some = 420;
const uint32_t __AS3___vec_Vector_double_private__sort = 421;
const uint32_t __AS3___vec_Vector_double_length_get = 423;
const uint32_t __AS3___vec_Vector_double_length_set = 424;
const uint32_t __AS3___vec_Vector_double_fixed_set = 425;
const uint32_t __AS3___vec_Vector_double_fixed_get = 426;
const uint32_t __AS3___vec_Vector_double_AS3_push = 433;
const uint32_t __AS3___vec_Vector_double_private__reverse = 434;
const uint32_t __AS3___vec_Vector_double_private__spliceHelper = 438;
const uint32_t __AS3___vec_Vector_double_AS3_unshift = 440;
const uint32_t __AS3___vec_Vector_double_private__filter = 441;
const uint32_t __AS3___vec_Vector_double_private__map = 442;
const uint32_t __AS3___vec_Vector_double_AS3_pop = 447;
const uint32_t Math_private__min = 461;
const uint32_t Math_private__max = 462;
const uint32_t Math_abs = 463;
const uint32_t Math_acos = 464;
const uint32_t Math_asin = 465;
const uint32_t Math_atan = 466;
const uint32_t Math_ceil = 467;
const uint32_t Math_cos = 468;
const uint32_t Math_exp = 469;
const uint32_t Math_floor = 470;
const uint32_t Math_log = 471;
const uint32_t Math_round = 472;
const uint32_t Math_sin = 473;
const uint32_t Math_sqrt = 474;
const uint32_t Math_tan = 475;
const uint32_t Math_atan2 = 476;
const uint32_t Math_pow = 477;
const uint32_t Math_max = 478;
const uint32_t Math_min = 479;
const uint32_t Math_random = 480;
const uint32_t Error_getErrorMessage = 485;
const uint32_t Error_getStackTrace = 489;
const uint32_t Date_parse = 556;
const uint32_t Date_UTC = 557;
const uint32_t Date_AS3_valueOf = 558;
const uint32_t Date_private__toString = 559;
const uint32_t Date_private__setTime = 560;
const uint32_t Date_private__get = 561;
const uint32_t Date_AS3_getUTCFullYear = 570;
const uint32_t Date_AS3_getUTCMonth = 571;
const uint32_t Date_AS3_getUTCDate = 572;
const uint32_t Date_AS3_getUTCDay = 573;
const uint32_t Date_AS3_getUTCHours = 574;
const uint32_t Date_AS3_getUTCMinutes = 575;
const uint32_t Date_AS3_getUTCSeconds = 576;
const uint32_t Date_AS3_getUTCMilliseconds = 577;
const uint32_t Date_AS3_getFullYear = 578;
const uint32_t Date_AS3_getMonth = 579;
const uint32_t Date_AS3_getDate = 580;
const uint32_t Date_AS3_getDay = 581;
const uint32_t Date_AS3_getHours = 582;
const uint32_t Date_AS3_getMinutes = 583;
const uint32_t Date_AS3_getSeconds = 584;
const uint32_t Date_AS3_getMilliseconds = 585;
const uint32_t Date_AS3_getTimezoneOffset = 586;
const uint32_t Date_AS3_getTime = 587;
const uint32_t Date_private__setFullYear = 588;
const uint32_t Date_private__setMonth = 589;
const uint32_t Date_private__setDate = 590;
const uint32_t Date_private__setHours = 591;
const uint32_t Date_private__setMinutes = 592;
const uint32_t Date_private__setSeconds = 593;
const uint32_t Date_private__setMilliseconds = 594;
const uint32_t Date_private__setUTCFullYear = 595;
const uint32_t Date_private__setUTCMonth = 596;
const uint32_t Date_private__setUTCDate = 597;
const uint32_t Date_private__setUTCHours = 598;
const uint32_t Date_private__setUTCMinutes = 599;
const uint32_t Date_private__setUTCSeconds = 600;
const uint32_t Date_private__setUTCMilliseconds = 601;
const uint32_t RegExp_source_get = 655;
const uint32_t RegExp_global_get = 656;
const uint32_t RegExp_ignoreCase_get = 657;
const uint32_t RegExp_multiline_get = 658;
const uint32_t RegExp_lastIndex_get = 659;
const uint32_t RegExp_lastIndex_set = 660;
const uint32_t RegExp_dotall_get = 661;
const uint32_t RegExp_extended_get = 662;
const uint32_t RegExp_AS3_exec = 663;
const uint32_t XML_ignoreComments_get = 709;
const uint32_t XML_ignoreComments_set = 710;
const uint32_t XML_ignoreProcessingInstructions_get = 711;
const uint32_t XML_ignoreProcessingInstructions_set = 712;
const uint32_t XML_ignoreWhitespace_get = 713;
const uint32_t XML_ignoreWhitespace_set = 714;
const uint32_t XML_prettyPrinting_get = 715;
const uint32_t XML_prettyPrinting_set = 716;
const uint32_t XML_prettyIndent_get = 717;
const uint32_t XML_prettyIndent_set = 718;
const uint32_t XML_AS3_toString = 722;
const uint32_t XML_AS3_hasOwnProperty = 723;
const uint32_t XML_AS3_propertyIsEnumerable = 724;
const uint32_t XML_AS3_addNamespace = 725;
const uint32_t XML_AS3_appendChild = 726;
const uint32_t XML_AS3_attribute = 727;
const uint32_t XML_AS3_attributes = 728;
const uint32_t XML_AS3_child = 729;
const uint32_t XML_AS3_childIndex = 730;
const uint32_t XML_AS3_children = 731;
const uint32_t XML_AS3_comments = 732;
const uint32_t XML_AS3_contains = 733;
const uint32_t XML_AS3_copy = 734;
const uint32_t XML_AS3_descendants = 735;
const uint32_t XML_AS3_elements = 736;
const uint32_t XML_AS3_hasComplexContent = 737;
const uint32_t XML_AS3_hasSimpleContent = 738;
const uint32_t XML_AS3_inScopeNamespaces = 739;
const uint32_t XML_AS3_insertChildAfter = 740;
const uint32_t XML_AS3_insertChildBefore = 741;
const uint32_t XML_AS3_localName = 743;
const uint32_t XML_AS3_name = 744;
const uint32_t XML_private__namespace = 745;
const uint32_t XML_AS3_namespaceDeclarations = 747;
const uint32_t XML_AS3_nodeKind = 748;
const uint32_t XML_AS3_normalize = 749;
const uint32_t XML_AS3_parent = 750;
const uint32_t XML_AS3_processingInstructions = 751;
const uint32_t XML_AS3_prependChild = 752;
const uint32_t XML_AS3_removeNamespace = 753;
const uint32_t XML_AS3_replace = 754;
const uint32_t XML_AS3_setChildren = 755;
const uint32_t XML_AS3_setLocalName = 756;
const uint32_t XML_AS3_setName = 757;
const uint32_t XML_AS3_setNamespace = 758;
const uint32_t XML_AS3_text = 759;
const uint32_t XML_AS3_toXMLString = 760;
const uint32_t XML_AS3_notification = 761;
const uint32_t XML_AS3_setNotification = 762;
const uint32_t XMLList_AS3_toString = 804;
const uint32_t XMLList_AS3_hasOwnProperty = 806;
const uint32_t XMLList_AS3_propertyIsEnumerable = 807;
const uint32_t XMLList_AS3_attribute = 808;
const uint32_t XMLList_AS3_attributes = 809;
const uint32_t XMLList_AS3_child = 810;
const uint32_t XMLList_AS3_children = 811;
const uint32_t XMLList_AS3_comments = 812;
const uint32_t XMLList_AS3_contains = 813;
const uint32_t XMLList_AS3_copy = 814;
const uint32_t XMLList_AS3_descendants = 815;
const uint32_t XMLList_AS3_elements = 816;
const uint32_t XMLList_AS3_hasComplexContent = 817;
const uint32_t XMLList_AS3_hasSimpleContent = 818;
const uint32_t XMLList_AS3_length = 819;
const uint32_t XMLList_AS3_name = 820;
const uint32_t XMLList_AS3_normalize = 821;
const uint32_t XMLList_AS3_parent = 822;
const uint32_t XMLList_AS3_processingInstructions = 823;
const uint32_t XMLList_AS3_text = 824;
const uint32_t XMLList_AS3_toXMLString = 825;
const uint32_t XMLList_AS3_addNamespace = 826;
const uint32_t XMLList_AS3_appendChild = 827;
const uint32_t XMLList_AS3_childIndex = 828;
const uint32_t XMLList_AS3_inScopeNamespaces = 829;
const uint32_t XMLList_AS3_insertChildAfter = 830;
const uint32_t XMLList_AS3_insertChildBefore = 831;
const uint32_t XMLList_AS3_nodeKind = 832;
const uint32_t XMLList_private__namespace = 833;
const uint32_t XMLList_AS3_localName = 835;
const uint32_t XMLList_AS3_namespaceDeclarations = 836;
const uint32_t XMLList_AS3_prependChild = 837;
const uint32_t XMLList_AS3_removeNamespace = 838;
const uint32_t XMLList_AS3_replace = 839;
const uint32_t XMLList_AS3_setChildren = 840;
const uint32_t XMLList_AS3_setLocalName = 841;
const uint32_t XMLList_AS3_setName = 842;
const uint32_t XMLList_AS3_setNamespace = 843;
const uint32_t QName_localName_get = 847;
const uint32_t QName_uri_get = 848;

extern AvmBox builtin_a2a_oaoa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Array_private__filter_thunk  builtin_a2a_oaoa_thunk
#define Array_private__map_thunk  builtin_a2a_oaoa_thunk

extern AvmBox builtin_s2a_sdd_opti0_opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_substr_thunk  builtin_s2a_sdd_opti0_opti2147483647_thunk
#define String_AS3_substring_thunk  builtin_s2a_sdd_opti0_opti2147483647_thunk
#define String_AS3_slice_thunk  builtin_s2a_sdd_opti0_opti2147483647_thunk

extern double builtin_d2d_si_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__charCodeAt_thunk  builtin_d2d_si_opti0_thunk

extern double builtin_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_AS3_getUTCDate_thunk  builtin_d2d_o_thunk
#define __AS3___vec_Vector_double_AS3_pop_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCMonth_thunk  builtin_d2d_o_thunk
#define Date_AS3_getDay_thunk  builtin_d2d_o_thunk
#define Date_AS3_getHours_thunk  builtin_d2d_o_thunk
#define Date_AS3_getMinutes_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCFullYear_thunk  builtin_d2d_o_thunk
#define Date_AS3_getMilliseconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCDay_thunk  builtin_d2d_o_thunk
#define Date_AS3_getMonth_thunk  builtin_d2d_o_thunk
#define Date_AS3_getDate_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCSeconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCMilliseconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getFullYear_thunk  builtin_d2d_o_thunk
#define Date_AS3_getTime_thunk  builtin_d2d_o_thunk
#define Date_AS3_getTimezoneOffset_thunk  builtin_d2d_o_thunk
#define Math_random_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCHours_thunk  builtin_d2d_o_thunk
#define Date_AS3_valueOf_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCMinutes_thunk  builtin_d2d_o_thunk
#define Date_AS3_getSeconds_thunk  builtin_d2d_o_thunk

extern double builtin_func_d2d_os_optsAvmThunkConstant_AvmString_63_____NaN_____thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_parseFloat_thunk  builtin_func_d2d_os_optsAvmThunkConstant_AvmString_63_____NaN_____thunk

extern AvmBox builtin_b2a_oa_optakAvmThunkUndefined_u_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_AS3_propertyIsEnumerable_thunk  builtin_b2a_oa_optakAvmThunkUndefined_u_thunk
#define XMLList_AS3_propertyIsEnumerable_thunk  builtin_b2a_oa_optakAvmThunkUndefined_u_thunk
#define XML_AS3_hasOwnProperty_thunk  builtin_b2a_oa_optakAvmThunkUndefined_u_thunk
#define XMLList_AS3_hasOwnProperty_thunk  builtin_b2a_oa_optakAvmThunkUndefined_u_thunk

extern AvmBox builtin_i2a_ss_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_localeCompare_thunk  builtin_i2a_ss_optakAvmThunkUndefined_thunk

extern AvmBox builtin_a2a_osa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__match_thunk  builtin_a2a_osa_thunk

extern AvmBox builtin_v2a_ouuuai_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_object_private__spliceHelper_thunk  builtin_v2a_ouuuai_thunk
#define __AS3___vec_Vector_uint_private__spliceHelper_thunk  builtin_v2a_ouuuai_thunk
#define __AS3___vec_Vector_int_private__spliceHelper_thunk  builtin_v2a_ouuuai_thunk
#define __AS3___vec_Vector_double_private__spliceHelper_thunk  builtin_v2a_ouuuai_thunk

extern AvmBox builtin_func_s2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_avmplus_getQualifiedClassName_thunk  builtin_func_s2a_oa_thunk
#define native_script_function_avmplus_getQualifiedSuperclassName_thunk  builtin_func_s2a_oa_thunk

extern AvmBox builtin_func_b2a_oa_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_isXMLName_thunk  builtin_func_b2a_oa_optakAvmThunkUndefined_thunk

extern AvmBox builtin_u2a_oao_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Array_private__unshift_thunk  builtin_u2a_oao_thunk

extern double builtin_func_d2d_osi_optsAvmThunkConstant_AvmString_63_____NaN_____opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_parseInt_thunk  builtin_func_d2d_osi_optsAvmThunkConstant_AvmString_63_____NaN_____opti0_thunk

extern AvmBox builtin_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_AS3_setNotification_thunk  builtin_a2a_oo_thunk

extern AvmBox builtin_s2a_n_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Namespace_uri_get_thunk  builtin_s2a_n_thunk

extern AvmBox builtin_s2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_AS3_toXMLString_thunk  builtin_s2a_o_thunk
#define XML_AS3_toString_thunk  builtin_s2a_o_thunk
#define Error_getStackTrace_thunk  builtin_s2a_o_thunk
#define QName_localName_get_thunk  builtin_s2a_o_thunk
#define XMLList_AS3_toString_thunk  builtin_s2a_o_thunk
#define XML_AS3_nodeKind_thunk  builtin_s2a_o_thunk
#define RegExp_source_get_thunk  builtin_s2a_o_thunk
#define XMLList_AS3_toXMLString_thunk  builtin_s2a_o_thunk
#define XMLList_AS3_nodeKind_thunk  builtin_s2a_o_thunk

extern AvmBox builtin_s2a_odi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Number_private__numberToString_thunk  builtin_s2a_odi_thunk

extern double builtin_d2d_odd_optdkAvmThunkNegInfinity_optdkAvmThunkNegInfinity_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Math_max_thunk  builtin_d2d_odd_optdkAvmThunkNegInfinity_optdkAvmThunkNegInfinity_rest_thunk

extern AvmBox builtin_v2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_uint_length_set_thunk  builtin_v2a_ou_thunk
#define __AS3___vec_Vector_object_length_set_thunk  builtin_v2a_ou_thunk
#define __AS3___vec_Vector_int_length_set_thunk  builtin_v2a_ou_thunk
#define __AS3___vec_Vector_double_length_set_thunk  builtin_v2a_ou_thunk
#define Array_length_set_thunk  builtin_v2a_ou_thunk

extern AvmBox builtin_a2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Array_private__pop_thunk  builtin_a2a_oa_thunk
#define XML_AS3_removeNamespace_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_appendChild_thunk  builtin_a2a_oa_thunk
#define XML_AS3_addNamespace_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_prependChild_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_attribute_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_addNamespace_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_child_thunk  builtin_a2a_oa_thunk
#define XML_AS3_appendChild_thunk  builtin_a2a_oa_thunk
#define Array_private__shift_thunk  builtin_a2a_oa_thunk
#define XML_AS3_prependChild_thunk  builtin_a2a_oa_thunk
#define XML_AS3_child_thunk  builtin_a2a_oa_thunk
#define XML_AS3_attribute_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_removeNamespace_thunk  builtin_a2a_oa_thunk
#define Array_private__reverse_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_setChildren_thunk  builtin_a2a_oa_thunk
#define XML_AS3_setChildren_thunk  builtin_a2a_oa_thunk

extern AvmBox builtin_func_a2a_oau_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_avmplus_describeTypeJSON_thunk  builtin_func_a2a_oau_thunk

extern double builtin_d2d_o_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_private__setUTCDate_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setFullYear_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setMinutes_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCMonth_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCSeconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setHours_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setDate_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCMinutes_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setMonth_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCHours_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setSeconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCFullYear_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setMilliseconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCMilliseconds_thunk  builtin_d2d_o_rest_thunk

extern AvmBox builtin_func_b2a_od_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_isNaN_thunk  builtin_func_b2a_od_optakAvmThunkUndefined_thunk
#define native_script_function_isFinite_thunk  builtin_func_b2a_od_optakAvmThunkUndefined_thunk

extern double builtin_d2d_oaaaaaaa_opti1_opti0_opti0_opti0_opti0_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_UTC_thunk  builtin_d2d_oaaaaaaa_opti1_opti0_opti0_opti0_opti0_rest_thunk

extern AvmBox builtin_i2a_s_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_length_get_thunk  builtin_i2a_s_thunk

extern AvmBox builtin_b2a_oaa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Object_private__isPrototypeOf_thunk  builtin_b2a_oaa_thunk

extern AvmBox builtin_func_s2a_os_optsAvmThunkConstant_AvmString_61_____undefined_____thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_decodeURI_thunk  builtin_func_s2a_os_optsAvmThunkConstant_AvmString_61_____undefined_____thunk
#define native_script_function_escape_thunk  builtin_func_s2a_os_optsAvmThunkConstant_AvmString_61_____undefined_____thunk
#define native_script_function_unescape_thunk  builtin_func_s2a_os_optsAvmThunkConstant_AvmString_61_____undefined_____thunk
#define native_script_function_encodeURI_thunk  builtin_func_s2a_os_optsAvmThunkConstant_AvmString_61_____undefined_____thunk
#define native_script_function_encodeURIComponent_thunk  builtin_func_s2a_os_optsAvmThunkConstant_AvmString_61_____undefined_____thunk
#define native_script_function_decodeURIComponent_thunk  builtin_func_s2a_os_optsAvmThunkConstant_AvmString_61_____undefined_____thunk

extern AvmBox builtin_a2a_oaaa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Array_private__sortOn_thunk  builtin_a2a_oaaa_thunk

extern AvmBox builtin_u2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_uint_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_int_length_get_thunk  builtin_u2a_o_thunk
#define Array_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_uint_AS3_pop_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_object_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_double_length_get_thunk  builtin_u2a_o_thunk

extern AvmBox builtin_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_double_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_uint_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_object_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_int_private__reverse_thunk  builtin_v2a_o_thunk

extern AvmBox builtin_a2a_oa_optakAvmThunkUndefined_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Function_AS3_call_thunk  builtin_a2a_oa_optakAvmThunkUndefined_rest_thunk

extern AvmBox builtin_s2a_si_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__charAt_thunk  builtin_s2a_si_opti0_thunk

extern AvmBox builtin_s2a_osaa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__replace_thunk  builtin_s2a_osaa_thunk

extern AvmBox builtin_b2a_oas_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Object_private__hasOwnProperty_thunk  builtin_b2a_oas_thunk
#define Object_private__propertyIsEnumerable_thunk  builtin_b2a_oas_thunk

extern AvmBox builtin_i2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_AS3_childIndex_thunk  builtin_i2a_o_thunk
#define XML_prettyIndent_get_thunk  builtin_i2a_o_thunk
#define __AS3___vec_Vector_int_AS3_pop_thunk  builtin_i2a_o_thunk
#define XMLList_AS3_length_thunk  builtin_i2a_o_thunk
#define RegExp_lastIndex_get_thunk  builtin_i2a_o_thunk
#define XMLList_AS3_childIndex_thunk  builtin_i2a_o_thunk
#define Function_length_get_thunk  builtin_i2a_o_thunk

extern AvmBox builtin_a2a_ooa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_object_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_double_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_object_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_int_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_uint_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_int_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_double_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_uint_private__filter_thunk  builtin_a2a_ooa_thunk

extern double builtin_d2d_sd_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_charCodeAt_thunk  builtin_d2d_sd_opti0_thunk

extern AvmBox builtin_s2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Object_private__toString_thunk  builtin_s2a_oa_thunk

extern AvmBox builtin_b2a_oaoa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_double_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_int_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_object_private__some_thunk  builtin_b2a_oaoa_thunk
#define Array_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_double_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_uint_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_object_private__every_thunk  builtin_b2a_oaoa_thunk
#define Array_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_int_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_uint_private__every_thunk  builtin_b2a_oaoa_thunk

extern AvmBox builtin_i2a_ssi_opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__lastIndexOf_thunk  builtin_i2a_ssi_opti2147483647_thunk

extern AvmBox builtin_b2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XMLList_AS3_contains_thunk  builtin_b2a_oa_thunk
#define XML_AS3_contains_thunk  builtin_b2a_oa_thunk

extern AvmBox builtin_s2a_sd_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_charAt_thunk  builtin_s2a_sd_opti0_thunk

extern AvmBox builtin_v2a_oaoa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_double_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_object_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_int_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_uint_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define Array_private__forEach_thunk  builtin_v2a_oaoa_thunk

extern AvmBox builtin_i2a_ssd_optsAvmThunkConstant_AvmString_61_____undefined_____opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_indexOf_thunk  builtin_i2a_ssd_optsAvmThunkConstant_AvmString_61_____undefined_____opti0_thunk

extern AvmBox builtin_s2a_s_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_toLowerCase_thunk  builtin_s2a_s_thunk
#define String_AS3_toUpperCase_thunk  builtin_s2a_s_thunk

extern AvmBox builtin_i2a_ssd_optsAvmThunkConstant_AvmString_61_____undefined_____opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_lastIndexOf_thunk  builtin_i2a_ssd_optsAvmThunkConstant_AvmString_61_____undefined_____opti2147483647_thunk

extern double builtin_d2d_odd_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Math_private__min_thunk  builtin_d2d_odd_thunk
#define Math_atan2_thunk  builtin_d2d_odd_thunk
#define Math_pow_thunk  builtin_d2d_odd_thunk
#define Math_private__max_thunk  builtin_d2d_odd_thunk

extern AvmBox builtin_a2a_n_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Namespace_prefix_get_thunk  builtin_a2a_n_thunk

extern AvmBox builtin_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XMLList_AS3_inScopeNamespaces_thunk  builtin_a2a_o_thunk
#define XML_AS3_notification_thunk  builtin_a2a_o_thunk
#define XML_AS3_inScopeNamespaces_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_copy_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_children_thunk  builtin_a2a_o_thunk
#define XML_AS3_attributes_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_text_thunk  builtin_a2a_o_thunk
#define __AS3___vec_Vector_object_AS3_pop_thunk  builtin_a2a_o_thunk
#define Class_prototype_get_thunk  builtin_a2a_o_thunk
#define XML_AS3_name_thunk  builtin_a2a_o_thunk
#define XML_AS3_namespaceDeclarations_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_name_thunk  builtin_a2a_o_thunk
#define QName_uri_get_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_normalize_thunk  builtin_a2a_o_thunk
#define XML_AS3_text_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_namespaceDeclarations_thunk  builtin_a2a_o_thunk
#define Function_prototype_get_thunk  builtin_a2a_o_thunk
#define XML_AS3_children_thunk  builtin_a2a_o_thunk
#define XML_AS3_parent_thunk  builtin_a2a_o_thunk
#define __AS3___vec_Vector_object_private_type_get_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_comments_thunk  builtin_a2a_o_thunk
#define XML_AS3_localName_thunk  builtin_a2a_o_thunk
#define XML_AS3_copy_thunk  builtin_a2a_o_thunk
#define XML_AS3_normalize_thunk  builtin_a2a_o_thunk
#define Array_AS3_pop_thunk  builtin_a2a_o_thunk
#define XML_AS3_comments_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_attributes_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_localName_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_parent_thunk  builtin_a2a_o_thunk

extern AvmBox builtin_a2a_osau_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__split_thunk  builtin_a2a_osau_thunk

extern AvmBox builtin_v2a_oasb_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Object_protected__setPropertyIsEnumerable_thunk  builtin_v2a_oasb_thunk

extern AvmBox builtin_a2a_os_optsAvmThunkConstant_AvmString_0__________thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define RegExp_AS3_exec_thunk  builtin_a2a_os_optsAvmThunkConstant_AvmString_0__________thunk

extern AvmBox builtin_u2a_o_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_uint_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_object_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define Array_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define Array_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_int_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_uint_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_double_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_object_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_int_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_double_AS3_push_thunk  builtin_u2a_o_rest_thunk

extern AvmBox builtin_s2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_private__toString_thunk  builtin_s2a_oi_thunk
#define Error_getErrorMessage_thunk  builtin_s2a_oi_thunk

extern AvmBox builtin_a2a_oa_optsAvmThunkConstant_AvmString_483___________thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XMLList_AS3_elements_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_483___________thunk
#define XML_AS3_descendants_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_483___________thunk
#define XML_AS3_processingInstructions_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_483___________thunk
#define XML_AS3_elements_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_483___________thunk
#define XMLList_AS3_descendants_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_483___________thunk
#define XMLList_AS3_processingInstructions_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_483___________thunk

extern AvmBox builtin_i2a_ssi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__indexOf_thunk  builtin_i2a_ssi_opti0_thunk

extern AvmBox builtin_s2a_o_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_fromCharCode_thunk  builtin_s2a_o_rest_thunk

extern AvmBox builtin_i2a_oaai_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Array_private__lastIndexOf_thunk  builtin_i2a_oaai_opti0_thunk

extern double builtin_d2d_od_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_private__setTime_thunk  builtin_d2d_od_thunk
#define Math_cos_thunk  builtin_d2d_od_thunk
#define Math_ceil_thunk  builtin_d2d_od_thunk
#define Math_acos_thunk  builtin_d2d_od_thunk
#define Math_abs_thunk  builtin_d2d_od_thunk
#define Math_atan_thunk  builtin_d2d_od_thunk
#define Math_asin_thunk  builtin_d2d_od_thunk
#define Math_exp_thunk  builtin_d2d_od_thunk
#define Math_round_thunk  builtin_d2d_od_thunk
#define Math_log_thunk  builtin_d2d_od_thunk
#define Math_tan_thunk  builtin_d2d_od_thunk
#define Math_sin_thunk  builtin_d2d_od_thunk
#define Math_sqrt_thunk  builtin_d2d_od_thunk
#define Math_floor_thunk  builtin_d2d_od_thunk

extern AvmBox builtin_a2a_oaa_optakAvmThunkUndefined_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Function_AS3_apply_thunk  builtin_a2a_oaa_optakAvmThunkUndefined_optakAvmThunkUndefined_thunk

extern AvmBox builtin_s2a_sii_opti0_opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__slice_thunk  builtin_s2a_sii_opti0_opti2147483647_thunk
#define String_private__substr_thunk  builtin_s2a_sii_opti0_opti2147483647_thunk
#define String_private__substring_thunk  builtin_s2a_sii_opti0_opti2147483647_thunk

extern AvmBox builtin_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_uint_fixed_set_thunk  builtin_v2a_ob_thunk
#define XML_prettyPrinting_set_thunk  builtin_v2a_ob_thunk
#define __AS3___vec_Vector_object_fixed_set_thunk  builtin_v2a_ob_thunk
#define XML_ignoreComments_set_thunk  builtin_v2a_ob_thunk
#define XML_ignoreWhitespace_set_thunk  builtin_v2a_ob_thunk
#define __AS3___vec_Vector_double_fixed_set_thunk  builtin_v2a_ob_thunk
#define XML_ignoreProcessingInstructions_set_thunk  builtin_v2a_ob_thunk
#define __AS3___vec_Vector_int_fixed_set_thunk  builtin_v2a_ob_thunk

extern AvmBox builtin_v2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XMLList_AS3_setName_thunk  builtin_v2a_oa_thunk
#define __AS3___vec_Vector_object_private_type_set_thunk  builtin_v2a_oa_thunk
#define XMLList_AS3_setLocalName_thunk  builtin_v2a_oa_thunk
#define Function_prototype_set_thunk  builtin_v2a_oa_thunk
#define XMLList_AS3_setNamespace_thunk  builtin_v2a_oa_thunk
#define XML_AS3_setName_thunk  builtin_v2a_oa_thunk
#define XML_AS3_setNamespace_thunk  builtin_v2a_oa_thunk
#define XML_AS3_setLocalName_thunk  builtin_v2a_oa_thunk

extern double builtin_d2d_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_parse_thunk  builtin_d2d_oa_thunk

extern AvmBox builtin_v2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_prettyIndent_set_thunk  builtin_v2a_oi_thunk
#define RegExp_lastIndex_set_thunk  builtin_v2a_oi_thunk

extern double builtin_d2d_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_private__get_thunk  builtin_d2d_oi_thunk

extern AvmBox builtin_a2a_oaa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_AS3_insertChildAfter_thunk  builtin_a2a_oaa_thunk
#define XMLList_AS3_insertChildBefore_thunk  builtin_a2a_oaa_thunk
#define XMLList_AS3_insertChildAfter_thunk  builtin_a2a_oaa_thunk
#define XML_AS3_insertChildBefore_thunk  builtin_a2a_oaa_thunk
#define XML_AS3_replace_thunk  builtin_a2a_oaa_thunk
#define XMLList_AS3_replace_thunk  builtin_a2a_oaa_thunk

extern AvmBox builtin_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define RegExp_multiline_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_double_fixed_get_thunk  builtin_b2a_o_thunk
#define RegExp_dotall_get_thunk  builtin_b2a_o_thunk
#define XMLList_AS3_hasComplexContent_thunk  builtin_b2a_o_thunk
#define XML_prettyPrinting_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_uint_fixed_get_thunk  builtin_b2a_o_thunk
#define XML_ignoreComments_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_int_fixed_get_thunk  builtin_b2a_o_thunk
#define RegExp_global_get_thunk  builtin_b2a_o_thunk
#define RegExp_ignoreCase_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_object_fixed_get_thunk  builtin_b2a_o_thunk
#define XMLList_AS3_hasSimpleContent_thunk  builtin_b2a_o_thunk
#define XML_AS3_hasSimpleContent_thunk  builtin_b2a_o_thunk
#define XML_ignoreWhitespace_get_thunk  builtin_b2a_o_thunk
#define RegExp_extended_get_thunk  builtin_b2a_o_thunk
#define XML_AS3_hasComplexContent_thunk  builtin_b2a_o_thunk
#define XML_ignoreProcessingInstructions_get_thunk  builtin_b2a_o_thunk

extern AvmBox builtin_i2a_osa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__search_thunk  builtin_i2a_osa_thunk

extern AvmBox builtin_a2a_oadd_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Array_private__slice_thunk  builtin_a2a_oadd_thunk

extern AvmBox builtin_a2a_oai_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_private__namespace_thunk  builtin_a2a_oai_thunk
#define XMLList_private__namespace_thunk  builtin_a2a_oai_thunk

extern AvmBox builtin_i2a_oaai_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Array_private__indexOf_thunk  builtin_i2a_oaai_thunk

extern AvmBox builtin_s2a_odii_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Number_private__convert_thunk  builtin_s2a_odii_thunk

extern double builtin_d2d_odd_optdkAvmThunkInfinity_optdkAvmThunkInfinity_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Math_min_thunk  builtin_d2d_odd_optdkAvmThunkInfinity_optdkAvmThunkInfinity_rest_thunk

extern AvmBox builtin_a2a_oao_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_uint_private__sort_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_object_private__sort_thunk  builtin_a2a_oao_thunk
#define Array_private__concat_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_int_private__sort_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_double_private__sort_thunk  builtin_a2a_oao_thunk
#define Array_private__splice_thunk  builtin_a2a_oao_thunk
#define Array_private__sort_thunk  builtin_a2a_oao_thunk

