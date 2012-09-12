/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.9.5.17.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Date.prototype.getUTCDay()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    // get the current time
    var now = (new Date()).valueOf();

    addTestCase( now );
    array[item++] = new TestCase( SECTION,
                                    "(new Date(NaN)).getUTCDay()",
                                    NaN,
                                    (new Date(NaN)).getUTCDay() );
    array[item++] = new TestCase( SECTION,
                                    "Date.prototype.getUTCDay.length",
                                    0,
                                    Date.prototype.getUTCDay.length );

    
    function addTestCase( t ) {
        for ( d = 0; d < TimeInMonth(MonthFromTime(t)); d+= msPerDay ) {
            t += d;
            array[item++] = new TestCase( SECTION,
                                        "(new Date(currentTime+"+d+")).getUTCDay()",
                                        true, WeekDay(t) ==
                                        (new Date(t)).getUTCDay() );
        }
    }
    return array;
}
