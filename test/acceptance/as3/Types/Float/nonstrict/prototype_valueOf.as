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


var SECTION = "4.6.4";
var VERSION = "AS3";
var TITLE   = "float.prototype.valueOf () : float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var test_flt:float = 3.14131211f;
AddTestCase("float.prototype.valueOf = function", true, float.prototype.valueOf is Function );

var orig_valof = Object.prototype.valueOf;
Object.prototype.valueOf = float.prototype.valueOf;
var test_obj:Object = {};
AddErrorTest("float.prototype.valueOf() on Object throws TypeError ", TYPEERROR, function(){ test_obj.public::valueOf();});
Object.prototype.valueOf = orig_valof;


var orig_valof = Number.prototype.valueOf;
Number.prototype.valueOf = float.prototype.valueOf;
var test_num:Number = 3.14131211;
AddErrorTest("float.prototype.valueOf() on Number throws TypeError", TYPEERROR, function(){ test_num.public::valueOf();});
Number.prototype.valueOf = orig_valof;


AddTestCase("float.prototype.valueOf returns a float", "float", typeof(test_flt.public::valueOf()));
AddTestCase("float.prototype.valueOf - returns this float", test_flt, test_flt.public::valueOf());
var test_flt_bits:int=1078528834; // 0x40490b42
AddTestCase("float.prototype.valueOf - returns this float, bits", test_flt_bits, FloatRawBits(test_flt.public::valueOf()));


AddTestCase("float.prototype.valueOf - DontEnum", "", getFloatProtoProp("valueOf"));
AddTestCase("float.prototype.valueOf is not enumerable", false, float.prototype.propertyIsEnumerable("valueOf"));

orig_valof = float.prototype.valueOf;
float.prototype.valueOf = 1.1243174;
AddTestCase("float.prototype.valueOf - Writable", true, orig_valof != float.prototype.valueOf);
float.prototype.valueOf = orig_valof;

AddTestCase("float.prototype.valueOf - Deletable", true, delete(float.prototype.valueOf));
// it should now find "Object" as valueOf, on the prototype chain
AddTestCase("float.prototype.valueOf should now be Object.prototype.valueOf", Object.prototype.valueOf, float.prototype.valueOf);
float.prototype.valueOf = orig_valof;

test();

