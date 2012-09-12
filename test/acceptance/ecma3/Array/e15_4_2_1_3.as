/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.4.2.1-3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Array Constructor:  new Array( item0, item1, ...)";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();

    var ARGUMENTS = ""
    var TEST_LENGTH = Math.pow(2,10); //Math.pow(2,32);

    for ( var index = 0; index < TEST_LENGTH; index++ ) {
        ARGUMENTS += index;
        ARGUMENTS += (index == (TEST_LENGTH-1) ) ? "" : ",";
    }

    var TEST_ARRAY = ARGUMENTS.split(",");

    var item;
    for ( item = 0; item < TEST_LENGTH; item++ ) {
        array[item] = new TestCase( SECTION, "TEST_ARRAY["+item+"]",     item+"",    TEST_ARRAY[item] );
    }

    array[item++] = new TestCase( SECTION, "new Array( ["+TEST_LENGTH+" arguments] ) +''",  ARGUMENTS,          TEST_ARRAY +"" );
    array[item++] = new TestCase( SECTION, "TEST_ARRAY.toString", "function Function() {}", (TEST_ARRAY.toString).toString());
    array[item++] = new TestCase( SECTION, "TEST_ARRAY.join", "function Function() {}", (TEST_ARRAY.join).toString() );
    array[item++] = new TestCase( SECTION, "TEST_ARRAY.sort", "function Function() {}", (TEST_ARRAY.sort).toString() );
    array[item++] = new TestCase( SECTION, "TEST_ARRAY.reverse", "function Function() {}", (TEST_ARRAY.reverse).toString());
    array[item++] = new TestCase( SECTION, "TEST_ARRAY.length", TEST_LENGTH,  TEST_ARRAY.length);

    TEST_ARRAY.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,
                                "TEST_ARRAY.toString = Object.prototype.toString; TEST_ARRAY.toString()",
                                "[object Array]",
                                TEST_ARRAY.toString());

    return ( array );
}
