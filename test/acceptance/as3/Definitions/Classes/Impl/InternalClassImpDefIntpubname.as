/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
import InternalClassImpDefIntpubname.*;
var SECTION = "Definitions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "Internal class implements default interface";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


///////////////////////////////////////////////////////////////
// add your tests here
  
var obj = new InternalClassAccesor();

//Internal class implements a default interface with a public interface name method
AddTestCase("Internal class implements a default interface with a public interface name method", "PASSED", obj.accdeffunc());


////////////////////////////////////////////////////////////////

test();       // leave this alone.  this executes the test cases and
              // displays results.
