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

package {

import avmplus.System;
import avmplus.File;
import flash.utils.ByteArray;
import flash.system.Worker;
import flash.system.Promise;
import flash.system.PromiseChannel;
import flash.system.WorkerDomain;
import flash.utils.Dictionary;


// Since arguments is an instance and a class, define a custom arguments type
// in order to be able to detect it
class argumentsClass {}

if (Worker.current.isPrimordial) {
    // Root Worker
    
    var SECTION = "concurrency";
    var VERSION = "AS3";
    var TITLE   = "Test message passing of basic datatypes.";
    
    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);
    
    var w:Worker = WorkerDomain.current.createWorkerFromPrimordial();
    var promise:Promise = w.start();
    
    function getEchoedObject(obj) {
        var result;
        try {
            var echo_object_promise:Promise = promise.async.echoObject(obj);
            result = echo_object_promise.receive();
        } catch (exception) {
            result = exception.toString();
        }
        return result;
    }
    
    // Test passing different object back and forth
    // echoObject will print the object and return it
    function testEchoedObject(obj, desc = undefined, type = undefined,
                              comparisonFunc = undefined) {
        var result = getEchoedObject(obj);
        if (desc == undefined) {
            desc = obj.toString();
        }
        
        if (comparisonFunc != undefined) {
            AddTestCase(desc, true, comparisonFunc(result));
            return;
        }
        
        if (type == undefined) {
            AddTestCase(desc, obj, result);
        } else if (type == argumentsClass) {
            compareArguments(desc, obj, result);
        } else if (type == Array) {
            compareArray(desc, obj, result);
        } else if (type == ByteArray) {
            compareByteArray(desc, obj, result);
        } else if (type == Date) {
            AddTestCase(desc, obj.getTime(), result.getTime());
            compareObjects(desc, obj, result);
        } else if (type == Error) {
            compareErrors(desc, obj, result);
        } else if (type == Object) {
            compareObjects(desc, obj, result);
        }
        print("testEchoedObject "+desc+" "+obj);
    }
    
    // ArgumentError
    var argumentError1:ArgumentError = new ArgumentError("my special ArgumentError");
    testEchoedObject(argumentError1, "Custom ArgumentError", Error);
    
    
    // arguments object -- TODO: should this work?  arguments is a fringe case
    
    function testPassingArguments(first) {
        testEchoedObject(arguments, "arguments array", Array)
    }
    
    testPassingArguments(2, Infinity, "and beyond");
    
    
    // Array
    var array:Array = [1, 2, "three", null, plainObject, [5,6,76]];
    testEchoedObject(array, "Mixed Array", Array)
    
    // Bug https://bugzilla.mozilla.org/show_bug.cgi?id=675764 causes assert
    // commenting out till fixed
    /*
    var sparseArray:Array = [1,"two"];
    sparseArray[2050] = "twenty fifty";
    sparseArray[784638] = [5,6,7,8];
    testEchoedObject(sparseArray, "Sparse Array", Array);
    */
    
    // Boolean
    var bool:Boolean = true;
    testEchoedObject(bool);
    bool = false;
    testEchoedObject(bool);
    
    // TODO: Class to be covered in ____ test file
    
    // Date
    var date = new Date("02/01/2005");
    testEchoedObject(date, "Date", Date);
    
    // DefinitionError
    var definitionError:DefinitionError = new DefinitionError("my special DefinitionError");
    testEchoedObject(definitionError, "Custom DefinitionError", Error);
    
    // Error - Note that errorID will not get passed as it is a read-only property
    var error:Error = new Error("Basic Error", 876);
    testEchoedObject(error, "Custom Error", Error);
    
    // EvalError
    var evalErr:EvalError = new EvalError("my special EvalError");
    testEchoedObject(evalErr, "Custom EvalError", Error);
    
    var ba:ByteArray=new ByteArray();
    ba.writeUTF("byte array string");
    testEchoedObject(ba, "ByteArray", ByteArray);
    
    // Function
    function testFunction() {}
    AddTestCase( "Passing a function is not supported", undefined, getEchoedObject(testFunction));
    
    // int
    testEchoedObject(12345);
    testEchoedObject(-Infinity);
    testEchoedObject(-0);
    testEchoedObject(0);
    testEchoedObject(Infinity);
    testEchoedObject(0xFFFFFF);
    testEchoedObject(int.MAX_VALUE);
    testEchoedObject(int.MIN_VALUE);
    testEchoedObject(int.MAX_VALUE + 1);
    testEchoedObject(int.MIN_VALUE - 1);
    
    // Namespace - TODO: test in seperate file and insert filename here
    
    // null
    var n:* = null;
    testEchoedObject(n, 'null');
    
    // Number
    testEchoedObject(Number.MAX_VALUE);
    testEchoedObject(Number.MIN_VALUE);
    testEchoedObject(NaN);
    testEchoedObject(Math.PI);
    testEchoedObject(Math.LOG2E);
    
    // Object
    var plainObject = new Object();
    testEchoedObject(plainObject, "Plain Object", Object);
    
    var myObject = new Object();
    myObject.toString = function () {
        return '[object myObject]';
    }

    // The overriden toString function will be undefined when returned
    var result;
    result = getEchoedObject(myObject);
    AddTestCase('Object with custom toString function', 'function', typeof result.toString); // should have the toString inherited from Object

    myObject.aDynamicProperty = function() {}
    AddTestCase('Dynamic properties with function values are dropped', undefined, getEchoedObject(myObject).aDynamicProperty);

    
    // QName - TODO: I assume this won't work as both properties are read-only
    
    // RegExp
    // TODO: Classes that don't work in AMF that probably should here?
    //var regexp:RegExp = /test-\d/i;
    //testEchoedObject(regexp, "Simple RegExp");
    
    
    // Strings
    testEchoedObject('', 'Echo empty string');
    testEchoedObject('hello world');

    // reduced from 25 to 15 doubling to avoid failure on windows and reduce time to run
    // produces string length: 163840
    var largeStr = '0123456789';
    for (var i=0; i<15; i++)
        largeStr += largeStr;
    
    AddTestCase('Echo large string', true, largeStr === getEchoedObject(largeStr));
    // uint
    testEchoedObject(uint.MAX_VALUE);
    testEchoedObject(uint.MIN_VALUE);
    testEchoedObject(uint.MAX_VALUE + 1);
    testEchoedObject(uint.MIN_VALUE - 1);
    
    // undefined
    var u:* = undefined;
    // TODO: What is the expected behavior here?
    AddTestCase('* type var set to undefined', null, getEchoedObject(u));
    
    // Vector
    
    // XML
    var x1:XML =
        <order>
            <!--This is a comment. -->
            <?PROC_INSTR sample ?>
            <item id='1'>
                <menuName>burger</menuName>
                <price>3.95</price>
            </item>
            <item id='2'>
                <menuName>fries</menuName>
                <price>1.45</price>
            </item>
        </order>
    AddTestCase('XML Object', x1, getEchoedObject(x1));
    
    // XMLList
    var books:XML = <books>
                    <book publisher="Addison-Wesley" name="Design Patterns" />
                    <book publisher="Addison-Wesley" name="The Pragmatic Programmer" />
                    <book publisher="Addison-Wesley" name="Test Driven Development" />
                    <book publisher="Addison-Wesley" name="Refactoring to Patterns" />
                    <book publisher="O'Reilly Media" name="The Cathedral & the Bazaar" />
                    <book publisher="O'Reilly Media" name="Unit Test Frameworks" />
                </books>;
                
    
    // XMLList is not supported in AMF, should it be here?
    // var xmllist:XMLList = books.book.(@publisher == "Addison-Wesley");
    // AddTestCase("XMLList compared to itself", xmllist, xmllist);
    // testEchoedObject(xmllist, "XMLList");

    namespace foo; 
    var aNS:Namespace = foo;
    var aNSCopy = getEchoedObject(aNS);
    AddTestCase('Namespace equality', true, aNSCopy == aNS);
    AddTestCase('Namespace identity', true, aNSCopy === aNS);
    
    AddTestCase('Worker identity', true, getEchoedObject(w) === w);
    
    var aDict:Dictionary = new Dictionary();
    aDict.foo = "bar";
    var k = new Date();
    aDict[k] = "Letters";
    aDict[function(){}] = "I'm a function";
    testEchoedObject('Trivial Dictionary equality', aDict, Object);
    
    var aDictCopy:Dictionary = getEchoedObject(aDict);

    AddTestCase('Nonstring Dictionary key', false, aDict[k] == aDictCopy[k]); // copy's keys have a different identity



    // Worker TODO: create seperate test file
    
    test();
    w.terminate();
    
} else {
    // worker
    public function echoObject(o) {
        return o;
    }
    
}

}