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
Returns the absolute value of x; the result has the same magnitude as x but has positive sign.
*/

var SECTION = "4.5.15";
var VERSION = "AS3";
var TITLE   = "public function abs(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:float):float { return float.abs(param); }

AddStrictTestCase("float.abs() returns a float", "float", getQualifiedClassName(float.abs(0)));
AddStrictTestCase("float.abs() length is 1", 1, float.abs.length);


// If x is NaN, the result is NaN.
AddStrictTestCase("float.abs(float.NaN)", float.NaN, float.abs(float.NaN));
AddStrictTestCase("float.abs(flaot.NaN) check()", float.NaN, check(float.NaN));

// If x is -0, the result is +0.
AddStrictTestCase("float.abs(0.0f)", 0f, float.abs(0.0f));
AddStrictTestCase("float.POSITIVE_INFINITY/float.abs(0.0f)", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.abs(0.0f));
AddStrictTestCase("float.abs(-0.0f)", 0f, float.abs(-0.0f));
AddStrictTestCase("float.POSITIVE_INFINITY/float.abs(-0.0f)", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.abs(-0.0f));
AddStrictTestCase("float.POSITIVE_INFINITY/check(-0.0f)", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/check(-0.0f));

// If x is -Infinity, the result is +Infinity.
AddStrictTestCase("float.abs(float.NEGATIVE_INFINITY)", float.POSITIVE_INFINITY, float.abs(float.NEGATIVE_INFINITY));
AddStrictTestCase("float.abs(float.POSITIVE_INFINITY)", float.POSITIVE_INFINITY, float.abs(float.POSITIVE_INFINITY));
AddStrictTestCase("float.abs(float.NEGATIVE_INFINITY) check()", float.POSITIVE_INFINITY, check(float.NEGATIVE_INFINITY));
AddStrictTestCase("float.abs(float.POSITIVE_INFINITY) check()", float.POSITIVE_INFINITY, check(float.POSITIVE_INFINITY));

var pi = 3.14f;
AddStrictTestCase("float.abs(-FloatLiteral)", pi, float.abs(-pi));
AddStrictTestCase("float.abs(FloatLiteral)", pi, float.abs(pi));
AddStrictTestCase("float.abs(-FloatLiteral) check()", pi, check(-pi));
AddStrictTestCase("float.abs(FloatLiteral) check()", pi, check(pi));
var pif:float = 3.14f;
AddStrictTestCase("float.abs(-typed)", pif, float.abs(-pif));
AddStrictTestCase("float.abs(typed)", pif, float.abs(pif));
AddStrictTestCase("float.abs(-typed) check()", pif, check(-pif));
AddStrictTestCase("float.abs(typed) check()", pif, check(pif));

AddStrictTestCase("float.abs(null)", 0f, float.abs(null));

AddStrictTestCase("float.abs(-float.MIN_VALUE)", float.MIN_VALUE, float.abs(-float.MIN_VALUE));
AddStrictTestCase("float.abs(-float.MAX_VALUE)", float.MAX_VALUE, float.abs(-float.MAX_VALUE));
AddStrictTestCase("float.abs(float.MIN_VALUE)", float.MIN_VALUE, float.abs(float.MIN_VALUE));
AddStrictTestCase("float.abs(float.MAX_VALUE)", float.MAX_VALUE, float.abs(float.MAX_VALUE));
AddStrictTestCase("float.abs(-float.MIN_VALUE) check()", float.MIN_VALUE, check(-float.MIN_VALUE));
AddStrictTestCase("float.abs(-float.MAX_VALUE) check()", float.MAX_VALUE, check(-float.MAX_VALUE));
AddStrictTestCase("float.abs(float.MIN_VALUE) check()", float.MIN_VALUE, check(float.MIN_VALUE));
AddStrictTestCase("float.abs(float.MAX_VALUE) check()", float.MAX_VALUE, check(float.MAX_VALUE));

test();

