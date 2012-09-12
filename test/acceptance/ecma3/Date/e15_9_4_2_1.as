/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var SECTION = "15.9.4.2-1";       // provide a document reference (ie, ECMA section)
    var VERSION = "ECMA"; // Version of JavaScript or ECMA
    var TITLE   = "Regression Test for Date.parse";       // Provide ECMA section title or a description
    var BUGNUMBER = "http://bugzilla.mozilla.org/show_bug.cgi?id=4088";     // Provide URL to bugsplat or bugzilla report

    startTest();               // leave this alone
    writeHeaderToLog( SECTION + " "+ TITLE);
    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "new Date('1/1/1999 12:30 AM').toString()",
                new Date(1999,0,1,0,30).toString(),
                new Date('1/1/1999 12:30 AM').toString() );

    array[item++] = new TestCase( SECTION,  "new Date('1/1/1999 12:30 PM').toString()",
                 new Date( 1999,0,1,12,30 ).toString(),
                 new Date('1/1/1999 12:30 PM').toString() );

    array[item++] = new TestCase( SECTION,  "new Date('1/1/1999 13:30 AM')",
                "Invalid Date",
                new Date('1/1/1999 13:30 AM').toString() );


    array[item++] = new TestCase( SECTION,  "new Date('1/1/1999 13:30 PM')",
                "Invalid Date",
                new Date('1/1/1999 13:30 PM').toString() );

    return ( array );
}
