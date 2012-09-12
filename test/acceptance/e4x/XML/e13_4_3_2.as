/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.3.2 - XML.ignoreComments");

var thisXML = "<XML><!--comment1--><TEAM>Giants</TEAM><CITY>San Francisco</CITY><!--comment2--></XML>"

XML.prettyPrinting = false;

// a) initial value of ignoreComments is true

AddTestCase( "XML.ignoreComments", true, XML.ignoreComments);

// toggling value works ok
AddTestCase( "XML.ignoreComments = false, XML.ignoreComments", false, (XML.ignoreComments = false, XML.ignoreComments));
AddTestCase( "XML.ignoreComments = true, XML.ignoreComments", true, (XML.ignoreComments = true, XML.ignoreComments));

// b) if ignoreComments is true, XML comments are ignored when construction the new XML objects
AddTestCase( "MYXML = new XML(thisXML), MYXML.toString()", "<XML><TEAM>Giants</TEAM><CITY>San Francisco</CITY></XML>",
             (XML.ignoreComments = true, MYXML = new XML(thisXML), MYXML.toString() ));
AddTestCase( "MYXML = new XML(thisXML), MYXML.toString() with ignoreComemnts=false", "<XML><!--comment1--><TEAM>Giants</TEAM><CITY>San Francisco</CITY><!--comment2--></XML>",
             (XML.ignoreComments = false, MYXML = new XML(thisXML), MYXML.toString() ));

// If ignoreComments is true, XML constructor from another XML node ignores comments
XML.ignoreComments = false;
var MYXML = new XML(thisXML); // this XML node has comments
XML.ignoreComments = true;
var xml2 = new XML(MYXML); // this XML tree should not have comments
AddTestCase( "xml2 = new XML(MYXML), xml2.toString()", "<XML><TEAM>Giants</TEAM><CITY>San Francisco</CITY></XML>",
             (xml2.toString()) );
XML.ignoreComments = false;
var xml3 = new XML(MYXML); // this XML tree will have comments
AddTestCase( "xml3 = new XML(MYXML), xml3.toString()", "<XML><!--comment1--><TEAM>Giants</TEAM><CITY>San Francisco</CITY><!--comment2--></XML>",
             (xml3.toString()) );


// c) two attributes { DontEnum, DontDelete }
// !!@


END();
