/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package foo {
    public class fletch{
        public function lives(){return 'PASSED';}
    }
}
import foo.*

var SECTION = "Definitions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "PackageDefinition" //Proved ECMA section titile or a description
var BUGNUMBER = "";

startTest();                // leave this alone


var FLETCHCLASS = new fletch();
AddTestCase( "class inside of package", "PASSED",FLETCHCLASS.lives() );

test();       // leave this alone.  this executes the test cases and
              // displays results.
