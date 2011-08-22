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
    import avmplus.*;
    import flash.utils.*;

    var SECTION = "15.2";
    var VERSION = "ECMA_5";
    startTest();
    var TITLE   = "JSON AS3 Classs types";


    public class testclass1 {
        public var var1;
        public var var2:Boolean;
        public function testclass1() {
            var1="var1_value";
            var2=false;
            var3="var3_value";
            var4="var4_value";
            transient1="transient_value1";
        }
        public function foo() {
        }
        private var var3;
        private var var4:String;

        public function get getonly() {
            return "getonly_value";
        }

        public function set setonly(s) {
        }

        [Transient]
        public var transient1;

        [Transient]
        [ExcludeClass]
        public function get transientgetter() {
            return "transient getter";
        }
    }

    public class testclass2 {
        public var var1:int=-1;
        public var var2:Number=-3.14;
        public var var3:Array=[1,2,3];
        public var var4:Object=new Object();
        public var var5=Infinity;
        function testclass2() {
            var4.prop1=10;
        }
    }

    writeHeaderToLog( SECTION + " "+ TITLE);
    

    startTest();

    AddTestCase("stringify an AS3 class with getters, transient properties",'{"getonly":"getonly_value","var1":"var1_value","var2":false}',sortObject(JSON.parse(JSON.stringify(new testclass1()))));

    AddTestCase("stringify an AS3 class",'{"var1":-1,"var2":-3.14,"var3":[1,2,3],"var4":[object Object],"var5":null}',sortObject(JSON.parse(JSON.stringify(new testclass2()))));

    var testobj:Object=new Object();
    testobj.prop1="1";
    testobj.prop2=true;
    testobj.prop3=undefined;
    testobj.prop4=null;
    testobj.prop5=10;
    testobj.prop6=10.11;
    testobj.prop7=NaN;
    testobj.prop8=-Infinity;

   AddTestCase("stringify an AS3 object with various methods",'{"prop1":"1","prop2":true,"prop4":null,"prop5":10,"prop6":10.11,"prop7":null,"prop8":null}',sortObject(JSON.parse(JSON.stringify(testobj))));

    var testobj2:Object=new Object();
    testobj2.prop1=10;
    testobj2.toJSON=function() {
        return "testobj2";
    }
    AddTestCase("stringify an AS3 object with toJSON","\"testobj2\"",JSON.stringify(testobj2));

    var testobj3:Object=new Object();
    testobj3.prop1=10;
    testobj3.toJSON=function f() {
        throw new Error("toJSON error");
    }
    var exception1="no exception";
    try {
        JSON.stringify(testobj3);
    } catch (e) {
        exception1=e.toString();
    }
    AddTestCase("stringify an AS3 object with toJSON","Error: toJSON error",exception1);

    var testobj4:Object=new Object();
    testobj4.toJSON=true;
    AddTestCase("stringify an AS3 object with non-function toJSON",'{"toJSON":true}',JSON.stringify(testobj4));

    test();

}
