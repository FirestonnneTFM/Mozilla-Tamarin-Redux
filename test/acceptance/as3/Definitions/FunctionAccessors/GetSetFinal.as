/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import GetSetFinal.*;

var SECTION = "FunctionAccessors";
var VERSION = "AS3";
var TITLE   = "Function Accessors";
var BUGNUMBER = "";

startTest();

OBJ = new GetSetFinal();

AddTestCase("Final class getter var:int", -10, OBJ.y);
AddTestCase("Final class setter var:int", 23334, (OBJ.y = 23334, OBJ.y));
AddTestCase("Final class getter var:Array", "1,2,3", OBJ.x.toString());
AddTestCase("Final class setter var:Array", "4,5,6", (OBJ.x = new Array(4,5,6), OBJ.x.toString()));
AddTestCase("Final class getter var:Boolean", true, OBJ.boolean);
AddTestCase("Final class setter var:Boolean", false, (OBJ.boolean = false, OBJ.boolean));
AddTestCase("Final class getter var:uint", 1, OBJ.u);
AddTestCase("Final class setter var:uint", 42, (OBJ.u = 42, OBJ.u));
AddTestCase("Final class getter var:String", "myString", OBJ.string);
AddTestCase("Final class setter var:String", "new string", (OBJ.string = "new string", OBJ.string));

// Attempt to access the private vars directly
try{
    var res = "not run";
    OBJ._x = 4;
    res = "no exception";
} catch (e1) {
    res = "exception";
} finally {
    AddTestCase("Access private var:Array", "exception", res);
}

try{
    var res = "not run";
    OBJ._y = 4;
    res = "no exception";
} catch (e2) {
    res = "exception";
} finally {
    AddTestCase("Access private var:int", "exception", res);
}

try{
    var res = "not run";
    OBJ._b = 4;
    res = "no exception";
} catch (e3) {
    res = "exception";
} finally {
    AddTestCase("Access private var:Boolean", "exception", res);
}

try{
    var res = "not run";
    OBJ._u = 4;
    res = "no exception";
} catch (e4) {
    res = "exception";
} finally {
    AddTestCase("Access private var:uint", "exception", res);
}

try{
    var res = "not run";
    OBJ._s = 4;
    res = "no exception";
} catch (e5) {
    res = "exception";
} finally {
    AddTestCase("Access private var:String", "exception", res);
}

// call setter from setter
OBJ.sfs2 = 55;
AddTestCase("Call setter from setter", 55, OBJ.sfs1);
AddTestCase("Call setter from setter", 55, OBJ.sfs2);

// call setter from getter
AddTestCase("Call setter from getter", 0, OBJ.sfg2);
AddTestCase("Call setter from getter", "PASSED", OBJ.sfg1);

// call getter from setter
OBJ.gfs1 = "FAILED";// setter for gfs1 should make the string 'PASSED'
AddTestCase("Call getter from setter", "PASSED", OBJ.gfs1);
AddTestCase("Call getter from setter", "PASSED", OBJ.gfs2);

// call getter from getter

AddTestCase("Call getter from getter", "PASSED", OBJ.gfg1);
AddTestCase("Call getter from getter", "PASSED", OBJ.gfg2);


test();

