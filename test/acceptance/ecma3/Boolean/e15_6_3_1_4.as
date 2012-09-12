/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.6.3.1-4";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Boolean.prototype"
    writeHeaderToLog( SECTION + TITLE );

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var BOOL_PROTO = Boolean.prototype;

    array[item++] = new TestCase( SECTION,
                                 "var BOOL_PROTO = Boolean.prototype; Boolean.prototype; Boolean.prototype == BOOL_PROTO",
                                 true,
                                 (BOOL_PROTO = Boolean.prototype, Boolean.prototype, Boolean.prototype == BOOL_PROTO ) );

    var thisError="no error";

    try{
        // save
        var origBoolProto = Boolean.prototype;

        Boolean.prototype=null;

        // restore
        Boolean.prototype = origBoolProto;
    }catch(e:ReferenceError){
        thisError=e.toString();
    }finally{
        array[item++]=new TestCase(SECTION,"Trying to verify that Boolean.prototype is read-only","ReferenceError: Error #1074",referenceError(thisError));
    }

    return ( array );
}
