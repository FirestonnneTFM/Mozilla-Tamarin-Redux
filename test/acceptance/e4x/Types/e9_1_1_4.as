/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("9.1.1.4 - XML [[DeleteByIndex]]");

order =
<order id="123456">
<customer id="123">
<firstname>John</firstname>
<lastname>Doe</lastname>
<address>123 Foobar Ave.</address>
<city>Bellevue</city>
<state>WA</state>
</customer>
<item id="1222">
<description>Big Screen Television</description>
<price>1299.99</price>
<quantity>1</quantity>
</item>
<item id="3456">
<description>Camera phone</description>
<price>399.99</price>
<quantity>1</quantity>
</item>
<item id="56789">
<description>DVD Player</description>
<price>399.99</price>
<quantity>1</quantity>
</item>
</order>;

delete order.item[1];

TEST(1, 2, order.item.length());


END();
