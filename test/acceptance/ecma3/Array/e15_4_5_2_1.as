/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.4.5.2-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Array.length";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase(   SECTION,
                                    "var A = new Array(); A.length",
                                    0,
                                    (A = new Array(), A.length ) );

    array[item++] = new TestCase(   SECTION,
                                    "var A = new Array(); A[Math.pow(2,32)-2] = 'hi'; A.length",
                                    Math.pow(2,32)-1,
                                    (A = new Array(), A[Math.pow(2,32)-2] = 'hi', A.length ) );

    array[item++] = new TestCase(   SECTION,
                                    "var A = new Array(); A.length = 123; A.length",
                                    123,
                                    (A = new Array(), A.length = 123, A.length ) );

    var A = new Array();
    A.length = 123;
    var PROPS = '';
    for ( var p in A ) {
        if (p == 'length')
            PROPS += p;
    }

    array[item++] = new TestCase(   SECTION,
                                    "var A = new Array(); A.length = 123; var PROPS = ''; for ( var p in A ) { PROPS += ( p == 'length' ? p : ''); } PROPS",
                                    "",
                                    PROPS );


    array[item++] = new TestCase(   SECTION,
                                    "var A = new Array(); A.length = 123; delete A.length",
                                    false ,
                                    (A = new Array(), A.length = 123, delete A.length ) );

    array[item++] = new TestCase(   SECTION,
                                    "var A = new Array(); A.length = 123; delete A.length; A.length",
                                    123,
                                    (A = new Array(), A.length = 123, delete A.length, A.length ) );
    return array;
}
