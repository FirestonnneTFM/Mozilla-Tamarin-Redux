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


var SECTION = "6.8.3";
var VERSION = "AS3";
var TITLE   = "The === operator";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var zerof:float =0.0;
var nd:Number = 1.111111111119;
var nf:float = nd; // rounds up
var ns:String = "1.111111111119";
var nd_down:Number = 0.51;
var nf_down:float = 0.51; // rounds down
var ns_down:String = "0.51"; // rounds down;
var no = new MyStringObject(nf);

/* Strict equality comparison:
1. If Type(x) is different from Type(y), then
   a. If Type(x) is float and Type(y) is Number, return the result of the comparison ToNumber(x) == y.
   b. If Type(x) is Number and Type(y) is float, return the result of the comparison x == ToNumber(y).
   c. return false
2. If Type(x) is undefined, return true.
3. If Type(x) is null, return true.
4. If Type(x) is Number (respectively, float), then
   a. If x is Number.NaN (respectively, float.NaN), return false.
   b. If y is Number.NaN (respectively, float.NaN), return false.
   c. If x is the same Number (respectively, float) value as y, return true.
   d. If x is +0 and y is -0, return true.
   e. If x is -0 and y is +0, return true.
   f. Return false
5. If Type(x) is String, then return true if x and y are exactly the same sequence of characters (same length and same characters in corresponding positions). Otherwise, return false.
6. If Type(x) is Boolean, return true if x and y are both true or both false; otherwise, return false.
7. Return true if x and y refer to the same object. Otherwise, return false.
*/
//TEST NOTE: we test points "1" and and "4" only.



AddTestCase("float.NaN === NaN", false, (float.NaN === NaN));
AddTestCase("Number.NaN === float.NaN", false, (Number.NaN === float.NaN));
AddTestCase("zerof === -0.0", true, (zerof === -0.0));
AddTestCase("0.0 === -zerof", true, (0.0 === -zerof));
AddTestCase("zerof === -zerof", true, (zerof === -zerof));
AddTestCase("-zerof === zerof", true, (-zerof === zerof));
AddTestCase("nf === Number(nf)", false, (nf === Number(nf)));
AddTestCase("nf_down === Number(nf_down)", false, (nf_down === Number(nf_down)));
AddTestCase("float.MIN_VALUE === float.MIN_VALUE-zerof", true, (float.MIN_VALUE === float.MIN_VALUE-zerof));
AddTestCase("float.MAX_VALUE === float.MIN_VALUE+float.MAX_VALUE", true, (float.MAX_VALUE === float.MIN_VALUE+float.MAX_VALUE));
AddTestCase("float.NEGATIVE_INFINITY === -float.POSITIVE_INFINITY", true, (float.NEGATIVE_INFINITY === -float.POSITIVE_INFINITY));
AddTestCase("-float.NEGATIVE_INFINITY === float.POSITIVE_INFINITY", true, (-float.NEGATIVE_INFINITY === float.POSITIVE_INFINITY));
AddTestCase("new MyObject(nf)  === nf", false, (new MyObject(nf)  === nf));
AddTestCase("nf_down  === String(nf_down)", false, (nf_down  === String(nf_down)));

/// some last extra tests
AddTestCase("null === zerof", false, (null === zerof));
AddTestCase("zerof === undefined", false, (zerof === undefined));

var nvo = new MyValueAlteringObject(nf);
AddTestCase("Evaluation order: '===' ", true, (zerof+nvo) === (nvo-1f));

test();

