/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("13.5.4.10 - XMLList elements()");

//TEST(1, true, XMLList.prototype.hasOwnProperty("elements"));
    
var xmlDoc = "<MLB><Team>Giants</Team><City>San Francisco</City><Team>Padres</Team><City>San Diego</City></MLB>";

// !!@ need to verify results of these test cases
// !!@ elements appears to be broken in Rhino

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.elements('Team').toString()", "<Team>Giants</Team>" + NL() + "<Team>Padres</Team>",
             (MYXML = new XMLList(xmlDoc), MYXML.elements('Team').toString()) );

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.elements('TEAM').toString()", "",
             (MYXML = new XMLList(xmlDoc), MYXML.elements('TEAM').toString()) );

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.elements('bogus').toString()", "",
             (MYXML = new XMLList(xmlDoc), MYXML.elements('bogus').toString()) );

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.elements()", "<Team>Giants</Team>" + NL() + "<City>San Francisco</City>" + NL() + "<Team>Padres</Team>" + NL() + "<City>San Diego</City>",
             (MYXML = new XMLList(xmlDoc), MYXML.elements().toString()) );
    
xmlDoc = "<MLB><Team>Giants</Team><City>San Francisco</City></MLB>";

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.elements('City').toString()", "San Francisco",
             (MYXML = new XMLList(xmlDoc), MYXML.elements('City').toString()) );

xmlDoc = "<A><MLB><Team>Giants</Team><City>San Francisco</City><Team>Padres</Team><City>San Diego</City></MLB></A>";

AddTestCase( "MYXML = new XMLList(xmlDoc), MYXML.elements('MLB')", "<MLB>" + NL() + "  <Team>Giants</Team>" + NL() + "  <City>San Francisco</City>" + NL() + "  <Team>Padres</Team>" + NL() + "  <City>San Diego</City>" + NL() + "</MLB>",
             (MYXML = new XMLList(xmlDoc), MYXML.elements('MLB').toString()) );

END();
