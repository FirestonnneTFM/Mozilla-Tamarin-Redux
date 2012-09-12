/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package extClass{
    public class subClass extends parentClass {
    }
}

import extClass.*;

var SECTION = " ";
var VERSION = "AS3";
var TITLE   = "import a class defined in .abc file";

startTest();

pc = new parentClass();
sc = new subClass();


AddTestCase( "parent class from imported abc file", true, pc.test());
AddTestCase( "sub class from imported abc file", true, sc.test());


test();


