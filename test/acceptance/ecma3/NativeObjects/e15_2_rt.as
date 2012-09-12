/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Native ECMAScript Objects";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION, "Object.constructor.prototype",   Object.prototype+"",   Object.constructor.prototype+"" );
    array[item++] = new TestCase( SECTION, "Array.constructor.prototype",    Object.prototype+"",   Array.constructor.prototype+"");
    array[item++] = new TestCase( SECTION, "String.constructor.prototype",   Object.prototype+"",   String.constructor.prototype+"");
    array[item++] = new TestCase( SECTION, "Boolean.constructor.prototype", Object.prototype+"",   Boolean.constructor.prototype+"");
    array[item++] = new TestCase( SECTION,  "Number.constructor.prototype", Object.prototype+"",   Number.constructor.prototype+"");
    array[item++] = new TestCase( SECTION,  "Date.constructor.prototype",   Object.prototype+"",   Date.constructor.prototype+"");
    array[item++] = new TestCase( SECTION, "getTestCases.constructor.prototype", Function.prototype+"", getTestCases.constructor.prototype+"");
    array[item++] = new TestCase( SECTION, "Math.pow.constructor.prototype", Function.prototype+"", Math.pow.constructor.prototype+"");
    array[item++] = new TestCase( SECTION, "String.prototype.indexOf.constructor.prototype", Function.prototype+"",   String.prototype.indexOf.constructor.prototype+"");

    return ( array );
}
