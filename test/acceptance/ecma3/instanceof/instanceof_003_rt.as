/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "instanceof-003";
    var VERSION = "ECMA_2";
    startTest();
        
    var TITLE   = "instanceof operator";
    var BUGNUMBER ="http://bugzilla.mozilla.org/show_bug.cgi?id=7635";

    writeHeaderToLog( SECTION + " "+ TITLE);
    
    var testcases = getTestCases();
    test();
    
function Foo() {};
function getTestCases() {
    var array = new Array();
    var item = 0;
    
    var theproto = {};
    Foo.prototype = theproto;

    array[item++] = new TestCase(SECTION,
        "function Foo() = {}; theproto = {}; Foo.prototype = theproto; " +
            "theproto instanceof Foo",
        false,
        theproto instanceof Foo );


    var o = {};

   /* AddTestCase(
        "o = {}; o instanceof o",
        false,
        o instanceof o );*/
    var thisError="no error";
    try{
        o instanceof o;
    }catch(e:Error){
       thisError = e.toString();
    }finally{
        array[item++] = new TestCase( SECTION, "o = {}; o instanceof o","TypeError: Error #1040",typeError(thisError));
    }
    
    return (array);
}
