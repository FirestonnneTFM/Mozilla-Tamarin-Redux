/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.9.5.4-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Date.prototype.getTime";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var TZ_ADJUST = TZ_DIFF * msPerHour;
    var now = (new Date()).valueOf();
    var UTC_29_FEB_2000 = TIME_2000 + 31*msPerDay + 28*msPerDay;
    var UTC_1_JAN_2005 = TIME_2000 + TimeInYear(2000) + TimeInYear(2001)+
    TimeInYear(2002)+TimeInYear(2003)+TimeInYear(2004);

    addTestCase2( now );
    addTestCase( TIME_1970 );
    addTestCase( TIME_1900 );
    addTestCase( TIME_2000 );
    addTestCase( UTC_29_FEB_2000 );
    addTestCase( UTC_1_JAN_2005 );

    
    function addTestCase( t ) {
        array[item++] = new TestCase( SECTION,
                                        "(new Date(+t+).valueOf()",
                                        true, t ==
                                        (new Date(t)).valueOf() );
    
        array[item++] = new TestCase( SECTION,
                                        "(new Date(+(t+1)+).valueOf()",
                                        true, t+1 ==
                                        (new Date(t+1)).valueOf() );
    
        array[item++] = new TestCase( SECTION,
                                        "(new Date(+(t-1)+).valueOf()",
                                        true,t-1 ==
                                        (new Date(t-1)).valueOf() );
    
        array[item++] = new TestCase( SECTION,
                                        "(new Date(+(t-TZ_ADJUST)+).valueOf()",
                                        true, t-TZ_ADJUST ==
                                        (new Date(t-TZ_ADJUST)).valueOf() );
    
        array[item++] = new TestCase( SECTION,
                                        "(new Date(+(t+TZ_ADJUST)+).valueOf()",
                                        true, t+TZ_ADJUST ==
                                        (new Date(t+TZ_ADJUST)).valueOf() );
    }
    
    
    // only used for current date and time
    function addTestCase2( t ) {
        array[item++] = new TestCase( SECTION,
                                        "(new Date(now).valueOf()",
                                        true, t ==
                                        (new Date(t)).valueOf() );
    
        array[item++] = new TestCase( SECTION,
                                        "(new Date(now+1).valueOf()",
                                        true, t+1 ==
                                        (new Date(t+1)).valueOf() );
    
        array[item++] = new TestCase( SECTION,
                                        "(new Date(now-1).valueOf()",
                                        true, t-1 ==
                                        (new Date(t-1)).valueOf() );
    
        array[item++] = new TestCase( SECTION,
                                        "(new Date(now-TZ_ADJUST).valueOf()",
                                        true, t-TZ_ADJUST==
                                        (new Date(t-TZ_ADJUST)).valueOf() );
    
        array[item++] = new TestCase( SECTION,
                                        "(new Date(now+TZ_ADJUST).valueOf()",
                                        true, t+TZ_ADJUST ==
                                        (new Date(t+TZ_ADJUST)).valueOf() );
    }
    return array;
}
