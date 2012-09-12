/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "bug129539";
var VERSION = "";
var TITLE   = "";
var bug = "129539";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var a;

    if( !a ){
        array[item++] = new TestCase(SECTION, "var a;!a", true, true);
    } else {
        array[item++] = new TestCase(SECTION, "var a;!a", false, true);
    }

    if( a == null ){
        array[item++] = new TestCase(SECTION, "var a;a == null", true, true);
    } else {
        array[item++] = new TestCase(SECTION, "var a;a == null", false, true);
    }

    if( a == undefined ){
        array[item++] = new TestCase(SECTION, "var a;a == undefined", true, true);
    } else {
        array[item++] = new TestCase(SECTION, "var a;a == undefined", false, true);
    }

    return array;
}
