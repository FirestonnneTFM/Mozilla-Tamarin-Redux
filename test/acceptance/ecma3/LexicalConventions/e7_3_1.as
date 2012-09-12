/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "7.3-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Comments";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    array[item++] = new TestCase( SECTION,
                                  "a comment with a line terminator string, and text following",
                                  "pass",
                                  "pass");

    // "\u000A" array[item].actual = "fail";

    array[item] = new TestCase( SECTION,
                                "// test \\n array[item].actual = \"pass\"",
                                 "pass",
                                 "" );

     array[item++].actual = 'pass';

     return ( array );
}
