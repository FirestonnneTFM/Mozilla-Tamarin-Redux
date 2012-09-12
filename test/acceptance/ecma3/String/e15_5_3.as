/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.5.3";
    var VERSION = "ECMA_2";
    startTest();
    var passed = true;
    writeHeaderToLog( SECTION + " Properties of the String Constructor" );

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "String.prototype",             Object.constructor.prototype,     String.constructor.prototype);
    array[item++] = new TestCase( SECTION,  "String.length",                1,                      String.length );
    return ( array );
}
