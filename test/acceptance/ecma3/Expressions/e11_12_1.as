/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "e11_12";
    var VERSION = "ECMA_1";
    startTest();
    var testcases = getTestCases();

    writeHeaderToLog( SECTION + " Conditional operator( ? : )");
    test();
function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,    "true ? 'PASSED' : 'FAILED'",     "PASSED",       (true?"PASSED":"FAILED"));
    array[item++] = new TestCase( SECTION,    "false ? 'FAILED' : 'PASSED'",     "PASSED",      (false?"FAILED":"PASSED"));

    array[item++] = new TestCase( SECTION,    "1 ? 'PASSED' : 'FAILED'",     "PASSED",          (1?"PASSED":"FAILED"));
    array[item++] = new TestCase( SECTION,    "0 ? 'FAILED' : 'PASSED'",     "PASSED",          (0?"FAILED":"PASSED"));
    array[item++] = new TestCase( SECTION,    "-1 ? 'PASSED' : 'FAILED'",     "PASSED",          (-1?"PASSED":"FAILED"));

    array[item++] = new TestCase( SECTION,    "NaN ? 'FAILED' : 'PASSED'",     "PASSED",          (Number.NaN?"FAILED":"PASSED"));

    array[item++] = new TestCase( SECTION,    "var VAR = true ? , : 'FAILED'", "PASSED",           (VAR = true ? "PASSED" : "FAILED") );

    return ( array );
}
