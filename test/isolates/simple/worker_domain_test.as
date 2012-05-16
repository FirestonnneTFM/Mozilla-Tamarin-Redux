import avmplus.System;
import avmplus.File;
import flash.utils.ByteArray;
import flash.system.Worker;
import flash.system.Promise;
import flash.system.WorkerDomain;


function remoteEcho(s:String) {
    return s;
}

if (Worker.current.isPrimordial()) {

    function makeCode(name) {
	return File.readByteArray(name);
    }
    
    var blob = makeCode("worker_domain_test.abc");
    var w:Worker; 
    try {
	w = new Worker();
	
    }
    catch (exception) {
	print("MAIN: EXCEPTION WHILE TRYING TO USE WORKER'S CONSTRUCTOR:\n\t"+exception);
    }
    
    var promise:Promise;
    var echoPromise:Promise;
    
    
    w = WorkerDomain.current.createWorkerFromByteArray(blob);
    promise = w.start();
    echoPromise = promise.remoteEcho("echo1");
    print("(MAIN DOMAIN - FROM BYTE ARRAY) RETURNED ECHO: "+echoPromise.local::receive());
    w.stop();
    
    w = WorkerDomain.current.createWorkerFromPrimordial();
    promise = w.start();
    echoPromise = promise.remoteEcho("echo2");
    print("(MAIN DOMAIN - FROM MAIN) RETURNED ECHO: "+echoPromise.local::receive());
    w.stop();

    var workerDomain:WorkerDomain = new WorkerDomain();
    w = workerDomain.createWorkerFromByteArray(blob);
    promise = w.start();
    echoPromise = promise.remoteEcho("echo3");
    print("(NEW DOMAIN - FROM BYTE ARRAY) RETURNED ECHO: "+echoPromise.local::receive());
    w.stop();
 }

