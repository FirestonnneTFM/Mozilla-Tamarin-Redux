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


var SECTION = "4.5.23";
var VERSION = "AS3";
var TITLE   = "public function floor(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


AddStrictTestCase("float.floor() returns a float", "float", getQualifiedClassName(float.floor(0)));
AddStrictTestCase("float.floor() length is 1", 1, float.floor.length);
AddErrorTest("float.floor() with no args", ARGUMENTERROR+1063,  function(){ float.floor(); });

AddStrictTestCase("float.floor(undefined)", float.NaN, float.floor(undefined));
AddStrictTestCase("float.floor(null)", float(0), float.floor(null));
AddStrictTestCase("float.floor(true)", float(1), float.floor(true));
AddStrictTestCase("float.floor(false)", float(0), float.floor(false));
AddStrictTestCase("float.floor(string)", float.NaN, float.floor("string"));
AddStrictTestCase("float.floor(float.NaN)", float.NaN, float.floor(float.NaN));

AddStrictTestCase("float.floor(0f)", float(0f), float.floor(0f));
AddStrictTestCase("float.floor(0f) sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.floor(0f));
AddStrictTestCase("float.floor(-0f)", float(-0f), float.floor(-0f));
AddStrictTestCase("float.floor(-0f) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.floor(-0f));


AddStrictTestCase("float.floor('1')", float(1), float.floor('1'));
AddStrictTestCase("float.floor('0')", float(0), float.floor('0'));
AddStrictTestCase("float.INFINITY/float.floor('0')", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.floor('0'));

AddStrictTestCase("float.floor(float.POSITIVE_INFINITY)", float.POSITIVE_INFINITY, float.floor(float.POSITIVE_INFINITY));
AddStrictTestCase("float.floor(float.NEGATIVE_INFINITY)", float.NEGATIVE_INFINITY, float.floor(float.NEGATIVE_INFINITY));
AddStrictTestCase("float.floor(float.MIN_VALUE)", float(0), float.floor(float.MIN_VALUE));
AddStrictTestCase("float.floor(-float.MIN_VALUE)", float(-1), float.floor(-float.MIN_VALUE));
AddStrictTestCase("float.floor(float.MAX_VALUE)", float.MAX_VALUE, float.floor(float.MAX_VALUE));

var myfloat:float = 1f;
AddStrictTestCase("float.floor(1f)", float(1f), float.floor(myfloat));
myfloat = 0f;
AddStrictTestCase("float.floor(0f)", float(0), float.floor(myfloat));
AddStrictTestCase("float.INFINITY/float.floor(0f)", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.floor(myfloat));
myfloat = -0f;
AddStrictTestCase("float.floor(-0f)", -float(0), float.floor(myfloat));
AddStrictTestCase("float.INFINITY/float.floor(-0f)", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.floor(myfloat));
myfloat = -1f;
AddStrictTestCase("float.floor(-1f)", float(-1f), float.floor(myfloat));

AddStrictTestCase("float.floor(1f) FloatLiteral", float(1), float.floor(1f));
AddStrictTestCase("float.floor(0f) FloatLiteral", float(0), float.floor(0f));
AddStrictTestCase("float.floor(-0f) FloatLiteral", -float(0), float.floor(-0f));
AddStrictTestCase("float.floor(-1f) FloatLiteral", -float(1), float.floor(-1f));

AddStrictTestCase("float.floor(3.124f) == -float.ceil(-3.124f)", -float.ceil(-3.124f), float.floor(3.124f));

AddStrictTestCase("float.floor(0.5f)", float(0f), float.floor(0.5f));
AddStrictTestCase("float.floor(0.5f) sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.floor(0.5f));
AddStrictTestCase("float.floor(0.999f)", float(0f), float.floor(0.999f));
AddStrictTestCase("float.floor(0.999f) sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.floor(0.999f));


test();

