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
var TITLE   = "Proxy advanced tests ported from ATS: ATS9AS3 Automated/Proxy/testProxyAdvanced";

startTest();

// This tests getting and setting property

// instantiate a new object
var myObject:Object = new Object();

// wrap that object in a proxy
var myObjectProxy:ProxyAdvanced = new ProxyAdvanced(myObject);

// simulate addProperty
function getQuantity():Number
{
	return books;
}

function setQuantity(numBooks:Number):void
{
	books = numBooks;
}

function getTitle():String
{
	return "Catcher in the Rye";
}

var myObjectProxy2:Book = new Book();

myObjectProxy2.addProperty("bookCount", getQuantity, setQuantity);
myObjectProxy2.addProperty("bookName", getTitle, null);

myObjectProxy2.bookCount = 5;


AddTestCase("Test getter/setter using 'addProperty'",
            "You ordered 5 copies of the book",
            "You ordered " + myObjectProxy2.bookCount + " copies of the book");
AddTestCase("Test getter with null setter using 'addProperty'",
            "The book you ordered is Catcher in the Rye",
            "The book you ordered is " + myObjectProxy2.bookName);

// Test array operator

myObjectProxy.testArrayOperator = 555;
AddTestCase("Test getter with array operator", 555,
            myObjectProxy["testArrayOperator"]);

myObjectProxy["testArrayOperator"] = 111;
AddTestCase("Test setter with array operator", 111,
            myObjectProxy.testArrayOperator);

import NameSpacePackage.*;
// Test namespaces:
var eg:NameSpaceExample = new NameSpaceExample();
var p:ProxyAdvanced = new ProxyAdvanced(eg);


eg.NameSpaceDef::two = "two";




// using myClass.ns::prop
AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'myClass.ns::myProp'",
            "eg.NameSpaceDef::two = two",
            'eg.NameSpaceDef::two = ' + eg.NameSpaceDef::two);
AddTestCase("Test myProxy.getter of a variable in a namespace with dot operator -- 'myClass.ns::myProp'",
            "p.NameSpaceDef::two = two",
            'p.NameSpaceDef::two = ' + p.NameSpaceDef::two);

p.NameSpaceDef::two = "twenty-two";

AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'myClass.ns::myProp'",
            "eg.NameSpaceDef::two = twenty-two",
            'eg.NameSpaceDef::two = ' + eg.NameSpaceDef::two);
AddTestCase("Test myProxy.getter of a variable in a namespace with dot operator -- 'myClass.ns::myProp'",
            "p.NameSpaceDef::two = twenty-two",
            'p.NameSpaceDef::two = ' + p.NameSpaceDef::two);

// wrap use namespace inside a function so the scope of the
// use namespace declaration is only scoped to the function.
function doUseNameSpace()
{
	use namespace NameSpaceDef;
    answerArr = []
	try {
        eg.three = 3;
		answerArr[0] = 'eg.NameSpaceDef::three = ' + eg.NameSpaceDef::three;
		answerArr[1] = 'p.NameSpaceDef::three = ' + p.NameSpaceDef::three;
		answerArr[2] = 'eg.three = ' + eg.three;
		answerArr[3] = 'p.three = ' + p.three;
	
		p.three = 33;
	
		answerArr[4] = 'eg.NameSpaceDef::three = ' + eg.NameSpaceDef::three;
		answerArr[5] = 'p.NameSpaceDef::three = ' + p.NameSpaceDef::three;
		answerArr[6] = 'eg.three = ' + eg.three;
		answerArr[7] = 'p.three = ' + p.three;
	} catch (notUsingNameSpace) {
		answerArr[0] = 'Bug 174012';
		answerArr[1] = 'Bug 174012';
		answerArr[2] = 'Bug 174012';
		answerArr[3] = 'Bug 174012';
		answerArr[4] = 'Bug 174012';
		answerArr[5] = 'Bug 174012';
		answerArr[6] = 'Bug 174012';
		answerArr[7] = 'Bug 174012';
	}
    AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'myClass.ns::myProp'",
                "eg.NameSpaceDef::three = 3",
                answerArr[0]);
    AddTestCase("Test myProxy.getter of a variable in a namespace with dot operator -- 'myClass.ns::myProp'",
                "p.NameSpaceDef::three = 3",
                answerArr[1]);
    AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'myClass.myProp'",
                "eg.three = 3",
                answerArr[2]);
    AddTestCase("Test myProxy.getter of a variable in a namespace with dot operator -- 'myClass.myProp'",
                "p.three = 3",
                answerArr[3]);

    AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'myClass.ns::myProp'",
                "eg.NameSpaceDef::three = 33",
                answerArr[4]);
    AddTestCase("Test myProxy.getter of a variable in a namespace with dot operator -- 'myClass.ns::myProp'",
                "p.NameSpaceDef::three = 33",
                answerArr[5]);
    AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'myClass.myProp'",
                "eg.three = 33",
                answerArr[6]);
    AddTestCase("Test myProxy.getter of a variable in a namespace with dot operator -- 'myClass.myProp'",
                "p.three = 33",
                answerArr[7]);
}
doUseNameSpace();

eg.NameSpaceDef::one = "Namespace one";

eg.onePub = "Public one";


// namespace public and namespace ns
// after setting value on eg
AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'eg.ns::one'",
            "eg.NameSpaceDef::one = Namespace one",
            'eg.NameSpaceDef::one = ' + eg.NameSpaceDef::one);
AddTestCase("Test myProxy.getter of a variable in a namespace with dot operator -- 'eg.public::one'",
            "eg.public::onePub = Public one",
            'eg.public::onePub = ' + eg.public::onePub);
AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'eg.one'",
            "eg.onePub = Public one",
            'eg.onePub = ' + eg.onePub);

AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'p.ns::one'",
            "p.NameSpaceDef::one = Namespace one",
            'p.NameSpaceDef::one = ' + p.NameSpaceDef::one);
AddTestCase("Test myProxy.getter of a variable in a namespace with dot operator -- 'p.public::one'",
            "p.public::onePub = Public one",
            'p.public::onePub = ' + p.public::onePub);
AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'p.one'",
            "p.onePub = Public one",
            'p.onePub = ' + p.onePub);

p.NameSpaceDef::one = "Namespace one again";

p.onePub = "Public one again";

// after setting value on p
AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'eg.ns::one'",
            "eg.NameSpaceDef::one = Namespace one again",
            'eg.NameSpaceDef::one = ' + eg.NameSpaceDef::one);
AddTestCase("Test myProxy.getter of a variable in a namespace with dot operator -- 'eg.public::one'",
            "eg.public::onePub = Public one again",
            'eg.public::onePub = ' + eg.public::onePub);
AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'eg.one'",
            "eg.onePub = Public one again",
            'eg.onePub = ' + eg.onePub);

AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'p.ns::one'",
            "p.NameSpaceDef::one = Namespace one again",
            'p.NameSpaceDef::one = ' + p.NameSpaceDef::one);
AddTestCase("Test myProxy.getter of a variable in a namespace with dot operator -- 'p.public::one'",
            "p.public::onePub = Public one again",
            'p.public::onePub = ' + p.public::onePub);
AddTestCase("Test myObject.getter of a variable in a namespace with dot operator -- 'p.one'",
            "p.onePub = Public one again",
            'p.onePub = ' + p.onePub);

test();
