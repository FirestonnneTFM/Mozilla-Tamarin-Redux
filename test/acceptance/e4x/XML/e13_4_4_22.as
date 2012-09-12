/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.22 - XML name()");

//TEST(1, true, XML.prototype.hasOwnProperty("name"));

x1 =
<alpha>
    <bravo>one</bravo>
    <charlie>
        <bravo>two</bravo>
    </charlie>
</alpha>;

y1 = x1.bravo.name();

TEST(2, "object", typeof(y1));
TEST(3, QName("bravo"), y1);

x1 =
<foo:alpha xmlns:foo="http://foo/">
    <foo:bravo name="one" foo:value="two">one</foo:bravo>
</foo:alpha>;

ns = new Namespace("http://foo/");
y1 = x1.ns::bravo.name();

TEST(4, "object", typeof(y1));
TEST(5, QName("http://foo/", "bravo"), y1);

y1 = x1.ns::bravo.@name.name();
TEST(6, QName("name"), y1);

y1 = x1.ns::bravo.@ns::value.name();
TEST(7, "http://foo/", y1.uri);
TEST(8, "value", y1.localName);
TEST(9, QName("http://foo/", "value"), y1);

var xmlDoc = "<company xmlns:printer='http://colors.com/printer/'><printer:employee id='1'><name>John</name> <city>California</city> </printer:employee></company>";

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.name()",
    new QName("company"),
    (MYXML = new XML(xmlDoc), MYXML.name()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.name() instanceof QName",
    true,
    (MYXML = new XML(xmlDoc), MYXML.name() instanceof QName));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.name().toString()",
    "company",
    (MYXML = new XML(xmlDoc), MYXML.name().toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.children()[0].name()",
    new QName("http://colors.com/printer/", "employee"),
    (MYXML = new XML(xmlDoc), MYXML.children()[0].name()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.children()[0].name() instanceof QName",
    true,
    (MYXML = new XML(xmlDoc), MYXML.children()[0].name() instanceof QName));
    
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.children()[0].name().toString()",
    "http://colors.com/printer/::employee",
    (MYXML = new XML(xmlDoc), MYXML.children()[0].name().toString()));

END();
