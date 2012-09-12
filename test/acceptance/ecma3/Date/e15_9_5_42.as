/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.9.5.42";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Date.prototype.toUTCString";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,
                                    "Date.prototype.toUTCString.length",
                                    0,
                                    Date.prototype.toString.length );

    var now = new Date();

    // can't test the content of the string, but can verify that the string is
    // parsable by Date.parse

    array[item++] = new TestCase( SECTION,
                                    "Math.abs(Date.parse(now.toUTCString()) - now.valueOf()) < 1000",
                                    true,
                                    Math.abs(Date.parse(now.toUTCString()) - now.valueOf()) < 1000 );

    array[item++] = new TestCase( SECTION,
                                    "typeof now.toUTCString()",
                                    "string",
                                    typeof now.toUTCString() );
    // 1970

    TZ_ADJUST = TZ_DIFF * msPerHour;

    array[item++] = new TestCase( SECTION,
                                    "Date.parse( (new Date(0)).toUTCString() )",
                                    0,
                                    Date.parse( (new Date(0)).toUTCString() ) )

    array[item++] = new TestCase( SECTION,
                                    "Date.parse( (new Date(+TZ_ADJUST+)).toUTCString() )",
                                    TZ_ADJUST,
                                    Date.parse( (new Date(TZ_ADJUST)).toUTCString() ) )

    // 1900
    array[item++] = new TestCase( SECTION,
                                    "Date.parse( (new Date(+TIME_1900+).toUTCString() )",
                                    TIME_1900,
                                    Date.parse( (new Date(TIME_1900)).toUTCString() ) )

    array[item++] = new TestCase( SECTION,
                                    "Date.parse( (new Date(+TIME_1900 -TZ_ADJUST+)).toUTCString() )",
                                    TIME_1900 -TZ_ADJUST,
                                    Date.parse( (new Date(TIME_1900 -TZ_ADJUST)).toUTCString() ) )

    // 2000
    array[item++] = new TestCase( SECTION,
                                    "Date.parse( (new Date(+TIME_2000+)).toUTCString() )",
                                    TIME_2000,
                                    Date.parse( (new Date(TIME_2000)).toUTCString() ) )

    array[item++] = new TestCase( SECTION,
                                    "Date.parse( (new Date(+TIME_2000 -TZ_ADJUST+)).toUTCString() )",
                                    TIME_2000 -TZ_ADJUST,
                                    Date.parse( (new Date(TIME_2000 -TZ_ADJUST)).toUTCString() ) )

    // 29 Feb 2000

    var UTC_29_FEB_2000 = TIME_2000 + 31*msPerDay + 28*msPerDay;
    array[item++] = new TestCase( SECTION,
                                    "Date.parse( (new Date(+UTC_29_FEB_2000+)).toUTCString() )",
                                    UTC_29_FEB_2000,
                                    Date.parse( (new Date(UTC_29_FEB_2000)).toUTCString() ) )

    array[item++] = new TestCase( SECTION,
                                    "Date.parse( (new Date(+(UTC_29_FEB_2000-1000)+)).toUTCString() )",
                                    UTC_29_FEB_2000-1000,
                                    Date.parse( (new Date(UTC_29_FEB_2000-1000)).toUTCString() ) )


    array[item++] = new TestCase( SECTION,
                                    "Date.parse( (new Date(+(UTC_29_FEB_2000-TZ_ADJUST)+)).toUTCString() )",
                                    UTC_29_FEB_2000-TZ_ADJUST,
                                    Date.parse( (new Date(UTC_29_FEB_2000-TZ_ADJUST)).toUTCString() ) )
    // 2O05

    var UTC_1_JAN_2005 = TIME_2000 + TimeInYear(2000) + TimeInYear(2001) +
    TimeInYear(2002) + TimeInYear(2003) + TimeInYear(2004);
    array[item++] = new TestCase( SECTION,
                                    "Date.parse( (new Date(+UTC_1_JAN_2005+)).toUTCString() )",
                                    UTC_1_JAN_2005,
                                    Date.parse( (new Date(UTC_1_JAN_2005)).toUTCString() ) )

    array[item++] = new TestCase( SECTION,
                                    "Date.parse( (new Date(+(UTC_1_JAN_2005-1000)+)).toUTCString() )",
                                    UTC_1_JAN_2005-1000,
                                    Date.parse( (new Date(UTC_1_JAN_2005-1000)).toUTCString() ) )

    array[item++] = new TestCase( SECTION,
                                    "Date.parse( (new Date(+(UTC_1_JAN_2005-TZ_ADJUST)+)).toUTCString() )",
                                    UTC_1_JAN_2005-TZ_ADJUST,
                                    Date.parse( (new Date(UTC_1_JAN_2005-TZ_ADJUST)).toUTCString() ) )

    return array;
}
