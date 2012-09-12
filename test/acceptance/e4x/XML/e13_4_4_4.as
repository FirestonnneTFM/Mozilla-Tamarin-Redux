/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.4 - XML attribute()");

//TEST(1, true, XML.prototype.hasOwnProperty("attribute"));

// Get count of employees
emps =
<employees count="2">
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

TEST_XML(2, 2, emps.attribute("count"));

// Get the id of the employee age 25
emps =
<employees>
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

TEST_XML(3, 0, emps.employee.(age == "25").attribute("id"));

// Get the id of the employee named Jim
emps =
<employees>
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

TEST_XML(4, 0, emps.employee.(name == "Jim").attribute("id"));

var xmlDoc = "<TEAM foo = 'bar' two='second'>Giants</TEAM>";

// verify that attribute correct finds one attribute node
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('foo') instanceof XMLList", true,
             (MYXML = new XML(xmlDoc), MYXML.attribute('foo') instanceof XMLList ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('foo') instanceof XML", false,
             (MYXML = new XML(xmlDoc), MYXML.attribute('foo') instanceof XML ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('foo').length()", 1,
             (MYXML = new XML(xmlDoc), MYXML.attribute('foo').length() ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('foo').toString()", "bar",
             (MYXML = new XML(xmlDoc), MYXML.attribute('foo').toString() ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('foo')[0].nodeKind()", "attribute",
             (MYXML = new XML(xmlDoc), MYXML.attribute('foo')[0].nodeKind() ));

// verify that attribute doesn't find non-existent names
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('DOESNOTEXIST') instanceof XMLList", true,
             (MYXML = new XML(xmlDoc), MYXML.attribute('DOESNOTEXIST') instanceof XMLList ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('DOESNOTEXIST') instanceof XML", false,
             (MYXML = new XML(xmlDoc), MYXML.attribute('DOESNOTEXIST') instanceof XML ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('DOESNOTEXIST').length()", 0,
             (MYXML = new XML(xmlDoc), MYXML.attribute('DOESNOTEXIST').length() ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('DOESNOTEXIST').toString()", "",
             (MYXML = new XML(xmlDoc), MYXML.attribute('DOESNOTEXIST').toString() ));
             
// verify that attribute doesn't find child node names
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('TEAM') instanceof XMLList", true,
             (MYXML = new XML(xmlDoc), MYXML.attribute('TEAM') instanceof XMLList ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('TEAM') instanceof XML", false,
             (MYXML = new XML(xmlDoc), MYXML.attribute('TEAM') instanceof XML ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('TEAM').toString()", "",
             (MYXML = new XML(xmlDoc), MYXML.attribute('TEAM').toString() ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attribute('TEAM').length()", 0,
             (MYXML = new XML(xmlDoc), MYXML.attribute('TEAM').length() ));

xl = <x a="aatr" b="batr">y</x>;

AddTestCase( "attribute(new QName(\"*\"))", "aatrbatr",
       ( q = new QName("*"), xl.attribute(q).toString() ));

AddTestCase( "attribute(new QName(\"@*\"))", "",
       ( q = new QName("@*"), xl.attribute(q).toString() ));

END();
