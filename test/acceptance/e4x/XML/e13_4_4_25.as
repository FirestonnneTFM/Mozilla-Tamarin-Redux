/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.25 - XML nodeKind()");

//TEST(1, true, XML.prototype.hasOwnProperty("nodeKind"));

x1 =
<alpha attr1="value1">
    <bravo>one</bravo>
</alpha>;

TEST(2, "element", x1.bravo.nodeKind());
TEST(3, "attribute", x1.@attr1.nodeKind());

// Non-existant node type is text
x1 = new XML();
TEST(4, "text", x1.nodeKind());
//TEST(5, "text", XML.prototype.nodeKind());

var xmlDoc = "<company><employee id='1'><name1>John</name1> <city>California</city> </employee></company>";


AddTestCase( "MYXML = new XML(xmlDoc), MYXML.nodeKind()",
    "element",
    (MYXML = new XML(xmlDoc), MYXML.nodeKind()));

AddTestCase( "MYXML = new XML(null), MYXML.nodeKind()",
    "text",
    (MYXML = new XML(null), MYXML.nodeKind()));

AddTestCase( "MYXML = new XML(undefined), MYXML.nodeKind()",
    "text",
    (MYXML = new XML(undefined), MYXML.nodeKind()));

AddTestCase( "MYXML = new XML(), MYXML.nodeKind()",
    "text",
    (MYXML = new XML(), MYXML.nodeKind()));

AddTestCase( "MYXML = new XML(), MYXML.children()[0].nodeKind()",
    "element",
    (MYXML = new XML(xmlDoc), MYXML.children()[0].nodeKind()));

AddTestCase( "MYXML = new XML(), MYXML.children()[0].attributes()[0].nodeKind()",
    "attribute",
    (MYXML = new XML(xmlDoc), MYXML.children()[0].attributes()[0].nodeKind()));

AddTestCase( "MYXML = new XML(), MYXML.children()[0].name1.children()[0].nodeKind()",
    "text",
    (MYXML = new XML(xmlDoc), MYXML.children()[0].name1.children()[0].nodeKind()));

XML.ignoreComments = false
AddTestCase( "MYXML = new XML(\"<!-- this is a comment -->\"), MYXML.nodeKind()",
    "element",
    (MYXML = new XML("<XML><!-- this is a comment --></XML>"), MYXML.nodeKind()));

AddTestCase( "MYXML = new XML(\"<!-- this is a comment -->\"), MYXML.children()[0].nodeKind()",
    "comment",
    (MYXML = new XML("<XML><!-- this is a comment --></XML>"), MYXML.children()[0].nodeKind()));

XML.ignoreProcessingInstructions = false
AddTestCase( "MYXML = new XML(\"<XML><?foo this is a pi ?></XML>\"), MYXML.nodeKind()",
    "element",
    (MYXML = new XML("<XML><?foo-- this is a pi--?></XML>"), MYXML.nodeKind()));

AddTestCase( "MYXML = new XML(\"<XML><?foo this is a pi ?></XML>\"), MYXML.children()[0].nodeKind()",
    "processing-instruction",
    (MYXML = new XML("<XML><?foo this is a pi ?></XML>"), MYXML.children()[0].nodeKind()));


END();
