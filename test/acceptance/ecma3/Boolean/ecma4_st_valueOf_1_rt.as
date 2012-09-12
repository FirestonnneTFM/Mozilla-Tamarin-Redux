/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/*
    In Ecma4 there are three sealed types; Boolean, Number and String
    You cannot set properties of an instance of a sealed type

    Should throw a ReferenceError

    Author:     mtilburg@macromedia.com
    Date:       October 13, 2004

*/
    var SECTION = "ECMA_4";
    var VERSION = "ECMA_4";
    startTest();
    var TITLE   = "valof=Boolean.prototype.valueOf;booleanobj=true;booleanobj.valueOf=valof;";
    writeHeaderToLog( TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var booleanObj:Boolean = new Boolean();

    var thisError:String = "no error thrown";
    var array:Array = new Array();
    var item:Number = 0;

    var valof:Boolean=Boolean.prototype.valueOf;
    try{
        booleanObj.ValueOf=true;
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++] =new TestCase(SECTION,"Cannot create a property on Boolean","ReferenceError: Error #1056",referenceError( thisError ) );
    }

    try{
        booleanObj.ValueOf=valof;
    }catch(e1:ReferenceError){
        thisError=e1.toString();
    }finally{
        array[item++] =new TestCase(SECTION,"Cannot create a property on Boolean","ReferenceError: Error #1056",referenceError( thisError ) );
    }

    return ( array );
}
