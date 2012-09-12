/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    //print( String( 10000000000000000000 ) )
    var SECTION = "15.5.4.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "String.prototype.constructor";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();


function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION, "String.prototype.constructor == String",  true, String.prototype.constructor == String );
    thisError="no error";
    STRING = new String.prototype.constructor('hi');
    try{
        STRING.getClass = Object.prototype.toString;
        STRING.getClass();
    }catch(e:Error){
        thisError=e.toString();
    }finally{
        array[item++] = new TestCase( SECTION, "var STRING = new String.prototype.constructor('hi'); STRING.getClass = Object.prototype.toString; STRING.getClass()","ReferenceError: Error #1056",referenceError(thisError));
    }

    /*array[item++] = new TestCase( SECTION, "var STRING = new String.prototype.constructor('hi'); STRING.getClass = Object.prototype.toString; STRING.getClass()","[object String]",(STRING = new String.prototype.constructor('hi'), STRING.getClass = Object.prototype.toString, STRING.getClass() ) );*/
    return ( array );
}

