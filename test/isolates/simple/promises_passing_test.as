import avmplus.System;
import avmplus.File;
import flash.utils.ByteArray;
import flash.system.Worker;
import flash.system.Promise;
import flash.system.WorkerDomain;


function makeCode(name) {
    return File.readByteArray(name);
}

var blob = makeCode("first_promise_tester.abc");
var p = WorkerDomain.current.createWorkerFromByteArray(blob);
var promise:Promise = p.start();


var startTestResult:Promise = promise.startTest();
startTestResult.local::receive(); // wait for completion

p.stop();
