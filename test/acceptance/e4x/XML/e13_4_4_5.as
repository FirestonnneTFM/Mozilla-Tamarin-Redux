/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.5 - XML attributes()");

//TEST(1, true, XML.prototype.hasOwnProperty("attributes"));

x1 =
<alpha attr1="value1" attr2="value2" attr3="value3">
    <bravo>one</bravo>
</alpha>;

TEST(2, "xml", typeof(x1.attributes()));

// Iterate through the attributes of an XML value
x1 =
<alpha attr1="value1" attr2="value2" attr3="value3">
    <bravo>one</bravo>
</alpha>;

correct = new Array("value1", "value2", "value3");
i = 0;

for each (var a in x1.attributes())
{
    TEST_XML(i + 3, correct[i], a);
    i++;
}

var xmlDoc = "<TEAM foo = 'bar' two='second'>Giants</TEAM>";

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attributes() instanceof XMLList", true,
             (MYXML = new XML(xmlDoc), MYXML.attributes() instanceof XMLList ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attributes() instanceof XML", false,
             (MYXML = new XML(xmlDoc), MYXML.attributes() instanceof XML ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attributes().length()", 2,
             (MYXML = new XML(xmlDoc), MYXML.attributes().length() ));
XML.prettyPrinting = false;
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attributes().toString()", "barsecond",
             (MYXML = new XML(xmlDoc), MYXML.attributes().toString() ));
XML.prettyPrinting = true;
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attributes().toString()", "barsecond",
             (MYXML = new XML(xmlDoc), MYXML.attributes().toString() ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attributes()[0].nodeKind()", "attribute",
             (MYXML = new XML(xmlDoc), MYXML.attributes()[0].nodeKind() ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.attributes()[1].nodeKind()", "attribute",
             (MYXML = new XML(xmlDoc), MYXML.attributes()[1].nodeKind() ));

END();
