/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "8";
var VERSION = "AS3";
var TITLE   = "The operation ToBoolean";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var v:Boolean;

v = float4(+0.0f);
AddTestCase("ToBoolean(float4(+0.0f))", false, v);

v = float4(-0.0f);
AddTestCase("ToBoolean(flaot4(-0.0f))", false, v);

v = float4(float.NaN);
AddTestCase("ToBoolean(float4(float.NaN))", false, v);

v = float4(1f);
AddTestCase("ToBoolean(float4(1f))", false, v);

v = float4(float(true));
AddTestCase("ToBoolean(float4(float(true)))", false, v);

v = float4(float(false));
AddTestCase("ToBoolean(float4(float(false)))", false, v);

test();

