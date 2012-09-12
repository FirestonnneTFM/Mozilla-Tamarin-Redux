/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.2.2.2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "new Object()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION, "typeof new Object()",   "object",       typeof new Object() );
    array[item++] = new TestCase( SECTION, "Object.prototype.toString()",   "[object Object]",  Object.prototype.toString() );
    array[item++] = new TestCase( SECTION, "(new Object()).toString()",  "[object Object]",   (new Object()).toString() );

    return ( array );
}
