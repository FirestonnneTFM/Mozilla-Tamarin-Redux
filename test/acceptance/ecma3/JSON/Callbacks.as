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
