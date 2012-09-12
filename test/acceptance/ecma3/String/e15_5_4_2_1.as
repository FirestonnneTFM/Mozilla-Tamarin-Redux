/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.5.4.2-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "String.prototype.toString";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    array[item++] = new TestCase( SECTION,   "String.prototype.toString()",        "",     String.prototype.toString() );
    array[item++] = new TestCase( SECTION,   "(new String()).toString()",          "",     (new String()).toString() );
    array[item++] = new TestCase( SECTION,   "(new String(\"\")).toString()",      "",     (new String("")).toString() );
    array[item++] = new TestCase( SECTION,   "(new String( String() )).toString()","",    (new String(String())).toString() );
    array[item++] = new TestCase( SECTION,  "(new String( \"h e l l o\" )).toString()",       "h e l l o",    (new String("h e l l o")).toString() );
    array[item++] = new TestCase( SECTION,   "(new String( 0 )).toString()",       "0",    (new String(0)).toString() );
    return ( array );
}
