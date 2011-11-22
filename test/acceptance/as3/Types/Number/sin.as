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
Returns an implementation-dependent approximation to the sine of x. The argument
is expressed in radians.
*/

import avmplus.*;

var SECTION = "15.8.2.16";
var VERSION = "AS3";
var TITLE   = "public native static function sin (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.sin(param); }

AddTestCase("Number.sin() returns a Number", "Number", getQualifiedClassName(Number.sin(1)));
AddTestCase("Number.sin() length is 1", 1, Number.sin.length);
AddErrorTest("Number.sin() with no args", ARGUMENTERROR+1063,  function(){ Number.sin(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.sin(undefined)", NaN, Number.sin(undefined));
AddTestCase("Number.sin(string)", NaN, Number.sin("string"));
AddTestCase("Number.sin(at.NaN)", NaN, Number.sin(NaN));
AddTestCase("Number.sin(NaN) check()", NaN, check(NaN));


// If x is +0, the result is +0.
var zero:Number = 0;
AddTestCase("Number.sin(zero=0)", 0, Number.sin(zero));
AddTestCase("Number.sin(zero=0) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.sin(zero));
AddTestCase("Number.sin(0)", 0, Number.sin(0));
AddTestCase("Number.sin(0) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.sin(0));
AddTestCase("Number.sin(0) check()", 0, check(0));
AddTestCase("Number.sin(0) check() sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(0));
AddTestCase("Number.sin('0')", 0, Number.sin('0'));
AddTestCase("Number.sin(null)", 0, Number.sin(null));
AddTestCase("Number.sin(false)", 0, Number.sin(false));

// If x is -0, the result is -0.
var neg_zero:Number = -0;
AddTestCase("Number.sin(zero=-0)", -0, Number.sin(neg_zero));
AddTestCase("Number.sin(zero=-0) sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.sin(neg_zero));
AddTestCase("Number.sin(-0) NumberLiteral", -0, Number.sin(-0));
AddTestCase("Number.sin(-0) NumberLiteral sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.sin(-0));
AddTestCase("Number.sin(-0) check()", -0, check(-0));
AddTestCase("Number.sin(-0) check() sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0));


// If x is +Infinity or -Infinity, the result is NaN.
AddTestCase("Number.sin(Number.POSITIVE_INFINITY)", NaN, Number.sin(Number.POSITIVE_INFINITY));
AddTestCase("Number.sin(Number.NEGATIVE_INFINITY)", NaN, Number.sin(Number.NEGATIVE_INFINITY));

AddTestCase("Number.sin(Number.PI/4)", 0.7071067811865134, Number.sin(Number.PI/4));
AddTestCase("Number.sin(Number.PI/2)", 1, Number.sin(Number.PI/2));
AddTestCase("Number.sin(Number.PI)", -8.74227766e-8, Number.sin(Number.PI));


test();

