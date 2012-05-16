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
import flash.concurrent.Mutex;

const index = 42;
const casLoc = 20;
public var output:String='';
public function pr(...args)
{
    var out:String=Worker.current.descriptor + ":";
    for each (var a in args) {
        out+=a+' ';
    }
    //System.runInSafepoint(function() {
            output+=out+'\n';
        //});
    print(out);
}

if (Worker.current.isPrimordial) {
    var SECTION = "workers";
    var VERSION = "AS3";
    var TITLE   = "Test Workers shared byte array";
    startTest();
    writeHeaderToLog(SECTION+" "+TITLE);

    var s1:ByteArray = new ByteArray();
    s1.length = 1024;
    s1.share();
    
    s1[index] = 100;
    s1[casLoc] = "A".charCodeAt(0);
    pr("wrote to shared storage at", index, s1[index]);
    
    var w = WorkerDomain.current.createWorkerFromPrimordial();


    var m1:Mutex = new Mutex();
    w.setStartArgument("mutex", m1);
    w.setStartArgument("array", s1);
    var tl:Promise = w.start();
    
    pr('started, mutex', m1, 'array', s1.length);
    
    //pr('sender has', s1[casLoc]);
    for (var i:int = 0; i< 10; i++) {
        while (true) {
            if (m1.tryLock()) {
                if (s1[casLoc] == "A".charCodeAt(0)) {
                    s1[casLoc] = "B".charCodeAt(0);
                    pr('A->B');
                    m1.unlock();
                    break;
                } else {
                    //pr('sender found ' + s1[casLoc] + ' retry');
                    m1.unlock();
                    //System.sleep(4);
                }
            } else {
                //pr("sender tryLock failed");
            }
        }
    }
    
    pr('sender has', casLoc, s1[casLoc]);
    backoutput = tl.async.output.receive();

    lines=output.split('\n');
    for (var j:uint=0;j<10;j++) {
        AddTestCase("confirm main writes succeeded "+j,'1:A->B ',lines[2+j]);
    }
    lines=backoutput.split('\n');
    for (j=0;j<10;j++) {
        AddTestCase("confirm background reads succeeded "+j,'2:B->A ',lines[4+j]);
    }
    AddTestCase("confirm shared bytearray was set correctly "+j,65,s1[20]);
    AddTestCase("confirm shared bytearray was set correctly "+j,111,s1[42]);
    test();
    //print(output);    
    //print(backoutput);    
    w.stop();

} else {
    
    var s:ByteArray = Worker.current.getStartArgument("array");
    var m:Mutex = Worker.current.getStartArgument("mutex");
    s[index] = 111;
    pr('wrote to shared storage at', index, s[index]);
    
    pr('receiver has', s[casLoc], m);
    for (var k:int = 0; k< 10; k++) {
        while (true) {
            if (m.tryLock()) {
                if (s[casLoc] == "B".charCodeAt(0)) {
                    s[casLoc] = "A".charCodeAt(0);
                    pr('B->A');
                    m.unlock();
                    break;
                } else {
                    //pr('receiver found ' + s[casLoc] + ', retry');
                    m.unlock();

                }
            } else {
                //pr("receiver tryLock failed");
            }
        }
    }
}

}
