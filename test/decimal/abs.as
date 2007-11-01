use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "abs.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// abs.dectest -- decimal absolute value                              --
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
// additon, subtraction, rounding, and more overflows are tested
// elsewhere.
use precision 9;
use rounding HALF_UP;
AddTestCase('absx001:p9 r:HALF_UP (0 + decimal.abs(1))', 1, 0 + decimal.abs(1));
AddTestCase('absx002:p9 r:HALF_UP (0 + decimal.abs(-1))', 1, 0 + decimal.abs(-1));
AddTestCase('absx003:p9 r:HALF_UP (0 + decimal.abs(1.00))', 1.00, 0 + decimal.abs(1.00));
AddTestCase('absx004:p9 r:HALF_UP (0 + decimal.abs(-1.00))', 1.00, 0 + decimal.abs(-1.00));
AddTestCase('absx005:p9 r:HALF_UP (0 + decimal.abs(0))', 0, 0 + decimal.abs(0));
AddTestCase('absx006:p9 r:HALF_UP (0 + decimal.abs(0.00))', 0.00, 0 + decimal.abs(0.00));
AddTestCase('absx007:p9 r:HALF_UP (0 + decimal.abs(00.0))', 0.0, 0 + decimal.abs(00.0));
AddTestCase('absx008:p9 r:HALF_UP (0 + decimal.abs(00.00))', 0.00, 0 + decimal.abs(00.00));
AddTestCase('absx009:p9 r:HALF_UP (0 + decimal.abs(00))', 0, 0 + decimal.abs(00));
AddTestCase('absx010:p9 r:HALF_UP (0 + decimal.abs(-2))', 2, 0 + decimal.abs(-2));
AddTestCase('absx011:p9 r:HALF_UP (0 + decimal.abs(2))', 2, 0 + decimal.abs(2));
AddTestCase('absx012:p9 r:HALF_UP (0 + decimal.abs(-2.00))', 2.00, 0 + decimal.abs(-2.00));
AddTestCase('absx013:p9 r:HALF_UP (0 + decimal.abs(2.00))', 2.00, 0 + decimal.abs(2.00));
AddTestCase('absx014:p9 r:HALF_UP (0 + decimal.abs(-0))', 0, 0 + decimal.abs(-0));
AddTestCase('absx015:p9 r:HALF_UP (0 + decimal.abs(-0.00))', 0.00, 0 + decimal.abs(-0.00));
AddTestCase('absx016:p9 r:HALF_UP (0 + decimal.abs(-00.0))', 0.0, 0 + decimal.abs(-00.0));
AddTestCase('absx017:p9 r:HALF_UP (0 + decimal.abs(-00.00))', 0.00, 0 + decimal.abs(-00.00));
AddTestCase('absx018:p9 r:HALF_UP (0 + decimal.abs(-00))', 0, 0 + decimal.abs(-00));
AddTestCase('absx020:p9 r:HALF_UP (0 + decimal.abs(-2000000))', 2000000, 0 + decimal.abs(-2000000));
AddTestCase('absx021:p9 r:HALF_UP (0 + decimal.abs(2000000))', 2000000, 0 + decimal.abs(2000000));
{
	use precision 7;
	AddTestCase('absx022:p7 r:HALF_UP (0 + decimal.abs(-2000000))', 2000000, 0 + decimal.abs(-2000000));
	AddTestCase('absx023:p7 r:HALF_UP (0 + decimal.abs(2000000))', 2000000, 0 + decimal.abs(2000000));
}
{
	use precision 6;
	AddTestCase('absx024:p6 r:HALF_UP (0 + decimal.abs(-2000000)) rounded', 2.00000e+6, 0 + decimal.abs(-2000000));
	AddTestCase('absx025:p6 r:HALF_UP (0 + decimal.abs(2000000)) rounded', 2.00000e+6, 0 + decimal.abs(2000000));
}
{
	use precision 3;
	AddTestCase('absx026:p3 r:HALF_UP (0 + decimal.abs(-2000000)) rounded', 2.00e+6, 0 + decimal.abs(-2000000));
	AddTestCase('absx027:p3 r:HALF_UP (0 + decimal.abs(2000000)) rounded', 2.00e+6, 0 + decimal.abs(2000000));
	AddTestCase('absx030:p3 r:HALF_UP (0 + decimal.abs(+0.1))', 0.1, 0 + decimal.abs(+0.1));
	AddTestCase('absx031:p3 r:HALF_UP (0 + decimal.abs(-0.1))', 0.1, 0 + decimal.abs(-0.1));
	AddTestCase('absx032:p3 r:HALF_UP (0 + decimal.abs(+0.01))', 0.01, 0 + decimal.abs(+0.01));
	AddTestCase('absx033:p3 r:HALF_UP (0 + decimal.abs(-0.01))', 0.01, 0 + decimal.abs(-0.01));
	AddTestCase('absx034:p3 r:HALF_UP (0 + decimal.abs(+0.001))', 0.001, 0 + decimal.abs(+0.001));
	AddTestCase('absx035:p3 r:HALF_UP (0 + decimal.abs(-0.001))', 0.001, 0 + decimal.abs(-0.001));
	AddTestCase('absx036:p3 r:HALF_UP (0 + decimal.abs(+0.000001))', 0.000001, 0 + decimal.abs(+0.000001));
	AddTestCase('absx037:p3 r:HALF_UP (0 + decimal.abs(-0.000001))', 0.000001, 0 + decimal.abs(-0.000001));
	AddTestCase('absx038:p3 r:HALF_UP (0 + decimal.abs(+0.000000000001))', 1e-12, 0 + decimal.abs(+0.000000000001));
	AddTestCase('absx039:p3 r:HALF_UP (0 + decimal.abs(-0.000000000001))', 1e-12, 0 + decimal.abs(-0.000000000001));
	// examples from decarith
}
{
	use precision 9;
	AddTestCase('absx040:p9 r:HALF_UP (0 + decimal.abs(2.1))', 2.1, 0 + decimal.abs(2.1));
	AddTestCase('absx041:p9 r:HALF_UP (0 + decimal.abs(-100))', 100, 0 + decimal.abs(-100));
	AddTestCase('absx042:p9 r:HALF_UP (0 + decimal.abs(101.5))', 101.5, 0 + decimal.abs(101.5));
	AddTestCase('absx043:p9 r:HALF_UP (0 + decimal.abs(-101.5))', 101.5, 0 + decimal.abs(-101.5));
	// more fixed, potential lhs swaps/overlays if done by subtract 0
}
{
	use precision 9;
	AddTestCase('absx060:p9 r:HALF_UP (0 + decimal.abs(-56267e-10))', 0.0000056267, 0 + decimal.abs(-56267e-10));
	AddTestCase('absx061:p9 r:HALF_UP (0 + decimal.abs(-56267e-5))', 0.56267, 0 + decimal.abs(-56267e-5));
	AddTestCase('absx062:p9 r:HALF_UP (0 + decimal.abs(-56267e-2))', 562.67, 0 + decimal.abs(-56267e-2));
	AddTestCase('absx063:p9 r:HALF_UP (0 + decimal.abs(-56267e-1))', 5626.7, 0 + decimal.abs(-56267e-1));
	AddTestCase('absx065:p9 r:HALF_UP (0 + decimal.abs(-56267e-0))', 56267, 0 + decimal.abs(-56267e-0));
	// overflow tests
}
{
	use precision 3;
	// subnormals and underflow
}
{
	use precision 3;
	AddTestCase('absx210:p3 r:HALF_UP (0 + decimal.abs(1.00e-999))', 1.00e-999, 0 + decimal.abs(1.00e-999));
	// next is rounded to emin
	AddTestCase('absx230:p3 r:HALF_UP (0 + decimal.abs(-1.00e-999))', 1.00e-999, 0 + decimal.abs(-1.00e-999));
	// next is rounded to emin
	// long operand tests
}
{
	use precision 9;
	AddTestCase('absx301:p9 r:HALF_UP (0 + decimal.abs(12345678000)) rounded', 1.23456780e+10, 0 + decimal.abs(12345678000));
	AddTestCase('absx302:p9 r:HALF_UP (0 + decimal.abs(1234567800)) rounded', 1.23456780e+9, 0 + decimal.abs(1234567800));
	AddTestCase('absx303:p9 r:HALF_UP (0 + decimal.abs(1234567890)) rounded', 1.23456789e+9, 0 + decimal.abs(1234567890));
	AddTestCase('absx304:p9 r:HALF_UP (0 + decimal.abs(1234567891)) inexact rounded', 1.23456789e+9, 0 + decimal.abs(1234567891));
	AddTestCase('absx305:p9 r:HALF_UP (0 + decimal.abs(12345678901)) inexact rounded', 1.23456789e+10, 0 + decimal.abs(12345678901));
	AddTestCase('absx306:p9 r:HALF_UP (0 + decimal.abs(1234567896)) inexact rounded', 1.23456790e+9, 0 + decimal.abs(1234567896));
}
{
	use precision 15;
	AddTestCase('absx321:p15 r:HALF_UP (0 + decimal.abs(12345678000))', 12345678000, 0 + decimal.abs(12345678000));
	AddTestCase('absx322:p15 r:HALF_UP (0 + decimal.abs(1234567800))', 1234567800, 0 + decimal.abs(1234567800));
	AddTestCase('absx323:p15 r:HALF_UP (0 + decimal.abs(1234567890))', 1234567890, 0 + decimal.abs(1234567890));
	AddTestCase('absx324:p15 r:HALF_UP (0 + decimal.abs(1234567891))', 1234567891, 0 + decimal.abs(1234567891));
	AddTestCase('absx325:p15 r:HALF_UP (0 + decimal.abs(12345678901))', 12345678901, 0 + decimal.abs(12345678901));
	AddTestCase('absx326:p15 r:HALF_UP (0 + decimal.abs(1234567896))', 1234567896, 0 + decimal.abs(1234567896));
	// specials
}
{
	use precision 9;
	// specials
	AddTestCase('absx520:p9 r:HALF_UP (0 + decimal.abs(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.abs(decimal.POSITIVE_INFINITY));
	AddTestCase('absx521:p9 r:HALF_UP (0 + decimal.abs(decimal.NEGATIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.abs(decimal.NEGATIVE_INFINITY));
	AddTestCase('absx522:p9 r:HALF_UP (0 + decimal.abs(NaN))', NaN, 0 + decimal.abs(NaN));
	AddTestCase('absx523:p9 r:HALF_UP (0 + decimal.abs(NaN)) invalid_operation', NaN, 0 + decimal.abs(NaN));
	AddTestCase('absx524:p9 r:HALF_UP (0 + decimal.abs(NaN))', NaN, 0 + decimal.abs(NaN));
	AddTestCase('absx525:p9 r:HALF_UP (0 + decimal.abs(NaN)) invalid_operation', NaN, 0 + decimal.abs(NaN));
	AddTestCase('absx526:p9 r:HALF_UP (0 + decimal.abs(-NaN))', -NaN, 0 + decimal.abs(-NaN));
	AddTestCase('absx527:p9 r:HALF_UP (0 + decimal.abs(-NaN)) invalid_operation', -NaN, 0 + decimal.abs(-NaN));
	// null tests
	AddTestCase('absx900:p9 r:HALF_UP (0 + decimal.abs(null)) invalid_operation', 0, 0 + decimal.abs(null));
	}
}
test();
