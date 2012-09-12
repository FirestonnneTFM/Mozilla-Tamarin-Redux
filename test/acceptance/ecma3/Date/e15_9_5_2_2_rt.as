/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.9.5.2-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Date.prototype.toString";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();
    
function getTestCases() {
    var array = new Array();
    var item = 0;

    var OBJ = new MyObject( new Date(0) );
    
    if (as3Enabled) {
        array[item++] = new TestCase(SECTION,
                                    "var OBJ = new MyObject( new Date(0) ); OBJ.toString()",
                                    "Invalid Date",
                                    OBJ.toString());
    } else {
        thisError="no Error thrown";
        try{
            OBJ.toString();
           }
        catch(e){
                 thisError=e.toString();
                }
        finally{
    
        /*array[item++] = new TestCase( SECTION,
                                        "var OBJ = new MyObject( new Date(0) ); OBJ.toString()",
                                        "error",
                                        OBJ.toString() );*/
         array[item++] = new TestCase( SECTION,
                                        "var OBJ = new MyObject( new Date(0) ); OBJ.toString()",
                                        "TypeError: Error #1034",
                                        typeError(thisError) );
        }
    }
           
    return array;
}
function MyObject( value ) {
    this.value = value;
    this.valueOf = function() { return this.value };
    this.toString = Date.prototype.toString;
    return this;
}
