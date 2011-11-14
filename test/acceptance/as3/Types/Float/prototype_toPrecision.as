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


var SECTION = "4.6.7";
var VERSION = "AS3";
var TITLE   = "float.prototype.toPrecision ( precision=0 ) : String";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var test_flt:float = 3.14131211f;
AddTestCase("float.prototype.toPrecision = function", true, float.prototype.toPrecision is Function );
AddTestCase("float.prototype.toPrecision returns a String", "String", getQualifiedClassName(test_flt.public::toPrecision(1)));

var orig_toprec = String.prototype.toPrecision;
String.prototype.toPrecision = float.prototype.toPrecision;
var test_str:String = "3.14131211";
AddErrorTest("float.prototype.toPrecision() on String throws RangeError", RANGEERROR, function(){ test_str.public::toPrecision() });
AddTestCase("float.prototype.toPrecision(7) on String does NOT throw TypeError", test_flt.public::toPrecision(7), test_str.public::toPrecision(7));
// undefined converted to 0, throws RangeError
AddErrorTest("float.prototype.toPrecision - accepts 'undefined' for precision", RANGEERROR, function(){ test_str.public::toPrecision(undefined);});
String.prototype.toPrecision = orig_toprec;


var expectedRangeErr:String = "???";
try{ test_flt.AS3::toPrecision(0); } catch(e:RangeError){ expectedRangeErr = rangeError(e.toString()); }
AddErrorTest("float.prototype.toPrecision = invokes AS3::toPrecision", expectedRangeErr, function(){ test_flt.public::toPrecision() });
AddTestCase("float.prototype.toPrecision = invokes AS3::toPrecision", test_flt.AS3::toPrecision(4), test_flt.public::toPrecision(4));

AddTestCase("float.prototype.toPrecision - DontEnum", "", getFloatProtoProp("toPrecision"));
AddTestCase("float.prototype.toPrecision is not enumerable", false, float.prototype.propertyIsEnumerable("toPrecision"));

orig_toprec = float.prototype.toPrecision;
float.prototype.toPrecision = 1.1243174;
AddTestCase("float.prototype.toPrecision - Writable", true, orig_toprec != float.prototype.toPrecision);
float.prototype.toPrecision = orig_toprec;

AddTestCase("float.prototype.toPrecision - Deletable", true, delete(float.prototype.toPrecision));
AddTestCase("float.prototype.toPrecision should now be undefined", undefined, float.prototype.toPrecision);
float.prototype.toPrecision = orig_toprec;

test();

