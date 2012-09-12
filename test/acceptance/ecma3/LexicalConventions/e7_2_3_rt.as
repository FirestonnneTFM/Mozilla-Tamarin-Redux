/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "7.2-3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Line Terminators";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;
    var b;


       
       b =

20;

    array[item++] = new TestCase( "7.2",    "b<cr>20",     20,     b);

    return ( array );
}
