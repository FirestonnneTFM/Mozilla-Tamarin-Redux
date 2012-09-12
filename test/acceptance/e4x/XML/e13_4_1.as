/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.1 - XML Constructor as Function");

x1 = XML();
TEST(1, "xml", typeof(x1));
TEST(2, true, x1 instanceof XML);

correct =
<Envelope
    xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/"
    xmlns:stock="http://mycompany.com/stocks"
    soap:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">
    <Body>
        <stock:GetLastTradePrice>
            <stock:symbol>DIS</stock:symbol>
        </stock:GetLastTradePrice>
    </Body>
</Envelope>;

x1 = XML(correct);
TEST(3, correct, x1);

text =
"<Envelope" +
"    xmlns:soap=\"http://schemas.xmlsoap.org/soap/envelope/\"" +
"    xmlns:stock=\"http://mycompany.com/stocks\"" +
"    soap:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\">" +
"    <Body>" +
"        <stock:GetLastTradePrice>" +
"            <stock:symbol>DIS</stock:symbol>" +
"        </stock:GetLastTradePrice>" +
"    </Body>" +
"</Envelope>";

x1 =  XML(text);
TEST(4, correct, x1);

// Make sure it's not copied if it's XML
x1 =
<alpha>
    <bravo>two</bravo>
</alpha>;

y1 = XML(x1);

x1.bravo = "three";

correct =
<alpha>
    <bravo>three</bravo>
</alpha>;

TEST(5, correct, y1);

// Make text node
x1 = XML("4");
TEST_XML(6, 4, x1);

x1 = XML(4);
TEST_XML(7, 4, x1);
 
// Undefined and null should behave like ""
x1 = XML(null);
TEST_XML(8, "", x1);

x1 = XML(undefined);
TEST_XML(9, "", x1);
  
XML.prettyPrinting = false;

var thisXML = "<XML><TEAM>Giants</TEAM><CITY>San Francisco</CITY></XML>";
var NULL_OBJECT = null;
// value is null
AddTestCase( "XML(null).valueOf().toString()", "", XML(null).valueOf().toString() );
AddTestCase( "typeof XML(null)", "xml", typeof XML(null) );

// value is undefined
AddTestCase( "XML(undefined).valueOf().toString()", "", XML(undefined).valueOf().toString() );
AddTestCase( "typeof XML(undefined)", "xml", typeof XML(undefined) );

// value is not supplied
AddTestCase( "XML().valueOf().toString()", "", XML().valueOf().toString() );
AddTestCase( "typeof XML()", "xml", typeof XML() );

// value is supplied
AddTestCase( "XML(thisXML).valueOf().toString()", thisXML, XML(thisXML).valueOf().toString() );
AddTestCase( "typeof XML(thisXML)", "xml", typeof XML(thisXML) );

END();
