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
Returns reciprocal square root of scalars.
Testmedia based on edge points in float.sqrt().
*/

var SECTION = "4.5.31";
var VERSION = "AS3";
var TITLE   = "public function rsqrt(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:float):float { return float.rsqrt(param); }

AddStrictTestCase("float.rsqrt() returns a float", "float", getQualifiedClassName(float.rsqrt(12.345f)));
AddStrictTestCase("float.rsqrt() length is 1", 1, float.rsqrt.length);

// If x is NaN, the result is NaN. (1/NaN == NaN)
AddStrictTestCase("float.rsqrt(undefined)", float.NaN, float.rsqrt(undefined));
AddStrictTestCase("float.rsqrt(float.NaN)", float.NaN, float.rsqrt(float.NaN));
AddStrictTestCase("float.rsqrt(float.NaN) check()", float.NaN, check(float.NaN));

// If x is less than 0, the result is NaN. (1/NaN == NaN)
AddStrictTestCase("float.rsqrt(-1.125f)", float.NaN, float.rsqrt(-1.125f));
AddStrictTestCase("float.rsqrt(-1.125f) check()", float.NaN, check(-1.125f));
AddStrictTestCase("float.rsqrt(float.NEGATIVE_INFINITY)", float.NaN, float.rsqrt(float.NEGATIVE_INFINITY));
AddStrictTestCase("float.rsqrt(float.NEGATIVE_INFINITY) check()", float.NaN, check(float.NEGATIVE_INFINITY));

// If x is +0, the result is +0. (1/0 == Infinity)
AddStrictTestCase("float.rsqrt(0f)", float.POSITIVE_INFINITY, float.rsqrt(0f));
AddStrictTestCase("float.rsqrt(0f) check()", float.POSITIVE_INFINITY, check(0f));
AddStrictTestCase("float.rsqrt(null)", float.POSITIVE_INFINITY, float.rsqrt(null));

// If x is -0, the result is -0. (1/-0 == -Infinity)
AddStrictTestCase("float.rsqrt(-0f)", float.NEGATIVE_INFINITY, float.rsqrt(-0f));
AddStrictTestCase("float.rsqrt(-0f) check()", float.NEGATIVE_INFINITY, check(-0f));

// If x is +Infinity, the result is +Infinity. (1/Infinity == 0)
AddStrictTestCase("float.rsqrt(float.POSITIVE_INFINITY)", 0f, float.rsqrt(float.POSITIVE_INFINITY));
AddStrictTestCase("float.rsqrt(float.POSITIVE_INFINITY) check()", 0f, check(float.POSITIVE_INFINITY));
AddStrictTestCase("float.rsqrt(float.POSITIVE_INFINITY) sign check",
                  float.POSITIVE_INFINITY,
                  float.POSITIVE_INFINITY/float.rsqrt(float.POSITIVE_INFINITY));
AddStrictTestCase("float.rsqrt(float.POSITIVE_INFINITY) check() sign check",
                  float.POSITIVE_INFINITY,
                  float.POSITIVE_INFINITY/check(float.POSITIVE_INFINITY));


// float.rsqrt(x) == 1f/float.sqrt(x)
var x:float = 3.124f;
AddStrictTestCase("x=3.124f float.rsqrt(x) == 1f/float.sqrt(x)", 1f/float.sqrt(x), float.rsqrt(x));

AddStrictTestCase("float.rsqrt(64)", float(0.125), float.rsqrt(64));

test();

