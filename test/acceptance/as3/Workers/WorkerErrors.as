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

    if (Worker.current.isPrimordial) {
        var SECTION = "concurrency";
        var VERSION = "AS3";
        var TITLE   = "Test Worker errors.";
        startTest();
        writeHeaderToLog( SECTION + " "+ TITLE);

        // start a worker twice
        var worker1:Worker=WorkerDomain.current.createWorkerFromPrimordial();
        var promise1:Promise=worker1.start();
        var exception1:String="no exception";
        try {
            worker1.start();
        } catch (e) {
            exception1=e.toString();
        }
        AddTestCase("exception is thrown when starting a worker already started","Error: Worker already started",exception1);


        // stop a worker not started
        var worker2:Worker=WorkerDomain.current.createWorkerFromPrimordial();
        var code2:Boolean= worker2.terminate();
        AddTestCase("worker terminate returns false if worker not started",false,code2);
        
        // promise receive on a global promise
        var result1=promise1.receive();
        AddTestCase("when a global promise receive is called null is returned",null,result1);
        {
            //use namespace async;
            var promise2:Promise=promise1.async.echo("test");
            promise2.receive();
            var result2=promise2.receive();
            AddTestCase("when a promise receive is called twice returns result","test",result2);
        }
        test();
        worker1.terminate();
    } else {
        public function echo(o:Object):Object {
            return o;
        }
    }
}