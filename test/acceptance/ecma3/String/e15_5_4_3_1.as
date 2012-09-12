/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.5.4.3-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "String.prototype.valueOf";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,   "String.prototype.valueOf.length", 0,      String.prototype.valueOf.length );

    array[item++] = new TestCase( SECTION,   "String.prototype.valueOf()",        "",     String.prototype.valueOf() );
    array[item++] = new TestCase( SECTION,   "(new String()).valueOf()",          "",     (new String()).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new String(\"\")).valueOf()",      "",     (new String("")).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new String( String() )).valueOf()","",    (new String(String())).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new String( \"h e l l o\" )).valueOf()",       "h e l l o",    (new String("h e l l o")).valueOf() );
    array[item++] = new TestCase( SECTION,   "(new String( 0 )).valueOf()",       "0",    (new String(0)).valueOf() );
    return ( array );
}
