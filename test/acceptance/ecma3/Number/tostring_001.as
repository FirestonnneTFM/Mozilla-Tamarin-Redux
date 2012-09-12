/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var SECTION = "tostring_001"
printStatus ("Number formatting test.");
printBugNumber ("11178");

startTest();
var testcases = getTestCases();
test();

function getTestCases()
{
    var array = new Array();
    var item = 0;
    
    var n0 = 1e23;
    var n1 = 5e22;
    var n2 = 1.6e24;

    array[item++] = new TestCase(SECTION, "1e+23", n0.toString(),"1e+23" );
    
    array[item++] = new TestCase(SECTION, "5e+22", n1.toString(), "5e+22");
    
    array[item++] = new TestCase(SECTION, "1.6e+24", n2.toString(), "1.6e+24");
    
    return array;
}


