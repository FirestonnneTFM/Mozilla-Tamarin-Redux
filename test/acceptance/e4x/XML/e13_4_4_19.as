/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.19 - insertChildBefore()");

//TEST(1, true, XML.prototype.hasOwnProperty("insertChildBefore"));
    
x1 =
<alpha>
    <bravo>one</bravo>
    <charlie>two</charlie>
</alpha>;

correct =
<alpha>
    <delta>three</delta>
    <bravo>one</bravo>
    <charlie>two</charlie>
</alpha>;

x1.insertChildBefore(x1.bravo[0], <delta>three</delta>);

TEST(2, correct, x1);

x1 =
<alpha>
    <bravo>one</bravo>
    <charlie>two</charlie>
</alpha>;

correct =
<alpha>
    <bravo>one</bravo>
    <charlie>two</charlie>
    <delta>three</delta>
</alpha>;
x2 = new XML();

x2 = x1.insertChildBefore(null, <delta>three</delta>);

TEST(3, correct, x1);

TEST(4, correct, x2);

// to simplify string matching
XML.prettyPrinting = false;

var xmlDoc = "<company></company>";
var child1 = new XML("<employee id='1'><name>John</name></employee>");
var child2 = new XML("<employee id='2'><name>Sue</name></employee>");
var child3 = new XML("<employee id='3'><name>Bob</name></employee>");

var allChildren = new XMLList("<employee id='1'><name>John</name></employee><employee id='2'><name>Sue</name></employee><employee id='3'><name>Bob</name></employee>");
var twoChildren = new XMLList("<employee id='1'><name>John</name></employee><employee id='2'><name>Sue</name></employee>");

var wholeString = "<company><employee id='1'><name>John</name></employee><employee id='2'><name>Sue</name></employee><employee id='3'><name>Bob</name></employee></company>";

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.insertChildBefore(null, child1), MYXML.toString()",
    "<company><employee id=\"1\"><name>John</name></employee></company>",
    (MYXML = new XML(xmlDoc), MYXML.insertChildBefore(null, child1), MYXML.toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.insertChildBefore(null, child1), MYXML.children()[0].parent() == MYXML",
    true,
    (MYXML = new XML(xmlDoc), MYXML.insertChildBefore(null, child1), MYXML.children()[0].parent() == MYXML));

// The child is equal to child1 (but not the same object)
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.insertChildBefore(null, child1), MYXML.children()[0] == child1",
    true,
    (MYXML = new XML(xmlDoc), MYXML.insertChildBefore(null, child1), MYXML.children()[0] == child1));

// The child is a duplicate of child1
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.insertChildBefore(null, child1), MYXML.children()[0] === child1",
    true,
    (MYXML = new XML(xmlDoc), MYXML.insertChildBefore(null, child1), MYXML.children()[0] === child1));

var MYXML = new XML(xmlDoc);
MYXML.insertChildBefore(null, child1);

// !!@ this crashes Rhino's implementation
AddTestCase( "MYXML.insertChildBefore(child1, child2), MYXML.toString()",
    "<company><employee id=\"2\"><name>Sue</name></employee><employee id=\"1\"><name>John</name></employee></company>",
    (MYXML.insertChildBefore(child1, child2), MYXML.toString()));


var MYXML = new XML(xmlDoc);
MYXML.insertChildBefore(null, child1);

AddTestCase( "MYXML.insertChildBefore(MYXML.children()[0], child2), MYXML.toString()",
    "<company><employee id=\"2\"><name>Sue</name></employee><employee id=\"1\"><name>John</name></employee></company>",
    (MYXML.insertChildBefore(MYXML.children()[0], child2), MYXML.toString()));

MYXML = new XML(xmlDoc);
MYXML.insertChildBefore(null, child2);
MYXML.insertChildBefore(MYXML.children()[0], child1);

// !!@ this crashes Rhino's implementation
AddTestCase( "MYXML.insertChildBefore(child2, child3), MYXML.toString()",
    "<company><employee id=\"1\"><name>John</name></employee><employee id=\"3\"><name>Bob</name></employee><employee id=\"2\"><name>Sue</name></employee></company>",
    (MYXML.insertChildBefore(child2, child3), MYXML.toString()));

MYXML = new XML(xmlDoc);
MYXML.insertChildBefore(null, child2);
MYXML.insertChildBefore(MYXML.children()[0], child1);

AddTestCase( "MYXML.insertChildBefore(MYXML.children()[1], child3), MYXML.toString()",
    "<company><employee id=\"1\"><name>John</name></employee><employee id=\"3\"><name>Bob</name></employee><employee id=\"2\"><name>Sue</name></employee></company>",
    (MYXML.insertChildBefore(MYXML.children()[1], child3), MYXML.toString()));
    
MYXML = new XML(xmlDoc);

AddTestCase("MYXML.insertChildBefore(null, XMLList), MYXML.toString()",
             new XML(wholeString).toString(),
             (MYXML.insertChildBefore(null, allChildren), MYXML.toString()));
             
MYXML = new XML(xmlDoc);
MYXML.insertChildBefore(null, child3);

AddTestCase("MYXML.insertChildBefore(child3, XMLList), MYXML.toString()",
             new XML(wholeString).toString(),
             (MYXML.insertChildBefore(MYXML.children()[0], twoChildren), MYXML.toString()));
             
MYXML = new XML(xmlDoc);
MYXML.insertChildBefore(null, child1);

AddTestCase("MYXML.insertChildBefore(child1, \"string\"), MYXML.toString()",
         new XML("<company>string<employee id='1'><name>John</name></employee></company>").toString(),
         (MYXML.insertChildBefore(MYXML.children()[0], "string"), MYXML.toString()));
             
var a = <a><b><c/></b></a>;

try {
    a.b.c.insertChildBefore (null, a);
    result = a;
} catch (e1) {
    result = typeError(e1.toString());
}
AddTestCase("a = <a><b><c/></b></a>, a.b.c.insertChildBefore(null,a)", "TypeError: Error #1118", result);




END();
