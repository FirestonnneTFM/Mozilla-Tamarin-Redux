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
* Portions created by the Initial Developer are Copyright (C) 2008
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

import avmplus.System;

var SECTION = "regress_654807";
var VERSION = "AS3";
var TITLE   = "SealedArray";
var bug = "654807";


startTest();
writeHeaderToLog(SECTION + " " + TITLE);

    // standard AddErrorTest function doesn't handle no-error well.
    function MyAddTestCase(desc:String, expected:String, testFunc:Function) 
    {
        try {
            var actual = testFunc();
            AddTestCase(desc, expected, String(actual));
        } catch (e) {
            actualErr = e;
            grabError(actualErr, expected);
            AddTestCase(desc, expected, String(actualErr).substr(0, expected.length));
        }
    }

    class SealedArray extends Array {}
    dynamic class DynamicArray extends Array {}
    dynamic class DynamicSealedArray extends SealedArray {}
    class SealedDynamicArray extends DynamicArray {}

    function run_tests(b:Array, mode:String)
    {
        // idiom "String(b.concat())" is used to create a copy of the 
        // possibly-subclass-of-Array, since toString may not work on the subclass
        
        MyAddTestCase(mode+" get_length", 
            "0", 
            function() { var r = b.length; return String(r); });

        MyAddTestCase(mode+" push", 
            { dynamic:"0,1,2", semisealed:"0,1,2", sealed:"ReferenceError: Error #1056"}[mode],
            function() { b.push(0,1,2); return String(b.concat()); });

        MyAddTestCase(mode+" get_length", 
            { dynamic:"3", semisealed:"3", sealed:"0"}[mode],
            function() { var r = b.length; return String(r); });

        MyAddTestCase(mode+" unshift", 
            { dynamic:"4,5,6,0,1,2", semisealed:"4,5,6,0,1,2", sealed:"ReferenceError: Error #1056"}[mode],
            function() { b.unshift(4,5,6); return String(b.concat()); });

        MyAddTestCase(mode+" get_length", 
            { dynamic:"6", semisealed:"6", sealed:"0"}[mode],
            function() { var r = b.length; return String(r); });

        MyAddTestCase(mode+" concat", 
            { dynamic:"4,5,6,0,1,2,4,5,6,0,1,2", semisealed:"4,5,6,0,1,2,4,5,6,0,1,2", sealed:""}[mode],
            function() { var r = b.concat(b); return String(r.concat()); });

        MyAddTestCase(mode+" get_length", 
            { dynamic:"6", semisealed:"6", sealed:"0"}[mode],
            function() { var r = b.length; return String(r); });

        MyAddTestCase(mode+" reverse", 
            { dynamic:"2,1,0,6,5,4", semisealed:"2,1,0,6,5,4", sealed:""}[mode],
            function() { b.reverse(); return String(b.concat()); });
        
        MyAddTestCase(mode+" get_length", 
            { dynamic:"6", semisealed:"6", sealed:"0"}[mode],
            function() { var r = b.length; return String(r); });

        MyAddTestCase(mode+" shift", 
            { dynamic:"2:1,0,6,5,4", semisealed:"2:1,0,6,5,4", sealed:"undefined:"}[mode],
            function() { var r = b.shift(); return String(r) + ":" + String(b.concat()); });

        MyAddTestCase(mode+" get_length", 
            { dynamic:"5", semisealed:"5", sealed:"0"}[mode],
            function() { var r = b.length; return String(r); });

        // splice fails differently when delCount == 0 vs delCount > 0
        MyAddTestCase(mode+" splice", 
            { dynamic:"9,1,0,6,5,4", semisealed:"9,1,0,6,5,4", sealed:"ReferenceError: Error #1056"}[mode],
            function() { b.splice(0, 0, 9); return String(b.concat()); });

        MyAddTestCase(mode+" get_length", 
            { dynamic:"6", semisealed:"6", sealed:"0"}[mode],
            function() { var r = b.length; return String(r); });

        MyAddTestCase(mode+" pop", 
            { dynamic:"4:9,1,0,6,5", semisealed:"4:9,1,0,6,5", sealed:"undefined:"}[mode],
            function() { var r = b.pop(); return String(r) + ":" + String(b.concat()); });

        MyAddTestCase(mode+" get_length", 
            { dynamic:"5", semisealed:"5", sealed:"0"}[mode],
            function() { var r = b.length; return String(r); });

        MyAddTestCase(mode+" set_length", 
            { dynamic:"3:9,1,0", semisealed:"5:9,1,0,6,5", sealed:"0:"}[mode],
            function() { b.length = 3; var r = b.length; return String(r) + ":" + String(b.concat()); });

        MyAddTestCase(mode+" getprop", 
            { dynamic:"9", semisealed:"ReferenceError: Error #1069", sealed:"ReferenceError: Error #1069"}[mode],
            function() { return b[0]; });

        MyAddTestCase(mode+" setprop", 
            { dynamic:"undefined", semisealed:"ReferenceError: Error #1056", sealed:"ReferenceError: Error #1056"}[mode],
            function() { b[0] = 44; });

        MyAddTestCase(mode+" hasprop", 
            { dynamic:"true", semisealed:"false", sealed:"false"}[mode],
            function() { return b.hasOwnProperty(0); });

        MyAddTestCase(mode+" delprop", 
            { dynamic:"true", semisealed:"false", sealed:"false"}[mode],
            function() { return delete b[0]; });

        // splice fails differently when delCount == 0 vs delCount > 0
        MyAddTestCase(mode+" splice", 
            { dynamic:"9,1,0", semisealed:"ReferenceError: Error #1069", sealed:"ReferenceError: Error #1056"}[mode],
            function() { b.splice(0, 1, 9); return String(b.concat()); });

        MyAddTestCase(mode+" join", 
            { dynamic:"9~1~0", semisealed:"ReferenceError: Error #1069", sealed:""}[mode],
            function() { return String(b.join("~")); });

        MyAddTestCase(mode+" toString", 
            { dynamic:"9,1,0", semisealed:"ReferenceError: Error #1069", sealed:""}[mode],
            function() { return b.toString(); });

        MyAddTestCase(mode+" toLocaleString", 
            { dynamic:"9,1,0", semisealed:"ReferenceError: Error #1069", sealed:""}[mode],
            function() { return b.toLocaleString(); });

        MyAddTestCase(mode+" sort", 
            { dynamic:"0,1,9", semisealed:"ReferenceError: Error #1069", sealed:""}[mode],
            function() { return String(b.sort(Array.NUMERIC)); });

        MyAddTestCase(mode+" indexOf", 
            { dynamic:"2", semisealed:"ReferenceError: Error #1069", sealed:"-1"}[mode],
            function() { return String(b.indexOf(9)); });

        MyAddTestCase(mode+" lastIndexOf", 
            { dynamic:"2", semisealed:"ReferenceError: Error #1069", sealed:"-1"}[mode],
            function() { return String(b.lastIndexOf(9)); });

        MyAddTestCase(mode+" every", 
            { dynamic:"true", semisealed:"ReferenceError: Error #1069", sealed:"true"}[mode],
            function() { return String(b.every( function(i) { return true; } )); });

        MyAddTestCase(mode+" filter", 
            { dynamic:"0,9", semisealed:"ReferenceError: Error #1069", sealed:""}[mode],
            function() { return String(b.filter( function(i) { return i != 1; } )); });

        MyAddTestCase(mode+" forEach", 
            { dynamic:"undefined", semisealed:"ReferenceError: Error #1069", sealed:"undefined"}[mode],
            function() { return String(b.forEach( function(i) { } )); });

        MyAddTestCase(mode+" some", 
            { dynamic:"true", semisealed:"ReferenceError: Error #1069", sealed:"false"}[mode],
            function() { return String(b.some( function(i) { return true } )); });

        MyAddTestCase(mode+" map", 
            { dynamic:"1,2,10", semisealed:"ReferenceError: Error #1069", sealed:""}[mode],
            function() { return String(b.map( function(i) { return i+1 } )); });

        MyAddTestCase(mode+" for...in", 
            { dynamic:"0,1,2,", semisealed:"0,1,2,3,4,", sealed:""}[mode],
            function() { var s = ""; for (var i in b) { s += String(i) + ","; } return s; });

        MyAddTestCase(mode+" for each...in", 
            { dynamic:"0,1,9,", semisealed:"9,1,0,6,5,", sealed:""}[mode],
            function() { var s = ""; for each (var i in b) { s += String(i) + ","; } return s; });
        
    }
    run_tests(new Array, "dynamic");
    run_tests(new SealedArray, System.swfVersion < 13 ? "semisealed" : "sealed");
    run_tests(new DynamicArray, "dynamic");
    run_tests(new DynamicSealedArray, "dynamic");
    run_tests(new SealedDynamicArray, System.swfVersion < 13 ? "semisealed" : "sealed");


test();
