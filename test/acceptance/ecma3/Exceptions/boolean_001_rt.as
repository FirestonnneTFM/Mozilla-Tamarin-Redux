/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "boolean-001.as";
    var VERSION = "ECMA_4";
    var TITLE   = "Boolean.prototype.toString()";
    startTest();
    writeHeaderToLog( SECTION +" "+ TITLE );

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var exception = "No exception thrown";

    var TO_STRING = Boolean.prototype.toString;

    var expectedError = 1056;
    if (as3Enabled) {
        expectedError = 1037;
    }

    try {
        var s = new String("Not a Boolean");
        s.toString = TO_STRING;
        s.toString();
    } catch ( e ) {
        exception = e.toString();
    }finally{

    array[item++] = new TestCase(
        SECTION,
        "Assigning Boolean.prototype.toString to a String object ",
        REFERENCEERROR+expectedError,
        referenceError( exception ) );
    }
    // new Boolean()
    try {
        var b = new Boolean();
        b.toString = TO_STRING;
        b.toString();
    } catch ( e1 ) {
        exception = e1.toString();
    }finally{

    array[item++] = new TestCase(
        SECTION,
        "Assigning Boolean.prototype.toString to an instance of new Boolean()",
        REFERENCEERROR+expectedError,
        referenceError( exception ) );

    }
    // new Boolean(true)
    try {
        var b = new Boolean(true);
        b.toString = TO_STRING;
        b.toString();
    } catch ( e2 ) {
        exception = e2.toString();
    }finally{

    array[item++] = new TestCase(
        SECTION,
        "Assigning Boolean.prototype.toString to an instance of new Boolean(true)",
        REFERENCEERROR+expectedError,
        referenceError( exception ) );

    }
    // new Boolean(false)
    try {
        var b = new Boolean(false);
        b.toString = TO_STRING;
        b.toString();
    } catch ( e3 ) {
        exception = e3.toString();
    }finally{

    array[item++] = new TestCase(
        SECTION,
        "Assigning Boolean.prototype.toString to an instance of new Boolean(false)",
        REFERENCEERROR+expectedError,
        referenceError( exception ) );
    }

    // true
    try {
        var b = true;
        b.toString = TO_STRING;
        b.toString();
    } catch ( e4 ) {
        exception = e4.toString();
    }finally{

    array[item++] = new TestCase(
        SECTION,
        "Assigning Boolean.prototype.toString to an instance of 'true'",
        REFERENCEERROR+expectedError,
        referenceError( exception ) );
    }

    // false
    try {
        var b = false;
        b.toString = TO_STRING;
        b.toString();
    } catch ( e5 ) {
        exception = e5.toString();
    }finally{

    array[item++] = new TestCase(
        SECTION,
        "Assigning Boolean.prototype.toString to an instance of 'false'",
        REFERENCEERROR+expectedError,
        referenceError( exception ) );
    }
    return array;
}
