/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "numberUtil.as";


var SECTION = "15.8.1.2";
var VERSION = "AS3";
var TITLE   = "public static const LN10:Number = 2.302585092994046;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var num_ln10:Number = 2.302585092994046;

AddTestCase("Number.LN10", num_ln10, Number.LN10);
AddTestCase("typeof Number.LN10", "Number", getQualifiedClassName(Number.LN10));

AddTestCase("Number.LN10 - DontDelete", false, delete(Number.LN10));
AddTestCase("Number.LN10 is still ok", num_ln10, Number.LN10);

AddTestCase("Number.LN10 - DontEnum", '',getNumberProp('LN10'));
AddTestCase("Number.LN10 is no enumberable", false, Number.propertyIsEnumerable('LN10'));

AddErrorTest("Number.LN10 - ReadOnly", REFERENCEERROR+1074, function(){ Number.LN10 = 0; });
AddTestCase("Number.LN10 is still here", num_ln10, Number.LN10);

test();

