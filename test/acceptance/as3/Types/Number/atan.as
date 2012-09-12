/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*
Returns an implementation-dependent approximation to the arc tangent of x.
The result is expressed in radians and ranges from iPI/2 to +PI/2.
*/

import avmplus.*;

var SECTION = "15.8.2.4";
var VERSION = "AS3";
var TITLE   = "public native static function atan (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.atan(param); }

AddTestCase("Number.atan() returns a Number", "Number", getQualifiedClassName(Number.atan(1)));
AddTestCase("Number.atan() length is 1", 1, Number.atan.length);
AddErrorTest("Number.atan() with no args", ARGUMENTERROR+1063,  function(){ Number.atan(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.atan(undefined)", NaN, Number.atan(undefined));
AddTestCase("Number.atan(string)", NaN, Number.atan("string"));
AddTestCase("Number.atan(NaN)", NaN, Number.atan(NaN));
AddTestCase("Number.atan(NaN) check()", NaN, check(NaN));

// If x is +0, the result is +0.
AddTestCase("Number.atan(0)", 0, Number.atan(0));
AddTestCase("Number.atan(0) check()", 0, check(0));
AddTestCase("Ensure that Number.atan(+0) returns +0", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.atan(0));
AddTestCase("Ensure that Number.atan(+0) returns +0 check()", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(0));

// If x is -0, the result is -0.
AddTestCase("Number.atan(-0)", -0, Number.atan(-0));
AddTestCase("Number.atan(-0) check()", -0, check(-0));
AddTestCase("Ensure that Number.atan(-0) returns -0", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.atan(-0));
AddTestCase("Ensure that Number.atan(-0) returns -0 check()", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0));


// If x is +Infinity, the result is an implementation-dependent approximation to +PI/2.
AddTestCase("Number.atan(Number.POSITIVE_INFINITY)", Number.PI/2, Number.atan(Number.POSITIVE_INFINITY));
AddTestCase("Number.atan(Number.POSITIVE_INFINITY) check()", Number.PI/2, check(Number.POSITIVE_INFINITY));

// If x is -Infinity, the result is an implementation-dependent approximation to -PI/2.
AddTestCase("Number.atan(Number.NEGATIVE_INFINITY)", -Number.PI/2, Number.atan(Number.NEGATIVE_INFINITY));
AddTestCase("Number.atan(Number.NEGATIVE_INFINITY) check()", -Number.PI/2, check(Number.NEGATIVE_INFINITY));


AddTestCase("Number.atan(null)", 0, Number.atan(null));
AddTestCase("Number.atan(true)", Number.PI/4, Number.atan(true));
AddTestCase("Number.atan(false)", 0, Number.atan(false));


AddTestCase("Number.atan('1')", Number.PI/4, Number.atan('1'));
AddTestCase("Number.atan('0')", 0, Number.atan('0'));

var myNum:Number = 1;
AddTestCase("Number.atan(myNum=1)", Number.PI/4.0, Number.atan(myNum));
myNum = 0;
AddTestCase("Number.atan(myNum=0)", 0, Number.atan(myNum));
myNum = -0;
AddTestCase("Number.atan(myNum=-0)", -0, Number.atan(myNum));
myNum = -1;
AddTestCase("Number.atan(myNum=-1)", -Number.PI/4.0, Number.atan(myNum));

AddTestCase("Number.atan(1) NumberLiteral", Number.PI/4.0, Number.atan(1));
AddTestCase("Number.atan(0) NumberLiteral", 0, Number.atan(0));
AddTestCase("Number.atan(-0) NumberLiteral", -0, Number.atan(-0));
AddTestCase("Number.atan(-1) NumberLiteral", -Number.PI/4.0, Number.atan(-1));



test();

