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


var SECTION = "6.4.3";
var VERSION = "AS3";
var TITLE   = "The % operation agumented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var f1:float = 1.2345678e9;
var f2:float = 6.543210987;
AddTestCase("float modulo result", float(7.874126434326171875e-01), f1%f2);
AddTestCase("FloatLiteral modulo result", float(7.874126434326171875e-01), 1.2345678e9f%6.543210987f);
 /*
    virgilp: 09/23/2011
    modulo on float & number should THEORETICALLY yield different results
    However, on gcc & VisualC (windows/x86), fmod seems to return identical results with fmodf
    if the input values are identical
    (and no, I didn't get fooled by the "fmod" version with float arguments - I explicitly
    casted the parameters to double)
    I suspect the runtime library implementations perform both operations on 64 bits.
    The thing is, there's no hardware instruction for modulo - except the x87 FPU
    (it has a "FPREM" instruction)
    Bottom line is - the C runtimelibrary makes no diffeernce (not on x86 and x64, Mac/Win, at least)
   */

// ABC Extension spec states that Float modulo can happen in double precision
AddTestCase("modulo on float & number should yield different results", true, (Number(f1)%Number(f2)) == (f1%f2) );
AddTestCase("modulo of 2 floats returns a float", "float", getQualifiedClassName(f1%f2));

var onef:float = 1f;
var neg_onef:float = -1f;
var zerof:float = 0f;
var neg_zerof:float = -0f;

function check(val1:*, val2:*):*
{
    return (val1 % val2);
}

AddStrictTestCase("float % Number", 0, check(onef, 1));
AddStrictTestCase("FloatLiteral % Number", 0, check(1f, 1));
AddStrictTestCase("Number % float", 0, check(1, onef));
AddStrictTestCase("Number % FloatLiteral", 0, check(1, 1f));
AddStrictTestCase("Boolean % float", 0, check(true, onef));
AddStrictTestCase("String % float", 0, check("1", onef));

// the left operand is the dividend and the right operand is the divisor.
// If either operand is NaN, the result is NaN.
AddTestCase("float.NaN % float", float.NaN, float.NaN % onef);
AddTestCase("isNaN float.NaN % float", true, isNaN(float.NaN % onef));
AddTestCase("float % float.NaN", float.NaN, onef % float.NaN);
AddTestCase("isNaN float % float.NaN", true, isNaN(onef % float.NaN));
AddTestCase("check(float.NaN, float)", float.NaN, check(float.NaN, onef));
AddTestCase("isNaN check(float.NaN, float)", true, isNaN(check(float.NaN, onef)));
AddTestCase("check(float, float.NaN)", float.NaN, check(onef, float.NaN));
AddTestCase("isNaN check(float, float.NaN)", true, isNaN(check(onef, float.NaN)));

AddTestCase("float.NaN % FloatLiteral", float.NaN, float.NaN % 1f);
AddTestCase("isNaN float.NaN % FloatLiteral", true, isNaN(float.NaN % 1f));
AddTestCase("FloatLiteral % float.NaN", float.NaN, 1f % float.NaN);
AddTestCase("isNaN FloatLiteral % float.NaN", true, isNaN(1f % float.NaN));
AddTestCase("check(float.NaN, FloatLiteral)", float.NaN, check(float.NaN, 1f));
AddTestCase("isNaN check(float.NaN, FloatLiteral)", true, isNaN(check(float.NaN, 1f)));
AddTestCase("check(FloatLiteral, float.NaN)", float.NaN, check(1f, float.NaN));
AddTestCase("isNaN check(FloatLiteral, float.NaN)", true, isNaN(check(1f, float.NaN)));

// The sign of the result equals the sign of the dividend.
AddStrictTestCase("float % float", 1f, 3f % 2f);
AddStrictTestCase("-float % float", -1f, -3f % 2f);
AddStrictTestCase("float % -float", 1f, 3f % -2f);
AddStrictTestCase("-float % -float", -1f, -3f % -2f);

AddStrictTestCase("check(float, float)", 1f, check(3f, 2f));
AddStrictTestCase("check(-float, float)", -1f, check(-3f, 2f));
AddStrictTestCase("check(float, -float)", 1f, check(3f, -2f));
AddStrictTestCase("check(-float, -float)", -1f, check(-3f, -2f));

// If the dividend is an infinity, or the divisor is a zero, or both, the result is NaN.
AddTestCase("float.POSITIVE_INFINITY % float", float.NaN, float.POSITIVE_INFINITY % onef);
AddTestCase("isNaN float.POSITIVE_INFINITY % float", true, isNaN(float.POSITIVE_INFINITY % onef));
AddTestCase("float.NEGATIVE_INFINITY % float", float.NaN, float.NEGATIVE_INFINITY % onef);
AddTestCase("isNaN float.NEGATIVE_INFINITY % float", true, isNaN(float.NEGATIVE_INFINITY % onef));
AddTestCase("float % 0f", float.NaN, onef % zerof);
AddStrictTestCase("is NaN float % 0f", true, isNaN(onef % zerof));
AddTestCase("float % -0f", float.NaN, onef % neg_zerof);
AddStrictTestCase("is NaN float % -0f", true, isNaN(onef % neg_zerof));
AddTestCase("float.POSITIVE_INFINITY % 0f", float.NaN, float.POSITIVE_INFINITY % zerof);
AddTestCase("isNaN float.POSITIVE_INFINITY % 0f", true, isNaN(float.POSITIVE_INFINITY % zerof));
AddTestCase("float.POSITIVE_INFINITY % -0f", float.NaN, float.POSITIVE_INFINITY % neg_zerof);
AddTestCase("isNaN float.POSITIVE_INFINITY % -0f", true, isNaN(float.POSITIVE_INFINITY % neg_zerof));

// If the dividend is finite and the divisor is an infinity, the result equals the dividend.
AddStrictTestCase("float % float.POSITIVE_INFINITY", onef, onef % float.POSITIVE_INFINITY);
AddStrictTestCase("check(float % float.POSITIVE_INFINITY)", onef, check(onef, float.POSITIVE_INFINITY));
AddStrictTestCase("float % float.NEGATIVE_INFINITY", onef, onef % float.NEGATIVE_INFINITY);
AddStrictTestCase("check(float % float.NEGATIVE_INFINITY)", onef, check(onef, float.NEGATIVE_INFINITY));

// If the dividend is a zero and the divisor is nonzero and finite, the result is the same as the dividend.
AddStrictTestCase("0f % float", zerof, zerof % onef);
AddStrictTestCase("check(0f, float)", zerof, check(zerof, onef));
AddStrictTestCase("-0f % float", neg_zerof, neg_zerof % onef);
AddStrictTestCase("-0f % float sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY / (neg_zerof % onef));
AddStrictTestCase("check(-0f, float)", neg_zerof, check(neg_zerof, onef));
AddStrictTestCase("check(-0f, float) sign check ", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY / check(neg_zerof, onef));


test();

