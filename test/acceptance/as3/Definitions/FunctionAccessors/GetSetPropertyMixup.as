/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 import GetSetPropertyMixup.*;
 
 
 var SECTION = "FunctionAccessors";
 var VERSION = "AS3";
 var TITLE   = "Function Accessors";
 var BUGNUMBER = "";
 

startTest();


w = new GetSetPropertyMixup();


AddTestCase("Get foo which gets _loo", "loo", w.foo);
w.foo = "foo new";

AddTestCase("Set foo which sets foo, check _foo for real" , "foo new", w.fooForReal);
AddTestCase("Set foo which sets foo, check _loo" , "loo", w.loo);

AddTestCase("Get poo", "poo", w.poo);

w.poo = "poo new";
AddTestCase("Set poo which sets _boo, check _boo", "poo new", w.boo);
AddTestCase("Set poo which sets _boo, check _poo", "poo", w.poo);

test();
