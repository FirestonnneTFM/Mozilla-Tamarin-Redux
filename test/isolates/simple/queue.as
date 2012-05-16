package{

import avmplus.System;
import flash.utils.ByteArray;
import flash.system.Worker;
import flash.system.Promise;
import flash.system.WorkerDomain;
import avmplus.File;


function makeCode(name) {
    return File.readByteArray(name);
}

if (Worker.current.isPrimordial) {

    var p = WorkerDomain.current.createWorkerFromPrimordial();
    var q:Promise = p.start();

    var blob;

    blob = makeCode("consumer.abc");
    var consumer = WorkerDomain.current.createWorkerFromByteArray(blob);
    var consumerPromise:Promise = consumer.start();

    var res:Promise = consumerPromise.async.retrieve(q);

    System.sleep(1000);

    blob = makeCode("producer.abc");
    var producer = WorkerDomain.current.createWorkerFromByteArray(blob);
    var producerPromise:Promise = producer.start();
       
    producerPromise.async.insert(q);

    res.receive(); // wait for completion
        
    producer.stop();
    consumer.stop();
    p.stop();
 }
 else {
     
     public function foo() {
	 print("BLAH");	 
     }
     
     var buffer:Vector.<int> = new Vector.<int>(0);
     var locks:Vector.<Promise> = new Vector.<Promise>(0);
     
     public function enqueue(el:int):void {
	 if (locks.length > 0) {
	     var lock = locks.pop();
	     lock.resolve(el);
	 }
	 else {
	     buffer.push(el);
	 }
     }
	 
	 public function dequeue():int {
	     if (buffer.length == 0) {
		 var lock = Promise.empty();
		 locks.push(lock);
		 var res:int = lock.receive();
		 print("DEQUEUED AFTER EMPTY");
		 return res;
	     }
	     else {
		 return buffer.pop();
	     }
	 }
 }

}