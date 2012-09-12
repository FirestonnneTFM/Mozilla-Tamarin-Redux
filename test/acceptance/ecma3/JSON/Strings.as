/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "JSON";
var VERSION = "AS3";
var TITLE   = "JSON String tests for JSON.parse and JSON.stringify";

startTest();

AddTestCase("Unicode \\u00bb","\u00bb",JSON.parse('"\\u00bb"'));
AddTestCase("Unicode \\u00ab","\u00ab",JSON.parse('"\\u00ab"'));
AddTestCase("Unicode \\u00bf","\u00bf",JSON.parse('"\\u00bf"'));
AddTestCase("Unicode \\u00Ab","\u00Ab",JSON.parse('"\\u00Ab"'));
AddTestCase("Unicode \\u00bF","\u00bF",JSON.parse('"\\u00bF"'));
AddTestCase("JSON parse true",true,JSON.parse('true'));
AddTestCase("JSON parse false",false,JSON.parse('false'));
AddTestCase("JSON parse null",null,JSON.parse('null '));

AddTestCase("JSON parse 0",0,JSON.parse('0'));
AddTestCase("JSON parse 1",1,JSON.parse('1'));
AddTestCase("JSON parse 2",2,JSON.parse('2'));
AddTestCase("JSON parse 3",3,JSON.parse('3'));
AddTestCase("JSON parse 4",4,JSON.parse('4'));
AddTestCase("JSON parse 5",5,JSON.parse('5'));
AddTestCase("JSON parse 6",6,JSON.parse('6'));
AddTestCase("JSON parse 7",7,JSON.parse('7'));
AddTestCase("JSON parse 8",8,JSON.parse('8'));
AddTestCase("JSON parse 9",9,JSON.parse('9'));

AddTestCase("JSON.stringify('')",'""',JSON.stringify(''));
AddTestCase("JSON.stringify('\n\f\\u0061')",'"\\n\\f\\\\u0061"',JSON.stringify('\n\f\\u0061'));

/*
AddTestCase("JSON.stringify('mn\\u0001op\\u0002qr\\u0003st')",
            '"mn\\u0001op\\u0002qr\\u0003st"',
            JSON.stringify('mn\u0001op\u0002qr\u0003st'));
*/
test();
