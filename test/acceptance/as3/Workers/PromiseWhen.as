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

    import flash.system.*

    var SECTION = "concurrency";
    var VERSION = "AS3";
    var TITLE   = "Test Promise when method";
    if (Worker.current.isPrimordial) {
        startTest();
        var result=null;
        var errorResult=null;
        function callback(receivedResult) {
	    result=receivedResult;
            print("result is "+result);
        }
        function errorResultHandler(receivedResult) {
            errorResult=receivedResult;
        }
        function errorFaultHandler(receivedResult) {
            errorResult=receivedResult;
        }
        var w:Worker=WorkerDomain.current.createWorkerFromPrimordial();
        var p:Promise=w.start();
        var p1:Promise=p.async.test1();
        p1.when(callback);
       
        var p2:Promise=p.async.generateError();
        p2.when(errorResultHandler,errorFaultHandler);

        var p3:Promise=p.async.test1();
        var result3:String=p3.receive();
        try {
             p2.receive();
        } catch (e) {
             //print("got error");
        }
        AddTestCase("Promise when confirm when callback returns correct value","test1",result);
        AddTestCase("Promise receive after when returns correct value","test1",result3);
        AddTestCase("Promise faultHandler returns thrown error","Error: thrown error",errorResult.toString());
        test();
        w.terminate();

    } else {
        public function test1() {
            return "test1";
        }
        public function generateError() {
            throw new Error("thrown error");
        }
    }

}