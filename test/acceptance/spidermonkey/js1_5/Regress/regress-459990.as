/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();

var gTestfile = 'regress-459990.js';
//-----------------------------------------------------------------------------
var BUGNUMBER = 459990;
var summary = 'Do not crash with if (true && a && b) { }';
var actual = '';
var expect = '';


//-----------------------------------------------------------------------------
addtestcases();
//-----------------------------------------------------------------------------

function addtestcases()
{

  printBugNumber(BUGNUMBER);
  printStatus (summary);

  try
  {
    if (true && a && b) { }
  }
  catch(ex)
  {
  }
  AddTestCase(summary, expect, actual);


}

test();
