/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.8.1.5-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.LOG10E";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;

    delete Math.LOG10E;
    array[item++] = new TestCase( SECTION, "delete Math.LOG10E; Math.LOG10E",   0.4342944819032518,     Math.LOG10E );
    array[item++] = new TestCase( SECTION, "delete Math.LOG10E",                false,                  delete Math.LOG10E );
    return ( array );
}
