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
Returns an implementation-dependent approximation to the arc tangent of x.
The result is expressed in radians and ranges from iPI/2 to +PI/2.
*/

var SECTION = "4.5.18";
var VERSION = "AS3";
var TITLE   = "public function atan(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:float):float { return float.atan(param); }

AddStrictTestCase("float.atan() returns a float", "float", getQualifiedClassName(float.atan(0)));
AddStrictTestCase("float.atan() length is 1", 1, float.atan.length);

// If x is NaN, the result is NaN.
AddStrictTestCase("float.atan(undefined)", float.NaN, float.atan(undefined));
AddStrictTestCase("float.atan(NaN)", float.NaN, float.atan(float.NaN));
AddStrictTestCase("float.atan(NaN) check()", float.NaN, check(float.NaN));

// If x is +0, the result is +0.
AddStrictTestCase("float.atan(0f)", 0f, float.atan(0f));
AddStrictTestCase("float.atan(0f) check()", 0f, check(0f));
AddStrictTestCase("Ensure that float.atan(+0f) returns +0f", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.atan(0f));
AddStrictTestCase("Ensure that float.atan(+0f) returns +0f check()", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/check(0f));

// If x is -0, the result is -0.
AddStrictTestCase("float.atan(-0f)", -0f, float.atan(-0f));
AddStrictTestCase("float.atan(-0f) check()", -0f, check(-0f));
AddStrictTestCase("Ensure that float.atan(-0f) returns -0f", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.atan(-0f));
AddStrictTestCase("Ensure that float.atan(-0f) returns -0f check()", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/check(-0f));


// If x is +Infinity, the result is an implementation-dependent approximation to +PI/2.
AddStrictTestCase("float.atan(float.POSITIVE_INFINITY)", float.PI/2f, float.atan(float.POSITIVE_INFINITY));
AddStrictTestCase("float.atan(float.POSITIVE_INFINITY) check()", float.PI/2f, check(float.POSITIVE_INFINITY));

// If x is -Infinity, the result is an implementation-dependent approximation to -PI/2.
AddStrictTestCase("float.atan(float.NEGATIVE_INFINITY)", -float.PI/2f, float.atan(float.NEGATIVE_INFINITY));
AddStrictTestCase("float.atan(float.NEGATIVE_INFINITY) check()", -float.PI/2f, check(float.NEGATIVE_INFINITY));


AddStrictTestCase("float.atan(null)", 0f, float.atan(null));

var myfloat:float = 1f;
AddStrictTestCase("float.atan(myfloat=1f)", float(float.PI/4.0f), float.atan(myfloat));
myfloat = 0f;
AddStrictTestCase("float.atan(myfloat=0f)", float(0), float.atan(myfloat));
myfloat = -0f;
AddStrictTestCase("float.atan(myfloat=-0f)", -float(0), float.atan(myfloat));
myfloat = -1f;
AddStrictTestCase("float.atan(myfloat=-1f)", -float(float.PI/4.0f), float.atan(myfloat));

AddStrictTestCase("float.atan(1f) FloatLiteral", float(float.PI/4.0f), float.atan(1f));
AddStrictTestCase("float.atan(0f) FloatLiteral", float(0), float.atan(0f));
AddStrictTestCase("float.atan(-0f) FloatLiteral", -float(0), float.atan(-0f));
AddStrictTestCase("float.atan(-1f) FloatLiteral", -float(float.PI/4.0f), float.atan(-1f));


test();

