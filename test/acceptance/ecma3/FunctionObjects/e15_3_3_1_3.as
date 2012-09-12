/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.3.3.1-3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Function.prototype";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var FUN_PROTO = Function.prototype;

    array[item++] = new TestCase(   SECTION,
                                    "delete Function.prototype",
                                    false,
                                    delete Function.prototype
                                );

    delete Function.prototype;
    array[item++] = new TestCase(   SECTION,
                                    "delete Function.prototype; Function.prototype",
                                    FUN_PROTO,
                                    Function.prototype
                                );
    return ( array );
}
