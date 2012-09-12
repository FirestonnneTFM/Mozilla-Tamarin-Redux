/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var VERSION = "ECMA_1";
    startTest();
    var SECTION = "15.9.3.8";
    var TYPEOF  = "object";

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


//  for TCMS, the testcases array must be global.
    var tc= 0;
    var TITLE = "Date constructor:  new Date( value )";
    var SECTION = "15.9.3.8";
    var VERSION = "ECMA_1";
    startTest();

    writeHeaderToLog( SECTION +" " + TITLE );

    testcases = getTestCases();

//  all tests must call a function that returns a boolean value
    test();

function getTestCases( ) {
    var array = new Array();
    var item = 0;

    // all the "ResultArrays" below are hard-coded to Pacific Standard Time values -
    var TZ_ADJUST =  -TZ_PST * msPerHour;


    // Dates around 1900

    var PST_1900 = TIME_1900 + 8*msPerHour;

    addNewTestCase( new Date( TIME_1900 ),
                    "new Date("+TIME_1900+")",
                    [TIME_1900,1900,0,1,1,0,0,0,0,1899,11,31,0,16,0,0,0] );

    addNewTestCase( new Date(PST_1900),
                    "new Date("+PST_1900+")",
                    [ PST_1900,1900,0,1,1,8,0,0,0,1900,0,1,1,0,0,0,0] );

    addNewTestCase( new Date( (new Date(TIME_1900)).toString() ),
                    "new Date(\+(new Date(TIME_1900)).toString()+\)",
                    [TIME_1900,1900,0,1,1,0,0,0,0,1899,11,31,0,16,0,0,0] );

    addNewTestCase( new Date( (new Date(PST_1900)).toString() ),
                    "new Date(\+(new Date(PST_1900 )).toString()+\)",
                    [ PST_1900,1900,0,1,1,8,0,0,0,1900,0,1,1,0,0,0,0] );

    addNewTestCase( new Date( (new Date(TIME_1900)).toUTCString() ),
                    "new Date(\""+(new Date(TIME_1900)).toUTCString()+"\")",
                    [TIME_1900,1900,0,1,1,0,0,0,0,1899,11,31,0,16,0,0,0] );

    addNewTestCase( new Date( (new Date(PST_1900)).toUTCString() ),
                    "new Date(\""+(new Date(PST_1900 )).toUTCString()+"\")",
                    [ PST_1900,1900,0,1,1,8,0,0,0,1900,0,1,1,0,0,0,0] );

/*
   This test case is incorrect.  Need to fix the DaylightSavings functions in
   shell.js for this to work properly.

    var DST_START_1998 = UTC( GetFirstSundayInApril(TimeFromYear(1998)) + 2*msPerHour )

    addNewTestCase( new Date(DST_START_1998-1),
                    "new Date("+(DST_START_1998-1)+")",
                    [DST_START_1998-1,1998,3,5,0,9,59,59,999,1998,3,5,0,1,59,59,999] );

    addNewTestCase( new Date(DST_START_1998),
                    "new Date("+DST_START_1998+")",
                    [DST_START_1998,1998,3,5,0,10,0,0,0,1998,3,5,0,3,0,0,0]);

    var DST_END_1998 = UTC( GetLastSundayInOctober(TimeFromYear(1998)) + 2*msPerHour );

    addNewTestCase ( new Date(DST_END_1998-1),
                    "new Date("+(DST_END_1998-1)+")",
                    [DST_END_1998-1,1998,9,25,0,8,59,59,999,1998,9,25,0,1,59,59,999] );

    addNewTestCase ( new Date(DST_END_1998),
                    "new Date("+DST_END_1998+")",
                    [DST_END_1998,1998,9,25,0,9,0,0,0,1998,9,25,0,1,0,0,0] );
*/

    function addNewTestCase( DateCase, DateString, ResultArray ) {
        //adjust hard-coded ResultArray for tester's timezone instead of PST
        adjustResultArray(ResultArray, 'msMode');

        item = array.length;

        array[item++] = new TestCase( SECTION, DateString+".getTime()", ResultArray[TIME],       DateCase.getTime() );
        array[item++] = new TestCase( SECTION, DateString+".valueOf()", ResultArray[TIME],       DateCase.valueOf() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCFullYear()",      ResultArray[UTC_YEAR], DateCase.getUTCFullYear() );
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
