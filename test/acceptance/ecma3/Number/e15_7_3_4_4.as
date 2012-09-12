/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.7.3.4-4";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Number.NaN";

    writeHeaderToLog( SECTION + " " + TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    string = '';
    for ( prop in Number ) {
        string += ( prop == 'NaN' ) ? prop : '';
    }

    array[item++] = new TestCase(
                    SECTION,
                    "var string = ''; for ( prop in Number ) { string += ( prop == 'NaN' ) ? prop : '' } string;",
                    "",
                    string
                    );

    return ( array );
}
