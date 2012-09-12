/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

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

