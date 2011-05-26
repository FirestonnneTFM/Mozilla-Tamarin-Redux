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


var SECTION = "4.5.17";
var VERSION = "AS3";
var TITLE   = "public function asin(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


AddTestCase("float.asin() returns a float", "float", getQualifiedClassName(float.asin(0)));
AddTestCase("float.asin() length is 1", 1, float.asin.length);
AddErrorTest("float.asin() with no args", ARGUMENTERROR+1063,  function(){ float.asin(); });

AddTestCase("float.asin(undefined)", float.NaN, float.asin(undefined));
AddTestCase("float.asin(null)", float(0), float.asin(null));
AddTestCase("float.asin(true)", float(float.PI/2f), float.asin(true));
AddTestCase("float.asin(false)", float(0), float.asin(false));
AddTestCase("float.asin(string)", float.NaN, float.asin("string"));
AddTestCase("float.asin(float.NaN)", float.NaN, float.asin(float.NaN));

AddTestCase("float.asin('1')", float(float.PI/2f), float.asin('1'));
AddTestCase("float.asin('0')", float(0), float.asin('0'));

var myfloat:float = 1f;
AddTestCase("float.asin(1f)", float(float.PI/2.0f), float.asin(myfloat));
myfloat = 0f;
AddTestCase("float.asin(0f)", float(0), float.asin(myfloat));
myfloat = -0f;
AddTestCase("float.asin(-0f)", -float(0), float.asin(myfloat));
myfloat = -1f;
AddTestCase("float.asin(-1f)", -float(float.PI/2.0f), float.asin(myfloat));

AddTestCase("float.asin(1f) FloatLiteral", float(float.PI/2.0f), float.asin(1f));
AddTestCase("float.asin(0f) FloatLiteral", float(0), float.asin(0f));
AddTestCase("float.asin(-0f) FloatLiteral", -float(0), float.asin(-0f));
AddTestCase("float.asin(-1f) FloatLiteral", -float(float.PI/2.0f), float.asin(-1f));

AddTestCase("float.asin(float.SQRT1_2)", 0.7853981256484985f, float.asin(float.SQRT1_2));
AddTestCase("float.asin(-float.SQRT1_2)", -0.7853981256484985f, float.asin(-float.SQRT1_2));

AddTestCase("Ensure that float.asin(-0) returns -0", float.NEGATIVE_INFINITY, Infinity/float.asin(-0f));


test();

