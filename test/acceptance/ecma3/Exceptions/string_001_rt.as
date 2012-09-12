/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "string-001";
    var VERSION = "JS1_4";
    var TITLE   = "String.prototype.toString";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var result = "Failed";
    var exception = "No exception thrown";
    var expect = "Passed";

    try {
        OBJECT = new Object();
        OBJECT.toString = String.prototype.toString;
        result = OBJECT.toString();
    } catch ( e:TypeError) {
        result = expect;
        exception = e.toString();
    }

    array[item++] = new TestCase(
        SECTION,
        "OBJECT = new Object(); "+
        " OBJECT.toString = String.prototype.toString; OBJECT.toString()" +
        " (threw " + typeError(exception) +")",
        expect,
        result );

    return array;
}

