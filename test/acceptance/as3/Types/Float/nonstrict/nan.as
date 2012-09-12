/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "floatUtil.as";


var SECTION = "4.5.5";
var VERSION = "AS3";
var TITLE   = "float.NaN";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var flt_nan:float = float.NaN;
var flt_nan_mask:int = 0x7f800000; // (FloatRawBits(float.NaN) & 0x7f800000) == 0x7f800000
AddTestCase("float.NaN", flt_nan_mask,  (FloatRawBits(float.NaN) & flt_nan_mask)); // Note: strictly speaking, float.NaN could have another hex representation, too.

var nanfl = 0f/0f;
AddTestCase("float.NaN is 0f/0f FloatLiteral", nanfl, float.NaN);

var nanf:float = 0f/0f;
AddTestCase("float.NaN is 0f/0f", nanf, float.NaN);


AddTestCase("float.NaN - DontDelete", false, delete(float.NaN));
AddTestCase("float.NaN is still ok", flt_nan_mask,  (FloatRawBits(float.NaN) & flt_nan_mask));

AddTestCase("float.NaN - DontEnum", '',getFloatProp('NaN'));
AddTestCase("float.NaN is no enumberable", false, float.propertyIsEnumerable('NaN'));

AddErrorTest("float.NaN - ReadOnly", REFERENCEERROR+1074, function(){ float.NaN = 0; });
AddTestCase("float.NaN is still here", flt_nan_mask,  (FloatRawBits(float.NaN) & flt_nan_mask));


test();

