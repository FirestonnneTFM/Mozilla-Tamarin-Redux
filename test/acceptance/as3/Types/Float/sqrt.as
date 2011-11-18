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


var SECTION = "4.5.31";
var VERSION = "AS3";
var TITLE   = "public function sqrt(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


AddStrictTestCase("float.sqrt() returns a float", "float", getQualifiedClassName(float.sqrt(0)));
AddStrictTestCase("float.sqrt() length is 1", 1, float.sqrt.length);
AddErrorTest("float.sqrt() with no args", ARGUMENTERROR+1063,  function(){ float.sqrt(); });

AddStrictTestCase("float.sqrt(undefined)", float.NaN, float.sqrt(undefined));
AddStrictTestCase("float.sqrt(null)", float(0), float.sqrt(null));
AddStrictTestCase("float.sqrt(true)", float(1), float.sqrt(true));
AddStrictTestCase("float.sqrt(false)", float(0), float.sqrt(false));
AddStrictTestCase("float.sqrt(string)", float.NaN, float.sqrt("string"));
AddStrictTestCase("float.sqrt(float.NaN)", float.NaN, float.sqrt(float.NaN));
AddStrictTestCase("float.sqrt(float.POSITIVE_INFINITY)", float.POSITIVE_INFINITY, float.sqrt(float.POSITIVE_INFINITY));
AddStrictTestCase("float.sqrt(float.NEGATIVE_INFINITY)", float.NaN, float.sqrt(float.NEGATIVE_INFINITY));

AddStrictTestCase("float.sqrt(-0.1f)", float.NaN, float.sqrt(-0.1f));
AddStrictTestCase("float.sqrt(-float.MIN_VALUE)", float.NaN, float.sqrt(-float.MIN_VALUE));

var zerof:float = 0f;
AddStrictTestCase("float.sqrt(0f)", float(0), float.sqrt(zerof));
AddStrictTestCase("float.sqrt(0f) FloatLiteral", float(0), float.sqrt(0f));
AddStrictTestCase("float.sqrt(0f) sign check", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.sqrt(0f));

var neg_zerof:float = -0f;
AddStrictTestCase("float.sqrt(-0f)", float(-0), float.sqrt(neg_zerof));
AddStrictTestCase("float.sqrt(-0f) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.sqrt(neg_zerof));
AddStrictTestCase("float.sqrt(-0f) FloatLiteral", float(-0), float.sqrt(-0f));
AddStrictTestCase("float.sqrt(-0f) FloatLiteral sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.sqrt(-0f));


AddStrictTestCase("float.sqrt(2f)", float.SQRT2, float.sqrt(2f));
AddStrictTestCase("float.sqrt(0.5f)", float.SQRT1_2, float.sqrt(0.5f));

var x:float = 3f;
for( var i:int = 0; i < 20; i++ )
{
    AddStrictTestCase("float.sqrt("+x+")", float(1.73205080756887719318).toFixed(i),  float.sqrt(x).toFixed(i));
}
x = 2f;
for( var i:int = 0; i < 20; i++ )
{
    AddStrictTestCase("float.sqrt("+x+")", float(1.4142135623730951455).toFixed(i),  float.sqrt(x).toFixed(i));
}

test();

