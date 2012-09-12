/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var VERSION =   "ECMA_1";
    startTest();
    var SECTION =   "15.9.2.1";
    var TITLE =     "Date Constructor used as a function";
    var TYPEOF  =   "string";
    var TOLERANCE = 1000;

    writeHeaderToLog("15.9.2.1 The Date Constructor Called as a Function:  " +
                     "Date( year, month, date, hours, minutes, seconds, ms )" );
    var testcases = getTestCases();

//  all tests must call a function that returns an array of TestCase objects.
    test();


function compareDate(d1, d2) {
    //Dates may be off by a second
    if (d1 == d2) {
        return true;
    } else if (Math.abs(new Date(d1) - new Date(d2)) <= 1000) {
        return true;
    } else {
        return false;
    }
}


function getTestCases() {
    var array = new Array();
    var item = 0;

    var TODAY = new Date();

    // Dates around 1970

    array[item++] = new TestCase( SECTION, "Date(1970,0,1,0,0,0,0)",            true, compareDate((new Date()).toString(), Date(1970,0,1,0,0,0,0) ));
    array[item++] = new TestCase( SECTION, "Date(1969,11,31,15,59,59,999)",     true, compareDate((new Date()).toString(), Date(1969,11,31,15,59,59,999)));
    array[item++] = new TestCase( SECTION, "Date(1969,11,31,16,0,0,0)",         true, compareDate((new Date()).toString(), Date(1969,11,31,16,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date(1969,11,31,16,0,0,1)",         true, compareDate((new Date()).toString(), Date(1969,11,31,16,0,0,1)));

    // Dates around 2000
    array[item++] = new TestCase( SECTION, "Date(1999,11,15,59,59,999)",        true, compareDate((new Date()).toString(), Date(1999,11,15,59,59,999)));
    array[item++] = new TestCase( SECTION, "Date(1999,11,16,0,0,0,0)",          true, compareDate((new Date()).toString(), Date(1999,11,16,0,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date(1999,11,31,23,59,59,999)",     true, compareDate((new Date()).toString(), Date(1999,11,31,23,59,59,999)) );
    array[item++] = new TestCase( SECTION, "Date(2000,0,1,0,0,0,0)",            true, compareDate((new Date()).toString(), Date(2000,0,0,0,0,0,0) ));
    array[item++] = new TestCase( SECTION, "Date(2000,0,1,0,0,0,1)",            true, compareDate((new Date()).toString(), Date(2000,0,0,0,0,0,1) ));

    // Dates around 1900

    array[item++] = new TestCase( SECTION, "Date(1899,11,31,23,59,59,999)",     true, compareDate((new Date()).toString(), Date(1899,11,31,23,59,59,999)));
    array[item++] = new TestCase( SECTION, "Date(1900,0,1,0,0,0,0)",            true, compareDate((new Date()).toString(), Date(1900,0,1,0,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date(1900,0,1,0,0,0,1)",            true, compareDate((new Date()).toString(), Date(1900,0,1,0,0,0,1)));
    array[item++] = new TestCase( SECTION, "Date(1899,11,31,16,0,0,0,0)",       true, compareDate((new Date()).toString(), Date(1899,11,31,16,0,0,0,0)));

    // Dates around feb 29, 2000

    array[item++] = new TestCase( SECTION, "Date( 2000,1,29,0,0,0,0)",         true, compareDate((new Date()).toString(), Date(2000,1,29,0,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date( 2000,1,28,23,59,59,999)",    true, compareDate((new Date()).toString(), Date( 2000,1,28,23,59,59,999)));
    array[item++] = new TestCase( SECTION, "Date( 2000,1,27,16,0,0,0)",        true, compareDate((new Date()).toString(), Date(2000,1,27,16,0,0,0)));

    // Dates around jan 1, 2005
    array[item++] = new TestCase( SECTION, "Date(2004,11,31,23,59,59,999)",     true, compareDate((new Date()).toString(), Date(2004,11,31,23,59,59,999)));
    array[item++] = new TestCase( SECTION, "Date(2005,0,1,0,0,0,0)",            true, compareDate((new Date()).toString(), Date(2005,0,1,0,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date(2005,0,1,0,0,0,1)",            true, compareDate((new Date()).toString(), Date(2005,0,1,0,0,0,1)));
    array[item++] = new TestCase( SECTION, "Date(2004,11,31,16,0,0,0,0)",       true, compareDate((new Date()).toString(), Date(2004,11,31,16,0,0,0,0)));

    // Dates around jan 1, 2032
    array[item++] = new TestCase( SECTION, "Date(2031,11,31,23,59,59,999)",     true, compareDate((new Date()).toString(), Date(2031,11,31,23,59,59,999)));
    array[item++] = new TestCase( SECTION, "Date(2032,0,1,0,0,0,0)",            true, compareDate((new Date()).toString(), Date(2032,0,1,0,0,0,0)));
    array[item++] = new TestCase( SECTION, "Date(2032,0,1,0,0,0,1)",            true, compareDate((new Date()).toString(), Date(2032,0,1,0,0,0,1)));
    array[item++] = new TestCase( SECTION, "Date(2031,11,31,16,0,0,0,0)",       true, compareDate((new Date()).toString(), Date(2031,11,31,16,0,0,0,0)));

    return ( array );
}
