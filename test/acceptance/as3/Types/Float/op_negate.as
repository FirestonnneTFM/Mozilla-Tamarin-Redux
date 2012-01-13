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

var SECTION = "6.3.5";
var VERSION = "AS3";
var TITLE   = "The negate operatror -";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var flt:float = 0f;
flt = -flt;
AddTestCase("unary minus on float zero", -2147483648 /*0x80000000*/, FloatRawBits(flt));
AddTestCase("unary minus on float zero sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/flt);
flt = -flt;
AddTestCase("unary minus on float negative zero", 0, FloatRawBits(flt));
AddTestCase("unary minus on float negative zero sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/flt);
var u = -flt;
AddTestCase("returns a float", "float", typeof(u));


flt = float.NaN;
AddTestCase("unary minus on float - NaN", 0x7f800000  /*NaN mask 0x7f800000*/, (FloatRawBits(-flt) & 0x7f800000));

flt = new float(-3.1413119f);
AddTestCase("unary minus on float - regular number", 1078528833 /*0x40490b42*/,FloatRawBits(-flt));


flt = new float(12.375f);
var pos = 1095106560;
var neg = 3242590208;
AddTestCase("float binary form match", pos.toString(2), uint(FloatRawBits(flt)).toString(2));
AddTestCase("unary minus on float binary form check", neg.toString(2), uint(FloatRawBits(-flt)).toString(2));

AddTestCase("unary minus on float.POSITIVE_INFINITY", float.NEGATIVE_INFINITY, -float.POSITIVE_INFINITY);
AddTestCase("unary minus on float.NEGATIVE_INFINITY", float.POSITIVE_INFINITY, -float.NEGATIVE_INFINITY);
AddTestCase("unary minus on float.MAX_VALUE", -3.40282346638528e+38f, -float.MAX_VALUE);
AddTestCase("unary minus on float.MIN_VALUE", -1.401298464324817e-45f, -float.MIN_VALUE);
AddTestCase("unary minus on float.NaN", float.NaN, -float.NaN);

test();

