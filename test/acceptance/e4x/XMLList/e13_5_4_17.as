/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.17 - XMLList processingInstructions()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("processingInstructions"));

// extra whitespace is on purpose for <?foo              bar> at the end of this string
 var xmlDoc = "<?xml version='1.0'?><xml><?xml-stylesheet href='mystyle.xsl'?><employee id='1'><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee> <employee id='2'><firstname>Sue</firstname><lastname>Day</lastname><age>32</age><?child-xml bar?></employee><?foo              bar?></xml>";
 
 XML.ignoreProcessingInstructions = true;
 AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.processingInstructions().toString()", "",
              (MYXML = new XMLList(xmlDoc), MYXML.processingInstructions().toXMLString()));
 
 XML.ignoreProcessingInstructions = false;

 AddTestCase( "ignorePI = false, MYXML = new XMLList(xmlDoc), MYXML.processingInstructions().toString()",
             "<?xml-stylesheet href='mystyle.xsl'?>\n<?foo bar?>",
              (MYXML = new XMLList(xmlDoc), MYXML.processingInstructions().toXMLString()));
 
 AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.processingInstructions('*')",
    "<?xml-stylesheet href='mystyle.xsl'?>\n<?foo bar?>",
    (MYXML = new XMLList(xmlDoc), MYXML.processingInstructions("*").toXMLString()));
 
 AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.processingInstructions('xml-stylesheet')",
    "<?xml-stylesheet href='mystyle.xsl'?>",
    (MYXML = new XMLList(xmlDoc), MYXML.processingInstructions("xml-stylesheet").toString()));

 AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.processingInstructions(new QName('xml-stylesheet'))",
    "<?xml-stylesheet href='mystyle.xsl'?>",
    (MYXML = new XMLList(xmlDoc), MYXML.processingInstructions(new QName("xml-stylesheet")).toString()));
 
 AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.processingInstructions(new QName('foo'))",
    "<?foo bar?>",
    (MYXML = new XMLList(xmlDoc), MYXML.processingInstructions(new QName("foo")).toString()));
 
 // Attribute name does not match
 AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.processingInstructions('@xml-stylesheet')",
    "",
    (MYXML = new XMLList(xmlDoc), MYXML.processingInstructions("@xml-stylesheet").toString()));
 
 AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.processingInstructions('xml-foo')",
    "",
    (MYXML = new XMLList(xmlDoc), MYXML.processingInstructions("xml-foo").toString()));
 
 AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.processingInstructions('child-xml')",
    "",
    (MYXML = new XMLList(xmlDoc), MYXML.processingInstructions("child-xml").toString()));

END();
