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


var SECTION = "4.4.7";
var VERSION = "AS3";
var TITLE   = "float4.POSITIVE_INFINITY";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var flt4:float4 = new float4(float.POSITIVE_INFINITY);
AddTestCase("float4.POSITIVE_INFINITY is float4(float.POSITIVE_INFINITY)", true, float4.POSITIVE_INFINITY == flt4);
AddTestCase("float4.POSITIVE_INFINITY.x is float.POSITIVE_INFINITY", float.POSITIVE_INFINITY, float4.POSITIVE_INFINITY.x);
AddTestCase("float4.POSITIVE_INFINITY.y is float.POSITIVE_INFINITY", float.POSITIVE_INFINITY, float4.POSITIVE_INFINITY.y);
AddTestCase("float4.POSITIVE_INFINITY.z is float.POSITIVE_INFINITY", float.POSITIVE_INFINITY, float4.POSITIVE_INFINITY.z);
AddTestCase("float4.POSITIVE_INFINITY.w is float.POSITIVE_INFINITY", float.POSITIVE_INFINITY, float4.POSITIVE_INFINITY.w);

AddTestCase("typeof float4.POSITIVE_INFINITY", "float4", getQualifiedClassName(float4.POSITIVE_INFINITY));

AddTestCase("float4.POSITIVE_INFINITY - DontDelete", false, delete(float4.POSITIVE_INFINITY));
AddTestCase("float4.POSITIVE_INFINITY is still ok", flt4, float4.POSITIVE_INFINITY);

AddTestCase("float4.POSITIVE_INFINITY - DontEnum", '',getFloat4Prop('POSITIVE_INFINITY'));
AddTestCase("float4.POSITIVE_INFINITY is no enumberable", false, float4.propertyIsEnumerable('POSITIVE_INFINITY'));

AddErrorTest("float4.POSITIVE_INFINITY - ReadOnly", REFERENCEERROR+1074, function(){ float4.POSITIVE_INFINITY = 0; });
AddTestCase("float4.POSITIVE_INFINITY is still here", flt4, float4.POSITIVE_INFINITY);

test();

