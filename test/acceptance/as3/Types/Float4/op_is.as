/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "5.5.1";
var VERSION = "AS3";
var TITLE   = "The is operator augmented by float4 values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var pi_float4:Object = new float4(3.14f);
var pi_float:Object = new float(3.14f);

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

