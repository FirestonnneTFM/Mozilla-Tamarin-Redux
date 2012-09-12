/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "floatUtil.as";


var SECTION = "4.5.12";
var VERSION = "AS3";
var TITLE   = "float.PI";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var flt_pi:float = float(3.1415927);

AddTestCase("float.PI", flt_pi, float.PI);
AddTestCase("typeof float.PI", "float", getQualifiedClassName(float.PI));

AddTestCase("float.PI - DontDelete", false, delete(float.PI));
AddTestCase("float.PI is still ok", flt_pi, float.PI);

AddTestCase("float.PI - DontEnum", '',getFloatProp('PI'));
AddTestCase("float.PI is no enumberable", false, float.propertyIsEnumerable('PI'));

AddErrorTest("float.PI - ReadOnly", REFERENCEERROR+1074, function(){ float.PI = 0; });
AddTestCase("float.PI is still here", flt_pi, float.PI);

test();

