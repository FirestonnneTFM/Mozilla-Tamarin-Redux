/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import GetSetProtectedExtended.*;

var SECTION = "FunctionAccessors";
var VERSION = "AS3";
var TITLE   = "Function Accessors";
var BUGNUMBER = "";

startTest();

OBJ = new GetSetProtectedExtended();

/*
 *
 * These will all need to be changed when
 * the protected attribute is implemented.
 *
 *
 */


AddTestCase("Protected getter, boolean", true, OBJ.getBoolean());
AddTestCase("Protected setter, boolean", false, OBJ.setBoolean(false));
AddTestCase("Protected getter, uint", 101, OBJ.getUint());
AddTestCase("Protected setter, uint", 5, OBJ.setUint(5));
AddTestCase("Protected getter, array", "1,2,3", OBJ.getArray().toString());
AddTestCase("Protected setter, array", "one,two,three", OBJ.setArray(["one","two","three"]).toString());
AddTestCase("Protected getter, string", "myString", OBJ.getString());
AddTestCase("Protected setter, string", "new string", OBJ.setString("new string"));
AddTestCase("Protected getter, no type", "no type", OBJ.getNoType());
AddTestCase("Protected setter, no type", 2012, OBJ.setNoType(2012));

test();

