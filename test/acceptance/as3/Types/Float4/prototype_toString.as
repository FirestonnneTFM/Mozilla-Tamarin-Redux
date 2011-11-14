/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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
include "floatUtil.as";


var SECTION = "4.5.2";
var VERSION = "AS3";
var TITLE   = "float4.prototype.toString ( radix=10 ) : String";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var test_flt4:float4 = new float4(3.14131211f);
AddTestCase("float4.prototype.toString = function", true, float4.prototype.toString is Function );
AddTestCase("float4.prototype.toString returns a String", "String", getQualifiedClassName(test_flt4.public::toString()));

var orig_tostr = Object.prototype.toString;
Object.prototype.toString = float4.prototype.toString;
var test_obj:Object = {};
AddErrorTest("float4.prototype.toString() on Object throws TypeError ", TYPEERROR, function(){ test_obj.public::toString();});
// we test that it throws TypeError, not RangeError
AddErrorTest("float4.prototype.toString(357) on Object throws TypeError", TYPEERROR, function(){ test_obj.public::toString(357);});
Object.prototype.toString = orig_tostr;

var orig_tostr = Number.prototype.toString;
Number.prototype.toString = float4.prototype.toString;
var test_num:Number = 3.14131211;
AddErrorTest("float4.prototype.toString() on Number throws TypeError", TYPEERROR, function(){ test_num.public::toString();});
AddErrorTest("float4.prototype.toString() on Number throws TypeError", TYPEERROR, function(){ Number.prototype.toString.AS3::call(test_num);});
// we test that it throws TypeError, not RangeError
AddErrorTest("float4.prototype.toString(357) on Number throws TypeError", TYPEERROR, function(){ test_num.public::toString(357);});
AddErrorTest("float4.prototype.toString() on Number throws TypeError", TYPEERROR, function(){ Number.prototype.toString.AS3::call(test_num);});
Number.prototype.toString = orig_tostr;

AddTestCase("float4.prototype.toString = invokes AS3::toString", test_flt4.AS3::toString(), test_flt4.public::toString());
AddTestCase("float4.prototype.toString(5) = invokes AS3::toString(5)", test_flt4.AS3::toString(5), test_flt4.public::toString(5));

AddTestCase("float4.prototype.toString - DontEnum", "", getFloat4ProtoProp("toString"));
AddTestCase("float4.prototype.toString is not enumerable", false, float4.prototype.propertyIsEnumerable("toString"));

var orig_tostr = float4.prototype.toString;
float4.prototype.toString = 1.1243174;
AddTestCase("float4.prototype.toString - Writable", true, orig_tostr != float4.prototype.toString);
float4.prototype.toString = orig_tostr;

AddTestCase("float4.prototype.toString - Deletable", true, delete(float4.prototype.toString));
// it should now find "Object" as toString, on the prototype chain
AddTestCase("float4.prototype.toString should now be Object.prototype.toString", Object.prototype.toString, float4.prototype.toString);
float4.prototype.toString = orig_tostr;

AddTestCase("float4.prototype.toString: implicit radix is 10", test_flt4.public::toString(10), test_flt4.public::toString());


test();

