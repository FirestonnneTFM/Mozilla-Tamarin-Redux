/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();                // leave this alone


var o:Object = new Object();
var a:uint = 0x1fffffff;

AddTestCase( "o.a = 0x1fffffff, o.b = -1, (o.a == o.b)", false, (o.a = a, o.b = -1, o.a == o.b) );


test();       // leave this alone.  this executes the test cases and
              // displays results.
