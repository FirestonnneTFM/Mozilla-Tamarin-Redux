/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
include "floatUtil.as";


var SECTION = "4.6.1";
var VERSION = "AS3";
var TITLE   = "float.prototype.constructor";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


AddTestCase("float.prototype.constructor = float", float, float.prototype.constructor);
AddTestCase("float.prototype.constructor = function", false, float.prototype.constructor is Function);

AddTestCase("float.prototype.constructor - DontEnum", "", getFloatProtoProp("constructor"));
AddTestCase("float.prototype.constructor is not enumerable", false, float.prototype.propertyIsEnumerable("constructor"));

var orig_cstr = float.prototype.constructor;
float.prototype.constructor = 1.1243174;
AddTestCase("float.prototype.constructor - Writable", true, orig_cstr != float.prototype.constructor);
float.prototype.constructor = orig_cstr;

AddTestCase("float.prototype.constructor - Deletable", true, delete(float.prototype.constructor));
// it should now find "Object" as constructor, on the prototype chain
AddTestCase("float.prototype.constructor should now be Object.prototype.constructor", Object, float.prototype.constructor);
float.prototype.constructor = orig_cstr;

test();

