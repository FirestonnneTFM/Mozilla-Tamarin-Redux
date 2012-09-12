/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var SECTION = "15.8.2.11";
    var VERSION = "";
    startTest();
    var TITLE   = "Math.max(x, y, ... rest) and additional tests base on code coverage";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    // Testcases based on code coverage analysis
    array[item++] = new TestCase( SECTION,  "Math.max(1, 2, 3)",       3,        Math.max(1, 2, 3) );
    array[item++] = new TestCase( SECTION,  "1.0/Math.max(0.0, -1, 0.0)",  Infinity, 1.0/Math.max(0.0, -1, 0.0) );
    array[item++] = new TestCase( SECTION,  "1.0/Math.max(0.0, -1, -0.0)", Infinity, 1.0/Math.max(0.0, -1, -0.0) );
    array[item++] = new TestCase( SECTION,  "1.0/Math.max(-0.0, -1, 0.0)", Infinity, 1.0/Math.max(-0.0, -1, 0.0) );
    array[item++] = new TestCase( SECTION,  "1.0/Math.max(-0.0, -1, -0.0)", -Infinity, 1.0/Math.max(-0.0, -1, -0.0) );
    array[item++] = new TestCase( SECTION,  "Math.max(4, 3, 4)", 4, Math.max(4, 3, 4) );
    return ( array );
}
