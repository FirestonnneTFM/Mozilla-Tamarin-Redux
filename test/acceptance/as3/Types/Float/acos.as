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

/*
Returns an implementation-dependent approximation to the arc cosine of x.
The result is expressed in radians and ranges from +0 to +PI.
*/

var SECTION = "4.5.16";
var VERSION = "AS3";
var TITLE   = "public function acos(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(param:float):float { return float.acos(param); }

AddStrictTestCase("float.acos() returns a float", "float", getQualifiedClassName(float.acos(0)));
AddStrictTestCase("float.acos() length is 1", 1, float.acos.length);

// If x is NaN, the result is NaN.
AddStrictTestCase("float.acos(undefined)", float.NaN, float.acos(undefined));
AddStrictTestCase("float.acos(float.NaN)", float.NaN, float.acos(float.NaN));
AddStrictTestCase("float.acos(float.NaN) check()", float.NaN, check(float.NaN));

// If x is greater than 1, the result is NaN.
AddStrictTestCase("float.acos(1.125f)", float.NaN, float.acos(1.125f));
AddStrictTestCase("float.acos(1.125f) check()", float.NaN, check(1.125f));

// If x is less than -1, the result is NaN.
AddStrictTestCase("float.acos(-1.125f)", float.NaN, float.acos(-1.125f));
AddStrictTestCase("float.acos(-1.125f) check", float.NaN, check(-1.125f));

// If x is exactly 1, the result is +0.
AddStrictTestCase("float.acos(1f)", 0f, float.acos(1f));
AddStrictTestCase("Ensure that float.acos(1f) returns +0", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.acos(1f));


AddStrictTestCase("float.acos(null)", float.PI/2.0f, float.acos(null));


var myfloat:float = 0f;
AddStrictTestCase("float.acos(myfloat=0f)", float(float.PI/2.0f), float.acos(myfloat));
myfloat = 1f;
AddStrictTestCase("float.acos(myfloat=1f)", float(0), float.acos(myfloat));
myfloat = -1f;
AddStrictTestCase("float.acos(myfloat=-1f)", float.PI, float.acos(myfloat));
myfloat = -0f;
AddStrictTestCase("float.acos(myfloat=-0f)", float(float.PI/2.0f), float.acos(myfloat));

AddStrictTestCase("float.acos(0f) FloatLiteral", float(float.PI/2.0f), float.acos(0f));
AddStrictTestCase("float.acos(1f) FloatLiteral", float(0), float.acos(1f));
AddStrictTestCase("float.acos(-1f) FloatLiteral", float.PI, float.acos(-1f));
AddStrictTestCase("float.acos(-0f) FloatLiteral", float(float.PI/2.0f), float.acos(-0f));

AddStrictTestCase("float.acos(float.SQRT1_2)", float(float.PI/4.0f), float.acos(float.SQRT1_2));
AddStrictTestCase("float.acos(-float.SQRT1_2)", float(float.PI/4.0f*3.0f), float.acos(-float.SQRT1_2));

test();

