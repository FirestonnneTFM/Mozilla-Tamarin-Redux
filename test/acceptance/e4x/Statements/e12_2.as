/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("12.2 - For-in statement");

// All the employee names
e =
<employees>
    <employee id="1">
        <name>Joe</name>
        <age>20</age>
    </employee>
    <employee id="2">
        <name>Sue</name>
        <age>30</age>
    </employee>
</employees>;

correct = new Array("Joe", "Sue", "Big Screen Television", "1299.99");

i = 0;
for (var n in e..name)
{
    TEST("1."+i, i.toString(), n);
    i++;
}
TEST("1." + i, 2, i);


// Each child of the first item
order =
<order>
    <customer>
        <name>John Smith</name>
    </customer>
    <item id="1">
        <description>Big Screen Television</description>
        <price>1299.99</price>
    </item>
    <item id="2">
        <description>DVD Player</description>
        <price>399.99</price>
    </item>
</order>;

i = 0;
for (var child in order.item)
{
    TEST("2."+i, i.toString(), child);
    i++
}
TEST("2." + i, 2, i);

i = 0;
for (child in order.item[0].*)
{
    TEST("3."+i, i.toString(), child);
    i++
}

TEST("3." + i, 2, i);

var i, s="";

var xmlDoc = "<L><z><A>1</A></z><z><A>2</A></z><z><A>3</A></z></L>";


// XML Object

var x1 = new XML(xmlDoc);

for (i in x1.z) {
     s += x1.z[i].A;
}

AddTestCase( "for-in       :", true, (s=="123") );

s = "";

for ( i in x1.z )
    s += x1.z[i].A;

AddTestCase( "for-in (var) :", true, (s=="123") );


// XMLList object

var xl = new XMLList(xmlDoc);
s = "";

for (i in xl.z) {
     s += xl.z[i].A;
}

AddTestCase( "for-in       :", true, (s=="123") );

s = "";

for ( i in xl.z )
    s += xl.z[i].A;

AddTestCase( "for-in (var) :", true, (s=="123") );

END();
