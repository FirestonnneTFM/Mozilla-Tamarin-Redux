/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package {

var SECTION = "Directives";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "Qualified expression reference";       // Provide ECMA section title or a description

startTest();                // leave this alone

public namespace Football
public namespace Baseball

public class Game {
    Football var n =  "Joe"
    Baseball var n =  "Steve"
}


var g = new Game();

AddTestCase( "Football::['n']", "Joe", g.Football::['n']);

AddTestCase( "Baseball::['n']", "Steve", g.Baseball::['n']);

}

test();       // leave this alone.  this executes the test cases and
              // displays results.
