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


var SECTION = "6.8.2";
var VERSION = "AS3";
var TITLE   = "The != operator";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

/*
1. If Type(x) is the same as Type(y), then
   a. If Type(x) is XMLList, x and y have the same number of properties, both the order and values of the properties match, return true.
   b. If Type(x) is XML, then [....]
   c. If Type(x) is Namespace and the x.uri == y.uri, return true
   d. If Type(x) is Qname, x.uri == y.uri, and x.localName == y.localName, return true
   e. If Type(x) is undefined, return true.
   f. If Type(x) is null, return true.
   g. If Type(x) is Number (respectively, float), then
       i.   If x is Number.NaN (respectively, float.NaN), return false.
       ii.  If y is Number.NaN (respectively, float.NaN), return false.
       iii. If x is the same Number (or float) value as y, return true.
       iv.  If x is +0 and y is -0, return true.
       v.   If x is -0 and y is +0, return true.
       vi.  Return false
   h. If Type(x) is String, then return true if x and y are exactly the same sequence of characters (same length and same characters in corresponding positions). Otherwise, return false.
   i. If Type(x) is Boolean, return true if x and y are both true or both false. Otherwise, return false.
   j. Return true if x and y refer to the same object. Otherwise, return false.
2. If x is null and y is undefined, return true.
3. If x is undefined and y is null, return true.
4. If Type(x) is Number and Type(y) is String, return the result of the comparison x == ToNumber(y).
5. If Type(x) is String and Type(y) is Number, return the result of the comparison ToNumber(x)== y.
6. If Type(x) is Boolean, return the result of the comparison ToNumber(x) == y.
7. If Type(y) is Boolean, return the result of the comparison x == ToNumber(y).
8. If Type(x) is XML and has simple content, return ToString(x) == ToString(y)
9. If Type(y) is XML and has simple content, r 9. eturn ToString(x) == ToString(y)
10.If Type(x) is XMLList, return true if either x.length is 0 and the other object is undefined or x.length is 1 and the only element of x equals (==) y.
11.If Type(y) is XMLList, return true if either y.length is 0 and the other object is undefined or
x.length is 1 and the only element of x equals (==) y.
12.If Type(x) is either String or Number or float and Type(y) is Object, return the result of the
comparison x == ToPrimitive(y).
13.If Type(x) is Object and Type(y) is either String or Number or float, return the result of the
comparison ToPrimitive(x) == y.
14. If Type(x) is float and Type(y) is String, return the result of the comparison x == ToFloat(y).
15. If Type(x) is String and Type(y) is float, return the result of the comparison ToFloat(x) == y.
16. If Type(x) is float and Type(y) is Number, return the result of the comparison ToNumber(x) == y.
17. If Type(x) is Number and Type(y) is float, return the result of the comparison x == ToNumber(y).
18. Return false.
*/
// TESTING note: we only need to test steps 1g and steps 12-17, as far as float is concerned.

var zerof:float = 0.0;
var onef:float = 1.0;
var nd:Number = 1.111111111119;
var nf:float = nd; // rounds up
var ns:String = "1.111111111119";
var nd_down:Number = 0.51;
var nf_down:float = 0.51; // rounds down
var ns_down:String = "0.51"; // rounds down;
var no = new MyStringObject(nf);

function notEquals(val1, val2)
{
    return (val1 != val2);
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
AddTestCase("float.NaN != 1f", true, (float.NaN != onef));
AddTestCase("float.NaN != float.NaN", true, (float.NaN != float.NaN));
AddTestCase("float.NaN != float.POSITIVE_INFINITY+float.NEGATIVE_INFINITY", true, (float.NaN!=float.POSITIVE_INFINITY+float.NEGATIVE_INFINITY));
AddTestCase("float.NaN != zerof", true, (float.NaN != zerof));

// ii.  If y is float.NaN, return false.
AddTestCase("1f != float.NaN", true, (1f != float.NaN));
AddTestCase("float.MIN_VALUE != float.NaN", true, (float.MIN_VALUE != float.NaN));
AddTestCase("float.POSITIVE_INFINITY+float.NEGATIVE_INFINITY != float.NaN", true, (float.POSITIVE_INFINITY+float.NEGATIVE_INFINITY!=float.NaN));
AddTestCase("zerof != float.NaN", true, (zerof != float.NaN));

// iii. If x is the same float value as y, return true.
AddTestCase("float.POSITIVE_INFINITY != float.POSITIVE_INFINITY", false, (float.POSITIVE_INFINITY != float.POSITIVE_INFINITY));
AddTestCase("float.POSITIVE_INFINITY != -float.NEGATIVE_INFINITY", false, (float.POSITIVE_INFINITY != -float.NEGATIVE_INFINITY));
AddTestCase("float.POSITIVE_INFINITY != float.POSITIVE_INFINITY-float.MAX_VALUE ", false, (float.POSITIVE_INFINITY != float.POSITIVE_INFINITY-float.MAX_VALUE ));
AddTestCase("float.NEGATIVE_INFINITY != float.NEGATIVE_INFINITY", false, (float.NEGATIVE_INFINITY != float.NEGATIVE_INFINITY));
AddTestCase("-float.POSITIVE_INFINITY != float.NEGATIVE_INFINITY", false, (-float.POSITIVE_INFINITY != float.NEGATIVE_INFINITY));
AddTestCase("float.NEGATIVE_INFINITY != float.NEGATIVE_INFINITY+float.MAX_VALUE ", false, (float.NEGATIVE_INFINITY != float.NEGATIVE_INFINITY+float.MAX_VALUE ));
AddTestCase("zerof != zerof", false, (zerof != zerof));
AddTestCase("-zerof != -zerof", false, (-zerof != -zerof));
AddTestCase("1f != onef", false, (1f != onef));

// iv.  If x is +0f and y is -0f, return true.
AddTestCase("zerof != -zerof", false, (zerof != -zerof));
AddTestCase("0f != -0f", false, (0f != -0f));
AddTestCase("notEquals() 0f != -0f", false, notEquals(0f, -0f));

// v.   If x is -0f and y is +0f, return true.
AddTestCase("-zerof != zerof", false, (-zerof != zerof));
AddTestCase("-0f != 0f", false, (-0f != 0f));
AddTestCase("notEquals() -0f != 0f", false, notEquals(-0f, 0f));

// vi.  Return false
AddTestCase("zerof != float.MIN_VALUE", true, (zerof != float.MIN_VALUE));
AddTestCase("-float.MIN_VALUE != zerof", true, ( -float.MIN_VALUE != zerof));
AddTestCase("float.POSITIVE_INFINITY != float.MAX_VALUE ", true, (float.POSITIVE_INFINITY != float.MAX_VALUE ));
AddTestCase("float.NEGATIVE_INFINITY != -float.MAX_VALUE ", true, (float.NEGATIVE_INFINITY != -float.MAX_VALUE ));
AddTestCase("nf != float.MIN_VALUE", true, (nf != float.MIN_VALUE));
AddTestCase("-float.MIN_VALUE == float.MIN_VALUE ", false, (-float.MIN_VALUE == float.MIN_VALUE ));



// 5. If type1 is Number and type2 is String or float, return the result of the comparison val1 != ToNumber (val2).
//"Number != Number(float), i.e. '!=' calls ToNumber on float; round_up test";
AddTestCase("nd != nf", true, (nd != nf));
AddTestCase("nf != Number(nf)", false, (Number(nf) != nf));
//"Number != Number(float), i.e. '!=' calls ToNumber on float; round_down test";
AddTestCase("nd_down != ndfdown", true, (nd_down != nf_down));
AddTestCase("Number(nf_down) != nf_down ", false, (Number(nf_down) != nf_down ));
// If this comparision is false, then the largeNumber was converted to float
var largeNumber:Number = 3.40282346638529e+38;
AddTestCase("largeNumber != float.POSITIVE_INFINITY", true, (largeNumber != float.POSITIVE_INFINITY));
// If this comparision is false, then Number.MIN_VALUE was converted to float
AddTestCase("Number.MIN_VALUE != 0f", true, (Number.MIN_VALUE != 0f));
AddTestCase("float(Number.MIN_VALUE) != 0f", false, (float(Number.MIN_VALUE) != 0f));

// 6. If type1 is String or a float and type2 is Number, return the result of the comparison ToNumber (val1) != val2.
//"Number(float) != Number, i.e. '!=' calls ToNumber on float; round_up test";
AddTestCase("nf != nd", true, (nf != nd));
AddTestCase("Number(nf) != nf", false, ( nf != Number(nf)));
//"Number(float) != Number, i.e. '!=' calls ToNumber on float; round_down test";
AddTestCase("nf_down != nd_down", true, (nf_down != nd_down));
AddTestCase("Number(nf_down) != nf_down ", false, (nf_down != Number(nf_down) ));
// If this comparision is false, then the largeNumber was converted to float
var largeNumber:Number = 3.40282346638529e+38;
AddTestCase("float.POSITIVE_INFINITY != largeNumber", true, (float.POSITIVE_INFINITY != largeNumber));
// If this comparision is false, then Number.MIN_VALUE was converted to float
AddTestCase("0f != Number.MIN_VALUE", true, (0f != Number.MIN_VALUE));
AddTestCase("0f != float(Number.MIN_VALUE)", false, (0f != float(Number.MIN_VALUE)));



// 13. If type1 is either String, Number or float and type2 is Object, return the result of the comparison val1 == ToPrimitive(val2).
AddTestCase("ns != no", true, (ns != no));
//"Object != float; ToPrimitive should return float, which in turn should compare via ToFloat - hence, equality";
AddTestCase("nf != no", false, (nf != no));
//"Object != float; ToPrimitive should return Number - hence, inequality first, equality next";
AddTestCase("nf != new MyObject(nd)", true, (nf != new MyObject(nd)));
AddTestCase("nf == new MyObject(Number(nf))", true, (nf == new MyObject(Number(nf))));

// If this comparision is true, then the largeNumber was converted to float
var largeNumber:Number = 3.40282346638529e+38;
AddTestCase("float.POSITIVE_INFINITY == new MyObject(largeNumber)", false, (float.POSITIVE_INFINITY == new MyObject(largeNumber)));
// If this comparision is true, then Number.MIN_VALUE was converted to float
AddTestCase("0f == new MyObject(Number.MIN_VALUE)", false, (0f == new MyObject(Number.MIN_VALUE)));

//"Object != Number; but the float.ToString rendering is precise, so the equality should fail.";
AddTestCase("nd != no", true, (nd != no));


// 14. If type1 is Object and type2 is either String, Number or float, return the result of the comparison ToPrimitive(val1) == val2.
AddTestCase("no != ns", true, (no != ns));
//"Object != float; ToPrimitive should return float, which in turn should compare via ToFloat - hence, equality";
AddTestCase("no != nf", false, (no != nf));
//"Object != float; ToPrimitive should return Number - hence, inequality first, equality next";
AddTestCase("new MyObject(Number(nf)) != nf", false, (new MyObject(Number(nf)) != nf));
//"Object == float; ToPrimitive should return Number - hence, inequality first, equality next";
AddTestCase("new MyObject(nd) == nf", false, (new MyObject(nd) == nf));
AddTestCase("new MyObject(Number(nf)) == nf", true, (new MyObject(Number(nf)) == nf));

// If this comparision is true, then the largeNumber was converted to float
var largeNumber:Number = 3.40282346638529e+38;
AddTestCase("new MyObject(largeNumber) == float.POSITIVE_INFINITY", false, (new MyObject(largeNumber) == float.POSITIVE_INFINITY));
// If this comparision is true, then Number.MIN_VALUE was converted to float
AddTestCase("new MyObject(Number.MIN_VALUE) == 0f", false, (new MyObject(Number.MIN_VALUE) == 0f));

//"Object != Number; but the float.ToString rendering is precise, so the equality should fail.";
AddTestCase("no != nd", true, (no != nd));



//"float != String; ToFloat called on String (round_up test)";
AddTestCase("nf != ns", true, (nf != ns));
//"float != String; ToFloat called on String (round_down test)";
AddTestCase(" ns_down != nf_down", true, ( ns_down != nf_down));
AddTestCase(" nf_down != ns_down", true, ( nf_down != ns_down));


/// some last extra tests
AddTestCase("zerof != null", true, (zerof != null));
AddTestCase("null != zerof", true, (null != zerof));
AddTestCase("undefined != zerof", true, (undefined != zerof));
AddTestCase("zerof != undefined", true, (zerof != undefined));


// Step 16-17:
//"float(number) != number, i.e. '!=' calls ToNumber on float; round_up test";
AddTestCase("nd != nf", true, (nd != nf));
AddTestCase("nf != Number(nf)", false, (nf != Number(nf)));
//"float(number) != number, i.e. '!=' calls ToNumber on float; round_down test";
AddTestCase("nf_down != nd_down", true, (nf_down != nd_down));
AddTestCase("Number(nf_down) != nf_down ", false, (Number(nf_down) != nf_down ));





// Section 6.8.1 - 6.8.2:  evaluation order (first operand evaluated first):
var nvo = new MyValueAlteringObject(nf);
AddTestCase(" '!=' , evaluation order", false, (nvo+1) != (0+nvo) ); // (0+1)!=(2-1)

AddTestCase("new MyObject(float(0xFFFFFF00)) != 0xFFFFFF01)", true, (new MyObject(float(0xFFFFFF00)) != 0xFFFFFF01));

// Weirdo case
var v3 = new MyObject(float(0xFFFFFF00));
var v4 = "4294967041"; // i.e. 0xFFFFFF01
// typeof v3.valueOf() -> float
// but v4 is a string so it will be a Number
AddTestCase("Weirdo spec behaviour: Object!=String, when ToPrimitive(Object)=float", true, v3!=v4);
v3++;
v4++;
// After post-increment, these should become Nubmer, and no longer equal
AddTestCase("Weirdo spec behaviour: after post-increment", true, v3!=v4);

test();

