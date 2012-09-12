/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Types: Conversions";
var VERSION = "as3";
var TITLE   = "implicit type conversions";

startTest();


// Value = "string"

var string:String = "string";
AddTestCase( "var string:String ='string'", "string", string );

var thisError = "no exception thrown";
try{
    var number:Number = "string";
} catch (e) {
//print( "hello?" );
    thisError = e.toString();
} finally {
    AddTestCase("number:Number = 'string'", "no exception thrown", typeError(thisError) );
    AddTestCase("number:Number = 'string'", NaN, number );
}

thisError = "no exception thrown";
try{
    var myInt:int = "string";
} catch(e1) {
    thisError = e1.toString();
} finally {
    AddTestCase("myInt:int = 'string'", "no exception thrown", typeError(thisError) );
        AddTestCase("myInt:int = 'string'", 0, myInt );
}


thisError = "no exception thrown";
try{
    var myUint:uint = "string";
} catch(e2) {
    thisError = e2.toString();
} finally {
    AddTestCase("myUInt:uint = 'string'", "no exception thrown", typeError(thisError) );
        AddTestCase("myUInt:uint = 'string'", 0, myUint );
}


thisError = "no exception thrown";
try{
    var boolean:Boolean = "string";
} catch(e3) {
    thisError = e3.toString();
} finally {
    AddTestCase("boolean:Boolean = 'string'", "no exception thrown", typeError(thisError) );
    AddTestCase("boolean:Boolean = 'string'", true, boolean );
}

var object:Object = "string";
AddTestCase( "var object:Object ='string'", "string", object);

// empty string conversions ---------------------------------------------------------------------
var emptyString:String = "";
AddTestCase( 'var string:String =""', "", emptyString );

thisError = "no exception thrown";
try{
    var number:Number = "";
} catch (e) {
    thisError = e.toString();
} finally {
    AddTestCase("number:Number = ''", "no exception thrown", typeError(thisError) );
    AddTestCase("number:Number = ''", 0, number );
}

thisError = "no exception thrown";
try{
    var myInt:int = "";
} catch(e1) {
    thisError = e1.toString();
} finally {
    AddTestCase("myInt:int = ''", "no exception thrown", typeError(thisError) );
        AddTestCase("myInt:int = ''", 0, myInt );
}


thisError = "no exception thrown";
try{
    var myUint:uint = "";
} catch(e2) {
    thisError = e2.toString();
} finally {
    AddTestCase("myUInt:uint = ''", "no exception thrown", typeError(thisError) );
        AddTestCase("myUInt:uint = ''", 0, myUint );
}


thisError = "no exception thrown";
try{
    var boolean:Boolean = "";
} catch(e3) {
    thisError = e3.toString();
} finally {
    AddTestCase("boolean:Boolean = ''", "no exception thrown", typeError(thisError) );

    //Note that the boolean result for empty string is opposite a non-empty string
    AddTestCase("boolean:Boolean = ''", false, boolean );
}

var object:Object = "";
AddTestCase( "var object:Object =''", "", object);


test();



