/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 import GetSetAllowedNames.*;
 
 
 var SECTION = "FunctionAccessors";
 var VERSION = "AS3";
 var TITLE   = "Function Accessors";
 var BUGNUMBER = "";
 

startTest();


var TESTOBJ = new GetSetAllowedNames();

AddTestCase( "getter name _a1", "_a1", TESTOBJ._a1);
AddTestCase( "getter name _a1_", "_a1_", TESTOBJ._a1_);
AddTestCase( "getter name __a1__", "__a1__", TESTOBJ.__a1__);
AddTestCase( "getter name $a1", "$a1", TESTOBJ.$a1);
AddTestCase( "getter name a$1", "a$1", TESTOBJ.a$1);
AddTestCase( "getter name a1$", "a1$", TESTOBJ.a1$);
AddTestCase( "getter name A1", "A1", TESTOBJ.A1);
AddTestCase( "getter name cases", "cases", TESTOBJ.cases);
AddTestCase( "getter name Cases", "Cases", TESTOBJ.Cases);
AddTestCase( "getter name abcdefghijklmnopqrstuvwxyz0123456789$_", "all", TESTOBJ.abcdefghijklmnopqrstuvwxyz0123456789$_);
AddTestCase( "getter name get", "get", TESTOBJ.get);


AddTestCase( "setter name _a1", "new _a1", (TESTOBJ._a1 = "new _a1", TESTOBJ._a1));
AddTestCase( "setter name _a1_", "new _a1_", (TESTOBJ._a1_ = "new _a1_", TESTOBJ._a1_));
AddTestCase( "setter name __a1__", "new __a1__", (TESTOBJ.__a1__ = "new __a1__", TESTOBJ.__a1__));
AddTestCase( "setter name $a1", "new $a1", (TESTOBJ.$a1 = "new $a1", TESTOBJ.$a1));
AddTestCase( "setter name a$1", "new a$1", (TESTOBJ.a$1 = "new a$1", TESTOBJ.a$1));
AddTestCase( "setter name a1$", "new a1$", (TESTOBJ.a1$ = "new a1$", TESTOBJ.a1$));
AddTestCase( "setter name A1", "new A1", (TESTOBJ.A1 = "new A1", TESTOBJ.A1));
AddTestCase( "setter name cases", "new cases", (TESTOBJ.cases = "new cases", TESTOBJ.cases));
AddTestCase( "setter name Cases", "new Cases", (TESTOBJ.Cases = "new Cases", TESTOBJ.Cases));
AddTestCase( "setter name abcdefghijklmnopqrstuvwxyz0123456789$_", "new all", (TESTOBJ.abcdefghijklmnopqrstuvwxyz0123456789$_ = "new all", TESTOBJ.abcdefghijklmnopqrstuvwxyz0123456789$_));
AddTestCase( "setter name set", "new set", (TESTOBJ.set = "new set", TESTOBJ.set));

var f1 = function () {}
var f2 = function () { var i = 5; }
AddTestCase( "getter function keyword, different capitalization", "function Function() {}", TESTOBJ.FuncTion.toString());
AddTestCase( "setter function keyword, different capitalization", f2, (TESTOBJ.FuncTion = f2, TESTOBJ.FuncTion));

AddTestCase( "getter name same as constructor, different capitalization", "constructor, different case", TESTOBJ.getSetAllowedNames);
AddTestCase( "setter name same as constructor, different capitalization", "constructor, different case new", (TESTOBJ.getSetAllowedNames = "constructor, different case new", TESTOBJ.getSetAllowedNames));

AddTestCase( "getter class keyword, different capitalization", "class", TESTOBJ.Class);
AddTestCase( "setter class keyword, different capitalization", "class new", (TESTOBJ.Class = "class new", TESTOBJ.Class));

test();
