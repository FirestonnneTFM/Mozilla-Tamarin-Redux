/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "expression-012";
    var VERSION = "JS1_4";
    var TITLE   = "The new operator";
    var BUGNUMBER= "327765";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var STRING = new String("hi");
    var result = "Failed";
    var exception = "No exception thrown";
    var expect = "Passed";

    try {
        result = new STRING();
    } catch ( e:TypeError ) {
        result = expect;
        exception = e.toString();
    }

    array[item++] = new TestCase(
        SECTION,
        "STRING = new String(\"hi\"); result = new STRING()" +
        " (threw " + typeError(exception) +"Attempted to create a new object of a variable)",
        expect,
        result );
        
    return array;
}

