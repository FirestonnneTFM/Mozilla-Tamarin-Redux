/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.31 - XML removeNamespace()");

//TEST(1, true, XML.prototype.hasOwnProperty("removeNamespace"));

x1 =
<alpha xmlns:foo="http://foo/">
    <bravo>one</bravo>
</alpha>;

correct =
<alpha>
    <bravo>one</bravo>
</alpha>;

TEST(1.5, correct, x1);
TEST(1.6, false, (correct.toString() == x1.toString()));

x1.removeNamespace("http://foo/");

TEST(2, correct.toString(), x1.toString());

TEST(2.5, correct, x1);

// Shouldn't remove namespace if referenced
x1 =
<foo:alpha xmlns:foo="http://foo/">
    <bravo>one</bravo>
</foo:alpha>;

correct =
<foo:alpha xmlns:foo="http://foo/">
    <bravo>one</bravo>
</foo:alpha>;

x1.removeNamespace("http://foo/");

TEST(3, correct, x1);


var xmlDoc = "<?xml version=\"1.0\"?><xsl:stylesheet xmlns:xsl=\"http://www.w3.org/TR/xsl\"><b><c xmlns:foo=\"http://www.foo.org/\">hi</c></b></xsl:stylesheet>";
var ns1 = Namespace ("xsl", "http://www.w3.org/TR/xsl");
var ns2 = Namespace ("foo", "http://www.foo.org");


// Namespace that is referenced by QName should not be removed
AddTestCase( "MYXML.removeNamespace(QName reference)", "http://www.w3.org/TR/xsl",
       (  MYXML = new XML(xmlDoc), MYXML.removeNamespace('xsl'), myGetNamespace(MYXML, 'xsl').toString()));


// Other namespaces should be removed
AddTestCase( "MYXML.removeNamespace(no Qname reference)", undefined,
       (  MYXML = new XML(xmlDoc), MYXML.b.c.removeNamespace('foo'), myGetNamespace(MYXML, 'foo')) );

var n1 = new Namespace('pfx', 'http://w3.org');
var n2 = new Namespace('http://us.gov');
var n3 = new Namespace('boo', 'http://us.gov');
var n4 = new Namespace('boo', 'http://hk.com');
var xml = "<a><b s='1'><c>55</c><d>bird</d></b><b s='2'><c>5</c><d>dinosaur</d></b></a>";

AddTestCase("Two namespaces in one node", true,
           ( x1 = new XML(xml), x1.addNamespace(n1), x1.addNamespace(n3), x1.removeNamespace(n3),
             x1.removeNamespace(n1), (myGetNamespace(x1, 'pfx') == myGetNamespace(x1, 'boo'))) );

AddTestCase("Two namespaces in one node", 1,
           ( x1 = new XML(xml), x1.addNamespace(n1), x1.addNamespace(n3), x1.removeNamespace(n3),
             x1.removeNamespace(n1), x1.inScopeNamespaces().length) );
             
AddTestCase("Two namespace in two different nodes", undefined,
           ( x1 = new XML(xml), x1.addNamespace(n3), x1.b[0].c.addNamespace(n1),
             x1.removeNamespace(n1), myGetNamespace(x1.b[0].c, 'pfx')));
             
var xml1 = <a xmlns:n2="http://us.gov"><b s='1'><c>55</c><d>bird</d></b><b s='2'><c>5</c><d>dinosaur</d></b></a>;
var xml2 = <a><b s='1'><c>55</c><d>bird</d></b><b s='2'><c>5</c><d>dinosaur</d></b></a>;
             
AddTestCase("Remove namespace without prefix", xml2,
             xml1.removeNamespace(n2), xml1);


END();
