/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


startTest();                // leave this alone


import UintPublicClassMethodArg.*;

var obj = new UintPublicClass();

AddTestCase( "Calling function with 1 uint argument", 1 , obj.oneArg(1) );
AddTestCase( "Calling function with 2 uint arguments", 3 , obj.twoArg(1,2) );
AddTestCase( "Calling function with 3 uint arguments", 6 , obj.threeArg(1,2,3) );
AddTestCase( "diffArg(uint, int, Number)", 6 , obj.diffArg(1,2,3) );
AddTestCase( "diffArg(int, uint, Number)", 6 , obj.diffArg2(1,2,3) );
AddTestCase( "diffArg(Number, int, uint)", 6 , obj.diffArg3(1,2,3) );
AddTestCase( "useProp(4)", 14 , obj.useProp(4) );
AddTestCase( "obj.pubProp = 10", 10 , obj.pubProp = 10 );
AddTestCase( "UintPublicClass.pubStatProp = 11", 11 , UintPublicClass.pubStatProp = 11 );

// precision runtime errors

var pResult = null;
try{
    obj.oneArg(-1);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "Precision runtime error one arg", "exception NOT caught", pResult );

pResult = null;
try{
    obj.twoArg(1,-2);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "Precision runtime error two args", "exception NOT caught", pResult );

pResult = null;
try{
    obj.threeArg(1,-2);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "Precision runtime error three args", "exception caught", pResult );

pResult = null;
try{
    obj.diffArg(-1,-2,-3);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "Precision runtime error diffArg", "exception NOT caught", pResult );

pResult = null;
try{
    obj.diffArg2(-1,-2,-3);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "Precision runtime error diffArg2", "exception NOT caught", pResult );

pResult = null;
try{
    obj.diffArg3(-1,-2,-3);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "Precision runtime error diffArg3", "exception NOT caught", pResult );

var n:Number = -20;

pResult = null;
try{
    obj.oneArg(n);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "var n:Number = -20; obj.oneArg(n);", "exception NOT caught", pResult );

pResult = null;
try{
    obj.twoArg(n);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "var n:Number = -20; obj.twoArg(n);", "exception caught", pResult );

pResult = null;
try{
    obj.twoArg(n,n);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "var n:Number = -20; obj.twoArg(n,n);", "exception NOT caught", pResult );

pResult = null;
try{
    obj.threeArg(n,n,n);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "var n:Number = -20; obj.threeArg(n,n,n);", "exception NOT caught", pResult );

pResult = null;
try{
    obj.diffArg(n,n,n);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "var n:Number = -20; obj.diffArg(n,n,n)", "exception NOT caught", pResult );

pResult = null;
try{
    obj.diffArg2(n,n,n);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "var n:Number = -20; obj.diffArg2(n,n,n)", "exception NOT caught", pResult );

pResult = null;
try{
    obj.diffArg3(n,n,n);
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "var n:Number = -20; obj.diffArg3(n,n,n)", "exception NOT caught", pResult );


// uint properties of the class

pResult = null;
try{
    obj.pubProp = -1;
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "obj.pubProp = -1", "exception NOT caught", pResult );

pResult = null;

try{
    UintPublicClass.pubStatProp = -1;
    pResult = "exception NOT caught";
} catch (e) {
    pResult = "exception caught";
}
AddTestCase( "UintPublicClass.pubStatProp = -1", "exception NOT caught", pResult );


test();       // leave this alone.  this executes the test cases and
              // displays results.

