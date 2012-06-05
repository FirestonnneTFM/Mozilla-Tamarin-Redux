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

import flash.system.Worker;
import flash.system.Promise;
import flash.system.WorkerDomain;
import flash.net.registerClassAlias;

public class MyClass {
    var ref_to_class:Class;
    var instance_self:MyClass;
    var circularRefObj:Object;
    
    public function MyClass() {
        instance_self = this;
        ref_to_class = MyClass;
        circularRefObj = new Object();
        circularRefObj.self = circularRefObj;
        circularRefObj.aProp = new Object();
        circularRefObj.aProp.parent = circularRefObj;
        circularRefObj.aDouble = Math.PI;
        circularRefObj.aProp.class_instance_ref = this;
    }
}

registerClassAlias('com.adobe.MyClass', MyClass);

if (Worker.current.isPrimordial) {
    // Root Worker
    
    var SECTION = "concurrency";
    var VERSION = "AS3";
    var TITLE   = "Test message passing of object with circular reference";
    
    startTest();
    writeHeaderToLog( SECTION + " "+ TITLE);
    
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
    
    var circularRefObj = new Object();
    circularRefObj.self = circularRefObj;
    circularRefObj.aProp = new Object();
    circularRefObj.aProp.parent = circularRefObj;
    circularRefObj.aDouble = Math.PI;
    circularRefObj.aProp.aStr = 'This space intentionally left blank';
    
    var echoed = getEchoedObject(circularRefObj);
    
    AddTestCase("Object equals itself", true, circularRefObj === circularRefObj);
    AddTestCase("Objects self reference", true, circularRefObj === circularRefObj.self);
    
    AddTestCase("Echoed aDouble", Math.PI, echoed.aDouble);
    AddTestCase("Nested string property", 'This space intentionally left blank',
                echoed.aProp.aStr);
    AddTestCase("Nested reference to self", 'This space intentionally left blank',
                echoed.aProp.parent.aProp.aStr)
    
    AddTestCase("Echoed object reference to self", true, echoed === echoed.self);
    AddTestCase("Echoed object nested ref to self", true, echoed === echoed.aProp.parent);
    AddTestCase("Echoed object nested ref to self", true, echoed === echoed.self.aProp.parent);
    
    var myclass:MyClass = new MyClass();
    var echoedMyClass:MyClass = getEchoedObject(myclass);
    AddTestCase("echoedMyClass is MyClass", true, echoedMyClass is MyClass);
    
    AddTestCase("Local class reference to parent class", true,
                MyClass === myclass.ref_to_class);
    
    // TODO: As currently designed, AMF does not support passing Class objects
    //AddTestCase("Echoed class reference to parent class", true,
    //            MyClass === echoedMyClass.ref_to_class);
    //AddTestCase("String Representation of echoed class reference to parent class",
    //            "[class MyClass]", echoedMyClass.ref_to_class.toString());
    //
    //AddTestCase("Echoed class object references to self", true,
    //            echoedMyClass === echoedMyClass.instance_self);
    
    AddTestCase("echoedMyClass.circularRefObj === echoedMyClass.circularRefObj.self",
                true, echoedMyClass.circularRefObj === echoedMyClass.circularRefObj.self);
    AddTestCase("echoedMyClass.circularRefObj === echoedMyClass.circularRefObj.aProp.parent",
                true, echoedMyClass.circularRefObj === echoedMyClass.circularRefObj.aProp.parent);
    AddTestCase("echoedMyClass.circularRefObj === echoedMyClass.circularRefObj.self.aProp.parent",
                true, echoedMyClass.circularRefObj === echoedMyClass.circularRefObj.self.aProp.parent);
    AddTestCase("echoedMyClass.instance_self.circularRefObj === echoedMyClass.circularRefObj.self",
                true, echoedMyClass.instance_self.circularRefObj === echoedMyClass.circularRefObj.self);
    
    AddTestCase("echoedMyClass === echoedMyClass.circularRefObj.aProp.class_instance_ref",
                true, echoedMyClass === echoedMyClass.circularRefObj.aProp.class_instance_ref);
    
    test();
    w.terminate();
} else {
    // worker
    public function echoObject(o) {
        return o;
    }
    
}

}