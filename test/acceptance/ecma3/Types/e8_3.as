/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "8.3";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The Boolean type";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;
        
    var x:Boolean;
    array[item++] = new TestCase( SECTION,
                                    "var x:Boolean; typeof x",
                                    "boolean",
                                     typeof x);
    var x:Boolean;
    array[item++] = new TestCase( SECTION,
                                    "var x:Boolean; typeof x == 'boolean'",
                                    true,
                                    typeof x == 'boolean');
    var x:Boolean;
    array[item++] = new TestCase( SECTION,
                                    "var x:Boolean; x == false",
                                    true,
                                    x == false);

       

    var x:Boolean;
    array[item++] = new TestCase( SECTION,
                                    "var x:Boolean; !x == true",
                                    true,
                                    !x == true);
    return array;
}
