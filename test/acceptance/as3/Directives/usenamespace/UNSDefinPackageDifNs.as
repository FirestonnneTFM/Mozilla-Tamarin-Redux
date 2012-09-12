/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


package P {
 
     public namespace Football
     public namespace Baseball

     public class Game{
          
      use namespace Football;
          Football function whoplay(){return "Joe"}
          use namespace Baseball;
          Baseball function whoplay(){return "Steve"}
     }
 }

 
var SECTION = "Directives";       // provide a document reference (ie, Actionscript section)
var VERSION = "AS 3.0";        // Version of ECMAScript or ActionScript
var TITLE   = "use namespace";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone





import P.*;

var game = new Game();

AddTestCase( "Who is going to play = 'Joe'", "Joe", game.Football::whoplay());
AddTestCase( "Who is going to play = 'Steve'", "Steve", game.Baseball::whoplay());



test();       // leave this alone.  this executes the test cases and
              // displays results.
