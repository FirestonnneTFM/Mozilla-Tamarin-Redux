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
/*
//  crashes
    exception1="no exception";
    try {
        JSON.parse("[");
    } catch(e) {
        exception1=removeExceptionDetail(e.toString());
    }
    AddTestCase("Arrays errors are detected, [",JSONSyntaxError,exception1);
*/
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

    var x:XML=<root><child prop="prop1">value</child></root>;
    print(x);

    test();

}
