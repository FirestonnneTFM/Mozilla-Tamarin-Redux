/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.5.4.14";
    var VERSION = "";
    startTest();
    var TITLE   = "String.prototype.split https://bugzilla.mozilla.org/show_bug.cgi?id=504567";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase(   SECTION,
                                    "'ab'.split(/a*/)",
                                    ",b",
                                    'ab'.split(/a*/).toString() );
    
    array[item++] = new TestCase(   SECTION,
                                    "'abab'.split(/a*/)",
                                    ",b,b",
                                    'abab'.split(/a*/).toString() );
    
    array[item++] = new TestCase(   SECTION,
                                    "'babab'.split(/a*/)",
                                    "b,b,b",
                                    'babab'.split(/a*/).toString() );
   
    return array;

}
