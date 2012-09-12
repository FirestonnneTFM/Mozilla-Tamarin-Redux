/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/**
   File Name:    filter.es
   Description:  filter(object,checker,thisobj)
     calls checker on every vector element of object in increasing numerical index order,
     collecting all the vector elements for which checker returns a true value.
     checker is called with three arguments: the property value, the property index, and object
     itself. The thisobj is used as the this object in the call.
     returns a new vector object containing the elements that were collected in the order
     they were collected.
   */
var SECTION="";
var VERSION = "ECMA_1";

startTest();

writeHeaderToLog( " Vector.filter()-using-initializers");

function EvenChecker(value,index,obj) {
  if (value%2==0)
    return true;
  return false;
}
var invalidchecker="a string";
function ThisChecker(value,index,obj):Boolean {
  msg+=this.message;
  return true;
}

var errormsg="";
try {
  var result=new <int>[].filter();
} catch (e) {
  errormsg=e.toString();
}
AddTestCase(    "filter checker is undefined",
        "ArgumentError: Error #1063",
    parseError(errormsg,"ArgumentError: Error #1063".length));

var errormsg="";
try {
  var result=new <int>[0,1,2,3,4,5,6,7,8,9].filter(invalidchecker);
} catch (e) {
  errormsg=e.toString();
}
AddTestCase(    "filter checker is not a function",
        "TypeError: Error #1034",
              parseError(errormsg,"TypeError: Error #1034".length));

var result=new <int>[].filter(EvenChecker);
AddTestCase(    "filter empty vector",
        "",
        result.toString());

AddTestCase(    "filter small vector",
        "0,2,4,6,8",
        new <int>[0,1,2,3,4,5,6,7,8,9].filter(EvenChecker).toString());

var myobject=new Object();
myobject.message="message";
var msg="";
var result=new <int>[0,1,2].filter(ThisChecker,myobject);
AddTestCase(    "filter use thisobj",
        "messagemessagemessage",
        msg);

test();
