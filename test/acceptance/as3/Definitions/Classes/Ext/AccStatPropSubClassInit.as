/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";  // Version of JavaScript or ECMA
var TITLE   = "Access static property of base class from subclass";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

/**
 * Calls to AddTestCase here. AddTestCase is a function that is defined
 * in shell.js and takes three arguments:
 * - a string representation of what is being tested
 * - the expected result
 * - the actual result
 *
 * For example, a test might look like this:
 *
 * var helloWorld = "Hello World";
 *
 * AddTestCase(
 * "var helloWorld = 'Hello World'",   // description of the test
 *  "Hello World",                     // expected result
 *  helloWorld );                      // actual result
 *
 */

import StaticProperty.*;
  



// ********************************************
// Check the static property of the sub class
// ********************************************
AddTestCase( "*** Check the static property of the sub class ***", 1, 1 );
AddTestCase( "AccStatPropSubClassInit.aStat", "BaseClass.x", AccStatPropSubClassInit.aStat );
AddTestCase( "AccStatPropSubClassInit.aStat2", "BaseClass.x", AccStatPropSubClassInit.aStat2 );


var obj = new AccStatPropSubClassInit();
// ********************************************
// Check the property of the sub class
// ********************************************
AddTestCase( "*** Check the property of the sub class ***", 1, 1 );
AddTestCase( "obj.aVar", "BaseClass.x", obj.aVar );
AddTestCase( "obj.aVar2", "BaseClass.x", obj.aVar2 );




test();       // leave this alone.  this executes the test cases and
              // displays results.
