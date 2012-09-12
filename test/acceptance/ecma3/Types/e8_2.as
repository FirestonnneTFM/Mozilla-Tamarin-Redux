/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "8.2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The null type";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
        
    var x = null;
    array[item++] = new TestCase( SECTION,
                                    "var x = null; typeof x",
                                    null,
                                    x);

    array[item++] = new TestCase( SECTION,
                                    "typeof null",
                                    "object",
                                    typeof null);
    return array;
}
