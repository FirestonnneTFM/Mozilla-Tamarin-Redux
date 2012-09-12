/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "apply regression";
var VERSION = "ECMA_3";

trace("STATUS: f.apply crash test.");

trace("BUGNUMBER: 21836");
startTest();

var testcases = getTestCases();

test();

function f()
{
}

function getTestCases() {
    var array = new Array();
    var item = 0;
    var thisError="no error";
    trace("The second argument of f.apply() should be an array:  "+test());

    function doTest():String
    {
        //f.apply(2,2);
    
        try{
            f.apply(2,2);
        }catch(e:Error){
            thisError=(e.toString()).substring(0,22);
        }finally{
    
        }
        return thisError;
    }

    doTest();

    array[item++] = new TestCase(SECTION, "Make sure we don't crash", true, true);

    return array;
}
