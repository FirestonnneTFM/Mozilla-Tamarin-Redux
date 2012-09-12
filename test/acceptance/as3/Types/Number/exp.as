/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

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

