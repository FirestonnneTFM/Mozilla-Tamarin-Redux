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
var TITLE   = "Specialized Addition Helper Functions";
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

var z = null;
var z_n:Number = z;

var n = new Namespace("http://www.example.com/");
var n_n:Number = n;

var s = "foo";
var s_s:String = s;

var o = new Object();
var o_s:String = o;

var d = new Date(0);
var d_s:String = d;

var x = new XML("<a><b/></a>");
var x_s:String = x;

var l = new XMLList("<a>one</a><b>two</b>");
var l_s:String = l;

var int32_max = 2147483647;

// We test cases in which a numeric value is added/concatenated to a non-numeric atom.
// We characterize the value of the non-numeric atom as to whether it results in a numeric
// addition or a string concatentation, i.e., behaves like a number or a string, when
// combined with a number.

function LikeNumber(i, a, a_n:Number)
{
    var i_n:Number = i;

    //NOTE: We assume that typed Number + Number addition functions correctly.

    if (i <= int32_max) {
        AddIntToAtom (i, a, i_n + a_n);
        AddAtomToInt (a, i, a_n + i_n);
    }
    AddDoubleToAtom  (i, a, i_n + a_n);
    AddAtomToDouble  (a, i, a_n + i_n);
    AddAtomToAtom    (i, a, i_n + a_n);
    AddAtomToAtom    (a, i, a_n + i_n);
}

function LikeString(i, a, a_s:String)
{
    var i_s:String = i;

    //NOTE: We assume that typed String + String concatenation functions correctly.

    if (i <= int32_max) {
        AddIntToAtom (i, a, i_s + a_s);
        AddAtomToInt (a, i, a_s + i_s);
    }
    AddDoubleToAtom  (i, a, i_s + a_s);
    AddAtomToDouble  (a, i, a_s + i_s);
    AddAtomToAtom    (i, a, i_s + a_s);
    AddAtomToAtom    (a, i, a_s + i_s);
}

function TryIntValue(i)
{
    LikeNumber(i, z, z_n);  // null
    LikeNumber(i, n, n_n);  // Namespace

    LikeString(i, s, s_s);  // String
    LikeString(i, o, o_s);  // Object
    LikeString(i, d, d_s);  // Date
    LikeString(i, x, x_s);  // XML
    LikeString(i, l, l_s);  // XMLList
}

var i = 555;               // Fits in 29-bit intptr
var j = 555555555;         // Won't fit in 29-bit intptr
var k = 5555555555555555;  // Won't fit in 53-bit intptr

function getTestCases()
{
   TryIntValue(i);
   TryIntValue(j);
   TryIntValue(k);

   return array;
}

var testcases = getTestCases();
test();
