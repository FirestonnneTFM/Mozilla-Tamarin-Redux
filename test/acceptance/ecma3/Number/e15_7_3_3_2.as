/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var SECTION = "15.7.3.3-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Number.MIN_VALUE";

    writeHeaderToLog( SECTION + " "+ TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var MIN_VAL = 5e-324;

    array[item++] = new TestCase(  SECTION, "delete( Number.MIN_VALUE )",                       false,      delete( Number.MIN_VALUE) );
    delete( Number.MIN_VALUE );
    array[item++] = new TestCase(  SECTION, "delete( Number.MIN_VALUE ); Number.MIN_VALUE",     MIN_VAL,    Number.MIN_VALUE );
    return ( array );
}
