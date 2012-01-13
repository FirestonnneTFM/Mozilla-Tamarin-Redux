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

var SECTION = "13";
var VERSION = "AS3";
var TITLE   = "Vector.<float>";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var f1:float = 3.1415f;
var f2:float = float.MAX_VALUE;
var f3:float = -0.00032f;
var f4:float = -12.375f;

var vecFlt:Vector.<float> = new Vector.<float>();
vecFlt.push(f1);
vecFlt.push(f2);
vecFlt.push(f3);
vecFlt.push(f4);

AddTestCase("vecflt[0] value", f1, vecFlt[0]);
AddTestCase("vecflt[0] typeof", "float", typeof vecFlt[0]);
AddTestCase("vecflt[1] value", f2, vecFlt[1]);
AddTestCase("vecflt[1] typeof", "float", typeof vecFlt[1]);
AddTestCase("vecflt[2] value", f3, vecFlt[2]);
AddTestCase("vecflt[2] typeof", "float", typeof vecFlt[2]);
AddTestCase("vecflt[3] value", f4, vecFlt[3]);
AddTestCase("vecflt[3] typeof", "float", typeof vecFlt[3]);


// Bug 697741 - Vector optimizations for float are miss using type information
var v:Vector.<float> = new <float> [1,1,1,1];
AddStrictTestCase("v[0] value", 1f, v[0]);
foo(v);
function foo(vec:Vector.<float>){ AddStrictTestCase("v[0] value", 1f, vec[0]); }

test();

