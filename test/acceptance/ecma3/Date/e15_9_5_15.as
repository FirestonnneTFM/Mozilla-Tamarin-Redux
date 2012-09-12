/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.9.5.15";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Date.prototype.getUTCHours()";

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

    addTestCase2( now );
    addTestCase( time );
    addTestCase( TIME_1970 );
    addTestCase( TIME_1900 );
    addTestCase( TIME_2000 );
    addTestCase( UTC_FEB_29_2000 );
    addTestCase( UTC_JAN_1_2005 );

    array[item++] = new TestCase( SECTION,
                                    "(new Date(NaN)).getUTCHours()",
                                    NaN,
                                    (new Date(NaN)).getUTCHours() );

    array[item++] = new TestCase( SECTION,
                                    "Date.prototype.getUTCHours.length",
                                    0,
                                    Date.prototype.getUTCHours.length );
    
    function addTestCase( t ) {
        for ( h = 0; h < 24; h+=3 ) {
                t += msPerHour;
                array[item++] = new TestCase( SECTION,
                                        "(new Date("+t+")).getUTCHours()",
                                        true, HourFromTime((t)) ==
                                        (new Date(t)).getUTCHours() );
        }
    }


    //used only for current Date
    function addTestCase2( t ) {
        for ( h = 0; h < 24; h+=3 ) {
                t += msPerHour;
                array[item++] = new TestCase( SECTION,
                                        "(new Date(currentDate)).getUTCHours()",
                                        true, HourFromTime((t)) ==
                                        (new Date(t)).getUTCHours() );
        }
    }

    return array;
}
