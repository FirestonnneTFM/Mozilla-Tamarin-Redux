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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
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
 * ***** END LICENSE BLOCK *****
*
*
* See http://bugzilla.mozilla.org/show_bug.cgi?id=599357
*
*/
//-----------------------------------------------------------------------------

var SECTION = "599357";
var VERSION = "";
var TITLE   = "Testing indexed get/set prop access with numeric expressions";
var bug = "599357";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();

    function getArrayAddII(a:Array, b:int, c:int){
        try {
            return (a[(b + c)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function getArrayIntToNumber(_arg1:Array, _arg2:int){
        var arr:Number = _arg2;
        return (_arg1[arr]);
    };
    function getArrayUintToNumber(_arg1:Array, _arg2:uint){
        var _local3:Number = _arg2;
        return (_arg1[_local3]);
    };
    function getArrayConstToNumber(_arg1:Array){
        var _local2:Number = 1;
        return (_arg1[_local2]);
    };
    function getArrayAddIC(a:Array, b:int){
        try {
            return (a[(b + 1)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function getArrayAddCI(a:Array, b:int){
        try {
            return (a[(1 + b)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function getArraySubII(a:Array, b:int, c:int){
        try {
            return (a[(b - c)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function getArraySubIC(a:Array, b:int){
        try {
            return (a[(b - 1)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function getArraySubCI(a:Array, b:int){
        try {
            return (a[(1 - b)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function getVectorAddII(a:Vector.<int>, b:int, c:int){
        try {
            return (a[(b + c)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function getVectorAddIC(a:Vector.<int>, b:int){
        try {
            return (a[(b + 1)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function getVectorAddCI(a:Vector.<int>, b:int){
        try {
            return (a[(1 + b)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function getVectorSubII(a:Vector.<int>, b:int, c:int){
        try {
            return (a[(b - c)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function getVectorSubIC(a:Vector.<int>, b:int){
        try {
            return (a[(b - 1)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function getVectorSubCI(a:Vector.<int>, b:int){
        try {
            return (a[(1 - b)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function setArrayAddII(a:Array, b:int, c:int, d:int){
        try {
            a[(b + c)] = d;
            return (a[(b + c)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function setArrayIntToNumber(a:Array, b:int, c:int){
        var d:Number = b;
        a[d] = c;
        return (a[d]);
    };
    function setArrayUintToNumber(a:Array, b:uint, c:int){
        var d:Number = b;
        a[d] = c;
        return (a[d]);
    };
    function setArrayConstToNumber(a:Array, b:int){
        var d:Number = 1;
        a[d] = b;
        return (a[d]);
    };
    function setArrayAddIC(a:Array, b:int, d:int){
        try {
            a[(b + 1)] = d;
            return (a[(b + 1)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function setArrayAddCI(a:Array, b:int, d:int){
        try {
            a[(1 + b)] = d;
            return (a[(1 + b)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function setArraySubII(a:Array, b:int, c:int, d:int){
        try {
            a[(b - c)] = d;
            return (a[(b - c)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function setArraySubIC(a:Array, b:int, d:int){
        try {
            a[(b - 1)] = d;
            return (a[(b - 1)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function setArraySubCI(a:Array, b:int, d:int){
        try {
            a[(1 - b)] = d;
            return (a[(1 - b)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function setVectorAddII(a:Vector.<int>, b:int, c:int, d:int){
        try {
            a[(b + c)] = d;
            return (a[(b + c)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function setVectorAddIC(a:Vector.<int>, b:int, d:int){
        try {
            a[(b + 1)] = d;
            return (a[(b + 1)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function setVectorAddCI(a:Vector.<int>, b:int, d:int){
        try {
            a[(1 + b)] = d;
            return (a[(1 + b)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function setVectorSubII(a:Vector.<int>, b:int, c:int, d:int){
        try {
            a[(b - c)] = d;
            return (a[(b - c)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function setVectorSubIC(a:Vector.<int>, b:int, d:int){
        try {
            a[(b - 1)] = d;
            return (a[(b - 1)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };
    function setVectorSubCI(a:Vector.<int>, b:int, d:int){
        try {
            a[(1 - b)] = d;
            return (a[(1 - b)]);
        } catch(e) {
            return (grabError(e, e.toString()));
        };
    };


	function getTestCases() {
        var array:Array = new Array();
        var index:int = 0;
        var arr:Array = [1, 2, 3, 4, 5];
        var vec:Vector.<int> = new Vector.<int>();
        vec.fixed = false;
        vec[0] = 1;
        vec[1] = 2;
        vec[2] = 3;
        vec[3] = 4;
        vec[4] = 5;
        array[index++] = new TestCase(SECTION, "array[1+2]", 4, getArrayAddII(arr, 1, 2));
        array[index++] = new TestCase(SECTION, "array[1+ -2]", undefined, getArrayAddII(arr, 1, -2));
        array[index++] = new TestCase(SECTION, "array[0x7fffffff+0x7fffffff]", undefined, getArrayAddII(arr, 0x7fffffff, 0x7fffffff));
        array[index++] = new TestCase(SECTION, "array[0x7fffffff+ -0x7fffffff]", 1, getArrayAddII(arr, 0x7fffffff, -0x7fffffff));
        array[index++] = new TestCase(SECTION, "array[-0x7fffffff+ -0x7fffffff]", undefined, getArrayAddII(arr, -0x7fffffff, -0x7fffffff));
        array[index++] = new TestCase(SECTION, "array[2+1], where 1 is const", 4, getArrayAddIC(arr, 2));
        array[index++] = new TestCase(SECTION, "array[2-1], where 1 is const", 2, getArraySubIC(arr, 2));
        array[index++] = new TestCase(SECTION, "array[1+2], where 1 is const", 4, getArrayAddCI(arr, 2));
        array[index++] = new TestCase(SECTION, "array[1-2], where 1 is const", undefined, getArraySubCI(arr, 2));
        array[index++] = new TestCase(SECTION, "array[2-1]", 2, getArraySubII(arr, 2, 1));
        array[index++] = new TestCase(SECTION, "array[0x80000000-0x80000000]", 1, getArraySubII(arr, 0x80000000, 0x80000000));
        array[index++] = new TestCase(SECTION, "array[0x80000000+0x80000000]", undefined, getArrayAddII(arr, 0x80000000, 0x80000000));
        
        array[index++] = new TestCase(SECTION, "vector[1+2]", 4, getVectorAddII(vec, 1, 2));
        array[index++] = new TestCase(SECTION, "vector[1+ -2]", "Error #1069", getVectorAddII(vec, 1, -2));
        array[index++] = new TestCase(SECTION, "vector[0x7fffffff+0x7fffffff]", "Error #1125", getVectorAddII(vec, 0x7fffffff, 0x7fffffff));
        array[index++] = new TestCase(SECTION, "vector[0x7fffffff+ -0x7fffffff]", 1, getVectorAddII(vec, 0x7fffffff, -0x7fffffff));
        array[index++] = new TestCase(SECTION, "vector[-0x7fffffff+ -0x7fffffff]", "Error #1069", getVectorAddII(vec, -0x7fffffff, -0x7fffffff));
        array[index++] = new TestCase(SECTION, "vector[2+1], where 1 is const", 4, getVectorAddIC(vec, 2));
        array[index++] = new TestCase(SECTION, "vector[2-1], where 1 is const", 2, getVectorSubIC(vec, 2));
        array[index++] = new TestCase(SECTION, "vector[1+2], where 1 is const", 4, getVectorAddCI(vec, 2));
        array[index++] = new TestCase(SECTION, "vector[1-2], where 1 is const", "Error #1069", getVectorSubCI(vec, 2));
        array[index++] = new TestCase(SECTION, "vector[2-1]", 2, getVectorSubII(vec, 2, 1));
        array[index++] = new TestCase(SECTION, "vector[0x80000000-0x80000000]", 1, getVectorSubII(vec, 0x80000000, 0x80000000));
        array[index++] = new TestCase(SECTION, "vector[0x80000000+0x80000000]", "Error #1069", getVectorAddII(vec, 0x80000000, 0x80000000));
        
        array[index++] = new TestCase(SECTION, "array[1], where 1 is a const stored in a Number var", 2, getArrayConstToNumber(arr));
        array[index++] = new TestCase(SECTION, "array[1], where 1 is a int stored in a Number var", 2, getArrayIntToNumber(arr, 1));
        array[index++] = new TestCase(SECTION, "array[1], where 1 is a uint stored in a Number var", 2, getArrayUintToNumber(arr, 1));
        
        array[index++] = new TestCase(SECTION, "set array[1], where 1 is a const stored in a Number var", 100, setArrayConstToNumber(arr, 100));
        array[index++] = new TestCase(SECTION, "set array[1], where 1 is a int stored in a Number var", 101, setArrayIntToNumber(arr, 1, 101));
        array[index++] = new TestCase(SECTION, "set array[1], where 1 is a uint stored in a Number var", 102, setArrayUintToNumber(arr, 1, 102));
        
        array[index++] = new TestCase(SECTION, "set array[1+2]", 10, setArrayAddII(arr, 1, 2, 10));
        array[index++] = new TestCase(SECTION, "set array[1+ -2]", 11, setArrayAddII(arr, 1, -2, 11));
        array[index++] = new TestCase(SECTION, "set array[0x7fffffff+0x7fffffff]", 12, setArrayAddII(arr, 0x7fffffff, 0x7fffffff, 12));
        array[index++] = new TestCase(SECTION, "set array[0x7fffffff+ -0x7fffffff]", 13, setArrayAddII(arr, 0x7fffffff, -0x7fffffff, 13));
        array[index++] = new TestCase(SECTION, "set array[-0x7fffffff+ -0x7fffffff]", 14, setArrayAddII(arr, -0x7fffffff, -0x7fffffff, 14));
        array[index++] = new TestCase(SECTION, "set array[2+1], where 1 is const", 15, setArrayAddIC(arr, 2, 15));
        array[index++] = new TestCase(SECTION, "set array[1+2], where 1 is const", 17, setArrayAddCI(arr, 2, 17));
        array[index++] = new TestCase(SECTION, "set array[2-1], where 1 is const", 16, setArraySubIC(arr, 2, 16));
        array[index++] = new TestCase(SECTION, "set array[1-2], where 1 is const", 18, setArraySubCI(arr, 2, 18));
        array[index++] = new TestCase(SECTION, "set array[2-1]", 19, setArraySubII(arr, 2, 1, 19));
        array[index++] = new TestCase(SECTION, "set array[-0x7fffffff- 0x7fffffff]", 20, setArraySubII(arr, -0x7fffffff, 0x7fffffff, 20));
        
        array[index++] = new TestCase(SECTION, "set vector[1+2]", 10, setVectorAddII(vec, 1, 2, 10));
        array[index++] = new TestCase(SECTION, "set vector[1+ -2]", "Error #1056", setVectorAddII(vec, 1, -2, 11));
        array[index++] = new TestCase(SECTION, "set vector[0x7fffffff+0x7fffffff]", "Error #1125", setVectorAddII(vec, 0x7fffffff, 0x7fffffff, 12));
        array[index++] = new TestCase(SECTION, "set vector[0x7fffffff+ -0x7fffffff]", 13, setVectorAddII(vec, 0x7fffffff, -0x7fffffff, 13));
        array[index++] = new TestCase(SECTION, "set vector[-0x7fffffff+ -0x7fffffff]", "Error #1056", setVectorAddII(vec, -0x7fffffff, -0x7fffffff, 14));
        array[index++] = new TestCase(SECTION, "set vector[2+1], where 1 is const", 15, setVectorAddIC(vec, 2, 15));
        array[index++] = new TestCase(SECTION, "set vector[2-1], where 1 is const", 16, setVectorSubIC(vec, 2, 16));
        array[index++] = new TestCase(SECTION, "set vector[1+2], where 1 is const", 17, setVectorAddCI(vec, 2, 17));
        array[index++] = new TestCase(SECTION, "set vector[1-2], where 1 is const", "Error #1056", setVectorSubCI(vec, 2, 18));
        array[index++] = new TestCase(SECTION, "set vector[1-1], where 1 is const", 18, setVectorSubCI(vec, 1, 18));
        array[index++] = new TestCase(SECTION, "set vector[2-1]", 19, setVectorSubII(vec, 2, 1, 19));
        array[index++] = new TestCase(SECTION, "set vector[-0x7fffffff- 0x7fffffff]", "Error #1056", setVectorSubII(vec, -0x7fffffff, 0x7fffffff, 19));
                
        return (array);
}
