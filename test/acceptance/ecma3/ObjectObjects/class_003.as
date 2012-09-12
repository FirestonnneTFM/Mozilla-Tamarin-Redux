/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
 * Date: 14 Mar 2001
 *
 * SUMMARY: Testing the [[Class]] property of native error types.
 * See ECMA-262 Edition 3, Section 8.6.2 for the [[Class]] property.
 *
 * Same as class-001.js - but testing only the native error types here.
 * See ECMA-262 Edition 3, Section 15.11.6 for a list of these types.
 *
 * ECMA expects the [[Class]] property to equal 'Error' in each case.
 * See ECMA-262 Edition 3, Sections 15.11.1.1 and 15.11.7.2 for this.
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=56868
 *
 * The getJSClass() function we use is in a utility file, e.g. "shell.js"
 */
//-------------------------------------------------------------------------------------------------
var SECTION = "class_003";
var VERSION = "";
var TITLE   = "Testing the internal [[Class]] property of native error types";
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
     * We expect 'Error' every time; see discussion above -
     */
    status = 'new Error()';
    actual = getJSClass(new Error());
    expect = 'Error';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'new EvalError()';
    actual = getJSClass(new EvalError());
    expect = 'EvalError';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'new RangeError()';
    actual = getJSClass(new RangeError());
    expect = 'RangeError';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'new ReferenceError()';
    actual = getJSClass(new ReferenceError());
    expect = 'ReferenceError';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'new SyntaxError()';
    actual = getJSClass(new SyntaxError());
    expect = 'SyntaxError';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'new TypeError()';
    actual = getJSClass(new TypeError());
    expect = 'TypeError';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'new URIError()';
    actual = getJSClass(new URIError());
    expect = 'URIError';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    return array;
}
