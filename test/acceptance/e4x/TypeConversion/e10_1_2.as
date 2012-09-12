/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("10.1.2 - XMLList.toString");

// One XML object

var x1  = new XML("<a>A</a>");
var x_ = x1.toString();
var y1  = "A";

AddTestCase( "ToString(XMLList:one XML object)                                     :", true, (x_==y1) );

/*---------------------------------------------------------------------------*/

x1  = new XML("<!-- [[Class]]='comment' -->");
x_ = x1.toString();
y1  = "";

AddTestCase( "ToString(XMLList:one XML object, [[Class]]='comment')                :", true, (x_==y1) );

/*---------------------------------------------------------------------------*/

x1  = new XML("<? xm-xsl-param name='Name' value='Value' ?>");
x_ = x1.toString();
y1  = "";

AddTestCase( "ToString(XMLList:one XML object, [[Class]]='processing-instruction') :", true, (x_==y1) );

/*---------------------------------------------------------------------------*/
XML.prettyPrinting = false;
x1  = new XMLList("<a><b>A</b><c>B</c></a><a><b>C</b><c>D</c></a>");
x_ = x1.toString();
y1  = "<a><b>A</b><c>B</c></a>\n<a><b>C</b><c>D</c></a>";

AddTestCase( "ToString(XMLList:multiple XML objects)                               :", true, (x_==y1) );

END();
