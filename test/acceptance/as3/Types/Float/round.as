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


var SECTION = "4.5.29";
var VERSION = "AS3";
var TITLE   = "public function round(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


AddStrictTestCase("float.round() returns a float", "float", getQualifiedClassName(float.round(12.345f)));
AddStrictTestCase("float.round() length is 1", 1, float.round.length);
AddErrorTest("float.round() with no args", ARGUMENTERROR+1063,  function(){ float.round(); });

AddStrictTestCase("float.round(undefined)", float.NaN, float.round(undefined));
AddStrictTestCase("float.round(null)", float(0), float.round(null));
AddStrictTestCase("float.round(true)", float(1), float.round(true));
AddStrictTestCase("float.round(false)", float(0), float.round(false));
AddStrictTestCase("float.round(string)", float.NaN, float.round("string"));
AddStrictTestCase("float.round(float.NaN)", float.NaN, float.round(float.NaN));

AddStrictTestCase("float.round(0f)", 0f, float.round(0f));
AddStrictTestCase("float.round(0f) is +0", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.round(0f));
AddStrictTestCase("float.round(-0f)", -0f, float.round(-0f));
AddStrictTestCase("float.round(-0f) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.round(-0f));
AddStrictTestCase("float.round(float.POSITIVE_INFINITY)", float.POSITIVE_INFINITY, float.round(float.POSITIVE_INFINITY));
AddStrictTestCase("float.round(float.NEGATIVE_INFINITY)", float.NEGATIVE_INFINITY, float.round(float.NEGATIVE_INFINITY));

AddStrictTestCase("float.round(0.49f)", 0f, float.round(0.49f));
AddStrictTestCase("float.round(0.49999f)", 0f, float.round(0.49999f));
AddStrictTestCase("float.round(4.9999e-2f)", 0f, float.round(4.9999e-2f));
AddStrictTestCase("float.round(float.MIN_VALUE)", 0f, float.round(float.MIN_VALUE));
AddStrictTestCase("float.round(0.5f)", 1f, float.round(0.5f));
AddStrictTestCase("float.round(5.000001e-1)", 1f, float.round(5.000001e-1));

AddStrictTestCase("float.round(-0.49f)", -0f, float.round(-0.49f));
AddStrictTestCase("float.round(-0.49f) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.round(-0.49f));
AddStrictTestCase("float.round(-0.49999f)", -0f, float.round(-0.49999f));
AddStrictTestCase("float.round(-0.49999f) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.round(-0.49999f));
AddStrictTestCase("float.round(-4.9999e-1f)", -0f, float.round(-4.9999e-1f));
AddStrictTestCase("float.round(-4.9999e-1f) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.round(4.9999e-1f));
AddStrictTestCase("float.round(-float.MIN_VALUE)", -0f, float.round(-float.MIN_VALUE));
AddStrictTestCase("float.round(-float.MIN_VALUE) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.round(-float.MIN_VALUE));
AddStrictTestCase("float.round(-0.5f)", -0f, float.round(-0.5f));
AddStrictTestCase("float.round(-0.5f) sign check", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.round(-0.5f));
AddStrictTestCase("float.round(-5.000001e-1)", -1f, float.round(-5.000001e-1));

AddStrictTestCase("float.round(3.124f) == float.floor(3.124f + 0.5f)", true, float.round(3.124f) == float.floor(3.124f + 0.5f));

var myfloat:float = 3.124f;
AddStrictTestCase("float.round(3.124f)", 3f, float.round(myfloat));
AddStrictTestCase("float.round(3.124f) FloatLiteral", 3f, float.round(3.124f));

AddStrictTestCase("float.round(float.MAX_VALUE)", float.MAX_VALUE, float.round(float.MAX_VALUE));


test();

