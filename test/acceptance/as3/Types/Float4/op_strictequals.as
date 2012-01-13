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

var SECTION = "5.6.3";
var VERSION = "AS3";
var TITLE   = "The === operator augmented by float4 values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var fivef:float = float(5f);
var fourf:float = float(4f);
var threef:float = float(3f);
var twof:float = float(2f);
var onef:float = float(1f);
var zerof:float = float(0f);

AddTestCase("float4(1f) === float4(1f)", true, float4(1f) === float4(1f));
AddTestCase("float4(0f) === float4(0f)", true, float4(0f) === float4(0f));
AddTestCase("float4(onef) === float4(onef)", true, float4(onef) === float4(onef));
AddTestCase("float4(zerof) === float4(zerof)", true, float4(zerof) === float4(zerof));
AddTestCase("float4(0f) === float4(-0f)", false, float4(0f) === float4(-0f));
AddTestCase("float4(0f) === float4(-0f)", false, float4(-0f) === float4(0f));
AddTestCase("float4(1f) === float4(2f)", false, float4(1f) === float4(2f));
AddTestCase("float4(2f) === float4(1f)", false, float4(2f) === float4(1f));

AddTestCase("float4(1f, 2f, 3f, 4f) === float4(1f, 2f, 3f, 4f)", true, float4(1f, 2f, 3f, 4f) === float4(1f, 2f, 3f, 4f));
AddTestCase("float4(1f, 2f, 3f, 4f) === float4(0f, 2f, 3f, 4f)", false, float4(1f, 2f, 3f, 4f) === float4(0f, 2f, 3f, 4f));
AddTestCase("float4(1f, 1f, 3f, 4f) === float4(1f, 1f, 3f, 4f)", false, float4(1f, 2f, 3f, 4f) === float4(1f, 1f, 3f, 4f));
AddTestCase("float4(1f, 2f, 2f, 4f) === float4(1f, 2f, 3f, 4f)", false, float4(1f, 2f, 3f, 4f) === float4(1f, 2f, 2f, 4f));
AddTestCase("float4(1f, 2f, 3f, 4f) === float4(!f, 2f, 3f, 5f)", false, float4(1f, 2f, 3f, 4f) === float4(1f, 2f, 3f, 5f));

AddTestCase("float4(onef, twof, threef, fourf) === float4(onef, twof, threef, fourf)", true, float4(onef, twof, threef, fourf) === float4(onef, twof, threef, fourf));
AddTestCase("float4(onef, twof, threef, fourf) === float4(zerof, twof, threef, fourf)", false, float4(onef, twof, threef, fourf) === float4(zerof, twof, threef, fourf));
AddTestCase("float4(onef, twof, threef, fourf) === float4(onef, onef, threef, fourf)", false, float4(onef, twof, threef, fourf) === float4(onef, onef, threef, fourf));
AddTestCase("float4(onef, twof, threef, fourf) === float4(onef, twof, twof, fourf)", false, float4(onef, twof, threef, fourf) === float4(onef, twof, twof, fourf));
AddTestCase("float4(onef, twof, threef, fourf) === float4(onef, twof, threef, 5f)", false, float4(onef, twof, threef, fourf) === float4(onef, twof, threef, fivef));

test();

