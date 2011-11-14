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


var SECTION = "5.5.1";
var VERSION = "AS3";
var TITLE   = "The is operator augmented by float4 values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var pi_float4:Object = new float4(3.14f);
var pi_float:Object = new float(3.14f);
AddErrorTest("TypeError if datatype is not Class", TYPEERROR, function(){ return pi_float4 is "float4"; });

AddTestCase("float4(3.14f) is float", true, pi_float4 is float4);
AddTestCase("float4(3.14f) is NOT Number", false, pi_float4 is Number);
AddTestCase("float4(3.14f) is Object", true, pi_float4 is Object);
AddTestCase("float4(3.14f) is NOT int", false, pi_float4 is int);

AddTestCase("float(3.14f) is NOT float4", false, float(3.14f) is float4);
AddTestCase("float var is NOT float4", false, pi_float is float4);

var three:float4 = float4(3f);
AddTestCase("float4(3f) is NOT int", false, three is int);

var minus_three:float4 = float4(-3f);
AddTestCase("float4(-3f) is NOT int", false, minus_three is int);
AddTestCase("float4(3.14f) is NOT uint", false, pi_float4 is uint);
var zero:float4 = float4(0f);
var neg_zero:float4 = float4(-0f);
AddTestCase("float4(0f) is NOT uint", false, zero is uint);
AddTestCase("float4(-0f) is NOT uint", false, neg_zero is uint);

AddTestCase("float4(0f) is NOT String,", false, zero is String);
AddTestCase("float4(0f) is NOT Boolean", false, zero is Boolean);
AddTestCase("float4(0f) is NOT Error", false, zero is Error);
AddTestCase("Number.NaN is NOT float4", false, Number.NaN is float4);


AddTestCase("Number(Infinity) is NOT float4", false, (new Number(Infinity)) is float4);

var vf = new Vector.<float4>();
AddTestCase("Vector.<float4> value is Vector.<float4>", true, vf is Vector.<float4>);
AddTestCase("Vector.<float4> value is Object", true, vf is Object);
AddTestCase("Vector.<float4> value is NOT Vector.<Number>", false, vf is Vector.<Number>);
AddTestCase("Vector.<float4> value is NOT Vector.<Object>", false, vf is Vector.<Object>);
AddTestCase("Vector.<float4> value is NOT Vector.<*>", false, vf is Vector.<*>);
vf = new Vector.<*>();
vf.push(float4.MAX_VALUE);
AddTestCase("Vector.<*> value is NOT Vector.<float4>", false, vf is Vector.<float4>);

vf = new Vector.<Number>();
AddTestCase("Vector.<Number> value is NOT Vector.<float4>", false, vf is Vector.<float4>);
vf = new Vector.<String>();
AddTestCase("Vector.<String> value is NOT Vector.<float4>", false, vf is Vector.<float4>);
vf = new Vector.<Object>();
AddTestCase("Vector.<Object> value is NOT Vector.<float4>", false, vf is Vector.<float4>);
vf = new Vector.<int>();
AddTestCase("Vector.<int> value is NOT Vector.<float4>", false, vf is Vector.<float4>);
vf = new Vector.<uint>();
AddTestCase("Vector.<uint> value is NOT Vector.<float4>", false, vf is Vector.<float4>);

AddTestCase("String is NOT float4", false, "twelve" is float4);
var myObject:Object = {};
AddTestCase("Object is NOT float4", false, myObject is float4);
AddTestCase("Boolean is NOT float4", false, true is float4);
var myArray:Array = new Array();
AddTestCase("Array is NOT float4", false, myArray is float4);


test();

