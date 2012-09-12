/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*
The Number value for e, the base of the natural logarithms, which is approximately
2.7182818284590452354. This property has the attributes { [[Writable]]: false,
[[Enumerable]]: false, [[Configurable]]: false }.
*/

include "numberUtil.as";

var SECTION = "15.8.1.1";
var VERSION = "AS3";
var TITLE   = "public static const E:Number = 2.718281828459045;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var num_e:Number = 2.718281828459045;

AddTestCase("Number.E", num_e, Number.E);
AddTestCase("typeof Number.E", "Number", getQualifiedClassName(Number.E));

AddTestCase("Number.E - DontDelete", false, delete(Number.E));
AddTestCase("Number.E is still ok", num_e, Number.E);

AddTestCase("Number.E - DontEnum", '', getNumberProp('E'));
AddTestCase("Number.E is no enumberable", false, Number.propertyIsEnumerable('E'));

AddErrorTest("Number.E - ReadOnly", REFERENCEERROR+1074, function(){ Number.E = 0; });
AddTestCase("Number.E is still here", num_e, Number.E);

test();

