/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
    In Ecma4 there are three sealed types; Boolean, Number and String
    You cannot set properties of an instance of a sealed type

    Should throw a ReferenceError

*/
    var SECTION = "ECMA_4";
    var VERSION = "ECMA_4";
    startTest();
    var TITLE   = "tostr=Number.prototype.toString;x=new Number();x.toString=tostr;";
    writeHeaderToLog( TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array:Array= new Array();
    var item:Number = 0;

    var thisError:String = "no exception thrown"
        //var tostr=Number.prototype.toString;
    var x:Number=new Number();
    try{
        x.toString=Number.prototype.toString;
        
    } catch (e:ReferenceError) {
        thisError = e.toString();
    } finally {
        var expectedError = 1056;
        if (as3Enabled) {
            expectedError = 1037;
        }
        array[item] = new TestCase(
                            SECTION,
                            "toStr=Number.prototype.toString;x=new Number();x.toString=tostr",
                            REFERENCEERROR+expectedError,
                            referenceError(thisError) );
    }
    return ( array );
}
