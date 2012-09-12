/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.7.4.5";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Number.toFixed";

    writeHeaderToLog( SECTION + " "+TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase(   SECTION,
                                    "Number.prototype.toFixed.length",
                                    1,
                                    Number.prototype.toFixed.length );

    var profits = 2489.8237

    array[item++] = new TestCase(   SECTION,
                                    "Number.toFixed -- rounding up",
                                    "2489.824",
                                    profits.toFixed(3)+"" );

    array[item++] = new TestCase(   SECTION,
                                    "Number.toFixed",
                                    "2489.82",
                                    profits.toFixed(2)+"" );

    array[item++] = new TestCase(   SECTION,
                                    "Number.toFixed -- padding",
                                    "2489.8237000",
                                    profits.toFixed(7)+"" );

    array[item++] = new TestCase(   SECTION,
                                    "Number.toFixed -- padding",
                                    "2489.8237000",
                                    profits.toFixed(7)+"" );

    array[item++] = new TestCase(   SECTION,
                                    "Number.toFixed(undefined)",
                                    "2490",
                                    profits.toFixed()+"" );

    array[item++] = new TestCase(   SECTION,
                                    "Number.toFixed(0)",
                                    "2490",
                                    profits.toFixed(0)+"" );
    array[item++] = new TestCase(   SECTION,
                                    "Number.toFixed(null)",
                                    "2490",
                                    profits.toFixed(null)+"" );

    
    var thisError:String="no error"

    try{
        profits.toFixed(-1);
    }catch(e:RangeError){
        thisError=e.toString();
    }finally{
        array[item++] = new TestCase(   SECTION,
                                    "Number.toFixed(0)",
                                    "RangeError: Error #1002",
                                    rangeError(thisError));
    }

    try{
        profits.toFixed(21);
    }catch(e:RangeError){
        thisError=e.toString();
    }finally{
        array[item++] = new TestCase(   SECTION,
                                    "Number.toFixed(21)",
                                    "RangeError: Error #1002",
                                    rangeError(thisError));
    }

    

    var MYNUM=1000000000000000128

    array[item++] = new TestCase(   SECTION,
                                    "Number.toFixed(0)",
                                    "1000000000000000100",
                                    MYNUM.toFixed(0)+"" );

    var MYNUM2 = 4;

    array[item++] = new TestCase(   SECTION,
                                    "Number.toFixed(2)",
                                    "4.00",
                                    MYNUM2.toFixed(2)+"" );

    
    return ( array );
}
