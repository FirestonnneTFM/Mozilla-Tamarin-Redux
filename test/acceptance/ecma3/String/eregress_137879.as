/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.5.5.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Parameters to string methods should be declared Number not int";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
   
    var a = "abcdefg";

    array[item++] = new TestCase(   SECTION,
                                    "charAt(Infinity)",
                                    "",
                                    a.charAt(Infinity) );
    array[item++] = new TestCase(   SECTION,
                                    "a.charAt(4294967296)",
                                    "",
                                    a.charAt(4294967296) );
    array[item++] = new TestCase(   SECTION,
                                    "a.charAt(4294967296+1) ",
                                    "",
                                    a.charAt(4294967296+1)  );
    array[item++] = new TestCase(   SECTION,
                                    "a.indexOf('2',4294967296)",
                                    -1,
                                    a.indexOf('2',4294967296) );
    array[item++] = new TestCase(   SECTION,
                                    "a.charCodeAt(4294967296)",
                                    NaN,
                                    a.charCodeAt(4294967296));
    array[item++] = new TestCase(   SECTION,
                                    "a.substring(4294967296,4294967296+2)",
                                    "",
                                    a.substring(4294967296,4294967296+2));
    array[item++] = new TestCase(   SECTION,
                                    "a.substring(NaN,Infinity)",
                                    "abcdefg",
                                    a.substring(NaN,Infinity));

   
    return array;

}
