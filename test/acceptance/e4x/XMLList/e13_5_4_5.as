/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.5 - XMLList children()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("children"));

// Test with XMLList of size 0
x1 = new XMLList()
TEST(2, "xml", typeof(x1.children()));
TEST_XML(3, "", x1.children());

// Test with XMLList of size 1
x1 += <alpha>one<bravo>two</bravo></alpha>;
TEST(4, "xml", typeof(x1.children()));

correct = <>one<bravo>two</bravo></>;
TEST(5, correct, x1.children());

// Test with XMLList of size > 1
x1 += <charlie><bravo>three</bravo></charlie>;
TEST(6, "xml", typeof(x1.children()));

correct = <>one<bravo>two</bravo><bravo>three</bravo></>;
TEST(7, correct, x1.children());

// Test no children
x1 = new XMLList();
x1 += <alpha></alpha>;
x1 += <bravo></bravo>;
TEST(8, "xml", typeof(x1.children()));
TEST_XML(9, "", x1.children());

//get all grandchildren of the order that have the name price

order =
<order>
    <customer>
        <name>John Smith</name>
    </customer>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
</order>;

correct= <price>1299.99</price> + <price>399.99</price>;

TEST(10, correct, order.children().price);

var xmlDoc = "<employee id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee><employee id=\"2\"><firstname>Sue</firstname><lastname>Day</lastname><age>32</age></employee>"

// propertyName as a string
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.children()",
        "<firstname>John</firstname>" + NL() + "<lastname>Walton</lastname>" + NL() + "<age>25</age>" + NL() + "<firstname>Sue</firstname>" + NL() + "<lastname>Day</lastname>" + NL() + "<age>32</age>",
        (MYXML = new XMLList(xmlDoc), MYXML.children().toString()));

END();
