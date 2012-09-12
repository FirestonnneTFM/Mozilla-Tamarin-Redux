/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();

/*
 *
 * Date:    07 February 2003
 * SUMMARY: Testing 0/0 inside functions
 *
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=192288
 *
 */
//-----------------------------------------------------------------------------
var gTestfile = 'regress-192288.js';
var UBound = 0;
var BUGNUMBER = 192288;
var summary = 'Testing 0/0 inside functions ';
var status = '';
var statusitems = [];
var actual = '';
var actualvalues = [];
var expect= '';
var expectedvalues = [];


function f()
{
  return 0/0;
}

status = inSection(1);
actual = isNaN(f());
expect = true;
addThis();

status = inSection(2);
actual = isNaN(f.apply(this));
expect = true;
addThis();

status = inSection(3);
actual = isNaN(f.apply(this));
expect = true;
addThis();

status = inSection(4);
actual = isNaN(function(){return 0/0;}());
expect = true;
addThis();

status = inSection(5);
actual = isNaN(function(){return 0/0;}());
expect = true;
addThis();



//-----------------------------------------------------------------------------
addtestcases();
//-----------------------------------------------------------------------------



function addThis()
{
  statusitems[UBound] = status;
  actualvalues[UBound] = actual;
  expectedvalues[UBound] = expect;
  UBound++;
}


function addtestcases()
{

  printBugNumber(BUGNUMBER);
  printStatus(summary);

  for (var i=0; i<UBound; i++)
  {
    AddTestCase(statusitems[i], expectedvalues[i], actualvalues[i]);
  }


}

test();
