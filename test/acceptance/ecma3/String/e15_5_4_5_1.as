/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.5.4.5-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "String.prototype.charCodeAt";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var TEST_STRING = new String( " !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~" );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();

    for ( j = 0, i = 0x0020; i < 0x007e; i++, j++ ) {
        array[j] = new TestCase( SECTION, "TEST_STRING.charCodeAt("+j+")", i, TEST_STRING.charCodeAt( j ) );
    }

    item = array.length;

    array[item++] = new TestCase( SECTION, 'TEST_STRING.charCodeAt('+i+')', NaN,    TEST_STRING.charCodeAt( i ) );
    return array;
}
