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


var SECTION = "4.5.20";
var VERSION = "AS3";
var TITLE   = "public function ceil(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


AddTestCase("float.ceil() returns a float", "float", getQualifiedClassName(float.ceil(0f)));
AddTestCase("float.ceil() length is 1", 1, float.ceil.length);
AddErrorTest("float.ceil() with no args", ARGUMENTERROR+1063,  function(){ float.ceil(); });

AddTestCase("float.ceil(undefined)", float.NaN, float.ceil(undefined));
AddTestCase("float.ceil(null)", float(0), float.ceil(null));
AddTestCase("float.ceil(true)", float(1), float.ceil(true));
AddTestCase("float.ceil(false)", float(0), float.ceil(false));
AddTestCase("float.ceil(string)", float.NaN, float.ceil("string"));
AddTestCase("float.ceil(float.NaN)", float.NaN, float.ceil(float.NaN));
AddTestCase("float.ceil(float.POSITIVE_INFINITY)", float.POSITIVE_INFINITY, float.ceil(float.POSITIVE_INFINITY));
AddTestCase("float.ceil(float.NEGATIVE_INFINITY)", float.NEGATIVE_INFINITY, float.ceil(float.NEGATIVE_INFINITY));
AddTestCase("float.ceil(float.MAX_VALUE)", float.MAX_VALUE, float.ceil(float.MAX_VALUE));
AddTestCase("float.ceil(float.MAX_VALUE+3.40282346638528e+31f)", float.POSITIVE_INFINITY, float.ceil(float.MAX_VALUE+3.40282346638528e+31f));
AddTestCase("float.ceil(float.MIN_VALUE)", float(1), float.ceil(float.MIN_VALUE));

AddTestCase("float.ceil('1')", float(1), float.ceil('1'));
AddTestCase("float.ceil('0')", float(0), float.ceil('0'));

var myfloat:float = 1f;
AddTestCase("float.ceil(1f)", float(1f), float.ceil(myfloat));
myfloat = 0f;
AddTestCase("float.ceil(0f)", float(0), float.ceil(myfloat));
AddTestCase("float.INFINITY/float.ceil(0f)", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.ceil(myfloat));
myfloat = -0f;
AddTestCase("float.ceil(-0f)", -float(0), float.ceil(myfloat));
AddTestCase("float.INFINITY/float.ceil(-0f)", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.ceil(myfloat));
myfloat = -1f;
AddTestCase("float.ceil(-1f)", float(-1f), float.ceil(myfloat));

AddTestCase("float.ceil(1f) FloatLiteral", float(1), float.ceil(1f));
AddTestCase("float.ceil(0f) FloatLiteral", float(0), float.ceil(0f));
AddTestCase("float.ceil(-0f) FloatLiteral", -float(0), float.ceil(-0f));
AddTestCase("float.ceil(-1f) FloatLiteral", -float(1), float.ceil(-1f));

AddTestCase("Ensure that float.ceil(-0) returns -0", float.NEGATIVE_INFINITY, Infinity/float.ceil(-0f));

AddTestCase("float.ceil(-0.1f)", float(-0f), float.ceil(-0.1f));
AddTestCase("Ensure that float.ceil(-0.1f) returns -0", float.NEGATIVE_INFINITY, Infinity/float.ceil(-0.1f));

AddTestCase("float.ceil(3.124f) == -float.floor(-3.124f)", -float.floor(-3.124f), float.ceil(3.124f));

test();

