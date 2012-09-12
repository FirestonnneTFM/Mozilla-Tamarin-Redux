/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
import PublicClassImpPublicIntIntname.*;
var SECTION = "Definitions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "Public class implements public interface";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


///////////////////////////////////////////////////////////////
// add your tests here
  
var obj = new PublicClass();

//Public class implements the first public interface with an interface name method
AddTestCase("Public class implements the first public interface with an interface name method", "PASSED", obj.accdeffunc());
//Public class implements the second public interface with an interface name method
AddTestCase("Public class implements the second public interface with an interface name method", "PASSED", obj.accdeffunc());


////////////////////////////////////////////////////////////////

test();       // leave this alone.  this executes the test cases and
              // displays results.
