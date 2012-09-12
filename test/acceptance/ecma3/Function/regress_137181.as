/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*
* Date:    12 Apr 2002
* SUMMARY: delete arguments[i] should break connection to local reference
*
* See http://bugzilla.mozilla.org/show_bug.cgi?id=137181
*
*/
//-----------------------------------------------------------------------------
    var SECTION = "regress_137181";
    var VERSION = "";
    startTest();

    var TITLE   = "delete arguments[i] should break connection to local reference";
    var bug = 137181;

    writeHeaderToLog( SECTION + " " + TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    var UBound = 0;
    var status = '';
    var statusitems = [];
    var actual = '';
    var actualvalues = [];
    var expect= '';
    var expectedvalues = [];


    status = inSection(1);
    function f1(x)
    {
      x = 1;
      delete arguments[0];
      return x;
    }
    actual = f1(0); // (bug: Rhino was returning |undefined|)
    expect = 1;
    //addThis();
    array[item++] = new TestCase(SECTION, status, expect, actual);
    
    
    status = inSection(2);
    function f2(x)
    {
      x = 1;
      delete arguments[0];
      arguments[0] = -1;
      return x;
    }
    actual = f2(0); // (bug: Rhino was returning -1)
    expect = 1;
    //addThis();
    array[item++] = new TestCase(SECTION, status, expect, actual);
    
    return array;
}

/*
function addThis()
{
  statusitems[UBound] = status;
  actualvalues[UBound] = actual;
  expectedvalues[UBound] = expect;
  UBound++;
}
*/

/*
function test()
{
  enterFunc('test');
  printBugNumber(bug);
  printStatus(summary);

  for (var i=0; i<UBound; i++)
  {
    reportCompare(expectedvalues[i], actualvalues[i], statusitems[i]);
  }

  exitFunc ('test');
}
*/
