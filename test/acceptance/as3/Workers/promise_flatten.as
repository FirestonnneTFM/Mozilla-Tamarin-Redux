package {

import avmplus.System;
import avmplus.File;
import flash.utils.ByteArray;
import flash.system.Worker;
import flash.system.Promise;
import flash.system.WorkerDomain;

var SECTION = "wokers";
var VERSION = "AS3";
var TITLE   = "Test Promise api.";

writeHeaderToLog( SECTION + " "+ TITLE);
startTest();

if (Worker.current.isPrimordial) {
  
  var w1 = WorkerDomain.current.createWorkerFromPrimordial();
  var promise1:Promise = w1.start();

  var p:Promise = Promise.wrap("BAR");
  var rec:Promise = Promise.wrap(p);
  AddTestCase("(RECURSIVE WRAP) BAR? ", "BAR", rec.receive());
  promise1.async.installWrap(p).receive(); // wait until done
  var res1:Promise = promise1.async.promiseWrapVar;
  AddTestCase("BAR? ", "BAR", res1.async.bar().receive());
  var res2:Promise = promise1.async.promiseWorkerVar;
  AddTestCase("BAZ? ", "BAZ", res2.async.baz().receive());
  try {
    var res_ex:Promise = promise1.async.parentsWrap;
    res_ex.receive();
  } catch (ex) {
    AddTestCase("EXCEPTION RETHROWN? ", "promises representing objects of a given worker cannot be returned to the same worker", ex.toString());
  }
  
  var res3:Promise = promise1.async.promiseWrapFn();
  AddTestCase("BAR? ", "BAR", res3.async.bar().receive());
  var res4:Promise = promise1.async.promiseWorkerFn();
  AddTestCase("BAZ? ", "BAZ", res4.async.baz().receive());

  var lock:Promise = Promise.empty();

  var counter:int = 0;
/*
  function promiseWrapHandlerP(p:Promise) {
    AddTestCase("(ASYNC) BAR? ", "BAR", p.async.bar().receive());
    counter++;
    if (counter == 2) {
      promise1.async.stopChild().receive();
      w1.stop();
      lock.resolve("UNLOCK");
    }
  }

  function promiseWorkerHandlerP(p:Promise) {
    AddTestCase("(ASYNC) BAZ? ", "BAZ", p.async.baz().receive());
    counter++;
    if (counter == 2) {
      promise1.async.stopChild().receive();
      w1.stop();      
      lock.resolve("UNLOCK");
    }
  }
*/
  function promiseWrapHandler(ignoreResult) {
    AddTestCase("(ASYNC) BAR? ", "BAR", res5.async.bar().receive());
    counter++;
    if (counter == 2) {
      promise1.async.stopChild().receive();
      w1.stop();
      lock.resolve("UNLOCK");
    }
  }

  function promiseWorkerHandler(ignoreResult) {
    AddTestCase("(ASYNC) BAZ? ", "BAZ", res6.async.baz().receive());
    counter++;
    if (counter == 2) {
      promise1.async.stopChild().receive();
      w1.stop();      
      lock.resolve("UNLOCK");
    }
  }

  var res5:Promise = promise1.async.promiseWrapFn();
  res5.when(promiseWrapHandler);
  var res6:Promise = promise1.async.promiseWorkerFn();
  res6.when(promiseWorkerHandler);

  lock.receive();

  test();
 }
 else {
   
   function makeCode(name) {
     return File.readByteArray(name);
   }

   var parentsWrap:Promise;

   public function installWrap(p:Promise) {
     parentsWrap = p;
   }

   var blob:ByteArray = makeCode("as3/Workers/promise_flatten_support/client.abc");
   var w2 = WorkerDomain.current.createWorkerFromByteArray(blob);
   var promise2:Promise = w2.start();

   public function stopChild() {
     w2.stop();
   }

   function fbar() {
     return "BAR";
   }

   public var o = {bar:fbar};

   public var promiseWrapVar:Promise = Promise.wrap(o);
   public var promiseWorkerVar:Promise = promise2.async.o;
   
   public function promiseWrapFn():Promise {
     return Promise.wrap(o);
   }
     
   public function promiseWorkerFn():Promise {
     return promise2.async.o;
   }

 }

}