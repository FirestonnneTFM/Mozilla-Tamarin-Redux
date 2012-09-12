/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.3 - XMLList attributes()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("attributes"));

// Test with XMLList of size 0
x1 = new XMLList()
TEST(2, "xml", typeof(x1.attributes()));
TEST_XML(3, "", x1.attributes());

// Test with XMLList of size 1
x1 += <alpha attr1="value1" attr2="value2">one</alpha>;

TEST(4, "xml", typeof(x1.attributes()));
correct = new XMLList();
correct += new XML("value1");
correct += new XML("value2");
TEST(5, correct, x1.attributes());

// Test with XMLList of size > 1
x1 += <bravo attr3="value3" attr4="value4">two</bravo>;

TEST(6, "xml", typeof(x1.attributes()));
correct = new XMLList();
correct += new XML("value1");
correct += new XML("value2");
correct += new XML("value3");
correct += new XML("value4");
TEST(7, correct, x1.attributes());

var xmlDoc = "<TEAM foo = 'bar' two='second'>Giants</TEAM><CITY two = 'third'>Giants</CITY>";

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.attributes() instanceof XMLList", true,
             (MYXML = new XMLList(xmlDoc), MYXML.attributes() instanceof XMLList ));
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.attributes() instanceof XML", false,
             (MYXML = new XMLList(xmlDoc), MYXML.attributes() instanceof XML ));
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.attributes().length()", 3,
             (MYXML = new XMLList(xmlDoc), MYXML.attributes().length() ));
XML.prettyPrinting = false;
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.attributes().toString()", "barsecondthird",
             (MYXML = new XMLList(xmlDoc), MYXML.attributes().toString() ));
XML.prettyPrinting = true;
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.attributes().toString()", "barsecondthird",
             (MYXML = new XMLList(xmlDoc), MYXML.attributes().toString() ));
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.attributes()[0].nodeKind()", "attribute",
             (MYXML = new XMLList(xmlDoc), MYXML.attributes()[0].nodeKind() ));
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.attributes()[1].nodeKind()", "attribute",
             (MYXML = new XMLList(xmlDoc), MYXML.attributes()[1].nodeKind() ));
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.attributes()[2].nodeKind()", "attribute",
             (MYXML = new XMLList(xmlDoc), MYXML.attributes()[2].nodeKind() ));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.attributes().toXMLString()", "bar" + NL() + "second" + NL() + "third",
             (MYXML = new XMLList(xmlDoc), MYXML.attributes().toXMLString() ));

END();
