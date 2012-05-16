import flash.system.Worker;
import flash.system.PromiseChannel;
class ReceiverHandler {

    public function ReceiverHandler(inc: PromiseChannel, out:PromiseChannel) {
        this.inc = inc;
        this.out = out;
    }

    var out:PromiseChannel;
    var inc:PromiseChannel;
    public var client:Object;

    function handle():Boolean {
        var msg = inc.receive();
        if (msg === 42) return false;
        var name = msg.name;
        var args = msg.args;
        var result = client[name].apply(client, args);
        out.send(result);
        return true;
    }
}

var h:ReceiverHandler = new ReceiverHandler(PromiseChannel.initial[0], PromiseChannel.initial[1]);
class Client {
    function hello(s) {
        print('hello', s);
    }
    function bye(s) {
        print('bye', s);
    }
}

h.client = new Client();

while(h.handle())
   ;





