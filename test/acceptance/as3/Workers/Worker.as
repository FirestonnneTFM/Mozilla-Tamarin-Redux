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
    import flash.system.Worker
    import flash.system.Promise
    import flash.system.WorkerDomain
    import flash.system.WorkerState;

    var w:Worker=Worker.current;
    var str:String=w.toString();
    var SECTION = "concurrency";
    var VERSION = "AS3";
    var TITLE   = "Test Worker api";
    
    startTest();

    // tests for main worker
    if (w.isPrimordial) {
        writeHeaderToLog( SECTION + " "+ TITLE);

        var nullWorker:Worker;

        var unstartedWorker:Worker=WorkerDomain.current.createWorkerFromPrimordial();
        AddTestCase("worker test main worker isParentOf child worker",w.isParentOf(unstartedWorker),true);
        AddTestCase("worker test child worker isParentOf main worker",unstartedWorker.isParentOf(w),false);

        var error:String = "NO ERROR";
        try {
            w.isParentOf(nullWorker);
        } catch (e) {
            error=e.toString();
        }
        AddTestCase("worker test main worker isParentOf null worker throws error", false, error=="NO ERROR");

        // Worker constructor cannot be called directly
        var exception1:String="no exception";
        try {
            new Worker();
        } catch (e) {
            exception1=e.toString();
        }
        AddTestCase("worker throws exception if constructor called directly", "ArgumentError: Error #2012",removeExceptionDetail(exception1));

        // toString returns a String
        AddTestCase("main worker: toString()","[object Worker]",w.toString());

        // isPrimordial is true for main worker
        AddTestCase("main worker: isPrimordial",true,w.isPrimordial);

        // state of main worker is running
        AddTestCase("main worker: state is RUNNING",WorkerState.RUNNING,w.state);

        // create Worker From Primordial returns a worker
        var wchild=WorkerDomain.current.createWorkerFromPrimordial();
        
        var workerxml:XML=describeType(Worker.current,FLASH10_FLAGS);
        AddTestCase("worker class is flash.system::Worker","flash.system::Worker",workerxml.@name.toString());
        AddTestCase("worker class is not dynamic","false",workerxml.@isDynamic.toString());
        AddTestCase("worker class is final","true",workerxml.@isFinal.toString());
        AddTestCase("worker class is not static","false",workerxml.@isStatic.toString());
        AddTestCase("worker class NEW is defined",true,WorkerState.NEW == "new");
        AddTestCase("worker class STARTING is defined",true,WorkerState.STARTING == "starting");
        AddTestCase("worker class RUNNING is defined",true,WorkerState.RUNNING == "running");
        AddTestCase("worker class FINISHING is defined",true,WorkerState.FINISHING == "finishing");
        AddTestCase("worker class STOPPED is defined",true,WorkerState.STOPPED == "stopped");
        AddTestCase("worker class FAILED is defined",true,WorkerState.FAILED == "failed");
        AddTestCase("worker class ABORTED is defined",true,WorkerState.ABORTED == "aborted");
        AddTestCase("worker class EXCEPTION is defined",true,WorkerState.EXCEPTION == "exception");
        
        // test equality main==main  main!=background
        AddTestCase("main worker is not equal child worker",false,Worker.current == wchild);

        // test equality main==null background
        AddTestCase("main worker is not equal to null worker", false, w == nullWorker);

        // after start state is STARTING or RUNNING
        var promise:Promise=wchild.start();
        AddTestCase("child worker: state is 'starting' or 'running' (2 or 3) is "+w.state,true,w.state==WorkerState.STARTING||w.state==WorkerState.RUNNING);

        // after stop state is STOPPED
        System.sleep(250); 
        // FIXME: stop() may kill the background worker before it finishes running its tests, the sleep above tries to reduce the likelihood of that.
        wchild.stop(); 
        AddTestCase("child worker: after stop() state is 'stopped'",WorkerState.STOPPED,wchild.state);

        test();

    // tests for background worker
    } else {
        // toString of background worker
        AddTestCase("child worker: toString()","[object Worker]",w.toString());

        // isPrimoridial is false
        AddTestCase("child worker: isPrimordial",false,w.isPrimordial);

        // the worker may not be finished yet, undetermined state
        System.sleep(50);
        AddTestCase("child worker: state is "+w.state,true,w.state==WorkerState.FINISHING||w.state==WorkerState.RUNNING);
        test();
    }
}
