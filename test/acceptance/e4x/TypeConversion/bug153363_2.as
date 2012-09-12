/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("bug153363_2 - XML.toXMLString");

var myxml = <order xmlns:x='x'>
<item id='1' xmlns:x='x2'>
<menuName xmlns:x='x'>burger</menuName>
<price>3.95</price>
</item>
</order>;

var expected_results1:String = <order xmlns:x='x'>
  <item id='1' xmlns:x='x2'>
    <menuName xmlns:x='x'>burger</menuName>
    <price>3.95</price>
  </item>
</order>

TEST(1,expected_results1,myxml.toXMLString());

var myxml2 = <order>
<item id="1">
<menuName xmlns:x="x" x:foo='10'>burger</menuName>
</item>
<item id="2">
<menuName xmlns:x="x" x:foo='20'>salad</menuName>
</item>
</order>;

var expected_results2:String = <order>
<item id="1">
<menuName xmlns:x="x" x:foo='10'>burger</menuName>
</item>
<item id="2">
<menuName xmlns:x="x" x:foo='20'>salad</menuName>
</item>
</order>;

TEST(2,expected_results2,myxml2.toXMLString());


END();

