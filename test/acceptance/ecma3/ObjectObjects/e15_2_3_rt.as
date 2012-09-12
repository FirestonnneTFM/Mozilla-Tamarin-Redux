/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.2.3";
    var VERSION = "ECMA_4";
    startTest();
    var TITLE   = "Properties of the Object Constructor";

    writeHeaderToLog( SECTION + " " + TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "Object.constructor.prototype",     Object.prototype+"",     Object.constructor.prototype+"");
    array[item++] = new TestCase( SECTION,  "Object.length",        1,                      Object.length );

    return ( array );
}
