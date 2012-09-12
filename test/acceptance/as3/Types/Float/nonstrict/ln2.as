/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "floatUtil.as";


var SECTION = "4.5.10";
var VERSION = "AS3";
var TITLE   = "float.LN2";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var flt_ln2:float = float(0.693147181);

AddTestCase("float.LN2", flt_ln2, float.LN2);
AddTestCase("typeof float.LN2", "float", getQualifiedClassName(float.LN2));

AddTestCase("float.LN2 - DontDelete", false, delete(float.LN2));
AddTestCase("float.LN2 is still ok", flt_ln2, float.LN2);

AddTestCase("float.LN2 - DontEnum", '',getFloatProp('LN2'));
AddTestCase("float.LN2 is no enumberable", false, float.propertyIsEnumerable('LN2'));

AddErrorTest("float.LN2 - ReadOnly", REFERENCEERROR+1074, function(){ float.LN2 = 0; });
AddTestCase("float.LN2 is still here", flt_ln2, float.LN2);

test();

