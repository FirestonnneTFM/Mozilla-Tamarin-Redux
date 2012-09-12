/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.21 - XMLList toXMLString()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("toXMLString"));
    
x1 = <><alpha>one</alpha></>;

TEST(2, "<alpha>one</alpha>", x1.toXMLString());

x1 = <><alpha>one</alpha><bravo>two</bravo></>;

TEST(3, "<alpha>one</alpha>" + NL() + "<bravo>two</bravo>", x1.toXMLString());


var xmlDoc = "<employees><employee id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee><employee id=\"2\"><firstname>Sue</firstname><lastname>Day</lastname><age>32</age></employee></employees>"


// propertyName as a string
XML.prettyPrinting = false;
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[0].toXMLString()",
    "<employee id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee>",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[0].toXMLString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[1].toXMLString()",
    "<employee id=\"2\"><firstname>Sue</firstname><lastname>Day</lastname><age>32</age></employee>",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[1].toXMLString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[0].firstname.toXMLString()",
    "<firstname>John</firstname>",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[0].firstname.toXMLString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[1].firstname.toXMLString()",
    "<firstname>Sue</firstname>",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[1].firstname.toXMLString()));

XML.prettyPrinting = true;
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[0].toXMLString()",
    "<employee id=\"1\">" + NL() + "  <firstname>John</firstname>" + NL() + "  <lastname>Walton</lastname>" + NL() + "  <age>25</age>" + NL() + "</employee>",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[0].toXMLString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[1].toXMLString()",
    "<employee id=\"2\">" + NL() + "  <firstname>Sue</firstname>" + NL() + "  <lastname>Day</lastname>" + NL() + "  <age>32</age>" + NL() + "</employee>",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[1].toXMLString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[0].firstname.toXMLString()",
    "<firstname>John</firstname>",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[0].firstname.toXMLString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[1].firstname.toXMLString()",
    "<firstname>Sue</firstname>",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[1].firstname.toXMLString()));

xmlDoc = "<XML>foo</XML>";
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.toXMLString()",
    "<XML>foo</XML>",
    (MYXML = new XMLList(xmlDoc), MYXML.toXMLString()));

END();
