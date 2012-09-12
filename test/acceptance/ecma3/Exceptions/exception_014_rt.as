/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "exception-014";
    var VERSION = "ECMA_4";
    var TITLE   = "Regression test for bug 105083";
    var BUGNUMBER= "105083";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    try {
        throw "Exception";
    } catch ( e ) {
        array[item++] = new TestCase(SECTION, "first thrown Exception", "Exception", e.toString() );
    }

    try {
        throw "Exception";
    } catch ( e1 ) {
        array[item++] = new TestCase(SECTION, "first thrown Exception", "Exception", e1.toString() );
    }
    return array;
}
