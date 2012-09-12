/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();

var gTestfile = 'regress-383674.js';
//-----------------------------------------------------------------------------
var BUGNUMBER = 383674;
var summary = 'Statement that implicitly calls toString should not be optimized away as a "useless expression"';
var actual = '';
var expect = '';


//-----------------------------------------------------------------------------
addtestcases();
//-----------------------------------------------------------------------------

function addtestcases()
{

  printBugNumber(BUGNUMBER);
  printStatus (summary);
    
  //options("strict");
  //options("werror");

  expect = 'toString called';
  actual = 'toString not called';
  try
  {
    var x = {toString: function() {
        actual = 'toString called';
        print(actual);
      }
    };
    var f = function() { var j = x; j + ""; }
    f();
    AddTestCase(summary + ': 1', expect, actual);
  }
  catch(ex)
  {
    AddTestCase( summary + ': 1', "No Error", ex + "");
  }

  actual = 'toString not called';
  try
  {
    (function() { const a =
         ({toString: function(){
             actual = 'toString called'; print(actual)} }); var j = a + ""; })();
    AddTestCase(summary + ': 2', expect, actual);
  }
  catch(ex)
  {
    AddTestCase(summary + ': 2', "No Error", ex + "");
  }


}

test();
