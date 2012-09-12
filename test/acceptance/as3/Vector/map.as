/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/**
   File Name:    map.as
   Description:  map(object,mapper,thisobj)
     calls mapper on each vector element of object in increasing numerical index order, collecting
     the return values from mapper in a new vector object.
     mapper is called with three arguments: the property value, the property index, and object itself.
     The thisobj is used as the this object in the call.
     returns a new vector object where the vector element at index i is the value returned from the call
     to mapper on object[i].
   */
var SECTION="";
var VERSION = "ECMA_1";

startTest();

writeHeaderToLog( " Vector.map()");

function mapper1(value,index,obj) {
   return "("+value+":"+index+")";
}
var mapper2="a string";
function mapper3(value,index,obj) {
   return "("+this.message+")";
}
function mapper4(value,index,obj) {
   return value*value;
}

var v1=new Vector.<int>();
v1.push(1);
var errormsg="";
try {
  var result=v1.map();
} catch (e) {
  errormsg=e.toString();
}
AddTestCase(
        "map mapper is undefined",
        "ArgumentError: Error #1063",
        parseError(errormsg,"ArgumentError: Error #1063".length));

var v1=new Vector.<int>();
v1.push(1);
var errormsg="";
try {
  var result=v1.map(mapper2);
} catch (e) {
  errormsg=e.toString();
}
AddTestCase(
        "map mapper is not a function",
        "TypeError: Error #1034",
        parseError(errormsg,"TypeError: Error #1034".length));

var v1=new Vector.<int>();
AddTestCase(
        "map empty vector",
        "",
        v1.map(mapper1).toString());

var v1=new Vector.<String>();
v1[0]='a';
v1[1]='b';
v1[2]='c';
AddTestCase(
        "map small vector",
        "(a:0),(b:1),(c:2)",
        v1.map(mapper1).toString());

var v1=new Vector.<String>(3,true);
v1[0]='a';
v1[1]='b';
v1[2]='c';
AddTestCase(
        "map fixed size small vector",
        "(a:0),(b:1),(c:2)",
        v1.map(mapper1).toString());

testobj=new Object();
testobj.message="testobj";
var v1=new Vector.<String>();
v1.push('a');v1.push('b');
AddTestCase(   "map vector passing new object",
               "(testobj),(testobj)",
               v1.map(mapper3,testobj).toString());

var v1=new Vector.<int>();
v1[0]=1;
v1[1]=2;
v1[2]=3;
v1[3]=4;
AddTestCase(   "map vector of int",
               "1,4,9,16",
               v1.map(mapper4).toString());

// From https://bugzilla.mozilla.org/show_bug.cgi?id=507501
function convertToUpper(item:String, index:int, v:Vector.<String>):String {
    return item.toUpperCase();
    }
    
var vec:Vector.<String> = Vector.<String>(['one','two']);


var vec2:Vector.<String> = vec.map(convertToUpper);
AddTestCase("Vector map to uppercase",
            "ONE,TWO",
            vec2.toString()
            );

AddTestCase("Type check", true, vec is Vector.<String>);
AddTestCase("Type check returned map value", true, vec.map(convertToUpper) is Vector.<String>);

// Custom vector type
class TestClass {
    private var myVal:Object;
    public function TestClass(v:Object):void {
        myVal = v;
    }
    public function toString():String {
        return myVal.toString();
    }
    
    public function doubleMyVar():void {
        myVal *= 2;
    }
    
    public static function double(item:Object, index:int, vector:Vector.<TestClass>):Object {
        item.doubleMyVar();
        return item;
    }
    
    public static function TestClass33():TestClass {
        return new TestClass(33);
    }
}

var v4:Vector.<TestClass> = new Vector.<TestClass>();
v4.push(new TestClass(33));
v4.push(new TestClass(44));
v4.push(new TestClass(50));

AddTestCase("Call map on custom vector class",
            "66,88,100",
            v4.map(TestClass.double).toString()
            );

function thisObjectTest(item:Object, index:int, vector:Vector.<TestClass>):Object {
    return this.TestClass33();
}

AddTestCase("test thisObject",
            "33,33,33",
            v4.map(thisObjectTest, TestClass).toString()
            );

test();
