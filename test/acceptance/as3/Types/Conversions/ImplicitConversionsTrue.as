/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Types: Conversions";
var VERSION = "as3";
var TITLE   = "implicit type conversions";

startTest();


// Value = true

var thisError = "no exception thrown";
try{
    var string:String = true;
} catch (e0) {
    thisError = e0.toString();
} finally {
    AddTestCase("string:String = true", "no exception thrown", typeError(thisError) );
    AddTestCase("string:String = true", "true", string);
}

thisError = "no exception thrown";
try{
    var number:Number = true;
} catch (e) {
    thisError = e.toString();
} finally {
    AddTestCase("number:Number = true", "no exception thrown", typeError(thisError) );
    AddTestCase("number:Number = true", 1, number);
}

thisError = "no exception thrown";
try{
    var myInt:int = true;
} catch(e1) {
    thisError = e1.toString();
} finally {
    AddTestCase("myInt:int = true", "no exception thrown", typeError(thisError) );
    AddTestCase("myInt:int = true", 1, myInt);
}

thisError = "no exception thrown";
try{
    var myUint:uint = true;
} catch(e2) {
    thisError = e2.toString();
} finally {
    AddTestCase("myUInt:uint = true", "no exception thrown", typeError(thisError) );
    AddTestCase("myUInt:uint = true", 1, myUint);
}

thisError = "no exception thrown";
try{
    var boolean:Boolean = true;
} catch(e3) {
    thisError = e3.toString();
} finally {
    AddTestCase("boolean:Boolean = true", "no exception thrown", typeError(thisError) );
}

var object:Object = true;
AddTestCase( "var object:Object = true", true, object);


test();



