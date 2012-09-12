/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var SECTION = "15.6.3";
var VERSION = "ECMA_2";
startTest();
var TITLE   = "Properties of the Boolean Constructor"
writeHeaderToLog( SECTION + TITLE );

var testcases = getTestCases();

// All tests must call a function that returns an array of TestCase objects.
test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    // The Boolean is a Class in AS 3.0.
    // Change when bug 149667 is fixed; should be true:
    array[item++] = new TestCase( SECTION, "Boolean.constructor.prototype == Class.prototype", true, Boolean.constructor.prototype == Class.prototype );
    array[item++] = new TestCase( SECTION, "Boolean.length", 1, Boolean.length );

    return ( array );

}
