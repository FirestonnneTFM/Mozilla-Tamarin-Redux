/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.27 - XML parent()");

//TEST(1, true, XML.prototype.hasOwnProperty("parent"));
    
var x1 =
<alpha>
    <bravo>one</bravo>
    <charlie>
        <bravo>two</bravo>
    </charlie>
</alpha>;

var y1 = x1.bravo;

TEST(2, x1, y1.parent());

TEST(3, undefined, x1.parent());

x1 = new XML("<XML></XML>");
var a = new XML("text node");
var b = new XML("<foo>bar</foo>");

AddTestCase ("MYXML = new('<XML></XML>'), MYXML.parent()", undefined, x1.parent());
AddTestCase ("MYXML = new('text node'), MYXML.parent()", undefined, a.parent());
AddTestCase ("MYXML = new('<foo>bar</foo>'), MYXML.parent()", undefined, b.parent());

x1.appendChild (a);
x1.appendChild (b);


// Text node is a special case
AddTestCase ("a - orphan node after x.appendChild, a.parent()", undefined, a.parent());
AddTestCase ("b - orphan node after x.appendChild, b.parent()", x1, b.parent());

AddTestCase ("x1.children()[0].parent()", x1, x1.children()[0].parent());
AddTestCase ("x1.children()[1].parent()", x1, x1.children()[0].parent());
AddTestCase ("x1.children()[0].parent() === x1", true, (x1.children()[0].parent() === x1));
AddTestCase ("x1.children()[1].parent() === x1", true, (x1.children()[0].parent() === x1));

var xDoc = "<company><employee id='1'><name1>John</name1> <city>California</city> </employee><employee id='2'><name1>Mary</name1> <city>Texas</city> </employee></company>";

AddTestCase( "x1 = new XML(xDoc), x1.employee[0].parent() == x1", true, (x1 = new XML(xDoc), x1.employee[0].parent() == x1));
AddTestCase( "x1 = new XML(xDoc), x1.employee.name1[0].parent() == x1.employee[0]", true, (x1 = new XML(xDoc), x1.employee.name1[0].parent() == x1.employee[0]));
AddTestCase( "x1 = new XML(xDoc), x1.employee[0].attribute('id').parent() === x1.employee[0]", true, (x1 = new XML(xDoc), x1.employee[0].attribute('id').parent() === x1.employee[0]));

AddTestCase( "x1 = new XML(xDoc), x1.employee[1].parent() == x1", true, (x1 = new XML(xDoc), x1.employee[1].parent() == x1));
AddTestCase( "x1 = new XML(xDoc), x1.employee.name1[1].parent() == x1.employee[0]", true, (x1 = new XML(xDoc), x1.employee.name1[1].parent() == x1.employee[1]));
AddTestCase( "x1 = new XML(xDoc), x1.employee[1].attribute('id').parent() === x1.employee[1]", true, (x1 = new XML(xDoc), x1.employee[1].attribute('id').parent() === x1.employee[1]));

XML.ignoreComments = false;
XML.ignoreProcessingInstructions = false;
xDoc = "<simple><!-- comment --><?x-stylesheet href=\"classic.xsl\" type=\"text/x\"?></simple>";

// Tests comments and PI nodes
AddTestCase( "x1 = new XML(xDoc), x1.children()[0].parent() == x1", true, (x1 = new XML(xDoc), x1.children()[0].parent() == x1));
AddTestCase( "x1 = new XML(xDoc), x1.children()[1].parent() == x1", true, (x1 = new XML(xDoc), x1.children()[1].parent() == x1));
AddTestCase( "x1 = new XML(xDoc), x1.children().parent() == x1", true, (x1 = new XML(xDoc), x1.children().parent() == x1));


END();
