/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*
Returns the smallest (closest to -Infinity) Number value that is not less than x
and is equal to a mathematical integer. If x is already an integer, the result is x.
*/

import avmplus.*;

var SECTION = "15.8.2.6";
var VERSION = "AS3";
var TITLE   = "public native static function ceil (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.ceil(param); }

AddTestCase("Number.ceil() returns a int", "int", getQualifiedClassName(Number.ceil(1.125)));
AddTestCase("Number.ceil() length is 1", 1, Number.ceil.length);
AddErrorTest("Number.ceil() with no args", ARGUMENTERROR+1063,  function(){ Number.ceil(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.ceil(undefined)", NaN, Number.ceil(undefined));
AddTestCase("Number.ceil(string)", NaN, Number.ceil("string"));
AddTestCase("Number.ceil(NaN)", NaN, Number.ceil(NaN));
AddTestCase("Number.ceil(NaN) check()", NaN, check(NaN));

// If x is +0, the result is +0.
AddTestCase("Number.ceil(0)", 0, Number.ceil(0));
AddTestCase("Number.ceil(0) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.ceil(0));
AddTestCase("Number.ceil(0) check()", 0, check(0));
AddTestCase("Number.ceil(0) check() sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(0));

// If x is -0, the result is -0.
AddTestCase("Number.ceil(-0)", -0, Number.ceil(-0));
AddTestCase("Number.ceil(-0) sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.ceil(-0));
AddTestCase("Number.ceil(-0) check()", -0, check(-0));
AddTestCase("Number.ceil(-0) check() sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0));

// If x is +Infinity, the result is +Infinty.
AddTestCase("Number.ceil(Number.POSITIVE_INFINITY)", Number.POSITIVE_INFINITY, Number.ceil(Number.POSITIVE_INFINITY));
AddTestCase("Number.ceil(Number.POSITIVE_INFINITY) check()", Number.POSITIVE_INFINITY, check(Number.POSITIVE_INFINITY));

// If x is -Infinity, the result is -Infinity.
AddTestCase("Number.ceil(Number.NEGATIVE_INFINITY)", Number.NEGATIVE_INFINITY, Number.ceil(Number.NEGATIVE_INFINITY));
AddTestCase("Number.ceil(Number.NEGATIVE_INFINITY) check()", Number.NEGATIVE_INFINITY, check(Number.NEGATIVE_INFINITY));

// If x is less than 0 but greater than -1, the result is -0.
AddTestCase("Number.ceil(-0.1)", Number(-0), Number.ceil(-0.1));
AddTestCase("Number that Number.ceil(-0.1) returns -0", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.ceil(-0.1));
AddTestCase("Number.ceil(-0.5)", -0, Number.ceil(-0.5));
AddTestCase("Number.ceil(-0.5) sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.ceil(-0.5));
AddTestCase("Number.ceil(-0.999)", -0, Number.ceil(-0.999));
AddTestCase("Number.ceil(-0.999) sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.ceil(-0.999));
AddTestCase("Number.ceil(-0.5) check()", -0, check(-0.5));
AddTestCase("Number.ceil(-0.5) check() sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0.5));
AddTestCase("Number.ceil(-0.999) check()", -0, check(-0.999));
AddTestCase("Number.ceil(-0.999) check() sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0.999));

// The value of Number.ceil(x) is the same as the value of -Number.floor(-x).
AddTestCase("Number.ceil(3.124) == -Number.floor(-3.124)", -Number.floor(-3.124), Number.ceil(3.124));

AddTestCase("Number.ceil(null)", 0, Number.ceil(null));
AddTestCase("Number.ceil(true)", 1, Number.ceil(true));
AddTestCase("Number.ceil(false)", 0, Number.ceil(false));

AddTestCase("Number.ceil(Number.MAX_VALUE)", Number.MAX_VALUE, Number.ceil(Number.MAX_VALUE));
AddTestCase("Number.ceil(Number.MAX_VALUE+1.79769313486231e+308)", Number.POSITIVE_INFINITY, Number.ceil(Number.MAX_VALUE+1.79769313486231e+308));
AddTestCase("Number.ceil(Number.MIN_VALUE)", 1, Number.ceil(Number.MIN_VALUE));

AddTestCase("Number.ceil('1')", 1, Number.ceil('1'));
AddTestCase("Number.ceil('0')", 0, Number.ceil('0'));

var myNum:Number = 1;
AddTestCase("Number.ceil(myNum=1)", 1, Number.ceil(myNum));
myNum = 0;
AddTestCase("Number.ceil(myNum=0)", 0, Number.ceil(myNum));
AddTestCase("Number.INFINITY/Number.ceil(myNum=0)", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.ceil(myNum));
myNum = -0;
AddTestCase("Number.ceil(myNum=-0)", -0, Number.ceil(myNum));
AddTestCase("Number.INFINITY/Number.ceil(myNum=-0)", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.ceil(myNum));
myNum = -1;
AddTestCase("Number.ceil(myNum=-1)", -1, Number.ceil(myNum));

AddTestCase("Number.ceil(1) NumberLiteral", 1, Number.ceil(1));
AddTestCase("Number.ceil(0) NumberLiteral", 0, Number.ceil(0));
AddTestCase("Number.ceil(-0) NumberLiteral", -0, Number.ceil(-0));
AddTestCase("Number.ceil(-1) NumberLiteral", -1, Number.ceil(-1));

test();

