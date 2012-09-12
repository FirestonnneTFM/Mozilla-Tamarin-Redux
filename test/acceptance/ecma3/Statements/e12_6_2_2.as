/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "12.6.2-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The for statment";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    array[item++] = new TestCase( SECTION, "for statement",  99,     testprogram() );
    return ( array );
}

function testprogram() {
    myVar = 0;

    for ( ; ; myVar++ ) {
        if ( myVar < 99 ) {
            continue;
        } else {
            break;
        }
    }

    return myVar;
}
