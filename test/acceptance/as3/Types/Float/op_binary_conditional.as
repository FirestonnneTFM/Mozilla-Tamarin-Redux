/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "6.11";
var VERSION = "AS3";
var TITLE   = "The conditional operator augmented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var neg_onef:float = -1f;
var zerof:float = 0f;
var onef:float = 1f;

AddTestCase("1f ? 'PASSED' : 'FAILED'", "PASSED", (onef?"PASSED":"FAILED"));
AddTestCase("1f FloatLiteral ? 'PASSED' : 'FAILED'", "PASSED", (1f?"PASSED":"FAILED"));
AddTestCase("0f ? 'FAILED' : 'PASSED'", "PASSED", (zerof?"FAILED":"PASSED"));
AddTestCase("0f FloatLiteral ? 'FAILED' : 'PASSED'", "PASSED", (0f?"FAILED":"PASSED"));
AddTestCase("-1f ? 'PASSED' : 'FAILED'", "PASSED", (neg_onef?"PASSED":"FAILED"));
AddTestCase("-1f FloatLiteral ? 'PASSED' : 'FAILED'", "PASSED", (-1f?"PASSED":"FAILED"));
AddTestCase("float.NaN ? 'FAILED' : 'PASSED'", "PASSED", (float.NaN?"FAILED":"PASSED"));



test();
