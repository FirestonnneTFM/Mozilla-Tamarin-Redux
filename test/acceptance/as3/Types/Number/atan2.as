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
Returns an implementation-dependent approximation to the arc tangent of the
quotient y/x of the arguments y and x, where the signs of y and x are used to
determine the quadrant of the result. Note that it is intentional and traditional
for the two-argument arc tangent function that the argument named y be first and
the argument named x be second. The result is expressed in radians and ranges
from -PI to +PI.
*/

import avmplus.*;

var SECTION = "15.8.2.5";
var VERSION = "AS3";
var TITLE   = "public native static function atan2 (y:Number, x:Number):Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param1:Number, param2:Number):Number { return Number.atan2(param1, param2); }

AddTestCase("Number.atan2() returns a Number", "Number", getQualifiedClassName(Number.atan2(1,0.5)));
AddTestCase("Number.atan2() length is 2", 2, Number.atan2.length);
AddErrorTest("Number.atan2() with no args", ARGUMENTERROR+1063,  function(){ Number.atan2(); });
AddErrorTest("Number.atan2(0) with one args", ARGUMENTERROR+1063,  function(){ Number.atan2(0); });

// If either x or y is NaN, the result is NaN.
AddTestCase("Number.atan2(0, undefined)", NaN, Number.atan2(0, undefined));
AddTestCase("Number.atan2(undefined, 0)", NaN, Number.atan2(undefined, 0));
AddTestCase("Number.atan2(0, string)", NaN, Number.atan2(0, "string"));
AddTestCase("Number.atan2(string, 0)", NaN, Number.atan2("string", 0));
AddTestCase("Number.atan2(1, NaN)", NaN, Number.atan2(1, NaN));
AddTestCase("Number.atan2(NaN, 1)", NaN, Number.atan2(NaN, 1));
AddTestCase("Number.atan2(1, NaN) check()", NaN, check(1, NaN));
AddTestCase("Number.atan2(NaN, 1) check()", NaN, check(NaN, 1));

// If y>0 and x is +0, the result is an implementation-dependent approximation to +PI/2.
AddTestCase("Number.atan2(1, 0)", Number.PI/2, Number.atan2(1, 0));
AddTestCase("Number.atan2(1, 0) check", Number.PI/2, check(1, 0));
AddTestCase("Number.atan2('1', '0')", Number.PI/2, Number.atan2('1', '0'));

// If y>0 and x is -0, the result is an implementation-dependent approximation to +PI/2.
AddTestCase("Number.atan2(1, -0)", Number.PI/2, Number.atan2(1, -0));
AddTestCase("Number.atan2(1, -0) check", Number.PI/2, check(1, -0));
AddTestCase("Number.atan2('1', '-0')", Number.PI/2, Number.atan2('1', '-0'));

// If y is +0 and x>0, the result is +0.
AddTestCase("Number.atan2(0, 1)", 0, Number.atan2(0, 1));
AddTestCase("Number.atan2(0, 1) check via Infinity", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.atan2(0, 1));
AddTestCase("Number.atan2(0, 1) check()", 0, check(0, 1));
AddTestCase("Number.atan2(0, 1) check() check via Infinity", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(0, 1));

// If y is +0 and x is +0, the result is +0.
AddTestCase("Number.atan2(0, 0)", 0, Number.atan2(0, 0));
AddTestCase("Number.atan2(0, 0) check via Infinity", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.atan2(0, 0));
AddTestCase("Number.atan2(0, 0) check()", 0, check(0, 0));
AddTestCase("Number.atan2(0, 0) check() check via Infinity", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(0, 0));

// If y is +0 and x is -0, the result is an implementation-dependent approximation to +PI.
AddTestCase("Number.atan2(0, -0)", Number.PI, Number.atan2(0, -0));
AddTestCase("Number.atan2(0, -0) check()", Number.PI, check(0, -0));

// If y is +0 and x<0, the result is an implementation-dependent approximation to +PI.
AddTestCase("Number.atan2(0, -0.1)", Number.PI, Number.atan2(0, -0.1));
AddTestCase("Number.atan2(0, -0.1) check()", Number.PI, check(0, -0.1));

// If y is -0 and x>0, the result is -0.
AddTestCase("Number.atan2(-0, 0.1)", -0, Number.atan2(-0, 0.1));
AddTestCase("Number.atan2(-0, 0.1) check via Infinity", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.atan2(-0, 0.1));
AddTestCase("Number.atan2(-0, 0.1) check()", -0, check(-0, 0.1));
AddTestCase("Number.atan2(-0, 0.1) check() check via Infinity", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0, 0.1));

// If y is -0 and x is +0, the result is -0.
AddTestCase("Number.atan2(-0, 0)", -0, Number.atan2(-0, 0));
AddTestCase("Number.atan2(-0, 0) check via Infinity", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.atan2(-0, 0));
AddTestCase("Number.atan2(-0, 0) check()", -0, check(-0, 0));
AddTestCase("Number.atan2(-0, 0) check() check via Infinity", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0, 0));

// If y is -0 and x is -0, the result is an implementation-dependent approximation to -PI.
AddTestCase("Number.atan2(-0, -0)", -Number.PI, Number.atan2(-0, -0));
AddTestCase("Number.atan2(-0, -0) cehck()", -Number.PI, check(-0, -0));

// If y is -0 and x<0, the result is an implementation-dependent approximation to -PI.
AddTestCase("Number.atan2(-0, -0.1)", -Number.PI, Number.atan2(-0, -0.1));
AddTestCase("Number.atan2(-0, -0.1) check()", -Number.PI, check(-0, -0.1));

// If y<0 and x is +0, the result is an implementation-dependent approximation to -PI/2.
AddTestCase("Number.atan2(-0.1, 0)", -Number.PI/2, Number.atan2(-0.1, 0));
AddTestCase("Number.atan2(-0.1, 0) check()", -Number.PI/2, check(-0.1, 0));

// If y<0 and x is -0, the result is an implementation-dependent approximation to -PI/2.
AddTestCase("Number.atan2(-0.1, -0)", -Number.PI/2, Number.atan2(-0.1, -0));
AddTestCase("Number.atan2(-0.1, -0) check()", -Number.PI/2, check(-0.1, -0));

// If y>0 and y is finite and x is +Infinity, the result is +0.
AddTestCase("Number.atan2(0.1, Number.POSITIVE_INFINITY)", 0, Number.atan2(0.1, Number.POSITIVE_INFINITY));
AddTestCase("Number.atan2(0.1, Number.POSITIVE_INFINITY) check via Infinity",
            Number.POSITIVE_INFINITY,
            Number.POSITIVE_INFINITY/Number.atan2(0.1, Number.POSITIVE_INFINITY));
AddTestCase("Number.atan2(0.1, Number.POSITIVE_INFINITY) check()", 0, check(0.1, Number.POSITIVE_INFINITY));
AddTestCase("Number.atan2(0.1, Number.POSITIVE_INFINITY) check() check via Infinity",
            Number.POSITIVE_INFINITY,
            Number.POSITIVE_INFINITY/check(0.1, Number.POSITIVE_INFINITY));


// If y>0 and y is finite and x is -Infinity, the result if an implementation-dependent approximation to +PI.
AddTestCase("Number.atan2(0.1, Number.NEGATIVE_INFINITY)", Number.PI, Number.atan2(0.1, Number.NEGATIVE_INFINITY));
AddTestCase("Number.atan2(0.1, Number.NEGATIVE_INFINITY) check()", Number.PI, check(0.1, Number.NEGATIVE_INFINITY));

// If y<0 and y is finite and x is +Infinity, the result is -0.
AddTestCase("Number.atan2(-0.1, Number.POSITIVE_INFINITY)", -0, Number.atan2(0.1, Number.POSITIVE_INFINITY));
AddTestCase("Number.atan2(-0.1, Number.POSITIVE_INFINITY) check via Infinity",
            Number.NEGATIVE_INFINITY,
            Number.POSITIVE_INFINITY/Number.atan2(-0.1, Number.POSITIVE_INFINITY));
AddTestCase("Number.atan2(-0.1, Number.POSITIVE_INFINITY) check()", -0, check(0.1, Number.POSITIVE_INFINITY));
AddTestCase("Number.atan2(-0.1, Number.POSITIVE_INFINITY) check() check via Infinity",
            Number.NEGATIVE_INFINITY,
            Number.POSITIVE_INFINITY/check(-0.1, Number.POSITIVE_INFINITY));

// If y<0 and y is finite and x is -Infinity, the result is an implementation-dependent approximation to -PI.
AddTestCase("Number.atan2(-0.1, Number.NEGATIVE_INFINITY)", -Number.PI, Number.atan2(-0.1, Number.NEGATIVE_INFINITY));
AddTestCase("Number.atan2(-0.1, Number.NEGATIVE_INFINITY) check()", -Number.PI, check(-0.1, Number.NEGATIVE_INFINITY));

// If y is +Infinity and x is finite, the result is an implementation-dependent approximation to +PI/2.
AddTestCase("Number.atan2(Number.POSITIVE_INFINITY, 0)", Number.PI/2, Number.atan2(Number.POSITIVE_INFINITY, 0));
AddTestCase("Number.atan2(Number.POSITIVE_INFINITY, 0) check()", Number.PI/2, check(Number.POSITIVE_INFINITY, 0));

// If y is -Infinity and x is finite, the result is an implementation-dependent approximation to -PI/2.
AddTestCase("Number.atan2(Number.NEGATIVE_INFINITY, 0)", -Number.PI/2, Number.atan2(Number.NEGATIVE_INFINITY, 0));
AddTestCase("Number.atan2(Number.NEGATIVE_INFINITY, 0) check()", -Number.PI/2, check(Number.NEGATIVE_INFINITY, 0));

// If y is +Infinity and x is +Infinity, the result is an implementation-dependent approximation to +PI/4.
AddTestCase("Number.atan2(Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY)", Number.PI/4, Number.atan2(Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY));
AddTestCase("Number.atan2(Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY) check()", Number.PI/4, check(Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY));

// If y is +Infinity and x is -Infinity, the result is an implementation-dependent approximation to +3PI/4.
AddTestCase("Number.atan2(Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY)", 3*Number.PI/4, Number.atan2(Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY));
AddTestCase("Number.atan2(Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY) check()", 3*Number.PI/4, check(Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY));

// If y is -Infinity and x is +Infinity, the result is an implementation-dependent approximation to -PI/4.
AddTestCase("Number.atan2(Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY)", -Number.PI/4, Number.atan2(Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY));
AddTestCase("Number.atan2(Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY) check()", -Number.PI/4, check(Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY));

// If y is -Infinity and x is -Infinity, the result is an implementation-dependent approximation to -3PI/4.
AddTestCase("Number.atan2(Number.NEGATIVE_INFINITY, Number.NEGATIVE_INFINITY)", -3*Number.PI/4, Number.atan2(Number.NEGATIVE_INFINITY, Number.NEGATIVE_INFINITY));
AddTestCase("Number.atan2(Number.NEGATIVE_INFINITY, Number.NEGATIVE_INFINITY) check()", -3*Number.PI/4, check(Number.NEGATIVE_INFINITY, Number.NEGATIVE_INFINITY));

test();

