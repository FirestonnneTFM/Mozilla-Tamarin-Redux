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

