import avmplus.System;
import avmplus.File;
import flash.system.Promise;
import flash.system.Worker;
import flash.system.WorkerDomain;

var w:Worker = WorkerDomain.current.createWorkerFromByteArray(File.readByteArray("dispatcher.abc"));
var promise:Promise = w.start();

var nWorkers:int = 1;
var testfile:String = 'alltests.txt';

if (System.argv.length>0) {
    try {
        nWorkers=int(System.argv[0]);
    } catch (e) {
        print("Error: parsing '"+System.argv[0]+"' to int, to set the number of workers.");
        System.exit(1);
    }
}
if (System.argv.length>1) {
   testfile=System.argv[1];
}

if (nWorkers<1) {
    print("Error: number of workers must be >0, currently set to: "+nWorkers);
    System.exit(1);
}

var tests=File.read(testfile).split('\n')
while (tests[tests.length-1]=='') {
      tests.pop()
}
nTests=tests.length;
print("starting "+nTests+" on "+nWorkers+" workers");
promise.dispatch(nWorkers, tests);
while (true) {
    var donePromise:Promise=promise.doneInvocations;
    var done:int=donePromise.local::receive();
    if (done>=nTests) {
         break;
     }
     System.sleep(100);
}
w.stop();
print("finished in "+getTimer());