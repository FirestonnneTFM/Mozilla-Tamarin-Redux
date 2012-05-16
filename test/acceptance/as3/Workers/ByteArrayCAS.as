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

const index = 42;
const casLoc = 20;
output = ''
public function pr(...args)
{
    var newArgs = [Worker.current.descriptor + ":"];
    for each (var a in args) {
        newArgs.push(a);
    }
    System.runInSafepoint(function() {
        out=''
        for (arg in args) {
            out+=args[arg]+' '
        }
        output+=out+'\n';
    });
}

if (Worker.current.isPrimordial) {

    var s:ByteArray = new ByteArray();
    s.length = 1024;
    s.share();
    
    s[index] = 100;
    s[casLoc] = "A".charCodeAt(0);
    pr("wrote to shared storage at", index, s[index]);
    
    var w = WorkerDomain.current.createWorkerFromPrimordial();
    var tl:Promise = w.start();
    
    pr('shared storage before ack ', s[index]);
    tl.async.requestWrite(s).receive();
    
    pr('shared storage after requestWrite', s[index]);
    
    tl.async.mainLoop();

    pr('sender has', s[casLoc]);
    for (var i:int = 0; i< 5; i++) {
        tries=0
        while (true) {
            if (s.compareAndSwapWordAt(casLoc, "A".charCodeAt(0), "B".charCodeAt(0))) {
                pr("(", i, "): A->B");
                break;
            } else {
                pr("sender cas failed "+i+" "+tries);
                tries+=1;
                if (tries>10) break;
            }
        }
    }
    pr('sender has', s[casLoc]);

    var SECTION = "workers";
    var VERSION = "AS3";
    var TITLE   = "Test Workers shared byte array";
    startTest();
    writeHeaderToLog(SECTION+" "+TITLE);

    lines=output.split('\n');
    AddTestCase("shared bytearray background worker wrote value","shared storage after requestWrite 111 ",lines[2]);
    AddTestCase("shared bytearray background worker before background swap","sender has 65 ",lines[3]);
    AddTestCase("shared bytearray background worker after background swap","sender has 65 ",lines[9]);
    for (var j:uint=0;j<5;j++) {
        AddTestCase("shared bytearray background worker writes worked","( "+j+" ): A->B ",lines[4+j]);
    }
    AddTestCase("shared bytearray contains correct value at 20",65,s[20]);
    AddTestCase("shared bytearray contains correct value at 42",111,s[42]);
    test();
    //print(output)
    w.stop();
    
} else {
    
    pr('hello');
    
    var b:ByteArray = null;
    
    public function requestWrite(aS:ByteArray)
    {
        b = aS;
        pr('received', b);
        b[index] = 111;
        pr('wrote to shared storage at', index, b[index]);
    }
    
    
    public function mainLoop() 
    {
        pr('receiver has', b[casLoc]);
        for (var i:int = 0; i< 5; i++) {
            tries=0;
            while (true) {
                if (b.compareAndSwapWordAt(casLoc, "B".charCodeAt(0), "A".charCodeAt(0))) {
                    pr("mainLoop (", i, "): B->A");
                    break;
                } else {
                    pr("receiver cas failed");
                    tries+=1;
                    if (tries>10) break;
                }
            }
        }
    }
}

}
