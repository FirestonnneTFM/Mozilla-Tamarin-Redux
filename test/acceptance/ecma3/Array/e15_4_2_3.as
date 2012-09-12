/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.4.2.3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Array Constructor:  new Array()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    var arr;
    array[item++] = new TestCase( SECTION,  "new   Array() +''",        "",                 (new Array()) +"" );
    array[item++] = new TestCase( SECTION,  "typeof new Array()",       "object",           (typeof new Array()) );
    array[item++] = new TestCase(   SECTION,
                                    "var arr = new Array(); arr.getClass = Object.prototype.toString; arr.getClass()",
                                    "[object Array]",
                                    (arr = new Array(), arr.getClass = Object.prototype.toString, arr.getClass() ) );

    array[item++] = new TestCase( SECTION,  "(new Array()).length",     0,                  (new Array()).length );
    array[item++] = new TestCase( SECTION,  "(new Array()).toString == Array.prototype.toString",   true,       (new Array()).toString == Array.prototype.toString );

    if (!as3Enabled) {
        array[item++] = new TestCase( SECTION,  "(new Array()).join  == Array.prototype.join",          true,       (new Array()).join  == Array.prototype.join );
        array[item++] = new TestCase( SECTION,  "(new Array()).reverse == Array.prototype.reverse",     true,       (new Array()).reverse  == Array.prototype.reverse );
        array[item++] = new TestCase( SECTION,  "(new Array()).sort  == Array.prototype.sort",          true,       (new Array()).sort  == Array.prototype.sort );
    }
    
    return ( array );
}
