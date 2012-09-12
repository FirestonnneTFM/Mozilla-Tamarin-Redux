/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


startTest();                // leave this alone



function UintArgs(n1:uint , n2:uint):uint {
 
  
 return ((((n1 + n2) - 10) * 10) / 10);

}


AddTestCase( "Calling function with 1 uint argument", 20 , UintArgs(20,10) );


test();       // leave this alone.  this executes the test cases and
              // displays results.
