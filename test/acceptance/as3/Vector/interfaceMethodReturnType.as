/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
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
 * The Original Code is Mozilla Communicator client code, released
 * March 31, 1998.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
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
