/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


var SECTION = "15.9.5.4-2-n";
var VERSION = "ECMA_1";
var TITLE   = "Date.prototype.getTime";


startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    var MYDATE = new MyDate(TIME_2000);
    
    if (as3Enabled) {
        array[item++] = new TestCase(SECTION, "MYDATE.getTime()",
                                         NaN,
                                         MYDATE.getTime());
    } else {
        
        thisError = "no error thrown";
        try {
            MYDATE.getTime();
        }
        catch(e) {
            thisError = e.toString();
        }
        finally {
            array[item++] = new TestCase(SECTION, "MYDATE.getTime()",
                                         "TypeError: Error #1034",
                                         typeError(thisError));
        }
    }
    return array;
}
function MyDate( value ) {
    this.value = value;
    this.getTime = Date.prototype.getTime;
}
