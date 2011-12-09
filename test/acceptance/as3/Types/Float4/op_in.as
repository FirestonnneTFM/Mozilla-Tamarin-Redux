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

var SECTION = "5.5.3";
var VERSION = "AS3";
var TITLE   = "The in operator augmented by float4 values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var flt4:float4 = new float4(1f, 2f, 3f, 4f);

AddTestCase("0 in float4", true, 0 in flt4);
AddTestCase("1 in float4", true, 1 in flt4);
AddTestCase("2 in float4", true, 2 in flt4);
AddTestCase("3 in float4", true, 3 in flt4);
AddTestCase("-1 in float4", false, -1 in flt4);
AddTestCase("4 in float4", false, 4 in flt4);

AddTestCase("'0' in float4", true, '0' in flt4);
AddTestCase("'1' in float4", true, '1' in flt4);
AddTestCase("'2' in float4", true, '2' in flt4);
AddTestCase("'3' in float4", true, '3' in flt4);
AddTestCase("'-1' in float4", false, '-1' in flt4);
AddTestCase("'4' in float4", false, '4' in flt4);


AddTestCase("'x' in float4", true, 'x' in flt4);
AddTestCase("'y' in float4", true, 'y' in flt4);
AddTestCase("'z' in float4", true, 'z' in flt4);
AddTestCase("'w' in float4", true, 'w' in flt4);
AddTestCase("'X' in float4", false, 'W' in flt4);
AddTestCase("'Y' in float4", false, 'Y' in flt4);
AddTestCase("'Z' in float4", false, 'Z' in flt4);
AddTestCase("'W' in float4", false, 'W' in flt4);


AddTestCase("'b' in float4", false, 'b' in flt4);
AddTestCase("'xyza' in float4", false, 'xyza' in flt4);


test();

