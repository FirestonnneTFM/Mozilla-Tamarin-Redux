/* machine generated file -- do not edit */
#define AVMTHUNK_VERSION 3
const uint32_t builtin_abc_class_count = 34;
const uint32_t builtin_abc_script_count = 6;
const uint32_t builtin_abc_method_count = 846;
const uint32_t builtin_abc_length = 40256;
extern const uint8_t builtin_abc_data[40256];
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
const uint32_t isXMLName = 0;
const uint32_t unescape = 1;
const uint32_t escape = 2;
const uint32_t parseFloat = 3;
const uint32_t parseInt = 4;
const uint32_t isFinite = 5;
const uint32_t isNaN = 6;
const uint32_t encodeURIComponent = 7;
const uint32_t encodeURI = 8;
const uint32_t decodeURIComponent = 9;
const uint32_t decodeURI = 10;
const uint32_t Object_private__hasOwnProperty = 12;
const uint32_t Object_private__propertyIsEnumerable = 13;
const uint32_t Object_protected__setPropertyIsEnumerable = 14;
const uint32_t Object_private__isPrototypeOf = 15;
const uint32_t Object_private__toString = 16;
/* const uint32_t Object_protected__dontEnumPrototype = 17; */
/* const uint32_t Object_init = 24; */
/* const uint32_t Object_AS3_isPrototypeOf = 25; */
/* const uint32_t Object_AS3_hasOwnProperty = 26; */
/* const uint32_t Object_AS3_propertyIsEnumerable = 27; */
const uint32_t Class_prototype_get = 30;
/* const uint32_t Function_private_emptyCtor = 37; */
const uint32_t Function_prototype_get = 38;
const uint32_t Function_prototype_set = 39;
const uint32_t Function_length_get = 40;
const uint32_t Function_AS3_call = 41;
const uint32_t Function_AS3_apply = 42;
const uint32_t Namespace_prefix_get = 47;
const uint32_t Namespace_uri_get = 48;
/* const uint32_t Namespace_AS3_valueOf = 49; */
/* const uint32_t Namespace_AS3_toString = 50; */
/* const uint32_t Boolean_AS3_toString = 55; */
/* const uint32_t Boolean_AS3_valueOf = 56; */
const uint32_t Number_private__numberToString = 64;
const uint32_t Number_private__convert = 65;
/* const uint32_t Number_AS3_toString = 66; */
/* const uint32_t Number_AS3_valueOf = 67; */
/* const uint32_t Number_AS3_toExponential = 68; */
/* const uint32_t Number_AS3_toPrecision = 69; */
/* const uint32_t Number_AS3_toFixed = 70; */
/* const uint32_t int_AS3_toString = 78; */
/* const uint32_t int_AS3_valueOf = 79; */
/* const uint32_t int_AS3_toExponential = 80; */
/* const uint32_t int_AS3_toPrecision = 81; */
/* const uint32_t int_AS3_toFixed = 82; */
/* const uint32_t uint_AS3_toString = 90; */
/* const uint32_t uint_AS3_valueOf = 91; */
/* const uint32_t uint_AS3_toExponential = 92; */
/* const uint32_t uint_AS3_toPrecision = 93; */
/* const uint32_t uint_AS3_toFixed = 94; */
const uint32_t String_AS3_fromCharCode = 115;
const uint32_t String_private__match = 116;
const uint32_t String_private__replace = 117;
const uint32_t String_private__search = 118;
const uint32_t String_private__split = 119;
const uint32_t String_length_get = 120;
const uint32_t String_private__indexOf = 121;
const uint32_t String_AS3_indexOf = 122;
const uint32_t String_private__lastIndexOf = 123;
const uint32_t String_AS3_lastIndexOf = 124;
const uint32_t String_private__charAt = 125;
const uint32_t String_AS3_charAt = 126;
const uint32_t String_private__charCodeAt = 127;
const uint32_t String_AS3_charCodeAt = 128;
/* const uint32_t String_AS3_concat = 129; */
const uint32_t String_AS3_localeCompare = 130;
/* const uint32_t String_AS3_match = 131; */
/* const uint32_t String_AS3_replace = 132; */
/* const uint32_t String_AS3_search = 133; */
const uint32_t String_private__slice = 134;
const uint32_t String_AS3_slice = 135;
/* const uint32_t String_AS3_split = 136; */
const uint32_t String_private__substring = 137;
const uint32_t String_AS3_substring = 138;
const uint32_t String_private__substr = 139;
const uint32_t String_AS3_substr = 140;
const uint32_t String_AS3_toLowerCase = 141;
/* const uint32_t String_AS3_toLocaleLowerCase = 142; */
const uint32_t String_AS3_toUpperCase = 143;
/* const uint32_t String_AS3_toLocaleUpperCase = 144; */
/* const uint32_t String_AS3_toString = 145; */
/* const uint32_t String_AS3_valueOf = 146; */
/* const uint32_t Array_private__join = 169; */
const uint32_t Array_private__pop = 170;
const uint32_t Array_private__reverse = 171;
const uint32_t Array_private__concat = 172;
const uint32_t Array_private__shift = 173;
const uint32_t Array_private__slice = 174;
const uint32_t Array_private__splice = 175;
const uint32_t Array_private__sort = 176;
const uint32_t Array_private__sortOn = 177;
const uint32_t Array_private__indexOf = 178;
const uint32_t Array_private__lastIndexOf = 179;
const uint32_t Array_private__every = 180;
const uint32_t Array_private__filter = 181;
const uint32_t Array_private__forEach = 182;
const uint32_t Array_private__map = 183;
const uint32_t Array_private__some = 184;
const uint32_t Array_length_get = 185;
const uint32_t Array_length_set = 186;
/* const uint32_t Array_AS3_join = 188; */
const uint32_t Array_AS3_pop = 189;
const uint32_t Array_AS3_push = 190;
/* const uint32_t Array_AS3_reverse = 191; */
/* const uint32_t Array_AS3_concat = 192; */
/* const uint32_t Array_AS3_shift = 193; */
/* const uint32_t Array_AS3_slice = 194; */
const uint32_t Array_AS3_unshift = 195;
/* const uint32_t Array_AS3_splice = 196; */
/* const uint32_t Array_AS3_sort = 197; */
/* const uint32_t Array_AS3_sortOn = 198; */
/* const uint32_t Array_AS3_indexOf = 199; */
/* const uint32_t Array_AS3_lastIndexOf = 200; */
/* const uint32_t Array_AS3_every = 201; */
/* const uint32_t Array_AS3_filter = 202; */
/* const uint32_t Array_AS3_forEach = 203; */
/* const uint32_t Array_AS3_map = 204; */
/* const uint32_t Array_AS3_some = 205; */
/* const uint32_t __AS3___vec_Vector_object_private_castToThisType = 228; */
const uint32_t __AS3___vec_Vector_object_private__every = 229;
const uint32_t __AS3___vec_Vector_object_private__forEach = 230;
const uint32_t __AS3___vec_Vector_object_private__some = 231;
const uint32_t __AS3___vec_Vector_object_private__sort = 232;
const uint32_t __AS3___vec_Vector_object_private_type_set = 234;
const uint32_t __AS3___vec_Vector_object_private_type_get = 235;
/* const uint32_t __AS3___vec_Vector_object_private_newThisType = 236; */
const uint32_t __AS3___vec_Vector_object_length_get = 237;
const uint32_t __AS3___vec_Vector_object_length_set = 238;
const uint32_t __AS3___vec_Vector_object_fixed_set = 239;
const uint32_t __AS3___vec_Vector_object_fixed_get = 240;
/* const uint32_t __AS3___vec_Vector_object_AS3_toString = 241; */
/* const uint32_t __AS3___vec_Vector_object_AS3_toLocaleString = 242; */
/* const uint32_t __AS3___vec_Vector_object_AS3_join = 243; */
/* const uint32_t __AS3___vec_Vector_object_private__concat = 244; */
/* const uint32_t __AS3___vec_Vector_object_AS3_every = 245; */
/* const uint32_t __AS3___vec_Vector_object_AS3_forEach = 246; */
/* const uint32_t __AS3___vec_Vector_object_AS3_map = 247; */
const uint32_t __AS3___vec_Vector_object_AS3_push = 248;
const uint32_t __AS3___vec_Vector_object_private__reverse = 249;
/* const uint32_t __AS3___vec_Vector_object_AS3_some = 250; */
/* const uint32_t __AS3___vec_Vector_object_private__slice = 251; */
/* const uint32_t __AS3___vec_Vector_object_private__splice = 252; */
const uint32_t __AS3___vec_Vector_object_private__spliceHelper = 253;
/* const uint32_t __AS3___vec_Vector_object_private__shift = 254; */
const uint32_t __AS3___vec_Vector_object_AS3_unshift = 255;
const uint32_t __AS3___vec_Vector_object_private__filter = 256;
const uint32_t __AS3___vec_Vector_object_private__map = 257;
/* const uint32_t __AS3___vec_Vector_object_private_clamp = 258; */
/* const uint32_t __AS3___vec_Vector_object_AS3_concat = 259; */
/* const uint32_t __AS3___vec_Vector_object_AS3_filter = 260; */
const uint32_t __AS3___vec_Vector_object_AS3_pop = 261;
/* const uint32_t __AS3___vec_Vector_object_AS3_reverse = 262; */
/* const uint32_t __AS3___vec_Vector_object_AS3_shift = 263; */
/* const uint32_t __AS3___vec_Vector_object_AS3_slice = 264; */
/* const uint32_t __AS3___vec_Vector_object_AS3_sort = 265; */
/* const uint32_t __AS3___vec_Vector_object_AS3_splice = 266; */
/* const uint32_t __AS3___vec_Vector_object_AS3_indexOf = 267; */
/* const uint32_t __AS3___vec_Vector_object_AS3_lastIndexOf = 268; */
/* const uint32_t __AS3___vec_Vector_int_private_castToThisType = 289; */
/* const uint32_t __AS3___vec_Vector_int_private_newThisType = 290; */
const uint32_t __AS3___vec_Vector_int_private__every = 291;
const uint32_t __AS3___vec_Vector_int_private__forEach = 292;
const uint32_t __AS3___vec_Vector_int_private__some = 293;
const uint32_t __AS3___vec_Vector_int_private__sort = 294;
const uint32_t __AS3___vec_Vector_int_length_get = 296;
const uint32_t __AS3___vec_Vector_int_length_set = 297;
const uint32_t __AS3___vec_Vector_int_fixed_set = 298;
const uint32_t __AS3___vec_Vector_int_fixed_get = 299;
/* const uint32_t __AS3___vec_Vector_int_AS3_toString = 300; */
/* const uint32_t __AS3___vec_Vector_int_AS3_toLocaleString = 301; */
/* const uint32_t __AS3___vec_Vector_int_AS3_join = 302; */
/* const uint32_t __AS3___vec_Vector_int_private__concat = 303; */
/* const uint32_t __AS3___vec_Vector_int_AS3_every = 304; */
/* const uint32_t __AS3___vec_Vector_int_AS3_forEach = 305; */
/* const uint32_t __AS3___vec_Vector_int_AS3_map = 306; */
const uint32_t __AS3___vec_Vector_int_AS3_push = 307;
const uint32_t __AS3___vec_Vector_int_private__reverse = 308;
/* const uint32_t __AS3___vec_Vector_int_AS3_some = 309; */
/* const uint32_t __AS3___vec_Vector_int_private__slice = 310; */
/* const uint32_t __AS3___vec_Vector_int_private__splice = 311; */
const uint32_t __AS3___vec_Vector_int_private__spliceHelper = 312;
/* const uint32_t __AS3___vec_Vector_int_private__shift = 313; */
const uint32_t __AS3___vec_Vector_int_AS3_unshift = 314;
const uint32_t __AS3___vec_Vector_int_private__filter = 315;
const uint32_t __AS3___vec_Vector_int_private__map = 316;
/* const uint32_t __AS3___vec_Vector_int_private_clamp = 317; */
/* const uint32_t __AS3___vec_Vector_int_AS3_concat = 318; */
/* const uint32_t __AS3___vec_Vector_int_AS3_filter = 319; */
const uint32_t __AS3___vec_Vector_int_AS3_pop = 320;
/* const uint32_t __AS3___vec_Vector_int_AS3_reverse = 321; */
/* const uint32_t __AS3___vec_Vector_int_AS3_shift = 322; */
/* const uint32_t __AS3___vec_Vector_int_AS3_slice = 323; */
/* const uint32_t __AS3___vec_Vector_int_AS3_sort = 324; */
/* const uint32_t __AS3___vec_Vector_int_AS3_splice = 325; */
/* const uint32_t __AS3___vec_Vector_int_AS3_indexOf = 326; */
/* const uint32_t __AS3___vec_Vector_int_AS3_lastIndexOf = 327; */
/* const uint32_t __AS3___vec_Vector_uint_private_castToThisType = 348; */
/* const uint32_t __AS3___vec_Vector_uint_private_newThisType = 349; */
const uint32_t __AS3___vec_Vector_uint_private__every = 350;
const uint32_t __AS3___vec_Vector_uint_private__forEach = 351;
const uint32_t __AS3___vec_Vector_uint_private__some = 352;
const uint32_t __AS3___vec_Vector_uint_private__sort = 353;
const uint32_t __AS3___vec_Vector_uint_length_get = 355;
const uint32_t __AS3___vec_Vector_uint_length_set = 356;
const uint32_t __AS3___vec_Vector_uint_fixed_set = 357;
const uint32_t __AS3___vec_Vector_uint_fixed_get = 358;
/* const uint32_t __AS3___vec_Vector_uint_AS3_toString = 359; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_toLocaleString = 360; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_join = 361; */
/* const uint32_t __AS3___vec_Vector_uint_private__concat = 362; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_every = 363; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_forEach = 364; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_map = 365; */
const uint32_t __AS3___vec_Vector_uint_AS3_push = 366;
const uint32_t __AS3___vec_Vector_uint_private__reverse = 367;
/* const uint32_t __AS3___vec_Vector_uint_AS3_some = 368; */
/* const uint32_t __AS3___vec_Vector_uint_private__slice = 369; */
/* const uint32_t __AS3___vec_Vector_uint_private__splice = 370; */
const uint32_t __AS3___vec_Vector_uint_private__spliceHelper = 371;
/* const uint32_t __AS3___vec_Vector_uint_private__shift = 372; */
const uint32_t __AS3___vec_Vector_uint_AS3_unshift = 373;
const uint32_t __AS3___vec_Vector_uint_private__filter = 374;
const uint32_t __AS3___vec_Vector_uint_private__map = 375;
/* const uint32_t __AS3___vec_Vector_uint_private_clamp = 376; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_concat = 377; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_filter = 378; */
const uint32_t __AS3___vec_Vector_uint_AS3_pop = 379;
/* const uint32_t __AS3___vec_Vector_uint_AS3_reverse = 380; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_shift = 381; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_slice = 382; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_sort = 383; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_splice = 384; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_indexOf = 385; */
/* const uint32_t __AS3___vec_Vector_uint_AS3_lastIndexOf = 386; */
/* const uint32_t __AS3___vec_Vector_double_private_castToThisType = 407; */
/* const uint32_t __AS3___vec_Vector_double_private_newThisType = 408; */
const uint32_t __AS3___vec_Vector_double_private__every = 409;
const uint32_t __AS3___vec_Vector_double_private__forEach = 410;
const uint32_t __AS3___vec_Vector_double_private__some = 411;
const uint32_t __AS3___vec_Vector_double_private__sort = 412;
const uint32_t __AS3___vec_Vector_double_length_get = 414;
const uint32_t __AS3___vec_Vector_double_length_set = 415;
const uint32_t __AS3___vec_Vector_double_fixed_set = 416;
const uint32_t __AS3___vec_Vector_double_fixed_get = 417;
/* const uint32_t __AS3___vec_Vector_double_AS3_toString = 418; */
/* const uint32_t __AS3___vec_Vector_double_AS3_toLocaleString = 419; */
/* const uint32_t __AS3___vec_Vector_double_AS3_join = 420; */
/* const uint32_t __AS3___vec_Vector_double_private__concat = 421; */
/* const uint32_t __AS3___vec_Vector_double_AS3_every = 422; */
/* const uint32_t __AS3___vec_Vector_double_AS3_forEach = 423; */
/* const uint32_t __AS3___vec_Vector_double_AS3_map = 424; */
const uint32_t __AS3___vec_Vector_double_AS3_push = 425;
const uint32_t __AS3___vec_Vector_double_private__reverse = 426;
/* const uint32_t __AS3___vec_Vector_double_AS3_some = 427; */
/* const uint32_t __AS3___vec_Vector_double_private__slice = 428; */
/* const uint32_t __AS3___vec_Vector_double_private__splice = 429; */
const uint32_t __AS3___vec_Vector_double_private__spliceHelper = 430;
/* const uint32_t __AS3___vec_Vector_double_private__shift = 431; */
const uint32_t __AS3___vec_Vector_double_AS3_unshift = 432;
const uint32_t __AS3___vec_Vector_double_private__filter = 433;
const uint32_t __AS3___vec_Vector_double_private__map = 434;
/* const uint32_t __AS3___vec_Vector_double_private_clamp = 435; */
/* const uint32_t __AS3___vec_Vector_double_AS3_concat = 436; */
/* const uint32_t __AS3___vec_Vector_double_AS3_filter = 437; */
const uint32_t __AS3___vec_Vector_double_AS3_pop = 438;
/* const uint32_t __AS3___vec_Vector_double_AS3_reverse = 439; */
/* const uint32_t __AS3___vec_Vector_double_AS3_shift = 440; */
/* const uint32_t __AS3___vec_Vector_double_AS3_slice = 441; */
/* const uint32_t __AS3___vec_Vector_double_AS3_sort = 442; */
/* const uint32_t __AS3___vec_Vector_double_AS3_splice = 443; */
/* const uint32_t __AS3___vec_Vector_double_AS3_indexOf = 444; */
/* const uint32_t __AS3___vec_Vector_double_AS3_lastIndexOf = 445; */
/* const uint32_t private_MethodClosure_prototype = 447; */
/* const uint32_t private_MethodClosure_prototype = 448; */
const uint32_t private_MethodClosure_length_get = 449;
const uint32_t private_MethodClosure_private_savedThis_get = 450;
const uint32_t Math_private__min = 454;
const uint32_t Math_private__max = 455;
const uint32_t Math_abs = 456;
const uint32_t Math_acos = 457;
const uint32_t Math_asin = 458;
const uint32_t Math_atan = 459;
const uint32_t Math_ceil = 460;
const uint32_t Math_cos = 461;
const uint32_t Math_exp = 462;
const uint32_t Math_floor = 463;
const uint32_t Math_log = 464;
const uint32_t Math_round = 465;
const uint32_t Math_sin = 466;
const uint32_t Math_sqrt = 467;
const uint32_t Math_tan = 468;
const uint32_t Math_atan2 = 469;
const uint32_t Math_pow = 470;
const uint32_t Math_max = 471;
const uint32_t Math_min = 472;
const uint32_t Math_random = 473;
const uint32_t Error_getErrorMessage = 478;
/* const uint32_t Error_throwError = 480; */
const uint32_t Error_getStackTrace = 482;
/* const uint32_t Error_errorID = 483; */
const uint32_t Date_parse = 549;
const uint32_t Date_UTC = 550;
const uint32_t Date_AS3_valueOf = 551;
const uint32_t Date_private__toString = 552;
const uint32_t Date_private__setTime = 553;
const uint32_t Date_private__get = 554;
/* const uint32_t Date_AS3_setTime = 555; */
/* const uint32_t Date_AS3_toString = 556; */
/* const uint32_t Date_AS3_toDateString = 557; */
/* const uint32_t Date_AS3_toTimeString = 558; */
/* const uint32_t Date_AS3_toLocaleString = 559; */
/* const uint32_t Date_AS3_toLocaleDateString = 560; */
/* const uint32_t Date_AS3_toLocaleTimeString = 561; */
/* const uint32_t Date_AS3_toUTCString = 562; */
const uint32_t Date_AS3_getUTCFullYear = 563;
const uint32_t Date_AS3_getUTCMonth = 564;
const uint32_t Date_AS3_getUTCDate = 565;
const uint32_t Date_AS3_getUTCDay = 566;
const uint32_t Date_AS3_getUTCHours = 567;
const uint32_t Date_AS3_getUTCMinutes = 568;
const uint32_t Date_AS3_getUTCSeconds = 569;
const uint32_t Date_AS3_getUTCMilliseconds = 570;
const uint32_t Date_AS3_getFullYear = 571;
const uint32_t Date_AS3_getMonth = 572;
const uint32_t Date_AS3_getDate = 573;
const uint32_t Date_AS3_getDay = 574;
const uint32_t Date_AS3_getHours = 575;
const uint32_t Date_AS3_getMinutes = 576;
const uint32_t Date_AS3_getSeconds = 577;
const uint32_t Date_AS3_getMilliseconds = 578;
const uint32_t Date_AS3_getTimezoneOffset = 579;
const uint32_t Date_AS3_getTime = 580;
const uint32_t Date_private__setFullYear = 581;
const uint32_t Date_private__setMonth = 582;
const uint32_t Date_private__setDate = 583;
const uint32_t Date_private__setHours = 584;
const uint32_t Date_private__setMinutes = 585;
const uint32_t Date_private__setSeconds = 586;
const uint32_t Date_private__setMilliseconds = 587;
const uint32_t Date_private__setUTCFullYear = 588;
const uint32_t Date_private__setUTCMonth = 589;
const uint32_t Date_private__setUTCDate = 590;
const uint32_t Date_private__setUTCHours = 591;
const uint32_t Date_private__setUTCMinutes = 592;
const uint32_t Date_private__setUTCSeconds = 593;
const uint32_t Date_private__setUTCMilliseconds = 594;
/* const uint32_t Date_AS3_setFullYear = 595; */
/* const uint32_t Date_AS3_setMonth = 596; */
/* const uint32_t Date_AS3_setDate = 597; */
/* const uint32_t Date_AS3_setHours = 598; */
/* const uint32_t Date_AS3_setMinutes = 599; */
/* const uint32_t Date_AS3_setSeconds = 600; */
/* const uint32_t Date_AS3_setMilliseconds = 601; */
/* const uint32_t Date_AS3_setUTCFullYear = 602; */
/* const uint32_t Date_AS3_setUTCMonth = 603; */
/* const uint32_t Date_AS3_setUTCDate = 604; */
/* const uint32_t Date_AS3_setUTCHours = 605; */
/* const uint32_t Date_AS3_setUTCMinutes = 606; */
/* const uint32_t Date_AS3_setUTCSeconds = 607; */
/* const uint32_t Date_AS3_setUTCMilliseconds = 608; */
/* const uint32_t Date_fullYear = 609; */
/* const uint32_t Date_fullYear = 610; */
/* const uint32_t Date_month = 611; */
/* const uint32_t Date_month = 612; */
/* const uint32_t Date_date = 613; */
/* const uint32_t Date_date = 614; */
/* const uint32_t Date_hours = 615; */
/* const uint32_t Date_hours = 616; */
/* const uint32_t Date_minutes = 617; */
/* const uint32_t Date_minutes = 618; */
/* const uint32_t Date_seconds = 619; */
/* const uint32_t Date_seconds = 620; */
/* const uint32_t Date_milliseconds = 621; */
/* const uint32_t Date_milliseconds = 622; */
/* const uint32_t Date_fullYearUTC = 623; */
/* const uint32_t Date_fullYearUTC = 624; */
/* const uint32_t Date_monthUTC = 625; */
/* const uint32_t Date_monthUTC = 626; */
/* const uint32_t Date_dateUTC = 627; */
/* const uint32_t Date_dateUTC = 628; */
/* const uint32_t Date_hoursUTC = 629; */
/* const uint32_t Date_hoursUTC = 630; */
/* const uint32_t Date_minutesUTC = 631; */
/* const uint32_t Date_minutesUTC = 632; */
/* const uint32_t Date_secondsUTC = 633; */
/* const uint32_t Date_secondsUTC = 634; */
/* const uint32_t Date_millisecondsUTC = 635; */
/* const uint32_t Date_millisecondsUTC = 636; */
/* const uint32_t Date_time = 637; */
/* const uint32_t Date_time = 638; */
/* const uint32_t Date_timezoneOffset = 639; */
/* const uint32_t Date_day = 640; */
/* const uint32_t Date_dayUTC = 641; */
const uint32_t RegExp_source_get = 648;
const uint32_t RegExp_global_get = 649;
const uint32_t RegExp_ignoreCase_get = 650;
const uint32_t RegExp_multiline_get = 651;
const uint32_t RegExp_lastIndex_get = 652;
const uint32_t RegExp_lastIndex_set = 653;
const uint32_t RegExp_dotall_get = 654;
const uint32_t RegExp_extended_get = 655;
const uint32_t RegExp_AS3_exec = 656;
/* const uint32_t RegExp_AS3_test = 657; */
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
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_os_optsAvmThunkConstant_AvmString_6_____NaN_____thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_os_optsAvmThunkConstant_AvmString_6_____NaN_____thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define parseFloat_thunk  builtin_d2d_os_optsAvmThunkConstant_AvmString_6_____NaN_____thunk
#define parseFloat_thunkc builtin_d2d_os_optsAvmThunkConstant_AvmString_6_____NaN_____thunkc

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

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssi_opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssi_opti2147483647_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_private__lastIndexOf_thunk  builtin_i2a_ssi_opti2147483647_thunk
#define String_private__lastIndexOf_thunkc builtin_i2a_ssi_opti2147483647_thunkc

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
#define Number_private__numberToString_thunk  builtin_s2a_odi_thunk
#define Number_private__numberToString_thunkc builtin_s2a_odi_thunkc

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

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_n_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_n_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Namespace_uri_get_thunk  builtin_s2a_n_thunk
#define Namespace_uri_get_thunkc builtin_s2a_n_thunkc

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

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssd_optsAvmThunkConstant_AvmString_4_____undefined_____opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssd_optsAvmThunkConstant_AvmString_4_____undefined_____opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_AS3_indexOf_thunk  builtin_i2a_ssd_optsAvmThunkConstant_AvmString_4_____undefined_____opti0_thunk
#define String_AS3_indexOf_thunkc builtin_i2a_ssd_optsAvmThunkConstant_AvmString_4_____undefined_____opti0_thunkc

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

extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oa_optakAvmThunkUndefined_rest_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBox AVMTHUNK_CALLTYPE builtin_a2a_oa_optakAvmThunkUndefined_rest_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Function_AS3_call_thunk  builtin_a2a_oa_optakAvmThunkUndefined_rest_thunk
#define Function_AS3_call_thunkc builtin_a2a_oa_optakAvmThunkUndefined_rest_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_si_opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_si_opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_private__charAt_thunk  builtin_s2a_si_opti0_thunk
#define String_private__charAt_thunkc builtin_s2a_si_opti0_thunkc

extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oas_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oas_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define Object_private__hasOwnProperty_thunk  builtin_b2a_oas_thunk
#define Object_private__hasOwnProperty_thunkc builtin_b2a_oas_thunkc
#define Object_private__propertyIsEnumerable_thunk  builtin_b2a_oas_thunk
#define Object_private__propertyIsEnumerable_thunkc builtin_b2a_oas_thunkc

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

extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_od_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_od_optakAvmThunkUndefined_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define isNaN_thunk  builtin_b2a_od_optakAvmThunkUndefined_thunk
#define isNaN_thunkc builtin_b2a_od_optakAvmThunkUndefined_thunkc
#define isFinite_thunk  builtin_b2a_od_optakAvmThunkUndefined_thunk
#define isFinite_thunkc builtin_b2a_od_optakAvmThunkUndefined_thunkc

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

extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_osi_optsAvmThunkConstant_AvmString_6_____NaN_____opti0_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_double AVMTHUNK_CALLTYPE builtin_d2d_osi_optsAvmThunkConstant_AvmString_6_____NaN_____opti0_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define parseInt_thunk  builtin_d2d_osi_optsAvmThunkConstant_AvmString_6_____NaN_____opti0_thunk
#define parseInt_thunkc builtin_d2d_osi_optsAvmThunkConstant_AvmString_6_____NaN_____opti0_thunkc

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

extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oa_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmBoolArg AVMTHUNK_CALLTYPE builtin_b2a_oa_optakAvmThunkUndefined_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define XMLList_AS3_propertyIsEnumerable_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define XMLList_AS3_propertyIsEnumerable_thunkc builtin_b2a_oa_optakAvmThunkUndefined_thunkc
#define XML_AS3_propertyIsEnumerable_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define XML_AS3_propertyIsEnumerable_thunkc builtin_b2a_oa_optakAvmThunkUndefined_thunkc
#define isXMLName_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define isXMLName_thunkc builtin_b2a_oa_optakAvmThunkUndefined_thunkc
#define XMLList_AS3_hasOwnProperty_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define XMLList_AS3_hasOwnProperty_thunkc builtin_b2a_oa_optakAvmThunkUndefined_thunkc
#define XML_AS3_hasOwnProperty_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define XML_AS3_hasOwnProperty_thunkc builtin_b2a_oa_optakAvmThunkUndefined_thunkc

extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_AvmString AVMTHUNK_CALLTYPE builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define unescape_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunk
#define unescape_thunkc builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunkc
#define decodeURI_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunk
#define decodeURI_thunkc builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunkc
#define decodeURIComponent_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunk
#define decodeURIComponent_thunkc builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunkc
#define escape_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunk
#define escape_thunkc builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunkc
#define encodeURIComponent_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunk
#define encodeURIComponent_thunkc builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunkc
#define encodeURI_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunk
#define encodeURI_thunkc builtin_s2a_os_optsAvmThunkConstant_AvmString_4_____undefined_____thunkc

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

extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssd_optsAvmThunkConstant_AvmString_4_____undefined_____opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
extern AvmThunkRetType_int32_t AVMTHUNK_CALLTYPE builtin_i2a_ssd_optsAvmThunkConstant_AvmString_4_____undefined_____opti2147483647_thunkc(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
#define String_AS3_lastIndexOf_thunk  builtin_i2a_ssd_optsAvmThunkConstant_AvmString_4_____undefined_____opti2147483647_thunk
#define String_AS3_lastIndexOf_thunkc builtin_i2a_ssd_optsAvmThunkConstant_AvmString_4_____undefined_____opti2147483647_thunkc

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

