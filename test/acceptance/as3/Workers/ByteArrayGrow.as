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
 * Portions created by the Initial Developer are Copyright (C) 2011
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

const baseLoc = 20;
const maxiter = 3000;
public var output='';
public function getOutput() {
    return output;
}
public function pr(...args)
{
    var newArgs = [Worker.current.descriptor + ":"];
    System.runInSafepoint(function() {
        out=Worker.current.descriptor + ":";
        for (var a in args) {
           out+=args[a]+' ';
        }
        output+=out+'\n';
    });
}
const CAP_A = "A".charCodeAt(0);

public function busy(param = 1)
{
    var result = 0;
    for (var i = 0; i < 1000*param; i++)
       result += i*2;
    return result;
}

if (Worker.current.isPrimordial) {
    // writer keeps growing and writing to an array

    var b:ByteArray = new ByteArray();
    b.length = 32;
    b.share();
    
    b[baseLoc] = CAP_A;
    
    var w = WorkerDomain.current.createWorkerFromPrimordial();
    var tl:Promise = w.start();
    
    tl.async.requestWrite(b).receive();
    
    
    tl.async.mainLoop();
    
    (function() {
            // Write a char 32 indices apart.
            for (var i:int = 0; i< maxiter; i++) {
                busy();
                b.length += 32;
                b[baseLoc + i*32] = CAP_A;
            }


        })();
    pr('writer done');

    backout=tl.async.getOutput().receive();    
    var SECTION = "workers";
    var VERSION = "AS3";
    var TITLE   = "Test Workers API.";
    startTest();
    writeHeaderToLog(SECTION+" "+TITLE);
    AddTestCase("main worker write succeeded","1:writer done ",output.split('\n')[0]);
    AddTestCase("background worker read succeeded","2:reader done ",backout.split('\n')[0]);
    AddTestCase("verify shared bytearray has new value",CAP_A,b[2996]);
    test();
    w.stop();
    
} else {
    var s:ByteArray = null;
    
    public function requestWrite(aS:ByteArray)
    {
        s = aS;
    }
    
    public function mainLoop() 
    {
        for (var i:int = 0; i< maxiter; i++) {
            busy(4);
            var len = s.length;
            //System.sleep(0); // sleep introduces a safepoint

            for (var loc:int = baseLoc; loc < i; loc += i*32) {
                if (loc >= len) {
                    break;
                }
                var val = s[loc];
                if (val != CAP_A) {
                    if (val == 0) {
                        // this can happen if the receiver gets ahead of the sender
                        pr('reader missed write, got', val);
                    } else {
                        pr('whoa, unexpected value');
                        return;
                    }
                }
            }
        }
        pr('reader done');
    }
}

}