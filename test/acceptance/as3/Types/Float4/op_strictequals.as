/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "5.6.3";
var VERSION = "AS3";
var TITLE   = "The === operator augmented by float4 values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var fivef:float = float(5f);
var fourf:float = float(4f);
var threef:float = float(3f);
var twof:float = float(2f);
var onef:float = float(1f);
var zerof:float = float(0f);

AddTestCase("float4(1f) === float4(1f)", true, float4(1f) === float4(1f));
AddTestCase("float4(0f) === float4(0f)", true, float4(0f) === float4(0f));
AddTestCase("float4(onef) === float4(onef)", true, float4(onef) === float4(onef));
AddTestCase("float4(zerof) === float4(zerof)", true, float4(zerof) === float4(zerof));
AddTestCase("float4(0f) === float4(-0f)", false, float4(0f) === float4(-0f));
AddTestCase("float4(0f) === float4(-0f)", false, float4(-0f) === float4(0f));
AddTestCase("float4(1f) === float4(2f)", false, float4(1f) === float4(2f));
AddTestCase("float4(2f) === float4(1f)", false, float4(2f) === float4(1f));

AddTestCase("float4(1f, 2f, 3f, 4f) === float4(1f, 2f, 3f, 4f)", true, float4(1f, 2f, 3f, 4f) === float4(1f, 2f, 3f, 4f));
AddTestCase("float4(1f, 2f, 3f, 4f) === float4(0f, 2f, 3f, 4f)", false, float4(1f, 2f, 3f, 4f) === float4(0f, 2f, 3f, 4f));
AddTestCase("float4(1f, 1f, 3f, 4f) === float4(1f, 1f, 3f, 4f)", false, float4(1f, 2f, 3f, 4f) === float4(1f, 1f, 3f, 4f));
AddTestCase("float4(1f, 2f, 2f, 4f) === float4(1f, 2f, 3f, 4f)", false, float4(1f, 2f, 3f, 4f) === float4(1f, 2f, 2f, 4f));
AddTestCase("float4(1f, 2f, 3f, 4f) === float4(!f, 2f, 3f, 5f)", false, float4(1f, 2f, 3f, 4f) === float4(1f, 2f, 3f, 5f));

AddTestCase("float4(onef, twof, threef, fourf) === float4(onef, twof, threef, fourf)", true, float4(onef, twof, threef, fourf) === float4(onef, twof, threef, fourf));
AddTestCase("float4(onef, twof, threef, fourf) === float4(zerof, twof, threef, fourf)", false, float4(onef, twof, threef, fourf) === float4(zerof, twof, threef, fourf));
AddTestCase("float4(onef, twof, threef, fourf) === float4(onef, onef, threef, fourf)", false, float4(onef, twof, threef, fourf) === float4(onef, onef, threef, fourf));
AddTestCase("float4(onef, twof, threef, fourf) === float4(onef, twof, twof, fourf)", false, float4(onef, twof, threef, fourf) === float4(onef, twof, twof, fourf));
AddTestCase("float4(onef, twof, threef, fourf) === float4(onef, twof, threef, 5f)", false, float4(onef, twof, threef, fourf) === float4(onef, twof, threef, fivef));

test();

