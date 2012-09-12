/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.2 - XML addNamespace()");

//TEST(1, true, XML.prototype.hasOwnProperty("addNamespace"));
//TEST(2, true, XML.prototype.hasOwnProperty("children"));

e =
<employees>
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

n = "http://foobar/";
e.addNamespace(n);

n = new Namespace();
e.addNamespace(n);

n = new Namespace("http://foobar/");
e.addNamespace(n);

x1 = <a/>;
n = new Namespace("ns", "uri");
x1.addNamespace(n);
TEST(2, "<a xmlns:ns=\"uri\"/>", x1.toXMLString());

var n1 = new Namespace('pfx', 'http://w3.org');
var n2 = new Namespace('http://us.gov');
var n3 = new Namespace('boo', 'http://us.gov');
var n4 = new Namespace('boo', 'http://hk.com');
var xml = "<a><b s='1'><c>55</c><d>bird</d></b><b s='2'><c>5</c><d>dinosaur</d></b></a>";
var xmlwithns = "<a xmlns:pfx=\"http://w3.org\"><a><b s='1'><c>55</c><d>bird</d></b><b s='2'><c>5</c><d>dinosaur</d></b></a>";

AddTestCase( "addNamespace with prefix:", "http://w3.org",
           (  x1 = new XML(xml), x1.addNamespace(n1), myGetNamespace(x1,'pfx').toString()));

AddTestCase( "addNamespace without prefix:", undefined,
           (  x1 = new XML(xml), x1.addNamespace(n2), myGetNamespace(x1, 'blah')));

expectedStr = "ArgumentError: Error #1063: Argument count mismatch on XML/addNamespace(). Expected 1, got 0";
expected = "Error #1063";
actual = "No error";

try {
    x1.addNamespace();
} catch(e1) {
    actual = grabError(e1, e1.toString());
}

AddTestCase( "addNamespace(): Error. Needs 1 argument", expected, actual);

AddTestCase( "Does namespace w/o prefix change XML object:", true,
           (  x1 = new XML(xml), y1 = new XML(xml), x1.addNamespace(n1), (x1 == y1)));

AddTestCase( "Does namespace w/ prefix change XML object:", true,
           (  x1 = new XML(xml), y1 = new XML(xml), x1.addNamespace(n2), (x1 == y1)));

AddTestCase( "Adding two different namespaces:", 'http://w3.org',
       (  x1 = new XML(xml), x1.addNamespace(n1), x1.addNamespace(n3), myGetNamespace(x1, 'pfx').toString()));

AddTestCase( "Adding two different namespaces:", 'http://us.gov',
           (  x1 = new XML(xml), x1.addNamespace(n1), x1.addNamespace(n3), myGetNamespace(x1, 'boo').toString()));

AddTestCase( "Adding namespace with pre-existing prefix:", 'http://hk.com',
           (  x1 = new XML(xml), x1.addNamespace(n3), x1.addNamespace(n4), myGetNamespace(x1, 'boo').toString()));


AddTestCase( "Adding namespace to something other than top node:", 'http://hk.com',
           (  x1 = new XML(xml), x1.b[0].d.addNamespace(n4), myGetNamespace(x1.b[0].d, 'boo').toString()));


AddTestCase( "Adding namespace to XMLList element:", 'http://hk.com',
           (  x1 = new XMLList(xml), x1.b[1].addNamespace(n4), myGetNamespace(x1.b[1], 'boo').toString()));
           


// namespaces with prefixes are preserved

x2 = <ns2:x xmlns:ns2="foo"><b>text</b></ns2:x>;
x2s = x2.toString();
correct = '<ns2:x xmlns:ns2="foo">\n  <b>text</b>\n</ns2:x>';
AddTestCase("Original XML", x2s, correct);

// Adding a namespace to a node will clear a conflicting prefix
var ns = new Namespace ("ns2", "newuri");
x2.addNamespace (ns);
x2s = x2.toString();
 
correct = '<x xmlns:ns2="newuri" xmlns="foo">\n  <b>text</b>\n</x>';

AddTestCase("Adding namespace that previously existed with a different prefix", correct,
       x2s);


correct = <newprefix:x xmlns:newprefix="foo"><b>text</b></newprefix:x>;

AddTestCase("Adding totally new namespace", correct,
(ns3 = new Namespace ("newprefix", "foo"), x2.addNamespace (ns3),x2));

END();
