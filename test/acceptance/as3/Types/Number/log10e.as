/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "numberUtil.as";


var SECTION = "15.8.1.5";
var VERSION = "AS3";
var TITLE   = "public static const LOG10E:Number = 0.4342944819032518";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var num_log10e:Number = 0.4342944819032518;

AddTestCase("Number.LOG10E", num_log10e, Number.LOG10E);
AddTestCase("typeof Number.LOG10E", "Number", getQualifiedClassName(Number.LOG10E));

AddTestCase("Number.LOG10E - DontDelete", false, delete(Number.LOG10E));
AddTestCase("Number.LOG10E is still ok", num_log10e, Number.LOG10E);

AddTestCase("Number.LOG10E - DontEnum", '',getNumberProp('LOG10E'));
AddTestCase("Number.LOG10E is no enumberable", false, Number.propertyIsEnumerable('LOG10E'));

AddErrorTest("Number.LOG10E - ReadOnly", REFERENCEERROR+1074, function(){ Number.LOG10E = 0; });
AddTestCase("Number.LOG10E is still here", num_log10e, Number.LOG10E);

// NOTE The value of Math.LOG10E is approximately the reciprocal of the value of Math.LN10.
AddTestCase("Number.LOG10E is approximately the reciprocal of the value of Number.LN10", 1/Number.LN10, Number.LOG10E);

test();

