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

var SECTION = "4.7.5";
var VERSION = "AS3";
var TITLE   = "AS3 function toPrecision ( precision=0 ) : String";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var test_flt:float = 2.7182818284e5f;
var test_num:Number;

AddTestCase("float.AS3::toPrecision = function", true, test_flt.AS3::toPrecision is Function);
AddTestCase("float.AS3::toPrecision returns a String", "String", getQualifiedClassName(test_flt.AS3::toPrecision(1)));

test_flt = Infinity;
test_num = test_flt;
AddTestCase("test float.AS3::toPrecision(2) Infinity", test_num.AS3::toPrecision(2), test_flt.AS3::toPrecision(2));
test_flt = -Infinity;
test_num = test_flt;
AddTestCase("test float.AS3::toPrecision(2) -Infinity", test_num.AS3::toPrecision(2), test_flt.AS3::toPrecision(2));
test_flt = NaN;
test_num = test_flt;
AddTestCase("test float.AS3::toPrecision(2) NaN", test_num.AS3::toPrecision(2), test_flt.AS3::toPrecision(2));
test_flt = float.MAX_VALUE;
test_num = test_flt;
AddTestCase("test float.AS3::toPrecision(2) float.MAX_VALUE", test_num.AS3::toPrecision(2), test_flt.AS3::toPrecision(2));
test_flt = float.MIN_VALUE;
test_num = test_flt;
AddTestCase("test float.AS3::toPrecision(2) float.MIN_VALUE", test_num.AS3::toPrecision(2), test_flt.AS3::toPrecision(2));
test_flt = new float(2.7182818284e5);
test_num = test_flt;
AddTestCase("test float.AS3::toPrecision(2) new float()", test_num.AS3::toPrecision(2), test_flt.AS3::toPrecision(2));
test_flt = 2.7182818284e5f;
test_num = test_flt;
AddTestCase("test float.AS3::toPrecision(2) float literal", test_num.AS3::toPrecision(2), 2.7182818284e5f.AS3::toPrecision(2));

var expectedRangeErr:String = "???";
try{ test_flt.AS3::toPrecision(0); } catch(e:RangeError){ expectedRangeErr = rangeError(e.toString()); }
AddErrorTest("float.AS3::toPrecision() == float.AS3::toPrecision(0)", expectedRangeErr, function(){ return test_flt.AS3::toPrecision();});

test_num = test_flt;
AddTestCase("float.AS3::toPrecision(3)", test_num.AS3::toPrecision(3), test_flt.AS3::toPrecision(3));

test_num = test_flt;
AddTestCase("float.AS3::toPrecision(21)", test_num.AS3::toPrecision(21), test_flt.AS3::toPrecision(21));

test_num = test_flt;
AddTestCase("float.AS3::toPrecision(1)", test_num.AS3::toPrecision(1), test_flt.AS3::toPrecision(1));

AddErrorTest("float.AS3::toPrecision(undefined)", RANGEERROR, function(){ test_flt.AS3::toPrecision(undefined) });
AddErrorTest("float.AS3::toPrecision(NaN): RangeError", RANGEERROR, function(){ test_flt.AS3::toPrecision(NaN) });
AddErrorTest("float.AS3::toPrecision(0): RangeError", RANGEERROR, function(){ test_flt.AS3::toPrecision(0) });
AddErrorTest("float.AS3::toPrecision(22): RangeError ", RANGEERROR, function(){ test_flt.AS3::toPrecision(22) });

test();

