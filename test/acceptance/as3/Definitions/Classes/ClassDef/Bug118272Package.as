/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Class Definition";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

//-----------------------------------------------------------------------------

import Bug118272Package.*;


var eg = new BugTest();
AddTestCase("Trying to initialize public  class identifier", "ReferenceError: Error #1056", referenceError(eg.thisError));
AddTestCase("Trying to initialize default class identifier", "ReferenceError: Error #1056", referenceError(eg.thisError1));
AddTestCase("Trying to initialize internal class identifier", "ReferenceError: Error #1056", referenceError(eg.thisError2));
AddTestCase("Trying to initialize dynamic class identifier", "ReferenceError: Error #1056", referenceError(eg.thisError3));
AddTestCase("Trying to initialize final class identifier", "ReferenceError: Error #1056", referenceError(eg.thisError4));



//test case in bug118272
class A { }
var thisError:String = "no error";
try{
A = null;
}catch(e:ReferenceError){
    thisError = e.toString();
}finally{
AddTestCase("Trying to initialize class identifier,the class is outside the package", "ReferenceError: Error #1074", referenceError(thisError));
}

test();       // leave this alone.  this executes the test cases and
              // displays results.
