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


var SECTION = "4.5.32";
var VERSION = "AS3";
var TITLE   = "public function tan(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


AddTestCase("float.tan() returns a float", "float", getQualifiedClassName(float.tan(0)));
AddTestCase("float.tan() length is 1", 1, float.tan.length);
AddErrorTest("float.tan() with no args", ARGUMENTERROR+1063,  function(){ float.tan(); });

AddTestCase("float.tan(undefined)", float.NaN, float.tan(undefined));
AddTestCase("float.tan(null)", float(0), float.tan(null));
AddTestCase("float.tan(true)", float(Math.tan(1)), float.tan(true));
AddTestCase("float.tan(false)", float(0), float.tan(false));
AddTestCase("float.tan(string)", float.NaN, float.tan("string"));
AddTestCase("float.tan(float.NaN)", float.NaN, float.tan(float.NaN));
AddTestCase("float.tan(float.POSITIVE_INFINITY)", float.NaN, float.tan(float.POSITIVE_INFINITY));
AddTestCase("float.tan(float.NEGATIVE_INFINITY)", float.NaN, float.tan(float.NEGATIVE_INFINITY));

var zerof:float = 0f;
AddTestCase("float.tan(0f)", float(0), float.tan(zerof));
AddTestCase("float.tan(0f) FloatLiteral", float(0), float.tan(0f));

var neg_zerof:float = -0f;
AddTestCase("float.tan(-0f)", float(-0), float.tan(neg_zerof));
AddTestCase("float.tan(-0f) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.tan(neg_zerof));
AddTestCase("float.tan(-0f) FloatLiteral", float(-0), float.tan(-0f));
AddTestCase("float.tan(-0f) FloatLiteral sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.tan(-0f));

AddTestCase("float.tan(float.PI/4f)", float(1), float.tan(float.PI/4f));
AddTestCase("float.tan(3f*float.PI/4f)", float(-1), float.tan(3f*float.PI/4f));
AddTestCase("float.tan(float.PI)", -float.sin(float.PI), float.tan(float.PI));
AddTestCase("float.tan(5f*float.PI/4f)", float(1.0000003576278687), float.tan(5f*float.PI/4f));

test();

