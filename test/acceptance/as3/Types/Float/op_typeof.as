/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "6.3.2";
var VERSION = "AS3";
var TITLE   = "The typeof operator";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var flt:float = 2.7182818284e5f;
AddTestCase("typeof on float", "float", typeof(flt));
AddTestCase("typeof on FloatLiteral", "float", typeof(2.7182818284e5f));

var flt_uninit:float;
AddTestCase("typeof on uninitilized float", "float", typeof(flt_uninit));
AddTestCase("typeof on new float()", "float", typeof(new float()));

AddTestCase("typeof on float.MAX_VALUE", "float", typeof(float.MAX_VALUE));

test();

