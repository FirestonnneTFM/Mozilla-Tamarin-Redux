/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.15 - XMLList normalize()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("normalize"));

var x1, a, b, c, d;

x1 = new XMLList("<XML>b<c></c>onetwo<foo>three</foo></XML>");

AddTestCase( "xml has multiple text nodes, xml.normalize(), xml.toString()",
    "<XML>" + NL() + "  b" + NL() + "  <c/>" + NL() + "  onetwo" + NL() + "  <foo>three</foo>" + NL() + "</XML>",
    (x1.normalize(), x1.toString()));
    
    
x1 = new XMLList("<XML>bonetwo<c></c><foo>three</foo></XML>");

AddTestCase( "xml has multiple text nodes, xml.normalize(), xml.toString()",
    "<XML>" + NL() + "  bonetwo" + NL() + "  <c/>" + NL() + "  <foo>three</foo>" + NL() + "</XML>",
(x1.normalize(), x1.toString()));

END();
