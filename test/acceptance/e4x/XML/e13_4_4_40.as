/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.40 - valueOf");

//TEST(1, true, XML.prototype.hasOwnProperty("valueOf"));

x1 =
<alpha>
    <bravo>one</bravo>
</alpha>;

TEST(2, x1, x1.valueOf());

// Make sure they're the same and not copies

x1 =
<alpha>
    <bravo>one</bravo>
</alpha>;

y1 = x1.valueOf();

x1.bravo = "two";

TEST(3, x1, y1);

var xmlDoc = "<employees><employee id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee></employees>"


// propertyName as a string
var MYXML = new XML(xmlDoc);
AddTestCase( "MYXML = new XML(xmlDoc),MYXML.valueOf() === MYXML",
    true,
    (MYXML.valueOf() === MYXML));
MYXML = new XML();
AddTestCase( "MYXML = new XML(),MYXML.valueOf() === MYXML",
    true,
    (MYXML.valueOf() === MYXML));
MYXML = new XML('');
AddTestCase( "MYXML = new XML(''),MYXML.valueOf() === MYXML",
    true,
    (MYXML.valueOf() === MYXML));
MYXML = new XML('foo');
AddTestCase( "MYXML = new XML('foo'),MYXML.valueOf() === MYXML",
    true,
    (MYXML.valueOf() === MYXML));

END();
