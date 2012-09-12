/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.4.4";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Properties of the Array Prototype Object";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "Array.prototype.length",   0,          Array.prototype.length );
    array[item++] = new TestCase( SECTION,  "Array.length",   1,          Array.length );
//  verify that prototype object is an Array object.
    array[item++] = new TestCase( SECTION,  "typeof Array.prototype",    "object",   typeof Array.prototype );

    var tempToString = Array.prototype.toString;
    array[item++] = new TestCase( SECTION,
                                    "Array.prototype.toString = Object.prototype.toString; Array.prototype.toString()",
                                    "[object Array]",
                                    (Array.prototype.toString = Object.prototype.toString, Array.prototype.toString()) );
    
    // revert Array.prototype.toString back to original for ATS tests
    Array.prototype.toString = tempToString;
    
    return ( array );
}
