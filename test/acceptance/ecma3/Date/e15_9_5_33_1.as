/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.9.5.33-1";
    var VERSION = "ECMA_1";
    startTest();

    writeHeaderToLog( SECTION + " Date.prototype.setUTCDate(date) ");
    var testcases:Array = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;
    
    // addNewTestCase( "TDATE = new Date(0);(TDATE).setUTCDate(31);TDATE",
    TDATE = new Date(0);
    (TDATE).setUTCDate(31);
    
    addNewTestCase( TDATE, UTCDateFromTime(SetUTCDate(0,31)), LocalDateFromTime(SetUTCDate(0,31)) );

    
    //   addNewTestCase( "TDATE = new Date(0);(TDATE).setUTCDate(1);TDATE",
    TDATE = new Date(0);
    (TDATE).setUTCDate(1);
    
    addNewTestCase(TDATE, UTCDateFromTime(SetUTCDate(0,1)), LocalDateFromTime(SetUTCDate(0,1)) );


    // addNewTestCase( "TDATE = new Date(86400000);(TDATE).setUTCDate(1);TDATE",
    TDATE = new Date(86400000);
    (TDATE).setUTCDate(1);

    addNewTestCase( TDATE, UTCDateFromTime(SetUTCDate(86400000,1)), LocalDateFromTime(SetUTCDate(86400000,1)) );


        
    
    function addNewTestCase( DateString, UTCDate, LocalDate) {
        var DateCase:Date = new Date();
        DateCase = DateString ;
    
        array[item++] = new TestCase( SECTION, "Date.getTime()",             UTCDate.value,       DateCase.getTime() );
        array[item++] = new TestCase( SECTION, "Date.valueOf()",             UTCDate.value,       DateCase.valueOf() );
    
        array[item++] = new TestCase( SECTION, "Date.getUTCFullYear()",      UTCDate.year,    DateCase.getUTCFullYear() );
        array[item++] = new TestCase( SECTION, "Date.getUTCMonth()",         UTCDate.month,  DateCase.getUTCMonth() );
        array[item++] = new TestCase( SECTION, "Date.getUTCDate()",          UTCDate.date,   DateCase.getUTCDate() );
        array[item++] = new TestCase( SECTION, "Date.getUTCDay()",           UTCDate.day,    DateCase.getUTCDay() );
        array[item++] = new TestCase( SECTION, "Date.getUTCHours()",         UTCDate.hours,  DateCase.getUTCHours() );
        array[item++] = new TestCase( SECTION, "Date.getUTCMinutes()",       UTCDate.minutes,DateCase.getUTCMinutes() );
        array[item++] = new TestCase( SECTION, "Date.getUTCSeconds()",       UTCDate.seconds,DateCase.getUTCSeconds() );
        array[item++] = new TestCase( SECTION, "Date.getUTCMilliseconds()",  UTCDate.ms,     DateCase.getUTCMilliseconds() );
    
        array[item++] = new TestCase( SECTION, "Date.getFullYear()",         LocalDate.year,       DateCase.getFullYear() );
        array[item++] = new TestCase( SECTION, "Date.getMonth()",            LocalDate.month,      DateCase.getMonth() );
        array[item++] = new TestCase( SECTION, "Date.getDate()",             LocalDate.date,       DateCase.getDate() );
        array[item++] = new TestCase( SECTION, "Date.getDay()",              LocalDate.day,        DateCase.getDay() );
        array[item++] = new TestCase( SECTION, "Date.getHours()",            LocalDate.hours,      DateCase.getHours() );
        array[item++] = new TestCase( SECTION, "Date.getMinutes()",          LocalDate.minutes,    DateCase.getMinutes() );
        array[item++] = new TestCase( SECTION, "Date.getSeconds()",          LocalDate.seconds,    DateCase.getSeconds() );
        array[item++] = new TestCase( SECTION, "Date.getMilliseconds()",     LocalDate.ms,         DateCase.getMilliseconds() );
    
        if (!as3Enabled) {
            array[item++] = new TestCase( SECTION,
                                              "Date.toString=Object.prototype.toString;"+DateString+".toString()",
                                              "[object Date]",
                                              (DateCase.myToString = Object.prototype.toString, DateCase.myToString()) );
        
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


function SetUTCDate( t, date ) {
    var T       = t;
    var DATE    = Number( date );
    var RESULT3 = MakeDay(YearFromTime(T), MonthFromTime(T), DATE );
    return ( TimeClip(MakeDate(RESULT3, TimeWithinDay(t))) );
}

