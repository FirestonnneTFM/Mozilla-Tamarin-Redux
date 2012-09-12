/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.2.4.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Object.prototype.constructor";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    array[item++] = new TestCase( SECTION,  "Object.prototype.constructor",
                                            Object,
                                            Object.prototype.constructor
                                );
    return ( array );
}
