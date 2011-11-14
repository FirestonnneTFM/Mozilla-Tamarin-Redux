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


var SECTION = "4.4.15.4";
var VERSION = "AS3";
var TITLE   = "Comparison methods public function float4.isLessOrEqual(arg1:float4 , arg2:float4):float4";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var flt4_a:float4 = new float4(1f, 1f, 1f, 1f);
var flt4_b:float4 = new float4(2f, 2f, 2f, 2f);
AddTestCase("float4.isLessOrEqual() returns a float4", "float4", getQualifiedClassName(float4.isLessOrEqual(flt4_a, flt4_b)));

flt4_a = new float4(1f, 1f, 1f, 1f);
flt4_b = new float4(2f, 2f, 2f, 2f);
AddStrictTestCase("float4.isLessOrEqual((1f, 1f, 1f, 1f), (2f, 2f, 2f, 2f))", new float4(1f, 1f, 1f, 1f), float4.isLessOrEqual(flt4_a, flt4_b));
AddStrictTestCase("float4.isLessOrEqual((2f, 2f, 2f, 2f), (1f, 1f, 1f, 1f))", new float4(0f, 0f, 0f, 0f), float4.isLessOrEqual(flt4_b, flt4_a));

flt4_a = new float4(1f, 1f, 1f, 1f);
flt4_b = new float4(2f, 0f, 0f, 0f);
AddStrictTestCase("float4.isLessOrEqual((1f, 1f, 1f, 1f), (2f, 0f, 0f, 0f))", new float4(1f, 0f, 0f, 0f), float4.isLess(flt4_a, flt4_b));
flt4_a = new float4(1f, 1f, 1f, 1f);
flt4_b = new float4(0f, 2f, 0f, 0f);
AddStrictTestCase("float4.isLessOrEqual((1f, 1f, 1f, 1f), (0f, 2f, 0f, 0f))", new float4(0f, 1f, 0f, 0f), float4.isLessOrEqual(flt4_a, flt4_b));
flt4_a = new float4(1f, 1f, 1f, 1f);
flt4_b = new float4(0f, 0f, 2f, 0f);
AddStrictTestCase("float4.isLessOrEqual((1f, 1f, 1f, 1f), (0f, 0f, 2f, 0f))", new float4(0f, 0f, 1f, 0f), float4.isLessOrEqual(flt4_a, flt4_b));
flt4_a = new float4(1f, 1f, 1f, 1f);
flt4_b = new float4(0f, 0f, 0f, 2f);
AddStrictTestCase("float4.isLessOrEqual((1f, 1f, 1f, 1f), (0f, 0f, 0f, 2f))", new float4(0f, 0f, 0f, 1f), float4.isLessOrEqual(flt4_a, flt4_b));

flt4_a = new float4(1f, 1f, 1f, 1f);
AddStrictTestCase("float4.isLessOrEqual((1f, 1f, 1f, 1f), (1f, 1f, 1f, 1f))", new float4(1f, 1f, 1f, 1f), float4.isLessOrEqual(flt4_a, flt4_a));

flt4_a = new float4(-0f);
flt4_b = new float4(0f);
AddStrictTestCase("float4.isLessOrEqual((-0f), (0f))", new float4(1f), float4.isLessOrEqual(flt4_a, flt4_b));
AddStrictTestCase("float4.isLessOrEqual((0f), (-0f))", new float4(1f), float4.isLessOrEqual(flt4_b, flt4_a));

test();

