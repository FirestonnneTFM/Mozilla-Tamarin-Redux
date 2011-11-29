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


var SECTION = "6.8.1";
var VERSION = "AS3";
var TITLE   = "The == operator";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var zerof:float = 0.0;
var onef:float = 1.0;
var nd:Number = 1.111111111119;
var nf:float = nd; // rounds up
var ns:String = "1.111111111119";
var nd_down:Number = 0.51;
var nf_down:float = 0.51; // rounds down
var ns_down:String = "0.51"; // rounds down;
var no = new MyStringObject(nf);

function equals(val1, val2)
{
    return (val1 == val2);
}

// Step 1g+
/*
   g+. If Type(x) is float, then
       i.   If x is float.NaN, return false.
       ii.  If y is float.NaN, return false.
       iii. If x is the same float value as y, return true.
       iv.  If x is +0f and y is -0f, return true.
       v.   If x is -0f and y is +0f, return true.
       vi.  Return false
*/

// i.   If x is float.NaN, return false.
AddTestCase("float.NaN == 1f", false, (float.NaN == onef));
AddTestCase("float.NaN == float.NaN", false, (float.NaN == float.NaN));
AddTestCase("float.NaN == float.POSITIVE_INFINITY+float.NEGATIVE_INFINITY", false, (float.NaN==float.POSITIVE_INFINITY+float.NEGATIVE_INFINITY));
AddTestCase("float.NaN == zerof", false, (float.NaN == zerof));

// ii.  If y is float.NaN, return false.
AddTestCase("1f == float.NaN", false, (1f == float.NaN));
AddTestCase("float.MIN_VALUE == float.NaN", false, (float.MIN_VALUE == float.NaN));
AddTestCase("float.POSITIVE_INFINITY+float.NEGATIVE_INFINITY==float.NaN", false, (float.POSITIVE_INFINITY+float.NEGATIVE_INFINITY==float.NaN));
AddTestCase("zerof == float.NaN", false, (zerof == float.NaN));

// iii. If x is the same float value as y, return true.
AddTestCase("float.POSITIVE_INFINITY == float.POSITIVE_INFINITY", true, (float.POSITIVE_INFINITY == float.POSITIVE_INFINITY));
AddTestCase("float.POSITIVE_INFINITY == -float.NEGATIVE_INFINITY", true, (float.POSITIVE_INFINITY == -float.NEGATIVE_INFINITY));
AddTestCase("float.POSITIVE_INFINITY == float.POSITIVE_INFINITY-float.MAX_VALUE ", true, (float.POSITIVE_INFINITY == float.POSITIVE_INFINITY-float.MAX_VALUE ));
AddTestCase("float.NEGATIVE_INFINITY == float.NEGATIVE_INFINITY", true, (float.NEGATIVE_INFINITY == float.NEGATIVE_INFINITY));
AddTestCase("-float.POSITIVE_INFINITY == float.NEGATIVE_INFINITY", true, (-float.POSITIVE_INFINITY == float.NEGATIVE_INFINITY));
AddTestCase("float.NEGATIVE_INFINITY == float.NEGATIVE_INFINITY+float.MAX_VALUE ", true, (float.NEGATIVE_INFINITY == float.NEGATIVE_INFINITY+float.MAX_VALUE ));
AddTestCase("zerof == zerof", true, (zerof == zerof));
AddTestCase("-zerof == -zerof", true, (-zerof == -zerof));
AddTestCase("1f == onef", true, (1f == onef));

// iv.  If x is +0f and y is -0f, return true.
AddTestCase("zerof == -zerof", true, (zerof == -zerof));
AddTestCase("0f == -0f", true, (0f == -0f));
AddTestCase("equals() 0f == -0f", true, equals(0f, -0f));

// v.   If x is -0f and y is +0f, return true.
AddTestCase("-zerof == zerof", true, (-zerof == zerof));
AddTestCase("-0f == 0f", true, (-0f == 0f));
AddTestCase("equals() -0f == 0f", true, equals(-0f, 0f));

// vi.  Return false
AddTestCase("zerof == float.MIN_VALUE", false, (zerof == float.MIN_VALUE));
AddTestCase("-float.MIN_VALUE == zerof", false, ( -float.MIN_VALUE == zerof));
AddTestCase("float.POSITIVE_INFINITY == float.MAX_VALUE ", false, (float.POSITIVE_INFINITY == float.MAX_VALUE ));
AddTestCase("float.NEGATIVE_INFINITY == -float.MAX_VALUE ", false, (float.NEGATIVE_INFINITY == -float.MAX_VALUE ));
AddTestCase("nf == float.MIN_VALUE", false, (nf == float.MIN_VALUE));
AddTestCase("-float.MIN_VALUE == float.MIN_VALUE ", false, (-float.MIN_VALUE == float.MIN_VALUE ));



// 5. If type1 is Number and type2 is String or float, return the result of the comparison val1 == ToNumber (val2).
//"Number == Number(float), i.e. '==' calls ToNumber on float; round_up test";
AddTestCase("nd == nf", false, (nd == nf));
AddTestCase("nf == Number(nf)", true, (Number(nf) == nf));
//"Number == Number(float), i.e. '==' calls ToNumber on float; round_down test";
AddTestCase("nd_down == ndfdown", false, (nd_down == nf_down));
AddTestCase("Number(nf_down) == nf_down ", true, (Number(nf_down) == nf_down ));
// If this comparision is true, then the largeNumber was converted to float
var largeNumber:Number = 3.40282346638529e+38;
AddTestCase("largeNumber == float.POSITIVE_INFINITY", false, (largeNumber == float.POSITIVE_INFINITY));
// If this comparision is true, then Number.MIN_VALUE was converted to float
AddTestCase("Number.MIN_VALUE == 0f", false, (Number.MIN_VALUE == 0f));
AddTestCase("float(Number.MIN_VALUE) == 0f", true, (float(Number.MIN_VALUE) == 0f));



// 6. If type1 is String or a float and type2 is Number, return the result of the comparison ToNumber (val1) == val2.
//"Number(float) == Number, i.e. '==' calls ToNumber on float; round_up test";
AddTestCase("nf == nd", false, (nf == nd));
AddTestCase("Number(nf) == nf", true, ( nf == Number(nf)));
//"Number(float) == Number, i.e. '==' calls ToNumber on float; round_down test";
AddTestCase("nf_down == nd_down", false, (nf_down == nd_down));
AddTestCase("Number(nf_down) == nf_down ", true, (nf_down == Number(nf_down) ));
// If this comparision is true, then the largeNumber was converted to float
var largeNumber:Number = 3.40282346638529e+38;
AddTestCase("float.POSITIVE_INFINITY == largeNumber", false, (float.POSITIVE_INFINITY == largeNumber));
// If this comparision is true, then Number.MIN_VALUE was converted to float
AddTestCase("0f == Number.MIN_VALUE", false, (0f == Number.MIN_VALUE));
AddTestCase("0f == float(Number.MIN_VALUE)", true, (0f == float(Number.MIN_VALUE)));


// 13. If type1 is either String, Number or float and type2 is Object, return the result of the comparison val1 == ToPrimitive(val2).
AddTestCase("ns == no", false, (ns == no));
//"float == Object; ToPrimitive should return float, which in turn should compare via ToFloat - hence, equality";
AddTestCase("nf == no", true, (nf == no));
//"float == Object; ToPrimitive should return Number - hence, inequality first, equality next";
AddTestCase("nf == new MyObject(nd)", false, (nf == new MyObject(nd)));
AddTestCase("nf == new MyObject(Number(nf))", true, (nf == new MyObject(Number(nf))));

// If this comparision is true, then the largeNumber was converted to float
var largeNumber:Number = 3.40282346638529e+38;
AddTestCase("float.POSITIVE_INFINITY == new MyObject(largeNumber)", false, (float.POSITIVE_INFINITY == new MyObject(largeNumber)));
// If this comparision is true, then Number.MIN_VALUE was converted to float
AddTestCase("0f == new MyObject(Number.MIN_VALUE)", false, (0f == new MyObject(Number.MIN_VALUE)));

//"Number == Object; but the float.ToString rendering is precise, so the equality should fail.";
AddTestCase("nd == no", false, (nd == no));



// 14. If type1 is Object and type2 is either String, Number or float, return the result of the comparison ToPrimitive(val1) == val2.
AddTestCase("no == ns", false, (no == ns));
//"Object == float; ToPrimitive should return float, which in turn should compare via ToFloat - hence, equality";
AddTestCase("no == nf", true, (no == nf));
//"Object == float; ToPrimitive should return Number - hence, inequality first, equality next";
AddTestCase("new MyObject(nd) == nf", false, (new MyObject(nd) == nf));
AddTestCase("new MyObject(Number(nf)) == nf", true, (new MyObject(Number(nf)) == nf));

// If this comparision is true, then the largeNumber was converted to float
var largeNumber:Number = 3.40282346638529e+38;
AddTestCase("new MyObject(largeNumber) == float.POSITIVE_INFINITY", false, (new MyObject(largeNumber) == float.POSITIVE_INFINITY));
// If this comparision is true, then Number.MIN_VALUE was converted to float
AddTestCase("new MyObject(Number.MIN_VALUE) == 0f", false, (new MyObject(Number.MIN_VALUE) == 0f));

//"Object == Number; but the float.ToString rendering is precise, so the equality should fail.";
AddTestCase("no == nd", false, (no == nd));

//"float == String; ToFloat called on String (round_up test)";
// nf == ToNumeric(ns) (8.a) -> nf = ToNumber(ns)
AddTestCase("nf == ns", false, (nf == ns));
//"float == String; ToFloat called on String (round_down test)";
AddTestCase(" ns_down == nf_down", false, ( ns_down == nf_down));
AddTestCase(" ns_down == nf_down", true, ( nf_down == nf_down));


/// some last extra tests
AddTestCase("zerof == null", false, (zerof == null));
AddTestCase("null == zerof", false, (null == zerof));
AddTestCase("undefined == zerof", false, (undefined == zerof));
AddTestCase("zerof == undefined", false, (zerof == undefined));


// Section 6.8.1 - 6.8.2:  evaluation order (first operand evaluated first):
var nvo = new MyValueAlteringObject(nf);
AddTestCase(" '==' , evaluation order", true, (0+nvo)==(nvo-1)); // (0+1)==(2-1)


AddTestCase("new MyObject(float(0xFFFFFF00)) == 0xFFFFFF01)", false, (new MyObject(float(0xFFFFFF00)) == 0xFFFFFF01));

// Weirdo case for Step 14
var v3 = new MyObject(float(0xFFFFFF00));
var v4 = "4294967041"; // i.e. 0xFFFFFF01
// typeof v3.valueOf() -> float
// but v4 is a string so it will be a Number
AddTestCase("Weirdo spec behaviour: Object==String, when ToPrimitive(Object)=float", false, v3==v4);
v3++;
v4++;
// After post-increment, these should become Nubmer, and no longer equal
AddTestCase("Weirdo spec behaviour: after post-increment", true, v3!=v4);


test();

