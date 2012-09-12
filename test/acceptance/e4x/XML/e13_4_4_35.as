/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.35 - setName");

//TEST(1, true, XML.prototype.hasOwnProperty("setName"));

x1 =
<alpha>
    <bravo>one</bravo>
</alpha>;

correct =
<charlie>
    <bravo>one</bravo>
</charlie>;

x1.setName("charlie");

TEST(2, correct, x1);

x1 =
<ns:alpha xmlns:ns="http://foobar/">
    <ns:bravo>one</ns:bravo>
</ns:alpha>;

correct =
<charlie xmlns:ns="http://foobar/">
    <ns:bravo>one</ns:bravo>
</charlie>;

x1.setName("charlie");

TEST(3, correct, x1);

x1 =
<ns:alpha xmlns:ns="http://foobar/">
    <ns:bravo>one</ns:bravo>
</ns:alpha>;

correct =
<ns:charlie xmlns:ns="http://foobar/">
    <ns:bravo>one</ns:bravo>
</ns:charlie>;

x1.setName(new QName("http://foobar/", "charlie"));

TEST(4, correct, x1);

XML.prettyPrinting = false;
var xmlDoc = "<company><employee id='1'><name>John</name> <city>California</city> </employee></company>";

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.setName('employees'),MYXML.name().toString()",
    "employees",
    (MYXML = new XML(xmlDoc),MYXML.setName('employees'), MYXML.name().toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.setName(new QName('employees')),MYXML.name().toString()",
    "employees",
    (MYXML = new XML(xmlDoc),MYXML.setName(new QName('employees')), MYXML.name().toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.setName(new QName('ns', 'employees')),MYXML.name().toString()",
    "ns::employees",
    (MYXML = new XML(xmlDoc),MYXML.setName(new QName('ns', 'employees')), MYXML.name().toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.setName('employees'),MYXML.toString()",
    "<employees><employee id=\"1\"><name>John</name><city>California</city></employee></employees>",
    (MYXML = new XML(xmlDoc),MYXML.setName('employees'), MYXML.toString()));

// Calling setName() on an attribute
AddTestCase("MYXML = new XML(xmlDoc), MYXML.employee.@id.setName('num')", "num", (MYXML = new XML(xmlDoc), MYXML.employee.@id.setName("num"), MYXML.employee.@num.name().toString()));

var TYPEERROR = "TypeError: Error #";
function typeError( str ){
    return str.slice(0,TYPEERROR.length+4);
}
MYXML = new XML(xmlDoc);
MYXML.employee.@id.setName("num");

try {
    MYXML.employee.@id.name();
    result = "no error";
} catch (e1) {
    result = typeError(e1.toString());
}

AddTestCase("MYXML = new XML(xmlDoc), MYXML.employee.@id.setName(\"num\"),MYXML.employee.@id.name())", "TypeError: Error #1086", result);
x1 =
<foo:alpha xmlns:foo="http://foo/" xmlns:bar="http://bar/">
    <foo:bravo attr="1">one</foo:bravo>
</foo:alpha>;

ns = new Namespace("foo", "http://foo/");
correct = <foo:alpha xmlns:foo="http://foo/" xmlns:bar="http://bar/">
    <foo:bravo foo="1">one</foo:bravo>
</foo:alpha>;

AddTestCase("Calling setName() on an attribute with same name as namespace", correct, (x1.ns::bravo.@attr.setName("foo"), x1));

// throws Rhino exception - bad name
MYXML = new XML(xmlDoc);
try {
    MYXML.setName('@employees');
    result = " no error";
} catch (e2) {
    result = typeError(e2.toString());
}
AddTestCase("MYXML.setName('@employees')", "TypeError: Error #1117", result);

try {
    MYXML.setName('!hi');
    result = " no error";
} catch (e3) {
    result = typeError(e3.toString());
}
AddTestCase("MYXML.setName('!hi')", "TypeError: Error #1117", result);

try {
    MYXML.setName('1+1=5');
    result = " no error";
} catch (e4) {
    result = typeError(e4.toString());
}
AddTestCase("MYXML.setName('1+1=5')", "TypeError: Error #1117", result);

try {
    MYXML.setName('555');
    result = " no error";
} catch (e5) {
    result = typeError(e5.toString());
}
AddTestCase("MYXML.setName('555')", "TypeError: Error #1117", result);


try {
    MYXML.setName('1love');
    result = " no error";
} catch (e6) {
    result = typeError(e6.toString());
}
AddTestCase("MYXML.setName('1love')", "TypeError: Error #1117", result);

try {
    MYXML.setName('*');
    result = " no error";
} catch (e7) {
    result = typeError(e7.toString());
}
AddTestCase("MYXML.setName('*')", "TypeError: Error #1117", result);



END();
