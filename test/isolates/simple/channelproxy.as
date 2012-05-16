import flash.utils.Proxy;
import flash.utils.flash_proxy;
import avmplus.System;
import avmplus.File;
import flash.system.Worker;
import flash.system.PromiseChannel;


class SenderProxy extends Proxy {

    public function SenderProxy(receiver:Worker) {
        out = new PromiseChannel(Worker.current, receiver);
        inc = new PromiseChannel(receiver, Worker.current);
    }

    public var out:PromiseChannel;
    public var inc:PromiseChannel;

    flash_proxy override function callProperty(name:*, ...rest):* {
        try {
            // investigate why toString() is needed.
            out.send({name: name.toString(), args:rest});
            return inc.receive();
        } catch (e:Error) {
            // respond to error here
        }
    }
    static function close(p: SenderProxy) {
        p.out.send(42);
    }
    
}



function makeCode(name) {
    return File.readByteArray(name);
}

var p = new Worker([makeCode("echoproxy.abc")]);
var proxy = new SenderProxy(p);

p.startWithChannels([proxy.out, proxy.inc]);

proxy.hello('world');

proxy.bye('kitty');

SenderProxy.close(proxy);
