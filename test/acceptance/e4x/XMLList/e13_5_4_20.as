/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.20 - XMLList toString()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("toString"));
    
x1 = <><alpha>one</alpha></>;

TEST(2, "one", x1.toString());

x1 = <><alpha>one</alpha><bravo>two</bravo></>;

TEST(3, "<alpha>one</alpha>" + NL() + "<bravo>two</bravo>", x1.toString());


var xmlDoc = "<employees><employee id='1'><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee><employee id='2'><firstname>Sue</firstname><lastname>Day</lastname><age>32</age></employee></employees>"


XML.prettyPrinting = false;
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[0].toString()",
    "<employee id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee>",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[0].toString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[1].toString()",
    "<employee id=\"2\"><firstname>Sue</firstname><lastname>Day</lastname><age>32</age></employee>",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[1].toString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[0].firstname.toString()",
    "John",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[0].firstname.toString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[1].firstname.toString()",
    "Sue",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[1].firstname.toString()));

XML.prettyPrinting = true;
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[0].toString()",
    "<employee id=\"1\">" + NL() + "  <firstname>John</firstname>" + NL() + "  <lastname>Walton</lastname>" + NL() + "  <age>25</age>" + NL() + "</employee>",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[0].toString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[1].toString()",
    "<employee id=\"2\">" + NL() + "  <firstname>Sue</firstname>" + NL() + "  <lastname>Day</lastname>" + NL() + "  <age>32</age>" + NL() + "</employee>",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[1].toString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[0].firstname.toString()",
    "John",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[0].firstname.toString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.employee[1].firstname.toString()",
    "Sue",
    (MYXML = new XMLList(xmlDoc), MYXML.employee[1].firstname.toString()));

xmlDoc = new XMLList("<XML>foo</XML>");

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.toString()",
    "foo",
    (MYXML = new XMLList(xmlDoc), MYXML.toString()));

END();
