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


var SECTION = "4.5.4";
var VERSION = "AS3";
var TITLE   = "float4.prototype.valueOf () : float4";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var test_flt4:float4 = new float4(3.14131211f);
AddTestCase("float4.prototype.valueOf = function", true, float4.prototype.valueOf is Function );
AddErrorTest("float4.prototype.valueOf(357) throws ArgumentError", ARGUMENTERROR, function(){ test_flt4.valueOf(357);});

var orig_valof = Object.prototype.valueOf;
Object.prototype.valueOf = float4.prototype.valueOf;
var test_obj:Object = {};
AddErrorTest("float4.prototype.valueOf() on Object throws TypeError ", TYPEERROR, function(){ test_obj.valueOf();});
// we test that it throws TypeError, not RangeError
AddErrorTest("float4.prototype.valueOf(357) on Object throws TypeError", TYPEERROR, function(){ test_obj.valueOf(357);});
Object.prototype.valueOf = orig_valof;

/* https://bugzilla.mozilla.org/show_bug.cgi?id=686862
var orig_valof = Number.prototype.valueOf;
Number.prototype.valueOf = float4.prototype.valueOf;
var test_num:Number = 3.14131211;
AddErrorTest("float4.prototype.valueOf() on Number throws TypeError", TYPEERROR, function(){ test_num.valueOf();});
// we test that it throws TypeError, not ArgumentError
AddErrorTest("float4.prototype.valueOf(357) on Number throws TypeError", TYPEERROR, function(){ test_num.toLocaleString(357);});
Number.prototype.valueOf = orig_valof;
*/

AddTestCase("float4.prototype.valueOf returns a float4", "float4", typeof(test_flt4.valueOf()));
AddTestCase("float4.prototype.valueOf - returns this float4", test_flt4, test_flt4.valueOf());

AddTestCase("float4.prototype.valueOf - DontEnum", "", getFloat4ProtoProp("valueOf"));
AddTestCase("float4.prototype.valueOf is not enumerable", false, float4.prototype.propertyIsEnumerable("valueOf"));

orig_valof = float4.prototype.valueOf;
float4.prototype.valueOf = 1.1243174;
AddTestCase("float4.prototype.valueOf - Writable", true, orig_valof != float4.prototype.valueOf);
float4.prototype.valueOf = orig_valof;

AddTestCase("float4.prototype.valueOf - Deletable", true, delete(float4.prototype.valueOf));
// it should now find "Object" as valueOf, on the prototype chain
AddTestCase("float4.prototype.valueOf should now be Object.prototype.valueOf", Object.prototype.valueOf, float4.prototype.valueOf);
float4.prototype.valueOf = orig_valof;

test();

