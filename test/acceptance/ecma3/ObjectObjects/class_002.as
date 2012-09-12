/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
 * Date: 14 Mar 2001
 *
 * SUMMARY: Testing the [[Class]] property of native constructors.
 * See ECMA-262 Edition 3 13-Oct-1999, Section 8.6.2 re [[Class]] property.
 *
 * Same as class-001.js - but testing the constructors here, not object instances.
 * Therefore we expect the [[Class]] property to equal 'Function' in each case.
 *
 * The getJSClass() function we use is in a utility file, e.g. "shell.js"
 */
//-------------------------------------------------------------------------------------------------
var SECTION = "class_002";
var VERSION = "";
var TITLE   = "Testing the internal [[Class]] property of native constructors";
var bug = "(none)";

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

    /*
     * We set the expect variable each time only for readability.
     * We expect 'Function' every time; see discussion above -
     */
    status = 'Object';
    actual = getJSClass(Object);
    expect = 'Object';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'Function';
    actual = getJSClass(Function);
    expect = 'Function';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'Array';
    actual = getJSClass(Array);
    expect = 'Array';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'String';
    actual = getJSClass(String);
    expect = 'String';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'Boolean';
    actual = getJSClass(Boolean);
    expect = 'Boolean';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'Number';
    actual = getJSClass(Number);
    expect = 'Number';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'Date';
    actual = getJSClass(Date);
    expect = 'Date';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'RegExp';
    actual = getJSClass(RegExp);
    expect = 'RegExp';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'Error';
    actual = getJSClass(Error);
    expect = 'Error';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    return array;
}
