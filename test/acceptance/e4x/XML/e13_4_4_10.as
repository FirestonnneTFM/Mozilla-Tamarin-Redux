/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.10 - XML contains()");

//TEST(1, true, XML.prototype.hasOwnProperty("contains"));

emps =
<employees>
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

TEST(2, true, emps.contains(emps));

var xmlDoc = "<MLB><Team>Giants</Team><City>San Francisco</City><Team>Padres</Team><City>San Diego</City></MLB>";

// same object, returns true
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.contains(MYMXL)", true,
             (MYXML = new XML(xmlDoc), MYXML.contains(MYXML)) );
             
// duplicated object, returns true
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.contains(MYMXL.copy())", true,
             (MYXML = new XML(xmlDoc), MYXML.contains(MYXML.copy())) );
             
// identical objects, returns true
AddTestCase( "MYXML = new XML(xmlDoc), MYXML2 = new XML(xmlDoc), MYXML.contains(MYMXL2)", true,
             (MYXML = new XML(xmlDoc), MYXML2 = new XML(xmlDoc), MYXML.contains(MYXML2)) );
             
// identical objects, returns true
AddTestCase( "MYXML = new XML(xmlDoc), MYXML2 = new XML(xmlDoc), MYXML2.contains(MYMXL)", true,
             (MYXML = new XML(xmlDoc), MYXML2 = new XML(xmlDoc), MYXML2.contains(MYXML)) );
             
// slightly different objects, returns false
AddTestCase( "MYXML = new XML(xmlDoc), MYXML2 = new XML(xmlDoc), MYXML2.foo = 'bar', MYXML.contains(MYMXL2)", false,
             (MYXML = new XML(xmlDoc), MYXML2 = new XML(xmlDoc), MYXML2.foo = 'bar', MYXML.contains(MYXML2)) );

// slightly different objects #2, returns false
AddTestCase( "MYXML = new XML(xmlDoc), MYXML2 = new XML(xmlDoc), MYXML2.Team[0].foo = 'bar', MYXML.contains(MYMXL2)", false,
             (MYXML = new XML(xmlDoc), MYXML2 = new XML(xmlDoc), MYXML2.Team[0].foo = 'bar', MYXML.contains(MYXML2)) );

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.Team[0].contains('Giants')", false,
             (MYXML = new XML(xmlDoc), MYXML.Team[0].contains('Giants')) );
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.Team[1].contains('Giants')", false,
             (MYXML = new XML(xmlDoc), MYXML.Team[1].contains('Giants')) );
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.City.contains('Giants')", false,
             (MYXML = new XML(xmlDoc), MYXML.City.contains('Giants')) );

END();
