/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "5.8.2";
var VERSION = "AS3";
var TITLE   = "The || operator augmented by float4 values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

function check(val1:*, val2:*):* { return (val1 || val2); }

// Float4 converts to false always in a boolean context, so in || over
// float4 the last float4 value to be encountered is always returned.

AddTestCase("float4(1f) || float4(1f)", float4(1f), float4(1f) || float4(1f));
AddTestCase("float4(1f) || float4(0f)", float4(0f), float4(1f) || float4(0f));
AddTestCase("float4(0f) || float4(1f)", float4(1f), float4(0f) || float4(1f));
AddTestCase("float4(-0f) || float4(1f)", float4(1f), float4(-0f) || float4(1f));
AddTestCase("float4(float.NaN) || float4(1f)", float4(1f), float4(float.NaN) || float4(1f));
AddTestCase("check(float4(1f), float4(1f))", float4(1f), check(float4(1f), float4(1f)));
AddTestCase("check(float4(1f), float4(0f))", float4(0f), check(float4(1f), float4(0f)));
AddTestCase("check(float4(0f), float4(1f))", float4(1f), check(float4(0f), float4(1f)));
AddTestCase("check(float4(-0f), float4(1f))", float4(1f), check(float4(-0f), float4(1f)));
AddTestCase("check(float4(float.NaN), float4(1f))", float4(1f), check(float4(float.NaN), float4(1f)));

AddTestCase("float4(1f, 2f, 3f, 4f) || float4(-1f, -2f, -3f, -4f)", float4(-1f, -2f, -3f, -4f), float4(1f, 2f, 3f, 4f) || float4(-1f, -2f, -3f, -4f));
AddTestCase("check(float4(1f, 2f, 3f, 4f), float4(-1f, -2f, -3f, -4f))", float4(-1f, -2f, -3f, -4f), check(float4(1f, 2f, 3f, 4f), float4(-1f, -2f, -3f, -4f)));

AddTestCase("float4(1f, 2f, 3f, float.NaN) || float4(-1f, -2f, -3f, -4f)", float4(-1f, -2f, -3f, -4f), float4(1f, 2f, 3f, float.NaN) || float4(-1f, -2f, -3f, -4f));
AddTestCase("float4(1f, 2f, 3f, 4f) || float4(0f, -2f, -3f, -4f)",  float4(0f, -2f, -3f, -4f), float4(1f, 2f, 3f, 4f) || float4(0f, -2f, -3f, -4f));
AddTestCase("float4(1f, 2f, -0f, 4f) || float4(-1f, -2f, -3f, -4f)", float4(-1f, -2f, -3f, -4f), float4(1f, 2f, -0f, 4f) || float4(-1f, -2f, -3f, -4f));
AddTestCase("float4(0f, -0f, float.NaN, 0f) || float4(1f)", float4(1f), float4(0f, -0f, float.NaN, 0f) || float4(1f));

AddTestCase("check(float4(1f, 2f, 3f, float.NaN), float4(-1f, -2f, -3f, -4f))", float4(-1f, -2f, -3f, -4f), check(float4(1f, 2f, 3f, float.NaN), float4(-1f, -2f, -3f, -4f)));
AddTestCase("check(float4(1f, 2f, 3f, 4f), float4(0f, -2f, -3f, -4f))",  float4(0f, -2f, -3f, -4f), check(float4(1f, 2f, 3f, 4f) , float4(0f, -2f, -3f, -4f)));
AddTestCase("check(float4(1f, 2f, -0f, 4f), float4(-1f, -2f, -3f, -4f))", float4(-1f, -2f, -3f, -4f), check(float4(1f, 2f, -0f, 4f), float4(-1f, -2f, -3f, -4f)));
AddTestCase("check(float4(0f, -0f, float.NaN, 0f), float4(1f))", float4(1f), check(float4(0f, -0f, float.NaN, 0f), float4(1f)));

test();

