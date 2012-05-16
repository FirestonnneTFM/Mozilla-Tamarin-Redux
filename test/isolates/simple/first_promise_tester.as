import avmplus.System;
import avmplus.File;
import flash.utils.ByteArray;
import flash.system.Worker;
import flash.system.Promise;
import flash.system.WorkerDomain;

function makeCode(name) {
    return File.readByteArray(name);
}

var blob = makeCode("second_promise_tester.abc");
var p = WorkerDomain.current.createWorkerFromByteArray(blob);
var promise:Promise = p.start();

function startTest() {
  var wrappedPromise:Promise = Promise.wrap("BLAH");
  
  var wrappedPassingResult:Promise = promise.testWrappedPassing(wrappedPromise);
  wrappedPassingResult.local::receive(); // wait for completion
  p.stop();
}
