/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "7.7.3-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Numeric Literals";
    var BUGNUMBER="122884";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,
        "9",
        9,
        9 );

    array[item++] = new TestCase( SECTION,
        "09",
        9,
        09 );

    array[item++] = new TestCase( SECTION,
        "099",
        99,
        099 );


    array[item++] = new TestCase( SECTION,
        "077",
        77,
        077 );
        
    return array;
}
