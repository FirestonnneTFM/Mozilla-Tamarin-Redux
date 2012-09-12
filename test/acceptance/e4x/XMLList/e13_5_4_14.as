/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.14 - XMLList length()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("length"));

x1 = <><alpha>one</alpha></>;

TEST(2, 1, x1.length());

x1 = <><alpha>one</alpha><bravo>two</bravo></>;

TEST(2, 2, x1.length());

emps =
<employees>
    <employee>
        <name>John</name>
    </employee>
    <employee>
        <name>Sue</name>
    </employee>
</employees>

correct =
<employees>
    <employee>
        <prefix>Mr.</prefix>
        <name>John</name>
    </employee>
    <employee>
        <name>Sue</name>
    </employee>
</employees>

TEST(3,2,emps..name.length());

var xmlDoc = "<employee id='1'><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee><employee id='2'><firstname>Sue</firstname><lastname>Day</lastname><age>32</age></employee>";



AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.length()", 2,
             (MYXML = new XMLList(xmlDoc), MYXML.length()));

xmlDoc = "<xml><employee id='1'><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee><employee id='2'><firstname>Sue</firstname><lastname>Day</lastname><age>32</age></employee></xml>";


// propertyName as a string
AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.length()", 1,
             (MYXML = new XMLList(xmlDoc), MYXML.length()));

AddTestCase( "MYXML = new XMLList(), MYXML.length()", 0,
             (MYXML = new XMLList(), MYXML.length()));

AddTestCase( "MYXML = new XMLList(null), MYXML.length()", 0,
             (MYXML = new XMLList(null), MYXML.length()));

AddTestCase( "MYXML = new XMLList(undefined), MYXML.length()", 0,
             (MYXML = new XMLList(undefined), MYXML.length()));

AddTestCase( "MYXML = new XMLList('foo'), MYXML.length()", 1,
             (MYXML = new XMLList("foo"), MYXML.length()));

XML.ignoreComments = false;
AddTestCase( "MYXML = new XMLList('<XML><!-- comment --></XML>'), MYXML.length()", 1,
             (MYXML = new XMLList("<XML><!-- comment --></XML>"), MYXML.length()));
             
END();
