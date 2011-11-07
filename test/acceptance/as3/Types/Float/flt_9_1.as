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


var SECTION = "9.1";
var VERSION = "AS3";
var TITLE   = "The operation ToNumber";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var expected:Array = DoubleRawBits(Number.POSITIVE_INFINITY);
var actual:Array = DoubleRawBits(float.POSITIVE_INFINITY);
AddTestCase("ToNumber(float.POSITIVE_INFINITY) 0", expected[0], actual[0]);
AddTestCase("ToNumber(float.POSITIVE_INFINITY) 1", expected[1], actual[1]);

expected = DoubleRawBits(Number.NEGATIVE_INFINITY);
actual   = DoubleRawBits(float.NEGATIVE_INFINITY);
AddTestCase("ToNumber(float.NEGATIVE_INFINITY) 0", expected[0], actual[0]);
AddTestCase("ToNumber(float.NEGATIVE_INFINITY) 1", expected[1], actual[1]);

expected = DoubleRawBits(12345);
actual   = DoubleRawBits(12345f);
AddTestCase("ToNumber(12345.0f) - test widening) 0", expected[0], actual[0]);
AddTestCase("ToNumber(12345.0f) - test widening) 1", expected[1], actual[1]);

expected = DoubleRawBits(-123456782336); /* that's the actual int value for -123.45678e9f */
actual   = DoubleRawBits(-123.45678e9f);
AddTestCase("ToNumber(-123.45678e9f) - test widening) 0", expected[0], actual[0]);
AddTestCase("ToNumber(-123.45678e9f) - test widening) 1", expected[1], actual[1]);

expected = DoubleRawBits(3.4028234663852886e+38); /* that's the actual exact value of float.MAX_VALUE extended to double */
actual   = DoubleRawBits(float.MAX_VALUE);
AddTestCase("ToNumber(float.MAX_VALUE) 0", expected[0], actual[0]);
AddTestCase("ToNumber(float.MAX_VALUE) 1", expected[1], actual[1]);


/* This is tricky, since float.MIN_VALUE may change from platform to platform. Check that going to Number & back preserves the value */
var n:Number = float.MIN_VALUE;
AddTestCase("ToNumber(float.MIN_VALUE)", true, float(n)===float.MIN_VALUE);

test();

