/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.9.5.13";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Date.prototype.getUTCDay()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var TZ_ADJUST = TZ_DIFF * msPerHour;

    // get the current time
    var now = (new Date()).valueOf();

    // calculate time for year 0
    for ( var time = 0, year = 1969; year >= 0; year-- ) {
        time -= TimeInYear(year);
    }
    // get time for 29 feb 2000

    var UTC_FEB_29_2000 = TIME_2000 + 31*msPerDay + 28*msPerHour;

    // get time for 1 jan 2005

    var UTC_JAN_1_2005 = TIME_2000 + TimeInYear(2000)+TimeInYear(2001)+
    TimeInYear(2002)+TimeInYear(2003)+TimeInYear(2004);

    array[item++] = new TestCase( SECTION,
                                    "(new Date(NaN)).getUTCDay()",
                                    NaN,
                                    (new Date(NaN)).getUTCDay() );

    array[item++] = new TestCase( SECTION,
                                    "Date.prototype.getUTCDay.length",
                                    0,
                                    Date.prototype.getUTCDay.length );

    function addTestCase( t ) {
        for ( var m = 0; m < 12; m++ ) {
            t += TimeInMonth(m);

            for ( d = 0; d < TimeInMonth(m); d+= msPerDay*7 ) {
                t += d;

                array[item++] = new TestCase( SECTION,
                                        "(new Date("+t+")).getUTCDay()",
                                        WeekDay((t)),
                                        (new Date(t)).getUTCDay() );
            }
        }
    }

    return ( array );
}
