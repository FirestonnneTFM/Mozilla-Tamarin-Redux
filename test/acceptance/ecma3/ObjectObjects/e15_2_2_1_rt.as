/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

    var SECTION = "15.2.2.1";
    var VERSION = "ECMA_4";
    startTest();
    var TITLE   = "new Object( value )";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,  "typeof new Object(null)",      "object",           typeof new Object(null) );
    MYOB = new Object(null);
    MYOB.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,  "MYOB = new Object(null); MYOB.toString = Object.prototype.toString; MYOB.toString()",  "[object Object]",    MYOB.toString());

    array[item++] = new TestCase( SECTION,  "typeof new Object(void 0)",      "object",           typeof new Object(void 0) );
    MYOB = new Object(new Object(void 0));
    MYOB.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,  "MYOB = new Object(new Object(void 0)); MYOB.toString = Object.prototype.toString; MYOB.toString()",  "[object Object]",    MYOB.toString());

    array[item++] = new TestCase( SECTION,  "typeof new Object(undefined)",      "object",           typeof new Object(undefined) );
    MYOB = new Object(new Object(undefined));
    MYOB.toString = Object.prototype.toString;
    array[item++] = new TestCase( SECTION,  "MYOB = new Object(new Object(undefined)); MYOB.toString = Object.prototype.toString; MYOB.toString()",  "[object Object]",    MYOB.toString());

    array[item++] = new TestCase( SECTION,  "typeof new Object('string')",      "string",           typeof new Object('string') );

    MYOB = new Object('string');
    array[item++] = new TestCase( SECTION,  "MYOB = (new Object('string'); MYOB.toString = Object.prototype.toString; MYOB.toString()",  "string", MYOB.toString());

    array[item++] = new TestCase( SECTION,  "(new Object('string').valueOf()",  "string",           (new Object('string')).valueOf() );

    array[item++] = new TestCase( SECTION,  "typeof new Object('')",            "string",           typeof new Object('') );
    MYOB = new Object('');
    array[item++] = new TestCase( SECTION,  "MYOB = (new Object(''); MYOB.toString = Object.prototype.toString; MYOB.toString()",  "", MYOB.toString());

    array[item++] = new TestCase( SECTION,  "(new Object('').valueOf()",        "",                 (new Object('')).valueOf() );

    array[item++] = new TestCase( SECTION,  "typeof new Object(Number.NaN)",      "number",                 typeof new Object(Number.NaN) );
    MYOB = new Object(Number.NaN);
    array[item++] = new TestCase( SECTION,  "MYOB = (new Object(Number.NaN); MYOB.toStriobjectng = Object.prototype.toString; MYOB.toString()",  "NaN", MYOB.toString() );
    array[item++] = new TestCase( SECTION,  "(new Object(Number.NaN).valueOf()",  Number.NaN,               (new Object(Number.NaN)).valueOf() );

    array[item++] = new TestCase( SECTION,  "typeof new Object(0)",      "number",                 typeof new Object(0) );
    MYOB = new Object(0);
    array[item++] = new TestCase( SECTION,  "MYOB = (new Object(0); MYOB.toString = Object.prototype.toString; MYOB.toString()",  "0", MYOB.toString());
    array[item++] = new TestCase( SECTION,  "(new Object(0).valueOf()",  0,               (new Object(0)).valueOf() );

    array[item++] = new TestCase( SECTION,  "typeof new Object(-0)",      "number",                 typeof new Object(-0) );
    MYOB = new Object(-0);
    array[item++] = new TestCase( SECTION,  "MYOB = (new Object(-0); MYOB.toString = Object.prototype.toString; MYOB.toString()",  "0", MYOB.toString() );
    array[item++] = new TestCase( SECTION,  "(new Object(-0).valueOf()",  -0,               (new Object(-0)).valueOf() );

    array[item++] = new TestCase( SECTION,  "typeof new Object(1)",      "number",                 typeof new Object(1) );
    MYOB = new Object(1);
    array[item++] = new TestCase( SECTION,  "MYOB = (new Object(1); MYOB.toString = Object.prototype.toString; MYOB.toString()",  "1",    MYOB.toString() );
    array[item++] = new TestCase( SECTION,  "(new Object(1).valueOf()",  1,               (new Object(1)).valueOf() );

    array[item++] = new TestCase( SECTION,  "typeof new Object(-1)",      "number",                 typeof new Object(-1) );
    MYOB = new Object(-1);
    array[item++] = new TestCase( SECTION,  "MYOB = (new Object(-1); MYOB.toString = Object.prototype.toString; MYOB.toString()",  "-1",    MYOB.toString() );
    array[item++] = new TestCase( SECTION,  "(new Object(-1).valueOf()",  -1,               (new Object(-1)).valueOf() );

    array[item++] = new TestCase( SECTION,  "typeof new Object(true)",      "boolean",                 typeof new Object(true) );
    Boolean.prototype.valueOf=Object.prototype.valueOf;
    MYOB = new Object(true);
    array[item++] = new TestCase( SECTION,  "MYOB = (new Object(true); MYOB.toString = Object.prototype.toString; MYOB.toString()",  "true",  MYOB.toString() );
    array[item++] = new TestCase( SECTION,  "(new Object(true).valueOf()",  true,               (new Object(true)).valueOf() );

    array[item++] = new TestCase( SECTION,  "typeof new Object(false)",      "boolean",              typeof new Object(false) );
    MYOB = new Object(false);
    array[item++] = new TestCase( SECTION,  "MYOB = (new Object(false); MYOB.toString = Object.prototype.toString; MYOB.toString()",  "false",  MYOB.toString() );
    array[item++] = new TestCase( SECTION,  "(new Object(false).valueOf()",  false,                 (new Object(false)).valueOf() );

    array[item++] = new TestCase( SECTION,  "typeof new Object(Boolean())",         "boolean",               typeof new Object(Boolean()) );
    MYOB = new Object(Boolean());
    array[item++] = new TestCase( SECTION,  "MYOB = (new Object(Boolean()); MYOB.toString = Object.prototype.toString; MYOB.toString()",  "false",  MYOB.toString() );
    array[item++] = new TestCase( SECTION,  "(new Object(Boolean()).valueOf()",     Boolean(),              (new Object(Boolean())).valueOf() );

    var myglobal    = this;
    var myobject    = new Object( "my new object" );
    var myarray     = new Array();
    var myboolean   = new Boolean();
    var mynumber    = new Number();
    var mystring    = new String();
    var myobject    = new Object();
    myfunction      = function(x){return x;}
    var mymath      = Math;
    var myregexp    = new RegExp(new String(''));

    function myobj():String{
        function f():String{
            return "hi!";
        }
    return f();
    }

    array[item++] = new TestCase( SECTION, "myglobal = new Object( this )",                     myglobal,       new Object(this) );
    array[item++] = new TestCase( SECTION, "myobject = new Object('my new object'); new Object(myobject)",            myobject,       new Object(myobject) );
    array[item++] = new TestCase( SECTION, "myarray = new Array(); new Object(myarray)",        myarray,        new Object(myarray) );
    array[item++] = new TestCase( SECTION, "myboolean = new Boolean(); new Object(myboolean)",  myboolean,      new Object(myboolean) );
    array[item++] = new TestCase( SECTION, "mynumber = new Number(); new Object(mynumber)",     mynumber,       new Object(mynumber) );
    array[item++] = new TestCase( SECTION, "mystring = new String(); new Object(mystring)",     mystring,       new Object(mystring) );
    array[item++] = new TestCase( SECTION, "myobject = new Object(); new Object(myobject)",    myobject,       new Object(myobject) );
    array[item++] = new TestCase( SECTION, "myfunction = function(x){return x;} new Object(myfunction)", myfunction,   new Object(myfunction) );
    array[item++] = new TestCase( SECTION, "function myobj(){function f(){}return f() new Object(myobj)", myobj,   new Object(myobj) );
    array[item++] = new TestCase( SECTION, "mymath = Math; new Object(mymath)",                 mymath,         new Object(mymath) );
    array[item++] = new TestCase( SECTION, "myregexp = new RegExp(new String('')), new Object(myregexp)",                 myregexp,         new Object(myregexp) );

    return ( array );
}
