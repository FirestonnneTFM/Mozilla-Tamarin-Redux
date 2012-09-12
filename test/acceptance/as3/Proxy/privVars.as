/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Proxy";
var VERSION = "AS3";
var TITLE   = "Proxy test ported from ATS: ATS9AS3 Automated/Proxy/privVars";

startTest();

var obj = new Animal();
obj.name = "Tiger";
obj.internalBool = false;
var proxyObj = new PrivProxy(obj);
proxyObj.age = 254;

AddTestCase("proxy public var", "Tiger", proxyObj.name);
AddTestCase("proxy private var", undefined, proxyObj.privVar);
AddTestCase("proxy protected var", undefined, proxyObj.protVar);
AddTestCase("proxy Number defined in Class var", 999999, proxyObj.insideNum);
AddTestCase("proxy internal var", false, proxyObj.internalBool);
AddTestCase("proxy staticStr on proxyObj", undefined, proxyObj.staticStr);
AddTestCase("proxy prototype", "Proto Shark", proxyObj.protoVar);
AddTestCase("proxy original object.age", 254, obj.age);

proxyObj.insideNum = -1234;
proxyObj.age = 254;

AddTestCase("proxy overwritten inside num", -1234, obj.insideNum);

proxyObj.staticStr = "Lion";
proxyObj.dynNull = "not Null";

AddTestCase("proxy  - trace static", "Panda", Animal.staticStr);
AddTestCase("proxy  - dyanmic", "not Null", obj.dynNull);

obj.dynNull = null;

AddTestCase("proxy  - dyanmic  as null", null, proxyObj.dynNull);

obj.func = function(){ }

AddTestCase("call function with 3 number arguments",
            "Method func was called. With args: Monkey,9999,true",
            proxyObj.func("Monkey", 9999, true));
AddTestCase("call function with 6 number arguments",
            "Method func was called. With args: Monkey,9999,true,Monkey,9999,true",
            proxyObj.func("Monkey", 9999, true, "Monkey", 9999, true));

test();