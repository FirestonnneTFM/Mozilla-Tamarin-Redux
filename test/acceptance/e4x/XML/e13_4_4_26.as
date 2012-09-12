/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.26 - XML normalize()");

//TEST(1, true, XML.prototype.hasOwnProperty("normalize"));

XML.ignoreWhitespace = false;
XML.prettyPrinting = false;

x1 =
<alpha> <bravo> one </bravo> </alpha>;

TEST_XML(2, "<alpha> <bravo> one </bravo> </alpha>", x1);
x1.normalize();
TEST_XML(3, "<alpha><bravo> one </bravo></alpha>", x1);

x1 =
<alpha>
    <bravo> one </bravo>
</alpha>;

x1.normalize();
TEST_XML(5, "<alpha><bravo> one </bravo></alpha>", x1);

XML.prettyPrinting = true;
var xml = new XML("<XML></XML>");
var a = new XML("zero");
var b = new XML("one");
var c = new XML("two");
var d = new XML("<foo>two</foo>");

xml.appendChild (a);
xml.appendChild (b);
xml.appendChild (c);
xml.appendChild (d);

AddTestCase( "xml has multiple text nodes, xml.normalize(), xml.toString()",
    "<XML>" + NL() + "  zeroonetwo" + NL() + "  <foo>two</foo>" + NL() + "</XML>",
    (xml.normalize(), xml.toString()));

xml = new XMLList("<XML>b</XML>");
a = new XMLList("one");
b = new XMLList("two");
c = new XMLList("<c></c>");
d = new XMLList("<foo>three</foo>");

xml.appendChild (a);
xml.appendChild (b);
xml.appendChild (c);
xml.appendChild (d);

AddTestCase( "xml has multiple text nodes, xml.normalize(), xml.toString()",
    "<XML>" + NL() + "  bonetwo" + NL() + "  <c/>" + NL() + "  <foo>three</foo>" + NL() + "</XML>",
(xml.normalize(), xml.toString()));

END();
