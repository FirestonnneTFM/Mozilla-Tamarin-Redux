/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.20 - XML length()");

//TEST(1, true, XML.prototype.hasOwnProperty("length"));

x1 =
<alpha attr1="value1">
    <bravo>one</bravo>
    <charlie>
        two
        three
        <echo>four</echo>
    </charlie>
    <delta />
</alpha>;

TEST(2, 1, x1.length());
TEST(3, 1, x1.bravo.length());
TEST(4, 1, x1.charlie.length());
TEST(5, 1, x1.delta.length());

var xmlDoc = "<xml><employee id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee><employee id=\"2\"><firstname>Sue</firstname><lastname>Day</lastname><age>32</age></employee></xml>"


// propertyName as a string
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.length()", 1,
             (MYXML = new XML(xmlDoc), MYXML.length()));

AddTestCase( "MYXML = new XML(), MYXML.length()", 1,
             (MYXML = new XML(), MYXML.length()));

AddTestCase( "MYXML = new XML(null), MYXML.length()", 1,
             (MYXML = new XML(null), MYXML.length()));

AddTestCase( "MYXML = new XML(undefined), MYXML.length()", 1,
             (MYXML = new XML(undefined), MYXML.length()));

AddTestCase( "MYXML = new XML('foo'), MYXML.length()", 1,
             (MYXML = new XML("foo"), MYXML.length()));

XML.ignoreComments = false;
AddTestCase( "MYXML = new XML('<XML><!-- comment --></XML>'), MYXML.length()", 1,
             (MYXML = new XML("<XML><!-- comment --></XML>"), MYXML.length()));

END();
