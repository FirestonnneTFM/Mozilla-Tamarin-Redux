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

var SECTION = "5.5.2";
var VERSION = "AS3";
var TITLE   = "The as operator augmented by float4 values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var pi_float4:Object = new float4(3.14f);
var pi_float:Object = new float(3.14f);
var three:float4 = float4(3f);
var minus_three:float4 = float4(-3f);
var zero:float4 = float4(0f);
var large_int_as_float4:float4 = float4(0x7FFFFF00);
var large_neg_int_as_float4:float4 = float4(int.MIN_VALUE);
var large_neg_int:int = int.MIN_VALUE+1;
var large_int:int = -268435456;
var large_uint:uint = 268435456;


AddStrictTestCase("float4(3.14f) as float4", float4(3.14), pi_float4 as float4);
AddStrictTestCase("float4(3.14f) as Number", null, pi_float4 as Number);
AddStrictTestCase("float4(2.1f) as Object", float4(2.1), float4(2.1) as Object);
AddTestCase("float4(3.14f) as int", null, pi_float4 as int);
AddStrictTestCase("float4(3f) as int", null, three as int);
AddTestCase("float4(-3f) as int", null, minus_three as int);
AddTestCase("float4(3.14f) as uint", null, pi_float4 as uint);
AddTestCase("float4(3f) as uint", null, three as uint);
AddTestCase("float4(-3f) as uint", null, minus_three as uint);
AddTestCase("float4(0f) as String", null, zero as String);
AddTestCase("float4(0f) as Boolean", null, zero as Boolean);
AddTestCase("float4(0f) as Error", null, zero as Error);
AddTestCase("Number.NaN as float4", null, Number.NaN as float4);
AddTestCase("float(3.14f) as float4", null, float(3.14f) as float4);
AddTestCase("float var as float4", null, pi_float as float4);

AddStrictTestCase("2.01 as float4 (null)", null, 2.01 as float4);

AddStrictTestCase("int.length (1) as  float4 ", null, int.length as float4);

AddStrictTestCase("int.MIN_VALUE as  float4", null, int.MIN_VALUE as float4);

AddStrictTestCase("large_negative_int as  float4 (null)", null, large_neg_int as float4);

AddStrictTestCase("uint.MAX_VALUE as float4 (null)", null, uint.MAX_VALUE as float4);

AddStrictTestCase("uint.MIN_VALUE (0) as float4", null, uint.MIN_VALUE as float4);

AddStrictTestCase("large int as float4 (if it ends in lots of zeroes - i.e. requires less than 23bits of mantissa)", null, large_int as float4);

AddStrictTestCase("large unsigned int as float4 (if it ends in lots of zeroes - i.e. requires less than 23bits of mantissa)", null, large_uint as float4);

var vf = new Vector.<float4>();
vf = new Vector.<float4>();
AddTestCase("Vector.<float4> value as Vector.<float>", null, vf as Vector.<float>);
AddTestCase("Vector.<float4> value as Object", vf, vf as Object);
AddTestCase("Vector.<float4> value as Vector.<Number>", null ,vf as Vector.<Number>);
AddTestCase("Vector.<float4> value as Vector.<Object>", null ,vf as Vector.<Object>);
AddTestCase("Vector.<float4> value as Vector.<*>", null, vf as Vector.<*>);

vf = new Vector.<Number>();
AddTestCase("Vector.<Number> value as NOT Vector.<float4>", null, vf as Vector.<float4>);
vf = new Vector.<String>();
AddTestCase("Vector.<String> value as NOT Vector.<float4>", null, vf as Vector.<float4>);
vf = new Vector.<Object>();
AddTestCase("Vector.<Object> value as NOT Vector.<float4>", null, vf as Vector.<float4>);
vf = new Vector.<int>();
AddTestCase("Vector.<int> value as NOT Vector.<float4>", null, vf as Vector.<float4>);
vf = new Vector.<uint>();
AddTestCase("Vector.<uint> value as NOT Vector.<float4>", null, vf as Vector.<float4>);

AddTestCase("String as float", null, "twelve" as float4);
var myObject:Object = {};
AddTestCase("Object as float4", null, myObject as float4);
AddTestCase("Boolean as float4", null, true as float4);
var myArray:Array = new Array();
AddTestCase("Array as floa4t", null, myArray as float4);



test();

