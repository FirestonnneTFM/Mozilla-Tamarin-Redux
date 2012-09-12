/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.3.4 - XML.ignoreWhitespace");

// We set this to false so we can more easily compare string output
XML.prettyPrinting = false;

// xml doc with white space
var xmlDoc = "<XML>  <TEAM>Giants</TEAM>\u000D<CITY>San\u0020Francisco</CITY>\u000A<SPORT>Baseball</SPORT>\u0009</XML>"


// a) value of ignoreWhitespace
AddTestCase( "XML.ignoreWhitespace = false, XML.ignoreWhitespace", false, (XML.ignoreWhitespace = false, XML.ignoreWhitespace));
AddTestCase( "XML.ignoreWhitespace = true, XML.ignoreWhitespace", true, (XML.ignoreWhitespace = true, XML.ignoreWhitespace));


// b) whitespace is ignored when true, not ignored when false
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.toString()", "<XML><TEAM>Giants</TEAM><CITY>San Francisco</CITY><SPORT>Baseball</SPORT></XML>",
             (XML.ignoreWhitespace = true, MYXML = new XML(xmlDoc), MYXML.toString() ));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.toString() with ignoreWhitespace=false",
        "<XML>  <TEAM>Giants</TEAM>\u000D<CITY>San\u0020Francisco</CITY>\u000A<SPORT>Baseball</SPORT>\u0009</XML>",
        (XML.ignoreWhitespace = false, MYXML = new XML(xmlDoc), MYXML.toString() ));

// c) whitespace characters
// tab
xmlDoc = "<a>\t<b>tab</b></a>";
AddTestCase( "XML with tab and XML.ignoreWhiteSpace = true", "<a><b>tab</b></a>",
           (XML.ignoreWhitespace = true, MYXML = new XML(xmlDoc), MYXML.toString() ));

AddTestCase( "XML with tab and XML.ignoreWhiteSpace = false", "<a>\t<b>tab</b></a>",
           (XML.ignoreWhitespace = false, MYXML = new XML(xmlDoc), MYXML.toString() ));

// new line
xmlDoc = "<a>\n<b>\n\ntab</b>\n</a>";
AddTestCase( "XML with new line and XML.ignoreWhiteSpace = true", "<a><b>tab</b></a>",
           (XML.ignoreWhitespace = true, MYXML = new XML(xmlDoc), MYXML.toString() ));

xmlDoc = "<a>\r\n<b>tab</b>\r\n</a>";
AddTestCase( "XML with new line and XML.ignoreWhiteSpace = false", "<a>\r\n<b>tab</b>\r\n</a>",
           (XML.ignoreWhitespace = false, MYXML = new XML(xmlDoc), MYXML.toString() ));

// d) attributes

xmlDoc = "<a><b      attr=\"1      2\">tab</b></a>";
AddTestCase( "new XML(\"<a><a><b      attr='1      2'>tab</b></a>\")", "<a><b attr=\"1      2\">tab</b></a>",
           (XML.ignoreWhitespace = true, MYXML = new XML(xmlDoc), MYXML.toString() ));
           
AddTestCase( "new XML(\"<a><a><b      attr='1      2'>tab</b></a>\")", "<a><b attr=\"1      2\">tab</b></a>",
           (XML.ignoreWhitespace = false, MYXML = new XML(xmlDoc), MYXML.toString() ));


END();
