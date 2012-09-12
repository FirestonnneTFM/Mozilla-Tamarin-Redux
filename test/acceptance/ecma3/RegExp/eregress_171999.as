/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*
* Date:    20 Sep 2002
* SUMMARY: RegExp conformance test
* See http://bugzilla.mozilla.org/show_bug.cgi?id=169534
*
*/
//-----------------------------------------------------------------------------

var SECTION = "eregress_171999";
var VERSION = "";
var TITLE   = "RegExp conformance test";
var bug = "171999";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var status = '';
    var actual = '';
    var expect= '';

    status = inSection(1);
    actual = /abc/.test(undefined);
    expect = false;
    array[item++] = new TestCase(SECTION, status, expect, actual);

    return array;
}
