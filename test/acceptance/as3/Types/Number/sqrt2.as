/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "numberUtil.as";


var SECTION = "15.8.2.8";
var VERSION = "AS3";
var TITLE   = "public static const SQRT2:Number = 1.4142135623730951;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var num_sqrt2:Number = 1.4142135623730951;

AddTestCase("Number.SQRT2", num_sqrt2, Number.SQRT2);
AddTestCase("typeof Number.SQRT2", "Number", getQualifiedClassName(Number.SQRT2));

AddTestCase("Number.SQRT2 - DontDelete", false, delete(Number.SQRT2));
AddTestCase("Number.SQRT2 is still ok", num_sqrt2, Number.SQRT2);

AddTestCase("Number.SQRT2 - DontEnum", '',getNumberProp('SQRT2'));
AddTestCase("Number.SQRT2 is no enumberable", false, Number.propertyIsEnumerable('SQRT2'));

AddErrorTest("Number.SQR_2 - ReadOnly", REFERENCEERROR+1074, function(){ Number.SQRT2 = 0; });
AddTestCase("Number.SQRT2 is still here", num_sqrt2, Number.SQRT2);

test();

