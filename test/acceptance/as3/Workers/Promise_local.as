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
import flash.system.*

var SECTION = "wokers";
var VERSION = "AS3";
var TITLE   = "Test Promise api.";


var done:Boolean = false;

var bar:String = "BAR";
var globalPromise:Promise = Promise.wrap(this);

var o:Object = {f:foo, b:bar};
var promise:Promise = Promise.wrap(o);

public function foo():String
{
    return "FOO";
}

if (Worker.current.isPrimordial)
{
    writeHeaderToLog( SECTION + " "+ TITLE);
    startTest();
    AddTestCase("FOO from global promise call", "FOO", globalPromise.async.foo().receive());
    AddTestCase("BAR from global promise property", "BAR", globalPromise.async.bar.receive());
    AddTestCase("FOO from regular promise call", "FOO", promise.async.f().receive());
    AddTestCase("BAR from regular promise propety", "BAR", promise.async.b.receive());

    var w:Worker=WorkerDomain.current.createWorkerFromPrimordial();
    var p:Promise=w.start();

    do {
        var finish:Boolean = p.async.done.receive();
        if (finish) break;
        else System.sleep(0);
    } while (true);

    w.terminate();

    test();

 } else {

/*
    public function handlerP(p:Promise):void
    {
        startTest();
        AddTestCase("FOO from regular asynchronous promise call", "FOO", p.receive());
        done = true;
        test();
    }
*/
    public function handler(result):void
    {
        startTest();
        AddTestCase("FOO from regular asynchronous promise call", "FOO", result);
        done = true;
        test();
    }

    var r:Promise = promise.async.f()
    r.when(handler);
 }

}