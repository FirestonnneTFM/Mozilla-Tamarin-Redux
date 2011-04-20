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

var SECTION = "JSON";
var VERSION = "AS3";
var TITLE   = "JSON adhoc tests for JSON.parse and JSON.stringify";

startTest();

function countSpaces(s:String) {
    var spaces:uint=0;
    for (var i=0;i<s.length;i++) {
        if (s.charAt(i)==' ') spaces+=1;
    }
    return spaces;
}

function jformat(x) {
    if (x is String)
    return '"' + x + '"';
    else
    return x;
}

// set the Object.toString and Array.toString to show each property value 
// instead of [Object object] for testing
var oldObject = Object.prototype.toString;
var oldArray = Array.prototype.toString;
Object.prototype.toString = 
    (function () {
    var s = "{";
    var first = true;
    for ( var i in this ) {
    if (this.hasOwnProperty(i)) {
        if (!first)
        s += ",";
        s += jformat(String(i)) + ":" + jformat(this[i]);
        first = false;
    }
    }
    return s + "}";
});
Array.prototype.toString = 
    (function () {
    var s = "[";
    var first = true;
    for ( var i=0 ; i < this.length ; i++ ) {
        if (!first)
            s += ",";
        first = false;
        if (!this.hasOwnProperty(i))
            continue;
        s += jformat(this[i]);
    }
    return s + "]";
});

// AddTestCase(comment,expected,actual)
// test JSON.parse on numeric values
AddTestCase("JSON.parse(1)",1,JSON.parse("1"));
AddTestCase("JSON.parse(-1.75e12)","-1750000000000",JSON.parse("-1.75e12").toString());
AddTestCase("JSON.parse(-1.75)",-1.75,JSON.parse("-1.75"));
AddTestCase("JSON.parse(1.75)",1.75,JSON.parse("1.75"));
AddTestCase("JSON.parse(-1e-12)","-1e-12",JSON.parse("-1e-12").toString())
AddTestCase("JSON.parse(-1e+12)","-1000000000000",JSON.parse("-1e+12").toString());

// test JSON.parse on simple string
AddTestCase("JSON.parse(supercallifragilistic)","supercallifragilistic",JSON.parse("\"supercallifragilistic\""));

// test JSON.parse on null
AddTestCase("JSON.parse(null)",null,JSON.parse("  null "));

// test JSON.parse true/false
AddTestCase("JSON.parse(true)",true,JSON.parse("true"));
AddTestCase("JSON.parse(false)",false,JSON.parse("\t\n\rfalse"));

// test JSON.parse array
AddTestCase("JSON.parse([1,2,3,true,false,null])","[1,2,3,true,false,null]",JSON.parse("[1,2,3,true,false,null]").toString());

// test JSON.parse object
AddTestCase("JSON.parse({a:10,b:20})","{\"a\":10,\"b\":20}",sortObject(JSON.parse("{\"a\":10,\"b\":20}")));
AddTestCase("JSON.parse({c:[1,2,3]}},a:{b:20})",'{"a":{"b":20},"c":[[1,"2",3]]}',sortObject(JSON.parse("{\"a\":{\"b\":20},\"c\":[1,\"2\",3]}")));

// test JSON.parse revivers
AddTestCase("JSON.parse(1,reviver)","44",JSON.parse("1", function (name, val) { return "44" }));
AddTestCase("JSON.parse([1,-2,3],negate reviver)","[-1,2,-3]",JSON.parse("[1,-2,3]", function (name, val) { if (val is Number) return -val; else return val; }).toString());
AddTestCase("JSON.parse([1,-2,3],undef neg reviver)",JSON.parse("[1,-2,3]", function (name, val) { if (val is Number && val < 0) return undefined; else return val; }).toString(),"[1,,3]");
// not sure why?
AddTestCase("JSON.parse([1,-2,3],undef 1 reviver)","[\"1\",,3]",JSON.parse("[\"1\",-2,3]", function (name, val) { if (name == "1") return undefined; else return val; }).toString());
AddTestCase("JSON.parse({a:{\"1\":20},c:[1,2,3]})","{\"a\":{\"1\":20},\"c\":[[,\"2\",3]]}",
  sortObject(JSON.parse("{\"a\":{\"1\":20},\"c\":[1,\"2\",3]}", function (name, val) { if (val == "1") return undefined; else return val; })));

// reset Object and Array toString to initial values
Object.prototype.toString = oldObject;
Array.prototype.toString = oldArray;

// test JSON.stringify on numbers
AddTestCase("JSON.stringify(1)","1",JSON.stringify(JSON.parse("1")));
AddTestCase("JSON.stringify(-1.75e12)","-1750000000000",JSON.stringify(JSON.parse("-1.75e12")));
AddTestCase("JSON.stringify(-1.75)","-1.75",JSON.stringify(JSON.parse("-1.75")));
AddTestCase("JSON.stringify(1.75)","1.75",JSON.stringify(JSON.parse("1.75")));
AddTestCase("JSON.stringify(-1e-12)","-1e-12",JSON.stringify(JSON.parse("-1e-12")));
AddTestCase("JSON.stringify(-1e+12)","-1000000000000",JSON.stringify(JSON.parse("-1e+12")));

// test JSON.stringify on string
AddTestCase("JSON.stringify(supercallifragilistic)","\"supercallifragilistic\"",JSON.stringify(JSON.parse("\"supercallifragilistic\"")));

// test JSON.stringify on null
AddTestCase("JSON.stringify(null)","null",JSON.stringify(JSON.parse("  null ")));

// test JSON.stringify on booleans
AddTestCase("JSON.stringify(true)","true",JSON.stringify(JSON.parse("true")));
AddTestCase("JSON.stringify(false)","false",JSON.stringify(JSON.parse("\t\n\rfalse")));

// test JSON.stringify on array
AddTestCase("JSON.stringify(array)","[1,2,3,true,false,null]",JSON.stringify(JSON.parse("[1,2,3,true,false,null]")));

// test JSON.stringify on objects
AddTestCase("JSON.stringify(object)","{\"a\":10,\"b\":20}",sortObject(JSON.parse(JSON.stringify(JSON.parse("{\"a\":10,\"b\":20}")))));
AddTestCase("JSON.stringify(nested object)",'{"a":[object Object],"c":[1,2,3]}',sortObject(JSON.parse("{\"a\":{\"b\":20},\"c\":[1,\"2\",3]}")));

// todo: why are the \n appearing? in all space
// test JSON.stringify with space=string
AddTestCase("JSON.stringify(array,replacer=null,space)","[\n 1,\n 2,\n 3,\n true,\n false,\n null\n]",JSON.stringify(JSON.parse("[1,2,3,true,false,null]"),null," "));
AddTestCase("JSON.stringify(object,replacer=null,space)",15,countSpaces(JSON.stringify(JSON.parse("{\"a\":{\"b\":20},\"c\":[1,\"2\",3]}"), null," ")));

// test JSON.stringify with space as Array
AddTestCase("JSON.stringify(array,replacer=array)","[1,2,3,true,false,null]",JSON.stringify(JSON.parse("[1,2,3,true,false,null]"),[1,3,5]));
AddTestCase("JSON.stringify(object,replacer=array)","{\"a\":{},\"c\":[1,\"2\",3]}",JSON.stringify(JSON.parse("{\"a\":{\"b\":20},\"c\":[1,\"2\",3]}"), ["a","c"]));

// test JSON.stringify with space as function
AddTestCase("JSON.stringify(array,replacer=function)","[1,null,3,null,false,null]",JSON.stringify(JSON.parse("[1,2,3,true,false,null]"), function (key, value) { if (!(parseInt(key) & 1)) return value; return undefined; } ));
AddTestCase("JSON.stringify(object,replacer=function)","{\"a\":[object Object],\"c\":[-1,2,-3]}",sortObject(JSON.parse(JSON.stringify(JSON.parse("{\"a\":{\"b\":20},\"c\":[1,\"2\",3]}")), function (key, value) { if (value is Number) return -value; return value; } )));


// test JSON.stringify circular structures throw TypeError exception
negativeTestException="no exception thrown";
try {
    var a= [];
    a[0]=a;
    JSON.stringify(a);
} catch(e) {
    negativeTestException=e.toString();
    negativeTestException=removeExceptionDetail(negativeTestException);
}
AddTestCase("JSON.stringify(circular structure)","TypeError: Error #1129",negativeTestException);

AddTestCase("test Quote on escaped characters: JSON.stringify(\\b,\\t,\\f,\\r)",'"\\b,\\t,\\f,\\r"',JSON.stringify("\b,\t,\f,\r"));
AddTestCase("test Quote on double quote",'"\\""',JSON.stringify('\"'));

test();
