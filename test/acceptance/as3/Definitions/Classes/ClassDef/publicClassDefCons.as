/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
 

import publicClassConstructors.*;

var SECTION = "Definitions";           // provide a document reference (ie, ECMA section)
var VERSION = "AS3";                   // Version of JavaScript or ECMA
var TITLE   = "Default Constructors of a public class";  // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


var currentDate = new Date(0);
var DefCons:publicClassDefCons = new publicClassDefCons();
//print (DefCons.Add());
//print (DefCons.wrapprivchangeval());
//print (DefCons.wrapprotmystring());
//print (DefCons.currentdate());
//print (DefCons.wrapintmyobject());
//print (DefCons.mydatatype);

AddTestCase("calling public final Instance method",30,DefCons.Add());
AddTestCase("Calling private Instance method",false,DefCons.wrapprivchangeval());
AddTestCase("Calling public Instance method",currentDate.toString(),(DefCons.currentdate()).toString());
AddTestCase("Calling internal Instance method","I am a string",DefCons.wrapintmyobject());





test();       // leave this alone.  this executes the test cases and
              // displays results.
