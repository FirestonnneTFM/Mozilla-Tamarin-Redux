/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "6.7.1";
var VERSION = "AS3";
var TITLE   = "The is operator augmented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(var1:*, var2:*):* { return var1 is var2; }

var pi_float:Object = new float(3.14);

AddTestCase("3.14f is float", true, pi_float is float);
AddTestCase("3.14f FloatLiteral is float", true, 3.14f is float);
AddTestCase("3.14f is NOT Number", false, pi_float is Number);
AddTestCase("3.14f FloatLiteral is NOT Number", false, 3.14f is Number);
AddTestCase("3.14f is Object", true, pi_float is Object);
AddTestCase("2.1f FloatLiteral is Object", true, 2.1f is Object);
AddTestCase("3.14f is NOT int", false, pi_float is int);
AddTestCase("3.14f FloatLiteral is NOT int", false, 3.14f is int);

AddTestCase("float.MIN_VALUE is float", true, float.MIN_VALUE is float);
AddTestCase("float.MAX_VALUE is float", true, float.MAX_VALUE is float);
AddTestCase("float.POSITIVE_INFINITY is float", true, float.POSITIVE_INFINITY is float);
AddTestCase("float.NEGATIVE_INFINITY is float", true, float.NEGATIVE_INFINITY is float);
AddTestCase("float.NaN is float", true, float.NaN is float);

var three:float = 3f;
AddTestCase("3f is NOT int", false, three is int);
AddTestCase("3f FloatLiteral is NOT int", false, 3f is int);

var minus_three:float = -3f;
AddTestCase("-3f is NOT int", false, minus_three is int);
AddTestCase("-3f FloatLiteral is NOT int", false, -3f is int);

var large_int_as_float:float = 0x7FFFFF00;
AddTestCase("large positive is NOT int", false, large_int_as_float is int);

var large_neg_int_as_float:float = int.MIN_VALUE;
AddTestCase("large negative is NOT int", false, large_neg_int_as_float is int);

AddTestCase("3.14f is NOT uint", false, pi_float is uint);
AddTestCase("3.14f FloatLiterl is NOT uint", false, 3.14f is uint);
AddTestCase("3f is NOT uint", false, three is uint);
AddTestCase("3f FloatLiteral is NOT uint", false, 3f is uint);
AddTestCase("-3f is NOT uint", false, minus_three is uint);
AddTestCase("-3f FloatLiteral is NOT uint", false, -3f is uint);

var large_uint_as_float:float = 0xFFFFFF00;
AddTestCase("large uint positive is NOT uint", false, large_uint_as_float is uint);
AddTestCase("large uint positive is NOT int", false, large_uint_as_float is int);

var zero:float = 0f;
var neg_zero:float = -0f;
AddTestCase("0f is NOT uint", false, zero is uint);
AddTestCase("0f FloatLiteral is NOT uint", false, 0f is uint);
AddTestCase("-0f is NOT uint", false, neg_zero is uint);
AddTestCase("-0f FloatLiteral is NOT uint", false, -0f is uint);

AddTestCase("0f is NOT String,", false, zero is String);
AddTestCase("0f is NOT Boolean", false, zero is Boolean);
AddTestCase("0f is NOT Error", false, zero is Error);
AddTestCase("0f FloatLiteral is NOT String,", false, 0f is String);
AddTestCase("0f FloatLiteral is NOT Boolean", false, 0f is Boolean);
AddTestCase("0f FloatLiteral is NOT Error", false, 0f is Error);

AddTestCase("Number.NaN is NOT float", false, Number.NaN is float);
AddTestCase("toplevel NaN (Number) is NOT float", false, Number.NaN is float);


AddTestCase("Number(float.MAX_VALUE) is NOT float", false, (new Number(float.MAX_VALUE)) is float);
AddTestCase("Number(float.MIN_VALUE) is NOT float", false, (new Number(float.MIN_VALUE)) is float);
AddTestCase("Number(Infinity) is NOT float", false, (new Number(Infinity)) is float);

AddStrictTestCase("2.01 is float", false, 2.01 is float);
AddStrictTestCase("2.01 is float check()", false, check(2.01, float));
AddStrictTestCase("3 is float", false, 3 is float);
AddStrictTestCase("3 is float check()", false, check(3, float));

AddTestCase("int.length (1) is NOT float", false, int.length is float);

AddTestCase("int.MIN_VALUE is NOT float (large negative no., but requires little mantissa)", false, int.MIN_VALUE is float);

var large_neg_int:int = int.MIN_VALUE+1;
AddTestCase("large_negative_int is NOT float", false, large_neg_int is float);

AddTestCase("uint.MAX_VALUE is NOT float (too big positive no)", false, uint.MAX_VALUE is float);

AddTestCase("uint.MIN_VALUE (0) is NOT float", false, uint.MIN_VALUE is float);

var large_int:int = -268435456;
AddTestCase("large int is NOT float (if it ends in lots of zeroes - i.e. requires less than 23bits of mantissa)", false, large_int is float);

var large_uint:uint = 268435456;
AddTestCase("large unsigned int is NOT float (if it ends in lots of zeroes - i.e. requires less than 23bits of mantissa)", false, large_uint is float);

var vf = new Vector.<float>();
AddTestCase("Vector.<float> value is Vector.<float>", true, vf is Vector.<float>);
AddTestCase("Vector.<float> value is Object", true, vf is Object);
AddTestCase("Vector.<float> value is NOT Vector.<Number>", false, vf is Vector.<Number>);
AddTestCase("Vector.<float> value is NOT Vector.<Object>", false, vf is Vector.<Object>);
AddTestCase("Vector.<float> value is NOT Vector.<*>", false, vf is Vector.<*>);
vf = new Vector.<*>();
vf.push(float.MAX_VALUE);
AddTestCase("Vector.<*> value is NOT Vector.<float>", false, vf is Vector.<float>);

vf = new Vector.<Number>();
AddTestCase("Vector.<Number> value is NOT Vector.<float>", false, vf is Vector.<float>);
vf = new Vector.<String>();
AddTestCase("Vector.<String> value is NOT Vector.<float>", false, vf is Vector.<float>);
vf = new Vector.<Object>();
AddTestCase("Vector.<Object> value is NOT Vector.<float>", false, vf is Vector.<float>);
vf = new Vector.<int>();
AddTestCase("Vector.<int> value is NOT Vector.<float>", false, vf is Vector.<float>);
vf = new Vector.<uint>();
AddTestCase("Vector.<uint> value is NOT Vector.<float>", false, vf is Vector.<float>);

AddTestCase("String is NOT float", false, "twelve" is float);
var myObject:Object = {};
AddTestCase("Object is NOT float", false, myObject is float);
AddTestCase("Boolean is NOT float", false, true is float);
var myArray:Array = new Array();
AddTestCase("Array is NOT float", false, myArray is float);


test();

