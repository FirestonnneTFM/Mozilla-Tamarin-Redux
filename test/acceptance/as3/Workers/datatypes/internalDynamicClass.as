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

import flash.net.registerClassAlias
import flash.system.Promise
import flash.system.Worker
import flash.system.WorkerDomain

internal dynamic class InternalDynamicClass {

    // note public needed, otherwise AMF3 won't preserve.
    public var array:Array;                            // Default property
    static var statFunction:Function;           // Default Static property
    var finNumber:Number;                   // Default Final property
    static var finStatNumber:Number;        // Default Final Static property
    
    internal var internalArray:Array;                           // Internal property
    internal static var internalStatFunction:Function;          // Internal Static property
    internal var internalFinNumber:Number;              // Internal Final property
    internal static var internalFinStatNumber:Number;       // Internal Final Static property

    private var privDate:Date;                              // Private property
    private static var privStatString:String;               // Private Static property
    private var privFinalString:String;             // Private Final property
    private static var privFinalStaticString:String // Private Final Static property

    public var pubBoolean:Boolean;                      // Public property
    public static var pubStatObject:Object;             // Public Static property
    public var pubFinArray:Array;                   // Public Final property
    public static var pubFinalStaticNumber:Number   // Public Final Static property


    // *****************
    // Default methods
    // *****************
    function getArray() : Array { return array; }
    function setArray( a:Array ) { array = a; }
    
    
    // ************************
    // Default virtual methods
    // ************************
    virtual function getVirtualArray() : Array { return array; }
    virtual function setVirtualArray( a:Array ) { array = a; }
    
    
    // ***********************
    // Default Static methods
    // ***********************
    static function setStatFunction(f:Function) { statFunction = f; }
    static function getStatFunction() : Function { return statFunction; }

    
    // **********************
    // Default Final methods
    // **********************
    final function setFinNumber(n:Number) { finNumber = n; }
    final function getFinNumber() : Number { return finNumber; }

    
    // *****************
    // Internal methods
    // *****************
    internal function getInternalArray() : Array { return internalArray; }
    internal function setInternalArray( a:Array ) { internalArray = a; }
    
    
    // *************************
    // Internal virtual methods
    // *************************
    internal virtual function getInternalVirtualArray() : Array { return internalArray; }
    internal virtual function setInternalVirtualArray( a:Array ) { internalArray = a; }
    
    
    // ***********************
    // Internal Static methods
    // ***********************
    internal static function setInternalStatFunction(f:Function) { InternalDynamicClass.internalStatFunction = f; }
    internal static function getInternalStatFunction() : Function { return InternalDynamicClass.internalStatFunction; }
    
    
    // **********************
    // Internal Final methods
    // **********************
    internal final function setInternalFinNumber(n:Number) { internalFinNumber = n; }
    internal final function getInternalFinNumber() : Number { return internalFinNumber; }
    
    
    // *******************
    // Private methods
    // *******************
    private function getPrivDate() : Date { return privDate; }
    private function setPrivDate( d:Date ) { privDate = d; }
    // wrapper function
    public function testGetSetPrivDate(d:Date) : Date {
        setPrivDate(d);
        return getPrivDate();
    }
    
    
    // *******************
    // Private virutal methods
    // *******************
    private virtual function getPrivVirtualDate() : Date { return privDate; }
    private virtual function setPrivVirtualDate( d:Date ) { privDate = d; }
    // wrapper function
    public function testGetSetPrivVirtualDate(d:Date) : Date {
        setPrivVirtualDate(d);
        return getPrivVirtualDate();
    }


    // **************************
    // Private Static methods
    // **************************
    private static function setPrivStatString(s:String) { privStatString = s; }
    private static function getPrivStatString() : String { return privStatString; }
    // wrapper function
    public function testGetSetPrivStatString(s:String) : String {
        setPrivStatString(s);
        return getPrivStatString();
    }
    
    
    // **************************
    // Private Final methods
    // **************************
    private final function setPrivFinalString(s:String) { privFinalString = s; }
    private final function getPrivFinalString() : String { return privFinalString; }
    // wrapper function
    public function testGetSetPrivFinalString(s:String) : String {
        setPrivFinalString(s);
        return getPrivFinalString();
    }
    
    
    // *******************
    // Public methods
    // *******************
    public function setPubBoolean( b:Boolean ) { pubBoolean = b; }
    public function getPubBoolean() : Boolean { return pubBoolean; }
    
    
    // *******************
    // Public virtual methods
    // *******************
    public virtual function setPubVirtualBoolean( b:Boolean ) { pubBoolean = b; }
    public virtual function getPubVirtualBoolean() : Boolean { return pubBoolean; }


    // **************************
    // Public Static methods
    // **************************
    public static function setPubStatObject(o:Object) { InternalDynamicClass.pubStatObject = o; }
    public static function getPubStatObject() : Object { return InternalDynamicClass.pubStatObject; }


    // *******************
    // Public Final methods
    // *******************
    public final function setPubFinArray(a:Array) { pubFinArray = a; }
    public final function getPubFinArray() : Array { return pubFinArray; }
}

registerClassAlias('com.adobe.tamarin.internaldynamicclas', InternalDynamicClass);

if (Worker.current.isPrimordial) {
    // Root Worker
    
    var SECTION = "concurrency";
    var VERSION = "AS3";
    var TITLE   = "Test message passing of internal dynamic class.";
    
    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);
    
    // Test passing different object back and forth
    // echoObject will print the object and return it
    function testEchoedObject(obj, result, desc = undefined, type = undefined,
                              comparisonFunc = undefined) {
        if (desc == undefined) {
            desc = obj.toString();
        }
        
        if (comparisonFunc != undefined) {
            AddTestCase(desc, true, comparisonFunc(result));
            return;
        }
        
        if (type == undefined) {
            AddTestCase(desc, obj, result);
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
    }
    
    
    var w:Worker = WorkerDomain.current.createWorkerFromPrimordial();
    var promise:Promise = w.start();
    
    function getEchoedObject(obj) {
        var echo_object_promise:Promise = promise.async.echoObject(obj);
        var result;
        try {
            result = echo_object_promise.receive();
        } catch (exception) {
            result = exception.toString();
        }
        return result;
    }
    
    var idc:InternalDynamicClass = new InternalDynamicClass();
    var arr:Array = [3,4,5,,,,,,,,,,,"hello",,,,,,89];
    idc.setArray(arr);
    
    
    var echoedClass = getEchoedObject(idc);
    
    AddTestCase("echoedClass is InternalDynamicClass", true,
                echoedClass is InternalDynamicClass);
    testEchoedObject(idc.array, echoedClass.array, "echoed array", Array);
    testEchoedObject(idc.array, echoedClass.getArray(), "echoed array via method", Array);
    
    
    
    test();
    w.terminate();
} else {
    // worker
    public function echoObject(o) {
        return o;
    }
    
}
    
}