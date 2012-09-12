/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "7.7.2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Boolean Literals";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    // StringLiteral:: "" and ''

    array[item++] = new TestCase( SECTION, "true",     Boolean(true),     true );
    array[item++] = new TestCase( SECTION, "false",    Boolean(false),    false );

    return ( array );
}
