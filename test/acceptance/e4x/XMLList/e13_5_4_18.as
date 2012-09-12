/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.18 - XMLList propertyIsEnumerable()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("propertyIsEnumerable"));

var xmlDoc = "<xml><employee id='1'><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee><employee id='2'><firstname>Sue</firstname><lastname>Day</lastname><age>32</age></employee></xml><a>1</a>";
 
 // propertyName as a string
 AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.propertyIsEnumerable(0)", true,
              (MYXML = new XMLList(xmlDoc), MYXML.propertyIsEnumerable('0')));
 AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.propertyIsEnumerable(1)", true,
              (MYXML = new XMLList(xmlDoc), MYXML.propertyIsEnumerable('1')));
 AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.propertyIsEnumerable(2)", false,
              (MYXML = new XMLList(xmlDoc), MYXML.propertyIsEnumerable('2')));
 AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.propertyIsEnumerable('employee')", false,
             (MYXML = new XMLList(xmlDoc), MYXML.propertyIsEnumerable('employee')));

END();
