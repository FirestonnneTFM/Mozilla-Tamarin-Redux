/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.7.3";
    var VERSION = "ECMA_2";
    startTest();
    var TITLE   = "Properties of the Number Constructor";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    array[item++] = new TestCase(SECTION, "Number.constructor.prototype",   Class.prototype, Number.constructor.prototype);
    array[item++] = new TestCase(SECTION, "Number.length",      1,                  Number.length );

    return ( array );
}
