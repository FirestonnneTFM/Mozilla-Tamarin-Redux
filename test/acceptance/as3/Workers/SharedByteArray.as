/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2012
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

package {

    import avmplus.System;
    import avmplus.File;
    import flash.utils.ByteArray;
    import flash.system.Worker;
    import flash.system.WorkerDomain;
    import flash.system.Promise;

    if (Worker.current.isPrimordial) {
        var b:ByteArray = new ByteArray();
        b.length=100;
        var SECTION = "Workers";
        var VERSION = "AS3";
        var TITLE   = "Test ByteArray shared API.";
        startTest();
        writeHeaderToLog(SECTION+" "+TITLE);

        // test changing ByteArray not shared does not change values
        b[0]=65; b[1]=0;
        var w:Worker=WorkerDomain.current.createWorkerFromPrimordial();
        var p1:Promise=w.start();
        var p2:Promise=p1.async.modifyByteArray(b);
        p2.receive();
        AddTestCase("bytearray not shared does not contain changes from background worker ["+b[0]+","+b[1]+"]==[65,0]",true,b[0]==65 && b[1]==0);

        // test compareAndSwap not shared does not change value
        b[0]=71; b[1]=0;
        p2=p1.async.testCompareAndSwap(b);
        p2.receive();
        AddTestCase("compareAndSwap not shared does not contain changes from background worker ["+b[0]+","+b[1]+"]==[71,0]",true,b[0]==71 && b[1]==0);

        // compareAndSwapInt: expect successful
        b[0]=65; b[1]=0;
        var result=false;
        result=b.compareAndSwapWordAt(0,65,66);
        AddTestCase("compareAndSwap successful swap, returns true",true,result);
        AddTestCase("compareAndSwap successful swap, updates value ["+b[0]+","+b[1]+"]==[66,0]",true,b[0]==66 && b[1]==0);

        // compareAndSwapInt: expect failure
        b[0]=65; b[1]=0;
        result=false;
        result=b.atomicCompareAndSwapIntAt(0,97,66) == 97;
        AddTestCase("compareAndSwap unsuccessful swap, returns false",false,result);
        AddTestCase("compareAndSwap unsuccessful swap, value is unchanged ["+b[0]+","+b[1]+"]==[65,0]",true,b[0]==65 && b[1]==0);

        // compareAndSwapInt: RangeError index is out of range (length is 100)
        result=false;
        b[0]=65; b[1]=0;
        var exc:String='no exception';
        try {
            result=b.atomicCompareAndSwapIntAt(110,97,66) == 97;
        } catch (e) {
            exc=e.toString();
        }
        AddTestCase("compareAndSwap index out of range throws RangeError","RangeError: Error #1506",removeExceptionDetail(exc));
        AddTestCase("compareAndSwap index out of range exception leaves values unchanged ["+b[0]+","+b[1]+"]==[65,0]",true,b[0]==65 && b[1]==0);

        // compareAndSwapInt: RangeError index is not in sync, not a word
        result=false;
        b[0]=65; b[1]=0; 
        var exc2:String='no exception';
        try {
            result=b.atomicCompareAndSwapWordAt(1,97,66) == 97;
        } catch (e) {
            exc2=e.toString();
        }
        AddTestCase("compareAndSwap index not in word alignment throws RangeError","RangeError: Error #1506",removeExceptionDetail(exc2));
        AddTestCase("compareAndSwap index not in word alignment leaves values unchanged ["+b[0]+","+b[1]+"]==[65,0]",true,b[0]==65 && b[1]==0);

        
        // write 65 at position 0
        b.writeByte(65);
        // write 97 at position 1, expecting to get overwritten by worker
        b.writeByte(97);
        p2=p1.async.modifyByteArray(b);
        p2.receive();
        b.position=2;
        b.writeByte(67);
        b.position=0;

        AddTestCase("compareAndSwap background worker changes byte array values ["+b[0]+","+b[1]+","+b[2]+"]==[65,66,67]", true, b[0]==65 && b[1]==66 && b[2]==67);

        b.position=0;
        b[0]=65; b[1]=0; b[2]=0; b[3]=0;
        b[4]=69; b[5]=0;
        p2=p1.async.testCompareAndSwap(b);
        var res=p2.receive();
        AddTestCase("compareAndSwap succeed and fail return values ["+res+"]==[true,false]",true, res[0] == true && res[1] == false);
        AddTestCase("compareAndSwap first word is changed ["+b[0]+","+b[1]+"]==[66,0]",true,b[0]==66 && b[1]==0);
        AddTestCase("compareAndSwap second word is not changed ["+b[4]+","+b[5]+"]==[69,0]",true,b[4]==69 && b[5]==0);
        AddTestCase("compareAndSwap bytearray length",100,b.length);

        // catch exception from background worker in receive
        p2=p1.async.testCompareAndSwapException(b);
        var exc3="no exception";
        try {
            p2.receive();
        } catch (e) {
            exc3=e.toString();
        }
        AddTestCase("compareAndSwap exception in background workers returned from receive","RangeError: Error #1506",removeExceptionDetail(exc3));
        test();

        w.terminate();
    } else {
        public function modifyByteArray(b1:ByteArray) {
            b1.position=1;
            b1.writeByte(66);
        }
        public function testCompareAndSwap(b1:ByteArray) {
            var res=[];
            res.push(b1.atomicCompareAndSwapIntAt(0,65,66) == 65);
            res.push(b1.atomicCompareAndSwapIntAt(4,97,67) == 97);
            return res;
        }
        public function testCompareAndSwapException(b1:ByteArray) {
            b1.compareAndSwapWordAt(110,0,65);
        }
    }
}
