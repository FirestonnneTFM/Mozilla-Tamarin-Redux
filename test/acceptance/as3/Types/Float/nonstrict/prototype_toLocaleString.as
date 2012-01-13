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


var SECTION = "4.6.3";
var VERSION = "AS3";
var TITLE   = "float.prototype.toLocaleString ( radix=10 ) : String";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var test_flt:float = 3.14131211f;
AddTestCase("float.prototype.toLocaleString = function", true, float.prototype.toLocaleString is Function );
AddTestCase("float.prototype.toLocaleString returns a String", "String", getQualifiedClassName(test_flt.public::toLocaleString()));

var orig_tostr = Object.prototype.toString;
Object.prototype.toLocaleString = float.prototype.toLocaleString;
var test_obj:Object = {};
AddErrorTest("float.prototype.toLocaleString() on Object throws TypeError ", TYPEERROR, function(){ test_obj.public::toLocaleString();});
// we test that it throws TypeError, not RangeError
AddErrorTest("float.prototype.toLocaleString(357) on Object throws TypeError", TYPEERROR, function(){ test_obj.public::toLocaleString(357);});
Object.prototype.toLocaleString = orig_tostr;

var orig_tostr = Number.prototype.toLocaleString;
var test_num:Number = 3.14131211;
Number.prototype.toLocaleString = float.prototype.toLocaleString;
/// there is no AS3::toLocaleString, this should always throw type error
AddErrorTest("float.prototype.toLocaleString() non-generic= throws TypeError", TYPEERROR, function(){ test_num.public::toLocaleString();});
AddErrorTest("float.prototype.toLocaleString(357) non-generic= throws TypeError", TYPEERROR, function(){ test_num.public::toLocaleString(357);});
Number.prototype.toLocaleString = orig_tostr;

AddTestCase("float.prototype.toLocaleString = invokes AS3::toString", test_flt.AS3::toString(), test_flt.public::toLocaleString());
AddTestCase("float.prototype.toLocaleString(25) = invokes AS3::toString(25)", test_flt.AS3::toString(25), test_flt.public::toLocaleString(25));

AddTestCase("float.prototype.toLocaleString - DontEnum", "", getFloatProtoProp("toLocaleString"));
AddTestCase("float.prototype.toLocaleString is not enumerable", false, float.prototype.propertyIsEnumerable("toLocaleString"));

orig_tostr = float.prototype.toLocaleString;
float.prototype.toLocaleString = 1.1243174;
AddTestCase("float.prototype.toLocaleString - Writable", true, orig_tostr != float.prototype.toLocaleString);
float.prototype.toLocaleString = orig_tostr;

AddTestCase("float.prototype.toLocaleString - Deletable", true, delete(float.prototype.toLocaleString));
// it should now find "Object" as toLocaleString, on the prototype chain
AddTestCase("float.prototype.toLocaleString should now be Object.prototype.toLocaleString", Object.prototype.toLocaleString, float.prototype.toLocaleString);
float.prototype.toLocaleString = orig_tostr;

AddTestCase("float.prototype.toLocaleString: implicit radix is 10", test_flt.public::toLocaleString(10), test_flt.public::toLocaleString());

test();

