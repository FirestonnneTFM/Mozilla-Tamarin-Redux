/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.13 - XMLList hasSimpleContent()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("hasSimpleContent"));

// One element should be same as XML case
x1 =
<>
<alpha attr1="value1">
    <bravo>one</bravo>
    <charlie>
        two
        three
        <echo>four</echo>
    </charlie>
    <delta />
    <foxtrot attr2="value2">five</foxtrot>
    <golf attr3="value3" />
    <hotel>
        six
        seven
    </hotel>
    <india><juliet /></india>
</alpha>;
</>;

TEST(2, false, x1.hasSimpleContent());
TEST(3, true, x1.bravo.hasSimpleContent());
TEST(4, false, x1.charlie.hasSimpleContent());
TEST(5, true, x1.delta.hasSimpleContent());
TEST(6, true, x1.foxtrot.hasSimpleContent());
TEST(7, true, x1.golf.hasSimpleContent());
TEST(8, true, x1.hotel.hasSimpleContent());
TEST(9, true, x1.@attr1.hasSimpleContent());
TEST(10, true, x1.bravo.child(0).hasSimpleContent());
TEST(11, false, x1.india.hasSimpleContent());

// More than one element is complex if one or more things in the list are elements.
x1 =
<>
<alpha>one</alpha>
<bravo>two</bravo>
</>;

TEST(12, false, x1.hasSimpleContent());

x1 =
<root>
    one
    <alpha>one</alpha>
</root>;

TEST(13, false, x1.*.hasSimpleContent());

x1 =
<root attr1="value1" attr2="value2">
    one
</root>;

TEST(14, true, x1.@*.hasSimpleContent());

var xmlDoc = "<employee><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee>"

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.hasSimpleContent()", true,
(MYXML = new XMLList(xmlDoc), MYXML.hasComplexContent()));

xmlDoc = "<firstname>John</firstname>"
AddTestCase ("MYXML = new XML(xmlDoc), MYXML.children().length()", 1,
      (MYXML = new XML(xmlDoc), MYXML.children().length()));
AddTestCase ("MYXML = new XML(xmlDoc), MYXML.children()[0].nodeKind()", "text",
      (MYXML = new XML(xmlDoc), MYXML.children()[0].nodeKind()));
AddTestCase ("MYXML = new XML(xmlDoc), MYXML.children()[0].nodeKind()", "text",
      (MYXML = new XML(xmlDoc), MYXML.children()[0].nodeKind()));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.children()[0].hasSimpleContent()", true,
      (MYXML = new XML(xmlDoc), MYXML.children()[0].hasSimpleContent()));

XML.ignoreComments = false;
xmlDoc = "<XML><!-- firstname --></XML>"
AddTestCase ("MYXML = new XML(xmlDoc), MYXML.children().length()", 1,
      (MYXML = new XML(xmlDoc), MYXML.children().length()));
AddTestCase ("MYXML = new XML(xmlDoc), MYXML.children()[0].nodeKind()", "comment",
      (MYXML = new XML(xmlDoc), MYXML.children()[0].nodeKind()));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.children()[0].hasSimpleContent()", false,
      (MYXML = new XML(xmlDoc), MYXML.children()[0].hasSimpleContent()));

XML.ignoreProcessingInstructions = false;
xmlDoc = "<XML><?xml-stylesheet href=\"classic.xsl\" type=\"text/xml\"?></XML>"
AddTestCase ("MYXML = new XML(xmlDoc), MYXML.children().length()", 1,
      (MYXML = new XML(xmlDoc), MYXML.children().length()));
AddTestCase ("MYXML = new XML(xmlDoc), MYXML.children()[0].nodeKind()", "processing-instruction",
      (MYXML = new XML(xmlDoc), MYXML.children()[0].nodeKind()));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.children()[0].hasSimpleContent()", false,
      (MYXML = new XML(xmlDoc), MYXML.children()[0].hasSimpleContent()));

xmlDoc = "<XML a='5' b='c'>foo</XML>"
AddTestCase ("MYXML = new XML(xmlDoc), MYXML.children().length()", 1,
      (MYXML = new XML(xmlDoc), MYXML.children().length()));
AddTestCase ("MYXML = new XML(xmlDoc), MYXML.children()[0].nodeKind()", "text",
      (MYXML = new XML(xmlDoc), MYXML.children()[0].nodeKind()));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.children()[0].hasSimpleContent()", true,
      (MYXML = new XML(xmlDoc), MYXML.children()[0].hasSimpleContent()));
      
END();
