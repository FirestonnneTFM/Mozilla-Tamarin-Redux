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
 * Portions created by the Initial Developer are Copyright (C) 2005-2006
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

    var SECTION = "15.3.5-2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "Properties of Function Instances";

    writeHeaderToLog( SECTION + " "+TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array:Array= new Array();
    var item:Number= 0;
        
    var thisError:String="no error";
    try{
        var MyObject = new Function( 'a', 'b', 'c', 'this.a = a; this.b = b; this.c = c; this.value = a+b+c; this.valueOf = new Function( "return this.value" )' );

    }catch(e:Error){
        thisError=(e.toString()).substring(0,22);
    }finally{
        array[item++] = new TestCase( SECTION,"Function('function body') not supported","EvalError: Error #1066",thisError);
    }

  

    var MyObject = function() {
         this.a = a;
         this.b = b;
         this.c = c;
         this.value = a+b+c;
         this.valueOf = function(){ return this.value}
    }

    array[item++] = new TestCase( SECTION, "MyObject.length",                       0,          MyObject.length );
    array[item++] = new TestCase( SECTION, "typeof MyObject.prototype",             "object",   typeof MyObject.prototype );
    array[item++] = new TestCase( SECTION, "typeof MyObject.prototype.constructor", "function", typeof MyObject.prototype.constructor );
    //not supported anymore
    //array[item++] = new TestCase( SECTION, "MyObject.arguments",null,       MyObject.arguments );

    return ( array );
}
