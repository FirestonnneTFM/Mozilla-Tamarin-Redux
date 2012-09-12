/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.9 - XMLList descendants()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("descendants"));
    
XML.prettyPrinting = false;

var xmlDoc = "<MLB><foo>bar</foo><Team>Giants<foo>bar</foo></Team><City><foo>bar</foo>San Francisco</City><Team>Padres</Team><City>San Diego</City></MLB>";

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.descendants('Team')", "<Team>Giants<foo>bar</foo></Team>" + NL() + "<Team>Padres</Team>",
             (MYXML = new XMLList(xmlDoc), MYXML.descendants('Team').toString()) );
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.descendants('Team').length()", 2,
             (MYXML = new XMLList(xmlDoc), MYXML.descendants('Team').length()) );
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.descendants('Team') instanceof XMLList", true,
             (MYXML = new XMLList(xmlDoc), MYXML.descendants('Team') instanceof XMLList) );

// find multiple levels of descendents
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.descendants('foo')", "<foo>bar</foo>" + NL() + "<foo>bar</foo>" + NL() + "<foo>bar</foo>",
             (MYXML = new XMLList(xmlDoc), MYXML.descendants('foo').toString()) );
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.descendants('foo').length()", 3,
             (MYXML = new XMLList(xmlDoc), MYXML.descendants('foo').length()) );
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.descendants('foo') instanceof XMLList", true,
             (MYXML = new XMLList(xmlDoc), MYXML.descendants('foo') instanceof XMLList) );

// no matching descendents
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.descendants('nomatch')", "",
             (MYXML = new XMLList(xmlDoc), MYXML.descendants('nomatch').toString()) );
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.descendants('nomatch').length()", 0,
             (MYXML = new XMLList(xmlDoc), MYXML.descendants('nomatch').length()) );
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.descendants('nomatch') instanceof XMLList", true,
             (MYXML = new XMLList(xmlDoc), MYXML.descendants('nomatch') instanceof XMLList) );

END();
