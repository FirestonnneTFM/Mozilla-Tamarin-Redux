/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "floatUtil.as";


var SECTION = "9.2";
var VERSION = "AS3";
var TITLE   = "The operation ToFloat";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var not_def; // undefined
var result = float(not_def);
AddTestCase("ToFloat(undefined)", true, isNaN(result));

result = float(null);
AddTestCase("ToFloat(null)", 0, FloatRawBits(result) );// Note: if the result is -0.0f, FloatRawBits would return -2147483648 (0x80000000)
AddTestCase("ToFloat(null) return type", "float", getQualifiedClassName(result));

AddTestCase("ToFloat(true)", float(1.0) /*TODO: should be 1.0f */, float(true) );
// Ok, so skip check_type every now and then... no biggie

result = float(false);
AddTestCase("ToFloat(false)", 0, FloatRawBits(result) );  // Note: if the result is -0.0f, FloatRawBits would return -2147483648 (0x80000000)
AddTestCase("ToFloat(false) return type", "float", getQualifiedClassName(result));

var flt_nan_mask:int = 0x7f800000; // (FloatRawBits(float.NaN) & 0x7f800000) == 0x7f800000
AddTestCase("ToFloat(Number.NaN)", flt_nan_mask, (FloatRawBits(float(Number.NaN)) & flt_nan_mask) );

var inf_int:int = 2139095040; //  0x7f800000 - positive infinity
var large_poz:float = Number.MAX_VALUE;
AddTestCase("ToFloat(>float.MAX_VALUE)", inf_int, FloatRawBits(large_poz) );


var neg_inf_int:int = -8388608; //0xff800000 - negative infinity
var large_neg:Number = -Number.MAX_VALUE;
result = float(large_neg);
AddTestCase("ToFloat(<-float.MAX_VALUE)", neg_inf_int, FloatRawBits(result) );
// we do this slightly different than large_poz... just for variation.
AddTestCase("ToFloat((<-float.MAX_VALUE) return type", "float", getQualifiedClassName(result));

large_neg = -float.MAX_VALUE;
AddTestCase("ToFloat(Number(-float.MAX_VALUE))", -float.MAX_VALUE, float(large_neg));

result = Number(float.MAX_VALUE);
AddTestCase("ToFloat(Number(float.MAX_VALUE))", float.MAX_VALUE, float(result));
AddTestCase("ToFloat(Number(float.MAX_VALUE)) return type", "Number", getQualifiedClassName(result));

var golden:Number= 1.6180339887;
var golden_bits:int=0x3fcf1bbd; // , i.e. 1.618034f
result = float(golden);
AddTestCase("ToFloat(Number(some_number - round up))", golden_bits, FloatRawBits(result));
AddTestCase("ToFloat(Number(some_number - round up)) return type", "float", getQualifiedClassName(result));


var lots_of_ones:float = 1.11111111111111111111111111111111111111111111111111111111111111111;
var lots_of_ones_bits:int=0x3F8E38E4; //  ,i.e. 1.1111111f
AddTestCase("ToFloat(Number(some_number - round down))", lots_of_ones_bits, FloatRawBits(lots_of_ones));

var golden_float:float = 1.618034; // TODO: should be 1.618034f!
AddTestCase("ToFloat(Object)", golden_float, float(new MyObject(golden)));

AddTestCase("ToFloat(String)", golden_float, float("1.618034"));

AddTestCase("ToFloat(float)", golden_float, float(golden_float));


var f4:float = float4(3f);
AddTestCase("f4:float = float4(3f)", float.NaN, f4);
var f:* = float(float4(1f));  // NaN
AddTestCase("f:float = float(float4(1f))", float.NaN, f);


test();

