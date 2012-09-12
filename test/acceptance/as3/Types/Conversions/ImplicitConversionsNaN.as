/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Types: Conversions";
var VERSION = "as3";
var TITLE   = "implicit type conversions";

startTest();


// Value = NaN

/*var thisError = "no exception thrown";
try{
    var string:String = NaN;
} catch (e0) {
    thisError = e0.toString();
} finally {
    AddTestCase( "var string:String = NaN", "no exception thrown", typeError(thisError));
    AddTestCase( "var string:String = NaN", "NaN", string);
}*/

var string:String = NaN;
AddTestCase( "var string:String = NaN", "NaN", string);

var number:Number = NaN;
AddTestCase("number:Number = NaN", NaN, number );

/*thisError = "no exception thrown";
try{
    var myInt:int = NaN;
} catch(e1) {
    thisError = e1.toString();
} finally {
    AddTestCase("myInt:int = NaN", "RangeError: Error #1061", rangeError(thisError) );
    AddTestCase("myInt:int = NaN", 0, myInt );
}*/

var myInt:int = NaN;
AddTestCase("myInt:int = NaN", 0, myInt );


/*thisError = "no exception thrown";
try{
    var myUint:uint = NaN;
} catch(e2) {
    thisError = e2.toString();
} finally {
    AddTestCase("myUInt:uint = NaN", "RangeError: Error #1061", rangeError(thisError) );
    AddTestCase("myUInt:uint = NaN", 0, myUint );
}*/

var myUint:uint = NaN;
AddTestCase("myUInt:uint = NaN", 0, myUint );


/*thisError = "no exception thrown";
try{
    var boolean:Boolean = NaN;
} catch(e3) {
    thisError = e3.toString();
} finally {
    AddTestCase("boolean:Boolean = NaN", "no exception thrown", typeError(thisError) );
    AddTestCase("boolean:Boolean = NaN", false, boolean );
}*/

var boolean:Boolean = NaN;
AddTestCase("boolean:Boolean = NaN", false, boolean );

var object:Object = NaN;
AddTestCase( "var object:Object = NaN", NaN, object);


test();



