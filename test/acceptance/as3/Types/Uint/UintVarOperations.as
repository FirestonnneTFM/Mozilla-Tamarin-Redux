/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

startTest();                // leave this alone


var num1:uint;
var num2:uint;
var num3:uint;
var num4:Number;
var num5:Number;

num1 = 20;
num2 = 5;
num4 = 10;
num5 = -100;

AddTestCase( "Uint addition", 25, (num3 = (num1 + num2)) );
AddTestCase( "Uint subtraction", 15, (num3 = (num1 - num2)) );
AddTestCase( "Uint multiplication", 100, (num3 = (num1 * num2)) );
AddTestCase( "Uint division", 4, (num3 = (num1 / num2)) );

AddTestCase( "Adding uint and Number variables", 30, (num3 = (num1 + num4)) );
AddTestCase( "Subtracting Number variable from uint variable", 10, (num3 = (num1 - num4)) );
AddTestCase( "Multiplying uint and Number variable", 200, (num3 = (num1 * num4)) );
AddTestCase( "Diving uint by a Number variable", 2, (num3 = (num1 / num4)) );

AddTestCase( "Adding uint and Number variables", 21, (num3 = (num1 + 1)) );
AddTestCase( "Subtracting Number variable from uint variable", 0, (num3 = (num1 - 20)) );
AddTestCase( "Multiplying uint and Number variable", 140, (num3 = (num1 * 7)) );
AddTestCase( "Diving uint by a Number variable", 2, (num3 = (num1 / 10)) );

// RangeError precision test cases
var pResult = null;
try{
    var temp:uint;
    temp = num1 + num5;
    pResult = "exception NOT caught";
} catch(e) {
    pResult = "exception caught";
}
AddTestCase( "var temp:uint; num1(+20) + num5(-100)", "exception NOT caught", pResult );

pResult = null;

try{
    var temp:uint;
    temp = -100;
    pResult = "exception NOT caught";
} catch(e) {
    pResult = "exception caught";
}
AddTestCase( "var temp:uint; temp = -100", "exception NOT caught", pResult );

//divide
pResult = null;
try{
    var temp:uint;
    temp = -100/2;
    pResult = "exception NOT caught";
} catch(e) {
    pResult = "exception caught";
}
AddTestCase( "var temp:uint; temp = -100/2", "exception NOT caught", pResult );

// multiply
pResult = null;
try{
    var temp:uint;
    temp = -100*2;
    pResult = "exception NOT caught";
} catch(e) {
    pResult = "exception caught";
}
AddTestCase( "var temp:uint; temp = -100*2", "exception NOT caught", pResult );

// subtract
pResult = null;
try{
    var temp:uint;
    temp = 1-100;
    pResult = "exception NOT caught";
} catch(e) {
    pResult = "exception caught";
}
AddTestCase( "var temp:uint; temp = 1-100", "exception NOT caught", pResult );


test();       // leave this alone.  this executes the test cases and
              // displays results.
