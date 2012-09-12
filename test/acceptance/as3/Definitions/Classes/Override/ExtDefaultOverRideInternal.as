/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import DefaultClass.*;


var SECTION = "Definitions";                                // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";                                 // Version of JavaScript or ECMA
var TITLE   = "Override default function in default class extending default class";     // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                                            // leave this alone


var CLASSDEFN = new ExtDefaultOverRideInternal();

AddTestCase( "*** Default Methods and Default properites ***", 1, 1 );
AddTestCase( "CLASSDEFN.setGetArray([test])", ["override","worked","test"].toString(), ( CLASSDEFN.setGetArray(["test"]).toString()) );


test();             // Leave this function alone.
            // This function is for executing the test case and then
            // displaying the result on to the console or the LOG file.
