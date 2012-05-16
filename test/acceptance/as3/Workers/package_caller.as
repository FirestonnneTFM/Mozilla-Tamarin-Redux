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
var TITLE   = "Test Promise api.";


writeHeaderToLog( SECTION + " "+ TITLE);
startTest();



function makeCode(name:String):ByteArray
{
    return File.readByteArray(name);
}

var blob:ByteArray = makeCode("as3/Workers/package_caller_support/callee.abc");
var p:Worker = WorkerDomain.current.createWorkerFromByteArray(blob);
var promise:Promise = p.start();

import bar.Clazz;
AddTestCase("call to bar.Clazz.foo()", "FOO", promise.async.Clazz.async.foo().receive());
AddTestCase("access to bar.Clazz.s", "BAR", promise.async.Clazz.async.s.receive());

namespace baz = "baz";
AddTestCase("call to baz.foo()", "baz.foo()", promise.async.baz::foo().receive());

namespace baz_bar = "baz.bar";
AddTestCase("call to baz.bar.foo()", "baz.bar.foo()", promise.async.baz_bar::foo().receive());

//namespace blah_bleh = "blah.bleh";
//AddTestCase("call to blah.bleh.foo()", "blah.bleh.foo()", promise.async.blah_bleh::foo().receive());
function blah_bleh_foo() {
    import blah.bleh.foo;
    return promise.async.foo().receive();
}
AddTestCase("call to blah.bleh.foo()", "blah.bleh.foo()", blah_bleh_foo());

//AddTestCase("call to foo()", "foo()", promise.async.foo().receive());

AddTestCase("access baz.V1", 7, promise.async.baz::v1.receive());
AddTestCase("access baz.bar.V2", 77, promise.async.baz_bar::v2.receive());
AddTestCase("access V3", 777, promise.async.v3.receive());

AddTestCase("call to unnamedFoo() in unnamed package", "unnamedFoo()", promise.async.unnamedFoo().receive());

AddErrorTest("Tried accessing non-existent variable v4 in global scope", TYPEERROR+1010, function(){ promise.v4.receive(); });

// TODO: convert to AddErrorTest() when error is properly converted
var error:String = "???";
try
{
    promise.async.baz::v4.receive();
}
catch (ex) {
    error = ex;
}
AddTestCase("Tried accessing non-existent variable baz.v4, confirm error", false, error=="???");

// TODO: convert to AddErrorTest() when error is properly converted
error = "???";
try
{
    promise.async.baz_bar::v4.receive();
}
catch (ex) {
    error = ex;
}
AddTestCase("Tried accessing non-existent variable baz.bar.v4, confirm error", false, error=="???");

AddTestCase("variable in global scope precedence over package prefix", 7777, promise.async.bam.receive());
AddTestCase("variable in global scope takes precedence over package", 77777, promise.async.bar.receive());
AddTestCase("class static variable in global scope takes precedence over package", 0, promise.async.baz.async.redef.receive());

p.stop();
test();

}