/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "5.10";
var VERSION = "AS3";
var TITLE   = "The assignment operators augmented by float4 values";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

var flt4:float4 = new float4(0f);
var tracker:int = 0;
var i:int

flt4 = new float4(2f);
AddTestCase("flt4 *= 3", float4(6f), flt4 *= 3);
AddTestCase("flt4 *= 2", float4(12f), flt4 *= 2);

flt4 = new float4(13f);
AddTestCase("flt4 %= 5", float4(3f), flt4 %= 5);
AddTestCase("flt4 %= 2", float4(1f), flt4 %= 2);

flt4 = new float4(12f);
AddTestCase("flt4 /= 3", float4(4f), flt4 /= 3);
AddTestCase("flt4 /= 2", float4(2f), flt4 /= 2);

flt4 = new float4(0f);
tracker = 0;
for (i = 1; i<5; i++)
{
    tracker += i;
    flt4 += i;
    AddTestCase("flt4 += "+i, float4(tracker), flt4);
}

flt4 = new float4(0f);
tracker = 0;
for (i = 1; i<5; i++)
{
    tracker -= i;
    flt4 -= i;
    AddTestCase("flt4 -= "+i, float4(tracker), flt4);
}


/*
AddTestCase("float4(1f) & float4(1f)", 0, float4(1f) & float4(1f));
AddTestCase("7 & float4(1f)", 0, 7 & float4(1f));
AddTestCase("float4(1f) & 3", 0, float4(1f) & 3);


AddTestCase("float4(1f) | float4(1f)", 0, float4(1f) | float4(1f));
AddTestCase("7 | float4(1f)", 7, 7 | float4(1f));
AddTestCase("float4(1f) | 3", 3, float4(1f) | 3);


AddTestCase("float4(1f) ^ float4(1f)", 0, float4(1f) ^ float4(1f));
AddTestCase("7 ^ float4(1f)", 7, 7 ^ float4(1f));
AddTestCase("float4(1f) ^ 3", 3, float4(1f) ^ 3);
*/

test();

