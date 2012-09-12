/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
package{

 
var SECTION = "Directives";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "Namespace functions inside a class";       // Provide ECMA section title or a description


startTest();                // leave this alone




 
     public namespace Football
     public namespace Baseball

     class Game{

          Football function whoplay(){return "Joe"}
          Baseball function whoplay(){return "Steve"}
     }



var game = new Game();

AddTestCase( "Who is going to play = 'Joe'", "Joe", game.Football::whoplay());

AddTestCase( "Who is going to play = 'Steve'", "Steve", game.Baseball::whoplay());

}

test();       // leave this alone.  this executes the test cases and
              // displays results.
