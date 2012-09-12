/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.9.5.3-1-n";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Date.prototype.valueOf";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    if (as3Enabled) {
        var OBJ = new MyObject( new Date(0) );
        array[item++] = new TestCase( SECTION,
                                        "var OBJ = new MyObject( new Date(0) ); OBJ.valueOf()",
                                        NaN,
                                        OBJ.valueOf());
    } else {
        thisError="no error thrown";
        try{
            var OBJ = new MyObject( new Date(0) );
            OBJ.valueOf();
           }
        catch(e){
                 thisError=e.toString();
                }
        finally{
        array[item++] = new TestCase( SECTION,
                                        "var OBJ = new MyObject( new Date(0) ); OBJ.valueOf()",
                                        "TypeError: Error #1034",
                                        typeError(thisError));
    
        }
    }
    return array;
}

function MyObject( value ) {
    this.value = value;
    this.valueOf = Date.prototype.valueOf;
//  The following line causes an infinte loop.
//  Might have been due to the new Function().
//  Changed this to function() { }
//    this.toString = function() { "return this+\"\";" };
    return this;
}
