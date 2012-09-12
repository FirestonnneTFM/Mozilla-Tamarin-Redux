/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.1.1.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "NaN";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[array.length] = new TestCase( SECTION, "NaN",               Number.NaN,     NaN );
    array[array.length] = new TestCase( SECTION, "this.NaN",          undefined,      this.NaN );
    array[array.length] = new TestCase( SECTION, "typeof NaN",        "number",       typeof NaN );

    return ( array );
}
