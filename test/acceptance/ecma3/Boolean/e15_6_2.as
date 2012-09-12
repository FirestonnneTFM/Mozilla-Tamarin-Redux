/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
    var SECTION = "15.6.2";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "15.6.2 The Boolean Constructor; 15.6.2.1 new Boolean( value ); 15.6.2.2 new Boolean()";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,   "typeof (new Boolean(1))",         "boolean",            typeof (new Boolean(1)) );
    array[item++] = new TestCase( SECTION,   "(new Boolean(1)).constructor",    Boolean.prototype.constructor,   (new Boolean(1)).constructor );

    var TESTBOOL:Boolean=new Boolean(1);
    array[item++] = new TestCase( SECTION,"TESTBOOL.toString()","true",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean(1)).valueOf()",true,         (new Boolean(1)).valueOf() );
    array[item++] = new TestCase( SECTION,"typeof new Boolean(1)","boolean",    typeof (new Boolean(1)) );
    array[item++] = new TestCase( SECTION,   "(new Boolean(0)).constructor",    Boolean.prototype.constructor,   (new Boolean(0)).constructor );

    var TESTBOOL:Boolean=new Boolean(0);
    array[item++] = new TestCase( SECTION, "TESTBOOL.toString()","false",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean(0)).valueOf()",   false,       (new Boolean(0)).valueOf() );
    array[item++] = new TestCase( SECTION,   "typeof new Boolean(0)","boolean",typeof (new Boolean(0)) );
    array[item++] = new TestCase( SECTION,   "(new Boolean(-1)).constructor",    Boolean.prototype.constructor,   (new Boolean(-1)).constructor );

    var TESTBOOL:Boolean=new Boolean(-1);
    array[item++] = new TestCase( SECTION,"TESTBOOL.toString()","true",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean(-1)).valueOf()",   true,       (new Boolean(-1)).valueOf() );
    array[item++] = new TestCase( SECTION,   "typeof new Boolean(-1)",         "boolean",   typeof (new Boolean(-1)) );
    array[item++] = new TestCase( SECTION,   "(new Boolean('')).constructor",    Boolean.prototype.constructor,   (new Boolean('')).constructor );

    var TESTBOOL:Boolean=new Boolean("");
    array[item++] = new TestCase( SECTION, "TESTBOOL.toString()", "false",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean('')).valueOf()",   false,       (new Boolean("")).valueOf() );
    array[item++] = new TestCase( SECTION,   "typeof new Boolean('')",         "boolean",   typeof (new Boolean("")) );
    array[item++] = new TestCase( SECTION,   "(new Boolean('1')).constructor",    Boolean.prototype.constructor,   (new Boolean("1")).constructor );

    var TESTBOOL:Boolean=new Boolean('1');
    array[item++] = new TestCase( SECTION, "TESTBOOL.toString()", "true",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean('1')).valueOf()",   true,       (new Boolean('1')).valueOf() );
    array[item++] = new TestCase( SECTION,   "typeof new Boolean('1')",         "boolean",   typeof (new Boolean('1')) );
    array[item++] = new TestCase( SECTION,   "(new Boolean('0')).constructor",    Boolean.prototype.constructor,   (new Boolean('0')).constructor );

    var TESTBOOL:Boolean=new Boolean('0');
    array[item++] = new TestCase( SECTION, "TESTBOOL.toString()", "true",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean('0')).valueOf()",   true,       (new Boolean('0')).valueOf() );
    array[item++] = new TestCase( SECTION,   "typeof new Boolean('0')",         "boolean",   typeof (new Boolean('0')) );
    array[item++] = new TestCase( SECTION,   "(new Boolean('-1')).constructor",    Boolean.prototype.constructor,   (new Boolean('-1')).constructor );

    var TESTBOOL:Boolean=new Boolean('-1');
    array[item++] = new TestCase( SECTION, "TESTBOOL.toString()","true",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean('-1')).valueOf()",   true,       (new Boolean('-1')).valueOf() );
    array[item++] = new TestCase( SECTION,   "typeof new Boolean('-1')",         "boolean",   typeof (new Boolean('-1')) );
    array[item++] = new TestCase( SECTION,   "(new Boolean(new Boolean(true))).constructor",    Boolean.prototype.constructor,   (new Boolean(new Boolean(true))).constructor );

    var TESTBOOL:Boolean=new Boolean(new Boolean(true));
    array[item++] = new TestCase( SECTION, "TESTBOOL.toString()", "true",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean(new Boolean(true))).valueOf()",   true,       (new Boolean(new Boolean(true))).valueOf() );
    array[item++] = new TestCase( SECTION,   "typeof new Boolean(new Boolean(true))",         "boolean",   typeof (new Boolean(new Boolean(true))) );
    array[item++] = new TestCase( SECTION,   "(new Boolean(Number.NaN)).constructor",    Boolean.prototype.constructor,   (new Boolean(Number.NaN)).constructor );

    var TESTBOOL:Boolean=new Boolean(Number.NaN);
    array[item++] = new TestCase( SECTION,"TESTBOOL.toString()","false",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean(Number.NaN)).valueOf()",   false,       (new Boolean(Number.NaN)).valueOf() );
    array[item++] = new TestCase( SECTION,   "typeof new Boolean(Number.NaN)",         "boolean",   typeof (new Boolean(Number.NaN)) );
    array[item++] = new TestCase( SECTION,   "(new Boolean(null)).constructor",    Boolean.prototype.constructor,   (new Boolean(null)).constructor );

    var TESTBOOL:Boolean=new Boolean(null);
    array[item++] = new TestCase( SECTION, "TESTBOOL.toString()","false",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean(null)).valueOf()",   false,       (new Boolean(null)).valueOf() );
    array[item++] = new TestCase( SECTION,   "typeof new Boolean(null)",         "boolean",   typeof (new Boolean(null)) );
    array[item++] = new TestCase( SECTION,   "(new Boolean(void 0)).constructor",    Boolean.prototype.constructor,   (new Boolean(void 0)).constructor );

    var TESTBOOL:Boolean=new Boolean(void 0);
    array[item++] = new TestCase( SECTION, "TESTBOOL.toString()","false",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean(void 0)).valueOf()",   false,       (new Boolean(void 0)).valueOf() );
    array[item++] = new TestCase( SECTION,   "typeof new Boolean(void 0)",         "boolean",   typeof (new Boolean(void 0)) );
    array[item++] = new TestCase( SECTION,   "(new Boolean(Number.POSITIVE_INFINITY)).constructor",    Boolean.prototype.constructor,   (new Boolean(Number.POSITIVE_INFINITY)).constructor );

    var TESTBOOL:Boolean=new Boolean(Number.POSITIVE_INFINITY);
    array[item++] = new TestCase( SECTION, "TESTBOOL.toString()", "true",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean(Number.POSITIVE_INFINITY)).valueOf()",   true,       (new Boolean(Number.POSITIVE_INFINITY)).valueOf() );
    array[item++] = new TestCase( SECTION,   "typeof new Boolean(Number.POSITIVE_INFINITY)",         "boolean",   typeof (new Boolean(Number.POSITIVE_INFINITY)) );
    array[item++] = new TestCase( SECTION,   "(new Boolean(Number.NEGATIVE_INFINITY)).constructor",    Boolean.prototype.constructor,   (new Boolean(Number.NEGATIVE_INFINITY)).constructor );

    var TESTBOOL:Boolean=new Boolean(Number.NEGATIVE_INFINITY);
    array[item++] = new TestCase( SECTION, "TESTBOOL.toString()", "true",TESTBOOL.toString());
    array[item++] = new TestCase( SECTION,   "(new Boolean(Number.NEGATIVE_INFINITY)).valueOf()",   true,       (new Boolean(Number.NEGATIVE_INFINITY)).valueOf() );
    array[item++] = new TestCase( SECTION,   "typeof new Boolean(Number.NEGATIVE_INFINITY)",         "boolean",   typeof (new Boolean(Number.NEGATIVE_INFINITY) ));
    array[item++] = new TestCase( SECTION,   "(new Boolean(Number.NEGATIVE_INFINITY)).constructor",    Boolean.prototype.constructor,   (new Boolean(Number.NEGATIVE_INFINITY)).constructor );

    var TESTBOOL:Boolean=new Boolean();
    array[item++] = new TestCase( "15.6.2.2", "TESTBOOL.toString()","false",TESTBOOL.toString());
    array[item++] = new TestCase( "15.6.2.2",   "(new Boolean()).valueOf()",   false,       (new Boolean()).valueOf() );
    array[item++] = new TestCase( "15.6.2.2",   "typeof new Boolean()",        "boolean",    typeof (new Boolean()) );

    return ( array );
}
