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
Returns an implementation-dependent approximation to the arc tangent of x.
The result is expressed in radians and ranges from iPI/2 to +PI/2.
*/

import avmplus.*;

var SECTION = "15.8.2.4";
var VERSION = "AS3";
var TITLE   = "public native static function atan (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.atan(param); }

AddTestCase("Number.atan() returns a Number", "Number", getQualifiedClassName(Number.atan(1)));
AddTestCase("Number.atan() length is 1", 1, Number.atan.length);
AddErrorTest("Number.atan() with no args", ARGUMENTERROR+1063,  function(){ Number.atan(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.atan(undefined)", NaN, Number.atan(undefined));
AddTestCase("Number.atan(string)", NaN, Number.atan("string"));
AddTestCase("Number.atan(NaN)", NaN, Number.atan(NaN));
AddTestCase("Number.atan(NaN) check()", NaN, check(NaN));

// If x is +0, the result is +0.
AddTestCase("Number.atan(0)", 0, Number.atan(0));
AddTestCase("Number.atan(0) check()", 0, check(0));
AddTestCase("Ensure that Number.atan(+0) returns +0", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.atan(0));
AddTestCase("Ensure that Number.atan(+0) returns +0 check()", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(0));

// If x is -0, the result is -0.
AddTestCase("Number.atan(-0)", -0, Number.atan(-0));
AddTestCase("Number.atan(-0) check()", -0, check(-0));
AddTestCase("Ensure that Number.atan(-0) returns -0", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.atan(-0));
AddTestCase("Ensure that Number.atan(-0) returns -0 check()", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0));


// If x is +Infinity, the result is an implementation-dependent approximation to +PI/2.
AddTestCase("Number.atan(Number.POSITIVE_INFINITY)", Number.PI/2, Number.atan(Number.POSITIVE_INFINITY));
AddTestCase("Number.atan(Number.POSITIVE_INFINITY) check()", Number.PI/2, check(Number.POSITIVE_INFINITY));

// If x is -Infinity, the result is an implementation-dependent approximation to -PI/2.
AddTestCase("Number.atan(Number.NEGATIVE_INFINITY)", -Number.PI/2, Number.atan(Number.NEGATIVE_INFINITY));
AddTestCase("Number.atan(Number.NEGATIVE_INFINITY) check()", -Number.PI/2, check(Number.NEGATIVE_INFINITY));


AddTestCase("Number.atan(null)", 0, Number.atan(null));
AddTestCase("Number.atan(true)", Number.PI/4, Number.atan(true));
AddTestCase("Number.atan(false)", 0, Number.atan(false));


AddTestCase("Number.atan('1')", Number.PI/4, Number.atan('1'));
AddTestCase("Number.atan('0')", 0, Number.atan('0'));

var myNum:Number = 1;
AddTestCase("Number.atan(myNum=1)", Number.PI/4.0, Number.atan(myNum));
myNum = 0;
AddTestCase("Number.atan(myNum=0)", 0, Number.atan(myNum));
myNum = -0;
AddTestCase("Number.atan(myNum=-0)", -0, Number.atan(myNum));
myNum = -1;
AddTestCase("Number.atan(myNum=-1)", -Number.PI/4.0, Number.atan(myNum));

AddTestCase("Number.atan(1) NumberLiteral", Number.PI/4.0, Number.atan(1));
AddTestCase("Number.atan(0) NumberLiteral", 0, Number.atan(0));
AddTestCase("Number.atan(-0) NumberLiteral", -0, Number.atan(-0));
AddTestCase("Number.atan(-1) NumberLiteral", -Number.PI/4.0, Number.atan(-1));



test();

