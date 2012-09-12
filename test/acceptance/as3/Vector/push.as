/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/**
   File Name:    push.es
   Description:  push(object,...items)
     push method adds elements to the end of the vector and increases the length of the vector
   *
   */
var SECTION="";
var VERSION = "ECMA_1";

startTest();

writeHeaderToLog( " Vector.push()");

var v1=new Vector.<int>();
v1.push();
AddTestCase(
        "push empty vector",
        "",
        v1.toString());

var v1=new Vector.<int>();
v1.push(1)
AddTestCase(
                "push single item to int vector",
                "1",
                v1.toString());

var v1=new Vector.<int>();
for (var i=0;i<3;i++) v1[i]=i;
v1.push()
AddTestCase(
                "push nothing to small int vector",
                "0,1,2",
                v1.toString());


var v1=new Vector.<int>();
for (var i=0;i<=3;i++) v1[i]=i;
v1.push(4,5,6);
AddTestCase(
                "push several elements to small int vector",
                "0,1,2,3,4,5,6",
                v1.toString());

var v1=new Vector.<int>(3,true);
for (var i=0;i<3;i++) v1[i]=i;
var errormsg="";
try {
  v1.push(9);
} catch (e) {
  errormsg=e.toString();
}
// RangeError: Error #1126: Cannot change the length of a fixed Vector.
AddTestCase(
        "attempt to push to a fixed int vector",
        "RangeError: Error #1126",
        parseError(errormsg,"RangeError: Error #1126".length));

var v1=new Vector.<uint>(3,true);
for (var i=0;i<3;i++) v1[i]=i;
var errormsg="";
try {
  v1.push();
} catch (e) {
  errormsg=e.toString();
}
// RangeError: Error #1126: Cannot change the length of a fixed Vector.
AddTestCase(
        "attempt to push nothing to a fixed uint vector",
        "RangeError: Error #1126",
        parseError(errormsg,"RangeError: Error #1126".length));

// Object vectors

var v1=new Vector.<Object>();
for (var i=0;i<=3;i++) v1[i]=i;
v1.push(4,'5',6.5374523,{hello:"world"});
AddTestCase(
                "push several elements to Object vector",
                "0,1,2,3,4,5,6.5374523,[object Object]",
                v1.toString());

var v1=new Vector.<*>();
for (var i=0;i<=3;i++) v1[i]=i;
v1.push(4,'5',6.5374523,{hello:"world"});
AddTestCase(
                "push several elements to Object vector",
                "0,1,2,3,4,5,6.5374523,[object Object]",
                v1.toString());

var v1=new Vector.<Object>(3,true);
for (var i=0;i<3;i++) v1[i]=i;
var errormsg="";
try {
  v1.push('hello');
} catch (e) {
  errormsg=e.toString();
}
// RangeError: Error #1126: Cannot change the length of a fixed Vector.
AddTestCase(
        "attempt to push to a fixed Object vector",
        "RangeError: Error #1126",
        parseError(errormsg,"RangeError: Error #1126".length));

var v1=new Vector.<Object>(3,true);
for (var i=0;i<3;i++) v1[i]=i;
var errormsg="";
try {
  v1.push();
} catch (e) {
  errormsg=e.toString();
}
// RangeError: Error #1126: Cannot change the length of a fixed Vector.
AddTestCase(
        "attempt to push nothing to a fixed Object vector",
        "RangeError: Error #1126",
        parseError(errormsg,"RangeError: Error #1126".length));



var v1=new Vector.<Function>(3);
var errormsg="";
try {
  v1.push({hello:"world"});
} catch (e) {
  errormsg=e.toString();
  print(errormsg)
}

// TypeError: Error #1034: Type Coercion failed: cannot convert Object@68a6c9 to Function.
AddTestCase(
        "push an Object to an Function vector",
        "TypeError: Error #1034",
        parseError(errormsg,"TypeError: Error #1034".length));

test();
