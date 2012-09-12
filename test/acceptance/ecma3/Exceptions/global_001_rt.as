/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "global-001";
    var VERSION = "ECMA_1";
    var TITLE   = "The Global Object";

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
        result = new this();
    } catch ( e:TypeError ) {
        result = expect;
        exception = e.toString();
    }

    array[item++] = new TestCase(
        SECTION,
        "result = new this()" +
        " (threw " + typeError(exception) +")",
        expect,
        result );
        
    return array;
}
