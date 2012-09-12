/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.6 - XMLList comments()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("comments"));

// !!@ very strange that this does find comments in the list but only in elements of the list

var xmlDoc = "<!-- This is Comment --><employee id='1'><!-- This is another Comment --><name>John</name> <city>California</city> </employee><!-- me too -->";

XML.prettyPrinting = true;
XML.ignoreComments = false;
AddTestCase( "XML.ignoreComments = false, MYXML = new XMLList(xmlDoc), MYXML.comments().toString()",
    "<!-- This is another Comment -->",
    (XML.ignoreComments = false, MYXML = new XMLList(xmlDoc), MYXML.comments().toString()));
AddTestCase( "XML.ignoreComments = false, MYXML = new XMLList(xmlDoc), MYXML.comments() instanceof XMLList", true, (MYXML = new XMLList(xmlDoc), MYXML.comments() instanceof XMLList));
AddTestCase( "XML.ignoreComments = false, MYXML = new XMLList(xmlDoc), MYXML.comments() instanceof XML", false, (MYXML = new XMLList(xmlDoc), MYXML.comments() instanceof XML));
AddTestCase( "XML.ignoreComments = false, MYXML = new XMLList(xmlDoc), MYXML.comments().length()", 1, (MYXML = new XMLList(xmlDoc), MYXML.comments().length() ));

AddTestCase( "XML.ignoreComments = false, MYXML = new XMLList(xmlDoc), XML.ignoreComments = true, MYXML.comments().toString()",
    "<!-- This is another Comment -->",
    (XML.ignoreComments = false, MYXML = new XMLList(xmlDoc), XML.ignoreComments = true, MYXML.comments().toString()));

END();
