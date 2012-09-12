/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.38 - XML toString()");

//TEST(1, true, XML.prototype.hasOwnProperty("toString"));

XML.prettyPrinting = false;

x1 =
<alpha>
    <bravo>one</bravo>
    <charlie>
        <bravo>two</bravo>
    </charlie>
</alpha>;

TEST(2, "one", x1.bravo.toString());
TEST(3, "<bravo>one</bravo>" + NL() + "<bravo>two</bravo>", x1..bravo.toString());

x1 =
<alpha>
    <bravo>one</bravo>
    <charlie/>
</alpha>;

TEST(4, "", x1.charlie.toString());

x1 =
<alpha>
    <bravo>one</bravo>
    <charlie>
        <bravo>two</bravo>
    </charlie>
</alpha>;

TEST(5, "<charlie><bravo>two</bravo></charlie>", x1.charlie.toString());

x1 =
<alpha>
    <bravo>one</bravo>
    <charlie>
        two
        <bravo/>
    </charlie>
</alpha>;

TEST(5, "<charlie>two<bravo/></charlie>", x1.charlie.toString());

x1 =
<alpha>
    <bravo></bravo>
    <bravo/>
</alpha>;

TEST(6, "<bravo/>" + NL() + "<bravo/>", x1.bravo.toString());

x1 =
<alpha>
    <bravo>one<charlie/></bravo>
    <bravo>two<charlie/></bravo>
</alpha>;

TEST(7, "<bravo>one<charlie/></bravo>" + NL() + "<bravo>two<charlie/></bravo>", x1.bravo.toString());

var xmlDoc = "<employees><employee id='1'><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee><employee id='2'><firstname>Sue</firstname><lastname>Day</lastname><age>32</age></employee></employees>"


XML.prettyPrinting = false;
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.employee[0].toString()",
    "<employee id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee>",
    (MYXML = new XML(xmlDoc), MYXML.employee[0].toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.employee[1].toString()",
    "<employee id=\"2\"><firstname>Sue</firstname><lastname>Day</lastname><age>32</age></employee>",
    (MYXML = new XML(xmlDoc), MYXML.employee[1].toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.employee[0].firstname.toString()",
    "John",
    (MYXML = new XML(xmlDoc), MYXML.employee[0].firstname.toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.employee[1].firstname.toString()",
    "Sue",
    (MYXML = new XML(xmlDoc), MYXML.employee[1].firstname.toString()));

XML.prettyPrinting = true;
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.employee[0].toString()",
    "<employee id=\"1\">" + NL() + "  <firstname>John</firstname>" + NL() + "  <lastname>Walton</lastname>" + NL() + "  <age>25</age>" + NL() + "</employee>",
    (MYXML = new XML(xmlDoc), MYXML.employee[0].toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.employee[1].toString()",
    "<employee id=\"2\">" + NL() + "  <firstname>Sue</firstname>" + NL() + "  <lastname>Day</lastname>" + NL() + "  <age>32</age>" + NL() + "</employee>",
    (MYXML = new XML(xmlDoc), MYXML.employee[1].toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.employee[0].firstname.toString()",
    "John",
    (MYXML = new XML(xmlDoc), MYXML.employee[0].firstname.toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.employee[1].firstname.toString()",
    "Sue",
    (MYXML = new XML(xmlDoc), MYXML.employee[1].firstname.toString()));

xmlDoc = new XML("<XML>foo</XML>");

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.toString()",
    "foo",
    (MYXML = new XML(xmlDoc), MYXML.toString()));
    
END();
