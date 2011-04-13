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
 * Portions created by the Initial Developer are Copyright (C) 2007-2008
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
/**
   File Name:    nonindexproperty.es
   Description:  Vector properties not uint will throw a runtime error.
   		 the exception is a current issue with properties defined in the prototype.
   *
   * Coverage is rather poor, and this test has been superseded by vectorIndexRangeExceptions.as for
   * SWF version 11 and above.  It is retained to preserve existing tests applicable to prior versions.
   */

import avmplus.System;

var SECTION = " ";
var VERSION = "AS3";
startTest();
writeHeaderToLog( SECTION + " Vector non-index properties");

Vector.<*>.prototype[3.14]="three";
var v1:Vector.<*>=new Vector.<*>();

v1[0]="zero";
v1["1"]="one";
v1[2.0]="two";
v1["3.0"]="three";

AddTestCase(    "standard 0 uint index",
		"zero",
		v1[0]);
AddTestCase(    "uint 1 as string index",
		"one",
		v1[1]);
AddTestCase(    "number 3.0 as string index",
		"two",
		v1[2]);
AddTestCase(    "number 2.0 index",
		"three",
		v1["3.0"]);


var NONE      = "exception not thrown";
var RANGE     = "RangeError: Error #1125";
var REFREAD   = "ReferenceError: Error #1069";
var REFWRITE  = "ReferenceError: Error #1056";

// Index is generic (Atom).

function AddVectorReadExceptionTest(description, index, expected)
{
    var err = "exception not thrown";
    try {
        v1[index] == description;  // read
    } catch(e) {
        err = e.toString();
    }

    AddTestCase("read index " + description + " throws exception because non-uint property",
                expected,
                parseError(err, expected.length));
}

function AddVectorWriteExceptionTest(description, index, expected)
{
    var err = "exception not thrown";
    try {
        v1[index] = description;  // write
    } catch(e) {
        err = e.toString();
    }

    AddTestCase("write index " + description + " throws exception because non-uint property",
                expected,
                parseError(err, expected.length));
}

// Index specialized to Number.

function AddVectorReadExceptionTest_D(description, index, expected)
{
    var err = "exception not thrown";
    var idx:Number = index;
    try {
        v1[idx] == description;  // read
    } catch(e) {
        err = e.toString();
    }

    AddTestCase("read index " + description + " throws exception because non-uint property",
                expected,
                parseError(err, expected.length));
}

function AddVectorWriteExceptionTest_D(description, index, expected)
{
    var err = "exception not thrown";
    var idx:Number = index;
    try {
        v1[idx] = description;  // write
    } catch(e) {
        err = e.toString();
    }

    AddTestCase("write index " + description + " throws exception because non-uint property",
                expected,
                parseError(err, expected.length));
}

// Index specialized to int.

function AddVectorReadExceptionTest_I(description, index, expected)
{
    var err = "exception not thrown";
    var idx:int = index;
    try {
        v1[idx] == description;  // read
    } catch(e) {
        err = e.toString();
    }

    AddTestCase("read index " + description + " throws exception because non-uint property",
                expected,
                parseError(err, expected.length));
}

function AddVectorWriteExceptionTest_I(description, index, expected)
{
    var err = "exception not thrown";
    var idx:int = index;
    try {
        v1[idx] = description;  // write
    } catch(e) {
        err = e.toString();
    }

    AddTestCase("write index " + description + " throws exception because non-uint property",
                expected,
                parseError(err, expected.length));
}

// 5.1
if (System.swfVersion >= 11) {
    AddVectorReadExceptionTest    ("5.1", 5.1, RANGE);
    AddVectorWriteExceptionTest   ("5.1", 5.1, RANGE);
    AddVectorReadExceptionTest_D  ("5.1", 5.1, RANGE);
    AddVectorWriteExceptionTest_D ("5.1", 5.1, RANGE);
} else {
    AddVectorReadExceptionTest    ("5.1", 5.1, REFREAD);
    AddVectorWriteExceptionTest   ("5.1", 5.1, REFWRITE);
    AddVectorReadExceptionTest_D  ("5.1", 5.1, REFREAD);
    AddVectorWriteExceptionTest_D ("5.1", 5.1, REFWRITE);
}

// "5.1"
if (System.swfVersion >= 11) {
    AddVectorReadExceptionTest  ("'5.1'", "5.1", RANGE);
    AddVectorWriteExceptionTest ("'5.1'", "5.1", RANGE);
} else {
    AddVectorReadExceptionTest  ("'5.1'", "5.1", REFREAD);
    AddVectorWriteExceptionTest ("'5.1'", "5.1", REFWRITE);
}

// -5.1
if (System.swfVersion >= 11) {
    AddVectorReadExceptionTest    ("-5.1", -5.1, RANGE);
    AddVectorWriteExceptionTest   ("-5.1", -5.1, RANGE);
    AddVectorReadExceptionTest_D  ("-5.1", -5.1, RANGE);
    AddVectorWriteExceptionTest_D ("-5.1", -5.1, RANGE);
} else {
    AddVectorReadExceptionTest    ("-5.1", -5.1, REFREAD);
    AddVectorWriteExceptionTest   ("-5.1", -5.1, REFWRITE);
    AddVectorReadExceptionTest_D  ("-5.1", -5.1, REFREAD);
    AddVectorWriteExceptionTest_D ("-5.1", -5.1, REFWRITE);
}

// "-5.1"
if (System.swfVersion >= 11) {
    AddVectorReadExceptionTest  ("'-5.1'", "-5.1", RANGE);
    AddVectorWriteExceptionTest ("'-5.1'", "-5.1", RANGE);
} else {
    AddVectorReadExceptionTest  ("'-5.1'", "-5.1", REFREAD);
    AddVectorWriteExceptionTest ("'-5.1'", "-5.1", REFWRITE);
}

// -6
if (System.swfVersion >= 11) {
    // Compiled code may specialize vector indexing to throw a more informative
    // exception for an otherwise valid index property that denotes a negative
    // index value.  In SWF11+, we extend this to all cases of vector indexing.
    // See bug 456852.
    AddVectorReadExceptionTest    ("-6", -6, RANGE);
    AddVectorWriteExceptionTest   ("-6", -6, RANGE);
    AddVectorReadExceptionTest_I  ("-6", -6, RANGE);
    AddVectorWriteExceptionTest_I ("-6", -6, RANGE);
} else {
    AddVectorReadExceptionTest    ("-6", -6, REFREAD);
    AddVectorWriteExceptionTest   ("-6", -6, REFWRITE);
    if (System.getRunmode().indexOf('interp') != -1) {
        // Forced interpretation.
        AddVectorReadExceptionTest_I  ("-6", -6, REFREAD);
        AddVectorWriteExceptionTest_I ("-6", -6, REFWRITE);
    } else {
        // Compiled by default.  This is JIT behavior.
        AddVectorReadExceptionTest_I  ("-6", -6, RANGE);
        AddVectorWriteExceptionTest_I ("-6", -6, RANGE);
    }
}

// -6.0
if (System.swfVersion >= 11) {
    // Compiled code may specialize vector indexing to throw a more informative
    // exception for an otherwise valid index property that denotes a negative
    // index value.  In SWF11+, we extend this to all cases of vector indexing.
    // See bug 456852.
    AddVectorReadExceptionTest    ("-6.0", -6.0, RANGE);
    AddVectorWriteExceptionTest   ("-6.0", -6.0, RANGE);
    AddVectorReadExceptionTest_D  ("-6.0", -6.0, RANGE);
    AddVectorWriteExceptionTest_D ("-6.0", -6.0, RANGE);
} else {
    AddVectorReadExceptionTest    ("-6.0", -6.0, REFREAD);
    AddVectorWriteExceptionTest   ("-6.0", -6.0, REFWRITE);
    AddVectorReadExceptionTest_D  ("-6.0", -6.0, REFREAD);
    AddVectorWriteExceptionTest_D ("-6.0", -6.0, REFWRITE);
}

// "-6"
if (System.swfVersion >= 11) {
    // JIT doesn't specialize this, so result prior to SWF11 was the same as for the interpreter.
    AddVectorReadExceptionTest  ("'-6'", "-6", RANGE);
    AddVectorWriteExceptionTest ("'-6'", "-6", RANGE);
} else {
    AddVectorReadExceptionTest  ("'-6'", "-6", REFREAD);
    AddVectorWriteExceptionTest ("'-6'", "-6", REFWRITE);
}

// "-6.0"
if (System.swfVersion >= 11) {
    // JIT doesn't specialize this, so result prior to SWF11 was the same as for the interpreter.
    AddVectorReadExceptionTest  ("'-6.0'", "-6.0", RANGE);
    AddVectorWriteExceptionTest ("'-6.0'", "-6.0", RANGE);
} else {
    AddVectorReadExceptionTest  ("'-6.0'", "-6.0", REFREAD);
    AddVectorWriteExceptionTest ("'-6.0'", "-6.0", REFWRITE);
}

// "foo"
AddVectorReadExceptionTest  ("'foo'", "foo", REFREAD);
AddVectorWriteExceptionTest ("'foo'", "foo", REFWRITE);

// Odd test case for a known issue.  Note that the property 3.14 is defined in the prototype.

var err1 = "exception not thrown";
try {
    v1["3.14"]=="seven";  // reference property defined in prototype
} catch(e) {
    err1 = e.toString();
}

if (System.swfVersion >= 11) {
   AddTestCase("when Vector.<*>.prototype[3.14] is set throws exception because non-uint property",
               RANGE,
               parseError(err1, RANGE.length));
} else {
   AddTestCase("when Vector.<*>.prototype[3.14] is set throws exception because non-uint property",
               REFREAD,
               parseError(err1, REFREAD.length));
}

// Check high and low extremes.

var max_int28_p1 =    268435456;
var max_int28    =    268435455;
var max_int28_m1 =    268435454;

var max_uint_p1  =   4294967296;
var max_uint     =   4294967295;
var max_uint_m1  =   4294967294;

var max_int_p1   =   2147483648;
var max_int      =   2147483647;
var max_int_m1   =   2147483646;

var min_int_p1   =  -2147483647;
var min_int      =  -2147483648;
var min_int_m1   =  -2147483649;

// Implementation limits prevent us from actually allocating a vector as large
// as these sizes, so all of these references will be to undefined properties.

if (System.swfVersion >= 11) {
    AddVectorReadExceptionTest  ("max_uint_p1", max_uint_p1,   RANGE);
    AddVectorWriteExceptionTest ("max_uint_p1", max_uint_p1,   RANGE);
    AddVectorReadExceptionTest  ("max_uint",    max_uint,      RANGE);
    AddVectorWriteExceptionTest ("max_uint",    max_uint,      RANGE);
} else {
    AddVectorReadExceptionTest  ("max_uint_p1", max_uint_p1,   REFREAD);
    AddVectorWriteExceptionTest ("max_uint_p1", max_uint_p1,   REFWRITE);
    if (System.getRunmode().indexOf('interp') != -1) {
        // Forced interpretation.
        AddVectorReadExceptionTest  ("max_uint",    max_uint,  REFREAD);
        AddVectorWriteExceptionTest ("max_uint",    max_uint,  REFWRITE);
    } else {
        // Compiled by default.  This is JIT behavior.
        AddVectorReadExceptionTest  ("max_uint",    max_uint,  REFREAD);
        AddVectorWriteExceptionTest ("max_uint",    max_uint,  RANGE);
    }
}

AddVectorReadExceptionTest  ("max_uint_m1", max_uint_m1,   RANGE);
AddVectorWriteExceptionTest ("max_uint_m1", max_uint_m1,   RANGE);
AddVectorReadExceptionTest  ("max_int_p1",  max_int_p1,    RANGE);
AddVectorWriteExceptionTest ("max_int_p1",  max_int_p1,    RANGE);
AddVectorReadExceptionTest  ("max_int",     max_int,       RANGE);
AddVectorWriteExceptionTest ("max_int",     max_int,       RANGE);
AddVectorReadExceptionTest  ("max_int_m1",  max_int_m1,    RANGE);
AddVectorWriteExceptionTest ("max_int_m1",  max_int_m1,    RANGE);

// The implementation does some case analysis at 28 bits.

AddVectorReadExceptionTest  ("max_int28_p1", max_int28_p1, RANGE);
AddVectorWriteExceptionTest ("max_int28_p1", max_int28_p1, RANGE);
AddVectorReadExceptionTest  ("max_int28",    max_int28,    RANGE);
AddVectorWriteExceptionTest ("max_int28",    max_int28,    RANGE);
AddVectorReadExceptionTest  ("max_int28_m1", max_int28_m1, RANGE);
AddVectorWriteExceptionTest ("max_int28_m1", max_int28_m1, RANGE);

if (System.swfVersion >= 11) {
    AddVectorReadExceptionTest  ("min_int_p1",  min_int_p1,    RANGE);     // Negative index not allowed.
    AddVectorWriteExceptionTest ("min_int_p1",  min_int_p1,    RANGE);     // Negative index not allowed.
    AddVectorReadExceptionTest  ("min_int",     min_int,       RANGE);     // Negative index not allowed.
    AddVectorWriteExceptionTest ("min_int",     min_int,       RANGE);     // Negative index not allowed.
    AddVectorReadExceptionTest  ("min_int_m1",  min_int_m1,    RANGE);     // Negative index not allowed.
    AddVectorWriteExceptionTest ("min_int_m1",  min_int_m1,    RANGE);     // Negative index not allowed.
} else {
    AddVectorReadExceptionTest  ("min_int_p1",  min_int_p1,    REFREAD);   // Negative index not allowed.
    AddVectorWriteExceptionTest ("min_int_p1",  min_int_p1,    REFWRITE);  // Negative index not allowed.
    AddVectorReadExceptionTest  ("min_int",     min_int,       REFREAD);   // Negative index not allowed.
    AddVectorWriteExceptionTest ("min_int",     min_int,       REFWRITE);  // Negative index not allowed.
    AddVectorReadExceptionTest  ("min_int_m1",  min_int_m1,    REFREAD);   // Negative index not allowed.
    AddVectorWriteExceptionTest ("min_int_m1",  min_int_m1,    REFWRITE);  // Negative index not allowed.
}

test();
