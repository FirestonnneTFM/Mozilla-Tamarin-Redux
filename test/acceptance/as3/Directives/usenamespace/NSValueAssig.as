/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */



var SECTION = "Directives";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "Namespace values";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone





class A{
namespace N1="www.ecma-international.org"
//namespace N2 = N1
namespace N3="flowershop.com";

var a=0;
N3 var flower1:String = "Gerbera Daisy";
namespace N4 = "flowershop.com";
N4 var flower2:String = "Rose";


function a1(){
        if(a!=1) { return N1.toString()}
    else {return null}
}
function a2(){
        return N3::flower1
}
function a3(){
        return N4::flower2
}

}

var obj:A = new A();
AddTestCase("Namespacevalue", "www.ecma-international.org", obj.a1());
AddTestCase("Getting variable", "Gerbera Daisy", obj.a2());
AddTestCase("Getting variable", "Rose", obj.a3());

test();
