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


var SECTION = "6.11";
var VERSION = "AS3";
var TITLE   = "The conditional operator augmented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var neg_onef:float = -1f;
var zerof:float = 0f;
var onef:float = 1f;

AddTestCase("1f ? 'PASSED' : 'FAILED'", "PASSED", (onef?"PASSED":"FAILED"));
AddTestCase("1f FloatLiteral ? 'PASSED' : 'FAILED'", "PASSED", (1f?"PASSED":"FAILED"));
AddTestCase("0f ? 'FAILED' : 'PASSED'", "PASSED", (zerof?"FAILED":"PASSED"));
AddTestCase("0f FloatLiteral ? 'FAILED' : 'PASSED'", "PASSED", (0f?"FAILED":"PASSED"));
AddTestCase("-1f ? 'PASSED' : 'FAILED'", "PASSED", (neg_onef?"PASSED":"FAILED"));
AddTestCase("-1f FloatLiteral ? 'PASSED' : 'FAILED'", "PASSED", (-1f?"PASSED":"FAILED"));
AddTestCase("float.NaN ? 'FAILED' : 'PASSED'", "PASSED", (float.NaN?"FAILED":"PASSED"));



test();
