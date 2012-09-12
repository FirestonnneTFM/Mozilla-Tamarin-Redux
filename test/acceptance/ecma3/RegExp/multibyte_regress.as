/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "regex";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "multi-byte regression tests";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


///////////////////////////////////////////////////////////////
// add your tests here
  

// Check that .index works for multibyte chars - regression for 186337
var indexErrors:String = '';
for (var y = 100; y < 0xffff; y+=1)
{
  if (y < 0xAC00 || y > 0xF300) // these are invalid unicode chars
  { // (Actually, there are a few valid chars in this range, but very few and this is simple test).
    var q = String.fromCharCode(y);
    var r = (/bA/g).exec(q + "Ab" + q + "bA");
    if (!r || r.index != 4)
      indexErrors += y.toString(16) + ', ';
  }
}

AddTestCase( ".index regex property broken multibyte chars:", "", indexErrors);

//
////////////////////////////////////////////////////////////////

test();       // leave this alone.  this executes the test cases and
              // displays results.
