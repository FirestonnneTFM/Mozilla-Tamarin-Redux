/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.3.3.1-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Function.prototype";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    str='';
    for (prop in Function)
        str += prop;
    array[item++] = new TestCase(   SECTION,
                                    "var str='';for (prop in Function ) str += prop; str;",
                                    "",
                                    str
                                );
    return ( array );
}
