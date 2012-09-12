/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Expressions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "qualified references";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone




import poo.*;

var f:foo = new foo();
AddTestCase( "f.teamName = 'Macromedia'", "Macromedia", f.teamName );
AddTestCase( "f.public::teamName = 'Macromedia'", "Macromedia", f.public::teamName );
AddTestCase( "f.Baseball::teamName = 'Giants'", "Giants", f.Baseball::teamName );
AddTestCase( "f.Football::teamName = 'Chargers'", "Chargers", f.Football::teamName );
AddTestCase( "f.Basketball::teamName = 'Kings'", "Kings", f.Basketball::teamName );
AddTestCase( "f.Hockey::teamName = 'Sharks'", "Sharks", f.Hockey::teamName );

AddTestCase( "f.Hockey::teamColor = 'yellow'", "yellow", f.Hockey::teamColor );

test();       // leave this alone.  this executes the test cases and
              // displays results.
