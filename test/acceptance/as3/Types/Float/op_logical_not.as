/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "6.3.7";
var VERSION = "AS3";
var TITLE   = "The logical not ! operator";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var flt:float = new float(3.1413119f);
AddStrictTestCase("logical not on float", !3, !flt);

flt = float(+0.0);
AddStrictTestCase("!float(+0.0)", Boolean(true), !flt);

flt = +0.0f;
AddTestCase("!(+0.0f) FloatLiteral", true, !flt);

flt = float(-0.0);
AddTestCase("!float(-0.0)", true, !flt);

flt = -0.0f;
AddTestCase("!(-0.0f) FloatLiteral", true, !flt);

flt = float.NaN;
AddTestCase("!float.NaN", true, !flt);

flt = float.MIN_VALUE;
AddTestCase("!float.MIN_VALUE", false, !flt);

flt = -float.MIN_VALUE;
AddTestCase("!-float.MIN_VALUE", false, !flt);

flt = float(-0.23);
AddTestCase("!float(-0.23)", false, !flt);

flt = -0.23f;
AddTestCase("!(-0.23f) FloatLiteral", false, !flt);



test();

