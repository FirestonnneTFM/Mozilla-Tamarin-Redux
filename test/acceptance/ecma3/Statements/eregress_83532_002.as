/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
 * Date: 01 June 2001
 *
 * SUMMARY: Testing that we don't crash on switch case -1...
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=83532
 *
 */
//-------------------------------------------------------------------------------------------------
var bug = 83532;
var summary = "Testing that we don't crash on switch case -1";
var sToEval = '';

startTest();

var testcases = getTestCases();

//-------------------------------------------------------------------------------------------------
test();
//-------------------------------------------------------------------------------------------------

function getTestCases()
{
    var array = new Array();
    var item = 0;
    
    doTest();
    
    array[item++] = new TestCase("", "Make sure we don't crash", true, true);
    
    return array;
}

function doTest()
{
  printBugNumber (bug);
  printStatus (summary);

  // Just testing that we don't crash on these -
  sToEval += 'function f () {switch(1) {case -1:}};';
  sToEval += 'function g(){switch(1){case (-1):}};';
  sToEval += 'var h = function() {switch(1) {case -1:}};'
  sToEval += 'f();';
  sToEval += 'g();';
  sToEval += 'h();';
}
