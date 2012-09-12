/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*
Returns an implementation-dependent approximation to the tangent of x. The
argument is expressed in radians.
*/

var SECTION = "4.5.32";
var VERSION = "AS3";
var TITLE   = "public function tan(x:float):float";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

AddErrorTest("float.tan() with no args", ARGUMENTERROR+1063,  function(){ float.tan(); });

// If x is NaN, the result is NaN.
AddStrictTestCase("float.tan(string)", float.NaN, float.tan("string"));
AddStrictTestCase("float.tan(undefined)", float.NaN, float.tan(undefined));

// If x is +0, the result is +0.
AddStrictTestCase("float.tan(false)", 0f, float.tan(false));


test();

