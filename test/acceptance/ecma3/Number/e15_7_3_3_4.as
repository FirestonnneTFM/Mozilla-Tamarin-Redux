/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var SECTION = "15.7.3.3-4";
    var VERSION = "ECMA_1";
    startTest();

    writeHeaderToLog( SECTION + " Number.MIN_VALUE:  DontEnum Attribute");

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    string = '';
    for ( prop in Number ) {
        string += ( prop == 'MIN_VALUE' ) ? prop : '';
    }

    array[item++] = new TestCase(
                    SECTION,
                    "var string = ''; for ( prop in Number ) { string += ( prop == 'MIN_VALUE' ) ? prop : '' } string;",
                    "",
                    string
                    );

    return ( array );
}
