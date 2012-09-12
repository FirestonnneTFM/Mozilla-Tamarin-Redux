/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


var SECTION = "E4X";
var VERSION = "";
var TITLE   = "Wildcard attribute assignment";

startTest();


var none:XML = <x><c/></x>;
none.@* = 1;
var noneres:XML = <x><c/></x>;
AddTestCase( "wildcard attribute assignment no result", noneres.toString(), none.toString());


var one:XML = <x bar="0"><c/></x>;
one.@* = 1;
var oneres:XML = <x bar="1"><c/></x>;
AddTestCase( "wildcard attribute assignment one result", oneres.toString(), one.toString());


var many:XML = <x bar="0" foo="bar"><c/></x>;
many.@* = 1;
var manyres:XML = <x bar="1"><c/></x>;
AddTestCase( "wildcard attribute assignment many results", manyres.toString(), many.toString());


test();

