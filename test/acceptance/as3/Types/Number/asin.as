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
Returns an implementation-dependent approximation to the arc sine of x.
The result is expressed in radians and ranges from -PI/2 to +PI/2.
*/

import avmplus.*;

var SECTION = "15.8.2.3";
var VERSION = "AS3";
var TITLE   = "public native static function asin (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.asin(param); }

AddTestCase("Number.asin() returns a Number", "Number", getQualifiedClassName(Number.asin(1)));
AddTestCase("Number.asin() length is 1", 1, Number.asin.length);
AddErrorTest("Number.asin() with no args", ARGUMENTERROR+1063,  function(){ Number.asin(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.asin(undefined)", NaN, Number.asin(undefined));
AddTestCase("Number.asin(string)", NaN, Number.asin("string"));
AddTestCase("Number.asin(NaN)", NaN, Number.asin(NaN));

// If x is greater than 1, the result is NaN.
AddTestCase("Number.asin(1.125)", NaN, Number.asin(1.125));
AddTestCase("Number.asin(1.125) check()", NaN, check(1.125));

// If x is less than –1, the result is NaN.
AddTestCase("Number.asin(-1.125)", NaN, Number.asin(-1.125));
AddTestCase("Number.asin(-1.125) check()", NaN, check(-1.125));


// If x is +0, the result is +0.
AddTestCase("Number.asin(0)", 0, Number.asin(0));
AddTestCase("Number.asin(0) check()", 0, check(0));
AddTestCase("Ensure that Number.asin(+0) returns +0", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.asin(0));
AddTestCase("Ensure that Number.asin(+0) returns +0 check()", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(0));

// If x is -0, the result is -0.
AddTestCase("Number.asin(-0)", -0, Number.asin(-0));
AddTestCase("Number.asin(-0) check()", -0, check(-0));
AddTestCase("Ensure that Number.asin(-0) returns -0", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.asin(-0));
AddTestCase("Ensure that Number.asin(-0) returns -0 check()", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0));


AddTestCase("Number.asin(null)", 0, Number.asin(null));
AddTestCase("Number.asin(true)", Number.PI/2, Number.asin(true));
AddTestCase("Number.asin(false)", 0, Number.asin(false));

AddTestCase("Number.asin('1')", Number.PI/2, Number.asin('1'));
AddTestCase("Number.asin('0')", 0, Number.asin('0'));

var myNum:Number = 1;
AddTestCase("Number.asin(myNum=1)", Number.PI/2.0, Number.asin(myNum));
myNum = 0;
AddTestCase("Number.asin(myNum=0)", 0, Number.asin(myNum));
myNum = -0;
AddTestCase("Number.asin(myNum=-0)", -0, Number.asin(myNum));
myNum = -1;
AddTestCase("Number.asin(myNum=-1)", -Number.PI/2.0, Number.asin(myNum));

AddTestCase("Number.asin(1) NumberLiteral", Number.PI/2.0, Number.asin(1));
AddTestCase("Number.asin(0) NumberLiteral", 0, Number.asin(0));
AddTestCase("Number.asin(-0) NumberLiteral", -0, Number.asin(-0));
AddTestCase("Number.asin(-1) NumberLiteral", -Number.PI/2.0, Number.asin(-1));

AddTestCase("Number.asin(Number.SQRT1_2)", 0.7853981256484985, Number.asin(Number.SQRT1_2));
AddTestCase("Number.asin(-Number.SQRT1_2)", -0.7853981256484985, Number.asin(-Number.SQRT1_2));



test();

