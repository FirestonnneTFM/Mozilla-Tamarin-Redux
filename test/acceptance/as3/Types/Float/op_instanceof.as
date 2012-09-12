/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "6.7.4";
var VERSION = "AS3";
var TITLE   = "The instanceof operator augmented by float values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var onef:float = 1f;
var vf = new Vector.<float>();

AddTestCase("float class is not instanceof float", false, float instanceof float);
AddTestCase("FloatLiteral is instanceof float", true, 1f instanceof float);
AddTestCase("float instance is instanceof float", true, onef instanceof float);
AddTestCase("float class is instanceof Object", true, float instanceof Object);
AddTestCase("float class is instanceof Class", true, float instanceof Class);
AddTestCase("float class is not instanceof Function", false, float instanceof Function);
AddTestCase("FloatLiteral is instanceof Object", true, 1f instanceof Object);
AddTestCase("float instance is instanceof Object", true, onef instanceof Object);
AddTestCase("Vector.<float> is not instanceof float", false, vf instanceof float);


AddTestCase("float class is not instanceof Number", false, float instanceof Number);
AddTestCase("FloatLiteral is not instanceof Number", false, 1f instanceof Number);
AddTestCase("float instance is not instanceof Number", false, onef instanceof Number);
AddTestCase("float class is not instanceof int", false, float instanceof int);
AddTestCase("FloatLiteral is not instanceof int", false, 1f instanceof int);
AddTestCase("float instance is not instanceof int", false, onef instanceof int);
AddTestCase("float class is not instanceof uint", false, float instanceof uint);
AddTestCase("FloatLiteral is not instanceof uint", false, 1f instanceof uint);
AddTestCase("float instance is not instanceof uint", false, onef instanceof uint);
AddTestCase("float class is not instanceof String", false, float instanceof String);
AddTestCase("FloatLiteral is not instanceof String", false, 1f instanceof String);
AddTestCase("float instance is not instanceof String", false, onef instanceof String);

AddErrorTest("AS: TypeError if datatype is not Class or Function", TYPEERROR, function(){ return 1f instanceof 1f; });


test();

