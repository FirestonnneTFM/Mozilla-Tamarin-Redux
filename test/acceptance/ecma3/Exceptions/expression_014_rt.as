/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "expression-014.js";
    var VERSION = "ECMA_1";
    var TITLE   = "The new operator";
    var BUGNUMBER= "327765";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var BOOLEAN = new Boolean();


    var result = "Failed";
    var exception = "No exception thrown";
    var expect = "Passed";

    try {
        result = new BOOLEAN();
    } catch ( e:TypeError ) {
        result = expect;
        exception = e.toString();
    }

    array[item++] = new TestCase(
        SECTION,
        "BOOLEAN = new Boolean(); result = new BOOLEAN()" +
        " (threw " + typeError(exception) +"Attempted to create a new object of a variable which is not function/class)",
        expect,
        result );
        
    return array;
}

