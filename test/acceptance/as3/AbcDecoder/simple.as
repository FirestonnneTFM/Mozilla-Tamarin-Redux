/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

 /*
  * This file is imports the variable defined in varsDef.as
  * avmplus varsDef.abc simple.abc
 */

var SECTION = " ";
var VERSION = "AS3";
var TITLE   = "import variables defined from a varsDef.abc file";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

AddTestCase( "importing 'str' ", "imported string", str);
AddTestCase( "importing 'num'", 10, num);

test();
