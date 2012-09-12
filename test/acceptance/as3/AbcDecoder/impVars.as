/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import packOne.*;
import packTwo.*;

var SECTION = " ";
var VERSION = "AS3";
var TITLE   = "import variable from a .abc file [defined in varsDef.as]";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);

AddTestCase( "importing 'var1' of packOne", "packOne:var1", var1);
AddTestCase( "importing 'var2' of packOne", "packOne:var2", var2);
AddTestCase( "importing 'var3' of packOne", "packOne:var3", var3);
AddTestCase( "importing 'var4' of packOne", "packOne:var4", var4);

/* Importing variables from the pacakge defined in the second pacakge */
AddTestCase( "importing 'p2var1' of packTwo", "packTwo:var1", p2var1);
AddTestCase( "importing 'p2var2' of packTwo", "packTwo:var2", p2var2);
AddTestCase( "importing 'p2var3' of packTwo", "packTwo:var3", p2var3);
AddTestCase( "importing 'p2var4' of packTwo", "packTwo:var4", p2var4);

test();
