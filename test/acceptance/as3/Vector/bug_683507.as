/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import avmplus.*;

var SECTION = "Vector";
var VERSION = "AS3";
startTest();
writeHeaderToLog( SECTION + " bug 683507");

expected = "TypeError: Error #1128";
err = "exception not thrown";
try {
    var vError:Vector.<Number, int> = new Vector.<Number, int>;
 }
catch (e:Error){
    err = e.toString();
}
AddTestCase("TypeError: Error #1128: Incorrect number of type parameters",
               expected,
               parseError(err, expected.length));


test();
