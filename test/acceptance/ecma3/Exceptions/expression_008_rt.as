/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "expression-008";
   var VERSION = "JS1_4";
    var TITLE   = "The new operator";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);
    
    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var NULL = null;
    
    
    var result = "Failed";
    var exception = "No exception thrown";
    var expect = "Passed";

    try {
        result = new NULL();
    } catch ( e:TypeError ) {
        result = expect;
        exception = e.toString();
    }

    array[item++] = new TestCase(
        SECTION,
        "NULL = null; result = new NULL()" +
        " (threw " + typeError(exception) +": Attempted to create a new object of a variable)",
        expect,
        result );
    return array;
}
