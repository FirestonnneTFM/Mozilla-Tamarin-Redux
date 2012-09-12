/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import PublicClass.*;


var SECTION = "Definitions";                                // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";                                 // Version of JavaScript or ECMA
var TITLE   = "Override public function in final class extending public class";     // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                                            // leave this alone


var CLASSDEFN = new FinExtPublicOverRidePublic();
var booleanValue:Boolean = true;

AddTestCase( "CLASSDEFN.callSuper(booleanValue)", booleanValue, CLASSDEFN.callSuper(booleanValue) );
AddTestCase( "CLASSDEFN.orSet", false, CLASSDEFN.orSet );
AddTestCase( "CLASSDEFN.orGet", false, CLASSDEFN.orGet );
AddTestCase( "CLASSDEFN.setPubBoolean( booleanValue ); CLASSDEFN.getPubBoolean()", booleanValue, ( CLASSDEFN.setPubBoolean( booleanValue ), CLASSDEFN.getPubBoolean() ) );
AddTestCase( "CLASSDEFN.orSet", true, CLASSDEFN.orSet );
AddTestCase( "CLASSDEFN.orGet", true, CLASSDEFN.orGet );

test();             // Leave this function alone.
            // This function is for executing the test case and then
            // displaying the result on to the console or the LOG file.
