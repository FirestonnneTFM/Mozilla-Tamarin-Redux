/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import DefaultClass.*;


var SECTION = "Definitions";                                // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";                                 // Version of JavaScript or ECMA
var TITLE   = "Override public function in default class extending default class";      // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                                            // leave this alone


var CLASSDEFN = new ExtDefaultOverRidePublic();
var myString = "teststring";

AddTestCase( "CLASSDEFN.setPubString(myString); CLASSDEFN.orSetString", "PASSED", (CLASSDEFN.setPubString(myString), CLASSDEFN.orSetString ) );
AddTestCase( "CLASSDEFN.getPubString()" , "override_teststring_override", CLASSDEFN.getPubString() );
AddTestCase( "CLASSDEFN.orGetString" , "PASSED", CLASSDEFN.orGetString );


AddTestCase( "CLASSDEFN.setPubString(null); CLASSDEFN.getPubString()", "override_null_override", (CLASSDEFN.setPubString(null), CLASSDEFN.getPubString()) );
AddTestCase( "CLASSDEFN.setPubString(undefined); CLASSDEFN.getPubString()", "override_null_override", (CLASSDEFN.setPubString(undefined), CLASSDEFN.getPubString()) );


test();             // Leave this function alone.
            // This function is for executing the test case and then
            // displaying the result on to the console or the LOG file.
