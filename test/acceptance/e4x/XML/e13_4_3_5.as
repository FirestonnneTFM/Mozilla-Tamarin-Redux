/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.3.5 - XML.prettyPrinting");

// xml doc
var xmlDoc = "<XML><TEAM>Giants</TEAM><CITY>San Francisco</CITY><SPORT>Baseball</SPORT></XML>"


// a) value of prettyPrinting
AddTestCase( "XML.prettyPrinting = false, XML.prettyPrinting", false, (XML.prettyPrinting = false, XML.prettyPrinting));
AddTestCase( "XML.prettyPrinting = true, XML.prettyPrinting", true, (XML.prettyPrinting = true, XML.prettyPrinting));

// b) pretty printing

AddTestCase( "MYOB = new XML(xmlDoc); XML.prettyPrinting = false; MYOB.toString()",
            "<XML><TEAM>Giants</TEAM><CITY>San Francisco</CITY><SPORT>Baseball</SPORT></XML>",
             (MYOB = new XML(xmlDoc), XML.prettyPrinting = false, MYOB.toString()));

// !!@ very simple example of printing output

AddTestCase( "MYOB = new XML(xmlDoc); XML.prettyPrinting = true; MYOB.toString()",
            "<XML>" + NL() + "  <TEAM>Giants</TEAM>" + NL() + "  <CITY>San Francisco</CITY>" + NL() + "  <SPORT>Baseball</SPORT>" + NL() + "</XML>",
             (MYOB = new XML(xmlDoc), XML.prettyPrinting = true, MYOB.toString()));


// c) attributes

// TODO

END();
