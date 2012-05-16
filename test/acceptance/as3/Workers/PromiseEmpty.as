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
import flash.utils.ByteArray;
import flash.system.Worker;
import flash.system.Promise;
import flash.system.WorkerDomain;


var result1:String='unknown';
var result2:String='unknown';

if (Worker.current.isPrimordial) {
  
    var SECTION = "workers";
    var VERSION = "AS3";
    var TITLE   = "Test Empty Promise";
    startTest();

    var worker = WorkerDomain.current.createWorkerFromPrimordial();
    var promise:Promise = worker.start();
    var empty_sync:Promise = Promise.empty();    
    var empty_async:Promise = Promise.empty();
    promise.async.foo(empty_async, "UNSYNCH");

    resultSync = "NONE";

    /*
    function handlerP(e_a:Promise) {
        result1=e_a.receive();
        promise.async.foo(empty_sync, "SYNCH");
    }
    */

    function handler(receivedResult) {
	result1=receivedResult;
        promise.async.foo(empty_sync, "SYNCH");
    }

    empty_async.when(handler);

    result2 = empty_sync.receive();
   
    var exception:String="no exception";
    try {
      empty_sync.resolve("DUMMY");
    } catch (ex) {
      exception=ex.toString();
    }
    AddTestCase("Test Unsync empty promise","UNSYNCH",result1);
    AddTestCase("Test Sync empty promise","SYNCH",result2);
    AddTestCase("Test closed empty promise error","an explicitly unresolved promise can be resolved only once",exception);
    worker.stop();
    test();

 } else {
    public function foo(e:Promise, s:String) {
         e.resolve(s);
     }
 }

}
    