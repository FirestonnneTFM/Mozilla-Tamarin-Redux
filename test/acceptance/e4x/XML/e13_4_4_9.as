/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.9 - XML comments()");

//TEST(1, true, XML.prototype.hasOwnProperty("comments"));

XML.ignoreComments = false;

x1 = new XML("<alpha><!-- comment one --><bravo><!-- comment two -->some text</bravo></alpha>");

TEST_XML(2, "<!-- comment one -->", x1.comments());
TEST_XML(3, "<!-- comment two -->", x1..*.comments());

x2 = new XML("<alpha><!-- comment one --><!-- comment 1.5 --><bravo><!-- comment two -->some text<charlie><!-- comment three --></charlie></bravo></alpha>");

TEST(4, "<!-- comment one -->\n<!-- comment 1.5 -->", x2.comments().toXMLString());
TEST(5, "<!-- comment two -->\n<!-- comment three -->", x2..*.comments().toXMLString());

XML.ignoreComments = true;
var xmlDoc = "<company><!-- This is Comment --><employee id='1'><!-- This is another Comment --><name>John</name> <city>California</city> </employee><!-- me too --></company>";

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.comments().toString()", "", (MYXML = new XML(xmlDoc), MYXML.comments().toString()));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.comments() instanceof XMLList", true, (MYXML = new XML(xmlDoc), MYXML.comments() instanceof XMLList));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.comments() instanceof XML", false, (MYXML = new XML(xmlDoc), MYXML.comments() instanceof XML));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.comments().length()", 0, (MYXML = new XML(xmlDoc), MYXML.comments().length() ));

XML.prettyPrinting = true;
XML.ignoreComments = false;
AddTestCase( "XML.ignoreComments = false, MYXML = new XML(xmlDoc), MYXML.comments().toString()",
    "<!-- This is Comment -->\n<!-- me too -->",
    (XML.ignoreComments = false, MYXML = new XML(xmlDoc), MYXML.comments().toXMLString()));
AddTestCase( "XML.ignoreComments = false, MYXML = new XML(xmlDoc), MYXML.comments() instanceof XMLList", true, (MYXML = new XML(xmlDoc), MYXML.comments() instanceof XMLList));
AddTestCase( "XML.ignoreComments = false, MYXML = new XML(xmlDoc), MYXML.comments() instanceof XML", false, (MYXML = new XML(xmlDoc), MYXML.comments() instanceof XML));
AddTestCase( "XML.ignoreComments = false, MYXML = new XML(xmlDoc), MYXML.comments().length()", 2, (MYXML = new XML(xmlDoc), MYXML.comments().length() ));

AddTestCase( "XML.ignoreComments = false, MYXML = new XML(xmlDoc), XML.ignoreComments = true, MYXML.comments().toString()",
    "<!-- This is Comment -->\n<!-- me too -->",
    (XML.ignoreComments = false, MYXML = new XML(xmlDoc), XML.ignoreComments = true, MYXML.comments().toXMLString()));

END();
