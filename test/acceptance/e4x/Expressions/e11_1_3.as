/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("11.1.3 - Wildcard Identifiers");

var x1 =
<alpha>
    <bravo>one</bravo>
    <charlie>two</charlie>
</alpha>

var correct = new XMLList("<bravo>one</bravo><charlie>two</charlie>");
TEST(1, correct, x1.*);

XML.ignoreWhitespace = false;

var xml1 = "<p><a>1</a><a>2</a><a>3</a></p>";
var xml2 = "<a>1</a><a>2</a><a>3</a>";
var xml3 = "<a><e f='a'>hey</e><e f='b'> </e><e f='c'>there</e></a><a>2</a><a>3</a>";
var xml4 = "<p><a hi='a' he='v' ho='m'>hello</a></p>";

var ns1 = new Namespace('foobar', 'http://boo.org');
var ns2 = new Namespace('fooboo', 'http://foo.org');
var ns3 = new Namespace('booboo', 'http://goo.org');

AddTestCase("x.a.*", "123", (x1 = new XML(xml1), x1.a.*.toString()));

AddTestCase("xmllist.a.*", "123", (x1 = new XMLList(xml1), x1.a.*.toString()));

AddTestCase("xmllist.*", "123", (x1 = new XMLList(xml2), x1.*.toString()));

AddTestCase("xmllist[0].*", "1", (x1 = new XMLList(xml2), x1[0].*.toString()));

AddTestCase("xmllist[0].e.*", "hey there", (x1 = new XMLList(xml3), x1[0].e.*.toString()));

AddTestCase("xml.a.@*", "avm", (x1 = new XML(xml4), x1.a.@*.toString()));


END();
