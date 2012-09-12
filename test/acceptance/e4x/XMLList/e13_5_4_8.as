/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.8 - XMLList copy()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("copy"));

emps = new XMLList();
emps += <employee id="0"><name>Jim</name><age>25</age></employee>;
emps += <employee id="1"><name>Joe</name><age>20</age></employee>;

correct = new XMLList();
correct += <employee id="0"><name>Jim</name><age>25</age></employee>;
correct += <employee id="1"><name>Joe</name><age>20</age></employee>;

TEST(2, emps, emps.copy());
TEST(3, correct, emps.copy());

// Make sure we're getting a copy, not a ref to orig.
emps = new XMLList();
emps += <employee id="0"><name>Jim</name><age>25</age></employee>;
emps += <employee id="1"><name>Joe</name><age>20</age></employee>;
   
correct = new XMLList();
correct += <employee id="0"><name>Jim</name><age>25</age></employee>;
correct += <employee id="1"><name>Joe</name><age>20</age></employee>;

x1 = emps.copy();

emps += <employee id="2"><name>Sue</name><age>32</age></employee>;

TEST(4, correct, x1);

XML.prettyPrinting = false;
var xmlDoc = "<MLB><Team>Giants</Team><City>San Francisco</City><Team>Padres</Team><City>San Diego</City></MLB>";

AddTestCase( "MYXML = new XMLList(xmlDoc), XMLCOPY = MYXML.copy()", xmlDoc,
             (MYXML = new XMLList(xmlDoc), XMLCOPY = MYXML.copy(), XMLCOPY.toString()) );
AddTestCase( "MYXML = new XMLList(null), XMLCOPY = MYXML.copy()", "",
             (MYXML = new XMLList(null), XMLCOPY = MYXML.copy(), XMLCOPY.toString()) );
AddTestCase( "MYXML = new XMLList(undefined), XMLCOPY = MYXML.copy()", MYXML.toString(),
             (MYXML = new XMLList(undefined), XMLCOPY = MYXML.copy(), XMLCOPY.toString()) );
AddTestCase( "MYXML = new XMLList(), XMLCOPY = MYXML.copy()", MYXML.toString(),
             (MYXML = new XMLList(), XMLCOPY = MYXML.copy(), XMLCOPY.toString()) );
AddTestCase( "MYXML = new XMLList(xmlDoc), XMLCOPY = MYXML.Team.copy()", "<Team>Giants</Team>" + NL() + "<Team>Padres</Team>",
             (MYXML = new XMLList(xmlDoc), XMLCOPY = MYXML.Team.copy(), XMLCOPY.toString()) );

// Make sure it's a copy
var MYXML = new XMLList(xmlDoc);
var MYXML2 = MYXML.copy();
AddTestCase ("MYXML == MYXML.copy()", true, (MYXML == MYXML.copy()));
MYXML2.foo = "bar";
//MYXML2 = new XML("<blah>hi</blah>");
AddTestCase ("MYXML == MYXML2 where MYXML2 is a copy that has been changed", false, (MYXML == MYXML2));

END();
