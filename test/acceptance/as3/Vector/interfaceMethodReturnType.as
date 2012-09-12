/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package
{
    public class C
    {
    }

    public interface ITest
    {
        function get vo():Vector.<Object>;
        function get vs():Vector.<String>;
        function get vi():Vector.<int>;
        function get vc():Vector.<C>;
        function get va():Vector.<*>;
    }

    public class Test implements ITest
    {
        private var _vo:Vector.<Object>;
        private var _vs:Vector.<String>;
        private var _vi:Vector.<int>;
        private var _vc:Vector.<C>;
        private var _va:Vector.<*>;

        public function get vo():Vector.<Object> { return _vo; }
        public function get vs():Vector.<String> { return _vs; }
        public function get vc():Vector.<C> { return _vc; }
        public function get vi():Vector.<int> { return _vi; }
        public function get va():Vector.<*> { return _va; }

        public function Test()
        {
            _vo = new Vector.<Object>();
            _vo.push("obj");

            _vs = new Vector.<String>();
            _vs.push("str");

            _vi = new Vector.<int>();
            _vi.push(7);

            _vc = new Vector.<C>();
            _vc.push(new C());

            _va = new Vector.<*>();
            _va.push("any");
        }
    }
}

var SECTION = "";
var VERSION = "ECMA_1";
startTest();
var TITLE   = "interfaceMethodReturnType";

writeHeaderToLog( SECTION + " "+ TITLE);

var t:Test = new Test();

AddTestCase("return Vector.<Object>", "obj", t.vo[0].toString() );
AddTestCase("return Vector.<String>", "str", t.vs[0].toString() );
AddTestCase("return Vector.<C>", "[object C]", t.vc[0].toString() );
AddTestCase("return Vector.<int>", "7", t.vi[0].toString() );
AddTestCase("return Vector.<*>", "any", t.va[0].toString() );

test();
