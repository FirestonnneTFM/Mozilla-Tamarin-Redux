/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.8-1";
    var VERSION = "ECMA_2";
    startTest();
    var TITLE   = "The Math Object";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    array[item++] = new TestCase( SECTION,
                                  "Math.constructor.prototype == Class.prototype",
                                  true,
                                  Math.constructor.prototype == Class.prototype );

    array[item++] = new TestCase( SECTION,
                                  "Object.constructor.prototype",
                                  Object.prototype+"",
                                  Object.constructor.prototype+"");

    return ( array );
}
