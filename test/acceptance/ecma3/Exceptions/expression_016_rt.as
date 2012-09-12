/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "expression-016";
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
        result = (void 0).valueOf();
    } catch ( e:TypeError ) {
        result = expect;
        exception = e.toString();
    }

    array[item++] = new TestCase(
        SECTION,
        "(void 0).valueOf()" +
        " (threw " + typeError(exception) +"Attempted to create an object of a variable that is not a function/class)",
        expect,
        result );

    return array;
}
