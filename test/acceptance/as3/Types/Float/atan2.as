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

var SECTION = "4.5.19";
var VERSION = "AS3";
var TITLE   = "public function atan2(y:float,x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param1:float, param2:float):float { return float.atan2(param1, param2); }

AddStrictTestCase("float.atan2() returns a float", "float", getQualifiedClassName(float.atan2(0f,0f)));
AddStrictTestCase("float.atan2() length is 2", 2, float.atan2.length);

// If either x or y is NaN, the result is NaN.
AddStrictTestCase("float.atan2(0f, undefined)", float.NaN, float.atan2(0f, undefined));
AddStrictTestCase("float.atan2(undefined, 0f)", float.NaN, float.atan2(undefined, 0f));
AddStrictTestCase("float.atan2(1f, float.NaN)", float.NaN, float.atan2(1f, float.NaN));
AddStrictTestCase("float.atan2(float.NaN, 1f)", float.NaN, float.atan2(float.NaN, 1f));
AddStrictTestCase("float.atan2(1f, float.NaN) check()", float.NaN, check(1f, float.NaN));
AddStrictTestCase("float.atan2(float.NaN, 1f) check()", float.NaN, check(float.NaN, 1f));

// If y>0 and x is +0, the result is an implementation-dependent approximation to +PI/2.
AddStrictTestCase("float.atan2(1f, 0f)", float.PI/2f, float.atan2(1f, 0f));
AddStrictTestCase("float.atan2(1f, 0f) check", float.PI/2f, check(1f, 0f));

// If y>0 and x is -0, the result is an implementation-dependent approximation to +PI/2.
AddStrictTestCase("float.atan2(1f, -0f)", float.PI/2f, float.atan2(1f, -0f));
AddStrictTestCase("float.atan2(1f, -0f) check", float.PI/2f, check(1f, -0f));

// If y is +0 and x>0, the result is +0.
AddTestCase("float.atan2(0f, 1f)", 0f, float.atan2(0f, 1f));
AddTestCase("float.atan2(0f, 1f) check via Infinity", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.atan2(0f, 1f));
AddTestCase("float.atan2(0f, 1f) check()", 0f, check(0f, 1f));
AddTestCase("float.atan2(0f, 1f) check() check via Infinity", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/check(0f, 1f));

// If y is +0 and x is +0, the result is +0.
AddStrictTestCase("float.atan2(0f, 0f)", 0f, float.atan2(0f, 0f));
AddStrictTestCase("float.atan2(0f, 0f) check via Infinity", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.atan2(0f, 0f));
AddStrictTestCase("float.atan2(0f, 0f) check()", 0f, check(0f, 0f));
AddStrictTestCase("float.atan2(0f, 0f) check() check via Infinity", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/check(0f, 0f));

// If y is +0 and x is -0, the result is an implementation-dependent approximation to +PI.
AddStrictTestCase("float.atan2(0f, -0f)", float.PI, float.atan2(0f, -0f));
AddStrictTestCase("float.atan2(0f, -0f) check()", float.PI, check(0f, -0f));

// If y is +0 and x<0, the result is an implementation-dependent approximation to +PI.
AddStrictTestCase("float.atan2(0f, -0.1f)", float.PI, float.atan2(0f, -0.1f));
AddStrictTestCase("float.atan2(0f, -0.1f) check()", float.PI, check(0f, -0.1f));

// If y is -0 and x>0, the result is -0.
AddStrictTestCase("float.atan2(-0f, 0.1f)", -0f, float.atan2(-0f, 0.1f));
AddStrictTestCase("float.atan2(-0f, 0.1f) check via Infinity", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.atan2(-0f, 0.1f));
AddStrictTestCase("float.atan2(-0f, 0.1f) check()", -0f, check(-0f, 0.1f));
AddStrictTestCase("float.atan2(-0f, 0.1f) check() check via Infinity", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/check(-0f, 0.1f));

// If y is -0 and x is +0, the result is -0.
AddStrictTestCase("float.atan2(-0f, 0f)", -0f, float.atan2(-0f, 0f));
AddStrictTestCase("float.atan2(-0f, 0f) check via Infinity", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.atan2(-0f, 0f));
AddStrictTestCase("float.atan2(-0f, 0f) check()", -0f, check(-0f, 0f));
AddStrictTestCase("float.atan2(-0f, 0f) check() check via Infinity", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/check(-0f, 0f));

// If y is -0 and x is -0, the result is an implementation-dependent approximation to -PI.
AddStrictTestCase("float.atan2(-0f, -0f)", -float.PI, float.atan2(-0f, -0f));
AddStrictTestCase("float.atan2(-0f, -0f) cehck()", -float.PI, check(-0f, -0f));

// If y is -0 and x<0, the result is an implementation-dependent approximation to -PI.
AddStrictTestCase("float.atan2(-0f, -0.1f)", -float.PI, float.atan2(-0f, -0.1f));
AddStrictTestCase("float.atan2(-0f, -0.1f) check()", -float.PI, check(-0f, -0.1f));

// If y<0 and x is +0, the result is an implementation-dependent approximation to -PI/2.
AddStrictTestCase("float.atan2(-0.1f, 0f)", -float.PI/2f, float.atan2(-0.1f, 0f));
AddStrictTestCase("float.atan2(-0.1f, 0f) check()", -float.PI/2f, check(-0.1f, 0f));

// If y<0 and x is -0, the result is an implementation-dependent approximation to -PI/2.
AddStrictTestCase("float.atan2(-0.1f, -0f)", -float.PI/2f, float.atan2(-0.1f, -0f));
AddStrictTestCase("float.atan2(-0.1f, -0f) check()", -float.PI/2f, check(-0.1f, -0f));

// If y>0 and y is finite and x is +Infinity, the result is +0.
AddStrictTestCase("float.atan2(0.1f, float.POSITIVE_INFINITY)", 0f, float.atan2(0.1f, float.POSITIVE_INFINITY));
AddStrictTestCase("float.atan2(0.1f, float.POSITIVE_INFINITY) check via Infinity",
                  float.POSITIVE_INFINITY,
                  float.POSITIVE_INFINITY/float.atan2(0.1f, float.POSITIVE_INFINITY));
AddStrictTestCase("float.atan2(0.1f, float.POSITIVE_INFINITY) check()", 0f, check(0.1f, float.POSITIVE_INFINITY));
AddStrictTestCase("float.atan2(0.1f, float.POSITIVE_INFINITY) check() check via Infinity",
                  float.POSITIVE_INFINITY,
                  float.POSITIVE_INFINITY/check(0.1f, float.POSITIVE_INFINITY));


// If y>0 and y is finite and x is -Infinity, the result if an implementation-dependent approximation to +PI.
AddStrictTestCase("float.atan2(0.1f, float.NEGATIVE_INFINITY)", float.PI, float.atan2(0.1f, float.NEGATIVE_INFINITY));
AddStrictTestCase("float.atan2(0.1f, float.NEGATIVE_INFINITY) check()", float.PI, check(0.1f, float.NEGATIVE_INFINITY));

// If y<0 and y is finite and x is +Infinity, the result is -0.
AddStrictTestCase("float.atan2(-0.1f, float.POSITIVE_INFINITY)", -0f, float.atan2(0.1f, float.POSITIVE_INFINITY));
AddStrictTestCase("float.atan2(-0.1float, float.POSITIVE_INFINITY) check via Infinity",
                  float.NEGATIVE_INFINITY,
                  float.POSITIVE_INFINITY/float.atan2(-0.1f, float.POSITIVE_INFINITY));
AddStrictTestCase("float.atan2(-0.1f, float.POSITIVE_INFINITY) check()", -0f, check(0.1f, float.POSITIVE_INFINITY));
AddStrictTestCase("float.atan2(-0.1f, float.POSITIVE_INFINITY) check() check via Infinity",
                  float.NEGATIVE_INFINITY,
                  float.POSITIVE_INFINITY/check(-0.1f, float.POSITIVE_INFINITY));

// If y<0 and y is finite and x is -Infinity, the result is an implementation-dependent approximation to -PI.
AddStrictTestCase("float.atan2(-0.1f, float.NEGATIVE_INFINITY)", -float.PI, float.atan2(-0.1f, float.NEGATIVE_INFINITY));
AddStrictTestCase("float.atan2(-0.1f, float.NEGATIVE_INFINITY) check()", -float.PI, check(-0.1f, float.NEGATIVE_INFINITY));

// If y is +Infinity and x is finite, the result is an implementation-dependent approximation to +PI/2.
AddStrictTestCase("float.atan2(float.POSITIVE_INFINITY, 0f)", float.PI/2f, float.atan2(float.POSITIVE_INFINITY, 0f));
AddStrictTestCase("float.atan2(float.POSITIVE_INFINITY, 0f) check()", float.PI/2f, check(float.POSITIVE_INFINITY, 0f));

// If y is -Infinity and x is finite, the result is an implementation-dependent approximation to -PI/2.
AddStrictTestCase("float.atan2(float.NEGATIVE_INFINITY, 0f)", -float.PI/2f, float.atan2(float.NEGATIVE_INFINITY, 0f));
AddStrictTestCase("float.atan2(float.NEGATIVE_INFINITY, 0f) check()", -float.PI/2f, check(float.NEGATIVE_INFINITY, 0f));

// If y is +Infinity and x is +Infinity, the result is an implementation-dependent approximation to +PI/4.
AddStrictTestCase("float.atan2(float.POSITIVE_INFINITY, float.POSITIVE_INFINITY)", float.PI/4f, float.atan2(float.POSITIVE_INFINITY, float.POSITIVE_INFINITY));
AddStrictTestCase("float.atan2(float.POSITIVE_INFINITY, float.POSITIVE_INFINITY) check()", float.PI/4f, check(float.POSITIVE_INFINITY, float.POSITIVE_INFINITY));

// If y is +Infinity and x is -Infinity, the result is an implementation-dependent approximation to +3PI/4.
AddStrictTestCase("float.atan2(float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY)", 3f*float.PI/4f, float.atan2(float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY));
AddStrictTestCase("float.atan2(float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY) check()", 3f*float.PI/4f, check(float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY));

// If y is -Infinity and x is +Infinity, the result is an implementation-dependent approximation to -PI/4.
AddStrictTestCase("float.atan2(float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY)", -float.PI/4f, float.atan2(float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY));
AddStrictTestCase("float.atan2(float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY) check()", -float.PI/4f, check(float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY));

// If y is -Infinity and x is -Infinity, the result is an implementation-dependent approximation to -3PI/4.
AddStrictTestCase("float.atan2(float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY)", -3f*float.PI/4f, float.atan2(float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY));
AddStrictTestCase("float.atan2(float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY) check()", -3f*float.PI/4f, check(float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY));

test();

