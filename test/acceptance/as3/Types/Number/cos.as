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
Returns an implementation-dependent approximation to the cosine of x. The
argument is expressed in radians.
*/

import avmplus.*;

var SECTION = "15.8.2.7";
var VERSION = "AS3";
var TITLE   = "public native static function cos (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.cos(param); }

AddTestCase("Number.cos() returns a Number", "Number", getQualifiedClassName(Number.cos(1)));
AddTestCase("Number.cos() length is 1", 1, Number.cos.length);
AddErrorTest("Number.cos() with no args", ARGUMENTERROR+1063,  function(){ Number.cos(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.cos(undefined)", NaN, Number.cos(undefined));
AddTestCase("Number.cos(string)", NaN, Number.cos("string"));
AddTestCase("Number.cos(NaN)", NaN, Number.cos(NaN));
AddTestCase("Number.cos(NaN) check()", NaN, check(NaN));

// If x is +0, the result is 1.
AddTestCase("Number.cos(0)", 1, Number.cos(0));
AddTestCase("Number.cos('0')", 1, Number.cos('0'));
AddTestCase("Number.cos(0) check()", 1, check(0));

// If x is -0, the result is 1.
AddTestCase("Number.cos(-0)", 1, Number.cos(-0));
AddTestCase("Number.cos('-0')", 1, Number.cos('-0'));
AddTestCase("Number.cos(-0) check()", 1, check(-0));

// If x is +Infinity, the result is NaN.
AddTestCase("Number.cos(Number.POSITIVE_INFINITY)", NaN, Number.cos(Number.POSITIVE_INFINITY));
AddTestCase("Number.cos(Number.POSITIVE_INFINITY) check()", NaN, check(Number.POSITIVE_INFINITY));

// If x is -Infinity, the result is NaN.
AddTestCase("Number.cos(Number.NEGATIVE_INFINITY)", NaN, Number.cos(Number.NEGATIVE_INFINITY));
AddTestCase("Number.cos(Number.NEGATIVE_INFINITY) check()", NaN, check(Number.NEGATIVE_INFINITY));


AddTestCase("Number.cos(null)", 1, Number.cos(null));
AddTestCase("Number.cos(true)", 0.5403022766113281, Number.cos(true));
AddTestCase("Number.cos(false)", 1, Number.cos(false));

AddTestCase("Number.cos(Number.PI)", -1, Number.cos(Number.PI));
AddTestCase("Number.cos(-Number.PI)", -1, Number.cos(-Number.PI));

var myNum:Number = 3.1415927;
AddTestCase("Number.cos(myNum=3.1415927)", -1, Number.cos(myNum));
AddTestCase("Number.cos(myNum=-3.1415927)", -1, Number.cos(-myNum));

AddTestCase("Number.cos(3.1415927) NumberLiteral", -1, Number.cos(3.1415927));
AddTestCase("Number.cos(-3.1415927) NumberLiteral", -1, Number.cos(-3.1415927));

AddTestCase("Number.cos(Number.MIN_VALUE)", 1, Number.cos(Number.MIN_VALUE));
AddTestCase("Number.cos(Number.MAX_VALUE)", -0.9999876894265599, Number.cos(Number.MAX_VALUE));

test();

