/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.8 - XML children()");

//TEST(1, true, XML.prototype.hasOwnProperty("children"));

emps =
<employees>
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

correct = new XMLList();
correct += <employee id="0"><name>Jim</name><age>25</age></employee>;
correct += <employee id="1"><name>Joe</name><age>20</age></employee>;

TEST(2, "xml", typeof(emps.children()));
TEST(3, correct, emps.children());

// Get the child elements of the first employee
correct = new XMLList();
correct += <name>Jim</name>,
correct += <age>25</age>;

TEST(4, correct, emps.employee[0].children());

var xmlDoc = "<company><employee id='1'><name>John</name> <city>California</city> </employee> <employee id='2'><name>Mary</name><city>Texas</city></employee></company>";

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.employee[0].children().toString()", "<name>John</name>" + NL() + "<city>California</city>", (MYXML = new XML(xmlDoc), MYXML.employee[0].children().toString()));

// Same results whether or not prettyPrinting is true (XMLList.toString testing)
XML.prettyPrinting = false;
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.employee[0].children().toString()", "<name>John</name>" + NL() + "<city>California</city>", (MYXML = new XML(xmlDoc), MYXML.employee[0].children().toString()));

//!!@This crashes ASC (because of the (id == '1') code
//!!@This does not work in Rhino
//!!@AddTestCase( "MYXML = new XML(xmlDoc), MYXML.employee.(id == '1').children()", "<name>John</name>, <city>California</city>", (MYXML = new XML(xmlDoc), MYXML.employee.(id == '1').children()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.employee[1].children().toString()", "<name>Mary</name>" + NL() + "<city>Texas</city>", (MYXML = new XML(xmlDoc), MYXML.employee[1].children().toString()));

END();
