/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "7.5-6";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Identifiers";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
     var _0abc = 5;
    array[item++] = new TestCase( SECTION,    "var _0abc = 5",   5,    _0abc );
    return ( array );
}

