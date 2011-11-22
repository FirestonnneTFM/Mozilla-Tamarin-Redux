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
Given zero or more arguments, calls ToNumber on each of the arguments and
returns the largest of the resulting values.
*/

import avmplus.*;

var SECTION = "15.8.2.11";
var VERSION = "AS3";
var TITLE   = "public native static function max (x:Number = NEGATIVE_INFINITY, y:Number = NEGATIVE_INFINITY, ... rest):Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function checkEmpty():Number { return Number.max(); }


AddTestCase("Number.max() returns a Number", "Number", getQualifiedClassName(Number.max(1.25)));
AddTestCase("Number.max() length is 2", 2, Number.max.length);

// If no arguments are given, the result is -Infinity.
AddTestCase("Number.max()", Number.NEGATIVE_INFINITY, Number.max());
AddTestCase("Number.max() checkEmpty()", Number.NEGATIVE_INFINITY, checkEmpty());

// If any value is NaN, the result is NaN.
// undefined, "String", Number.NaN in first, second and in rest args should return Number.NaN
AddTestCase("Number.max(undefined, 2.1, 3.2)", NaN, Number.max(undefined, 2.1, 3.2));
AddTestCase("Number.max(2.1, undefined, 3.2)", NaN, Number.max(2.1, undefined, 3.2));
AddTestCase("Number.max(2.1, 3.2, undefined)", NaN, Number.max(2.1, 3.2, undefined));

AddTestCase("Number.max('string', 2.1, 3.2)", NaN, Number.max('string', 2.1, 3.2));
AddTestCase("Number.max(2.1, 'string', 3.2)", NaN, Number.max(2.1, 'string', 3.2));
AddTestCase("Number.max(2.1, 3.2, 'string')", NaN, Number.max(2.1, 3.2, 'string'));

AddTestCase("Number.max(Number.NaN, 2.1, 3.2)", NaN, Number.max(Number.NaN, 2.1, 3.2));
AddTestCase("Number.max(2.1, Number.NaN, 3.2)", NaN, Number.max(2.1, Number.NaN, 3.2));
AddTestCase("Number.max(2.1, 3.2, Number.NaN)", NaN, Number.max(2.1, 3.2, Number.NaN));

// The comparison of values to determine the largest value is done as in 11.8.5 except that +0 is considered to be larger than -0.
AddTestCase("Number.max(1, 1)", 1, Number.max(1, 1));
AddTestCase("Number.max(1, 0)", 1, Number.max(1, 0));
AddTestCase("Number.max(0, 1)", 1, Number.max(0, 1));
AddTestCase("Number.max(1, 1, 1)", 1, Number.max(1, 1, 1));
AddTestCase("Number.max(1, 0, 0)", 1, Number.max(1, 0, 0));
AddTestCase("Number.max(0, 1, 0)", 1, Number.max(0, 1, 0));
AddTestCase("Number.max(0, 0, 1)", 1, Number.max(0, 0, 1));
AddTestCase("Number.max(1, 1, 0)", 1, Number.max(1, 1, 0));
AddTestCase("Number.max(1, 0, 1)", 1, Number.max(1, 0, 1));
AddTestCase("Number.max(0, 1, 1)", 1, Number.max(0, 1, 1));

/*
Do the following combinations, treating 1=0 and 0=-0. This will check that handling -0 is correct
for both x and y, PLUS that the rest args are checked properly.
    1, 1
    0, 0
    1, 0
    0, 1
    1, 1, 1
    0, 0, 0
    1, 0, 0
    0, 1, 0
    0, 0, 1
    1, 1, 0
    1, 0, 1
    0, 1, 1
*/
// The comparison of values to determine the largest value is done as in 11.8.5 except that +0 is considered to be larger than -0.
function isPositive(param:Number):Boolean
{
    return Number.POSITIVE_INFINITY/param == Number.POSITIVE_INFINITY;
}
AddTestCase("Number.max( 0,  0)", 0, Number.max(0, 0));
AddTestCase("Number.max( 0,  0) check sign", true, isPositive(Number.max(0, 0)));
AddTestCase("Number.max(-0, -0)", -0, Number.max(-0, -0));
AddTestCase("Number.max(-0, -0) check sign", false, isPositive(Number.max(-0, -0)));
AddTestCase("Number.max( 0, -0)", 0, Number.max(0, -0));
AddTestCase("Number.max( 0, -0) check sign", true, isPositive(Number.max(0, -0)));
AddTestCase("Number.max(-0,  0)", 0, Number.max(-0, 0));
AddTestCase("Number.max(-0,  0) check sign", true, isPositive(Number.max(-0, 0)));
AddTestCase("Number.max( 0,  0,  0)", 0, Number.max(0, 0, 0));
AddTestCase("Number.max( 0,  0,  0) check sign", true, isPositive(Number.max(0, 0, 0)));
AddTestCase("Number.max(-0, -0, -0)", -0, Number.max(-0, -0, -0));
AddTestCase("Number.max(-0, -0, -0) check sign", false, isPositive(Number.max(-0, -0, -0)));
AddTestCase("Number.max( 0, -0, -0)", 0, Number.max(0, -0, -0));
AddTestCase("Number.max( 0, -0, -0) check sign", true, isPositive(Number.max(0, -0, -0)));
AddTestCase("Number.max(-0,  0, -0)", 0, Number.max(-0, 0, -0));
AddTestCase("Number.max(-0,  0, -0) check sign", true, isPositive(Number.max(-0, 0, -0)));
AddTestCase("Number.max(-0, -0,  0)", 0, Number.max(-0, -0, 0));
AddTestCase("Number.max(-0, -0,  0) check sign", true, isPositive(Number.max(-0, -0, 0)));
AddTestCase("Number.max( 0,  0, -0)", 0, Number.max(0, 0, -0));
AddTestCase("Number.max( 0,  0, -0) check sign", true, isPositive(Number.max(0, 0, -0)));
AddTestCase("Number.max( 0, -0,  0)", 0, Number.max(0, -0, 0));
AddTestCase("Number.max( 0, -0,  0) check sign", true, isPositive(Number.max(0, -0, 0)));
AddTestCase("Number.max(-0,  0,  0)", 0, Number.max(-0, 0, 0));
AddTestCase("Number.max(-0,  0,  0) check sign", true, isPositive(Number.max(-0, 0, 0)));


AddTestCase("Number.max(null, 1)", 1, Number.max(null, 1));
AddTestCase("Number.max(-1, null)", 0, Number.max(-1, null));
AddTestCase("Number.max(false, true)", 1, Number.max(false, true));


AddTestCase("Number.max(Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY)", Number.POSITIVE_INFINITY, Number.max(Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY));
AddTestCase("Number.max(Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY)", Number.POSITIVE_INFINITY, Number.max(Number.POSITIVE_INFINITY, Number.NEGATIVE_INFINITY));
AddTestCase("Number.max(Number.MIN_VALUE, 0)", Number.MIN_VALUE, Number.max(Number.MIN_VALUE, 0));

AddTestCase("Number.max(Number.POSITIVE_INFINITY, Number.MAX_VALUE)", Number.POSITIVE_INFINITY, Number.max(Number.POSITIVE_INFINITY, Number.MAX_VALUE));

test();

