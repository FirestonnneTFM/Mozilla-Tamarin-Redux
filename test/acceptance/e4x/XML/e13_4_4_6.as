/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.4.4.6 - XML child()");

//TEST(1, true, XML.prototype.hasOwnProperty("child"));

emps =
<employees>
    <employee id="0"><name>Jim</name><age>25</age></employee>
    <employee id="1"><name>Joe</name><age>20</age></employee>
</employees>;

correct =
<employee id="0"><name>Jim</name><age>25</age></employee> +
<employee id="1"><name>Joe</name><age>20</age></employee>;


TEST(2, correct, emps.child("employee"));

TEST(3, <name>Joe</name>, emps.employee[1].child("name"));

correct = <employee id="1"><name>Joe</name><age>20</age></employee>;

TEST(4, correct, emps.child(1));

var xmlDoc = "<MLB><Team>Giants</Team><City>San Francisco</City><Team>Padres</Team><City>San Diego</City></MLB>";

// Rhino returns "<Team>Giants</Team>\n<Team>Padres></Team>"

// propertyName as a string
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child('Team')", "<Team>Giants</Team>" + NL() + "<Team>Padres</Team>",
             (MYXML = new XML(xmlDoc), MYXML.child('Team').toString() ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child('Team') instanceof XMLList", true,
             (MYXML = new XML(xmlDoc), MYXML.child('Team') instanceof XMLList ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child('Team') instanceof XML", false,
             (MYXML = new XML(xmlDoc), MYXML.child('Team') instanceof XML ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child('Team').length()", 2,
             (MYXML = new XML(xmlDoc), MYXML.child('Team').length()));
AddTestCase( "MYXML = new XML(null), MYXML.child('Team')", "",
             (MYXML = new XML(null), MYXML.child('Team').toString() ));
AddTestCase( "MYXML = new XML(undefined), MYXML.child('Team')", "",
             (MYXML = new XML(undefined), MYXML.child('Team').toString() ));
AddTestCase( "MYXML = new XML(), MYXML.child('Team')", "",
             (MYXML = new XML(), MYXML.child('Team').toString() ));

// propertyName as a numeric index
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child(1) instanceof XMLList", true,
             (MYXML = new XML(xmlDoc), MYXML.child(1) instanceof XMLList ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child(1)", "San Francisco",
             (MYXML = new XML(xmlDoc), MYXML.child(1).toString() ));
AddTestCase( "MYXML = new XML(null), MYXML.child(1)", "",
             (MYXML = new XML(null), MYXML.child(1).toString() ));
AddTestCase( "MYXML = new XML(undefined), MYXML.child(1)", "",
             (MYXML = new XML(undefined), MYXML.child(1).toString() ));
AddTestCase( "MYXML = new XML(), MYXML.child(1)", "",
             (MYXML = new XML(), MYXML.child(1).toString() ));

AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child(0) instanceof XMLList", true,
             (MYXML = new XML(xmlDoc), MYXML.child(0) instanceof XMLList ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child(0)", "Giants",
             (MYXML = new XML(xmlDoc), MYXML.child(0).toString() ));
AddTestCase( "MYXML = new XML(null), MYXML.child(0)", "",
             (MYXML = new XML(null), MYXML.child(0).toString() ));
AddTestCase( "MYXML = new XML(undefined), MYXML.child(0)", "",
             (MYXML = new XML(undefined), MYXML.child(0).toString() ));
AddTestCase( "MYXML = new XML(), MYXML.child(0)", "",
             (MYXML = new XML(), MYXML.child(0).toString() ));

// propertyName is invalid

// invalid propertyName
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child('DoesNotExist') instanceof XMLList", true,
             (MYXML = new XML(xmlDoc), MYXML.child('DoesNotExist') instanceof XMLList ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child('DoesNotExist')", "",
             (MYXML = new XML(xmlDoc), MYXML.child('DoesNotExist').toString() ));
AddTestCase( "MYXML = new XML(null), MYXML.child('DoesNotExist')", "",
             (MYXML = new XML(null), MYXML.child('DoesNotExist').toString() ));
AddTestCase( "MYXML = new XML(undefined), MYXML.child('DoesNotExist')", "",
             (MYXML = new XML(undefined), MYXML.child('DoesNotExist').toString() ));
AddTestCase( "MYXML = new XML(), MYXML.child('DoesNotExist')", "",
             (MYXML = new XML(), MYXML.child('DoesNotExist').toString() ));

// invalid index
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child(8) instanceof XMLList", true,
             (MYXML = new XML(xmlDoc), MYXML.child(8) instanceof XMLList ));
AddTestCase( "MYXML = new XML(xmlDoc), MYXML.child(8)", "",
             (MYXML = new XML(xmlDoc), MYXML.child(8).toString() ));
AddTestCase( "MYXML = new XML(null), MYXML.child(8)", "",
             (MYXML = new XML(null), MYXML.child(8).toString() ));
AddTestCase( "MYXML = new XML(undefined), MYXML.child(8)", "",
             (MYXML = new XML(undefined), MYXML.child(8).toString() ));
AddTestCase( "MYXML = new XML(), MYXML.child(8)", "",
             (MYXML = new XML(), MYXML.child(8).toString() ));


END();
