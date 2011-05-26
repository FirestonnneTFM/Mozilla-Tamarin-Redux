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


var SECTION = "4.5.30";
var VERSION = "AS3";
var TITLE   = "public function sin(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


AddTestCase("float.sin() returns a float", "float", getQualifiedClassName(float.sin(0)));
AddTestCase("float.sin() length is 1", 1, float.sin.length);
AddErrorTest("float.sin() with no args", ARGUMENTERROR+1063,  function(){ float.sin(); });

AddTestCase("float.sin(undefined)", float.NaN, float.sin(undefined));
AddTestCase("float.sin(null)", float(0), float.sin(null));
AddTestCase("float.sin(true)", float(Math.sin(1)), float.sin(true));
AddTestCase("float.sin(false)", float(0), float.sin(false));
AddTestCase("float.sin(string)", float.NaN, float.sin("string"));
AddTestCase("float.sin(float.NaN)", float.NaN, float.sin(float.NaN));
AddTestCase("float.sin(float.POSITIVE_INFINITY)", float.NaN, float.sin(float.POSITIVE_INFINITY));
AddTestCase("float.sin(float.NEGATIVE_INFINITY)", float.NaN, float.sin(float.NEGATIVE_INFINITY));

var zerof:float = 0f;
AddTestCase("float.sin(0f)", float(0), float.sin(zerof));
AddTestCase("float.sin(0f) FloatLiteral", float(0), float.sin(0f));

var neg_zerof:float = -0f;
AddTestCase("float.sin(-0f)", float(-0), float.sin(neg_zerof));
AddTestCase("float.sin(-0f) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.sin(neg_zerof));
AddTestCase("float.sin(-0f) FloatLiteral", float(-0), float.sin(-0f));
AddTestCase("float.sin(-0f) FloatLiteral sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.sin(-0f));

AddTestCase("float.sin(0.7853981633974f)", float(0.7071067811865134), float.sin(0.7853981633974f));
AddTestCase("float.sin(1.570796326795f)", float(1), float.sin(1.570796326795f));
AddTestCase("float.sin(2.356194490192f)", float(0.7071067811867916), float.sin(2.356194490192f));
AddTestCase("float.sin(3.1415927f)", float(-8.74227766e-8), float.sin(3.1415927f));


test();

