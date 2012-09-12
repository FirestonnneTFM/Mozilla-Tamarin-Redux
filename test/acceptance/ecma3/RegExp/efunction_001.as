/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "RegExp/function-001";
    var VERSION = "ECMA_2";
    var TITLE   = "RegExp( pattern, flags )";

    startTest();
    writeHeaderToLog(SECTION + " " + TITLE);
    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    /*
     * for each test case, verify:
     * - verify that [[Class]] property is RegExp
     * - prototype property should be set to RegExp.prototype
     * - source is set to the empty string
     * - global property is set to false
     * - ignoreCase property is set to false
     * - multiline property is set to false
     * - lastIndex property is set to 0
     */

    RegExp.prototype.getClassProperty = Object.prototype.toString;
    var re = new RegExp();

    /*array[item++] = new TestCase(SECTION,
        "new RegExp().constructor.prototype",
        RegExp.prototype,
        re.constructor.prototype
    );*/

    array[item++] = new TestCase(SECTION,
        "RegExp.prototype.getClassProperty = Object.prototype.toString; " +
        "(new RegExp()).getClassProperty()",
        "[object RegExp]",
        re.getClassProperty() );

    array[item++] = new TestCase(SECTION,
        "(new RegExp()).source",
        "",
        re.source );

    array[item++] = new TestCase(SECTION,
        "(new RegExp()).global",
        false,
        re.global );

    array[item++] = new TestCase(SECTION,
        "(new RegExp()).ignoreCase",
        false,
        re.ignoreCase );

    array[item++] = new TestCase(SECTION,
        "(new RegExp()).multiline",
        false,
        re.multiline );

    array[item++] = new TestCase(SECTION,
        "(new RegExp()).lastIndex",
        0,
        re.lastIndex );
        
    //restore
    delete RegExp.prototype.getClassProperty;
    
    return array;
}
