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
 * Portions created by the Initial Developer are Copyright (C) 2005-2006
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

    var SECTION = "15.5.1";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "The String Constructor Called as a Function";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION,	"String('string primitive')",	"string primitive",	String('string primitive') );
    array[item++] = new TestCase( SECTION,	"String(void 0)",		"undefined",		String( void 0) );
    array[item++] = new TestCase( SECTION,	"String(null)","null",String(null));
    array[item++] = new TestCase( SECTION,	"String(true)",			    "true",			String( true) );
    array[item++] = new TestCase( SECTION,	"String(false)",		    "false",		String( false ) );
    array[item++] = new TestCase( SECTION,	"String(Boolean(true))",	"true",			String(Boolean(true)) );
    array[item++] = new TestCase( SECTION,	"String(Boolean(false))",	"false",		String(Boolean(false)) );
    array[item++] = new TestCase( SECTION,	"String(Boolean())",		"false",		String(Boolean(false)) );
    array[item++] = new TestCase( SECTION,	"String(new Array())",		"",			    String( new Array()) );
    array[item++] = new TestCase( SECTION,	"String(new Array(1,2,3))",	"1,2,3",		String( new Array(1,2,3)) );


    array[item++] = new TestCase( SECTION,    "String( Number.NaN )",       "NaN",                  String( Number.NaN ) );
    array[item++] = new TestCase( SECTION,    "String( 0 )",                "0",                    String( 0 ) );
    array[item++] = new TestCase( SECTION,    "String( -0 )",               "0",                   String( -0 ) );
    array[item++] = new TestCase( SECTION,    "String( Number.POSITIVE_INFINITY )", "Infinity",     String( Number.POSITIVE_INFINITY ) );
    array[item++] = new TestCase( SECTION,    "String( Number.NEGATIVE_INFINITY )", "-Infinity",    String( Number.NEGATIVE_INFINITY ) );
    array[item++] = new TestCase( SECTION,    "String( -1 )",               "-1",                   String( -1 ) );

    // cases in step 6:  integers  1e21 > x >= 1 or -1 >= x > -1e21

    array[item++] = new TestCase( SECTION,    "String( 1 )",                    "1",                    String( 1 ) );
    array[item++] = new TestCase( SECTION,    "String( 10 )",                   "10",                   String( 10 ) );
    array[item++] = new TestCase( SECTION,    "String( 100 )",                  "100",                  String( 100 ) );
    array[item++] = new TestCase( SECTION,    "String( 1000 )",                 "1000",                 String( 1000 ) );
    array[item++] = new TestCase( SECTION,    "String( 10000 )",                "10000",                String( 10000 ) );
    array[item++] = new TestCase( SECTION,    "String( 10000000000 )",          "10000000000",          String( 10000000000 ) );
    array[item++] = new TestCase( SECTION,    "String( 10000000000000000000 )", "10000000000000000000", String( 10000000000000000000 ) );
    array[item++] = new TestCase( SECTION,    "String( 100000000000000000000 )","100000000000000000000",String( 100000000000000000000 ) );

    array[item++] = new TestCase( SECTION,    "String( 12345 )",                    "12345",                    String( 12345 ) );
    array[item++] = new TestCase( SECTION,    "String( 1234567890 )",               "1234567890",               String( 1234567890 ) );

    array[item++] = new TestCase( SECTION,    "String( -1 )",                       "-1",                       String( -1 ) );
    array[item++] = new TestCase( SECTION,    "String( -10 )",                      "-10",                      String( -10 ) );
    array[item++] = new TestCase( SECTION,    "String( -100 )",                     "-100",                     String( -100 ) );
    array[item++] = new TestCase( SECTION,    "String( -1000 )",                    "-1000",                    String( -1000 ) );
    array[item++] = new TestCase( SECTION,    "String( -1000000000 )",              "-1000000000",              String( -1000000000 ) );
    array[item++] = new TestCase( SECTION,    "String( -1000000000000000 )",        "-1000000000000000",        String( -1000000000000000 ) );
    array[item++] = new TestCase( SECTION,    "String( -100000000000000000000 )",   "-100000000000000000000",   String( -100000000000000000000 ) );
    array[item++] = new TestCase( SECTION,    "String( -1000000000000000000000 )",  "-1e+21",                   String( -1000000000000000000000 ) );

    array[item++] = new TestCase( SECTION,    "String( -12345 )",                    "-12345",                  String( -12345 ) );
    array[item++] = new TestCase( SECTION,    "String( -1234567890 )",               "-1234567890",             String( -1234567890 ) );

    // cases in step 7: numbers with a fractional component, 1e21> x >1 or  -1 > x > -1e21,
    array[item++] = new TestCase( SECTION,    "String( 1.0000001 )",                "1.0000001",                String( 1.0000001 ) );


    // cases in step 8:  fractions between 1 > x > -1, exclusive of 0 and -0

    // cases in step 9:  numbers with 1 significant digit >= 1e+21 or <= 1e-6

    array[item++] = new TestCase( SECTION,    "String( 1000000000000000000000 )",   "1e+21",             String( 1000000000000000000000 ) );
    array[item++] = new TestCase( SECTION,    "String( 10000000000000000000000 )",   "1e+22",            String( 10000000000000000000000 ) );

    //  cases in step 10:  numbers with more than 1 significant digit >= 1e+21 or <= 1e-6
    array[item++] = new TestCase( SECTION,    "String( 1.2345 )",                    "1.2345",                  String( 1.2345));
    array[item++] = new TestCase( SECTION,    "String( 1.234567890 )",               "1.23456789",             String( 1.234567890 ));

    array[item++] = new TestCase( SECTION,    "String( .12345 )",                   "0.12345",               String(.12345 )     );
    array[item++] = new TestCase( SECTION,    "String( .012345 )",                  "0.012345",              String(.012345)     );
    array[item++] = new TestCase( SECTION,    "String( .0012345 )",                 "0.0012345",             String(.0012345)    );
    array[item++] = new TestCase( SECTION,    "String( .00012345 )",                "0.00012345",            String(.00012345)   );
    array[item++] = new TestCase( SECTION,    "String( .000012345 )",               "0.000012345",           String(.000012345)  );
    array[item++] = new TestCase( SECTION,    "String( .0000012345 )",              "0.0000012345",          String(.0000012345) );
    array[item++] = new TestCase( SECTION,    "String( .00000012345 )",             "1.2345e-7",            String(.00000012345));

    array[item++] = new TestCase( "15.5.2",	"String()","",String() );

    return ( array );
}
