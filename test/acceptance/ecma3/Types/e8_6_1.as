/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "8.6.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Property attributes of Object type";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var OBJ_PROT = Object.prototype;

    try{
        Object.prototype=null
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++]=new TestCase(SECTION,"Verifying the read only property of Object.prototype","ReferenceError: Error #1074",referenceError(thisError));
    }
    array[item++] = new TestCase(   SECTION,
                                    "var OBJ_PROT = Object.prototype; Object.prototype = null; Object.prototype == OBJ_PROT",
                                    true,
                                    (OBJ_PROT = Object.prototype, Object.prototype == OBJ_PROT ) );
    

    try{
        Object.prototype=0
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++]=new TestCase(SECTION,"Verifying the read only property of Object.prototype","ReferenceError: Error #1074",referenceError(thisError));
    }
    array[item++] = new TestCase(   SECTION,
                                    "Object.prototype=0; Object.prototype",
                                    Object.prototype,
                                    Object.prototype );

    var OBJ_PROT1 = Object.prototype;
    delete( Object.prototype );
    array[item++] = new TestCase(SECTION, "var OBJ_PROT1 = Object.prototype; delete( Object.prototype ); OBJ_PROT1 == Object.prototype",    true, OBJ_PROT1 == Object.prototype);
    array[item++] = new TestCase(SECTION, "delete( Object.prototype )",          false,       delete( Object.prototype ) );

    var string = '';
    for ( prop in Object ) {
        string += ( prop == 'prototype' ) ? prop : '';
    }

    array[item++] = new TestCase(SECTION,"var string = ''; for ( prop in Object ) { string += ( prop == 'prototype' ) ? prop: '' } string;","",string);

    

    return ( array );
}


function MyObject( value ) {
    this.value = value;

    // the new Function() changes to function() {}.
    this.valueOf = function() { return this.value; }
    this.toString = function() { return this.value+''; }
    this.valueOf = function() { return this.value; }
    this.toString = function() { return this.value +'';}
}
