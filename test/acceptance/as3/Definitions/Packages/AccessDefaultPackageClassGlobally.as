/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package
{
    public class B
    {
        public function C()
        {
            return 3;
        }
    }
}

var SECTION = "Definitions\Packages";                   // provide a document reference (ie, ECMA section)
var VERSION = "ActionScript 3.0";           // Version of JavaScript or ECMA
var TITLE   = "access default package class globally";       // Provide ECMA section title or a description
var BUGNUMBER = "";

import A.*;

startTest();

var obj = new B();

AddTestCase("Using default package class globally", 3, obj.C());

test();
