/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2007-2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

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
