/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "instaceof_001";
    var VERSION = "ECMA_2";
    startTest();
    var TITLE   = "instanceof operator";

    writeHeaderToLog( SECTION + " "+ TITLE);
    
    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
        
    var b = new Boolean();

    array[item++] = new TestCase( SECTION,
                                    "var b = new Boolean(); b instanceof Boolean",
                                    true,
                                    b instanceof Boolean );

    array[item++] = new TestCase( SECTION,
                                    "b instanceof Object",
                                    true,
                                    b instanceof Object );
    return ( array );
}
