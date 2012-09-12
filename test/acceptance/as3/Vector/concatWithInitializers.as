/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/**
   File Name:    concat.es
   Description:  The static concat method collects the vector elements from object followed by the vector
    elements from the additional items, in order, into a new vector object.  All the items must be objects.
    returns a new vector object
   */

var SECTION = " ";
var VERSION = "AS3";
startTest();

writeHeaderToLog( SECTION + " Vector.concat()-using-initializers");

var v1=new <uint>[0,1,2];
var v2=new <uint>[3,4,5];
var v3=v1.concat(v2)
AddTestCase(    "concat uint vector, original vector is unchanged",
        "0,1,2",
        v1.toString());
AddTestCase(    "concat uint vector, new vector concat worked",
        "0,1,2,3,4,5",
        v3.toString());

var v1=new <String>["zero","one","two"];
var v2=new <int>[0,1,2];
var errormsg;
try {
  var v3=v1.concat(v2);
} catch (e) {
  errormsg=e.toString();
}
AddTestCase(    "concat two differently typed vectors",
                "TypeError: Error #1034",
                parseError(errormsg,"TypeError: Error #1034".length));
                

var v1=new <uint>[5,6,7,8,9];
var v2=new <int>[0,1,2];
var errormsg;
try {
  var v3=v1.concat(v2);
} catch (e) {
  errormsg=e.toString();
}
AddTestCase(    "concat two differently typed vectors - uint and int",
                "TypeError: Error #1034",
                parseError(errormsg,"TypeError: Error #1034".length));


test();

