/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "6.6";
var VERSION = "AS3";
var TITLE   = "The bitwise shift operators augmented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var f1:float = -1.2345678e9; // TODO: use float literals
var f2:float = 3.1234f;
var twof:float = 2f;

AddTestCase("left shift on float returns a Number", "Number", getQualifiedClassName(f1<<2));
AddTestCase("left shift on float", -643303936, f1<<2);
AddTestCase("left shift on FloatLiteral", 4, 1f<<2);
AddTestCase("float left shift on float", -643303936, f1<<twof);
AddTestCase("FloatLiteral left shift on FloatLiteral", 4, 1f<<2f);
AddTestCase("left shift on 3.1234f", 12, f2<<2);
AddTestCase("left shift on float.MIN_VALUE", 0, float.MIN_VALUE<<2);
AddTestCase("left shift on float.MAX_VALUE", 0, float.MAX_VALUE<<2);



AddTestCase("right shift on float returns a Number", "Number", getQualifiedClassName(f1>>2));
AddTestCase("right shift on float", -308641952, f1>>2);
AddTestCase("right shift on FloatLiteral", 25, 100f>>2);
AddTestCase("float right shift on float", -308641952, f1>>twof);
AddTestCase("FloatLiteral right shift on FloatLiteral", 25, 100f>>2f);
AddTestCase("right shift on 3.1234f", 0, f2>>2);
AddTestCase("right shift on float.MIN_VALUE", 0, float.MIN_VALUE>>2);
AddTestCase("right shift on float.MAX_VALUE", 0, float.MAX_VALUE>>2);



AddTestCase("right shift(unsigned) on float returns a Number", "Number", getQualifiedClassName(f1>>>2));
AddTestCase("right shift(unsigned) on float", 765099872, f1>>>2);
AddTestCase("right shift(unsigned) on FloatLiteral", 1073741799, -100f>>>2);
AddTestCase("float right shift(unsigned) on float", 765099872, f1>>>twof);
AddTestCase("FloatLiteral right shift(unsigned) on FloatLiteral", 1073741799, -100f>>>2f);
AddTestCase("right shift(unsigned) on 3.1234f", 0, f2>>>2);
AddTestCase("right shift(unsigned) on float.MIN_VALUE", 0, float.MIN_VALUE>>>2);
AddTestCase("right shift(unsigned) on float.MAX_VALUE", 0, float.MAX_VALUE>>>2);

test();

