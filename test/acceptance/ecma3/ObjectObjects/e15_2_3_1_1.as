/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.2.3.1-1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Object.prototype";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    str = ''; for ( p in Object ) { str += p; }

    array[item++] = new TestCase( SECTION,  "var str = '';for ( p in Object ) { str += p; }; str",
                                            "",
                                            str
                                );
    return ( array );
}
