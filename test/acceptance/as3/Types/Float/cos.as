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


var SECTION = "4.5.21";
var VERSION = "AS3";
var TITLE   = "public function cos(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


AddStrictTestCase("float.cos() returns a float", "float", getQualifiedClassName(float.cos(0)));
AddStrictTestCase("float.cos() length is 1", 1, float.cos.length);
AddErrorTest("float.cos() with no args", ARGUMENTERROR+1063,  function(){ float.cos(); });

AddStrictTestCase("float.cos(undefined)", float.NaN, float.cos(undefined));
AddStrictTestCase("float.cos(null)", float(1), float.cos(null));
AddStrictTestCase("float.cos(true)", 0.5403022766113281f, float.cos(true));
AddStrictTestCase("float.cos(false)", float(1), float.cos(false));
AddStrictTestCase("float.cos(string)", float.NaN, float.cos("string"));
AddStrictTestCase("float.cos(float.NaN)", float.NaN, float.cos(float.NaN));

AddStrictTestCase("float.cos(0)", float(1f), float.cos(0f));
AddStrictTestCase("float.cos(-0)", float(1f), float.cos(-0f));

AddStrictTestCase("float.cos('0')", float(1), float.cos('0'));

AddStrictTestCase("float.cos(float.PI)", -float(1), float.cos(float.PI));
AddStrictTestCase("float.cos(-float.PI)", -float(1), float.cos(-float.PI));

var myfloat:float = 3.1415927f;
AddStrictTestCase("float.cos(3.1415927f)", -float(1), float.cos(myfloat));
AddStrictTestCase("float.cos(-3.1415927f)", -float(1), float.cos(-myfloat));

AddStrictTestCase("float.cos(3.1415927f) FloatLiteral", -float(1), float.cos(3.1415927f));
AddStrictTestCase("float.cos(-3.1415927f) FloatLiteral", -float(1), float.cos(-3.1415927f));

AddStrictTestCase("float.cos(float.POSITIVE_INFINITY)", float.NaN, float.cos(float.POSITIVE_INFINITY));
AddStrictTestCase("float.cos(float.NEGATIVE_INFINITY)", float.NaN, float.cos(float.NEGATIVE_INFINITY));

AddStrictTestCase("float.cos(float.MIN_VALUE)", float(1), float.cos(float.MIN_VALUE));

test();

