/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
class Base
{
    public var x, y;
    public var intField:int;
}

class TestSuper extends Base
{
    public var intField2:int;
    public function testSuperPostInc()
    {
        AddTestCase("typeof super.x++", "number", typeof super.x++);
        AddTestCase("super.x", Number.NaN, super.x);
        AddTestCase("super.intField++", 0, super.intField++);
        AddTestCase("typeof super.intField", "number", typeof super.intField);
        AddTestCase("super.intField", 1, super.intField);
        AddTestCase("intField2++", 0, intField2++);
        AddTestCase("intField2", 1, intField2);
    }

    public function testSuperPostDec()
    {
        AddTestCase("typeof super.x--", "number", typeof super.x--);
        AddTestCase("super.x", Number.NaN, super.x);
        AddTestCase("super.intField--", 0, super.intField--);
        AddTestCase("typeof super.intField", "number", typeof super.intField);
        AddTestCase("super.intField", -1, super.intField);
        AddTestCase("intField2--", 0, intField2--);
        AddTestCase("intField2", -1, intField2);
    }
}

var SECTION = "Expressions";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS3";        // Version of ECMAScript or ActionScript
var TITLE   = "Postfix operators";       // Provide ECMA section title or a description

/*
  Note that this test is an extention to the following ecma3 tests:
  ecma3/Expressions/e11_3_1.as
  ecma3/Expressions/e11_3_2.as
*/

startTest();                // leave this alone

new TestSuper().testSuperPostInc();
new TestSuper().testSuperPostDec();

test();       // leave this alone.  this executes the test cases and
              // displays results.