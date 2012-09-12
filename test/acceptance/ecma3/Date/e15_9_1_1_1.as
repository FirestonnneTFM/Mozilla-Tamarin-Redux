/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

//  every one hundred years contains:
//    24 years with 366 days
//
//  every four hundred years contains:
//    97 years with 366 days
//   303 years with 365 days
//
//   86400000*365*97    =    3067372800000
//  +86400000*366*303   =  + 9555408000000
//                      =    1.26227808e+13
    var FOUR_HUNDRED_YEARS = 1.26227808e+13;
    var SECTION         =  "15.9.1.1-1";

    startTest();
    var testcases       = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    
    for (  M_SECS = 0, CURRENT_YEAR = 1970;
                 M_SECS < 8640000000000000;
                tc++,   M_SECS += FOUR_HUNDRED_YEARS, CURRENT_YEAR += 400 ) {

        array[item++] = new TestCase( SECTION,   "new Date("+M_SECS+")", CURRENT_YEAR, (new Date( M_SECS)).getUTCFullYear() );
    }

    array[item++] = new TestCase( SECTION,   "new Date(Number.NaN)", NaN, (new Date( Number.NaN)).getUTCFullYear() );
    
    return array;
}
