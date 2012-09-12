
/* This Source Code Form is subject to the terms of the Mozilla Public
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
   
package {
    import flash.system.Worker;
    import flash.system.WorkerDomain;
    import flash.utils.ByteArray;

    var SECTION = "Workers";
    var VERSION = "as3";
    var TITLE   = "shared ByteArray api";
    startTest();
    writeHeaderToLog(SECTION+" "+TITLE);

    var ba:ByteArray=new ByteArray();

// test atomicCompareAndSwapIntAt throws exception if index is past length

    var exception:String="";
    try {
        ba.atomicCompareAndSwapIntAt(0,65,97);
    } catch (e) {
        exception=e.toString();
    }
    AddTestCase("ByteArray atomicCompareAndSwapIntAt throws Range Error when bytearray length is 0","RangeError: Error #1506",exception.substring(0,"RangeError: Error #1506".length));

    ba[0]=65;
    ba[1]=0;
    ba[2]=0;
    ba[3]=0;
    exception="";
    try {
        ba.atomicCompareAndSwapIntAt(10,65,97);
    } catch (e) {
        exception=e.toString();
    }
    AddTestCase("ByteArray atomicCompareAndSwapIntAt throws Range Error when index exceeds length","RangeError: Error #1506",exception.substring(0,"RangeError: Error #1506".length));


    // test atomicCompareAndSwapIntAt throws exception if index does not align on word (multiple of 4)
    ba.length=100;    exception="";
    try {
        ba.atomicCompareAndSwapIntAt(1,65,97);
    } catch (e) {
        exception=e.toString();
    }
    AddTestCase("ByteArray atomicCompareAndSwapIntAt throws Range Error if index does not align on word","RangeError: Error #1506",exception.substring(0,"RangeError: Error #1506".length));

// test atomicCompareAndSwapIntAt throws exception if index if not on word boundry (4th byte)
    ba[0]=65;
    ba[1]=0;
    ba[2]=0;
    ba[3]=0;
    ba[4]=66;
    ba[5]=0;
    ba[6]=0;
    ba[7]=0;
    ba[8]=67;
    ba[9]=0;
    ba[10]=0;
    ba[11]=0;

    var res1:int=ba.atomicCompareAndSwapIntAt(0,65,97);
    AddTestCase("ByteArray atomicCompareAndSwapIntAt matches return",65,res1);
    AddTestCase("ByteArray atomicCompareandSwapIntAt matches changes value",97,ba[0]);

    var res2:int=ba.atomicCompareAndSwapIntAt(4,65,98); // should fail
    AddTestCase("ByteArray atomicCompareAndSwapIntAt no match return",66,res2);
    AddTestCase("ByteArray atomicCompareAndSwapIntAt no match does not change value",66,ba[4]);

    ba.length=3;
    AddTestCase("ByteArray atomicCompareAndSwapLength alters length on match",3,ba.atomicCompareAndSwapLength(3,10));
    AddTestCase("after ByteArray atomicCompareSwapLength the length was altered",10,ba.length);
    AddTestCase("ByteArray atomicCompareAndSwapLength does not change length when expectedLength does not match",10,ba.atomicCompareAndSwapLength(11,12));
    AddTestCase("after ByteArray atomicCompareSwapLength then length does not change",10,ba.length);

// test ByteArray share
    AddTestCase("ByteArray shareable defaults to false",false,ba.shareable);

    ba.shareable=false;
    AddTestCase("ByteArray is still not shareable when setting shareable=false",false,ba.shareable);

    ba.shareable=true;
    AddTestCase("ByteArray shareable can be set true",true,ba.shareable);
    ba[1]=97;
    AddTestCase("ByteArray can set value when shareable=true",97,ba[1]);
    ba.shareable=false;
    AddTestCase("ByteArray cannot set shareable=false once shareable=true",true,ba.shareable);

    ba.shareable=true;
    AddTestCase("ByteArray set shareable when shareable is already true",true,ba.shareable);

    test();
}