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
 * Portions created by the Initial Developer are Copyright (C) 2011
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
