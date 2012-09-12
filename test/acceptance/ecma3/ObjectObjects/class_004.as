/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
 * Date: 14 Mar 2001
 *
 * SUMMARY: Testing [[Class]] property of native error constructors.
 * See ECMA-262 Edition 3, Section 8.6.2 for the [[Class]] property.
 *
 * See ECMA-262 Edition 3, Section 15.11.6 for the native error types.
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=56868
 *
 * Same as class-003.js - but testing the constructors here, not object instances.
 * Therefore we expect the [[Class]] property to equal 'Function' in each case.
 *
 * The getJSClass() function we use is in a utility file, e.g. "shell.js"
 */
//-------------------------------------------------------------------------------------------------
var SECTION = "class_004";
var VERSION = "";
var TITLE   = "Testing the internal [[Class]] property of native error constructors";
var bug = "56868";

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
    status = 'Error';
    actual = getJSClass(Error);
    expect = 'Error';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'EvalError';
    actual = getJSClass(EvalError);
    expect = 'EvalError';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'RangeError';
    actual = getJSClass(RangeError);
    expect = 'RangeError';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'ReferenceError';
    actual = getJSClass(ReferenceError);
    expect = 'ReferenceError';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'SyntaxError';
    actual = getJSClass(SyntaxError);
    expect = 'SyntaxError';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'TypeError';
    actual = getJSClass(TypeError);
    expect = 'TypeError';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'URIError';
    actual = getJSClass(TypeError);
    expect = 'TypeError';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    return array;
}
