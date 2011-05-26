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


var SECTION = "6.4.2";
var VERSION = "AS3";
var TITLE   = "The / operation agumented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var f1:float = 1.2345678e9; // TODO: use float literals
var f2:float = 6.543210987; // TODO: use float literals
// c double 188679197.7903248965740204
// c float  188679200
AddStrictTestCase("float division result", float(1.886792e+08), f1/f2);
AddStrictTestCase("FloatLiteral division result", float(1.886792e+08), 1.2345678e9f/6.543210987f);
AddTestCase("division on float & number should yield different results", true, (f1/f2) != (1.2345678e9/6.543210987) );
AddTestCase("division on float & number should yield different results", true, (f1/f2) != (Number(f1)/Number(f2)) );
AddTestCase("division of 2 floats returns a float", "float", getQualifiedClassName(f1/f2));


var val1:float = 4.734612e3f;
var val2:float = 5.417242e5f;
AddStrictTestCase("multiplication of 2 floats", 2.564853760e9f, val1*val2);
var val3 = 4.734612e3f * 5.417242e5f;
AddStrictTestCase("multiplication of 2 FloatLiterals", 2.564853760e9f, val3);

var onef:float = 1f;
var neg_onef:float = -1f;
var zerof:float = 0f;
var neg_zerof:float = -0f;

function check(val1:*, val2:*):*
{
    return (val1 / val2);
}

AddStrictTestCase("float / Number", 1, check(onef, 1));
AddStrictTestCase("FloatLiteral / Number", 1, check(1f, 1));
AddStrictTestCase("Number / float", 1, check(1, onef));
AddStrictTestCase("Number / FloatLiteral", 1, check(1, 1f));
AddStrictTestCase("Boolean / float", 1, check(true, onef));
AddStrictTestCase("String / float", 1, check("1", onef));


// If either is NaN then NaN
AddTestCase("float.NaN / float", float.NaN, float.NaN / onef);
AddTestCase("isNaN float.NaN / float", true, isNaN(float.NaN / onef));
AddTestCase("float / float.NaN", float.NaN, onef / float.NaN);
AddTestCase("isNaN float / float.NaN", true, isNaN(onef / float.NaN));
AddTestCase("check(float.NaN, float)", float.NaN, check(float.NaN, onef));
AddTestCase("isNaN check(float.NaN, float)", true, isNaN(check(float.NaN, onef)));
AddTestCase("check(float, float.NaN)", float.NaN, check(onef, float.NaN));
AddTestCase("isNaN check(float, float.NaN)", true, isNaN(check(onef, float.NaN)));

AddTestCase("float.NaN / FloatLiteral", float.NaN, float.NaN / 1f);
AddTestCase("isNaN float.NaN / FloatLiteral", true, isNaN(float.NaN / 1f));
AddTestCase("FloatLiteral / float.NaN", float.NaN, 1f / float.NaN);
AddTestCase("isNaN FloatLiteral / float.NaN", true, isNaN(1f / float.NaN));
AddTestCase("check(float.NaN, FloatLiteral)", float.NaN, check(float.NaN, 1f));
AddTestCase("isNaN check(float.NaN, FloatLiteral)", true, isNaN(check(float.NaN, 1f)));
AddTestCase("check(FloatLiteral, float.NaN)", float.NaN, check(1f, float.NaN));
AddTestCase("isNaN check(FloatLiteral, float.NaN)", true, isNaN(check(1f, float.NaN)));

// result is positive if both have same sign, negative if they differ
AddStrictTestCase("float / float", 1f, 1f / 1f);
AddStrictTestCase("-float / float", -1f, -1f / 1f);
AddStrictTestCase("float / -float", -1f, 1f / -1f);
AddStrictTestCase("-float / -float", 1f, -1f / -1f);

AddStrictTestCase("check(float, float)", 1f, check(1f, 1f));
AddStrictTestCase("check(-float, float)", -1f, check(-1f, 1f));
AddStrictTestCase("check(float, -float)", -1f, check(1f, -1f));
AddStrictTestCase("check(-float, -float)", 1f, check(-1f, -1f));

// Division of an infinity by an infinity results in NaN.
AddTestCase("float.POSITIVE_INFINITY / float.POSITIVE_INFINITY", float.NaN, float.POSITIVE_INFINITY / float.POSITIVE_INFINITY);
AddTestCase("isNaN float.POSITIVE_INFINITY / float.POSITIVE_INFINITY", true, isNaN(float.POSITIVE_INFINITY / float.POSITIVE_INFINITY));
AddTestCase("float.NEGATIVE_INFINITY / float.POSITIVE_INFINITY", float.NaN, float.NEGATIVE_INFINITY / float.POSITIVE_INFINITY);
AddTestCase("isNaN float.NEGATIVE_INFINITY / float.POSITIVE_INFINITY", true, isNaN(float.NEGATIVE_INFINITY / float.POSITIVE_INFINITY));
AddTestCase("float.POSITIVE_INFINITY / float.NEGATIVE_INFINITY", float.NaN, float.POSITIVE_INFINITY / float.NEGATIVE_INFINITY);
AddTestCase("isNaN float.POSITIVE_INFINITY / float.NEGATIVE_INFINITY", true, isNaN(float.POSITIVE_INFINITY / float.NEGATIVE_INFINITY));
AddTestCase("float.NEGATIVE_INFINITY / float.NEGATIVE_INFINITY", float.NaN, float.NEGATIVE_INFINITY / float.NEGATIVE_INFINITY);
AddTestCase("isNaN float.NEGATIVE_INFINITY / float.NEGATIVE_INFINITY", true, isNaN(float.NEGATIVE_INFINITY / float.NEGATIVE_INFINITY));

AddTestCase("check(float.POSITIVE_INFINITY, float.POSITIVE_INFINITY)", float.NaN, check(float.POSITIVE_INFINITY, float.POSITIVE_INFINITY));
AddTestCase("isNaN check(float.POSITIVE_INFINITY, float.POSITIVE_INFINITY)", true, isNaN(check(float.POSITIVE_INFINITY, float.POSITIVE_INFINITY)));
AddTestCase("check(float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY)", float.NaN, check(float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY));
AddTestCase("isNaN check(float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY)", true, isNaN(check(float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY)));
AddTestCase("check(float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY)", float.NaN, check(float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY));
AddTestCase("isNaN check(float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY)", true, isNaN(check(float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY)));
AddTestCase("check(float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY)", float.NaN, check(float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY));
AddTestCase("isNaN check(float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY)", true, isNaN(check(float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY)));


// Division of an infinity by a zero results in an infinity. The sign is determined by the rule already stated above.
AddStrictTestCase("float.POSITIVE_INFINITY / float", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY / 0f);
AddStrictTestCase("check(float.POSITIVE_INFINITY, float)", float.POSITIVE_INFINITY, check(float.POSITIVE_INFINITY, 0f));
AddStrictTestCase("float.POSITIVE_INFINITY / -float", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY / -0f);
AddStrictTestCase("check(float.POSITIVE_INFINITY, -float)", float.NEGATIVE_INFINITY, check(float.POSITIVE_INFINITY, -0f));
AddStrictTestCase("float.NEGATIVE_INFINITY / float", float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY / 0f);
AddStrictTestCase("check(float.NEGATIVE_INFINITY, float)", float.NEGATIVE_INFINITY, check(float.NEGATIVE_INFINITY, 0f));
AddStrictTestCase("float.NEGATIVE_INFINITY / -float", float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY / -0f);
AddStrictTestCase("check(float.NEGATIVE_INFINITY, -float)", float.POSITIVE_INFINITY, check(float.NEGATIVE_INFINITY, -0f));


// Division of an infinity by a nonzero finite value results in a signed infinity. The sign is determined by the rule already stated above.
AddStrictTestCase("float.POSITIVE_INFINITY / float", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY / 1f);
AddStrictTestCase("check(float.POSITIVE_INFINITY, float)", float.POSITIVE_INFINITY, check(float.POSITIVE_INFINITY, 1f));
AddStrictTestCase("float.POSITIVE_INFINITY / -float", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY / -1f);
AddStrictTestCase("check(float.POSITIVE_INFINITY, -float)", float.NEGATIVE_INFINITY, check(float.POSITIVE_INFINITY, -1f));
AddStrictTestCase("float.NEGATIVE_INFINITY / float", float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY / 1f);
AddStrictTestCase("check(float.NEGATIVE_INFINITY, float)", float.NEGATIVE_INFINITY, check(float.NEGATIVE_INFINITY, 1f));
AddStrictTestCase("float.NEGATIVE_INFINITY / -float", float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY / -1f);
AddStrictTestCase("check(float.NEGATIVE_INFINITY, -float)", float.POSITIVE_INFINITY, check(float.NEGATIVE_INFINITY, -1f));


// Division of a finite value by an infinity results in zero. The sign is determined by the rule already stated above.
AddStrictTestCase("float / float.POSITIVE_INFINITY", 0f, 1f / float.POSITIVE_INFINITY);
AddStrictTestCase("float / float.POSITIVE_INFINITY sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY / (1f / float.POSITIVE_INFINITY));
AddStrictTestCase("check(float, float.POSITIVE_INFINITY)", 0f, check(1f, float.POSITIVE_INFINITY));
AddStrictTestCase("-float / float.POSITIVE_INFINITY", -0f, -1f / float.POSITIVE_INFINITY);
AddStrictTestCase("-float / float.POSITIVE_INFINITY sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY / (-1f / float.POSITIVE_INFINITY));
AddStrictTestCase("check(-float, float.POSITIVE_INFINITY)", -0f, check(-1f, float.POSITIVE_INFINITY));
AddStrictTestCase("float / float.NEGATIVE_INFINITY", -0f, 1f / float.NEGATIVE_INFINITY);
AddStrictTestCase("float / float.NEGATIVE_INFINITY sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY / (1f / float.NEGATIVE_INFINITY));
AddStrictTestCase("check(float, float.NEGATIVE_INFINITY)", -0f, check(1f, float.NEGATIVE_INFINITY));
AddStrictTestCase("-float / float.NEGATIVE_INFINITY", 0f, -1f / float.NEGATIVE_INFINITY);
AddStrictTestCase("check(-float, float.NEGATIVE_INFINITY)", 0f, check(-1f, float.NEGATIVE_INFINITY));

// Division of a zero by a zero results in NaN; division of zero by any other finite value results in zero,
// with the sign determined by the rule already stated above.
AddTestCase("0f / 0f", float.NaN, zerof / zerof);
AddTestCase("isNaN 0f / 0f", true, isNaN(zerof / zerof));
AddTestCase("0f / -0f", float.NaN, zerof / neg_zerof);
AddTestCase("isNaN 0f / -0f", true, isNaN(zerof / neg_zerof));
AddTestCase("-0f / -0f", float.NaN, neg_zerof / neg_zerof);
AddTestCase("isNaN -0f / -0f", true, isNaN(neg_zerof / neg_zerof));

AddStrictTestCase("0f / 1f", 0f, 0f / 1f);
AddStrictTestCase("0f / 1f sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY / (0f / 1f));
AddStrictTestCase("check(0f, 1f)", 0f, check(0f, 1f));
AddStrictTestCase("0f / -1f", -0f, 0f / -1f);
AddStrictTestCase("0f / -1f sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY / (0f / -1f));
AddStrictTestCase("check(0f, -1f)", -0f, check(0f, -1f));
AddStrictTestCase("-0f / 1f", -0f, -0f / 1f);
AddStrictTestCase("-0f / 1f sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY / (-0f / 1f));
AddStrictTestCase("check(-0f, 1f)", -0f, check(-0f, 1f));
AddStrictTestCase("-0f / -1f", -0f, -0f / -1f);
AddStrictTestCase("-0f / -1f sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY / (-0f / -1f));
AddStrictTestCase("check(-0f, -1f)", 0f, check(-0f, -1f));

// Division of a nonzero finite value by a zero results in a signed infinity. The sign is determined by the rule already stated above.
AddStrictTestCase("1f / 0f", float.POSITIVE_INFINITY, 1f / 0f);
AddStrictTestCase("-1f / 0f", float.NEGATIVE_INFINITY, -1f / 0f);
AddStrictTestCase("1f / -0f", float.NEGATIVE_INFINITY, 1f / -0f);
AddStrictTestCase("-1f / -0f", float.POSITIVE_INFINITY, -1f / -0f);
AddStrictTestCase("check(1f, 0f)", float.POSITIVE_INFINITY, check(1f, 0f));
AddStrictTestCase("check(-1f, 0f)", float.NEGATIVE_INFINITY, check(-1f, 0f));
AddStrictTestCase("check(1f, -0f)", float.NEGATIVE_INFINITY, check(1f, -0f));
AddStrictTestCase("check(-1f, -0f)", float.POSITIVE_INFINITY, check(-1f, -0f));


test();

