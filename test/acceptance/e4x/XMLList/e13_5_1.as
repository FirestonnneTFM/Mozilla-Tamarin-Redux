/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.1 - XMLList Constructor as Function");

x1 = XMLList();

TEST(1, "xml", typeof(x1));
TEST(2, true, x1 instanceof XMLList);

// Make sure it's not copied if it's an XMLList
x1 = new XMLList("<alpha>one</alpha><bravo>two</bravo>");


y1 = XMLList(x1);
TEST(3, x1 === y1, true);

x1 += <charlie>three</charlie>;
TEST(4, x1 === y1, false);

// Load from one XML type
x1 = XMLList(<alpha>one</alpha>);
TEST_XML(5, "<alpha>one</alpha>", x1);

// Load from Anonymous
x1 = XMLList(<><alpha>one</alpha><bravo>two</bravo></>);
correct = new XMLList();
correct += <alpha>one</alpha>;
correct += <bravo>two</bravo>;
TEST_XML(6, correct.toString(), x1);

// Load from Anonymous as string
x1 = XMLList(<><alpha>one</alpha><bravo>two</bravo></>);
correct = new XMLList();
correct += <alpha>one</alpha>;
correct += <bravo>two</bravo>;
TEST_XML(7, correct.toString(), x1);

// Load from single textnode
x1 = XMLList("foobar");
TEST_XML(8, "foobar", x1);

x1 = XMLList(7);
TEST_XML(9, "7", x1);

// Undefined and null should behave like ""
x1 = XMLList(null);
TEST_XML(10, "", x1);

x1 = XMLList(undefined);
TEST_XML(11, "", x1);

XML.prettyPrinting = false;

var thisXML = "<TEAM>Giants</TEAM><CITY>San Francisco</CITY>";

// value is null
AddTestCase( "XMLList(null).toString()", "", XMLList(null).toString() );
AddTestCase( "typeof XMLList(null)", "xml", typeof XMLList(null) );
AddTestCase( "XMLList(null) instanceof XMLList", true, XMLList(null) instanceof XMLList);

// value is undefined
AddTestCase( "XMLList(undefined).toString()", "", XMLList(undefined).toString() );
AddTestCase( "typeof XMLList(undefined)", "xml", typeof XMLList(undefined) );
AddTestCase( "XMLList(undefined) instanceof XMLList", true, XMLList(undefined) instanceof XMLList);

// value is not supplied
AddTestCase( "XMLList().toString()", "", XMLList().toString() );
AddTestCase( "typeof XMLList()", "xml", typeof XMLList() );
AddTestCase( "XMLList() instanceof XMLList", true, XMLList() instanceof XMLList);

// value is supplied (string)
AddTestCase( "XMLList(thisXML).toString()",
    "<TEAM>Giants</TEAM>" + NL() + "<CITY>San Francisco</CITY>",
    XMLList(thisXML).toString() );
AddTestCase( "typeof XMLList(thisXML)", "xml", typeof XMLList(thisXML) );

// value is supplied (xmlList)
var xl = new XMLList ("<foo>bar></foo><foo2>bar></foo2>");
AddTestCase( "XMLList(xl) === xl", true, XMLList(xl) === xl);

// value is supplied (xml)
var x1 = new XML ("<foo>bar></foo>");
AddTestCase( "XMLList(x1).length()", 1, XMLList(x1).length());
AddTestCase( "XMLList(x1).contains(x1)", true, XMLList(x1)[0].contains(x1));

END();
