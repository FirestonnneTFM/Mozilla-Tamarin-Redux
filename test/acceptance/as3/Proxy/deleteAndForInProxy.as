/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2011
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

var SECTION = "Proxy";
var VERSION = "AS3";
var TITLE   = "Proxy test ported from ATS: ATS9AS3 Automated/Proxy/deleteAndForInProxy";

startTest();

// instantiate a new object
var myObject:* = new Object();

// wrap that object in a proxy
var myObjectProxy:ProxySmoke = new ProxySmoke(myObject);
var proxyOfProxy:ProxySmoke = new ProxySmoke(myObjectProxy);

myObjectProxy.property1 = Math.PI;
myObject.property2 = "Hello, world!";

AddTestCase("delete property on Object", true, delete myObject.property1);
AddTestCase("delete property on Proxy Object", true,
            delete myObjectProxy.property2);
AddTestCase("delete Nonexistent property on Object", true,
            delete myObject.nonExistent00);
AddTestCase("delete Nonexistent property on Proxy Object", true,
            delete myObjectProxy.nonExistent00);
AddTestCase("delete function on Object", true,
            delete myObject.delEchoFunction0);
AddTestCase("delete function on Proxy Object", true,
            delete myObjectProxy.delEchoFunction1);

myObject.delEchoFunction0 = function(myArg:String):String
{
	return myArg;
}
myObject.delEchoFunction1 = function(myArg:String):String
{
	return myArg;
}
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
function compareArray(a0:Array, a1:Array):int{
	var num = 0;
	trace("-------");
	for(var i in a1){
		trace(a0[i] + " / " + a1[i]);
		if(a0[i] != a1[i]){
			num++;
		}
	}
	return num;
}

myObject.testHasProperty1 = "weasel";
myObjectProxy.testHasProperty2 = "coffee";

// test inumerating over proxied object
function checkProxy(proxy:*, ansArray0:Array, ansArray1:Array):Boolean
{
	var pArray0 = new Array();
	var pArray1 = new Array();
	for(var i in proxy){
		pArray0.push(i);
		pArray1.push(proxy[i]);
	}
	pArray0.sort();
	pArray1.sort();
	trace("pArray0: " + pArray0.toString());
	trace("pArray1: " + pArray1.toString());
	var num0 = compareArray(pArray0, ansArray0);
	var num1 = compareArray(pArray0, ansArray0);
	if(num0 != 0 || num1 != 0){
		return false;
	}else{
		return true;
	}
}


var ansArray0 = new Array("delEchoFunction0","delEchoFunction1","echoString",
                          "multiplyNumbers","sayHello","testHasProperty1",
                          "testHasProperty2");
var ansArray1 = new Array("coffee","function Function() {}",
                          "function Function() {}","function Function() {}",
                          "function Function() {}","function Function() {}",
                          "weasel");

var obj = {firstName:"Tara", age:27, city:"San Francisco"};
var feProxy:ProxySmoke = new ProxySmoke(obj);
var feArray0 = new Array();
var ansFeArray0 = ["27", "San Francisco", "Tara"];
for each (var item in feProxy) { 
	feArray0.push(item);
    //trace("item: " + item); 
} 
feArray0.sort();

AddTestCase("for in loop over Proxy Object variables", true,
            checkProxy(proxyOfProxy, ansArray0, ansArray1));
AddTestCase("for in loop over Proxy Object values", "spacer", "spacer");
AddTestCase("for each in loop over Proxy Object", 0,
            compareArray(feArray0, ansFeArray0));

AddTestCase("delete proxy of proxy Object", false, delete proxyOfProxy);
AddTestCase("delete proxy Object", false, delete feProxy);
AddTestCase("delete original Object", false, delete obj);

//proxy before and after then delete
var ansProxyArray0 = ["foo","num","str"];
var ansProxyArray1 = ["9999","nuts","yo mama"];
var obj1 = new Object();
obj1.str = "nuts";
var obj1Proxy0 = new ProxySmoke(obj1);
obj1Proxy0.num = 9999;
var obj1Proxy1 = new ProxySmoke(obj1);
obj1Proxy1.foo = "bar";
var obj1ProxyProxy1 = new ProxySmoke(obj1Proxy1);
obj1ProxyProxy1.foo = "yo mama";

AddTestCase("add properties one by one and for in on props", true,
            checkProxy(obj1ProxyProxy1, ansProxyArray0, ansProxyArray1));

var errorMsg = "no error";
try{
	obj1Proxy0.doAction();
}catch(e){
	errorMsg = e.toString().substring(0,"TypeError: Error #1006".length);
}

AddTestCase("call non existent function on proxy", "TypeError: Error #1006",
            errorMsg);

test();