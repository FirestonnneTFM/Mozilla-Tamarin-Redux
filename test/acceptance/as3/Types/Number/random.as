/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/*
Returns a Number value with positive sign, greater than or equal to 0 but less
than 1, chosen randomly or pseudo randomly with approximately uniform distribution
over that range, using an implementation-dependent algorithm or strategy. This
function takes no arguments.
*/

import avmplus.*;

var SECTION = "15.8.2.14";
var VERSION = "AS3";
var TITLE   = "public native static function random ():Number;";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


AddTestCase("Number.random() returns a Number", "Number", getQualifiedClassName(Number.random()));
AddTestCase("Number.random() length is 0", 0, Number.random.length);
AddErrorTest("Number.random() with args", ARGUMENTERROR+1063,  function(){ Number.random(12); });

var myRandom:Number;
for (var x:int = 0; x < 1000; x++)
{
    myRandom = Number.random();
    if ( myRandom < 0)
        AddTestCase("Number.random() illegal value returned", "<0", myRandom);
    if ( myRandom > 1)
        AddTestCase("Number.random() illegal value returned", ">1", myRandom);
}


test();

