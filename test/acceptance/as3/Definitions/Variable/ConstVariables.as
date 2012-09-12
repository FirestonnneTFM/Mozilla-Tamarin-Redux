/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "const variables";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


import Package1.*;

use namespace ns1;

const item1:String = "const item1 set at creation time";

AddTestCase( "const variable item1", "const item1 set at creation time", item1);

AddTestCase( "package const variable packageItem1", "const packageItem1 set at creation time", packageItem1);
AddTestCase( "package const variable packageItem2", "const packageItem2 set at creation time", packageItem2);
AddTestCase( "package const variable packageItem3", undefined, packageItem3);
AddTestCase( "package const variable packageItem4", "const packageItem4 set at creation time", packageItem4);
AddTestCase( "package const variable packageItem5", 5, packageItem5);

var c1 = new Class1();

AddTestCase( "Class1 const variable classItem1", "const Class1 classItem1 set at creation time", c1.classItem1);
AddTestCase( "Class1 const variable classItem2", "const Class1 classItem2 set at creation time", c1.classItem2);
AddTestCase( "Class1 const variable classItem3", undefined, c1.classItem3);
AddTestCase( "Class1 const variable classItem4", "const Class1 classItem4 set at creation time", c1.classItem4);
AddTestCase( "Class1 const variable classItem5", 6, c1.classItem5);
AddTestCase( "Class1 const variable classItem6", "static const Class1 classItem6 set at creation time", Class1.classItem6);
AddTestCase( "Class1 const variable classItem7", "ns1 const Class1 classItem7 set at creation time", c1.classItem7);
AddTestCase( "Class1 const variable classItem8", "ns1 static const Class1 classItem8 set at creation time", Class1.classItem8);

var c2 = new Class2();

AddTestCase( "Class2 const variable classItem1", "const Class2 classItem1 set in constructor", c2.classItem1);
AddTestCase( "Class2 const variable classItem2", "const Class2 classItem2 set in constructor", c2.classItem2);
AddTestCase( "Class2 const variable classItem3", undefined, c2.classItem3);
AddTestCase( "Class2 const variable classItem4", "const Class2 classItem4 set in constructor", c2.classItem4);
AddTestCase( "Class2 const variable classItem5", 7, c2.classItem5);
AddTestCase( "Class2 const variable classItem6", "static const Class2 classItem6 set in function", Class2.classItem6);
AddTestCase( "Class2 const variable classItem7", "ns1 const Class2 classItem7 set in constructor", c2.classItem7);
AddTestCase( "Class2 const variable classItem8", "ns1 static const Class2 classItem8 set in function", Class2.classItem8);

test();       // leave this alone.  this executes the test cases and
              // displays results.
