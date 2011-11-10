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
include "floatUtil.as";


var SECTION = "6.9";
var VERSION = "AS3";
var TITLE   = "The binary bitwise operators augmented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var f1:float = -1.2345678e9; // TODO: use float literals
var f2:float = 3.1234f;
var twof:float = 2f;
var val1:float;
var val2:float;

AddTestCase("Bitwise AND on floats returns a int", "int", getQualifiedClassName(f1&2));
AddTestCase("Bitwise AND on FloatLiteral returns a int", "int", getQualifiedClassName(-1.2345678e9f&3.1223f));
AddStrictTestCase("Bitwise AND on float.MIN_VALUE and float(0xFFFFFF00)", 0, float.MIN_VALUE&float(0xFFFFFF00));
AddStrictTestCase("Bitwise AND on 4294967040 and float(0xFFFFFF00)", int(0xFFFFFF00), 4294967040&float(0xFFFFFF00));
AddStrictTestCase("Bitwise AND on float(0xFFFFFF00) and 4294967040", int(0xFFFFFF00), float(0xFFFFFF00)&4294967040);

val1 = 5f;
val2 = 3f;
AddStrictTestCase("Bitwise AND on 5f and 3f", 1, val1&val2);
AddStrictTestCase("Bitwise AND on FloatLiteral 5f and 3f", 1, 5f&3f);

val1 = 3.125f;
val2 = 2.1f;
AddStrictTestCase("Bitwise AND on 3.125f and 2.1f", 2, val1&val2);
AddStrictTestCase("Bitwise AND on FloatLiteral 3.125f and 2.1f", 2, 3.125f&2.1f);

val1 = 0.62e+1f;
val2 = 131.25e-1f;
AddStrictTestCase("Bitwise AND on 0.62e-1f and 1.3125e+1f", 4, val1&val2);
AddStrictTestCase("Bitwise AND on FloatLiteral 0.62e-1f and 1.3125e+1f", 4, 0.62e+1f&131.25e-1f);



AddTestCase("Bitwise XOR on floats returns a int", "int", getQualifiedClassName(twof^2));
AddTestCase("Bitwise XOR on FloatLiteral returns a int", "int", getQualifiedClassName(2f^2f));
AddStrictTestCase("Bitwise XOR on float.MIN_VALUE and float(0xFFFFFF00)", int(0xFFFFFF00), float.MIN_VALUE^float(0xFFFFFF00));
AddStrictTestCase("Bitwise XOR on 4294967040 and float(0xFFFFFF00)", 0, 4294967040^float(0xFFFFFF00));
AddStrictTestCase("Bitwise XOR on float(0xFFFFFF00) and 4294967040", 0, float(0xFFFFFF00)^4294967040);

val1 = 5f;
val2 = 3f;
AddStrictTestCase("Bitwise XOR on 5f and 3f", 6, val1^val2);
AddStrictTestCase("Bitwise XOR on FloatLiteral 5f and 3f", 6, 5f^3f);

val1 = 3.125f;
val2 = 2.1f;
AddStrictTestCase("Bitwise XOR on 3.125f and 2.1f", 1, val1^val2);
AddStrictTestCase("Bitwise XOR on FloatLiteral 3.125f and 2.1f", 1, 3.125f^2.1f);

val1 = 0.62e+1f;
val2 = 131.25e-1f;
AddStrictTestCase("Bitwise XOR on 0.62e-1f and 1.3125e+1f", 11, val1^val2);
AddStrictTestCase("Bitwise XOR on FloatLiteral 0.62e-1f and 1.3125e+1f", 11, 0.62e+1f^131.25e-1f);


AddTestCase("Bitwise OR on floats returns a int", "int", getQualifiedClassName(twof|2));
AddTestCase("Bitwise OR on FloatLiteral returns a int", "int", getQualifiedClassName(2f|2f));
AddStrictTestCase("Bitwise OR on float.MIN_VALUE and float(0xFFFFFF00)", int(0xFFFFFF00), float.MIN_VALUE|float(0xFFFFFF00));
AddStrictTestCase("Bitwise OR on 4294967040 and float(0xFFFFFF00)", -256, 4294967040|float(0xFFFFFF00));
AddStrictTestCase("Bitwise OR on float(0xFFFFFF00) and 4294967040", -256, float(0xFFFFFF00)|4294967040);

val1 = 5f;
val2 = 3f;
AddStrictTestCase("Bitwise OR on 5f and 3f", 7, val1|val2);
AddStrictTestCase("Bitwise OR on FloatLiteral 5f and 3f", 7, 5f|3f);

val1 = 3.125f;
val2 = 2.1f;
AddStrictTestCase("Bitwise OR on 3.125f and 2.1f", 3, val1|val2);
AddStrictTestCase("Bitwise OR on FloatLiteral 3.125f and 2.1f", 3, 3.125f|2.1f);

val1 = 0.62e+1f;
val2 = 131.25e-1f;
AddStrictTestCase("Bitwise OR on 0.62e-1f and 1.3125e+1f", 15, val1|val2);
AddStrictTestCase("Bitwise OR on FloatLiteral 0.62e-1f and 1.3125e+1f", 15, 0.62e+1f|131.25e-1f);


test();


