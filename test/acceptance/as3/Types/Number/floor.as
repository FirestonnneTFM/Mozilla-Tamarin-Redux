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
Returns the greatest (closest to +Infinity) Number value that is not greater
than x and is equal to a mathematical integer. If x is already an integer, the
result is x.
*/

import avmplus.*;

var SECTION = "15.8.2.9";
var VERSION = "AS3";
var TITLE   = "public native static function floor (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.floor(param); }

AddTestCase("Number.floor() returns a int", "int", getQualifiedClassName(Number.floor(1.125)));
AddTestCase("Number.floor() length is 1", 1, Number.floor.length);
AddErrorTest("Number.floor() with no args", ARGUMENTERROR+1063,  function(){ Number.floor(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.floor(undefined)", NaN, Number.floor(undefined));
AddTestCase("Number.floor(string)", NaN, Number.floor("string"));
AddTestCase("Number.floor(NaN)", NaN, Number.floor(NaN));
AddTestCase("Number.floor(NaN)", NaN, check(NaN));

// If x is +0, the result is +0.
AddTestCase("Number.floor(0)", 0, Number.floor(0));
AddTestCase("Number.floor(0) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.floor(0));
AddTestCase("Number.floor(0) check()", 0, check(0));
AddTestCase("Number.floor(0) check() sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(0));
AddTestCase("Number.floor(null)", 0, Number.floor(null));
AddTestCase("Number.floor(false)", 0, Number.floor(false));
AddTestCase("Number.floor('0')", 0, Number.floor('0'));
AddTestCase("Number.INFINITY/Number.floor('0')", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.floor('0'));

// If x is -0, the result is -0.
AddTestCase("Number.floor(-0)", -0, Number.floor(-0));
AddTestCase("Number.floor(-0) sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.floor(-0));
AddTestCase("Number.floor(-0) check()", -0, check(-0));
AddTestCase("Number.floor(-0) check() sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0));

// If x is +Infinity, the result is +Infinity.
AddTestCase("Number.floor(Number.POSITIVE_INFINITY)", Number.POSITIVE_INFINITY, Number.floor(Number.POSITIVE_INFINITY));
AddTestCase("Number.floor(Number.POSITIVE_INFINITY) check()", Number.POSITIVE_INFINITY, check(Number.POSITIVE_INFINITY));

// If x is -Infinity, the result is -Infinity.
AddTestCase("Number.floor(Number.NEGATIVE_INFINITY)", Number.NEGATIVE_INFINITY, Number.floor(Number.NEGATIVE_INFINITY));
AddTestCase("Number.floor(Number.NEGATIVE_INFINITY) check()", Number.NEGATIVE_INFINITY, check(Number.NEGATIVE_INFINITY));

// If x is greater than 0 but less than 1, the result is +0.
AddTestCase("Number.floor(Number.MIN_VALUE)", 0, Number.floor(Number.MIN_VALUE));
AddTestCase("Number.floor(0.5)", 0, Number.floor(0.5));
AddTestCase("Number.floor(0.5) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.floor(0.5));
AddTestCase("Number.floor(0.999)", 0, Number.floor(0.999));
AddTestCase("Number.floor(0.999) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.floor(0.999));
AddTestCase("Number.floor(0.5) check()", 0, check(0.5));
AddTestCase("Number.floor(0.5) check() sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(0.5));

// The value of Number.floor(x) is the same as the value of -Number.ceil(-x).
AddTestCase("Number.floor(3.124) == -Number.ceil(-3.124)", -Number.ceil(-3.124), Number.floor(3.124));



AddTestCase("Number.floor(true)", 1, Number.floor(true));
AddTestCase("Number.floor('1')", 1, Number.floor('1'));

AddTestCase("Number.floor(-Number.MIN_VALUE)", -1, Number.floor(-Number.MIN_VALUE));
AddTestCase("Number.floor(Number.MAX_VALUE)", Number.MAX_VALUE, Number.floor(Number.MAX_VALUE));

var myNum:Number = 1;
AddTestCase("Number.floor(myNum=1)", 1, Number.floor(myNum));
myNum = 0;
AddTestCase("Number.floor(myNum=0)", 0, Number.floor(myNum));
AddTestCase("Number.INFINITY/Number.floor(myNum=0)", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.floor(myNum));
myNum = -0;
AddTestCase("Number.floor(myNum=-0)", -0, Number.floor(myNum));
AddTestCase("Number.INFINITY/Number.floor(myNum=-0)", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.floor(myNum));
myNum = -1;
AddTestCase("Number.floor(myNum=-1)", -1, Number.floor(myNum));

AddTestCase("Number.floor(1) NumberLiteral", 1, Number.floor(1));
AddTestCase("Number.floor(0) NumberLiteral", 0, Number.floor(0));
AddTestCase("Number.floor(-0) NumberLiteral", -0, Number.floor(-0));
AddTestCase("Number.floor(-1) NumberLiteral", -1, Number.floor(-1));





test();

