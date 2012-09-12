/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import OptionalParams.*;


var SECTION = "Definitions";                                // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";                                 // Version of JavaScript or ECMA
var TITLE   = "Override a method defined in a namespace";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                                            // leave this alone



var base = new BaseClass();
var obj = new OverrideWithOptionalParams();

AddTestCase( "base.setInt(), base.i", 0, ( base.setInt(), base.i ) );
AddTestCase( "base.setInt(3), base.i", 3, ( base.setInt(3), base.i ) );
AddTestCase( "base.setString(), base.s", "default", ( base.setString(), base.s ) );
AddTestCase( "base.setString('here'), base.s", "here", ( base.setString("here"), base.s ) );
AddTestCase( "base.setAll(), base.i base.s", "0default", ( base.setAll(), (base.i + base.s) ) );
AddTestCase( "base.setAll(6, 'here'), base.i base.s", "6here", ( base.setAll(6, "here"), (base.i + base.s) ) );

AddTestCase( "obj.setInt(), obj.i", 1, ( obj.setInt(), obj.i ) );
AddTestCase( "obj.setInt(3), obj.i", 3, ( obj.setInt(3), obj.i ) );
AddTestCase( "obj.setString(), obj.s", "override", ( obj.setString(), obj.s ) );
AddTestCase( "obj.setString('here'), obj.s", "here", ( obj.setString("here"), obj.s ) );
AddTestCase( "obj.setAll(), obj.i obj.s", "1override", ( obj.setAll(), (obj.i + obj.s) ) );
AddTestCase( "obj.setAll(6, 'here'), obj.i obj.s", "6here", ( obj.setAll(6, "here"), (obj.i + obj.s) ) );





test();             // Leave this function alone.
            // This function is for executing the test case and then
            // displaying the result on to the console or the LOG file.
