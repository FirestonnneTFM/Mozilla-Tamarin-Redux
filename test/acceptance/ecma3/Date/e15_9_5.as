/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "15.9.5";
var VERSION = "ECMA_1";
startTest();
var TITLE   = "Properties of the Date Prototype Object";

writeHeaderToLog( SECTION + " "+ TITLE);
var testcases = getTestCases();
test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    if (as3Enabled) {
        // Date is a sealed class
        try{
            Date.prototype.valueOf=Object.prototype.toString;
        }catch(e){
            thisError=e.toString();
        }finally{
            array[item++] =new TestCase(SECTION,
                    "ReferenceError: Error #1037: Cannot assign to a method valueOf on Date.",
                    "ReferenceError: Error #1037",
                    referenceError( thisError ) );
        }
    } else {    // ES
        var origGetClass:Function = Date.prototype.getClass;
        var origValueOf:Function = Date.prototype.valueOf;
    
        Date.prototype.getClass = Object.prototype.toString;
        Date.prototype.valueOf=Object.prototype.toString;
        array[item++] = new TestCase( SECTION,
                        "Date.prototype.getClass",
                        "[object Date]",
                        Date.prototype.getClass() );
        array[item++] = new TestCase( SECTION,
                        "Date.prototype.valueOf()",
                        "[object Date]",
                        (Date.prototype.valueOf()) );
    
        // restore
        Date.prototype.getClass = origGetClass;
        Date.prototype.valueOf = origValueOf;
    }


    return ( array );
}
