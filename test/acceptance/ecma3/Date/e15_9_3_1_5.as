/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.9.3.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "new Date( year, month, date, hours, minutes, seconds, ms )";

    var TIME        = 0;
    var UTC_YEAR    = 1;
    var UTC_MONTH   = 2;
    var UTC_DATE    = 3;
    var UTC_DAY     = 4;
    var UTC_HOURS   = 5;
    var UTC_MINUTES = 6;
    var UTC_SECONDS = 7;
    var UTC_MS      = 8;

    var YEAR        = 9;
    var MONTH       = 10;
    var DATE        = 11;
    var DAY         = 12;
    var HOURS       = 13;
    var MINUTES     = 14;
    var SECONDS     = 15;
    var MS          = 16;

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases( ) {
    var array = new Array();
    var item = 0;

    // all the "ResultArrays" below are hard-coded to Pacific Standard Time values -
    var TZ_ADJUST =  TZ_PST * msPerHour;

    // Dates around 2005

    var UTC_YEAR_2005 = TIME_2000 + TimeInYear(2000) + TimeInYear(2001) +
    TimeInYear(2002) + TimeInYear(2003) + TimeInYear(2004);

    addNewTestCase( new Date(2005,0,1,0,0,0,0),
                    "new Date(2005,0,1,0,0,0,0)",
                    [UTC_YEAR_2005-TZ_ADJUST,2005,0,1,6,8,0,0,0,2005,0,1,6,0,0,0,0] );

    addNewTestCase( new Date(2004,11,31,16,0,0,0),
                    "new Date(2004,11,31,16,0,0,0)",
                    [UTC_YEAR_2005,2005,0,1,6,0,0,0,0,2004,11,31,5,16,0,0,0] );
/*
   This test case is incorrect.  Need to fix the DaylightSavings functions in
   shell.js for this to work properly.

    // Daylight Savings test case

    var DST_START_1998 = UTC( GetFirstSundayInApril(TimeFromYear(1998)) + 2*msPerHour )

    addNewTestCase( new Date(1998,3,5,1,59,59,999),
                    "new Date(1998,3,5,1,59,59,999)",
                    [DST_START_1998-1,1998,3,5,0,9,59,59,999,1998,3,5,0,1,59,59,999] );

    addNewTestCase( new Date(1998,3,5,2,0,0,0),
                    "new Date(1998,3,5,2,0,0,0)",
                    [DST_START_1998,1998,3,5,0,10,0,0,0,1998,3,5,0,3,0,0,0]);

    var DST_END_1998 = UTC( GetLastSundayInOctober(TimeFromYear(1998)) + 2*msPerHour );

    addNewTestCase ( new Date(1998,9,25,1,59,59,999),
                    "new Date(1998,9,25,1,59,59,999)",
                    [DST_END_1998-1,1998,9,25,0,8,59,59,999,1998,9,25,0,1,59,59,999] );

    addNewTestCase ( new Date(1998,9,25,2,0,0,0),
                    "new Date(1998,9,25,2,0,0,0)",
                    [DST_END_1998,1998,9,25,0,9,0,0,0,1998,9,25,0,1,0,0,0] );
*/

    function addNewTestCase( DateCase, DateString, ResultArray ) {
        //adjust hard-coded ResultArray for tester's timezone instead of PST
        adjustResultArray(ResultArray);

        var item = array.length;

        array[item++] = new TestCase( SECTION, DateString+".getTime()", ResultArray[TIME],       DateCase.getTime() );
        array[item++] = new TestCase( SECTION, DateString+".valueOf()", ResultArray[TIME],       DateCase.valueOf() );

        array[item++] = new TestCase( SECTION, DateString+".getUTCFullYear()",      ResultArray[UTC_YEAR],  DateCase.getUTCFullYear() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCMonth()",         ResultArray[UTC_MONTH],  DateCase.getUTCMonth() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCDate()",          ResultArray[UTC_DATE],   DateCase.getUTCDate() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCDay()",           ResultArray[UTC_DAY],    DateCase.getUTCDay() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCHours()",         ResultArray[UTC_HOURS],  DateCase.getUTCHours() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCMinutes()",       ResultArray[UTC_MINUTES],DateCase.getUTCMinutes() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCSeconds()",       ResultArray[UTC_SECONDS],DateCase.getUTCSeconds() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCMilliseconds()",  ResultArray[UTC_MS],     DateCase.getUTCMilliseconds() );

        array[item++] = new TestCase( SECTION, DateString+".getFullYear()",         ResultArray[YEAR],       DateCase.getFullYear() );
        array[item++] = new TestCase( SECTION, DateString+".getMonth()",            ResultArray[MONTH],      DateCase.getMonth() );
        array[item++] = new TestCase( SECTION, DateString+".getDate()",             ResultArray[DATE],       DateCase.getDate() );
        array[item++] = new TestCase( SECTION, DateString+".getDay()",              ResultArray[DAY],        DateCase.getDay() );
        array[item++] = new TestCase( SECTION, DateString+".getHours()",            ResultArray[HOURS],      DateCase.getHours() );
        array[item++] = new TestCase( SECTION, DateString+".getMinutes()",          ResultArray[MINUTES],    DateCase.getMinutes() );
        array[item++] = new TestCase( SECTION, DateString+".getSeconds()",          ResultArray[SECONDS],    DateCase.getSeconds() );
        array[item++] = new TestCase( SECTION, DateString+".getMilliseconds()",     ResultArray[MS],         DateCase.getMilliseconds() );
    }

    return ( array );
}
