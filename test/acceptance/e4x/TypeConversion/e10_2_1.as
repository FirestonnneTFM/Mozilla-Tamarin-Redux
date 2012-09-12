/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("10.2.1 - XML.toXMLString");

// text

var x1  = new XML("abc & 123");
var x0 = x1.toXMLString();
var y0 = "abc &amp; 123";

AddTestCase( "ToXMLString(text)                          :", true, (x0==y0) );

/*---------------------------------------------------------------------------*/
// comment

x1  = new XML("<x><!-- Hello World --></x>");
x0 = x1.toXMLString();
y0 = "<x/>";

AddTestCase( "ToXMLString(comment)                       :", true, (x0==y0) );

/*---------------------------------------------------------------------------*/
// processing instruction

x1  = new XML("<?xml version='1.0'?><x>i</x>");
x0 = x1.toXMLString();
y0 = "<x>i</x>";

AddTestCase( "ToXMLString(processing-instruction)        :", true, (x0==y0) );

/*---------------------------------------------------------------------------*/
// ToXMLString ( x )

XML.ignoreWhitespace = true;

x1 = new XML("<a><b>B</b><c>C</c></a>");

x0 = x1.toXMLString();
y0 = "<a>\n  <b>B</b>\n  <c>C</c>\n</a>";

AddTestCase( "ToXMLString(XML)                           :", true, (x0==y0) );

END();
