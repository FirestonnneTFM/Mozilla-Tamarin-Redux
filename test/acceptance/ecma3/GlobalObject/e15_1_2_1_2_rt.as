/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.1.2.1-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "eval(x)";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    d = new Date(0);
    with (d)
    {
    x = getUTCMonth() +'/'+ getUTCDate() +'/'+ getUTCFullYear();
    }
    array[0] = new TestCase( SECTION,
                             "d = new Date(0); with (d) { x = getUTCMonth() +'/'+ getUTCDate() +'/'+ getUTCFullYear(); } x",
                             "0/1/1970", x );
    return ( array );
}
