/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 

import publicClassConsNoParamPackage.*;

var SECTION = "Definitions";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "Constructors with no parameters of a public class";  // Provide ECMA section                                                                     //title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


                     
var NoParamCons:publicClassConsNoParam = new publicClassConsNoParam();
//print (NoParamCons.Add());


AddTestCase("calling public  Instance method",30,NoParamCons.Add());





test();       // leave this alone.  this executes the test cases and
              // displays results.
