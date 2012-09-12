/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


    var SECTION = "instanceof";       // provide a document reference (ie, ECMA section)
    var VERSION = "ECMA_2"; // Version of JavaScript or ECMA
    startTest();               // leave this alone

    var TITLE   = "Regression test for Bugzilla #7635";       // Provide ECMA section title or a description
    var BUGNUMBER = "http://bugzilla.mozilla.org/show_bug.cgi?id=7635";     // Provide URL to bugsplat or bugzilla report

    writeHeaderToLog( SECTION + " "+ TITLE);
    
    var testcases = getTestCases();
 
    test();       // leave this alone.  this executes the test cases and
                  // displays results.
   
    /*
     * Calls to AddTestCase here. AddTestCase is a function that is defined
     * in shell.js and takes three arguments:
     * - a string representation of what is being tested
     * - the expected result
     * - the actual result
     *
     * For example, a test might look like this:
     *
     * var zip = /[\d]{5}$/;
     *
     * AddTestCase(
     * "zip = /[\d]{5}$/; \"PO Box 12345 Boston, MA 02134\".match(zip)",   // description of the test
     *  "02134",                                                           // expected result
     *  "PO Box 12345 Boston, MA 02134".match(zip) );                      // actual result
     *
     */


function getTestCases() {
function Foo() {}
    var array = new Array();
    var item = 0;
    
    var theproto = {};
    Foo.prototype = theproto
    //theproto instanceof Foo

    array[item++] = new TestCase( SECTION,
            "function Foo() {}; theproto = {}; Foo.prototype = theproto; theproto instanceof Foo",
            false,
            theproto instanceof Foo );
    
    var o  = {};

    //AddTestCase( "var o = {}; o instanceof o", false, o instanceof o );
    var thisError="no error";
    try{
        o instanceof o;
    }catch(e:Error){
       thisError = e.toString();
    }finally{
        array[item++] = new TestCase( SECTION,
            "o = {}; o instanceof o","TypeError: Error #1040",typeError(thisError));
    }

    var f = new Function();

    array[item++] = new TestCase( SECTION, "var f = new Function(); f instanceof f", false, f instanceof f );
    
    return (array);
}
