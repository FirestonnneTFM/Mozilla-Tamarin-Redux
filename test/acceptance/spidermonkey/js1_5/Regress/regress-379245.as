/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();

var gTestfile = 'regress-379245.js';
//-----------------------------------------------------------------------------
var BUGNUMBER = 379245;
var summary = 'inline calls';
var actual = 'No Crash';
var expect = 'No Crash';


//-----------------------------------------------------------------------------
addtestcases();
//-----------------------------------------------------------------------------

function addtestcases()
{

  printBugNumber(BUGNUMBER);
  printStatus (summary);
 
  var fThis;

  function f()
  {
    fThis = this;
    return ({x: f}).x;
  }

  f()();

  if (this !== fThis)
    throw "bad this";

  AddTestCase(summary, expect, actual);


}

test();
