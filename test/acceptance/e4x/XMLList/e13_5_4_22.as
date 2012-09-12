/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.22 - XMLList valueOf()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("valueOf"));
    
var xmlDoc = "<employees><employee id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee></employees>"


// propertyName as a string
var MYXML = new XMLList(xmlDoc);
AddTestCase( "MYXML = new XMLList(xmlDoc),MYXML.valueOf() === MYXML",
    true,
    (MYXML.valueOf() === MYXML));
MYXML = new XMLList();
AddTestCase( "MYXML = new XMLList(),MYXML.valueOf() === MYXML",
    true,
    (MYXML.valueOf() === MYXML));
MYXML = new XMLList('');
AddTestCase( "MYXML = new XMLList(''),MYXML.valueOf() === MYXML",
    true,
    (MYXML.valueOf() === MYXML));
MYXML = new XMLList('foo');
AddTestCase( "MYXML = new XMLList('foo'),MYXML.valueOf() === MYXML",
    true,
    (MYXML.valueOf() === MYXML));

END();
