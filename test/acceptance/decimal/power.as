use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "power.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// power.dectest -- decimal exponentiation [power(x, y)]              --
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
// in addition to the power operator testcases here, see also the file
// powersqrt.dectest which includes all the tests from
// squareroot.dectest implemented using power(x, 0.5)
use precision 16;
use rounding HALF_EVEN;
// base checks.  note 0**0 is an error.
AddTestCase('powx001:p16 r:HALF_EVEN (0 + decimal.pow(0,0)) ', 1, 0 + decimal.pow(0,0));
AddTestCase('powx002:p16 r:HALF_EVEN (0 + decimal.pow(0,1))', 0, 0 + decimal.pow(0,1));
AddTestCase('powx003:p16 r:HALF_EVEN (0 + decimal.pow(0,2))', 0, 0 + decimal.pow(0,2));
AddTestCase('powx004:p16 r:HALF_EVEN (0 + decimal.pow(1,0))', 1, 0 + decimal.pow(1,0));
AddTestCase('powx005:p16 r:HALF_EVEN (0 + decimal.pow(1,1))', 1, 0 + decimal.pow(1,1));
AddTestCase('powx006:p16 r:HALF_EVEN (0 + decimal.pow(1,2))', 1, 0 + decimal.pow(1,2));
AddTestCase('powx010:p16 r:HALF_EVEN (0 + decimal.pow(2,0))', 1, 0 + decimal.pow(2,0));
AddTestCase('powx011:p16 r:HALF_EVEN (0 + decimal.pow(2,1))', 2, 0 + decimal.pow(2,1));
AddTestCase('powx012:p16 r:HALF_EVEN (0 + decimal.pow(2,2))', 4, 0 + decimal.pow(2,2));
AddTestCase('powx013:p16 r:HALF_EVEN (0 + decimal.pow(2,3))', 8, 0 + decimal.pow(2,3));
AddTestCase('powx014:p16 r:HALF_EVEN (0 + decimal.pow(2,4))', 16, 0 + decimal.pow(2,4));
AddTestCase('powx015:p16 r:HALF_EVEN (0 + decimal.pow(2,5))', 32, 0 + decimal.pow(2,5));
AddTestCase('powx016:p16 r:HALF_EVEN (0 + decimal.pow(2,6))', 64, 0 + decimal.pow(2,6));
AddTestCase('powx017:p16 r:HALF_EVEN (0 + decimal.pow(2,7))', 128, 0 + decimal.pow(2,7));
AddTestCase('powx018:p16 r:HALF_EVEN (0 + decimal.pow(2,8))', 256, 0 + decimal.pow(2,8));
AddTestCase('powx019:p16 r:HALF_EVEN (0 + decimal.pow(2,9))', 512, 0 + decimal.pow(2,9));
AddTestCase('powx020:p16 r:HALF_EVEN (0 + decimal.pow(2,10))', 1024, 0 + decimal.pow(2,10));
AddTestCase('powx021:p16 r:HALF_EVEN (0 + decimal.pow(2,11))', 2048, 0 + decimal.pow(2,11));
AddTestCase('powx022:p16 r:HALF_EVEN (0 + decimal.pow(2,12))', 4096, 0 + decimal.pow(2,12));
AddTestCase('powx023:p16 r:HALF_EVEN (0 + decimal.pow(2,15))', 32768, 0 + decimal.pow(2,15));
AddTestCase('powx024:p16 r:HALF_EVEN (0 + decimal.pow(2,16))', 65536, 0 + decimal.pow(2,16));
AddTestCase('powx025:p16 r:HALF_EVEN (0 + decimal.pow(2,31))', 2147483648, 0 + decimal.pow(2,31));
// nb 0 not stripped in next
AddTestCase('powx026:p16 r:HALF_EVEN (0 + decimal.pow(2,32))', 4294967296, 0 + decimal.pow(2,32));
{
	use precision 9;
	AddTestCase('powx027:p9 r:HALF_EVEN (0 + decimal.pow(2,31)) inexact rounded', 2.14748365e+9, 0 + decimal.pow(2,31));
	// nb 0 not stripped in next
	AddTestCase('powx028:p9 r:HALF_EVEN (0 + decimal.pow(2,32)) inexact rounded', 4.29496730e+9, 0 + decimal.pow(2,32));
}
{
	use precision 10;
	AddTestCase('powx029:p10 r:HALF_EVEN (0 + decimal.pow(2,31))', 2147483648, 0 + decimal.pow(2,31));
	AddTestCase('powx030:p10 r:HALF_EVEN (0 + decimal.pow(2,32))', 4294967296, 0 + decimal.pow(2,32));
}
{
	use precision 9;
	AddTestCase('powx031:p9 r:HALF_EVEN (0 + decimal.pow(3,2))', 9, 0 + decimal.pow(3,2));
	AddTestCase('powx032:p9 r:HALF_EVEN (0 + decimal.pow(4,2))', 16, 0 + decimal.pow(4,2));
	AddTestCase('powx033:p9 r:HALF_EVEN (0 + decimal.pow(5,2))', 25, 0 + decimal.pow(5,2));
	AddTestCase('powx034:p9 r:HALF_EVEN (0 + decimal.pow(6,2))', 36, 0 + decimal.pow(6,2));
	AddTestCase('powx035:p9 r:HALF_EVEN (0 + decimal.pow(7,2))', 49, 0 + decimal.pow(7,2));
	AddTestCase('powx036:p9 r:HALF_EVEN (0 + decimal.pow(8,2))', 64, 0 + decimal.pow(8,2));
	AddTestCase('powx037:p9 r:HALF_EVEN (0 + decimal.pow(9,2))', 81, 0 + decimal.pow(9,2));
	AddTestCase('powx038:p9 r:HALF_EVEN (0 + decimal.pow(10,2))', 100, 0 + decimal.pow(10,2));
	AddTestCase('powx039:p9 r:HALF_EVEN (0 + decimal.pow(11,2))', 121, 0 + decimal.pow(11,2));
	AddTestCase('powx040:p9 r:HALF_EVEN (0 + decimal.pow(12,2))', 144, 0 + decimal.pow(12,2));
	AddTestCase('powx041:p9 r:HALF_EVEN (0 + decimal.pow(3,3))', 27, 0 + decimal.pow(3,3));
	AddTestCase('powx042:p9 r:HALF_EVEN (0 + decimal.pow(4,3))', 64, 0 + decimal.pow(4,3));
	AddTestCase('powx043:p9 r:HALF_EVEN (0 + decimal.pow(5,3))', 125, 0 + decimal.pow(5,3));
	AddTestCase('powx044:p9 r:HALF_EVEN (0 + decimal.pow(6,3))', 216, 0 + decimal.pow(6,3));
	AddTestCase('powx045:p9 r:HALF_EVEN (0 + decimal.pow(7,3))', 343, 0 + decimal.pow(7,3));
	AddTestCase('powx047:p9 r:HALF_EVEN (0 + decimal.pow(-3,3))', -27, 0 + decimal.pow(-3,3));
	AddTestCase('powx048:p9 r:HALF_EVEN (0 + decimal.pow(-4,3))', -64, 0 + decimal.pow(-4,3));
	AddTestCase('powx049:p9 r:HALF_EVEN (0 + decimal.pow(-5,3))', -125, 0 + decimal.pow(-5,3));
	AddTestCase('powx050:p9 r:HALF_EVEN (0 + decimal.pow(-6,3))', -216, 0 + decimal.pow(-6,3));
	AddTestCase('powx051:p9 r:HALF_EVEN (0 + decimal.pow(-7,3))', -343, 0 + decimal.pow(-7,3));
	AddTestCase('powx052:p9 r:HALF_EVEN (0 + decimal.pow(10,0))', 1, 0 + decimal.pow(10,0));
	AddTestCase('powx053:p9 r:HALF_EVEN (0 + decimal.pow(10,1))', 10, 0 + decimal.pow(10,1));
	AddTestCase('powx054:p9 r:HALF_EVEN (0 + decimal.pow(10,2))', 100, 0 + decimal.pow(10,2));
	AddTestCase('powx055:p9 r:HALF_EVEN (0 + decimal.pow(10,3))', 1000, 0 + decimal.pow(10,3));
	AddTestCase('powx056:p9 r:HALF_EVEN (0 + decimal.pow(10,4))', 10000, 0 + decimal.pow(10,4));
	AddTestCase('powx057:p9 r:HALF_EVEN (0 + decimal.pow(10,5))', 100000, 0 + decimal.pow(10,5));
	AddTestCase('powx058:p9 r:HALF_EVEN (0 + decimal.pow(10,6))', 1000000, 0 + decimal.pow(10,6));
	AddTestCase('powx059:p9 r:HALF_EVEN (0 + decimal.pow(10,7))', 10000000, 0 + decimal.pow(10,7));
	AddTestCase('powx060:p9 r:HALF_EVEN (0 + decimal.pow(10,8))', 100000000, 0 + decimal.pow(10,8));
	AddTestCase('powx061:p9 r:HALF_EVEN (0 + decimal.pow(10,9)) rounded', 1.00000000e+9, 0 + decimal.pow(10,9));
	AddTestCase('powx062:p9 r:HALF_EVEN (0 + decimal.pow(10,22)) rounded', 1.00000000e+22, 0 + decimal.pow(10,22));
	AddTestCase('powx063:p9 r:HALF_EVEN (0 + decimal.pow(10,77)) rounded', 1.00000000e+77, 0 + decimal.pow(10,77));
	AddTestCase('powx064:p9 r:HALF_EVEN (0 + decimal.pow(10,99)) rounded', 1.00000000e+99, 0 + decimal.pow(10,99));
	AddTestCase('powx070:p9 r:HALF_EVEN (0 + decimal.pow(0.3,0))', 1, 0 + decimal.pow(0.3,0));
	AddTestCase('powx071:p9 r:HALF_EVEN (0 + decimal.pow(0.3,1))', 0.3, 0 + decimal.pow(0.3,1));
	AddTestCase('powx072:p9 r:HALF_EVEN (0 + decimal.pow(0.3,1.00))', 0.3, 0 + decimal.pow(0.3,1.00));
	AddTestCase('powx073:p9 r:HALF_EVEN (0 + decimal.pow(0.3,2.00))', 0.09, 0 + decimal.pow(0.3,2.00));
	AddTestCase('powx074:p9 r:HALF_EVEN (0 + decimal.pow(0.3,2.000000000))', 0.09, 0 + decimal.pow(0.3,2.000000000));
	AddTestCase('powx075:p9 r:HALF_EVEN (0 + decimal.pow(6.0,1)) -- nb zeros not stripped', 6.0, 0 + decimal.pow(6.0,1));
	AddTestCase('powx076:p9 r:HALF_EVEN (0 + decimal.pow(6.0,2)) -- ..', 36.00, 0 + decimal.pow(6.0,2));
	AddTestCase('powx077:p9 r:HALF_EVEN (0 + decimal.pow(-3,2)) -- from netrexx book', 9, 0 + decimal.pow(-3,2));
	AddTestCase('powx078:p9 r:HALF_EVEN (0 + decimal.pow(4,3)) -- .. (sort of)', 64, 0 + decimal.pow(4,3));
	AddTestCase('powx080:p9 r:HALF_EVEN (0 + decimal.pow(0.1,0))', 1, 0 + decimal.pow(0.1,0));
	AddTestCase('powx081:p9 r:HALF_EVEN (0 + decimal.pow(0.1,1))', 0.1, 0 + decimal.pow(0.1,1));
	AddTestCase('powx082:p9 r:HALF_EVEN (0 + decimal.pow(0.1,2))', 0.01, 0 + decimal.pow(0.1,2));
	AddTestCase('powx083:p9 r:HALF_EVEN (0 + decimal.pow(0.1,3))', 0.001, 0 + decimal.pow(0.1,3));
	AddTestCase('powx084:p9 r:HALF_EVEN (0 + decimal.pow(0.1,4))', 0.0001, 0 + decimal.pow(0.1,4));
	AddTestCase('powx085:p9 r:HALF_EVEN (0 + decimal.pow(0.1,5))', 0.00001, 0 + decimal.pow(0.1,5));
	AddTestCase('powx086:p9 r:HALF_EVEN (0 + decimal.pow(0.1,6))', 0.000001, 0 + decimal.pow(0.1,6));
	AddTestCase('powx087:p9 r:HALF_EVEN (0 + decimal.pow(0.1,7))', 1e-7, 0 + decimal.pow(0.1,7));
	AddTestCase('powx088:p9 r:HALF_EVEN (0 + decimal.pow(0.1,8))', 1e-8, 0 + decimal.pow(0.1,8));
	AddTestCase('powx089:p9 r:HALF_EVEN (0 + decimal.pow(0.1,9))', 1e-9, 0 + decimal.pow(0.1,9));
	AddTestCase('powx090:p9 r:HALF_EVEN (0 + decimal.pow(101,2))', 10201, 0 + decimal.pow(101,2));
	AddTestCase('powx091:p9 r:HALF_EVEN (0 + decimal.pow(101,3))', 1030301, 0 + decimal.pow(101,3));
	AddTestCase('powx092:p9 r:HALF_EVEN (0 + decimal.pow(101,4))', 104060401, 0 + decimal.pow(101,4));
	AddTestCase('powx093:p9 r:HALF_EVEN (0 + decimal.pow(101,5)) inexact rounded', 1.05101005e+10, 0 + decimal.pow(101,5));
	AddTestCase('powx094:p9 r:HALF_EVEN (0 + decimal.pow(101,6)) inexact rounded', 1.06152015e+12, 0 + decimal.pow(101,6));
	AddTestCase('powx095:p9 r:HALF_EVEN (0 + decimal.pow(101,7)) inexact rounded', 1.07213535e+14, 0 + decimal.pow(101,7));
	// negative powers
	AddTestCase('powx099:p9 r:HALF_EVEN (0 + decimal.pow(1,-1))', 1, 0 + decimal.pow(1,-1));
	AddTestCase('powx100:p9 r:HALF_EVEN (0 + decimal.pow(3,-1)) inexact rounded', 0.333333333, 0 + decimal.pow(3,-1));
	AddTestCase('powx101:p9 r:HALF_EVEN (0 + decimal.pow(2,-1))', 0.5, 0 + decimal.pow(2,-1));
	AddTestCase('powx102:p9 r:HALF_EVEN (0 + decimal.pow(2,-2))', 0.25, 0 + decimal.pow(2,-2));
	AddTestCase('powx103:p9 r:HALF_EVEN (0 + decimal.pow(2,-4))', 0.0625, 0 + decimal.pow(2,-4));
	AddTestCase('powx104:p9 r:HALF_EVEN (0 + decimal.pow(2,-8))', 0.00390625, 0 + decimal.pow(2,-8));
	AddTestCase('powx105:p9 r:HALF_EVEN (0 + decimal.pow(2,-16)) inexact rounded', 0.0000152587891, 0 + decimal.pow(2,-16));
	AddTestCase('powx106:p9 r:HALF_EVEN (0 + decimal.pow(2,-32)) inexact rounded', 2.32830644e-10, 0 + decimal.pow(2,-32));
	AddTestCase('powx108:p9 r:HALF_EVEN (0 + decimal.pow(2,-64)) inexact rounded', 5.42101086e-20, 0 + decimal.pow(2,-64));
	AddTestCase('powx110:p9 r:HALF_EVEN (0 + decimal.pow(10,-8))', 1e-8, 0 + decimal.pow(10,-8));
	AddTestCase('powx111:p9 r:HALF_EVEN (0 + decimal.pow(10,-7))', 1e-7, 0 + decimal.pow(10,-7));
	AddTestCase('powx112:p9 r:HALF_EVEN (0 + decimal.pow(10,-6))', 0.000001, 0 + decimal.pow(10,-6));
	AddTestCase('powx113:p9 r:HALF_EVEN (0 + decimal.pow(10,-5))', 0.00001, 0 + decimal.pow(10,-5));
	AddTestCase('powx114:p9 r:HALF_EVEN (0 + decimal.pow(10,-4))', 0.0001, 0 + decimal.pow(10,-4));
	AddTestCase('powx115:p9 r:HALF_EVEN (0 + decimal.pow(10,-3))', 0.001, 0 + decimal.pow(10,-3));
	AddTestCase('powx116:p9 r:HALF_EVEN (0 + decimal.pow(10,-2))', 0.01, 0 + decimal.pow(10,-2));
	AddTestCase('powx117:p9 r:HALF_EVEN (0 + decimal.pow(10,-1))', 0.1, 0 + decimal.pow(10,-1));
	AddTestCase('powx121:p9 r:HALF_EVEN (0 + decimal.pow(10,-77))', 1e-77, 0 + decimal.pow(10,-77));
	AddTestCase('powx122:p9 r:HALF_EVEN (0 + decimal.pow(10,-22))', 1e-22, 0 + decimal.pow(10,-22));
	AddTestCase('powx123:p9 r:HALF_EVEN (0 + decimal.pow(2,-1))', 0.5, 0 + decimal.pow(2,-1));
	AddTestCase('powx124:p9 r:HALF_EVEN (0 + decimal.pow(2,-2))', 0.25, 0 + decimal.pow(2,-2));
	AddTestCase('powx125:p9 r:HALF_EVEN (0 + decimal.pow(2,-4))', 0.0625, 0 + decimal.pow(2,-4));
	AddTestCase('powx126:p9 r:HALF_EVEN (0 + decimal.pow(0,-1))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0,-1));
	AddTestCase('powx127:p9 r:HALF_EVEN (0 + decimal.pow(0,-2))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0,-2));
	AddTestCase('powx128:p9 r:HALF_EVEN (0 + decimal.pow(-0,-1))', decimal.NEGATIVE_INFINITY, 0 + decimal.pow(-0,-1));
	AddTestCase('powx129:p9 r:HALF_EVEN (0 + decimal.pow(-0,-2))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(-0,-2));
	// "0.5" tests from original rexx diagnostics [loop unrolled]
	AddTestCase('powx200:p9 r:HALF_EVEN (0 + decimal.pow(0.5,0))', 1, 0 + decimal.pow(0.5,0));
	AddTestCase('powx201:p9 r:HALF_EVEN (0 + decimal.pow(0.5,1))', 0.5, 0 + decimal.pow(0.5,1));
	AddTestCase('powx202:p9 r:HALF_EVEN (0 + decimal.pow(0.5,2))', 0.25, 0 + decimal.pow(0.5,2));
	AddTestCase('powx203:p9 r:HALF_EVEN (0 + decimal.pow(0.5,3))', 0.125, 0 + decimal.pow(0.5,3));
	AddTestCase('powx204:p9 r:HALF_EVEN (0 + decimal.pow(0.5,4))', 0.0625, 0 + decimal.pow(0.5,4));
	AddTestCase('powx205:p9 r:HALF_EVEN (0 + decimal.pow(0.5,5))', 0.03125, 0 + decimal.pow(0.5,5));
	AddTestCase('powx206:p9 r:HALF_EVEN (0 + decimal.pow(0.5,6))', 0.015625, 0 + decimal.pow(0.5,6));
	AddTestCase('powx207:p9 r:HALF_EVEN (0 + decimal.pow(0.5,7))', 0.0078125, 0 + decimal.pow(0.5,7));
	AddTestCase('powx208:p9 r:HALF_EVEN (0 + decimal.pow(0.5,8))', 0.00390625, 0 + decimal.pow(0.5,8));
	AddTestCase('powx209:p9 r:HALF_EVEN (0 + decimal.pow(0.5,9))', 0.001953125, 0 + decimal.pow(0.5,9));
	AddTestCase('powx210:p9 r:HALF_EVEN (0 + decimal.pow(0.5,10))', 0.0009765625, 0 + decimal.pow(0.5,10));
	AddTestCase('powx211:p9 r:HALF_EVEN (0 + decimal.pow(1,100000000))', 1, 0 + decimal.pow(1,100000000));
	AddTestCase('powx212:p9 r:HALF_EVEN (0 + decimal.pow(1,999999998))', 1, 0 + decimal.pow(1,999999998));
	AddTestCase('powx213:p9 r:HALF_EVEN (0 + decimal.pow(1,999999999))', 1, 0 + decimal.pow(1,999999999));
	// the vienna case.  checks both setup and 1/acc working precision
	// modified 1998.12.14 as rhs no longer rounded before use (must fit)
	// modified 1990.02.04 as lhs is now rounded (instead of truncated to guard)
	//    '123456789e+10'    -- lhs .. rounded to 1.23e+18
	//    '-1.23000e+2'      -- rhs .. [was: -1.23455e+2, rounds to -123]
	// modified 2002.10.06 -- finally, no input rounding
	// with input rounding, result would be 8.74e-2226
}
{
	use precision 3;
	AddTestCase('powx219:p3 r:HALF_EVEN (0 + decimal.pow(123456789e+10,-1.23000e+2)) inexact rounded', 5.54e-2226, 0 + decimal.pow(123456789e+10,-1.23000e+2));
	// zeros
}
{
	use precision 7;
	AddTestCase('powx223:p7 r:HALF_EVEN (0 + decimal.pow(0e-30,3))', 0, 0 + decimal.pow(0e-30,3));
	AddTestCase('powx224:p7 r:HALF_EVEN (0 + decimal.pow(0e-10,3))', 0, 0 + decimal.pow(0e-10,3));
	AddTestCase('powx225:p7 r:HALF_EVEN (0 + decimal.pow(0e-1,3))', 0, 0 + decimal.pow(0e-1,3));
	AddTestCase('powx226:p7 r:HALF_EVEN (0 + decimal.pow(0e+0,3))', 0, 0 + decimal.pow(0e+0,3));
	AddTestCase('powx227:p7 r:HALF_EVEN (0 + decimal.pow(0,3))', 0, 0 + decimal.pow(0,3));
	AddTestCase('powx228:p7 r:HALF_EVEN (0 + decimal.pow(0e+1,3))', 0, 0 + decimal.pow(0e+1,3));
	AddTestCase('powx229:p7 r:HALF_EVEN (0 + decimal.pow(0e+10,3))', 0, 0 + decimal.pow(0e+10,3));
	AddTestCase('powx230:p7 r:HALF_EVEN (0 + decimal.pow(0e+30,3))', 0, 0 + decimal.pow(0e+30,3));
	AddTestCase('powx231:p7 r:HALF_EVEN (0 + decimal.pow(3,0e-30))', 1, 0 + decimal.pow(3,0e-30));
	AddTestCase('powx232:p7 r:HALF_EVEN (0 + decimal.pow(3,0e-10))', 1, 0 + decimal.pow(3,0e-10));
	AddTestCase('powx233:p7 r:HALF_EVEN (0 + decimal.pow(3,0e-1))', 1, 0 + decimal.pow(3,0e-1));
	AddTestCase('powx234:p7 r:HALF_EVEN (0 + decimal.pow(3,0e+0))', 1, 0 + decimal.pow(3,0e+0));
	AddTestCase('powx235:p7 r:HALF_EVEN (0 + decimal.pow(3,0))', 1, 0 + decimal.pow(3,0));
	AddTestCase('powx236:p7 r:HALF_EVEN (0 + decimal.pow(3,0e+1))', 1, 0 + decimal.pow(3,0e+1));
	AddTestCase('powx237:p7 r:HALF_EVEN (0 + decimal.pow(3,0e+10))', 1, 0 + decimal.pow(3,0e+10));
	AddTestCase('powx238:p7 r:HALF_EVEN (0 + decimal.pow(3,0e+30))', 1, 0 + decimal.pow(3,0e+30));
	AddTestCase('powx239:p7 r:HALF_EVEN (0 + decimal.pow(0e-30,-3))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0e-30,-3));
	AddTestCase('powx240:p7 r:HALF_EVEN (0 + decimal.pow(0e-10,-3))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0e-10,-3));
	AddTestCase('powx241:p7 r:HALF_EVEN (0 + decimal.pow(0e-1,-3))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0e-1,-3));
	AddTestCase('powx242:p7 r:HALF_EVEN (0 + decimal.pow(0e+0,-3))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0e+0,-3));
	AddTestCase('powx243:p7 r:HALF_EVEN (0 + decimal.pow(0,-3))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0,-3));
	AddTestCase('powx244:p7 r:HALF_EVEN (0 + decimal.pow(0e+1,-3))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0e+1,-3));
	AddTestCase('powx245:p7 r:HALF_EVEN (0 + decimal.pow(0e+10,-3))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0e+10,-3));
	AddTestCase('powx246:p7 r:HALF_EVEN (0 + decimal.pow(0e+30,-3))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0e+30,-3));
	AddTestCase('powx247:p7 r:HALF_EVEN (0 + decimal.pow(-3,0e-30))', 1, 0 + decimal.pow(-3,0e-30));
	AddTestCase('powx248:p7 r:HALF_EVEN (0 + decimal.pow(-3,0e-10))', 1, 0 + decimal.pow(-3,0e-10));
	AddTestCase('powx249:p7 r:HALF_EVEN (0 + decimal.pow(-3,0e-1))', 1, 0 + decimal.pow(-3,0e-1));
	AddTestCase('powx250:p7 r:HALF_EVEN (0 + decimal.pow(-3,0e+0))', 1, 0 + decimal.pow(-3,0e+0));
	AddTestCase('powx251:p7 r:HALF_EVEN (0 + decimal.pow(-3,0))', 1, 0 + decimal.pow(-3,0));
	AddTestCase('powx252:p7 r:HALF_EVEN (0 + decimal.pow(-3,0e+1))', 1, 0 + decimal.pow(-3,0e+1));
	AddTestCase('powx253:p7 r:HALF_EVEN (0 + decimal.pow(-3,0e+10))', 1, 0 + decimal.pow(-3,0e+10));
	AddTestCase('powx254:p7 r:HALF_EVEN (0 + decimal.pow(-3,0e+30))', 1, 0 + decimal.pow(-3,0e+30));
	// a few lhs negatives
}
{
	use precision 9;
	AddTestCase('powx260:p9 r:HALF_EVEN (0 + decimal.pow(-10,0))', 1, 0 + decimal.pow(-10,0));
	AddTestCase('powx261:p9 r:HALF_EVEN (0 + decimal.pow(-10,1))', -10, 0 + decimal.pow(-10,1));
	AddTestCase('powx262:p9 r:HALF_EVEN (0 + decimal.pow(-10,2))', 100, 0 + decimal.pow(-10,2));
	AddTestCase('powx263:p9 r:HALF_EVEN (0 + decimal.pow(-10,3))', -1000, 0 + decimal.pow(-10,3));
	AddTestCase('powx264:p9 r:HALF_EVEN (0 + decimal.pow(-10,4))', 10000, 0 + decimal.pow(-10,4));
	AddTestCase('powx265:p9 r:HALF_EVEN (0 + decimal.pow(-10,5))', -100000, 0 + decimal.pow(-10,5));
	AddTestCase('powx266:p9 r:HALF_EVEN (0 + decimal.pow(-10,6))', 1000000, 0 + decimal.pow(-10,6));
	AddTestCase('powx267:p9 r:HALF_EVEN (0 + decimal.pow(-10,7))', -10000000, 0 + decimal.pow(-10,7));
	AddTestCase('powx268:p9 r:HALF_EVEN (0 + decimal.pow(-10,8))', 100000000, 0 + decimal.pow(-10,8));
	AddTestCase('powx269:p9 r:HALF_EVEN (0 + decimal.pow(-10,9)) rounded', -1.00000000e+9, 0 + decimal.pow(-10,9));
	AddTestCase('powx270:p9 r:HALF_EVEN (0 + decimal.pow(-10,22)) rounded', 1.00000000e+22, 0 + decimal.pow(-10,22));
	AddTestCase('powx271:p9 r:HALF_EVEN (0 + decimal.pow(-10,77)) rounded', -1.00000000e+77, 0 + decimal.pow(-10,77));
	AddTestCase('powx272:p9 r:HALF_EVEN (0 + decimal.pow(-10,99)) rounded', -1.00000000e+99, 0 + decimal.pow(-10,99));
	// some more edge cases
}
{
	use precision 15;
	AddTestCase('powx391:p15 r:HALF_EVEN (0 + decimal.pow(0.1,999))', 1e-999, 0 + decimal.pow(0.1,999));
	// multiply tests are here to aid checking and test for consistent handling
	// of underflow
}
{
	use precision 5;
	// squares
	AddTestCase('mulx406:p5 r:HALF_EVEN (40e-501 * 40e-501)', 1.600e-999, 40e-501 * 40e-501);
	AddTestCase('powx406:p5 r:HALF_EVEN (0 + decimal.pow(40e-501,2))', 1.600e-999, 0 + decimal.pow(40e-501,2));
	// cubes
	AddTestCase('mulx416:p5 r:HALF_EVEN (10e-668 * 100e-334)', 1.000e-999, 10e-668 * 100e-334);
	AddTestCase('powx416:p5 r:HALF_EVEN (0 + decimal.pow(10e-334,3))', 1.000e-999, 0 + decimal.pow(10e-334,3));
	// negative powers, testing subnormals
}
{
	use precision 5;
	AddTestCase('powx422:p5 r:HALF_EVEN (0 + decimal.pow(2.5e-500,-2))', 1.6e+999, 0 + decimal.pow(2.5e-500,-2));
	AddTestCase('powx423:p5 r:HALF_EVEN (0 + decimal.pow(2.5e+499,-2))', 1.6e-999, 0 + decimal.pow(2.5e+499,-2));
	AddTestCase('powx427:p5 r:HALF_EVEN (0 + decimal.pow(0.25e+499,-2))', 1.6e-997, 0 + decimal.pow(0.25e+499,-2));
	AddTestCase('powx428:p5 r:HALF_EVEN (0 + decimal.pow(0.25e+500,-2))', 1.6e-999, 0 + decimal.pow(0.25e+500,-2));
	AddTestCase('powx432:p5 r:HALF_EVEN (0 + decimal.pow(0.04e+499,-2))', 6.25e-996, 0 + decimal.pow(0.04e+499,-2));
	AddTestCase('powx433:p5 r:HALF_EVEN (0 + decimal.pow(0.04e+500,-2))', 6.25e-998, 0 + decimal.pow(0.04e+500,-2));
	AddTestCase('powx441:p5 r:HALF_EVEN (0 + decimal.pow(0.04e+334,-3))', 1.5625e-998, 0 + decimal.pow(0.04e+334,-3));
	AddTestCase('powx444:p5 r:HALF_EVEN (0 + decimal.pow(0.25e+333,-3))', 6.4e-998, 0 + decimal.pow(0.25e+333,-3));
	// check sign for cubes  and a few squares
	AddTestCase('powx448:p5 r:HALF_EVEN (0 + decimal.pow(-0.04e+334,-3))', -1.5625e-998, 0 + decimal.pow(-0.04e+334,-3));
	AddTestCase('powx451:p5 r:HALF_EVEN (0 + decimal.pow(-0.25e+333,-3))', -6.4e-998, 0 + decimal.pow(-0.25e+333,-3));
	AddTestCase('powx455:p5 r:HALF_EVEN (0 + decimal.pow(-0.04e+499,-2))', 6.25e-996, 0 + decimal.pow(-0.04e+499,-2));
	AddTestCase('powx456:p5 r:HALF_EVEN (0 + decimal.pow(-0.04e+500,-2))', 6.25e-998, 0 + decimal.pow(-0.04e+500,-2));
	// test -0s
}
{
	use precision 9;
	AddTestCase('powx560:p9 r:HALF_EVEN (0 + decimal.pow(0,0)) invalid_operation', 1, 0 + decimal.pow(0,0));
	AddTestCase('powx561:p9 r:HALF_EVEN (0 + decimal.pow(0,-0)) invalid_operation', 1, 0 + decimal.pow(0,-0));
	AddTestCase('powx562:p9 r:HALF_EVEN (0 + decimal.pow(-0,0)) invalid_operation', 1, 0 + decimal.pow(-0,0));
	AddTestCase('powx563:p9 r:HALF_EVEN (0 + decimal.pow(-0,-0)) invalid_operation', 1, 0 + decimal.pow(-0,-0));
	AddTestCase('powx564:p9 r:HALF_EVEN (0 + decimal.pow(1,0))', 1, 0 + decimal.pow(1,0));
	AddTestCase('powx565:p9 r:HALF_EVEN (0 + decimal.pow(1,-0))', 1, 0 + decimal.pow(1,-0));
	AddTestCase('powx566:p9 r:HALF_EVEN (0 + decimal.pow(-1,0))', 1, 0 + decimal.pow(-1,0));
	AddTestCase('powx567:p9 r:HALF_EVEN (0 + decimal.pow(-1,-0))', 1, 0 + decimal.pow(-1,-0));
	AddTestCase('powx568:p9 r:HALF_EVEN (0 + decimal.pow(0,1))', 0, 0 + decimal.pow(0,1));
	AddTestCase('powx569:p9 r:HALF_EVEN (0 + decimal.pow(0,-1))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0,-1));
	AddTestCase('powx570:p9 r:HALF_EVEN (0 + decimal.pow(-0,1))', -0, 0 + decimal.pow(-0,1));
	AddTestCase('powx571:p9 r:HALF_EVEN (0 + decimal.pow(-0,-1))', decimal.NEGATIVE_INFINITY, 0 + decimal.pow(-0,-1));
	AddTestCase('powx572:p9 r:HALF_EVEN (0 + decimal.pow(0,2))', 0, 0 + decimal.pow(0,2));
	AddTestCase('powx573:p9 r:HALF_EVEN (0 + decimal.pow(0,-2))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0,-2));
	AddTestCase('powx574:p9 r:HALF_EVEN (0 + decimal.pow(-0,2))', 0, 0 + decimal.pow(-0,2));
	AddTestCase('powx575:p9 r:HALF_EVEN (0 + decimal.pow(-0,-2))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(-0,-2));
	AddTestCase('powx576:p9 r:HALF_EVEN (0 + decimal.pow(0,3))', 0, 0 + decimal.pow(0,3));
	AddTestCase('powx577:p9 r:HALF_EVEN (0 + decimal.pow(0,-3))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0,-3));
	AddTestCase('powx578:p9 r:HALF_EVEN (0 + decimal.pow(-0,3))', -0, 0 + decimal.pow(-0,3));
	AddTestCase('powx579:p9 r:HALF_EVEN (0 + decimal.pow(-0,-3))', decimal.NEGATIVE_INFINITY, 0 + decimal.pow(-0,-3));
	// specials
	AddTestCase('powx580:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY))', 0, 0 + decimal.pow(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx581:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,-1000))', 0, 0 + decimal.pow(decimal.POSITIVE_INFINITY,-1000));
	AddTestCase('powx582:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,-1))', 0, 0 + decimal.pow(decimal.POSITIVE_INFINITY,-1));
	AddTestCase('powx583:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,-0.5))', 0, 0 + decimal.pow(decimal.POSITIVE_INFINITY,-0.5));
	AddTestCase('powx584:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,-0))', 1, 0 + decimal.pow(decimal.POSITIVE_INFINITY,-0));
	AddTestCase('powx585:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,0))', 1, 0 + decimal.pow(decimal.POSITIVE_INFINITY,0));
	AddTestCase('powx586:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,0.5))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(decimal.POSITIVE_INFINITY,0.5));
	AddTestCase('powx587:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,1))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(decimal.POSITIVE_INFINITY,1));
	AddTestCase('powx588:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,1000))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(decimal.POSITIVE_INFINITY,1000));
	AddTestCase('powx589:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY));
	AddTestCase('powx590:p9 r:HALF_EVEN (0 + decimal.pow(-1000,decimal.POSITIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.pow(-1000,decimal.POSITIVE_INFINITY));
	AddTestCase('powx591:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY));
	AddTestCase('powx592:p9 r:HALF_EVEN (0 + decimal.pow(-1,decimal.POSITIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.pow(-1,decimal.POSITIVE_INFINITY));
	AddTestCase('powx593:p9 r:HALF_EVEN (0 + decimal.pow(-0.5,decimal.POSITIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.pow(-0.5,decimal.POSITIVE_INFINITY));
	AddTestCase('powx594:p9 r:HALF_EVEN (0 + decimal.pow(-0,decimal.POSITIVE_INFINITY))', 0, 0 + decimal.pow(-0,decimal.POSITIVE_INFINITY));
	AddTestCase('powx595:p9 r:HALF_EVEN (0 + decimal.pow(0,decimal.POSITIVE_INFINITY))', 0, 0 + decimal.pow(0,decimal.POSITIVE_INFINITY));
	AddTestCase('powx596:p9 r:HALF_EVEN (0 + decimal.pow(0.5,decimal.POSITIVE_INFINITY))', 0, 0 + decimal.pow(0.5,decimal.POSITIVE_INFINITY));
	AddTestCase('powx597:p9 r:HALF_EVEN (0 + decimal.pow(1,decimal.POSITIVE_INFINITY)) inexact rounded', 1.00000000, 0 + decimal.pow(1,decimal.POSITIVE_INFINITY));
	AddTestCase('powx598:p9 r:HALF_EVEN (0 + decimal.pow(1000,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(1000,decimal.POSITIVE_INFINITY));
	AddTestCase('powx599:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY));
	AddTestCase('powx600:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx601:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,-1000))', 0, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,-1000));
	AddTestCase('powx602:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,-1))', -0, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,-1));
	AddTestCase('powx603:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,-0.5)) invalid_operation', NaN, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,-0.5));
	AddTestCase('powx604:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,-0))', 1, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,-0));
	AddTestCase('powx605:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,0))', 1, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,0));
	AddTestCase('powx606:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,0.5)) invalid_operation', NaN, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,0.5));
	AddTestCase('powx607:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,1))', decimal.NEGATIVE_INFINITY, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,1));
	AddTestCase('powx608:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,1000))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,1000));
	AddTestCase('powx609:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY));
	AddTestCase('powx610:p9 r:HALF_EVEN (0 + decimal.pow(-1000,decimal.POSITIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.pow(-1000,decimal.POSITIVE_INFINITY));
	AddTestCase('powx611:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx612:p9 r:HALF_EVEN (0 + decimal.pow(-1,decimal.NEGATIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.pow(-1,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx613:p9 r:HALF_EVEN (0 + decimal.pow(-0.5,decimal.NEGATIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.pow(-0.5,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx614:p9 r:HALF_EVEN (0 + decimal.pow(-0,decimal.NEGATIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(-0,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx615:p9 r:HALF_EVEN (0 + decimal.pow(0,decimal.NEGATIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx616:p9 r:HALF_EVEN (0 + decimal.pow(0.5,decimal.NEGATIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(0.5,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx617:p9 r:HALF_EVEN (0 + decimal.pow(1,decimal.NEGATIVE_INFINITY)) inexact rounded', 1.00000000, 0 + decimal.pow(1,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx618:p9 r:HALF_EVEN (0 + decimal.pow(1000,decimal.NEGATIVE_INFINITY))', 0, 0 + decimal.pow(1000,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx619:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY))', 0, 0 + decimal.pow(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx621:p9 r:HALF_EVEN (0 + decimal.pow(NaN,decimal.NEGATIVE_INFINITY))', NaN, 0 + decimal.pow(NaN,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx622:p9 r:HALF_EVEN (0 + decimal.pow(NaN,-1000))', NaN, 0 + decimal.pow(NaN,-1000));
	AddTestCase('powx623:p9 r:HALF_EVEN (0 + decimal.pow(NaN,-1))', NaN, 0 + decimal.pow(NaN,-1));
	AddTestCase('powx624:p9 r:HALF_EVEN (0 + decimal.pow(NaN,-0.5))', NaN, 0 + decimal.pow(NaN,-0.5));
	AddTestCase('powx625:p9 r:HALF_EVEN (0 + decimal.pow(NaN,-0))', 1, 0 + decimal.pow(NaN,-0));
	AddTestCase('powx626:p9 r:HALF_EVEN (0 + decimal.pow(NaN,0))', 1, 0 + decimal.pow(NaN,0));
	AddTestCase('powx627:p9 r:HALF_EVEN (0 + decimal.pow(NaN,0.5))', NaN, 0 + decimal.pow(NaN,0.5));
	AddTestCase('powx628:p9 r:HALF_EVEN (0 + decimal.pow(NaN,1))', NaN, 0 + decimal.pow(NaN,1));
	AddTestCase('powx629:p9 r:HALF_EVEN (0 + decimal.pow(NaN,1000))', NaN, 0 + decimal.pow(NaN,1000));
	AddTestCase('powx630:p9 r:HALF_EVEN (0 + decimal.pow(NaN,decimal.POSITIVE_INFINITY))', NaN, 0 + decimal.pow(NaN,decimal.POSITIVE_INFINITY));
	AddTestCase('powx631:p9 r:HALF_EVEN (0 + decimal.pow(NaN,NaN))', NaN, 0 + decimal.pow(NaN,NaN));
	AddTestCase('powx632:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,NaN))', NaN, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,NaN));
	AddTestCase('powx633:p9 r:HALF_EVEN (0 + decimal.pow(-1000,NaN))', NaN, 0 + decimal.pow(-1000,NaN));
	AddTestCase('powx634:p9 r:HALF_EVEN (0 + decimal.pow(-1,NaN))', NaN, 0 + decimal.pow(-1,NaN));
	AddTestCase('powx635:p9 r:HALF_EVEN (0 + decimal.pow(-0,NaN))', NaN, 0 + decimal.pow(-0,NaN));
	AddTestCase('powx636:p9 r:HALF_EVEN (0 + decimal.pow(0,NaN))', NaN, 0 + decimal.pow(0,NaN));
	AddTestCase('powx637:p9 r:HALF_EVEN (0 + decimal.pow(1,NaN))', NaN, 0 + decimal.pow(1,NaN));
	AddTestCase('powx638:p9 r:HALF_EVEN (0 + decimal.pow(1000,NaN))', NaN, 0 + decimal.pow(1000,NaN));
	AddTestCase('powx639:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,NaN))', NaN, 0 + decimal.pow(decimal.POSITIVE_INFINITY,NaN));
	AddTestCase('powx641:p9 r:HALF_EVEN (0 + decimal.pow(NaN,decimal.NEGATIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.pow(NaN,decimal.NEGATIVE_INFINITY));
	AddTestCase('powx642:p9 r:HALF_EVEN (0 + decimal.pow(NaN,-1000)) invalid_operation', NaN, 0 + decimal.pow(NaN,-1000));
	AddTestCase('powx643:p9 r:HALF_EVEN (0 + decimal.pow(NaN,-1)) invalid_operation', NaN, 0 + decimal.pow(NaN,-1));
	AddTestCase('powx644:p9 r:HALF_EVEN (0 + decimal.pow(NaN,-0.5)) invalid_operation', NaN, 0 + decimal.pow(NaN,-0.5));
	AddTestCase('powx645:p9 r:HALF_EVEN (0 + decimal.pow(NaN,-0)) invalid_operation', 1, 0 + decimal.pow(NaN,-0));
	AddTestCase('powx646:p9 r:HALF_EVEN (0 + decimal.pow(NaN,0)) invalid_operation', 1, 0 + decimal.pow(NaN,0));
	AddTestCase('powx647:p9 r:HALF_EVEN (0 + decimal.pow(NaN,0.5)) invalid_operation', NaN, 0 + decimal.pow(NaN,0.5));
	AddTestCase('powx648:p9 r:HALF_EVEN (0 + decimal.pow(NaN,1)) invalid_operation', NaN, 0 + decimal.pow(NaN,1));
	AddTestCase('powx649:p9 r:HALF_EVEN (0 + decimal.pow(NaN,1000)) invalid_operation', NaN, 0 + decimal.pow(NaN,1000));
	AddTestCase('powx650:p9 r:HALF_EVEN (0 + decimal.pow(NaN,NaN)) invalid_operation', NaN, 0 + decimal.pow(NaN,NaN));
	AddTestCase('powx651:p9 r:HALF_EVEN (0 + decimal.pow(NaN,NaN)) invalid_operation', NaN, 0 + decimal.pow(NaN,NaN));
	AddTestCase('powx652:p9 r:HALF_EVEN (0 + decimal.pow(NaN,NaN)) invalid_operation', NaN, 0 + decimal.pow(NaN,NaN));
	AddTestCase('powx653:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,NaN)) invalid_operation', NaN, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,NaN));
	AddTestCase('powx654:p9 r:HALF_EVEN (0 + decimal.pow(-1000,NaN)) invalid_operation', NaN, 0 + decimal.pow(-1000,NaN));
	AddTestCase('powx655:p9 r:HALF_EVEN (0 + decimal.pow(-1,NaN)) invalid_operation', NaN, 0 + decimal.pow(-1,NaN));
	AddTestCase('powx656:p9 r:HALF_EVEN (0 + decimal.pow(-0.5,NaN)) invalid_operation', NaN, 0 + decimal.pow(-0.5,NaN));
	AddTestCase('powx657:p9 r:HALF_EVEN (0 + decimal.pow(-0,NaN)) invalid_operation', NaN, 0 + decimal.pow(-0,NaN));
	AddTestCase('powx658:p9 r:HALF_EVEN (0 + decimal.pow(0,NaN)) invalid_operation', NaN, 0 + decimal.pow(0,NaN));
	AddTestCase('powx659:p9 r:HALF_EVEN (0 + decimal.pow(0.5,NaN)) invalid_operation', NaN, 0 + decimal.pow(0.5,NaN));
	AddTestCase('powx660:p9 r:HALF_EVEN (0 + decimal.pow(1,NaN)) invalid_operation', NaN, 0 + decimal.pow(1,NaN));
	AddTestCase('powx661:p9 r:HALF_EVEN (0 + decimal.pow(1000,NaN)) invalid_operation', NaN, 0 + decimal.pow(1000,NaN));
	AddTestCase('powx662:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,NaN)) invalid_operation', NaN, 0 + decimal.pow(decimal.POSITIVE_INFINITY,NaN));
	AddTestCase('powx663:p9 r:HALF_EVEN (0 + decimal.pow(NaN,NaN)) invalid_operation', NaN, 0 + decimal.pow(NaN,NaN));
	// nan propagation
	AddTestCase('powx670:p9 r:HALF_EVEN (0 + decimal.pow(NaN,NaN)) invalid_operation', NaN, 0 + decimal.pow(NaN,NaN));
	AddTestCase('powx671:p9 r:HALF_EVEN (0 + decimal.pow(NaN,NaN)) invalid_operation', NaN, 0 + decimal.pow(NaN,NaN));
	AddTestCase('powx672:p9 r:HALF_EVEN (0 + decimal.pow(1,NaN)) invalid_operation', NaN, 0 + decimal.pow(1,NaN));
	AddTestCase('powx673:p9 r:HALF_EVEN (0 + decimal.pow(NaN,1)) invalid_operation', NaN, 0 + decimal.pow(NaN,1));
	AddTestCase('powx674:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,NaN)) invalid_operation', NaN, 0 + decimal.pow(decimal.POSITIVE_INFINITY,NaN));
	AddTestCase('powx675:p9 r:HALF_EVEN (0 + decimal.pow(NaN,decimal.POSITIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.pow(NaN,decimal.POSITIVE_INFINITY));
	AddTestCase('powx676:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,NaN))', NaN, 0 + decimal.pow(decimal.POSITIVE_INFINITY,NaN));
	AddTestCase('powx677:p9 r:HALF_EVEN (0 + decimal.pow(NaN,decimal.POSITIVE_INFINITY))', NaN, 0 + decimal.pow(NaN,decimal.POSITIVE_INFINITY));
	AddTestCase('powx678:p9 r:HALF_EVEN (0 + decimal.pow(1,NaN))', NaN, 0 + decimal.pow(1,NaN));
	AddTestCase('powx679:p9 r:HALF_EVEN (0 + decimal.pow(NaN,1))', NaN, 0 + decimal.pow(NaN,1));
	AddTestCase('powx680:p9 r:HALF_EVEN (0 + decimal.pow(NaN,NaN))', NaN, 0 + decimal.pow(NaN,NaN));
	AddTestCase('powx681:p9 r:HALF_EVEN (0 + decimal.pow(NaN,NaN))', NaN, 0 + decimal.pow(NaN,NaN));
	AddTestCase('powx682:p9 r:HALF_EVEN (0 + decimal.pow(NaN,NaN))', NaN, 0 + decimal.pow(NaN,NaN));
	AddTestCase('powx683:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,-NaN)) invalid_operation', -NaN, 0 + decimal.pow(decimal.POSITIVE_INFINITY,-NaN));
	AddTestCase('powx684:p9 r:HALF_EVEN (0 + decimal.pow(-NaN,decimal.POSITIVE_INFINITY)) invalid_operation', -NaN, 0 + decimal.pow(-NaN,decimal.POSITIVE_INFINITY));
	AddTestCase('powx685:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,-NaN))', -NaN, 0 + decimal.pow(decimal.POSITIVE_INFINITY,-NaN));
	AddTestCase('powx686:p9 r:HALF_EVEN (0 + decimal.pow(-NaN,decimal.POSITIVE_INFINITY))', -NaN, 0 + decimal.pow(-NaN,decimal.POSITIVE_INFINITY));
	AddTestCase('powx687:p9 r:HALF_EVEN (0 + decimal.pow(-NaN,-NaN))', -NaN, 0 + decimal.pow(-NaN,-NaN));
	// long operand and rhs range checks
}
{
	use precision 9;
	AddTestCase('powx701:p9 r:HALF_EVEN (0 + decimal.pow(12345678000,1)) rounded', 1.23456780e+10, 0 + decimal.pow(12345678000,1));
	AddTestCase('powx702:p9 r:HALF_EVEN (0 + decimal.pow(1234567800,1)) rounded', 1.23456780e+9, 0 + decimal.pow(1234567800,1));
	AddTestCase('powx703:p9 r:HALF_EVEN (0 + decimal.pow(1234567890,1)) rounded', 1.23456789e+9, 0 + decimal.pow(1234567890,1));
	AddTestCase('powx704:p9 r:HALF_EVEN (0 + decimal.pow(1234567891,1)) inexact rounded', 1.23456789e+9, 0 + decimal.pow(1234567891,1));
	AddTestCase('powx705:p9 r:HALF_EVEN (0 + decimal.pow(12345678901,1)) inexact rounded', 1.23456789e+10, 0 + decimal.pow(12345678901,1));
	AddTestCase('powx706:p9 r:HALF_EVEN (0 + decimal.pow(1234567896,1)) inexact rounded', 1.23456790e+9, 0 + decimal.pow(1234567896,1));
}
{
	use precision 15;
	// still checking
	AddTestCase('powx741:p15 r:HALF_EVEN (0 + decimal.pow(12345678000,1))', 12345678000, 0 + decimal.pow(12345678000,1));
	AddTestCase('powx742:p15 r:HALF_EVEN (0 + decimal.pow(1234567800,1))', 1234567800, 0 + decimal.pow(1234567800,1));
	AddTestCase('powx743:p15 r:HALF_EVEN (0 + decimal.pow(1234567890,1))', 1234567890, 0 + decimal.pow(1234567890,1));
	AddTestCase('powx744:p15 r:HALF_EVEN (0 + decimal.pow(1234567891,1))', 1234567891, 0 + decimal.pow(1234567891,1));
	AddTestCase('powx745:p15 r:HALF_EVEN (0 + decimal.pow(12345678901,1))', 12345678901, 0 + decimal.pow(12345678901,1));
	AddTestCase('powx746:p15 r:HALF_EVEN (0 + decimal.pow(1234567896,1))', 1234567896, 0 + decimal.pow(1234567896,1));
}
{
	use precision 9;
	// near out-of-range edge cases
	AddTestCase('powx163:p9 r:HALF_EVEN (0 + decimal.pow(10,999999)) rounded', 1.00000000e+999999, 0 + decimal.pow(10,999999));
	AddTestCase('powx164:p9 r:HALF_EVEN (0 + decimal.pow(10,999998)) rounded', 1.00000000e+999998, 0 + decimal.pow(10,999998));
	AddTestCase('powx165:p9 r:HALF_EVEN (0 + decimal.pow(10,999997)) rounded', 1.00000000e+999997, 0 + decimal.pow(10,999997));
	AddTestCase('powx166:p9 r:HALF_EVEN (0 + decimal.pow(10,333333)) rounded', 1.00000000e+333333, 0 + decimal.pow(10,333333));
	AddTestCase('powx183:p9 r:HALF_EVEN (0 + decimal.pow(7,1000000)) inexact rounded', 1.09651419e+845098, 0 + decimal.pow(7,1000000));
	AddTestCase('powx184:p9 r:HALF_EVEN (0 + decimal.pow(7,1000001)) inexact rounded', 7.67559934e+845098, 0 + decimal.pow(7,1000001));
	AddTestCase('powx186:p9 r:HALF_EVEN (0 + decimal.pow(7,-1000001)) inexact rounded', 1.30282986e-845099, 0 + decimal.pow(7,-1000001));
	AddTestCase('powx187:p9 r:HALF_EVEN (0 + decimal.pow(7,-1000000)) inexact rounded', 9.11980901e-845099, 0 + decimal.pow(7,-1000000));
	AddTestCase('powx118:p9 r:HALF_EVEN (0 + decimal.pow(10,-333333))', 1e-333333, 0 + decimal.pow(10,-333333));
	AddTestCase('powx119:p9 r:HALF_EVEN (0 + decimal.pow(10,-999998))', 1e-999998, 0 + decimal.pow(10,-999998));
	AddTestCase('powx120:p9 r:HALF_EVEN (0 + decimal.pow(10,-999999))', 1e-999999, 0 + decimal.pow(10,-999999));
	AddTestCase('powx181:p9 r:HALF_EVEN (0 + decimal.pow(7,999998)) inexact rounded', 2.23778406e+845096, 0 + decimal.pow(7,999998));
	AddTestCase('powx182:p9 r:HALF_EVEN (0 + decimal.pow(7,999999)) inexact rounded', 1.56644884e+845097, 0 + decimal.pow(7,999999));
	AddTestCase('powx189:p9 r:HALF_EVEN (0 + decimal.pow(7,-999999)) inexact rounded', 6.38386631e-845098, 0 + decimal.pow(7,-999999));
	AddTestCase('powx190:p9 r:HALF_EVEN (0 + decimal.pow(7,-999998)) inexact rounded', 4.46870641e-845097, 0 + decimal.pow(7,-999998));
	// overflow and underflow tests
}
{
	use precision 9;
	AddTestCase('powx277:p9 r:HALF_EVEN (0 + decimal.pow(9,999999)) inexact rounded', 3.59084629e+954241, 0 + decimal.pow(9,999999));
	AddTestCase('powx278:p9 r:HALF_EVEN (0 + decimal.pow(9.99999999,999999)) inexact rounded', 9.99000501e+999998, 0 + decimal.pow(9.99999999,999999));
	AddTestCase('powx279:p9 r:HALF_EVEN (0 + decimal.pow(10,999999)) rounded', 1.00000000e+999999, 0 + decimal.pow(10,999999));
	AddTestCase('powx280:p9 r:HALF_EVEN (0 + decimal.pow(10.0000001,999999)) inexact rounded', 1.01005016e+999999, 0 + decimal.pow(10.0000001,999999));
	AddTestCase('powx281:p9 r:HALF_EVEN (0 + decimal.pow(10.000001,999999)) inexact rounded', 1.10517080e+999999, 0 + decimal.pow(10.000001,999999));
	AddTestCase('powx282:p9 r:HALF_EVEN (0 + decimal.pow(10.00001,999999)) inexact rounded', 2.71827775e+999999, 0 + decimal.pow(10.00001,999999));
	AddTestCase('powx290:p9 r:HALF_EVEN (0 + decimal.pow(0.5,999999)) inexact rounded', 2.02006812e-301030, 0 + decimal.pow(0.5,999999));
	AddTestCase('powx291:p9 r:HALF_EVEN (0 + decimal.pow(0.1,999999)) -- unrounded', 1e-999999, 0 + decimal.pow(0.1,999999));
	AddTestCase('powx310:p9 r:HALF_EVEN (0 + decimal.pow(-9,999999)) inexact rounded', -3.59084629e+954241, 0 + decimal.pow(-9,999999));
	AddTestCase('powx311:p9 r:HALF_EVEN (0 + decimal.pow(-10,999999)) rounded', -1.00000000e+999999, 0 + decimal.pow(-10,999999));
	AddTestCase('powx320:p9 r:HALF_EVEN (0 + decimal.pow(-0.5,999999)) inexact rounded', -2.02006812e-301030, 0 + decimal.pow(-0.5,999999));
	AddTestCase('powx321:p9 r:HALF_EVEN (0 + decimal.pow(-0.1,999999))', -1e-999999, 0 + decimal.pow(-0.1,999999));
	// note no trim of next result
	AddTestCase('powx330:p9 r:HALF_EVEN (0 + decimal.pow(-9,999998)) inexact rounded', 3.98982921e+954240, 0 + decimal.pow(-9,999998));
	AddTestCase('powx331:p9 r:HALF_EVEN (0 + decimal.pow(-10,999998)) rounded', 1.00000000e+999998, 0 + decimal.pow(-10,999998));
	AddTestCase('powx340:p9 r:HALF_EVEN (0 + decimal.pow(-0.5,999998)) inexact rounded', 4.04013624e-301030, 0 + decimal.pow(-0.5,999998));
	AddTestCase('powx341:p9 r:HALF_EVEN (0 + decimal.pow(-0.1,999998)) -- nb exact unrounded', 1e-999998, 0 + decimal.pow(-0.1,999998));
	// some subnormals
}
{
	use precision 9;
	// [precision is 9, so smallest exponent is -1000000007
	AddTestCase('powx350:p9 r:HALF_EVEN (0 + decimal.pow(1e-1,500000))', 1e-500000, 0 + decimal.pow(1e-1,500000));
	AddTestCase('powx360:p9 r:HALF_EVEN (0 + decimal.pow(0.010001,500000)) inexact rounded', 5.17176082e-999979, 0 + decimal.pow(0.010001,500000));
	// 1/subnormal -> overflow
	AddTestCase('powx371:p9 r:HALF_EVEN (0 + decimal.pow(1e-1,-500000))', 1e+500000, 0 + decimal.pow(1e-1,-500000));
	AddTestCase('powx381:p9 r:HALF_EVEN (0 + decimal.pow(0.010001,-500000)) inexact rounded', 1.93357743e+999978, 0 + decimal.pow(0.010001,-500000));
	AddTestCase('powx382:p9 r:HALF_EVEN (0 + decimal.pow(0.010000001,-500000)) inexact rounded', 9.51229427e+999999, 0 + decimal.pow(0.010000001,-500000));
	AddTestCase('powx384:p9 r:HALF_EVEN (0 + decimal.pow(0.0100000009,-500000)) inexact rounded', 9.55997484e+999999, 0 + decimal.pow(0.0100000009,-500000));
	AddTestCase('powx385:p9 r:HALF_EVEN (0 + decimal.pow(0.0100000001,-500000)) inexact rounded', 9.95012479e+999999, 0 + decimal.pow(0.0100000001,-500000));
	// negative power giving subnormal
	// test some 'false integer' boundaries
}
{
	use precision 16;
	{
		use rounding HALF_EVEN;
		AddTestCase('powx501:p16 r:HALF_EVEN (0 + decimal.pow(100,1e+1)) rounded', 1.000000000000000e+20, 0 + decimal.pow(100,1e+1));
		AddTestCase('powx502:p16 r:HALF_EVEN (0 + decimal.pow(100,1e+2)) rounded', 1.000000000000000e+200, 0 + decimal.pow(100,1e+2));
		// a check for double-rounded subnormals
		{
			use precision 5;
			// null tests
			AddTestCase('powx900:p5 r:HALF_EVEN (0 + decimal.pow(1,null)) ', 1, 0 + decimal.pow(1,null));
			AddTestCase('powx901:p5 r:HALF_EVEN (0 + decimal.pow(null,1)) ', 0, 0 + decimal.pow(null,1));
			//--------------------------------------------------------------------
			// below here are tests with a precision or context outside of the  --
			// decnumber 'mathematical functions' restricted range.  these      --
			// remain supported in decnumber to minimize breakage, but may be   --
			// outside the range of other implementations.                      --
			//--------------------------------------------------------------------
		}
		{
			use precision 9;
			AddTestCase('powx1063:p9 r:HALF_EVEN (0 + decimal.pow(10,999999999)) rounded', 1.00000000e+999999999, 0 + decimal.pow(10,999999999));
			AddTestCase('powx1064:p9 r:HALF_EVEN (0 + decimal.pow(10,999999998)) rounded', 1.00000000e+999999998, 0 + decimal.pow(10,999999998));
			AddTestCase('powx1065:p9 r:HALF_EVEN (0 + decimal.pow(10,999999997)) rounded', 1.00000000e+999999997, 0 + decimal.pow(10,999999997));
			AddTestCase('powx1066:p9 r:HALF_EVEN (0 + decimal.pow(10,333333333)) rounded', 1.00000000e+333333333, 0 + decimal.pow(10,333333333));
			// next two are integer-out-of range
			AddTestCase('powx1183:p9 r:HALF_EVEN (0 + decimal.pow(7,1000000000)) invalid_context', Infinity, 0 + decimal.pow(7,1000000000));
			AddTestCase('powx1184:p9 r:HALF_EVEN (0 + decimal.pow(7,1000000001)) invalid_context', Infinity, 0 + decimal.pow(7,1000000001));
			AddTestCase('powx1186:p9 r:HALF_EVEN (0 + decimal.pow(7,-1000000001)) inexact rounded', 1.38243630e-845098041, 0 + decimal.pow(7,-1000000001));
			AddTestCase('powx1187:p9 r:HALF_EVEN (0 + decimal.pow(7,-1000000000)) inexact rounded', 9.67705411e-845098041, 0 + decimal.pow(7,-1000000000));
			// out-of-range edge cases
			AddTestCase('powx1118:p9 r:HALF_EVEN (0 + decimal.pow(10,-333333333))', 1e-333333333, 0 + decimal.pow(10,-333333333));
			AddTestCase('powx1119:p9 r:HALF_EVEN (0 + decimal.pow(10,-999999998))', 1e-999999998, 0 + decimal.pow(10,-999999998));
			AddTestCase('powx1120:p9 r:HALF_EVEN (0 + decimal.pow(10,-999999999))', 1e-999999999, 0 + decimal.pow(10,-999999999));
			AddTestCase('powx1181:p9 r:HALF_EVEN (0 + decimal.pow(7,999999998)) inexact rounded', 2.10892313e+845098038, 0 + decimal.pow(7,999999998));
			AddTestCase('powx1182:p9 r:HALF_EVEN (0 + decimal.pow(7,999999999)) inexact rounded', 1.47624619e+845098039, 0 + decimal.pow(7,999999999));
			AddTestCase('powx1189:p9 r:HALF_EVEN (0 + decimal.pow(7,-999999999)) inexact rounded', 6.77393787e-845098040, 0 + decimal.pow(7,-999999999));
			AddTestCase('powx1190:p9 r:HALF_EVEN (0 + decimal.pow(7,-999999998)) inexact rounded', 4.74175651e-845098039, 0 + decimal.pow(7,-999999998));
			// a (rare) case where the last digit is not within 0.5 ulp with classic precision
		}
		{
			use precision 9;
			//AddTestCase('powx1215:p9 r:HALF_EVEN (0 + decimal.pow("-21971575.0e+31454441","-7")) inexact rounded', "-4.04549502e-220181139", 0 + decimal.pow("-21971575.0e+31454441","-7"));
		}
		{
			use precision 20;
			//AddTestCase('powx1216:p20 r:HALF_EVEN (0 + decimal.pow("-21971575.0e+31454441","-7")) inexact rounded', "-4.0454950249324891788e-220181139", 0 + decimal.pow("-21971575.0e+31454441","-7"));
			// overflow and underflow tests
		}
		{
			use precision 9;
			AddTestCase('powx1280:p9 r:HALF_EVEN (0 + decimal.pow(9,999999999)) inexact rounded', 3.05550054e+954242508, 0 + decimal.pow(9,999999999));
			AddTestCase('powx1281:p9 r:HALF_EVEN (0 + decimal.pow(10,999999999)) rounded', 1.00000000e+999999999, 0 + decimal.pow(10,999999999));
			AddTestCase('powx1290:p9 r:HALF_EVEN (0 + decimal.pow(0.5,999999999)) inexact rounded', 4.33559594e-301029996, 0 + decimal.pow(0.5,999999999));
			AddTestCase('powx1291:p9 r:HALF_EVEN (0 + decimal.pow(0.1,999999999)) -- unrounded', 1e-999999999, 0 + decimal.pow(0.1,999999999));
			AddTestCase('powx1310:p9 r:HALF_EVEN (0 + decimal.pow(-9,999999999)) inexact rounded', -3.05550054e+954242508, 0 + decimal.pow(-9,999999999));
			AddTestCase('powx1311:p9 r:HALF_EVEN (0 + decimal.pow(-10,999999999)) rounded', -1.00000000e+999999999, 0 + decimal.pow(-10,999999999));
			AddTestCase('powx1320:p9 r:HALF_EVEN (0 + decimal.pow(-0.5,999999999)) inexact rounded', -4.33559594e-301029996, 0 + decimal.pow(-0.5,999999999));
			AddTestCase('powx1321:p9 r:HALF_EVEN (0 + decimal.pow(-0.1,999999999))', -1e-999999999, 0 + decimal.pow(-0.1,999999999));
			// note no trim of next result
			AddTestCase('powx1330:p9 r:HALF_EVEN (0 + decimal.pow(-9,999999998)) inexact rounded', 3.39500060e+954242507, 0 + decimal.pow(-9,999999998));
			AddTestCase('powx1331:p9 r:HALF_EVEN (0 + decimal.pow(-10,999999998)) rounded', 1.00000000e+999999998, 0 + decimal.pow(-10,999999998));
			AddTestCase('powx1340:p9 r:HALF_EVEN (0 + decimal.pow(-0.5,999999998)) inexact rounded', 8.67119187e-301029996, 0 + decimal.pow(-0.5,999999998));
			AddTestCase('powx1341:p9 r:HALF_EVEN (0 + decimal.pow(-0.1,999999998)) -- nb exact unrounded', 1e-999999998, 0 + decimal.pow(-0.1,999999998));
			// some subnormals
		}
		{
			use precision 9;
			// [precision is 9, so smallest exponent is -1000000007
			AddTestCase('powx1350:p9 r:HALF_EVEN (0 + decimal.pow(1e-1,500000000))', 1e-500000000, 0 + decimal.pow(1e-1,500000000));
			AddTestCase('powx1360:p9 r:HALF_EVEN (0 + decimal.pow(0.010001,500000000)) inexact rounded', 4.34941988e-999978287, 0 + decimal.pow(0.010001,500000000));
			AddTestCase('powx1361:p9 r:HALF_EVEN (0 + decimal.pow(0.010000001,500000000)) inexact rounded', 5.18469257e-999999979, 0 + decimal.pow(0.010000001,500000000));
			AddTestCase('powx1362:p9 r:HALF_EVEN (0 + decimal.pow(0.010000001,500000001)) inexact rounded', 5.18469309e-999999981, 0 + decimal.pow(0.010000001,500000001));
			AddTestCase('powx1363:p9 r:HALF_EVEN (0 + decimal.pow(0.0100000009,500000000)) inexact rounded', 3.49342003e-999999981, 0 + decimal.pow(0.0100000009,500000000));
			AddTestCase('powx1364:p9 r:HALF_EVEN (0 + decimal.pow(0.0100000001,500000000)) inexact rounded', 1.48413155e-999999998, 0 + decimal.pow(0.0100000001,500000000));
			// 1/subnormal -> overflow
			AddTestCase('powx1371:p9 r:HALF_EVEN (0 + decimal.pow(1e-1,-500000000))', 1e+500000000, 0 + decimal.pow(1e-1,-500000000));
			AddTestCase('powx1381:p9 r:HALF_EVEN (0 + decimal.pow(0.010001,-500000000)) inexact rounded', 2.29915719e+999978286, 0 + decimal.pow(0.010001,-500000000));
			AddTestCase('powx1382:p9 r:HALF_EVEN (0 + decimal.pow(0.010000001,-500000000)) inexact rounded', 1.92875467e+999999978, 0 + decimal.pow(0.010000001,-500000000));
			AddTestCase('powx1383:p9 r:HALF_EVEN (0 + decimal.pow(0.010000001,-500000001)) inexact rounded', 1.92875448e+999999980, 0 + decimal.pow(0.010000001,-500000001));
			AddTestCase('powx1384:p9 r:HALF_EVEN (0 + decimal.pow(0.0100000009,-500000000)) inexact rounded', 2.86252438e+999999980, 0 + decimal.pow(0.0100000009,-500000000));
			AddTestCase('powx1385:p9 r:HALF_EVEN (0 + decimal.pow(0.0100000001,-500000000)) inexact rounded', 6.73794717e+999999997, 0 + decimal.pow(0.0100000001,-500000000));
			// negative power giving subnormal
			//--------------------------------------------------------------------
			// below here are the tests with a non-integer rhs, including the   --
			// tests that previously caused invalid operation.  an integer-only --
			// (on rhs) implementation should handle all the tests above as     --
			// shown, and would flag most of the following tests as invalid.    --
			//--------------------------------------------------------------------
		}
		{
			use precision 16;
			{
				use rounding HALF_EVEN;
				AddTestCase('powx2001:p16 r:HALF_EVEN (0 + decimal.pow(2,2.000001)) inexact rounded', 4.000002772589683, 0 + decimal.pow(2,2.000001));
				AddTestCase('powx2002:p16 r:HALF_EVEN (0 + decimal.pow(2,2.00000000))', 4, 0 + decimal.pow(2,2.00000000));
				AddTestCase('powx2003:p16 r:HALF_EVEN (0 + decimal.pow(2,2.000000001)) inexact rounded', 4.000000002772589, 0 + decimal.pow(2,2.000000001));
				AddTestCase('powx2004:p16 r:HALF_EVEN (0 + decimal.pow(2,2.0000000001)) inexact rounded', 4.000000000277259, 0 + decimal.pow(2,2.0000000001));
				AddTestCase('powx2005:p16 r:HALF_EVEN (0 + decimal.pow(2,2.00000000001)) inexact rounded', 4.000000000027726, 0 + decimal.pow(2,2.00000000001));
				AddTestCase('powx2006:p16 r:HALF_EVEN (0 + decimal.pow(2,2.000000000001)) inexact rounded', 4.000000000002773, 0 + decimal.pow(2,2.000000000001));
				AddTestCase('powx2007:p16 r:HALF_EVEN (0 + decimal.pow(2,2.0000000000001)) inexact rounded', 4.000000000000277, 0 + decimal.pow(2,2.0000000000001));
				AddTestCase('powx2008:p16 r:HALF_EVEN (0 + decimal.pow(2,2.00000000000001)) inexact rounded', 4.000000000000028, 0 + decimal.pow(2,2.00000000000001));
				AddTestCase('powx2009:p16 r:HALF_EVEN (0 + decimal.pow(2,2.000000000000001)) inexact rounded', 4.000000000000003, 0 + decimal.pow(2,2.000000000000001));
				AddTestCase('powx2010:p16 r:HALF_EVEN (0 + decimal.pow(2,2.0000000000000001)) inexact rounded', 4.000000000000000, 0 + decimal.pow(2,2.0000000000000001));
				//                1 234567890123456
				AddTestCase('powx2011:p16 r:HALF_EVEN (0 + decimal.pow(1,1234))', 1, 0 + decimal.pow(1,1234));
				{
					use precision 4;
					AddTestCase('powx2012:p4 r:HALF_EVEN (0 + decimal.pow(1,1234))', 1, 0 + decimal.pow(1,1234));
				}
				{
					use precision 3;
					AddTestCase('powx2013:p3 r:HALF_EVEN (0 + decimal.pow(1,1234))', 1, 0 + decimal.pow(1,1234));
					AddTestCase('powx2014:p3 r:HALF_EVEN (0 + decimal.pow(1,12.34e+2))', 1, 0 + decimal.pow(1,12.34e+2));
					AddTestCase('powx2015:p3 r:HALF_EVEN (0 + decimal.pow(1,12.3)) inexact rounded', 1.00, 0 + decimal.pow(1,12.3));
					AddTestCase('powx2016:p3 r:HALF_EVEN (0 + decimal.pow(1,12.0))', 1, 0 + decimal.pow(1,12.0));
					AddTestCase('powx2017:p3 r:HALF_EVEN (0 + decimal.pow(1,1.01)) inexact rounded', 1.00, 0 + decimal.pow(1,1.01));
					AddTestCase('powx2018:p3 r:HALF_EVEN (0 + decimal.pow(2,1.00))', 2, 0 + decimal.pow(2,1.00));
					AddTestCase('powx2019:p3 r:HALF_EVEN (0 + decimal.pow(2,2.00))', 4, 0 + decimal.pow(2,2.00));
				}
				{
					use precision 9;
					AddTestCase('powx2030:p9 r:HALF_EVEN (0 + decimal.pow(1,1.0001)) inexact rounded', 1.00000000, 0 + decimal.pow(1,1.0001));
					AddTestCase('powx2031:p9 r:HALF_EVEN (0 + decimal.pow(1,1.0000001)) inexact rounded', 1.00000000, 0 + decimal.pow(1,1.0000001));
					AddTestCase('powx2032:p9 r:HALF_EVEN (0 + decimal.pow(1,1.0000000001)) inexact rounded', 1.00000000, 0 + decimal.pow(1,1.0000000001));
					AddTestCase('powx2033:p9 r:HALF_EVEN (0 + decimal.pow(1,1.0000000000001)) inexact rounded', 1.00000000, 0 + decimal.pow(1,1.0000000000001));
				}
				{
					use precision 5;
					AddTestCase('powx2034:p5 r:HALF_EVEN (0 + decimal.pow(1,1.0001)) inexact rounded', 1.0000, 0 + decimal.pow(1,1.0001));
					AddTestCase('powx2035:p5 r:HALF_EVEN (0 + decimal.pow(1,1.0000001)) inexact rounded', 1.0000, 0 + decimal.pow(1,1.0000001));
					AddTestCase('powx2036:p5 r:HALF_EVEN (0 + decimal.pow(1,1.0000000001)) inexact rounded', 1.0000, 0 + decimal.pow(1,1.0000000001));
					AddTestCase('powx2037:p5 r:HALF_EVEN (0 + decimal.pow(1,1.0000000000001)) inexact rounded', 1.0000, 0 + decimal.pow(1,1.0000000000001));
					AddTestCase('powx2038:p5 r:HALF_EVEN (0 + decimal.pow(1,1.0000000000001)) inexact rounded', 1.0000, 0 + decimal.pow(1,1.0000000000001));
					{
						use rounding CEILING;
						{
							use precision 3;
							AddTestCase('powx2039:p3 r:CEILING (0 + decimal.pow(1,1.01)) inexact rounded', 1.00, 0 + decimal.pow(1,1.01));
							AddTestCase('powx2040:p3 r:CEILING (0 + decimal.pow(1,12.3)) inexact rounded', 1.00, 0 + decimal.pow(1,12.3));
							{
								use rounding HALF_EVEN;
								// 1 ** any integer, including big ones, should be exact
								AddTestCase('powx2041:p3 r:HALF_EVEN (0 + decimal.pow(1,1000000000))', 1, 0 + decimal.pow(1,1000000000));
								AddTestCase('powx2042:p3 r:HALF_EVEN (0 + decimal.pow(1,9999999999))', 1, 0 + decimal.pow(1,9999999999));
								AddTestCase('powx2043:p3 r:HALF_EVEN (0 + decimal.pow(1,12345678000))', 1, 0 + decimal.pow(1,12345678000));
								AddTestCase('powx2044:p3 r:HALF_EVEN (0 + decimal.pow(1,1234567800))', 1, 0 + decimal.pow(1,1234567800));
								AddTestCase('powx2045:p3 r:HALF_EVEN (0 + decimal.pow(1,1234567890))', 1, 0 + decimal.pow(1,1234567890));
								AddTestCase('powx2046:p3 r:HALF_EVEN (0 + decimal.pow(1,11234567891))', 1, 0 + decimal.pow(1,11234567891));
								AddTestCase('powx2047:p3 r:HALF_EVEN (0 + decimal.pow(1,12345678901))', 1, 0 + decimal.pow(1,12345678901));
								AddTestCase('powx2048:p3 r:HALF_EVEN (0 + decimal.pow(1,1234567896))', 1, 0 + decimal.pow(1,1234567896));
								AddTestCase('powx2049:p3 r:HALF_EVEN (0 + decimal.pow(1,-1234567896))', 1, 0 + decimal.pow(1,-1234567896));
								AddTestCase('powx2051:p3 r:HALF_EVEN (0 + decimal.pow(1,1000000000))', 1, 0 + decimal.pow(1,1000000000));
								AddTestCase('powx2052:p3 r:HALF_EVEN (0 + decimal.pow(1,-1000000000))', 1, 0 + decimal.pow(1,-1000000000));
								AddTestCase('powx2053:p3 r:HALF_EVEN (0 + decimal.pow(1,12345678000))', 1, 0 + decimal.pow(1,12345678000));
								AddTestCase('powx2054:p3 r:HALF_EVEN (0 + decimal.pow(1,-1234567896))', 1, 0 + decimal.pow(1,-1234567896));
								AddTestCase('powx2055:p3 r:HALF_EVEN (0 + decimal.pow(1,1000000000))', 1, 0 + decimal.pow(1,1000000000));
								AddTestCase('powx2056:p3 r:HALF_EVEN (0 + decimal.pow(1,4300000000))', 1, 0 + decimal.pow(1,4300000000));
								AddTestCase('powx2057:p3 r:HALF_EVEN (0 + decimal.pow(1,-1000000000))', 1, 0 + decimal.pow(1,-1000000000));
								// negatives ... but not out of range for decnumber
								AddTestCase('powx2061:p3 r:HALF_EVEN (0 + decimal.pow(-1,100000))', 1, 0 + decimal.pow(-1,100000));
								AddTestCase('powx2062:p3 r:HALF_EVEN (0 + decimal.pow(-1,999999))', -1, 0 + decimal.pow(-1,999999));
								AddTestCase('powx2063:p3 r:HALF_EVEN (0 + decimal.pow(-1,1278000))', 1, 0 + decimal.pow(-1,1278000));
								AddTestCase('powx2064:p3 r:HALF_EVEN (0 + decimal.pow(-1,127803))', -1, 0 + decimal.pow(-1,127803));
								AddTestCase('powx2065:p3 r:HALF_EVEN (0 + decimal.pow(-1,127890))', 1, 0 + decimal.pow(-1,127890));
								AddTestCase('powx2066:p3 r:HALF_EVEN (0 + decimal.pow(-1,1167891))', -1, 0 + decimal.pow(-1,1167891));
								AddTestCase('powx2067:p3 r:HALF_EVEN (0 + decimal.pow(-1,1278901))', -1, 0 + decimal.pow(-1,1278901));
								AddTestCase('powx2068:p3 r:HALF_EVEN (0 + decimal.pow(-1,127896))', 1, 0 + decimal.pow(-1,127896));
								AddTestCase('powx2069:p3 r:HALF_EVEN (0 + decimal.pow(-1,-167897))', -1, 0 + decimal.pow(-1,-167897));
								AddTestCase('powx2071:p3 r:HALF_EVEN (0 + decimal.pow(-1,100000))', 1, 0 + decimal.pow(-1,100000));
								AddTestCase('powx2072:p3 r:HALF_EVEN (0 + decimal.pow(-1,-100001))', -1, 0 + decimal.pow(-1,-100001));
								AddTestCase('powx2073:p3 r:HALF_EVEN (0 + decimal.pow(-1,1278000))', 1, 0 + decimal.pow(-1,1278000));
								AddTestCase('powx2074:p3 r:HALF_EVEN (0 + decimal.pow(-1,-167896))', 1, 0 + decimal.pow(-1,-167896));
								AddTestCase('powx2075:p3 r:HALF_EVEN (0 + decimal.pow(-1,100000))', 1, 0 + decimal.pow(-1,100000));
								AddTestCase('powx2076:p3 r:HALF_EVEN (0 + decimal.pow(-1,-100009))', -1, 0 + decimal.pow(-1,-100009));
								// the above were derived from the earlier version of power.dectest;
								// now start new tests for power(x,y) for non-integer y
								{
									use precision 9;
									// tests from specification
									AddTestCase('powx2081:p9 r:HALF_EVEN (0 + decimal.pow(2,3))', 8, 0 + decimal.pow(2,3));
									AddTestCase('powx2082:p9 r:HALF_EVEN (0 + decimal.pow(-2,3))', -8, 0 + decimal.pow(-2,3));
									AddTestCase('powx2083:p9 r:HALF_EVEN (0 + decimal.pow(2,-3))', 0.125, 0 + decimal.pow(2,-3));
									AddTestCase('powx2084:p9 r:HALF_EVEN (0 + decimal.pow(1.7,8)) inexact rounded', 69.7575744, 0 + decimal.pow(1.7,8));
									AddTestCase('powx2085:p9 r:HALF_EVEN (0 + decimal.pow(10,0.301029996)) inexact rounded', 2.00000000, 0 + decimal.pow(10,0.301029996));
									AddTestCase('powx2086:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,-1))', 0, 0 + decimal.pow(decimal.POSITIVE_INFINITY,-1));
									AddTestCase('powx2087:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,0))', 1, 0 + decimal.pow(decimal.POSITIVE_INFINITY,0));
									AddTestCase('powx2088:p9 r:HALF_EVEN (0 + decimal.pow(decimal.POSITIVE_INFINITY,1))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(decimal.POSITIVE_INFINITY,1));
									AddTestCase('powx2089:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,-1))', -0, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,-1));
									AddTestCase('powx2090:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,0))', 1, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,0));
									AddTestCase('powx2091:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,1))', decimal.NEGATIVE_INFINITY, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,1));
									AddTestCase('powx2092:p9 r:HALF_EVEN (0 + decimal.pow(decimal.NEGATIVE_INFINITY,2))', decimal.POSITIVE_INFINITY, 0 + decimal.pow(decimal.NEGATIVE_INFINITY,2));
									AddTestCase('powx2093:p9 r:HALF_EVEN (0 + decimal.pow(0,0)) invalid_operation', 1, 0 + decimal.pow(0,0));
								}
								{
									use precision 16;
									{
										use rounding HALF_EVEN;
										// basics
										AddTestCase('powx2100:p16 r:HALF_EVEN (0 + decimal.pow(1e-7,1e-7)) inexact rounded', 0.9999983881917339, 0 + decimal.pow(1e-7,1e-7));
										AddTestCase('powx2101:p16 r:HALF_EVEN (0 + decimal.pow(0.003,1e-7)) inexact rounded', 0.9999994190858697, 0 + decimal.pow(0.003,1e-7));
										AddTestCase('powx2102:p16 r:HALF_EVEN (0 + decimal.pow(0.7,1e-7)) inexact rounded', 0.9999999643325062, 0 + decimal.pow(0.7,1e-7));
										AddTestCase('powx2103:p16 r:HALF_EVEN (0 + decimal.pow(1.2,1e-7)) inexact rounded', 1.000000018232156, 0 + decimal.pow(1.2,1e-7));
										AddTestCase('powx2104:p16 r:HALF_EVEN (0 + decimal.pow(71,1e-7)) inexact rounded', 1.000000426268079, 0 + decimal.pow(71,1e-7));
										AddTestCase('powx2105:p16 r:HALF_EVEN (0 + decimal.pow(9e+9,1e-7)) inexact rounded', 1.000002292051668, 0 + decimal.pow(9e+9,1e-7));
										AddTestCase('powx2110:p16 r:HALF_EVEN (0 + decimal.pow(1e-7,0.003)) inexact rounded', 0.9527961640236519, 0 + decimal.pow(1e-7,0.003));
										AddTestCase('powx2111:p16 r:HALF_EVEN (0 + decimal.pow(0.003,0.003)) inexact rounded', 0.9827235503366797, 0 + decimal.pow(0.003,0.003));
										AddTestCase('powx2112:p16 r:HALF_EVEN (0 + decimal.pow(0.7,0.003)) inexact rounded', 0.9989305474406207, 0 + decimal.pow(0.7,0.003));
										AddTestCase('powx2113:p16 r:HALF_EVEN (0 + decimal.pow(1.2,0.003)) inexact rounded', 1.000547114282834, 0 + decimal.pow(1.2,0.003));
										AddTestCase('powx2114:p16 r:HALF_EVEN (0 + decimal.pow(71,0.003)) inexact rounded', 1.012870156273545, 0 + decimal.pow(71,0.003));
										AddTestCase('powx2115:p16 r:HALF_EVEN (0 + decimal.pow(9e+9,0.003)) inexact rounded', 1.071180671278787, 0 + decimal.pow(9e+9,0.003));
										AddTestCase('powx2120:p16 r:HALF_EVEN (0 + decimal.pow(1e-7,0.7)) inexact rounded', 0.00001258925411794167, 0 + decimal.pow(1e-7,0.7));
										AddTestCase('powx2121:p16 r:HALF_EVEN (0 + decimal.pow(0.003,0.7)) inexact rounded', 0.01713897630281030, 0 + decimal.pow(0.003,0.7));
										AddTestCase('powx2122:p16 r:HALF_EVEN (0 + decimal.pow(0.7,0.7)) inexact rounded', 0.7790559126704491, 0 + decimal.pow(0.7,0.7));
										AddTestCase('powx2123:p16 r:HALF_EVEN (0 + decimal.pow(1.2,0.7)) inexact rounded', 1.136126977198889, 0 + decimal.pow(1.2,0.7));
										AddTestCase('powx2124:p16 r:HALF_EVEN (0 + decimal.pow(71,0.7)) inexact rounded', 19.76427300093870, 0 + decimal.pow(71,0.7));
										AddTestCase('powx2125:p16 r:HALF_EVEN (0 + decimal.pow(9e+9,0.7)) inexact rounded', 9289016.976853710, 0 + decimal.pow(9e+9,0.7));
										AddTestCase('powx2130:p16 r:HALF_EVEN (0 + decimal.pow(1e-7,1.2)) inexact rounded', 3.981071705534973e-9, 0 + decimal.pow(1e-7,1.2));
										AddTestCase('powx2131:p16 r:HALF_EVEN (0 + decimal.pow(0.003,1.2)) inexact rounded', 0.0009387403933595694, 0 + decimal.pow(0.003,1.2));
										AddTestCase('powx2132:p16 r:HALF_EVEN (0 + decimal.pow(0.7,1.2)) inexact rounded', 0.6518049405663864, 0 + decimal.pow(0.7,1.2));
										AddTestCase('powx2133:p16 r:HALF_EVEN (0 + decimal.pow(1.2,1.2)) inexact rounded', 1.244564747203978, 0 + decimal.pow(1.2,1.2));
										AddTestCase('powx2134:p16 r:HALF_EVEN (0 + decimal.pow(71,1.2)) inexact rounded', 166.5367244638552, 0 + decimal.pow(71,1.2));
										AddTestCase('powx2135:p16 r:HALF_EVEN (0 + decimal.pow(9e+9,1.2)) inexact rounded', 881233526124.8791, 0 + decimal.pow(9e+9,1.2));
										AddTestCase('powx2141:p16 r:HALF_EVEN (0 + decimal.pow(0.003,71)) inexact rounded', 7.509466514979725e-180, 0 + decimal.pow(0.003,71));
										AddTestCase('powx2142:p16 r:HALF_EVEN (0 + decimal.pow(0.7,71)) inexact rounded', 1.004525211269079e-11, 0 + decimal.pow(0.7,71));
										AddTestCase('powx2143:p16 r:HALF_EVEN (0 + decimal.pow(1.2,71)) inexact rounded', 418666.7483186515, 0 + decimal.pow(1.2,71));
										AddTestCase('powx2144:p16 r:HALF_EVEN (0 + decimal.pow(71,71)) inexact rounded', 2.750063734834616e+131, 0 + decimal.pow(71,71));
										// number line milestones with lhs<1 and lhs>1
										// overflow boundary (nmax)
										AddTestCase('powx2201:p16 r:HALF_EVEN (0 + decimal.pow(71,207.966651583983199)) inexact rounded', 9.999999999999994e+384, 0 + decimal.pow(71,207.966651583983199));
										AddTestCase('powx2203:p16 r:HALF_EVEN (0 + decimal.pow(0.003,-152.603449817093576)) inexact rounded', 9.999999999999994e+384, 0 + decimal.pow(0.003,-152.603449817093576));
										// nmin boundary
										AddTestCase('powx2211:p16 r:HALF_EVEN (0 + decimal.pow(71,-206.886305341988480)) inexact rounded', 1.000000000000005e-383, 0 + decimal.pow(71,-206.886305341988480));
										AddTestCase('powx2212:p16 r:HALF_EVEN (0 + decimal.pow(71,-206.886305341988481)) inexact rounded', 1.000000000000001e-383, 0 + decimal.pow(71,-206.886305341988481));
										//                                           9.999999999999924565357019820
										AddTestCase('powx2215:p16 r:HALF_EVEN (0 + decimal.pow(0.003,151.810704623238543)) inexact rounded', 1.000000000000009e-383, 0 + decimal.pow(0.003,151.810704623238543));
										AddTestCase('powx2216:p16 r:HALF_EVEN (0 + decimal.pow(0.003,151.810704623238544)) inexact rounded', 1.000000000000003e-383, 0 + decimal.pow(0.003,151.810704623238544));
										// ntiny boundary, these edge cases determined using half_up rounding
									}
									{
										use rounding HALF_UP;
									}
									{
										use rounding HALF_EVEN;
										// power(10, y) are important ...
										// integer powers are exact, unless over/underflow
										AddTestCase('powx2302:p16 r:HALF_EVEN (0 + decimal.pow(10,384)) rounded', 1.000000000000000e+384, 0 + decimal.pow(10,384));
										AddTestCase('powx2303:p16 r:HALF_EVEN (0 + decimal.pow(10,17)) rounded', 1.000000000000000e+17, 0 + decimal.pow(10,17));
										AddTestCase('powx2304:p16 r:HALF_EVEN (0 + decimal.pow(10,16)) rounded', 1.000000000000000e+16, 0 + decimal.pow(10,16));
										AddTestCase('powx2305:p16 r:HALF_EVEN (0 + decimal.pow(10,15))', 1000000000000000, 0 + decimal.pow(10,15));
										AddTestCase('powx2306:p16 r:HALF_EVEN (0 + decimal.pow(10,10))', 10000000000, 0 + decimal.pow(10,10));
										AddTestCase('powx2307:p16 r:HALF_EVEN (0 + decimal.pow(10,5))', 100000, 0 + decimal.pow(10,5));
										AddTestCase('powx2308:p16 r:HALF_EVEN (0 + decimal.pow(10,1))', 10, 0 + decimal.pow(10,1));
										AddTestCase('powx2309:p16 r:HALF_EVEN (0 + decimal.pow(10,0))', 1, 0 + decimal.pow(10,0));
										AddTestCase('powx2310:p16 r:HALF_EVEN (0 + decimal.pow(10,-1))', 0.1, 0 + decimal.pow(10,-1));
										AddTestCase('powx2311:p16 r:HALF_EVEN (0 + decimal.pow(10,-5))', 0.00001, 0 + decimal.pow(10,-5));
										AddTestCase('powx2312:p16 r:HALF_EVEN (0 + decimal.pow(10,-6))', 0.000001, 0 + decimal.pow(10,-6));
										AddTestCase('powx2313:p16 r:HALF_EVEN (0 + decimal.pow(10,-7))', 1e-7, 0 + decimal.pow(10,-7));
										AddTestCase('powx2314:p16 r:HALF_EVEN (0 + decimal.pow(10,-8))', 1e-8, 0 + decimal.pow(10,-8));
										AddTestCase('powx2315:p16 r:HALF_EVEN (0 + decimal.pow(10,-9))', 1e-9, 0 + decimal.pow(10,-9));
										AddTestCase('powx2316:p16 r:HALF_EVEN (0 + decimal.pow(10,-10))', 1e-10, 0 + decimal.pow(10,-10));
										AddTestCase('powx2317:p16 r:HALF_EVEN (0 + decimal.pow(10,-383))', 1e-383, 0 + decimal.pow(10,-383));
										// independent sanity check: 1961 godfrey & siddons four-figure logs
										AddTestCase('powx2351:p16 r:HALF_EVEN (0 + decimal.pow(10,0.0000))', 1, 0 + decimal.pow(10,0.0000));
										AddTestCase('powx2352:p16 r:HALF_EVEN (0 + decimal.pow(10,0.3010)) inexact rounded', 1.999861869632744, 0 + decimal.pow(10,0.3010));
										AddTestCase('powx2353:p16 r:HALF_EVEN (0 + decimal.pow(10,0.4771)) inexact rounded', 2.999853181190793, 0 + decimal.pow(10,0.4771));
										AddTestCase('powx2354:p16 r:HALF_EVEN (0 + decimal.pow(10,0.6021)) inexact rounded', 4.000368510461250, 0 + decimal.pow(10,0.6021));
										AddTestCase('powx2355:p16 r:HALF_EVEN (0 + decimal.pow(10,0.6990)) inexact rounded', 5.000345349769785, 0 + decimal.pow(10,0.6990));
										AddTestCase('powx2356:p16 r:HALF_EVEN (0 + decimal.pow(10,0.7782)) inexact rounded', 6.000673538641164, 0 + decimal.pow(10,0.7782));
										AddTestCase('powx2357:p16 r:HALF_EVEN (0 + decimal.pow(10,0.8451)) inexact rounded', 7.000031591308969, 0 + decimal.pow(10,0.8451));
										AddTestCase('powx2358:p16 r:HALF_EVEN (0 + decimal.pow(10,0.9031)) inexact rounded', 8.000184448550990, 0 + decimal.pow(10,0.9031));
										AddTestCase('powx2359:p16 r:HALF_EVEN (0 + decimal.pow(10,0.9542)) inexact rounded', 8.999119108700520, 0 + decimal.pow(10,0.9542));
										AddTestCase('powx2360:p16 r:HALF_EVEN (0 + decimal.pow(10,0.9956)) inexact rounded', 9.899197750805841, 0 + decimal.pow(10,0.9956));
										AddTestCase('powx2361:p16 r:HALF_EVEN (0 + decimal.pow(10,0.9996)) inexact rounded', 9.990793899844618, 0 + decimal.pow(10,0.9996));
										{
											use precision 4;
											AddTestCase('powx2371:p4 r:HALF_EVEN (0 + decimal.pow(10,0.0000))', 1, 0 + decimal.pow(10,0.0000));
											AddTestCase('powx2372:p4 r:HALF_EVEN (0 + decimal.pow(10,0.3010)) inexact rounded', 2.000, 0 + decimal.pow(10,0.3010));
											AddTestCase('powx2373:p4 r:HALF_EVEN (0 + decimal.pow(10,0.4771)) inexact rounded', 3.000, 0 + decimal.pow(10,0.4771));
											AddTestCase('powx2374:p4 r:HALF_EVEN (0 + decimal.pow(10,0.6021)) inexact rounded', 4.000, 0 + decimal.pow(10,0.6021));
											AddTestCase('powx2375:p4 r:HALF_EVEN (0 + decimal.pow(10,0.6990)) inexact rounded', 5.000, 0 + decimal.pow(10,0.6990));
											AddTestCase('powx2376:p4 r:HALF_EVEN (0 + decimal.pow(10,0.7782)) inexact rounded', 6.001, 0 + decimal.pow(10,0.7782));
											AddTestCase('powx2377:p4 r:HALF_EVEN (0 + decimal.pow(10,0.8451)) inexact rounded', 7.000, 0 + decimal.pow(10,0.8451));
											AddTestCase('powx2378:p4 r:HALF_EVEN (0 + decimal.pow(10,0.9031)) inexact rounded', 8.000, 0 + decimal.pow(10,0.9031));
											AddTestCase('powx2379:p4 r:HALF_EVEN (0 + decimal.pow(10,0.9542)) inexact rounded', 8.999, 0 + decimal.pow(10,0.9542));
											AddTestCase('powx2380:p4 r:HALF_EVEN (0 + decimal.pow(10,0.9956)) inexact rounded', 9.899, 0 + decimal.pow(10,0.9956));
											AddTestCase('powx2381:p4 r:HALF_EVEN (0 + decimal.pow(10,0.9996)) inexact rounded', 9.991, 0 + decimal.pow(10,0.9996));
											// 10**x ~=2 (inverse of the test in log10.dectest)
										}
										{
											use precision 33;
											AddTestCase('powx2418:p33 r:HALF_EVEN (0 + decimal.pow(10,0.301029995663981195213738894724493)) inexact rounded', 2.00000000000000000000000000000000, 0 + decimal.pow(10,0.301029995663981195213738894724493));
										}
										{
											use precision 32;
											AddTestCase('powx2419:p32 r:HALF_EVEN (0 + decimal.pow(10,0.30102999566398119521373889472449)) inexact rounded', 2.0000000000000000000000000000000, 0 + decimal.pow(10,0.30102999566398119521373889472449));
										}
										{
											use precision 31;
											AddTestCase('powx2420:p31 r:HALF_EVEN (0 + decimal.pow(10,0.3010299956639811952137388947245)) inexact rounded', 2.000000000000000000000000000000, 0 + decimal.pow(10,0.3010299956639811952137388947245));
										}
										{
											use precision 30;
											AddTestCase('powx2421:p30 r:HALF_EVEN (0 + decimal.pow(10,0.301029995663981195213738894725)) inexact rounded', 2.00000000000000000000000000000, 0 + decimal.pow(10,0.301029995663981195213738894725));
										}
										{
											use precision 29;
											AddTestCase('powx2422:p29 r:HALF_EVEN (0 + decimal.pow(10,0.30102999566398119521373889472)) inexact rounded', 2.0000000000000000000000000000, 0 + decimal.pow(10,0.30102999566398119521373889472));
										}
										{
											use precision 28;
											AddTestCase('powx2423:p28 r:HALF_EVEN (0 + decimal.pow(10,0.3010299956639811952137388947)) inexact rounded', 2.000000000000000000000000000, 0 + decimal.pow(10,0.3010299956639811952137388947));
										}
										{
											use precision 27;
											AddTestCase('powx2424:p27 r:HALF_EVEN (0 + decimal.pow(10,0.301029995663981195213738895)) inexact rounded', 2.00000000000000000000000000, 0 + decimal.pow(10,0.301029995663981195213738895));
										}
										{
											use precision 26;
											AddTestCase('powx2425:p26 r:HALF_EVEN (0 + decimal.pow(10,0.30102999566398119521373889)) inexact rounded', 2.0000000000000000000000000, 0 + decimal.pow(10,0.30102999566398119521373889));
										}
										{
											use precision 25;
											AddTestCase('powx2426:p25 r:HALF_EVEN (0 + decimal.pow(10,0.3010299956639811952137389)) inexact rounded', 2.000000000000000000000000, 0 + decimal.pow(10,0.3010299956639811952137389));
										}
										{
											use precision 24;
											AddTestCase('powx2427:p24 r:HALF_EVEN (0 + decimal.pow(10,0.301029995663981195213739)) inexact rounded', 2.00000000000000000000000, 0 + decimal.pow(10,0.301029995663981195213739));
										}
										{
											use precision 23;
											AddTestCase('powx2428:p23 r:HALF_EVEN (0 + decimal.pow(10,0.30102999566398119521374)) inexact rounded', 2.0000000000000000000000, 0 + decimal.pow(10,0.30102999566398119521374));
										}
										{
											use precision 22;
											AddTestCase('powx2429:p22 r:HALF_EVEN (0 + decimal.pow(10,0.3010299956639811952137)) inexact rounded', 2.000000000000000000000, 0 + decimal.pow(10,0.3010299956639811952137));
										}
										{
											use precision 21;
											AddTestCase('powx2430:p21 r:HALF_EVEN (0 + decimal.pow(10,0.301029995663981195214)) inexact rounded', 2.00000000000000000000, 0 + decimal.pow(10,0.301029995663981195214));
										}
										{
											use precision 20;
											AddTestCase('powx2431:p20 r:HALF_EVEN (0 + decimal.pow(10,0.30102999566398119521)) inexact rounded', 2.0000000000000000000, 0 + decimal.pow(10,0.30102999566398119521));
										}
										{
											use precision 19;
											AddTestCase('powx2432:p19 r:HALF_EVEN (0 + decimal.pow(10,0.3010299956639811952)) inexact rounded', 2.000000000000000000, 0 + decimal.pow(10,0.3010299956639811952));
										}
										{
											use precision 18;
											AddTestCase('powx2433:p18 r:HALF_EVEN (0 + decimal.pow(10,0.301029995663981195)) inexact rounded', 2.00000000000000000, 0 + decimal.pow(10,0.301029995663981195));
										}
										{
											use precision 17;
											AddTestCase('powx2434:p17 r:HALF_EVEN (0 + decimal.pow(10,0.30102999566398120)) inexact rounded', 2.0000000000000000, 0 + decimal.pow(10,0.30102999566398120));
										}
										{
											use precision 16;
											AddTestCase('powx2435:p16 r:HALF_EVEN (0 + decimal.pow(10,0.3010299956639812)) inexact rounded', 2.000000000000000, 0 + decimal.pow(10,0.3010299956639812));
										}
										{
											use precision 15;
											AddTestCase('powx2436:p15 r:HALF_EVEN (0 + decimal.pow(10,0.301029995663981)) inexact rounded', 2.00000000000000, 0 + decimal.pow(10,0.301029995663981));
										}
										{
											use precision 14;
											AddTestCase('powx2437:p14 r:HALF_EVEN (0 + decimal.pow(10,0.30102999566398)) inexact rounded', 2.0000000000000, 0 + decimal.pow(10,0.30102999566398));
										}
										{
											use precision 13;
											AddTestCase('powx2438:p13 r:HALF_EVEN (0 + decimal.pow(10,0.3010299956640)) inexact rounded', 2.000000000000, 0 + decimal.pow(10,0.3010299956640));
										}
										{
											use precision 12;
											AddTestCase('powx2439:p12 r:HALF_EVEN (0 + decimal.pow(10,0.301029995664)) inexact rounded', 2.00000000000, 0 + decimal.pow(10,0.301029995664));
										}
										{
											use precision 11;
											AddTestCase('powx2440:p11 r:HALF_EVEN (0 + decimal.pow(10,0.30102999566)) inexact rounded', 2.0000000000, 0 + decimal.pow(10,0.30102999566));
										}
										{
											use precision 10;
											AddTestCase('powx2441:p10 r:HALF_EVEN (0 + decimal.pow(10,0.3010299957)) inexact rounded', 2.000000000, 0 + decimal.pow(10,0.3010299957));
										}
										{
											use precision 9;
											AddTestCase('powx2442:p9 r:HALF_EVEN (0 + decimal.pow(10,0.301029996)) inexact rounded', 2.00000000, 0 + decimal.pow(10,0.301029996));
										}
										{
											use precision 8;
											AddTestCase('powx2443:p8 r:HALF_EVEN (0 + decimal.pow(10,0.30103000)) inexact rounded', 2.0000000, 0 + decimal.pow(10,0.30103000));
										}
										{
											use precision 7;
											AddTestCase('powx2444:p7 r:HALF_EVEN (0 + decimal.pow(10,0.3010300)) inexact rounded', 2.000000, 0 + decimal.pow(10,0.3010300));
										}
										{
											use precision 6;
											AddTestCase('powx2445:p6 r:HALF_EVEN (0 + decimal.pow(10,0.301030)) inexact rounded', 2.00000, 0 + decimal.pow(10,0.301030));
										}
										{
											use precision 5;
											AddTestCase('powx2446:p5 r:HALF_EVEN (0 + decimal.pow(10,0.30103)) inexact rounded', 2.0000, 0 + decimal.pow(10,0.30103));
										}
										{
											use precision 4;
											AddTestCase('powx2447:p4 r:HALF_EVEN (0 + decimal.pow(10,0.3010)) inexact rounded', 2.000, 0 + decimal.pow(10,0.3010));
										}
										{
											use precision 3;
											AddTestCase('powx2448:p3 r:HALF_EVEN (0 + decimal.pow(10,0.301)) inexact rounded', 2.00, 0 + decimal.pow(10,0.301));
										}
										{
											use precision 2;
											AddTestCase('powx2449:p2 r:HALF_EVEN (0 + decimal.pow(10,0.30)) inexact rounded', 2.0, 0 + decimal.pow(10,0.30));
										}
										{
											use precision 1;
											AddTestCase('powx2450:p1 r:HALF_EVEN (0 + decimal.pow(10,0.3)) inexact rounded', 2, 0 + decimal.pow(10,0.3));
										}
										{
											use precision 16;
											{
												use rounding HALF_EVEN;
												// close-to-e tests
												// e**e, 16->34
												// sequence around an integer
												// randomly generated tests
												// p=34, within 0-999 -- positive arg2
												// p=16, within 0-99 -- positive arg2
												{
													use precision 16;
													AddTestCase('powx3101:p16 r:HALF_EVEN (0 + decimal.pow(0.0000215524639223,48.37532522355252)) inexact rounded', 1.804663257287277e-226, 0 + decimal.pow(0.0000215524639223,48.37532522355252));
													AddTestCase('powx3102:p16 r:HALF_EVEN (0 + decimal.pow(00.80705856227999,2706.777535121391)) inexact rounded', 1.029625065876157e-252, 0 + decimal.pow(00.80705856227999,2706.777535121391));
													AddTestCase('powx3103:p16 r:HALF_EVEN (0 + decimal.pow(3.445441676383689,428.5185892455830)) inexact rounded', 1.657401683096454e+230, 0 + decimal.pow(3.445441676383689,428.5185892455830));
													AddTestCase('powx3104:p16 r:HALF_EVEN (0 + decimal.pow(0.0040158689495826,159.5725558816240)) inexact rounded', 4.255743665762492e-383, 0 + decimal.pow(0.0040158689495826,159.5725558816240));
													AddTestCase('powx3105:p16 r:HALF_EVEN (0 + decimal.pow(0.0000841553281215,38.32504413453944)) inexact rounded', 6.738653902512052e-157, 0 + decimal.pow(0.0000841553281215,38.32504413453944));
													AddTestCase('powx3106:p16 r:HALF_EVEN (0 + decimal.pow(0.7322610252571353,502.1254457674118)) inexact rounded', 1.109978126985943e-68, 0 + decimal.pow(0.7322610252571353,502.1254457674118));
													AddTestCase('powx3107:p16 r:HALF_EVEN (0 + decimal.pow(10.75052532144880,67.34180604734781)) inexact rounded', 2.873015019470189e+69, 0 + decimal.pow(10.75052532144880,67.34180604734781));
													AddTestCase('powx3108:p16 r:HALF_EVEN (0 + decimal.pow(26.20425952945617,104.6002671186488)) inexact rounded', 2.301859355777030e+148, 0 + decimal.pow(26.20425952945617,104.6002671186488));
													AddTestCase('powx3109:p16 r:HALF_EVEN (0 + decimal.pow(0.0000055737473850,31.16285859005424)) inexact rounded', 1.883348470100446e-164, 0 + decimal.pow(0.0000055737473850,31.16285859005424));
													AddTestCase('powx3110:p16 r:HALF_EVEN (0 + decimal.pow(61.06096011360700,10.93608439088726)) inexact rounded', 3.382686473028249e+19, 0 + decimal.pow(61.06096011360700,10.93608439088726));
													AddTestCase('powx3111:p16 r:HALF_EVEN (0 + decimal.pow(9.340880853257137,179.9094938131726)) inexact rounded', 3.819299795937696e+174, 0 + decimal.pow(9.340880853257137,179.9094938131726));
													AddTestCase('powx3112:p16 r:HALF_EVEN (0 + decimal.pow(0.0000050767371756,72.03346394186741)) inexact rounded', 4.216236691569869e-382, 0 + decimal.pow(0.0000050767371756,72.03346394186741));
													AddTestCase('powx3113:p16 r:HALF_EVEN (0 + decimal.pow(6.838478807860596,47.49665590602285)) inexact rounded', 4.547621630099203e+39, 0 + decimal.pow(6.838478807860596,47.49665590602285));
													AddTestCase('powx3114:p16 r:HALF_EVEN (0 + decimal.pow(0.1299324346439081,397.7440523576938)) inexact rounded', 3.065047705553981e-353, 0 + decimal.pow(0.1299324346439081,397.7440523576938));
													AddTestCase('powx3115:p16 r:HALF_EVEN (0 + decimal.pow(0.0003418047034264,20.00516791512018)) inexact rounded', 4.546189665380487e-70, 0 + decimal.pow(0.0003418047034264,20.00516791512018));
													AddTestCase('powx3116:p16 r:HALF_EVEN (0 + decimal.pow(0.0001276899611715,78.12968287355703)) inexact rounded', 5.960217405063995e-305, 0 + decimal.pow(0.0001276899611715,78.12968287355703));
													AddTestCase('powx3117:p16 r:HALF_EVEN (0 + decimal.pow(25.93160588180509,252.6245071004620)) inexact rounded', 1.472171597589146e+357, 0 + decimal.pow(25.93160588180509,252.6245071004620));
													AddTestCase('powx3118:p16 r:HALF_EVEN (0 + decimal.pow(35.47516857763178,86.14723037360925)) inexact rounded', 3.324299908481125e+133, 0 + decimal.pow(35.47516857763178,86.14723037360925));
													AddTestCase('powx3119:p16 r:HALF_EVEN (0 + decimal.pow(0.0000048171086721,43.31965603038666)) inexact rounded', 4.572331516616228e-231, 0 + decimal.pow(0.0000048171086721,43.31965603038666));
													AddTestCase('powx3120:p16 r:HALF_EVEN (0 + decimal.pow(17.97652681097851,144.4684576550292)) inexact rounded', 1.842509906097860e+181, 0 + decimal.pow(17.97652681097851,144.4684576550292));
													AddTestCase('powx3121:p16 r:HALF_EVEN (0 + decimal.pow(3.622765141518729,305.1948680344950)) inexact rounded', 4.132320967578704e+170, 0 + decimal.pow(3.622765141518729,305.1948680344950));
													AddTestCase('powx3122:p16 r:HALF_EVEN (0 + decimal.pow(0.0080959002453519,143.9899444945627)) inexact rounded', 6.474627812947047e-302, 0 + decimal.pow(0.0080959002453519,143.9899444945627));
													AddTestCase('powx3123:p16 r:HALF_EVEN (0 + decimal.pow(9.841699927276571,299.2466668837188)) inexact rounded', 1.489097656208736e+297, 0 + decimal.pow(9.841699927276571,299.2466668837188));
													AddTestCase('powx3125:p16 r:HALF_EVEN (0 + decimal.pow(0.0000084459792645,52.47348690745487)) inexact rounded', 6.076251876516942e-267, 0 + decimal.pow(0.0000084459792645,52.47348690745487));
													AddTestCase('powx3126:p16 r:HALF_EVEN (0 + decimal.pow(27.86589909967504,191.7296537102283)) inexact rounded', 1.157064112989386e+277, 0 + decimal.pow(27.86589909967504,191.7296537102283));
													AddTestCase('powx3127:p16 r:HALF_EVEN (0 + decimal.pow(0.0000419907937234,58.44957702730767)) inexact rounded', 1.496950672075162e-256, 0 + decimal.pow(0.0000419907937234,58.44957702730767));
													AddTestCase('powx3128:p16 r:HALF_EVEN (0 + decimal.pow(0.0000664977739382,80.06749213261876)) inexact rounded', 3.488517620107875e-335, 0 + decimal.pow(0.0000664977739382,80.06749213261876));
													AddTestCase('powx3129:p16 r:HALF_EVEN (0 + decimal.pow(58.49554484886656,125.8480768373499)) inexact rounded', 2.449089862146640e+222, 0 + decimal.pow(58.49554484886656,125.8480768373499));
													AddTestCase('powx3130:p16 r:HALF_EVEN (0 + decimal.pow(15.02820060024449,212.3527988973338)) inexact rounded', 8.307913932682067e+249, 0 + decimal.pow(15.02820060024449,212.3527988973338));
													AddTestCase('powx3131:p16 r:HALF_EVEN (0 + decimal.pow(0.0002650089942992,30.92173123678761)) inexact rounded', 2.517827664836147e-111, 0 + decimal.pow(0.0002650089942992,30.92173123678761));
													AddTestCase('powx3132:p16 r:HALF_EVEN (0 + decimal.pow(0.0007342977426578,69.49168880741123)) inexact rounded', 1.600168665674440e-218, 0 + decimal.pow(0.0007342977426578,69.49168880741123));
													AddTestCase('powx3133:p16 r:HALF_EVEN (0 + decimal.pow(0.0063816068650629,150.1400094183812)) inexact rounded', 2.705057295799001e-330, 0 + decimal.pow(0.0063816068650629,150.1400094183812));
													AddTestCase('powx3134:p16 r:HALF_EVEN (0 + decimal.pow(9.912921122728791,297.8274013633411)) inexact rounded', 4.967624993438900e+296, 0 + decimal.pow(9.912921122728791,297.8274013633411));
													AddTestCase('powx3135:p16 r:HALF_EVEN (0 + decimal.pow(1.988603563989245,768.4862967922182)) inexact rounded', 2.692842474899596e+229, 0 + decimal.pow(1.988603563989245,768.4862967922182));
													AddTestCase('powx3136:p16 r:HALF_EVEN (0 + decimal.pow(8.418014519517691,164.2431359980725)) inexact rounded', 9.106211585888836e+151, 0 + decimal.pow(8.418014519517691,164.2431359980725));
													AddTestCase('powx3137:p16 r:HALF_EVEN (0 + decimal.pow(6.068823604450686,120.2955212365837)) inexact rounded', 1.599431918105982e+94, 0 + decimal.pow(6.068823604450686,120.2955212365837));
													AddTestCase('powx3138:p16 r:HALF_EVEN (0 + decimal.pow(56.90062738303850,54.90468294683645)) inexact rounded', 2.312839177902428e+96, 0 + decimal.pow(56.90062738303850,54.90468294683645));
													AddTestCase('powx3139:p16 r:HALF_EVEN (0 + decimal.pow(5.710905139750871,73.44608752962156)) inexact rounded', 3.775876053709929e+55, 0 + decimal.pow(5.710905139750871,73.44608752962156));
													AddTestCase('powx3140:p16 r:HALF_EVEN (0 + decimal.pow(0.0000017446761203,1.223981492228899)) inexact rounded', 8.952936595465635e-8, 0 + decimal.pow(0.0000017446761203,1.223981492228899));
													// p=7, within 0-9 -- positive arg2
												}
												{
													use precision 7;
													AddTestCase('powx3001:p7 r:HALF_EVEN (0 + decimal.pow(8.738689,55.96523)) inexact rounded', 4.878180e+52, 0 + decimal.pow(8.738689,55.96523));
													AddTestCase('powx3002:p7 r:HALF_EVEN (0 + decimal.pow(0.0404763,147.4965)) inexact rounded', 3.689722e-206, 0 + decimal.pow(0.0404763,147.4965));
													AddTestCase('powx3003:p7 r:HALF_EVEN (0 + decimal.pow(0.0604232,76.69778)) inexact rounded', 3.319183e-94, 0 + decimal.pow(0.0604232,76.69778));
													AddTestCase('powx3004:p7 r:HALF_EVEN (0 + decimal.pow(0.0058855,107.5018)) inexact rounded', 1.768875e-240, 0 + decimal.pow(0.0058855,107.5018));
													AddTestCase('powx3005:p7 r:HALF_EVEN (0 + decimal.pow(2.058302,1173.050)) inexact rounded', 5.778899e+367, 0 + decimal.pow(2.058302,1173.050));
													AddTestCase('powx3006:p7 r:HALF_EVEN (0 + decimal.pow(0.0056998,85.70157)) inexact rounded', 4.716783e-193, 0 + decimal.pow(0.0056998,85.70157));
													AddTestCase('powx3007:p7 r:HALF_EVEN (0 + decimal.pow(0.8169297,3693.537)) inexact rounded', 4.475962e-325, 0 + decimal.pow(0.8169297,3693.537));
													AddTestCase('powx3008:p7 r:HALF_EVEN (0 + decimal.pow(0.2810153,659.9568)) inexact rounded', 1.533177e-364, 0 + decimal.pow(0.2810153,659.9568));
													AddTestCase('powx3009:p7 r:HALF_EVEN (0 + decimal.pow(4.617478,15.68308)) inexact rounded', 2.629748e+10, 0 + decimal.pow(4.617478,15.68308));
													AddTestCase('powx3010:p7 r:HALF_EVEN (0 + decimal.pow(0.0296418,244.2302)) inexact rounded', 6.207949e-374, 0 + decimal.pow(0.0296418,244.2302));
													AddTestCase('powx3011:p7 r:HALF_EVEN (0 + decimal.pow(0.0036456,127.9987)) inexact rounded', 8.120891e-313, 0 + decimal.pow(0.0036456,127.9987));
													AddTestCase('powx3012:p7 r:HALF_EVEN (0 + decimal.pow(0.5012813,577.5418)) inexact rounded', 6.088802e-174, 0 + decimal.pow(0.5012813,577.5418));
													AddTestCase('powx3013:p7 r:HALF_EVEN (0 + decimal.pow(0.0033275,119.9800)) inexact rounded', 5.055049e-298, 0 + decimal.pow(0.0033275,119.9800));
													AddTestCase('powx3014:p7 r:HALF_EVEN (0 + decimal.pow(0.0037652,111.7092)) inexact rounded', 1.560351e-271, 0 + decimal.pow(0.0037652,111.7092));
													AddTestCase('powx3015:p7 r:HALF_EVEN (0 + decimal.pow(0.6463252,239.0568)) inexact rounded', 4.864564e-46, 0 + decimal.pow(0.6463252,239.0568));
													AddTestCase('powx3016:p7 r:HALF_EVEN (0 + decimal.pow(4.784378,475.0521)) inexact rounded', 8.964460e+322, 0 + decimal.pow(4.784378,475.0521));
													AddTestCase('powx3017:p7 r:HALF_EVEN (0 + decimal.pow(4.610305,563.1791)) inexact rounded', 6.290298e+373, 0 + decimal.pow(4.610305,563.1791));
													AddTestCase('powx3018:p7 r:HALF_EVEN (0 + decimal.pow(0.0175167,80.52208)) inexact rounded', 3.623472e-142, 0 + decimal.pow(0.0175167,80.52208));
													AddTestCase('powx3019:p7 r:HALF_EVEN (0 + decimal.pow(5.238307,356.7944)) inexact rounded', 4.011461e+256, 0 + decimal.pow(5.238307,356.7944));
													AddTestCase('powx3020:p7 r:HALF_EVEN (0 + decimal.pow(0.0003527,96.26347)) inexact rounded', 4.377932e-333, 0 + decimal.pow(0.0003527,96.26347));
													AddTestCase('powx3022:p7 r:HALF_EVEN (0 + decimal.pow(5.753573,273.2340)) inexact rounded', 4.373184e+207, 0 + decimal.pow(5.753573,273.2340));
													AddTestCase('powx3023:p7 r:HALF_EVEN (0 + decimal.pow(7.778665,332.7917)) inexact rounded', 3.060640e+296, 0 + decimal.pow(7.778665,332.7917));
													AddTestCase('powx3024:p7 r:HALF_EVEN (0 + decimal.pow(1.432479,2046.064)) inexact rounded', 2.325829e+319, 0 + decimal.pow(1.432479,2046.064));
													AddTestCase('powx3025:p7 r:HALF_EVEN (0 + decimal.pow(5.610516,136.4563)) inexact rounded', 1.607502e+102, 0 + decimal.pow(5.610516,136.4563));
													AddTestCase('powx3026:p7 r:HALF_EVEN (0 + decimal.pow(0.0050697,137.4513)) inexact rounded', 3.522315e-316, 0 + decimal.pow(0.0050697,137.4513));
													AddTestCase('powx3027:p7 r:HALF_EVEN (0 + decimal.pow(5.678737,85.16253)) inexact rounded', 1.713909e+64, 0 + decimal.pow(5.678737,85.16253));
													AddTestCase('powx3028:p7 r:HALF_EVEN (0 + decimal.pow(0.0816167,236.1973)) inexact rounded', 9.228802e-258, 0 + decimal.pow(0.0816167,236.1973));
													AddTestCase('powx3029:p7 r:HALF_EVEN (0 + decimal.pow(0.2602805,562.0157)) inexact rounded', 2.944556e-329, 0 + decimal.pow(0.2602805,562.0157));
													AddTestCase('powx3030:p7 r:HALF_EVEN (0 + decimal.pow(0.0080936,24.25367)) inexact rounded', 1.839755e-51, 0 + decimal.pow(0.0080936,24.25367));
													AddTestCase('powx3031:p7 r:HALF_EVEN (0 + decimal.pow(4.092016,82.94603)) inexact rounded', 5.724948e+50, 0 + decimal.pow(4.092016,82.94603));
													AddTestCase('powx3032:p7 r:HALF_EVEN (0 + decimal.pow(0.0078255,7.204184)) inexact rounded', 6.675342e-16, 0 + decimal.pow(0.0078255,7.204184));
													AddTestCase('powx3033:p7 r:HALF_EVEN (0 + decimal.pow(0.9917693,29846.44)) inexact rounded', 7.430177e-108, 0 + decimal.pow(0.9917693,29846.44));
													AddTestCase('powx3034:p7 r:HALF_EVEN (0 + decimal.pow(1.610380,301.2467)) inexact rounded', 2.170142e+62, 0 + decimal.pow(1.610380,301.2467));
													AddTestCase('powx3035:p7 r:HALF_EVEN (0 + decimal.pow(0.0588236,212.1097)) inexact rounded', 1.023196e-261, 0 + decimal.pow(0.0588236,212.1097));
													AddTestCase('powx3036:p7 r:HALF_EVEN (0 + decimal.pow(2.498069,531.4647)) inexact rounded', 2.054561e+211, 0 + decimal.pow(2.498069,531.4647));
													AddTestCase('powx3037:p7 r:HALF_EVEN (0 + decimal.pow(9.964342,326.5438)) inexact rounded', 1.089452e+326, 0 + decimal.pow(9.964342,326.5438));
													AddTestCase('powx3038:p7 r:HALF_EVEN (0 + decimal.pow(0.0820626,268.8718)) inexact rounded', 1.107350e-292, 0 + decimal.pow(0.0820626,268.8718));
													AddTestCase('powx3039:p7 r:HALF_EVEN (0 + decimal.pow(6.176486,360.7779)) inexact rounded', 1.914449e+285, 0 + decimal.pow(6.176486,360.7779));
													AddTestCase('powx3040:p7 r:HALF_EVEN (0 + decimal.pow(4.206363,16.17288)) inexact rounded', 1.231314e+10, 0 + decimal.pow(4.206363,16.17288));
													// p=34, within 0-999 -- negative arg2
													// p=16, within 0-99 -- negative arg2
												}
												{
													use precision 16;
													AddTestCase('powx3601:p16 r:HALF_EVEN (0 + decimal.pow(0.0000151338748474,-40.84655618364688)) inexact rounded', 7.628470824137755e+196, 0 + decimal.pow(0.0000151338748474,-40.84655618364688));
													AddTestCase('powx3602:p16 r:HALF_EVEN (0 + decimal.pow(0.1542771848654862,-435.8830009466800)) inexact rounded', 6.389817177800744e+353, 0 + decimal.pow(0.1542771848654862,-435.8830009466800));
													AddTestCase('powx3603:p16 r:HALF_EVEN (0 + decimal.pow(48.28477749367364,-218.5929209902050)) inexact rounded', 8.531049532576154e-369, 0 + decimal.pow(48.28477749367364,-218.5929209902050));
													AddTestCase('powx3604:p16 r:HALF_EVEN (0 + decimal.pow(7.960775891584911,-12.78113732182505)) inexact rounded', 3.053270889769488e-12, 0 + decimal.pow(7.960775891584911,-12.78113732182505));
													AddTestCase('powx3605:p16 r:HALF_EVEN (0 + decimal.pow(0.9430340651863058,-9010.470056913748)) inexact rounded', 3.313374654923807e+229, 0 + decimal.pow(0.9430340651863058,-9010.470056913748));
													AddTestCase('powx3606:p16 r:HALF_EVEN (0 + decimal.pow(0.0000202661501602,-65.57915207383306)) inexact rounded', 5.997379176536464e+307, 0 + decimal.pow(0.0000202661501602,-65.57915207383306));
													AddTestCase('powx3607:p16 r:HALF_EVEN (0 + decimal.pow(04.33007440798390,-232.0476834666588)) inexact rounded', 2.007827183010456e-148, 0 + decimal.pow(04.33007440798390,-232.0476834666588));
													AddTestCase('powx3608:p16 r:HALF_EVEN (0 + decimal.pow(0.0000141944643914,-11.32407921958717)) inexact rounded', 7.902934485074846e+54, 0 + decimal.pow(0.0000141944643914,-11.32407921958717));
													AddTestCase('powx3609:p16 r:HALF_EVEN (0 + decimal.pow(0.0000021977758261,-53.53706138253307)) inexact rounded', 8.195631772317815e+302, 0 + decimal.pow(0.0000021977758261,-53.53706138253307));
													AddTestCase('powx3610:p16 r:HALF_EVEN (0 + decimal.pow(39.51297655474188,-19.40370976012326)) inexact rounded', 1.040699608072659e-31, 0 + decimal.pow(39.51297655474188,-19.40370976012326));
													AddTestCase('powx3611:p16 r:HALF_EVEN (0 + decimal.pow(38.71210232488775,-66.58341618227921)) inexact rounded', 1.886855066146495e-106, 0 + decimal.pow(38.71210232488775,-66.58341618227921));
													AddTestCase('powx3612:p16 r:HALF_EVEN (0 + decimal.pow(0.0000804235229062,-6.715207948992859)) inexact rounded', 3.134757864389333e+27, 0 + decimal.pow(0.0000804235229062,-6.715207948992859));
													AddTestCase('powx3613:p16 r:HALF_EVEN (0 + decimal.pow(0.0000073547092399,-11.27725685719934)) inexact rounded', 7.781428390953695e+57, 0 + decimal.pow(0.0000073547092399,-11.27725685719934));
													AddTestCase('powx3614:p16 r:HALF_EVEN (0 + decimal.pow(52.72181272599316,-186.1422311607435)) inexact rounded', 2.916601998744177e-321, 0 + decimal.pow(52.72181272599316,-186.1422311607435));
													AddTestCase('powx3615:p16 r:HALF_EVEN (0 + decimal.pow(0.0969519963083306,-280.8220862151369)) inexact rounded', 3.955906885970987e+284, 0 + decimal.pow(0.0969519963083306,-280.8220862151369));
													AddTestCase('powx3616:p16 r:HALF_EVEN (0 + decimal.pow(94.07263302150081,-148.2031146071230)) inexact rounded', 3.361958990752490e-293, 0 + decimal.pow(94.07263302150081,-148.2031146071230));
													AddTestCase('powx3617:p16 r:HALF_EVEN (0 + decimal.pow(85.80286965053704,-90.21453695813759)) inexact rounded', 3.715602429645798e-175, 0 + decimal.pow(85.80286965053704,-90.21453695813759));
													AddTestCase('powx3618:p16 r:HALF_EVEN (0 + decimal.pow(03.52699858152259,-492.0414362539196)) inexact rounded', 4.507309220081092e-270, 0 + decimal.pow(03.52699858152259,-492.0414362539196));
													AddTestCase('powx3619:p16 r:HALF_EVEN (0 + decimal.pow(0.0508278086396068,-181.0871731572167)) inexact rounded', 2.034428013017949e+234, 0 + decimal.pow(0.0508278086396068,-181.0871731572167));
													AddTestCase('powx3620:p16 r:HALF_EVEN (0 + decimal.pow(0.395576740303172,-915.5524507432392)) inexact rounded', 5.706585187437578e+368, 0 + decimal.pow(0.395576740303172,-915.5524507432392));
													AddTestCase('powx3621:p16 r:HALF_EVEN (0 + decimal.pow(38.06105826789202,-49.75913753435335)) inexact rounded', 2.273188991431738e-79, 0 + decimal.pow(38.06105826789202,-49.75913753435335));
													AddTestCase('powx3622:p16 r:HALF_EVEN (0 + decimal.pow(0.0003656748910646,-73.28988491310354)) inexact rounded', 7.768936940568763e+251, 0 + decimal.pow(0.0003656748910646,-73.28988491310354));
													AddTestCase('powx3623:p16 r:HALF_EVEN (0 + decimal.pow(0.0000006373551809,-51.30825234200690)) inexact rounded', 7.697618167701985e+317, 0 + decimal.pow(0.0000006373551809,-51.30825234200690));
													AddTestCase('powx3624:p16 r:HALF_EVEN (0 + decimal.pow(82.41729920673856,-35.73319631625699)) inexact rounded', 3.424042354585529e-69, 0 + decimal.pow(82.41729920673856,-35.73319631625699));
													AddTestCase('powx3625:p16 r:HALF_EVEN (0 + decimal.pow(0.7845821453127670,-971.4982028897663)) inexact rounded', 2.283415527661089e+102, 0 + decimal.pow(0.7845821453127670,-971.4982028897663));
													AddTestCase('powx3626:p16 r:HALF_EVEN (0 + decimal.pow(4.840983673433497,-182.3730452370515)) inexact rounded', 1.220591407927770e-125, 0 + decimal.pow(4.840983673433497,-182.3730452370515));
													AddTestCase('powx3627:p16 r:HALF_EVEN (0 + decimal.pow(0.0000006137592139,-2.122139474431484)) inexact rounded', 15231217034839.29, 0 + decimal.pow(0.0000006137592139,-2.122139474431484));
													AddTestCase('powx3628:p16 r:HALF_EVEN (0 + decimal.pow(0.0003657962862984,-35.97993782448099)) inexact rounded', 4.512701319250839e+123, 0 + decimal.pow(0.0003657962862984,-35.97993782448099));
													AddTestCase('powx3629:p16 r:HALF_EVEN (0 + decimal.pow(40.93693004443150,-165.1362408792997)) inexact rounded', 6.044276411057239e-267, 0 + decimal.pow(40.93693004443150,-165.1362408792997));
													AddTestCase('powx3630:p16 r:HALF_EVEN (0 + decimal.pow(0.2941552583028898,-17.41046264945892)) inexact rounded', 1787833103.503346, 0 + decimal.pow(0.2941552583028898,-17.41046264945892));
													AddTestCase('powx3631:p16 r:HALF_EVEN (0 + decimal.pow(63.99335135369977,-69.92417205168579)) inexact rounded', 5.099359804872509e-127, 0 + decimal.pow(63.99335135369977,-69.92417205168579));
													AddTestCase('powx3632:p16 r:HALF_EVEN (0 + decimal.pow(0.0000657924467388,-89.14497293588313)) inexact rounded', 6.145878266688521e+372, 0 + decimal.pow(0.0000657924467388,-89.14497293588313));
													AddTestCase('powx3633:p16 r:HALF_EVEN (0 + decimal.pow(11.35071250339147,-323.3705865614542)) inexact rounded', 6.863626248766775e-342, 0 + decimal.pow(11.35071250339147,-323.3705865614542));
													AddTestCase('powx3634:p16 r:HALF_EVEN (0 + decimal.pow(23.88024718470895,-277.7117513329510)) inexact rounded', 2.006441422612815e-383, 0 + decimal.pow(23.88024718470895,-277.7117513329510));
													AddTestCase('powx3635:p16 r:HALF_EVEN (0 + decimal.pow(0.0000009111939914,-58.51782946929182)) inexact rounded', 2.954352883996773e+353, 0 + decimal.pow(0.0000009111939914,-58.51782946929182));
													AddTestCase('powx3636:p16 r:HALF_EVEN (0 + decimal.pow(0.0000878179048782,-75.81060420238669)) inexact rounded', 3.306878455207585e+307, 0 + decimal.pow(0.0000878179048782,-75.81060420238669));
													AddTestCase('powx3637:p16 r:HALF_EVEN (0 + decimal.pow(07.39190564273779,-287.5047307244636)) inexact rounded', 1.692080354659805e-250, 0 + decimal.pow(07.39190564273779,-287.5047307244636));
													AddTestCase('powx3638:p16 r:HALF_EVEN (0 + decimal.pow(0.0000298310819799,-1.844740377759355)) inexact rounded', 222874718.7238888, 0 + decimal.pow(0.0000298310819799,-1.844740377759355));
													AddTestCase('powx3639:p16 r:HALF_EVEN (0 + decimal.pow(0.0000006412929384,-28.24850078229290)) inexact rounded', 8.737164230666529e+174, 0 + decimal.pow(0.0000006412929384,-28.24850078229290));
													AddTestCase('powx3640:p16 r:HALF_EVEN (0 + decimal.pow(0.0000010202965998,-47.17573701956498)) inexact rounded', 4.392845306049341e+282, 0 + decimal.pow(0.0000010202965998,-47.17573701956498));
													// p=7, within 0-9 -- negative arg2
												}
												{
													use precision 7;
													AddTestCase('powx3501:p7 r:HALF_EVEN (0 + decimal.pow(0.326324,-71.96509)) inexact rounded', 1.000673e+35, 0 + decimal.pow(0.326324,-71.96509));
													AddTestCase('powx3502:p7 r:HALF_EVEN (0 + decimal.pow(0.0017635,-0.7186967)) inexact rounded', 95.28419, 0 + decimal.pow(0.0017635,-0.7186967));
													AddTestCase('powx3503:p7 r:HALF_EVEN (0 + decimal.pow(8.564155,-253.0899)) inexact rounded', 8.850512e-237, 0 + decimal.pow(8.564155,-253.0899));
													AddTestCase('powx3504:p7 r:HALF_EVEN (0 + decimal.pow(8.987272,-2.155789)) inexact rounded', 0.008793859, 0 + decimal.pow(8.987272,-2.155789));
													AddTestCase('powx3505:p7 r:HALF_EVEN (0 + decimal.pow(9.604856,-139.9630)) inexact rounded', 3.073492e-138, 0 + decimal.pow(9.604856,-139.9630));
													AddTestCase('powx3506:p7 r:HALF_EVEN (0 + decimal.pow(0.8472919,-2539.085)) inexact rounded', 5.372686e+182, 0 + decimal.pow(0.8472919,-2539.085));
													AddTestCase('powx3507:p7 r:HALF_EVEN (0 + decimal.pow(5.312329,-60.32965)) inexact rounded', 1.753121e-44, 0 + decimal.pow(5.312329,-60.32965));
													AddTestCase('powx3508:p7 r:HALF_EVEN (0 + decimal.pow(0.0338294,-100.5440)) inexact rounded', 7.423939e+147, 0 + decimal.pow(0.0338294,-100.5440));
													AddTestCase('powx3509:p7 r:HALF_EVEN (0 + decimal.pow(0.0017777,-130.8583)) inexact rounded', 7.565629e+359, 0 + decimal.pow(0.0017777,-130.8583));
													AddTestCase('powx3510:p7 r:HALF_EVEN (0 + decimal.pow(8.016154,-405.5689)) inexact rounded', 2.395977e-367, 0 + decimal.pow(8.016154,-405.5689));
													AddTestCase('powx3511:p7 r:HALF_EVEN (0 + decimal.pow(5.016570,-327.8906)) inexact rounded', 2.203784e-230, 0 + decimal.pow(5.016570,-327.8906));
													AddTestCase('powx3512:p7 r:HALF_EVEN (0 + decimal.pow(0.8161743,-744.5276)) inexact rounded', 4.786899e+65, 0 + decimal.pow(0.8161743,-744.5276));
													AddTestCase('powx3513:p7 r:HALF_EVEN (0 + decimal.pow(0.0666343,-164.7320)) inexact rounded', 5.951240e+193, 0 + decimal.pow(0.0666343,-164.7320));
													AddTestCase('powx3514:p7 r:HALF_EVEN (0 + decimal.pow(0.0803966,-202.2666)) inexact rounded', 2.715512e+221, 0 + decimal.pow(0.0803966,-202.2666));
													AddTestCase('powx3515:p7 r:HALF_EVEN (0 + decimal.pow(0.0014752,-12.55547)) inexact rounded', 3.518905e+35, 0 + decimal.pow(0.0014752,-12.55547));
													AddTestCase('powx3516:p7 r:HALF_EVEN (0 + decimal.pow(9.737565,-14.69615)) inexact rounded', 2.975672e-15, 0 + decimal.pow(9.737565,-14.69615));
													AddTestCase('powx3517:p7 r:HALF_EVEN (0 + decimal.pow(0.6634172,-152.7308)) inexact rounded', 1.654458e+27, 0 + decimal.pow(0.6634172,-152.7308));
													AddTestCase('powx3518:p7 r:HALF_EVEN (0 + decimal.pow(0.0009337,-33.32939)) inexact rounded', 9.575039e+100, 0 + decimal.pow(0.0009337,-33.32939));
													AddTestCase('powx3519:p7 r:HALF_EVEN (0 + decimal.pow(8.679922,-224.4194)) inexact rounded', 2.392446e-211, 0 + decimal.pow(8.679922,-224.4194));
													AddTestCase('powx3520:p7 r:HALF_EVEN (0 + decimal.pow(7.390494,-161.9483)) inexact rounded', 2.088375e-141, 0 + decimal.pow(7.390494,-161.9483));
													AddTestCase('powx3521:p7 r:HALF_EVEN (0 + decimal.pow(0.4631489,-417.1673)) inexact rounded', 2.821106e+139, 0 + decimal.pow(0.4631489,-417.1673));
													AddTestCase('powx3522:p7 r:HALF_EVEN (0 + decimal.pow(0.0095471,-7.677458)) inexact rounded', 3.231855e+15, 0 + decimal.pow(0.0095471,-7.677458));
													AddTestCase('powx3523:p7 r:HALF_EVEN (0 + decimal.pow(6.566339,-176.1867)) inexact rounded', 9.965633e-145, 0 + decimal.pow(6.566339,-176.1867));
													AddTestCase('powx3524:p7 r:HALF_EVEN (0 + decimal.pow(2.696128,-26.15501)) inexact rounded', 5.419731e-12, 0 + decimal.pow(2.696128,-26.15501));
													AddTestCase('powx3525:p7 r:HALF_EVEN (0 + decimal.pow(0.4464366,-852.1893)) inexact rounded', 2.957725e+298, 0 + decimal.pow(0.4464366,-852.1893));
													AddTestCase('powx3526:p7 r:HALF_EVEN (0 + decimal.pow(0.4772006,-921.4111)) inexact rounded', 1.118105e+296, 0 + decimal.pow(0.4772006,-921.4111));
													AddTestCase('powx3527:p7 r:HALF_EVEN (0 + decimal.pow(8.923696,-359.2211)) inexact rounded', 3.501573e-342, 0 + decimal.pow(8.923696,-359.2211));
													AddTestCase('powx3528:p7 r:HALF_EVEN (0 + decimal.pow(0.0018008,-66.91252)) inexact rounded', 4.402718e+183, 0 + decimal.pow(0.0018008,-66.91252));
													AddTestCase('powx3529:p7 r:HALF_EVEN (0 + decimal.pow(0.0811964,-92.83278)) inexact rounded', 1.701111e+101, 0 + decimal.pow(0.0811964,-92.83278));
													AddTestCase('powx3530:p7 r:HALF_EVEN (0 + decimal.pow(0.0711219,-58.94347)) inexact rounded', 4.644148e+67, 0 + decimal.pow(0.0711219,-58.94347));
													AddTestCase('powx3531:p7 r:HALF_EVEN (0 + decimal.pow(7.958121,-50.66123)) inexact rounded', 2.311161e-46, 0 + decimal.pow(7.958121,-50.66123));
													AddTestCase('powx3532:p7 r:HALF_EVEN (0 + decimal.pow(6.106466,-81.83610)) inexact rounded', 4.943285e-65, 0 + decimal.pow(6.106466,-81.83610));
													AddTestCase('powx3533:p7 r:HALF_EVEN (0 + decimal.pow(4.557634,-129.5268)) inexact rounded', 4.737917e-86, 0 + decimal.pow(4.557634,-129.5268));
													AddTestCase('powx3534:p7 r:HALF_EVEN (0 + decimal.pow(0.0027348,-9.180135)) inexact rounded', 3.383524e+23, 0 + decimal.pow(0.0027348,-9.180135));
													AddTestCase('powx3535:p7 r:HALF_EVEN (0 + decimal.pow(0.0083924,-46.24016)) inexact rounded', 9.996212e+95, 0 + decimal.pow(0.0083924,-46.24016));
													AddTestCase('powx3536:p7 r:HALF_EVEN (0 + decimal.pow(2.138523,-47.25897)) inexact rounded', 2.507009e-16, 0 + decimal.pow(2.138523,-47.25897));
													AddTestCase('powx3537:p7 r:HALF_EVEN (0 + decimal.pow(1.626728,-1573.830)) inexact rounded', 2.668117e-333, 0 + decimal.pow(1.626728,-1573.830));
													AddTestCase('powx3538:p7 r:HALF_EVEN (0 + decimal.pow(0.082615,-164.5842)) inexact rounded', 1.717882e+178, 0 + decimal.pow(0.082615,-164.5842));
													AddTestCase('powx3539:p7 r:HALF_EVEN (0 + decimal.pow(7.636003,-363.6763)) inexact rounded', 8.366174e-322, 0 + decimal.pow(7.636003,-363.6763));
													AddTestCase('powx3540:p7 r:HALF_EVEN (0 + decimal.pow(0.0021481,-138.0065)) inexact rounded', 1.562505e+368, 0 + decimal.pow(0.0021481,-138.0065));
													// invalid operations due to restrictions
													// [next two probably skipped by most test harnesses]
												}
												{
													use precision 9;
													AddTestCase('powx4003:p9 r:HALF_EVEN (0 + decimal.pow(1,1.1)) invalid_context', 1, 0 + decimal.pow(1,1.1));
													AddTestCase('powx4004:p9 r:HALF_EVEN (0 + decimal.pow(1,1.1)) inexact rounded', 1.00000000, 0 + decimal.pow(1,1.1));
													AddTestCase('powx4005:p9 r:HALF_EVEN (0 + decimal.pow(1,1.1)) invalid_context', 1, 0 + decimal.pow(1,1.1));
													AddTestCase('powx4006:p9 r:HALF_EVEN (0 + decimal.pow(1,1.1)) inexact rounded', 1.00000000, 0 + decimal.pow(1,1.1));
													// operand range violations
													AddTestCase('powx4007:p9 r:HALF_EVEN (0 + decimal.pow(1,1.1e+999999))', 1, 0 + decimal.pow(1,1.1e+999999));
													AddTestCase('powx4008:p9 r:HALF_EVEN (0 + decimal.pow(1,1.1e+1000000)) invalid_operation', 1, 0 + decimal.pow(1,1.1e+1000000));
													AddTestCase('powx4010:p9 r:HALF_EVEN (0 + decimal.pow(1.1e+1000000,1.1)) invalid_operation', Infinity, 0 + decimal.pow(1.1e+1000000,1.1));
													AddTestCase('powx4011:p9 r:HALF_EVEN (0 + decimal.pow(1,1.1e-1999997)) inexact rounded', 1.00000000, 0 + decimal.pow(1,1.1e-1999997));
													AddTestCase('powx4012:p9 r:HALF_EVEN (0 + decimal.pow(1,1.1e-1999998)) invalid_operation', 1, 0 + decimal.pow(1,1.1e-1999998));
													AddTestCase('powx4014:p9 r:HALF_EVEN (0 + decimal.pow(1.1e-1999998,1.1)) invalid_operation', 0, 0 + decimal.pow(1.1e-1999998,1.1));
													// rounding modes -- power is sensitive
												}
												{
													use precision 7;
													//   0.7  ** 3.3 =>   0.30819354053418943822
													//   0.7  ** 3.4 =>   0.29739477638272533854
													//  -1.2  ** 17  => -22.18611106740436992
													//  -1.3  ** 17  => -86.50415919381337933
													//   0.5  ** 11  =>   0.00048828125
													//   3.15 ** 3   =>  31.255875
													{
														use rounding FLOOR;
														AddTestCase('powx4140:p7 r:FLOOR (0 + decimal.pow(0.7,3.3)) inexact rounded', 0.3081935, 0 + decimal.pow(0.7,3.3));
														AddTestCase('powx4141:p7 r:FLOOR (0 + decimal.pow(0.7,3.4)) inexact rounded', 0.2973947, 0 + decimal.pow(0.7,3.4));
														AddTestCase('powx4142:p7 r:FLOOR (0 + decimal.pow(-1.2,17)) inexact rounded', -22.18612, 0 + decimal.pow(-1.2,17));
														AddTestCase('powx4143:p7 r:FLOOR (0 + decimal.pow(-1.3,17)) inexact rounded', -86.50416, 0 + decimal.pow(-1.3,17));
														AddTestCase('powx4144:p7 r:FLOOR (0 + decimal.pow(17,81.27115)) inexact rounded', 9.999973e+99, 0 + decimal.pow(17,81.27115));
													}
													{
														use rounding CEILING;
														AddTestCase('powx4160:p7 r:CEILING (0 + decimal.pow(0.7,3.3)) inexact rounded', 0.3081936, 0 + decimal.pow(0.7,3.3));
														AddTestCase('powx4161:p7 r:CEILING (0 + decimal.pow(0.7,3.4)) inexact rounded', 0.2973948, 0 + decimal.pow(0.7,3.4));
														AddTestCase('powx4162:p7 r:CEILING (0 + decimal.pow(-1.2,17)) inexact rounded', -22.18611, 0 + decimal.pow(-1.2,17));
														AddTestCase('powx4163:p7 r:CEILING (0 + decimal.pow(-1.3,17)) inexact rounded', -86.50415, 0 + decimal.pow(-1.3,17));
														AddTestCase('powx4164:p7 r:CEILING (0 + decimal.pow(17,81.27115)) inexact rounded', 9.999974e+99, 0 + decimal.pow(17,81.27115));
													}
													{
														use rounding HALF_UP;
														AddTestCase('powx4180:p7 r:HALF_UP (0 + decimal.pow(0.7,3.3)) inexact rounded', 0.3081935, 0 + decimal.pow(0.7,3.3));
														AddTestCase('powx4181:p7 r:HALF_UP (0 + decimal.pow(0.7,3.4)) inexact rounded', 0.2973948, 0 + decimal.pow(0.7,3.4));
														AddTestCase('powx4182:p7 r:HALF_UP (0 + decimal.pow(-1.2,17)) inexact rounded', -22.18611, 0 + decimal.pow(-1.2,17));
														AddTestCase('powx4183:p7 r:HALF_UP (0 + decimal.pow(-1.3,17)) inexact rounded', -86.50416, 0 + decimal.pow(-1.3,17));
														AddTestCase('powx4184:p7 r:HALF_UP (0 + decimal.pow(0.5,11)) inexact rounded', 0.0004882813, 0 + decimal.pow(0.5,11));
														AddTestCase('powx4185:p7 r:HALF_UP (0 + decimal.pow(3.15,3)) inexact rounded', 31.25588, 0 + decimal.pow(3.15,3));
														AddTestCase('powx4186:p7 r:HALF_UP (0 + decimal.pow(17,81.27115)) inexact rounded', 9.999974e+99, 0 + decimal.pow(17,81.27115));
													}
													{
														use rounding HALF_EVEN;
														AddTestCase('powx4200:p7 r:HALF_EVEN (0 + decimal.pow(0.7,3.3)) inexact rounded', 0.3081935, 0 + decimal.pow(0.7,3.3));
														AddTestCase('powx4201:p7 r:HALF_EVEN (0 + decimal.pow(0.7,3.4)) inexact rounded', 0.2973948, 0 + decimal.pow(0.7,3.4));
														AddTestCase('powx4202:p7 r:HALF_EVEN (0 + decimal.pow(-1.2,17)) inexact rounded', -22.18611, 0 + decimal.pow(-1.2,17));
														AddTestCase('powx4203:p7 r:HALF_EVEN (0 + decimal.pow(-1.3,17)) inexact rounded', -86.50416, 0 + decimal.pow(-1.3,17));
														AddTestCase('powx4204:p7 r:HALF_EVEN (0 + decimal.pow(0.5,11)) inexact rounded', 0.0004882812, 0 + decimal.pow(0.5,11));
														AddTestCase('powx4205:p7 r:HALF_EVEN (0 + decimal.pow(3.15,3)) inexact rounded', 31.25588, 0 + decimal.pow(3.15,3));
														AddTestCase('powx4206:p7 r:HALF_EVEN (0 + decimal.pow(17,81.27115)) inexact rounded', 9.999974e+99, 0 + decimal.pow(17,81.27115));
													}
													{
														use rounding HALF_DOWN;
														AddTestCase('powx4220:p7 r:HALF_DOWN (0 + decimal.pow(0.7,3.3)) inexact rounded', 0.3081935, 0 + decimal.pow(0.7,3.3));
														AddTestCase('powx4221:p7 r:HALF_DOWN (0 + decimal.pow(0.7,3.4)) inexact rounded', 0.2973948, 0 + decimal.pow(0.7,3.4));
														AddTestCase('powx4222:p7 r:HALF_DOWN (0 + decimal.pow(-1.2,17)) inexact rounded', -22.18611, 0 + decimal.pow(-1.2,17));
														AddTestCase('powx4223:p7 r:HALF_DOWN (0 + decimal.pow(-1.3,17)) inexact rounded', -86.50416, 0 + decimal.pow(-1.3,17));
														AddTestCase('powx4224:p7 r:HALF_DOWN (0 + decimal.pow(0.5,11)) inexact rounded', 0.0004882812, 0 + decimal.pow(0.5,11));
														AddTestCase('powx4225:p7 r:HALF_DOWN (0 + decimal.pow(3.15,3)) inexact rounded', 31.25587, 0 + decimal.pow(3.15,3));
														AddTestCase('powx4226:p7 r:HALF_DOWN (0 + decimal.pow(-3.15,3)) inexact rounded', -31.25587, 0 + decimal.pow(-3.15,3));
														AddTestCase('powx4227:p7 r:HALF_DOWN (0 + decimal.pow(17,81.27115)) inexact rounded', 9.999974e+99, 0 + decimal.pow(17,81.27115));
														// more rounding tests as per ilan nehama's suggestions & analysis
														// these are likely to show > 0.5 ulp error for very small powers
														{
															use precision 7;
															// for x=nextfp(1)=1.00..001 (where the number of 0s is precision-2)
															//   power(x,y)=x when the rounding is up (e.g., toward_pos_inf or
															//   ceil) for any y in (0,1].
															{
																use rounding CEILING;
																AddTestCase('powx4301:p7 r:CEILING (0 + decimal.pow(1.000001,0))', 1, 0 + decimal.pow(1.000001,0));
																// the next test should be skipped for decnumber
																AddTestCase('powx4304:p7 r:CEILING (0 + decimal.pow(1.000001,1e-10)) inexact rounded', 1.000001, 0 + decimal.pow(1.000001,1e-10));
																AddTestCase('powx4305:p7 r:CEILING (0 + decimal.pow(1.000001,0.1)) inexact rounded', 1.000001, 0 + decimal.pow(1.000001,0.1));
																AddTestCase('powx4306:p7 r:CEILING (0 + decimal.pow(1.000001,0.1234567)) inexact rounded', 1.000001, 0 + decimal.pow(1.000001,0.1234567));
																AddTestCase('powx4307:p7 r:CEILING (0 + decimal.pow(1.000001,0.7)) inexact rounded', 1.000001, 0 + decimal.pow(1.000001,0.7));
																AddTestCase('powx4308:p7 r:CEILING (0 + decimal.pow(1.000001,0.9999999)) inexact rounded', 1.000001, 0 + decimal.pow(1.000001,0.9999999));
																AddTestCase('powx4309:p7 r:CEILING (0 + decimal.pow(1.000001,1.000000))', 1.000001, 0 + decimal.pow(1.000001,1.000000));
																//   power(x,y)=1 when the rounding is down (e.g. toward_zero or
																//   floor) for any y in [0,1).
															}
															{
																use rounding FLOOR;
																AddTestCase('powx4321:p7 r:FLOOR (0 + decimal.pow(1.000001,0))', 1, 0 + decimal.pow(1.000001,0));
																AddTestCase('powx4322:p7 r:FLOOR (0 + decimal.pow(1.000001,1e-101)) inexact rounded', 1.000000, 0 + decimal.pow(1.000001,1e-101));
																AddTestCase('powx4323:p7 r:FLOOR (0 + decimal.pow(1.000001,1e-95)) inexact rounded', 1.000000, 0 + decimal.pow(1.000001,1e-95));
																AddTestCase('powx4324:p7 r:FLOOR (0 + decimal.pow(1.000001,1e-10)) inexact rounded', 1.000000, 0 + decimal.pow(1.000001,1e-10));
																AddTestCase('powx4325:p7 r:FLOOR (0 + decimal.pow(1.000001,0.1)) inexact rounded', 1.000000, 0 + decimal.pow(1.000001,0.1));
																AddTestCase('powx4326:p7 r:FLOOR (0 + decimal.pow(1.000001,0.1234567)) inexact rounded', 1.000000, 0 + decimal.pow(1.000001,0.1234567));
																AddTestCase('powx4327:p7 r:FLOOR (0 + decimal.pow(1.000001,0.7)) inexact rounded', 1.000000, 0 + decimal.pow(1.000001,0.7));
																AddTestCase('powx4328:p7 r:FLOOR (0 + decimal.pow(1.000001,0.9999999)) inexact rounded', 1.000000, 0 + decimal.pow(1.000001,0.9999999));
																AddTestCase('powx4329:p7 r:FLOOR (0 + decimal.pow(1.000001,1.000000))', 1.000001, 0 + decimal.pow(1.000001,1.000000));
																// for x=prevfp(1)=0.99..99 (where the number of 9s is precision)
																//   power(x,y)=x when the rounding is down for any y in (0,1].
															}
															{
																use rounding FLOOR;
																AddTestCase('powx4341:p7 r:FLOOR (0 + decimal.pow(0.9999999,0))', 1, 0 + decimal.pow(0.9999999,0));
																// the next test should be skipped for decnumber
																AddTestCase('powx4344:p7 r:FLOOR (0 + decimal.pow(0.9999999,1e-10)) inexact rounded', 0.9999999, 0 + decimal.pow(0.9999999,1e-10));
																AddTestCase('powx4345:p7 r:FLOOR (0 + decimal.pow(0.9999999,0.1)) inexact rounded', 0.9999999, 0 + decimal.pow(0.9999999,0.1));
																AddTestCase('powx4346:p7 r:FLOOR (0 + decimal.pow(0.9999999,0.1234567)) inexact rounded', 0.9999999, 0 + decimal.pow(0.9999999,0.1234567));
																AddTestCase('powx4347:p7 r:FLOOR (0 + decimal.pow(0.9999999,0.7)) inexact rounded', 0.9999999, 0 + decimal.pow(0.9999999,0.7));
																AddTestCase('powx4348:p7 r:FLOOR (0 + decimal.pow(0.9999999,0.9999999)) inexact rounded', 0.9999999, 0 + decimal.pow(0.9999999,0.9999999));
																AddTestCase('powx4349:p7 r:FLOOR (0 + decimal.pow(0.9999999,1.000000))', 0.9999999, 0 + decimal.pow(0.9999999,1.000000));
																//   power(x,y)=1 when the rounding is up for any y in (0,1].
															}
															{
																use rounding CEILING;
																AddTestCase('powx4361:p7 r:CEILING (0 + decimal.pow(0.9999999,0))', 1, 0 + decimal.pow(0.9999999,0));
																AddTestCase('powx4362:p7 r:CEILING (0 + decimal.pow(0.9999999,1e-101)) inexact rounded', 1.000000, 0 + decimal.pow(0.9999999,1e-101));
																AddTestCase('powx4363:p7 r:CEILING (0 + decimal.pow(0.9999999,1e-95)) inexact rounded', 1.000000, 0 + decimal.pow(0.9999999,1e-95));
																AddTestCase('powx4364:p7 r:CEILING (0 + decimal.pow(0.9999999,1e-10)) inexact rounded', 1.000000, 0 + decimal.pow(0.9999999,1e-10));
																AddTestCase('powx4365:p7 r:CEILING (0 + decimal.pow(0.9999999,0.1)) inexact rounded', 1.000000, 0 + decimal.pow(0.9999999,0.1));
																AddTestCase('powx4366:p7 r:CEILING (0 + decimal.pow(0.9999999,0.1234567)) inexact rounded', 1.000000, 0 + decimal.pow(0.9999999,0.1234567));
																AddTestCase('powx4367:p7 r:CEILING (0 + decimal.pow(0.9999999,0.7)) inexact rounded', 1.000000, 0 + decimal.pow(0.9999999,0.7));
																AddTestCase('powx4368:p7 r:CEILING (0 + decimal.pow(0.9999999,0.9999999)) inexact rounded', 1.000000, 0 + decimal.pow(0.9999999,0.9999999));
																AddTestCase('powx4369:p7 r:CEILING (0 + decimal.pow(0.9999999,1.000000))', 0.9999999, 0 + decimal.pow(0.9999999,1.000000));
																// for x=nextfp(0)
																//   power(x,y)=0 when the rounding is down for any y larger than 1.
															}
															{
																use rounding FLOOR;
																AddTestCase('powx4382:p7 r:FLOOR (0 + decimal.pow(1e-101,0))', 1, 0 + decimal.pow(1e-101,0));
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
test();
