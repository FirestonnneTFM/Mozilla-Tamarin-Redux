/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var SECTION = "15.7.4-1";
    var VERSION = "ECMA_1";
    startTest();
    writeHeaderToLog( SECTION + "Properties of the Number prototype object");

    var testcases = getTestCases();

    test();


function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase(SECTION, "Number.prototype.valueOf()",      0,                  Number.prototype.valueOf() );
    array[item++] = new TestCase(SECTION, "typeof(Number.prototype)",        "object",           typeof(Number.prototype) );
    array[item++] = new TestCase(SECTION, "Number.prototype.constructor == Number",    true,     Number.prototype.constructor == Number );
//    array[item++] = new TestCase(SECTION, "Number.prototype == Number.__proto__",      true,   Number.prototype == Number.__proto__ );
    return ( array );
}
