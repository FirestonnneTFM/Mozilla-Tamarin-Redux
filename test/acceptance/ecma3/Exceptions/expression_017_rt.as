/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "expression-017";
    var VERSION = "JS1_4";
    var TITLE   = "Function Calls";

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
        result = nullvalueOf();
    } catch ( e ) {
        result = expect;
        exception = e.toString();
    }

    array[item++] = new TestCase(
        SECTION,
        "null.valueOf()" +
        " (threw " + referenceError(exception) +")",
        expect,
        result );

    return array;
}
