/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "regress_636535";
    var VERSION = "AS3";
    var TITLE   = "Array.splice should not crash";
    var bug     = "636535";

    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);
    var testcases = getTestCases();
    test();

function getTestCases()
{
    var item = 0;
    var array = [];
    
    var a = [4]
    array[item++] = new TestCase(SECTION, "a[0] == 4", 4, a[0]);
    array[item++] = new TestCase(SECTION, "a.length == 1", 1, a.length);
    delete a[0];
    array[item++] = new TestCase(SECTION, "a[0] == undefined", undefined, a[0]);
    array[item++] = new TestCase(SECTION, "a.length == 1", 1, a.length);
    a.splice(0, 1);
    array[item++] = new TestCase(SECTION, "a[0] == undefined", undefined, a[0]);
    array[item++] = new TestCase(SECTION, "a.length == 0", 0, a.length);

    return ( array );
}
