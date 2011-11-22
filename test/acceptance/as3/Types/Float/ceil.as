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
include "floatUtil.as";

/*
Returns the smallest (closest to -Infinity) float value that is not less than x
and is equal to a mathematical integer. If x is already an integer, the result is x.
*/

var SECTION = "4.5.20";
var VERSION = "AS3";
var TITLE   = "public function ceil(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:float):float { return float.ceil(param); }

AddStrictTestCase("float.ceil() returns a float", "float", getQualifiedClassName(float.ceil(0f)));
AddStrictTestCase("float.ceil() length is 1", 1, float.ceil.length);
AddErrorTest("float.ceil() with no args", ARGUMENTERROR+1063,  function(){ float.ceil(); });

// If x is NaN, the result is NaN.
AddStrictTestCase("float.ceil(undefined)", float.NaN, float.ceil(undefined));
AddStrictTestCase("float.ceil(string)", float.NaN, float.ceil("string"));
AddStrictTestCase("float.ceil(NaN)", float.NaN, float.ceil(float.NaN));
AddStrictTestCase("float.ceil(NaN) check()", float.NaN, check(float.NaN));

// If x is +0, the result is +0.
AddStrictTestCase("float.ceil(0f)", 0f, float.ceil(0f));
AddStrictTestCase("float.ceil(0f) sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.ceil(0f));
AddStrictTestCase("float.ceil(0f) check()", 0f, check(0f));
AddStrictTestCase("float.ceil(0f) check() sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/check(0f));

// If x is -0, the result is -0.
AddStrictTestCase("float.ceil(-0f)", -0f, float.ceil(-0f));
AddStrictTestCase("float.ceil(-0f) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.ceil(-0f));
AddStrictTestCase("float.ceil(-0f) check()", -0f, check(-0f));
AddStrictTestCase("float.ceil(-0f) check() sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/check(-0f));

// If x is +Infinity, the result is +Infinty.
AddStrictTestCase("float.ceil(float.POSITIVE_INFINITY)", float.POSITIVE_INFINITY, float.ceil(float.POSITIVE_INFINITY));
AddStrictTestCase("float.ceil(float.POSITIVE_INFINITY) check()", float.POSITIVE_INFINITY, check(float.POSITIVE_INFINITY));

// If x is -Infinity, the result is -Infinity.
AddStrictTestCase("float.ceil(float.NEGATIVE_INFINITY)", float.NEGATIVE_INFINITY, float.ceil(float.NEGATIVE_INFINITY));
AddStrictTestCase("float.ceil(float.NEGATIVE_INFINITY) check()", float.NEGATIVE_INFINITY, check(float.NEGATIVE_INFINITY));

// If x is less than 0 but greater than -1, the result is -0.
AddStrictTestCase("float.ceil(-0.1f)", float(-0), float.ceil(-0.1f));
AddStrictTestCase("float that float.ceil(-0.1f) returns -0f", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.ceil(-0.1f));
AddStrictTestCase("float.ceil(-0.5f)", -0f, float.ceil(-0.5f));
AddStrictTestCase("float.ceil(-0.5f) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.ceil(-0.5f));
AddStrictTestCase("float.ceil(-0.999f)", -0f, float.ceil(-0.999f));
AddStrictTestCase("float.ceil(-0.999f) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.ceil(-0.999f));
AddStrictTestCase("float.ceil(-0.5f) check()", -0f, check(-0.5f));
AddStrictTestCase("float.ceil(-0.5f) check() sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/check(-0.5f));
AddStrictTestCase("float.ceil(-0.999f) check()", -0f, check(-0.999f));
AddStrictTestCase("float.ceil(-0.999f) check() sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/check(-0.999f));

// The value of float.ceil(x) is the same as the value of -float.floor(-x).
AddStrictTestCase("float.ceil(3.124f) == -float.floor(-3.124f)", -float.floor(-3.124f), float.ceil(3.124f));

AddStrictTestCase("float.ceil(null)", 0f, float.ceil(null));
AddStrictTestCase("float.ceil(true)", 1f, float.ceil(true));
AddStrictTestCase("float.ceil(false)", 0f, float.ceil(false));

AddStrictTestCase("float.ceil(float.MAX_VALUE)", float.MAX_VALUE, float.ceil(float.MAX_VALUE));
AddStrictTestCase("float.ceil(float.MAX_VALUE+3.40282346638528e+31f)", float.POSITIVE_INFINITY, float.ceil(float.MAX_VALUE+3.40282346638528e+31f));
AddStrictTestCase("float.ceil(float.MIN_VALUE)", 1f, float.ceil(float.MIN_VALUE));

AddStrictTestCase("float.ceil('1')", 1f, float.ceil('1'));
AddStrictTestCase("float.ceil('0')", 0f, float.ceil('0'));

var myfloat:float = 1f;
AddStrictTestCase("float.ceil(myfloat=1f)", float(1f), float.ceil(myfloat));
myfloat = 0f;
AddStrictTestCase("float.ceil(myfloat=0f)", float(0), float.ceil(myfloat));
AddTestCase("float.INFINITY/float.ceil(myfloat=0f)", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.ceil(myfloat));
myfloat = -0f;
AddStrictTestCase("float.ceil(myfloat=-0f)", -float(0), float.ceil(myfloat));
AddStrictTestCase("float.INFINITY/float.ceil(myfloat=-0f)", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.ceil(myfloat));
myfloat = -1f;
AddStrictTestCase("float.ceil(myfloat=-1f)", float(-1f), float.ceil(myfloat));

AddStrictTestCase("float.ceil(1f) FloatLiteral", float(1), float.ceil(1f));
AddStrictTestCase("float.ceil(0f) FloatLiteral", float(0), float.ceil(0f));
AddStrictTestCase("float.ceil(-0f) FloatLiteral", -float(0), float.ceil(-0f));
AddStrictTestCase("float.ceil(-1f) FloatLiteral", -float(1), float.ceil(-1f));


test();

