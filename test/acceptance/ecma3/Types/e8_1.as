/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "8.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The undefined type";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
        
    var x;
    array[item++] = new TestCase( SECTION,
                                    "var x; typeof x",
                                    "undefined",
                                     typeof x);
    var x;
    array[item++] = new TestCase( SECTION,
                                    "var x; typeof x == 'undefined",
                                    true,
                                    typeof x == 'undefined');
    var x;
    array[item++] = new TestCase( SECTION,
                                    "var x; x == void 0",
                                    true,
                                    x == void 0);
    return array;
}
