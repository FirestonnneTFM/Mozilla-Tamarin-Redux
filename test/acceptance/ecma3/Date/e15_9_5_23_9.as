/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.9.5.23-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Date.prototype.setTime()";

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

    test_times = new Array( now, time, TIME_1970, TIME_1900, TIME_2000,
    UTC_FEB_29_2000, UTC_JAN_1_2005 );


    for ( var j = 0; j < test_times.length; j++ ) {
        addTestCase( new Date(UTC_JAN_1_2005), test_times[j] );
    }
    
        
    function addTestCase( d, t ) {
        array[item++] = new TestCase( SECTION,
                                        "(  ).setTime()",
                                        true, t ==
                                        d.setTime(t) );
    
        array[item++] = new TestCase( SECTION,
                                        "( ).setTime()",
                                        true, TimeClip(t+1.1) ==
                                        d.setTime(t+1.1) );
    
        array[item++] = new TestCase( SECTION,
                                        "().setTime()",
                                        true, t+1 ==
                                        d.setTime(t+1) );
    
        array[item++] = new TestCase( SECTION,
                                        "().setTime()",
                                        true, t-1 ==
                                        d.setTime(t-1) );
    
        array[item++] = new TestCase( SECTION,
                                        "( ).setTime()",
                                        true, t-TZ_ADJUST ==
                                        d.setTime(t-TZ_ADJUST) );
    
        array[item++] = new TestCase( SECTION,
                                        "( ).setTime()",
                                        true, t+TZ_ADJUST ==
                                        d.setTime(t+TZ_ADJUST) );
    }
    return array;
}

