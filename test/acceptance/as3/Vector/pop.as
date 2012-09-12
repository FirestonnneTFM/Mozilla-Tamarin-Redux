/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/**
   File Name:    pop.as
   Description:  pop(object)
     pop method extracts the last vector element from object and removes it by decreasing the value of the length
     of property object by 1.
   *
   */
var SECTION="";
var VERSION = "ECMA_1";

startTest();

writeHeaderToLog( " Vector.pop()");

var v1=new Vector.<int>();
AddTestCase(
        "pop empty vector",
        0,
        v1.pop());
AddTestCase(
        "pop empty vector, original vector change",
        "",
        v1.toString());

var v1=new Vector.<int>();
v1[0]=100;
AddTestCase(
                "pop single length vector element",
                100,
                v1.pop());
AddTestCase(
                "pop single length vector, original vector change",
                "",
                v1.toString());

var v1=new Vector.<int>();
for (var i=0;i<10;i++) v1[i]=10-i;
AddTestCase(
                "pop simple vector element",
                1,
                v1.pop());
AddTestCase(
                "pop simple vector element, original vector changed",
                "10,9,8,7,6,5,4,3,2",
                v1.toString());
var v1=new Vector.<int>(10);
AddTestCase(
                "pop vector with initialized size",
                0,
                v1.pop());
AddTestCase(
                "pop vector with initialized size original vector changed",
                "0,0,0,0,0,0,0,0,0",
                v1.toString());

var v1=new Vector.<int>(10,true);
var errormsg="";
try {
  v1.pop();
} catch (e) {
  errormsg=e.toString();
}
AddTestCase(
                "pop fixed vector should throw exception",
                "RangeError: Error #1126",
                parseError(errormsg,"RangeError: Error #1126".length));
AddTestCase(
                "pop fixed vector should not change vector",
                "0,0,0,0,0,0,0,0,0,0",
                v1.toString());

var v2 = new Vector.<Object>(10,true);
var errormsg="";
try {
  p = v2.pop();
} catch (e) {
  errormsg=e.toString();
}
AddTestCase(
                "pop fixed object vector should throw exception",
                "RangeError: Error #1126",
                parseError(errormsg,"RangeError: Error #1126".length));

var v2 = new Vector.<Object>();
var popped = v2.pop();
AddTestCase('pop empty object vector',
            undefined,
            popped);

test();
