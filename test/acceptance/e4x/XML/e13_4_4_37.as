/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.37 - XML text()");

//TEST(1, true, XML.prototype.hasOwnProperty("text"));

x1 =
<alpha>
    <bravo>one</bravo>
    <charlie>
        <bravo>two</bravo>
    </charlie>
</alpha>;

TEST_XML(2, "one", x1.bravo.text());

correct = new XMLList();
correct += new XML("one");
correct += new XML("two");
TEST(3, correct, x1..bravo.text());
TEST_XML(4, "", x1.charlie.text());
TEST_XML(5, "", x1.foobar.text());
TEST_XML(6, "one", x1.*.text());

XML.prettyPrinting = false;
var xmlDoc = "<employee id='1'>foo<firstname>John</firstname>bar<lastname>Walton</lastname>still<age>25</age>reading</employee>"

// propertyName as a string
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.text().toString()",
    "foobarstillreading",
    (MYXML = new XML(xmlDoc), MYXML.text().toString()));
    
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.text() instanceof XMLList",
    true,
    (MYXML = new XML(xmlDoc), MYXML.text() instanceof XMLList));

AddTestCase( "MYXML = new XML('<XML></XML>'), MYXML.text().toString()",
    "",
    (MYXML = new XML('<XML></XML>'), MYXML.text().toString()));
    
AddTestCase( "MYXML = new XML('<XML></XML>'), MYXML.text() instanceof XMLList",
    true,
    (MYXML = new XML('<XML></XML>'), MYXML.text() instanceof XMLList));
    
xmlDoc = <a>b</a>;

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.text().toString()",
    "b",
    (MYXML = new XML(xmlDoc), MYXML.text().toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.text().toString()",
    "b",
    (MYXML = new XML(xmlDoc), MYXML.setName('c'), MYXML.text().toString()));

END();
