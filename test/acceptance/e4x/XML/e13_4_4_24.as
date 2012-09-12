/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.24 - XML namespaceDeclarations()");

//TEST(1, true, XML.prototype.hasOwnProperty("namespaceDeclarations"));
    
x1 =
<foo:alpha xmlns:foo="http://foo/" xmlns:bar="http://bar/">
    <foo:bravo>one</foo:bravo>
</foo:alpha>;

y1 = x1.namespaceDeclarations();

TEST(2, 2, y1.length);
TEST(3, "object", typeof(y1[0]));
TEST(4, "object", typeof(y1[1]));
TEST(5, "foo", y1[0].prefix);
TEST(6, Namespace("http://foo/"), y1[0]);
TEST(7, "bar", y1[1].prefix);
TEST(8, Namespace("http://bar/"), y1[1]);

var n1 = new Namespace('pfx', 'http://w3.org');
var n2 = new Namespace('http://us.gov');
var n3 = new Namespace('boo', 'http://us.gov');
var n4 = new Namespace('boo', 'http://hk.com');
var xml1 = "<a><b s='1'><c>55</c><d>bird</d></b><b s='2'><c>5</c><d>dinosaur</d></b></a>";

//AddTestCase( "Undefined declaration:", (''),
//     (  x1 = new XML(xml1), x1.addNamespace(), x1.namespaceDeclarations().toString()));

AddTestCase( "Undefined declaration, length:", 0,
       (  x1 = new XML(xml1), x1.addNamespace(null), x1.namespaceDeclarations().length));

AddTestCase( "Two declarations in toplevel scope:", ('http://hk.com'),
           (  x1 = new XML(xml1), x1.addNamespace(n1), x1.addNamespace(n4), x1.namespaceDeclarations()[1].toString()));

AddTestCase( "Two declarations in toplevel scope:", ('http://w3.org'),
           (  x1 = new XML(xml1), x1.addNamespace(n1), x1.addNamespace(n4), x1.namespaceDeclarations()[0].toString()));

AddTestCase( "No declaration:", (''),
           (  x1 = new XML(xml1), x1.namespaceDeclarations().toString()));
           
AddTestCase( "One declaration w/o prefix, length:", 0,
       (  x1 = new XML(xml1), x1.addNamespace(n2), x1.namespaceDeclarations().length));

AddTestCase( "One declaration w/ prefix, length:", 1,
       (  x1 = new XML(xml1), x1.addNamespace(n1), x1.namespaceDeclarations().length));

AddTestCase( "One declaration at toplevel, one at child, length at toplevel:", 1,
       (  x1 = new XML(xml1), x1.addNamespace(n3), x1.b[0].c.addNamespace(n4), x1.namespaceDeclarations().length));

AddTestCase( "One declaration at toplevel, two at child, length at child:", 2,
       (  x1 = new XML(xml1), x1.addNamespace(n3), x1.b[1].c.addNamespace(n4), x1.b[1].c.addNamespace(n1), x1.b[1].c.namespaceDeclarations().length));

AddTestCase( "namespaceDeclarations[1].typeof:", "object",
           (  x1 = new XML(xml1), x1.addNamespace(n1), x1.addNamespace(n4), typeof x1.namespaceDeclarations()[1]));

AddTestCase( "namespaceDeclarations[1].prefix:", "boo",
           (  x1 = new XML(xml1), x1.addNamespace(n1), x1.addNamespace(n4), x1.namespaceDeclarations()[1].prefix));

           
var xml1Doc = "<?xml1 version=\"1.0\"?><xsl:stylesheet xmlns:xsl=\"http://www.w3.org/TR/xsl\"><b><c xmlns:foo=\"http://www.foo.org/\">hi</c></b></xsl:stylesheet>";

AddTestCase( "Reading one toplevel declaration:", "http://www.w3.org/TR/xsl",
       (  x1 = new XML(xml1Doc), x1.namespaceDeclarations().toString()));

AddTestCase( "Another declaration up parent chain:", "http://www.foo.org/",
       (  x1 = new XML(xml1Doc), x1.b.c.namespaceDeclarations().toString()));
       
// Adding because of Mozilla bug https://bugzilla.mozilla.org/show_bug.cgi?id=278112

var xhtml1NS = new Namespace('http://www.w3.org/1999/xhtml');
var xhtml = <html />;

AddTestCase("namespaceDeclarations before setNamespace()", 0, xhtml.namespaceDeclarations().length);

xhtml.setNamespace(xhtml1NS);

AddTestCase("namespaceDeclarations after setNamespace()", 0, xhtml.namespaceDeclarations().length);


END();
