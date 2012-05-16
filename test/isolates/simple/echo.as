import flash.system.PromiseChannel;
import flash.system.Worker;

var incoming = PromiseChannel.initial[0];
var outgoing = PromiseChannel.initial[1];
function loop() {
    try {
        while(true) {
	    var data = incoming.receive();
	    print('got type', data.constructor);
	    outgoing.send(data);
	    if (data === 42) {
	      // outgoing.send(data);
	        //print('done');
       	        break;
	    }
        }
    } catch (e) {
        //print('echo: oops', e);
    }
}

loop();
try {
    incoming.receive(); // should block
} catch (e) {
    print('problem', e);
}
Worker.current.stop();



