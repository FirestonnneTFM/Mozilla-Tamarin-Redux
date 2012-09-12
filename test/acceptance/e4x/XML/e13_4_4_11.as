/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.11 - XML copy()");

//TEST(1, true, XML.prototype.hasOwnProperty("copy"));

emps =
<employees>
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

correct =
<employee id="0"><name>Jim</name><age>25</age></employee>;

x1 = emps.employee[0].copy();

TEST(2, undefined, x1.parent());
TEST(3, correct, x1);
 
// Make sure we're getting a copy, not a ref to orig.
emps =
<employees>
    <employee id="0"><fname>Jim</fname><age>25</age></employee>
    <employee id="1"><fname>Joe</fname><age>20</age></employee>
</employees>;

correct =
<employee id="0"><fname>Jim</fname><age>25</age></employee>

empCopy = emps.employee[0].copy();

emps.employee[0].fname[0] = "Sally";

TEST(4, correct, empCopy);

// Try copying whole XML twice
emps =
<employees>
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

empCopy = emps.copy();
x1 = empCopy.copy();

TEST(5, x1, emps);

XML.prettyPrinting = false;
var xmlDoc = "<MLB><Team>Giants</Team><City>San Francisco</City><Team>Padres</Team><City>San Diego</City></MLB>";

AddTestCase( "MYXML = new XML(xmlDoc), XMLCOPY = MYXML.copy()", xmlDoc,
             (MYXML = new XML(xmlDoc), XMLCOPY = MYXML.copy(), XMLCOPY.toString()) );
AddTestCase( "MYXML = new XML(null), XMLCOPY = MYXML.copy()", "",
             (MYXML = new XML(null), XMLCOPY = MYXML.copy(), XMLCOPY.toString()) );
AddTestCase( "MYXML = new XML(undefined), XMLCOPY = MYXML.copy()", MYXML.toString(),
             (MYXML = new XML(undefined), XMLCOPY = MYXML.copy(), XMLCOPY.toString()) );
AddTestCase( "MYXML = new XML(), XMLCOPY = MYXML.copy()", MYXML.toString(),
             (MYXML = new XML(), XMLCOPY = MYXML.copy(), XMLCOPY.toString()) );
AddTestCase( "MYXML = new XML(xmlDoc), XMLCOPY = MYXML.Team.copy()", "<Team>Giants</Team>" + NL() + "<Team>Padres</Team>",
             (MYXML = new XML(xmlDoc), XMLCOPY = MYXML.Team.copy(), XMLCOPY.toString()) );

// Make sure it's a copy
var MYXML = new XML(xmlDoc);
var MYXML2 = MYXML.copy();
AddTestCase ("MYXML == MYXML.copy()", true, (MYXML == MYXML.copy()));
MYXML2.foo = "bar";
AddTestCase ("MYXML == MYXML2 where MYXML2 is a copy that has been changed", false, (MYXML == MYXML2));

END();
