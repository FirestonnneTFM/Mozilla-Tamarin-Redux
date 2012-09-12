/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "expression-007";
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
    var exception = "No exception thrown";
    var expect = "Passed";
    var UNDEFINED = void 0;
    
    try {
        
          
        UNDEFINED();
    } catch ( e:TypeError ) {
        
        exception = e.toString();
    }finally{

    array[item++] = new TestCase(
        SECTION,
        "UNDEFINED = void 0; result = UNDEFINED()" +
        " (threw " + typeError(exception) +": Call attempted on an object that is not a function.)",
        "TypeError: Error #1006",
        typeError(exception) );

    }
    return array;
}
