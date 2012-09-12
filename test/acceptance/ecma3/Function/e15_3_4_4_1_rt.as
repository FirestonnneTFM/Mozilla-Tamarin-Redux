/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
*
*
* Date:    21 May 2002
* SUMMARY: ECMA conformance of Function.prototype.call
*
*   Function.prototype.call(thisArg [,arg1 [,arg2, ...]])
*
* See ECMA-262 Edition 3 Final, Section 15.3.4.4
*/
//-----------------------------------------------------------------------------
    var SECTION = "e15_3_4_3_1";
    var VERSION = "";
    startTest();

    var TITLE   = "Testing ECMA conformance of Function.prototype.call";
    var bug = 145791;

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

    
    function F0(a)
    {
      return "" + this + arguments.length;
    }
    
    function F1(a)
    {
      return "" + this + a;
    }
    
    function F2()
    {
      return "" + this;
    }

    
    
    
    /*
     * Function.prototype.call.length should return 1
     */
    status = inSection(1);
    actual = Function.prototype.call.length;
    expect = 1;
    //addThis();
    array[item++] = new TestCase(SECTION, status, expect, actual);
    
    
    /*
     * When |thisArg| is not provided to the call() method, the
     * called function must be passed the global object as |this|
     */
    status = inSection(2);
    actual = F0.call();
    expect = "" + this + 0;
    //addThis();
    array[item++] = new TestCase(SECTION, status, expect, actual);
    
    
    /*
     * If [,arg1 [,arg2, ...]] are not provided to the call() method,
     * the called function should be invoked with an empty argument list
     */
    status = inSection(3);
    actual = F0.call("");
    expect = "" + "" + 0;
    //addThis();
    array[item++] = new TestCase(SECTION, status, expect, actual);
    
    status = inSection(4);
    actual = F0.call(true);
    expect = "" + true + 0;
    //addThis();
    array[item++] = new TestCase(SECTION, status, expect, actual);
    
    
    /*
     * Function.prototype.call(x) and
     * Function.prototype.call(x, undefined) should return the same result
     */
    status = inSection(5);
    actual = F1.call(0, undefined);
    expect = F1.call(0);
    //addThis();
    array[item++] = new TestCase(SECTION, status, expect, actual);
    
    status = inSection(6);
    actual = F1.call("", undefined);
    expect = F1.call("");
    //addThis();
    array[item++] = new TestCase(SECTION, status, expect, actual);
    
    status = inSection(7);
    actual = F1.call(null, undefined);
    expect = F1.call(null);
    //addThis();
    array[item++] = new TestCase(SECTION, status, expect, actual);
    
    status = inSection(8);
    actual = F1.call(undefined, undefined);
    expect = F1.call(undefined);
    //addThis();
    array[item++] = new TestCase(SECTION, status, expect, actual);
    
    
    /*
     * Function.prototype.call() and
     * Function.prototype.call(undefined) should return the same result
     */
    status = inSection(9);
    actual = F2.call(undefined);
    expect = F2.call();
    //addThis();
    array[item++] = new TestCase(SECTION, status, expect, actual);
    
    
    /*
     * Function.prototype.call() and
     * Function.prototype.call(null) should return the same result
     */
    status = inSection(10);
    actual = F2.call(null);
    expect = F2.call();
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
