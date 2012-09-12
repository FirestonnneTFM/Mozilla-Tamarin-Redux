/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.3.6 - XML.prettyIndent");

// xml doc
XML.prettyPrinting = true;
var xmlDoc = "<XML><TEAM>Giants</TEAM><CITY>San Francisco</CITY><SPORT>Baseball</SPORT></XML>"


// a) value of prettyIndent
AddTestCase( "XML.prettyIndent = 4, XML.prettyIndent", 4, (XML.prettyIndent = 4, XML.prettyIndent));
AddTestCase( "XML.prettyIndent = 2, XML.prettyIndent", 2, (XML.prettyIndent = 2, XML.prettyIndent));
AddTestCase( "XML.prettyIndent = -1, XML.prettyIndent", -1, (XML.prettyIndent = -1, XML.prettyIndent));

// b) pretty printing

AddTestCase( "MYOB = new XML(xmlDoc); XML.prettyIndent = 2; MYOB.toString()",
            "<XML>" + NL() + "  <TEAM>Giants</TEAM>" + NL() + "  <CITY>San Francisco</CITY>" + NL() + "  <SPORT>Baseball</SPORT>" + NL() + "</XML>",
             (MYOB = new XML(xmlDoc), XML.prettyIndent = 2, MYOB.toString()));

AddTestCase( "MYOB = new XML(xmlDoc); XML.prettyIdent = 4; MYOB.toString()",
            "<XML>" + NL() + "    <TEAM>Giants</TEAM>" + NL() + "    <CITY>San Francisco</CITY>" + NL() + "    <SPORT>Baseball</SPORT>" + NL() + "</XML>",
             (MYOB = new XML(xmlDoc), XML.prettyIndent = 4, MYOB.toString()));

AddTestCase( "MYOB = new XML(xmlDoc); XML.prettyIndent = 1; MYOB.toString()",
            "<XML>" + NL() + " <TEAM>Giants</TEAM>" + NL() + " <CITY>San Francisco</CITY>" + NL() + " <SPORT>Baseball</SPORT>" + NL() + "</XML>",
             (MYOB = new XML(xmlDoc), XML.prettyIndent = 1, MYOB.toString()));

// !!@ bad value causes pretty printing to be disabled
AddTestCase( "MYOB = new XML(xmlDoc); XML.prettyIndent = -5; MYOB.toString()",
            "<XML><TEAM>Giants</TEAM><CITY>San Francisco</CITY><SPORT>Baseball</SPORT></XML>",
            //"<XML>" + NL() + "  <TEAM>Giants</TEAM>" + NL() + "  <CITY>San Francisco</CITY>" + NL() + "  <SPORT>Baseball</SPORT>" + NL() + "</XML>",
             (MYOB = new XML(xmlDoc), XML.prettyIndent = -5, MYOB.toString()));



// !!@ very simple example of printing output
XML.prettyPrinting = true;
XML.prettyIndent = 10;
AddTestCase( "MYOB = new XML(xmlDoc); XML.prettyPrinting = true; MYOB.toString()",
            "<XML>" + NL() + "          <TEAM>Giants</TEAM>" + NL() + "          <CITY>San Francisco</CITY>" + NL() + "          <SPORT>Baseball</SPORT>" + NL() + "</XML>",
             (MYOB = new XML(xmlDoc), XML.prettyPrinting = true, MYOB.toString()));


// d) attributes

XML.prettyIndent = 5;
xmlDoc = "<XML><TEAM attr1=\"attr\" attr2=\"hi\">Giants</TEAM><CITY>San Francisco</CITY><SPORT>Baseball</SPORT></XML>"
AddTestCase( "MYOB = new XML(xmlDoc); XML.prettyPrinting = true; MYOB.toString()",
            "<XML>" + NL() + "     <TEAM attr1=\"attr\" attr2=\"hi\">Giants</TEAM>" + NL() + "     <CITY>San Francisco</CITY>" + NL() + "     <SPORT>Baseball</SPORT>" + NL() + "</XML>",
             (MYOB = new XML(xmlDoc), XML.prettyPrinting = true, MYOB.toString()));


END();
