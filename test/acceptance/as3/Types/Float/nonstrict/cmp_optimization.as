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

import avmplus.*;

var SECTION = "8.4";
var VERSION = "AS3";
var TITLE   = "Verify type-specialized implementations of relational operators involving float";

// Code coverage test for type-specialized comparisions, e.g., cmpOptimization() in CodegenLIR.
// Verify that specialized comparisons produce the same result as untyped comparisons.  We're
// not looking to verify the underlying mathematics of the comparisions, but rather that the
// case analysis for the type specialization is correct and the correct coercions are performed.

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function Cmp_Float_Float(op:String, x:float, y:float):Boolean
{
    var res:Boolean = false;
    switch (op) {
    case "<":   return x < y;   break;
    case "<=":  return x <= y;  break;
    case ">":   return x > y;   break;
    case ">=":  return x >= y;  break;
    case "==":  return x == y;  break;
    case "!=":  return x != y;  break;
    case "===": return x === y; break;
    case "!==": return x !== y; break;
    }
    return res;
}

function Cmp_Float_Number(op:String, x:float, y:Number):Boolean
{
    var res:Boolean = false;
    switch (op) {
    case "<":   return x < y;   break;
    case "<=":  return x <= y;  break;
    case ">":   return x > y;   break;
    case ">=":  return x >= y;  break;
    case "==":  return x == y;  break;
    case "!=":  return x != y;  break;
    case "===": return x === y; break;
    case "!==": return x !== y; break;
    }
    return res;
}

function Cmp_Number_Float(op:String, x:Number, y:float):Boolean
{
    var res:Boolean = false;
    switch (op) {
    case "<":   return x < y;   break;
    case "<=":  return x <= y;  break;
    case ">":   return x > y;   break;
    case ">=":  return x >= y;  break;
    case "==":  return x == y;  break;
    case "!=":  return x != y;  break;
    case "===": return x === y; break;
    case "!==": return x !== y; break;
    }
    return res;
}

function Cmp_Float_Date(op:String, x:float, y:Date):Boolean
{
    var res:Boolean = false;
    switch (op) {
    case "<":   return x < y;   break;
    case "<=":  return x <= y;  break;
    case ">":   return x > y;   break;
    case ">=":  return x >= y;  break;
    case "==":  return x == y;  break;
    case "!=":  return x != y;  break;
    case "===": return x === y; break;
    case "!==": return x !== y; break;
    }
    return res;
}

function Cmp_Date_Float(op:String, x:Date, y:float):Boolean
{
    var res:Boolean = false;
    switch (op) {
    case "<":   return x < y;   break;
    case "<=":  return x <= y;  break;
    case ">":   return x > y;   break;
    case ">=":  return x >= y;  break;
    case "==":  return x == y;  break;
    case "!=":  return x != y;  break;
    case "===": return x === y; break;
    case "!==": return x !== y; break;
    }
    return res;
}

function Cmp_Float_String(op:String, x:float, y:String):Boolean
{
    var res:Boolean = false;
    switch (op) {
    case "<":   return x < y;   break;
    case "<=":  return x <= y;  break;
    case ">":   return x > y;   break;
    case ">=":  return x >= y;  break;
    case "==":  return x == y;  break;
    case "!=":  return x != y;  break;
    case "===": return x === y; break;
    case "!==": return x !== y; break;
    }
    return res;
}

function Cmp_String_Float(op:String, x:String, y:float):Boolean
{
    var res:Boolean = false;
    switch (op) {
    case "<":   return x < y;   break;
    case "<=":  return x <= y;  break;
    case ">":   return x > y;   break;
    case ">=":  return x >= y;  break;
    case "==":  return x == y;  break;
    case "!=":  return x != y;  break;
    case "===": return x === y; break;
    case "!==": return x !== y; break;
    }
    return res;
}

function Cmp_Float_Any(op:String, x:float, y):Boolean
{
    var res:Boolean = false;
    switch (op) {
    case "<":   return x < y;   break;
    case "<=":  return x <= y;  break;
    case ">":   return x > y;   break;
    case ">=":  return x >= y;  break;
    case "==":  return x == y;  break;
    case "!=":  return x != y;  break;
    case "===": return x === y; break;
    case "!==": return x !== y; break;
    }
    return res;
}

function Cmp_Any_Float(op:String, x, y:float):Boolean
{
    var res:Boolean = false;
    switch (op) {
    case "<":   return x < y;   break;
    case "<=":  return x <= y;  break;
    case ">":   return x > y;   break;
    case ">=":  return x >= y;  break;
    case "==":  return x == y;  break;
    case "!=":  return x != y;  break;
    case "===": return x === y; break;
    case "!==": return x !== y; break;
    }
    return res;
}

function Cmp_Any_Any(op:String, x, y):Boolean
{
    var res:Boolean = false;
    switch (op) {
    case "<":   return x < y;   break;
    case "<=":  return x <= y;  break;
    case ">":   return x > y;   break;
    case ">=":  return x >= y;  break;
    case "==":  return x == y;  break;
    case "!=":  return x != y;  break;
    case "===": return x === y; break;
    case "!==": return x !== y; break;
    }
    return res;
}

function AddTest(lht:String, op:String, rht:String, fun, x, y)
{
    var actual:Boolean = fun(op, x, y);
    var expected:Boolean = Cmp_Any_Any(op, x, y);
    var testname:String =  x + ":" + lht + " " + op + " " + y + ":" + rht;
    //var result:String = (actual === expected) ? "PASSED" : ("FAILED, expected " + expected);
    //trace(testname + " => " + result);
    AddTestCase(testname, expected, actual);
}

function TestComparisons(xt, yt, fun, x, y)
{
    AddTest(xt, "<",   yt, fun, x, y);
    AddTest(xt, "<=",  yt, fun, x, y);
    AddTest(xt, ">",   yt, fun, x, y);
    AddTest(xt, ">=",  yt, fun, x, y);
    AddTest(xt, "==",  yt, fun, x, y);
    AddTest(xt, "!=",  yt, fun, x, y);
    AddTest(xt, "===", yt, fun, x, y);
    AddTest(xt, "!==", yt, fun, x, y);
}

function TestNumericTypes(x, y)
{
    TestComparisons("float",  "float",   Cmp_Float_Float,    float(x),     float(y)    );
    TestComparisons("float",  "Number",  Cmp_Float_Number,   float(x),     Number(y)   );
    TestComparisons("Number", "float",   Cmp_Number_Float,   Number(x),    float(y)    );
}

function TestObjectTypes(x, y)
{
    TestNumericTypes(x, y);

    TestComparisons("float",  "Date",    Cmp_Float_Date,     float(x),     new Date(y) );
    TestComparisons("Date",   "float",   Cmp_Date_Float,     new Date(x),  float(y)    );
    TestComparisons("float",  "String",  Cmp_Float_String,   float(x),     String(y)   );
    TestComparisons("String", "float",   Cmp_String_Float,   String(x),    float(y)    );
    TestComparisons("float",  "*",       Cmp_Float_Any,      float(x),     y           );
    TestComparisons("*",      "float",   Cmp_Any_Float,      x,            float(y)    );
}

function TestSpecialsAnyX(x, y)
{
    TestComparisons("*",      "float",   Cmp_Any_Float,      x,            float(y)    );
}

function TestSpecialsAnyY(x, y)
{
    TestComparisons("float",  "*",       Cmp_Float_Any,      float(x),     y           );
}

function TestSpecialsTypedX(x, y)
{
    TestSpecialsAnyX(x, y);

    TestComparisons("Date",   "float",   Cmp_Date_Float,     x,            float(y)    );
    TestComparisons("String", "float",   Cmp_String_Float,   x,            float(y)    );
}

function TestSpecialsTypedY(x, y)
{
    TestSpecialsAnyY(x, y);

    TestComparisons("float",  "Date",    Cmp_Float_Date,     float(x),     y           );
    TestComparisons("float",  "String",  Cmp_Float_String,   float(x),     y           );
}

function TestValues()
{
    // Zero is interesting, as it is the result of likely coercions.

    TestObjectTypes(0, 0);
    TestObjectTypes(0, 1);
    TestObjectTypes(1, 0);
    TestObjectTypes(1, 1);

    TestNumericTypes(NaN, 0);
    TestNumericTypes(NaN, 1);
    TestNumericTypes(0,   NaN);
    TestNumericTypes(1,   NaN);
    TestNumericTypes(NaN, NaN);

    TestSpecialsTypedX(null, 0);
    TestSpecialsTypedX(null, 1);

    TestSpecialsTypedY(0, null);
    TestSpecialsTypedY(1, null);

    // Undefined is converted to null when coerced to an object type,
    // e.g., when passed as a Date or String parameter.

    TestSpecialsAnyX(undefined, 0);
    TestSpecialsAnyX(undefined, 1);
    TestSpecialsAnyX(true, 0);
    TestSpecialsAnyX(true, 1);
    TestSpecialsAnyX(false, 0);
    TestSpecialsAnyX(false, 1);

    TestSpecialsAnyY(0, undefined);
    TestSpecialsAnyY(1, undefined);
    TestSpecialsAnyY(0, true);
    TestSpecialsAnyY(1, true);
    TestSpecialsAnyY(0, false);
    TestSpecialsAnyY(1, false);
}

TestValues();

test();
