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

    import flash.system.Worker
    import flash.system.Promise
    import flash.system.PromiseState
    import flash.system.WorkerDomain

    var worker:Worker=Worker.current;
    var str:String=worker.toString();
    var SECTION = "wokers";
    var VERSION = "AS3";
    var TITLE   = "Test Promise api.";

    startTest();
    if (worker.isPrimordial) {
    
        writeHeaderToLog( SECTION + " "+ TITLE);

        var exception1:String="no exception";
        try {
            new Promise();
        } catch (e) {
            exception1=e.toString();
        }

        AddTestCase("cannot call Promise constructor directly", "ArgumentError: Error #2012", removeExceptionDetail(exception1));

        var bckworker=WorkerDomain.current.createWorkerFromPrimordial();
        var promise:Promise=bckworker.start();
    
        AddTestCase("Promise state after worker is started",PromiseState.NEW,promise.state);    

        var stringPromise:Promise=promise.async.sendString();
        var result1=stringPromise.receive();

        AddTestCase("Promise remotecall and resolve on simple function","[test string]",result1);    

        var echoPromise:Promise=promise.async.echo("[echo string]");

        AddTestCase("Promise state before resolved",PromiseState.NEW,echoPromise.state);

        var result2=echoPromise.receive();

        AddTestCase("Promise remotecall and resolve on simple function with parameter","[echo string]",result2);    
        AddTestCase("Promise state after resolved",PromiseState.RECEIVED,echoPromise.state);

        var msg2="no exception";
        var errorPromise:Promise=promise.async.exception();
        try {
            var result3=errorPromise.receive();
        } catch(e) {
            msg2=e.toString();
        }
        // expecting EXCEPTION/6
        AddTestCase("Promise state after exception",PromiseState.BROKEN,errorPromise.state);

        test();

        bckworker.terminate();

    } else {
        public function sendString() {
            return "[test string]";
        }
        public function echo(o:Object):Object {
            return o;
        }
        public function exception() {
            throw new Error("error");
        }
    }
} // end package