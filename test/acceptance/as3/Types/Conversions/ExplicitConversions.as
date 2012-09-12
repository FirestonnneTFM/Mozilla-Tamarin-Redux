/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Types: Conversions";
var VERSION = "as3";
var TITLE   = "type conversions";

startTest();

// "string"
AddTestCase("String('string')", "string", String("string"));
AddTestCase("String('')", "", String(""));
AddTestCase("Number('string')", NaN, Number("string"));
AddTestCase("Number('')", 0, Number(""));
AddTestCase("int('string')", 0, int("string"));
AddTestCase("int('')", 0, int(""));
AddTestCase("uint('string')", 0, uint("string"));
AddTestCase("uint('')", 0, uint(""));
AddTestCase("Boolean('string')", true, Boolean("string"));
AddTestCase("Boolean('')", false, Boolean(""));
AddTestCase("Object('string')", "string", Object("string"));
AddTestCase("Object('')", "", Object(""));

// null

AddTestCase( "String(null)", "null", String(null));
AddTestCase( "Number(null)", +0, Number(null));
AddTestCase( "int(null)", +0, int(null));
AddTestCase( "uint(null)", +0, uint(null));
AddTestCase( "Boolean(null)", false, Boolean(null));
AddTestCase( "Object(null)", "[object Object]", Object(null)+"");

// undefined
AddTestCase( "String(undefined)", "undefined", String(undefined));
AddTestCase( "Number(undefined)", NaN, Number(undefined));
AddTestCase( "int(undefined)", +0, int(undefined));
AddTestCase( "uint(undefined)", +0, uint(undefined));
AddTestCase( "Boolean(undefined)", false, Boolean(undefined));
AddTestCase( "Object(undefined)", "[object Object]", Object(undefined)+"");

// true
AddTestCase( "String(true)", "true", String(true));
AddTestCase( "Number(true)", 1, Number(true));
AddTestCase( "int(true)", 1, int(true));
AddTestCase( "uint(true)", 1, uint(true));
AddTestCase( "Boolean(true)", true, Boolean(true));
AddTestCase( "Object(true)", true, Object(true));

// false
AddTestCase( "String(false)", "false", String(false));
AddTestCase( "Number(false)", +0, Number(false));
AddTestCase( "int(false)", +0, int(false));
AddTestCase( "uint(false)", +0, uint(false));
AddTestCase( "Boolean(false)", false, Boolean(false));
AddTestCase( "Object(false)", false, Object(false));

// 1.23
AddTestCase( "String(1.23)", "1.23", String(1.23));
AddTestCase( "Number(1.23)", 1.23, Number(1.23));
AddTestCase( "int(1.23)", 1, int(1.23));
AddTestCase( "uint(1.23)", 1, uint(1.23));
AddTestCase( "Boolean(1.23)", true, Boolean(1.23));
AddTestCase( "Object(1.23)", 1.23, Object(1.23));

// -1.23
AddTestCase( "String(-1.23)", "-1.23", String(-1.23));
AddTestCase( "Number(-1.23)", -1.23, Number(-1.23));
AddTestCase( "int(-1.23)", -1, int(-1.23));
AddTestCase( "uint(-1.23)", 4294967295, uint(-1.23));
AddTestCase( "Boolean(-1.23)", true, Boolean(-1.23));
AddTestCase( "Object(-1.23)", -1.23, Object(-1.23));

// NaN
AddTestCase( "String(NaN)", "NaN", String(NaN));
AddTestCase( "Number(NaN)", NaN, Number(NaN));
AddTestCase( "int(NaN)", +0, int(NaN));
AddTestCase( "uint(NaN)", +0, uint(NaN));
AddTestCase( "Boolean(NaN)", false, Boolean(NaN));
AddTestCase( "Object(NaN)", NaN, Object(NaN));





test();
