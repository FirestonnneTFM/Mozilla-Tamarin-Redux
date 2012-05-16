import avmplus.System;
import avmplus.File;
import flash.utils.ByteArray;
import flash.system.Worker;
import flash.system.Promise;
import flash.system.PromiseChannel;
import flash.system.WorkerDomain;

// count how many invocations have been completed
var doneInvocations:int = 0;

var workers:Array = new Array();
var promises:Array = new Array();

var tests:Array;

function serviceHandler(p:Promise):void {
    try {
        var promise_slot:int = p.local::receive();
    } catch (e) {c	     
        print("exception: "+e);
    }
    doneInvocations++;
    if (tests.length==0) {
	workers[promise_slot].stop();
    }
    else {
	var res:Promise = promises[promise_slot].runtest(tests.shift(), promise_slot);
	res.local::when(arguments.callee);
    }    
}

function getDone():int {
    return doneInvocations;
}

function dispatch(numWorkers:int, tests1:Array) {
    tests=tests1;
    print("creating workers: "+numWorkers);
    for(var i:int = 0; i<numWorkers; i++) {
	workers[i] = WorkerDomain.current.createWorkerFromByteArray(File.readByteArray("service.abc"));
	promises[i] = workers[i].start();
    }
    for (var i:int=0;i<numWorkers;i++) {
	var res:Promise = promises[i].runtest(tests.shift(),i);
	res.local::when(serviceHandler);
    }
}
    