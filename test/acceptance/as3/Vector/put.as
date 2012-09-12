/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/**
   File Name:          put.es
   ECMA Section:       [[ Put]] (P, V)
   Description:
   Vector objects use a variation of the [[Put]] method used for other native
   put usage for vectors is v1[i]=..., may only set v1[i] where i<=v1.length

   Author:             dschaffe@adobe.com 19-Nov-2007
*/

var SECTION = "";
var VERSION = "ECMA_1";
startTest();
var TITLE   = "Vector [[Put]] (P, V)";

writeHeaderToLog( SECTION + " "+ TITLE);

var v1=new Vector.<int>();
v1[0]=10;
AddTestCase("set [0] to empty vector",
            10,
            v1[0]);
AddTestCase("set [0] to empty vector, length increments",
            1,
            v1.length);

var v1=new Vector.<int>();
var errormsg="";
try {
  v1[1]=10;
} catch (e) {
  errormsg=e.toString();
}
AddTestCase("set [1] element on empty vector, throws exception",
            "RangeError: Error #1125",
            parseError(errormsg,"RangeError: Error #1125".length));
AddTestCase("set [1] element on empty vector, array is still empty",
            "",
            v1.toString());

var v1=new Vector.<int>(5,true);
for (var i:uint=0;i<5;i++) v1[i]=i+1;
var errormsg="";
try {
  v1[5]=10;
} catch (e) {
  errormsg=e.toString();
}
AddTestCase("set fixed vector past fixed length throws exception",
            "RangeError: Error #1125",
            parseError(errormsg,"RangeError: Error #1125".length));
AddTestCase("set fixed vector past fixed length throws exception, original vector remains same",
            "1,2,3,4,5",
            v1.toString());

var v1=new Vector.<int>(5);
for (var i=0;i<5;i++) v1[i]=i;
v1[4]=10;
AddTestCase("set existing element in vector to new value",
            "0,1,2,3,10",
            v1.toString());

var v1=new Vector.<int>(5);
for (var i=0;i<5;i++) v1[i]=i;
v1[5]=5;
AddTestCase("existing vector set expand the vector by setting element to v1[length]",
            "0,1,2,3,4,5",
            v1.toString());


test();
