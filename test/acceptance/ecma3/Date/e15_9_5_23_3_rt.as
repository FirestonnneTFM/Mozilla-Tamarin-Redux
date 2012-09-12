/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "15.9.5.23-3-n";
var VERSION = "ECMA_1";
var TITLE   = "Date.prototype.setTime()";


startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var testcases = getTestCases();
test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    
    var MYDATE = new MyDate(TIME_1970);
    
    if (as3Enabled) {
        MYDATE.setTime(TIME_2000)
        array[item++] = new TestCase(SECTION,
                                "MYDATE.setTime(TIME_2000)",
                                TIME_2000,
                                MYDATE.getTime());
    } else {
        thisError = "no error thrown";
        try {
            MYDATE.setTime(TIME_2000);
        }
        catch(e){
            thisError=e.toString();
        }
        finally {
            trace(thisError)
            array[item++] = new TestCase(SECTION,
                                "MYDATE.setTime(TIME_2000)",
                                "TypeError: Error #1034",
                                typeError(thisError));
        }
    }
    
    return array;
}

function MyDate(value) {
    this.value = value;
    this.setTime = Date.prototype.setTime;
    this.getTime = Date.prototype.getTime;
    return this;
}
