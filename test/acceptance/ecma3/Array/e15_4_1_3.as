/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.4.1.3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Array Constructor Called as a Function:  Array()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase(   SECTION,
                                    "typeof Array()",
                                    "object",
                                    typeof Array() );

    var MYARR;

    array[item++] = new TestCase(   SECTION,
                                    "MYARR = new Array();MYARR.getClass = Object.prototype.toString;MYARR.getClass()",
                                    "[object Array]",
                                    (MYARR = Array(),MYARR.getClass = Object.prototype.toString,MYARR.getClass()) );

    array[item++] = new TestCase(   SECTION,
                                    "(Array()).length",
                                    0,          (
                                    Array()).length );

    array[item++] = new TestCase(   SECTION,
                                    "Array().toString()",
                                    "",
                                    Array().toString() );


    return ( array );
}
