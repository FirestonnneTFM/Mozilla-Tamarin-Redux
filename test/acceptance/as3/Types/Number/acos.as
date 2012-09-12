/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*
Returns an implementation-dependent approximation to the arc cosine of x.
The result is expressed in radians and ranges from +0 to +PI.
*/

import avmplus.*;

var SECTION = "15.8.2.2";
var VERSION = "AS3";
var TITLE   = "public native static function acos (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.acos(param); }

AddTestCase("Number.acos() returns a Number", "Number", getQualifiedClassName(Number.acos(0)));
AddTestCase("Number.acos() length is 1", 1, Number.acos.length);
AddErrorTest("Number.acos() with no args", ARGUMENTERROR+1063,  function(){ Number.acos(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.acos(undefined)", NaN, Number.acos(undefined));
AddTestCase("Number.acos(string)", NaN, Number.acos("string"));
AddTestCase("Number.acos(NaN)", NaN, Number.acos(NaN));
AddTestCase("Number.acos(NaN) check()", NaN, check(NaN));

// If x is greater than 1, the result is NaN.
AddTestCase("Number.acos(1.125)", NaN, Number.acos(1.125));
AddTestCase("Number.acos(1.125) check()", NaN, check(1.125));

// If x is less than -1, the result is NaN.
AddTestCase("Number.acos(-1.125)", NaN, Number.acos(-1.125));
AddTestCase("Number.acos(-1.125) check", NaN, check(-1.125));

// If x is exactly 1, the result is +0.
AddTestCase("Number.acos(1)", 0, Number.acos(1));
AddTestCase("Ensure that Number.acos(1) returns +0", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.acos(1));


AddTestCase("Number.acos(null)", Number.PI/2.0, Number.acos(null));
AddTestCase("Number.acos(true)", 0, Number.acos(true));
AddTestCase("Number.acos(false)", Number.PI/2.0, Number.acos(false));

AddTestCase("Number.acos('1')", 0, Number.acos('1'));
AddTestCase("Number.acos('0')", Number.PI/2.0, Number.acos('0'));

var myNum:Number = 0;
AddTestCase("Number.acos(myNum=0)", Number.PI/2.0, Number.acos(myNum));
myNum = 1;
AddTestCase("Number.acos(myNum=1)", 0, Number.acos(myNum));
myNum = -1;
AddTestCase("Number.acos(myNum=-1)", Number.PI, Number.acos(myNum));
myNum = -0;
AddTestCase("Number.acos(myNum=-0)", Number.PI/2.0, Number.acos(myNum));

AddTestCase("Number.acos(0) NumberLiteral", Number.PI/2.0, Number.acos(0));
AddTestCase("Number.acos(1) NumberLiteral", 0, Number.acos(1));
AddTestCase("Number.acos(-1) NumberLiteral", Number.PI, Number.acos(-1));
AddTestCase("Number.acos(-0) NumberLiteral", Number.PI/2.0, Number.acos(-0));

AddTestCase("Number.acos(Number.SQRT1_2)", Number.PI/4.0, Number.acos(Number.SQRT1_2));
AddTestCase("Number.acos(-Number.SQRT1_2)", Number.PI/4.0*3.0, Number.acos(-Number.SQRT1_2));







test();

