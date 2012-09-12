/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION="";

startTest();

writeHeaderToLog( "Test getting vector values");


// Round out code coverage with these tests

// ****************************

function testGetSet_UintVector_UintIndex() {
    
    var v:Vector.<uint> = new Vector.<uint>(10, false);
    var a:uint = 5;
    v[a] = 33;
    AddTestCase("set uint property", 33, v[5]);
    AddTestCase("get uint property", 33, v[a]);
    
    // get: m_length <= index
    var errormsg = "no error";
    a = 10;
    try {
        var dummy = v[a];
    } catch (e) {
        errormsg = e.toString();
    }
    AddTestCase("get: m_length == index",
                "RangeError: Error #1125",
                parseError(errormsg, "RangeError: Error #1125".length));
    
    // m_length == index,
    a = 10;
    v[a] = 33;
    AddTestCase("set uint property: index == length",
                33,
                v[10]);
    AddTestCase("set uint property: index == length, verify length grows by one",
                    11,
                    v.length);
    
    // index > m_length
    a = 20;
    errormsg = "no error";
    try {
        v[a] = setValue;
    } catch (e) {
        errormsg = e.toString();
    }
    AddTestCase("index > m_length",
                "ReferenceError: Error #1065",
                parseError(errormsg, "ReferenceError: Error #1125".length));
    
    // index > m_length, m_fixed=true
    v = new Vector.<uint>(10, true);
    a = 10;
    var errormsg = "no error";
    try {
        v[a] = setValue;
    } catch (e) {
        errormsg = e.toString();
    }
    AddTestCase("index == m_length, m_fixed=true",
                "ReferenceError: Error #1065",
                parseError(errormsg, "ReferenceError: Error #1125".length));
} // testGetSet

// VectorClass.h: _get/_setUintProperty(uint32_t,T)
//testGetSet(int, uint, 555);
testGetSet_UintVector_UintIndex();


test();
