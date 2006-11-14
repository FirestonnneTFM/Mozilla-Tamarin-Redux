/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * The contents of this file are subject to the Netscape Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is Rhino code, released
 * May 6, 1999.
 *
 * The Initial Developer of the Original Code is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1997-2000 Netscape Communications Corporation. All
 * Rights Reserved.
 *
 * Contributor(s):
 * Igor Bukanov
 * Ethan Hugg
 * Milen Nankov
 *
 * Alternatively, the contents of this file may be used under the
 * terms of the GNU Public License (the "GPL"), in which case the
 * provisions of the GPL are applicable instead of those above.
 * If you wish to allow use of your version of this file only
 * under the terms of the GPL and not to allow others to use your
 * version of this file under the NPL, indicate your decision by
 * deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL.  If you do not delete
 * the provisions above, a recipient may use your version of this
 * file under either the NPL or the GPL.
 */

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
