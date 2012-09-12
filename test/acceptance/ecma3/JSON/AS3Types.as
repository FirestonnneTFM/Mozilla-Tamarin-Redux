/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package {
    import avmplus.*;
    import flash.utils.*;

    var SECTION = "15.2";
    var VERSION = "ECMA_5";
    startTest();
    var TITLE   = "JSON AS3 specific types";

    writeHeaderToLog( SECTION + " "+ TITLE);

    startTest();

    // Vector tests

    AddTestCase("Vectors are stringified to JSON Array syntax",'[1,"2",true,4,"a"]',JSON.stringify(Vector.<*>([1,"2",true,4.0,"a"])));
    AddTestCase("Vectors of int are stringified to JSON Array syntax",'[1,-2,3,-4]',JSON.stringify(Vector.<int>([1,-2,3,-4])));
    AddTestCase("Vectors of uint are stringified to JSON Array syntax",'[1,2,3,4]',JSON.stringify(Vector.<uint>([1,2,3,4])));
    AddTestCase("Vectors of Number are stringified to JSON Array syntax",'[1,2.2,3.33,4.444]',JSON.stringify(Vector.<Number>([1,2.2,3.33,4.444])));
    AddTestCase("Vectors of Boolean are stringified to JSON Array syntax",'[true,false,true,false]',JSON.stringify(Vector.<Boolean>([true,false,true,false])));
    AddTestCase("uninitialized Vector is stringified to []","[]",JSON.stringify(new Vector.<*>()));
    AddTestCase("Vector of edge case values",'[null,null,null,null,""]',JSON.stringify(Vector.<*>([null,undefined,-Infinity,NaN,""])));
   
    // Array tests
    AddTestCase("Arrays are parsed correctly, empty []","",JSON.parse("[]").toString());
    AddTestCase("Arrays are parsed correctly, [1]","1",JSON.parse("[1]").toString());
    AddTestCase("Arrays are parsed correctly, [1,2,3]","1,2,3",JSON.parse("[1,2,3]").toString());

    JSONSyntaxError="SyntaxError: Error #1132";

//  crashes
    exception1="no exception";
    try {
        JSON.parse("[");
    } catch(e) {
        exception1=removeExceptionDetail(e.toString());
    }
    AddTestCase("Arrays errors are detected, [",JSONSyntaxError,exception1);

    exception2="no exception";
    try {
        JSON.parse("[1,2,3,fals]");
    } catch(e) {
        exception2=removeExceptionDetail(e.toString());
    }
    AddTestCase("Arrays errors are detected, [1,2,3,fals]",JSONSyntaxError,exception2);

    exception3="no exception";
    try {
        JSON.parse("[1,2,]");
    } catch(e) {
        exception3=removeExceptionDetail(e.toString());
    }
    AddTestCase("Arrays errors are detected, [1,2,]",JSONSyntaxError,exception3);

    exception4="no exception";
    try {
        JSON.parse("[1,2,3");
    } catch(e) {
        exception4=removeExceptionDetail(e.toString());
    }
    AddTestCase("Arrays errors are detected, [1,2,3",JSONSyntaxError,exception4);

    var star:*="anytype";
    AddTestCase("Type * is like an untyped variable",'"anytype"',JSON.stringify(star));


    // Dictionary tests
    var d:Dictionary=new Dictionary();

    class Foo extends Object {
        static var timecounter = 1;
        public var timestamp;
        var name;
        function Foo(name) { this.name = name; this.timestamp = timecounter++; }
        public function toString():String { return this.name; }
    }
    var o1 = new Foo("o");
    var p2 = new Foo("p");
    var o3 = new Foo("o");
    d[o3]="value";
    AddTestCase("stringify a Dictionary object",'"Dictionary"',JSON.stringify(d));

    // Change toJSON to show object values, where distinct objects
    // with identical toString output are distinguished (if possible)
    // by the timestamps they were constructed with.
    var origDictionarytoJSON=Dictionary.prototype.toJSON;
    Dictionary.prototype.toJSON=function():* {
        var x = {};
        for (var i in this) {
            if ("timestamp" in i) {
                x[String(i)+"_"+i.timestamp] = this[i];
            } else {
                x[String(i)] = this[i];
            }
        }
        return x; // x is not a String!
    };

    // The simple case: a single element Dictionary won't run into
    // issues of unspecified order of rendered key/value entries.
    AddTestCase("stringify a 1-elem Dictionary with customized toJSON",
                '{"o_3":"value"}',
                JSON.stringify(d));

    d[o1]="o1-value";
    d[p2]="p2-value";
    d[o3]="o3-value";

    // Trickier case: multi-element Dictionary may present entries in
    // arbitrary order; normalize it by reparsing and sorting entries.
    AddTestCase("stringify a 3-elem Dictionary with customized toJSON",
                '{"o_1":"o1-value","o_3":"o3-value","p_2":"p2-value"}',
                sortObject(JSON.parse(JSON.stringify(d))));

    // Restore original toJSON and its trivial behavior.
    Dictionary.prototype.toJSON=origDictionarytoJSON;
    AddTestCase("stringify a Dictionary restored original toJSON",'"Dictionary"',JSON.stringify(d));

    // ByteArray tests
    var b:ByteArray=new ByteArray();
    b.writeUTF("byte array string");
    AddTestCase("stringify a ByteArray object",'"ByteArray"',JSON.stringify(b));

    var origByteArraytoJSON=ByteArray.prototype.toJSON;
    ByteArray.prototype.toJSON=function() {
        return this.toString().substring(2);
    }
    AddTestCase("stringify a ByteArray object with custom toJSON",'"byte array string"',JSON.stringify(b));
    ByteArray.prototype.toJSON=origByteArraytoJSON;
    AddTestCase("stringify a ByteArray object with restored toJSON",'"ByteArray"',JSON.stringify(b));
    
    // XML

    var x:XML=<root><element1 prop1="one"/></root>;
    AddTestCase("stringify XML object",'"XML"',JSON.stringify(x));

    // Date
    var dt:Date=new Date(2011,3,26,10,33,0,111);
    AddTestCase("stringify a Date object",true,JSON.stringify(dt).indexOf('"Tue Apr 26 10:33:00')>-1);
    var origDatetoJSON=Date.prototype.toJSON;
    Date.prototype.toJSON=function() {
        return ""+this.getFullYear()+"-"+(this.getMonth()+1)+"-"+this.getDate()+"T"+this.getHours()+":"+this.getMinutes()+":"+this.getSeconds()+"."+this.getMilliseconds()+"Z";
    }
    AddTestCase("stringify a Date object with custom toJSON",'"2011-4-26T10:33:0.111Z"',JSON.stringify(dt));
    Date.prototype.toJSON=origDatetoJSON;
    AddTestCase("stringify a Date object with restored toJSON",true,JSON.stringify(dt).indexOf('"Tue Apr 26 10:33:00')>-1);

    test();

}
