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
Returns an implementation-dependent approximation to the tangent of x. The
argument is expressed in radians.
*/

import avmplus.*;

var SECTION = "15.8.2.18";
var VERSION = "AS3";
var TITLE   = "public native static function tan (x:Number) :Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:Number):Number { return Number.tan(param); }

AddTestCase("Number.tan() returns a Number", "Number", getQualifiedClassName(Number.tan(1)));
AddTestCase("Number.tan() length is 1", 1, Number.tan.length);
AddErrorTest("Number.tan() with no args", ARGUMENTERROR+1063,  function(){ Number.tan(); });

// If x is NaN, the result is NaN.
AddTestCase("Number.tan(undefined)", NaN, Number.tan(undefined));
AddTestCase("Number.tan(string)", NaN, Number.tan("string"));
AddTestCase("Number.tan(NaN)", NaN, Number.tan(NaN));
AddTestCase("Number.tan(NaN) check()", NaN, check(NaN));

// If x is +0, the result is +0.
var zero:Number = 0;
AddTestCase("Number.tan(zero=0)", 0, Number.tan(zero));
AddTestCase("Number.tan(0) NumberLiteral", 0, Number.tan(0));
AddTestCase("Number.tan(0) sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/Number.tan(0));
AddTestCase("Number.tan(0) check()", 0, check(0));
AddTestCase("Number.tan(0) check() sign check", Number.POSITIVE_INFINITY, Number.POSITIVE_INFINITY/check(0));
AddTestCase("Number.tan(null)", 0, Number.tan(null));
AddTestCase("Number.tan(false)", 0, Number.tan(false));

// If x is -0, the result is -0.
var neg_zero:Number = -0;
AddTestCase("Number.tan(neg_zero)", -0, Number.tan(neg_zero));
AddTestCase("Number.tan(neg_zero) sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.tan(neg_zero));
AddTestCase("Number.tan(-0) NumberLiteral", -0, Number.tan(-0));
AddTestCase("Number.tan(-0) NumberLiteral sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/Number.tan(-0));
AddTestCase("Number.tan(-0) check()", -0, check(-0));
AddTestCase("Number.tan(-0) check() sign check", Number.NEGATIVE_INFINITY, Number.POSITIVE_INFINITY/check(-0));

// If x is +Infinity or -Infinity, the result is NaN.
AddTestCase("Number.tan(Number.POSITIVE_INFINITY)", NaN, Number.tan(Number.POSITIVE_INFINITY));
AddTestCase("Number.tan(Number.NEGATIVE_INFINITY)", NaN, Number.tan(Number.NEGATIVE_INFINITY));
AddTestCase("Number.tan(Number.POSITIVE_INFINITY) check()", NaN, check(Number.POSITIVE_INFINITY));
AddTestCase("Number.tan(Number.NEGATIVE_INFINITY) check()", NaN, check(Number.NEGATIVE_INFINITY));


AddTestCase("Number.tan(Number.PI/4)", 1, Number.tan(Number.PI/4));
AddTestCase("Number.tan(3*Number.PI/4)", -1, Number.tan(3*Number.PI/4));
AddTestCase("Number.tan(Number.PI)", -Number.sin(Number.PI), Number.tan(Number.PI));

test();

