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

var SECTION = "6.7.2";
var VERSION = "AS3";
var TITLE   = "The as operator augmented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var pi_float:Object = new float(3.14);
var three:float = 3f;
var minus_three:float = -3f;
var large_int_as_float:float = 0x7FFFFF00;
var large_neg_int_as_float:float = int.MIN_VALUE;
var large_uint_as_float:float = 0xFFFFFF00;
var zero:float = 0f;
var large_neg_int:int = int.MIN_VALUE+1;
var large_int:int = -268435456;
var large_uint:uint = 268435456;
var vf = new Vector.<float>();

function check(var1:*, var2:*):* { return var1 as var2; }

AddStrictTestCase("3.14f as float", float(3.14), pi_float as float);
AddStrictTestCase("3.14f FloatLiteral as float", float(3.14), 3.14f as float);
AddStrictTestCase("3.14f as Number", null, pi_float as Number);
AddStrictTestCase("3.14f FloatLiteral as Number", null, 3.14f as Number);
AddStrictTestCase("2.1f as Object", float(2.1), float(2.1) as Object);
AddStrictTestCase("2.1f FloatLiteral as Object", float(2.1), 2.1f as Object);
AddTestCase("3.14f as int", null, pi_float as int);
AddTestCase("3.14f FloatLiteral as int", null, 3.14f as int);
AddStrictTestCase("3f as int", null, three as int);
AddStrictTestCase("3f FloatLiteral as int", null, 3f as int);
AddTestCase("-3f as int", null, minus_three as int);
AddTestCase("-3f FloatLiteral as int", null, -3f as int);
AddTestCase("3.14f as uint", null, pi_float as uint);
AddTestCase("3.14f FloatLiteral as uint", null, 3.14f as uint);
AddTestCase("3f as uint", null, three as uint);
AddTestCase("3f FloatLiteral as uint", null, 3f as uint);
AddTestCase("-3f as uint", null, minus_three as uint);
AddTestCase("-3f FloatLiteral as uint", null, -3f as uint);
AddTestCase("0f as String", null, zero as String);
AddTestCase("0f FloatLiteral as String", null, 0f as String);
AddTestCase("0f as Boolean", null, zero as Boolean);
AddTestCase("0f FloatLiteral as Boolean", null, 0f as Boolean);
AddTestCase("0f as Error", null, zero as Error);
AddTestCase("0f FloatLiteral as Error", null, 0f as Error);
AddTestCase("Number.NaN as float", null, Number.NaN as float);

AddTestCase("float.MIN_VALUE as float", float.MIN_VALUE, float.MIN_VALUE as float);
AddTestCase("float.MAX_VALUE as float", float.MAX_VALUE, float.MAX_VALUE as float);
AddTestCase("float.POSITIVE_INFINITY as float", float.POSITIVE_INFINITY, float.POSITIVE_INFINITY as float);
AddTestCase("float.NEGATIVE_INFINITY as float", float.NEGATIVE_INFINITY, float.NEGATIVE_INFINITY as float);
AddTestCase("float.NaN as float", float.NaN, float.NaN as float);

AddStrictTestCase("Number(float.MAX_VALUE) as float", null, (new Number(float.MAX_VALUE)) as float);
AddStrictTestCase("Number(float.MIN_VALUE) as float", null, (new Number(float.MIN_VALUE)) as float);

AddStrictTestCase("float(Number.MAX_VALUE) as float is float(Infinity)", float(Infinity), (new float(Number.MAX_VALUE)) as float);

AddStrictTestCase("2.01 as float", null, 2.01 as float);
AddStrictTestCase("2.01 as float check()", null, check(2.01, float));
AddStrictTestCase("3 as float", null, 3 as float);
AddStrictTestCase("3 as float check()", null, check(3, float));

AddStrictTestCase("int.length (1) as  float ", null, int.length as float);

AddStrictTestCase("int.MIN_VALUE as  float", null, int.MIN_VALUE as float);
AddStrictTestCase("check int.MIN_VALUE as float", null, check(int.MIN_VALUE, float));

AddStrictTestCase("large_negative_int as  float (null)", null, large_neg_int as float);

AddStrictTestCase("uint.MAX_VALUE as float (null)", null, uint.MAX_VALUE as float);

AddStrictTestCase("uint.MIN_VALUE (0) as float", null, uint.MIN_VALUE as float);
AddStrictTestCase("check uint.MIN_VALUE (0) as float", null, check(uint.MIN_VALUE, float));

AddStrictTestCase("large int as float (if it ends in lots of zeroes - i.e. requires less than 23bits of mantissa)", null, large_int as float);

AddStrictTestCase("large unsigned int as float (if it ends in lots of zeroes - i.e. requires less than 23bits of mantissa)", null, large_uint as float);

vf = new Vector.<*>();
vf.push(float.MAX_VALUE);
AddTestCase("Vector.<*> value as Vector.<float>", null, vf as Vector.<float>);
vf = new Vector.<float>();
AddTestCase("Vector.<float> value as Vector.<float>", vf, vf as Vector.<float>);
AddTestCase("Vector.<float> value as Object", vf, vf as Object);
AddTestCase("Vector.<float> value as Vector.<Number>", null ,vf as Vector.<Number>);
AddTestCase("Vector.<float> value as Vector.<Object>", null ,vf as Vector.<Object>);
AddTestCase("Vector.<float> value as Vector.<*>", null, vf as Vector.<*>);

vf = new Vector.<Number>();
AddTestCase("Vector.<Number> value as NOT Vector.<float>", null, vf as Vector.<float>);
vf = new Vector.<String>();
AddTestCase("Vector.<String> value as NOT Vector.<float>", null, vf as Vector.<float>);
vf = new Vector.<Object>();
AddTestCase("Vector.<Object> value as NOT Vector.<float>", null, vf as Vector.<float>);
vf = new Vector.<int>();
AddTestCase("Vector.<int> value as NOT Vector.<float>", null, vf as Vector.<float>);
vf = new Vector.<uint>();
AddTestCase("Vector.<uint> value as NOT Vector.<float>", null, vf as Vector.<float>);

AddTestCase("String as float", null, "twelve" as float);
var myObject:Object = {};
AddTestCase("Object as float", null, myObject as float);
AddTestCase("Boolean as float", null, true as float);
var myArray:Array = new Array();
AddTestCase("Array as float", null, myArray as float);



test();

