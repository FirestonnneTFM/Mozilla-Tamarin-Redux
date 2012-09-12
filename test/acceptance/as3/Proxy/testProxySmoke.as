/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Proxy";
var VERSION = "AS3";
var TITLE   = "Proxy smoke tests ported from ATS: ATS9AS3 Automated/Proxy/testProxySmoke";

startTest();

// instantiate a new object
var myObject:* = new Object();

// wrap that object in a proxy
var myObjectProxy:ProxySmoke = new ProxySmoke(myObject);

myObjectProxy.property1 = Math.PI;
myObject.property2 = "Hello, world!";

AddTestCase("set and get property1 on Proxy", Math.PI, myObjectProxy.property1);
AddTestCase("set and get property2 on Proxy", "Hello, world!",
            myObjectProxy.property2);
AddTestCase("set and get property1 on original Object", Math.PI,
            myObject.property1);
AddTestCase("set and get property2 on original Object", "Hello, world!",
            myObject.property2);
AddTestCase("compare original Object's property1 with Proxy Object's property1",
            myObjectProxy.property1, myObject.property1);
AddTestCase("compare original Object's property2 with Proxy Object's property2",
            myObject.property2, myObjectProxy.property2);

delete myObjectProxy.property1;
delete myObject.property2;

AddTestCase("delete property1 from original Object and check for property in original Object",
            undefined, myObject.property1);
AddTestCase("delete property1 from original Object and check for property in Proxy Object",
            undefined, myObjectProxy.property1);
AddTestCase("delete property2 from Proxy Object and check for property in original Object",
            undefined, myObject.property2);
AddTestCase("delete property2 from Proxy Object and check for property in Proxy Object",
            undefined, myObjectProxy.property2);

myObject.echoString = function(myArg:String):String
{
    return myArg;
}

myObject.multiplyNumbers = function(myNum1:Number, myNum2:Number):Number
{
    return (myNum1 * myNum2);
}

myObject.sayHello = function():String
{
    return "Hello, World!";
}

AddTestCase("test that a call to a function with 1 argument can be redirected properly",
            "echo String worked!", myObjectProxy.echoString("echo String worked!"));
AddTestCase("test that a call to a function with 2 arguments can be redirected properly",
            50, myObjectProxy.multiplyNumbers(5, 10));
AddTestCase("test that if a function has more than 2 arguments, just call the default function myFunction",
            "Method redirectFunction was called", myObjectProxy.redirectFunction(5, 10, false));
AddTestCase("test that a call to a function with 0 arguments can be redirected properly",
            "Hello, World!", myObjectProxy.sayHello());

myObject.testHasProperty1 = "weasel";
myObjectProxy.testHasProperty2 = "coffee";

AddTestCase("test hasProperty with existing property on original Object set on original Object",
            true, ("testHasProperty1" in myObject));
AddTestCase("test hasProperty with existing property on Proxy Object set on original Object",
            true, ("testHasProperty1" in myObjectProxy));
AddTestCase("test hasProperty with existing property on original Object set on Proxy Object",
            true, ("testHasProperty2" in myObject));
AddTestCase("test hasProperty with existing property on Proxy Object set on Proxy Object",
            true, ("testHasProperty2" in myObjectProxy));
AddTestCase("test hasProperty with non-existing property on original Object",
            false, ("noExistHasProperty1" in myObject));
AddTestCase("test hasProperty with non-existing property on Proxy Object",
            false, ("noExistHasProperty1" in myObjectProxy));

// instantiate a new object
var myIntTestObject:* = new Object();

// wrap that object in a proxy
var myIntTestProxy:ProxySmoke = new ProxySmoke(myIntTestObject);

myIntTestProxy["10"] = "TEN";

AddTestCase("set myProxy['10'] and get myProxy[10]", "TEN", myIntTestProxy[10]);
AddTestCase("set myProxy['10'] and get myObject[10]", "TEN", myIntTestObject[10]);
AddTestCase("set myProxy['10'] and get myProxy['10']", "TEN", myIntTestProxy["10"]);
AddTestCase("set myProxy['10'] and get myObject['10']", "TEN", myIntTestObject["10"]);

myIntTestProxy[5] = "FIVE";

AddTestCase("set myProxy[5] and get myProxy[5]", "FIVE", myIntTestProxy[5]);
AddTestCase("set myProxy[5] and get myObject[5]", "FIVE", myIntTestObject[5]);
AddTestCase("set myProxy[5] and get myProxy['5']", "FIVE", myIntTestProxy["5"]);
AddTestCase("set myProxy[5] and get myObject['5']", "FIVE",  myIntTestObject["5"]);

myIntTestObject["20"] = "TWENTY";

AddTestCase("set myObject['20'] and get myProxy[20]", "TWENTY", myIntTestProxy[20]);
AddTestCase("set myObject['20'] and get myObject[20]", "TWENTY", myIntTestObject[20]);
AddTestCase("set myObject['20'] and get myProxy['20']", "TWENTY", myIntTestProxy["20"]);
AddTestCase("set myObject['20'] and get myObject['20']", "TWENTY", myIntTestObject["20"]);

myIntTestObject[13] = "THIRTEEN";

AddTestCase("set myObject[13] and get myProxy[13]", "THIRTEEN", myIntTestProxy[13]);
AddTestCase("set myObject[13] and get myObject[13]", "THIRTEEN", myIntTestObject[13]);
AddTestCase("set myObject[13] and get myProxy['13']", "THIRTEEN", myIntTestProxy["13"]);
AddTestCase("set myObject[13] and get myObject['13']", "THIRTEEN", myIntTestObject["13"]);

delete myIntTestProxy["13"];

AddTestCase("set myObject[13] and delete myProxy['13'] and get myProxy[13]",
            undefined, myIntTestProxy[13]);
AddTestCase("set myObject[13] and delete myProxy['13'] and get myObject[13]",
            undefined, myIntTestObject[13]);
AddTestCase("set myObject[13] and delete myProxy['13'] and get myProxy['13']",
            undefined, myIntTestProxy["13"]);
AddTestCase("set myObject[13] and delete myProxy['13'] and get myObject['13']",
            undefined, myIntTestObject["13"]);

delete myIntTestObject[10];

AddTestCase("set myProxy['10'] and delete myProxy[10] and get myProxy[10]",
            undefined, myIntTestProxy[10]);
AddTestCase("set myProxy['10'] and delete myProxy[10] and get myObject[10]",
            undefined, myIntTestObject[10]);
AddTestCase("set myProxy['10'] and delete myProxy[10] and get myProxy['10']",
            undefined, myIntTestProxy["10"]);
AddTestCase("set myProxy['10'] and delete myProxy[10] and get myObject['10']",
            undefined, myIntTestObject["10"]);

test();