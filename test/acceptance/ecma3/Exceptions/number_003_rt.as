/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "number-003";
    var VERSION = "ECMA_4";
    var TITLE   = "Exceptions for Number.valueOf()";

    startTest();
    writeHeaderToLog( SECTION + " Number.prototype.valueOf()");
    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;


    var result = "Failed";
    var exception = "No exception thrown";
    var expect = "Passed";

    try {
        VALUE_OF = Number.prototype.valueOf;
        OBJECT = new String("Infinity");
        OBJECT.valueOf = VALUE_OF;
        result = OBJECT.valueOf();
    } catch ( e ) {
        result = expect;
        exception = e.toString();
    }

    array[item++] = new TestCase(
        SECTION,
        "Assigning Number.prototype.valueOf as the valueOf of a String object " +
        " (threw " + referenceError(exception) +")",
        expect,
        result );

    // new Number()
    try {
        VALUE_OF = Number.prototype.valueOf;
        OBJECT = new Number();
        OBJECT.valueOf = VALUE_OF;
        result = OBJECT.valueOf();
    } catch ( e1:ReferenceError ) {
        result = expect;
        exception = e1.toString();
    }

    array[item++] = new TestCase(
        SECTION,
        "Assigning Number.prototype.valueOf as the valueOf of new Number() " +
        " (threw " + referenceError(exception) +")",
        expect,
        result );

    // new Number(4)
    try {
        VALUE_OF = Number.prototype.valueOf;
        OBJECT = new Number(4);
        OBJECT.valueOf = VALUE_OF;
        result = OBJECT.valueOf();
    } catch ( e2 ) {
        result = expect;
        exception = e2.toString();
    }

    array[item++] = new TestCase(
        SECTION,
        "Assigning Number.prototype.valueOf as the valueOf of new Number(4) " +
        " (threw " + referenceError(exception) +")",
        expect,
        result );

    // 4
    try {
        VALUE_OF = Number.prototype.valueOf;
        OBJECT = 4;
        OBJECT.valueOf = VALUE_OF;
        result = OBJECT.valueOf();
    } catch ( e3 ) {
        result = expect;
        exception = e3.toString();
    }

    array[item++] = new TestCase(
        SECTION,
        "Assigning Number.prototype.valueOf as the valueOf of '4' " +
        " (threw " + referenceError(exception) +")",
        expect,
        result );

    return array;
}
