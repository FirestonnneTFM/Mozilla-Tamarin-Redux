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


var SECTION = "6.8.4";
var VERSION = "AS3";
var TITLE   = "The !== operator";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var onef:float = 1f;
var zerof:float = 0.0;
var onen:float = 1;
var zeron:float = 0.0;
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

// 2 (a) If Type(x) is float and Type(y) is Number, return the result of the comparison ToNumber(x) == y.
AddTestCase("1f !== 1", false, (onef !== onen));
AddTestCase("1f FloatLiteral !== 1 NumberLiteral", false, (1f !== 1));
AddTestCase("strictNotEquals() 1f FloatLiteral !== 1 NumberLiteral", false, strictNotEquals(1f, 1));
AddTestCase("1.1f !== 1.1", true, (1.1f !== 1.1));
AddTestCase("strictNotEquals() 1.1f !== 1.1", true, strictNotEquals(1.1f, 1.1));
AddTestCase("float.NaN !== NaN", true, (float.NaN !== NaN));
AddTestCase("zerof !== -0.0", false, (zerof !== -0.0));
AddTestCase("nf !== Number(nf)", false, (nf !== Number(nf)));
AddTestCase("nf_down !== Number(nf_down)", false, (nf_down !== Number(nf_down)));

// 2 (b) If Type(x) is Number and Type(y) is float, return the result of the comparison x == ToNumber(y).
AddTestCase("1 !== 1f", false, (onen !== onef));
AddTestCase("1 NumberLiteral !== 1f FloatLiteral", false, (1 !== 1f));
AddTestCase("strictNotEquals() 1 NumberLiteral !== 1f FloatLiteral", false, strictNotEquals(1, 1f));
AddTestCase("1.1 !== 1.1f", true, (1.1 !== 1.1f));
AddTestCase("strictNotEquals() 1.1 !== 1.1f", true, strictNotEquals(1.1, 1.1f));
AddTestCase("Number.NaN !== float.NaN", true, (Number.NaN !== float.NaN));
AddTestCase("0.0 !== -zerof", false, (0.0 !== -zerof));
AddTestCase("Number(nf) !== nf", false, (Number(nf) !== nf));
AddTestCase("Number(nf_down) !== nf_down", false, (Number(nf_down) !== nf_down));


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
AddTestCase(" '!==' , evaluation order", false,(nvo+1) !== (zerof+nvo) );

test();

