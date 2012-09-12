/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "expression-006.js";
    var VERSION = "JS1_4";
    var TITLE   = "The new operator";
    var BUGNUMBER="327765";

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
        var OBJECT = new Object();
        result = new OBJECT();
    } catch ( e:TypeError ) {
        result = expect;
        exception = e.toString();
    }finally{
    
    array[item++] = new TestCase(
        SECTION,
        "OBJECT = new Object; result = new OBJECT()" +
        " (threw " + typeError(exception) +": Instantiation attempted on a non-constructor.)",
        expect,
        result );
            }
    return array;
}
