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


var SECTION = "4.6.1";
var VERSION = "AS3";
var TITLE   = "AS3 function toString ( radix=10 ) : String";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var test_flt4:float4 = new float4(2.7182818284e5f);

AddTestCase("float4.AS3::toString = function", true, test_flt4.AS3::toString is Function);
AddTestCase("float4.AS3::toString returns a String", "String", getQualifiedClassName(test_flt4.AS3::toString()));

AddTestCase("float4.AS3::toString: implicit radix is 10", test_flt4.AS3::toString(10), test_flt4.AS3::toString());

AddTestCase("float4.AS3::toString: with string radix", test_flt4.AS3::toString(10), test_flt4.AS3::toString("10"));

test_flt4 = new float4(float.NaN);
AddTestCase("No range error for NaN", "NaN,NaN,NaN,NaN", test_flt4.toString(99));
test_flt4 = new float4(float.POSITIVE_INFINITY);
AddTestCase("No range error for +Inf", "Infinity,Infinity,Infinity,Infinity", test_flt4.toString(99));
test_flt4 = new float4(float.NEGATIVE_INFINITY);
AddTestCase("No range error for -Inf", "-Infinity,-Infinity,-Infinity,-Infinity", test_flt4.toString(99));

test_flt4 = new float4(1f);
AddErrorTest("float4.AS3::toString: range errors toString(37)", RANGEERROR, function(){test_flt4.AS3::toString(37)});
AddErrorTest("float4.AS3::toString: range errors toString(1)", RANGEERROR, function(){test_flt4.AS3::toString(1)});
AddErrorTest("float4.AS3::toString: range errors toString(null)", RANGEERROR, function(){test_flt4.AS3::toString(null)});
AddErrorTest("float4.AS3::toString: range errors toString(undefined)", RANGEERROR, function(){test_flt4.AS3::toString(undefined)});
AddErrorTest("float4.AS3::toString: range errors toString(float.NaN)", RANGEERROR, function(){test_flt4.AS3::toString(float.NaN)});
AddErrorTest("float4.AS3::toString: range errors toString(Infinity)", RANGEERROR, function(){test_flt4.AS3::toString(Infinity)});
AddErrorTest("float4.AS3::toString: range errors toString(-Infinity)", RANGEERROR, function(){test_flt4.AS3::toString(-Infinity)});

/* FIXME: Continue once this bug is fixed https://bugzilla.mozilla.org/show_bug.cgi?id=694990
AddTestCase("float.AS3::toString: base 36", "5tqs", test_flt.AS3::toString(36)); // should go on to convert only the integral part
AddTestCase("float.AS3::toString: base 2", "1000010010111010100", test_flt.AS3::toString(2)); // should go on to convert only the integral part
AddTestCase("float.AS3::toString: decimal", "5tqs", test_flt.AS3::toString(36.2)); // should covert radix to int
AddTestCase("float.AS3::toString: hexadecimal", "5tqs", test_flt.AS3::toString(0x24)); // should covert radix to int

AddTestCase("float.AS3::toString: NaN, in base 16", "NaN", float.NaN.AS3::toString(16)); // base doesn't matter, still prints 'NaN'

AddTestCase("float.AS3::toString: float.MAX_VALUE, in base 16", "ffffff00000000000000000000000000", float.MAX_VALUE.AS3::toString(16));
AddTestCase("float.AS3::toString: float.MAX_VALUE, in base 16", (340282346638528859811704183484516925440).toString(16), float.MAX_VALUE.AS3::toString(16));

test_flt = -float.MAX_VALUE;
AddTestCase("float.AS3::toString: -float.MAX_VALUE, in base 16", "-ffffff00000000000000000000000000", test_flt.AS3::toString(16));
AddTestCase("float.AS3::toString: -float.MAX_VALUE, in base 16", (-340282346638528859811704183484516925440).toString(16), test_flt.AS3::toString(16));

test_flt = -float.MIN_VALUE;
AddTestCase("float.AS3::toString: -float.MIN_VALUE, in base 16", "0", test_flt.AS3::toString(16)); // shouldn't be "-0"!

test_flt = Infinity;
AddTestCase("float.AS3::toString: Infinity, in base 16", "Infinity", float.POSITIVE_INFINITY.AS3::toString(16)); // base doesn't matter, still prints 'Infinity'

test_flt = -Infinity;
AddTestCase("float.AS3::toString: -Infinity, in base 16", "-Infinity",float.NEGATIVE_INFINITY.AS3::toString(16)); // base doesn't matter, still prints '-Infinity'
*/
test();

