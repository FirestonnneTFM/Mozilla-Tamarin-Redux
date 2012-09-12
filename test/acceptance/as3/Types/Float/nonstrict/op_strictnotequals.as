/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "floatUtil.as";


var SECTION = "6.8.4";
var VERSION = "AS3";
var TITLE   = "The !== operator";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var onef:float = 1f;
var zerof:float = 0.0f;
var onen:Number = 1;
var zeron:Number = 0.0;
var nd:Number = 1.111111111119;
var nf:float = nd; // rounds up
var ns:String = "1.111111111119";
var nd_down:Number = 0.51;
var nf_down:float = 0.51; // rounds down
var ns_down:String = "0.51"; // rounds down;
var no = new MyStringObject(nf);

function strictNotEquals(val1, val2)
{
    return (val1 !== val2);
}

// Let type1=Type(val1) and type2=Type(val2), If type1 is not the same as type2 then return false
AddTestCase("1f !== 1", true, (onef !== onen));
AddTestCase("1f FloatLiteral !== 1 NumberLiteral", false, (1f !== 1));
AddTestCase("strictNotEquals() 1f FloatLiteral !== 1 NumberLiteral", true, strictNotEquals(1f, 1));
AddTestCase("1.1f !== 1.1", true, (1.1f !== 1.1));
AddTestCase("strictNotEquals() 1.1f !== 1.1", true, strictNotEquals(1.1f, 1.1));
AddTestCase("float.NaN !== NaN", true, (float.NaN !== NaN));
AddTestCase("zerof !== -0.0", false, (zerof !== -0.0));
AddTestCase("nf !== Number(nf)", true, (nf !== Number(nf)));
AddTestCase("nf_down !== Number(nf_down)", true, (nf_down !== Number(nf_down)));

// Let type1=Type(val1) and type2=Type(val2), If type1 is not the same as type2 then return false
AddTestCase("1 !== 1f", true, (onen !== onef));
AddTestCase("1 NumberLiteral !== 1f FloatLiteral", false, (1 !== 1f));
AddTestCase("strictNotEquals() 1 NumberLiteral !== 1f FloatLiteral", true, strictNotEquals(1, 1f));
AddTestCase("1.1 !== 1.1f", true, (1.1 !== 1.1f));
AddTestCase("strictNotEquals() 1.1 !== 1.1f", true, strictNotEquals(1.1, 1.1f));
AddTestCase("Number.NaN !== float.NaN", true, (Number.NaN !== float.NaN));
AddTestCase("0.0 !== -zerof", false, (0.0 !== -zerof));
AddTestCase("Number(nf) !== nf", true, (Number(nf) !== nf));
AddTestCase("Number(nf_down) !== nf_down", true, (Number(nf_down) !== nf_down));


// 2 (c) If type1 is different from type2: return false
AddTestCase("undefined !== zerof", true, (undefined !== zerof));
AddTestCase("null !== zerof", true, (null !== zerof));
AddTestCase("false !== zerof", true, (false !== zerof));
AddTestCase("\"0\" !== zerof", true, ("0" !== zerof));
AddTestCase("strictNotEquals() \"0\" !== zerof", true, strictNotEquals("0", zerof));
AddTestCase("nf_down  !== String(nf_down)", true, (nf_down  !== String(nf_down)));
AddTestCase("new MyObject(nf)  !== nf", true, (new MyObject(nf)  !== nf));

// 6. If type1 is float:
// (a) If val1 is float.NaN return false.
AddTestCase("float.NaN !== onef", true, (float.NaN !== onef));
AddTestCase("float.NaN !== 1f", true, (float.NaN !== 1f));
AddTestCase("float.NaN !== (float.POSITIVE_INFINITY/float.NEGATIVE_INFINITY)", true, (float.NaN !== (float.POSITIVE_INFINITY/float.NEGATIVE_INFINITY)));

// (b) If val2 is float.NaN return false.
AddTestCase("onef !== float.NaN", true, (onef !== float.NaN));
AddTestCase("1f !== float.NaN", true, (1f !== float.NaN));
AddTestCase("(float.POSITIVE_INFINITY/float.NEGATIVE_INFINITY) !== float.NaN", true, ((float.POSITIVE_INFINITY/float.NEGATIVE_INFINITY) !== float.NaN));

// (c) If val1 is the same float value as val2, return true.
AddTestCase("float.MIN_VALUE !== float.MIN_VALUE-zerof", false, (float.MIN_VALUE !== float.MIN_VALUE-zerof));
AddTestCase("float.MAX_VALUE !== float.MIN_VALUE+float.MAX_VALUE", false, (float.MAX_VALUE !== float.MIN_VALUE+float.MAX_VALUE));
AddTestCase("float.NEGATIVE_INFINITY !== -float.POSITIVE_INFINITY", false, (float.NEGATIVE_INFINITY !== -float.POSITIVE_INFINITY));
AddTestCase("-float.NEGATIVE_INFINITY !== float.POSITIVE_INFINITY", false, (-float.NEGATIVE_INFINITY !== float.POSITIVE_INFINITY));
AddTestCase("onef !== 1f", false, (onef !== 1f));
AddTestCase("1f !== onef", false, (1f !== onef));
AddTestCase("float(0xFFFFFF00) !== float(0xFFFFFF01)", false, (float(0xFFFFFF00) !== float(0xFFFFFF01)));
AddTestCase("1.1f !== 1.100000023841858f", false, (1.1f !== 1.100000023841858f));
AddTestCase("strictNotEquals() 1.1f !== 1.100000023841858f", false, strictNotEquals(1.1f, 1.100000023841858f));

// (d) If val1 is +0 and val2 is -0, return true.
AddTestCase("zerof !== -zerof", false, (zerof !== -zerof));
AddTestCase("0f !== -0f", false, (0f !== -0f));
AddTestCase("strictNotEquals() 0f !== -0f", false, strictNotEquals(0f, -0f));

// (e) If val1 is -0 and val2 is +0, return true.
AddTestCase("-zerof !== zerof", false, (-zerof !== zerof));
AddTestCase("-0f !== 0f", false, (-0f !== 0f));
AddTestCase("strictNotEquals() -0f !== 0f", false, strictNotEquals(-0f, 0f));

// (f) Return false
AddTestCase("-onef !== onef", true, (-onef !== onef));
AddTestCase("-1f !== 1f", true, (-1f !== 1f));
AddTestCase("strictNotEquals() -1f !== 1f", true, strictNotEquals(-1f, 1f));

// 8. Return true if val1 and val2 refer to the same object. Otherwise, return false
AddTestCase("new MyObject(1f)  !== new MyObject(1f)", true, (new MyObject(1f)  !== new MyObject(1f)));
var var1 = new MyObject(1f);
AddTestCase("var1  !== var1", false, (var1  !== var1));

var nvo = new MyValueAlteringObject(nf);
AddTestCase(" '!==' , evaluation order", false,(nvo+1f) !== (zerof+nvo) );

test();

