/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
import flash.utils.Dictionary;

var SECTION = "Expressions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "Logical Assignment";       // Provide ECMA section title or a description


startTest();                // leave this alone



var counter : uint = 0;
dynamic class C extends Dictionary
{
    function C(p : uint)
    {
        counter += p;
    }
}

// This tests that the constructor for C(1) is called twice, as it's
// a shortcut for (new C(1))[0] = (new C(1))[0] || new C(3);
var v0:C = (new C(1))[0] ||= new C(3);
AddTestCase('(new C(1))[0] ||= new C(3)', 5, counter);

// This tests that the constructor for C(1) is called twice, as it's
// a shortcut for (new C(1))[0] = (new C(1))[0] && new C(3);
var v1:C = (new C(1))[0] &&= new C(3);
AddTestCase('(new C(1))[0] &&= new C(3)', 7, counter);

var v:C;
(v ||= new C(1))[0] ||= new C(3);
AddTestCase('v ||= new C(1))[0] ||= new C(3)', 11, counter);

(v &&= new C(1))[0] &&= new C(3);
AddTestCase('v &&= new C(1))[0] &&= new C(3)', 13, counter);

test();       // leave this alone.  this executes the test cases and
              // displays results.