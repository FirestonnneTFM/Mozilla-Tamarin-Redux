/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "e11_14_1";
    var VERSION = "ECMA_1";
    startTest();
    var testcases = getTestCases();

    writeHeaderToLog( SECTION + " Comma operator (,)");
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,    "true, false",                    false,  (true, false) );
    array[item++] = new TestCase( SECTION,    "VAR1=true, VAR2=false",          false,  (VAR1=true, VAR2=false) );
    array[item++] = new TestCase( SECTION,    "VAR1=true, VAR2=false;VAR1",     true,   (VAR1=true, VAR2=false, VAR1) );
    return ( array );
}
