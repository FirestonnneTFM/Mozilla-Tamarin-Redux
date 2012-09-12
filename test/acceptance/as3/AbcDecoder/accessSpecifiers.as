/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

 /*
  * This file access the methods/properties defined in .abc file
  * Aim : To test the access specifiers
 */

var SECTION = " ";
var VERSION = "AS3";
var TITLE   = "import a class defined in .abc file";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var obj = new accSpecClass();

AddTestCase( "invoke the method 'func1()' from the imported file", "string", obj.accSpec1);
AddTestCase( "invoke the method 'func2()' from the imported file", "Inside func1()-public function", obj.func1());
AddTestCase( "invoke the method 'func2()' from the imported file", "Inside func2()-Dynamic function", obj.func2());

var obj = new dynClass();

AddTestCase( "invoke the method 'func1()' from the imported file", "string", obj.dynSpec1);
AddTestCase( "invoke the method 'func2()' from the imported file", "Inside func1()-public function", obj.func1());
AddTestCase( "invoke the method 'func2()' from the imported file", "Inside func2()-Dynamic function", obj.func2());

test();
