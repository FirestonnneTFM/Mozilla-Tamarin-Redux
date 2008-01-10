use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "dqMinus.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// dqminus.dectest -- decquad 0-x                                     --
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
// all operands and results are decquads.
use rounding HALF_EVEN;
// sanity check
AddTestCase("dqmns001:p9 r:HALF_EVEN (- +7.50)", -7.50, - +7.50);
// infinities
AddTestCase("dqmns011:p9 r:HALF_EVEN (- decimal.POSITIVE_INFINITY)", decimal.NEGATIVE_INFINITY, - decimal.POSITIVE_INFINITY);
AddTestCase("dqmns012:p9 r:HALF_EVEN (- decimal.NEGATIVE_INFINITY)", decimal.POSITIVE_INFINITY, - decimal.NEGATIVE_INFINITY);
// nans, 0 payload
AddTestCase("dqmns021:p9 r:HALF_EVEN (- NaN)", NaN, - NaN);
AddTestCase("dqmns022:p9 r:HALF_EVEN (- -NaN)", -NaN, - -NaN);
AddTestCase("dqmns023:p9 r:HALF_EVEN (- NaN) invalid_operation", NaN, - NaN);
AddTestCase("dqmns024:p9 r:HALF_EVEN (- -NaN) invalid_operation", -NaN, - -NaN);
// nans, non-0 payload
AddTestCase("dqmns031:p9 r:HALF_EVEN (- NaN)", NaN, - NaN);
AddTestCase("dqmns032:p9 r:HALF_EVEN (- -NaN)", -NaN, - -NaN);
AddTestCase("dqmns033:p9 r:HALF_EVEN (- NaN) invalid_operation", NaN, - NaN);
AddTestCase("dqmns034:p9 r:HALF_EVEN (- -NaN) invalid_operation", -NaN, - -NaN);
AddTestCase("dqmns035:p9 r:HALF_EVEN (- NaN)", NaN, - NaN);
AddTestCase("dqmns036:p9 r:HALF_EVEN (- -NaN)", -NaN, - -NaN);
AddTestCase("dqmns037:p9 r:HALF_EVEN (- NaN) invalid_operation", NaN, - NaN);
AddTestCase("dqmns038:p9 r:HALF_EVEN (- -NaN) invalid_operation", -NaN, - -NaN);
// finites
AddTestCase("dqmns101:p9 r:HALF_EVEN (- 7)", -7, - 7);
AddTestCase("dqmns102:p9 r:HALF_EVEN (- -7)", 7, - -7);
AddTestCase("dqmns103:p9 r:HALF_EVEN (- 75)", -75, - 75);
AddTestCase("dqmns104:p9 r:HALF_EVEN (- -75)", 75, - -75);
AddTestCase("dqmns105:p9 r:HALF_EVEN (- 7.50)", -7.50, - 7.50);
AddTestCase("dqmns106:p9 r:HALF_EVEN (- -7.50)", 7.50, - -7.50);
AddTestCase("dqmns107:p9 r:HALF_EVEN (- 7.500)", -7.500, - 7.500);
AddTestCase("dqmns108:p9 r:HALF_EVEN (- -7.500)", 7.500, - -7.500);
// zeros
AddTestCase("dqmns111:p9 r:HALF_EVEN (- 0)", 0, - 0);
AddTestCase("dqmns112:p9 r:HALF_EVEN (- -0)", 0, - -0);
AddTestCase("dqmns113:p9 r:HALF_EVEN (- 0e+4)", 0e+4, - 0e+4);
AddTestCase("dqmns114:p9 r:HALF_EVEN (- -0e+4)", 0e+4, - -0e+4);
AddTestCase("dqmns115:p9 r:HALF_EVEN (- 0.0000)", 0.0000, - 0.0000);
AddTestCase("dqmns116:p9 r:HALF_EVEN (- -0.0000)", 0.0000, - -0.0000);
AddTestCase("dqmns117:p9 r:HALF_EVEN (- 0e-141)", 0e-141, - 0e-141);
AddTestCase("dqmns118:p9 r:HALF_EVEN (- -0e-141)", 0e-141, - -0e-141);
// full coefficients, alternating bits
AddTestCase("dqmns121:p9 r:HALF_EVEN (- 2682682682682682682682682682682682)", -2682682682682682682682682682682682, - 2682682682682682682682682682682682);
AddTestCase("dqmns122:p9 r:HALF_EVEN (- -2682682682682682682682682682682682)", 2682682682682682682682682682682682, - -2682682682682682682682682682682682);
AddTestCase("dqmns123:p9 r:HALF_EVEN (- 1341341341341341341341341341341341)", -1341341341341341341341341341341341, - 1341341341341341341341341341341341);
AddTestCase("dqmns124:p9 r:HALF_EVEN (- -1341341341341341341341341341341341)", 1341341341341341341341341341341341, - -1341341341341341341341341341341341);
// nmax, nmin, ntiny
AddTestCase("dqmns131:p9 r:HALF_EVEN (- 9.999999999999999999999999999999999e+6144)", -9.999999999999999999999999999999999e+6144, - 9.999999999999999999999999999999999e+6144);
AddTestCase("dqmns132:p9 r:HALF_EVEN (- 1e-6143)", -1e-6143, - 1e-6143);
AddTestCase("dqmns133:p9 r:HALF_EVEN (- 1.000000000000000000000000000000000e-6143)", -1.000000000000000000000000000000000e-6143, - 1.000000000000000000000000000000000e-6143);
AddTestCase("dqmns136:p9 r:HALF_EVEN (- -1.000000000000000000000000000000000e-6143)", 1.000000000000000000000000000000000e-6143, - -1.000000000000000000000000000000000e-6143);
AddTestCase("dqmns137:p9 r:HALF_EVEN (- -1e-6143)", 1e-6143, - -1e-6143);
AddTestCase("dqmns138:p9 r:HALF_EVEN (- -9.999999999999999999999999999999999e+6144)", 9.999999999999999999999999999999999e+6144, - -9.999999999999999999999999999999999e+6144);
}
test();
