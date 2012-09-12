/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.5.5.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Using + operator to concatenate a string and a value";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
   
   

    array[item++] = new TestCase(   SECTION,
                                    "'string'+0x4455",
                                    "string17493",
                                    "string"+0x4455 );
    
                                    
   
    return array;

}
