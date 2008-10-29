/* machine generated file -- do not edit */
#define AVMTHUNK_VERSION 3
const uint32_t builtin_abc_class_count = 34;
const uint32_t builtin_abc_script_count = 6;
const uint32_t builtin_abc_method_count = 846;
const uint32_t builtin_abc_length = 39764;
extern const uint8_t builtin_abc_data[39764];
AVMTHUNK_DECLARE_NATIVE_INITIALIZER(builtin, builtin)
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
const uint32_t unescape = 0;
const uint32_t escape = 1;
const uint32_t parseFloat = 2;
const uint32_t parseInt = 3;
const uint32_t isFinite = 4;
const uint32_t isNaN = 5;
const uint32_t encodeURIComponent = 6;
const uint32_t encodeURI = 7;
const uint32_t decodeURIComponent = 8;
const uint32_t decodeURI = 9;
const uint32_t Object_private__hasOwnProperty = 11;
const uint32_t Object_private__propertyIsEnumerable = 12;
const uint32_t Object_protected__setPropertyIsEnumerable = 13;
const uint32_t Object_private__isPrototypeOf = 14;
const uint32_t Object_private__toString = 15;
/* const uint32_t Object_protected__dontEnumPrototype = 16; */
/* const uint32_t Object_init = 23; */
/* const uint32_t Object_AS3_isPrototypeOf = 24; */
/* const uint32_t Object_AS3_hasOwnProperty = 25; */
/* const uint32_t Object_AS3_propertyIsEnumerable = 26; */
const uint32_t Class_prototype_get = 29;
/* const uint32_t Function_private_emptyCtor = 36; */
const uint32_t Function_prototype_get = 37;
const uint32_t Function_prototype_set = 38;
const uint32_t Function_length_get = 39;
const uint32_t Function_AS3_call = 40;
const uint32_t Function_AS3_apply = 41;
const uint32_t Namespace_prefix_get = 46;
const uint32_t Namespace_uri_get = 47;
/* const uint32_t Namespace_AS3_valueOf = 48; */
/* const uint32_t Namespace_AS3_toString = 49; */
/* const uint32_t Boolean_AS3_toString = 54; */
/* const uint32_t Boolean_AS3_valueOf = 55; */
const uint32_t Number_private__toString = 63;
const uint32_t Number_private__convert = 64;
/* const uint32_t Number_AS3_toString = 65; */
/* const uint32_t Number_AS3_valueOf = 66; */
/* const uint32_t Number_AS3_toExponential = 67; */
/* const uint32_t Number_AS3_toPrecision = 68; */
/* const uint32_t Number_AS3_toFixed = 69; */
/* const uint32_t int_AS3_toString = 77; */
/* const uint32_t int_AS3_valueOf = 78; */
/* const uint32_t int_AS3_toExponential = 79; */
/* const uint32_t int_AS3_toPrecision = 80; */
/* const uint32_t int_AS3_toFixed = 81; */
/* const uint32_t uint_AS3_toString = 89; */
/* const uint32_t uint_AS3_valueOf = 90; */
/* const uint32_t uint_AS3_toExponential = 91; */
/* const uint32_t uint_AS3_toPrecision = 92; */
/* const uint32_t uint_AS3_toFixed = 93; */
const uint32_t String_AS3_fromCharCode = 114;
const uint32_t String_private__match = 115;
const uint32_t String_private__replace = 116;
const uint32_t String_private__search = 117;
const uint32_t String_private__split = 118;
const uint32_t String_length_get = 119;
const uint32_t String_private__indexOf = 120;
const uint32_t String_AS3_indexOf = 121;
const uint32_t String_private__lastIndexOf = 122;
const uint32_t String_AS3_lastIndexOf = 123;
const uint32_t String_private__charAt = 124;
const uint32_t String_AS3_charAt = 125;
const uint32_t String_private__charCodeAt = 126;
const uint32_t String_AS3_charCodeAt = 127;
/* const uint32_t String_AS3_concat = 128; */
const uint32_t String_AS3_localeCompare = 129;
/* const uint32_t String_AS3_match = 130; */
/* const uint32_t String_AS3_replace = 131; */
/* const uint32_t String_AS3_search = 132; */
const uint32_t String_private__slice = 133;
const uint32_t String_AS3_slice = 134;
/* const uint32_t String_AS3_split = 135; */
const uint32_t String_private__substring = 136;
const uint32_t String_AS3_substring = 137;
const uint32_t String_private__substr = 138;
const uint32_t String_AS3_substr = 139;
const uint32_t String_AS3_toLowerCase = 140;
/* const uint32_t String_AS3_toLocaleLowerCase = 141; */
const uint32_t String_AS3_toUpperCase = 142;
/* const uint32_t String_AS3_toLocaleUpperCase = 143; */
/* const uint32_t String_AS3_toString = 144; */
/* const uint32_t String_AS3_valueOf = 145; */
/* const uint32_t Array_private__join = 168; */
const uint32_t Array_private__pop = 169;
const uint32_t Array_private__reverse = 170;
const uint32_t Array_private__concat = 171;
const uint32_t Array_private__shift = 172;
const uint32_t Array_private__slice = 173;
const uint32_t Array_private__splice = 174;
const uint32_t Array_private__sort = 175;
const uint32_t Array_private__sortOn = 176;
const uint32_t Array_private__indexOf = 177;
const uint32_t Array_private__lastIndexOf = 178;
const uint32_t Array_private__every = 179;
const uint32_t Array_private__filter = 180;
const uint32_t Array_private__forEach = 181;
const uint32_t Array_private__map = 182;
const uint32_t Array_private__some = 183;
const uint32_t Array_length_get = 184;
const uint32_t Array_length_set = 185;
/* const uint32_t Array_AS3_join = 187; */
const uint32_t Array_AS3_pop = 188;
const uint32_t Array_AS3_push = 189;
/* const uint32_t Array_AS3_reverse = 190; */
/* const uint32_t Array_AS3_concat = 191; */
/* const uint32_t Array_AS3_shift = 192; */
/* const uint32_t Array_AS3_slice = 193; */
const uint32_t Array_AS3_unshift = 194;
/* const uint32_t Array_AS3_splice = 195; */
/* const uint32_t Array_AS3_sort = 196; */
/* const uint32_t Array_AS3_sortOn = 197; */
/* const uint32_t Array_AS3_indexOf = 198; */
/* const uint32_t Array_AS3_lastIndexOf = 199; */
/* const uint32_t Array_AS3_every = 200; */
/* const uint32_t Array_AS3_filter = 201; */
/* const uint32_t Array_AS3_forEach = 202; */
/* const uint32_t Array_AS3_map = 203; */
/* const uint32_t Array_AS3_some = 204; */
/* const uint32_t __AS3___vec_Vector_object_private_castToThisType = 227; */
const uint32_t __AS3___vec_Vector_object_private__every = 228;
const uint32_t __AS3___vec_Vector_object_private__forEach = 229;
const uint32_t __AS3___vec_Vector_object_private__some = 230;
const uint32_t __AS3___vec_Vector_object_private__sort = 231;
const uint32_t __AS3___vec_Vector_object_private_type_set = 233;
const uint32_t __AS3___vec_Vector_object_private_type_get = 234;
/* const uint32_t __AS3___vec_Vector_object_private_newThisType = 235; */
const uint32_t __AS3___vec_Vector_object_length_get = 236;
const uint32_t __AS3___vec_Vector_object_length_set = 237;
const uint32_t __AS3___vec_Vector_object_fixed_set = 238;
const uint32_t __AS3___vec_Vector_object_fixed_get = 239;
/* const uint32_t __AS3___vec_Vector_object_AS3_toString = 240; */
/* const uint32_t __AS3___vec_Vector_object_AS3_toLocaleString = 241; */
/* const uint32_t __AS3___vec_Vector_object_AS3_join = 242; */
/* const uint32_t __AS3___vec_Vector_object_private__concat = 243; */
/* const uint32_t __AS3___vec_Vector_object_AS3_every = 244; */
/* const uint32_t __AS3___vec_Vector_object_AS3_forEach = 245; */
/* const uint32_t __AS3___vec_Vector_object_AS3_map = 246; */
const uint32_t __AS3___vec_Vector_object_AS3_push = 247;
const uint32_t __AS3___vec_Vector_object_private__reverse = 248;
/* const uint32_t __AS3___vec_Vector_object_AS3_some = 249; */
/* const uint32_t __AS3___vec_Vector_object_private__slice = 250; */
/* const uint32_t __AS3___vec_Vector_object_private__splice = 251; */
const uint32_t __AS3___vec_Vector_object_private__spliceHelper = 252;
/* const uint32_t __AS3___vec_Vector_object_private__shift = 253; */
const uint32_t __AS3___vec_Vector_object_AS3_unshift = 254;
const uint32_t __AS3___vec_Vector_object_private__filter = 255;
const uint32_t __AS3___vec_Vector_object_private__map = 256;
/* const uint32_t __AS3___vec_Vector_object_private_clamp = 257; */
/* const uint32_t __AS3___vec_Vector_object_AS3_concat = 258; */
/* const uint32_t __AS3___vec_Vector_object_AS3_filter = 259; */
const uint32_t __AS3___vec_Vector_object_AS3_pop = 260;
/* const uint32_t __AS3___vec_Vector_object_AS3_reverse = 261; */
/* const uint32_t __AS3___vec_Vector_object_AS3_shift = 262; */
/* const uint32_t __AS3___vec_Vector_object_AS3_slice = 263; */
/* const uint32_t __AS3___vec_Vector_object_AS3_sort = 264; */
/* const uint32_t __AS3___vec_Vector_object_AS3_splice = 265; */
/* const uint32_t __AS3___vec_Vector_object_AS3_indexOf = 266; */
/* const uint32_t __AS3___vec_Vector_object_AS3_lastIndexOf = 267; */
/* const uint32_t __AS3___vec_Vector_int_private_castToThisType = 288; */
/* const uint32_t __AS3___vec_Vector_int_private_newThisType = 289; */
const uint32_t __AS3___vec_Vector_int_private__every = 290;
const uint32_t __AS3___vec_Vector_int_private__forEach = 291;
const uint32_t __AS3___vec_Vector_int_private__some = 292;
const uint32_t __AS3___vec_Vector_int_private__sort = 293;
const uint32_t __AS3___vec_Vector_int_length_get = 295;
const uint32_t __AS3___vec_Vector_int_length_set = 296;
const uint32_t __AS3___vec_Vector_int_fixed_set = 297;
const uint32_t __AS3___vec_Vector_int_fixed_get = 298;
/* const uint32_t __AS3___vec_Vector_int_AS3_toString = 299; */
/* const uint32_t __AS3___vec_Vector_int_AS3_toLocaleString = 300; */
/* const uint32_t __AS3___vec_Vector_int_AS3_join = 301; */
/* const uint32_t __AS3___vec_Vector_int_private__concat = 302; */
/* const uint32_t __AS3___vec_Vector_int_AS3_every = 303; */
/* const uint32_t __AS3___vec_Vector_int_AS3_forEach = 304; */
/* const uint32_t __AS3___vec_Vector_int_AS3_map = 305; */
const uint32_t __AS3___vec_Vector_int_AS3_push = 306;
const uint32_t __AS3___vec_Vector_int_private__reverse = 307;
/* const uint32_t __AS3___vec_Vector_int_AS3_some = 308; */
/* const uint32_t __AS3___vec_Vector_int_private__slice = 309; */
/* const uint32_t __AS3___vec_Vector_int_private__splice = 310; */
const uint32_t __AS3___vec_Vector_int_private__spliceHelper = 311;
/* const uint32_t __AS3___vec_Vector_int_private__shift = 312; */
const uint32_t __AS3___vec_Vector_int_AS3_unshift = 313;
const uint32_t __AS3___vec_Vector_int_private__filter = 314;
const uint32_t __AS3___vec_Vector_int_private__map = 315;
/* const uint32_t __AS3___vec_Vector_int_private_clamp = 316; */
/* const uint32_t __AS3___vec_Vector_int_AS3_concat = 317; */
/* const uint32_t __AS3___vec_Vector_int_AS3_filter = 318; */
const uint32_t __AS3___vec_Vector_int_AS3_pop = 319;
/* const uint32_t __AS3___vec_Vector_int_AS3_reverse = 320; */
/* const uint32_t __AS3___vec_Vector_int_AS3_shift = 321; */
/* const uint32_t __AS3___vec_Vector_int_AS3_slice = 322; */
/* const uint32_t __AS3___vec_Vector_int_AS3_sort = 323; */
/* const uint32_t __AS3___vec_Vector_int_AS3_splice = 324; */
/* const uint32_t __AS3___vec_Vector_int_AS3_indexOf = 325; */
/* const uint32_t __AS3___vec_Vector_int_AS3_lastIndexOf = 326; */
/* const uint32_t __AS3___vec_Vector_uint_private_castToThisType = 347; */
/* const uint32_t __AS3___vec_Vector_uint_private_newThisType = 348; */
const uint32_t __AS3___vec_Vector_uint_private__every = 349;
const uint32_t __AS3___vec_Vector_uint_private__forEach = 350;
const uint32_t __AS3___vec_Vector_uint_private__some = 351;
const uint32_t __AS3___vec_Vector_uint_private__sort = 352;
const uint32_t __AS3___vec_Vector_uint_length_get = 354;
const uint32_t __AS3___vec_Vector_uint_length_set = 355;
const uint32_t __AS3___vec_Vector_uint_fixed_set = 356;
const uint32_t __AS3___vec_Vector_uint_fixed_get = 357;
/* const uint32_t __AS3___vec_Vector_uint_AS3_toString = 358; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_toLocaleString = 359; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_join = 360; */
/* const uint32_t __AS3___vec_Vector_uint_private__concat = 361; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_every = 362; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_forEach = 363; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_map = 364; */
const uint32_t __AS3___vec_Vector_uint_AS3_push = 365;
const uint32_t __AS3___vec_Vector_uint_private__reverse = 366;
/* const uint32_t __AS3___vec_Vector_uint_AS3_some = 367; */
/* const uint32_t __AS3___vec_Vector_uint_private__slice = 368; */
/* const uint32_t __AS3___vec_Vector_uint_private__splice = 369; */
const uint32_t __AS3___vec_Vector_uint_private__spliceHelper = 370;
/* const uint32_t __AS3___vec_Vector_uint_private__shift = 371; */
const uint32_t __AS3___vec_Vector_uint_AS3_unshift = 372;
const uint32_t __AS3___vec_Vector_uint_private__filter = 373;
const uint32_t __AS3___vec_Vector_uint_private__map = 374;
/* const uint32_t __AS3___vec_Vector_uint_private_clamp = 375; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_concat = 376; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_filter = 377; */
const uint32_t __AS3___vec_Vector_uint_AS3_pop = 378;
/* const uint32_t __AS3___vec_Vector_uint_AS3_reverse = 379; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_shift = 380; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_slice = 381; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_sort = 382; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_splice = 383; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_indexOf = 384; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_lastIndexOf = 385; */
/* const uint32_t __AS3___vec_Vector_double_private_castToThisType = 406; */
/* const uint32_t __AS3___vec_Vector_double_private_newThisType = 407; */
const uint32_t __AS3___vec_Vector_double_private__every = 408;
const uint32_t __AS3___vec_Vector_double_private__forEach = 409;
const uint32_t __AS3___vec_Vector_double_private__some = 410;
const uint32_t __AS3___vec_Vector_double_private__sort = 411;
const uint32_t __AS3___vec_Vector_double_length_get = 413;
const uint32_t __AS3___vec_Vector_double_length_set = 414;
const uint32_t __AS3___vec_Vector_double_fixed_set = 415;
const uint32_t __AS3___vec_Vector_double_fixed_get = 416;
/* const uint32_t __AS3___vec_Vector_double_AS3_toString = 417; */
/* const uint32_t __AS3___vec_Vector_double_AS3_toLocaleString = 418; */
/* const uint32_t __AS3___vec_Vector_double_AS3_join = 419; */
/* const uint32_t __AS3___vec_Vector_double_private__concat = 420; */
/* const uint32_t __AS3___vec_Vector_double_AS3_every = 421; */
/* const uint32_t __AS3___vec_Vector_double_AS3_forEach = 422; */
/* const uint32_t __AS3___vec_Vector_double_AS3_map = 423; */
const uint32_t __AS3___vec_Vector_double_AS3_push = 424;
const uint32_t __AS3___vec_Vector_double_private__reverse = 425;
/* const uint32_t __AS3___vec_Vector_double_AS3_some = 426; */
/* const uint32_t __AS3___vec_Vector_double_private__slice = 427; */
/* const uint32_t __AS3___vec_Vector_double_private__splice = 428; */
const uint32_t __AS3___vec_Vector_double_private__spliceHelper = 429;
/* const uint32_t __AS3___vec_Vector_double_private__shift = 430; */
const uint32_t __AS3___vec_Vector_double_AS3_unshift = 431;
const uint32_t __AS3___vec_Vector_double_private__filter = 432;
const uint32_t __AS3___vec_Vector_double_private__map = 433;
/* const uint32_t __AS3___vec_Vector_double_private_clamp = 434; */
/* const uint32_t __AS3___vec_Vector_double_AS3_concat = 435; */
/* const uint32_t __AS3___vec_Vector_double_AS3_filter = 436; */
const uint32_t __AS3___vec_Vector_double_AS3_pop = 437;
/* const uint32_t __AS3___vec_Vector_double_AS3_reverse = 438; */
/* const uint32_t __AS3___vec_Vector_double_AS3_shift = 439; */
/* const uint32_t __AS3___vec_Vector_double_AS3_slice = 440; */
/* const uint32_t __AS3___vec_Vector_double_AS3_sort = 441; */
/* const uint32_t __AS3___vec_Vector_double_AS3_splice = 442; */
/* const uint32_t __AS3___vec_Vector_double_AS3_indexOf = 443; */
/* const uint32_t __AS3___vec_Vector_double_AS3_lastIndexOf = 444; */
/* const uint32_t private_MethodClosure_prototype = 446; */
/* const uint32_t private_MethodClosure_prototype = 447; */
const uint32_t private_MethodClosure_length_get = 448;
const uint32_t private_MethodClosure_private_savedThis_get = 449;
const uint32_t Math_private__min = 453;
const uint32_t Math_private__max = 454;
const uint32_t Math_abs = 455;
const uint32_t Math_acos = 456;
const uint32_t Math_asin = 457;
const uint32_t Math_atan = 458;
const uint32_t Math_ceil = 459;
const uint32_t Math_cos = 460;
const uint32_t Math_exp = 461;
const uint32_t Math_floor = 462;
const uint32_t Math_log = 463;
const uint32_t Math_round = 464;
const uint32_t Math_sin = 465;
const uint32_t Math_sqrt = 466;
const uint32_t Math_tan = 467;
const uint32_t Math_atan2 = 468;
const uint32_t Math_pow = 469;
const uint32_t Math_max = 470;
const uint32_t Math_min = 471;
const uint32_t Math_random = 472;
const uint32_t Error_getErrorMessage = 477;
/* const uint32_t Error_throwError = 479; */
const uint32_t Error_getStackTrace = 481;
/* const uint32_t Error_errorID = 482; */
const uint32_t Date_parse = 548;
const uint32_t Date_UTC = 549;
const uint32_t Date_AS3_valueOf = 550;
const uint32_t Date_private__toString = 551;
const uint32_t Date_private__setTime = 552;
const uint32_t Date_private__get = 553;
/* const uint32_t Date_AS3_setTime = 554; */
/* const uint32_t Date_AS3_toString = 555; */
/* const uint32_t Date_AS3_toDateString = 556; */
/* const uint32_t Date_AS3_toTimeString = 557; */
/* const uint32_t Date_AS3_toLocaleString = 558; */
/* const uint32_t Date_AS3_toLocaleDateString = 559; */
/* const uint32_t Date_AS3_toLocaleTimeString = 560; */
/* const uint32_t Date_AS3_toUTCString = 561; */
const uint32_t Date_AS3_getUTCFullYear = 562;
const uint32_t Date_AS3_getUTCMonth = 563;
const uint32_t Date_AS3_getUTCDate = 564;
const uint32_t Date_AS3_getUTCDay = 565;
const uint32_t Date_AS3_getUTCHours = 566;
const uint32_t Date_AS3_getUTCMinutes = 567;
const uint32_t Date_AS3_getUTCSeconds = 568;
const uint32_t Date_AS3_getUTCMilliseconds = 569;
const uint32_t Date_AS3_getFullYear = 570;
const uint32_t Date_AS3_getMonth = 571;
const uint32_t Date_AS3_getDate = 572;
const uint32_t Date_AS3_getDay = 573;
const uint32_t Date_AS3_getHours = 574;
const uint32_t Date_AS3_getMinutes = 575;
const uint32_t Date_AS3_getSeconds = 576;
const uint32_t Date_AS3_getMilliseconds = 577;
const uint32_t Date_AS3_getTimezoneOffset = 578;
const uint32_t Date_AS3_getTime = 579;
const uint32_t Date_private__setFullYear = 580;
const uint32_t Date_private__setMonth = 581;
const uint32_t Date_private__setDate = 582;
const uint32_t Date_private__setHours = 583;
const uint32_t Date_private__setMinutes = 584;
const uint32_t Date_private__setSeconds = 585;
const uint32_t Date_private__setMilliseconds = 586;
const uint32_t Date_private__setUTCFullYear = 587;
const uint32_t Date_private__setUTCMonth = 588;
const uint32_t Date_private__setUTCDate = 589;
const uint32_t Date_private__setUTCHours = 590;
const uint32_t Date_private__setUTCMinutes = 591;
const uint32_t Date_private__setUTCSeconds = 592;
const uint32_t Date_private__setUTCMilliseconds = 593;
/* const uint32_t Date_AS3_setFullYear = 594; */
/* const uint32_t Date_AS3_setMonth = 595; */
/* const uint32_t Date_AS3_setDate = 596; */
/* const uint32_t Date_AS3_setHours = 597; */
/* const uint32_t Date_AS3_setMinutes = 598; */
/* const uint32_t Date_AS3_setSeconds = 599; */
/* const uint32_t Date_AS3_setMilliseconds = 600; */
/* const uint32_t Date_AS3_setUTCFullYear = 601; */
/* const uint32_t Date_AS3_setUTCMonth = 602; */
/* const uint32_t Date_AS3_setUTCDate = 603; */
/* const uint32_t Date_AS3_setUTCHours = 604; */
/* const uint32_t Date_AS3_setUTCMinutes = 605; */
/* const uint32_t Date_AS3_setUTCSeconds = 606; */
/* const uint32_t Date_AS3_setUTCMilliseconds = 607; */
/* const uint32_t Date_fullYear = 608; */
/* const uint32_t Date_fullYear = 609; */
/* const uint32_t Date_month = 610; */
/* const uint32_t Date_month = 611; */
/* const uint32_t Date_date = 612; */
/* const uint32_t Date_date = 613; */
/* const uint32_t Date_hours = 614; */
/* const uint32_t Date_hours = 615; */
/* const uint32_t Date_minutes = 616; */
/* const uint32_t Date_minutes = 617; */
/* const uint32_t Date_seconds = 618; */
/* const uint32_t Date_seconds = 619; */
/* const uint32_t Date_milliseconds = 620; */
/* const uint32_t Date_milliseconds = 621; */
/* const uint32_t Date_fullYearUTC = 622; */
/* const uint32_t Date_fullYearUTC = 623; */
/* const uint32_t Date_monthUTC = 624; */
/* const uint32_t Date_monthUTC = 625; */
/* const uint32_t Date_dateUTC = 626; */
/* const uint32_t Date_dateUTC = 627; */
/* const uint32_t Date_hoursUTC = 628; */
/* const uint32_t Date_hoursUTC = 629; */
/* const uint32_t Date_minutesUTC = 630; */
/* const uint32_t Date_minutesUTC = 631; */
/* const uint32_t Date_secondsUTC = 632; */
/* const uint32_t Date_secondsUTC = 633; */
/* const uint32_t Date_millisecondsUTC = 634; */
/* const uint32_t Date_millisecondsUTC = 635; */
/* const uint32_t Date_time = 636; */
/* const uint32_t Date_time = 637; */
/* const uint32_t Date_timezoneOffset = 638; */
/* const uint32_t Date_day = 639; */
/* const uint32_t Date_dayUTC = 640; */
const uint32_t RegExp_source_get = 647;
const uint32_t RegExp_global_get = 648;
const uint32_t RegExp_ignoreCase_get = 649;
const uint32_t RegExp_multiline_get = 650;
const uint32_t RegExp_lastIndex_get = 651;
const uint32_t RegExp_lastIndex_set = 652;
const uint32_t RegExp_dotall_get = 653;
const uint32_t RegExp_extended_get = 654;
const uint32_t RegExp_AS3_exec = 655;
/* const uint32_t RegExp_AS3_test = 656; */
const uint32_t isXMLName = 659;
const uint32_t XML_ignoreComments_get = 702;
const uint32_t XML_ignoreComments_set = 703;
const uint32_t XML_ignoreProcessingInstructions_get = 704;
const uint32_t XML_ignoreProcessingInstructions_set = 705;
const uint32_t XML_ignoreWhitespace_get = 706;
const uint32_t XML_ignoreWhitespace_set = 707;
const uint32_t XML_prettyPrinting_get = 708;
const uint32_t XML_prettyPrinting_set = 709;
const uint32_t XML_prettyIndent_get = 710;
const uint32_t XML_prettyIndent_set = 711;
/* const uint32_t XML_AS3_settings = 712; */
/* const uint32_t XML_AS3_setSettings = 713; */
/* const uint32_t XML_AS3_defaultSettings = 714; */
const uint32_t XML_AS3_toString = 715;
const uint32_t XML_AS3_hasOwnProperty = 716;
const uint32_t XML_AS3_propertyIsEnumerable = 717;
const uint32_t XML_AS3_addNamespace = 718;
const uint32_t XML_AS3_appendChild = 719;
const uint32_t XML_AS3_attribute = 720;
const uint32_t XML_AS3_attributes = 721;
const uint32_t XML_AS3_child = 722;
const uint32_t XML_AS3_childIndex = 723;
const uint32_t XML_AS3_children = 724;
const uint32_t XML_AS3_comments = 725;
const uint32_t XML_AS3_contains = 726;
const uint32_t XML_AS3_copy = 727;
const uint32_t XML_AS3_descendants = 728;
const uint32_t XML_AS3_elements = 729;
const uint32_t XML_AS3_hasComplexContent = 730;
const uint32_t XML_AS3_hasSimpleContent = 731;
const uint32_t XML_AS3_inScopeNamespaces = 732;
const uint32_t XML_AS3_insertChildAfter = 733;
const uint32_t XML_AS3_insertChildBefore = 734;
/* const uint32_t XML_AS3_length = 735; */
const uint32_t XML_AS3_localName = 736;
const uint32_t XML_AS3_name = 737;
const uint32_t XML_private__namespace = 738;
/* const uint32_t XML_AS3_namespace = 739; */
const uint32_t XML_AS3_namespaceDeclarations = 740;
const uint32_t XML_AS3_nodeKind = 741;
const uint32_t XML_AS3_normalize = 742;
const uint32_t XML_AS3_parent = 743;
const uint32_t XML_AS3_processingInstructions = 744;
const uint32_t XML_AS3_prependChild = 745;
const uint32_t XML_AS3_removeNamespace = 746;
const uint32_t XML_AS3_replace = 747;
const uint32_t XML_AS3_setChildren = 748;
const uint32_t XML_AS3_setLocalName = 749;
const uint32_t XML_AS3_setName = 750;
const uint32_t XML_AS3_setNamespace = 751;
const uint32_t XML_AS3_text = 752;
const uint32_t XML_AS3_toXMLString = 753;
const uint32_t XML_AS3_notification = 754;
const uint32_t XML_AS3_setNotification = 755;
/* const uint32_t XML_AS3_valueOf = 757; */
const uint32_t XMLList_AS3_toString = 797;
/* const uint32_t XMLList_AS3_valueOf = 798; */
const uint32_t XMLList_AS3_hasOwnProperty = 799;
const uint32_t XMLList_AS3_propertyIsEnumerable = 800;
const uint32_t XMLList_AS3_attribute = 801;
const uint32_t XMLList_AS3_attributes = 802;
const uint32_t XMLList_AS3_child = 803;
const uint32_t XMLList_AS3_children = 804;
const uint32_t XMLList_AS3_comments = 805;
const uint32_t XMLList_AS3_contains = 806;
const uint32_t XMLList_AS3_copy = 807;
const uint32_t XMLList_AS3_descendants = 808;
const uint32_t XMLList_AS3_elements = 809;
const uint32_t XMLList_AS3_hasComplexContent = 810;
const uint32_t XMLList_AS3_hasSimpleContent = 811;
const uint32_t XMLList_AS3_length = 812;
const uint32_t XMLList_AS3_name = 813;
const uint32_t XMLList_AS3_normalize = 814;
const uint32_t XMLList_AS3_parent = 815;
const uint32_t XMLList_AS3_processingInstructions = 816;
const uint32_t XMLList_AS3_text = 817;
const uint32_t XMLList_AS3_toXMLString = 818;
const uint32_t XMLList_AS3_addNamespace = 819;
const uint32_t XMLList_AS3_appendChild = 820;
const uint32_t XMLList_AS3_childIndex = 821;
const uint32_t XMLList_AS3_inScopeNamespaces = 822;
const uint32_t XMLList_AS3_insertChildAfter = 823;
const uint32_t XMLList_AS3_insertChildBefore = 824;
const uint32_t XMLList_AS3_nodeKind = 825;
const uint32_t XMLList_private__namespace = 826;
/* const uint32_t XMLList_AS3_namespace = 827; */
const uint32_t XMLList_AS3_localName = 828;
const uint32_t XMLList_AS3_namespaceDeclarations = 829;
const uint32_t XMLList_AS3_prependChild = 830;
const uint32_t XMLList_AS3_removeNamespace = 831;
const uint32_t XMLList_AS3_replace = 832;
const uint32_t XMLList_AS3_setChildren = 833;
const uint32_t XMLList_AS3_setLocalName = 834;
const uint32_t XMLList_AS3_setName = 835;
const uint32_t XMLList_AS3_setNamespace = 836;
const uint32_t QName_localName_get = 840;
const uint32_t QName_uri_get = 841;
/* const uint32_t QName_AS3_valueOf = 842; */
/* const uint32_t QName_AS3_toString = 843; */

/* thunks (71 unique) */
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oaoa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oaoa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Array_private__filter_thunk  builtin_a2a_oaoa_thunk
#define Array_private__filter_thunkc builtin_a2a_oaoa_thunkc
#define Array_private__map_thunk  builtin_a2a_oaoa_thunk
#define Array_private__map_thunkc builtin_a2a_oaoa_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE builtin_v2a_ouuuai_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE builtin_v2a_ouuuai_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define __AS3___vec_Vector_object_private__spliceHelper_thunk  builtin_v2a_ouuuai_thunk
#define __AS3___vec_Vector_object_private__spliceHelper_thunkc builtin_v2a_ouuuai_thunkc
#define __AS3___vec_Vector_uint_private__spliceHelper_thunk  builtin_v2a_ouuuai_thunk
#define __AS3___vec_Vector_uint_private__spliceHelper_thunkc builtin_v2a_ouuuai_thunkc
#define __AS3___vec_Vector_int_private__spliceHelper_thunk  builtin_v2a_ouuuai_thunk
#define __AS3___vec_Vector_int_private__spliceHelper_thunkc builtin_v2a_ouuuai_thunkc
#define __AS3___vec_Vector_double_private__spliceHelper_thunk  builtin_v2a_ouuuai_thunk
#define __AS3___vec_Vector_double_private__spliceHelper_thunkc builtin_v2a_ouuuai_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_si_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_si_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_private__charCodeAt_thunk  builtin_d2d_si_opti0_thunk
#define String_private__charCodeAt_thunkc builtin_d2d_si_opti0_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Date_AS3_getUTCDate_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCDate_thunkc builtin_d2d_o_thunkc
#define __AS3___vec_Vector_double_AS3_pop_thunk  builtin_d2d_o_thunk
#define __AS3___vec_Vector_double_AS3_pop_thunkc builtin_d2d_o_thunkc
#define Date_AS3_valueOf_thunk  builtin_d2d_o_thunk
#define Date_AS3_valueOf_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getDay_thunk  builtin_d2d_o_thunk
#define Date_AS3_getDay_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getSeconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getSeconds_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getUTCFullYear_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCFullYear_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getMilliseconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getMilliseconds_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getUTCDay_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCDay_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getMonth_thunk  builtin_d2d_o_thunk
#define Date_AS3_getMonth_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getUTCHours_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCHours_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getMinutes_thunk  builtin_d2d_o_thunk
#define Date_AS3_getMinutes_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getUTCMilliseconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCMilliseconds_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getUTCMonth_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCMonth_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getTime_thunk  builtin_d2d_o_thunk
#define Date_AS3_getTime_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getTimezoneOffset_thunk  builtin_d2d_o_thunk
#define Date_AS3_getTimezoneOffset_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getFullYear_thunk  builtin_d2d_o_thunk
#define Date_AS3_getFullYear_thunkc builtin_d2d_o_thunkc
#define Math_random_thunk  builtin_d2d_o_thunk
#define Math_random_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getUTCSeconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCSeconds_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getDate_thunk  builtin_d2d_o_thunk
#define Date_AS3_getDate_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getUTCMinutes_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCMinutes_thunkc builtin_d2d_o_thunkc
#define Date_AS3_getHours_thunk  builtin_d2d_o_thunk
#define Date_AS3_getHours_thunkc builtin_d2d_o_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ss_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ss_optakAvmThunkUndefined_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_AS3_localeCompare_thunk  builtin_i2a_ss_optakAvmThunkUndefined_thunk
#define String_AS3_localeCompare_thunkc builtin_i2a_ss_optakAvmThunkUndefined_thunkc

extern AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE builtin_u2a_o_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE builtin_u2a_o_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define __AS3___vec_Vector_double_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_double_AS3_push_thunkc builtin_u2a_o_rest_thunkc
#define __AS3___vec_Vector_object_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_object_AS3_push_thunkc builtin_u2a_o_rest_thunkc
#define __AS3___vec_Vector_uint_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_uint_AS3_push_thunkc builtin_u2a_o_rest_thunkc
#define Array_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define Array_AS3_unshift_thunkc builtin_u2a_o_rest_thunkc
#define Array_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define Array_AS3_push_thunkc builtin_u2a_o_rest_thunkc
#define __AS3___vec_Vector_int_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_int_AS3_unshift_thunkc builtin_u2a_o_rest_thunkc
#define __AS3___vec_Vector_uint_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_uint_AS3_unshift_thunkc builtin_u2a_o_rest_thunkc
#define __AS3___vec_Vector_double_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_double_AS3_unshift_thunkc builtin_u2a_o_rest_thunkc
#define __AS3___vec_Vector_object_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_object_AS3_unshift_thunkc builtin_u2a_o_rest_thunkc
#define __AS3___vec_Vector_int_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_int_AS3_push_thunkc builtin_u2a_o_rest_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_ou_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_ou_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define __AS3___vec_Vector_uint_length_set_thunk  builtin_a2a_ou_thunk
#define __AS3___vec_Vector_uint_length_set_thunkc builtin_a2a_ou_thunkc
#define __AS3___vec_Vector_object_length_set_thunk  builtin_a2a_ou_thunk
#define __AS3___vec_Vector_object_length_set_thunkc builtin_a2a_ou_thunkc
#define __AS3___vec_Vector_int_length_set_thunk  builtin_a2a_ou_thunk
#define __AS3___vec_Vector_int_length_set_thunkc builtin_a2a_ou_thunkc
#define __AS3___vec_Vector_double_length_set_thunk  builtin_a2a_ou_thunk
#define __AS3___vec_Vector_double_length_set_thunkc builtin_a2a_ou_thunkc
#define Array_length_set_thunk  builtin_a2a_ou_thunk
#define Array_length_set_thunkc builtin_a2a_ou_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_odi_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_odi_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Number_private__toString_thunk  builtin_s2a_odi_thunk
#define Number_private__toString_thunkc builtin_s2a_odi_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oi_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oi_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define XML_prettyIndent_set_thunk  builtin_a2a_oi_thunk
#define XML_prettyIndent_set_thunkc builtin_a2a_oi_thunkc
#define RegExp_lastIndex_set_thunk  builtin_a2a_oi_thunk
#define RegExp_lastIndex_set_thunkc builtin_a2a_oi_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oo_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define XML_AS3_setNotification_thunk  builtin_a2a_oo_thunk
#define XML_AS3_setNotification_thunkc builtin_a2a_oo_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define unescape_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunk
#define unescape_thunkc builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunkc
#define decodeURI_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunk
#define decodeURI_thunkc builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunkc
#define decodeURIComponent_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunk
#define decodeURIComponent_thunkc builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunkc
#define escape_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunk
#define escape_thunkc builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunkc
#define encodeURIComponent_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunk
#define encodeURIComponent_thunkc builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunkc
#define encodeURI_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunk
#define encodeURI_thunkc builtin_s2a_os_optsAvmThunkConstant_AvmString_3_____undefined_____thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define XML_AS3_toXMLString_thunk  builtin_s2a_o_thunk
#define XML_AS3_toXMLString_thunkc builtin_s2a_o_thunkc
#define XML_AS3_toString_thunk  builtin_s2a_o_thunk
#define XML_AS3_toString_thunkc builtin_s2a_o_thunkc
#define Error_getStackTrace_thunk  builtin_s2a_o_thunk
#define Error_getStackTrace_thunkc builtin_s2a_o_thunkc
#define QName_localName_get_thunk  builtin_s2a_o_thunk
#define QName_localName_get_thunkc builtin_s2a_o_thunkc
#define XMLList_AS3_toString_thunk  builtin_s2a_o_thunk
#define XMLList_AS3_toString_thunkc builtin_s2a_o_thunkc
#define XML_AS3_nodeKind_thunk  builtin_s2a_o_thunk
#define XML_AS3_nodeKind_thunkc builtin_s2a_o_thunkc
#define RegExp_source_get_thunk  builtin_s2a_o_thunk
#define RegExp_source_get_thunkc builtin_s2a_o_thunkc
#define XMLList_AS3_toXMLString_thunk  builtin_s2a_o_thunk
#define XMLList_AS3_toXMLString_thunkc builtin_s2a_o_thunkc
#define XMLList_AS3_nodeKind_thunk  builtin_s2a_o_thunk
#define XMLList_AS3_nodeKind_thunkc builtin_s2a_o_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_ob_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_ob_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define __AS3___vec_Vector_uint_fixed_set_thunk  builtin_a2a_ob_thunk
#define __AS3___vec_Vector_uint_fixed_set_thunkc builtin_a2a_ob_thunkc
#define XML_prettyPrinting_set_thunk  builtin_a2a_ob_thunk
#define XML_prettyPrinting_set_thunkc builtin_a2a_ob_thunkc
#define __AS3___vec_Vector_object_fixed_set_thunk  builtin_a2a_ob_thunk
#define __AS3___vec_Vector_object_fixed_set_thunkc builtin_a2a_ob_thunkc
#define XML_ignoreComments_set_thunk  builtin_a2a_ob_thunk
#define XML_ignoreComments_set_thunkc builtin_a2a_ob_thunkc
#define XML_ignoreWhitespace_set_thunk  builtin_a2a_ob_thunk
#define XML_ignoreWhitespace_set_thunkc builtin_a2a_ob_thunkc
#define __AS3___vec_Vector_double_fixed_set_thunk  builtin_a2a_ob_thunk
#define __AS3___vec_Vector_double_fixed_set_thunkc builtin_a2a_ob_thunkc
#define XML_ignoreProcessingInstructions_set_thunk  builtin_a2a_ob_thunk
#define XML_ignoreProcessingInstructions_set_thunkc builtin_a2a_ob_thunkc
#define __AS3___vec_Vector_int_fixed_set_thunk  builtin_a2a_ob_thunk
#define __AS3___vec_Vector_int_fixed_set_thunkc builtin_a2a_ob_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_odd_optdkAvmThunkNegInfinity_optdkAvmThunkNegInfinity_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_odd_optdkAvmThunkNegInfinity_optdkAvmThunkNegInfinity_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Math_max_thunk  builtin_d2d_odd_optdkAvmThunkNegInfinity_optdkAvmThunkNegInfinity_rest_thunk
#define Math_max_thunkc builtin_d2d_odd_optdkAvmThunkNegInfinity_optdkAvmThunkNegInfinity_rest_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define XML_AS3_addNamespace_thunk  builtin_a2a_oa_thunk
#define XML_AS3_addNamespace_thunkc builtin_a2a_oa_thunkc
#define Array_private__pop_thunk  builtin_a2a_oa_thunk
#define Array_private__pop_thunkc builtin_a2a_oa_thunkc
#define XML_AS3_removeNamespace_thunk  builtin_a2a_oa_thunk
#define XML_AS3_removeNamespace_thunkc builtin_a2a_oa_thunkc
#define Array_private__reverse_thunk  builtin_a2a_oa_thunk
#define Array_private__reverse_thunkc builtin_a2a_oa_thunkc
#define XMLList_AS3_setChildren_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_setChildren_thunkc builtin_a2a_oa_thunkc
#define XMLList_AS3_prependChild_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_prependChild_thunkc builtin_a2a_oa_thunkc
#define XML_AS3_appendChild_thunk  builtin_a2a_oa_thunk
#define XML_AS3_appendChild_thunkc builtin_a2a_oa_thunkc
#define XMLList_AS3_appendChild_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_appendChild_thunkc builtin_a2a_oa_thunkc
#define XML_AS3_prependChild_thunk  builtin_a2a_oa_thunk
#define XML_AS3_prependChild_thunkc builtin_a2a_oa_thunkc
#define XMLList_AS3_child_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_child_thunkc builtin_a2a_oa_thunkc
#define Function_prototype_set_thunk  builtin_a2a_oa_thunk
#define Function_prototype_set_thunkc builtin_a2a_oa_thunkc
#define XMLList_AS3_attribute_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_attribute_thunkc builtin_a2a_oa_thunkc
#define XMLList_AS3_addNamespace_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_addNamespace_thunkc builtin_a2a_oa_thunkc
#define XML_AS3_child_thunk  builtin_a2a_oa_thunk
#define XML_AS3_child_thunkc builtin_a2a_oa_thunkc
#define XML_AS3_attribute_thunk  builtin_a2a_oa_thunk
#define XML_AS3_attribute_thunkc builtin_a2a_oa_thunkc
#define XMLList_AS3_removeNamespace_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_removeNamespace_thunkc builtin_a2a_oa_thunkc
#define Array_private__shift_thunk  builtin_a2a_oa_thunk
#define Array_private__shift_thunkc builtin_a2a_oa_thunkc
#define XML_AS3_setChildren_thunk  builtin_a2a_oa_thunk
#define XML_AS3_setChildren_thunkc builtin_a2a_oa_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_sd_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_sd_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_AS3_charAt_thunk  builtin_s2a_sd_opti0_thunk
#define String_AS3_charAt_thunkc builtin_s2a_sd_opti0_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_o_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_o_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Date_private__setUTCDate_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCDate_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setFullYear_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setFullYear_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setMinutes_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setMinutes_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setUTCMonth_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCMonth_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setUTCSeconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCSeconds_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setHours_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setHours_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setDate_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setDate_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setUTCMinutes_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCMinutes_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setMonth_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setMonth_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setUTCHours_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCHours_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setSeconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setSeconds_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setUTCFullYear_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCFullYear_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setMilliseconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setMilliseconds_thunkc builtin_d2d_o_rest_thunkc
#define Date_private__setUTCMilliseconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCMilliseconds_thunkc builtin_d2d_o_rest_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_oaaaaaaa_opti1_opti0_opti0_opti0_opti0_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_oaaaaaaa_opti1_opti0_opti0_opti0_opti0_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Date_UTC_thunk  builtin_d2d_oaaaaaaa_opti1_opti0_opti0_opti0_opti0_rest_thunk
#define Date_UTC_thunkc builtin_d2d_oaaaaaaa_opti1_opti0_opti0_opti0_opti0_rest_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_s_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_s_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_length_get_thunk  builtin_i2a_s_thunk
#define String_length_get_thunkc builtin_i2a_s_thunkc

extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oaa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oaa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Object_private__isPrototypeOf_thunk  builtin_b2a_oaa_thunk
#define Object_private__isPrototypeOf_thunkc builtin_b2a_oaa_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oaaa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oaaa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Array_private__sortOn_thunk  builtin_a2a_oaaa_thunk
#define Array_private__sortOn_thunkc builtin_a2a_oaaa_thunkc

extern AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE builtin_u2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_uint32_t AVMTHUNK_CALLTYPE builtin_u2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define __AS3___vec_Vector_uint_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_uint_length_get_thunkc builtin_u2a_o_thunkc
#define __AS3___vec_Vector_int_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_int_length_get_thunkc builtin_u2a_o_thunkc
#define Array_length_get_thunk  builtin_u2a_o_thunk
#define Array_length_get_thunkc builtin_u2a_o_thunkc
#define __AS3___vec_Vector_uint_AS3_pop_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_uint_AS3_pop_thunkc builtin_u2a_o_thunkc
#define __AS3___vec_Vector_object_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_object_length_get_thunkc builtin_u2a_o_thunkc
#define __AS3___vec_Vector_double_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_double_length_get_thunkc builtin_u2a_o_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_osi_optsAvmThunkConstant_AvmString_5_____NaN_____opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_osi_optsAvmThunkConstant_AvmString_5_____NaN_____opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define parseInt_thunk  builtin_d2d_osi_optsAvmThunkConstant_AvmString_5_____NaN_____opti0_thunk
#define parseInt_thunkc builtin_d2d_osi_optsAvmThunkConstant_AvmString_5_____NaN_____opti0_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oa_optakAvmThunkUndefined_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oa_optakAvmThunkUndefined_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Function_AS3_call_thunk  builtin_a2a_oa_optakAvmThunkUndefined_rest_thunk
#define Function_AS3_call_thunkc builtin_a2a_oa_optakAvmThunkUndefined_rest_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_si_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_si_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_private__charAt_thunk  builtin_s2a_si_opti0_thunk
#define String_private__charAt_thunkc builtin_s2a_si_opti0_thunkc

extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_od_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_od_optakAvmThunkUndefined_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define isNaN_thunk  builtin_b2a_od_optakAvmThunkUndefined_thunk
#define isNaN_thunkc builtin_b2a_od_optakAvmThunkUndefined_thunkc
#define isFinite_thunk  builtin_b2a_od_optakAvmThunkUndefined_thunk
#define isFinite_thunkc builtin_b2a_od_optakAvmThunkUndefined_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssd_optsAvmThunkConstant_AvmString_3_____undefined_____opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssd_optsAvmThunkConstant_AvmString_3_____undefined_____opti2147483647_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_AS3_lastIndexOf_thunk  builtin_i2a_ssd_optsAvmThunkConstant_AvmString_3_____undefined_____opti2147483647_thunk
#define String_AS3_lastIndexOf_thunkc builtin_i2a_ssd_optsAvmThunkConstant_AvmString_3_____undefined_____opti2147483647_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define XML_AS3_childIndex_thunk  builtin_i2a_o_thunk
#define XML_AS3_childIndex_thunkc builtin_i2a_o_thunkc
#define XML_prettyIndent_get_thunk  builtin_i2a_o_thunk
#define XML_prettyIndent_get_thunkc builtin_i2a_o_thunkc
#define private_MethodClosure_length_get_thunk  builtin_i2a_o_thunk
#define private_MethodClosure_length_get_thunkc builtin_i2a_o_thunkc
#define __AS3___vec_Vector_int_AS3_pop_thunk  builtin_i2a_o_thunk
#define __AS3___vec_Vector_int_AS3_pop_thunkc builtin_i2a_o_thunkc
#define XMLList_AS3_length_thunk  builtin_i2a_o_thunk
#define XMLList_AS3_length_thunkc builtin_i2a_o_thunkc
#define RegExp_lastIndex_get_thunk  builtin_i2a_o_thunk
#define RegExp_lastIndex_get_thunkc builtin_i2a_o_thunkc
#define XMLList_AS3_childIndex_thunk  builtin_i2a_o_thunk
#define XMLList_AS3_childIndex_thunkc builtin_i2a_o_thunkc
#define Function_length_get_thunk  builtin_i2a_o_thunk
#define Function_length_get_thunkc builtin_i2a_o_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssd_optsAvmThunkConstant_AvmString_3_____undefined_____opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssd_optsAvmThunkConstant_AvmString_3_____undefined_____opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_AS3_indexOf_thunk  builtin_i2a_ssd_optsAvmThunkConstant_AvmString_3_____undefined_____opti0_thunk
#define String_AS3_indexOf_thunkc builtin_i2a_ssd_optsAvmThunkConstant_AvmString_3_____undefined_____opti0_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_ooa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_ooa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define __AS3___vec_Vector_object_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_object_private__map_thunkc builtin_a2a_ooa_thunkc
#define __AS3___vec_Vector_double_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_double_private__filter_thunkc builtin_a2a_ooa_thunkc
#define __AS3___vec_Vector_object_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_object_private__filter_thunkc builtin_a2a_ooa_thunkc
#define __AS3___vec_Vector_int_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_int_private__map_thunkc builtin_a2a_ooa_thunkc
#define __AS3___vec_Vector_uint_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_uint_private__map_thunkc builtin_a2a_ooa_thunkc
#define __AS3___vec_Vector_int_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_int_private__filter_thunkc builtin_a2a_ooa_thunkc
#define __AS3___vec_Vector_double_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_double_private__map_thunkc builtin_a2a_ooa_thunkc
#define __AS3___vec_Vector_uint_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_uint_private__filter_thunkc builtin_a2a_ooa_thunkc

extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oas_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oas_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Object_private__hasOwnProperty_thunk  builtin_b2a_oas_thunk
#define Object_private__hasOwnProperty_thunkc builtin_b2a_oas_thunkc
#define Object_private__propertyIsEnumerable_thunk  builtin_b2a_oas_thunk
#define Object_private__propertyIsEnumerable_thunkc builtin_b2a_oas_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_sd_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_sd_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_AS3_charCodeAt_thunk  builtin_d2d_sd_opti0_thunk
#define String_AS3_charCodeAt_thunkc builtin_d2d_sd_opti0_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_oa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_oa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Object_private__toString_thunk  builtin_s2a_oa_thunk
#define Object_private__toString_thunkc builtin_s2a_oa_thunkc

extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oaoa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oaoa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define __AS3___vec_Vector_double_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_double_private__every_thunkc builtin_b2a_oaoa_thunkc
#define __AS3___vec_Vector_int_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_int_private__some_thunkc builtin_b2a_oaoa_thunkc
#define __AS3___vec_Vector_object_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_object_private__some_thunkc builtin_b2a_oaoa_thunkc
#define Array_private__some_thunk  builtin_b2a_oaoa_thunk
#define Array_private__some_thunkc builtin_b2a_oaoa_thunkc
#define __AS3___vec_Vector_double_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_double_private__some_thunkc builtin_b2a_oaoa_thunkc
#define __AS3___vec_Vector_uint_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_uint_private__some_thunkc builtin_b2a_oaoa_thunkc
#define __AS3___vec_Vector_object_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_object_private__every_thunkc builtin_b2a_oaoa_thunkc
#define Array_private__every_thunk  builtin_b2a_oaoa_thunk
#define Array_private__every_thunkc builtin_b2a_oaoa_thunkc
#define __AS3___vec_Vector_int_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_int_private__every_thunkc builtin_b2a_oaoa_thunkc
#define __AS3___vec_Vector_uint_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_uint_private__every_thunkc builtin_b2a_oaoa_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssi_opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssi_opti2147483647_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_private__lastIndexOf_thunk  builtin_i2a_ssi_opti2147483647_thunk
#define String_private__lastIndexOf_thunkc builtin_i2a_ssi_opti2147483647_thunkc

extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define XMLList_AS3_contains_thunk  builtin_b2a_oa_thunk
#define XMLList_AS3_contains_thunkc builtin_b2a_oa_thunkc
#define XML_AS3_contains_thunk  builtin_b2a_oa_thunk
#define XML_AS3_contains_thunkc builtin_b2a_oa_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_osa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_osa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_private__match_thunk  builtin_a2a_osa_thunk
#define String_private__match_thunkc builtin_a2a_osa_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE builtin_v2a_oaoa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE builtin_v2a_oaoa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define __AS3___vec_Vector_double_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_double_private__forEach_thunkc builtin_v2a_oaoa_thunkc
#define __AS3___vec_Vector_object_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_object_private__forEach_thunkc builtin_v2a_oaoa_thunkc
#define __AS3___vec_Vector_int_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_int_private__forEach_thunkc builtin_v2a_oaoa_thunkc
#define __AS3___vec_Vector_uint_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_uint_private__forEach_thunkc builtin_v2a_oaoa_thunkc
#define Array_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define Array_private__forEach_thunkc builtin_v2a_oaoa_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define XMLList_AS3_elements_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunk
#define XMLList_AS3_elements_thunkc builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunkc
#define XMLList_AS3_descendants_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunk
#define XMLList_AS3_descendants_thunkc builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunkc
#define XML_AS3_processingInstructions_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunk
#define XML_AS3_processingInstructions_thunkc builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunkc
#define XML_AS3_elements_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunk
#define XML_AS3_elements_thunkc builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunkc
#define XML_AS3_descendants_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunk
#define XML_AS3_descendants_thunkc builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunkc
#define XMLList_AS3_processingInstructions_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunk
#define XMLList_AS3_processingInstructions_thunkc builtin_a2a_oa_optsAvmThunkConstant_AvmString_0___________thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_s_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_s_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_AS3_toLowerCase_thunk  builtin_s2a_s_thunk
#define String_AS3_toLowerCase_thunkc builtin_s2a_s_thunkc
#define String_AS3_toUpperCase_thunk  builtin_s2a_s_thunk
#define String_AS3_toUpperCase_thunkc builtin_s2a_s_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_sdd_opti0_opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_sdd_opti0_opti2147483647_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_AS3_substr_thunk  builtin_s2a_sdd_opti0_opti2147483647_thunk
#define String_AS3_substr_thunkc builtin_s2a_sdd_opti0_opti2147483647_thunkc
#define String_AS3_substring_thunk  builtin_s2a_sdd_opti0_opti2147483647_thunk
#define String_AS3_substring_thunkc builtin_s2a_sdd_opti0_opti2147483647_thunkc
#define String_AS3_slice_thunk  builtin_s2a_sdd_opti0_opti2147483647_thunk
#define String_AS3_slice_thunkc builtin_s2a_sdd_opti0_opti2147483647_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_odd_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_odd_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Math_private__min_thunk  builtin_d2d_odd_thunk
#define Math_private__min_thunkc builtin_d2d_odd_thunkc
#define Math_private__max_thunk  builtin_d2d_odd_thunk
#define Math_private__max_thunkc builtin_d2d_odd_thunkc
#define Math_pow_thunk  builtin_d2d_odd_thunk
#define Math_pow_thunkc builtin_d2d_odd_thunkc
#define Math_atan2_thunk  builtin_d2d_odd_thunk
#define Math_atan2_thunkc builtin_d2d_odd_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_n_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_n_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Namespace_prefix_get_thunk  builtin_a2a_n_thunk
#define Namespace_prefix_get_thunkc builtin_a2a_n_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define private_MethodClosure_private_savedThis_get_thunk  builtin_a2a_o_thunk
#define private_MethodClosure_private_savedThis_get_thunkc builtin_a2a_o_thunkc
#define XMLList_AS3_inScopeNamespaces_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_inScopeNamespaces_thunkc builtin_a2a_o_thunkc
#define XML_AS3_notification_thunk  builtin_a2a_o_thunk
#define XML_AS3_notification_thunkc builtin_a2a_o_thunkc
#define XML_AS3_inScopeNamespaces_thunk  builtin_a2a_o_thunk
#define XML_AS3_inScopeNamespaces_thunkc builtin_a2a_o_thunkc
#define XMLList_AS3_copy_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_copy_thunkc builtin_a2a_o_thunkc
#define XMLList_AS3_children_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_children_thunkc builtin_a2a_o_thunkc
#define XMLList_AS3_text_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_text_thunkc builtin_a2a_o_thunkc
#define XML_AS3_attributes_thunk  builtin_a2a_o_thunk
#define XML_AS3_attributes_thunkc builtin_a2a_o_thunkc
#define __AS3___vec_Vector_object_AS3_pop_thunk  builtin_a2a_o_thunk
#define __AS3___vec_Vector_object_AS3_pop_thunkc builtin_a2a_o_thunkc
#define __AS3___vec_Vector_object_private_type_get_thunk  builtin_a2a_o_thunk
#define __AS3___vec_Vector_object_private_type_get_thunkc builtin_a2a_o_thunkc
#define XML_AS3_name_thunk  builtin_a2a_o_thunk
#define XML_AS3_name_thunkc builtin_a2a_o_thunkc
#define XML_AS3_namespaceDeclarations_thunk  builtin_a2a_o_thunk
#define XML_AS3_namespaceDeclarations_thunkc builtin_a2a_o_thunkc
#define Class_prototype_get_thunk  builtin_a2a_o_thunk
#define Class_prototype_get_thunkc builtin_a2a_o_thunkc
#define XMLList_AS3_name_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_name_thunkc builtin_a2a_o_thunkc
#define QName_uri_get_thunk  builtin_a2a_o_thunk
#define QName_uri_get_thunkc builtin_a2a_o_thunkc
#define XMLList_AS3_normalize_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_normalize_thunkc builtin_a2a_o_thunkc
#define XML_AS3_text_thunk  builtin_a2a_o_thunk
#define XML_AS3_text_thunkc builtin_a2a_o_thunkc
#define XMLList_AS3_namespaceDeclarations_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_namespaceDeclarations_thunkc builtin_a2a_o_thunkc
#define Function_prototype_get_thunk  builtin_a2a_o_thunk
#define Function_prototype_get_thunkc builtin_a2a_o_thunkc
#define XML_AS3_children_thunk  builtin_a2a_o_thunk
#define XML_AS3_children_thunkc builtin_a2a_o_thunkc
#define XML_AS3_parent_thunk  builtin_a2a_o_thunk
#define XML_AS3_parent_thunkc builtin_a2a_o_thunkc
#define XMLList_AS3_comments_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_comments_thunkc builtin_a2a_o_thunkc
#define XMLList_AS3_attributes_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_attributes_thunkc builtin_a2a_o_thunkc
#define XML_AS3_copy_thunk  builtin_a2a_o_thunk
#define XML_AS3_copy_thunkc builtin_a2a_o_thunkc
#define XML_AS3_normalize_thunk  builtin_a2a_o_thunk
#define XML_AS3_normalize_thunkc builtin_a2a_o_thunkc
#define Array_AS3_pop_thunk  builtin_a2a_o_thunk
#define Array_AS3_pop_thunkc builtin_a2a_o_thunkc
#define XMLList_AS3_parent_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_parent_thunkc builtin_a2a_o_thunkc
#define XML_AS3_localName_thunk  builtin_a2a_o_thunk
#define XML_AS3_localName_thunkc builtin_a2a_o_thunkc
#define XMLList_AS3_localName_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_localName_thunkc builtin_a2a_o_thunkc
#define XML_AS3_comments_thunk  builtin_a2a_o_thunk
#define XML_AS3_comments_thunkc builtin_a2a_o_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_osaa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_osaa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_private__replace_thunk  builtin_s2a_osaa_thunk
#define String_private__replace_thunkc builtin_s2a_osaa_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE builtin_v2a_oasb_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE builtin_v2a_oasb_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Object_protected__setPropertyIsEnumerable_thunk  builtin_v2a_oasb_thunk
#define Object_protected__setPropertyIsEnumerable_thunkc builtin_v2a_oasb_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_osau_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_osau_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_private__split_thunk  builtin_a2a_osau_thunk
#define String_private__split_thunkc builtin_a2a_osau_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oai_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oai_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define XMLList_private__namespace_thunk  builtin_a2a_oai_thunk
#define XMLList_private__namespace_thunkc builtin_a2a_oai_thunkc
#define XML_private__namespace_thunk  builtin_a2a_oai_thunk
#define XML_private__namespace_thunkc builtin_a2a_oai_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_oi_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_oi_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Date_private__toString_thunk  builtin_s2a_oi_thunk
#define Date_private__toString_thunkc builtin_s2a_oi_thunkc
#define Error_getErrorMessage_thunk  builtin_s2a_oi_thunk
#define Error_getErrorMessage_thunkc builtin_s2a_oi_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssi_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssi_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_private__indexOf_thunk  builtin_i2a_ssi_opti0_thunk
#define String_private__indexOf_thunkc builtin_i2a_ssi_opti0_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_oaai_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_oaai_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Array_private__lastIndexOf_thunk  builtin_i2a_oaai_opti0_thunk
#define Array_private__lastIndexOf_thunkc builtin_i2a_oaai_opti0_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_od_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_od_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Date_private__setTime_thunk  builtin_d2d_od_thunk
#define Date_private__setTime_thunkc builtin_d2d_od_thunkc
#define Math_cos_thunk  builtin_d2d_od_thunk
#define Math_cos_thunkc builtin_d2d_od_thunkc
#define Math_ceil_thunk  builtin_d2d_od_thunk
#define Math_ceil_thunkc builtin_d2d_od_thunkc
#define Math_acos_thunk  builtin_d2d_od_thunk
#define Math_acos_thunkc builtin_d2d_od_thunkc
#define Math_abs_thunk  builtin_d2d_od_thunk
#define Math_abs_thunkc builtin_d2d_od_thunkc
#define Math_atan_thunk  builtin_d2d_od_thunk
#define Math_atan_thunkc builtin_d2d_od_thunkc
#define Math_asin_thunk  builtin_d2d_od_thunk
#define Math_asin_thunkc builtin_d2d_od_thunkc
#define Math_exp_thunk  builtin_d2d_od_thunk
#define Math_exp_thunkc builtin_d2d_od_thunkc
#define Math_log_thunk  builtin_d2d_od_thunk
#define Math_log_thunkc builtin_d2d_od_thunkc
#define Math_round_thunk  builtin_d2d_od_thunk
#define Math_round_thunkc builtin_d2d_od_thunkc
#define Math_tan_thunk  builtin_d2d_od_thunk
#define Math_tan_thunkc builtin_d2d_od_thunkc
#define Math_sin_thunk  builtin_d2d_od_thunk
#define Math_sin_thunkc builtin_d2d_od_thunkc
#define Math_sqrt_thunk  builtin_d2d_od_thunk
#define Math_sqrt_thunkc builtin_d2d_od_thunkc
#define Math_floor_thunk  builtin_d2d_od_thunk
#define Math_floor_thunkc builtin_d2d_od_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oaa_optakAvmThunkUndefined_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oaa_optakAvmThunkUndefined_optakAvmThunkUndefined_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Function_AS3_apply_thunk  builtin_a2a_oaa_optakAvmThunkUndefined_optakAvmThunkUndefined_thunk
#define Function_AS3_apply_thunkc builtin_a2a_oaa_optakAvmThunkUndefined_optakAvmThunkUndefined_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_sii_opti0_opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_sii_opti0_opti2147483647_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_private__substr_thunk  builtin_s2a_sii_opti0_opti2147483647_thunk
#define String_private__substr_thunkc builtin_s2a_sii_opti0_opti2147483647_thunkc
#define String_private__slice_thunk  builtin_s2a_sii_opti0_opti2147483647_thunk
#define String_private__slice_thunkc builtin_s2a_sii_opti0_opti2147483647_thunkc
#define String_private__substring_thunk  builtin_s2a_sii_opti0_opti2147483647_thunk
#define String_private__substring_thunkc builtin_s2a_sii_opti0_opti2147483647_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_o_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_o_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_AS3_fromCharCode_thunk  builtin_s2a_o_rest_thunk
#define String_AS3_fromCharCode_thunkc builtin_s2a_o_rest_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE builtin_v2a_oa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE builtin_v2a_oa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define XMLList_AS3_setName_thunk  builtin_v2a_oa_thunk
#define XMLList_AS3_setName_thunkc builtin_v2a_oa_thunkc
#define __AS3___vec_Vector_object_private_type_set_thunk  builtin_v2a_oa_thunk
#define __AS3___vec_Vector_object_private_type_set_thunkc builtin_v2a_oa_thunkc
#define XMLList_AS3_setLocalName_thunk  builtin_v2a_oa_thunk
#define XMLList_AS3_setLocalName_thunkc builtin_v2a_oa_thunkc
#define XMLList_AS3_setNamespace_thunk  builtin_v2a_oa_thunk
#define XMLList_AS3_setNamespace_thunkc builtin_v2a_oa_thunkc
#define XML_AS3_setName_thunk  builtin_v2a_oa_thunk
#define XML_AS3_setName_thunkc builtin_v2a_oa_thunkc
#define XML_AS3_setNamespace_thunk  builtin_v2a_oa_thunk
#define XML_AS3_setNamespace_thunkc builtin_v2a_oa_thunkc
#define XML_AS3_setLocalName_thunk  builtin_v2a_oa_thunk
#define XML_AS3_setLocalName_thunkc builtin_v2a_oa_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_oa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_oa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Date_parse_thunk  builtin_d2d_oa_thunk
#define Date_parse_thunkc builtin_d2d_oa_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_n_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_n_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Namespace_uri_get_thunk  builtin_s2a_n_thunk
#define Namespace_uri_get_thunkc builtin_s2a_n_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_os_optsAvmThunkConstant_AvmString_5_____NaN_____thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_os_optsAvmThunkConstant_AvmString_5_____NaN_____thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define parseFloat_thunk  builtin_d2d_os_optsAvmThunkConstant_AvmString_5_____NaN_____thunk
#define parseFloat_thunkc builtin_d2d_os_optsAvmThunkConstant_AvmString_5_____NaN_____thunkc

extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oa_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oa_optakAvmThunkUndefined_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define XML_AS3_hasOwnProperty_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define XML_AS3_hasOwnProperty_thunkc builtin_b2a_oa_optakAvmThunkUndefined_thunkc
#define XMLList_AS3_propertyIsEnumerable_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define XMLList_AS3_propertyIsEnumerable_thunkc builtin_b2a_oa_optakAvmThunkUndefined_thunkc
#define XML_AS3_propertyIsEnumerable_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define XML_AS3_propertyIsEnumerable_thunkc builtin_b2a_oa_optakAvmThunkUndefined_thunkc
#define XMLList_AS3_hasOwnProperty_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define XMLList_AS3_hasOwnProperty_thunkc builtin_b2a_oa_optakAvmThunkUndefined_thunkc
#define isXMLName_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define isXMLName_thunkc builtin_b2a_oa_optakAvmThunkUndefined_thunkc

extern AvmThunkRetType_void AVMTHUNK_CALLTYPE builtin_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_void AVMTHUNK_CALLTYPE builtin_v2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define __AS3___vec_Vector_double_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_double_private__reverse_thunkc builtin_v2a_o_thunkc
#define __AS3___vec_Vector_uint_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_uint_private__reverse_thunkc builtin_v2a_o_thunkc
#define __AS3___vec_Vector_object_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_object_private__reverse_thunkc builtin_v2a_o_thunkc
#define __AS3___vec_Vector_int_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_int_private__reverse_thunkc builtin_v2a_o_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_oi_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_oi_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Date_private__get_thunk  builtin_d2d_oi_thunk
#define Date_private__get_thunkc builtin_d2d_oi_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oaa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oaa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define XML_AS3_insertChildAfter_thunk  builtin_a2a_oaa_thunk
#define XML_AS3_insertChildAfter_thunkc builtin_a2a_oaa_thunkc
#define XMLList_AS3_insertChildBefore_thunk  builtin_a2a_oaa_thunk
#define XMLList_AS3_insertChildBefore_thunkc builtin_a2a_oaa_thunkc
#define XMLList_AS3_insertChildAfter_thunk  builtin_a2a_oaa_thunk
#define XMLList_AS3_insertChildAfter_thunkc builtin_a2a_oaa_thunkc
#define XML_AS3_insertChildBefore_thunk  builtin_a2a_oaa_thunk
#define XML_AS3_insertChildBefore_thunkc builtin_a2a_oaa_thunkc
#define XMLList_AS3_replace_thunk  builtin_a2a_oaa_thunk
#define XMLList_AS3_replace_thunkc builtin_a2a_oaa_thunkc
#define XML_AS3_replace_thunk  builtin_a2a_oaa_thunk
#define XML_AS3_replace_thunkc builtin_a2a_oaa_thunkc

extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_o_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define RegExp_multiline_get_thunk  builtin_b2a_o_thunk
#define RegExp_multiline_get_thunkc builtin_b2a_o_thunkc
#define __AS3___vec_Vector_double_fixed_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_double_fixed_get_thunkc builtin_b2a_o_thunkc
#define RegExp_dotall_get_thunk  builtin_b2a_o_thunk
#define RegExp_dotall_get_thunkc builtin_b2a_o_thunkc
#define XMLList_AS3_hasComplexContent_thunk  builtin_b2a_o_thunk
#define XMLList_AS3_hasComplexContent_thunkc builtin_b2a_o_thunkc
#define XML_prettyPrinting_get_thunk  builtin_b2a_o_thunk
#define XML_prettyPrinting_get_thunkc builtin_b2a_o_thunkc
#define __AS3___vec_Vector_uint_fixed_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_uint_fixed_get_thunkc builtin_b2a_o_thunkc
#define XML_ignoreComments_get_thunk  builtin_b2a_o_thunk
#define XML_ignoreComments_get_thunkc builtin_b2a_o_thunkc
#define __AS3___vec_Vector_int_fixed_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_int_fixed_get_thunkc builtin_b2a_o_thunkc
#define RegExp_global_get_thunk  builtin_b2a_o_thunk
#define RegExp_global_get_thunkc builtin_b2a_o_thunkc
#define RegExp_ignoreCase_get_thunk  builtin_b2a_o_thunk
#define RegExp_ignoreCase_get_thunkc builtin_b2a_o_thunkc
#define __AS3___vec_Vector_object_fixed_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_object_fixed_get_thunkc builtin_b2a_o_thunkc
#define XML_AS3_hasSimpleContent_thunk  builtin_b2a_o_thunk
#define XML_AS3_hasSimpleContent_thunkc builtin_b2a_o_thunkc
#define XMLList_AS3_hasSimpleContent_thunk  builtin_b2a_o_thunk
#define XMLList_AS3_hasSimpleContent_thunkc builtin_b2a_o_thunkc
#define XML_ignoreWhitespace_get_thunk  builtin_b2a_o_thunk
#define XML_ignoreWhitespace_get_thunkc builtin_b2a_o_thunkc
#define RegExp_extended_get_thunk  builtin_b2a_o_thunk
#define RegExp_extended_get_thunkc builtin_b2a_o_thunkc
#define XML_AS3_hasComplexContent_thunk  builtin_b2a_o_thunk
#define XML_AS3_hasComplexContent_thunkc builtin_b2a_o_thunkc
#define XML_ignoreProcessingInstructions_get_thunk  builtin_b2a_o_thunk
#define XML_ignoreProcessingInstructions_get_thunkc builtin_b2a_o_thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_osa_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_osa_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_private__search_thunk  builtin_i2a_osa_thunk
#define String_private__search_thunkc builtin_i2a_osa_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oadd_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oadd_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Array_private__slice_thunk  builtin_a2a_oadd_thunk
#define Array_private__slice_thunkc builtin_a2a_oadd_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_os_optsAvmThunkConstant_AvmString_1__________thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_os_optsAvmThunkConstant_AvmString_1__________thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define RegExp_AS3_exec_thunk  builtin_a2a_os_optsAvmThunkConstant_AvmString_1__________thunk
#define RegExp_AS3_exec_thunkc builtin_a2a_os_optsAvmThunkConstant_AvmString_1__________thunkc

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_oaai_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_oaai_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Array_private__indexOf_thunk  builtin_i2a_oaai_thunk
#define Array_private__indexOf_thunkc builtin_i2a_oaai_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_odii_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_odii_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Number_private__convert_thunk  builtin_s2a_odii_thunk
#define Number_private__convert_thunkc builtin_s2a_odii_thunkc

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_odd_optdkAvmThunkInfinity_optdkAvmThunkInfinity_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_odd_optdkAvmThunkInfinity_optdkAvmThunkInfinity_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Math_min_thunk  builtin_d2d_odd_optdkAvmThunkInfinity_optdkAvmThunkInfinity_rest_thunk
#define Math_min_thunkc builtin_d2d_odd_optdkAvmThunkInfinity_optdkAvmThunkInfinity_rest_thunkc

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oao_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oao_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define __AS3___vec_Vector_uint_private__sort_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_uint_private__sort_thunkc builtin_a2a_oao_thunkc
#define __AS3___vec_Vector_object_private__sort_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_object_private__sort_thunkc builtin_a2a_oao_thunkc
#define Array_private__splice_thunk  builtin_a2a_oao_thunk
#define Array_private__splice_thunkc builtin_a2a_oao_thunkc
#define __AS3___vec_Vector_int_private__sort_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_int_private__sort_thunkc builtin_a2a_oao_thunkc
#define __AS3___vec_Vector_double_private__sort_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_double_private__sort_thunkc builtin_a2a_oao_thunkc
#define Array_private__concat_thunk  builtin_a2a_oao_thunk
#define Array_private__concat_thunkc builtin_a2a_oao_thunkc
#define Array_private__sort_thunk  builtin_a2a_oao_thunk
#define Array_private__sort_thunkc builtin_a2a_oao_thunkc

