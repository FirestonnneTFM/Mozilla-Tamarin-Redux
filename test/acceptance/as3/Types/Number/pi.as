/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "numberUtil.as";


var SECTION = "15.8.1.6";
var VERSION = "AS3";
var TITLE   = "public static const PI:Number = 3.141592653589793;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var num_pi:Number = 3.141592653589793;

AddTestCase("Number.PI", num_pi, Number.PI);
AddTestCase("typeof Number.PI", "Number", getQualifiedClassName(Number.PI));

AddTestCase("Number.PI - DontDelete", false, delete(Number.PI));
AddTestCase("Number.PI is still ok", num_pi, Number.PI);

AddTestCase("Number.PI - DontEnum", '',getNumberProp('PI'));
AddTestCase("Number.PI is no enumberable", false, Number.propertyIsEnumerable('PI'));

AddErrorTest("Number.PI - ReadOnly", REFERENCEERROR+1074, function(){ Number.PI = 0; });
AddTestCase("Number.PI is still here", num_pi, Number.PI);

test();

