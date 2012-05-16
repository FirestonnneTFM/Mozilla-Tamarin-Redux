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
    import flash.net.registerClassAlias;
    import flash.system.*
    import avmplus.*
    //use namespace async;
    
    class myclass {
        public var string1:String;
        public var array1:Array;
        public var boolean1:Boolean;
        public var ref1:myclass;
        function toString() {
            return "string1: '"+string1+"' array1:["+array1+"] boolean1:'"+boolean1+" ref1:'"+ref1+"'";
        }
    }
    registerClassAlias('com.adobe.myclass', myclass);

    var SECTION = "concurrency";
    var VERSION = "AS3";
    var TITLE   = "Test Worker api";
    
    startTest();

    public function foo() {
         return "FOO";
    }
    var bar="BAR";
    var globalPromise:Promise=Promise.wrap(this);
    var o={f:foo,b:bar};
    var promise:Promise = Promise.wrap(o);

    if (Worker.current.isPrimordial) {
        AddTestCase("promise from global wrapped function",globalPromise.async.foo().receive(),"FOO");
        AddTestCase("promise from global wrapped property",globalPromise.async.bar.receive(),"BAR");
        AddTestCase("promise from object wrapped function",promise.async.f().receive(),"FOO");
        AddTestCase("promise from object wrapped property",promise.async.b.receive(),"BAR");

        var m1:myclass=new myclass();
        m1.string1 = "myclass1";
        m1.array1 = [1,2,3];
        m1.boolean1 = true;
        m1.ref1 = null;
        var p1:Promise=Promise.wrap(m1);
        var p2:Promise=Promise.wrap(m1);
        var o1=p1.receive();
        var o2=p2.receive();

        AddTestCase("Promise wrapping object and receiving the promise returns the same object",o1,m1);
        AddTestCase("Promise wrapping same object twice returns the same object",o2,m1);

        var p3:Promise=Promise.wrap(null);

        var worker:Worker=WorkerDomain.current.createWorkerFromPrimordial();
        var promise1:Promise=worker.start();
        {
            var promise2:Promise=promise1.async.echo(p1);
            var m3=promise2.receive();
            AddTestCase("Promise wrapped object echoed from a worker returns equivalent objects",m3.toString(),m1.toString());
            AddTestCase("Promise wrapped object echoed from a worker returns a copy of the object, not the same object",true,m1!=m3);
            var promise3:Promise=promise1.async.echo(p3);
            AddTestCase("Promise wrapped null value echoed from a worker returns null", null, promise3.receive());


        }
        worker.stop();

        test();
    } else {
        public function echo(p:Promise):Object {
	    return p.receive();
        }
    }
} // end package