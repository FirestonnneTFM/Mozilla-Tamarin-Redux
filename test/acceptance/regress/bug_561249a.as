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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
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
 * ***** END LICENSE BLOCK *****
 *
 *
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=561249
 *
 */
//-----------------------------------------------------------------------------

var SECTION = "561249";
var VERSION = "";
var TITLE   = "Specialized/Inlined Addition Overflow and Representation Change Boundaries";
var bug = "561249";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);

var array:Array = new Array();
var item:int = 0;

function VerifyEquals(actual, expect, a, b, ctx)
{
    var status = ctx + " " + a + " + " + b;
    array[item++] = new TestCase(SECTION, status, expect, actual);
}

function AddIntToInt(a:int, b:int, c)
{
    VerifyEquals(a + b, c, a, b, "AddIntToInt");
}

function AddDoubleToDouble(a:Number, b:Number, c)
{
    VerifyEquals(a + b, c, a, b, "AddDoubleToDouble");
}

function AddIntToDouble(a:int, b:Number, c)
{
    VerifyEquals(a + b, c, a, b, "AddIntToDouble");
}

function AddDoubleToInt(a:Number, b:int, c)
{
    VerifyEquals(a + b, c, a, b, "AddDoubleToInt");
}

function AddIntToAtom(a:int, b, c)
{
    VerifyEquals(a + b, c, a, b, "AddIntToAtom");
}

function AddAtomToInt(a, b:int, c)
{
    VerifyEquals(a + b, c, a, b, "AddAtomToInt");
}

function AddDoubleToAtom(a:Number, b, c)
{
    VerifyEquals(a + b, c, a, b, "AddDoubleToAtom");
}

function AddAtomToDouble(a, b:Number, c)
{
    VerifyEquals(a + b, c, a, b, "AddAtomToDouble");
}

function AddAtomToAtom(a, b, c)
{
    VerifyEquals(a + b, c, a, b, "AddAtomToAtom");
}

function II(a:int, b:int, c)
{
    AddIntToInt(a, b, c);
    AddIntToInt(b, a, c);
    AddIntToDouble(a, b, c);
    AddDoubleToInt(b, a, c);
    AddDoubleToDouble(a, b, c);
    AddDoubleToDouble(b, a, c);
    //
    AddIntToAtom(a, b, c);
    AddIntToAtom(b, a, c);
    AddAtomToInt(a, b, c);
    AddAtomToInt(b, a, c);
    AddDoubleToAtom(a, b, c);
    AddDoubleToAtom(b, a, c);
    AddAtomToDouble(a, b, c);
    AddAtomToDouble(b, a, c);
    AddAtomToAtom(a, b, c);
    AddAtomToAtom(b, a, c);
}

function ID(a:int, b:Number, c)
{
    AddIntToDouble(a, b, c);
    AddDoubleToInt(b, a, c);
    AddDoubleToDouble(a, b, c);
    AddDoubleToDouble(b, a, c);
    //
    AddIntToAtom(a, b, c);
    AddAtomToInt(b, a, c);
    AddDoubleToAtom(a, b, c);
    AddDoubleToAtom(b, a, c);
    AddAtomToDouble(a, b, c);
    AddAtomToDouble(b, a, c);
    AddAtomToAtom(a, b, c);
    AddAtomToAtom(b, a, c);
}

var int29_maxm1 =   268435454;
var int29_max   =   268435455;
var int29_maxp1 =   268435456;

var int29_minm1 =  -268435457;
var int29_min   =  -268435456;
var int29_minp1 =  -268435455;

var int32_maxm1 =   2147483646;
var int32_max   =   2147483647;
var int32_maxp1 =   2147483648;

var int32_minm1 =  -2147483649;
var int32_min   =  -2147483648;
var int32_minp1 =  -2147483647;

var int53_maxm1 =   4503599627370494;
var int53_max   =   4503599627370495;
var int53_maxp1 =   4503599627370496;

var int53_minm1 =  -4503599627370497;
var int53_min   =  -4503599627370496;
var int53_minp1 =  -4503599627370495;

// Note that values larger than int54_max and smaller than
// int54_min cannot be represented exactly as a double (Number).

var int54_maxm1 =   9007199254740990;
var int54_max   =   9007199254740991;

var int54_min   =  -9007199254740992;
var int54_minp1 =  -9007199254740991;

function getTestCases()
{
    // An integer representable in 29 bits will fit
    // in a kIntptrType atom on a 32-bit platform.

    II(0,    int29_max,    int29_max);
    II(0,    int29_maxp1,  int29_maxp1);
    II(0,    int29_min,    int29_min);
    II(0,    int29_minm1,  int29_minm1);

    II(1,    int29_maxm1,  int29_max);
    II(1,    int29_min,    int29_minp1);
    II(1,    int29_minm1,  int29_min);

    II(-1,   int29_max,    int29_maxm1);
    II(-1,   int29_maxp1,  int29_max);
    II(-1,   int29_min,    int29_minm1);
    II(-1,   int29_minp1,  int29_min);

    // 32-bit integer values may be represented as
    // doubles without loss.  We may need to test
    // a 32-bit overflow prior to determining whether
    // an intptr will suffice, or a double is needed.
    // Thus, we test both the 29-bit and 32-bit boundaries.
    // Also, in some cases, we will promote an integer
    // result to a double when it exceeds 32 bits, in
    // order to exploit a hardware truncation instruction.

    II(0,    int32_max,    int32_max);
    ID(0,    int32_maxp1,  int32_maxp1);
    II(0,    int32_min,    int32_min);
    ID(0,    int32_minm1,  int32_minm1);

    II(1,    int32_max,    int32_maxp1);
    II(1,    int32_maxm1,  int32_max);
    II(1,    int32_min,    int32_minp1);
    ID(1,    int32_minm1,  int32_min);

    II(-1,   int32_max,    int32_maxm1);
    ID(-1,   int32_maxp1,  int32_max);
    II(-1,   int32_min,    int32_minm1);
    II(-1,   int32_minp1,  int32_min);

    // An integer representable in 53 bits will fit
    // in a kIntptrType atom on a 64-bit platform.
    // In fact, 54 bits will fit as well, but the
    // VM may sometimes enforce a smaller limit.
    // Even if this is fixed, the confusion warrants
    // exercising both the 53-bit and 54-bit boundaries.

    ID(0,    int53_max,    int53_max);
    ID(0,    int53_maxp1,  int53_maxp1);
    ID(0,    int53_min,    int53_min);
    ID(0,    int53_minm1,  int53_minm1);

    ID(1,    int53_max,    int53_maxp1);
    ID(1,    int53_maxm1,  int53_max);
    ID(1,    int53_min,    int53_minp1);
    ID(1,    int53_minm1,  int53_min);

    ID(-1,   int53_max,    int53_maxm1);
    ID(-1,   int53_maxp1,  int53_max);
    ID(-1,   int53_min,    int53_minm1);
    ID(-1,   int53_minp1,  int53_min);

    // An integer representable in 54 bits will fit
    // in a kIntptrType atom on a 64-bit platform.

    ID(0,    int54_max,    int54_max);
    ID(0,    int54_min,    int54_min);

    ID(1,    int54_maxm1,  int54_max);
    ID(1,    int54_min,    int54_minp1);

    ID(-1,   int54_max,    int54_maxm1);
    ID(-1,   int54_minp1,  int54_min);

    return array;
}

var testcases = getTestCases();
test();
