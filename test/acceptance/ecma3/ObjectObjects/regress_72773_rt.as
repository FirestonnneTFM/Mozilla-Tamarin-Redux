/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
 * Date: 09 May 2001
 *
 * SUMMARY: Regression test: we shouldn't crash on this code
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=72773
 *
 * See ECMA-262 Edition 3 13-Oct-1999, Section 8.6.2 re [[Class]] property.
 *
 * Same as class-001.js - but testing user-defined types here, not native types.
 * Therefore we expect the [[Class]] property to equal 'Object' in each case -
 *
 * The getJSClass() function we use is in a utility file, e.g. "shell.js"
 */
//-------------------------------------------------------------------------------------------------
var SECTION = "regress_72773_rt";
var VERSION = "";
var TITLE   = "Regression test: we shouldn't crash on this code";
var bug = "72773";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var status = '';
    var actual = '';
    var expect = '';
    var sToEval = '';

    /*
     * This code should produce an error, but not a crash.
     *  'TypeError: Function.prototype.toString called on incompatible object'
     */
    sToEval += 'function Cow(name){this.name = name;}'
    sToEval += 'function Calf(str){this.name = str;}'
    sToEval += 'Calf.prototype = Cow;'
    sToEval += 'new Calf().toString();'

    status = 'Trying to catch an expected error';
    try
    {
      eval(sToEval);
    }
    catch(e)
    {
      actual = getJSClass(e);
      expect = 'ReferenceError';
    }

    array[item++] = new TestCase(SECTION, status, expect, actual);

    return array;
}
