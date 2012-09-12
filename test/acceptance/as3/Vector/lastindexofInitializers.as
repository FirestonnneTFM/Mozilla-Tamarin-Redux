/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/**
   File Name:    lastindexof.es
   Description:  lastindexOf(object,value,from=...)
     compares value with every vector element of object in increasing numerical index order, starting at the
     index from, stopping when an vector lement is equial to value by the === operator, From is rounded toward zero
     before use.  If from is negative, it is treated as object.length+from, returns vector index from first value or -1
     if no such element is found.
   *
   */

var SECTION = ""
var VERSION = "ECMA_1";

startTest();

writeHeaderToLog( SECTION + " Vector.lastIndexOf()-initializers");


AddTestCase(    "lastIndexOf empty vector",
        -1,
        new <int>[].lastIndexOf(0));

AddTestCase(    "lastIndexOf object not found",
        -1,
        new <int>[1,2,3,4,5].lastIndexOf(10));

AddTestCase(    "lastIndexOf single match found",
        4,
        new<int>[0,1,2,3,4,5,6,7,8,9].lastIndexOf(4));

AddTestCase(    "lastIndexOf first match found",
        24,
        new<int>[0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9].lastIndexOf(4));

AddTestCase(    "lastIndexOf first match found setting start parameter",
        14,
        [0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9].lastIndexOf(4,20));

AddTestCase(    "lastIndexOf start parameter greater than vector length",
        24,
        [0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9].lastIndexOf(4,100));

AddTestCase(    "lastIndexOf start parameter negative",
        14,
        [0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6,7,8,9].lastIndexOf(4,-10));

test();

