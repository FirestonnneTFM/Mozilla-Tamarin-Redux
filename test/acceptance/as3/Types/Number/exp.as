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

/*
Returns an implementation-dependent approximation to the exponential function
of x (e raised to the power of x, where e is the base of the natural logarithms).
*/

import avmplus.*;

var SECTION = "15.8.2.8";
var VERSION = "AS3";
var TITLE   = "public native static function exp (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.exp(param); }

AddTestCase("Number.exp() returns a Number", "Number", getQualifiedClassName(Number.exp(1)));
AddTestCase("Number.exp() length is 1", 1, Number.exp.length);
AddErrorTest("Number.exp() with no args", ARGUMENTERROR+1063,  function(){ Number.exp(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.exp(undefined)", NaN, Number.exp(undefined));
AddTestCase("Number.exp(string)", NaN, Number.exp("string"));
AddTestCase("Number.exp(NaN)", NaN, Number.exp(NaN));
AddTestCase("Number.exp(NaN) check()", NaN, check(NaN));

// If x is +0, the result is 1.
AddTestCase("Number.exp(0)", 1, Number.exp(0));
AddTestCase("Number.exp('0')", 1, Number.exp('0'));
AddTestCase("Number.exp(0) check()", 1, check(0));

// If x is -0, the result is 1.
AddTestCase("Number.exp(-0)", 1, Number.exp(-0));
AddTestCase("Number.exp('-0')", 1, Number.exp('-0'));
AddTestCase("Number.exp(-0) check()", 1, check(-0));

// If x is +Infinity, the result is +Infinity.
AddTestCase("Number.exp(Number.POSITIVE_INFINITY)", Number.POSITIVE_INFINITY, Number.exp(Number.POSITIVE_INFINITY));
AddTestCase("Number.exp(Number.POSITIVE_INFINITY) check()", Number.POSITIVE_INFINITY, check(Number.POSITIVE_INFINITY));

// If x is -Infinity, the result is +0.
AddTestCase("Number.exp(Number.NEGATIVE_INFINITY)", 0, Number.exp(Number.NEGATIVE_INFINITY));
AddTestCase("Number.exp(Number.NEGATIVE_INFINITY) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.exp(Number.NEGATIVE_INFINITY));
AddTestCase("Number.exp(Number.NEGATIVE_INFINITY) check()", 0, check(Number.NEGATIVE_INFINITY));
AddTestCase("Number.exp(Number.NEGATIVE_INFINITY) check() sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(Number.NEGATIVE_INFINITY));


AddTestCase("Number.exp(null)", 1, Number.exp(null));
AddTestCase("Number.exp(false)", 1, Number.exp(false));

AddTestCase("Number.exp(1)", Number.E, Number.exp(1));
AddTestCase("Number.exp(1) check()", Number.E, check(1));
AddTestCase("Number.exp('1')", Number.E, Number.exp('1'));
AddTestCase("Number.exp(true)", Number.E, Number.exp(true));

AddTestCase("Number.exp(Number.MIN_VALUE)", 1, Number.exp(Number.MIN_VALUE));
AddTestCase("Number.exp(Number.MAX_VALUE)", Number.POSITIVE_INFINITY, Number.exp(Number.MAX_VALUE));

AddTestCase("Number.exp(1.0e+3)", Number.POSITIVE_INFINITY, Number.exp(1.0e+3));
AddTestCase("Number.exp(-1.0e+3)", 0, Number.exp(-1.0e+3));

test();

