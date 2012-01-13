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
Returns an implementation-dependent approximation to the exponential function
of x (e raised to the power of x, where e is the base of the natural logarithms).
*/

var SECTION = "4.5.22";
var VERSION = "AS3";
var TITLE   = "public function exp(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:float):float { return float.exp(param); }

AddStrictTestCase("float.exp() returns a float", "float", getQualifiedClassName(float.exp(0)));
AddStrictTestCase("float.exp() length is 1", 1, float.exp.length);

// If x is NaN, the result is NaN.
AddStrictTestCase("float.exp(NaN)", float.NaN, float.exp(float.NaN));
AddStrictTestCase("float.exp(NaN) check()", float.NaN, check(float.NaN));

// If x is +0, the result is 1.
AddStrictTestCase("float.exp(0f)", 1f, float.exp(0f));
AddStrictTestCase("float.exp(0f) check()", 1f, check(0f));

// If x is -0, the result is 1.
AddStrictTestCase("float.exp(-0f)", 1f, float.exp(-0f));
AddStrictTestCase("float.exp(-0f) check()", 1f, check(-0f));

// If x is +Infinity, the result is +Infinity.
AddStrictTestCase("float.exp(float.POSITIVE_INFINITY)", float.POSITIVE_INFINITY, float.exp(float.POSITIVE_INFINITY));
AddStrictTestCase("float.exp(float.POSITIVE_INFINITY) check()", float.POSITIVE_INFINITY, check(float.POSITIVE_INFINITY));

// If x is -Infinity, the result is +0.
AddStrictTestCase("float.exp(float.NEGATIVE_INFINITY)", 0f, float.exp(float.NEGATIVE_INFINITY));
AddStrictTestCase("float.exp(float.NEGATIVE_INFINITY) sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.exp(float.NEGATIVE_INFINITY));
AddStrictTestCase("float.exp(float.NEGATIVE_INFINITY) check()", 0f, check(float.NEGATIVE_INFINITY));
AddStrictTestCase("float.exp(float.NEGATIVE_INFINITY) check() sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/check(float.NEGATIVE_INFINITY));


AddStrictTestCase("float.exp(null)", 1f, float.exp(null));

AddStrictTestCase("float.exp(1)", float.E, float.exp(1f));
AddStrictTestCase("float.exp(1) check()", float.E, check(1f));

AddStrictTestCase("float.exp(float.MIN_VALUE)", 1f, float.exp(float.MIN_VALUE));
AddStrictTestCase("float.exp(float.MAX_VALUE)", float.POSITIVE_INFINITY, float.exp(float.MAX_VALUE));

AddStrictTestCase("float.exp(1.0e+3)", float.POSITIVE_INFINITY, float.exp(1.0e+3));
AddStrictTestCase("float.exp(-1.0e+3)", float(0), float.exp(-1.0e+3));

test();

