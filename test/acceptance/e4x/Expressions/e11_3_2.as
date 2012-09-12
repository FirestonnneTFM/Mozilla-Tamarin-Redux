/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("11.3.2 - Typeof Operator");

x1 = new XML();
TEST(1, "xml", typeof(x1));
x1 = new XMLList();
TEST(2, "xml", typeof(x1));



x1  = new XML("<a><b><c>C</c><d>D</d></b></a>");
x_ = new XML("<b><e>E</e></b>");

AddTestCase( "typeof XML             :", "xml",       typeof(x1) );
AddTestCase( "typeof XML             :", "xml",       typeof(x1.a.b+x_) );

x1  = new XMLList("<a>A</a><b>B</b><c>C</c>");
x_ = new XMLList("<d>D</d>");

AddTestCase( "typeof XMLList         :", "xml",       typeof(x1) );
AddTestCase( "typeof XMLList         :", "xml",       typeof(x1+x_) );


END();
