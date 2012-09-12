/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Types: Conversions";
var VERSION = "as3";
var TITLE   = "implicit type conversions";

startTest();


// Value = null

var string:String = null;
AddTestCase( "var string:String =null", null, string );

var thisError = "no exception thrown";
try{
    var mynumber:Number = null;
} catch (e) {
    thisError = e.toString();
} finally {
    AddTestCase("number:Number = null", "no exception thrown", typeError(thisError) );
        AddTestCase("number:Number = null", 0, mynumber);
}

thisError = "no exception thrown";
try{
    var myInt:int = null;
} catch(e1) {
    thisError = e1.toString();
} finally {
    AddTestCase("myInt:int = null", "no exception thrown", typeError(thisError) );
        AddTestCase("myInt:int = null", 0, myInt );
}

thisError = "no exception thrown";
try{
    var myUint:uint = null;
} catch(e2) {
    thisError = e2.toString();
} finally {
    AddTestCase("myUInt:uint = null", "no exception thrown", typeError(thisError) );
        AddTestCase("myUInt:uint = null", 0, myUint );
}

thisError = "no exception thrown";
try{
    var myboolean:Boolean = null;
} catch(e3) {
    thisError = e3.toString();
} finally {
    AddTestCase("boolean:Boolean = null", "no exception thrown", typeError(thisError) );
        AddTestCase("boolean:Boolean = null", false, myboolean);
}

var object:Object = null;
AddTestCase( "var object:Object = null", null, object);


test();



