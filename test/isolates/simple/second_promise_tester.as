import avmplus.System;
import avmplus.File;
import flash.utils.ByteArray;
import flash.system.Worker;
import flash.system.Promise;
import flash.system.WorkerDomain;

function makeCode(name) {
    return File.readByteArray(name);
}

var blob = makeCode("third_promise_tester.abc");
var p = WorkerDomain.current.createWorkerFromByteArray(blob);
var promise:Promise = p.start();

function testWrappedPassing(wrappedPromise:Promise) {
    var printWrappedResult:Promise = promise.printWrapped(wrappedPromise);
    printWrappedResult.local::receive(); // wait for completion
    p.stop();
}
