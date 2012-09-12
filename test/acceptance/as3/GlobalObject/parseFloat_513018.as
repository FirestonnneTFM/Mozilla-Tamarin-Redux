/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import avmplus.System;

var SECTION = "GlobalObject";
var VERSION = "as3";
startTest();
var TITLE   = "bug 513018";

writeHeaderToLog( SECTION + " "+ TITLE );

if (System.swfVersion < 11) {
    AddTestCase('SWF9: 12..34..56',
        parseFloat("12..34..56"),
        1234.56);
} else {
    AddTestCase('SWF11+: 12..34..56',
        parseFloat("12..34..56"),
        12);
}

test();
