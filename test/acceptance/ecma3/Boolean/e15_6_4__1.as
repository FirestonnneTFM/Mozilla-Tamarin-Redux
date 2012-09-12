/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var VERSION = "ECMA_1"
    startTest();
    var SECTION = "15.6.4-1";

    writeHeaderToLog( SECTION + " Properties of the Boolean Prototype Object");
    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION, "typeof Boolean.prototype == typeof( new Object )",
                                            true,
                                            typeof Boolean.prototype == typeof( new Object ) );
    array[item++] = new TestCase( SECTION, "typeof( Boolean.prototype )",
                                            "object",
                                            typeof(Boolean.prototype) );

    //save original toString
    var origToString:Function = Boolean.prototype.toString;

    Boolean.prototype.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,
                                    "Boolean.prototype.toString = Object.prototype.toString; Boolean.prototype.toString()",
                                    "[object Object]",
                                    Boolean.prototype.toString());
    array[item++] = new TestCase( SECTION, "Boolean.prototype.valueOf()",
                                            false,
                                            Boolean.prototype.valueOf());

    //restore original toString
    Boolean.prototype.toString = origToString;

    return ( array );
}
