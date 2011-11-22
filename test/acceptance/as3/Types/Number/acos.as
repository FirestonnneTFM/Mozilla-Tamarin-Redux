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

/*
Returns an implementation-dependent approximation to the arc cosine of x.
The result is expressed in radians and ranges from +0 to +PI.
*/

import avmplus.*;

var SECTION = "15.8.2.2";
var VERSION = "AS3";
var TITLE   = "public native static function acos (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.acos(param); }

AddTestCase("Number.acos() returns a Number", "Number", getQualifiedClassName(Number.acos(0)));
AddTestCase("Number.acos() length is 1", 1, Number.acos.length);
AddErrorTest("Number.acos() with no args", ARGUMENTERROR+1063,  function(){ Number.acos(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.acos(undefined)", NaN, Number.acos(undefined));
AddTestCase("Number.acos(string)", NaN, Number.acos("string"));
AddTestCase("Number.acos(NaN)", NaN, Number.acos(NaN));
AddTestCase("Number.acos(NaN) check()", NaN, check(NaN));

// If x is greater than 1, the result is NaN.
AddTestCase("Number.acos(1.125)", NaN, Number.acos(1.125));
AddTestCase("Number.acos(1.125) check()", NaN, check(1.125));

// If x is less than -1, the result is NaN.
AddTestCase("Number.acos(-1.125)", NaN, Number.acos(-1.125));
AddTestCase("Number.acos(-1.125) check", NaN, check(-1.125));

// If x is exactly 1, the result is +0.
AddTestCase("Number.acos(1)", 0, Number.acos(1));
AddTestCase("Ensure that Number.acos(1) returns +0", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.acos(1));


AddTestCase("Number.acos(null)", Number.PI/2.0, Number.acos(null));
AddTestCase("Number.acos(true)", 0, Number.acos(true));
AddTestCase("Number.acos(false)", Number.PI/2.0, Number.acos(false));

AddTestCase("Number.acos('1')", 0, Number.acos('1'));
AddTestCase("Number.acos('0')", Number.PI/2.0, Number.acos('0'));

var myNum:Number = 0;
AddTestCase("Number.acos(myNum=0)", Number.PI/2.0, Number.acos(myNum));
myNum = 1;
AddTestCase("Number.acos(myNum=1)", 0, Number.acos(myNum));
myNum = -1;
AddTestCase("Number.acos(myNum=-1)", Number.PI, Number.acos(myNum));
myNum = -0;
AddTestCase("Number.acos(myNum=-0)", Number.PI/2.0, Number.acos(myNum));

AddTestCase("Number.acos(0) NumberLiteral", Number.PI/2.0, Number.acos(0));
AddTestCase("Number.acos(1) NumberLiteral", 0, Number.acos(1));
AddTestCase("Number.acos(-1) NumberLiteral", Number.PI, Number.acos(-1));
AddTestCase("Number.acos(-0) NumberLiteral", Number.PI/2.0, Number.acos(-0));

AddTestCase("Number.acos(Number.SQRT1_2)", Number.PI/4.0, Number.acos(Number.SQRT1_2));
AddTestCase("Number.acos(-Number.SQRT1_2)", Number.PI/4.0*3.0, Number.acos(-Number.SQRT1_2));







test();

