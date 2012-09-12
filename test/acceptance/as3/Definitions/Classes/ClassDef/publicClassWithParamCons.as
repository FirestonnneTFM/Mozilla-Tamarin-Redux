/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 

import testpublicClassWithParamCons.*;

var SECTION = "Definitions";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "No Parameter Constructors of a Internal class";  // Provide ECMA section                                                                 // title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


var a:Number=20;
var b:Number=0.5;

                     
var publicWithParamCons:publicClassWithParamCons = new publicClassWithParamCons(a,b);
//print (publicWithParamCons.Add());

AddTestCase("calling public Instance method",20.5,publicWithParamCons.Add());





test();       // leave this alone.  this executes the test cases and
              // displays results.
