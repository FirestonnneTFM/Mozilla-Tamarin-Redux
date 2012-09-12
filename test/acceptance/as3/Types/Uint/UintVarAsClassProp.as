/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import UintVarAsClassProp.*;

startTest();                // leave this alone


var obj = new testuint();

AddTestCase( "Uint public property", 1, obj.num1 );


test();       // leave this alone.  this executes the test cases and
              // displays results.
