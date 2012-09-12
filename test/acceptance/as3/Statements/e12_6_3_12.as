/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "12.6.3-12";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The for..in statment";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

class A {
    var result = "PASSED";

    public function doTest():String {
        for ( aVar in this ) {
            if (aVar == "aVar") {
                result = "FAILED"
            }
        };
        return result;
    }
}

function getTestCases() {
    var array = new Array();
    var item = 0;

    var actualResult = new A().doTest();

    array[item++] = new TestCase(
        SECTION,
        "var result=''; for ( aVar in this ) { " +
        "if (aVar == 'aVar') {return a failure}; result",
        "PASSED",
        actualResult );

    return array;
}
