use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "dqAbs.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// dqabs.dectest -- decquad absolute value, heeding snan              --
// copyright (c) ibm corporation, 1981, 2007.  all rights reserved.   --
//----------------------------------------------------------------------
// please see the document "general decimal arithmetic testcases"     --
// at http://www2.hursley.ibm.com/decimal for the description of      --
// these testcases.                                                   --
//                                                                    --
// these testcases are experimental ('beta' versions), and they       --
// may contain errors.  they are offered on an as-is basis.  in       --
// particular, achieving the same results as the tests here is not    --
// a guarantee that an implementation complies with any standard      --
// or specification.  the tests are not exhaustive.                   --
//                                                                    --
// please send comments, suggestions, and corrections to the author:  --
//   mike cowlishaw, ibm fellow                                       --
//   ibm uk, po box 31, birmingham road, warwick cv34 5jl, uk         --
//   mfc@uk.ibm.com                                                   --
//----------------------------------------------------------------------
// version: 2.55
use rounding HALF_EVEN;
AddTestCase("dqabs001:p9 r:HALF_EVEN (decimal.abs(1))", 1, decimal.abs(1));
AddTestCase("dqabs002:p9 r:HALF_EVEN (decimal.abs(-1))", 1, decimal.abs(-1));
AddTestCase("dqabs003:p9 r:HALF_EVEN (decimal.abs(1.00))", 1.00, decimal.abs(1.00));
AddTestCase("dqabs004:p9 r:HALF_EVEN (decimal.abs(-1.00))", 1.00, decimal.abs(-1.00));
AddTestCase("dqabs005:p9 r:HALF_EVEN (decimal.abs(0))", 0, decimal.abs(0));
AddTestCase("dqabs006:p9 r:HALF_EVEN (decimal.abs(0.00))", 0.00, decimal.abs(0.00));
AddTestCase("dqabs007:p9 r:HALF_EVEN (decimal.abs(00.0))", 0.0, decimal.abs(00.0));
AddTestCase("dqabs008:p9 r:HALF_EVEN (decimal.abs(00.00))", 0.00, decimal.abs(00.00));
AddTestCase("dqabs009:p9 r:HALF_EVEN (decimal.abs(00))", 0, decimal.abs(00));
AddTestCase("dqabs010:p9 r:HALF_EVEN (decimal.abs(-2))", 2, decimal.abs(-2));
AddTestCase("dqabs011:p9 r:HALF_EVEN (decimal.abs(2))", 2, decimal.abs(2));
AddTestCase("dqabs012:p9 r:HALF_EVEN (decimal.abs(-2.00))", 2.00, decimal.abs(-2.00));
AddTestCase("dqabs013:p9 r:HALF_EVEN (decimal.abs(2.00))", 2.00, decimal.abs(2.00));
AddTestCase("dqabs014:p9 r:HALF_EVEN (decimal.abs(-0))", 0, decimal.abs(-0));
AddTestCase("dqabs015:p9 r:HALF_EVEN (decimal.abs(-0.00))", 0.00, decimal.abs(-0.00));
AddTestCase("dqabs016:p9 r:HALF_EVEN (decimal.abs(-00.0))", 0.0, decimal.abs(-00.0));
AddTestCase("dqabs017:p9 r:HALF_EVEN (decimal.abs(-00.00))", 0.00, decimal.abs(-00.00));
AddTestCase("dqabs018:p9 r:HALF_EVEN (decimal.abs(-00))", 0, decimal.abs(-00));
AddTestCase("dqabs020:p9 r:HALF_EVEN (decimal.abs(-2000000))", 2000000, decimal.abs(-2000000));
AddTestCase("dqabs021:p9 r:HALF_EVEN (decimal.abs(2000000))", 2000000, decimal.abs(2000000));
AddTestCase("dqabs030:p9 r:HALF_EVEN (decimal.abs(+0.1))", 0.1, decimal.abs(+0.1));
AddTestCase("dqabs031:p9 r:HALF_EVEN (decimal.abs(-0.1))", 0.1, decimal.abs(-0.1));
AddTestCase("dqabs032:p9 r:HALF_EVEN (decimal.abs(+0.01))", 0.01, decimal.abs(+0.01));
AddTestCase("dqabs033:p9 r:HALF_EVEN (decimal.abs(-0.01))", 0.01, decimal.abs(-0.01));
AddTestCase("dqabs034:p9 r:HALF_EVEN (decimal.abs(+0.001))", 0.001, decimal.abs(+0.001));
AddTestCase("dqabs035:p9 r:HALF_EVEN (decimal.abs(-0.001))", 0.001, decimal.abs(-0.001));
AddTestCase("dqabs036:p9 r:HALF_EVEN (decimal.abs(+0.000001))", 0.000001, decimal.abs(+0.000001));
AddTestCase("dqabs037:p9 r:HALF_EVEN (decimal.abs(-0.000001))", 0.000001, decimal.abs(-0.000001));
AddTestCase("dqabs038:p9 r:HALF_EVEN (decimal.abs(+0.000000000001))", 1e-12, decimal.abs(+0.000000000001));
AddTestCase("dqabs039:p9 r:HALF_EVEN (decimal.abs(-0.000000000001))", 1e-12, decimal.abs(-0.000000000001));
// examples from decarith
AddTestCase("dqabs040:p9 r:HALF_EVEN (decimal.abs(2.1))", 2.1, decimal.abs(2.1));
AddTestCase("dqabs041:p9 r:HALF_EVEN (decimal.abs(-100))", 100, decimal.abs(-100));
AddTestCase("dqabs042:p9 r:HALF_EVEN (decimal.abs(101.5))", 101.5, decimal.abs(101.5));
AddTestCase("dqabs043:p9 r:HALF_EVEN (decimal.abs(-101.5))", 101.5, decimal.abs(-101.5));
// more fixed, potential lhs swaps/overlays if done by subtract 0
AddTestCase("dqabs060:p9 r:HALF_EVEN (decimal.abs(-56267e-10))", 0.0000056267, decimal.abs(-56267e-10));
AddTestCase("dqabs061:p9 r:HALF_EVEN (decimal.abs(-56267e-5))", 0.56267, decimal.abs(-56267e-5));
AddTestCase("dqabs062:p9 r:HALF_EVEN (decimal.abs(-56267e-2))", 562.67, decimal.abs(-56267e-2));
AddTestCase("dqabs063:p9 r:HALF_EVEN (decimal.abs(-56267e-1))", 5626.7, decimal.abs(-56267e-1));
AddTestCase("dqabs065:p9 r:HALF_EVEN (decimal.abs(-56267e-0))", 56267, decimal.abs(-56267e-0));
// subnormals and underflow
// long operand tests
AddTestCase("dqabs321:p9 r:HALF_EVEN (decimal.abs(1234567890123456))", 1234567890123456, decimal.abs(1234567890123456));
AddTestCase("dqabs322:p9 r:HALF_EVEN (decimal.abs(12345678000))", 12345678000, decimal.abs(12345678000));
AddTestCase("dqabs323:p9 r:HALF_EVEN (decimal.abs(1234567800))", 1234567800, decimal.abs(1234567800));
AddTestCase("dqabs324:p9 r:HALF_EVEN (decimal.abs(1234567890))", 1234567890, decimal.abs(1234567890));
AddTestCase("dqabs325:p9 r:HALF_EVEN (decimal.abs(1234567891))", 1234567891, decimal.abs(1234567891));
AddTestCase("dqabs326:p9 r:HALF_EVEN (decimal.abs(12345678901))", 12345678901, decimal.abs(12345678901));
AddTestCase("dqabs327:p9 r:HALF_EVEN (decimal.abs(1234567896))", 1234567896, decimal.abs(1234567896));
// zeros
AddTestCase("dqabs111:p9 r:HALF_EVEN (decimal.abs(0))", 0, decimal.abs(0));
AddTestCase("dqabs112:p9 r:HALF_EVEN (decimal.abs(-0))", 0, decimal.abs(-0));
AddTestCase("dqabs113:p9 r:HALF_EVEN (decimal.abs(0e+6))", 0e+6, decimal.abs(0e+6));
AddTestCase("dqabs114:p9 r:HALF_EVEN (decimal.abs(-0e+6))", 0e+6, decimal.abs(-0e+6));
AddTestCase("dqabs115:p9 r:HALF_EVEN (decimal.abs(0.0000))", 0.0000, decimal.abs(0.0000));
AddTestCase("dqabs116:p9 r:HALF_EVEN (decimal.abs(-0.0000))", 0.0000, decimal.abs(-0.0000));
AddTestCase("dqabs117:p9 r:HALF_EVEN (decimal.abs(0e-141))", 0e-141, decimal.abs(0e-141));
AddTestCase("dqabs118:p9 r:HALF_EVEN (decimal.abs(-0e-141))", 0e-141, decimal.abs(-0e-141));
// full coefficients, alternating bits
AddTestCase("dqabs121:p9 r:HALF_EVEN (decimal.abs(2682682682682682682682682682682682))", 2682682682682682682682682682682682, decimal.abs(2682682682682682682682682682682682));
AddTestCase("dqabs122:p9 r:HALF_EVEN (decimal.abs(-2682682682682682682682682682682682))", 2682682682682682682682682682682682, decimal.abs(-2682682682682682682682682682682682));
AddTestCase("dqabs123:p9 r:HALF_EVEN (decimal.abs(1341341341341341341341341341341341))", 1341341341341341341341341341341341, decimal.abs(1341341341341341341341341341341341));
AddTestCase("dqabs124:p9 r:HALF_EVEN (decimal.abs(-1341341341341341341341341341341341))", 1341341341341341341341341341341341, decimal.abs(-1341341341341341341341341341341341));
// nmax, nmin, ntiny
AddTestCase("dqabs131:p9 r:HALF_EVEN (decimal.abs(9.999999999999999999999999999999999e+6144))", 9.999999999999999999999999999999999e+6144, decimal.abs(9.999999999999999999999999999999999e+6144));
AddTestCase("dqabs132:p9 r:HALF_EVEN (decimal.abs(1e-6143))", 1e-6143, decimal.abs(1e-6143));
AddTestCase("dqabs133:p9 r:HALF_EVEN (decimal.abs(1.000000000000000000000000000000000e-6143))", 1.000000000000000000000000000000000e-6143, decimal.abs(1.000000000000000000000000000000000e-6143));
AddTestCase("dqabs136:p9 r:HALF_EVEN (decimal.abs(-1.000000000000000000000000000000000e-6143))", 1.000000000000000000000000000000000e-6143, decimal.abs(-1.000000000000000000000000000000000e-6143));
AddTestCase("dqabs137:p9 r:HALF_EVEN (decimal.abs(-1e-6143))", 1e-6143, decimal.abs(-1e-6143));
AddTestCase("dqabs138:p9 r:HALF_EVEN (decimal.abs(-9.999999999999999999999999999999999e+6144))", 9.999999999999999999999999999999999e+6144, decimal.abs(-9.999999999999999999999999999999999e+6144));
// specials
AddTestCase("dqabs520:p9 r:HALF_EVEN (decimal.abs(decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.abs(decimal.POSITIVE_INFINITY));
AddTestCase("dqabs521:p9 r:HALF_EVEN (decimal.abs(decimal.NEGATIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.abs(decimal.NEGATIVE_INFINITY));
AddTestCase("dqabs522:p9 r:HALF_EVEN (decimal.abs(NaN))", NaN, decimal.abs(NaN));
AddTestCase("dqabs523:p9 r:HALF_EVEN (decimal.abs(NaN)) invalid_operation", NaN, decimal.abs(NaN));
AddTestCase("dqabs524:p9 r:HALF_EVEN (decimal.abs(NaN))", NaN, decimal.abs(NaN));
AddTestCase("dqabs525:p9 r:HALF_EVEN (decimal.abs(NaN)) invalid_operation", NaN, decimal.abs(NaN));
AddTestCase("dqabs526:p9 r:HALF_EVEN (decimal.abs(-NaN))", -NaN, decimal.abs(-NaN));
AddTestCase("dqabs527:p9 r:HALF_EVEN (decimal.abs(-NaN)) invalid_operation", -NaN, decimal.abs(-NaN));
// null tests
AddTestCase("dqabs900:p9 r:HALF_EVEN (decimal.abs(null)) invalid_operation", 0, decimal.abs(null));
}
test();
