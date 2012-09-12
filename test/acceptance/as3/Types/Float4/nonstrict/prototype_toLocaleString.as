/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "4.5.3";
var VERSION = "AS3";
var TITLE   = "float4.prototype.toLocaleString ( radix=10 ) : String";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var test_flt4:float4 = new float4(3.14131211f);
AddTestCase("float4.prototype.toLocaleString = function", true, float4.prototype.toLocaleString is Function );
AddTestCase("float4.prototype.toLocaleString returns a String", "String", getQualifiedClassName(test_flt4.public::toLocaleString()));

var orig_tostr = Object.prototype.toString;
Object.prototype.toLocaleString = float4.prototype.toLocaleString;
var test_obj:Object = {};
AddErrorTest("float4.prototype.toLocaleString() on Object throws TypeError ", TYPEERROR, function(){ test_obj.public::toLocaleString();});
// we test that it throws TypeError, not RangeError
AddErrorTest("float4.prototype.toLocaleString(357) on Object throws TypeError", TYPEERROR, function(){ test_obj.public::toLocaleString(357);});
Object.prototype.toLocaleString = orig_tostr;

var orig_tostr = Number.prototype.toLocaleString;
var test_num:Number = 3.14131211;
Number.prototype.toLocaleString = float4.prototype.toLocaleString;
/// there is no AS3::toLocaleString, this should always throw type error
AddErrorTest("float4.prototype.toLocaleString() non-generic= throws TypeError", TYPEERROR, function(){ test_num.public::toLocaleString();});
AddErrorTest("float4.prototype.toLocaleString(357) non-generic= throws TypeError", TYPEERROR, function(){ test_num.public::toLocaleString(357);});
Number.prototype.toLocaleString = orig_tostr;

AddTestCase("float4.prototype.toLocaleString = invokes AS3::toString", test_flt4.AS3::toString(), test_flt4.public::toLocaleString());
AddTestCase("float4.prototype.toLocaleString(25) = invokes AS3::toString(25)", test_flt4.AS3::toString(25), test_flt4.public::toLocaleString(25));

AddTestCase("float4.prototype.toLocaleString - DontEnum", "", getFloat4ProtoProp("toLocaleString"));
AddTestCase("float4.prototype.toLocaleString is not enumerable", false, float4.prototype.propertyIsEnumerable("toLocaleString"));

orig_tostr = float4.prototype.toLocaleString;
float4.prototype.toLocaleString = 1.1243174;
AddTestCase("float4.prototype.toLocaleString - Writable", true, orig_tostr != float4.prototype.toLocaleString);
float4.prototype.toLocaleString = orig_tostr;

AddTestCase("float4.prototype.toLocaleString - Deletable", true, delete(float4.prototype.toLocaleString));
// it should now find "Object" as toLocaleString, on the prototype chain
AddTestCase("float4.prototype.toLocaleString should now be Object.prototype.toLocaleString", Object.prototype.toLocaleString, float4.prototype.toLocaleString);
float4.prototype.toLocaleString = orig_tostr;

AddTestCase("float4.prototype.toLocaleString: implicit radix is 10", test_flt4.public::toLocaleString(10), test_flt4.public::toLocaleString());

test();

