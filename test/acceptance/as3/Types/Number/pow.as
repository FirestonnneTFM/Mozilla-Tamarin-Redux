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
Returns an implementation-dependent approximation to the result of raising x to the power y.
*/

import avmplus.*;

var SECTION = "15.8.2.13";
var VERSION = "AS3";
var TITLE   = "public native static function pow (x:Number, y:Number):Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param1:Number, param2:Number):Number { return Number.pow(param1, param2); }

AddTestCase("Number.pow() returns a Number", "Number", getQualifiedClassName(Number.pow(1.21,3.1)));
AddTestCase("Number.pow() length is 2", 2, Number.pow.length);
AddErrorTest("Number.pow() with no args", ARGUMENTERROR+1063,  function(){ Number.pow(); });
AddErrorTest("Number.pow() with one args", ARGUMENTERROR+1063,  function(){ Number.pow(1); });

// If y is NaN, the result is NaN.
AddTestCase("Number.pow(1.0, undefined)", NaN, Number.pow(1.0, undefined));
AddTestCase("Number.pow(1.0, string)", NaN, Number.pow(1.0, "string"));
AddTestCase("Number.pow(1.0, NaN)", NaN, Number.pow(1.0, NaN));
AddTestCase("Number.pow(1.0, NaN) check()", NaN, check(1.0, NaN));

// If y is +0, the result is 1, even if x is NaN.
AddTestCase("Number.pow(undefined, 0)", 1, Number.pow(undefined, 0));
AddTestCase("Number.pow(string, 0)", 1, Number.pow("string", 0));
AddTestCase("Number.pow(NaN, 0)", 1, Number.pow(NaN, 0));
AddTestCase("Number.pow(1.2, 0)", 1, Number.pow(1.2, 0));
AddTestCase("Number.pow(NaN, 0) check()", 1, check(NaN, 0));
AddTestCase("Number.pow(1.2, 0) check()", 1, check(1.2, 0));

// If y is -0, the result is 1, even if x is NaN.
AddTestCase("Number.pow(undefined, -0)", 1, Number.pow(undefined, -0));
AddTestCase("Number.pow(string, -0)", 1, Number.pow("string", -0));
AddTestCase("Number.pow(NaN, -0)", 1, Number.pow(NaN, -0));
AddTestCase("Number.pow(1.2, -0)", 1, Number.pow(1.2, -0));
AddTestCase("Number.pow(NaN, -0) check()", 1, check(NaN, -0));
AddTestCase("Number.pow(1.2, -0) check()", 1, check(1.2, -0));

// If x is NaN and y is nonzero, the result is NaN.
AddTestCase("Number.pow(undefined, 1)", NaN, Number.pow(undefined, 1));
AddTestCase("Number.pow(string, 1)", NaN, Number.pow("string", 1));
AddTestCase("Number.pow(NaN, 1)", NaN, Number.pow(NaN, 1));
AddTestCase("Number.pow(NaN, 1) check()", NaN, check(NaN, 1));

// If abs(x)>1 and y is +Infinity, the result is +Infinity.
AddTestCase("Number.pow(1.2, Number.POSITIVE_INFINITY)", Number.POSITIVE_INFINITY, Number.pow(1.2, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(-1.2, Number.POSITIVE_INFINITY)", Number.POSITIVE_INFINITY, Number.pow(-1.2, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(1.2, Number.POSITIVE_INFINITY) check()", Number.POSITIVE_INFINITY, check(1.2, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(-1.2, Number.POSITIVE_INFINITY) check()", Number.POSITIVE_INFINITY, check(-1.2, Number.POSITIVE_INFINITY));

// If abs(x)>1 and y is -Infinity, the result is +0.
AddTestCase("Number.pow(1.2, Number.NEGATIVE_INFINITY)", 0, Number.pow(1.2, Number.NEGATIVE_INFINITY));
AddTestCase("Number.pow(1.2, Number.NEGATIVE_INFINITY) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.pow(1.2, Number.NEGATIVE_INFINITY));
AddTestCase("Number.pow(-1.2, Number.NEGATIVE_INFINITY)", 0, Number.pow(-1.2, Number.NEGATIVE_INFINITY));
AddTestCase("Number.pow(-1.2, Number.NEGATIVE_INFINITY) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.pow(-1.2, Number.NEGATIVE_INFINITY));
AddTestCase("Number.pow(1.2, Number.NEGATIVE_INFINITY) check()", 0, check(1.2, Number.NEGATIVE_INFINITY));
AddTestCase("Number.pow(1.2, Number.NEGATIVE_INFINITY) check() sign check",
            Number.POSITIVE_INFINITY,
            Number.POSITIVE_INFINITY/check(1.2, Number.NEGATIVE_INFINITY));
AddTestCase("Number.pow(-1.2, Number.NEGATIVE_INFINITY) check()", 0, check(-1.2, Number.NEGATIVE_INFINITY));
AddTestCase("Number.pow(-1.2, Number.NEGATIVE_INFINITY) check() sign check",
            Number.POSITIVE_INFINITY,
            Number.POSITIVE_INFINITY/check(-1.2, Number.NEGATIVE_INFINITY));


// If abs(x)==1 and y is +Infinity, the result is NaN.
AddTestCase("Number.pow(1.0, Number.POSITIVE_INFINITY)", Number.NaN, Number.pow(1.0, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(-1.0, Number.POSITIVE_INFINITY)", Number.NaN, Number.pow(-1.0, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(1.0, Number.POSITIVE_INFINITY) check()", Number.NaN, check(1.0, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(-1.0, Number.POSITIVE_INFINITY) check()", Number.NaN, check(-1.0, Number.POSITIVE_INFINITY));

// If abs(x)==1 and y is -Infinity, the result is NaN.
AddTestCase("Number.pow(1.0, Number.NEGATIVE_INFINITY)", Number.NaN, Number.pow(1.0, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(-1.0, Number.NEGATIVE_INFINITY)", Number.NaN, Number.pow(-1.0, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(1.0, Number.NEGATIVE_INFINITY) check()", Number.NaN, check(1.0, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(-1.0, Number.NEGATIVE_INFINITY) check()", Number.NaN, check(-1.0, Number.POSITIVE_INFINITY));

// If abs(x)<1 and y is +Infinity, the result is +0.
AddTestCase("Number.pow(0.2, Number.POSITIVE_INFINITY)", 0, Number.pow(0.2, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(0.2, Number.POSITIVE_INFINITY) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.pow(0.2, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(-0.2, Number.POSITIVE_INFINITY)", 0, Number.pow(-0.2, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(-0.2, Number.POSITIVE_INFINITY) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.pow(-0.2, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(0.2, Number.POSITIVE_INFINITY) check()", 0, check(0.2, Number.POSITIVE_INFINITY));
AddTestCase("Number.pow(0.2, Number.POSITIVE_INFINITY) check() sign check",
            Number.POSITIVE_INFINITY,
            Number.POSITIVE_INFINITY/check(0.2, Number.POSITIVE_INFINITY));

// If abs(x)<1 and y is -Infinity, the result is +Infinity.
AddTestCase("Number.pow(0.2, Number.NEGATIVE_INFINITY)", Number.POSITIVE_INFINITY, Number.pow(0.2, Number.NEGATIVE_INFINITY));
AddTestCase("Number.pow(-0.2, Number.NEGATIVE_INFINITY)", Number.POSITIVE_INFINITY, Number.pow(-0.2, Number.NEGATIVE_INFINITY));
AddTestCase("Number.pow(0.2, Number.NEGATIVE_INFINITY) check()", Number.POSITIVE_INFINITY, check(0.2, Number.NEGATIVE_INFINITY));
AddTestCase("Number.pow(-0.2, Number.NEGATIVE_INFINITY) check()", Number.POSITIVE_INFINITY, check(-0.2, Number.NEGATIVE_INFINITY));

// If x is +Infinity and y>0, the result is +Infinity.
AddTestCase("Number.pow(Number.POSITIVE_INFINITY, 0.1)", Number.POSITIVE_INFINITY, Number.pow(Number.POSITIVE_INFINITY, 0.1));
AddTestCase("Number.pow(Number.POSITIVE_INFINITY, 0.1) check()", Number.POSITIVE_INFINITY, check(Number.POSITIVE_INFINITY, 0.1));

// If x is +Infinity and y<0, the result is +0.
AddTestCase("Number.pow(Number.POSITIVE_INFINITY, -0.1)", 0, Number.pow(Number.POSITIVE_INFINITY, -0.1));
AddTestCase("Number.pow(Number.POSITIVE_INFINITY, -0.1) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.pow(Number.POSITIVE_INFINITY, -0.1));
AddTestCase("Number.pow(Number.POSITIVE_INFINITY, -0.1) check()", 0, check(Number.POSITIVE_INFINITY, -0.1));
AddTestCase("Number.pow(Number.POSITIVE_INFINITY, -0.1) check() sign check",
            Number.POSITIVE_INFINITY,
            Number.POSITIVE_INFINITY/check(Number.POSITIVE_INFINITY, -0.1));

// If x is -Infinity and y>0 and y is an odd integer, the result is -Infinity.
AddTestCase("Number.pow(Number.NEGATIVE_INFINITY, 1)", Number.NEGATIVE_INFINITY, Number.pow(Number.NEGATIVE_INFINITY, 1));
AddTestCase("Number.pow(Number.NEGATIVE_INFINITY, 1) check", Number.NEGATIVE_INFINITY, check(Number.NEGATIVE_INFINITY, 1));

// If x is -Infinity and y>0 and y is not an odd integer, the result is +Infinity.
AddTestCase("Number.pow(Number.NEGATIVE_INFINITY, 2)", Number.POSITIVE_INFINITY, Number.pow(Number.NEGATIVE_INFINITY, 2));
AddTestCase("Number.pow(Number.NEGATIVE_INFINITY, 2) check()", Number.POSITIVE_INFINITY, check(Number.NEGATIVE_INFINITY, 2));

// If x is -Infinity and y<0 and y is an odd integer, the result is -0.
AddTestCase("Number.pow(Number.NEGATIVE_INFINITY, -1)", -0, Number.pow(Number.NEGATIVE_INFINITY, -1));
AddTestCase("Number.pow(Number.NEGATIVE_INFINITY, -1) sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.pow(Number.NEGATIVE_INFINITY, -1));
AddTestCase("Number.pow(Number.NEGATIVE_INFINITY, -1) check()", -0, check(Number.NEGATIVE_INFINITY, -1));
AddTestCase("Number.pow(Number.NEGATIVE_INFINITY, -1) check() sign check",
            Number.NEGATIVE_INFINITY,
            Number.POSITIVE_INFINITY/check(Number.NEGATIVE_INFINITY, -1));

// If x is -Infinity and y<0 and y is not an odd integer, the result is +0.
AddTestCase("Number.pow(Number.NEGATIVE_INFINITY, -2)", 0, Number.pow(Number.NEGATIVE_INFINITY, -2));
AddTestCase("Number.pow(Number.NEGATIVE_INFINITY, -2) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.pow(Number.NEGATIVE_INFINITY, -2));
AddTestCase("Number.pow(Number.NEGATIVE_INFINITY, -2) check()", 0, check(Number.NEGATIVE_INFINITY, -2));
AddTestCase("Number.pow(Number.NEGATIVE_INFINITY, -2) check() sign check",
            Number.POSITIVE_INFINITY,
            Number.POSITIVE_INFINITY/check(Number.NEGATIVE_INFINITY, -2));

// If x is +0 and y>0, the result is +0.
AddTestCase("Number.pow(0, 2)", 0, Number.pow(0, 2));
AddTestCase("Number.pow(0, 2) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.pow(0, 2));
AddTestCase("Number.pow(0, 2) check()", 0, check(0, 2));
AddTestCase("Number.pow(0, 2) check() sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(0, 2));

// If x is +0 and y<0, the result is +Infinity.
AddTestCase("Number.pow(0, -2)", Number.POSITIVE_INFINITY, Number.pow(0, -2));
AddTestCase("Number.pow(0, -2) check()", Number.POSITIVE_INFINITY, check(0, -2));

// If x is -0 and y>0 and y is an odd integer, the result is -0.
AddTestCase("Number.pow(-0, 1)", -0, Number.pow(-0, 1));
AddTestCase("Number.pow(-0, 1) sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.pow(-0, 1));
AddTestCase("Number.pow(-0, 1) check()", -0, check(-0, 1));
AddTestCase("Number.pow(-0, 1) chec() sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0, 1));

// If x is -0 and y>0 and y is not an odd integer, the result is +0.
AddTestCase("Number.pow(-0, 2)", 0, Number.pow(-0, 2));
AddTestCase("Number.pow(-0, 2) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.pow(-0, 2));
AddTestCase("Number.pow(-0, 2) check()", 0, check(-0, 2));
AddTestCase("Number.pow(-0, 2) check() sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0, 2));

// If x is -0 and y<0 and y is an odd integer, the result is -Infinity.
AddTestCase("Number.pow(-0, -1)", Number.NEGATIVE_INFINITY, Number.pow(-0, -1));
AddTestCase("Number.pow(-0, -1) check()", Number.NEGATIVE_INFINITY, check(-0, -1));

// If x is -0 and y<0 and y is not an odd integer, the result is +Infinity.
AddTestCase("Number.pow(-0, -2)", Number.POSITIVE_INFINITY, Number.pow(-0, -2));
AddTestCase("Number.pow(-0, -2) check()", Number.POSITIVE_INFINITY, check(-0, -2));

// If x<0 and x is finite and y is finite and y is not an integer, the result is NaN.
AddTestCase("Number.pow(-1.125, 2.1)", NaN, Number.pow(-1.125, 2.1));
AddTestCase("Number.pow(-1.125, 2.1) check()", NaN, check(-1.125, 2.1));


var param1:Number = 3.14159265;
var param2:Number = 0.000001;
AddTestCase("Number.pow(3.14159265, 0.000001)", 1.0000011920928955, Number.pow(param1, param2));
AddTestCase("Number.pow(3.14159265, 0.000001) NumberLiteral", 1.0000011920928955, Number.pow(3.14159265, 0.000001));


test();

