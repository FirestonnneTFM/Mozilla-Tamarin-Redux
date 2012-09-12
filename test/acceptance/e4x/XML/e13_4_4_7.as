/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.7 - XML childIndex()");

//TEST(1, true, XML.prototype.hasOwnProperty("childIndex"));

emps =
<employees>
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

TEST(2, 0, emps.employee[0].childIndex());

// Get the ordinal index of the employee named Joe
TEST(3, 1, emps.employee.(age == "20").childIndex());
TEST(4, 1, emps.employee.(name == "Joe").childIndex());

var xmlDoc = "<MLB><Team>Giants</Team><City>San Francisco</City><Team>Padres</Team><City>San Diego</City></MLB>";

// valid test cases
// MYXML.child(0) returns an XMLList with one node
// The [0] returns the first element in the list which should be child 0
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child(0)[0].childIndex()", 0,
             (MYXML = new XML(xmlDoc), MYXML.child(0)[0].childIndex() ));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child(1)[0].childIndex()", 1,
             (MYXML = new XML(xmlDoc), MYXML.child(1)[0].childIndex() ));

// what does childIndex return if there is no parent
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.childIndex()", -1,
             (MYXML = new XML(xmlDoc), MYXML.childIndex() ));

END();
