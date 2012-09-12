/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.9.5.23-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Date.prototype.setTime()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var TZ_ADJUST = TZ_DIFF * msPerHour;

    // get the current time
    var now = (new Date()).valueOf();

    test_times = new Array( now, TIME_1970, TIME_1900, TIME_2000 );


    for ( var j = 0; j < test_times.length; j++ ) {
        addTestCase( new Date(now), test_times[j] );
    }


    array[item++] = new TestCase( SECTION,
                                    "(new Date(NaN)).setTime()",
                                    NaN,
                                    (new Date(NaN)).setTime() );

    array[item++] = new TestCase( SECTION,
                                    "Date.prototype.setTime.length",
                                    1,
                                    Date.prototype.setTime.length );
                                    
        
    function addTestCase( d, t ) {
        array[item++] = new TestCase( SECTION,
                                        "(  ).setTime()",
                                        true, t ==
                                        d.setTime(t) );
    
        array[item++] = new TestCase( SECTION,
                                        "( ).setTime()",
                                        true, TimeClip(t+1.1) ==
                                        d.setTime(t+1.1) );
    
        array[item++] = new TestCase( SECTION,
                                        "().setTime()",
                                        true, t+1 ==
                                        d.setTime(t+1) );
    
        array[item++] = new TestCase( SECTION,
                                        "().setTime()",
                                        true, t-1 ==
                                        d.setTime(t-1) );
    
        array[item++] = new TestCase( SECTION,
                                        "( ).setTime()",
                                        true, t-TZ_ADJUST ==
                                        d.setTime(t-TZ_ADJUST) );
    
        array[item++] = new TestCase( SECTION,
                                        "( ).setTime()",
                                        true, t+TZ_ADJUST ==
                                        d.setTime(t+TZ_ADJUST) );
    }
    return array;
}
