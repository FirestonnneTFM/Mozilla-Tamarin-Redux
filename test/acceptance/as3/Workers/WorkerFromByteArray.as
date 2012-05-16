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

import flash.system.*
import flash.utils.ByteArray


if (Worker.current.isPrimordial) {

    var SECTION = "concurrency";
    var VERSION = "AS3";
    var TITLE   = "Test createWorkerFromByteArray";

    startTest();
    var bytes:Array=[16, 0, 46, 0, 0, 0, 0, 5, 0, 6, 79, 98, 106, 101, 99, 116, 9, 101, 99, 104, 111, 46, 97, 115, 36, 49, 4, 101, 99, 104, 111, 3, 22, 1, 5, 3, 0, 3, 7, 1, 2, 7, 2, 4, 2, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 2, 0, 1, 0, 0, 2, 0, 1, 2, 1, 1, 2, 209, 72, 0, 0, 1, 2, 1, 1, 2, 9, 208, 48, 64, 0, 100, 43, 109, 1, 71, 0, 0];
    var bytearray:ByteArray=new ByteArray();
    for (var i:uint=0;i<bytes.length;i++) {
        bytearray.writeByte(bytes[i]);
    }
    var worker:Worker=WorkerDomain.current.createWorkerFromByteArray(bytearray);
    var ipromise:Promise=worker.start();
    /*
    var promise:Promise=ipromise.echo("test string");
    var result=promise.receive();
    AddTestCase("remote call from Worker result is correct",result,"test string");
    */
    AddTestCase("Worker creation successful",PromiseState.NEW,ipromise.state);
    worker.stop();

    /*
    message="no error";
    try {
        ipromise.echo("test string");
    } catch (e) {
        message=e.toString();
    }
    AddTestCase("error calling stopped worker",message,"Error: channel closed in worker 1");
    */
    
    test();

}

}