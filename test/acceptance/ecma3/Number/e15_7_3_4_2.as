/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var SECTION = "15.7.3.4-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Number.NaN";

    writeHeaderToLog( SECTION + " "+ TITLE );

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;

    delete( Number.NaN );
    array[item++] = new TestCase(SECTION, "delete( Number.NaN ); Number.NaN",       NaN,        Number.NaN );
    array[item++] = new TestCase( SECTION, "delete( Number.NaN )",                  false,      delete( Number.NaN ) );

    return ( array );
}
