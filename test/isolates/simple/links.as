package {
import avmplus.System;
import flash.system.Promise;
import flash.system.Worker;
import flash.system.WorkerDomain;
import flash.utils.ByteArray;
import flash.net.registerClassAlias;
import flash.system.Link;


    public function echo(o:*):*
    {
        return o;
    }

    public var link:Link;
    
    public function sendLinkOverPromise(l:Link) {
        link = l;
        print('got link', l);
    }

    public function requestRead()
    {
        print('read', link.receive());
        print('read', link.receive());
        print('read', link.receive());
        print('read', link.receive());
        print('read', link.receive());
        print('read', link.receive());
        print('read', link.receive());

        Worker.current.stop();
    }

    if (Worker.current.isPrimordial)
    {
        var w:Worker = WorkerDomain.current.createWorkerFromPrimordial();
        link = Worker.current.newLinkTo(w);
        var top:Promise = w.start();
        top.async.sendLinkOverPromise(link).receive();
        print('top is', top);
        link.send(true);
        link.send(100000.00000);
        link.send(null);
        link.send(undefined);
        link.send(w.newLinkTo(Worker.current));
        var ba:ByteArray = new ByteArray();
        ba.writeObject({hello: "World"});
        link.send(ba);
        link.send({bye: "Universe"});
        top.async.requestRead().receive();

    } else {
        
        
    }

}