/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import avmplus.System

START("13.4.4.32 - XML replace()");

//TEST(1, true, XML.prototype.hasOwnProperty("replace"));

// Replace the first employee record with an open staff requisition
emps =
<employees>
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

correct =
<employees>
    <requisition status="open" />
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

emps.replace(0, <requisition status="open" />);

TEST(2, correct, emps);

// Replace all children with open staff requisition

emps =
<employees>
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

correct =
<employees>
    <requisition status="open" />
</employees>;

emps.replace("*", <requisition status="open" />);

TEST(3, correct, emps);

// Replace all employee elements with open staff requisition

emps =
<employees>
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

correct =
<employees>
    <requisition status="open" />
</employees>;

emps.replace("employee", <requisition status="open" />);

TEST(4, correct, emps);

XML.prettyPrinting = false;
var xmlDoc = "<employee id='1'><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee>"

// propertyName as a string
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.replace(0,'Mr. John')",
    "<employee id=\"1\">Mr. John<lastname>Walton</lastname><age>25</age></employee>",
             (MYXML = new XML(xmlDoc), MYXML.replace(0,'Mr. John').toString()));

xmlDoc = "<employee id='1'><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee>"

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.replace('phone','542144')",
    "<employee id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee>",
             (MYXML = new XML(xmlDoc), MYXML.replace('phone','542144').toString()));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.replace('firstname','Johnny')",
    "<employee id=\"1\">Johnny<lastname>Walton</lastname><age>25</age></employee>",
             (MYXML = new XML(xmlDoc), MYXML.replace('firstname','Johnny').toString()));

var expectedResult;
if (System.swfVersion < 10)
    expectedResult = '<employee id="1"><phone>1234567</phone></employee>';
else
    expectedResult = '<phone>1234567</phone>';

// This should replace all the children
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.replace('*','<phone>1234567</phone>')",
    expectedResult,
             (MYXML = new XML(xmlDoc), MYXML.replace('*',"<phone>1234567</phone>").toString()));

// What about using an attribute name as a input parameter
// !!@ Rhino does an attribute addition after id!?!?
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.replace('@phone','<phone>7654321</phone>')",
    "<employee id=\"1\"><firstname>John</firstname><lastname>Walton</lastname><age>25</age></employee>",
             (MYXML = new XML(xmlDoc), MYXML.replace('@phone',"<phone>7654321</phone>").toString()));



END();
