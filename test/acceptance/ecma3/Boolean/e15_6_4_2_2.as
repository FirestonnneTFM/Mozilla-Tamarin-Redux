/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.6.4.2-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Boolean.prototype.toString()"
    writeHeaderToLog( SECTION + TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    tostr=Boolean.prototype.toString;
    Boolean.prototype.toString=tostr;
    x=new Boolean();
    array[item++] = new TestCase(   SECTION,
                                    "tostr=Boolean.prototype.toString; Boolean.prototype.toString=tostr;x=new Boolean();x.toString()",
                                    "false",
                                    x.toString());

    tostr=Boolean.prototype.toString;
    Boolean.prototype.toString=tostr;
    x=new Boolean(true);
    array[item++] = new TestCase(   SECTION,
                                    "tostr=Boolean.prototype.toString; Boolean.prototype.toString=tostr;x=new Boolean(true);x.toString()",
                                    "true",
                                    x.toString());

    tostr = Boolean.prototype.toString;
    Boolean.prototype.toString=tostr;
    x=new Boolean(false);
    array[item++] = new TestCase( SECTION,
                                    "tostr=Boolean.prototype.toString; Boolean.prototype.toString=tostr;x=new Boolean(false);x.toString()",
                                    "false",
                                    x.toString());
    return (array);

}
