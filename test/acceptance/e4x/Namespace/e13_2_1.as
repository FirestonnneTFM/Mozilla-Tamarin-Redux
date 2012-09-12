/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.2.1 - Namespace Constructor as Function");

n = Namespace();
m = new Namespace();
TEST(1, typeof(m), typeof(n));
TEST(2, m.prefix, n.prefix);
TEST(3, m.uri, n.uri);

n = Namespace("http://foobar/");
m = new Namespace("http://foobar/");
TEST(4, typeof(m), typeof(n));
TEST(5, m.prefix, n.prefix);
TEST(6, m.uri, n.uri);

n = Namespace("foobar", "http://foobar/");
m = new Namespace("foobar", "http://foobar/");
TEST(7, typeof(m), typeof(n));
TEST(8, m.prefix, n.prefix);
TEST(9, m.uri, n.uri);

n = Namespace(m);
TEST(10, m, n);

var thisXML = "<XML><TEAM>Giants</TEAM><CITY>San Francisco</CITY></XML>";
var NULL_OBJECT = "";
 

// value is not supplied
AddTestCase( "Namespace()", NULL_OBJECT, Namespace().toString());
AddTestCase( "typeof Namespace()", "object", typeof Namespace() );
//AddTestCase( "Namespace().__proto__ == Namespace.prototype", true, Namespace().__proto__ == Namespace.prototype);

//One value is supplied
AddTestCase( "Namespace('pfx').toString()", 'pfx', Namespace('pfx').toString() );
AddTestCase( "typeof Namespace('pfx')", "object", typeof Namespace('pfx') );
//AddTestCase( "Namespace('pfx').__proto__ == Namespace.prototype", true, Namespace('pfx').__proto__ == Namespace.prototype);

var ns = new Namespace('http://foo.bar');
AddTestCase( "Namespace(nsObj).toString()", 'http://foo.bar', Namespace(ns).toString() );

//Two values are supplied
AddTestCase( "Namespace('pfx','ns') == new Namespace('pfx', 'ns')", new Namespace('pfx', 'http://www.w3.org/TR/html4/'), Namespace('pfx','http://www.w3.org/TR/html4/') );
AddTestCase( "typeof Namespace('pfx','http://www.w3.org/TR/html4/')", "object", typeof Namespace('pfx','http://www.w3.org/TR/html4/') );
//AddTestCase( "Namespace('pfx','http://www.w3.org/TR/html4/').__proto__ == Namespace.prototype", true, Namespace('pfx','http://www.w3.org/TR/html4/').__proto__ == Namespace.prototype );

ns = new Namespace('pfx', 'http://foo.bar');
AddTestCase( "Namespace(nsObj).toString()", 'http://foo.bar', Namespace(ns).toString() );

END();
