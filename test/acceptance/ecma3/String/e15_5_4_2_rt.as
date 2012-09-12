/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.5.4.2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "String.prototype.tostring";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

   /* array[item++] = new TestCase( SECTION, "String.prototype.toString.__proto__",  Function.prototype, String.prototype.toString.__proto__ );*/
    array[item++] = new TestCase(   SECTION,
                                    "String.prototype.toString() == String.prototype.valueOf()",
                                    true,
                                    String.prototype.toString() == String.prototype.valueOf() );

    array[item++] = new TestCase(   SECTION, "String.prototype.toString()",     "",     String.prototype.toString() );
    array[item++] = new TestCase(   SECTION, "String.prototype.toString.length",    0,  String.prototype.toString.length );


    array[item++] = new TestCase(   SECTION,
                                    "TESTSTRING = new String(),TESTSTRING.valueOf() == TESTSTRING.toString()",
                                    true,
                                    (TESTSTRING = new String(),TESTSTRING.valueOf() == TESTSTRING.toString()) );
    array[item++] = new TestCase(   SECTION,
                                    "TESTSTRING = new String(true),TESTSTRING.valueOf() == TESTSTRING.toString()",
                                    true,
                                    (TESTSTRING = new String(true),TESTSTRING.valueOf() == TESTSTRING.toString()) );
    array[item++] = new TestCase(   SECTION,
                                    "TESTSTRING = new String(false),TESTSTRING.valueOf() == TESTSTRING.toString()",
                                    true,
                                    (TESTSTRING = new String(false),TESTSTRING.valueOf() == TESTSTRING.toString()) );
    array[item++] = new TestCase(   SECTION,
                                    "TESTSTRING = new String(Math.PI),TESTSTRING.valueOf() == TESTSTRING.toString()",
                                    true,
                                    (TESTSTRING = new String(Math.PI),TESTSTRING.valueOf() == TESTSTRING.toString()) );
    array[item++] = new TestCase(   SECTION,
                                    "TESTSTRING = new String(),TESTSTRING.valueOf() == TESTSTRING.toString()",
                                    true,
                                    (TESTSTRING = new String(),TESTSTRING.valueOf() == TESTSTRING.toString()) );

    return ( array );
}
