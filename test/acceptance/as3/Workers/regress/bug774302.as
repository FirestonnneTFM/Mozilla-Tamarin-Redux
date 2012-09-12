/* This Source Code Form is subject to the terms of the Mozilla Public
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
   
 package {
    import flash.system.Worker
    import flash.system.WorkerDomain
 
    if (Worker.current.isPrimordial) {
        var SECTION = "workers";
        var VERSION = "as3";
        var TITLE   = "regression test bz:774302";
        startTest();
        writeHeaderToLog(SECTION+" "+TITLE);

        var w:Worker=WorkerDomain.current.createWorkerFromPrimordial();
        var exception:String="no exception";
        w.start();
        try {
            w.start();
        } catch (e) {
            exception=e;
        }
        w.terminate();
        AddTestCase("test correct exception is thrown","Error: Error #1511",removeExceptionDetail(exception));
        test();
    } else {
        trace("started background worker");
    }
}    