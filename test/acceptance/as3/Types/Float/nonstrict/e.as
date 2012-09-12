/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "floatUtil.as";


var SECTION = "4.5.8";
var VERSION = "AS3";
var TITLE   = "float.E";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


// var flt_e:float = float(Math.E);
var flt_e:float = float(2.7182818);

AddTestCase("float.E", flt_e, float.E);
AddTestCase("typeof float.E", "float", getQualifiedClassName(float.E));

AddTestCase("float.E - DontDelete", false, delete(float.E));
AddTestCase("float.E is still ok", flt_e, float.E);

AddTestCase("float.E - DontEnum", '',getFloatProp('E'));
AddTestCase("float.E is no enumberable", false, float.propertyIsEnumerable('E'));

AddErrorTest("float.E - ReadOnly", REFERENCEERROR+1074, function(){ float.E = 0; });
AddTestCase("float.E is still here", flt_e, float.E);

test();

