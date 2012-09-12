/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.9.5.30-1";
    var VERSION = "ECMA_1";
    startTest();

    writeHeaderToLog( SECTION + " Date.prototype.setHours( hour [, min, sec, ms] )");

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;
    
    addNewTestCase( 0,0,0,0,void 0,
                    "TDATE = new Date(0);(TDATE).setHours(0);TDATE" );

    addNewTestCase( 28800000, 23, 59, 999,void 0,
                    "TDATE = new Date(28800000);(TDATE).setHours(23,59,999);TDATE" );

    addNewTestCase( 28800000, 999, 999, void 0, void 0,
                    "TDATE = new Date(28800000);(TDATE).setHours(999,999);TDATE" );

    addNewTestCase( 28800000,999,0, void 0, void 0,
                    "TDATE = new Date(28800000);(TDATE).setHours(999);TDATE" );

    addNewTestCase( 28800000,-8, void 0, void 0, void 0,
                    "TDATE = new Date(28800000);(TDATE).setHours(-8);TDATE" );

    addNewTestCase( 946684800000,8760, void 0, void 0, void 0,
                "TDATE = new Date(946684800000);(TDATE).setHours(8760);TDATE" );

    addNewTestCase( TIME_2000 - msPerDay, 23, 59, 59, 999,
                    "d = new Date( " + (TIME_2000-msPerDay) +"); d.setHours(23,59,59,999)" );

    addNewTestCase( TIME_2000 - msPerDay, 23, 59, 59, 1000,
                    "d = new Date( " + (TIME_2000-msPerDay) +"); d.setHours(23,59,59,1000)" );


/*
    addNewTestCase( "TDATE = new Date(-2208988800000);(TDATE).setHours(59,999);TDATE",
                    UTCDateFromTime(SetHours(-2208988800000,59,999)),
                    LocalDateFromTime(SetHours(-2208988800000,59,999)) );

    addNewTestCase( "TDATE = new Date(-2208988800000);(TDATE).setUTCMilliseconds(123456789);TDATE",
                    UTCDateFromTime(SetUTCMilliseconds(-2208988800000,123456789)),
                    LocalDateFromTime(SetUTCMilliseconds(-2208988800000,123456789)) );

    addNewTestCase( "TDATE = new Date(-2208988800000);(TDATE).setUTCMilliseconds(123456);TDATE",
                    UTCDateFromTime(SetUTCMilliseconds(-2208988800000,123456)),
                    LocalDateFromTime(SetUTCMilliseconds(-2208988800000,123456)) );

    addNewTestCase( "TDATE = new Date(-2208988800000);(TDATE).setUTCMilliseconds(-123456);TDATE",
                    UTCDateFromTime(SetUTCMilliseconds(-2208988800000,-123456)),
                    LocalDateFromTime(SetUTCMilliseconds(-2208988800000,-123456)) );

    addNewTestCase( "TDATE = new Date(0);(TDATE).setUTCMilliseconds(-999);TDATE",
                    UTCDateFromTime(SetUTCMilliseconds(0,-999)),
                    LocalDateFromTime(SetUTCMilliseconds(0,-999)) );
*/

    
    function addNewTestCase( time, hours, min, sec, ms, DateString) {
        var UTCDate =   UTCDateFromTime( SetHours( time, hours, min, sec, ms ));
        var LocalDate = LocalDateFromTime( SetHours( time, hours, min, sec, ms ));
    
        var DateCase = new Date( time );
    
        if ( min == void 0 ) {
            DateCase.setHours( hours );
        } else {
            if ( sec == void 0 ) {
                DateCase.setHours( hours, min );
            } else {
                if ( ms == void 0 ) {
                    DateCase.setHours( hours, min, sec );
                } else {
                    DateCase.setHours( hours, min, sec, ms );
                }
            }
        }
    
    
        array[item++] = new TestCase( SECTION, DateString+".getTime()",             UTCDate.value,       DateCase.getTime() );
        array[item++] = new TestCase( SECTION, DateString+".valueOf()",             UTCDate.value,       DateCase.valueOf() );
    
        array[item++] = new TestCase( SECTION, DateString+".getUTCFullYear()",      UTCDate.year,    DateCase.getUTCFullYear() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCMonth()",         UTCDate.month,  DateCase.getUTCMonth() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCDate()",          UTCDate.date,   DateCase.getUTCDate() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCDay()",           UTCDate.day,    DateCase.getUTCDay() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCHours()",         UTCDate.hours,  DateCase.getUTCHours() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCMinutes()",       UTCDate.minutes,DateCase.getUTCMinutes() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCSeconds()",       UTCDate.seconds,DateCase.getUTCSeconds() );
        array[item++] = new TestCase( SECTION, DateString+".getUTCMilliseconds()",  UTCDate.ms,     DateCase.getUTCMilliseconds() );
    
        array[item++] = new TestCase( SECTION, DateString+".getFullYear()",         LocalDate.year,       DateCase.getFullYear() );
        array[item++] = new TestCase( SECTION, DateString+".getMonth()",            LocalDate.month,      DateCase.getMonth() );
        array[item++] = new TestCase( SECTION, DateString+".getDate()",             LocalDate.date,       DateCase.getDate() );
        array[item++] = new TestCase( SECTION, DateString+".getDay()",              LocalDate.day,        DateCase.getDay() );
        array[item++] = new TestCase( SECTION, DateString+".getHours()",            LocalDate.hours,      DateCase.getHours() );
        array[item++] = new TestCase( SECTION, DateString+".getMinutes()",          LocalDate.minutes,    DateCase.getMinutes() );
        array[item++] = new TestCase( SECTION, DateString+".getSeconds()",          LocalDate.seconds,    DateCase.getSeconds() );
        array[item++] = new TestCase( SECTION, DateString+".getMilliseconds()",     LocalDate.ms,         DateCase.getMilliseconds() );
    
        if (!as3Enabled) {
            DateCase.toString = Object.prototype.toString;
            array[item++]  =new TestCase(SECTION,"DateCase.toString = Object.prototype.toString; DateCase.toString()","[object Date]", DateCase.toString() );
        
        
            array[item++] = new TestCase( SECTION,
                                              DateString+".myToString=Object.prototype.toString;"+DateString+".myToString()",
                                              "[object Date]",
                                              (DateCase.myToString = Object.prototype.toString, DateCase.myToString()) );
        }
    }
    return array;
}

function MyDate() {
    this.year = 0;
    this.month = 0;
    this.date = 0;
    this.hours = 0;
    this.minutes = 0;
    this.seconds = 0;
    this.ms = 0;
}
function LocalDateFromTime(t) {
    t = LocalTime(t);
    return ( MyDateFromTime(t) );
}
function UTCDateFromTime(t) {
 return ( MyDateFromTime(t) );
}
function MyDateFromTime( t ) {
    var d = new MyDate();
    d.year = YearFromTime(t);
    d.month = MonthFromTime(t);
    d.date = DateFromTime(t);
    d.hours = HourFromTime(t);
    d.minutes = MinFromTime(t);
    d.seconds = SecFromTime(t);
    d.ms = msFromTime(t);

    d.day = WeekDay( t );
    d.time = MakeTime( d.hours, d.minutes, d.seconds, d.ms );
    d.value = TimeClip( MakeDate( MakeDay( d.year, d.month, d.date ), d.time ) );

    return (d);
}
function SetHours( t, hour, min, sec, ms ) {
    var TIME = LocalTime(t);
    var HOUR = Number(hour);
    var MIN =  ( min == void 0) ? MinFromTime(TIME) : Number(min);
    var SEC  = ( sec == void 0) ? SecFromTime(TIME) : Number(sec);
    var MS   = ( ms == void 0 ) ? msFromTime(TIME)  : Number(ms);
    var RESULT6 = MakeTime( HOUR,
                            MIN,
                            SEC,
                            MS );
    var UTC_TIME = UTC(  MakeDate(Day(TIME), RESULT6) );
    return ( TimeClip(UTC_TIME) );
}
