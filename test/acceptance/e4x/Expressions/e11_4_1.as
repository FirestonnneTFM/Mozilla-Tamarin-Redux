/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("11.4.1 - Addition Operator");

employeeData = <name>Fred</name> + <age>28</age> + <hobby>skiing</hobby>;
TEST(1, "xml", typeof(employeeData));
correct = <><name>Fred</name><age>28</age><hobby>skiing</hobby></>;
TEST(2, correct, employeeData);

order = <order>
        <item>
            <description>Big Screen Television</description>
        </item>
        <item>
            <description>DVD Player</description>
        </item>
        <item>
            <description>CD Player</description>
        </item>
        <item>
            <description>8-Track Player</description>
        </item>
        </order>;

correct =
<item><description>Big Screen Television</description></item> +
<item><description>CD Player</description></item> +
<item><description>8-Track Player</description></item>;

myItems = order.item[0] + order.item[2] + order.item[3];
TEST(3, "xml", typeof(myItems));
TEST(4, correct, myItems);

correct =
<item><description>Big Screen Television</description></item> +
<item><description>DVD Player</description></item> +
<item><description>CD Player</description></item> +
<item><description>8-Track Player</description></item> +
<item><description>New Item</description></item>;

newItems = order.item + <item><description>New Item</description></item>;
TEST(5, "xml", typeof(newItems));
TEST(6, correct, newItems);

order =
<order>
    <item>
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item>
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
    <item>
        <description>CD Player</description>
        <price>199.99</price>
    </item>
    <item>
        <description>8-Track Player</description>
        <price>69.99</price>
    </item>
</order>;


totalPrice = +order.item[0].price + +order.item[1].price;
TEST(7, "number", typeof(totalPrice));
TEST(8, 1699.98, totalPrice);

totalPrice = +order.item[1].price + +order.item[3].price;
TEST(9, 469.98, totalPrice);


order =
<order>
    <customer>
        <address>
            <street>123 Foobar Ave.</street>
            <city>Bellevue</city>
            <state>WA</state>
            <zip>98008</zip>
        </address>
     </customer>
</order>;

streetCity = "" + order.customer.address.street + order.customer.address.city;
TEST(10, "string", typeof(streetCity));
TEST(11, "123 Foobar Ave.Bellevue", streetCity);


statezip = String(order.customer.address.state) + order.customer.address.zip;
TEST(12, "string", typeof(statezip));
TEST(13, "WA98008", statezip);

// XML + XML

var x1, y1, z1;

x1 = new XML("<a><b><c>A</c><d>B</d></b></a>");
y1 = new XML("<a><b><c>C</c><d>D</d></b></a>");
z1 = new XMLList("<a><b><c>A</c><d>B</d></b></a><a><b><c>C</c><d>D</d></b></a>");

AddTestCase( "XML     + XML:     ", true, ((x1+y1)==z1) );


// XML + XMLList

x1 = new XML("<a><b><c>A</c><d>B</d></b></a>");
y1 = new XMLList("<e>C</e><e>D</e><e>E</e>");
z1 = new XMLList("<a><b><c>A</c><d>B</d></b></a><e>C</e><e>D</e><e>E</e>");

AddTestCase( "XML     + XMLList: ", true, ((x1+y1)==z1) );


// XMLList + XML

x1 = new XMLList("<e>C</e><e>D</e><e>E</e>");
y1 = new XML("<a><b><c>A</c><d>B</d></b></a>");
z1 = new XMLList("<e>C</e><e>D</e><e>E</e><a><b><c>A</c><d>B</d></b></a>");

AddTestCase( "XMLList + XML:     ", true, ((x1+y1)==z1) );


// XMLList + XMLList

x1 = new XMLList("<a>A</a><a>B</a><a>C</a>");
y1 = new XMLList("<a>D</a><a>E</a><a>F</a>");
z1 = new XMLList("<a>A</a><a>B</a><a>C</a><a>D</a><a>E</a><a>F</a>");

AddTestCase( "XMLList + XMLList: ", true, ((x1+y1)==z1) );

END();
