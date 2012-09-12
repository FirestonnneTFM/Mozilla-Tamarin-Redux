/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import DefaultClass.*;


var SECTION = "Definitions";                                // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";                                 // Version of JavaScript or ECMA
var TITLE   = "Override public function in dynamic class extending default class";      // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                                            // leave this alone


var CLASSDEFN = new DynExtDefaultOverRidePublic();

AddTestCase( "CLASSDEFN.setPubBoolean(true); CLASSDEFN.orSetCalled", true, ( CLASSDEFN.setPubBoolean(true), CLASSDEFN.orSetCalled ) );
AddTestCase( "CLASSDEFN.getPubBoolean();", true, CLASSDEFN.getPubBoolean() );
AddTestCase( "CLASSDEFN.orGetCalled", true, CLASSDEFN.orGetCalled );
CLASSDEFN.orGetCalled=false;
AddTestCase( "CLASSDEFN.setPubBoolean(false); CLASSDEFN.orSetCalled", true, ( CLASSDEFN.setPubBoolean(false), CLASSDEFN.orSetCalled ) );
AddTestCase( "CLASSDEFN.getPubBoolean();", false, CLASSDEFN.getPubBoolean() );
AddTestCase( "CLASSDEFN.orGetCalled", true, CLASSDEFN.orGetCalled );


test();             // Leave this function alone.
            // This function is for executing the test case and then
            // displaying the result on to the console or the LOG file.
