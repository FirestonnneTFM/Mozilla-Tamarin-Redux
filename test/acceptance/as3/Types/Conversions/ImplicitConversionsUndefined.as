/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Types: Conversions";
var VERSION = "as3";
var TITLE   = "implicit type conversions";

startTest();


// Value = undefined

var thisError = "no exception thrown";
try{
    var string:String = undefined;
} catch (e0) {
    thisError = e0.toString();
} finally {
    AddTestCase( "var string:String =null", "no exception thrown", typeError(thisError));
        AddTestCase( "var string:String =null", null,string);
}

thisError = "no exception thrown";
try{
    var mynumber:Number = undefined;
} catch (e) {
    thisError = e.toString();
} finally {
    AddTestCase("number:Number = undefined", "no exception thrown", typeError(thisError) );
        AddTestCase("number:Number = undefined", NaN, mynumber );
}

thisError = "no exception thrown";
try{
    var myInt:int = undefined;
} catch(e1) {
    thisError = e1.toString();
} finally {
    AddTestCase("myInt:int = undefined", "no exception thrown", typeError(thisError) );
        AddTestCase("myInt:int = undefined", 0, myInt );
}

thisError = "no exception thrown";
try{
    var myUint:uint = undefined;
} catch(e2) {
    thisError = e2.toString();
} finally {
        AddTestCase("myUInt:uint = undefined", "no exception thrown", typeError(thisError));

    AddTestCase("myUInt:uint = undefined", 0, myUint);
}

thisError = "no exception thrown";
try{
    var myboolean:Boolean = undefined;
} catch(e3) {
    thisError = e3.toString();
} finally {
    AddTestCase("myboolean:Boolean = undefined", "no exception thrown", typeError(thisError) );
        AddTestCase("myboolean:Boolean = undefined", false, myboolean);
}

var object:Object = undefined;
AddTestCase( "var object:Object = null", null, object);


test();



