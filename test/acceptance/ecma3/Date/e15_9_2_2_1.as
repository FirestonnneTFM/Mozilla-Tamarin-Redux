/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var VERSION = 9706;
    startTest();
    var SECTION = "15.9.2.2";
    var TOLERANCE = 100;
    var TITLE = "The Date Constructor Called as a Function";

    writeHeaderToLog(SECTION+" "+TITLE );
    var testcases = getTestCases();

//  all tests must call a function that returns an array of TestCase objects.
    test();




function getTestCases() {
    var array = new Array();
    var item = 0;

    // Dates around 1970

    array[item++] = new TestCase( SECTION, "Date(1970,0,1,0,0,0)",          true, compareDate(( Date()).toString(), Date(1970,0,1,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date(1969,11,31,15,59,59)",     true, compareDate(( Date()).toString(), Date(1969,11,31,15,59,59)));
    array[item++] = new TestCase( SECTION, "Date(1969,11,31,16,0,0)",       true, compareDate(( Date()).toString(), Date(1969,11,31,16,0,0)));
    array[item++] = new TestCase( SECTION, "Date(1969,11,31,16,0,1)",       true, compareDate(( Date()).toString(), Date(1969,11,31,16,0,1)));

    // Dates around 2000
    array[item++] = new TestCase( SECTION, "Date(1999,11,15,59,59)",        true, compareDate(( Date()).toString(), Date(1999,11,15,59,59)));
    array[item++] = new TestCase( SECTION, "Date(1999,11,16,0,0,0)",        true, compareDate(( Date()).toString(), Date(1999,11,16,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date(1999,11,31,23,59,59)",     true, compareDate(( Date()).toString(), Date(1999,11,31,23,59,59)));
    array[item++] = new TestCase( SECTION, "Date(2000,0,1,0,0,0)",          true, compareDate(( Date()).toString(), Date(2000,0,0,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date(2000,0,1,0,0,1)",          true, compareDate(( Date()).toString(), Date(2000,0,0,0,0,1)));

    // Dates around 1900

    array[item++] = new TestCase( SECTION, "Date(1899,11,31,23,59,59)",     true, compareDate(( Date()).toString(), Date(1899,11,31,23,59,59)));
    array[item++] = new TestCase( SECTION, "Date(1900,0,1,0,0,0)",          true, compareDate(( Date()).toString(), Date(1900,0,1,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date(1900,0,1,0,0,1)",          true, compareDate(( Date()).toString(), Date(1900,0,1,0,0,1)));
    array[item++] = new TestCase( SECTION, "Date(1899,11,31,16,0,0,0)",     true, compareDate(( Date()).toString(), Date(1899,11,31,16,0,0,0)));

    // Dates around feb 29, 2000

    array[item++] = new TestCase( SECTION, "Date( 2000,1,29,0,0,0)",        true, compareDate(( Date()).toString(), Date(2000,1,29,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date( 2000,1,28,23,59,59)",     true, compareDate(( Date()).toString(), Date( 2000,1,28,23,59,59)));
    array[item++] = new TestCase( SECTION, "Date( 2000,1,27,16,0,0)",       true, compareDate(( Date()).toString(), Date(2000,1,27,16,0,0)));

    // Dates around jan 1, 2005
    array[item++] = new TestCase( SECTION, "Date(2004,11,31,23,59,59)",     true, compareDate(( Date()).toString(), Date(2004,11,31,23,59,59)));
    array[item++] = new TestCase( SECTION, "Date(2005,0,1,0,0,0)",          true, compareDate(( Date()).toString(), Date(2005,0,1,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date(2005,0,1,0,0,1)",          true, compareDate(( Date()).toString(), Date(2005,0,1,0,0,1)));
    array[item++] = new TestCase( SECTION, "Date(2004,11,31,16,0,0,0)",     true, compareDate(( Date()).toString(), Date(2004,11,31,16,0,0,0)));

    // Dates around jan 1, 2032
    array[item++] = new TestCase( SECTION, "Date(2031,11,31,23,59,59)",     true, compareDate(( Date()).toString(), Date(2031,11,31,23,59,59)));
    array[item++] = new TestCase( SECTION, "Date(2032,0,1,0,0,0)",          true, compareDate(( Date()).toString(), Date(2032,0,1,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date(2032,0,1,0,0,1)",          true, compareDate(( Date()).toString(), Date(2032,0,1,0,0,1)));
    array[item++] = new TestCase( SECTION, "Date(2031,11,31,16,0,0,0)",     true, compareDate(( Date()).toString(), Date(2031,11,31,16,0,0,0)));

    return ( array );
}
