/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Types: Conversions";
var VERSION = "as3";
var TITLE   = "implicit type conversions";

startTest();


// Value = false

var thisError = "no exception thrown";
try{
    var string:String = false;
} catch (e0) {
    thisError = e0.toString();
} finally {
    AddTestCase("string:String = false", "no exception thrown", typeError(thisError) );
    AddTestCase("string:String = false", "false", string);
}

thisError = "no exception thrown";
try{
    var number:Number = false;
} catch (e) {
    thisError = e.toString();
} finally {
    AddTestCase("number:Number = false", "no exception thrown", typeError(thisError) );
    AddTestCase("number:Number = false", 0, number );
}

thisError = "no exception thrown";
try{
    var myInt:int = false;
} catch(e1) {
    thisError = e1.toString();
} finally {
    AddTestCase("myInt:int = false", "no exception thrown", typeError(thisError) );
    AddTestCase("myInt:int = false", 0, myInt );
}

thisError = "no exception thrown";
try{
    var myUint:uint = false;
} catch(e2) {
    thisError = e2.toString();
} finally {
    AddTestCase("myUInt:uint = false", "no exception thrown", typeError(thisError) );
    AddTestCase("myUInt:uint = false", 0, myUint );
}

thisError = "no exception thrown";
try{
    var boolean:Boolean = false;
} catch(e3) {
    thisError = e3.toString();
} finally {
    AddTestCase("boolean:Boolean = false", "no exception thrown", typeError(thisError) );
}

var object:Object = false;
AddTestCase( "var object:Object = false", false, object);


test();



