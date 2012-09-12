/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("11.6.1 - XML Assignment");

// Change the value of the id attribute on the second item
order =
<order>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;

correct =
<order>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="1.23">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;

order.item[1].@id = 1.23;
TEST(1, correct, order);

// Add a new attribute to the second item
order =
<order>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;

correct =
<order>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2" newattr="new value">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;

order.item[1].@newattr = "new value";
TEST(2, correct, order);

// Construct an attribute list containing all the ids in this order
order =
<order>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;

order.@allids = order.item.@id;
TEST_XML(3, "1 2 3 4", order.@allids);

// Replace first child of the order element with an XML value
order =
<order>
    <customer>
        <name>John</name>
        <address>948 Ranier Ave.</address>
        <city>Portland</city>
        <state>OR</state>
    </customer>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;


order.*[0] =
<customer>
    <name>Fred</name>
    <address>123 Foobar Ave.</address>
    <city>Bellevue</city>
    <state>WA</state>
</customer>;

correct =
<order>
    <customer>
       <name>Fred</name>
       <address>123 Foobar Ave.</address>
       <city>Bellevue</city>
       <state>WA</state>
    </customer>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;

TEST(4, correct, order);

// Replace the second child of the order element with a list of items

order =
<order>
    <customer>
        <name>John</name>
        <address>948 Ranier Ave.</address>
        <city>Portland</city>
        <state>OR</state>
    </customer>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;

correct =
<order>
    <customer>
        <name>John</name>
        <address>948 Ranier Ave.</address>
        <city>Portland</city>
        <state>OR</state>
    </customer>
    <item>item one</item>
    <item>item two</item>
    <item>item three</item>
    <item id="2">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;

order.item[0] = <item>item one</item> +
           <item>item two</item> +
           <item>item three</item>;

TEST(5, correct, order);

// Replace the third child of the order with a text node
order =
<order>
    <customer>
        <name>John</name>
        <address>948 Ranier Ave.</address>
        <city>Portland</city>
        <state>OR</state>
    </customer>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;

correct =
<order>
    <customer>
        <name>John</name>
        <address>948 Ranier Ave.</address>
        <city>Portland</city>
        <state>OR</state>
    </customer>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2">A Text Node</item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;

order.item[1] = "A Text Node";

TEST(6, correct, order);

// append a new item to the end of the order

order =
<order>
    <customer>
        <name>John</name>
        <address>948 Ranier Ave.</address>
        <city>Portland</city>
        <state>OR</state>
    </customer>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;

correct =
<order>
    <customer>
        <name>John</name>
        <address>948 Ranier Ave.</address>
        <city>Portland</city>
        <state>OR</state>
    </customer>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item id="3">
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item id="4">
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
    <item>new item</item>
</order>;

order.*[order.*.length()] = <item>new item</item>;

TEST(7, correct, order);

// Change the price of the item
item =
<item>
    <description>Big Screen Television</description>
    <price>1299.99</price>
</item>

correct =
<item>
    <description>Big Screen Television</description>
    <price>99.95</price>
</item>

item.price = 99.95;

TEST(8, item, correct);

// Change the description of the item
item =
<item>
    <description>Big Screen Television</description>
    <price>1299.99</price>
</item>

correct =
<item>
    <description>Mobile Phone</description>
    <price>1299.99</price>
</item>

item.description = "Mobile Phone";

TEST(9, item, correct);

// property name begins with "@"

var xx  = new XML("<a attr='A' />");
var xl = new XMLList("<a attr='X' /><a attr='Y' /><a attr='Z' />");
var x_ = new XML("<a attr='X Y Z' />");

xx.@attr = xl.@attr;

AddTestCase( "x.@attr=XMLList                             :", true, (xx==x_) );

xx  = new XML("<a attr='A' />");
yy  = new XML("<a attr='B' />");
xx.@attr = "B";

AddTestCase( "xx.@attr='B'                                 :", "B", xx.@attr.toString() );

xx.@attr__ = "B";

AddTestCase( "xx.@attr__='B'                               :", true, (xx.@attr__=="B") );


// property name does NOT begin with "@" and is NOT array index

var x0  = new XML("<a><b>B</b><c>C</c><d>D</d></a>");
var x1  = new XML("<a><b>Z</b></a>");
var x0_ = new XML("<a><b>Z</b><c>C</c><d>D</d></a>");

x0.b = x1.b;

AddTestCase( "Replace XML Obj - XML                       :", true, (x0==x0_) );

var x2 = new XMLList("<b><c>Y</c><d>X</d></b>");

x0.b = x2;

x0_ = new XML("<a><b><c>Y</c><d>X</d></b><c>C</c><d>D</d></a>");

AddTestCase( "Replace XML Obj - XMLList                   :", true, (x0==x0_) );

x0  = new XML("<a><b>B</b><c>C</c><d>D</d></a>");

x0.e =  new XML("<e>E</e>");

x0_ = new XML("<a><b>B</b><c>C</c><d>D</d><e>E</e></a>");

AddTestCase( "Append new XML property                     :", true, (x0==x0_) );

x0  = new XML("<a><b>B0</b><b>B1</b><b>B2</b></a>");
x1  = new XML("<a><b>BB</b></a>");
x0_ = new XML("<a><b>BB</b></a>");

x0 = x1;

AddTestCase( "Multiple XML objs with given name - XML     :", true, (x0==x0_) );

x0  = new XML("<a><b>B0</b><b>B1</b><b>B2</b></a>");
x1  = new XML("<b>BB</b>");
x0_ = new XML("<a><b>BB</b></a>");

x0.b = x1;

AddTestCase( "Multiple XML objs with given name - XMLList :", true, (x0==x0_) );

x0  = new XML("<a><b>B</b><c>C</c></a>");
x0_ = new XML("<a><b>A</b><c>C</c></a>");

x0.b = "A";

AddTestCase( "x.b = 'A'                                 :", true, (x0==x0_) );

END();
