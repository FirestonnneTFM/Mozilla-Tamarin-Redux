package {
import avmplus.System;
import flash.system.Promise;
import flash.system.Worker;
import flash.system.WorkerDomain;
import flash.utils.ByteArray;
import flash.net.registerClassAlias;


    public function echo(o:*):*
    {
        return o;
    }


    if (Worker.current.isPrimordial)
    {
        var w:Worker = WorkerDomain.current.createWorkerFromPrimordial();
        //link = Worker.current.newLinkTo(w);
        w.setStartArgument("arg1", 10);
        w.setStartArgument("arg1", 11);

        w.setStartArgument("arg2", 1.20);
        w.setStartArgument("arg3", true);
        var obj = new ByteArray();
        obj.writeObject({ hello: "World"});
        w.setStartArgument("arg4", obj);
        obj = new ByteArray();
        obj.writeObject({ hello: "World"});
        w.setStartArgument("arg4", obj);
        w.setStartArgument("arg5", null);

        var top:Promise = w.start();
        
    } else {
        for (var i = 1; i <= 5; i++) {
            print(Worker.current.getStartArgument("arg" + i));
        }
        Worker.current.stop();
    }

}