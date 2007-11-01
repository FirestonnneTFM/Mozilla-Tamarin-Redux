use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "subtract.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// subtract.dectest -- decimal subtraction                            --
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
use precision 9;
use rounding HALF_UP;
// [first group are 'quick confidence check']
AddTestCase('subx001:p9 r:HALF_UP (0 - 0)', 0, 0 - 0);
AddTestCase('subx002:p9 r:HALF_UP (1 - 1)', 0, 1 - 1);
AddTestCase('subx003:p9 r:HALF_UP (1 - 2)', -1, 1 - 2);
AddTestCase('subx004:p9 r:HALF_UP (2 - 1)', 1, 2 - 1);
AddTestCase('subx005:p9 r:HALF_UP (2 - 2)', 0, 2 - 2);
AddTestCase('subx006:p9 r:HALF_UP (3 - 2)', 1, 3 - 2);
AddTestCase('subx007:p9 r:HALF_UP (2 - 3)', -1, 2 - 3);
AddTestCase('subx011:p9 r:HALF_UP (-0 - 0)', -0, -0 - 0);
AddTestCase('subx012:p9 r:HALF_UP (-1 - 1)', -2, -1 - 1);
AddTestCase('subx013:p9 r:HALF_UP (-1 - 2)', -3, -1 - 2);
AddTestCase('subx014:p9 r:HALF_UP (-2 - 1)', -3, -2 - 1);
AddTestCase('subx015:p9 r:HALF_UP (-2 - 2)', -4, -2 - 2);
AddTestCase('subx016:p9 r:HALF_UP (-3 - 2)', -5, -3 - 2);
AddTestCase('subx017:p9 r:HALF_UP (-2 - 3)', -5, -2 - 3);
AddTestCase('subx021:p9 r:HALF_UP (0 - -0)', 0, 0 - -0);
AddTestCase('subx022:p9 r:HALF_UP (1 - -1)', 2, 1 - -1);
AddTestCase('subx023:p9 r:HALF_UP (1 - -2)', 3, 1 - -2);
AddTestCase('subx024:p9 r:HALF_UP (2 - -1)', 3, 2 - -1);
AddTestCase('subx025:p9 r:HALF_UP (2 - -2)', 4, 2 - -2);
AddTestCase('subx026:p9 r:HALF_UP (3 - -2)', 5, 3 - -2);
AddTestCase('subx027:p9 r:HALF_UP (2 - -3)', 5, 2 - -3);
AddTestCase('subx030:p9 r:HALF_UP (11 - 1)', 10, 11 - 1);
AddTestCase('subx031:p9 r:HALF_UP (10 - 1)', 9, 10 - 1);
AddTestCase('subx032:p9 r:HALF_UP (9 - 1)', 8, 9 - 1);
AddTestCase('subx033:p9 r:HALF_UP (1 - 1)', 0, 1 - 1);
AddTestCase('subx034:p9 r:HALF_UP (0 - 1)', -1, 0 - 1);
AddTestCase('subx035:p9 r:HALF_UP (-1 - 1)', -2, -1 - 1);
AddTestCase('subx036:p9 r:HALF_UP (-9 - 1)', -10, -9 - 1);
AddTestCase('subx037:p9 r:HALF_UP (-10 - 1)', -11, -10 - 1);
AddTestCase('subx038:p9 r:HALF_UP (-11 - 1)', -12, -11 - 1);
AddTestCase('subx040:p9 r:HALF_UP (5.75 - 3.3)', 2.45, 5.75 - 3.3);
AddTestCase('subx041:p9 r:HALF_UP (5 - -3)', 8, 5 - -3);
AddTestCase('subx042:p9 r:HALF_UP (-5 - -3)', -2, -5 - -3);
AddTestCase('subx043:p9 r:HALF_UP (-7 - 2.5)', -9.5, -7 - 2.5);
AddTestCase('subx044:p9 r:HALF_UP (0.7 - 0.3)', 0.4, 0.7 - 0.3);
AddTestCase('subx045:p9 r:HALF_UP (1.3 - 0.3)', 1.0, 1.3 - 0.3);
AddTestCase('subx046:p9 r:HALF_UP (1.25 - 1.25)', 0.00, 1.25 - 1.25);
AddTestCase('subx050:p9 r:HALF_UP (1.23456789 - 1.00000000)', 0.23456789, 1.23456789 - 1.00000000);
AddTestCase('subx051:p9 r:HALF_UP (1.23456789 - 1.00000089)', 0.23456700, 1.23456789 - 1.00000089);
AddTestCase('subx052:p9 r:HALF_UP (0.5555555559 - 0.0000000001) inexact rounded', 0.555555556, 0.5555555559 - 0.0000000001);
AddTestCase('subx053:p9 r:HALF_UP (0.5555555559 - 0.0000000005) inexact rounded', 0.555555555, 0.5555555559 - 0.0000000005);
AddTestCase('subx054:p9 r:HALF_UP (0.4444444444 - 0.1111111111) inexact rounded', 0.333333333, 0.4444444444 - 0.1111111111);
AddTestCase('subx055:p9 r:HALF_UP (1.0000000000 - 0.00000001) rounded', 0.999999990, 1.0000000000 - 0.00000001);
AddTestCase('subx056:p9 r:HALF_UP (0.4444444444999 - 0) inexact rounded', 0.444444444, 0.4444444444999 - 0);
AddTestCase('subx057:p9 r:HALF_UP (0.4444444445000 - 0) inexact rounded', 0.444444445, 0.4444444445000 - 0);
AddTestCase('subx060:p9 r:HALF_UP (70 - 10000e+9) inexact rounded', -1.00000000e+13, 70 - 10000e+9);
AddTestCase('subx061:p9 r:HALF_UP (700 - 10000e+9) inexact rounded', -1.00000000e+13, 700 - 10000e+9);
AddTestCase('subx062:p9 r:HALF_UP (7000 - 10000e+9) inexact rounded', -9.99999999e+12, 7000 - 10000e+9);
AddTestCase('subx063:p9 r:HALF_UP (70000 - 10000e+9) rounded', -9.99999993e+12, 70000 - 10000e+9);
AddTestCase('subx064:p9 r:HALF_UP (700000 - 10000e+9) rounded', -9.99999930e+12, 700000 - 10000e+9);
// symmetry:
AddTestCase('subx065:p9 r:HALF_UP (10000e+9 - 70) inexact rounded', 1.00000000e+13, 10000e+9 - 70);
AddTestCase('subx066:p9 r:HALF_UP (10000e+9 - 700) inexact rounded', 1.00000000e+13, 10000e+9 - 700);
AddTestCase('subx067:p9 r:HALF_UP (10000e+9 - 7000) inexact rounded', 9.99999999e+12, 10000e+9 - 7000);
AddTestCase('subx068:p9 r:HALF_UP (10000e+9 - 70000) rounded', 9.99999993e+12, 10000e+9 - 70000);
AddTestCase('subx069:p9 r:HALF_UP (10000e+9 - 700000) rounded', 9.99999930e+12, 10000e+9 - 700000);
// change precision
AddTestCase('subx080:p9 r:HALF_UP (10000e+9 - 70000) rounded', 9.99999993e+12, 10000e+9 - 70000);
{
	use precision 6;
	AddTestCase('subx081:p6 r:HALF_UP (10000e+9 - 70000) inexact rounded', 1.00000e+13, 10000e+9 - 70000);
}
{
	use precision 9;
	// some of the next group are really constructor tests
	AddTestCase('subx090:p9 r:HALF_UP (00.0 - 0.0)', 0.0, 00.0 - 0.0);
	AddTestCase('subx091:p9 r:HALF_UP (00.0 - 0.00)', 0.00, 00.0 - 0.00);
	AddTestCase('subx092:p9 r:HALF_UP (0.00 - 00.0)', 0.00, 0.00 - 00.0);
	AddTestCase('subx093:p9 r:HALF_UP (00.0 - 0.00)', 0.00, 00.0 - 0.00);
	AddTestCase('subx094:p9 r:HALF_UP (0.00 - 00.0)', 0.00, 0.00 - 00.0);
	AddTestCase('subx095:p9 r:HALF_UP (3 - .3)', 2.7, 3 - .3);
	AddTestCase('subx096:p9 r:HALF_UP (3. - .3)', 2.7, 3. - .3);
	AddTestCase('subx097:p9 r:HALF_UP (3.0 - .3)', 2.7, 3.0 - .3);
	AddTestCase('subx098:p9 r:HALF_UP (3.00 - .3)', 2.70, 3.00 - .3);
	AddTestCase('subx099:p9 r:HALF_UP (3 - 3)', 0, 3 - 3);
	AddTestCase('subx100:p9 r:HALF_UP (3 - +3)', 0, 3 - +3);
	AddTestCase('subx101:p9 r:HALF_UP (3 - -3)', 6, 3 - -3);
	AddTestCase('subx102:p9 r:HALF_UP (3 - 0.3)', 2.7, 3 - 0.3);
	AddTestCase('subx103:p9 r:HALF_UP (3. - 0.3)', 2.7, 3. - 0.3);
	AddTestCase('subx104:p9 r:HALF_UP (3.0 - 0.3)', 2.7, 3.0 - 0.3);
	AddTestCase('subx105:p9 r:HALF_UP (3.00 - 0.3)', 2.70, 3.00 - 0.3);
	AddTestCase('subx106:p9 r:HALF_UP (3 - 3.0)', 0.0, 3 - 3.0);
	AddTestCase('subx107:p9 r:HALF_UP (3 - +3.0)', 0.0, 3 - +3.0);
	AddTestCase('subx108:p9 r:HALF_UP (3 - -3.0)', 6.0, 3 - -3.0);
	// the above all from add; massaged and extended.  now some new ones...
	// [particularly important for comparisons]
	// nb: -xe-8 below were non-exponents pre-ansi x3-274, and -1e-7 or 0e-7
	// with input rounding.
	AddTestCase('subx120:p9 r:HALF_UP (10.23456784 - 10.23456789)', -5e-8, 10.23456784 - 10.23456789);
	AddTestCase('subx121:p9 r:HALF_UP (10.23456785 - 10.23456789)', -4e-8, 10.23456785 - 10.23456789);
	AddTestCase('subx122:p9 r:HALF_UP (10.23456786 - 10.23456789)', -3e-8, 10.23456786 - 10.23456789);
	AddTestCase('subx123:p9 r:HALF_UP (10.23456787 - 10.23456789)', -2e-8, 10.23456787 - 10.23456789);
	AddTestCase('subx124:p9 r:HALF_UP (10.23456788 - 10.23456789)', -1e-8, 10.23456788 - 10.23456789);
	AddTestCase('subx125:p9 r:HALF_UP (10.23456789 - 10.23456789)', 0e-8, 10.23456789 - 10.23456789);
	AddTestCase('subx126:p9 r:HALF_UP (10.23456790 - 10.23456789)', 1e-8, 10.23456790 - 10.23456789);
	AddTestCase('subx127:p9 r:HALF_UP (10.23456791 - 10.23456789)', 2e-8, 10.23456791 - 10.23456789);
	AddTestCase('subx128:p9 r:HALF_UP (10.23456792 - 10.23456789)', 3e-8, 10.23456792 - 10.23456789);
	AddTestCase('subx129:p9 r:HALF_UP (10.23456793 - 10.23456789)', 4e-8, 10.23456793 - 10.23456789);
	AddTestCase('subx130:p9 r:HALF_UP (10.23456794 - 10.23456789)', 5e-8, 10.23456794 - 10.23456789);
	AddTestCase('subx131:p9 r:HALF_UP (10.23456781 - 10.23456786)', -5e-8, 10.23456781 - 10.23456786);
	AddTestCase('subx132:p9 r:HALF_UP (10.23456782 - 10.23456786)', -4e-8, 10.23456782 - 10.23456786);
	AddTestCase('subx133:p9 r:HALF_UP (10.23456783 - 10.23456786)', -3e-8, 10.23456783 - 10.23456786);
	AddTestCase('subx134:p9 r:HALF_UP (10.23456784 - 10.23456786)', -2e-8, 10.23456784 - 10.23456786);
	AddTestCase('subx135:p9 r:HALF_UP (10.23456785 - 10.23456786)', -1e-8, 10.23456785 - 10.23456786);
	AddTestCase('subx136:p9 r:HALF_UP (10.23456786 - 10.23456786)', 0e-8, 10.23456786 - 10.23456786);
	AddTestCase('subx137:p9 r:HALF_UP (10.23456787 - 10.23456786)', 1e-8, 10.23456787 - 10.23456786);
	AddTestCase('subx138:p9 r:HALF_UP (10.23456788 - 10.23456786)', 2e-8, 10.23456788 - 10.23456786);
	AddTestCase('subx139:p9 r:HALF_UP (10.23456789 - 10.23456786)', 3e-8, 10.23456789 - 10.23456786);
	AddTestCase('subx140:p9 r:HALF_UP (10.23456790 - 10.23456786)', 4e-8, 10.23456790 - 10.23456786);
	AddTestCase('subx141:p9 r:HALF_UP (10.23456791 - 10.23456786)', 5e-8, 10.23456791 - 10.23456786);
	AddTestCase('subx142:p9 r:HALF_UP (1 - 0.999999999)', 1e-9, 1 - 0.999999999);
	AddTestCase('subx143:p9 r:HALF_UP (0.999999999 - 1)', -1e-9, 0.999999999 - 1);
	AddTestCase('subx144:p9 r:HALF_UP (-10.23456780 - -10.23456786)', 6e-8, -10.23456780 - -10.23456786);
	AddTestCase('subx145:p9 r:HALF_UP (-10.23456790 - -10.23456786)', -4e-8, -10.23456790 - -10.23456786);
	AddTestCase('subx146:p9 r:HALF_UP (-10.23456791 - -10.23456786)', -5e-8, -10.23456791 - -10.23456786);
}
{
	use precision 3;
	AddTestCase('subx150:p3 r:HALF_UP (12345678900000 - 9999999999999) inexact rounded', 2.35e+12, 12345678900000 - 9999999999999);
	AddTestCase('subx151:p3 r:HALF_UP (9999999999999 - 12345678900000) inexact rounded', -2.35e+12, 9999999999999 - 12345678900000);
}
{
	use precision 6;
	AddTestCase('subx152:p6 r:HALF_UP (12345678900000 - 9999999999999) inexact rounded', 2.34568e+12, 12345678900000 - 9999999999999);
	AddTestCase('subx153:p6 r:HALF_UP (9999999999999 - 12345678900000) inexact rounded', -2.34568e+12, 9999999999999 - 12345678900000);
}
{
	use precision 9;
	AddTestCase('subx154:p9 r:HALF_UP (12345678900000 - 9999999999999) inexact rounded', 2.34567890e+12, 12345678900000 - 9999999999999);
	AddTestCase('subx155:p9 r:HALF_UP (9999999999999 - 12345678900000) inexact rounded', -2.34567890e+12, 9999999999999 - 12345678900000);
}
{
	use precision 12;
	AddTestCase('subx156:p12 r:HALF_UP (12345678900000 - 9999999999999) inexact rounded', 2.34567890000e+12, 12345678900000 - 9999999999999);
	AddTestCase('subx157:p12 r:HALF_UP (9999999999999 - 12345678900000) inexact rounded', -2.34567890000e+12, 9999999999999 - 12345678900000);
}
{
	use precision 15;
	AddTestCase('subx158:p15 r:HALF_UP (12345678900000 - 9999999999999)', 2345678900001, 12345678900000 - 9999999999999);
	AddTestCase('subx159:p15 r:HALF_UP (9999999999999 - 12345678900000)', -2345678900001, 9999999999999 - 12345678900000);
}
{
	use precision 9;
	// additional scaled arithmetic tests [0.97 problem]
	AddTestCase('subx160:p9 r:HALF_UP (0 - .1)', -0.1, 0 - .1);
	AddTestCase('subx161:p9 r:HALF_UP (00 - .97983)', -0.97983, 00 - .97983);
	AddTestCase('subx162:p9 r:HALF_UP (0 - .9)', -0.9, 0 - .9);
	AddTestCase('subx163:p9 r:HALF_UP (0 - 0.102)', -0.102, 0 - 0.102);
	AddTestCase('subx164:p9 r:HALF_UP (0 - .4)', -0.4, 0 - .4);
	AddTestCase('subx165:p9 r:HALF_UP (0 - .307)', -0.307, 0 - .307);
	AddTestCase('subx166:p9 r:HALF_UP (0 - .43822)', -0.43822, 0 - .43822);
	AddTestCase('subx167:p9 r:HALF_UP (0 - .911)', -0.911, 0 - .911);
	AddTestCase('subx168:p9 r:HALF_UP (.0 - .02)', -0.02, .0 - .02);
	AddTestCase('subx169:p9 r:HALF_UP (00 - .392)', -0.392, 00 - .392);
	AddTestCase('subx170:p9 r:HALF_UP (0 - .26)', -0.26, 0 - .26);
	AddTestCase('subx171:p9 r:HALF_UP (0 - 0.51)', -0.51, 0 - 0.51);
	AddTestCase('subx172:p9 r:HALF_UP (0 - .2234)', -0.2234, 0 - .2234);
	AddTestCase('subx173:p9 r:HALF_UP (0 - .2)', -0.2, 0 - .2);
	AddTestCase('subx174:p9 r:HALF_UP (.0 - .0008)', -0.0008, .0 - .0008);
	// 0. on left
	AddTestCase('subx180:p9 r:HALF_UP (0.0 - -.1)', 0.1, 0.0 - -.1);
	AddTestCase('subx181:p9 r:HALF_UP (0.00 - -.97983)', 0.97983, 0.00 - -.97983);
	AddTestCase('subx182:p9 r:HALF_UP (0.0 - -.9)', 0.9, 0.0 - -.9);
	AddTestCase('subx183:p9 r:HALF_UP (0.0 - -0.102)', 0.102, 0.0 - -0.102);
	AddTestCase('subx184:p9 r:HALF_UP (0.0 - -.4)', 0.4, 0.0 - -.4);
	AddTestCase('subx185:p9 r:HALF_UP (0.0 - -.307)', 0.307, 0.0 - -.307);
	AddTestCase('subx186:p9 r:HALF_UP (0.0 - -.43822)', 0.43822, 0.0 - -.43822);
	AddTestCase('subx187:p9 r:HALF_UP (0.0 - -.911)', 0.911, 0.0 - -.911);
	AddTestCase('subx188:p9 r:HALF_UP (0.0 - -.02)', 0.02, 0.0 - -.02);
	AddTestCase('subx189:p9 r:HALF_UP (0.00 - -.392)', 0.392, 0.00 - -.392);
	AddTestCase('subx190:p9 r:HALF_UP (0.0 - -.26)', 0.26, 0.0 - -.26);
	AddTestCase('subx191:p9 r:HALF_UP (0.0 - -0.51)', 0.51, 0.0 - -0.51);
	AddTestCase('subx192:p9 r:HALF_UP (0.0 - -.2234)', 0.2234, 0.0 - -.2234);
	AddTestCase('subx193:p9 r:HALF_UP (0.0 - -.2)', 0.2, 0.0 - -.2);
	AddTestCase('subx194:p9 r:HALF_UP (0.0 - -.0008)', 0.0008, 0.0 - -.0008);
	// negatives of same
	AddTestCase('subx200:p9 r:HALF_UP (0 - -.1)', 0.1, 0 - -.1);
	AddTestCase('subx201:p9 r:HALF_UP (00 - -.97983)', 0.97983, 00 - -.97983);
	AddTestCase('subx202:p9 r:HALF_UP (0 - -.9)', 0.9, 0 - -.9);
	AddTestCase('subx203:p9 r:HALF_UP (0 - -0.102)', 0.102, 0 - -0.102);
	AddTestCase('subx204:p9 r:HALF_UP (0 - -.4)', 0.4, 0 - -.4);
	AddTestCase('subx205:p9 r:HALF_UP (0 - -.307)', 0.307, 0 - -.307);
	AddTestCase('subx206:p9 r:HALF_UP (0 - -.43822)', 0.43822, 0 - -.43822);
	AddTestCase('subx207:p9 r:HALF_UP (0 - -.911)', 0.911, 0 - -.911);
	AddTestCase('subx208:p9 r:HALF_UP (.0 - -.02)', 0.02, .0 - -.02);
	AddTestCase('subx209:p9 r:HALF_UP (00 - -.392)', 0.392, 00 - -.392);
	AddTestCase('subx210:p9 r:HALF_UP (0 - -.26)', 0.26, 0 - -.26);
	AddTestCase('subx211:p9 r:HALF_UP (0 - -0.51)', 0.51, 0 - -0.51);
	AddTestCase('subx212:p9 r:HALF_UP (0 - -.2234)', 0.2234, 0 - -.2234);
	AddTestCase('subx213:p9 r:HALF_UP (0 - -.2)', 0.2, 0 - -.2);
	AddTestCase('subx214:p9 r:HALF_UP (.0 - -.0008)', 0.0008, .0 - -.0008);
	// more fixed, lhs swaps [really the same as testcases under add]
	AddTestCase('subx220:p9 r:HALF_UP (-56267e-12 - 0)', -5.6267e-8, -56267e-12 - 0);
	AddTestCase('subx221:p9 r:HALF_UP (-56267e-11 - 0)', -5.6267e-7, -56267e-11 - 0);
	AddTestCase('subx222:p9 r:HALF_UP (-56267e-10 - 0)', -0.0000056267, -56267e-10 - 0);
	AddTestCase('subx223:p9 r:HALF_UP (-56267e-9 - 0)', -0.000056267, -56267e-9 - 0);
	AddTestCase('subx224:p9 r:HALF_UP (-56267e-8 - 0)', -0.00056267, -56267e-8 - 0);
	AddTestCase('subx225:p9 r:HALF_UP (-56267e-7 - 0)', -0.0056267, -56267e-7 - 0);
	AddTestCase('subx226:p9 r:HALF_UP (-56267e-6 - 0)', -0.056267, -56267e-6 - 0);
	AddTestCase('subx227:p9 r:HALF_UP (-56267e-5 - 0)', -0.56267, -56267e-5 - 0);
	AddTestCase('subx228:p9 r:HALF_UP (-56267e-2 - 0)', -562.67, -56267e-2 - 0);
	AddTestCase('subx229:p9 r:HALF_UP (-56267e-1 - 0)', -5626.7, -56267e-1 - 0);
	AddTestCase('subx230:p9 r:HALF_UP (-56267e-0 - 0)', -56267, -56267e-0 - 0);
	// symmetry ...
	AddTestCase('subx240:p9 r:HALF_UP (0 - -56267e-12)', 5.6267e-8, 0 - -56267e-12);
	AddTestCase('subx241:p9 r:HALF_UP (0 - -56267e-11)', 5.6267e-7, 0 - -56267e-11);
	AddTestCase('subx242:p9 r:HALF_UP (0 - -56267e-10)', 0.0000056267, 0 - -56267e-10);
	AddTestCase('subx243:p9 r:HALF_UP (0 - -56267e-9)', 0.000056267, 0 - -56267e-9);
	AddTestCase('subx244:p9 r:HALF_UP (0 - -56267e-8)', 0.00056267, 0 - -56267e-8);
	AddTestCase('subx245:p9 r:HALF_UP (0 - -56267e-7)', 0.0056267, 0 - -56267e-7);
	AddTestCase('subx246:p9 r:HALF_UP (0 - -56267e-6)', 0.056267, 0 - -56267e-6);
	AddTestCase('subx247:p9 r:HALF_UP (0 - -56267e-5)', 0.56267, 0 - -56267e-5);
	AddTestCase('subx248:p9 r:HALF_UP (0 - -56267e-2)', 562.67, 0 - -56267e-2);
	AddTestCase('subx249:p9 r:HALF_UP (0 - -56267e-1)', 5626.7, 0 - -56267e-1);
	AddTestCase('subx250:p9 r:HALF_UP (0 - -56267e-0)', 56267, 0 - -56267e-0);
	// now some more from the 'new' add
}
{
	use precision 9;
	AddTestCase('subx301:p9 r:HALF_UP (1.23456789 - 1.00000000)', 0.23456789, 1.23456789 - 1.00000000);
	AddTestCase('subx302:p9 r:HALF_UP (1.23456789 - 1.00000011)', 0.23456778, 1.23456789 - 1.00000011);
	AddTestCase('subx311:p9 r:HALF_UP (0.4444444444 - 0.5555555555) inexact rounded', -0.111111111, 0.4444444444 - 0.5555555555);
	AddTestCase('subx312:p9 r:HALF_UP (0.4444444440 - 0.5555555555) inexact rounded', -0.111111112, 0.4444444440 - 0.5555555555);
	AddTestCase('subx313:p9 r:HALF_UP (0.4444444444 - 0.5555555550) inexact rounded', -0.111111111, 0.4444444444 - 0.5555555550);
	AddTestCase('subx314:p9 r:HALF_UP (0.44444444449 - 0) inexact rounded', 0.444444444, 0.44444444449 - 0);
	AddTestCase('subx315:p9 r:HALF_UP (0.444444444499 - 0) inexact rounded', 0.444444444, 0.444444444499 - 0);
	AddTestCase('subx316:p9 r:HALF_UP (0.4444444444999 - 0) inexact rounded', 0.444444444, 0.4444444444999 - 0);
	AddTestCase('subx317:p9 r:HALF_UP (0.4444444445000 - 0) inexact rounded', 0.444444445, 0.4444444445000 - 0);
	AddTestCase('subx318:p9 r:HALF_UP (0.4444444445001 - 0) inexact rounded', 0.444444445, 0.4444444445001 - 0);
	AddTestCase('subx319:p9 r:HALF_UP (0.444444444501 - 0) inexact rounded', 0.444444445, 0.444444444501 - 0);
	AddTestCase('subx320:p9 r:HALF_UP (0.44444444451 - 0) inexact rounded', 0.444444445, 0.44444444451 - 0);
	// some carrying effects
	AddTestCase('subx321:p9 r:HALF_UP (0.9998 - 0.0000)', 0.9998, 0.9998 - 0.0000);
	AddTestCase('subx322:p9 r:HALF_UP (0.9998 - 0.0001)', 0.9997, 0.9998 - 0.0001);
	AddTestCase('subx323:p9 r:HALF_UP (0.9998 - 0.0002)', 0.9996, 0.9998 - 0.0002);
	AddTestCase('subx324:p9 r:HALF_UP (0.9998 - 0.0003)', 0.9995, 0.9998 - 0.0003);
	AddTestCase('subx325:p9 r:HALF_UP (0.9998 - -0.0000)', 0.9998, 0.9998 - -0.0000);
	AddTestCase('subx326:p9 r:HALF_UP (0.9998 - -0.0001)', 0.9999, 0.9998 - -0.0001);
	AddTestCase('subx327:p9 r:HALF_UP (0.9998 - -0.0002)', 1.0000, 0.9998 - -0.0002);
	AddTestCase('subx328:p9 r:HALF_UP (0.9998 - -0.0003)', 1.0001, 0.9998 - -0.0003);
	AddTestCase('subx330:p9 r:HALF_UP (70 - 10000e+9) inexact rounded', -1.00000000e+13, 70 - 10000e+9);
	AddTestCase('subx331:p9 r:HALF_UP (700 - 10000e+9) inexact rounded', -1.00000000e+13, 700 - 10000e+9);
	AddTestCase('subx332:p9 r:HALF_UP (7000 - 10000e+9) inexact rounded', -9.99999999e+12, 7000 - 10000e+9);
	AddTestCase('subx333:p9 r:HALF_UP (70000 - 10000e+9) rounded', -9.99999993e+12, 70000 - 10000e+9);
	AddTestCase('subx334:p9 r:HALF_UP (700000 - 10000e+9) rounded', -9.99999930e+12, 700000 - 10000e+9);
	AddTestCase('subx335:p9 r:HALF_UP (7000000 - 10000e+9) rounded', -9.99999300e+12, 7000000 - 10000e+9);
	// symmetry:
	AddTestCase('subx340:p9 r:HALF_UP (10000e+9 - 70) inexact rounded', 1.00000000e+13, 10000e+9 - 70);
	AddTestCase('subx341:p9 r:HALF_UP (10000e+9 - 700) inexact rounded', 1.00000000e+13, 10000e+9 - 700);
	AddTestCase('subx342:p9 r:HALF_UP (10000e+9 - 7000) inexact rounded', 9.99999999e+12, 10000e+9 - 7000);
	AddTestCase('subx343:p9 r:HALF_UP (10000e+9 - 70000) rounded', 9.99999993e+12, 10000e+9 - 70000);
	AddTestCase('subx344:p9 r:HALF_UP (10000e+9 - 700000) rounded', 9.99999930e+12, 10000e+9 - 700000);
	AddTestCase('subx345:p9 r:HALF_UP (10000e+9 - 7000000) rounded', 9.99999300e+12, 10000e+9 - 7000000);
	// same, higher precision
}
{
	use precision 15;
	AddTestCase('subx346:p15 r:HALF_UP (10000e+9 - 7)', 9999999999993, 10000e+9 - 7);
	AddTestCase('subx347:p15 r:HALF_UP (10000e+9 - 70)', 9999999999930, 10000e+9 - 70);
	AddTestCase('subx348:p15 r:HALF_UP (10000e+9 - 700)', 9999999999300, 10000e+9 - 700);
	AddTestCase('subx349:p15 r:HALF_UP (10000e+9 - 7000)', 9999999993000, 10000e+9 - 7000);
	AddTestCase('subx350:p15 r:HALF_UP (10000e+9 - 70000)', 9999999930000, 10000e+9 - 70000);
	AddTestCase('subx351:p15 r:HALF_UP (10000e+9 - 700000)', 9999999300000, 10000e+9 - 700000);
	AddTestCase('subx352:p15 r:HALF_UP (7 - 10000e+9)', -9999999999993, 7 - 10000e+9);
	AddTestCase('subx353:p15 r:HALF_UP (70 - 10000e+9)', -9999999999930, 70 - 10000e+9);
	AddTestCase('subx354:p15 r:HALF_UP (700 - 10000e+9)', -9999999999300, 700 - 10000e+9);
	AddTestCase('subx355:p15 r:HALF_UP (7000 - 10000e+9)', -9999999993000, 7000 - 10000e+9);
	AddTestCase('subx356:p15 r:HALF_UP (70000 - 10000e+9)', -9999999930000, 70000 - 10000e+9);
	AddTestCase('subx357:p15 r:HALF_UP (700000 - 10000e+9)', -9999999300000, 700000 - 10000e+9);
	// zero preservation
}
{
	use precision 6;
	AddTestCase('subx360:p6 r:HALF_UP (10000e+9 - 70000) inexact rounded', 1.00000e+13, 10000e+9 - 70000);
	AddTestCase('subx361:p6 r:HALF_UP (1 - 0.0001)', 0.9999, 1 - 0.0001);
	AddTestCase('subx362:p6 r:HALF_UP (1 - 0.00001)', 0.99999, 1 - 0.00001);
	AddTestCase('subx363:p6 r:HALF_UP (1 - 0.000001)', 0.999999, 1 - 0.000001);
	AddTestCase('subx364:p6 r:HALF_UP (1 - 0.0000001) inexact rounded', 1.00000, 1 - 0.0000001);
	AddTestCase('subx365:p6 r:HALF_UP (1 - 0.00000001) inexact rounded', 1.00000, 1 - 0.00000001);
	// some funny zeros [in case of bad signum]
	AddTestCase('subx370:p6 r:HALF_UP (1 - 0)', 1, 1 - 0);
	AddTestCase('subx371:p6 r:HALF_UP (1 - 0.)', 1, 1 - 0.);
	AddTestCase('subx372:p6 r:HALF_UP (1 - .0)', 1.0, 1 - .0);
	AddTestCase('subx373:p6 r:HALF_UP (1 - 0.0)', 1.0, 1 - 0.0);
	AddTestCase('subx374:p6 r:HALF_UP (0 - 1)', -1, 0 - 1);
	AddTestCase('subx375:p6 r:HALF_UP (0. - 1)', -1, 0. - 1);
	AddTestCase('subx376:p6 r:HALF_UP (.0 - 1)', -1.0, .0 - 1);
	AddTestCase('subx377:p6 r:HALF_UP (0.0 - 1)', -1.0, 0.0 - 1);
}
{
	use precision 9;
	// leading 0 digit before round
	AddTestCase('subx910:p9 r:HALF_UP (-103519362 - -51897955.3)', -51621406.7, -103519362 - -51897955.3);
	AddTestCase('subx911:p9 r:HALF_UP (159579.444 - 89827.5229)', 69751.9211, 159579.444 - 89827.5229);
	AddTestCase('subx920:p9 r:HALF_UP (333.123456 - 33.1234566) inexact rounded', 299.999999, 333.123456 - 33.1234566);
	AddTestCase('subx921:p9 r:HALF_UP (333.123456 - 33.1234565) inexact rounded', 300.000000, 333.123456 - 33.1234565);
	AddTestCase('subx922:p9 r:HALF_UP (133.123456 - 33.1234565)', 99.9999995, 133.123456 - 33.1234565);
	AddTestCase('subx923:p9 r:HALF_UP (133.123456 - 33.1234564)', 99.9999996, 133.123456 - 33.1234564);
	AddTestCase('subx924:p9 r:HALF_UP (133.123456 - 33.1234540) rounded', 100.000002, 133.123456 - 33.1234540);
	AddTestCase('subx925:p9 r:HALF_UP (133.123456 - 43.1234560)', 90.0000000, 133.123456 - 43.1234560);
	AddTestCase('subx926:p9 r:HALF_UP (133.123456 - 43.1234561)', 89.9999999, 133.123456 - 43.1234561);
	AddTestCase('subx927:p9 r:HALF_UP (133.123456 - 43.1234566)', 89.9999994, 133.123456 - 43.1234566);
	AddTestCase('subx928:p9 r:HALF_UP (101.123456 - 91.1234566)', 9.9999994, 101.123456 - 91.1234566);
	AddTestCase('subx929:p9 r:HALF_UP (101.123456 - 99.1234566)', 1.9999994, 101.123456 - 99.1234566);
	// more of the same; probe for cluster boundary problems
}
{
	use precision 1;
	AddTestCase('subx930:p1 r:HALF_UP (11 - 2)', 9, 11 - 2);
}
{
	use precision 2;
	AddTestCase('subx932:p2 r:HALF_UP (101 - 2)', 99, 101 - 2);
}
{
	use precision 3;
	AddTestCase('subx934:p3 r:HALF_UP (101 - 2.1)', 98.9, 101 - 2.1);
	AddTestCase('subx935:p3 r:HALF_UP (101 - 92.01)', 8.99, 101 - 92.01);
}
{
	use precision 4;
	AddTestCase('subx936:p4 r:HALF_UP (101 - 2.01)', 98.99, 101 - 2.01);
	AddTestCase('subx937:p4 r:HALF_UP (101 - 92.01)', 8.99, 101 - 92.01);
	AddTestCase('subx938:p4 r:HALF_UP (101 - 92.006)', 8.994, 101 - 92.006);
}
{
	use precision 5;
	AddTestCase('subx939:p5 r:HALF_UP (101 - 2.001)', 98.999, 101 - 2.001);
	AddTestCase('subx940:p5 r:HALF_UP (101 - 92.001)', 8.999, 101 - 92.001);
	AddTestCase('subx941:p5 r:HALF_UP (101 - 92.0006)', 8.9994, 101 - 92.0006);
}
{
	use precision 6;
	AddTestCase('subx942:p6 r:HALF_UP (101 - 2.0001)', 98.9999, 101 - 2.0001);
	AddTestCase('subx943:p6 r:HALF_UP (101 - 92.0001)', 8.9999, 101 - 92.0001);
	AddTestCase('subx944:p6 r:HALF_UP (101 - 92.00006)', 8.99994, 101 - 92.00006);
}
{
	use precision 7;
	AddTestCase('subx945:p7 r:HALF_UP (101 - 2.00001)', 98.99999, 101 - 2.00001);
	AddTestCase('subx946:p7 r:HALF_UP (101 - 92.00001)', 8.99999, 101 - 92.00001);
	AddTestCase('subx947:p7 r:HALF_UP (101 - 92.000006)', 8.999994, 101 - 92.000006);
}
{
	use precision 8;
	AddTestCase('subx948:p8 r:HALF_UP (101 - 2.000001)', 98.999999, 101 - 2.000001);
	AddTestCase('subx949:p8 r:HALF_UP (101 - 92.000001)', 8.999999, 101 - 92.000001);
	AddTestCase('subx950:p8 r:HALF_UP (101 - 92.0000006)', 8.9999994, 101 - 92.0000006);
}
{
	use precision 9;
	AddTestCase('subx951:p9 r:HALF_UP (101 - 2.0000001)', 98.9999999, 101 - 2.0000001);
	AddTestCase('subx952:p9 r:HALF_UP (101 - 92.0000001)', 8.9999999, 101 - 92.0000001);
	AddTestCase('subx953:p9 r:HALF_UP (101 - 92.00000006)', 8.99999994, 101 - 92.00000006);
}
{
	use precision 9;
	// more lhs swaps [were fixed]
	AddTestCase('subx390:p9 r:HALF_UP (-56267e-10 - 0)', -0.0000056267, -56267e-10 - 0);
	AddTestCase('subx391:p9 r:HALF_UP (-56267e-6 - 0)', -0.056267, -56267e-6 - 0);
	AddTestCase('subx392:p9 r:HALF_UP (-56267e-5 - 0)', -0.56267, -56267e-5 - 0);
	AddTestCase('subx393:p9 r:HALF_UP (-56267e-4 - 0)', -5.6267, -56267e-4 - 0);
	AddTestCase('subx394:p9 r:HALF_UP (-56267e-3 - 0)', -56.267, -56267e-3 - 0);
	AddTestCase('subx395:p9 r:HALF_UP (-56267e-2 - 0)', -562.67, -56267e-2 - 0);
	AddTestCase('subx396:p9 r:HALF_UP (-56267e-1 - 0)', -5626.7, -56267e-1 - 0);
	AddTestCase('subx397:p9 r:HALF_UP (-56267e-0 - 0)', -56267, -56267e-0 - 0);
	AddTestCase('subx398:p9 r:HALF_UP (-5e-10 - 0)', -5e-10, -5e-10 - 0);
	AddTestCase('subx399:p9 r:HALF_UP (-5e-7 - 0)', -5e-7, -5e-7 - 0);
	AddTestCase('subx400:p9 r:HALF_UP (-5e-6 - 0)', -0.000005, -5e-6 - 0);
	AddTestCase('subx401:p9 r:HALF_UP (-5e-5 - 0)', -0.00005, -5e-5 - 0);
	AddTestCase('subx402:p9 r:HALF_UP (-5e-4 - 0)', -0.0005, -5e-4 - 0);
	AddTestCase('subx403:p9 r:HALF_UP (-5e-1 - 0)', -0.5, -5e-1 - 0);
	AddTestCase('subx404:p9 r:HALF_UP (-5e0 - 0)', -5, -5e0 - 0);
	AddTestCase('subx405:p9 r:HALF_UP (-5e1 - 0)', -50, -5e1 - 0);
	AddTestCase('subx406:p9 r:HALF_UP (-5e5 - 0)', -500000, -5e5 - 0);
	AddTestCase('subx407:p9 r:HALF_UP (-5e8 - 0)', -500000000, -5e8 - 0);
	AddTestCase('subx408:p9 r:HALF_UP (-5e9 - 0) rounded', -5.00000000e+9, -5e9 - 0);
	AddTestCase('subx409:p9 r:HALF_UP (-5e10 - 0) rounded', -5.00000000e+10, -5e10 - 0);
	AddTestCase('subx410:p9 r:HALF_UP (-5e11 - 0) rounded', -5.00000000e+11, -5e11 - 0);
	AddTestCase('subx411:p9 r:HALF_UP (-5e100 - 0) rounded', -5.00000000e+100, -5e100 - 0);
	// more rhs swaps [were fixed]
	AddTestCase('subx420:p9 r:HALF_UP (0 - -56267e-10)', 0.0000056267, 0 - -56267e-10);
	AddTestCase('subx421:p9 r:HALF_UP (0 - -56267e-6)', 0.056267, 0 - -56267e-6);
	AddTestCase('subx422:p9 r:HALF_UP (0 - -56267e-5)', 0.56267, 0 - -56267e-5);
	AddTestCase('subx423:p9 r:HALF_UP (0 - -56267e-4)', 5.6267, 0 - -56267e-4);
	AddTestCase('subx424:p9 r:HALF_UP (0 - -56267e-3)', 56.267, 0 - -56267e-3);
	AddTestCase('subx425:p9 r:HALF_UP (0 - -56267e-2)', 562.67, 0 - -56267e-2);
	AddTestCase('subx426:p9 r:HALF_UP (0 - -56267e-1)', 5626.7, 0 - -56267e-1);
	AddTestCase('subx427:p9 r:HALF_UP (0 - -56267e-0)', 56267, 0 - -56267e-0);
	AddTestCase('subx428:p9 r:HALF_UP (0 - -5e-10)', 5e-10, 0 - -5e-10);
	AddTestCase('subx429:p9 r:HALF_UP (0 - -5e-7)', 5e-7, 0 - -5e-7);
	AddTestCase('subx430:p9 r:HALF_UP (0 - -5e-6)', 0.000005, 0 - -5e-6);
	AddTestCase('subx431:p9 r:HALF_UP (0 - -5e-5)', 0.00005, 0 - -5e-5);
	AddTestCase('subx432:p9 r:HALF_UP (0 - -5e-4)', 0.0005, 0 - -5e-4);
	AddTestCase('subx433:p9 r:HALF_UP (0 - -5e-1)', 0.5, 0 - -5e-1);
	AddTestCase('subx434:p9 r:HALF_UP (0 - -5e0)', 5, 0 - -5e0);
	AddTestCase('subx435:p9 r:HALF_UP (0 - -5e1)', 50, 0 - -5e1);
	AddTestCase('subx436:p9 r:HALF_UP (0 - -5e5)', 500000, 0 - -5e5);
	AddTestCase('subx437:p9 r:HALF_UP (0 - -5e8)', 500000000, 0 - -5e8);
	AddTestCase('subx438:p9 r:HALF_UP (0 - -5e9) rounded', 5.00000000e+9, 0 - -5e9);
	AddTestCase('subx439:p9 r:HALF_UP (0 - -5e10) rounded', 5.00000000e+10, 0 - -5e10);
	AddTestCase('subx440:p9 r:HALF_UP (0 - -5e11) rounded', 5.00000000e+11, 0 - -5e11);
	AddTestCase('subx441:p9 r:HALF_UP (0 - -5e100) rounded', 5.00000000e+100, 0 - -5e100);
	// try borderline precision, with carries, etc.
}
{
	use precision 15;
	AddTestCase('subx461:p15 r:HALF_UP (1e+12 - 1)', 999999999999, 1e+12 - 1);
	AddTestCase('subx462:p15 r:HALF_UP (1e+12 - -1.11)', 1000000000001.11, 1e+12 - -1.11);
	AddTestCase('subx463:p15 r:HALF_UP (1.11 - -1e+12)', 1000000000001.11, 1.11 - -1e+12);
	AddTestCase('subx464:p15 r:HALF_UP (-1 - -1e+12)', 999999999999, -1 - -1e+12);
	AddTestCase('subx465:p15 r:HALF_UP (7e+12 - 1)', 6999999999999, 7e+12 - 1);
	AddTestCase('subx466:p15 r:HALF_UP (7e+12 - -1.11)', 7000000000001.11, 7e+12 - -1.11);
	AddTestCase('subx467:p15 r:HALF_UP (1.11 - -7e+12)', 7000000000001.11, 1.11 - -7e+12);
	AddTestCase('subx468:p15 r:HALF_UP (-1 - -7e+12)', 6999999999999, -1 - -7e+12);
	//                 123456789012345       123456789012345      1 23456789012345
	AddTestCase('subx470:p15 r:HALF_UP (0.444444444444444 - -0.555555555555563) inexact rounded', 1.00000000000001, 0.444444444444444 - -0.555555555555563);
	AddTestCase('subx471:p15 r:HALF_UP (0.444444444444444 - -0.555555555555562) inexact rounded', 1.00000000000001, 0.444444444444444 - -0.555555555555562);
	AddTestCase('subx472:p15 r:HALF_UP (0.444444444444444 - -0.555555555555561) inexact rounded', 1.00000000000001, 0.444444444444444 - -0.555555555555561);
	AddTestCase('subx473:p15 r:HALF_UP (0.444444444444444 - -0.555555555555560) inexact rounded', 1.00000000000000, 0.444444444444444 - -0.555555555555560);
	AddTestCase('subx474:p15 r:HALF_UP (0.444444444444444 - -0.555555555555559) inexact rounded', 1.00000000000000, 0.444444444444444 - -0.555555555555559);
	AddTestCase('subx475:p15 r:HALF_UP (0.444444444444444 - -0.555555555555558) inexact rounded', 1.00000000000000, 0.444444444444444 - -0.555555555555558);
	AddTestCase('subx476:p15 r:HALF_UP (0.444444444444444 - -0.555555555555557) inexact rounded', 1.00000000000000, 0.444444444444444 - -0.555555555555557);
	AddTestCase('subx477:p15 r:HALF_UP (0.444444444444444 - -0.555555555555556) rounded', 1.00000000000000, 0.444444444444444 - -0.555555555555556);
	AddTestCase('subx478:p15 r:HALF_UP (0.444444444444444 - -0.555555555555555)', 0.999999999999999, 0.444444444444444 - -0.555555555555555);
	AddTestCase('subx479:p15 r:HALF_UP (0.444444444444444 - -0.555555555555554)', 0.999999999999998, 0.444444444444444 - -0.555555555555554);
	AddTestCase('subx480:p15 r:HALF_UP (0.444444444444444 - -0.555555555555553)', 0.999999999999997, 0.444444444444444 - -0.555555555555553);
	AddTestCase('subx481:p15 r:HALF_UP (0.444444444444444 - -0.555555555555552)', 0.999999999999996, 0.444444444444444 - -0.555555555555552);
	AddTestCase('subx482:p15 r:HALF_UP (0.444444444444444 - -0.555555555555551)', 0.999999999999995, 0.444444444444444 - -0.555555555555551);
	AddTestCase('subx483:p15 r:HALF_UP (0.444444444444444 - -0.555555555555550)', 0.999999999999994, 0.444444444444444 - -0.555555555555550);
	// and some more, including residue effects and different roundings
}
{
	use precision 9;
	{
		use rounding HALF_UP;
		AddTestCase('subx500:p9 r:HALF_UP (123456789 - 0)', 123456789, 123456789 - 0);
		AddTestCase('subx501:p9 r:HALF_UP (123456789 - 0.000000001) inexact rounded', 123456789, 123456789 - 0.000000001);
		AddTestCase('subx502:p9 r:HALF_UP (123456789 - 0.000001) inexact rounded', 123456789, 123456789 - 0.000001);
		AddTestCase('subx503:p9 r:HALF_UP (123456789 - 0.1) inexact rounded', 123456789, 123456789 - 0.1);
		AddTestCase('subx504:p9 r:HALF_UP (123456789 - 0.4) inexact rounded', 123456789, 123456789 - 0.4);
		AddTestCase('subx505:p9 r:HALF_UP (123456789 - 0.49) inexact rounded', 123456789, 123456789 - 0.49);
		AddTestCase('subx506:p9 r:HALF_UP (123456789 - 0.499999) inexact rounded', 123456789, 123456789 - 0.499999);
		AddTestCase('subx507:p9 r:HALF_UP (123456789 - 0.499999999) inexact rounded', 123456789, 123456789 - 0.499999999);
		AddTestCase('subx508:p9 r:HALF_UP (123456789 - 0.5) inexact rounded', 123456789, 123456789 - 0.5);
		AddTestCase('subx509:p9 r:HALF_UP (123456789 - 0.500000001) inexact rounded', 123456788, 123456789 - 0.500000001);
		AddTestCase('subx510:p9 r:HALF_UP (123456789 - 0.500001) inexact rounded', 123456788, 123456789 - 0.500001);
		AddTestCase('subx511:p9 r:HALF_UP (123456789 - 0.51) inexact rounded', 123456788, 123456789 - 0.51);
		AddTestCase('subx512:p9 r:HALF_UP (123456789 - 0.6) inexact rounded', 123456788, 123456789 - 0.6);
		AddTestCase('subx513:p9 r:HALF_UP (123456789 - 0.9) inexact rounded', 123456788, 123456789 - 0.9);
		AddTestCase('subx514:p9 r:HALF_UP (123456789 - 0.99999) inexact rounded', 123456788, 123456789 - 0.99999);
		AddTestCase('subx515:p9 r:HALF_UP (123456789 - 0.999999999) inexact rounded', 123456788, 123456789 - 0.999999999);
		AddTestCase('subx516:p9 r:HALF_UP (123456789 - 1)', 123456788, 123456789 - 1);
		AddTestCase('subx517:p9 r:HALF_UP (123456789 - 1.000000001) inexact rounded', 123456788, 123456789 - 1.000000001);
		AddTestCase('subx518:p9 r:HALF_UP (123456789 - 1.00001) inexact rounded', 123456788, 123456789 - 1.00001);
		AddTestCase('subx519:p9 r:HALF_UP (123456789 - 1.1) inexact rounded', 123456788, 123456789 - 1.1);
	}
	{
		use rounding HALF_EVEN;
		AddTestCase('subx520:p9 r:HALF_EVEN (123456789 - 0)', 123456789, 123456789 - 0);
		AddTestCase('subx521:p9 r:HALF_EVEN (123456789 - 0.000000001) inexact rounded', 123456789, 123456789 - 0.000000001);
		AddTestCase('subx522:p9 r:HALF_EVEN (123456789 - 0.000001) inexact rounded', 123456789, 123456789 - 0.000001);
		AddTestCase('subx523:p9 r:HALF_EVEN (123456789 - 0.1) inexact rounded', 123456789, 123456789 - 0.1);
		AddTestCase('subx524:p9 r:HALF_EVEN (123456789 - 0.4) inexact rounded', 123456789, 123456789 - 0.4);
		AddTestCase('subx525:p9 r:HALF_EVEN (123456789 - 0.49) inexact rounded', 123456789, 123456789 - 0.49);
		AddTestCase('subx526:p9 r:HALF_EVEN (123456789 - 0.499999) inexact rounded', 123456789, 123456789 - 0.499999);
		AddTestCase('subx527:p9 r:HALF_EVEN (123456789 - 0.499999999) inexact rounded', 123456789, 123456789 - 0.499999999);
		AddTestCase('subx528:p9 r:HALF_EVEN (123456789 - 0.5) inexact rounded', 123456788, 123456789 - 0.5);
		AddTestCase('subx529:p9 r:HALF_EVEN (123456789 - 0.500000001) inexact rounded', 123456788, 123456789 - 0.500000001);
		AddTestCase('subx530:p9 r:HALF_EVEN (123456789 - 0.500001) inexact rounded', 123456788, 123456789 - 0.500001);
		AddTestCase('subx531:p9 r:HALF_EVEN (123456789 - 0.51) inexact rounded', 123456788, 123456789 - 0.51);
		AddTestCase('subx532:p9 r:HALF_EVEN (123456789 - 0.6) inexact rounded', 123456788, 123456789 - 0.6);
		AddTestCase('subx533:p9 r:HALF_EVEN (123456789 - 0.9) inexact rounded', 123456788, 123456789 - 0.9);
		AddTestCase('subx534:p9 r:HALF_EVEN (123456789 - 0.99999) inexact rounded', 123456788, 123456789 - 0.99999);
		AddTestCase('subx535:p9 r:HALF_EVEN (123456789 - 0.999999999) inexact rounded', 123456788, 123456789 - 0.999999999);
		AddTestCase('subx536:p9 r:HALF_EVEN (123456789 - 1)', 123456788, 123456789 - 1);
		AddTestCase('subx537:p9 r:HALF_EVEN (123456789 - 1.00000001) inexact rounded', 123456788, 123456789 - 1.00000001);
		AddTestCase('subx538:p9 r:HALF_EVEN (123456789 - 1.00001) inexact rounded', 123456788, 123456789 - 1.00001);
		AddTestCase('subx539:p9 r:HALF_EVEN (123456789 - 1.1) inexact rounded', 123456788, 123456789 - 1.1);
		// critical few with even bottom digit...
		AddTestCase('subx540:p9 r:HALF_EVEN (123456788 - 0.499999999) inexact rounded', 123456788, 123456788 - 0.499999999);
		AddTestCase('subx541:p9 r:HALF_EVEN (123456788 - 0.5) inexact rounded', 123456788, 123456788 - 0.5);
		AddTestCase('subx542:p9 r:HALF_EVEN (123456788 - 0.500000001) inexact rounded', 123456787, 123456788 - 0.500000001);
		// symmetry...
	}
	{
		use rounding HALF_UP;
		AddTestCase('subx600:p9 r:HALF_UP (0 - 123456789)', -123456789, 0 - 123456789);
		AddTestCase('subx601:p9 r:HALF_UP (0.000000001 - 123456789) inexact rounded', -123456789, 0.000000001 - 123456789);
		AddTestCase('subx602:p9 r:HALF_UP (0.000001 - 123456789) inexact rounded', -123456789, 0.000001 - 123456789);
		AddTestCase('subx603:p9 r:HALF_UP (0.1 - 123456789) inexact rounded', -123456789, 0.1 - 123456789);
		AddTestCase('subx604:p9 r:HALF_UP (0.4 - 123456789) inexact rounded', -123456789, 0.4 - 123456789);
		AddTestCase('subx605:p9 r:HALF_UP (0.49 - 123456789) inexact rounded', -123456789, 0.49 - 123456789);
		AddTestCase('subx606:p9 r:HALF_UP (0.499999 - 123456789) inexact rounded', -123456789, 0.499999 - 123456789);
		AddTestCase('subx607:p9 r:HALF_UP (0.499999999 - 123456789) inexact rounded', -123456789, 0.499999999 - 123456789);
		AddTestCase('subx608:p9 r:HALF_UP (0.5 - 123456789) inexact rounded', -123456789, 0.5 - 123456789);
		AddTestCase('subx609:p9 r:HALF_UP (0.500000001 - 123456789) inexact rounded', -123456788, 0.500000001 - 123456789);
		AddTestCase('subx610:p9 r:HALF_UP (0.500001 - 123456789) inexact rounded', -123456788, 0.500001 - 123456789);
		AddTestCase('subx611:p9 r:HALF_UP (0.51 - 123456789) inexact rounded', -123456788, 0.51 - 123456789);
		AddTestCase('subx612:p9 r:HALF_UP (0.6 - 123456789) inexact rounded', -123456788, 0.6 - 123456789);
		AddTestCase('subx613:p9 r:HALF_UP (0.9 - 123456789) inexact rounded', -123456788, 0.9 - 123456789);
		AddTestCase('subx614:p9 r:HALF_UP (0.99999 - 123456789) inexact rounded', -123456788, 0.99999 - 123456789);
		AddTestCase('subx615:p9 r:HALF_UP (0.999999999 - 123456789) inexact rounded', -123456788, 0.999999999 - 123456789);
		AddTestCase('subx616:p9 r:HALF_UP (1 - 123456789)', -123456788, 1 - 123456789);
		AddTestCase('subx617:p9 r:HALF_UP (1.000000001 - 123456789) inexact rounded', -123456788, 1.000000001 - 123456789);
		AddTestCase('subx618:p9 r:HALF_UP (1.00001 - 123456789) inexact rounded', -123456788, 1.00001 - 123456789);
		AddTestCase('subx619:p9 r:HALF_UP (1.1 - 123456789) inexact rounded', -123456788, 1.1 - 123456789);
	}
	{
		use rounding HALF_EVEN;
		AddTestCase('subx620:p9 r:HALF_EVEN (0 - 123456789)', -123456789, 0 - 123456789);
		AddTestCase('subx621:p9 r:HALF_EVEN (0.000000001 - 123456789) inexact rounded', -123456789, 0.000000001 - 123456789);
		AddTestCase('subx622:p9 r:HALF_EVEN (0.000001 - 123456789) inexact rounded', -123456789, 0.000001 - 123456789);
		AddTestCase('subx623:p9 r:HALF_EVEN (0.1 - 123456789) inexact rounded', -123456789, 0.1 - 123456789);
		AddTestCase('subx624:p9 r:HALF_EVEN (0.4 - 123456789) inexact rounded', -123456789, 0.4 - 123456789);
		AddTestCase('subx625:p9 r:HALF_EVEN (0.49 - 123456789) inexact rounded', -123456789, 0.49 - 123456789);
		AddTestCase('subx626:p9 r:HALF_EVEN (0.499999 - 123456789) inexact rounded', -123456789, 0.499999 - 123456789);
		AddTestCase('subx627:p9 r:HALF_EVEN (0.499999999 - 123456789) inexact rounded', -123456789, 0.499999999 - 123456789);
		AddTestCase('subx628:p9 r:HALF_EVEN (0.5 - 123456789) inexact rounded', -123456788, 0.5 - 123456789);
		AddTestCase('subx629:p9 r:HALF_EVEN (0.500000001 - 123456789) inexact rounded', -123456788, 0.500000001 - 123456789);
		AddTestCase('subx630:p9 r:HALF_EVEN (0.500001 - 123456789) inexact rounded', -123456788, 0.500001 - 123456789);
		AddTestCase('subx631:p9 r:HALF_EVEN (0.51 - 123456789) inexact rounded', -123456788, 0.51 - 123456789);
		AddTestCase('subx632:p9 r:HALF_EVEN (0.6 - 123456789) inexact rounded', -123456788, 0.6 - 123456789);
		AddTestCase('subx633:p9 r:HALF_EVEN (0.9 - 123456789) inexact rounded', -123456788, 0.9 - 123456789);
		AddTestCase('subx634:p9 r:HALF_EVEN (0.99999 - 123456789) inexact rounded', -123456788, 0.99999 - 123456789);
		AddTestCase('subx635:p9 r:HALF_EVEN (0.999999999 - 123456789) inexact rounded', -123456788, 0.999999999 - 123456789);
		AddTestCase('subx636:p9 r:HALF_EVEN (1 - 123456789)', -123456788, 1 - 123456789);
		AddTestCase('subx637:p9 r:HALF_EVEN (1.00000001 - 123456789) inexact rounded', -123456788, 1.00000001 - 123456789);
		AddTestCase('subx638:p9 r:HALF_EVEN (1.00001 - 123456789) inexact rounded', -123456788, 1.00001 - 123456789);
		AddTestCase('subx639:p9 r:HALF_EVEN (1.1 - 123456789) inexact rounded', -123456788, 1.1 - 123456789);
		// critical few with even bottom digit...
		AddTestCase('subx640:p9 r:HALF_EVEN (0.499999999 - 123456788) inexact rounded', -123456788, 0.499999999 - 123456788);
		AddTestCase('subx641:p9 r:HALF_EVEN (0.5 - 123456788) inexact rounded', -123456788, 0.5 - 123456788);
		AddTestCase('subx642:p9 r:HALF_EVEN (0.500000001 - 123456788) inexact rounded', -123456787, 0.500000001 - 123456788);
		// lots of leading zeros in intermediate result, and showing effects of
		// input rounding would have affected the following
		{
			use precision 9;
			{
				use rounding HALF_UP;
				AddTestCase('subx670:p9 r:HALF_UP (123456789 - 123456788.1)', 0.9, 123456789 - 123456788.1);
				AddTestCase('subx671:p9 r:HALF_UP (123456789 - 123456788.9)', 0.1, 123456789 - 123456788.9);
				AddTestCase('subx672:p9 r:HALF_UP (123456789 - 123456789.1)', -0.1, 123456789 - 123456789.1);
				AddTestCase('subx673:p9 r:HALF_UP (123456789 - 123456789.5)', -0.5, 123456789 - 123456789.5);
				AddTestCase('subx674:p9 r:HALF_UP (123456789 - 123456789.9)', -0.9, 123456789 - 123456789.9);
			}
			{
				use rounding HALF_EVEN;
				AddTestCase('subx680:p9 r:HALF_EVEN (123456789 - 123456788.1)', 0.9, 123456789 - 123456788.1);
				AddTestCase('subx681:p9 r:HALF_EVEN (123456789 - 123456788.9)', 0.1, 123456789 - 123456788.9);
				AddTestCase('subx682:p9 r:HALF_EVEN (123456789 - 123456789.1)', -0.1, 123456789 - 123456789.1);
				AddTestCase('subx683:p9 r:HALF_EVEN (123456789 - 123456789.5)', -0.5, 123456789 - 123456789.5);
				AddTestCase('subx684:p9 r:HALF_EVEN (123456789 - 123456789.9)', -0.9, 123456789 - 123456789.9);
				AddTestCase('subx685:p9 r:HALF_EVEN (123456788 - 123456787.1)', 0.9, 123456788 - 123456787.1);
				AddTestCase('subx686:p9 r:HALF_EVEN (123456788 - 123456787.9)', 0.1, 123456788 - 123456787.9);
				AddTestCase('subx687:p9 r:HALF_EVEN (123456788 - 123456788.1)', -0.1, 123456788 - 123456788.1);
				AddTestCase('subx688:p9 r:HALF_EVEN (123456788 - 123456788.5)', -0.5, 123456788 - 123456788.5);
				AddTestCase('subx689:p9 r:HALF_EVEN (123456788 - 123456788.9)', -0.9, 123456788 - 123456788.9);
				// input preparation tests
			}
			{
				use rounding HALF_UP;
				{
					use precision 3;
					AddTestCase('subx700:p3 r:HALF_UP (12345678900000 - -9999999999999) inexact rounded', 2.23e+13, 12345678900000 - -9999999999999);
					AddTestCase('subx701:p3 r:HALF_UP (9999999999999 - -12345678900000) inexact rounded', 2.23e+13, 9999999999999 - -12345678900000);
					AddTestCase('subx702:p3 r:HALF_UP (12e+3 - -3456) inexact rounded', 1.55e+4, 12e+3 - -3456);
					AddTestCase('subx703:p3 r:HALF_UP (12e+3 - -3446) inexact rounded', 1.54e+4, 12e+3 - -3446);
					AddTestCase('subx704:p3 r:HALF_UP (12e+3 - -3454) inexact rounded', 1.55e+4, 12e+3 - -3454);
					AddTestCase('subx705:p3 r:HALF_UP (12e+3 - -3444) inexact rounded', 1.54e+4, 12e+3 - -3444);
					AddTestCase('subx706:p3 r:HALF_UP (3456 - -12e+3) inexact rounded', 1.55e+4, 3456 - -12e+3);
					AddTestCase('subx707:p3 r:HALF_UP (3446 - -12e+3) inexact rounded', 1.54e+4, 3446 - -12e+3);
					AddTestCase('subx708:p3 r:HALF_UP (3454 - -12e+3) inexact rounded', 1.55e+4, 3454 - -12e+3);
					AddTestCase('subx709:p3 r:HALF_UP (3444 - -12e+3) inexact rounded', 1.54e+4, 3444 - -12e+3);
					// overflow and underflow tests [subnormals now possible]
				}
				{
					use precision 9;
					{
						use rounding HALF_UP;
						{
							use precision 3;
							// [more below]
							// long operand checks
						}
						{
							use precision 9;
							AddTestCase('sub731:p9 r:HALF_UP (12345678000 - 0) rounded', 1.23456780e+10, 12345678000 - 0);
							AddTestCase('sub732:p9 r:HALF_UP (0 - 12345678000) rounded', -1.23456780e+10, 0 - 12345678000);
							AddTestCase('sub733:p9 r:HALF_UP (1234567800 - 0) rounded', 1.23456780e+9, 1234567800 - 0);
							AddTestCase('sub734:p9 r:HALF_UP (0 - 1234567800) rounded', -1.23456780e+9, 0 - 1234567800);
							AddTestCase('sub735:p9 r:HALF_UP (1234567890 - 0) rounded', 1.23456789e+9, 1234567890 - 0);
							AddTestCase('sub736:p9 r:HALF_UP (0 - 1234567890) rounded', -1.23456789e+9, 0 - 1234567890);
							AddTestCase('sub737:p9 r:HALF_UP (1234567891 - 0) inexact rounded', 1.23456789e+9, 1234567891 - 0);
							AddTestCase('sub738:p9 r:HALF_UP (0 - 1234567891) inexact rounded', -1.23456789e+9, 0 - 1234567891);
							AddTestCase('sub739:p9 r:HALF_UP (12345678901 - 0) inexact rounded', 1.23456789e+10, 12345678901 - 0);
							AddTestCase('sub740:p9 r:HALF_UP (0 - 12345678901) inexact rounded', -1.23456789e+10, 0 - 12345678901);
							AddTestCase('sub741:p9 r:HALF_UP (1234567896 - 0) inexact rounded', 1.23456790e+9, 1234567896 - 0);
							AddTestCase('sub742:p9 r:HALF_UP (0 - 1234567896) inexact rounded', -1.23456790e+9, 0 - 1234567896);
						}
						{
							use precision 15;
							AddTestCase('sub751:p15 r:HALF_UP (12345678000 - 0)', 12345678000, 12345678000 - 0);
							AddTestCase('sub752:p15 r:HALF_UP (0 - 12345678000)', -12345678000, 0 - 12345678000);
							AddTestCase('sub753:p15 r:HALF_UP (1234567800 - 0)', 1234567800, 1234567800 - 0);
							AddTestCase('sub754:p15 r:HALF_UP (0 - 1234567800)', -1234567800, 0 - 1234567800);
							AddTestCase('sub755:p15 r:HALF_UP (1234567890 - 0)', 1234567890, 1234567890 - 0);
							AddTestCase('sub756:p15 r:HALF_UP (0 - 1234567890)', -1234567890, 0 - 1234567890);
							AddTestCase('sub757:p15 r:HALF_UP (1234567891 - 0)', 1234567891, 1234567891 - 0);
							AddTestCase('sub758:p15 r:HALF_UP (0 - 1234567891)', -1234567891, 0 - 1234567891);
							AddTestCase('sub759:p15 r:HALF_UP (12345678901 - 0)', 12345678901, 12345678901 - 0);
							AddTestCase('sub760:p15 r:HALF_UP (0 - 12345678901)', -12345678901, 0 - 12345678901);
							AddTestCase('sub761:p15 r:HALF_UP (1234567896 - 0)', 1234567896, 1234567896 - 0);
							AddTestCase('sub762:p15 r:HALF_UP (0 - 1234567896)', -1234567896, 0 - 1234567896);
							// specials
							AddTestCase('subx780:p15 r:HALF_UP (decimal.NEGATIVE_INFINITY - decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY - decimal.POSITIVE_INFINITY);
							AddTestCase('subx781:p15 r:HALF_UP (decimal.NEGATIVE_INFINITY - 1000)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY - 1000);
							AddTestCase('subx782:p15 r:HALF_UP (decimal.NEGATIVE_INFINITY - 1)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY - 1);
							AddTestCase('subx783:p15 r:HALF_UP (decimal.NEGATIVE_INFINITY - -0)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY - -0);
							AddTestCase('subx784:p15 r:HALF_UP (decimal.NEGATIVE_INFINITY - -1)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY - -1);
							AddTestCase('subx785:p15 r:HALF_UP (decimal.NEGATIVE_INFINITY - -1000)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY - -1000);
							AddTestCase('subx787:p15 r:HALF_UP (-1000 - decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, -1000 - decimal.POSITIVE_INFINITY);
							AddTestCase('subx788:p15 r:HALF_UP (decimal.NEGATIVE_INFINITY - decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY - decimal.POSITIVE_INFINITY);
							AddTestCase('subx789:p15 r:HALF_UP (-1 - decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, -1 - decimal.POSITIVE_INFINITY);
							AddTestCase('subx790:p15 r:HALF_UP (0 - decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, 0 - decimal.POSITIVE_INFINITY);
							AddTestCase('subx791:p15 r:HALF_UP (1 - decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, 1 - decimal.POSITIVE_INFINITY);
							AddTestCase('subx792:p15 r:HALF_UP (1000 - decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, 1000 - decimal.POSITIVE_INFINITY);
							AddTestCase('subx800:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - decimal.POSITIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY - decimal.POSITIVE_INFINITY);
							AddTestCase('subx801:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - 1000)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY - 1000);
							AddTestCase('subx802:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - 1)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY - 1);
							AddTestCase('subx803:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - 0)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY - 0);
							AddTestCase('subx804:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - -0)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY - -0);
							AddTestCase('subx805:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - -1)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY - -1);
							AddTestCase('subx806:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - -1000)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY - -1000);
							AddTestCase('subx807:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - decimal.NEGATIVE_INFINITY)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY - decimal.NEGATIVE_INFINITY);
							AddTestCase('subx808:p15 r:HALF_UP (-1000 - decimal.NEGATIVE_INFINITY)', decimal.POSITIVE_INFINITY, -1000 - decimal.NEGATIVE_INFINITY);
							AddTestCase('subx809:p15 r:HALF_UP (decimal.NEGATIVE_INFINITY - decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.NEGATIVE_INFINITY - decimal.NEGATIVE_INFINITY);
							AddTestCase('subx810:p15 r:HALF_UP (-1 - decimal.NEGATIVE_INFINITY)', decimal.POSITIVE_INFINITY, -1 - decimal.NEGATIVE_INFINITY);
							AddTestCase('subx811:p15 r:HALF_UP (-0 - decimal.NEGATIVE_INFINITY)', decimal.POSITIVE_INFINITY, -0 - decimal.NEGATIVE_INFINITY);
							AddTestCase('subx812:p15 r:HALF_UP (0 - decimal.NEGATIVE_INFINITY)', decimal.POSITIVE_INFINITY, 0 - decimal.NEGATIVE_INFINITY);
							AddTestCase('subx813:p15 r:HALF_UP (1 - decimal.NEGATIVE_INFINITY)', decimal.POSITIVE_INFINITY, 1 - decimal.NEGATIVE_INFINITY);
							AddTestCase('subx814:p15 r:HALF_UP (1000 - decimal.NEGATIVE_INFINITY)', decimal.POSITIVE_INFINITY, 1000 - decimal.NEGATIVE_INFINITY);
							AddTestCase('subx815:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - decimal.NEGATIVE_INFINITY)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY - decimal.NEGATIVE_INFINITY);
							AddTestCase('subx821:p15 r:HALF_UP (NaN - decimal.POSITIVE_INFINITY)', NaN, NaN - decimal.POSITIVE_INFINITY);
							AddTestCase('subx822:p15 r:HALF_UP (-NaN - 1000)', -NaN, -NaN - 1000);
							AddTestCase('subx823:p15 r:HALF_UP (NaN - 1)', NaN, NaN - 1);
							AddTestCase('subx824:p15 r:HALF_UP (NaN - 0)', NaN, NaN - 0);
							AddTestCase('subx825:p15 r:HALF_UP (NaN - -0)', NaN, NaN - -0);
							AddTestCase('subx826:p15 r:HALF_UP (NaN - -1)', NaN, NaN - -1);
							AddTestCase('subx827:p15 r:HALF_UP (NaN - -1000)', NaN, NaN - -1000);
							AddTestCase('subx828:p15 r:HALF_UP (NaN - decimal.NEGATIVE_INFINITY)', NaN, NaN - decimal.NEGATIVE_INFINITY);
							AddTestCase('subx829:p15 r:HALF_UP (-NaN - NaN)', -NaN, -NaN - NaN);
							AddTestCase('subx830:p15 r:HALF_UP (decimal.NEGATIVE_INFINITY - NaN)', NaN, decimal.NEGATIVE_INFINITY - NaN);
							AddTestCase('subx831:p15 r:HALF_UP (-1000 - NaN)', NaN, -1000 - NaN);
							AddTestCase('subx832:p15 r:HALF_UP (-1 - NaN)', NaN, -1 - NaN);
							AddTestCase('subx833:p15 r:HALF_UP (-0 - NaN)', NaN, -0 - NaN);
							AddTestCase('subx834:p15 r:HALF_UP (0 - NaN)', NaN, 0 - NaN);
							AddTestCase('subx835:p15 r:HALF_UP (1 - NaN)', NaN, 1 - NaN);
							AddTestCase('subx836:p15 r:HALF_UP (1000 - -NaN)', -NaN, 1000 - -NaN);
							AddTestCase('subx837:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - NaN)', NaN, decimal.POSITIVE_INFINITY - NaN);
							AddTestCase('subx841:p15 r:HALF_UP (NaN - decimal.POSITIVE_INFINITY) invalid_operation', NaN, NaN - decimal.POSITIVE_INFINITY);
							AddTestCase('subx842:p15 r:HALF_UP (-NaN - 1000) invalid_operation', -NaN, -NaN - 1000);
							AddTestCase('subx843:p15 r:HALF_UP (NaN - 1) invalid_operation', NaN, NaN - 1);
							AddTestCase('subx844:p15 r:HALF_UP (NaN - 0) invalid_operation', NaN, NaN - 0);
							AddTestCase('subx845:p15 r:HALF_UP (NaN - -0) invalid_operation', NaN, NaN - -0);
							AddTestCase('subx846:p15 r:HALF_UP (NaN - -1) invalid_operation', NaN, NaN - -1);
							AddTestCase('subx847:p15 r:HALF_UP (NaN - -1000) invalid_operation', NaN, NaN - -1000);
							AddTestCase('subx848:p15 r:HALF_UP (NaN - NaN) invalid_operation', NaN, NaN - NaN);
							AddTestCase('subx849:p15 r:HALF_UP (NaN - NaN) invalid_operation', NaN, NaN - NaN);
							AddTestCase('subx850:p15 r:HALF_UP (NaN - NaN) invalid_operation', NaN, NaN - NaN);
							AddTestCase('subx851:p15 r:HALF_UP (decimal.NEGATIVE_INFINITY - -NaN) invalid_operation', -NaN, decimal.NEGATIVE_INFINITY - -NaN);
							AddTestCase('subx852:p15 r:HALF_UP (-1000 - NaN) invalid_operation', NaN, -1000 - NaN);
							AddTestCase('subx853:p15 r:HALF_UP (-1 - NaN) invalid_operation', NaN, -1 - NaN);
							AddTestCase('subx854:p15 r:HALF_UP (-0 - NaN) invalid_operation', NaN, -0 - NaN);
							AddTestCase('subx855:p15 r:HALF_UP (0 - NaN) invalid_operation', NaN, 0 - NaN);
							AddTestCase('subx856:p15 r:HALF_UP (1 - NaN) invalid_operation', NaN, 1 - NaN);
							AddTestCase('subx857:p15 r:HALF_UP (1000 - NaN) invalid_operation', NaN, 1000 - NaN);
							AddTestCase('subx858:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - NaN) invalid_operation', NaN, decimal.POSITIVE_INFINITY - NaN);
							AddTestCase('subx859:p15 r:HALF_UP (NaN - NaN) invalid_operation', NaN, NaN - NaN);
							// propagating nans
							AddTestCase('subx861:p15 r:HALF_UP (NaN - decimal.NEGATIVE_INFINITY)', NaN, NaN - decimal.NEGATIVE_INFINITY);
							AddTestCase('subx862:p15 r:HALF_UP (-NaN - -1000)', -NaN, -NaN - -1000);
							AddTestCase('subx863:p15 r:HALF_UP (NaN - 1000)', NaN, NaN - 1000);
							AddTestCase('subx864:p15 r:HALF_UP (NaN - decimal.POSITIVE_INFINITY)', NaN, NaN - decimal.POSITIVE_INFINITY);
							AddTestCase('subx865:p15 r:HALF_UP (NaN - NaN)', NaN, NaN - NaN);
							AddTestCase('subx866:p15 r:HALF_UP (decimal.NEGATIVE_INFINITY - -NaN)', -NaN, decimal.NEGATIVE_INFINITY - -NaN);
							AddTestCase('subx867:p15 r:HALF_UP (-1000 - NaN)', NaN, -1000 - NaN);
							AddTestCase('subx868:p15 r:HALF_UP (1000 - NaN)', NaN, 1000 - NaN);
							AddTestCase('subx869:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - NaN)', NaN, decimal.POSITIVE_INFINITY - NaN);
							AddTestCase('subx871:p15 r:HALF_UP (NaN - decimal.NEGATIVE_INFINITY) invalid_operation', NaN, NaN - decimal.NEGATIVE_INFINITY);
							AddTestCase('subx872:p15 r:HALF_UP (NaN - -1000) invalid_operation', NaN, NaN - -1000);
							AddTestCase('subx873:p15 r:HALF_UP (-NaN - 1000) invalid_operation', -NaN, -NaN - 1000);
							AddTestCase('subx874:p15 r:HALF_UP (NaN - NaN) invalid_operation', NaN, NaN - NaN);
							AddTestCase('subx875:p15 r:HALF_UP (NaN - NaN) invalid_operation', NaN, NaN - NaN);
							AddTestCase('subx876:p15 r:HALF_UP (NaN - NaN) invalid_operation', NaN, NaN - NaN);
							AddTestCase('subx877:p15 r:HALF_UP (decimal.NEGATIVE_INFINITY - NaN) invalid_operation', NaN, decimal.NEGATIVE_INFINITY - NaN);
							AddTestCase('subx878:p15 r:HALF_UP (-1000 - NaN) invalid_operation', NaN, -1000 - NaN);
							AddTestCase('subx879:p15 r:HALF_UP (1000 - -NaN) invalid_operation', -NaN, 1000 - -NaN);
							AddTestCase('subx880:p15 r:HALF_UP (decimal.POSITIVE_INFINITY - NaN) invalid_operation', NaN, decimal.POSITIVE_INFINITY - NaN);
							AddTestCase('subx881:p15 r:HALF_UP (NaN - NaN) invalid_operation', NaN, NaN - NaN);
							// edge case spills
							AddTestCase('subx901:p15 r:HALF_UP (2.e-3 - 1.002)', -1.000, 2.e-3 - 1.002);
							AddTestCase('subx902:p15 r:HALF_UP (2.0e-3 - 1.002)', -1.0000, 2.0e-3 - 1.002);
							AddTestCase('subx903:p15 r:HALF_UP (2.00e-3 - 1.0020)', -1.00000, 2.00e-3 - 1.0020);
							AddTestCase('subx904:p15 r:HALF_UP (2.000e-3 - 1.00200)', -1.000000, 2.000e-3 - 1.00200);
							AddTestCase('subx905:p15 r:HALF_UP (2.0000e-3 - 1.002000)', -1.0000000, 2.0000e-3 - 1.002000);
							AddTestCase('subx906:p15 r:HALF_UP (2.00000e-3 - 1.0020000)', -1.00000000, 2.00000e-3 - 1.0020000);
							AddTestCase('subx907:p15 r:HALF_UP (2.000000e-3 - 1.00200000)', -1.000000000, 2.000000e-3 - 1.00200000);
							AddTestCase('subx908:p15 r:HALF_UP (2.0000000e-3 - 1.002000000)', -1.0000000000, 2.0000000e-3 - 1.002000000);
							// subnormals and underflows
						}
						{
							use precision 3;
							AddTestCase('subx1010:p3 r:HALF_UP (0 - 1.00e-999)', -1.00e-999, 0 - 1.00e-999);
							// next is rounded to emin
							AddTestCase('subx1030:p3 r:HALF_UP (0 - -1.00e-999)', 1.00e-999, 0 - -1.00e-999);
							// next is rounded to emin
							// some non-zero subnormal subtracts
							// subx1056 is a tricky case
							{
								use rounding HALF_UP;
								AddTestCase('subx1051:p3 r:HALF_UP (0.1e-999 - 0.1e-999)', 0e-1000, 0.1e-999 - 0.1e-999);
								AddTestCase('subx1052:p3 r:HALF_UP (0.10e-999 - 0.1e-999)', 0e-1001, 0.10e-999 - 0.1e-999);
								// check for double-rounded subnormals
								{
									use precision 5;
									{
										use rounding HALF_UP;
										// examples from sql proposal (krishna kulkarni)
										// null tests
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
