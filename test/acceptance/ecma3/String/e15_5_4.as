/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.5.4";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Properties of the String Prototype object";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION, "typeof String.prototype",   "object",   typeof String.prototype );
    array[item++] = new TestCase( SECTION, "String.prototype.valueOf()",
                                            "",
                                            (String.prototype.valueOf()).toString() );
    var origStringGetClass = String.prototype.getClass;
    array[item++] = new TestCase( SECTION,
                                  "String.prototype.getClass = Object.prototype.toString; String.prototype.getClass()",
                                  "[object Object]",
                                  (String.prototype.getClass = Object.prototype.toString, String.prototype.getClass()) );
    array[item++] = new TestCase( SECTION, "String.prototype +''",       "",        String.prototype + '' );
    array[item++] = new TestCase( SECTION, "String.prototype.length",    undefined,         String.prototype.length );
    array[item++] = new TestCase( SECTION, "String.length",    1,         String.length );

    //restore
    String.prototype.getClass = origStringGetClass;
    return ( array );
}

