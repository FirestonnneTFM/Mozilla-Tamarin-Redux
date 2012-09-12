/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.2.1.2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Object()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var MYOB = Object();

           array[item++] = new TestCase( SECTION, "var MYOB = Object(); MYOB.valueOf()", MYOB,MYOB.valueOf());



    array[item++] = new TestCase( SECTION, "typeof Object()",       "object",               typeof (Object(null)) );


           array[item++] = new TestCase( SECTION, "var MYOB = Object();  MYOB.toString()", "[object Object]",MYOB.toString());



    return ( array );
}
