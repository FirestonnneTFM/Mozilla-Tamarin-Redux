/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.1.1.3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "undefined";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION, "undefined",               undefined,      undefined );
    array[item++] = new TestCase( SECTION, "this.undefined",          undefined,      this.undefined );
    array[item++] = new TestCase( SECTION, "typeof undefined",        "undefined",      typeof undefined );

    return ( array );
}
