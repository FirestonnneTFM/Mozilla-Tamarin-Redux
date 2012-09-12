/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "6.4.1";
var VERSION = "AS3";
var TITLE   = "The * operation agumented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var f1:float = 1.2345678e9;
var f2:float = 6.543210987;

AddStrictTestCase("float multiplication result", float(8.078037504e+09), f1*f2);
AddStrictTestCase("FloatLiteral multiplication result", float(8.078037504e+09), 1.2345678e9f*6.543210987f);
AddTestCase("multiplication of 2 floats returns a float", "float", getQualifiedClassName(f1*f2));


/*
4.734612e3 * 5.417242e5
c float   2.564853760e9
c double  2.5648538980103998184204102e9
as float  2.564853760e9
as double 2.5648538980104e9
 */
var val1:float = 4.734612e3f;
var val2:float = 5.417242e5f;
AddStrictTestCase("multiplication of 2 floats", 2.564853760e9f, val1*val2);
var val3 = 4.734612e3f * 5.417242e5f;
AddStrictTestCase("multiplication of 2 FloatLiterals", 2.564853760e9f, val3);

var onef:float = 1f;
var neg_onef:float = -1f;

function check(val1:*, val2:*):*
{
    return (val1 * val2);
}

AddStrictTestCase("float * Number", 1, check(onef, 1));
AddStrictTestCase("FloatLiteral * Number", 1, check(1f, 1));
AddStrictTestCase("Number * float", 1, check(1, onef));
AddStrictTestCase("Number * FloatLiteral", 1, check(1, 1f));
AddStrictTestCase("Boolean * float", 1, check(true, onef));
AddStrictTestCase("String * float", 1, check("1", onef));


// If either is NaN then NaN
AddTestCase("float.NaN * float", float.NaN, float.NaN * onef);
AddTestCase("isNaN float.NaN * float", true, isNaN(float.NaN * onef));
AddTestCase("float * float.NaN", float.NaN, onef * float.NaN);
AddTestCase("isNaN float * float.NaN", true, isNaN(onef * float.NaN));
AddTestCase("check(float.NaN, float)", float.NaN, check(float.NaN, onef));
AddTestCase("isNaN check(float.NaN, float)", true, isNaN(check(float.NaN, onef)));
AddTestCase("check(float, float.NaN)", float.NaN, check(onef, float.NaN));
AddTestCase("isNaN check(float, float.NaN)", true, isNaN(check(onef, float.NaN)));

AddTestCase("float.NaN * FloatLiteral", float.NaN, float.NaN * 1f);
AddTestCase("isNaN float.NaN * FloatLiteral", true, isNaN(float.NaN * 1f));
AddTestCase("FloatLiteral * float.NaN", float.NaN, 1f * float.NaN);
AddTestCase("isNaN FloatLiteral * float.NaN", true, isNaN(1f * float.NaN));
AddTestCase("check(float.NaN, FloatLiteral)", float.NaN, check(float.NaN, 1f));
AddTestCase("isNaN check(float.NaN, FloatLiteral)", true, isNaN(check(float.NaN, 1f)));
AddTestCase("check(FloatLiteral, float.NaN)", float.NaN, check(1f, float.NaN));
AddTestCase("isNaN check(FloatLiteral, float.NaN)", true, isNaN(check(1f, float.NaN)));

// result is positive if both have same sign, negative if they differ
AddStrictTestCase("float * float", 1f, 1f * 1f);
AddStrictTestCase("-float * float", -1f, -1f * 1f);
AddStrictTestCase("float * -float", -1f, 1f * -1f);
AddStrictTestCase("-float * -float", 1f, -1f * -1f);

AddStrictTestCase("check(float, float)", 1f, check(1f, 1f));
AddStrictTestCase("check(-float, float)", -1f, check(-1f, 1f));
AddStrictTestCase("check(float, -float)", -1f, check(1f, -1f));
AddStrictTestCase("check(-float, -float)", 1f, check(-1f, -1f));

// infinity * zero is NaN (what about -0)
var zerof:float = 0f;
var neg_zerof:float = -0f;
AddTestCase("float.POSITIVE_INFINITY * zerof", float.NaN, float.POSITIVE_INFINITY * zerof);
AddTestCase("isNaN float.POSITIVE_INFINITY * zerof", true, isNaN(float.POSITIVE_INFINITY * zerof));
AddTestCase("isNaN check(float.POSITIVE_INFINITY, zerof)", true, isNaN(check(float.POSITIVE_INFINITY, zerof)));
AddTestCase("zerof * float.POSITIVE_INFINITY", float.NaN, zerof * float.POSITIVE_INFINITY);
AddTestCase("isNaN zerof * float.POSITIVE_INFINITY", true, isNaN(zerof * float.POSITIVE_INFINITY));
AddTestCase("isNaN check(zerof, float.POSITIVE_INFINITY)", true, isNaN(check(zerof, float.POSITIVE_INFINITY)));
AddTestCase("float.POSITIVE_INFINITY * neg_zerof", float.NaN, float.POSITIVE_INFINITY * neg_zerof);
AddTestCase("isNaN float.POSITIVE_INFINITY * neg_zerof", true, isNaN(float.POSITIVE_INFINITY * neg_zerof));
AddTestCase("isNaN check(float.POSITIVE_INFINITY, neg_zerof)", true, isNaN(check(float.POSITIVE_INFINITY, neg_zerof)));
AddTestCase("neg_zerof * float.POSITIVE_INFINITY", float.NaN, neg_zerof * float.POSITIVE_INFINITY);
AddTestCase("isNaN neg_zerof * float.POSITIVE_INFINITY", true, isNaN(neg_zerof * float.POSITIVE_INFINITY));
AddTestCase("isNaN check(neg_zerof, float.POSITIVE_INFINITY)", true, isNaN(check(neg_zerof, float.POSITIVE_INFINITY)));

AddTestCase("float.NEGATIVE_INFINITY * zerof", float.NaN, float.NEGATIVE_INFINITY * zerof);
AddTestCase("isNaN float.NEGATIVE_INFINITY * zerof", true, isNaN(float.NEGATIVE_INFINITY * zerof));
AddTestCase("isNaN check(float.NEGATIVE_INFINITY, zerof)", true, isNaN(check(float.NEGATIVE_INFINITY, zerof)));
AddTestCase("zerof * float.NEGATIVE_INFINITY", float.NaN, zerof * float.NEGATIVE_INFINITY);
AddTestCase("isNaN zerof * float.NEGATIVE_INFINITY", true, isNaN(zerof * float.NEGATIVE_INFINITY));
AddTestCase("isNaN check(zerof, float.NEGATIVE_INFINITY)", true, isNaN(check(zerof, float.NEGATIVE_INFINITY)));
AddTestCase("float.NEGATIVE_INFINITY * neg_zerof", float.NaN, float.NEGATIVE_INFINITY * neg_zerof);
AddTestCase("isNaN float.NEGATIVE_INFINITY * neg_zerof", true, isNaN(float.NEGATIVE_INFINITY * neg_zerof));
AddTestCase("isNaN check(float.NEGATIVE_INFINITY, neg_zerof)", true, isNaN(check(float.NEGATIVE_INFINITY, neg_zerof)));
AddTestCase("neg_zerof * float.NEGATIVE_INFINITY", float.NaN, neg_zerof * float.NEGATIVE_INFINITY);
AddTestCase("isNaN neg_zerof * float.NEGATIVE_INFINITY", true, isNaN(neg_zerof * float.NEGATIVE_INFINITY));
AddTestCase("isNaN check(neg_zerof, float.NEGATIVE_INFINITY)", true, isNaN(check(neg_zerof, float.NEGATIVE_INFINITY)));

// infinity * infinity = infinity, sign determined by above rule
AddStrictTestCase("float.POSITIVE_INFINITY * float.POSITIVE_INFINITY", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY * float.POSITIVE_INFINITY);
AddStrictTestCase("float.NEGATIVE_INFINITY * float.POSITIVE_INFINITY", float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY * float.POSITIVE_INFINITY);
AddStrictTestCase("float.POSITIVE_INFINITY * float.NEGATIVE_INFINITY", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY * float.NEGATIVE_INFINITY);
AddStrictTestCase("float.NEGATIVE_INFINITY * float.NEGATIVE_INFINITY", float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY * float.NEGATIVE_INFINITY);

AddStrictTestCase("check(float.POSITIVE_INFINITY, float.POSITIVE_INFINITY)", float.POSITIVE_INFINITY, check( float.POSITIVE_INFINITY, float.POSITIVE_INFINITY));
AddStrictTestCase("check(float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY)", float.NEGATIVE_INFINITY, check(float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY));
AddStrictTestCase("check(float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY)", float.NEGATIVE_INFINITY, check(float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY));
AddStrictTestCase("check(float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY)", float.POSITIVE_INFINITY, check(float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY));

// infinity * finite = infinity, sign determined by above rule
AddStrictTestCase("float.POSITIVE_INFINITY * onef", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY * onef);
AddStrictTestCase("onef * float.POSITIVE_INFINITY", float.POSITIVE_INFINITY, onef * float.POSITIVE_INFINITY);
AddStrictTestCase("float.NEGATIVE_INFINITY * onef", float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY * onef);
AddStrictTestCase("onef * float.NEGATIVE_INFINITY", float.NEGATIVE_INFINITY, onef * float.NEGATIVE_INFINITY);
AddStrictTestCase("float.POSITIVE_INFINITY * neg_onef", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY * neg_onef);
AddStrictTestCase("neg_onef * float.POSITIVE_INFINITY", float.NEGATIVE_INFINITY, neg_onef * float.POSITIVE_INFINITY);
AddStrictTestCase("float.NEGATIVE_INFINITY * neg_onef", float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY * neg_onef);
AddStrictTestCase("neg_onef * float.NEGATIVE_INFINITY", float.POSITIVE_INFINITY, neg_onef * float.NEGATIVE_INFINITY);

AddStrictTestCase("check(float.POSITIVE_INFINITY, onef)", float.POSITIVE_INFINITY, check(float.POSITIVE_INFINITY, onef));
AddStrictTestCase("check(onef, float.POSITIVE_INFINITY)", float.POSITIVE_INFINITY, check(onef, float.POSITIVE_INFINITY));
AddStrictTestCase("check(float.NEGATIVE_INFINITY, onef)", float.NEGATIVE_INFINITY, check(float.NEGATIVE_INFINITY, onef));
AddStrictTestCase("check(onef, float.NEGATIVE_INFINITY)", float.NEGATIVE_INFINITY, check(onef, float.NEGATIVE_INFINITY));
AddStrictTestCase("check(float.POSITIVE_INFINITY, neg_onef)", float.NEGATIVE_INFINITY, check(float.POSITIVE_INFINITY, neg_onef));
AddStrictTestCase("check(neg_onef, float.POSITIVE_INFINITY)", float.NEGATIVE_INFINITY, check(neg_onef, float.POSITIVE_INFINITY));
AddStrictTestCase("check(float.NEGATIVE_INFINITY, neg_onef)", float.POSITIVE_INFINITY, check(float.NEGATIVE_INFINITY, neg_onef));
AddStrictTestCase("check(neg_onef, float.NEGATIVE_INFINITY)", float.POSITIVE_INFINITY, check(neg_onef, float.NEGATIVE_INFINITY));


AddStrictTestCase("float.POSITIVE_INFINITY * FloatLiteral", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY * 1f);
AddStrictTestCase("FloatLiteral * float.POSITIVE_INFINITY", float.POSITIVE_INFINITY, 1f * float.POSITIVE_INFINITY);
AddStrictTestCase("float.NEGATIVE_INFINITY * FloatLiteral", float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY * 1f);
AddStrictTestCase("FloatLiteral * float.NEGATIVE_INFINITY", float.NEGATIVE_INFINITY, 1f * float.NEGATIVE_INFINITY);
AddStrictTestCase("float.POSITIVE_INFINITY * -FloatLiteral", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY * -1f);
AddStrictTestCase("-FloatLiteral * float.POSITIVE_INFINITY", float.NEGATIVE_INFINITY, -1f * float.POSITIVE_INFINITY);
AddStrictTestCase("float.NEGATIVE_INFINITY * -FloatLiteral", float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY * -1f);
AddStrictTestCase("-FloatLiteral * float.NEGATIVE_INFINITY", float.POSITIVE_INFINITY, -1f * float.NEGATIVE_INFINITY);

AddStrictTestCase("check(float.POSITIVE_INFINITY, FloatLiteral)", float.POSITIVE_INFINITY, check(float.POSITIVE_INFINITY, 1f));
AddStrictTestCase("check(FloatLiteral, float.POSITIVE_INFINITY)", float.POSITIVE_INFINITY, check(1f, float.POSITIVE_INFINITY));
AddStrictTestCase("check(float.NEGATIVE_INFINITY, FloatLiteral)", float.NEGATIVE_INFINITY, check(float.NEGATIVE_INFINITY, 1f));
AddStrictTestCase("check(FloatLiteral, float.NEGATIVE_INFINITY)", float.NEGATIVE_INFINITY, check(1f, float.NEGATIVE_INFINITY));
AddStrictTestCase("check(float.POSITIVE_INFINITY, -FloatLiteral)", float.NEGATIVE_INFINITY, check(float.POSITIVE_INFINITY, -1f));
AddStrictTestCase("check(-FloatLiteral, float.POSITIVE_INFINITY)", float.NEGATIVE_INFINITY, check(-1f, float.POSITIVE_INFINITY));
AddStrictTestCase("check(float.NEGATIVE_INFINITY, -FloatLiteral)", float.POSITIVE_INFINITY, check(float.NEGATIVE_INFINITY, -1f));
AddStrictTestCase("check(-FloatLiteral, float.NEGATIVE_INFINITY)", float.POSITIVE_INFINITY, check(-1f, float.NEGATIVE_INFINITY));



test();

