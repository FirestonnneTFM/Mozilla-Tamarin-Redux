/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package Importinterfaceclass{

    public interface Publicinterface {
              function setPubArray(a:Array);
     }
}


package Packagclass{

import Importinterfaceclass.Publicinterface
public class PublicClass implements Publicinterface{
    var array:Array;
    public var pubArray:Array;

    public function setPubArray( a:Array ) { pubArray = a;}
}
}


var SECTION = "Directives";                     // provide a document reference (ie, ECMA section)
var VERSION = "ActionScript 3.0";               // Version of JavaScript or ECMA
var TITLE   = "Import an interface into a package that has a class and then import the class";          // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                                    // leave this alone



var arr = new Array(1, 2, 3);

import Packagclass.PublicClass

var obj = new PublicClass();

AddTestCase( "Import a public interface to a class and them import the class", arr, (obj.setPubArray(arr), obj.pubArray) );

/*===========================================================================*/


test();       // leave this alone.  this executes the test cases and
              // displays results.
