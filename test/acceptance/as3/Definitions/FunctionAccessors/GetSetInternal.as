/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import GetSetInternal.*;

var SECTION = "FunctionAccessors";
var VERSION = "AS3";
var TITLE   = "Function Accessors";
var BUGNUMBER = "";

startTest();

OBJ = new GetSetInternal();

AddTestCase("Internal getter, boolean", true, OBJ.getBoolean());
AddTestCase("Internal setter, boolean", false, OBJ.setBoolean(false));
AddTestCase("Internal getter, uint", 101, OBJ.getUint());
AddTestCase("Internal setter, uint", 5, OBJ.setUint(5));
AddTestCase("Internal getter, array", "1,2,3", OBJ.getArray().toString());
AddTestCase("Internal setter, array", "one,two,three", OBJ.setArray(["one","two","three"]).toString());
AddTestCase("Internal getter, string", "myString", OBJ.getString());
AddTestCase("Internal setter, string", "new string", OBJ.setString("new string"));
AddTestCase("Internal getter, no type", "no type", OBJ.getNoType());
AddTestCase("Internal setter, no type", 2012, OBJ.setNoType(2012));

try {
    internObj = new GetSetInternalInternal();
    res = "no exception";
} catch (e1) {
    res = "exception";
}
AddTestCase("Try to instantiate internal class from outside package", "exception", res);



test();

