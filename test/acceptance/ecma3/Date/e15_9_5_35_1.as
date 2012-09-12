/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.9.5.35-1";
    var VERSION = "ECMA_1";
    startTest();

    writeHeaderToLog( SECTION + " Date.prototype.setUTCMonth(mon [,date] ) ");
    var testcases:Array=getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    
//    addNewTestCase( "TDATE = new Date(0);(TDATE).setUTCMonth(0);TDATE",
    var TDATE:Date = new Date(0);
    (TDATE).setUTCMonth(0);
    addNewTestCase( TDATE,
                    UTCDateFromTime(SetUTCMonth(0,0)),
                    LocalDateFromTime(SetUTCMonth(0,0)) );

   // addNewTestCase( "TDATE = new Date(0);(TDATE).setUTCMonth(11);TDATE",
    var TDATE:Date = new Date(0);
    (TDATE).setUTCMonth(11);
     addNewTestCase(TDATE,
            UTCDateFromTime(SetUTCMonth(0,11)),
                    LocalDateFromTime(SetUTCMonth(0,11)) );

//    addNewTestCase( "TDATE = new Date(0);(TDATE).setUTCMonth(3,4);TDATE",
    var TDATE:Date = new Date(0);
    (TDATE).setUTCMonth(3,4);
      addNewTestCase(TDATE,
            UTCDateFromTime(SetUTCMonth(0,3,4)),
                    LocalDateFromTime(SetUTCMonth(0,3,4)) );

    
    
    function addNewTestCase( DateString, UTCDate, LocalDate) {
       
           DateCase = DateString ;
    
    //    fixed_year = ( ExpectDate.year >=1900 || ExpectDate.year < 2000 ) ? ExpectDate.year - 1900 : ExpectDate.year;
    
        array[item++] = new TestCase( SECTION, "DateString+.getTime()",             UTCDate.value,       DateCase.getTime() );
        array[item++] = new TestCase( SECTION, "DateString+.valueOf()",             UTCDate.value,       DateCase.valueOf() );
    
        array[item++] = new TestCase( SECTION, "DateString+.getUTCFullYear()",      UTCDate.year,    DateCase.getUTCFullYear() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCMonth()",         UTCDate.month,  DateCase.getUTCMonth() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCDate()",          UTCDate.date,   DateCase.getUTCDate() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCDay()",           UTCDate.day,    DateCase.getUTCDay() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCHours()",         UTCDate.hours,  DateCase.getUTCHours() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCMinutes()",       UTCDate.minutes,DateCase.getUTCMinutes() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCSeconds()",       UTCDate.seconds,DateCase.getUTCSeconds() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCMilliseconds()",  UTCDate.ms,     DateCase.getUTCMilliseconds() );
    
        array[item++] = new TestCase( SECTION, "DateString+.getFullYear()",         LocalDate.year,       DateCase.getFullYear() );
        array[item++] = new TestCase( SECTION, "DateString+.getMonth()",            LocalDate.month,      DateCase.getMonth() );

    //Allow for DST variation on different platforms (osx) - see https://bugzilla.mozilla.org/show_bug.cgi?id=401898
    var date = DateCase.getDate();
    if (LocalDate.date == (date+1)) date++;
        array[item++] = new TestCase( SECTION, DateString+".getDate()",             LocalDate.date,       date);

    var day = DateCase.getDay();
    if (LocalDate.day == (day+1)) day++;
        array[item++] = new TestCase( SECTION, DateString+".getDay()",              LocalDate.day,        day );

    var hours = DateCase.getHours();
    if (LocalDate.hours == (hours+1)) {
        hours++;
    } else if (hours == 23 && LocalDate.hours == 0) {
        hours = 0;
    }
        array[item++] = new TestCase( SECTION, DateString+".getHours()",            LocalDate.hours,      hours );

        array[item++] = new TestCase( SECTION, "DateString+.getMinutes()",          LocalDate.minutes,    DateCase.getMinutes() );
        array[item++] = new TestCase( SECTION, "DateString+.getSeconds()",          LocalDate.seconds,    DateCase.getSeconds() );
        array[item++] = new TestCase( SECTION, "DateString+.getMilliseconds()",     LocalDate.ms,         DateCase.getMilliseconds() );
    
        if (!as3Enabled) {
            array[item++] = new TestCase( SECTION,
                                               "DateString+.toString=Object.prototype.toString;+DateString+.toString()",
                                               "[object Date]",(DateCase.myToString=Object.prototype.toString,DateCase.myToString()) );
         
            DateCase.toString = Object.prototype.toString;
            array[item++]  =new TestCase(SECTION,"DateCase.toString = Object.prototype.toString; DateCase.toString()","[object Date]", DateCase.toString() );
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

    d.time = MakeTime( d.hours, d.minutes, d.seconds, d.ms );
    d.value = TimeClip( MakeDate( MakeDay( d.year, d.month, d.date ), d.time ) );
    d.day = WeekDay( d.value );

    return (d);
}
function SetUTCMonth( t, month, date ) {
    var T       = t;
    var MONTH   = Number( month );
    var DATE    = ( date == void 0) ? DateFromTime(T) : Number( date );

    var RESULT4 = MakeDay(YearFromTime(T), MONTH, DATE );
    var RESULT5 = MakeDate( RESULT4, TimeWithinDay(T));

    return ( TimeClip(RESULT5) );
}
