/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
 
package {

    import flash.system.Worker;
    import flash.system.WorkerDomain;
    import avmplus.System;

    if (Worker.current.isPrimordial) {
        var SECTION = "Workers";
        var VERSION = "as3";
        var TITLE   = "test Worker api";
        startTest();
        writeHeaderToLog(SECTION+" "+TITLE);

        AddTestCase("test main worker is primordial",true,Worker.current.isPrimordial);

    // test Worker constructor throws exception and does not create a worker
        var constr_worker:Worker=null;
        var constr_worker_exc:String="";
        try {
            constr_worker=new Worker();
        } catch (e) {
            constr_worker_exc=e.toString();
        }
        AddTestCase("test cannot use Worker Constructor, does not create worker",null,constr_worker);
        AddTestCase("test cannot use Worker Constructor, throws exception","ArgumentError: Error #2012",constr_worker_exc.substring(0,"ArgumentError: Error #2012".length));

    // test background worker is not primordial
        var bck_worker:Worker=WorkerDomain.current.createWorkerFromPrimordial();
        AddTestCase("test background worker is NOT primordial",false,bck_worker.isPrimordial);

    // test worker state
        AddTestCase("test main worker state is running","running",Worker.current.state);
        AddTestCase("test background worker state is new","new",bck_worker.state);
        bck_worker.start();
	    AddTestCase("test after start on background worker state is running","new",bck_worker.state);
        bck_worker.terminate();
        var start:uint=getTimer();
        while (bck_worker.state!="terminated") {
            System.sleep(10);
            if (getTimer()-start>2000) break;
        }
        print("done after "+(getTimer()-start));
	    AddTestCase("test after stop on background worker state is terminated","terminated",bck_worker.state);
        test();
    } else {
        trace("in background worker");
    }
}
