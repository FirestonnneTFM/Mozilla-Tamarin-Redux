/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.17 - XML inScopeNamespaces()");

//TEST(1, true, XML.prototype.hasOwnProperty("inScopeNamespaces"));
 
x1 =
<alpha xmlns:foo="http://foo/" xmlns:bar="http://bar/">
    <bravo>one</bravo>
</alpha>;

namespaces = x1.bravo.inScopeNamespaces();


TEST(2, "foo", namespaces[0].prefix);
TEST(3, "http://foo/", namespaces[0].uri);
TEST(4, "bar", namespaces[1].prefix);
TEST(5, "http://bar/", namespaces[1].uri);
//TEST(6, "", namespaces[2].prefix);
//TEST(7, "", namespaces[2].uri);
TEST(8, 2, namespaces.length);

var n1 = new Namespace('pfx', 'http://w3.org');
var n2 = new Namespace('http://us.gov');
var n3 = new Namespace('boo', 'http://us.gov');
var n4 = new Namespace('boo', 'http://hk.com');
var xml = "<a><b s='1'><c>55</c><d>bird</d></b><b s='2'><c>5</c><d>dinosaur</d></b></a>";


AddTestCase( "Two namespaces in toplevel scope:", ('http://hk.com'),
           (  x1 = new XML(xml), x1.addNamespace(n1), x1.addNamespace(n4), x1.inScopeNamespaces()[1].toString()));

AddTestCase( "Two namespaces in toplevel scope:", ('http://w3.org'),
           (  x1 = new XML(xml), x1.addNamespace(n1), x1.addNamespace(n4), x1.inScopeNamespaces()[0].toString()));

AddTestCase( "No namespace:", (''),
           (  x1 = new XML(xml), x1.inScopeNamespaces().toString()));
           
try {
    x1 = new XML(xml);
    x1.addNamespace();
    result = "no exception";
} catch (e1) {
    result = "exception";
}

AddTestCase( "Undefined namespace:", "exception", result);

AddTestCase( "Undefined namespace, length:", 1,
       (  x1 = new XML(xml), x1.addNamespace(null), x1.inScopeNamespaces().length));
       
AddTestCase( "One namespace w/o prefix, length:", 1,
       (  x1 = new XML(xml), x1.addNamespace(n2), x1.inScopeNamespaces().length));

AddTestCase( "One namespace w/ prefix, length:", 1,
       (  x1 = new XML(xml), x1.addNamespace(n1), x1.inScopeNamespaces().length));

AddTestCase( "One namespace at toplevel, one at child, length at toplevel:", 1,
       (  x1 = new XML(xml), x1.addNamespace(n3), x1.b[0].c.addNamespace(n4), x1.inScopeNamespaces().length));

AddTestCase( "One namespace at toplevel, two at child, length at child:", 2,
       (  x1 = new XML(xml), x1.addNamespace(n3), x1.b[1].c.addNamespace(n4), x1.b[1].c.addNamespace(n1), x1.b[1].c.inScopeNamespaces().length));

AddTestCase( "inScopeNamespaces[0].typeof:", "object",
           (  x1 = new XML(xml), x1.addNamespace(n1), x1.addNamespace(n4), typeof x1.inScopeNamespaces()[0]));

AddTestCase( "inScopeNamespaces[1].prefix:", "boo",
           (  x1 = new XML(xml), x1.addNamespace(n1), x1.addNamespace(n4), x1.inScopeNamespaces()[1].prefix));

   
var xmlDoc = "<?xml version=\"1.0\"?><xsl:stylesheet xmlns:xsl=\"http://www.w3.org/TR/xsl\"><b><c xmlns:foo=\"http://www.foo.org/\">hi</c></b></xsl:stylesheet>";

AddTestCase( "Reading one toplevel namespace:", (["http://www.w3.org/TR/xsl"]).toString(),
       (  x1 = new XML(xmlDoc), x1.inScopeNamespaces().toString()));

AddTestCase( "Reading two namespaces up parent chain:", (["http://www.foo.org/","http://www.w3.org/TR/xsl"]).toString(),
       (  x1 = new XML(xmlDoc), x1.b.c.inScopeNamespaces().toString()));

END();
