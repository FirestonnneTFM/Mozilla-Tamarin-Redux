/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.34 - XML setLocalName()");

//TEST(1, true, XML.prototype.hasOwnProperty("setLocalName"));

x1 =
<alpha>
    <bravo>one</bravo>
</alpha>;

correct =
<charlie>
    <bravo>one</bravo>
</charlie>;

x1.setLocalName("charlie");

TEST(2, correct, x1);

x1 =
<ns:alpha xmlns:ns="http://foobar/">
    <ns:bravo>one</ns:bravo>
</ns:alpha>;

correct =
<ns:charlie xmlns:ns="http://foobar/">
    <ns:bravo>one</ns:bravo>
</ns:charlie>;

x1.setLocalName("charlie");

TEST(3, correct, x1);

XML.prettyPrinting = false;
var xmlDoc = "<employee id='1'><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee>"

// propertyName as a string
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.setLocalName('newlocalname'),MYXML.localName()",
    "newlocalname",
    (MYXML = new XML(xmlDoc), MYXML.setLocalName('newlocalname'),MYXML.localName()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.setLocalName('newlocalname'),MYXML.toString()",
    "<newlocalname id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></newlocalname>",
    (MYXML = new XML(xmlDoc), MYXML.setLocalName('newlocalname'),MYXML.toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.setLocalName(new QName('newlocalname')),MYXML.toString()",
    "<newlocalname id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></newlocalname>",
    (MYXML = new XML(xmlDoc), MYXML.setLocalName(QName('newlocalname')),MYXML.toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.setLocalName(new QName('foo', 'newlocalname')),MYXML.toString()",
    "<newlocalname id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></newlocalname>",
    (MYXML = new XML(xmlDoc), MYXML.setLocalName(QName('foo', 'newlocalname')),MYXML.toString()));

MYXML = new XML(xmlDoc);

try {
    MYXML.setLocalName('@newlocalname');
    result = "no error";
} catch (e1) {
    result = typeError(e1.toString());
}

AddTestCase( "setLocalName('@newlocalname')", "TypeError: Error #1117", result);


try {
    MYXML.setLocalName('*');
    result = "no error";
} catch (e2) {
    result = typeError(e2.toString());
}

AddTestCase( "setLocalName('*')", "TypeError: Error #1117", result);

try {
    MYXML.setLocalName('x123=5');
    result = "no error";
} catch (e3) {
    result = typeError(e3.toString());
}

AddTestCase( "setLocalName('x123=5')", "TypeError: Error #1117", result);

try {
    MYXML.setLocalName('123');
    result = "no error";
} catch (e4) {
    result = typeError(e4.toString());
}

AddTestCase( "setLocalName('123')", "TypeError: Error #1117", result);

try {
    MYXML.setLocalName('!bam');
    result = "no error";
} catch (e5) {
    result = typeError(e5.toString());
}

AddTestCase( "setLocalName('!bam')", "TypeError: Error #1117", result);

END();
