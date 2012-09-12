/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 

import testdynfinalClassWithParamCons.*;

var SECTION = "Definitions";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "Constructors with parameters of a dynamic class";  // Provide ECMA section                                                                 //title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


//var currentDate = new Date();
var deffinWithParamCons:dynfinClassWithParamCons = new dynfinClassWithParamCons(20,40);
//print (deffinWithParamCons.Add());


AddTestCase("calling public Instance method",60,deffinWithParamCons.Add());





test();       // leave this alone.  this executes the test cases and
              // displays results.
