/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.6.4.3-3";
    var VERSION = "ECMA_4";
    startTest();
    var TITLE   = "Boolean.prototype.valueOf()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = new Array();

    testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    valof=Boolean.prototype.valueOf;
    Boolean.prototype.valueOf=valof;
    x=true;
    array[item++] = new TestCase( SECTION,
                                "valof=Boolean.prototype.valueOf; Boolean.prototype.valueOf=valof; x=true; x.valueOf()",
                                true,
                                x.valueOf());
    x=false;
    array[item++] = new TestCase( SECTION,
                                "valof=Boolean.prototype.valueOf; Boolean.prototype.valueOf=valof; x=false; x.valueOf()",
                                false,
                                x.valueOf());
    return ( array );
}
