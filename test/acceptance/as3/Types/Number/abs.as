/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*
Returns the absolute value of x; the result has the same magnitude as x but has positive sign.
*/

import avmplus.*;

var SECTION = "15.8.2.1";
var VERSION = "AS3";
var TITLE   = "public native static function abs (x:Number):Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.abs(param); }

AddTestCase("Number.abs(3.14) returns a Number", "Number", getQualifiedClassName(Number.abs(3.14)));
AddTestCase("Number.abs(-0) returns a int", "int", getQualifiedClassName(Number.abs(-0)));
AddTestCase("Number.abs(1) returns a int", "int", getQualifiedClassName(Number.abs(1)));
AddTestCase("Number.abs() length is 1", 1, Number.abs.length);
AddErrorTest("Number.abs() with no args", ARGUMENTERROR+1063,  function(){ Number.abs(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.abs(undefined)", NaN, Number.abs(undefined));
AddTestCase("Number.abs(string)", NaN, Number.abs("string"));
AddTestCase("Number.abs(NaN)", NaN, Number.abs(NaN));
AddTestCase("Number.abs(NaN) check()", NaN, check(NaN));

// If x is -0, the result is +0.
AddTestCase("Number.abs(0.0)", 0, Number.abs(0.0));
AddTestCase("Number.POSITIVE_INFINITY/Number.abs(0.0)", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.abs(0.0));
AddTestCase("Number.abs(-0.0)", 0, Number.abs(-0.0));
AddTestCase("Number.POSITIVE_INFINITY/Number.abs(-0.0)", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.abs(-0.0));
AddTestCase("Number.POSITIVE_INFINITY/cehck(-0.0)", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0.0));

// If x is -Infinity, the result is +Infinity.
AddTestCase("Number.abs(Number.NEGATIVE_INFINITY)", Number.POSITIVE_INFINITY, Number.abs(Number.NEGATIVE_INFINITY));
AddTestCase("Number.abs(Number.POSITIVE_INFINITY)", Number.POSITIVE_INFINITY, Number.abs(Number.POSITIVE_INFINITY));
AddTestCase("Number.abs(Number.NEGATIVE_INFINITY) check()", Number.POSITIVE_INFINITY, check(Number.NEGATIVE_INFINITY));
AddTestCase("Number.abs(Number.POSITIVE_INFINITY) check()", Number.POSITIVE_INFINITY, check(Number.POSITIVE_INFINITY));

var pi = 3.14;
AddTestCase("Number.abs(-NumberLiteral)", pi, Number.abs(-pi));
AddTestCase("Number.abs(NumberLiteral)", pi, Number.abs(pi));
AddTestCase("Number.abs(-NumberLiteral) check()", pi, check(-pi));
AddTestCase("Number.abs(NumberLiteral) check()", pi, check(pi));
var pi:Number = 3.14;
AddTestCase("Number.abs(-typed)", pi, Number.abs(-pi));
AddTestCase("Number.abs(typed)", pi, Number.abs(pi));
AddTestCase("Number.abs(-typed) check()", pi, check(-pi));
AddTestCase("Number.abs(typed) check()", pi, check(pi));

AddTestCase("Number.abs(null)", 0, Number.abs(null));
AddTestCase("Number.abs(true)", 1, Number.abs(true));
AddTestCase("Number.abs(false)", 0, Number.abs(false));

AddTestCase("Number.abs('1')", 1, Number.abs('1'));
AddTestCase("Number.abs('0')", 0, Number.abs('0'));
AddTestCase("Number.NEGATIVE_INFINITY/Number.abs('0')", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.abs('0'));

AddTestCase("Number.abs(-Number.MIN_VALUE)", Number.MIN_VALUE, Number.abs(-Number.MIN_VALUE));
AddTestCase("Number.abs(-Number.MAX_VALUE)", Number.MAX_VALUE, Number.abs(-Number.MAX_VALUE));
AddTestCase("Number.abs(Number.MIN_VALUE)", Number.MIN_VALUE, Number.abs(Number.MIN_VALUE));
AddTestCase("Number.abs(Number.MAX_VALUE)", Number.MAX_VALUE, Number.abs(Number.MAX_VALUE));
AddTestCase("Number.abs(-Number.MIN_VALUE) check()", Number.MIN_VALUE, check(-Number.MIN_VALUE));
AddTestCase("Number.abs(-Number.MAX_VALUE) check()", Number.MAX_VALUE, check(-Number.MAX_VALUE));
AddTestCase("Number.abs(Number.MIN_VALUE) check()", Number.MIN_VALUE, check(Number.MIN_VALUE));
AddTestCase("Number.abs(Number.MAX_VALUE) check()", Number.MAX_VALUE, check(Number.MAX_VALUE));



test();

