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
Returns an implementation-dependent approximation to the tangent of x. The
argument is expressed in radians.
*/

var SECTION = "4.5.32";
var VERSION = "AS3";
var TITLE   = "public function tan(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:float):float { return float.tan(param); }

AddStrictTestCase("float.tan() returns a float", "float", getQualifiedClassName(float.tan(0)));
AddStrictTestCase("float.tan() length is 1", 1, float.tan.length);

// If x is NaN, the result is NaN.
AddStrictTestCase("float.tan(undefined)", float.NaN, float.tan(undefined));
AddStrictTestCase("float.tan(float.NaN)", float.NaN, float.tan(float.NaN));
AddStrictTestCase("float.tan(float.NaN) check()", float.NaN, check(float.NaN));

// If x is +0, the result is +0.
var zero:float = 0f;
AddStrictTestCase("float.tan(zero=0f)", 0f, float.tan(zero));
AddStrictTestCase("float.tan(0f) FloatLiteral", 0f, float.tan(0f));
AddStrictTestCase("float.tan(0f) sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.tan(0f));
AddStrictTestCase("float.tan(0f) check()", 0f, check(0f));
AddStrictTestCase("float.tan(0f) check() sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/check(0f));
AddStrictTestCase("float.tan(null)", 0f, float.tan(null));

// If x is -0, the result is -0.
var neg_zero:float = -0f;
AddStrictTestCase("float.tan(neg_zero)", -0f, float.tan(neg_zero));
AddStrictTestCase("float.tan(neg_zero) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.tan(neg_zero));
AddStrictTestCase("float.tan(-0f) FloatLiteral", -0f, float.tan(-0f));
AddStrictTestCase("float.tan(-0f) FloatLiteral sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.tan(-0f));
AddStrictTestCase("float.tan(-0f) check()", -0f, check(-0f));
AddStrictTestCase("float.tan(-0f) check() sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/check(-0f));

// If x is +Infinity or -Infinity, the result is NaN.
AddStrictTestCase("float.tan(float.POSITIVE_INFINITY)", float.NaN, float.tan(float.POSITIVE_INFINITY));
AddStrictTestCase("float.tan(float.NEGATIVE_INFINITY)", float.NaN, float.tan(float.NEGATIVE_INFINITY));
AddStrictTestCase("float.tan(float.POSITIVE_INFINITY) check()", float.NaN, check(float.POSITIVE_INFINITY));
AddStrictTestCase("float.tan(float.NEGATIVE_INFINITY) check()", float.NaN, check(float.NEGATIVE_INFINITY));

AddStrictTestCase("float.tan(float.PI/4f)", float(1), float.tan(float.PI/4f));
AddStrictTestCase("float.tan(3f*float.PI/4f)", float(-1), float.tan(3f*float.PI/4f));
AddStrictTestCase("float.tan(float.PI)", -float.sin(float.PI), float.tan(float.PI));
AddStrictTestCase("float.tan(5f*float.PI/4f)", float(1.0000003576278687), float.tan(5f*float.PI/4f));

test();

