/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "6.3.1";
var VERSION = "AS3";
var TITLE   = "The delete operator";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var obj:Object = {Infinity:float.MAX_VALUE};
AddTestCase("delete on float", true, delete(obj[float.POSITIVE_INFINITY]));
AddTestCase("delete on float", undefined, obj.Infinity);

var obj2:Object = {1.0f:"bar"};
AddTestCase("delete on FloatLiteral property index", true, delete(obj2[1.0f]));
AddTestCase("delete on FloatLiteral property index", undefined, obj2[1.0f]);

test();

