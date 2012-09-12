/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
/**
   File Name:    concat.es
   Description:  The static concat method collects the vector elements from object followed by the vector
    elements from the additional items, in order, into a new vector object.  All the items must be objects.
    returns a new vector object
   */

var SECTION = " ";
var VERSION = "AS3";
startTest();

writeHeaderToLog( SECTION + " Vector.concat()");

var v1=new Vector.<uint>();
v1[0]=0; v1[1]=1; v1[2]=2;
var v2=new Vector.<uint>();
v2[0]=3;v2[1]=4;v2[2]=5;
var v3=v1.concat(v2)
AddTestCase(    "concat uint vector, original vector is unchanged",
        "0,1,2",
        v1.toString());
AddTestCase(    "concat uint vector, new vector concat worked",
        "0,1,2,3,4,5",
        v3.toString());

var v1=new Vector.<String>();
v1[0]="zero"; v1[1]="one"; v1[2]="two";
var v2=new Vector.<int>();
v2[0]=0; v2[1]=1; v2[2]=2;
var errormsg;
try {
  var v3=v1.concat(v2);
} catch (e) {
  errormsg=e.toString();
}
AddTestCase(    "concat two differently typed vectors",
                "TypeError: Error #1034",
                parseError(errormsg,"TypeError: Error #1034".length));

class TestClass {
    private var myVal:Object;
    public function TestClass(v:Object):void {
        myVal = v;
    }
    public function toString():String {
        return myVal.toString();
    }
}

var v4:Vector.<TestClass> = new Vector.<TestClass>();
v4.push(new TestClass(33));
v4.push(new TestClass(44));

var v5 = new Vector.<TestClass>()
v5.push(new TestClass(100));

var v6 = v4.concat(v5);

AddTestCase("concat custom vector class", "33,44,100", v6.toString());

AddTestCase("concat vector to itself multiple times",
            "100,100,100",
            v5.concat(v5,v5).toString()
            );

AddTestCase("concat with no parameters duplicates original vector",
            "33,44",
            v4.concat().toString()
            );

var b1 = new <Boolean>[true,false,true];
var b2 = new <Boolean>[false,true,false];
AddTestCase("concat boolean vectors", "true,false,true,false,true,false", b1.concat(b2).toString());

var xmlVector = new <XML>[];
var expectedArr:Array = [];
for (var i=0; i<80; i++) {
    xmlVector = xmlVector.concat(new <XML>[XML("<test>"+i+"</test>")]);
    expectedArr.push(i);
}

AddTestCase("concat XML vectors", expectedArr.join(','), xmlVector.toString() )

var va:Array = []
// Concat multiple vectors
for (var i=0; i <= 10; i++) {
    va[i] = new <int>[i];
}

AddTestCase("concat multiple int vectors",
            "0,1,2,3,4,5,6,7,8,9,10",
            va[0].concat(va[1],va[2],va[3],va[4],va[5],va[6],va[7],va[8],va[9],va[10])
           );

test();

