/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


var SECTION = "Directives\const";                       // provide a document reference (ie, ECMA section)
var VERSION = "ActionScript 3.0";                   // Version of JavaScript or ECMA
var TITLE   = "'const' outside a class access from inside the class";   // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


/*===========================================================================*/


const myConst = 50;

class ConstClass {
    
    var myConstAdd = 20 + myConst;
}

var Obj = new ConstClass();
myObjConst = Obj.myConstAdd;

AddTestCase( "Testing the 'const' keywords access from an object of a class: var myConstAdd = 20 + myConst;", 70, myObjConst );


test();             // Leave this function alone.
            // This function is for executing the test case and then
            // displaying the result on to the console or the LOG file.
