/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "number-002";
    var VERSION = "JS1_4";
    var TITLE   = "Exceptions for Number.valueOf()";

    startTest();
    writeHeaderToLog( SECTION + " Number.prototype.valueOf()");

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var result = "Failed";
    var exception = "No exception thrown";
    var expect = "Passed";

    try {
        object= new Object();
        
       object.valueOf=Number.prototype.valueOf;
        
        result = object.valueOf();
        
    } catch ( e ) {
        result = expect;
        exception = (e.toString()).substring(0,22);
    }
    
    array[item++] = new TestCase(
        SECTION,
        "object = new Object(); object.valueOf = Number.prototype.valueOf; object.valueOf()" +
        " (threw " + exception +")",
        expect,
        result );
        
    return array;
}
