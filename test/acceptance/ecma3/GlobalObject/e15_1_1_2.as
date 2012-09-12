/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.1.1.2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Infinity";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION, "Infinity",               Number.POSITIVE_INFINITY,      Infinity );
    array[item++] = new TestCase( SECTION, "this.Infinity",          undefined,                     this.Infinity );
    array[item++] = new TestCase( SECTION, "typeof Infinity",        "number",                      typeof Infinity );

    return ( array );
}
