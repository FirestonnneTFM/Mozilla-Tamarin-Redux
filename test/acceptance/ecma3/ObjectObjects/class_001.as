/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
 * Date: 14 Mar 2001
 *
 * SUMMARY: Testing the internal [[Class]] property of objects
 * See ECMA-262 Edition 3 13-Oct-1999, Section 8.6.2
 *
 * The getJSClass() function we use is in a utility file, e.g. "shell.js".
 *
 *    Modified:     28th October 2004 (gasingh@macromedia.com)
 *              Removed the occurence of new Function('abc').
 *              This is being changed to function() { abc }.
 *
 */
//-------------------------------------------------------------------------------------------------
var SECTION = "class_001";
var VERSION = "";
var TITLE   = "Testing the internal [[Class]] property of objects";
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
        var k = new Function();
        
        
    status = 'the global object';
    actual = getJSClass(this);
    expect = 'global';
    array[item++] = new TestCase(SECTION, status, expect, actual);
    status = 'new Object()';
    actual = getJSClass(new Object());
    expect = 'Object';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    // new Function() will be dropped in ecma4, will return undefined
    // new Function() has been replaced by function() {}
    /*status = 'new Function()';
    actual = getJSClass(k)+"";
    expect = 'Function';
    array[item++] = new TestCase(SECTION, status, expect, actual);*/

    status = 'new Array()';
    actual = getJSClass(new Array());
    expect = 'Array';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'new String()';
    actual = getJSClass(new String());
    expect = 'String';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'new Boolean()';
    actual = getJSClass(new Boolean());
    expect = 'Boolean';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'new Number()';
    actual = getJSClass(new Number());
    expect = 'Number';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'Math';
    actual = getJSClass(Math);  // can't use 'new' with the Math object (EMCA3, 15.8)
    expect = 'Math';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'new Date()';
    actual = getJSClass(new Date());
    expect = 'Date';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'new RegExp()';
    actual = getJSClass(new RegExp());
    expect = 'RegExp';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    status = 'new Error()';
    actual = getJSClass(new Error());
    expect = 'Error';
    array[item++] = new TestCase(SECTION, status, expect, actual);

    return array;
}
