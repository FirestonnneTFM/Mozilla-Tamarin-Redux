use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "minus.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// minus.dectest -- decimal negation                                  --
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
// this set of tests primarily tests the existence of the operator.
// subtraction, rounding, and more overflows are tested elsewhere.
use precision 9;
use rounding HALF_UP;
AddTestCase('minx001:p9 r:HALF_UP (- 1)', -1, - 1);
AddTestCase('minx002:p9 r:HALF_UP (- -1)', 1, - -1);
AddTestCase('minx003:p9 r:HALF_UP (- 1.00)', -1.00, - 1.00);
AddTestCase('minx004:p9 r:HALF_UP (- -1.00)', 1.00, - -1.00);
AddTestCase('minx005:p9 r:HALF_UP (- 0)', 0, - 0);
AddTestCase('minx006:p9 r:HALF_UP (- 0.00)', 0.00, - 0.00);
AddTestCase('minx007:p9 r:HALF_UP (- 00.0)', 0.0, - 00.0);
AddTestCase('minx008:p9 r:HALF_UP (- 00.00)', 0.00, - 00.00);
AddTestCase('minx009:p9 r:HALF_UP (- 00)', 0, - 00);
AddTestCase('minx010:p9 r:HALF_UP (- -2)', 2, - -2);
AddTestCase('minx011:p9 r:HALF_UP (- 2)', -2, - 2);
AddTestCase('minx012:p9 r:HALF_UP (- -2.00)', 2.00, - -2.00);
AddTestCase('minx013:p9 r:HALF_UP (- 2.00)', -2.00, - 2.00);
AddTestCase('minx014:p9 r:HALF_UP (- -0)', 0, - -0);
AddTestCase('minx015:p9 r:HALF_UP (- -0.00)', 0.00, - -0.00);
AddTestCase('minx016:p9 r:HALF_UP (- -00.0)', 0.0, - -00.0);
AddTestCase('minx017:p9 r:HALF_UP (- -00.00)', 0.00, - -00.00);
AddTestCase('minx018:p9 r:HALF_UP (- -00)', 0, - -00);
// "lhs" zeros in plus and minus have exponent = operand
AddTestCase('minx020:p9 r:HALF_UP (- -0e3)', 0e+3, - -0e3);
AddTestCase('minx021:p9 r:HALF_UP (- -0e2)', 0e+2, - -0e2);
AddTestCase('minx022:p9 r:HALF_UP (- -0e1)', 0e+1, - -0e1);
AddTestCase('minx023:p9 r:HALF_UP (- -0e0)', 0, - -0e0);
AddTestCase('minx024:p9 r:HALF_UP (- +0e0)', 0, - +0e0);
AddTestCase('minx025:p9 r:HALF_UP (- +0e1)', 0e+1, - +0e1);
AddTestCase('minx026:p9 r:HALF_UP (- +0e2)', 0e+2, - +0e2);
AddTestCase('minx027:p9 r:HALF_UP (- +0e3)', 0e+3, - +0e3);
AddTestCase('minx030:p9 r:HALF_UP (- -5e3)', 5e+3, - -5e3);
AddTestCase('minx031:p9 r:HALF_UP (- -5e8)', 5e+8, - -5e8);
AddTestCase('minx032:p9 r:HALF_UP (- -5e13)', 5e+13, - -5e13);
AddTestCase('minx033:p9 r:HALF_UP (- -5e18)', 5e+18, - -5e18);
AddTestCase('minx034:p9 r:HALF_UP (- +5e3)', -5e+3, - +5e3);
AddTestCase('minx035:p9 r:HALF_UP (- +5e8)', -5e+8, - +5e8);
AddTestCase('minx036:p9 r:HALF_UP (- +5e13)', -5e+13, - +5e13);
AddTestCase('minx037:p9 r:HALF_UP (- +5e18)', -5e+18, - +5e18);
AddTestCase('minx050:p9 r:HALF_UP (- -2000000)', 2000000, - -2000000);
AddTestCase('minx051:p9 r:HALF_UP (- 2000000)', -2000000, - 2000000);
{
	use precision 7;
	AddTestCase('minx052:p7 r:HALF_UP (- -2000000)', 2000000, - -2000000);
	AddTestCase('minx053:p7 r:HALF_UP (- 2000000)', -2000000, - 2000000);
}
{
	use precision 6;
	AddTestCase('minx054:p6 r:HALF_UP (- -2000000) rounded', 2.00000e+6, - -2000000);
	AddTestCase('minx055:p6 r:HALF_UP (- 2000000) rounded', -2.00000e+6, - 2000000);
}
{
	use precision 3;
	AddTestCase('minx056:p3 r:HALF_UP (- -2000000) rounded', 2.00e+6, - -2000000);
	AddTestCase('minx057:p3 r:HALF_UP (- 2000000) rounded', -2.00e+6, - 2000000);
	// more fixed, potential lhs swaps/overlays if done by 0 subtract x
}
{
	use precision 9;
	AddTestCase('minx060:p9 r:HALF_UP (- 56267e-10)', -0.0000056267, - 56267e-10);
	AddTestCase('minx061:p9 r:HALF_UP (- 56267e-5)', -0.56267, - 56267e-5);
	AddTestCase('minx062:p9 r:HALF_UP (- 56267e-2)', -562.67, - 56267e-2);
	AddTestCase('minx063:p9 r:HALF_UP (- 56267e-1)', -5626.7, - 56267e-1);
	AddTestCase('minx065:p9 r:HALF_UP (- 56267e-0)', -56267, - 56267e-0);
	AddTestCase('minx066:p9 r:HALF_UP (- 56267e+0)', -56267, - 56267e+0);
	AddTestCase('minx067:p9 r:HALF_UP (- 56267e+1)', -5.6267e+5, - 56267e+1);
	AddTestCase('minx068:p9 r:HALF_UP (- 56267e+2)', -5.6267e+6, - 56267e+2);
	AddTestCase('minx069:p9 r:HALF_UP (- 56267e+3)', -5.6267e+7, - 56267e+3);
	AddTestCase('minx070:p9 r:HALF_UP (- 56267e+4)', -5.6267e+8, - 56267e+4);
	AddTestCase('minx071:p9 r:HALF_UP (- 56267e+5)', -5.6267e+9, - 56267e+5);
	AddTestCase('minx072:p9 r:HALF_UP (- 56267e+6)', -5.6267e+10, - 56267e+6);
	AddTestCase('minx080:p9 r:HALF_UP (- -56267e-10)', 0.0000056267, - -56267e-10);
	AddTestCase('minx081:p9 r:HALF_UP (- -56267e-5)', 0.56267, - -56267e-5);
	AddTestCase('minx082:p9 r:HALF_UP (- -56267e-2)', 562.67, - -56267e-2);
	AddTestCase('minx083:p9 r:HALF_UP (- -56267e-1)', 5626.7, - -56267e-1);
	AddTestCase('minx085:p9 r:HALF_UP (- -56267e-0)', 56267, - -56267e-0);
	AddTestCase('minx086:p9 r:HALF_UP (- -56267e+0)', 56267, - -56267e+0);
	AddTestCase('minx087:p9 r:HALF_UP (- -56267e+1)', 5.6267e+5, - -56267e+1);
	AddTestCase('minx088:p9 r:HALF_UP (- -56267e+2)', 5.6267e+6, - -56267e+2);
	AddTestCase('minx089:p9 r:HALF_UP (- -56267e+3)', 5.6267e+7, - -56267e+3);
	AddTestCase('minx090:p9 r:HALF_UP (- -56267e+4)', 5.6267e+8, - -56267e+4);
	AddTestCase('minx091:p9 r:HALF_UP (- -56267e+5)', 5.6267e+9, - -56267e+5);
	AddTestCase('minx092:p9 r:HALF_UP (- -56267e+6)', 5.6267e+10, - -56267e+6);
	// overflow tests
}
{
	use precision 3;
	// subnormals and underflow
}
{
	use precision 3;
	AddTestCase('minx110:p3 r:HALF_UP (- 1.00e-999)', -1.00e-999, - 1.00e-999);
	// next is rounded to emin
	AddTestCase('minx130:p3 r:HALF_UP (- -1.00e-999)', 1.00e-999, - -1.00e-999);
	// next is rounded to emin
	// long operand checks
}
{
	use precision 9;
	AddTestCase('minx301:p9 r:HALF_UP (- 12345678000) rounded', -1.23456780e+10, - 12345678000);
	AddTestCase('minx302:p9 r:HALF_UP (- 1234567800) rounded', -1.23456780e+9, - 1234567800);
	AddTestCase('minx303:p9 r:HALF_UP (- 1234567890) rounded', -1.23456789e+9, - 1234567890);
	AddTestCase('minx304:p9 r:HALF_UP (- 1234567891) inexact rounded', -1.23456789e+9,0 - 1234567891);
	AddTestCase('minx305:p9 r:HALF_UP (- 12345678901) inexact rounded', -1.23456789e+10,0 - 12345678901);
	AddTestCase('minx306:p9 r:HALF_UP (- 1234567896) inexact rounded', -1.23456790e+9,0 - 1234567896);
}
{
	use precision 15;
	// still checking
	AddTestCase('minx321:p15 r:HALF_UP (- 12345678000)', -12345678000, - 12345678000);
	AddTestCase('minx322:p15 r:HALF_UP (- 1234567800)', -1234567800, - 1234567800);
	AddTestCase('minx323:p15 r:HALF_UP (- 1234567890)', -1234567890, - 1234567890);
	AddTestCase('minx324:p15 r:HALF_UP (- 1234567891)', -1234567891, - 1234567891);
	AddTestCase('minx325:p15 r:HALF_UP (- 12345678901)', -12345678901, - 12345678901);
	AddTestCase('minx326:p15 r:HALF_UP (- 1234567896)', -1234567896, - 1234567896);
	// specials
	AddTestCase('minx420:p15 r:HALF_UP (- decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, - decimal.POSITIVE_INFINITY);
	AddTestCase('minx421:p15 r:HALF_UP (- decimal.NEGATIVE_INFINITY)', decimal.POSITIVE_INFINITY, - decimal.NEGATIVE_INFINITY);
	AddTestCase('minx422:p15 r:HALF_UP (- NaN)', NaN, - NaN);
	AddTestCase('minx423:p15 r:HALF_UP (- NaN) invalid_operation', NaN, - NaN);
	AddTestCase('minx424:p15 r:HALF_UP (- NaN)', NaN, - NaN);
	AddTestCase('minx425:p15 r:HALF_UP (- NaN) invalid_operation', NaN, - NaN);
	AddTestCase('minx426:p15 r:HALF_UP (- -NaN)', -NaN, - -NaN);
	AddTestCase('minx427:p15 r:HALF_UP (- -NaN) invalid_operation', -NaN, - -NaN);
	AddTestCase('minx428:p15 r:HALF_UP (- -NaN)', -NaN, - -NaN);
	AddTestCase('minx429:p15 r:HALF_UP (- -NaN) invalid_operation', -NaN, - -NaN);
	// null tests
	AddTestCase('minx900:p15 r:HALF_UP (- null) invalid_operation', -0, - null);
	}
}
test();
