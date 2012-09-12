/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.30 - propertyIsEnumerable()");

//TEST(1, true, XML.prototype.hasOwnProperty("propertyIsEnumerable"));

// All properties accessible by Get are enumerable
x1 =
<alpha>
    <bravo>one</bravo>
</alpha>;

TEST(2, true, x1.propertyIsEnumerable("0"));
TEST(3, true, x1.propertyIsEnumerable(0));
TEST(5, false, x1.propertyIsEnumerable("bravo"));
TEST(6, false, x1.propertyIsEnumerable());
TEST(7, false, x1.propertyIsEnumerable(undefined));
TEST(8, false, x1.propertyIsEnumerable(null));

var xmlDoc = "<xml><employee id='1'><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee><employee id='2'><firstname>Sue</firstname><lastname>Day</lastname><age>32</age></employee></xml>"

// propertyName as a string
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.propertyIsEnumerable(0)", true,
             (MYXML = new XML(xmlDoc), MYXML.propertyIsEnumerable('0')));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.propertyIsEnumerable(1)", false,
             (MYXML = new XML(xmlDoc), MYXML.propertyIsEnumerable('1')));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.propertyIsEnumerable(2)", false,
             (MYXML = new XML(xmlDoc), MYXML.propertyIsEnumerable('2')));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.propertyIsEnumerable('employee')", false,
             (MYXML = new XML(xmlDoc), MYXML.propertyIsEnumerable('employee')));

END();
