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

    import avmplus.*
    import flash.util.*
    import flash.system.*

    var w:Worker=Worker.current;
    var str:String=w.toString();
    var SECTION = "concurrency";
    var VERSION = "AS3";
    var TITLE   = "Test WorkerDomain createWorker api.";
    

    if (Worker.current.isPrimordial) {
        startTest();
        writeHeaderToLog( SECTION + " "+ TITLE);

        var worker1:Worker=WorkerDomain.current.createWorkerFromByteArray(File.readByteArray("as3/Workers/WorkerDomainCreateWorker_support/BackgroundWorker.abc"));
    var promise1:Promise=worker1.start();

        var worker2:Worker=WorkerDomain.current.createWorkerFromByteArray(null);
        var promise2:Promise=worker2.start();

        {
            //use namespace async;
            var promise1res:Promise=promise1.async.testMethod();
            var promise2res:Promise=promise2.async.testMethod();
            
            var res1:String=promise1res.receive();
            var res2:String=promise2res.receive();
            
            AddTestCase("WorkerDomain createWorkerFromByteArray loads a worker from an external file",res1,"in BackgroundWorker.as");
            AddTestCase("WorkerDomain createWorkerFromByteArray loads a worker from the same class when the bytearray is null",res2,"in WorkerDomainCreateWorker.as");
        }

        worker1.terminate();
        worker2.terminate();

        test();
    } else {
        public function testMethod():String {
            return "in WorkerDomainCreateWorker.as";
        }
    }
} // end package