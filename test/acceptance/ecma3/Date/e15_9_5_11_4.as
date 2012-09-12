/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.9.5.11";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Date.prototype.getUTCDate()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var TZ_ADJUST = TZ_DIFF * msPerHour;

    addTestCase( TIME_1900 );


    function addTestCase( t ) {
        for ( var m = 0; m < 11; m++ ) {
            t += TimeInMonth(m);

            for ( var d = 0; d < TimeInMonth( m ); d += 7* msPerDay ) {
                t += d;
                array[item++] = new TestCase( SECTION,
                                        "(new Date("+t+")).getUTCDate()",
                                        DateFromTime((t)),
                                        (new Date(t)).getUTCDate() );
    /*
                array[item++] = new TestCase( SECTION,
                                        "(new Date("+(t+1)+")).getUTCDate()",
                                        DateFromTime((t+1)),
                                        (new Date(t+1)).getUTCDate() );

                array[item++] = new TestCase( SECTION,
                                        "(new Date("+(t-1)+")).getUTCDate()",
                                        DateFromTime((t-1)),
                                        (new Date(t-1)).getUTCDate() );

                array[item++] = new TestCase( SECTION,
                                        "(new Date("+(t-TZ_ADJUST)+")).getUTCDate()",
                                        DateFromTime((t-TZ_ADJUST)),
                                        (new Date(t-TZ_ADJUST)).getUTCDate() );

                array[item++] = new TestCase( SECTION,
                                        "(new Date("+(t+TZ_ADJUST)+")).getUTCDate()",
                                        DateFromTime((t+TZ_ADJUST)),
                                        (new Date(t+TZ_ADJUST)).getUTCDate() );
    */
            }
        }
    }

    return ( array );
}
