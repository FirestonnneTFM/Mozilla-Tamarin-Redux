/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "string-002";
    var VERSION = "JS1_4";
    var TITLE   = "String.prototype.valueOf";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var result = "Failed";
    var exception = "No exception thrown";
    var expect = "Passed";

    try {
        var OBJECT =new Object();
        OBJECT.valueOf = String.prototype.valueOf;
        result = OBJECT.valueOf();
    } catch ( e ) {
        result = expect;
        exception = e.toString();
    }

    array[item++] = new TestCase(
        SECTION,
        "OBJECT = new Object; OBJECT.valueOf = String.prototype.valueOf;"+
        "result = OBJECT.valueOf();" +
        " (threw " + exception +")",
        expect,
        result );

    return array;
}

