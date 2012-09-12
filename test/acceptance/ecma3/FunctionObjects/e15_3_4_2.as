/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.3.4.2";
    var VERSION = "ECMA_4";
    startTest();
    var TITLE   = "Function.prototype.toString()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;


    function MyObject( value ) {
        this.value = function() {return this.value;}
        this.toString = function() {return this.value+"";}
    }
    
    var myvar = new MyObject( true );
    myvar.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,  "myvar = new MyObject( true );  myvar.toString()",'[object Object]',myvar.toString());
        
    myvar = function() {};

    array[item++] = new TestCase( SECTION,  "myvar = function() {};  myvar.toString()",
                                            "function Function() {}",
                                            myvar.toString());
    
                                 
    array[item++] = new TestCase( SECTION,  "Function.prototype.toString()",
                                            "function Function() {}",
                                            Function.prototype.toString());
    myvar = Function();
 
    array[item++] = new TestCase( SECTION,  "myvar = Function();  myvar.toString()","function Function() {}",myvar.toString());

    return ( array );
}
