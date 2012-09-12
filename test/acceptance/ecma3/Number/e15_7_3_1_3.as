/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var VERSION = "ECMA_1";
    startTest();
    var SECTION = "15.7.3.1-3";
    var TITLE   = "Number.prototype";

    writeHeaderToLog( SECTION + " Number.prototype:  DontEnum Attribute");

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    string = '';
    for ( prop in Number ) {
        string += ( prop == 'prototype' ) ? prop : '';
    }

    array[item++] = new TestCase(
                    SECTION,
                    "var string = ''; for ( prop in Number ) { string += ( prop == 'prototype' ) ? prop: '' } string;",
                    "",
                    string
                    );

    return ( array );
}
