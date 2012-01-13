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

var SECTION = "XXX";
var VERSION = "AS3";
var TITLE   = "delete operator";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var flt4:float4 = new float4(1,2,3,4);

// In-range deletion - these are not deletable so the result should be false and the element should be there still

AddTestCase("delete an in-range element of a float4", false, delete flt4[2]);
AddTestCase("delete an in-range element of a float4", false, delete flt4["2"]);
AddTestCase("deleted element is still there", 3, flt4[2]);

// Out-of-range deletion with an index property - we're working with the "Vector" nature of float4 so the result should be true

AddTestCase("delete an out-of-range element of a float4", true, delete flt4[4]);

// Out-of-range deletion with non-index properties - since it's a sealed object we should throw the customary exception for
// sealed object deletion attempts.

AddErrorTest("delete an out-of-range element of a float4 (negative)", "ReferenceError: Error #1120", function () { delete flt4[-1] });
AddErrorTest("delete an out-of-range element of a float4 (non-integer)", "ReferenceError: Error #1120", function () { delete flt4["4.75"] });
AddErrorTest("delete an out-of-range element of a float4 (non-number)", "ReferenceError: Error #1120", function () { delete flt4["zappa"] });

test();
