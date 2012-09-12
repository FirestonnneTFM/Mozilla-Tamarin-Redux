/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.4.2.1-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Array Constructor:  new Array( item0, item1, ...)";

    writeHeaderToLog( SECTION + " "+ TITLE);

    testcases = getTestCases();

    test();

function getTestCases()
{
    var array = new Array();

    //var TEST_STRING = "new Array(";
    var ARGUMENTS = ""
    var TEST_LENGTH = Math.pow(2,10); //Math.pow(2,32);

    for ( var index = 0; index < TEST_LENGTH; index++ )
    {
        ARGUMENTS += index;
        ARGUMENTS += (index == (TEST_LENGTH-1) ) ? "" : ",";
    }

    //TEST_STRING += ARGUMENTS + ")";
    var TEST_STRING = ARGUMENTS.split(",");

    var TEST_ARRAY = TEST_STRING;

    for ( var item = 0; item < TEST_LENGTH; item++ )
    {
        array[item] = new TestCase( SECTION, "["+item+"]", item+"", TEST_ARRAY[item] );
    }

    array[item++ ] = new TestCase( SECTION, "new Array( ["+TEST_LENGTH+" arguments] ) +''",    ARGUMENTS, TEST_ARRAY +"" );

    return ( array );
}
