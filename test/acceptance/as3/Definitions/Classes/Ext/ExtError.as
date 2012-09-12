/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */



import ExtError.*;

var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "AS 3.0";  // Version of JavaScript or ECMA
var TITLE   = "extend Error";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone


var error = new CustError();
var ee = new CustEvalError();
var te = new CustTypeError();
var re = new CustReferenceError();
var ra = new CustRangeError();

AddTestCase( "var error = new CustError()", "Error", error.toString() );
AddTestCase( "var ee = new CustEvalError()", "EvalError", ee.toString() );
AddTestCase( "var te = new CustTypeError()", "TypeError", te.toString() );
AddTestCase( "var re = new CustReferenceError()", "ReferenceError", re.toString() );
AddTestCase( "var ra = new CustRangeError()", "RangeError", ra.toString() );

AddTestCase( "typeof new CustError()", "object", typeof new CustError() );
AddTestCase( "typeof new CustEvalError()", "object", typeof new CustEvalError() );
AddTestCase( "typeof new CustTypeError()", "object", typeof new CustTypeError() );
AddTestCase( "typeof new CustReferenceError()", "object", typeof new CustReferenceError() );
AddTestCase( "typeof new CustRangeError()", "object", typeof new CustRangeError() );


// dynamic Cust Error Cases

error = new CustError2();
ee = new CustEvalError2();
te = new CustTypeError2();
re = new CustReferenceError2();
ra = new CustRangeError2();

AddTestCase( "var error = new CustError2()", "Error", error.toString() );
AddTestCase( "var ee = new CustEvalError2()", "EvalError", ee.toString() );
AddTestCase( "var te = new CustTypeError2()", "TypeError", te.toString() );
AddTestCase( "var re = new CustReferenceError2()", "ReferenceError", re.toString() );
AddTestCase( "var ra = new CustRangeError2()", "RangeError", ra.toString() );

error = new CustError2("test");
ee = new CustEvalError2("eval error");
te = new CustTypeError2("type error");
re = new CustReferenceError2("reference error");
ra = new CustRangeError2("range error");

AddTestCase( "var error = new CustError2('test')", "Error: test", error.toString() );
AddTestCase( "var ee = new CustEvalError2('eval error')", "EvalError: eval error", ee.toString() );
AddTestCase( "var te = new CustTypeError2('type error')", "TypeError: type error", te.toString() );
AddTestCase( "var re = new CustReferenceError2('reference error')", "ReferenceError: reference error", re.toString() );
AddTestCase( "var ra = new CustRangeError2('range error')", "RangeError: range error", ra.toString() );

AddTestCase( "typeof new CustError2()", "object", typeof new CustError2() );
AddTestCase( "typeof new CustEvalError2()", "object", typeof new CustEvalError2() );
AddTestCase( "typeof new CustTypeError2()", "object", typeof new CustTypeError2() );
AddTestCase( "typeof new CustReferenceError2()", "object", typeof new CustReferenceError2() );
AddTestCase( "typeof new CustRangeError2()", "object", typeof new CustRangeError2() );

AddTestCase( "typeof new CustError2('test')", "object", typeof new CustError2('test') );
AddTestCase( "typeof new CustEvalError2('test')", "object", typeof new CustEvalError2('test') );
AddTestCase( "typeof new CustTypeError2('test')", "object", typeof new CustTypeError2('test') );
AddTestCase( "typeof new CustReferenceError2('test')", "object", typeof new CustReferenceError2('test') );
AddTestCase( "typeof new CustRangeError2('test')", "object", typeof new CustRangeError2('test') );


AddTestCase( "(err = new CustError2(), err.getClass = Object.prototype.toString, err.getClass() )",
             "[object CustError2]",
             (err = new CustError2(), err.getClass = Object.prototype.toString, err.getClass() ) );
AddTestCase( "(err = new CustEvalError2(), err.getClass = Object.prototype.toString, err.getClass() )",
             "[object CustEvalError2]",
             (err = new CustEvalError2(), err.getClass = Object.prototype.toString, err.getClass() ) );
AddTestCase( "(err = new CustTypeError2(), err.getClass = Object.prototype.toString, err.getClass() )",
             "[object CustTypeError2]",
             (err = new CustTypeError2(), err.getClass = Object.prototype.toString, err.getClass() ) );
AddTestCase( "(err = new CustReferenceError2(), err.getClass = Object.prototype.toString, err.getClass() )",
             "[object CustReferenceError2]",
             (err = new CustReferenceError2(), err.getClass = Object.prototype.toString, err.getClass() ) );
AddTestCase( "(err = new CustRangeError2(), err.getClass = Object.prototype.toString, err.getClass() )",
             "[object CustRangeError2]",
             (err = new CustRangeError2(), err.getClass = Object.prototype.toString, err.getClass() ) );

AddTestCase( "(err = new CustError2('test'), err.getClass = Object.prototype.toString, err.getClass() )",
             "[object CustError2]",
             (err = new CustError2('test'), err.getClass = Object.prototype.toString, err.getClass() ) );
AddTestCase( "(err = new CustEvalError2('test'), err.getClass = Object.prototype.toString, err.getClass() )",
             "[object CustEvalError2]",
             (err = new CustEvalError2('test'), err.getClass = Object.prototype.toString, err.getClass() ) );
AddTestCase( "(err = new CustTypeError2('test'), err.getClass = Object.prototype.toString, err.getClass() )",
             "[object CustTypeError2]",
             (err = new CustTypeError2('test'), err.getClass = Object.prototype.toString, err.getClass() ) );
AddTestCase( "(err = new CustReferenceError2('test'), err.getClass = Object.prototype.toString, err.getClass() )",
             "[object CustReferenceError2]",
             (err = new CustReferenceError2('test'), err.getClass = Object.prototype.toString, err.getClass() ) );
AddTestCase( "(err = new CustRangeError2('test'), err.getClass = Object.prototype.toString, err.getClass() )",
             "[object CustRangeError2]",
             (err = new CustRangeError2('test'), err.getClass = Object.prototype.toString, err.getClass() ) );



test();       // leave this alone.  this executes the test cases and
              // displays results.
