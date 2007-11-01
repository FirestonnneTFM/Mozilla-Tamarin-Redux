use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "exp.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// exp.dectest -- decimal natural exponentiation                      --
// copyright (c) ibm corporation, 2005, 2007.  all rights reserved.   --
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
// tests of the exponential funtion.  currently all testcases here
// show results which are correctly rounded (within <= 0.5 ulp).
use precision 9;
use rounding HALF_EVEN;
// basics (examples in specificiation, etc.)
AddTestCase('expx001:p9 r:HALF_EVEN (0 + decimal.exp(decimal.NEGATIVE_INFINITY))', 0, 0 + decimal.exp(decimal.NEGATIVE_INFINITY));
AddTestCase('expx002:p9 r:HALF_EVEN (0 + decimal.exp(-10)) inexact rounded', 0.0000453999298, 0 + decimal.exp(-10));
AddTestCase('expx003:p9 r:HALF_EVEN (0 + decimal.exp(-1)) inexact rounded', 0.367879441, 0 + decimal.exp(-1));
AddTestCase('expx004:p9 r:HALF_EVEN (0 + decimal.exp(0))', 1, 0 + decimal.exp(0));
AddTestCase('expx005:p9 r:HALF_EVEN (0 + decimal.exp(-0))', 1, 0 + decimal.exp(-0));
AddTestCase('expx006:p9 r:HALF_EVEN (0 + decimal.exp(1)) inexact rounded', 2.71828183, 0 + decimal.exp(1));
AddTestCase('expx007:p9 r:HALF_EVEN (0 + decimal.exp(0.693147181)) inexact rounded', 2.00000000, 0 + decimal.exp(0.693147181));
AddTestCase('expx008:p9 r:HALF_EVEN (0 + decimal.exp(10)) inexact rounded', 22026.4658, 0 + decimal.exp(10));
AddTestCase('expx009:p9 r:HALF_EVEN (0 + decimal.exp(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.exp(decimal.POSITIVE_INFINITY));
// tiny edge cases
{
	use precision 7;
	AddTestCase('expx011:p7 r:HALF_EVEN (0 + decimal.exp(0.1)) inexact rounded', 1.105171, 0 + decimal.exp(0.1));
	AddTestCase('expx012:p7 r:HALF_EVEN (0 + decimal.exp(0.01)) inexact rounded', 1.010050, 0 + decimal.exp(0.01));
	AddTestCase('expx013:p7 r:HALF_EVEN (0 + decimal.exp(0.001)) inexact rounded', 1.001001, 0 + decimal.exp(0.001));
	AddTestCase('expx014:p7 r:HALF_EVEN (0 + decimal.exp(0.0001)) inexact rounded', 1.000100, 0 + decimal.exp(0.0001));
	AddTestCase('expx015:p7 r:HALF_EVEN (0 + decimal.exp(0.00001)) inexact rounded', 1.000010, 0 + decimal.exp(0.00001));
	AddTestCase('expx016:p7 r:HALF_EVEN (0 + decimal.exp(0.000001)) inexact rounded', 1.000001, 0 + decimal.exp(0.000001));
	AddTestCase('expx017:p7 r:HALF_EVEN (0 + decimal.exp(0.0000001)) inexact rounded', 1.000000, 0 + decimal.exp(0.0000001));
	AddTestCase('expx018:p7 r:HALF_EVEN (0 + decimal.exp(0.0000003)) inexact rounded', 1.000000, 0 + decimal.exp(0.0000003));
	AddTestCase('expx019:p7 r:HALF_EVEN (0 + decimal.exp(0.0000004)) inexact rounded', 1.000000, 0 + decimal.exp(0.0000004));
	AddTestCase('expx020:p7 r:HALF_EVEN (0 + decimal.exp(0.0000005)) inexact rounded', 1.000001, 0 + decimal.exp(0.0000005));
	AddTestCase('expx021:p7 r:HALF_EVEN (0 + decimal.exp(0.0000008)) inexact rounded', 1.000001, 0 + decimal.exp(0.0000008));
	AddTestCase('expx022:p7 r:HALF_EVEN (0 + decimal.exp(0.0000009)) inexact rounded', 1.000001, 0 + decimal.exp(0.0000009));
	AddTestCase('expx023:p7 r:HALF_EVEN (0 + decimal.exp(0.0000010)) inexact rounded', 1.000001, 0 + decimal.exp(0.0000010));
	AddTestCase('expx024:p7 r:HALF_EVEN (0 + decimal.exp(0.0000011)) inexact rounded', 1.000001, 0 + decimal.exp(0.0000011));
	AddTestCase('expx025:p7 r:HALF_EVEN (0 + decimal.exp(0.00000009)) inexact rounded', 1.000000, 0 + decimal.exp(0.00000009));
	AddTestCase('expx026:p7 r:HALF_EVEN (0 + decimal.exp(0.00000005)) inexact rounded', 1.000000, 0 + decimal.exp(0.00000005));
	AddTestCase('expx027:p7 r:HALF_EVEN (0 + decimal.exp(0.00000004)) inexact rounded', 1.000000, 0 + decimal.exp(0.00000004));
	AddTestCase('expx028:p7 r:HALF_EVEN (0 + decimal.exp(0.00000001)) inexact rounded', 1.000000, 0 + decimal.exp(0.00000001));
	// and some more zeros
	AddTestCase('expx030:p7 r:HALF_EVEN (0 + decimal.exp(0.00000000))', 1, 0 + decimal.exp(0.00000000));
	AddTestCase('expx031:p7 r:HALF_EVEN (0 + decimal.exp(0e+100))', 1, 0 + decimal.exp(0e+100));
	AddTestCase('expx032:p7 r:HALF_EVEN (0 + decimal.exp(0e-100))', 1, 0 + decimal.exp(0e-100));
	AddTestCase('expx033:p7 r:HALF_EVEN (0 + decimal.exp(-0.00000000))', 1, 0 + decimal.exp(-0.00000000));
	AddTestCase('expx034:p7 r:HALF_EVEN (0 + decimal.exp(-0e+100))', 1, 0 + decimal.exp(-0e+100));
	AddTestCase('expx035:p7 r:HALF_EVEN (0 + decimal.exp(-0e-100))', 1, 0 + decimal.exp(-0e-100));
	// basic e=0, e=1, e=2, e=4, e>=8 cases
}
{
	use precision 7;
	AddTestCase('expx041:p7 r:HALF_EVEN (0 + decimal.exp(1)) inexact rounded', 2.718282, 0 + decimal.exp(1));
	AddTestCase('expx042:p7 r:HALF_EVEN (0 + decimal.exp(-1)) inexact rounded', 0.3678794, 0 + decimal.exp(-1));
	AddTestCase('expx043:p7 r:HALF_EVEN (0 + decimal.exp(10)) inexact rounded', 22026.47, 0 + decimal.exp(10));
	AddTestCase('expx044:p7 r:HALF_EVEN (0 + decimal.exp(-10)) inexact rounded', 0.00004539993, 0 + decimal.exp(-10));
	AddTestCase('expx045:p7 r:HALF_EVEN (0 + decimal.exp(100)) inexact rounded', 2.688117e+43, 0 + decimal.exp(100));
	AddTestCase('expx046:p7 r:HALF_EVEN (0 + decimal.exp(-100)) inexact rounded', 3.720076e-44, 0 + decimal.exp(-100));
	// miscellanea
	// similar to 'vf bug' test, at 17, but with last digit corrected for decimal
}
{
	use precision 16;
	AddTestCase('expx055:p16 r:HALF_EVEN (0 + decimal.exp(-5.42410311287441459172e+2)) inexact rounded', 2.717658486884572e-236, 0 + decimal.exp(-5.42410311287441459172e+2));
	//  result from netrexx/java prototype -> 2.7176584868845721117677929628617246054459644711108e-236
	//   result from rexx (series) version -> 2.717658486884572111767792962861724605446e-236
}
{
	use precision 17;
	AddTestCase('expx056:p17 r:HALF_EVEN (0 + decimal.exp(-5.42410311287441459172e+2)) inexact rounded', 2.7176584868845721e-236, 0 + decimal.exp(-5.42410311287441459172e+2));
}
{
	use precision 18;
	AddTestCase('expx057:p18 r:HALF_EVEN (0 + decimal.exp(-5.42410311287441459172e+2)) inexact rounded', 2.71765848688457211e-236, 0 + decimal.exp(-5.42410311287441459172e+2));
}
{
	use precision 19;
	AddTestCase('expx058:p19 r:HALF_EVEN (0 + decimal.exp(-5.42410311287441459172e+2)) inexact rounded', 2.717658486884572112e-236, 0 + decimal.exp(-5.42410311287441459172e+2));
}
{
	use precision 20;
	AddTestCase('expx059:p20 r:HALF_EVEN (0 + decimal.exp(-5.42410311287441459172e+2)) inexact rounded', 2.7176584868845721118e-236, 0 + decimal.exp(-5.42410311287441459172e+2));
	// rounding in areas of ..500.., ..499.., ..100.., ..999.. sequences
}
{
	use precision 31;
	AddTestCase('expx102:p31 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.9999999100000040499998785000027, 0 + decimal.exp(-9e-8));
}
{
	use precision 30;
	AddTestCase('expx103:p30 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.999999910000004049999878500003, 0 + decimal.exp(-9e-8));
}
{
	use precision 29;
	AddTestCase('expx104:p29 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.99999991000000404999987850000, 0 + decimal.exp(-9e-8));
}
{
	use precision 28;
	AddTestCase('expx105:p28 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.9999999100000040499998785000, 0 + decimal.exp(-9e-8));
}
{
	use precision 27;
	AddTestCase('expx106:p27 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.999999910000004049999878500, 0 + decimal.exp(-9e-8));
}
{
	use precision 26;
	AddTestCase('expx107:p26 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.99999991000000404999987850, 0 + decimal.exp(-9e-8));
}
{
	use precision 25;
	AddTestCase('expx108:p25 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.9999999100000040499998785, 0 + decimal.exp(-9e-8));
}
{
	use precision 24;
	AddTestCase('expx109:p24 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.999999910000004049999879, 0 + decimal.exp(-9e-8));
}
{
	use precision 23;
	AddTestCase('expx110:p23 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.99999991000000404999988, 0 + decimal.exp(-9e-8));
}
{
	use precision 22;
	AddTestCase('expx111:p22 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.9999999100000040499999, 0 + decimal.exp(-9e-8));
}
{
	use precision 21;
	AddTestCase('expx112:p21 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.999999910000004050000, 0 + decimal.exp(-9e-8));
}
{
	use precision 20;
	AddTestCase('expx113:p20 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.99999991000000405000, 0 + decimal.exp(-9e-8));
}
{
	use precision 19;
	AddTestCase('expx114:p19 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.9999999100000040500, 0 + decimal.exp(-9e-8));
}
{
	use precision 18;
	AddTestCase('expx115:p18 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.999999910000004050, 0 + decimal.exp(-9e-8));
}
{
	use precision 17;
	AddTestCase('expx116:p17 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.99999991000000405, 0 + decimal.exp(-9e-8));
}
{
	use precision 16;
	AddTestCase('expx117:p16 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.9999999100000040, 0 + decimal.exp(-9e-8));
}
{
	use precision 15;
	AddTestCase('expx118:p15 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.999999910000004, 0 + decimal.exp(-9e-8));
}
{
	use precision 14;
	AddTestCase('expx119:p14 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.99999991000000, 0 + decimal.exp(-9e-8));
}
{
	use precision 13;
	AddTestCase('expx120:p13 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.9999999100000, 0 + decimal.exp(-9e-8));
}
{
	use precision 12;
	AddTestCase('expx121:p12 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.999999910000, 0 + decimal.exp(-9e-8));
}
{
	use precision 11;
	AddTestCase('expx122:p11 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.99999991000, 0 + decimal.exp(-9e-8));
}
{
	use precision 10;
	AddTestCase('expx123:p10 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.9999999100, 0 + decimal.exp(-9e-8));
}
{
	use precision 9;
	AddTestCase('expx124:p9 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.999999910, 0 + decimal.exp(-9e-8));
}
{
	use precision 8;
	AddTestCase('expx125:p8 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.99999991, 0 + decimal.exp(-9e-8));
}
{
	use precision 7;
	AddTestCase('expx126:p7 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 0.9999999, 0 + decimal.exp(-9e-8));
}
{
	use precision 6;
	AddTestCase('expx127:p6 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 1.00000, 0 + decimal.exp(-9e-8));
}
{
	use precision 5;
	AddTestCase('expx128:p5 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 1.0000, 0 + decimal.exp(-9e-8));
}
{
	use precision 4;
	AddTestCase('expx129:p4 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 1.000, 0 + decimal.exp(-9e-8));
}
{
	use precision 3;
	AddTestCase('expx130:p3 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 1.00, 0 + decimal.exp(-9e-8));
}
{
	use precision 2;
	AddTestCase('expx131:p2 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 1.0, 0 + decimal.exp(-9e-8));
}
{
	use precision 1;
	AddTestCase('expx132:p1 r:HALF_EVEN (0 + decimal.exp(-9e-8)) inexact rounded', 1, 0 + decimal.exp(-9e-8));
	// sanity checks, with iteration counts [normalized so 0<=|x|<1]
	// iterations: 2
	// iterations: 8
	// iterations: 6
	// iterations: 15
	// iterations: 14
	// iterations: 26
	// iterations: 39
	// iterations: 41
	// iterations: 43
	// iterations: 26
	// iterations: 26
	// iterations: 27
	// iterations: 28
	// iterations: 30
	// iterations: 36
	// iterations: 26
	// iterations: 28
	// iterations: 29
	// iterations: 30
	// iterations: 2
	// iterations: 7
	// iterations: 6
	// iterations: 15
	// iterations: 13
	// iterations: 25
	// iterations: 38
	// iterations: 41
	// iterations: 42
	// iterations: 26
	// iterations: 26
	// iterations: 26
	// iterations: 28
	// iterations: 29
	// iterations: 36
	// iterations: 26
	// iterations: 28
	// iterations: 28
	// iterations: 29
	// a biggie [result verified 3 ways]
	// extreme range boundaries
}
{
	use precision 16;
	// ntiny boundary
	// nmax/10 and nmax boundary
	AddTestCase('expx292:p16 r:HALF_EVEN (0 + decimal.exp(2302582.790408952)) inexact rounded', 9.999999993100277e+999998, 0 + decimal.exp(2302582.790408952));
	AddTestCase('expx293:p16 r:HALF_EVEN (0 + decimal.exp(2302582.790408953)) inexact rounded', 1.000000000310028e+999999, 0 + decimal.exp(2302582.790408953));
	AddTestCase('expx294:p16 r:HALF_EVEN (0 + decimal.exp(2302585.092993946)) inexact rounded', 9.999999003159870e+999999, 0 + decimal.exp(2302585.092993946));
	AddTestCase('expx295:p16 r:HALF_EVEN (0 + decimal.exp(2302585.092994036)) inexact rounded', 9.999999903159821e+999999, 0 + decimal.exp(2302585.092994036));
	AddTestCase('expx296:p16 r:HALF_EVEN (0 + decimal.exp(2302585.092994045)) inexact rounded', 9.999999993159820e+999999, 0 + decimal.exp(2302585.092994045));
	// 0<-x<<1 effects
}
{
	use precision 30;
	AddTestCase('expx320:p30 r:HALF_EVEN (0 + decimal.exp(-4.9999999999999e-8)) inexact rounded', 0.999999950000001250000979166617, 0 + decimal.exp(-4.9999999999999e-8));
	AddTestCase('expx321:p30 r:HALF_EVEN (0 + decimal.exp(-5.0000000000000e-8)) inexact rounded', 0.999999950000001249999979166667, 0 + decimal.exp(-5.0000000000000e-8));
	AddTestCase('expx322:p30 r:HALF_EVEN (0 + decimal.exp(-5.0000000000001e-8)) inexact rounded', 0.999999950000001249998979166717, 0 + decimal.exp(-5.0000000000001e-8));
}
{
	use precision 20;
	AddTestCase('expx323:p20 r:HALF_EVEN (0 + decimal.exp(-4.9999999999999e-8)) inexact rounded', 0.99999995000000125000, 0 + decimal.exp(-4.9999999999999e-8));
	AddTestCase('expx324:p20 r:HALF_EVEN (0 + decimal.exp(-5.0000000000000e-8)) inexact rounded', 0.99999995000000125000, 0 + decimal.exp(-5.0000000000000e-8));
	AddTestCase('expx325:p20 r:HALF_EVEN (0 + decimal.exp(-5.0000000000001e-8)) inexact rounded', 0.99999995000000125000, 0 + decimal.exp(-5.0000000000001e-8));
}
{
	use precision 14;
	AddTestCase('expx326:p14 r:HALF_EVEN (0 + decimal.exp(-4.9999999999999e-8)) inexact rounded', 0.99999995000000, 0 + decimal.exp(-4.9999999999999e-8));
	AddTestCase('expx327:p14 r:HALF_EVEN (0 + decimal.exp(-5.0000000000000e-8)) inexact rounded', 0.99999995000000, 0 + decimal.exp(-5.0000000000000e-8));
	AddTestCase('expx328:p14 r:HALF_EVEN (0 + decimal.exp(-5.0000000000001e-8)) inexact rounded', 0.99999995000000, 0 + decimal.exp(-5.0000000000001e-8));
	// overprecise and 0<-x<<1
}
{
	use precision 8;
	AddTestCase('expx330:p8 r:HALF_EVEN (0 + decimal.exp(-4.9999999999999e-8)) inexact rounded', 0.99999995, 0 + decimal.exp(-4.9999999999999e-8));
	AddTestCase('expx331:p8 r:HALF_EVEN (0 + decimal.exp(-5.0000000000000e-8)) inexact rounded', 0.99999995, 0 + decimal.exp(-5.0000000000000e-8));
	AddTestCase('expx332:p8 r:HALF_EVEN (0 + decimal.exp(-5.0000000000001e-8)) inexact rounded', 0.99999995, 0 + decimal.exp(-5.0000000000001e-8));
}
{
	use precision 7;
	AddTestCase('expx333:p7 r:HALF_EVEN (0 + decimal.exp(-4.9999999999999e-8)) inexact rounded', 1.000000, 0 + decimal.exp(-4.9999999999999e-8));
	AddTestCase('expx334:p7 r:HALF_EVEN (0 + decimal.exp(-5.0000000000000e-8)) inexact rounded', 1.000000, 0 + decimal.exp(-5.0000000000000e-8));
	AddTestCase('expx335:p7 r:HALF_EVEN (0 + decimal.exp(-5.0000000000001e-8)) inexact rounded', 1.000000, 0 + decimal.exp(-5.0000000000001e-8));
}
{
	use precision 3;
	AddTestCase('expx336:p3 r:HALF_EVEN (0 + decimal.exp(-4.9999999999999e-8)) inexact rounded', 1.00, 0 + decimal.exp(-4.9999999999999e-8));
	AddTestCase('expx337:p3 r:HALF_EVEN (0 + decimal.exp(-5.0000000000000e-8)) inexact rounded', 1.00, 0 + decimal.exp(-5.0000000000000e-8));
	AddTestCase('expx338:p3 r:HALF_EVEN (0 + decimal.exp(-5.0000000000001e-8)) inexact rounded', 1.00, 0 + decimal.exp(-5.0000000000001e-8));
	// 0<x<<1 effects
}
{
	use precision 30;
	AddTestCase('expx340:p30 r:HALF_EVEN (0 + decimal.exp(4.9999999999999e-8)) inexact rounded', 1.00000005000000124999902083328, 0 + decimal.exp(4.9999999999999e-8));
	AddTestCase('expx341:p30 r:HALF_EVEN (0 + decimal.exp(5.0000000000000e-8)) inexact rounded', 1.00000005000000125000002083333, 0 + decimal.exp(5.0000000000000e-8));
	AddTestCase('expx342:p30 r:HALF_EVEN (0 + decimal.exp(5.0000000000001e-8)) inexact rounded', 1.00000005000000125000102083338, 0 + decimal.exp(5.0000000000001e-8));
}
{
	use precision 20;
	AddTestCase('expx343:p20 r:HALF_EVEN (0 + decimal.exp(4.9999999999999e-8)) inexact rounded', 1.0000000500000012500, 0 + decimal.exp(4.9999999999999e-8));
	AddTestCase('expx344:p20 r:HALF_EVEN (0 + decimal.exp(5.0000000000000e-8)) inexact rounded', 1.0000000500000012500, 0 + decimal.exp(5.0000000000000e-8));
	AddTestCase('expx345:p20 r:HALF_EVEN (0 + decimal.exp(5.0000000000001e-8)) inexact rounded', 1.0000000500000012500, 0 + decimal.exp(5.0000000000001e-8));
}
{
	use precision 14;
	AddTestCase('expx346:p14 r:HALF_EVEN (0 + decimal.exp(4.9999999999999e-8)) inexact rounded', 1.0000000500000, 0 + decimal.exp(4.9999999999999e-8));
	AddTestCase('expx347:p14 r:HALF_EVEN (0 + decimal.exp(5.0000000000000e-8)) inexact rounded', 1.0000000500000, 0 + decimal.exp(5.0000000000000e-8));
	AddTestCase('expx348:p14 r:HALF_EVEN (0 + decimal.exp(5.0000000000001e-8)) inexact rounded', 1.0000000500000, 0 + decimal.exp(5.0000000000001e-8));
	// overprecise and 0<x<<1
}
{
	use precision 8;
	AddTestCase('expx350:p8 r:HALF_EVEN (0 + decimal.exp(4.9999999999999e-8)) inexact rounded', 1.0000001, 0 + decimal.exp(4.9999999999999e-8));
	AddTestCase('expx351:p8 r:HALF_EVEN (0 + decimal.exp(5.0000000000000e-8)) inexact rounded', 1.0000001, 0 + decimal.exp(5.0000000000000e-8));
	AddTestCase('expx352:p8 r:HALF_EVEN (0 + decimal.exp(5.0000000000001e-8)) inexact rounded', 1.0000001, 0 + decimal.exp(5.0000000000001e-8));
}
{
	use precision 7;
	AddTestCase('expx353:p7 r:HALF_EVEN (0 + decimal.exp(4.9999999999999e-8)) inexact rounded', 1.000000, 0 + decimal.exp(4.9999999999999e-8));
	AddTestCase('expx354:p7 r:HALF_EVEN (0 + decimal.exp(5.0000000000000e-8)) inexact rounded', 1.000000, 0 + decimal.exp(5.0000000000000e-8));
	AddTestCase('expx355:p7 r:HALF_EVEN (0 + decimal.exp(5.0000000000001e-8)) inexact rounded', 1.000000, 0 + decimal.exp(5.0000000000001e-8));
}
{
	use precision 3;
	AddTestCase('expx356:p3 r:HALF_EVEN (0 + decimal.exp(4.9999999999999e-8)) inexact rounded', 1.00, 0 + decimal.exp(4.9999999999999e-8));
	AddTestCase('expx357:p3 r:HALF_EVEN (0 + decimal.exp(5.0000000000000e-8)) inexact rounded', 1.00, 0 + decimal.exp(5.0000000000000e-8));
	AddTestCase('expx358:p3 r:HALF_EVEN (0 + decimal.exp(5.0000000000001e-8)) inexact rounded', 1.00, 0 + decimal.exp(5.0000000000001e-8));
	// cases near 1              --  1 2345678901234567890
}
{
	use precision 20;
	AddTestCase('expx401:p20 r:HALF_EVEN (0 + decimal.exp(0.99999999999996)) inexact rounded', 2.7182818284589365041, 0 + decimal.exp(0.99999999999996));
	AddTestCase('expx402:p20 r:HALF_EVEN (0 + decimal.exp(0.99999999999997)) inexact rounded', 2.7182818284589636869, 0 + decimal.exp(0.99999999999997));
	AddTestCase('expx403:p20 r:HALF_EVEN (0 + decimal.exp(0.99999999999998)) inexact rounded', 2.7182818284589908697, 0 + decimal.exp(0.99999999999998));
	AddTestCase('expx404:p20 r:HALF_EVEN (0 + decimal.exp(0.99999999999999)) inexact rounded', 2.7182818284590180525, 0 + decimal.exp(0.99999999999999));
	AddTestCase('expx405:p20 r:HALF_EVEN (0 + decimal.exp(1.0000000000000)) inexact rounded', 2.7182818284590452354, 0 + decimal.exp(1.0000000000000));
	AddTestCase('expx406:p20 r:HALF_EVEN (0 + decimal.exp(1.0000000000001)) inexact rounded', 2.7182818284593170635, 0 + decimal.exp(1.0000000000001));
	AddTestCase('expx407:p20 r:HALF_EVEN (0 + decimal.exp(1.0000000000002)) inexact rounded', 2.7182818284595888917, 0 + decimal.exp(1.0000000000002));
}
{
	use precision 14;
	AddTestCase('expx411:p14 r:HALF_EVEN (0 + decimal.exp(0.99999999999996)) inexact rounded', 2.7182818284589, 0 + decimal.exp(0.99999999999996));
	AddTestCase('expx412:p14 r:HALF_EVEN (0 + decimal.exp(0.99999999999997)) inexact rounded', 2.7182818284590, 0 + decimal.exp(0.99999999999997));
	AddTestCase('expx413:p14 r:HALF_EVEN (0 + decimal.exp(0.99999999999998)) inexact rounded', 2.7182818284590, 0 + decimal.exp(0.99999999999998));
	AddTestCase('expx414:p14 r:HALF_EVEN (0 + decimal.exp(0.99999999999999)) inexact rounded', 2.7182818284590, 0 + decimal.exp(0.99999999999999));
	AddTestCase('expx415:p14 r:HALF_EVEN (0 + decimal.exp(1.0000000000000)) inexact rounded', 2.7182818284590, 0 + decimal.exp(1.0000000000000));
	AddTestCase('expx416:p14 r:HALF_EVEN (0 + decimal.exp(1.0000000000001)) inexact rounded', 2.7182818284593, 0 + decimal.exp(1.0000000000001));
	AddTestCase('expx417:p14 r:HALF_EVEN (0 + decimal.exp(1.0000000000002)) inexact rounded', 2.7182818284596, 0 + decimal.exp(1.0000000000002));
	// overprecise...
}
{
	use precision 7;
	AddTestCase('expx421:p7 r:HALF_EVEN (0 + decimal.exp(0.99999999999996)) inexact rounded', 2.718282, 0 + decimal.exp(0.99999999999996));
	AddTestCase('expx422:p7 r:HALF_EVEN (0 + decimal.exp(0.99999999999997)) inexact rounded', 2.718282, 0 + decimal.exp(0.99999999999997));
	AddTestCase('expx423:p7 r:HALF_EVEN (0 + decimal.exp(0.99999999999998)) inexact rounded', 2.718282, 0 + decimal.exp(0.99999999999998));
	AddTestCase('expx424:p7 r:HALF_EVEN (0 + decimal.exp(0.99999999999999)) inexact rounded', 2.718282, 0 + decimal.exp(0.99999999999999));
	AddTestCase('expx425:p7 r:HALF_EVEN (0 + decimal.exp(1.0000000000001)) inexact rounded', 2.718282, 0 + decimal.exp(1.0000000000001));
	AddTestCase('expx426:p7 r:HALF_EVEN (0 + decimal.exp(1.0000000000002)) inexact rounded', 2.718282, 0 + decimal.exp(1.0000000000002));
	AddTestCase('expx427:p7 r:HALF_EVEN (0 + decimal.exp(1.0000000000003)) inexact rounded', 2.718282, 0 + decimal.exp(1.0000000000003));
}
{
	use precision 2;
	AddTestCase('expx431:p2 r:HALF_EVEN (0 + decimal.exp(0.99999999999996)) inexact rounded', 2.7, 0 + decimal.exp(0.99999999999996));
	AddTestCase('expx432:p2 r:HALF_EVEN (0 + decimal.exp(0.99999999999997)) inexact rounded', 2.7, 0 + decimal.exp(0.99999999999997));
	AddTestCase('expx433:p2 r:HALF_EVEN (0 + decimal.exp(0.99999999999998)) inexact rounded', 2.7, 0 + decimal.exp(0.99999999999998));
	AddTestCase('expx434:p2 r:HALF_EVEN (0 + decimal.exp(0.99999999999999)) inexact rounded', 2.7, 0 + decimal.exp(0.99999999999999));
	AddTestCase('expx435:p2 r:HALF_EVEN (0 + decimal.exp(1.0000000000001)) inexact rounded', 2.7, 0 + decimal.exp(1.0000000000001));
	AddTestCase('expx436:p2 r:HALF_EVEN (0 + decimal.exp(1.0000000000002)) inexact rounded', 2.7, 0 + decimal.exp(1.0000000000002));
	AddTestCase('expx437:p2 r:HALF_EVEN (0 + decimal.exp(1.0000000000003)) inexact rounded', 2.7, 0 + decimal.exp(1.0000000000003));
	// basics at low precisions
}
{
	use precision 3;
	AddTestCase('expx501:p3 r:HALF_EVEN (0 + decimal.exp(decimal.NEGATIVE_INFINITY))', 0, 0 + decimal.exp(decimal.NEGATIVE_INFINITY));
	AddTestCase('expx502:p3 r:HALF_EVEN (0 + decimal.exp(-10)) inexact rounded', 0.0000454, 0 + decimal.exp(-10));
	AddTestCase('expx503:p3 r:HALF_EVEN (0 + decimal.exp(-1)) inexact rounded', 0.368, 0 + decimal.exp(-1));
	AddTestCase('expx504:p3 r:HALF_EVEN (0 + decimal.exp(0))', 1, 0 + decimal.exp(0));
	AddTestCase('expx505:p3 r:HALF_EVEN (0 + decimal.exp(-0))', 1, 0 + decimal.exp(-0));
	AddTestCase('expx506:p3 r:HALF_EVEN (0 + decimal.exp(1)) inexact rounded', 2.72, 0 + decimal.exp(1));
	AddTestCase('expx507:p3 r:HALF_EVEN (0 + decimal.exp(0.693147181)) inexact rounded', 2.00, 0 + decimal.exp(0.693147181));
	AddTestCase('expx508:p3 r:HALF_EVEN (0 + decimal.exp(10)) inexact rounded', 2.20e+4, 0 + decimal.exp(10));
	AddTestCase('expx509:p3 r:HALF_EVEN (0 + decimal.exp(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.exp(decimal.POSITIVE_INFINITY));
}
{
	use precision 2;
	AddTestCase('expx511:p2 r:HALF_EVEN (0 + decimal.exp(decimal.NEGATIVE_INFINITY))', 0, 0 + decimal.exp(decimal.NEGATIVE_INFINITY));
	AddTestCase('expx512:p2 r:HALF_EVEN (0 + decimal.exp(-10)) inexact rounded', 0.000045, 0 + decimal.exp(-10));
	AddTestCase('expx513:p2 r:HALF_EVEN (0 + decimal.exp(-1)) inexact rounded', 0.37, 0 + decimal.exp(-1));
	AddTestCase('expx514:p2 r:HALF_EVEN (0 + decimal.exp(0))', 1, 0 + decimal.exp(0));
	AddTestCase('expx515:p2 r:HALF_EVEN (0 + decimal.exp(-0))', 1, 0 + decimal.exp(-0));
	AddTestCase('expx516:p2 r:HALF_EVEN (0 + decimal.exp(1)) inexact rounded', 2.7, 0 + decimal.exp(1));
	AddTestCase('expx517:p2 r:HALF_EVEN (0 + decimal.exp(0.693147181)) inexact rounded', 2.0, 0 + decimal.exp(0.693147181));
	AddTestCase('expx518:p2 r:HALF_EVEN (0 + decimal.exp(10)) inexact rounded', 2.2e+4, 0 + decimal.exp(10));
	AddTestCase('expx519:p2 r:HALF_EVEN (0 + decimal.exp(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.exp(decimal.POSITIVE_INFINITY));
}
{
	use precision 1;
	AddTestCase('expx521:p1 r:HALF_EVEN (0 + decimal.exp(decimal.NEGATIVE_INFINITY))', 0, 0 + decimal.exp(decimal.NEGATIVE_INFINITY));
	AddTestCase('expx522:p1 r:HALF_EVEN (0 + decimal.exp(-10)) inexact rounded', 0.00005, 0 + decimal.exp(-10));
	AddTestCase('expx523:p1 r:HALF_EVEN (0 + decimal.exp(-1)) inexact rounded', 0.4, 0 + decimal.exp(-1));
	AddTestCase('expx524:p1 r:HALF_EVEN (0 + decimal.exp(0))', 1, 0 + decimal.exp(0));
	AddTestCase('expx525:p1 r:HALF_EVEN (0 + decimal.exp(-0))', 1, 0 + decimal.exp(-0));
	AddTestCase('expx526:p1 r:HALF_EVEN (0 + decimal.exp(1)) inexact rounded', 3, 0 + decimal.exp(1));
	AddTestCase('expx527:p1 r:HALF_EVEN (0 + decimal.exp(0.693147181)) inexact rounded', 2, 0 + decimal.exp(0.693147181));
	AddTestCase('expx528:p1 r:HALF_EVEN (0 + decimal.exp(10)) inexact rounded', 2e+4, 0 + decimal.exp(10));
	AddTestCase('expx529:p1 r:HALF_EVEN (0 + decimal.exp(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.exp(decimal.POSITIVE_INFINITY));
	// overflows, including some overprecise borderlines
}
{
	use precision 7;
	AddTestCase('expx709:p7 r:HALF_EVEN (0 + decimal.exp(886.4952607)) inexact rounded', 9.999999e+384, 0 + decimal.exp(886.4952607));
	AddTestCase('expx711:p7 r:HALF_EVEN (0 + decimal.exp(886.49526)) inexact rounded', 9.999992e+384, 0 + decimal.exp(886.49526));
}
{
	use precision 16;
	AddTestCase('expx722:p16 r:HALF_EVEN (0 + decimal.exp(886.4952608027075882)) inexact rounded', 9.999999999999999e+384, 0 + decimal.exp(886.4952608027075882));
	AddTestCase('expx724:p16 r:HALF_EVEN (0 + decimal.exp(886.49526080270758)) inexact rounded', 9.999999999999917e+384, 0 + decimal.exp(886.49526080270758));
	AddTestCase('expx726:p16 r:HALF_EVEN (0 + decimal.exp(886.4952608027075)) inexact rounded', 9.999999999999117e+384, 0 + decimal.exp(886.4952608027075));
	// and by special request ...
}
{
	use precision 15;
	AddTestCase('expx732:p15 r:HALF_EVEN (0 + decimal.exp(886.495260802707)) inexact rounded', 9.99999999999412e+384, 0 + decimal.exp(886.495260802707));
	AddTestCase('expx733:p15 r:HALF_EVEN (0 + decimal.exp(886.495260802706)) inexact rounded', 9.99999999998412e+384, 0 + decimal.exp(886.495260802706));
	AddTestCase('expx736:p15 r:HALF_EVEN (0 + decimal.exp(2302.58509299404)) inexact rounded', 9.99999999994316e+999, 0 + decimal.exp(2302.58509299404));
	AddTestCase('expx737:p15 r:HALF_EVEN (0 + decimal.exp(2302.58509299403)) inexact rounded', 9.99999999984316e+999, 0 + decimal.exp(2302.58509299403));
	// subnormals and underflows, including underflow-to-zero edge point
}
{
	use precision 7;
	AddTestCase('expx758:p7 r:HALF_EVEN (0 + decimal.exp(-881.89009)) inexact rounded', 1.000001e-383, 0 + decimal.exp(-881.89009));
	// special values
	AddTestCase('expx820:p7 r:HALF_EVEN (0 + decimal.exp(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.exp(decimal.POSITIVE_INFINITY));
	AddTestCase('expx821:p7 r:HALF_EVEN (0 + decimal.exp(decimal.NEGATIVE_INFINITY))', 0, 0 + decimal.exp(decimal.NEGATIVE_INFINITY));
	AddTestCase('expx822:p7 r:HALF_EVEN (0 + decimal.exp(NaN))', NaN, 0 + decimal.exp(NaN));
	AddTestCase('expx823:p7 r:HALF_EVEN (0 + decimal.exp(NaN)) invalid_operation', NaN, 0 + decimal.exp(NaN));
	// propagating nans
	AddTestCase('expx824:p7 r:HALF_EVEN (0 + decimal.exp(NaN)) invalid_operation', NaN, 0 + decimal.exp(NaN));
	AddTestCase('expx825:p7 r:HALF_EVEN (0 + decimal.exp(-NaN)) invalid_operation', -NaN, 0 + decimal.exp(-NaN));
	AddTestCase('expx826:p7 r:HALF_EVEN (0 + decimal.exp(NaN))', NaN, 0 + decimal.exp(NaN));
	AddTestCase('expx827:p7 r:HALF_EVEN (0 + decimal.exp(-NaN))', -NaN, 0 + decimal.exp(-NaN));
	AddTestCase('expx828:p7 r:HALF_EVEN (0 + decimal.exp(NaN))', NaN, 0 + decimal.exp(NaN));
	// invalid operations due to restrictions
	// [next two probably skipped by most test harnesses]
}
{
	use precision 9;
	AddTestCase('expx903:p9 r:HALF_EVEN (0 + decimal.exp(decimal.NEGATIVE_INFINITY)) invalid_context', 0, 0 + decimal.exp(decimal.NEGATIVE_INFINITY));
	AddTestCase('expx904:p9 r:HALF_EVEN (0 + decimal.exp(decimal.NEGATIVE_INFINITY))', 0, 0 + decimal.exp(decimal.NEGATIVE_INFINITY));
	AddTestCase('expx905:p9 r:HALF_EVEN (0 + decimal.exp(decimal.NEGATIVE_INFINITY)) invalid_context', 0, 0 + decimal.exp(decimal.NEGATIVE_INFINITY));
	AddTestCase('expx906:p9 r:HALF_EVEN (0 + decimal.exp(decimal.NEGATIVE_INFINITY))', 0, 0 + decimal.exp(decimal.NEGATIVE_INFINITY));
	//
}
{
	use precision 16;
	{
		use rounding HALF_EVEN;
		// null test
		AddTestCase('expx900:p16 r:HALF_EVEN (0 + decimal.exp(null)) invalid_operation', 1, 0 + decimal.exp(null));
		// randoms p=50, within 0-999
		// exp(1) at 34
		// randoms p=34, within 0-999
		// randoms p=16, within 0-99
		{
			use precision 16;
			AddTestCase('expx1101:p16 r:HALF_EVEN (0 + decimal.exp(8.473011527013724)) inexact rounded', 4783.900643969246, 0 + decimal.exp(8.473011527013724));
			AddTestCase('expx1102:p16 r:HALF_EVEN (0 + decimal.exp(0.0000055753022764)) inexact rounded', 1.000005575317818, 0 + decimal.exp(0.0000055753022764));
			AddTestCase('expx1103:p16 r:HALF_EVEN (0 + decimal.exp(0.0000323474114482)) inexact rounded', 1.000032347934631, 0 + decimal.exp(0.0000323474114482));
			AddTestCase('expx1104:p16 r:HALF_EVEN (0 + decimal.exp(64.54374138544166)) inexact rounded', 1.073966476173531e+28, 0 + decimal.exp(64.54374138544166));
			AddTestCase('expx1105:p16 r:HALF_EVEN (0 + decimal.exp(90.47203246416569)) inexact rounded', 1.956610887250643e+39, 0 + decimal.exp(90.47203246416569));
			AddTestCase('expx1106:p16 r:HALF_EVEN (0 + decimal.exp(9.299931532342757)) inexact rounded', 10937.27033325227, 0 + decimal.exp(9.299931532342757));
			AddTestCase('expx1107:p16 r:HALF_EVEN (0 + decimal.exp(8.759678437852203)) inexact rounded', 6372.062234495381, 0 + decimal.exp(8.759678437852203));
			AddTestCase('expx1108:p16 r:HALF_EVEN (0 + decimal.exp(0.0000931755127172)) inexact rounded', 1.000093179853690, 0 + decimal.exp(0.0000931755127172));
			AddTestCase('expx1109:p16 r:HALF_EVEN (0 + decimal.exp(0.0000028101158373)) inexact rounded', 1.000002810119786, 0 + decimal.exp(0.0000028101158373));
			AddTestCase('expx1110:p16 r:HALF_EVEN (0 + decimal.exp(0.0000008008130919)) inexact rounded', 1.000000800813413, 0 + decimal.exp(0.0000008008130919));
			AddTestCase('expx1111:p16 r:HALF_EVEN (0 + decimal.exp(8.339771722299049)) inexact rounded', 4187.133803081878, 0 + decimal.exp(8.339771722299049));
			AddTestCase('expx1112:p16 r:HALF_EVEN (0 + decimal.exp(0.0026140497995474)) inexact rounded', 1.002617469406750, 0 + decimal.exp(0.0026140497995474));
			AddTestCase('expx1113:p16 r:HALF_EVEN (0 + decimal.exp(0.7478033356261771)) inexact rounded', 2.112354781975418, 0 + decimal.exp(0.7478033356261771));
			AddTestCase('expx1114:p16 r:HALF_EVEN (0 + decimal.exp(51.77663761827966)) inexact rounded', 3.064135801120365e+22, 0 + decimal.exp(51.77663761827966));
			AddTestCase('expx1115:p16 r:HALF_EVEN (0 + decimal.exp(0.1524989783061012)) inexact rounded', 1.164741272084955, 0 + decimal.exp(0.1524989783061012));
			AddTestCase('expx1116:p16 r:HALF_EVEN (0 + decimal.exp(0.0066298798669219)) inexact rounded', 1.006651906170791, 0 + decimal.exp(0.0066298798669219));
			AddTestCase('expx1117:p16 r:HALF_EVEN (0 + decimal.exp(9.955141865534960)) inexact rounded', 21060.23334287038, 0 + decimal.exp(9.955141865534960));
			AddTestCase('expx1118:p16 r:HALF_EVEN (0 + decimal.exp(92.34503059198483)) inexact rounded', 1.273318993481226e+40, 0 + decimal.exp(92.34503059198483));
			AddTestCase('expx1119:p16 r:HALF_EVEN (0 + decimal.exp(0.0000709388677346)) inexact rounded', 1.000070941383956, 0 + decimal.exp(0.0000709388677346));
			AddTestCase('expx1120:p16 r:HALF_EVEN (0 + decimal.exp(79.12883036433204)) inexact rounded', 2.318538899389243e+34, 0 + decimal.exp(79.12883036433204));
			AddTestCase('expx1121:p16 r:HALF_EVEN (0 + decimal.exp(0.0000090881548873)) inexact rounded', 1.000009088196185, 0 + decimal.exp(0.0000090881548873));
			AddTestCase('expx1122:p16 r:HALF_EVEN (0 + decimal.exp(0.0424828809603411)) inexact rounded', 1.043398194245720, 0 + decimal.exp(0.0424828809603411));
			AddTestCase('expx1123:p16 r:HALF_EVEN (0 + decimal.exp(0.8009035891427416)) inexact rounded', 2.227552811933310, 0 + decimal.exp(0.8009035891427416));
			AddTestCase('expx1124:p16 r:HALF_EVEN (0 + decimal.exp(8.825786167283102)) inexact rounded', 6807.540455289995, 0 + decimal.exp(8.825786167283102));
			AddTestCase('expx1125:p16 r:HALF_EVEN (0 + decimal.exp(1.535457249746275)) inexact rounded', 4.643448260146849, 0 + decimal.exp(1.535457249746275));
			AddTestCase('expx1126:p16 r:HALF_EVEN (0 + decimal.exp(69.02254254355800)) inexact rounded', 9.464754500670653e+29, 0 + decimal.exp(69.02254254355800));
			AddTestCase('expx1127:p16 r:HALF_EVEN (0 + decimal.exp(0.0007050554368713)) inexact rounded', 1.000705304046880, 0 + decimal.exp(0.0007050554368713));
			AddTestCase('expx1128:p16 r:HALF_EVEN (0 + decimal.exp(0.0000081206549504)) inexact rounded', 1.000008120687923, 0 + decimal.exp(0.0000081206549504));
			AddTestCase('expx1129:p16 r:HALF_EVEN (0 + decimal.exp(0.621774854641137)) inexact rounded', 1.862230298554903, 0 + decimal.exp(0.621774854641137));
			AddTestCase('expx1130:p16 r:HALF_EVEN (0 + decimal.exp(3.847629031404354)) inexact rounded', 46.88177613568203, 0 + decimal.exp(3.847629031404354));
			AddTestCase('expx1131:p16 r:HALF_EVEN (0 + decimal.exp(24.81250184697732)) inexact rounded', 59694268456.19966, 0 + decimal.exp(24.81250184697732));
			AddTestCase('expx1132:p16 r:HALF_EVEN (0 + decimal.exp(5.107546500516044)) inexact rounded', 165.2643809755670, 0 + decimal.exp(5.107546500516044));
			AddTestCase('expx1133:p16 r:HALF_EVEN (0 + decimal.exp(79.17810943951986)) inexact rounded', 2.435656372541360e+34, 0 + decimal.exp(79.17810943951986));
			AddTestCase('expx1134:p16 r:HALF_EVEN (0 + decimal.exp(0.0051394695667015)) inexact rounded', 1.005152699295301, 0 + decimal.exp(0.0051394695667015));
			AddTestCase('expx1135:p16 r:HALF_EVEN (0 + decimal.exp(57.44504488501725)) inexact rounded', 8.872908566929688e+24, 0 + decimal.exp(57.44504488501725));
			AddTestCase('expx1136:p16 r:HALF_EVEN (0 + decimal.exp(0.0000508388968036)) inexact rounded', 1.000050840189122, 0 + decimal.exp(0.0000508388968036));
			AddTestCase('expx1137:p16 r:HALF_EVEN (0 + decimal.exp(69.71309932148997)) inexact rounded', 1.888053740693541e+30, 0 + decimal.exp(69.71309932148997));
			AddTestCase('expx1138:p16 r:HALF_EVEN (0 + decimal.exp(0.0064183412981502)) inexact rounded', 1.006438982988835, 0 + decimal.exp(0.0064183412981502));
			AddTestCase('expx1139:p16 r:HALF_EVEN (0 + decimal.exp(9.346991220814677)) inexact rounded', 11464.27802035082, 0 + decimal.exp(9.346991220814677));
			AddTestCase('expx1140:p16 r:HALF_EVEN (0 + decimal.exp(33.09087139999152)) inexact rounded', 235062229168763.5, 0 + decimal.exp(33.09087139999152));
			// randoms p=7, within 0-9
		}
		{
			use precision 7;
			AddTestCase('expx1001:p7 r:HALF_EVEN (0 + decimal.exp(2.395441)) inexact rounded', 10.97304, 0 + decimal.exp(2.395441));
			AddTestCase('expx1002:p7 r:HALF_EVEN (0 + decimal.exp(0.6406779)) inexact rounded', 1.897767, 0 + decimal.exp(0.6406779));
			AddTestCase('expx1003:p7 r:HALF_EVEN (0 + decimal.exp(0.5618218)) inexact rounded', 1.753865, 0 + decimal.exp(0.5618218));
			AddTestCase('expx1004:p7 r:HALF_EVEN (0 + decimal.exp(3.055120)) inexact rounded', 21.22373, 0 + decimal.exp(3.055120));
			AddTestCase('expx1005:p7 r:HALF_EVEN (0 + decimal.exp(1.536792)) inexact rounded', 4.649650, 0 + decimal.exp(1.536792));
			AddTestCase('expx1006:p7 r:HALF_EVEN (0 + decimal.exp(0.0801591)) inexact rounded', 1.083459, 0 + decimal.exp(0.0801591));
			AddTestCase('expx1007:p7 r:HALF_EVEN (0 + decimal.exp(0.0966875)) inexact rounded', 1.101516, 0 + decimal.exp(0.0966875));
			AddTestCase('expx1008:p7 r:HALF_EVEN (0 + decimal.exp(0.0646761)) inexact rounded', 1.066813, 0 + decimal.exp(0.0646761));
			AddTestCase('expx1009:p7 r:HALF_EVEN (0 + decimal.exp(0.0095670)) inexact rounded', 1.009613, 0 + decimal.exp(0.0095670));
			AddTestCase('expx1010:p7 r:HALF_EVEN (0 + decimal.exp(2.956859)) inexact rounded', 19.23745, 0 + decimal.exp(2.956859));
			AddTestCase('expx1011:p7 r:HALF_EVEN (0 + decimal.exp(7.504679)) inexact rounded', 1816.522, 0 + decimal.exp(7.504679));
			AddTestCase('expx1012:p7 r:HALF_EVEN (0 + decimal.exp(0.0045259)) inexact rounded', 1.004536, 0 + decimal.exp(0.0045259));
			AddTestCase('expx1013:p7 r:HALF_EVEN (0 + decimal.exp(3.810071)) inexact rounded', 45.15364, 0 + decimal.exp(3.810071));
			AddTestCase('expx1014:p7 r:HALF_EVEN (0 + decimal.exp(1.502390)) inexact rounded', 4.492413, 0 + decimal.exp(1.502390));
			AddTestCase('expx1015:p7 r:HALF_EVEN (0 + decimal.exp(0.0321523)) inexact rounded', 1.032675, 0 + decimal.exp(0.0321523));
			AddTestCase('expx1016:p7 r:HALF_EVEN (0 + decimal.exp(0.0057214)) inexact rounded', 1.005738, 0 + decimal.exp(0.0057214));
			AddTestCase('expx1017:p7 r:HALF_EVEN (0 + decimal.exp(9.811445)) inexact rounded', 18241.33, 0 + decimal.exp(9.811445));
			AddTestCase('expx1018:p7 r:HALF_EVEN (0 + decimal.exp(3.245249)) inexact rounded', 25.66810, 0 + decimal.exp(3.245249));
			AddTestCase('expx1019:p7 r:HALF_EVEN (0 + decimal.exp(0.3189742)) inexact rounded', 1.375716, 0 + decimal.exp(0.3189742));
			AddTestCase('expx1020:p7 r:HALF_EVEN (0 + decimal.exp(0.8621610)) inexact rounded', 2.368273, 0 + decimal.exp(0.8621610));
			AddTestCase('expx1021:p7 r:HALF_EVEN (0 + decimal.exp(0.0122511)) inexact rounded', 1.012326, 0 + decimal.exp(0.0122511));
			AddTestCase('expx1022:p7 r:HALF_EVEN (0 + decimal.exp(2.202088)) inexact rounded', 9.043877, 0 + decimal.exp(2.202088));
			AddTestCase('expx1023:p7 r:HALF_EVEN (0 + decimal.exp(8.778203)) inexact rounded', 6491.202, 0 + decimal.exp(8.778203));
			AddTestCase('expx1024:p7 r:HALF_EVEN (0 + decimal.exp(0.1896279)) inexact rounded', 1.208800, 0 + decimal.exp(0.1896279));
			AddTestCase('expx1025:p7 r:HALF_EVEN (0 + decimal.exp(0.4510947)) inexact rounded', 1.570030, 0 + decimal.exp(0.4510947));
			AddTestCase('expx1026:p7 r:HALF_EVEN (0 + decimal.exp(0.276413)) inexact rounded', 1.318392, 0 + decimal.exp(0.276413));
			AddTestCase('expx1027:p7 r:HALF_EVEN (0 + decimal.exp(4.490067)) inexact rounded', 89.12742, 0 + decimal.exp(4.490067));
			AddTestCase('expx1028:p7 r:HALF_EVEN (0 + decimal.exp(0.0439786)) inexact rounded', 1.044960, 0 + decimal.exp(0.0439786));
			AddTestCase('expx1029:p7 r:HALF_EVEN (0 + decimal.exp(0.8168245)) inexact rounded', 2.263301, 0 + decimal.exp(0.8168245));
			AddTestCase('expx1030:p7 r:HALF_EVEN (0 + decimal.exp(0.0391658)) inexact rounded', 1.039943, 0 + decimal.exp(0.0391658));
			AddTestCase('expx1031:p7 r:HALF_EVEN (0 + decimal.exp(9.261816)) inexact rounded', 10528.24, 0 + decimal.exp(9.261816));
			AddTestCase('expx1032:p7 r:HALF_EVEN (0 + decimal.exp(9.611186)) inexact rounded', 14930.87, 0 + decimal.exp(9.611186));
			AddTestCase('expx1033:p7 r:HALF_EVEN (0 + decimal.exp(9.118125)) inexact rounded', 9119.087, 0 + decimal.exp(9.118125));
			AddTestCase('expx1034:p7 r:HALF_EVEN (0 + decimal.exp(9.469083)) inexact rounded', 12953.00, 0 + decimal.exp(9.469083));
			AddTestCase('expx1035:p7 r:HALF_EVEN (0 + decimal.exp(0.0499983)) inexact rounded', 1.051269, 0 + decimal.exp(0.0499983));
			AddTestCase('expx1036:p7 r:HALF_EVEN (0 + decimal.exp(0.0050746)) inexact rounded', 1.005087, 0 + decimal.exp(0.0050746));
			AddTestCase('expx1037:p7 r:HALF_EVEN (0 + decimal.exp(0.0014696)) inexact rounded', 1.001471, 0 + decimal.exp(0.0014696));
			AddTestCase('expx1038:p7 r:HALF_EVEN (0 + decimal.exp(9.138494)) inexact rounded', 9306.739, 0 + decimal.exp(9.138494));
			AddTestCase('expx1039:p7 r:HALF_EVEN (0 + decimal.exp(0.0065436)) inexact rounded', 1.006565, 0 + decimal.exp(0.0065436));
			AddTestCase('expx1040:p7 r:HALF_EVEN (0 + decimal.exp(0.7284803)) inexact rounded', 2.071930, 0 + decimal.exp(0.7284803));
			}
		}
	}
}
test();
