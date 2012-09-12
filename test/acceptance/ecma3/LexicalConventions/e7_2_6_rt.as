/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "7.2-6";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Line Terminators";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    var a=10;
var b=10;
var c;
       

    
c=
a
*
b

    array[item++] = new TestCase( "7.2",    "c<cr>a<cr>*<cr>b",     100,     c);

    return ( array );
}
