/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.8.1.1-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Math.E";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var MATH_E = 2.7182818284590452354
    array[item++] = new TestCase( SECTION, "delete(Math.E)",                false,    delete Math.E );
    delete Math.E;
    array[item++] = new TestCase( SECTION, "delete(Math.E); Math.E",        MATH_E,   Math.E );
    return ( array );
}
