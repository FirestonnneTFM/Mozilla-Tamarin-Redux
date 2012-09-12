/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*
Returns an implementation-dependent approximation to the sine of x. The argument
is expressed in radians.
*/

import avmplus.*;

var SECTION = "15.8.2.16";
var VERSION = "AS3";
var TITLE   = "public native static function sin (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.sin(param); }

AddTestCase("Number.sin() returns a Number", "Number", getQualifiedClassName(Number.sin(1)));
AddTestCase("Number.sin() length is 1", 1, Number.sin.length);
AddErrorTest("Number.sin() with no args", ARGUMENTERROR+1063,  function(){ Number.sin(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.sin(undefined)", NaN, Number.sin(undefined));
AddTestCase("Number.sin(string)", NaN, Number.sin("string"));
AddTestCase("Number.sin(NaN)", NaN, Number.sin(NaN));
AddTestCase("Number.sin(NaN) check()", NaN, check(NaN));


// If x is +0, the result is +0.
var zero:Number = 0;
AddTestCase("Number.sin(zero=0)", 0, Number.sin(zero));
AddTestCase("Number.sin(zero=0) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.sin(zero));
AddTestCase("Number.sin(0)", 0, Number.sin(0));
AddTestCase("Number.sin(0) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.sin(0));
AddTestCase("Number.sin(0) check()", 0, check(0));
AddTestCase("Number.sin(0) check() sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(0));
AddTestCase("Number.sin('0')", 0, Number.sin('0'));
AddTestCase("Number.sin(null)", 0, Number.sin(null));
AddTestCase("Number.sin(false)", 0, Number.sin(false));

// If x is -0, the result is -0.
var neg_zero:Number = -0;
AddTestCase("Number.sin(zero=-0)", -0, Number.sin(neg_zero));
AddTestCase("Number.sin(zero=-0) sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.sin(neg_zero));
AddTestCase("Number.sin(-0) NumberLiteral", -0, Number.sin(-0));
AddTestCase("Number.sin(-0) NumberLiteral sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.sin(-0));
AddTestCase("Number.sin(-0) check()", -0, check(-0));
AddTestCase("Number.sin(-0) check() sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0));


// If x is +Infinity or -Infinity, the result is NaN.
AddTestCase("Number.sin(Number.POSITIVE_INFINITY)", NaN, Number.sin(Number.POSITIVE_INFINITY));
AddTestCase("Number.sin(Number.NEGATIVE_INFINITY)", NaN, Number.sin(Number.NEGATIVE_INFINITY));

AddTestCase("Number.sin(Number.PI/4)", 0.7071067811865134, Number.sin(Number.PI/4));
AddTestCase("Number.sin(Number.PI/2)", 1, Number.sin(Number.PI/2));
AddTestCase("Number.sin(Number.PI)", -8.74227766e-8, Number.sin(Number.PI));


test();

