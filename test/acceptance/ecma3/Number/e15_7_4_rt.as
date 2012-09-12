/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.7.4";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Properties of the Number Prototype Object";

    writeHeaderToLog( SECTION + " "+TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var origToString:Function = Number.prototype.toString;
    
    Number.prototype.toString=Object.prototype.toString;
    array[item++] = new TestCase( SECTION,
                                  "Number.prototype.toString=Object.prototype.toString;Number.prototype.toString()",
                                  "[object Object]",
                                  Number.prototype.toString() );
    array[item++] = new TestCase( SECTION, "typeof Number.prototype",                           "object",    typeof Number.prototype );
    array[item++] = new TestCase( SECTION, "Number.prototype.valueOf()",                        0,          Number.prototype.valueOf() );

    //restore original prototype
    Number.prototype.toString = origToString;
    
    return ( array );
}
