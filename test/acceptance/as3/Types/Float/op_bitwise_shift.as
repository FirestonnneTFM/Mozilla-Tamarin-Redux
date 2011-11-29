/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2011
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

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

