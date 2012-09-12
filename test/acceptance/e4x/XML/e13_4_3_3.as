/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.3.3 - XML.ignoreProcessingInstructions");

// We set this to false so we can more easily compare string output
XML.prettyPrinting = false;

// xml string with processing instructions
var xmlDoc = "<?xml version=\"1.0\"?><XML><?xml-stylesheet href=\"classic.xsl\" type=\"text/xml\"?><TEAM>Giants</TEAM><CITY>San Francisco</CITY></XML>"

// a) value of ignoreProcessingInstructions
AddTestCase ("XML.ignoreProcessingInstructions", true, (XML.ignoreProcessingInstructions));
AddTestCase( "XML.ignoreProcessingInstructions = false, XML.ignoreProcessingInstructions", false, (XML.ignoreProcessingInstructions = false, XML.ignoreProcessingInstructions));
AddTestCase( "XML.ignoreProcessingInstructions = true, XML.ignoreProcessingInstructions", true, (XML.ignoreProcessingInstructions = true, XML.ignoreProcessingInstructions));

// b) if ignoreProcessingInstructions is true, XML processing instructions are ignored when construction the new XML objects
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.toString()", "<XML><TEAM>Giants</TEAM><CITY>San Francisco</CITY></XML>",
             (XML.ignoreProcessingInstructions = true, MYXML = new XML(xmlDoc), MYXML.toString() ));
             
// !!@ note that the "<?xml version=\"1.0\"?>" tag magically disappeared.
             
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.toString() with ignoreProcessingInstructions=false",
        "<XML><?xml-stylesheet href=\"classic.xsl\" type=\"text/xml\"?><TEAM>Giants</TEAM><CITY>San Francisco</CITY></XML>",
        (XML.ignoreProcessingInstructions = false, MYXML = new XML(xmlDoc), MYXML.toString() ));


// If ignoreProcessingInstructions is true, XML constructor from another XML node ignores processing instructions
XML.ignoreProcessingInstructions = false;
var MYXML = new XML(xmlDoc); // this XML node has processing instructions
XML.ignoreProcessingInstructions = true;
var xml2 = new XML(MYXML); // this XML tree should not have processing instructions
AddTestCase( "xml2 = new XML(MYXML), xml2.toString()", "<XML><TEAM>Giants</TEAM><CITY>San Francisco</CITY></XML>",
             (xml2.toString()) );
XML.ignoreProcessingInstructions = false;
var xml3 = new XML(MYXML); // this XML tree will have processing instructions
AddTestCase( "xml3 = new XML(MYXML), xml3.toString()",
        "<XML><?xml-stylesheet href=\"classic.xsl\" type=\"text/xml\"?><TEAM>Giants</TEAM><CITY>San Francisco</CITY></XML>",
             (xml3.toString()) );


END();
