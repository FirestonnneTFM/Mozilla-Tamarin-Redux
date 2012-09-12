/* -*- Mode: java; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

START("10.3 - toXML");

var x1;

// boolean
x1 = new Boolean(true);
TEST_XML(1, "true", new XML(x1));

// number
x1 = new Number(123);
TEST_XML(2, "123", new XML(x1));

// String
x1 = new String("<alpha><bravo>one</bravo></alpha>");
TEST(3, <alpha><bravo>one</bravo></alpha>, new XML(x1));

// XML
x1 = new XML("<alpha><bravo>one</bravo></alpha>");
TEST(4, <alpha><bravo>one</bravo></alpha>, new XML(x1));

// XMLList
x1 = new XMLList("<alpha><bravo>one</bravo></alpha>");
TEST(5, <alpha><bravo>one</bravo></alpha>, new XML(x1));

try {
    x1 = new XMLList(<alpha>one</alpha> + <bravo>two</bravo>);
    new XML(x1);
    SHOULD_THROW(6);
} catch (ex) {
    TEST(6, "TypeError", ex.name);
}
/*
// Undefined

try
{
    ToXML(undefined);
    AddTestCase( "ToXML(undefined) :", true, false );
}
catch (e)
{
    AddTestCase( "ToXML(undefined) :", true, true );
}


// Null

try
{
    ToXML(null);
    AddTestCase( "ToXML(null)      :", true, false );
}
catch (e)
{
    AddTestCase( "ToXML(null)      :", true, true );
}


// Boolean

var xt = "<parent xmlns=''>true</parent>";
var xf = "<parent xmlns=''>false</parent>";

AddTestCase( "ToXML(true)      :", true, (ToXML(true)==xt) );
AddTestCase( "ToXML(false)     :", true, (ToXML(false)==xf) );


// Number

var xn = "<parent xmlns=''>1234</parent>";

AddTestCase( "ToXML(1234)      :", true, (ToXML(1234)==xn) );


// XML

var x1 = new XML("<a><b>A</b></a>");

AddTestCase( "ToXML(XML)       :", true, (ToXML(x1)==x1) );


// XMLList

x1 = new XML("<a>A</a>");

AddTestCase( "ToXML(XMLList)   :", true, (ToXML(x1)=="A") );


// XMLList - XMLList contains more than one property

x1 = <a>A</a>
    <b>B</b>
    <c>C</c>;

try
{
    ToXML(x);
    AddTestCase( "ToXML(XMLList)   :", true, false );
}
catch (e)
{
    AddTestCase( "ToXML(XMLList)   :", true, true );
}


// Object

var a = new Array();

try
{
    ToXML(a);
    AddTestCase( "ToXML(Object)    :", true, false );
}
catch (e)
{
    AddTestCase( "ToXML(Object)    :", true, true );
}
*/
END();
