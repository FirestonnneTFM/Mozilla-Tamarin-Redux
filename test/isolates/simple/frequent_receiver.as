import avmplus.System;
import flash.system.PromiseChannel;

var m1 = PromiseChannel.initial[0];
var m2 = PromiseChannel.initial[1];

var NUM_MSGS:Number = m1.receive();

var a:Array = new Array(NUM_MSGS);
for (var i = 0; i < NUM_MSGS; i++) {
    a[i] = m1.receive();
}

// a barrier (in attempt to get more accurate time measurements) - let
// the other side know (via "SYNC" that the actual timed payload is
// about to arrive)
var msg = m1.receive();
m2.send("SYNC"); 

for (var i = 0; i < NUM_MSGS; i++) {
    m2.send(a[i]);
}

// Hack to avoid closing channels on exit while receiver hasn't received all the buffer items yet:
System.sleep(50);
