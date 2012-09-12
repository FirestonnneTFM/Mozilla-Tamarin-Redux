/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.21 - XML localName()");

//TEST(1, true, XML.prototype.hasOwnProperty("localName"));

x1 = new XML("<alpha><bravo>one</bravo><charlie><bravo>two</bravo></charlie></alpha>");
var y1;
y1 = x1.localName();
TEST(2, "string", typeof(y1));
TEST(3, "alpha", y1);

y1 = x1.bravo.localName();
x1.bravo.setNamespace("http://someuri");
TEST(4, "bravo", y1);

x1 =
<foo:alpha xmlns:foo="http://foo/">
    <foo:bravo name="bar" foo:value="one">one</foo:bravo>
</foo:alpha>;

ns = new Namespace("http://foo/");
y1 = x1.ns::bravo.localName();
TEST(5, "string", typeof(y1));
TEST(6, "bravo", y1);

y1 = x1.ns::bravo.@name.localName();
TEST(7, "name", y1);

y1 = x1.ns::bravo.@ns::value.localName();
TEST(8, "value", y1);

var xmlDoc = "<company xmlns:printer='http://colors.com/printer/'><printer:employee id='1'><name>John</name> <city>California</city> </printer:employee></company>";

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.localName()",
    "company",
    (MYXML = new XML(xmlDoc), MYXML.localName()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.localName() instanceof QName",
    false,
    (MYXML = new XML(xmlDoc), MYXML.localName() instanceof QName));

// !!@ fails in Rhino??
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.localName() instanceof String",
    true,
    (MYXML = new XML(xmlDoc), MYXML.localName() instanceof String));

AddTestCase( "MYXML = new XML(xmlDoc), typeof(MYXML.localName())",
    "string",
    (MYXML = new XML(xmlDoc), typeof(MYXML.localName())));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.children()[0].localName()",
    "employee",
    (MYXML = new XML(xmlDoc), MYXML.children()[0].localName()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.children()[0].localName() instanceof QName",
    false,
    (MYXML = new XML(xmlDoc), MYXML.children()[0].localName() instanceof QName));

// !!@ fails in Rhino??
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.children()[0].localName() instanceof String",
    true,
    (MYXML = new XML(xmlDoc), MYXML.children()[0].localName() instanceof String));

AddTestCase( "MYXML = new XML(xmlDoc), typeof(MYXML.children()[0].localName())",
    "string",
    (MYXML = new XML(xmlDoc), typeof(MYXML.children()[0].localName())));

END();
