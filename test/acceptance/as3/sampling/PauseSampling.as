/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

import flash.sampler.*
import avmplus.*

var SECTION = "Sampling";
var VERSION = "AS3";
var TITLE   = "Sampling Basic Usage";

var isdebugger=System.isDebugger();

startTest();
writeHeaderToLog("Sampling api");

var objs:Array=new Array();
class simpleobject {
    var str:String;
    function simpleobject(s:String) {
        this.str=s;
    }
}
function simpleLoop() {
    for (var i:int=0;i<10;i++) {
       objs.push(new simpleobject(""+i));
    }
}

sampleInternalAllocs(true);

simpleLoop();
if (isdebugger) {
    AddTestCase(
      "BeforeStartSampling: test before startSampling sample count 0",
      0,
      getSampleCount()
    );
} else {
    AddTestCase(
      "BeforeStartSampling: test before startSampling sample count 0",
      -1,
      getSampleCount()
    );
}
startSampling();
simpleLoop();
pauseSampling();
var time=getTimer();
while (getTimer()<time+50) {}
var count=getSampleCount();
var newcount=getNewObjectCount();

simpleLoop();

if (isdebugger) {
    AddTestCase(
      "PauseSampling: after pauseSampling verify no more NewObjectSamples",
      newcount,
      getNewObjectCount()
    );
} else {
    AddTestCase(
      "PauseSampling: after pauseSampling verify no more samples are counted",
      -1,
      getSampleCount()
    );
}
startSampling();
simpleLoop();
stopSampling();

if (isdebugger) {
    AddTestCase(
      "StopSampling: after stopSampling samples are reset",
      0,
      getSampleCount()
    );
} else {
    AddTestCase(
      "StopSampling: after stopSampling samples are reset",
      -1,
      getSampleCount()
    );
}
test();

function getNewObjectCount():int {
    var ct:int=0;
    var nos:NewObjectSample;
    for each (var sample in getSamples()) {
        if ((nos=sample as NewObjectSample) != null) {
            ct++;
        }
    }
    return ct;
}