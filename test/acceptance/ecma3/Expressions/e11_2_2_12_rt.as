/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "11.2.2.l2.as";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The new operator";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var FUNCTION = new Function();

    f = new FUNCTION();
    array[item++] = new TestCase( SECTION,
                                    "var FUNCTION = new Function(); f = new FUNCTION(); typeof f",
                                    "object",
                                    typeof f );
    return array;
}
