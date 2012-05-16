import avmplus.*
import flash.system.Worker;
import flash.system.Promise;
import flash.system.WorkerDomain;

var prefix="../../"

var counter:int=0;
function runtest(test:String, promise_slot:int):int {
  var start:int=getTimer();  
  print("*** starting worker: "+promise_slot+" count: "+counter+" test: "+test);
  var fulltest=prefix+test;
  counter++;
  try {
      Domain.currentDomain.load(fulltest);
  } catch (e) {
      print("uncaught exception: "+e);
  }
  print("*** finished worker: "+promise_slot+" count: "+counter+" time: "+(getTimer()-start)+" test: "+test);
  return promise_slot;
}
