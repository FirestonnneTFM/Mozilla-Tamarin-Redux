/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package {
    var SECTION = "15.2";
    var VERSION = "ECMA_5";
    startTest();
    var TITLE   = "JSON AS3 Callback tests";

    writeHeaderToLog( SECTION + " "+ TITLE);

    startTest();
    
    AddTestCase('simple reviver',true,JSON.parse('[1,2,3]',function f() { return true; }));

    var keys=[];
    JSON.parse('[1,2,3]',function f(key,value) { keys[keys.length]=key; });
    keys.sort();
    AddTestCase('simple reviver test keys',',0,1,2',keys.toString());

    var values=[];
    JSON.parse('[1,2,3]',function f(key,value) { values[values.length]=value; });
    values.sort();
    AddTestCase('simple reviver test values',",,,1,2,3",values.toString());

    var keys2=[];
    JSON.parse('{"a":1,"b":2,"c":3}',function f(key,value) { keys2[keys2.length]=key; });
    keys2.sort();
    AddTestCase('simple reviver test keys on Object',',a,b,c',keys2.toString());

    var values2=[];
    JSON.parse('{"a":1,"b":2,"c":3}',function f(key,value) { values2[values2.length]=value; });
    values2.sort();
    AddTestCase('simple reviver test values on Object',"1,2,3,[object Object]",values2.toString());

    AddTestCase('simple reviver replaces values','1,0,0,4,5',JSON.parse('[1,2,3,4,5]',function f(key,value) { if (value=='2' || value=='3') return 0; else return value; }).toString());

    AddTestCase("simple reviver undefined removes values",'{"c":3,"d":4}',sortObject(JSON.parse('{"a":1,"b":2,"c":3,"d":4}',function f(key,value) { if (key=='a' || key=='b') return undefined; else return value; })));

    test();
}
