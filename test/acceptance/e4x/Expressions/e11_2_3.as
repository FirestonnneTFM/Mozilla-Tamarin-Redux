/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("11.2.3 - XML Descendant Accessor");

var e =
<employees>
    <employee id="1"><name>Joe</name><age>20</age></employee>
    <employee id="2"><name>Sue</name><age>30</age></employee>
</employees>

names = e..name;

correct =
<name>Joe</name> +
<name>Sue</name>;

TEST(1, correct, names);

e = "<employees><employee id=\"1\"><name>Joe</name><age>20</age></employee><employee id=\"2\"><name>Sue</name><age>30</age></employee></employees>";

AddTestCase("xml..validnode:", "Joe", (x1 = new XML(e), names = x1..name, names[0].toString()));

AddTestCase("xml..validnode length:", 2, (x1 = new XML(e), names = x1..name, names.length()));

AddTestCase("xml..invalidnode:", undefined, (x1 = new XML(e), names = x1..hood, names[0]));

AddTestCase("xmllist..validnode:", "Joe", (x1 = new XMLList(e), names = x1..name, names[0].toString()));

AddTestCase("xmllist..invalidnode:", undefined, (x1 = new XMLList(e), names = x1..hood, names[0]));

AddTestCase("xmllist..invalidnode length:", 0, (x1 = new XMLList(e), names = x1..hood, names.length()));

e =
<employees>
    <employee id="1"><first_name>Joe</first_name><age>20</age></employee>
    <employee id="2"><first_name>Sue</first_name><age>30</age></employee>
</employees>

correct =
<first_name>Joe</first_name> +
<first_name>Sue</first_name>;

names = e..first_name;

TEST(2, correct, names);

e =
<employees>
    <employee id="1"><first-name>Joe</first-name><age>20</age></employee>
    <employee id="2"><first-name>Sue</first-name><age>30</age></employee>
</employees>

e =
<company><staff>
    <bug attr='1'><coat><bug>heart</bug></coat></bug>
    <bug attr='2'><dirt><bug>part</bug></dirt></bug>
</staff></company>

es = <><bug attr='1'><coat><bug>heart</bug></coat></bug><bug>heart</bug><bug attr='2'><dirt><bug>part</bug></dirt></bug><bug>part</bug></>;

AddTestCase(3, es, e..bug);

END();
