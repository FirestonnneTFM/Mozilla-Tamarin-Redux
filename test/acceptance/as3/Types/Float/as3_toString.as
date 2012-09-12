/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "4.7.1";
var VERSION = "AS3";
var TITLE   = "AS3 function toString ( radix=10 ) : String";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var test_flt:float = 2.7182818284e5f;

AddTestCase("float.AS3::toString = function", true, test_flt.AS3::toString is Function);
AddTestCase("float.AS3::toString returns a String", "String", getQualifiedClassName(test_flt.AS3::toString()));

AddTestCase("float.AS3::toString applied to float literal", test_flt.AS3::toString(), 2.7182818284e5f.AS3::toString());

AddTestCase("float.AS3::toString: implicit radix is 10", test_flt.AS3::toString(10), test_flt.AS3::toString());

AddTestCase("float.AS3::toString: with string radix", Number(test_flt).AS3::toString(), test_flt.AS3::toString("10"));
AddTestCase("No range error for NaN", "NaN", float.NaN.toString(99));
AddTestCase("No range error for +Inf", "Infinity", float.POSITIVE_INFINITY.toString(99));
AddTestCase("No range error for -Inf", "-Infinity", float.NEGATIVE_INFINITY.toString(99));

AddErrorTest("float.AS3::toString: range errors toString(37)", RANGEERROR, function(){test_flt.AS3::toString(37)});
AddErrorTest("float.AS3::toString: range errors toString(1)", RANGEERROR, function(){test_flt.AS3::toString(1)});
AddErrorTest("float.AS3::toString: range errors toString(null)", RANGEERROR, function(){test_flt.AS3::toString(null)});
AddErrorTest("float.AS3::toString: range errors toString(undefined)", RANGEERROR, function(){test_flt.AS3::toString(undefined)});
AddErrorTest("float.AS3::toString: range errors toString(float.NaN)", RANGEERROR, function(){test_flt.AS3::toString(float.NaN)});
AddErrorTest("float.AS3::toString: range errors toString(Infinity)", RANGEERROR, function(){test_flt.AS3::toString(Infinity)});
AddErrorTest("float.AS3::toString: range errors toString(-Infinity)", RANGEERROR, function(){test_flt.AS3::toString(-Infinity)});


AddTestCase("float.AS3::toString: base 36", "5tqs", test_flt.AS3::toString(36)); // should go on to convert only the integral part
AddTestCase("float.AS3::toString: base 2", "1000010010111010100", test_flt.AS3::toString(2)); // should go on to convert only the integral part
AddTestCase("float.AS3::toString: decimal", "5tqs", test_flt.AS3::toString(36.2)); // should covert radix to int
AddTestCase("float.AS3::toString: hexadecimal", "5tqs", test_flt.AS3::toString(0x24)); // should covert radix to int

AddTestCase("float.AS3::toString: NaN, in base 16", "NaN", float.NaN.AS3::toString(16)); // base doesn't matter, still prints 'NaN'

AddTestCase("float.AS3::toString: float.MAX_VALUE, in base 16", "ffffff00000000000000000000000000", float.MAX_VALUE.AS3::toString(16));
AddTestCase("float.AS3::toString: float.MAX_VALUE, in base 16", (340282346638528859811704183484516925440).toString(16), float.MAX_VALUE.AS3::toString(16));

test_flt = -float.MAX_VALUE;
AddTestCase("float.AS3::toString: -float.MAX_VALUE, in base 16", "-ffffff00000000000000000000000000", test_flt.AS3::toString(16));
AddTestCase("float.AS3::toString: -float.MAX_VALUE, in base 16", (-340282346638528859811704183484516925440).toString(16), test_flt.AS3::toString(16));

test_flt = -float.MIN_VALUE;
AddTestCase("float.AS3::toString: -float.MIN_VALUE, in base 16", "0", test_flt.AS3::toString(16)); // shouldn't be "-0"!

test_flt = Infinity;
AddTestCase("float.AS3::toString: Infinity, in base 16", "Infinity", float.POSITIVE_INFINITY.AS3::toString(16)); // base doesn't matter, still prints 'Infinity'

test_flt = -Infinity;
AddTestCase("float.AS3::toString: -Infinity, in base 16", "-Infinity",float.NEGATIVE_INFINITY.AS3::toString(16)); // base doesn't matter, still prints '-Infinity'

test();

