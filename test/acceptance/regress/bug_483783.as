/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Regression Tests";
var VERSION = "";
var TITLE = "Bug 483783: crash when creating large strings";

startTest();

var myString:String = "";
for(var j:Number = 0; j < 3000000; j++)
    myString += "a";

AddTestCase("Verify large string is created",
            3000000,
            myString.length
            );

test();