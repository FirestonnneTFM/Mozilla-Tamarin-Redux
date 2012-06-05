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

import avmplus.System;
import avmplus.File;
import flash.utils.ByteArray;
import flash.system.Worker;
import flash.system.Promise;
import flash.system.WorkerDomain;
import flash.net.registerClassAlias;


// Root Worker
class MyClass {
    var a:int;
    var b:Vector.<Number> = Vector.<Number>([Math.PI, 45.45,0.0001]);
    
    public function MyClass() {
        a = 123456;
    }
}

registerClassAlias('com.adobe.MyClass', MyClass);

function makeCode(name) {
    return File.readByteArray(name);
}


var SECTION = "concurrency";
var VERSION = "AS3";
var TITLE   = "Test message passing of class that does not have same properties defined in the child worker";

startTest();
writeHeaderToLog( SECTION + " "+ TITLE);


var blob = makeCode('as3/Workers/datatypes/class_different_child_definition_support/child_worker.abc');
var w:Worker = WorkerDomain.current.createWorkerFromByteArray(blob);
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

var mc:MyClass = new MyClass();
print(typeof(mc));
var echoedObj = getEchoedObject(mc);
// the following test is expected to pass
//AddTestCase("mc.a", 123456, mc.a);

// the following tests are unexpected passes
/*
AddTestCase("echoedObj is MyClass", true, echoedObj is MyClass);
AddTestCase("echoedObj.a", 123456, echoedObj.a);
AddTestCase("echoedObj.b[0]", Math.PI, echoedObj.b[0]);
AddTestCase("echoedObj.b[1]", 45.45, echoedObj.b[1]);
AddTestCase("echoedObj.b[2]", 0.0001, echoedObj.b[2]);
//AddTestCase("echoedObj.c", "c string", echoedObj.c);
*/

// the following test is an expected failure
AddTestCase("echoedObj is MyClass", false, echoedObj is MyClass);

test();
w.terminate();

}
