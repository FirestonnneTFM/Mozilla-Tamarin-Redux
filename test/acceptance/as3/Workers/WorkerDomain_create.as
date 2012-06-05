/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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
import flash.system.Promise;
import flash.system.WorkerDomain;

var SECTION = "wokers";
var VERSION = "AS3";
var TITLE   = "Test WorkerDomain creating a worker";



public function remoteEcho(s:String) {
    return s;
}

if (Worker.current.isPrimordial) {

    function makeCode(name)
    {
        return File.readByteArray(name);
    }

    writeHeaderToLog( SECTION + " "+ TITLE);
    startTest();

    var blob = makeCode("as3/Workers/WorkerDomain_create.abc");
    var w:Worker;

    AddErrorTest("MAIN: EXCEPTION WHILE TRYING TO USE WORKER'S CONSTRUCTOR", ARGUMENTERROR+2012, function(){ w = new Worker(); });

    var promise:Promise;
    var echoPromise:Promise;

    w = WorkerDomain.current.createWorkerFromByteArray(blob);
    promise = w.start();
    echoPromise = promise.async.remoteEcho("echo1");
    AddTestCase("(MAIN DOMAIN - FROM BYTE ARRAY) RETURNED ECHO", "echo1", echoPromise.receive());
    w.terminate();

    w = WorkerDomain.current.createWorkerFromPrimordial();
    promise = w.start();
    echoPromise = promise.async.remoteEcho("echo2");
    AddTestCase("(MAIN DOMAIN - FROM MAIN) RETURNED ECHO", "echo2", echoPromise.receive());
    w.terminate();

    var workerDomain:WorkerDomain = new WorkerDomain();
    w = workerDomain.createWorkerFromByteArray(blob);
    promise = w.start();
    echoPromise = promise.async.remoteEcho("echo3");
    AddTestCase("(NEW DOMAIN - FROM BYTE ARRAY) RETURNED ECHO", "echo3", echoPromise.receive());
    w.terminate();

    test();
 }

}