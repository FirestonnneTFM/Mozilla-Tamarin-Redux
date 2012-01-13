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
Returns an implementation-dependent approximation to the natural logarithm of x.
*/

var SECTION = "4.5.24";
var VERSION = "AS3";
var TITLE   = "public function log(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:float):float { return float.log(param); }

AddStrictTestCase("float.log() returns a float", "float", getQualifiedClassName(float.log(0)));
AddStrictTestCase("float.log() length is 1", 1, float.log.length);

// If x is NaN, the result is NaN.
AddStrictTestCase("float.log(NaN)", float.NaN, float.log(float.NaN));
AddStrictTestCase("float.log(NaN) check()", float.NaN, check(float.NaN));

// If x is less than 0, the result is NaN.
AddStrictTestCase("float.log(-1f)", float.NaN, float.log(-1f));
AddStrictTestCase("float.log(-1f) check()", float.NaN, check(-1f));
AddStrictTestCase("float.log(float.NEGATIVE_INFINITY)", float.NaN, float.log(float.NEGATIVE_INFINITY));
AddStrictTestCase("float.log(float.NEGATIVE_INFINITY) check()", float.NaN, check(float.NEGATIVE_INFINITY));

// If x is +0 or -0, the result is -Infinity.
AddStrictTestCase("float.log(0f)", float.NEGATIVE_INFINITY, float.log(0f));
AddStrictTestCase("float.log(0f) check()", float.NEGATIVE_INFINITY, check(0f));
AddStrictTestCase("float.log(-0f)", float.NEGATIVE_INFINITY, float.log(-0f));
AddStrictTestCase("float.log(-0f) check()", float.NEGATIVE_INFINITY, check(-0f));

// If x is 1, the result is +0.
AddStrictTestCase("float.log(1f)", 0f, float.log(1f));
AddStrictTestCase("float.log(1f) check()", 0f, check(1f));
AddStrictTestCase("float.log(1f) is +0f", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.log(1f));
AddStrictTestCase("float.log(1f) is +0f check()", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/check(1f));

// If x is +Infinity, the result is +Infinity.
AddStrictTestCase("float.log(float.POSITIVE_INFINITY)", float.POSITIVE_INFINITY, float.log(float.POSITIVE_INFINITY));
AddStrictTestCase("float.log(float.POSITIVE_INFINITY) check()", float.POSITIVE_INFINITY, check(float.POSITIVE_INFINITY));


var myfloat:float = 1.0e-6f;
AddStrictTestCase("float.log(-1.0e-6f)", float.NaN, float.log(-myfloat));
AddStrictTestCase("float.log(1.0e-6f)", -13.8155107498168945f, float.log(myfloat));
AddStrictTestCase("float.log(-1.0e-6f) FloatLiteral", float.NaN, float.log(-1.0e-6f));
AddStrictTestCase("float.log(1.0e-6f) FloatLiteral", -13.8155107498168945f, float.log(1.0e-6f));

myfloat = 1f;
AddStrictTestCase("float.log(-1f)", float.NaN, float.log(-myfloat));
AddStrictTestCase("float.log(1f)", 0f, float.log(myfloat));
AddStrictTestCase("float.log(-1f) FloatLiteral", float.NaN, float.log(-1f));
AddStrictTestCase("float.log(1f) FloatLiteral", 0f, float.log(1f));


test();

