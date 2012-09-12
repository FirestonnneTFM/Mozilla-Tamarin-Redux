/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.4.2.1-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Array Constructor:  new Array( item0, item1, ...)";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;
    var arr;

    array[item++] = new TestCase( SECTION,  "typeof new Array(1,2)",        "object",           typeof new Array(1,2) );
    array[item++] = new TestCase( SECTION,  "(new Array(1,2)).toString",    "function Function() {}",    ((new Array(1,2)).toString).toString() );
    array[item++] = new TestCase( SECTION,
                                    "var arr = new Array(1,2,3); arr.getClass = Object.prototype.toString; arr.getClass()",
                                    "[object Array]",
                                    (arr = new Array(1,2,3), arr.getClass = Object.prototype.toString, arr.getClass() ) );

    array[item++] = new TestCase( SECTION,  "(new Array(1,2)).length",      2,                  (new Array(1,2)).length );
    array[item++] = new TestCase( SECTION,  "var arr = (new Array(1,2)), arr[0]",  1,           (arr = (new Array(1,2)), arr[0] ) );
    array[item++] = new TestCase( SECTION,  "var arr = (new Array(1,2)), arr[1]",  2,           (arr = (new Array(1,2)), arr[1] ) );
    array[item++] = new TestCase( SECTION,  "var arr = (new Array(1,2)), String(arr)",  "1,2",  (arr = (new Array(1,2)), String(arr) ) );

    return ( array );
}
