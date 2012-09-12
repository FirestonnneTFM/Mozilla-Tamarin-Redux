/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.19 - XMLList text()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("text"));

XML.prettyPrinting = false;
var xmlDoc = "<employee id='1'>foo<firstname>John</firstname>bar<lastname>Walton</lastname>still<age>25</age>reading</employee>"

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.text().toString()",
    "foobarstillreading",
    (MYXML = new XMLList(xmlDoc), MYXML.text().toString()));
    
AddTestCase( "MYXML = new XMLList('<XML></XML>'), MYXML.text().toString()",
    "",
    (MYXML = new XMLList('<XML></XML>'), MYXML.text().toString()));
    
xmlDoc = <a>b</a>;

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.text().toString()",
    "b",
    (MYXML = new XMLList(xmlDoc), MYXML.text().toString()));

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.text().toString()",
    "b",
    (MYXML = new XMLList(xmlDoc), MYXML.setName('c'), MYXML.text().toString()));

END();
