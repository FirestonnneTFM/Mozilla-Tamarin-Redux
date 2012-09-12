/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.3.1 - QName Constructor as a Function");

q = QName("foobar");
p = new QName("foobar");
TEST(1, typeof(p), typeof(q));
TEST(2, p.localName, q.localName);
TEST(3, p.uri, q.uri);

q = QName("http://foobar/", "foobar");
p = new QName("http://foobar/", "foobar");
TEST(4, typeof(p), typeof(q));
TEST(5, p.localName, q.localName);
TEST(6, p.uri, q.uri);

p1 = QName(q);
p2 = new QName(q);
TEST(7, typeof(p2), typeof(p1));
TEST(8, p2.localName, p1.localName);
TEST(9, p2.uri, p1.uri);

n = new Namespace("http://foobar/");
q = QName(n, "foobar");
p = QName(n, "foobar");
TEST(10, typeof(p), typeof(q));
TEST(11, p.localName, q.localName);
TEST(12, p.uri, q.uri);

p = QName(q);
TEST(13, p, q);

// One value is supplied
AddTestCase( "QName('name').valueOf().toString()", 'name', QName('name').valueOf().toString() );
AddTestCase( "QName('name').valueOf() == 'name'", true, QName('name').valueOf() == 'name' );
AddTestCase( "typeof QName('name')", "object", typeof QName('name') );
//AddTestCase( "QName('name').__proto__", Namespace.prototype, QName('name').__proto__ );

// If one parameter is QName, same value is returned
AddTestCase ("foo = QName('foo'), bar = Qname(foo), bar === foo", true,
    (foo = QName("foo"), bar = QName(foo), bar === foo));

// If one parameter is QName but there is a Namespace param, different object is returned
AddTestCase ("foo = QName('foo'), bar = Qname(\"\", foo), bar === foo", false,
    (foo = QName("foo"), bar = QName("", foo), bar === foo));


//Two values are supplied
AddTestCase( "ns = new Namespace('duh'), QName(ns, 'name')",
    "duh::name",
    (ns = new Namespace('duh'), QName(ns, 'name').toString() ));
    
AddTestCase( "ns = new Namespace('duh'), typeof QName(ns, 'name')",
    "object",
    ( ns = new Namespace('duh'), typeof QName(ns, 'name') ));

AddTestCase( "ns = new Namespace('duh'), typeof QName(ns, 'name')",
    true,
    ( ns = new Namespace('duh'), QName(ns, 'name') instanceof QName));


END();
