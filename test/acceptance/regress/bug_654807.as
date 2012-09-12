/* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/. */

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
