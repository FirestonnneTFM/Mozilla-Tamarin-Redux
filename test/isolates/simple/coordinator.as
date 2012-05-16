package {

import avmplus.System;
import avmplus.File;
import flash.utils.ByteArray;
import flash.system.Worker;
import flash.system.Promise;
import flash.system.WorkerDomain;

function makeCode(name) {
    return File.readByteArray(name);
}

var blob = makeCode("dispatcher.abc");
var w:Worker = WorkerDomain.current.createWorkerFromByteArray(blob);

var promise:Promise = w.start();

var NUM_WORKERS:int = 10;
var NUM_INVOCATIONS:int = 20;

var lock:Promise = Promise.empty();

promise.async.dispatch(NUM_WORKERS, NUM_INVOCATIONS, lock);
lock.receive();
w.stop();

}
