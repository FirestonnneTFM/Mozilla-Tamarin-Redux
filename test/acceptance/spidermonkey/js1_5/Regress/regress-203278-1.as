/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();

var gTestfile = 'regress-203278-1.js';
//-----------------------------------------------------------------------------
var BUGNUMBER = 203278;
var summary = 'Don\'t crash in recursive js_MarkGCThing';
var actual = 'FAIL';
var expect = 'PASS';

printBugNumber(BUGNUMBER);
printStatus (summary);

function test1() {}
function addtestcases() { test1.call(this); }
test.prototype = new test1();

var length = 1024 * 1024 - 1;
var obj = new addtestcases();
var first = obj;
for(var i = 0 ; i < length ; i++) {
  obj.next = new addtestcases();
  obj = obj.next;
}

actual = 'PASS';

AddTestCase(summary, expect, actual);


test();
