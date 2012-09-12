/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "as operator";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "test";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

///////////////////////////////////////////////////////////////
// add your tests here

try {
    var x = 13;
    var y:String = "";
    var z = (x as notAValidType);

} catch(e) {
    y = e;
} finally {
    AddTestCase( "as Type Error: (x as notAValidType)", "ReferenceError: Error #1065", referenceError(y) );
}

try {
    x = 13;
    var temp = "hello";
    y = "";
    z = (x as temp);

} catch(e:TypeError) {
    y = e;
} finally {
    AddTestCase( "as Type Error: temp='hello'; (x as temp)", "TypeError: Error #1009", typeError(y) );
}

try {
    x = 13;
    y = "";
    z = (x as undefined);

} catch(e:TypeError) {
    y = e;
} finally {
    AddTestCase( "as Type Error: (x as undefined)", "TypeError: Error #1010", typeError(y) );
}

try {
    x = 13;
    y = "";
    z = (x as 3333);

} catch(e:TypeError) {
    y = e;
} finally {
    AddTestCase( "as Type Error: (x as 3333)", "TypeError: Error #1009", typeError(y) );
}

try {
    x = 13;
    y = "";
    z = (x as "string");

} catch(e:TypeError) {
    y = e;
} finally {
    AddTestCase( "as Type Error: (x as 'string')", "TypeError: Error #1009", typeError(y) );
}


//
////////////////////////////////////////////////////////////////

test();       // leave this alone.  this executes the test cases and
              // displays results.

