/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import GetSetStaticPackage.*;
import GetSetStaticSameName.*;

var SECTION = "FunctionAccessors";
var VERSION = "AS3";
var TITLE   = "Function Accessors";
var BUGNUMBER = "";

startTest();

AddTestCase("Static getter var:int", -10, GetSetStatic.y);
AddTestCase("Static setter var:int", 23334, (GetSetStatic.y = 23334, GetSetStatic.y));
AddTestCase("Static getter var:Array", "1,2,3", GetSetStatic.x.toString());
AddTestCase("Static setter var:Array", "4,5,6", (GetSetStatic.x = new Array(4,5,6), GetSetStatic.x.toString()));
AddTestCase("Static getter var:Boolean", true, GetSetStatic.boolean);
AddTestCase("Static setter var:Boolean", false, (GetSetStatic.boolean = false, GetSetStatic.boolean));
AddTestCase("Static getter var:uint", 1, GetSetStatic.u);
AddTestCase("Static setter var:uint", 42, (GetSetStatic.u = 42, GetSetStatic.u));
AddTestCase("Static getter var:String", "myString", GetSetStatic.string);
AddTestCase("Static setter var:String", "new string", (GetSetStatic.string = "new string", GetSetStatic.string));

// Attempt to access the private vars directly
// New instances of vars will be created since the private vars are not accessible
try{
    var res = "not run";
    AddTestCase("Access private var:Array", 4, GetSetStatic._x = 4);
    res = "no exception";
} catch (e1) {
    res = "exception";
} finally {
    AddTestCase("Access private var:Array", "no exception", res);
}

try{
    var res = "not run";
    AddTestCase("Access private var:int", 4, GetSetStatic._y = 4);
    res = "no exception";
} catch (e2) {
    res = "exception";
} finally {
    AddTestCase("Access private var:int", "no exception", res);
}

try{
    var res = "not run";
    AddTestCase("Access private var:Boolean", 4, GetSetStatic._b = 4);
    res = "no exception";
} catch (e3) {
    res = "exception";
} finally {
    AddTestCase("Access private var:Boolean", "no exception", res);
}

try{
    var res = "not run";
    AddTestCase("Access private var:uint", 4, GetSetStatic._u = 4);
    res = "no exception";
} catch (e4) {
    res = "exception";
} finally {
    AddTestCase("Access private var:uint", "no exception", res);
}

try{
    var res = "not run";
    AddTestCase("Access private var:String", 4, GetSetStatic._s = 4);
    res = "no exception";
} catch (e5) {
    res = "exception";
} finally {
    AddTestCase("Access private var:String", "no exception", res);
}

// call setter from setter
GetSetStatic.sfs2 = 55;
AddTestCase("Call setter from setter", 55, GetSetStatic.sfs1);
AddTestCase("Call setter from setter", 55, GetSetStatic.sfs2);

// call setter from getter
AddTestCase("Call setter from getter", 0, GetSetStatic.sfg2);
AddTestCase("Call setter from getter", "PASSED", GetSetStatic.sfg1);

// call getter from setter
GetSetStatic.gfs1 = "FAILED";// setter for gfs1 should make the string 'PASSED'
AddTestCase("Call getter from setter", "PASSED", GetSetStatic.gfs1);
AddTestCase("Call getter from setter", "PASSED", GetSetStatic.gfs2);

// call getter from getter

AddTestCase("Call getter from getter", "PASSED", GetSetStatic.gfg1);
AddTestCase("Call getter from getter", "PASSED", GetSetStatic.gfg2);

// Try to access a getter in a class that's the same name as the package it's in
// See bug 133422; test case needs to be updated when/if bug is fixed
try{
    var res = "not run";
    trace(GetSetStaticSameName.y);
    res = "no exception";
} catch (e6) {
    res = "exception";
} finally {
    AddTestCase("Access getter in class in package of same name", "exception", res);
}

// Attempt to access non-static var
// See bug 117661; test case needs to be updated when/if bug is fixed
try{
    var res = "not run";
    var someVar = GetSetStatic.n;
    res = "no exception";
} catch (e7) {
    res = "exception";
} finally {
    AddTestCase("Get non-static var:Number", "exception", res);
}

// Set non-static var
// See bug 133468; test case needs to be updated when/if bug is fixed
try{
    var res = "not run";
    GetSetStatic.n = 5.55;
    res = GetSetStatic.n;
} catch (e8) {
    res = "exception";
} finally {
    AddTestCase("Set non-static var:Number", 5.55, res);
}

test();

