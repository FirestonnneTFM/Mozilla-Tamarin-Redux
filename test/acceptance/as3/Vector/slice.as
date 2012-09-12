/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var SECTION="";
var VERSION = "ECMA_1";

startTest();

writeHeaderToLog( " Vector.slice()");
var v1=new Vector.<String>();
AddTestCase(
        "slice no args on empty vector",
        "",
        v1.slice().toString());
test();