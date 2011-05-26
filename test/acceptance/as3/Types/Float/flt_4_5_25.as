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


var SECTION = "4.5.25";
var VERSION = "AS3";
var TITLE   = "public function max(...xs):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


AddTestCase("float.max() returns a float", "float", getQualifiedClassName(float.max(0)));
AddTestCase("float.max() length is 0", 0, float.max.length);

AddTestCase("float.max()", float.NEGATIVE_INFINITY, float.max());

// undefined, "String", Number.NaN, float.NaN, in first, second and in rest args should return float.NaN
AddTestCase("float.max(undefined, 2.1f, 3.2f)", float.NaN, float.max(undefined, 2.1f, 3.2f));
AddTestCase("float.max(2.1f, undefined, 3.2f)", float.NaN, float.max(2.1f, undefined, 3.2f));
AddTestCase("float.max(2.1f, 3.2f, undefined)", float.NaN, float.max(2.1f, 3.2f, undefined));

AddTestCase("float.max('string', 2.1f, 3.2f)", float.NaN, float.max('string', 2.1f, 3.2f));
AddTestCase("float.max(2.1f, 'string', 3.2f)", float.NaN, float.max(2.1f, 'string', 3.2f));
AddTestCase("float.max(2.1f, 3.2f, 'string')", float.NaN, float.max(2.1f, 3.2f, 'string'));

AddTestCase("float.max(Number.NaN, 2.1f, 3.2f)", float.NaN, float.max(Number.NaN, 2.1f, 3.2f));
AddTestCase("float.max(2.1f, Number.NaN, 3.2f)", float.NaN, float.max(2.1f, Number.NaN, 3.2f));
AddTestCase("float.max(2.1f, 3.2f, Number.NaN)", float.NaN, float.max(2.1f, 3.2f, Number.NaN));

AddTestCase("float.max(float.NaN, 2.1f, 3.2f)", float.NaN, float.max(float.NaN, 2.1f, 3.2f));
AddTestCase("float.max(2.1f, float.NaN, 3.2f)", float.NaN, float.max(2.1f, float.NaN, 3.2f));
AddTestCase("float.max(2.1f, 3.2f, float.NaN)", float.NaN, float.max(2.1f, 3.2f, float.NaN));

AddTestCase("float.max(null, 1f)", 1f, float.max(null, 1f));
AddTestCase("float.max(-1f, null)", 0f, float.max(-1f, null));
AddTestCase("float.POSITIVE_INFINITY/float.max(-1f, null)", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.max(-1f, null));
AddTestCase("float.max(false, true)", 1f, float.max(false, true));

AddTestCase("float.max(0f, -0f)", 0f, float.max(0f, -0f));
AddTestCase("float.max(0f, -0f) confirm not negative", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.max(0f, -0f));
AddTestCase("float.max(-0f, 0f)", 0f, float.max(-0f, 0f));
AddTestCase("float.max(-0f, 0f) confirm not negative", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY/float.max(-0f, 0f));
AddTestCase("float.max(-0f, -0f)", 0f, float.max(-0f, -0f));
AddTestCase("float.max(-0f, -0f) confirm negative", float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY/float.max(-0f, -0f));

AddTestCase("float.max(float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY)", float.POSITIVE_INFINITY, float.max(float.NEGATIVE_INFINITY, float.POSITIVE_INFINITY));
AddTestCase("float.max(float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY)", float.POSITIVE_INFINITY, float.max(float.POSITIVE_INFINITY, float.NEGATIVE_INFINITY));
AddTestCase("float.max(float.MIN_VALUE, 0f)", float.MIN_VALUE, float.max(float.MIN_VALUE, 0f));
AddTestCase("float.max(float.MIN_VALUE, 1.401298464324816e-45f)", float.MIN_VALUE, float.max(float.MIN_VALUE, 1.401298464324816e-45f));
AddTestCase("float.max(float.MIN_VALUE, 1.401298464324818e-45f)", float.MIN_VALUE, float.max(float.MIN_VALUE, 1.401298464324818e-45f));

AddTestCase("float.max(Number.MAX_VALUE, float.MAX_VALUE)", float.POSITIVE_INFINITY, float.max(Number.MAX_VALUE, float.MAX_VALUE));
AddTestCase("float.max(Number.MIN_VALUE, float.MIN_VALUE)", float.MIN_VALUE, float.max(Number.MIN_VALUE, float.MIN_VALUE));

AddTestCase("float.max(float.POSITIVE_INFINITY, float.MAX_VALUE)", float.POSITIVE_INFINITY, float.max(float.POSITIVE_INFINITY, float.MAX_VALUE));

var myfloat:float = 3.124f;
var myBool:Boolean = true;
var myNum:Number = 3.1;
var myString:String = "2";
AddTestCase("float.max('2', true, 3.1, 3.124f)", myfloat, float.max(myString, myBool, myNum, myfloat));
AddTestCase("float.max('2', true, 3.1, 3.124f) literals", myfloat, float.max('2', true, 3.1, 3.124f));
AddTestCase("float.max('2', true, 3.1, 3.124f, '24')", 24f, float.max(myString, myBool, myNum, myfloat, String('24')));
AddTestCase("float.max('2', true, 3.1, 3.124f, '24') literals", 24f, float.max('2', true, 3.1, 3.124f, '24'));

test();

