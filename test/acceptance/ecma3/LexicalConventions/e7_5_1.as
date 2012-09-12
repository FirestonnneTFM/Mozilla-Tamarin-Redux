/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "7.5-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Identifiers";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    //array[item++] = new TestCase( SECTION,    "var $123 = 5",      5,       eval("var $123 = 5;$123") );
    var $123 = 5;
    array[item++] = new TestCase( SECTION,    "var $123 = 5",      5,  $123 );
    //array[item++] = new TestCase( SECTION,    "var _123 = 5",      5,       eval("var _123 = 5;_123") );
    var _123 = 5;
    array[item++] = new TestCase( SECTION,    "var _123 = 5",      5,   _123);
    var MyNumber:Number = 100
    var mynumber:Number = 20
    array[item++] = new TestCase( SECTION,    "Testing case sensitivity of identifier",      false,  MyNumber==20);

    return ( array );
}
