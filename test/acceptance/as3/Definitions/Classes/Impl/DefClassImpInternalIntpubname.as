/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
import DefClassImpInternalIntpubname.*;
var SECTION = "Definitions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "Default class implements internal interface";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


///////////////////////////////////////////////////////////////
// add your tests here
  
var obj:DefaultClassAccesor = new DefaultClassAccesor();


//Default class implements a default interface with a public interface name method
AddTestCase("Default class implements an internal interface with a public interface name method", "PASSED", obj.accdeffunc());

////////////////////////////////////////////////////////////////

test();       // leave this alone.  this executes the test cases and
              // displays results.
