/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.28 - processingInsructions()");

//TEST(1, true, XML.prototype.hasOwnProperty("processingInstructions"));

XML.ignoreProcessingInstructions = false;

// test generic PI
var x1 = new XML("<alpha><?xyz abc=\"123\" michael=\"weird\"?><?another name=\"value\" ?><bravo>one</bravo></alpha>");

var correct = new XMLList("<?xyz abc=\"123\" michael=\"weird\"?><?another name=\"value\" ?>");

TEST(2, correct, x1.processingInstructions());
TEST(3, correct, x1.processingInstructions("*"));

correct = "<?xyz abc=\"123\" michael=\"weird\"?>";

TEST_XML(4, correct, x1.processingInstructions("xyz"));

// test XML-decl
// Un-comment these tests when we can read in doc starting with PI.
x1 = new XML("<?xml version=\"1.0\" ?><alpha><bravo>one</bravo></alpha>");

correct = new XMLList("<?xml version=\"1.0\" encoding=\"utf-8\"?>");

test(5, correct, x1.processingInstructions());
test(6, correct, x1.processingInstructions("*"));
test(7, correct, x1.processingInstructions("xml"));

// extra whitespace is on purpose for <?foo              bar> at the end of this string
var xmlDoc = "<?xml version='1.0'?><xml><?xml-stylesheet href='mystyle.xsl'?><employee id='1'><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee> <employee id='2'><firstname>Sue</firstname><lastname>Day</lastname><age>32</age><?child-xml bar?></employee><?foo              bar?></xml>"

// propertyName as a string
XML.ignoreProcessingInstructions = true;

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.processingInstructions().toString()", "",
             (MYXML = new XML(xmlDoc), MYXML.processingInstructions().toString()));

XML.ignoreProcessingInstructions = false;

AddTestCase( "ignorePI = false, MYXML = new XML(xmlDoc), MYXML.processingInstructions().toString()",
             "<?xml-stylesheet href='mystyle.xsl'?>\n<?foo bar?>",
             (MYXML = new XML(xmlDoc), MYXML.processingInstructions().toXMLString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.processingInstructions('*')",
    "<?xml-stylesheet href='mystyle.xsl'?>\n<?foo bar?>",
    (MYXML = new XML(xmlDoc), MYXML.processingInstructions("*").toXMLString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.processingInstructions('xml-stylesheet')",
    "<?xml-stylesheet href='mystyle.xsl'?>",
    (MYXML = new XML(xmlDoc), MYXML.processingInstructions("xml-stylesheet").toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.processingInstructions(new QName('xml-stylesheet'))",
    "<?xml-stylesheet href='mystyle.xsl'?>",
    (MYXML = new XML(xmlDoc), MYXML.processingInstructions(new QName("xml-stylesheet")).toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.processingInstructions(new QName('foo'))",
    "<?foo bar?>",
    (MYXML = new XML(xmlDoc), MYXML.processingInstructions(new QName("foo")).toString()));

// Attribute name does not match
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.processingInstructions('@xml-stylesheet')",
    "",
    (MYXML = new XML(xmlDoc), MYXML.processingInstructions("@xml-stylesheet").toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.processingInstructions('xml-foo')",
    "",
    (MYXML = new XML(xmlDoc), MYXML.processingInstructions("xml-foo").toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.processingInstructions('child-xml')",
    "",
    (MYXML = new XML(xmlDoc), MYXML.processingInstructions("child-xml").toString()));

END();
