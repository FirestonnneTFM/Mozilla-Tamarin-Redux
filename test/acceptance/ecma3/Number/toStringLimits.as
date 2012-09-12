/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
var SECTION = "tostring_001"
printStatus ("Number formatting limits.");
printBugNumber ("2322890");

startTest();
var testcases = getTestCases();
test();

function getTestCases()
{
    var array = new Array();
    var item = 0;
    
    array[item++] = new TestCase(SECTION, "Number.MAX_VALUE", 1024, Number.MAX_VALUE.toString(2).length );
    array[item++] = new TestCase(SECTION, "-Number.MAX_VALUE", 1025, (-Number.MAX_VALUE).toString(2).length );

    //  Both these are rounded towards zero.
    array[item++] = new TestCase(SECTION, "Number.MIN_VALUE", 1, Number.MIN_VALUE.toString(2).length );
    array[item++] = new TestCase(SECTION, "-Number.MIN_VALUE", 1, (-Number.MIN_VALUE).toString(2).length );
    
    return array;
}


