/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.4.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Array Constructor Called as a Function";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    var arr;

    array[item++] = new TestCase(   SECTION,
                                    "Array() +''",
                                    "",
                                    Array() +"" );

    array[item++] = new TestCase(   SECTION,
                                    "typeof Array()",
                                    "object",
                                    typeof Array() );

    array[item++] = new TestCase(   SECTION,
                                    "var arr = Array(); arr.getClass = Object.prototype.toString; arr.getClass()",
                                    "[object Array]",
                                    (arr = Array(), arr.getClass = Object.prototype.toString, arr.getClass() ) );

    array[item++] = new TestCase(   SECTION,
                                    "var arr = Array(); arr.toString == Array.prototype.toString",
                                    true,
                                    (arr = Array(), arr.toString == Array.prototype.toString ) );

    array[item++] = new TestCase(   SECTION,
                                    "Array().length",
                                    0,
                                    Array().length );


    array[item++] = new TestCase(   SECTION,
                                    "Array(1,2,3) +''",
                                    "1,2,3",
                                    Array(1,2,3) +"" );

    array[item++] = new TestCase(   SECTION,
                                    "typeof Array(1,2,3)",
                                    "object",
                                    typeof Array(1,2,3) );

    array[item++] = new TestCase(   SECTION,
                                    "var arr = Array(1,2,3); arr.getClass = Object.prototype.toString; arr.getClass()",
                                    "[object Array]",
                                    (arr = Array(1,2,3), arr.getClass = Object.prototype.toString, arr.getClass() ) );

    array[item++] = new TestCase(   SECTION,
                                    "var arr = Array(1,2,3); arr.toString == Array.prototype.toString",
                                    true,
                                    (arr = Array(1,2,3), arr.toString == Array.prototype.toString ) );

    array[item++] = new TestCase(   SECTION,
                                    "Array(1,2,3).length",
                                    3,
                                    Array(1,2,3).length );

    array[item++] = new TestCase(   SECTION,
                                    "typeof Array(12345)",
                                    "object",
                                    typeof Array(12345) );

    array[item++] = new TestCase(   SECTION,
                                    "var arr = Array(12345); arr.getClass = Object.prototype.toString; arr.getClass()",
                                    "[object Array]",
                                    (arr = Array(12345), arr.getClass = Object.prototype.toString, arr.getClass() ) );

    array[item++] = new TestCase(   SECTION,
                                    "var arr = Array(1,2,3,4,5); arr.toString == Array.prototype.toString",
                                    true,
                                    (arr = Array(1,2,3,4,5), arr.toString == Array.prototype.toString ) );

    array[item++] = new TestCase(   SECTION,
                                    "Array(12345).length",
                                    12345,
                                    Array(12345).length );

    return ( array );
}
