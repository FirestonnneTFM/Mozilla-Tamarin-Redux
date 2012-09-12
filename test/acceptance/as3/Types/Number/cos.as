/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*
Returns an implementation-dependent approximation to the cosine of x. The
argument is expressed in radians.
*/

import avmplus.*;

var SECTION = "15.8.2.7";
var VERSION = "AS3";
var TITLE   = "public native static function cos (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.cos(param); }

AddTestCase("Number.cos() returns a Number", "Number", getQualifiedClassName(Number.cos(1)));
AddTestCase("Number.cos() length is 1", 1, Number.cos.length);
AddErrorTest("Number.cos() with no args", ARGUMENTERROR+1063,  function(){ Number.cos(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.cos(undefined)", NaN, Number.cos(undefined));
AddTestCase("Number.cos(string)", NaN, Number.cos("string"));
AddTestCase("Number.cos(NaN)", NaN, Number.cos(NaN));
AddTestCase("Number.cos(NaN) check()", NaN, check(NaN));

// If x is +0, the result is 1.
AddTestCase("Number.cos(0)", 1, Number.cos(0));
AddTestCase("Number.cos('0')", 1, Number.cos('0'));
AddTestCase("Number.cos(0) check()", 1, check(0));

// If x is -0, the result is 1.
AddTestCase("Number.cos(-0)", 1, Number.cos(-0));
AddTestCase("Number.cos('-0')", 1, Number.cos('-0'));
AddTestCase("Number.cos(-0) check()", 1, check(-0));

// If x is +Infinity, the result is NaN.
AddTestCase("Number.cos(Number.POSITIVE_INFINITY)", NaN, Number.cos(Number.POSITIVE_INFINITY));
AddTestCase("Number.cos(Number.POSITIVE_INFINITY) check()", NaN, check(Number.POSITIVE_INFINITY));

// If x is -Infinity, the result is NaN.
AddTestCase("Number.cos(Number.NEGATIVE_INFINITY)", NaN, Number.cos(Number.NEGATIVE_INFINITY));
AddTestCase("Number.cos(Number.NEGATIVE_INFINITY) check()", NaN, check(Number.NEGATIVE_INFINITY));


AddTestCase("Number.cos(null)", 1, Number.cos(null));
AddTestCase("Number.cos(true)", 0.5403022766113281, Number.cos(true));
AddTestCase("Number.cos(false)", 1, Number.cos(false));

AddTestCase("Number.cos(Number.PI)", -1, Number.cos(Number.PI));
AddTestCase("Number.cos(-Number.PI)", -1, Number.cos(-Number.PI));

var myNum:Number = 3.1415927;
AddTestCase("Number.cos(myNum=3.1415927)", -1, Number.cos(myNum));
AddTestCase("Number.cos(myNum=-3.1415927)", -1, Number.cos(-myNum));

AddTestCase("Number.cos(3.1415927) NumberLiteral", -1, Number.cos(3.1415927));
AddTestCase("Number.cos(-3.1415927) NumberLiteral", -1, Number.cos(-3.1415927));

AddTestCase("Number.cos(Number.MIN_VALUE)", 1, Number.cos(Number.MIN_VALUE));
AddTestCase("Number.cos(Number.MAX_VALUE)", -0.9999876894265599, Number.cos(Number.MAX_VALUE));

test();

