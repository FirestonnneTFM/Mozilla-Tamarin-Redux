/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS3";  // Version of JavaScript or ECMA
var TITLE   = "Interface Definition";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

//-----------------------------------------------------------------------------

import LatticeAmbiguous.*;

var fg1 = new ImplFG
AddTestCase("public on unambiguous interface method (f)", "IFuncF::f", fg1.f())
AddTestCase("public on unambiguous interface method (g)", "IFuncG::g", fg1.g())

var ffg1 = new ImplFFG
AddTestCase("namespace attribute on ambiguous interface method (F/f)", "{IFuncF,IFuncFG}::f", ffg1.IFuncF::f())
AddTestCase("namespace attribute on ambiguous interface method (FG/f)", "{IFuncF,IFuncFG}::f", ffg1.IFuncFG::f())
AddTestCase("public on unambiguous interface method (FG/g)", "IFuncFG::g", ffg1.g())

var fxg1 = new ImplGxF
AddTestCase("public on unambiguous extended interface method (f)", "IFuncF::f", fxg1.f())
AddTestCase("public on unambiguous interface method (g)", "IFuncGxF::g", fxg1.g())

var hxfg1 = new ImplHxFG
AddTestCase("extended implementation method (f)", "IFuncF::f", hxfg1.f())
AddTestCase("extended implementation method (g)", "IFuncG::g", hxfg1.g())
AddTestCase("public on unambiguous interface method (h)", "IFuncH::h", hxfg1.h())

test();       // leave this alone.  this executes the test cases and
              // displays results.
