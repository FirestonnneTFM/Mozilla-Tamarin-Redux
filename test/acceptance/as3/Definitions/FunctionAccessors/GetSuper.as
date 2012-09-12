/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 var SECTION = "FunctionAccessors";
 var VERSION = "AS3";
 var TITLE   = "Function Accessors";
 var BUGNUMBER = "106381";
 
startTest();

class A
{
var _v:Number = 0;

function get v():Number
{
return _v;
}

function set v(value:Number)
{
_v = value;
}
}

class B extends A
{
override function get v():Number
{

return super.v + 1; // this caused infinite recursion per bug 106381
}
}

var b:B = new B();
try{
    var res = "not run";
    b.v; // should cause infinite recursion
    res = "no exception";
} catch (e) {
    res = "exception";
} finally {
    AddTestCase("Getter calling super", "no exception", res);
}

try{
    var res = "not run";
    b.v = 1;
    res = "no exception";
    AddTestCase("Setting value whose getter calls super", 2, b.v);
} catch (e) {
    res = "exception";
} finally {
    AddTestCase("Infinite recursion getter calling super", "no exception", res);
}

test();
