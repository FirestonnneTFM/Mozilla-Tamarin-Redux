/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "expression-005";
    var VERSION = "JS1_4";
    var TITLE   = "The new operator";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var result = "Failed";
    var expect = "Passed";
    var exception = "No exception thrown";

    try {
        result = new Math();
    } catch ( e:TypeError ) {
        result = expect;
        exception = e.toString();
    }finally{

    array[item++] = new TestCase(
        SECTION,
        "result= new Math() (threw " + typeError(exception) + ": Math is not a constructor)",
        expect,
        result );
             }

    return array;
}
