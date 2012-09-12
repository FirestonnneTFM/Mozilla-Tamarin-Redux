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

    addTestCase( TIME_2000 );

    function addTestCase( t ) {
        for ( var m = 0; m < 12; m++ ) {
            t += TimeInMonth(m);

            for ( d = 0; d < TimeInMonth(m); d+= msPerDay*14 ) {
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
