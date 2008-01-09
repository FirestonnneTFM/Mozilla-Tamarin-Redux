use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "add.decTest";
var BUGNUMBER = "";
startTest();
{
//----/cancell----------------------------------------------------------
// add.dectest -- decimal addition                                    --
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
AddTestCase('addx001:p9 r:HALF_UP (1 + 1)', 2, 1 + 1);
AddTestCase('addx002:p9 r:HALF_UP (2 + 3)', 5, 2 + 3);
AddTestCase('addx003:p9 r:HALF_UP (5.75 + 3.3)', 9.05, 5.75 + 3.3);
AddTestCase('addx004:p9 r:HALF_UP (5 + -3)', 2, 5 + -3);
AddTestCase('addx005:p9 r:HALF_UP (-5 + -3)', -8, -5 + -3);
AddTestCase('addx006:p9 r:HALF_UP (-7 + 2.5)', -4.5, -7 + 2.5);
AddTestCase('addx007:p9 r:HALF_UP (0.7 + 0.3)', 1.0, 0.7 + 0.3);
AddTestCase('addx008:p9 r:HALF_UP (1.25 + 1.25)', 2.50, 1.25 + 1.25);
AddTestCase('addx009:p9 r:HALF_UP (1.23456789 + 1.00000000)', 2.23456789, 1.23456789 + 1.00000000);
AddTestCase('addx010:p9 r:HALF_UP (1.23456789 + 1.00000011)', 2.23456800, 1.23456789 + 1.00000011);
AddTestCase('addx011:p9 r:HALF_UP (0.4444444444 + 0.5555555555) inexact rounded', 1.00000000, 0.4444444444 + 0.5555555555);
AddTestCase('addx012:p9 r:HALF_UP (0.4444444440 + 0.5555555555) inexact rounded', 1.00000000, 0.4444444440 + 0.5555555555);
AddTestCase('addx013:p9 r:HALF_UP (0.4444444444 + 0.5555555550) inexact rounded', 0.999999999, 0.4444444444 + 0.5555555550);
AddTestCase('addx014:p9 r:HALF_UP (0.44444444449 + 0) inexact rounded', 0.444444444, 0.44444444449 + 0);
AddTestCase('addx015:p9 r:HALF_UP (0.444444444499 + 0) inexact rounded', 0.444444444, 0.444444444499 + 0);
AddTestCase('addx016:p9 r:HALF_UP (0.4444444444999 + 0) inexact rounded', 0.444444444, 0.4444444444999 + 0);
AddTestCase('addx017:p9 r:HALF_UP (0.4444444445000 + 0) inexact rounded', 0.444444445, 0.4444444445000 + 0);
AddTestCase('addx018:p9 r:HALF_UP (0.4444444445001 + 0) inexact rounded', 0.444444445, 0.4444444445001 + 0);
AddTestCase('addx019:p9 r:HALF_UP (0.444444444501 + 0) inexact rounded', 0.444444445, 0.444444444501 + 0);
AddTestCase('addx020:p9 r:HALF_UP (0.44444444451 + 0) inexact rounded', 0.444444445, 0.44444444451 + 0);
AddTestCase('addx021:p9 r:HALF_UP (0 + 1)', 1, 0 + 1);
AddTestCase('addx022:p9 r:HALF_UP (1 + 1)', 2, 1 + 1);
AddTestCase('addx023:p9 r:HALF_UP (2 + 1)', 3, 2 + 1);
AddTestCase('addx024:p9 r:HALF_UP (3 + 1)', 4, 3 + 1);
AddTestCase('addx025:p9 r:HALF_UP (4 + 1)', 5, 4 + 1);
AddTestCase('addx026:p9 r:HALF_UP (5 + 1)', 6, 5 + 1);
AddTestCase('addx027:p9 r:HALF_UP (6 + 1)', 7, 6 + 1);
AddTestCase('addx028:p9 r:HALF_UP (7 + 1)', 8, 7 + 1);
AddTestCase('addx029:p9 r:HALF_UP (8 + 1)', 9, 8 + 1);
AddTestCase('addx030:p9 r:HALF_UP (9 + 1)', 10, 9 + 1);
// some carrying effects
AddTestCase('addx031:p9 r:HALF_UP (0.9998 + 0.0000)', 0.9998, 0.9998 + 0.0000);
AddTestCase('addx032:p9 r:HALF_UP (0.9998 + 0.0001)', 0.9999, 0.9998 + 0.0001);
AddTestCase('addx033:p9 r:HALF_UP (0.9998 + 0.0002)', 1.0000, 0.9998 + 0.0002);
AddTestCase('addx034:p9 r:HALF_UP (0.9998 + 0.0003)', 1.0001, 0.9998 + 0.0003);
AddTestCase('addx035:p9 r:HALF_UP (70 + 10000e+9) inexact rounded', 1.00000000e+13, 70 + 10000e+9);
AddTestCase('addx036:p9 r:HALF_UP (700 + 10000e+9) inexact rounded', 1.00000000e+13, 700 + 10000e+9);
AddTestCase('addx037:p9 r:HALF_UP (7000 + 10000e+9) inexact rounded', 1.00000000e+13, 7000 + 10000e+9);
AddTestCase('addx038:p9 r:HALF_UP (70000 + 10000e+9) inexact rounded', 1.00000001e+13, 70000 + 10000e+9);
AddTestCase('addx039:p9 r:HALF_UP (700000 + 10000e+9) rounded', 1.00000007e+13, 700000 + 10000e+9);
// symmetry:
AddTestCase('addx040:p9 r:HALF_UP (10000e+9 + 70) inexact rounded', 1.00000000e+13, 10000e+9 + 70);
AddTestCase('addx041:p9 r:HALF_UP (10000e+9 + 700) inexact rounded', 1.00000000e+13, 10000e+9 + 700);
AddTestCase('addx042:p9 r:HALF_UP (10000e+9 + 7000) inexact rounded', 1.00000000e+13, 10000e+9 + 7000);
AddTestCase('addx044:p9 r:HALF_UP (10000e+9 + 70000) inexact rounded', 1.00000001e+13, 10000e+9 + 70000);
AddTestCase('addx045:p9 r:HALF_UP (10000e+9 + 700000) rounded', 1.00000007e+13, 10000e+9 + 700000);
// same, higher precision
{
	use precision 15;
	AddTestCase('addx046:p15 r:HALF_UP (10000e+9 + 7)', 10000000000007, 10000e+9 + 7);
	AddTestCase('addx047:p15 r:HALF_UP (10000e+9 + 70)', 10000000000070, 10000e+9 + 70);
	AddTestCase('addx048:p15 r:HALF_UP (10000e+9 + 700)', 10000000000700, 10000e+9 + 700);
	AddTestCase('addx049:p15 r:HALF_UP (10000e+9 + 7000)', 10000000007000, 10000e+9 + 7000);
	AddTestCase('addx050:p15 r:HALF_UP (10000e+9 + 70000)', 10000000070000, 10000e+9 + 70000);
	AddTestCase('addx051:p15 r:HALF_UP (10000e+9 + 700000)', 10000000700000, 10000e+9 + 700000);
	AddTestCase('addx052:p15 r:HALF_UP (10000e+9 + 7000000)', 10000007000000, 10000e+9 + 7000000);
	// examples from decarith
	AddTestCase('addx053:p15 r:HALF_UP (12 + 7.00)', 19.00, 12 + 7.00);
	AddTestCase('addx054:p15 r:HALF_UP (1.3 + -1.07)', 0.23, 1.3 + -1.07);
	AddTestCase('addx055:p15 r:HALF_UP (1.3 + -1.30)', 0.00, 1.3 + -1.30);
	AddTestCase('addx056:p15 r:HALF_UP (1.3 + -2.07)', -0.77, 1.3 + -2.07);
	AddTestCase('addx057:p15 r:HALF_UP (1e+2 + 1e+4)', 1.01e+4, 1e+2 + 1e+4);
	// zero preservation
}
{
	use precision 6;
	AddTestCase('addx060:p6 r:HALF_UP (10000e+9 + 70000) inexact rounded', 1.00000e+13, 10000e+9 + 70000);
	AddTestCase('addx061:p6 r:HALF_UP (1 + 0.0001)', 1.0001, 1 + 0.0001);
	AddTestCase('addx062:p6 r:HALF_UP (1 + 0.00001)', 1.00001, 1 + 0.00001);
	AddTestCase('addx063:p6 r:HALF_UP (1 + 0.000001) inexact rounded', 1.00000, 1 + 0.000001);
	AddTestCase('addx064:p6 r:HALF_UP (1 + 0.0000001) inexact rounded', 1.00000, 1 + 0.0000001);
	AddTestCase('addx065:p6 r:HALF_UP (1 + 0.00000001) inexact rounded', 1.00000, 1 + 0.00000001);
	// some funny zeros [in case of bad signum]
	AddTestCase('addx070:p6 r:HALF_UP (1 + 0)', 1, 1 + 0);
	AddTestCase('addx071:p6 r:HALF_UP (1 + 0.)', 1, 1 + 0.);
	AddTestCase('addx072:p6 r:HALF_UP (1 + .0)', 1.0, 1 + .0);
	AddTestCase('addx073:p6 r:HALF_UP (1 + 0.0)', 1.0, 1 + 0.0);
	AddTestCase('addx074:p6 r:HALF_UP (1 + 0.00)', 1.00, 1 + 0.00);
	AddTestCase('addx075:p6 r:HALF_UP (0 + 1)', 1, 0 + 1);
	AddTestCase('addx076:p6 r:HALF_UP (0. + 1)', 1, 0. + 1);
	AddTestCase('addx077:p6 r:HALF_UP (.0 + 1)', 1.0, .0 + 1);
	AddTestCase('addx078:p6 r:HALF_UP (0.0 + 1)', 1.0, 0.0 + 1);
	AddTestCase('addx079:p6 r:HALF_UP (0.00 + 1)', 1.00, 0.00 + 1);
}
{
	use precision 9;
	// some carries
	AddTestCase('addx080:p9 r:HALF_UP (999999998 + 1)', 999999999, 999999998 + 1);
	AddTestCase('addx081:p9 r:HALF_UP (999999999 + 1) rounded', 1.00000000e+9, 999999999 + 1);
	AddTestCase('addx082:p9 r:HALF_UP (99999999 + 1)', 100000000, 99999999 + 1);
	AddTestCase('addx083:p9 r:HALF_UP (9999999 + 1)', 10000000, 9999999 + 1);
	AddTestCase('addx084:p9 r:HALF_UP (999999 + 1)', 1000000, 999999 + 1);
	AddTestCase('addx085:p9 r:HALF_UP (99999 + 1)', 100000, 99999 + 1);
	AddTestCase('addx086:p9 r:HALF_UP (9999 + 1)', 10000, 9999 + 1);
	AddTestCase('addx087:p9 r:HALF_UP (999 + 1)', 1000, 999 + 1);
	AddTestCase('addx088:p9 r:HALF_UP (99 + 1)', 100, 99 + 1);
	AddTestCase('addx089:p9 r:HALF_UP (9 + 1)', 10, 9 + 1);
	// more lhs swaps
	AddTestCase('addx090:p9 r:HALF_UP (-56267e-10 + 0)', -0.0000056267, -56267e-10 + 0);
	AddTestCase('addx091:p9 r:HALF_UP (-56267e-6 + 0)', -0.056267, -56267e-6 + 0);
	AddTestCase('addx092:p9 r:HALF_UP (-56267e-5 + 0)', -0.56267, -56267e-5 + 0);
	AddTestCase('addx093:p9 r:HALF_UP (-56267e-4 + 0)', -5.6267, -56267e-4 + 0);
	AddTestCase('addx094:p9 r:HALF_UP (-56267e-3 + 0)', -56.267, -56267e-3 + 0);
	AddTestCase('addx095:p9 r:HALF_UP (-56267e-2 + 0)', -562.67, -56267e-2 + 0);
	AddTestCase('addx096:p9 r:HALF_UP (-56267e-1 + 0)', -5626.7, -56267e-1 + 0);
	AddTestCase('addx097:p9 r:HALF_UP (-56267e-0 + 0)', -56267, -56267e-0 + 0);
	AddTestCase('addx098:p9 r:HALF_UP (-5e-10 + 0)', -5e-10, -5e-10 + 0);
	AddTestCase('addx099:p9 r:HALF_UP (-5e-7 + 0)', -5e-7, -5e-7 + 0);
	AddTestCase('addx100:p9 r:HALF_UP (-5e-6 + 0)', -0.000005, -5e-6 + 0);
	AddTestCase('addx101:p9 r:HALF_UP (-5e-5 + 0)', -0.00005, -5e-5 + 0);
	AddTestCase('addx102:p9 r:HALF_UP (-5e-4 + 0)', -0.0005, -5e-4 + 0);
	AddTestCase('addx103:p9 r:HALF_UP (-5e-1 + 0)', -0.5, -5e-1 + 0);
	AddTestCase('addx104:p9 r:HALF_UP (-5e0 + 0)', -5, -5e0 + 0);
	AddTestCase('addx105:p9 r:HALF_UP (-5e1 + 0)', -50, -5e1 + 0);
	AddTestCase('addx106:p9 r:HALF_UP (-5e5 + 0)', -500000, -5e5 + 0);
	AddTestCase('addx107:p9 r:HALF_UP (-5e8 + 0)', -500000000, -5e8 + 0);
	AddTestCase('addx108:p9 r:HALF_UP (-5e9 + 0) rounded', -5.00000000e+9, -5e9 + 0);
	AddTestCase('addx109:p9 r:HALF_UP (-5e10 + 0) rounded', -5.00000000e+10, -5e10 + 0);
	AddTestCase('addx110:p9 r:HALF_UP (-5e11 + 0) rounded', -5.00000000e+11, -5e11 + 0);
	AddTestCase('addx111:p9 r:HALF_UP (-5e100 + 0) rounded', -5.00000000e+100, -5e100 + 0);
	// more rhs swaps
	AddTestCase('addx113:p9 r:HALF_UP (0 + -56267e-10)', -0.0000056267, 0 + -56267e-10);
	AddTestCase('addx114:p9 r:HALF_UP (0 + -56267e-6)', -0.056267, 0 + -56267e-6);
	AddTestCase('addx116:p9 r:HALF_UP (0 + -56267e-5)', -0.56267, 0 + -56267e-5);
	AddTestCase('addx117:p9 r:HALF_UP (0 + -56267e-4)', -5.6267, 0 + -56267e-4);
	AddTestCase('addx119:p9 r:HALF_UP (0 + -56267e-3)', -56.267, 0 + -56267e-3);
	AddTestCase('addx120:p9 r:HALF_UP (0 + -56267e-2)', -562.67, 0 + -56267e-2);
	AddTestCase('addx121:p9 r:HALF_UP (0 + -56267e-1)', -5626.7, 0 + -56267e-1);
	AddTestCase('addx122:p9 r:HALF_UP (0 + -56267e-0)', -56267, 0 + -56267e-0);
	AddTestCase('addx123:p9 r:HALF_UP (0 + -5e-10)', -5e-10, 0 + -5e-10);
	AddTestCase('addx124:p9 r:HALF_UP (0 + -5e-7)', -5e-7, 0 + -5e-7);
	AddTestCase('addx125:p9 r:HALF_UP (0 + -5e-6)', -0.000005, 0 + -5e-6);
	AddTestCase('addx126:p9 r:HALF_UP (0 + -5e-5)', -0.00005, 0 + -5e-5);
	AddTestCase('addx127:p9 r:HALF_UP (0 + -5e-4)', -0.0005, 0 + -5e-4);
	AddTestCase('addx128:p9 r:HALF_UP (0 + -5e-1)', -0.5, 0 + -5e-1);
	AddTestCase('addx129:p9 r:HALF_UP (0 + -5e0)', -5, 0 + -5e0);
	AddTestCase('addx130:p9 r:HALF_UP (0 + -5e1)', -50, 0 + -5e1);
	AddTestCase('addx131:p9 r:HALF_UP (0 + -5e5)', -500000, 0 + -5e5);
	AddTestCase('addx132:p9 r:HALF_UP (0 + -5e8)', -500000000, 0 + -5e8);
	AddTestCase('addx133:p9 r:HALF_UP (0 + -5e9) rounded', -5.00000000e+9, 0 + -5e9);
	AddTestCase('addx134:p9 r:HALF_UP (0 + -5e10) rounded', -5.00000000e+10, 0 + -5e10);
	AddTestCase('addx135:p9 r:HALF_UP (0 + -5e11) rounded', -5.00000000e+11, 0 + -5e11);
	AddTestCase('addx136:p9 r:HALF_UP (0 + -5e100) rounded', -5.00000000e+100, 0 + -5e100);
	// related
	AddTestCase('addx137:p9 r:HALF_UP (1 + 0e-12) rounded', 1.00000000, 1 + 0e-12);
	AddTestCase('addx138:p9 r:HALF_UP (-1 + 0e-12) rounded', -1.00000000, -1 + 0e-12);
	AddTestCase('addx139:p9 r:HALF_UP (0e-12 + 1) rounded', 1.00000000, 0e-12 + 1);
	AddTestCase('addx140:p9 r:HALF_UP (0e-12 + -1) rounded', -1.00000000, 0e-12 + -1);
	AddTestCase('addx141:p9 r:HALF_UP (1e+4 + 0.0000)', 10000.0000, 1e+4 + 0.0000);
	AddTestCase('addx142:p9 r:HALF_UP (1e+4 + 0.00000) rounded', 10000.0000, 1e+4 + 0.00000);
	AddTestCase('addx143:p9 r:HALF_UP (0.000 + 1e+5)', 100000.000, 0.000 + 1e+5);
	AddTestCase('addx144:p9 r:HALF_UP (0.0000 + 1e+5) rounded', 100000.000, 0.0000 + 1e+5);
	// [some of the next group are really constructor tests]
	AddTestCase('addx146:p9 r:HALF_UP (00.0 + 0)', 0.0, 00.0 + 0);
	AddTestCase('addx147:p9 r:HALF_UP (0.00 + 0)', 0.00, 0.00 + 0);
	AddTestCase('addx148:p9 r:HALF_UP (0 + 0.00)', 0.00, 0 + 0.00);
	AddTestCase('addx149:p9 r:HALF_UP (0 + 00.0)', 0.0, 0 + 00.0);
	AddTestCase('addx150:p9 r:HALF_UP (00.0 + 0.00)', 0.00, 00.0 + 0.00);
	AddTestCase('addx151:p9 r:HALF_UP (0.00 + 00.0)', 0.00, 0.00 + 00.0);
	AddTestCase('addx152:p9 r:HALF_UP (3 + .3)', 3.3, 3 + .3);
	AddTestCase('addx153:p9 r:HALF_UP (3. + .3)', 3.3, 3. + .3);
	AddTestCase('addx154:p9 r:HALF_UP (3.0 + .3)', 3.3, 3.0 + .3);
	AddTestCase('addx155:p9 r:HALF_UP (3.00 + .3)', 3.30, 3.00 + .3);
	AddTestCase('addx156:p9 r:HALF_UP (3 + 3)', 6, 3 + 3);
	AddTestCase('addx157:p9 r:HALF_UP (3 + +3)', 6, 3 + +3);
	AddTestCase('addx158:p9 r:HALF_UP (3 + -3)', 0, 3 + -3);
	AddTestCase('addx159:p9 r:HALF_UP (0.3 + -0.3)', 0.0, 0.3 + -0.3);
	AddTestCase('addx160:p9 r:HALF_UP (0.03 + -0.03)', 0.00, 0.03 + -0.03);
	// try borderline precision, with carries, etc.
}
{
	use precision 15;
	AddTestCase('addx161:p15 r:HALF_UP (1e+12 + -1)', 999999999999, 1e+12 + -1);
	AddTestCase('addx162:p15 r:HALF_UP (1e+12 + 1.11)', 1000000000001.11, 1e+12 + 1.11);
	AddTestCase('addx163:p15 r:HALF_UP (1.11 + 1e+12)', 1000000000001.11, 1.11 + 1e+12);
	AddTestCase('addx164:p15 r:HALF_UP (-1 + 1e+12)', 999999999999, -1 + 1e+12);
	AddTestCase('addx165:p15 r:HALF_UP (7e+12 + -1)', 6999999999999, 7e+12 + -1);
	AddTestCase('addx166:p15 r:HALF_UP (7e+12 + 1.11)', 7000000000001.11, 7e+12 + 1.11);
	AddTestCase('addx167:p15 r:HALF_UP (1.11 + 7e+12)', 7000000000001.11, 1.11 + 7e+12);
	AddTestCase('addx168:p15 r:HALF_UP (-1 + 7e+12)', 6999999999999, -1 + 7e+12);
	//             123456789012345      123456789012345      1 23456789012345
	AddTestCase('addx170:p15 r:HALF_UP (0.444444444444444 + 0.555555555555563) inexact rounded', 1.00000000000001, 0.444444444444444 + 0.555555555555563);
	AddTestCase('addx171:p15 r:HALF_UP (0.444444444444444 + 0.555555555555562) inexact rounded', 1.00000000000001, 0.444444444444444 + 0.555555555555562);
	AddTestCase('addx172:p15 r:HALF_UP (0.444444444444444 + 0.555555555555561) inexact rounded', 1.00000000000001, 0.444444444444444 + 0.555555555555561);
	AddTestCase('addx173:p15 r:HALF_UP (0.444444444444444 + 0.555555555555560) inexact rounded', 1.00000000000000, 0.444444444444444 + 0.555555555555560);
	AddTestCase('addx174:p15 r:HALF_UP (0.444444444444444 + 0.555555555555559) inexact rounded', 1.00000000000000, 0.444444444444444 + 0.555555555555559);
	AddTestCase('addx175:p15 r:HALF_UP (0.444444444444444 + 0.555555555555558) inexact rounded', 1.00000000000000, 0.444444444444444 + 0.555555555555558);
	AddTestCase('addx176:p15 r:HALF_UP (0.444444444444444 + 0.555555555555557) inexact rounded', 1.00000000000000, 0.444444444444444 + 0.555555555555557);
	AddTestCase('addx177:p15 r:HALF_UP (0.444444444444444 + 0.555555555555556) rounded', 1.00000000000000, 0.444444444444444 + 0.555555555555556);
	AddTestCase('addx178:p15 r:HALF_UP (0.444444444444444 + 0.555555555555555)', 0.999999999999999, 0.444444444444444 + 0.555555555555555);
	AddTestCase('addx179:p15 r:HALF_UP (0.444444444444444 + 0.555555555555554)', 0.999999999999998, 0.444444444444444 + 0.555555555555554);
	AddTestCase('addx180:p15 r:HALF_UP (0.444444444444444 + 0.555555555555553)', 0.999999999999997, 0.444444444444444 + 0.555555555555553);
	AddTestCase('addx181:p15 r:HALF_UP (0.444444444444444 + 0.555555555555552)', 0.999999999999996, 0.444444444444444 + 0.555555555555552);
	AddTestCase('addx182:p15 r:HALF_UP (0.444444444444444 + 0.555555555555551)', 0.999999999999995, 0.444444444444444 + 0.555555555555551);
	AddTestCase('addx183:p15 r:HALF_UP (0.444444444444444 + 0.555555555555550)', 0.999999999999994, 0.444444444444444 + 0.555555555555550);
	// and some more, including residue effects and different roundings
}
{
	use precision 9;
	{
		use rounding HALF_UP;
		AddTestCase('addx200:p9 r:HALF_UP (123456789 + 0)', 123456789, 123456789 + 0);
		AddTestCase('addx201:p9 r:HALF_UP (123456789 + 0.000000001) inexact rounded', 123456789, 123456789 + 0.000000001);
		AddTestCase('addx202:p9 r:HALF_UP (123456789 + 0.000001) inexact rounded', 123456789, 123456789 + 0.000001);
		AddTestCase('addx203:p9 r:HALF_UP (123456789 + 0.1) inexact rounded', 123456789, 123456789 + 0.1);
		AddTestCase('addx204:p9 r:HALF_UP (123456789 + 0.4) inexact rounded', 123456789, 123456789 + 0.4);
		AddTestCase('addx205:p9 r:HALF_UP (123456789 + 0.49) inexact rounded', 123456789, 123456789 + 0.49);
		AddTestCase('addx206:p9 r:HALF_UP (123456789 + 0.499999) inexact rounded', 123456789, 123456789 + 0.499999);
		AddTestCase('addx207:p9 r:HALF_UP (123456789 + 0.499999999) inexact rounded', 123456789, 123456789 + 0.499999999);
		AddTestCase('addx208:p9 r:HALF_UP (123456789 + 0.5) inexact rounded', 123456790, 123456789 + 0.5);
		AddTestCase('addx209:p9 r:HALF_UP (123456789 + 0.500000001) inexact rounded', 123456790, 123456789 + 0.500000001);
		AddTestCase('addx210:p9 r:HALF_UP (123456789 + 0.500001) inexact rounded', 123456790, 123456789 + 0.500001);
		AddTestCase('addx211:p9 r:HALF_UP (123456789 + 0.51) inexact rounded', 123456790, 123456789 + 0.51);
		AddTestCase('addx212:p9 r:HALF_UP (123456789 + 0.6) inexact rounded', 123456790, 123456789 + 0.6);
		AddTestCase('addx213:p9 r:HALF_UP (123456789 + 0.9) inexact rounded', 123456790, 123456789 + 0.9);
		AddTestCase('addx214:p9 r:HALF_UP (123456789 + 0.99999) inexact rounded', 123456790, 123456789 + 0.99999);
		AddTestCase('addx215:p9 r:HALF_UP (123456789 + 0.999999999) inexact rounded', 123456790, 123456789 + 0.999999999);
		AddTestCase('addx216:p9 r:HALF_UP (123456789 + 1)', 123456790, 123456789 + 1);
		AddTestCase('addx217:p9 r:HALF_UP (123456789 + 1.000000001) inexact rounded', 123456790, 123456789 + 1.000000001);
		AddTestCase('addx218:p9 r:HALF_UP (123456789 + 1.00001) inexact rounded', 123456790, 123456789 + 1.00001);
		AddTestCase('addx219:p9 r:HALF_UP (123456789 + 1.1) inexact rounded', 123456790, 123456789 + 1.1);
	}
	{
		use rounding HALF_EVEN;
		AddTestCase('addx220:p9 r:HALF_EVEN (123456789 + 0)', 123456789, 123456789 + 0);
		AddTestCase('addx221:p9 r:HALF_EVEN (123456789 + 0.000000001) inexact rounded', 123456789, 123456789 + 0.000000001);
		AddTestCase('addx222:p9 r:HALF_EVEN (123456789 + 0.000001) inexact rounded', 123456789, 123456789 + 0.000001);
		AddTestCase('addx223:p9 r:HALF_EVEN (123456789 + 0.1) inexact rounded', 123456789, 123456789 + 0.1);
		AddTestCase('addx224:p9 r:HALF_EVEN (123456789 + 0.4) inexact rounded', 123456789, 123456789 + 0.4);
		AddTestCase('addx225:p9 r:HALF_EVEN (123456789 + 0.49) inexact rounded', 123456789, 123456789 + 0.49);
		AddTestCase('addx226:p9 r:HALF_EVEN (123456789 + 0.499999) inexact rounded', 123456789, 123456789 + 0.499999);
		AddTestCase('addx227:p9 r:HALF_EVEN (123456789 + 0.499999999) inexact rounded', 123456789, 123456789 + 0.499999999);
		AddTestCase('addx228:p9 r:HALF_EVEN (123456789 + 0.5) inexact rounded', 123456790, 123456789 + 0.5);
		AddTestCase('addx229:p9 r:HALF_EVEN (123456789 + 0.500000001) inexact rounded', 123456790, 123456789 + 0.500000001);
		AddTestCase('addx230:p9 r:HALF_EVEN (123456789 + 0.500001) inexact rounded', 123456790, 123456789 + 0.500001);
		AddTestCase('addx231:p9 r:HALF_EVEN (123456789 + 0.51) inexact rounded', 123456790, 123456789 + 0.51);
		AddTestCase('addx232:p9 r:HALF_EVEN (123456789 + 0.6) inexact rounded', 123456790, 123456789 + 0.6);
		AddTestCase('addx233:p9 r:HALF_EVEN (123456789 + 0.9) inexact rounded', 123456790, 123456789 + 0.9);
		AddTestCase('addx234:p9 r:HALF_EVEN (123456789 + 0.99999) inexact rounded', 123456790, 123456789 + 0.99999);
		AddTestCase('addx235:p9 r:HALF_EVEN (123456789 + 0.999999999) inexact rounded', 123456790, 123456789 + 0.999999999);
		AddTestCase('addx236:p9 r:HALF_EVEN (123456789 + 1)', 123456790, 123456789 + 1);
		AddTestCase('addx237:p9 r:HALF_EVEN (123456789 + 1.00000001) inexact rounded', 123456790, 123456789 + 1.00000001);
		AddTestCase('addx238:p9 r:HALF_EVEN (123456789 + 1.00001) inexact rounded', 123456790, 123456789 + 1.00001);
		AddTestCase('addx239:p9 r:HALF_EVEN (123456789 + 1.1) inexact rounded', 123456790, 123456789 + 1.1);
		// critical few with even bottom digit...
		AddTestCase('addx240:p9 r:HALF_EVEN (123456788 + 0.499999999) inexact rounded', 123456788, 123456788 + 0.499999999);
		AddTestCase('addx241:p9 r:HALF_EVEN (123456788 + 0.5) inexact rounded', 123456788, 123456788 + 0.5);
		AddTestCase('addx242:p9 r:HALF_EVEN (123456788 + 0.500000001) inexact rounded', 123456789, 123456788 + 0.500000001);
		// input preparation tests (operands should not be rounded)
		{
			use precision 3;
			{
				use rounding HALF_UP;
				AddTestCase('addx270:p3 r:HALF_UP (12345678900000 + 9999999999999) inexact rounded', 2.23e+13, 12345678900000 + 9999999999999);
				AddTestCase('addx271:p3 r:HALF_UP (9999999999999 + 12345678900000) inexact rounded', 2.23e+13, 9999999999999 + 12345678900000);
				AddTestCase('addx272:p3 r:HALF_UP (12e+3 + 3444) inexact rounded', 1.54e+4, 12e+3 + 3444);
				AddTestCase('addx273:p3 r:HALF_UP (12e+3 + 3446) inexact rounded', 1.54e+4, 12e+3 + 3446);
				AddTestCase('addx274:p3 r:HALF_UP (12e+3 + 3449.9) inexact rounded', 1.54e+4, 12e+3 + 3449.9);
				AddTestCase('addx275:p3 r:HALF_UP (12e+3 + 3450.0) inexact rounded', 1.55e+4, 12e+3 + 3450.0);
				AddTestCase('addx276:p3 r:HALF_UP (12e+3 + 3450.1) inexact rounded', 1.55e+4, 12e+3 + 3450.1);
				AddTestCase('addx277:p3 r:HALF_UP (12e+3 + 3454) inexact rounded', 1.55e+4, 12e+3 + 3454);
				AddTestCase('addx278:p3 r:HALF_UP (12e+3 + 3456) inexact rounded', 1.55e+4, 12e+3 + 3456);
				AddTestCase('addx281:p3 r:HALF_UP (3444 + 12e+3) inexact rounded', 1.54e+4, 3444 + 12e+3);
				AddTestCase('addx282:p3 r:HALF_UP (3446 + 12e+3) inexact rounded', 1.54e+4, 3446 + 12e+3);
				AddTestCase('addx283:p3 r:HALF_UP (3449.9 + 12e+3) inexact rounded', 1.54e+4, 3449.9 + 12e+3);
				AddTestCase('addx284:p3 r:HALF_UP (3450.0 + 12e+3) inexact rounded', 1.55e+4, 3450.0 + 12e+3);
				AddTestCase('addx285:p3 r:HALF_UP (3450.1 + 12e+3) inexact rounded', 1.55e+4, 3450.1 + 12e+3);
				AddTestCase('addx286:p3 r:HALF_UP (3454 + 12e+3) inexact rounded', 1.55e+4, 3454 + 12e+3);
				AddTestCase('addx287:p3 r:HALF_UP (3456 + 12e+3) inexact rounded', 1.55e+4, 3456 + 12e+3);
			}
			{
				use rounding HALF_DOWN;
				AddTestCase('addx291:p3 r:HALF_DOWN (3444 + 12e+3) inexact rounded', 1.54e+4, 3444 + 12e+3);
				AddTestCase('addx292:p3 r:HALF_DOWN (3446 + 12e+3) inexact rounded', 1.54e+4, 3446 + 12e+3);
				AddTestCase('addx293:p3 r:HALF_DOWN (3449.9 + 12e+3) inexact rounded', 1.54e+4, 3449.9 + 12e+3);
				AddTestCase('addx294:p3 r:HALF_DOWN (3450.0 + 12e+3) inexact rounded', 1.54e+4, 3450.0 + 12e+3);
				AddTestCase('addx295:p3 r:HALF_DOWN (3450.1 + 12e+3) inexact rounded', 1.55e+4, 3450.1 + 12e+3);
				AddTestCase('addx296:p3 r:HALF_DOWN (3454 + 12e+3) inexact rounded', 1.55e+4, 3454 + 12e+3);
				AddTestCase('addx297:p3 r:HALF_DOWN (3456 + 12e+3) inexact rounded', 1.55e+4, 3456 + 12e+3);
				// 1 in last place tests
			}
			{
				use rounding HALF_UP;
				AddTestCase('addx301:p3 r:HALF_UP (-1 + 1)', 0, -1 + 1);
				AddTestCase('addx302:p3 r:HALF_UP (0 + 1)', 1, 0 + 1);
				AddTestCase('addx303:p3 r:HALF_UP (1 + 1)', 2, 1 + 1);
				AddTestCase('addx304:p3 r:HALF_UP (12 + 1)', 13, 12 + 1);
				AddTestCase('addx305:p3 r:HALF_UP (98 + 1)', 99, 98 + 1);
				AddTestCase('addx306:p3 r:HALF_UP (99 + 1)', 100, 99 + 1);
				AddTestCase('addx307:p3 r:HALF_UP (100 + 1)', 101, 100 + 1);
				AddTestCase('addx308:p3 r:HALF_UP (101 + 1)', 102, 101 + 1);
				AddTestCase('addx309:p3 r:HALF_UP (-1 + -1)', -2, -1 + -1);
				AddTestCase('addx310:p3 r:HALF_UP (0 + -1)', -1, 0 + -1);
				AddTestCase('addx311:p3 r:HALF_UP (1 + -1)', 0, 1 + -1);
				AddTestCase('addx312:p3 r:HALF_UP (12 + -1)', 11, 12 + -1);
				AddTestCase('addx313:p3 r:HALF_UP (98 + -1)', 97, 98 + -1);
				AddTestCase('addx314:p3 r:HALF_UP (99 + -1)', 98, 99 + -1);
				AddTestCase('addx315:p3 r:HALF_UP (100 + -1)', 99, 100 + -1);
				AddTestCase('addx316:p3 r:HALF_UP (101 + -1)', 100, 101 + -1);
				AddTestCase('addx321:p3 r:HALF_UP (-0.01 + 0.01)', 0.00, -0.01 + 0.01);
				AddTestCase('addx322:p3 r:HALF_UP (0.00 + 0.01)', 0.01, 0.00 + 0.01);
				AddTestCase('addx323:p3 r:HALF_UP (0.01 + 0.01)', 0.02, 0.01 + 0.01);
				AddTestCase('addx324:p3 r:HALF_UP (0.12 + 0.01)', 0.13, 0.12 + 0.01);
				AddTestCase('addx325:p3 r:HALF_UP (0.98 + 0.01)', 0.99, 0.98 + 0.01);
				AddTestCase('addx326:p3 r:HALF_UP (0.99 + 0.01)', 1.00, 0.99 + 0.01);
				AddTestCase('addx327:p3 r:HALF_UP (1.00 + 0.01)', 1.01, 1.00 + 0.01);
				AddTestCase('addx328:p3 r:HALF_UP (1.01 + 0.01)', 1.02, 1.01 + 0.01);
				AddTestCase('addx329:p3 r:HALF_UP (-0.01 + -0.01)', -0.02, -0.01 + -0.01);
				AddTestCase('addx330:p3 r:HALF_UP (0.00 + -0.01)', -0.01, 0.00 + -0.01);
				AddTestCase('addx331:p3 r:HALF_UP (0.01 + -0.01)', 0.00, 0.01 + -0.01);
				AddTestCase('addx332:p3 r:HALF_UP (0.12 + -0.01)', 0.11, 0.12 + -0.01);
				AddTestCase('addx333:p3 r:HALF_UP (0.98 + -0.01)', 0.97, 0.98 + -0.01);
				AddTestCase('addx334:p3 r:HALF_UP (0.99 + -0.01)', 0.98, 0.99 + -0.01);
				AddTestCase('addx335:p3 r:HALF_UP (1.00 + -0.01)', 0.99, 1.00 + -0.01);
				AddTestCase('addx336:p3 r:HALF_UP (1.01 + -0.01)', 1.00, 1.01 + -0.01);
				// some more cases where adding 0 affects the coefficient
				{
					use precision 9;
					AddTestCase('addx340:p9 r:HALF_UP (1e+3 + 0)', 1000, 1e+3 + 0);
					AddTestCase('addx341:p9 r:HALF_UP (1e+8 + 0)', 100000000, 1e+8 + 0);
					AddTestCase('addx342:p9 r:HALF_UP (1e+9 + 0) rounded', 1.00000000e+9, 1e+9 + 0);
					AddTestCase('addx343:p9 r:HALF_UP (1e+10 + 0) rounded', 1.00000000e+10, 1e+10 + 0);
					// which simply follow from these cases ...
					AddTestCase('addx344:p9 r:HALF_UP (1e+3 + 1)', 1001, 1e+3 + 1);
					AddTestCase('addx345:p9 r:HALF_UP (1e+8 + 1)', 100000001, 1e+8 + 1);
					AddTestCase('addx346:p9 r:HALF_UP (1e+9 + 1) inexact rounded', 1.00000000e+9, 1e+9 + 1);
					AddTestCase('addx347:p9 r:HALF_UP (1e+10 + 1) inexact rounded', 1.00000000e+10, 1e+10 + 1);
					AddTestCase('addx348:p9 r:HALF_UP (1e+3 + 7)', 1007, 1e+3 + 7);
					AddTestCase('addx349:p9 r:HALF_UP (1e+8 + 7)', 100000007, 1e+8 + 7);
					AddTestCase('addx350:p9 r:HALF_UP (1e+9 + 7) inexact rounded', 1.00000001e+9, 1e+9 + 7);
					AddTestCase('addx351:p9 r:HALF_UP (1e+10 + 7) inexact rounded', 1.00000000e+10, 1e+10 + 7);
					// tryzeros cases
				}
				{
					use precision 7;
					{
						use rounding HALF_UP;
						AddTestCase('addx361:p7 r:HALF_UP (0e+50 + 10000e+1)', 1.0000e+5, 0e+50 + 10000e+1);
						AddTestCase('addx362:p7 r:HALF_UP (10000e+1 + 0e-50) rounded', 100000.0, 10000e+1 + 0e-50);
						AddTestCase('addx363:p7 r:HALF_UP (10000e+1 + 10000e-50) rounded inexact', 100000.0, 10000e+1 + 10000e-50);
						AddTestCase('addx364:p7 r:HALF_UP (9.999999e+92 + -9.999999e+92)', 0e+86, 9.999999e+92 + -9.999999e+92);
						// a curiosity from jsr 13 testing
					}
					{
						use rounding HALF_DOWN;
						{
							use precision 10;
							AddTestCase('addx370:p10 r:HALF_DOWN (99999999 + 81512)', 100081511, 99999999 + 81512);
						}
						{
							use precision 6;
							AddTestCase('addx371:p6 r:HALF_DOWN (99999999 + 81512) rounded inexact', 1.00082e+8, 99999999 + 81512);
							{
								use rounding HALF_UP;
								{
									use precision 10;
									AddTestCase('addx372:p10 r:HALF_UP (99999999 + 81512)', 100081511, 99999999 + 81512);
								}
								{
									use precision 6;
									AddTestCase('addx373:p6 r:HALF_UP (99999999 + 81512) rounded inexact', 1.00082e+8, 99999999 + 81512);
									{
										use rounding HALF_EVEN;
										{
											use precision 10;
											AddTestCase('addx374:p10 r:HALF_EVEN (99999999 + 81512)', 100081511, 99999999 + 81512);
										}
										{
											use precision 6;
											AddTestCase('addx375:p6 r:HALF_EVEN (99999999 + 81512) rounded inexact', 1.00082e+8, 99999999 + 81512);
											// ulp replacement tests
										}
										{
											use precision 9;
											AddTestCase('addx400:p9 r:HALF_EVEN (1 + 77e-7)', 1.0000077, 1 + 77e-7);
											AddTestCase('addx401:p9 r:HALF_EVEN (1 + 77e-8)', 1.00000077, 1 + 77e-8);
											AddTestCase('addx402:p9 r:HALF_EVEN (1 + 77e-9) inexact rounded', 1.00000008, 1 + 77e-9);
											AddTestCase('addx403:p9 r:HALF_EVEN (1 + 77e-10) inexact rounded', 1.00000001, 1 + 77e-10);
											AddTestCase('addx404:p9 r:HALF_EVEN (1 + 77e-11) inexact rounded', 1.00000000, 1 + 77e-11);
											AddTestCase('addx405:p9 r:HALF_EVEN (1 + 77e-12) inexact rounded', 1.00000000, 1 + 77e-12);
											AddTestCase('addx406:p9 r:HALF_EVEN (1 + 77e-999) inexact rounded', 1.00000000, 1 + 77e-999);
											AddTestCase('addx407:p9 r:HALF_EVEN (1 + 77e-9999999) inexact rounded', 1.00000000, 1 + 77e-9999999);
											AddTestCase('addx410:p9 r:HALF_EVEN (10 + 77e-7)', 10.0000077, 10 + 77e-7);
											AddTestCase('addx411:p9 r:HALF_EVEN (10 + 77e-8) inexact rounded', 10.0000008, 10 + 77e-8);
											AddTestCase('addx412:p9 r:HALF_EVEN (10 + 77e-9) inexact rounded', 10.0000001, 10 + 77e-9);
											AddTestCase('addx413:p9 r:HALF_EVEN (10 + 77e-10) inexact rounded', 10.0000000, 10 + 77e-10);
											AddTestCase('addx414:p9 r:HALF_EVEN (10 + 77e-11) inexact rounded', 10.0000000, 10 + 77e-11);
											AddTestCase('addx415:p9 r:HALF_EVEN (10 + 77e-12) inexact rounded', 10.0000000, 10 + 77e-12);
											AddTestCase('addx416:p9 r:HALF_EVEN (10 + 77e-999) inexact rounded', 10.0000000, 10 + 77e-999);
											AddTestCase('addx417:p9 r:HALF_EVEN (10 + 77e-9999999) inexact rounded', 10.0000000, 10 + 77e-9999999);
											AddTestCase('addx420:p9 r:HALF_EVEN (77e-7 + 1)', 1.0000077, 77e-7 + 1);
											AddTestCase('addx421:p9 r:HALF_EVEN (77e-8 + 1)', 1.00000077, 77e-8 + 1);
											AddTestCase('addx422:p9 r:HALF_EVEN (77e-9 + 1) inexact rounded', 1.00000008, 77e-9 + 1);
											AddTestCase('addx423:p9 r:HALF_EVEN (77e-10 + 1) inexact rounded', 1.00000001, 77e-10 + 1);
											AddTestCase('addx424:p9 r:HALF_EVEN (77e-11 + 1) inexact rounded', 1.00000000, 77e-11 + 1);
											AddTestCase('addx425:p9 r:HALF_EVEN (77e-12 + 1) inexact rounded', 1.00000000, 77e-12 + 1);
											AddTestCase('addx426:p9 r:HALF_EVEN (77e-999 + 1) inexact rounded', 1.00000000, 77e-999 + 1);
											AddTestCase('addx427:p9 r:HALF_EVEN (77e-9999999 + 1) inexact rounded', 1.00000000, 77e-9999999 + 1);
											AddTestCase('addx430:p9 r:HALF_EVEN (77e-7 + 10)', 10.0000077, 77e-7 + 10);
											AddTestCase('addx431:p9 r:HALF_EVEN (77e-8 + 10) inexact rounded', 10.0000008, 77e-8 + 10);
											AddTestCase('addx432:p9 r:HALF_EVEN (77e-9 + 10) inexact rounded', 10.0000001, 77e-9 + 10);
											AddTestCase('addx433:p9 r:HALF_EVEN (77e-10 + 10) inexact rounded', 10.0000000, 77e-10 + 10);
											AddTestCase('addx434:p9 r:HALF_EVEN (77e-11 + 10) inexact rounded', 10.0000000, 77e-11 + 10);
											AddTestCase('addx435:p9 r:HALF_EVEN (77e-12 + 10) inexact rounded', 10.0000000, 77e-12 + 10);
											AddTestCase('addx436:p9 r:HALF_EVEN (77e-999 + 10) inexact rounded', 10.0000000, 77e-999 + 10);
											AddTestCase('addx437:p9 r:HALF_EVEN (77e-9999999 + 10) inexact rounded', 10.0000000, 77e-9999999 + 10);
											// negative ulps
											AddTestCase('addx440:p9 r:HALF_EVEN (1 + -77e-7)', 0.9999923, 1 + -77e-7);
											AddTestCase('addx441:p9 r:HALF_EVEN (1 + -77e-8)', 0.99999923, 1 + -77e-8);
											AddTestCase('addx442:p9 r:HALF_EVEN (1 + -77e-9)', 0.999999923, 1 + -77e-9);
											AddTestCase('addx443:p9 r:HALF_EVEN (1 + -77e-10) inexact rounded', 0.999999992, 1 + -77e-10);
											AddTestCase('addx444:p9 r:HALF_EVEN (1 + -77e-11) inexact rounded', 0.999999999, 1 + -77e-11);
											AddTestCase('addx445:p9 r:HALF_EVEN (1 + -77e-12) inexact rounded', 1.00000000, 1 + -77e-12);
											AddTestCase('addx446:p9 r:HALF_EVEN (1 + -77e-999) inexact rounded', 1.00000000, 1 + -77e-999);
											AddTestCase('addx447:p9 r:HALF_EVEN (1 + -77e-9999999) inexact rounded', 1.00000000, 1 + -77e-9999999);
											AddTestCase('addx450:p9 r:HALF_EVEN (10 + -77e-7)', 9.9999923, 10 + -77e-7);
											AddTestCase('addx451:p9 r:HALF_EVEN (10 + -77e-8)', 9.99999923, 10 + -77e-8);
											AddTestCase('addx452:p9 r:HALF_EVEN (10 + -77e-9) inexact rounded', 9.99999992, 10 + -77e-9);
											AddTestCase('addx453:p9 r:HALF_EVEN (10 + -77e-10) inexact rounded', 9.99999999, 10 + -77e-10);
											AddTestCase('addx454:p9 r:HALF_EVEN (10 + -77e-11) inexact rounded', 10.0000000, 10 + -77e-11);
											AddTestCase('addx455:p9 r:HALF_EVEN (10 + -77e-12) inexact rounded', 10.0000000, 10 + -77e-12);
											AddTestCase('addx456:p9 r:HALF_EVEN (10 + -77e-999) inexact rounded', 10.0000000, 10 + -77e-999);
											AddTestCase('addx457:p9 r:HALF_EVEN (10 + -77e-9999999) inexact rounded', 10.0000000, 10 + -77e-9999999);
											AddTestCase('addx460:p9 r:HALF_EVEN (-77e-7 + 1)', 0.9999923, -77e-7 + 1);
											AddTestCase('addx461:p9 r:HALF_EVEN (-77e-8 + 1)', 0.99999923, -77e-8 + 1);
											AddTestCase('addx462:p9 r:HALF_EVEN (-77e-9 + 1)', 0.999999923, -77e-9 + 1);
											AddTestCase('addx463:p9 r:HALF_EVEN (-77e-10 + 1) inexact rounded', 0.999999992, -77e-10 + 1);
											AddTestCase('addx464:p9 r:HALF_EVEN (-77e-11 + 1) inexact rounded', 0.999999999, -77e-11 + 1);
											AddTestCase('addx465:p9 r:HALF_EVEN (-77e-12 + 1) inexact rounded', 1.00000000, -77e-12 + 1);
											AddTestCase('addx466:p9 r:HALF_EVEN (-77e-999 + 1) inexact rounded', 1.00000000, -77e-999 + 1);
											AddTestCase('addx467:p9 r:HALF_EVEN (-77e-9999999 + 1) inexact rounded', 1.00000000, -77e-9999999 + 1);
											AddTestCase('addx470:p9 r:HALF_EVEN (-77e-7 + 10)', 9.9999923, -77e-7 + 10);
											AddTestCase('addx471:p9 r:HALF_EVEN (-77e-8 + 10)', 9.99999923, -77e-8 + 10);
											AddTestCase('addx472:p9 r:HALF_EVEN (-77e-9 + 10) inexact rounded', 9.99999992, -77e-9 + 10);
											AddTestCase('addx473:p9 r:HALF_EVEN (-77e-10 + 10) inexact rounded', 9.99999999, -77e-10 + 10);
											AddTestCase('addx474:p9 r:HALF_EVEN (-77e-11 + 10) inexact rounded', 10.0000000, -77e-11 + 10);
											AddTestCase('addx475:p9 r:HALF_EVEN (-77e-12 + 10) inexact rounded', 10.0000000, -77e-12 + 10);
											AddTestCase('addx476:p9 r:HALF_EVEN (-77e-999 + 10) inexact rounded', 10.0000000, -77e-999 + 10);
											AddTestCase('addx477:p9 r:HALF_EVEN (-77e-9999999 + 10) inexact rounded', 10.0000000, -77e-9999999 + 10);
											// negative ulps
											AddTestCase('addx480:p9 r:HALF_EVEN (-1 + 77e-7)', -0.9999923, -1 + 77e-7);
											AddTestCase('addx481:p9 r:HALF_EVEN (-1 + 77e-8)', -0.99999923, -1 + 77e-8);
											AddTestCase('addx482:p9 r:HALF_EVEN (-1 + 77e-9)', -0.999999923, -1 + 77e-9);
											AddTestCase('addx483:p9 r:HALF_EVEN (-1 + 77e-10) inexact rounded', -0.999999992, -1 + 77e-10);
											AddTestCase('addx484:p9 r:HALF_EVEN (-1 + 77e-11) inexact rounded', -0.999999999, -1 + 77e-11);
											AddTestCase('addx485:p9 r:HALF_EVEN (-1 + 77e-12) inexact rounded', -1.00000000, -1 + 77e-12);
											AddTestCase('addx486:p9 r:HALF_EVEN (-1 + 77e-999) inexact rounded', -1.00000000, -1 + 77e-999);
											AddTestCase('addx487:p9 r:HALF_EVEN (-1 + 77e-9999999) inexact rounded', -1.00000000, -1 + 77e-9999999);
											AddTestCase('addx490:p9 r:HALF_EVEN (-10 + 77e-7)', -9.9999923, -10 + 77e-7);
											AddTestCase('addx491:p9 r:HALF_EVEN (-10 + 77e-8)', -9.99999923, -10 + 77e-8);
											AddTestCase('addx492:p9 r:HALF_EVEN (-10 + 77e-9) inexact rounded', -9.99999992, -10 + 77e-9);
											AddTestCase('addx493:p9 r:HALF_EVEN (-10 + 77e-10) inexact rounded', -9.99999999, -10 + 77e-10);
											AddTestCase('addx494:p9 r:HALF_EVEN (-10 + 77e-11) inexact rounded', -10.0000000, -10 + 77e-11);
											AddTestCase('addx495:p9 r:HALF_EVEN (-10 + 77e-12) inexact rounded', -10.0000000, -10 + 77e-12);
											AddTestCase('addx496:p9 r:HALF_EVEN (-10 + 77e-999) inexact rounded', -10.0000000, -10 + 77e-999);
											AddTestCase('addx497:p9 r:HALF_EVEN (-10 + 77e-9999999) inexact rounded', -10.0000000, -10 + 77e-9999999);
											AddTestCase('addx500:p9 r:HALF_EVEN (77e-7 + -1)', -0.9999923, 77e-7 + -1);
											AddTestCase('addx501:p9 r:HALF_EVEN (77e-8 + -1)', -0.99999923, 77e-8 + -1);
											AddTestCase('addx502:p9 r:HALF_EVEN (77e-9 + -1)', -0.999999923, 77e-9 + -1);
											AddTestCase('addx503:p9 r:HALF_EVEN (77e-10 + -1) inexact rounded', -0.999999992, 77e-10 + -1);
											AddTestCase('addx504:p9 r:HALF_EVEN (77e-11 + -1) inexact rounded', -0.999999999, 77e-11 + -1);
											AddTestCase('addx505:p9 r:HALF_EVEN (77e-12 + -1) inexact rounded', -1.00000000, 77e-12 + -1);
											AddTestCase('addx506:p9 r:HALF_EVEN (77e-999 + -1) inexact rounded', -1.00000000, 77e-999 + -1);
											AddTestCase('addx507:p9 r:HALF_EVEN (77e-9999999 + -1) inexact rounded', -1.00000000, 77e-9999999 + -1);
											AddTestCase('addx510:p9 r:HALF_EVEN (77e-7 + -10)', -9.9999923, 77e-7 + -10);
											AddTestCase('addx511:p9 r:HALF_EVEN (77e-8 + -10)', -9.99999923, 77e-8 + -10);
											AddTestCase('addx512:p9 r:HALF_EVEN (77e-9 + -10) inexact rounded', -9.99999992, 77e-9 + -10);
											AddTestCase('addx513:p9 r:HALF_EVEN (77e-10 + -10) inexact rounded', -9.99999999, 77e-10 + -10);
											AddTestCase('addx514:p9 r:HALF_EVEN (77e-11 + -10) inexact rounded', -10.0000000, 77e-11 + -10);
											AddTestCase('addx515:p9 r:HALF_EVEN (77e-12 + -10) inexact rounded', -10.0000000, 77e-12 + -10);
											AddTestCase('addx516:p9 r:HALF_EVEN (77e-999 + -10) inexact rounded', -10.0000000, 77e-999 + -10);
											AddTestCase('addx517:p9 r:HALF_EVEN (77e-9999999 + -10) inexact rounded', -10.0000000, 77e-9999999 + -10);
											// long operands
										}
										{
											use precision 9;
											AddTestCase('addx521:p9 r:HALF_EVEN (12345678000 + 0) rounded', 1.23456780e+10, 12345678000 + 0);
											AddTestCase('addx522:p9 r:HALF_EVEN (0 + 12345678000) rounded', 1.23456780e+10, 0 + 12345678000);
											AddTestCase('addx523:p9 r:HALF_EVEN (1234567800 + 0) rounded', 1.23456780e+9, 1234567800 + 0);
											AddTestCase('addx524:p9 r:HALF_EVEN (0 + 1234567800) rounded', 1.23456780e+9, 0 + 1234567800);
											AddTestCase('addx525:p9 r:HALF_EVEN (1234567890 + 0) rounded', 1.23456789e+9, 1234567890 + 0);
											AddTestCase('addx526:p9 r:HALF_EVEN (0 + 1234567890) rounded', 1.23456789e+9, 0 + 1234567890);
											AddTestCase('addx527:p9 r:HALF_EVEN (1234567891 + 0) inexact rounded', 1.23456789e+9, 1234567891 + 0);
											AddTestCase('addx528:p9 r:HALF_EVEN (0 + 1234567891) inexact rounded', 1.23456789e+9, 0 + 1234567891);
											AddTestCase('addx529:p9 r:HALF_EVEN (12345678901 + 0) inexact rounded', 1.23456789e+10, 12345678901 + 0);
											AddTestCase('addx530:p9 r:HALF_EVEN (0 + 12345678901) inexact rounded', 1.23456789e+10, 0 + 12345678901);
											AddTestCase('addx531:p9 r:HALF_EVEN (1234567896 + 0) inexact rounded', 1.23456790e+9, 1234567896 + 0);
											AddTestCase('addx532:p9 r:HALF_EVEN (0 + 1234567896) inexact rounded', 1.23456790e+9, 0 + 1234567896);
										}
										{
											use precision 15;
											// still checking
											AddTestCase('addx541:p15 r:HALF_EVEN (12345678000 + 0)', 12345678000, 12345678000 + 0);
											AddTestCase('addx542:p15 r:HALF_EVEN (0 + 12345678000)', 12345678000, 0 + 12345678000);
											AddTestCase('addx543:p15 r:HALF_EVEN (1234567800 + 0)', 1234567800, 1234567800 + 0);
											AddTestCase('addx544:p15 r:HALF_EVEN (0 + 1234567800)', 1234567800, 0 + 1234567800);
											AddTestCase('addx545:p15 r:HALF_EVEN (1234567890 + 0)', 1234567890, 1234567890 + 0);
											AddTestCase('addx546:p15 r:HALF_EVEN (0 + 1234567890)', 1234567890, 0 + 1234567890);
											AddTestCase('addx547:p15 r:HALF_EVEN (1234567891 + 0)', 1234567891, 1234567891 + 0);
											AddTestCase('addx548:p15 r:HALF_EVEN (0 + 1234567891)', 1234567891, 0 + 1234567891);
											AddTestCase('addx549:p15 r:HALF_EVEN (12345678901 + 0)', 12345678901, 12345678901 + 0);
											AddTestCase('addx550:p15 r:HALF_EVEN (0 + 12345678901)', 12345678901, 0 + 12345678901);
											AddTestCase('addx551:p15 r:HALF_EVEN (1234567896 + 0)', 1234567896, 1234567896 + 0);
											AddTestCase('addx552:p15 r:HALF_EVEN (0 + 1234567896)', 1234567896, 0 + 1234567896);
											// verify a query
										}
										{
											use precision 16;
											// and using decimal64 bounds (see also ddadd.dectest)
										}
										{
											use precision 16;
											// some more residue effects with extreme rounding
										}
										{
											use precision 9;
											{
												use rounding HALF_UP;
												AddTestCase('addx601:p9 r:HALF_UP (123456789 + 0.000001) inexact rounded', 123456789, 123456789 + 0.000001);
											}
											{
												use rounding HALF_EVEN;
												AddTestCase('addx602:p9 r:HALF_EVEN (123456789 + 0.000001) inexact rounded', 123456789, 123456789 + 0.000001);
											}
											{
												use rounding HALF_DOWN;
												AddTestCase('addx603:p9 r:HALF_DOWN (123456789 + 0.000001) inexact rounded', 123456789, 123456789 + 0.000001);
											}
											{
												use rounding FLOOR;
												AddTestCase('addx604:p9 r:FLOOR (123456789 + 0.000001) inexact rounded', 123456789, 123456789 + 0.000001);
											}
											{
												use rounding CEILING;
												AddTestCase('addx605:p9 r:CEILING (123456789 + 0.000001) inexact rounded', 123456790, 123456789 + 0.000001);
											}
											{
												use rounding HALF_UP;
												AddTestCase('addx611:p9 r:HALF_UP (123456789 + -0.000001) inexact rounded', 123456789, 123456789 + -0.000001);
											}
											{
												use rounding HALF_EVEN;
												AddTestCase('addx612:p9 r:HALF_EVEN (123456789 + -0.000001) inexact rounded', 123456789, 123456789 + -0.000001);
											}
											{
												use rounding HALF_DOWN;
												AddTestCase('addx613:p9 r:HALF_DOWN (123456789 + -0.000001) inexact rounded', 123456789, 123456789 + -0.000001);
											}
											{
												use rounding FLOOR;
												AddTestCase('addx614:p9 r:FLOOR (123456789 + -0.000001) inexact rounded', 123456788, 123456789 + -0.000001);
											}
											{
												use rounding CEILING;
												AddTestCase('addx615:p9 r:CEILING (123456789 + -0.000001) inexact rounded', 123456789, 123456789 + -0.000001);
											}
											{
												use rounding HALF_UP;
												AddTestCase('addx621:p9 r:HALF_UP (123456789 + 0.499999) inexact rounded', 123456789, 123456789 + 0.499999);
											}
											{
												use rounding HALF_EVEN;
												AddTestCase('addx622:p9 r:HALF_EVEN (123456789 + 0.499999) inexact rounded', 123456789, 123456789 + 0.499999);
											}
											{
												use rounding HALF_DOWN;
												AddTestCase('addx623:p9 r:HALF_DOWN (123456789 + 0.499999) inexact rounded', 123456789, 123456789 + 0.499999);
											}
											{
												use rounding FLOOR;
												AddTestCase('addx624:p9 r:FLOOR (123456789 + 0.499999) inexact rounded', 123456789, 123456789 + 0.499999);
											}
											{
												use rounding CEILING;
												AddTestCase('addx625:p9 r:CEILING (123456789 + 0.499999) inexact rounded', 123456790, 123456789 + 0.499999);
											}
											{
												use rounding HALF_UP;
												AddTestCase('addx631:p9 r:HALF_UP (123456789 + -0.499999) inexact rounded', 123456789, 123456789 + -0.499999);
											}
											{
												use rounding HALF_EVEN;
												AddTestCase('addx632:p9 r:HALF_EVEN (123456789 + -0.499999) inexact rounded', 123456789, 123456789 + -0.499999);
											}
											{
												use rounding HALF_DOWN;
												AddTestCase('addx633:p9 r:HALF_DOWN (123456789 + -0.499999) inexact rounded', 123456789, 123456789 + -0.499999);
											}
											{
												use rounding FLOOR;
												AddTestCase('addx634:p9 r:FLOOR (123456789 + -0.499999) inexact rounded', 123456788, 123456789 + -0.499999);
											}
											{
												use rounding CEILING;
												AddTestCase('addx635:p9 r:CEILING (123456789 + -0.499999) inexact rounded', 123456789, 123456789 + -0.499999);
											}
											{
												use rounding HALF_UP;
												AddTestCase('addx641:p9 r:HALF_UP (123456789 + 0.500001) inexact rounded', 123456790, 123456789 + 0.500001);
											}
											{
												use rounding HALF_EVEN;
												AddTestCase('addx642:p9 r:HALF_EVEN (123456789 + 0.500001) inexact rounded', 123456790, 123456789 + 0.500001);
											}
											{
												use rounding HALF_DOWN;
												AddTestCase('addx643:p9 r:HALF_DOWN (123456789 + 0.500001) inexact rounded', 123456790, 123456789 + 0.500001);
											}
											{
												use rounding FLOOR;
												AddTestCase('addx644:p9 r:FLOOR (123456789 + 0.500001) inexact rounded', 123456789, 123456789 + 0.500001);
											}
											{
												use rounding CEILING;
												AddTestCase('addx645:p9 r:CEILING (123456789 + 0.500001) inexact rounded', 123456790, 123456789 + 0.500001);
											}
											{
												use rounding HALF_UP;
												AddTestCase('addx651:p9 r:HALF_UP (123456789 + -0.500001) inexact rounded', 123456788, 123456789 + -0.500001);
											}
											{
												use rounding HALF_EVEN;
												AddTestCase('addx652:p9 r:HALF_EVEN (123456789 + -0.500001) inexact rounded', 123456788, 123456789 + -0.500001);
											}
											{
												use rounding HALF_DOWN;
												AddTestCase('addx653:p9 r:HALF_DOWN (123456789 + -0.500001) inexact rounded', 123456788, 123456789 + -0.500001);
											}
											{
												use rounding FLOOR;
												AddTestCase('addx654:p9 r:FLOOR (123456789 + -0.500001) inexact rounded', 123456788, 123456789 + -0.500001);
											}
											{
												use rounding CEILING;
												AddTestCase('addx655:p9 r:CEILING (123456789 + -0.500001) inexact rounded', 123456789, 123456789 + -0.500001);
												// long operand triangle
											}
											{
												use rounding HALF_UP;
												{
													use precision 33;
													AddTestCase('addx664:p33 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.4221102363892233711483, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 32;
													AddTestCase('addx665:p32 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.422110236389223371148, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 31;
													AddTestCase('addx666:p31 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.42211023638922337115, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 30;
													AddTestCase('addx667:p30 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.4221102363892233711, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 29;
													AddTestCase('addx668:p29 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.422110236389223371, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 28;
													AddTestCase('addx669:p28 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.42211023638922337, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 27;
													AddTestCase('addx670:p27 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.4221102363892234, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 26;
													AddTestCase('addx671:p26 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.422110236389223, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 25;
													AddTestCase('addx672:p25 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.42211023638922, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 24;
													AddTestCase('addx673:p24 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.4221102363892, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 23;
													AddTestCase('addx674:p23 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.422110236389, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 22;
													AddTestCase('addx675:p22 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.42211023639, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 21;
													AddTestCase('addx676:p21 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.4221102364, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 20;
													AddTestCase('addx677:p20 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.422110236, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 19;
													AddTestCase('addx678:p19 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.42211024, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 18;
													AddTestCase('addx679:p18 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.4221102, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 17;
													AddTestCase('addx680:p17 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.422110, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 16;
													AddTestCase('addx681:p16 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.42211, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 15;
													AddTestCase('addx682:p15 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.4221, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 14;
													AddTestCase('addx683:p14 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.422, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 13;
													AddTestCase('addx684:p13 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.42, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 12;
													AddTestCase('addx685:p12 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166.4, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 11;
													AddTestCase('addx686:p11 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 98471174166, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 10;
													AddTestCase('addx687:p10 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 9.847117417e+10, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 9;
													AddTestCase('addx688:p9 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 9.84711742e+10, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 8;
													AddTestCase('addx689:p8 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 9.8471174e+10, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 7;
													AddTestCase('addx690:p7 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 9.847117e+10, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 6;
													AddTestCase('addx691:p6 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 9.84712e+10, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 5;
													AddTestCase('addx692:p5 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 9.8471e+10, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 4;
													AddTestCase('addx693:p4 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 9.847e+10, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 3;
													AddTestCase('addx694:p3 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 9.85e+10, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 2;
													AddTestCase('addx695:p2 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 9.8e+10, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
												}
												{
													use precision 1;
													AddTestCase('addx696:p1 r:HALF_UP (98471198160.56524417578665886060 + -23994.14313393939743548945165462) inexact rounded', 1e+11, 98471198160.56524417578665886060 + -23994.14313393939743548945165462);
													// more zeros, etc.
													{
														use rounding HALF_UP;
														{
															use precision 9;
															AddTestCase('addx701:p9 r:HALF_UP (5.00 + 1.00e-3)', 5.00100, 5.00 + 1.00e-3);
															AddTestCase('addx702:p9 r:HALF_UP (00.00 + 0.000)', 0.000, 00.00 + 0.000);
															AddTestCase('addx703:p9 r:HALF_UP (00.00 + 0e-3)', 0.000, 00.00 + 0e-3);
															AddTestCase('addx704:p9 r:HALF_UP (0e-3 + 00.00)', 0.000, 0e-3 + 00.00);
															AddTestCase('addx710:p9 r:HALF_UP (0e+3 + 00.00)', 0.00, 0e+3 + 00.00);
															AddTestCase('addx711:p9 r:HALF_UP (0e+3 + 00.0)', 0.0, 0e+3 + 00.0);
															AddTestCase('addx712:p9 r:HALF_UP (0e+3 + 00.)', 0, 0e+3 + 00.);
															AddTestCase('addx713:p9 r:HALF_UP (0e+3 + 00.e+1)', 0e+1, 0e+3 + 00.e+1);
															AddTestCase('addx714:p9 r:HALF_UP (0e+3 + 00.e+2)', 0e+2, 0e+3 + 00.e+2);
															AddTestCase('addx715:p9 r:HALF_UP (0e+3 + 00.e+3)', 0e+3, 0e+3 + 00.e+3);
															AddTestCase('addx716:p9 r:HALF_UP (0e+3 + 00.e+4)', 0e+3, 0e+3 + 00.e+4);
															AddTestCase('addx717:p9 r:HALF_UP (0e+3 + 00.e+5)', 0e+3, 0e+3 + 00.e+5);
															AddTestCase('addx718:p9 r:HALF_UP (0e+3 + -00.0)', 0.0, 0e+3 + -00.0);
															AddTestCase('addx719:p9 r:HALF_UP (0e+3 + -00.)', 0, 0e+3 + -00.);
															AddTestCase('addx731:p9 r:HALF_UP (0e+3 + -00.e+1)', 0e+1, 0e+3 + -00.e+1);
															AddTestCase('addx720:p9 r:HALF_UP (00.00 + 0e+3)', 0.00, 00.00 + 0e+3);
															AddTestCase('addx721:p9 r:HALF_UP (00.0 + 0e+3)', 0.0, 00.0 + 0e+3);
															AddTestCase('addx722:p9 r:HALF_UP (00. + 0e+3)', 0, 00. + 0e+3);
															AddTestCase('addx723:p9 r:HALF_UP (00.e+1 + 0e+3)', 0e+1, 00.e+1 + 0e+3);
															AddTestCase('addx724:p9 r:HALF_UP (00.e+2 + 0e+3)', 0e+2, 00.e+2 + 0e+3);
															AddTestCase('addx725:p9 r:HALF_UP (00.e+3 + 0e+3)', 0e+3, 00.e+3 + 0e+3);
															AddTestCase('addx726:p9 r:HALF_UP (00.e+4 + 0e+3)', 0e+3, 00.e+4 + 0e+3);
															AddTestCase('addx727:p9 r:HALF_UP (00.e+5 + 0e+3)', 0e+3, 00.e+5 + 0e+3);
															AddTestCase('addx728:p9 r:HALF_UP (-00.00 + 0e+3)', 0.00, -00.00 + 0e+3);
															AddTestCase('addx729:p9 r:HALF_UP (-00.0 + 0e+3)', 0.0, -00.0 + 0e+3);
															AddTestCase('addx730:p9 r:HALF_UP (-00. + 0e+3)', 0, -00. + 0e+3);
															AddTestCase('addx732:p9 r:HALF_UP (0 + 0)', 0, 0 + 0);
															AddTestCase('addx733:p9 r:HALF_UP (0 + -0)', 0, 0 + -0);
															AddTestCase('addx734:p9 r:HALF_UP (-0 + 0)', 0, -0 + 0);
															AddTestCase('addx735:p9 r:HALF_UP (-0 + -0) -- ieee 854 special case', -0, -0 + -0);
															AddTestCase('addx736:p9 r:HALF_UP (1 + -1)', 0, 1 + -1);
															AddTestCase('addx737:p9 r:HALF_UP (-1 + -1)', -2, -1 + -1);
															AddTestCase('addx738:p9 r:HALF_UP (1 + 1)', 2, 1 + 1);
															AddTestCase('addx739:p9 r:HALF_UP (-1 + 1)', 0, -1 + 1);
															AddTestCase('addx741:p9 r:HALF_UP (0 + -1)', -1, 0 + -1);
															AddTestCase('addx742:p9 r:HALF_UP (-0 + -1)', -1, -0 + -1);
															AddTestCase('addx743:p9 r:HALF_UP (0 + 1)', 1, 0 + 1);
															AddTestCase('addx744:p9 r:HALF_UP (-0 + 1)', 1, -0 + 1);
															AddTestCase('addx745:p9 r:HALF_UP (-1 + 0)', -1, -1 + 0);
															AddTestCase('addx746:p9 r:HALF_UP (-1 + -0)', -1, -1 + -0);
															AddTestCase('addx747:p9 r:HALF_UP (1 + 0)', 1, 1 + 0);
															AddTestCase('addx748:p9 r:HALF_UP (1 + -0)', 1, 1 + -0);
															AddTestCase('addx751:p9 r:HALF_UP (0.0 + -1)', -1.0, 0.0 + -1);
															AddTestCase('addx752:p9 r:HALF_UP (-0.0 + -1)', -1.0, -0.0 + -1);
															AddTestCase('addx753:p9 r:HALF_UP (0.0 + 1)', 1.0, 0.0 + 1);
															AddTestCase('addx754:p9 r:HALF_UP (-0.0 + 1)', 1.0, -0.0 + 1);
															AddTestCase('addx755:p9 r:HALF_UP (-1.0 + 0)', -1.0, -1.0 + 0);
															AddTestCase('addx756:p9 r:HALF_UP (-1.0 + -0)', -1.0, -1.0 + -0);
															AddTestCase('addx757:p9 r:HALF_UP (1.0 + 0)', 1.0, 1.0 + 0);
															AddTestCase('addx758:p9 r:HALF_UP (1.0 + -0)', 1.0, 1.0 + -0);
															AddTestCase('addx761:p9 r:HALF_UP (0 + -1.0)', -1.0, 0 + -1.0);
															AddTestCase('addx762:p9 r:HALF_UP (-0 + -1.0)', -1.0, -0 + -1.0);
															AddTestCase('addx763:p9 r:HALF_UP (0 + 1.0)', 1.0, 0 + 1.0);
															AddTestCase('addx764:p9 r:HALF_UP (-0 + 1.0)', 1.0, -0 + 1.0);
															AddTestCase('addx765:p9 r:HALF_UP (-1 + 0.0)', -1.0, -1 + 0.0);
															AddTestCase('addx766:p9 r:HALF_UP (-1 + -0.0)', -1.0, -1 + -0.0);
															AddTestCase('addx767:p9 r:HALF_UP (1 + 0.0)', 1.0, 1 + 0.0);
															AddTestCase('addx768:p9 r:HALF_UP (1 + -0.0)', 1.0, 1 + -0.0);
															AddTestCase('addx771:p9 r:HALF_UP (0.0 + -1.0)', -1.0, 0.0 + -1.0);
															AddTestCase('addx772:p9 r:HALF_UP (-0.0 + -1.0)', -1.0, -0.0 + -1.0);
															AddTestCase('addx773:p9 r:HALF_UP (0.0 + 1.0)', 1.0, 0.0 + 1.0);
															AddTestCase('addx774:p9 r:HALF_UP (-0.0 + 1.0)', 1.0, -0.0 + 1.0);
															AddTestCase('addx775:p9 r:HALF_UP (-1.0 + 0.0)', -1.0, -1.0 + 0.0);
															AddTestCase('addx776:p9 r:HALF_UP (-1.0 + -0.0)', -1.0, -1.0 + -0.0);
															AddTestCase('addx777:p9 r:HALF_UP (1.0 + 0.0)', 1.0, 1.0 + 0.0);
															AddTestCase('addx778:p9 r:HALF_UP (1.0 + -0.0)', 1.0, 1.0 + -0.0);
															// specials
															AddTestCase('addx780:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx781:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + -1000)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + -1000);
															AddTestCase('addx782:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + -1)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + -1);
															AddTestCase('addx783:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + -0)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + -0);
															AddTestCase('addx784:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + 0)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + 0);
															AddTestCase('addx785:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + 1)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + 1);
															AddTestCase('addx786:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + 1000)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + 1000);
															AddTestCase('addx787:p9 r:HALF_UP (-1000 + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, -1000 + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx788:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx789:p9 r:HALF_UP (-1 + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, -1 + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx790:p9 r:HALF_UP (-0 + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, -0 + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx791:p9 r:HALF_UP (0 + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, 0 + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx792:p9 r:HALF_UP (1 + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, 1 + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx793:p9 r:HALF_UP (1000 + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, 1000 + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx794:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx800:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx801:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + -1000)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + -1000);
															AddTestCase('addx802:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + -1)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + -1);
															AddTestCase('addx803:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + -0)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + -0);
															AddTestCase('addx804:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + 0)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + 0);
															AddTestCase('addx805:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + 1)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + 1);
															AddTestCase('addx806:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + 1000)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + 1000);
															AddTestCase('addx807:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + decimal.POSITIVE_INFINITY);
															AddTestCase('addx808:p9 r:HALF_UP (-1000 + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, -1000 + decimal.POSITIVE_INFINITY);
															AddTestCase('addx809:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + decimal.POSITIVE_INFINITY) invalid_operation', NaN, decimal.NEGATIVE_INFINITY + decimal.POSITIVE_INFINITY);
															AddTestCase('addx810:p9 r:HALF_UP (-1 + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, -1 + decimal.POSITIVE_INFINITY);
															AddTestCase('addx811:p9 r:HALF_UP (-0 + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, -0 + decimal.POSITIVE_INFINITY);
															AddTestCase('addx812:p9 r:HALF_UP (0 + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, 0 + decimal.POSITIVE_INFINITY);
															AddTestCase('addx813:p9 r:HALF_UP (1 + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, 1 + decimal.POSITIVE_INFINITY);
															AddTestCase('addx814:p9 r:HALF_UP (1000 + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, 1000 + decimal.POSITIVE_INFINITY);
															AddTestCase('addx815:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + decimal.POSITIVE_INFINITY);
															AddTestCase('addx821:p9 r:HALF_UP (NaN + decimal.NEGATIVE_INFINITY)', NaN, NaN + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx822:p9 r:HALF_UP (NaN + -1000)', NaN, NaN + -1000);
															AddTestCase('addx823:p9 r:HALF_UP (NaN + -1)', NaN, NaN + -1);
															AddTestCase('addx824:p9 r:HALF_UP (NaN + -0)', NaN, NaN + -0);
															AddTestCase('addx825:p9 r:HALF_UP (NaN + 0)', NaN, NaN + 0);
															AddTestCase('addx826:p9 r:HALF_UP (NaN + 1)', NaN, NaN + 1);
															AddTestCase('addx827:p9 r:HALF_UP (NaN + 1000)', NaN, NaN + 1000);
															AddTestCase('addx828:p9 r:HALF_UP (NaN + decimal.POSITIVE_INFINITY)', NaN, NaN + decimal.POSITIVE_INFINITY);
															AddTestCase('addx829:p9 r:HALF_UP (NaN + NaN)', NaN, NaN + NaN);
															AddTestCase('addx830:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + NaN)', NaN, decimal.NEGATIVE_INFINITY + NaN);
															AddTestCase('addx831:p9 r:HALF_UP (-1000 + NaN)', NaN, -1000 + NaN);
															AddTestCase('addx832:p9 r:HALF_UP (-1 + NaN)', NaN, -1 + NaN);
															AddTestCase('addx833:p9 r:HALF_UP (-0 + NaN)', NaN, -0 + NaN);
															AddTestCase('addx834:p9 r:HALF_UP (0 + NaN)', NaN, 0 + NaN);
															AddTestCase('addx835:p9 r:HALF_UP (1 + NaN)', NaN, 1 + NaN);
															AddTestCase('addx836:p9 r:HALF_UP (1000 + NaN)', NaN, 1000 + NaN);
															AddTestCase('addx837:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + NaN)', NaN, decimal.POSITIVE_INFINITY + NaN);
															AddTestCase('addx841:p9 r:HALF_UP (NaN + decimal.NEGATIVE_INFINITY) invalid_operation', NaN, NaN + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx842:p9 r:HALF_UP (NaN + -1000) invalid_operation', NaN, NaN + -1000);
															AddTestCase('addx843:p9 r:HALF_UP (NaN + -1) invalid_operation', NaN, NaN + -1);
															AddTestCase('addx844:p9 r:HALF_UP (NaN + -0) invalid_operation', NaN, NaN + -0);
															AddTestCase('addx845:p9 r:HALF_UP (NaN + 0) invalid_operation', NaN, NaN + 0);
															AddTestCase('addx846:p9 r:HALF_UP (NaN + 1) invalid_operation', NaN, NaN + 1);
															AddTestCase('addx847:p9 r:HALF_UP (NaN + 1000) invalid_operation', NaN, NaN + 1000);
															AddTestCase('addx848:p9 r:HALF_UP (NaN + NaN) invalid_operation', NaN, NaN + NaN);
															AddTestCase('addx849:p9 r:HALF_UP (NaN + NaN) invalid_operation', NaN, NaN + NaN);
															AddTestCase('addx850:p9 r:HALF_UP (NaN + NaN) invalid_operation', NaN, NaN + NaN);
															AddTestCase('addx851:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + NaN) invalid_operation', NaN, decimal.NEGATIVE_INFINITY + NaN);
															AddTestCase('addx852:p9 r:HALF_UP (-1000 + NaN) invalid_operation', NaN, -1000 + NaN);
															AddTestCase('addx853:p9 r:HALF_UP (-1 + NaN) invalid_operation', NaN, -1 + NaN);
															AddTestCase('addx854:p9 r:HALF_UP (-0 + NaN) invalid_operation', NaN, -0 + NaN);
															AddTestCase('addx855:p9 r:HALF_UP (0 + NaN) invalid_operation', NaN, 0 + NaN);
															AddTestCase('addx856:p9 r:HALF_UP (1 + NaN) invalid_operation', NaN, 1 + NaN);
															AddTestCase('addx857:p9 r:HALF_UP (1000 + NaN) invalid_operation', NaN, 1000 + NaN);
															AddTestCase('addx858:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + NaN) invalid_operation', NaN, decimal.POSITIVE_INFINITY + NaN);
															AddTestCase('addx859:p9 r:HALF_UP (NaN + NaN) invalid_operation', NaN, NaN + NaN);
															// propagating nans
															AddTestCase('addx861:p9 r:HALF_UP (NaN + decimal.NEGATIVE_INFINITY)', NaN, NaN + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx862:p9 r:HALF_UP (+NaN + -1000)', NaN, +NaN + -1000);
															AddTestCase('addx863:p9 r:HALF_UP (NaN + 1000)', NaN, NaN + 1000);
															AddTestCase('addx864:p9 r:HALF_UP (NaN + decimal.POSITIVE_INFINITY)', NaN, NaN + decimal.POSITIVE_INFINITY);
															AddTestCase('addx865:p9 r:HALF_UP (NaN + +NaN)', NaN, NaN + +NaN);
															AddTestCase('addx866:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + NaN)', NaN, decimal.NEGATIVE_INFINITY + NaN);
															AddTestCase('addx867:p9 r:HALF_UP (-1000 + NaN)', NaN, -1000 + NaN);
															AddTestCase('addx868:p9 r:HALF_UP (1000 + NaN)', NaN, 1000 + NaN);
															AddTestCase('addx869:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + +NaN)', NaN, decimal.POSITIVE_INFINITY + +NaN);
															AddTestCase('addx871:p9 r:HALF_UP (NaN + decimal.NEGATIVE_INFINITY) invalid_operation', NaN, NaN + decimal.NEGATIVE_INFINITY);
															AddTestCase('addx872:p9 r:HALF_UP (NaN + -1000) invalid_operation', NaN, NaN + -1000);
															AddTestCase('addx873:p9 r:HALF_UP (NaN + 1000) invalid_operation', NaN, NaN + 1000);
															AddTestCase('addx874:p9 r:HALF_UP (NaN + NaN) invalid_operation', NaN, NaN + NaN);
															AddTestCase('addx875:p9 r:HALF_UP (NaN + NaN) invalid_operation', NaN, NaN + NaN);
															AddTestCase('addx876:p9 r:HALF_UP (NaN + NaN) invalid_operation', NaN, NaN + NaN);
															AddTestCase('addx877:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY + +NaN) invalid_operation', NaN, decimal.NEGATIVE_INFINITY + +NaN);
															AddTestCase('addx878:p9 r:HALF_UP (-1000 + NaN) invalid_operation', NaN, -1000 + NaN);
															AddTestCase('addx879:p9 r:HALF_UP (1000 + NaN) invalid_operation', NaN, 1000 + NaN);
															AddTestCase('addx880:p9 r:HALF_UP (decimal.POSITIVE_INFINITY + NaN) invalid_operation', NaN, decimal.POSITIVE_INFINITY + NaN);
															AddTestCase('addx881:p9 r:HALF_UP (+NaN + +NaN) invalid_operation', NaN, +NaN + +NaN);
															AddTestCase('addx882:p9 r:HALF_UP (-NaN + NaN)', -NaN, -NaN + NaN);
															AddTestCase('addx883:p9 r:HALF_UP (-NaN + NaN) invalid_operation', -NaN, -NaN + NaN);
															AddTestCase('addx884:p9 r:HALF_UP (1000 + -NaN)', -NaN, 1000 + -NaN);
															AddTestCase('addx885:p9 r:HALF_UP (1000 + -NaN) invalid_operation', -NaN, 1000 + -NaN);
															// overflow, underflow and subnormal tests
														}
														{
															use precision 9;
															// AddTestCase('addx902:p9 r:HALF_UP (-1e+999999999 + +9e+999999999)', 8e+999999999, -1e+999999999 + +9e+999999999);
															// AddTestCase('addx903:p9 r:HALF_UP (-9e+999999999 + +1e+999999999)', -8e+999999999, -9e+999999999 + +1e+999999999);
														}
														{
															use precision 3;
														}
														{
															use precision 3;
															AddTestCase('addx910:p3 r:HALF_UP (1.00e-999 + 0)', 1.00e-999, 1.00e-999 + 0);
															// next is rounded to nmin
															AddTestCase('addx930:p3 r:HALF_UP (-1.00e-999 + 0)', -1.00e-999, -1.00e-999 + 0);
															// next is rounded to nmin
															// some non-zero subnormal adds
															AddTestCase('addx950:p3 r:HALF_UP (1.00e-999 + 0.1e-999)', 1.10e-999, 1.00e-999 + 0.1e-999);
															AddTestCase('addx955:p3 r:HALF_UP (0.999e-999 + 0.1e-999) inexact rounded', 1.10e-999, 0.999e-999 + 0.1e-999);
															// negatives...
															AddTestCase('addx962:p3 r:HALF_UP (0.1e-999 + -0.1e-999)', 0e-1000, 0.1e-999 + -0.1e-999);
															AddTestCase('addx963:p3 r:HALF_UP (0.10e-999 + -0.1e-999)', 0e-1001, 0.10e-999 + -0.1e-999);
															// some 'real' numbers
														}
														{
															use precision 8;
														}
														{
															use precision 7;
														}
														{
															use precision 6;
															// now the case where we can get underflow but the result is normal
															// [note this can't happen if the operands are also bounded, as we
															// cannot represent 1e-399, for example]
														}
														{
															use precision 16;
															{
																use rounding HALF_UP;
																AddTestCase('addx571:p16 r:HALF_UP (1e-383 + 0)', 1e-383, 1e-383 + 0);
																AddTestCase('addx573:p16 r:HALF_UP (1e-383 + 1e-384)', 1.1e-383, 1e-383 + 1e-384);
																// here we explore the boundary of rounding a subnormal to nmin
																// check overflow edge case
																{
																	use precision 7;
																	{
																		use rounding HALF_UP;
																		AddTestCase('addx973:p7 r:HALF_UP (9.999999e+96 + 1) inexact rounded', 9.999999e+96, 9.999999e+96 + 1);
																		AddTestCase('addx974:p7 r:HALF_UP (9999999e+90 + 1) inexact rounded', 9.999999e+96, 9999999e+90 + 1);
																		AddTestCase('addx981:p7 r:HALF_UP (9999999e+90 + 4e+89) inexact rounded', 9.999999e+96, 9999999e+90 + 4e+89);
																		AddTestCase('addx982:p7 r:HALF_UP (9999999e+90 + 3e+89) inexact rounded', 9.999999e+96, 9999999e+90 + 3e+89);
																		AddTestCase('addx983:p7 r:HALF_UP (9999999e+90 + 2e+89) inexact rounded', 9.999999e+96, 9999999e+90 + 2e+89);
																		AddTestCase('addx984:p7 r:HALF_UP (9999999e+90 + 1e+89) inexact rounded', 9.999999e+96, 9999999e+90 + 1e+89);
																		AddTestCase('addx986:p7 r:HALF_UP (-9.999999e+96 + -1) inexact rounded', -9.999999e+96, -9.999999e+96 + -1);
																		AddTestCase('addx987:p7 r:HALF_UP (-9999999e+90 + -1) inexact rounded', -9.999999e+96, -9999999e+90 + -1);
																		AddTestCase('addx994:p7 r:HALF_UP (-9999999e+90 + -4e+89) inexact rounded', -9.999999e+96, -9999999e+90 + -4e+89);
																		AddTestCase('addx995:p7 r:HALF_UP (-9999999e+90 + -3e+89) inexact rounded', -9.999999e+96, -9999999e+90 + -3e+89);
																		AddTestCase('addx996:p7 r:HALF_UP (-9999999e+90 + -2e+89) inexact rounded', -9.999999e+96, -9999999e+90 + -2e+89);
																		AddTestCase('addx997:p7 r:HALF_UP (-9999999e+90 + -1e+89) inexact rounded', -9.999999e+96, -9999999e+90 + -1e+89);
																		// check for double-rounded subnormals
																		{
																			use precision 5;
																			// add: lhs and rhs 0
																			// add: lhs >> rhs and vice versa
																			// add: lhs + rhs addition carried out
																			// and for round down full and subnormal results
																		}
																		{
																			use precision 16;
																			{
																				use rounding CEILING;
																				AddTestCase('addx1110:p16 r:CEILING (-1e+2 + +1e-383) rounded inexact', -99.99999999999999, -1e+2 + +1e-383);
																				AddTestCase('addx1111:p16 r:CEILING (-1e+1 + +1e-383) rounded inexact', -9.999999999999999, -1e+1 + +1e-383);
																				AddTestCase('addx1113:p16 r:CEILING (-1 + +1e-383) rounded inexact', -0.9999999999999999, -1 + +1e-383);
																				AddTestCase('addx1114:p16 r:CEILING (-1e-1 + +1e-383) rounded inexact', -0.09999999999999999, -1e-1 + +1e-383);
																				AddTestCase('addx1115:p16 r:CEILING (-1e-2 + +1e-383) rounded inexact', -0.009999999999999999, -1e-2 + +1e-383);
																				AddTestCase('addx1116:p16 r:CEILING (-1e-3 + +1e-383) rounded inexact', -0.0009999999999999999, -1e-3 + +1e-383);
																				AddTestCase('addx1117:p16 r:CEILING (-1e-4 + +1e-383) rounded inexact', -0.00009999999999999999, -1e-4 + +1e-383);
																				AddTestCase('addx1118:p16 r:CEILING (-1e-5 + +1e-383) rounded inexact', -0.000009999999999999999, -1e-5 + +1e-383);
																				AddTestCase('addx1119:p16 r:CEILING (-1e-6 + +1e-383) rounded inexact', -9.999999999999999e-7, -1e-6 + +1e-383);
																				{
																					use precision 7;
																					// subnormal boundary
																					// tests based on gunnar degnbol's edge case
																				}
																				{
																					use precision 15;
																					{
																						use rounding HALF_UP;
																						AddTestCase('addx1200:p15 r:HALF_UP (1e15 + -0.5) inexact rounded', 1.00000000000000e+15, 1e15 + -0.5);
																						AddTestCase('addx1201:p15 r:HALF_UP (1e15 + -0.50) inexact rounded', 1.00000000000000e+15, 1e15 + -0.50);
																						AddTestCase('addx1210:p15 r:HALF_UP (1e15 + -0.51) inexact rounded', 999999999999999, 1e15 + -0.51);
																						AddTestCase('addx1211:p15 r:HALF_UP (1e15 + -0.501) inexact rounded', 999999999999999, 1e15 + -0.501);
																						AddTestCase('addx1212:p15 r:HALF_UP (1e15 + -0.5001) inexact rounded', 999999999999999, 1e15 + -0.5001);
																						AddTestCase('addx1213:p15 r:HALF_UP (1e15 + -0.50001) inexact rounded', 999999999999999, 1e15 + -0.50001);
																						AddTestCase('addx1214:p15 r:HALF_UP (1e15 + -0.500001) inexact rounded', 999999999999999, 1e15 + -0.500001);
																						AddTestCase('addx1215:p15 r:HALF_UP (1e15 + -0.5000001) inexact rounded', 999999999999999, 1e15 + -0.5000001);
																						AddTestCase('addx1216:p15 r:HALF_UP (1e15 + -0.50000001) inexact rounded', 999999999999999, 1e15 + -0.50000001);
																						AddTestCase('addx1217:p15 r:HALF_UP (1e15 + -0.500000001) inexact rounded', 999999999999999, 1e15 + -0.500000001);
																						AddTestCase('addx1218:p15 r:HALF_UP (1e15 + -0.5000000001) inexact rounded', 999999999999999, 1e15 + -0.5000000001);
																						AddTestCase('addx1219:p15 r:HALF_UP (1e15 + -0.50000000001) inexact rounded', 999999999999999, 1e15 + -0.50000000001);
																						AddTestCase('addx1220:p15 r:HALF_UP (1e15 + -0.500000000001) inexact rounded', 999999999999999, 1e15 + -0.500000000001);
																						AddTestCase('addx1221:p15 r:HALF_UP (1e15 + -0.5000000000001) inexact rounded', 999999999999999, 1e15 + -0.5000000000001);
																						AddTestCase('addx1222:p15 r:HALF_UP (1e15 + -0.50000000000001) inexact rounded', 999999999999999, 1e15 + -0.50000000000001);
																						AddTestCase('addx1223:p15 r:HALF_UP (1e15 + -0.500000000000001) inexact rounded', 999999999999999, 1e15 + -0.500000000000001);
																						AddTestCase('addx1224:p15 r:HALF_UP (1e15 + -0.5000000000000001) inexact rounded', 999999999999999, 1e15 + -0.5000000000000001);
																						AddTestCase('addx1225:p15 r:HALF_UP (1e15 + -0.5000000000000000) inexact rounded', 1.00000000000000e+15, 1e15 + -0.5000000000000000);
																						AddTestCase('addx1230:p15 r:HALF_UP (1e15 + -5000000.000000001) inexact rounded', 999999995000000, 1e15 + -5000000.000000001);
																						{
																							use precision 16;
																							AddTestCase('addx1300:p16 r:HALF_UP (1e16 + -0.5) inexact rounded', 1.000000000000000e+16, 1e16 + -0.5);
																							AddTestCase('addx1310:p16 r:HALF_UP (1e16 + -0.51) inexact rounded', 9999999999999999, 1e16 + -0.51);
																							AddTestCase('addx1311:p16 r:HALF_UP (1e16 + -0.501) inexact rounded', 9999999999999999, 1e16 + -0.501);
																							AddTestCase('addx1312:p16 r:HALF_UP (1e16 + -0.5001) inexact rounded', 9999999999999999, 1e16 + -0.5001);
																							AddTestCase('addx1313:p16 r:HALF_UP (1e16 + -0.50001) inexact rounded', 9999999999999999, 1e16 + -0.50001);
																							AddTestCase('addx1314:p16 r:HALF_UP (1e16 + -0.500001) inexact rounded', 9999999999999999, 1e16 + -0.500001);
																							AddTestCase('addx1315:p16 r:HALF_UP (1e16 + -0.5000001) inexact rounded', 9999999999999999, 1e16 + -0.5000001);
																							AddTestCase('addx1316:p16 r:HALF_UP (1e16 + -0.50000001) inexact rounded', 9999999999999999, 1e16 + -0.50000001);
																							AddTestCase('addx1317:p16 r:HALF_UP (1e16 + -0.500000001) inexact rounded', 9999999999999999, 1e16 + -0.500000001);
																							AddTestCase('addx1318:p16 r:HALF_UP (1e16 + -0.5000000001) inexact rounded', 9999999999999999, 1e16 + -0.5000000001);
																							AddTestCase('addx1319:p16 r:HALF_UP (1e16 + -0.50000000001) inexact rounded', 9999999999999999, 1e16 + -0.50000000001);
																							AddTestCase('addx1320:p16 r:HALF_UP (1e16 + -0.500000000001) inexact rounded', 9999999999999999, 1e16 + -0.500000000001);
																							AddTestCase('addx1321:p16 r:HALF_UP (1e16 + -0.5000000000001) inexact rounded', 9999999999999999, 1e16 + -0.5000000000001);
																							AddTestCase('addx1322:p16 r:HALF_UP (1e16 + -0.50000000000001) inexact rounded', 9999999999999999, 1e16 + -0.50000000000001);
																							AddTestCase('addx1323:p16 r:HALF_UP (1e16 + -0.500000000000001) inexact rounded', 9999999999999999, 1e16 + -0.500000000000001);
																							AddTestCase('addx1324:p16 r:HALF_UP (1e16 + -0.5000000000000001) inexact rounded', 9999999999999999, 1e16 + -0.5000000000000001);
																							AddTestCase('addx1325:p16 r:HALF_UP (1e16 + -0.5000000000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.5000000000000000);
																							AddTestCase('addx1326:p16 r:HALF_UP (1e16 + -0.500000000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.500000000000000);
																							AddTestCase('addx1327:p16 r:HALF_UP (1e16 + -0.50000000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.50000000000000);
																							AddTestCase('addx1328:p16 r:HALF_UP (1e16 + -0.5000000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.5000000000000);
																							AddTestCase('addx1329:p16 r:HALF_UP (1e16 + -0.500000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.500000000000);
																							AddTestCase('addx1330:p16 r:HALF_UP (1e16 + -0.50000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.50000000000);
																							AddTestCase('addx1331:p16 r:HALF_UP (1e16 + -0.5000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.5000000000);
																							AddTestCase('addx1332:p16 r:HALF_UP (1e16 + -0.500000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.500000000);
																							AddTestCase('addx1333:p16 r:HALF_UP (1e16 + -0.50000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.50000000);
																							AddTestCase('addx1334:p16 r:HALF_UP (1e16 + -0.5000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.5000000);
																							AddTestCase('addx1335:p16 r:HALF_UP (1e16 + -0.500000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.500000);
																							AddTestCase('addx1336:p16 r:HALF_UP (1e16 + -0.50000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.50000);
																							AddTestCase('addx1337:p16 r:HALF_UP (1e16 + -0.5000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.5000);
																							AddTestCase('addx1338:p16 r:HALF_UP (1e16 + -0.500) inexact rounded', 1.000000000000000e+16, 1e16 + -0.500);
																							AddTestCase('addx1339:p16 r:HALF_UP (1e16 + -0.50) inexact rounded', 1.000000000000000e+16, 1e16 + -0.50);
																							AddTestCase('addx1340:p16 r:HALF_UP (1e16 + -5000000.000010001) inexact rounded', 9999999995000000, 1e16 + -5000000.000010001);
																							AddTestCase('addx1341:p16 r:HALF_UP (1e16 + -5000000.000000001) inexact rounded', 9999999995000000, 1e16 + -5000000.000000001);
																							AddTestCase('addx1349:p16 r:HALF_UP (9999999999999999 + 0.4) inexact rounded', 9999999999999999, 9999999999999999 + 0.4);
																							AddTestCase('addx1350:p16 r:HALF_UP (9999999999999999 + 0.49) inexact rounded', 9999999999999999, 9999999999999999 + 0.49);
																							AddTestCase('addx1351:p16 r:HALF_UP (9999999999999999 + 0.499) inexact rounded', 9999999999999999, 9999999999999999 + 0.499);
																							AddTestCase('addx1352:p16 r:HALF_UP (9999999999999999 + 0.4999) inexact rounded', 9999999999999999, 9999999999999999 + 0.4999);
																							AddTestCase('addx1353:p16 r:HALF_UP (9999999999999999 + 0.49999) inexact rounded', 9999999999999999, 9999999999999999 + 0.49999);
																							AddTestCase('addx1354:p16 r:HALF_UP (9999999999999999 + 0.499999) inexact rounded', 9999999999999999, 9999999999999999 + 0.499999);
																							AddTestCase('addx1355:p16 r:HALF_UP (9999999999999999 + 0.4999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.4999999);
																							AddTestCase('addx1356:p16 r:HALF_UP (9999999999999999 + 0.49999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.49999999);
																							AddTestCase('addx1357:p16 r:HALF_UP (9999999999999999 + 0.499999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.499999999);
																							AddTestCase('addx1358:p16 r:HALF_UP (9999999999999999 + 0.4999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.4999999999);
																							AddTestCase('addx1359:p16 r:HALF_UP (9999999999999999 + 0.49999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.49999999999);
																							AddTestCase('addx1360:p16 r:HALF_UP (9999999999999999 + 0.499999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.499999999999);
																							AddTestCase('addx1361:p16 r:HALF_UP (9999999999999999 + 0.4999999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.4999999999999);
																							AddTestCase('addx1362:p16 r:HALF_UP (9999999999999999 + 0.49999999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.49999999999999);
																							AddTestCase('addx1363:p16 r:HALF_UP (9999999999999999 + 0.499999999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.499999999999999);
																							AddTestCase('addx1364:p16 r:HALF_UP (9999999999999999 + 0.4999999999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.4999999999999999);
																							AddTestCase('addx1365:p16 r:HALF_UP (9999999999999999 + 0.5000000000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000000000000);
																							AddTestCase('addx1367:p16 r:HALF_UP (9999999999999999 + 0.500000000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000000000000);
																							AddTestCase('addx1368:p16 r:HALF_UP (9999999999999999 + 0.50000000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000000000000);
																							AddTestCase('addx1369:p16 r:HALF_UP (9999999999999999 + 0.5000000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000000000);
																							AddTestCase('addx1370:p16 r:HALF_UP (9999999999999999 + 0.500000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000000000);
																							AddTestCase('addx1371:p16 r:HALF_UP (9999999999999999 + 0.50000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000000000);
																							AddTestCase('addx1372:p16 r:HALF_UP (9999999999999999 + 0.5000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000000);
																							AddTestCase('addx1373:p16 r:HALF_UP (9999999999999999 + 0.500000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000000);
																							AddTestCase('addx1374:p16 r:HALF_UP (9999999999999999 + 0.50000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000000);
																							AddTestCase('addx1375:p16 r:HALF_UP (9999999999999999 + 0.5000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000);
																							AddTestCase('addx1376:p16 r:HALF_UP (9999999999999999 + 0.500000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000);
																							AddTestCase('addx1377:p16 r:HALF_UP (9999999999999999 + 0.50000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000);
																							AddTestCase('addx1378:p16 r:HALF_UP (9999999999999999 + 0.5000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000);
																							AddTestCase('addx1379:p16 r:HALF_UP (9999999999999999 + 0.500) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500);
																							AddTestCase('addx1380:p16 r:HALF_UP (9999999999999999 + 0.50) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50);
																							AddTestCase('addx1381:p16 r:HALF_UP (9999999999999999 + 0.5) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5);
																							AddTestCase('addx1382:p16 r:HALF_UP (9999999999999999 + 0.5000000000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000000000001);
																							AddTestCase('addx1383:p16 r:HALF_UP (9999999999999999 + 0.500000000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000000000001);
																							AddTestCase('addx1384:p16 r:HALF_UP (9999999999999999 + 0.50000000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000000000001);
																							AddTestCase('addx1385:p16 r:HALF_UP (9999999999999999 + 0.5000000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000000001);
																							AddTestCase('addx1386:p16 r:HALF_UP (9999999999999999 + 0.500000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000000001);
																							AddTestCase('addx1387:p16 r:HALF_UP (9999999999999999 + 0.50000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000000001);
																							AddTestCase('addx1388:p16 r:HALF_UP (9999999999999999 + 0.5000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000001);
																							AddTestCase('addx1389:p16 r:HALF_UP (9999999999999999 + 0.500000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000001);
																							AddTestCase('addx1390:p16 r:HALF_UP (9999999999999999 + 0.50000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000001);
																							AddTestCase('addx1391:p16 r:HALF_UP (9999999999999999 + 0.5000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000001);
																							AddTestCase('addx1392:p16 r:HALF_UP (9999999999999999 + 0.500001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500001);
																							AddTestCase('addx1393:p16 r:HALF_UP (9999999999999999 + 0.50001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50001);
																							AddTestCase('addx1394:p16 r:HALF_UP (9999999999999999 + 0.5001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5001);
																							AddTestCase('addx1395:p16 r:HALF_UP (9999999999999999 + 0.501) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.501);
																							AddTestCase('addx1396:p16 r:HALF_UP (9999999999999999 + 0.51) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.51);
																							// more gd edge cases, where difference between the unadjusted
																							// exponents is larger than the maximum precision and one side is 0
																						}
																						{
																							use precision 15;
																							{
																								use rounding HALF_UP;
																								AddTestCase('addx1400:p15 r:HALF_UP (0 + 1.23456789012345)', 1.23456789012345, 0 + 1.23456789012345);
																								AddTestCase('addx1401:p15 r:HALF_UP (0 + 1.23456789012345e-1)', 0.123456789012345, 0 + 1.23456789012345e-1);
																								AddTestCase('addx1402:p15 r:HALF_UP (0 + 1.23456789012345e-2)', 0.0123456789012345, 0 + 1.23456789012345e-2);
																								AddTestCase('addx1403:p15 r:HALF_UP (0 + 1.23456789012345e-3)', 0.00123456789012345, 0 + 1.23456789012345e-3);
																								AddTestCase('addx1404:p15 r:HALF_UP (0 + 1.23456789012345e-4)', 0.000123456789012345, 0 + 1.23456789012345e-4);
																								AddTestCase('addx1405:p15 r:HALF_UP (0 + 1.23456789012345e-5)', 0.0000123456789012345, 0 + 1.23456789012345e-5);
																								AddTestCase('addx1406:p15 r:HALF_UP (0 + 1.23456789012345e-6)', 0.00000123456789012345, 0 + 1.23456789012345e-6);
																								AddTestCase('addx1407:p15 r:HALF_UP (0 + 1.23456789012345e-7)', 1.23456789012345e-7, 0 + 1.23456789012345e-7);
																								AddTestCase('addx1408:p15 r:HALF_UP (0 + 1.23456789012345e-8)', 1.23456789012345e-8, 0 + 1.23456789012345e-8);
																								AddTestCase('addx1409:p15 r:HALF_UP (0 + 1.23456789012345e-9)', 1.23456789012345e-9, 0 + 1.23456789012345e-9);
																								AddTestCase('addx1410:p15 r:HALF_UP (0 + 1.23456789012345e-10)', 1.23456789012345e-10, 0 + 1.23456789012345e-10);
																								AddTestCase('addx1411:p15 r:HALF_UP (0 + 1.23456789012345e-11)', 1.23456789012345e-11, 0 + 1.23456789012345e-11);
																								AddTestCase('addx1412:p15 r:HALF_UP (0 + 1.23456789012345e-12)', 1.23456789012345e-12, 0 + 1.23456789012345e-12);
																								AddTestCase('addx1413:p15 r:HALF_UP (0 + 1.23456789012345e-13)', 1.23456789012345e-13, 0 + 1.23456789012345e-13);
																								AddTestCase('addx1414:p15 r:HALF_UP (0 + 1.23456789012345e-14)', 1.23456789012345e-14, 0 + 1.23456789012345e-14);
																								AddTestCase('addx1415:p15 r:HALF_UP (0 + 1.23456789012345e-15)', 1.23456789012345e-15, 0 + 1.23456789012345e-15);
																								AddTestCase('addx1416:p15 r:HALF_UP (0 + 1.23456789012345e-16)', 1.23456789012345e-16, 0 + 1.23456789012345e-16);
																								AddTestCase('addx1417:p15 r:HALF_UP (0 + 1.23456789012345e-17)', 1.23456789012345e-17, 0 + 1.23456789012345e-17);
																								AddTestCase('addx1418:p15 r:HALF_UP (0 + 1.23456789012345e-18)', 1.23456789012345e-18, 0 + 1.23456789012345e-18);
																								AddTestCase('addx1419:p15 r:HALF_UP (0 + 1.23456789012345e-19)', 1.23456789012345e-19, 0 + 1.23456789012345e-19);
																								// same, precision 16..
																								{
																									use precision 16;
																									AddTestCase('addx1420:p16 r:HALF_UP (0 + 1.123456789012345)', 1.123456789012345, 0 + 1.123456789012345);
																									AddTestCase('addx1421:p16 r:HALF_UP (0 + 1.123456789012345e-1)', 0.1123456789012345, 0 + 1.123456789012345e-1);
																									AddTestCase('addx1422:p16 r:HALF_UP (0 + 1.123456789012345e-2)', 0.01123456789012345, 0 + 1.123456789012345e-2);
																									AddTestCase('addx1423:p16 r:HALF_UP (0 + 1.123456789012345e-3)', 0.001123456789012345, 0 + 1.123456789012345e-3);
																									AddTestCase('addx1424:p16 r:HALF_UP (0 + 1.123456789012345e-4)', 0.0001123456789012345, 0 + 1.123456789012345e-4);
																									AddTestCase('addx1425:p16 r:HALF_UP (0 + 1.123456789012345e-5)', 0.00001123456789012345, 0 + 1.123456789012345e-5);
																									AddTestCase('addx1426:p16 r:HALF_UP (0 + 1.123456789012345e-6)', 0.000001123456789012345, 0 + 1.123456789012345e-6);
																									AddTestCase('addx1427:p16 r:HALF_UP (0 + 1.123456789012345e-7)', 1.123456789012345e-7, 0 + 1.123456789012345e-7);
																									AddTestCase('addx1428:p16 r:HALF_UP (0 + 1.123456789012345e-8)', 1.123456789012345e-8, 0 + 1.123456789012345e-8);
																									AddTestCase('addx1429:p16 r:HALF_UP (0 + 1.123456789012345e-9)', 1.123456789012345e-9, 0 + 1.123456789012345e-9);
																									AddTestCase('addx1430:p16 r:HALF_UP (0 + 1.123456789012345e-10)', 1.123456789012345e-10, 0 + 1.123456789012345e-10);
																									AddTestCase('addx1431:p16 r:HALF_UP (0 + 1.123456789012345e-11)', 1.123456789012345e-11, 0 + 1.123456789012345e-11);
																									AddTestCase('addx1432:p16 r:HALF_UP (0 + 1.123456789012345e-12)', 1.123456789012345e-12, 0 + 1.123456789012345e-12);
																									AddTestCase('addx1433:p16 r:HALF_UP (0 + 1.123456789012345e-13)', 1.123456789012345e-13, 0 + 1.123456789012345e-13);
																									AddTestCase('addx1434:p16 r:HALF_UP (0 + 1.123456789012345e-14)', 1.123456789012345e-14, 0 + 1.123456789012345e-14);
																									AddTestCase('addx1435:p16 r:HALF_UP (0 + 1.123456789012345e-15)', 1.123456789012345e-15, 0 + 1.123456789012345e-15);
																									AddTestCase('addx1436:p16 r:HALF_UP (0 + 1.123456789012345e-16)', 1.123456789012345e-16, 0 + 1.123456789012345e-16);
																									AddTestCase('addx1437:p16 r:HALF_UP (0 + 1.123456789012345e-17)', 1.123456789012345e-17, 0 + 1.123456789012345e-17);
																									AddTestCase('addx1438:p16 r:HALF_UP (0 + 1.123456789012345e-18)', 1.123456789012345e-18, 0 + 1.123456789012345e-18);
																									AddTestCase('addx1439:p16 r:HALF_UP (0 + 1.123456789012345e-19)', 1.123456789012345e-19, 0 + 1.123456789012345e-19);
																									// same, reversed 0
																									AddTestCase('addx1440:p16 r:HALF_UP (1.123456789012345 + 0)', 1.123456789012345, 1.123456789012345 + 0);
																									AddTestCase('addx1441:p16 r:HALF_UP (1.123456789012345e-1 + 0)', 0.1123456789012345, 1.123456789012345e-1 + 0);
																									AddTestCase('addx1442:p16 r:HALF_UP (1.123456789012345e-2 + 0)', 0.01123456789012345, 1.123456789012345e-2 + 0);
																									AddTestCase('addx1443:p16 r:HALF_UP (1.123456789012345e-3 + 0)', 0.001123456789012345, 1.123456789012345e-3 + 0);
																									AddTestCase('addx1444:p16 r:HALF_UP (1.123456789012345e-4 + 0)', 0.0001123456789012345, 1.123456789012345e-4 + 0);
																									AddTestCase('addx1445:p16 r:HALF_UP (1.123456789012345e-5 + 0)', 0.00001123456789012345, 1.123456789012345e-5 + 0);
																									AddTestCase('addx1446:p16 r:HALF_UP (1.123456789012345e-6 + 0)', 0.000001123456789012345, 1.123456789012345e-6 + 0);
																									AddTestCase('addx1447:p16 r:HALF_UP (1.123456789012345e-7 + 0)', 1.123456789012345e-7, 1.123456789012345e-7 + 0);
																									AddTestCase('addx1448:p16 r:HALF_UP (1.123456789012345e-8 + 0)', 1.123456789012345e-8, 1.123456789012345e-8 + 0);
																									AddTestCase('addx1449:p16 r:HALF_UP (1.123456789012345e-9 + 0)', 1.123456789012345e-9, 1.123456789012345e-9 + 0);
																									AddTestCase('addx1450:p16 r:HALF_UP (1.123456789012345e-10 + 0)', 1.123456789012345e-10, 1.123456789012345e-10 + 0);
																									AddTestCase('addx1451:p16 r:HALF_UP (1.123456789012345e-11 + 0)', 1.123456789012345e-11, 1.123456789012345e-11 + 0);
																									AddTestCase('addx1452:p16 r:HALF_UP (1.123456789012345e-12 + 0)', 1.123456789012345e-12, 1.123456789012345e-12 + 0);
																									AddTestCase('addx1453:p16 r:HALF_UP (1.123456789012345e-13 + 0)', 1.123456789012345e-13, 1.123456789012345e-13 + 0);
																									AddTestCase('addx1454:p16 r:HALF_UP (1.123456789012345e-14 + 0)', 1.123456789012345e-14, 1.123456789012345e-14 + 0);
																									AddTestCase('addx1455:p16 r:HALF_UP (1.123456789012345e-15 + 0)', 1.123456789012345e-15, 1.123456789012345e-15 + 0);
																									AddTestCase('addx1456:p16 r:HALF_UP (1.123456789012345e-16 + 0)', 1.123456789012345e-16, 1.123456789012345e-16 + 0);
																									AddTestCase('addx1457:p16 r:HALF_UP (1.123456789012345e-17 + 0)', 1.123456789012345e-17, 1.123456789012345e-17 + 0);
																									AddTestCase('addx1458:p16 r:HALF_UP (1.123456789012345e-18 + 0)', 1.123456789012345e-18, 1.123456789012345e-18 + 0);
																									AddTestCase('addx1459:p16 r:HALF_UP (1.123456789012345e-19 + 0)', 1.123456789012345e-19, 1.123456789012345e-19 + 0);
																									// same, es on the 0
																									AddTestCase('addx1460:p16 r:HALF_UP (1.123456789012345 + 0e-0)', 1.123456789012345, 1.123456789012345 + 0e-0);
																									AddTestCase('addx1461:p16 r:HALF_UP (1.123456789012345 + 0e-1)', 1.123456789012345, 1.123456789012345 + 0e-1);
																									AddTestCase('addx1462:p16 r:HALF_UP (1.123456789012345 + 0e-2)', 1.123456789012345, 1.123456789012345 + 0e-2);
																									AddTestCase('addx1463:p16 r:HALF_UP (1.123456789012345 + 0e-3)', 1.123456789012345, 1.123456789012345 + 0e-3);
																									AddTestCase('addx1464:p16 r:HALF_UP (1.123456789012345 + 0e-4)', 1.123456789012345, 1.123456789012345 + 0e-4);
																									AddTestCase('addx1465:p16 r:HALF_UP (1.123456789012345 + 0e-5)', 1.123456789012345, 1.123456789012345 + 0e-5);
																									AddTestCase('addx1466:p16 r:HALF_UP (1.123456789012345 + 0e-6)', 1.123456789012345, 1.123456789012345 + 0e-6);
																									AddTestCase('addx1467:p16 r:HALF_UP (1.123456789012345 + 0e-7)', 1.123456789012345, 1.123456789012345 + 0e-7);
																									AddTestCase('addx1468:p16 r:HALF_UP (1.123456789012345 + 0e-8)', 1.123456789012345, 1.123456789012345 + 0e-8);
																									AddTestCase('addx1469:p16 r:HALF_UP (1.123456789012345 + 0e-9)', 1.123456789012345, 1.123456789012345 + 0e-9);
																									AddTestCase('addx1470:p16 r:HALF_UP (1.123456789012345 + 0e-10)', 1.123456789012345, 1.123456789012345 + 0e-10);
																									AddTestCase('addx1471:p16 r:HALF_UP (1.123456789012345 + 0e-11)', 1.123456789012345, 1.123456789012345 + 0e-11);
																									AddTestCase('addx1472:p16 r:HALF_UP (1.123456789012345 + 0e-12)', 1.123456789012345, 1.123456789012345 + 0e-12);
																									AddTestCase('addx1473:p16 r:HALF_UP (1.123456789012345 + 0e-13)', 1.123456789012345, 1.123456789012345 + 0e-13);
																									AddTestCase('addx1474:p16 r:HALF_UP (1.123456789012345 + 0e-14)', 1.123456789012345, 1.123456789012345 + 0e-14);
																									AddTestCase('addx1475:p16 r:HALF_UP (1.123456789012345 + 0e-15)', 1.123456789012345, 1.123456789012345 + 0e-15);
																									// next four flag rounded because the 0 extends the result
																									AddTestCase('addx1476:p16 r:HALF_UP (1.123456789012345 + 0e-16) rounded', 1.123456789012345, 1.123456789012345 + 0e-16);
																									AddTestCase('addx1477:p16 r:HALF_UP (1.123456789012345 + 0e-17) rounded', 1.123456789012345, 1.123456789012345 + 0e-17);
																									AddTestCase('addx1478:p16 r:HALF_UP (1.123456789012345 + 0e-18) rounded', 1.123456789012345, 1.123456789012345 + 0e-18);
																									AddTestCase('addx1479:p16 r:HALF_UP (1.123456789012345 + 0e-19) rounded', 1.123456789012345, 1.123456789012345 + 0e-19);
																									// sum of two opposite-sign operands is exactly 0 and floor => -0
																								}
																								{
																									use precision 16;
																									{
																										use rounding HALF_UP;
																										// exact zeros from zeros
																										AddTestCase('addx1500:p16 r:HALF_UP (0 + 0e-19)', 0e-19, 0 + 0e-19);
																										AddTestCase('addx1501:p16 r:HALF_UP (-0 + 0e-19)', 0e-19, -0 + 0e-19);
																										AddTestCase('addx1502:p16 r:HALF_UP (0 + -0e-19)', 0e-19, 0 + -0e-19);
																										AddTestCase('addx1503:p16 r:HALF_UP (-0 + -0e-19)', -0e-19, -0 + -0e-19);
																										// inexact zeros
																										// some exact zeros from non-zeros
																									}
																									{
																										use rounding HALF_DOWN;
																										// exact zeros from zeros
																										AddTestCase('addx1520:p16 r:HALF_DOWN (0 + 0e-19)', 0e-19, 0 + 0e-19);
																										AddTestCase('addx1521:p16 r:HALF_DOWN (-0 + 0e-19)', 0e-19, -0 + 0e-19);
																										AddTestCase('addx1522:p16 r:HALF_DOWN (0 + -0e-19)', 0e-19, 0 + -0e-19);
																										AddTestCase('addx1523:p16 r:HALF_DOWN (-0 + -0e-19)', -0e-19, -0 + -0e-19);
																										// inexact zeros
																										// some exact zeros from non-zeros
																									}
																									{
																										use rounding HALF_EVEN;
																										// exact zeros from zeros
																										AddTestCase('addx1540:p16 r:HALF_EVEN (0 + 0e-19)', 0e-19, 0 + 0e-19);
																										AddTestCase('addx1541:p16 r:HALF_EVEN (-0 + 0e-19)', 0e-19, -0 + 0e-19);
																										AddTestCase('addx1542:p16 r:HALF_EVEN (0 + -0e-19)', 0e-19, 0 + -0e-19);
																										AddTestCase('addx1543:p16 r:HALF_EVEN (-0 + -0e-19)', -0e-19, -0 + -0e-19);
																										// inexact zeros
																										// some exact zeros from non-zeros
																										// exact zeros from zeros
																										// inexact zeros
																										// some exact zeros from non-zeros
																										// exact zeros from zeros
																										// inexact zeros
																										// some exact zeros from non-zeros
																									}
																									{
																										use rounding CEILING;
																										// exact zeros from zeros
																										AddTestCase('addx1600:p16 r:CEILING (0 + 0e-19)', 0e-19, 0 + 0e-19);
																										AddTestCase('addx1601:p16 r:CEILING (-0 + 0e-19)', 0e-19, -0 + 0e-19);
																										AddTestCase('addx1602:p16 r:CEILING (0 + -0e-19)', 0e-19, 0 + -0e-19);
																										AddTestCase('addx1603:p16 r:CEILING (-0 + -0e-19)', -0e-19, -0 + -0e-19);
																										// inexact zeros
																										// some exact zeros from non-zeros
																										// and the extra-special ugly case; unusual minuses marked by -- *
																									}
																									{
																										use rounding FLOOR;
																										// exact zeros from zeros
																										AddTestCase('addx1620:p16 r:FLOOR (0 + 0e-19)', 0e-19, 0 + 0e-19);
																										AddTestCase('addx1621:p16 r:FLOOR (-0 + 0e-19) -- *', -0e-19, -0 + 0e-19);
																										AddTestCase('addx1622:p16 r:FLOOR (0 + -0e-19) -- *', -0e-19, 0 + -0e-19);
																										AddTestCase('addx1623:p16 r:FLOOR (-0 + -0e-19)', -0e-19, -0 + -0e-19);
																										// inexact zeros
																										// some exact zeros from non-zeros
																										// bigdecimal problem testcases 2006.01.23
																										{
																											use precision 16;
																										}
																										{
																											use precision 7;
																										}
																										{
																											use precision 6;
																										}
																										{
																											use precision 5;
																										}
																										{
																											use precision 4;
																										}
																										{
																											use precision 3;
																										}
																										{
																											use precision 2;
																										}
																										{
																											use precision 1;
																											{
																												use rounding HALF_EVEN;
																												{
																													use precision 7;
																													AddTestCase('addx1661:p7 r:HALF_EVEN (10001e+2 + -2e+1)', 1.00008e+6, 10001e+2 + -2e+1);
																												}
																												{
																													use precision 6;
																													AddTestCase('addx1662:p6 r:HALF_EVEN (10001e+2 + -2e+1)', 1.00008e+6, 10001e+2 + -2e+1);
																												}
																												{
																													use precision 5;
																													AddTestCase('addx1663:p5 r:HALF_EVEN (10001e+2 + -2e+1) inexact rounded', 1.0001e+6, 10001e+2 + -2e+1);
																												}
																												{
																													use precision 4;
																													AddTestCase('addx1664:p4 r:HALF_EVEN (10001e+2 + -2e+1) inexact rounded', 1.000e+6, 10001e+2 + -2e+1);
																												}
																												{
																													use precision 3;
																													AddTestCase('addx1665:p3 r:HALF_EVEN (10001e+2 + -2e+1) inexact rounded', 1.00e+6, 10001e+2 + -2e+1);
																												}
																												{
																													use precision 2;
																													AddTestCase('addx1666:p2 r:HALF_EVEN (10001e+2 + -2e+1) inexact rounded', 1.0e+6, 10001e+2 + -2e+1);
																												}
																												{
																													use precision 1;
																													AddTestCase('addx1667:p1 r:HALF_EVEN (10001e+2 + -2e+1) inexact rounded', 1e+6, 10001e+2 + -2e+1);
																												}
																												{
																													use precision 7;
																												}
																												{
																													use precision 6;
																												}
																												{
																													use precision 5;
																												}
																												{
																													use precision 4;
																												}
																												{
																													use precision 3;
																												}
																												{
																													use precision 2;
																												}
																												{
																													use precision 1;
																													{
																														use rounding HALF_UP;
																														// examples from sql proposal (krishna kulkarni)
																														//----------------------------------------------------------------------
																														// same as above, using decimal64 default parameters                  --
																														//----------------------------------------------------------------------
																														{
																															use precision 16;
																															{
																																use rounding HALF_EVEN;
																																// [first group are 'quick confidence check']
																																AddTestCase('addx6001:p16 r:HALF_EVEN (1 + 1)', 2, 1 + 1);
																																AddTestCase('addx6002:p16 r:HALF_EVEN (2 + 3)', 5, 2 + 3);
																																AddTestCase('addx6003:p16 r:HALF_EVEN (5.75 + 3.3)', 9.05, 5.75 + 3.3);
																																AddTestCase('addx6004:p16 r:HALF_EVEN (5 + -3)', 2, 5 + -3);
																																AddTestCase('addx6005:p16 r:HALF_EVEN (-5 + -3)', -8, -5 + -3);
																																AddTestCase('addx6006:p16 r:HALF_EVEN (-7 + 2.5)', -4.5, -7 + 2.5);
																																AddTestCase('addx6007:p16 r:HALF_EVEN (0.7 + 0.3)', 1.0, 0.7 + 0.3);
																																AddTestCase('addx6008:p16 r:HALF_EVEN (1.25 + 1.25)', 2.50, 1.25 + 1.25);
																																AddTestCase('addx6009:p16 r:HALF_EVEN (1.23456789 + 1.00000000)', 2.23456789, 1.23456789 + 1.00000000);
																																AddTestCase('addx6010:p16 r:HALF_EVEN (1.23456789 + 1.00000011)', 2.23456800, 1.23456789 + 1.00000011);
																																AddTestCase('addx6011:p16 r:HALF_EVEN (0.44444444444444444 + 0.55555555555555555) inexact rounded', 1.000000000000000, 0.44444444444444444 + 0.55555555555555555);
																																AddTestCase('addx6012:p16 r:HALF_EVEN (0.44444444444444440 + 0.55555555555555555) inexact rounded', 1.000000000000000, 0.44444444444444440 + 0.55555555555555555);
																																AddTestCase('addx6013:p16 r:HALF_EVEN (0.44444444444444444 + 0.55555555555555550) inexact rounded', 0.9999999999999999, 0.44444444444444444 + 0.55555555555555550);
																																AddTestCase('addx6014:p16 r:HALF_EVEN (0.444444444444444449 + 0) inexact rounded', 0.4444444444444444, 0.444444444444444449 + 0);
																																AddTestCase('addx6015:p16 r:HALF_EVEN (0.4444444444444444499 + 0) inexact rounded', 0.4444444444444444, 0.4444444444444444499 + 0);
																																AddTestCase('addx6016:p16 r:HALF_EVEN (0.44444444444444444999 + 0) inexact rounded', 0.4444444444444444, 0.44444444444444444999 + 0);
																																AddTestCase('addx6017:p16 r:HALF_EVEN (0.44444444444444445000 + 0) inexact rounded', 0.4444444444444444, 0.44444444444444445000 + 0);
																																AddTestCase('addx6018:p16 r:HALF_EVEN (0.44444444444444445001 + 0) inexact rounded', 0.4444444444444445, 0.44444444444444445001 + 0);
																																AddTestCase('addx6019:p16 r:HALF_EVEN (0.4444444444444444501 + 0) inexact rounded', 0.4444444444444445, 0.4444444444444444501 + 0);
																																AddTestCase('addx6020:p16 r:HALF_EVEN (0.444444444444444451 + 0) inexact rounded', 0.4444444444444445, 0.444444444444444451 + 0);
																																AddTestCase('addx6021:p16 r:HALF_EVEN (0 + 1)', 1, 0 + 1);
																																AddTestCase('addx6022:p16 r:HALF_EVEN (1 + 1)', 2, 1 + 1);
																																AddTestCase('addx6023:p16 r:HALF_EVEN (2 + 1)', 3, 2 + 1);
																																AddTestCase('addx6024:p16 r:HALF_EVEN (3 + 1)', 4, 3 + 1);
																																AddTestCase('addx6025:p16 r:HALF_EVEN (4 + 1)', 5, 4 + 1);
																																AddTestCase('addx6026:p16 r:HALF_EVEN (5 + 1)', 6, 5 + 1);
																																AddTestCase('addx6027:p16 r:HALF_EVEN (6 + 1)', 7, 6 + 1);
																																AddTestCase('addx6028:p16 r:HALF_EVEN (7 + 1)', 8, 7 + 1);
																																AddTestCase('addx6029:p16 r:HALF_EVEN (8 + 1)', 9, 8 + 1);
																																AddTestCase('addx6030:p16 r:HALF_EVEN (9 + 1)', 10, 9 + 1);
																																// some carrying effects
																																AddTestCase('addx6031:p16 r:HALF_EVEN (0.9998 + 0.0000)', 0.9998, 0.9998 + 0.0000);
																																AddTestCase('addx6032:p16 r:HALF_EVEN (0.9998 + 0.0001)', 0.9999, 0.9998 + 0.0001);
																																AddTestCase('addx6033:p16 r:HALF_EVEN (0.9998 + 0.0002)', 1.0000, 0.9998 + 0.0002);
																																AddTestCase('addx6034:p16 r:HALF_EVEN (0.9998 + 0.0003)', 1.0001, 0.9998 + 0.0003);
																																AddTestCase('addx6035:p16 r:HALF_EVEN (70 + 10000e+16) inexact rounded', 1.000000000000000e+20, 70 + 10000e+16);
																																AddTestCase('addx6036:p16 r:HALF_EVEN (700 + 10000e+16) inexact rounded', 1.000000000000000e+20, 700 + 10000e+16);
																																AddTestCase('addx6037:p16 r:HALF_EVEN (7000 + 10000e+16) inexact rounded', 1.000000000000000e+20, 7000 + 10000e+16);
																																AddTestCase('addx6038:p16 r:HALF_EVEN (70000 + 10000e+16) inexact rounded', 1.000000000000001e+20, 70000 + 10000e+16);
																																AddTestCase('addx6039:p16 r:HALF_EVEN (700000 + 10000e+16) rounded', 1.000000000000007e+20, 700000 + 10000e+16);
																																// symmetry:
																																AddTestCase('addx6040:p16 r:HALF_EVEN (10000e+16 + 70) inexact rounded', 1.000000000000000e+20, 10000e+16 + 70);
																																AddTestCase('addx6041:p16 r:HALF_EVEN (10000e+16 + 700) inexact rounded', 1.000000000000000e+20, 10000e+16 + 700);
																																AddTestCase('addx6042:p16 r:HALF_EVEN (10000e+16 + 7000) inexact rounded', 1.000000000000000e+20, 10000e+16 + 7000);
																																AddTestCase('addx6044:p16 r:HALF_EVEN (10000e+16 + 70000) inexact rounded', 1.000000000000001e+20, 10000e+16 + 70000);
																																AddTestCase('addx6045:p16 r:HALF_EVEN (10000e+16 + 700000) rounded', 1.000000000000007e+20, 10000e+16 + 700000);
																																AddTestCase('addx6046:p16 r:HALF_EVEN (10000e+9 + 7)', 10000000000007, 10000e+9 + 7);
																																AddTestCase('addx6047:p16 r:HALF_EVEN (10000e+9 + 70)', 10000000000070, 10000e+9 + 70);
																																AddTestCase('addx6048:p16 r:HALF_EVEN (10000e+9 + 700)', 10000000000700, 10000e+9 + 700);
																																AddTestCase('addx6049:p16 r:HALF_EVEN (10000e+9 + 7000)', 10000000007000, 10000e+9 + 7000);
																																AddTestCase('addx6050:p16 r:HALF_EVEN (10000e+9 + 70000)', 10000000070000, 10000e+9 + 70000);
																																AddTestCase('addx6051:p16 r:HALF_EVEN (10000e+9 + 700000)', 10000000700000, 10000e+9 + 700000);
																																// examples from decarith
																																AddTestCase('addx6053:p16 r:HALF_EVEN (12 + 7.00)', 19.00, 12 + 7.00);
																																AddTestCase('addx6054:p16 r:HALF_EVEN (1.3 + -1.07)', 0.23, 1.3 + -1.07);
																																AddTestCase('addx6055:p16 r:HALF_EVEN (1.3 + -1.30)', 0.00, 1.3 + -1.30);
																																AddTestCase('addx6056:p16 r:HALF_EVEN (1.3 + -2.07)', -0.77, 1.3 + -2.07);
																																AddTestCase('addx6057:p16 r:HALF_EVEN (1e+2 + 1e+4)', 1.01e+4, 1e+2 + 1e+4);
																																// from above
																																AddTestCase('addx6061:p16 r:HALF_EVEN (1 + 0.1)', 1.1, 1 + 0.1);
																																AddTestCase('addx6062:p16 r:HALF_EVEN (1 + 0.01)', 1.01, 1 + 0.01);
																																AddTestCase('addx6063:p16 r:HALF_EVEN (1 + 0.001)', 1.001, 1 + 0.001);
																																AddTestCase('addx6064:p16 r:HALF_EVEN (1 + 0.0001)', 1.0001, 1 + 0.0001);
																																AddTestCase('addx6065:p16 r:HALF_EVEN (1 + 0.00001)', 1.00001, 1 + 0.00001);
																																AddTestCase('addx6066:p16 r:HALF_EVEN (1 + 0.000001)', 1.000001, 1 + 0.000001);
																																AddTestCase('addx6067:p16 r:HALF_EVEN (1 + 0.0000001)', 1.0000001, 1 + 0.0000001);
																																AddTestCase('addx6068:p16 r:HALF_EVEN (1 + 0.00000001)', 1.00000001, 1 + 0.00000001);
																																// cancellation to integer
																																AddTestCase('addx6069:p16 r:HALF_EVEN (99999999999999123456789 + -99999999999999e+9)', 123456789, 99999999999999123456789 + -99999999999999e+9);
																																// some funny zeros [in case of bad signum]
																																AddTestCase('addx6070:p16 r:HALF_EVEN (1 + 0)', 1, 1 + 0);
																																AddTestCase('addx6071:p16 r:HALF_EVEN (1 + 0.)', 1, 1 + 0.);
																																AddTestCase('addx6072:p16 r:HALF_EVEN (1 + .0)', 1.0, 1 + .0);
																																AddTestCase('addx6073:p16 r:HALF_EVEN (1 + 0.0)', 1.0, 1 + 0.0);
																																AddTestCase('addx6074:p16 r:HALF_EVEN (1 + 0.00)', 1.00, 1 + 0.00);
																																AddTestCase('addx6075:p16 r:HALF_EVEN (0 + 1)', 1, 0 + 1);
																																AddTestCase('addx6076:p16 r:HALF_EVEN (0. + 1)', 1, 0. + 1);
																																AddTestCase('addx6077:p16 r:HALF_EVEN (.0 + 1)', 1.0, .0 + 1);
																																AddTestCase('addx6078:p16 r:HALF_EVEN (0.0 + 1)', 1.0, 0.0 + 1);
																																AddTestCase('addx6079:p16 r:HALF_EVEN (0.00 + 1)', 1.00, 0.00 + 1);
																																// some carries
																																AddTestCase('addx6080:p16 r:HALF_EVEN (9999999999999998 + 1)', 9999999999999999, 9999999999999998 + 1);
																																AddTestCase('addx6081:p16 r:HALF_EVEN (9999999999999999 + 1) rounded', 1.000000000000000e+16, 9999999999999999 + 1);
																																AddTestCase('addx6082:p16 r:HALF_EVEN (999999999999999 + 1)', 1000000000000000, 999999999999999 + 1);
																																AddTestCase('addx6083:p16 r:HALF_EVEN (9999999999999 + 1)', 10000000000000, 9999999999999 + 1);
																																AddTestCase('addx6084:p16 r:HALF_EVEN (99999999999 + 1)', 100000000000, 99999999999 + 1);
																																AddTestCase('addx6085:p16 r:HALF_EVEN (999999999 + 1)', 1000000000, 999999999 + 1);
																																AddTestCase('addx6086:p16 r:HALF_EVEN (9999999 + 1)', 10000000, 9999999 + 1);
																																AddTestCase('addx6087:p16 r:HALF_EVEN (99999 + 1)', 100000, 99999 + 1);
																																AddTestCase('addx6088:p16 r:HALF_EVEN (999 + 1)', 1000, 999 + 1);
																																AddTestCase('addx6089:p16 r:HALF_EVEN (9 + 1)', 10, 9 + 1);
																																// more lhs swaps
																																AddTestCase('addx6090:p16 r:HALF_EVEN (-56267e-10 + 0)', -0.0000056267, -56267e-10 + 0);
																																AddTestCase('addx6091:p16 r:HALF_EVEN (-56267e-6 + 0)', -0.056267, -56267e-6 + 0);
																																AddTestCase('addx6092:p16 r:HALF_EVEN (-56267e-5 + 0)', -0.56267, -56267e-5 + 0);
																																AddTestCase('addx6093:p16 r:HALF_EVEN (-56267e-4 + 0)', -5.6267, -56267e-4 + 0);
																																AddTestCase('addx6094:p16 r:HALF_EVEN (-56267e-3 + 0)', -56.267, -56267e-3 + 0);
																																AddTestCase('addx6095:p16 r:HALF_EVEN (-56267e-2 + 0)', -562.67, -56267e-2 + 0);
																																AddTestCase('addx6096:p16 r:HALF_EVEN (-56267e-1 + 0)', -5626.7, -56267e-1 + 0);
																																AddTestCase('addx6097:p16 r:HALF_EVEN (-56267e-0 + 0)', -56267, -56267e-0 + 0);
																																AddTestCase('addx6098:p16 r:HALF_EVEN (-5e-10 + 0)', -5e-10, -5e-10 + 0);
																																AddTestCase('addx6099:p16 r:HALF_EVEN (-5e-7 + 0)', -5e-7, -5e-7 + 0);
																																AddTestCase('addx6100:p16 r:HALF_EVEN (-5e-6 + 0)', -0.000005, -5e-6 + 0);
																																AddTestCase('addx6101:p16 r:HALF_EVEN (-5e-5 + 0)', -0.00005, -5e-5 + 0);
																																AddTestCase('addx6102:p16 r:HALF_EVEN (-5e-4 + 0)', -0.0005, -5e-4 + 0);
																																AddTestCase('addx6103:p16 r:HALF_EVEN (-5e-1 + 0)', -0.5, -5e-1 + 0);
																																AddTestCase('addx6104:p16 r:HALF_EVEN (-5e0 + 0)', -5, -5e0 + 0);
																																AddTestCase('addx6105:p16 r:HALF_EVEN (-5e1 + 0)', -50, -5e1 + 0);
																																AddTestCase('addx6106:p16 r:HALF_EVEN (-5e5 + 0)', -500000, -5e5 + 0);
																																AddTestCase('addx6107:p16 r:HALF_EVEN (-5e15 + 0)', -5000000000000000, -5e15 + 0);
																																AddTestCase('addx6108:p16 r:HALF_EVEN (-5e16 + 0) rounded', -5.000000000000000e+16, -5e16 + 0);
																																AddTestCase('addx6109:p16 r:HALF_EVEN (-5e17 + 0) rounded', -5.000000000000000e+17, -5e17 + 0);
																																AddTestCase('addx6110:p16 r:HALF_EVEN (-5e18 + 0) rounded', -5.000000000000000e+18, -5e18 + 0);
																																AddTestCase('addx6111:p16 r:HALF_EVEN (-5e100 + 0) rounded', -5.000000000000000e+100, -5e100 + 0);
																																// more rhs swaps
																																AddTestCase('addx6113:p16 r:HALF_EVEN (0 + -56267e-10)', -0.0000056267, 0 + -56267e-10);
																																AddTestCase('addx6114:p16 r:HALF_EVEN (0 + -56267e-6)', -0.056267, 0 + -56267e-6);
																																AddTestCase('addx6116:p16 r:HALF_EVEN (0 + -56267e-5)', -0.56267, 0 + -56267e-5);
																																AddTestCase('addx6117:p16 r:HALF_EVEN (0 + -56267e-4)', -5.6267, 0 + -56267e-4);
																																AddTestCase('addx6119:p16 r:HALF_EVEN (0 + -56267e-3)', -56.267, 0 + -56267e-3);
																																AddTestCase('addx6120:p16 r:HALF_EVEN (0 + -56267e-2)', -562.67, 0 + -56267e-2);
																																AddTestCase('addx6121:p16 r:HALF_EVEN (0 + -56267e-1)', -5626.7, 0 + -56267e-1);
																																AddTestCase('addx6122:p16 r:HALF_EVEN (0 + -56267e-0)', -56267, 0 + -56267e-0);
																																AddTestCase('addx6123:p16 r:HALF_EVEN (0 + -5e-10)', -5e-10, 0 + -5e-10);
																																AddTestCase('addx6124:p16 r:HALF_EVEN (0 + -5e-7)', -5e-7, 0 + -5e-7);
																																AddTestCase('addx6125:p16 r:HALF_EVEN (0 + -5e-6)', -0.000005, 0 + -5e-6);
																																AddTestCase('addx6126:p16 r:HALF_EVEN (0 + -5e-5)', -0.00005, 0 + -5e-5);
																																AddTestCase('addx6127:p16 r:HALF_EVEN (0 + -5e-4)', -0.0005, 0 + -5e-4);
																																AddTestCase('addx6128:p16 r:HALF_EVEN (0 + -5e-1)', -0.5, 0 + -5e-1);
																																AddTestCase('addx6129:p16 r:HALF_EVEN (0 + -5e0)', -5, 0 + -5e0);
																																AddTestCase('addx6130:p16 r:HALF_EVEN (0 + -5e1)', -50, 0 + -5e1);
																																AddTestCase('addx6131:p16 r:HALF_EVEN (0 + -5e5)', -500000, 0 + -5e5);
																																AddTestCase('addx6132:p16 r:HALF_EVEN (0 + -5e15)', -5000000000000000, 0 + -5e15);
																																AddTestCase('addx6133:p16 r:HALF_EVEN (0 + -5e16) rounded', -5.000000000000000e+16, 0 + -5e16);
																																AddTestCase('addx6134:p16 r:HALF_EVEN (0 + -5e17) rounded', -5.000000000000000e+17, 0 + -5e17);
																																AddTestCase('addx6135:p16 r:HALF_EVEN (0 + -5e18) rounded', -5.000000000000000e+18, 0 + -5e18);
																																AddTestCase('addx6136:p16 r:HALF_EVEN (0 + -5e100) rounded', -5.000000000000000e+100, 0 + -5e100);
																																// related
																																AddTestCase('addx6137:p16 r:HALF_EVEN (1 + 0e-19) rounded', 1.000000000000000, 1 + 0e-19);
																																AddTestCase('addx6138:p16 r:HALF_EVEN (-1 + 0e-19) rounded', -1.000000000000000, -1 + 0e-19);
																																AddTestCase('addx6139:p16 r:HALF_EVEN (0e-19 + 1) rounded', 1.000000000000000, 0e-19 + 1);
																																AddTestCase('addx6140:p16 r:HALF_EVEN (0e-19 + -1) rounded', -1.000000000000000, 0e-19 + -1);
																																AddTestCase('addx6141:p16 r:HALF_EVEN (1e+11 + 0.0000)', 100000000000.0000, 1e+11 + 0.0000);
																																AddTestCase('addx6142:p16 r:HALF_EVEN (1e+11 + 0.00000) rounded', 100000000000.0000, 1e+11 + 0.00000);
																																AddTestCase('addx6143:p16 r:HALF_EVEN (0.000 + 1e+12)', 1000000000000.000, 0.000 + 1e+12);
																																AddTestCase('addx6144:p16 r:HALF_EVEN (0.0000 + 1e+12) rounded', 1000000000000.000, 0.0000 + 1e+12);
																																// [some of the next group are really constructor tests]
																																AddTestCase('addx6146:p16 r:HALF_EVEN (00.0 + 0)', 0.0, 00.0 + 0);
																																AddTestCase('addx6147:p16 r:HALF_EVEN (0.00 + 0)', 0.00, 0.00 + 0);
																																AddTestCase('addx6148:p16 r:HALF_EVEN (0 + 0.00)', 0.00, 0 + 0.00);
																																AddTestCase('addx6149:p16 r:HALF_EVEN (0 + 00.0)', 0.0, 0 + 00.0);
																																AddTestCase('addx6150:p16 r:HALF_EVEN (00.0 + 0.00)', 0.00, 00.0 + 0.00);
																																AddTestCase('addx6151:p16 r:HALF_EVEN (0.00 + 00.0)', 0.00, 0.00 + 00.0);
																																AddTestCase('addx6152:p16 r:HALF_EVEN (3 + .3)', 3.3, 3 + .3);
																																AddTestCase('addx6153:p16 r:HALF_EVEN (3. + .3)', 3.3, 3. + .3);
																																AddTestCase('addx6154:p16 r:HALF_EVEN (3.0 + .3)', 3.3, 3.0 + .3);
																																AddTestCase('addx6155:p16 r:HALF_EVEN (3.00 + .3)', 3.30, 3.00 + .3);
																																AddTestCase('addx6156:p16 r:HALF_EVEN (3 + 3)', 6, 3 + 3);
																																AddTestCase('addx6157:p16 r:HALF_EVEN (3 + +3)', 6, 3 + +3);
																																AddTestCase('addx6158:p16 r:HALF_EVEN (3 + -3)', 0, 3 + -3);
																																AddTestCase('addx6159:p16 r:HALF_EVEN (0.3 + -0.3)', 0.0, 0.3 + -0.3);
																																AddTestCase('addx6160:p16 r:HALF_EVEN (0.03 + -0.03)', 0.00, 0.03 + -0.03);
																																// try borderline precision, with carries, etc.
																																AddTestCase('addx6161:p16 r:HALF_EVEN (1e+13 + -1)', 9999999999999, 1e+13 + -1);
																																AddTestCase('addx6162:p16 r:HALF_EVEN (1e+13 + 1.11)', 10000000000001.11, 1e+13 + 1.11);
																																AddTestCase('addx6163:p16 r:HALF_EVEN (1.11 + 1e+13)', 10000000000001.11, 1.11 + 1e+13);
																																AddTestCase('addx6164:p16 r:HALF_EVEN (-1 + 1e+13)', 9999999999999, -1 + 1e+13);
																																AddTestCase('addx6165:p16 r:HALF_EVEN (7e+13 + -1)', 69999999999999, 7e+13 + -1);
																																AddTestCase('addx6166:p16 r:HALF_EVEN (7e+13 + 1.11)', 70000000000001.11, 7e+13 + 1.11);
																																AddTestCase('addx6167:p16 r:HALF_EVEN (1.11 + 7e+13)', 70000000000001.11, 1.11 + 7e+13);
																																AddTestCase('addx6168:p16 r:HALF_EVEN (-1 + 7e+13)', 69999999999999, -1 + 7e+13);
																																//             1234567890123456      1234567890123456      1 234567890123456
																																AddTestCase('addx6170:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555563) inexact rounded', 1.000000000000001, 0.4444444444444444 + 0.5555555555555563);
																																AddTestCase('addx6171:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555562) inexact rounded', 1.000000000000001, 0.4444444444444444 + 0.5555555555555562);
																																AddTestCase('addx6172:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555561) inexact rounded', 1.000000000000000, 0.4444444444444444 + 0.5555555555555561);
																																AddTestCase('addx6173:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555560) inexact rounded', 1.000000000000000, 0.4444444444444444 + 0.5555555555555560);
																																AddTestCase('addx6174:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555559) inexact rounded', 1.000000000000000, 0.4444444444444444 + 0.5555555555555559);
																																AddTestCase('addx6175:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555558) inexact rounded', 1.000000000000000, 0.4444444444444444 + 0.5555555555555558);
																																AddTestCase('addx6176:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555557) inexact rounded', 1.000000000000000, 0.4444444444444444 + 0.5555555555555557);
																																AddTestCase('addx6177:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555556) rounded', 1.000000000000000, 0.4444444444444444 + 0.5555555555555556);
																																AddTestCase('addx6178:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555555)', 0.9999999999999999, 0.4444444444444444 + 0.5555555555555555);
																																AddTestCase('addx6179:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555554)', 0.9999999999999998, 0.4444444444444444 + 0.5555555555555554);
																																AddTestCase('addx6180:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555553)', 0.9999999999999997, 0.4444444444444444 + 0.5555555555555553);
																																AddTestCase('addx6181:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555552)', 0.9999999999999996, 0.4444444444444444 + 0.5555555555555552);
																																AddTestCase('addx6182:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555551)', 0.9999999999999995, 0.4444444444444444 + 0.5555555555555551);
																																AddTestCase('addx6183:p16 r:HALF_EVEN (0.4444444444444444 + 0.5555555555555550)', 0.9999999999999994, 0.4444444444444444 + 0.5555555555555550);
																																// and some more, including residue effects and different roundings
																															}
																															{
																																use rounding HALF_UP;
																																AddTestCase('addx6200:p16 r:HALF_UP (6543210123456789 + 0)', 6543210123456789, 6543210123456789 + 0);
																																AddTestCase('addx6201:p16 r:HALF_UP (6543210123456789 + 0.000000001) inexact rounded', 6543210123456789, 6543210123456789 + 0.000000001);
																																AddTestCase('addx6202:p16 r:HALF_UP (6543210123456789 + 0.000001) inexact rounded', 6543210123456789, 6543210123456789 + 0.000001);
																																AddTestCase('addx6203:p16 r:HALF_UP (6543210123456789 + 0.1) inexact rounded', 6543210123456789, 6543210123456789 + 0.1);
																																AddTestCase('addx6204:p16 r:HALF_UP (6543210123456789 + 0.4) inexact rounded', 6543210123456789, 6543210123456789 + 0.4);
																																AddTestCase('addx6205:p16 r:HALF_UP (6543210123456789 + 0.49) inexact rounded', 6543210123456789, 6543210123456789 + 0.49);
																																AddTestCase('addx6206:p16 r:HALF_UP (6543210123456789 + 0.499999) inexact rounded', 6543210123456789, 6543210123456789 + 0.499999);
																																AddTestCase('addx6207:p16 r:HALF_UP (6543210123456789 + 0.499999999) inexact rounded', 6543210123456789, 6543210123456789 + 0.499999999);
																																AddTestCase('addx6208:p16 r:HALF_UP (6543210123456789 + 0.5) inexact rounded', 6543210123456790, 6543210123456789 + 0.5);
																																AddTestCase('addx6209:p16 r:HALF_UP (6543210123456789 + 0.500000001) inexact rounded', 6543210123456790, 6543210123456789 + 0.500000001);
																																AddTestCase('addx6210:p16 r:HALF_UP (6543210123456789 + 0.500001) inexact rounded', 6543210123456790, 6543210123456789 + 0.500001);
																																AddTestCase('addx6211:p16 r:HALF_UP (6543210123456789 + 0.51) inexact rounded', 6543210123456790, 6543210123456789 + 0.51);
																																AddTestCase('addx6212:p16 r:HALF_UP (6543210123456789 + 0.6) inexact rounded', 6543210123456790, 6543210123456789 + 0.6);
																																AddTestCase('addx6213:p16 r:HALF_UP (6543210123456789 + 0.9) inexact rounded', 6543210123456790, 6543210123456789 + 0.9);
																																AddTestCase('addx6214:p16 r:HALF_UP (6543210123456789 + 0.99999) inexact rounded', 6543210123456790, 6543210123456789 + 0.99999);
																																AddTestCase('addx6215:p16 r:HALF_UP (6543210123456789 + 0.999999999) inexact rounded', 6543210123456790, 6543210123456789 + 0.999999999);
																																AddTestCase('addx6216:p16 r:HALF_UP (6543210123456789 + 1)', 6543210123456790, 6543210123456789 + 1);
																																AddTestCase('addx6217:p16 r:HALF_UP (6543210123456789 + 1.000000001) inexact rounded', 6543210123456790, 6543210123456789 + 1.000000001);
																																AddTestCase('addx6218:p16 r:HALF_UP (6543210123456789 + 1.00001) inexact rounded', 6543210123456790, 6543210123456789 + 1.00001);
																																AddTestCase('addx6219:p16 r:HALF_UP (6543210123456789 + 1.1) inexact rounded', 6543210123456790, 6543210123456789 + 1.1);
																															}
																															{
																																use rounding HALF_EVEN;
																																AddTestCase('addx6220:p16 r:HALF_EVEN (6543210123456789 + 0)', 6543210123456789, 6543210123456789 + 0);
																																AddTestCase('addx6221:p16 r:HALF_EVEN (6543210123456789 + 0.000000001) inexact rounded', 6543210123456789, 6543210123456789 + 0.000000001);
																																AddTestCase('addx6222:p16 r:HALF_EVEN (6543210123456789 + 0.000001) inexact rounded', 6543210123456789, 6543210123456789 + 0.000001);
																																AddTestCase('addx6223:p16 r:HALF_EVEN (6543210123456789 + 0.1) inexact rounded', 6543210123456789, 6543210123456789 + 0.1);
																																AddTestCase('addx6224:p16 r:HALF_EVEN (6543210123456789 + 0.4) inexact rounded', 6543210123456789, 6543210123456789 + 0.4);
																																AddTestCase('addx6225:p16 r:HALF_EVEN (6543210123456789 + 0.49) inexact rounded', 6543210123456789, 6543210123456789 + 0.49);
																																AddTestCase('addx6226:p16 r:HALF_EVEN (6543210123456789 + 0.499999) inexact rounded', 6543210123456789, 6543210123456789 + 0.499999);
																																AddTestCase('addx6227:p16 r:HALF_EVEN (6543210123456789 + 0.499999999) inexact rounded', 6543210123456789, 6543210123456789 + 0.499999999);
																																AddTestCase('addx6228:p16 r:HALF_EVEN (6543210123456789 + 0.5) inexact rounded', 6543210123456790, 6543210123456789 + 0.5);
																																AddTestCase('addx6229:p16 r:HALF_EVEN (6543210123456789 + 0.500000001) inexact rounded', 6543210123456790, 6543210123456789 + 0.500000001);
																																AddTestCase('addx6230:p16 r:HALF_EVEN (6543210123456789 + 0.500001) inexact rounded', 6543210123456790, 6543210123456789 + 0.500001);
																																AddTestCase('addx6231:p16 r:HALF_EVEN (6543210123456789 + 0.51) inexact rounded', 6543210123456790, 6543210123456789 + 0.51);
																																AddTestCase('addx6232:p16 r:HALF_EVEN (6543210123456789 + 0.6) inexact rounded', 6543210123456790, 6543210123456789 + 0.6);
																																AddTestCase('addx6233:p16 r:HALF_EVEN (6543210123456789 + 0.9) inexact rounded', 6543210123456790, 6543210123456789 + 0.9);
																																AddTestCase('addx6234:p16 r:HALF_EVEN (6543210123456789 + 0.99999) inexact rounded', 6543210123456790, 6543210123456789 + 0.99999);
																																AddTestCase('addx6235:p16 r:HALF_EVEN (6543210123456789 + 0.999999999) inexact rounded', 6543210123456790, 6543210123456789 + 0.999999999);
																																AddTestCase('addx6236:p16 r:HALF_EVEN (6543210123456789 + 1)', 6543210123456790, 6543210123456789 + 1);
																																AddTestCase('addx6237:p16 r:HALF_EVEN (6543210123456789 + 1.00000001) inexact rounded', 6543210123456790, 6543210123456789 + 1.00000001);
																																AddTestCase('addx6238:p16 r:HALF_EVEN (6543210123456789 + 1.00001) inexact rounded', 6543210123456790, 6543210123456789 + 1.00001);
																																AddTestCase('addx6239:p16 r:HALF_EVEN (6543210123456789 + 1.1) inexact rounded', 6543210123456790, 6543210123456789 + 1.1);
																																// critical few with even bottom digit...
																																AddTestCase('addx6240:p16 r:HALF_EVEN (6543210123456788 + 0.499999999) inexact rounded', 6543210123456788, 6543210123456788 + 0.499999999);
																																AddTestCase('addx6241:p16 r:HALF_EVEN (6543210123456788 + 0.5) inexact rounded', 6543210123456788, 6543210123456788 + 0.5);
																																AddTestCase('addx6242:p16 r:HALF_EVEN (6543210123456788 + 0.500000001) inexact rounded', 6543210123456789, 6543210123456788 + 0.500000001);
																																// 1 in last place tests
																															}
																															{
																																use rounding HALF_EVEN;
																																AddTestCase('addx6301:p16 r:HALF_EVEN (-1 + 1)', 0, -1 + 1);
																																AddTestCase('addx6302:p16 r:HALF_EVEN (0 + 1)', 1, 0 + 1);
																																AddTestCase('addx6303:p16 r:HALF_EVEN (1 + 1)', 2, 1 + 1);
																																AddTestCase('addx6304:p16 r:HALF_EVEN (12 + 1)', 13, 12 + 1);
																																AddTestCase('addx6305:p16 r:HALF_EVEN (98 + 1)', 99, 98 + 1);
																																AddTestCase('addx6306:p16 r:HALF_EVEN (99 + 1)', 100, 99 + 1);
																																AddTestCase('addx6307:p16 r:HALF_EVEN (100 + 1)', 101, 100 + 1);
																																AddTestCase('addx6308:p16 r:HALF_EVEN (101 + 1)', 102, 101 + 1);
																																AddTestCase('addx6309:p16 r:HALF_EVEN (-1 + -1)', -2, -1 + -1);
																																AddTestCase('addx6310:p16 r:HALF_EVEN (0 + -1)', -1, 0 + -1);
																																AddTestCase('addx6311:p16 r:HALF_EVEN (1 + -1)', 0, 1 + -1);
																																AddTestCase('addx6312:p16 r:HALF_EVEN (12 + -1)', 11, 12 + -1);
																																AddTestCase('addx6313:p16 r:HALF_EVEN (98 + -1)', 97, 98 + -1);
																																AddTestCase('addx6314:p16 r:HALF_EVEN (99 + -1)', 98, 99 + -1);
																																AddTestCase('addx6315:p16 r:HALF_EVEN (100 + -1)', 99, 100 + -1);
																																AddTestCase('addx6316:p16 r:HALF_EVEN (101 + -1)', 100, 101 + -1);
																																AddTestCase('addx6321:p16 r:HALF_EVEN (-0.01 + 0.01)', 0.00, -0.01 + 0.01);
																																AddTestCase('addx6322:p16 r:HALF_EVEN (0.00 + 0.01)', 0.01, 0.00 + 0.01);
																																AddTestCase('addx6323:p16 r:HALF_EVEN (0.01 + 0.01)', 0.02, 0.01 + 0.01);
																																AddTestCase('addx6324:p16 r:HALF_EVEN (0.12 + 0.01)', 0.13, 0.12 + 0.01);
																																AddTestCase('addx6325:p16 r:HALF_EVEN (0.98 + 0.01)', 0.99, 0.98 + 0.01);
																																AddTestCase('addx6326:p16 r:HALF_EVEN (0.99 + 0.01)', 1.00, 0.99 + 0.01);
																																AddTestCase('addx6327:p16 r:HALF_EVEN (1.00 + 0.01)', 1.01, 1.00 + 0.01);
																																AddTestCase('addx6328:p16 r:HALF_EVEN (1.01 + 0.01)', 1.02, 1.01 + 0.01);
																																AddTestCase('addx6329:p16 r:HALF_EVEN (-0.01 + -0.01)', -0.02, -0.01 + -0.01);
																																AddTestCase('addx6330:p16 r:HALF_EVEN (0.00 + -0.01)', -0.01, 0.00 + -0.01);
																																AddTestCase('addx6331:p16 r:HALF_EVEN (0.01 + -0.01)', 0.00, 0.01 + -0.01);
																																AddTestCase('addx6332:p16 r:HALF_EVEN (0.12 + -0.01)', 0.11, 0.12 + -0.01);
																																AddTestCase('addx6333:p16 r:HALF_EVEN (0.98 + -0.01)', 0.97, 0.98 + -0.01);
																																AddTestCase('addx6334:p16 r:HALF_EVEN (0.99 + -0.01)', 0.98, 0.99 + -0.01);
																																AddTestCase('addx6335:p16 r:HALF_EVEN (1.00 + -0.01)', 0.99, 1.00 + -0.01);
																																AddTestCase('addx6336:p16 r:HALF_EVEN (1.01 + -0.01)', 1.00, 1.01 + -0.01);
																																// some more cases where adding 0 affects the coefficient
																																AddTestCase('addx6340:p16 r:HALF_EVEN (1e+3 + 0)', 1000, 1e+3 + 0);
																																AddTestCase('addx6341:p16 r:HALF_EVEN (1e+15 + 0)', 1000000000000000, 1e+15 + 0);
																																AddTestCase('addx6342:p16 r:HALF_EVEN (1e+16 + 0) rounded', 1.000000000000000e+16, 1e+16 + 0);
																																AddTestCase('addx6343:p16 r:HALF_EVEN (1e+17 + 0) rounded', 1.000000000000000e+17, 1e+17 + 0);
																																// which simply follow from these cases ...
																																AddTestCase('addx6344:p16 r:HALF_EVEN (1e+3 + 1)', 1001, 1e+3 + 1);
																																AddTestCase('addx6345:p16 r:HALF_EVEN (1e+15 + 1)', 1000000000000001, 1e+15 + 1);
																																AddTestCase('addx6346:p16 r:HALF_EVEN (1e+16 + 1) inexact rounded', 1.000000000000000e+16, 1e+16 + 1);
																																AddTestCase('addx6347:p16 r:HALF_EVEN (1e+17 + 1) inexact rounded', 1.000000000000000e+17, 1e+17 + 1);
																																AddTestCase('addx6348:p16 r:HALF_EVEN (1e+3 + 7)', 1007, 1e+3 + 7);
																																AddTestCase('addx6349:p16 r:HALF_EVEN (1e+15 + 7)', 1000000000000007, 1e+15 + 7);
																																AddTestCase('addx6350:p16 r:HALF_EVEN (1e+16 + 7) inexact rounded', 1.000000000000001e+16, 1e+16 + 7);
																																AddTestCase('addx6351:p16 r:HALF_EVEN (1e+17 + 7) inexact rounded', 1.000000000000000e+17, 1e+17 + 7);
																																// tryzeros cases
																																AddTestCase('addx6361:p16 r:HALF_EVEN (0e+50 + 10000e+1)', 1.0000e+5, 0e+50 + 10000e+1);
																																AddTestCase('addx6362:p16 r:HALF_EVEN (10000e+1 + 0e-50) rounded', 100000.0000000000, 10000e+1 + 0e-50);
																																AddTestCase('addx6363:p16 r:HALF_EVEN (10000e+1 + 10000e-50) rounded inexact', 100000.0000000000, 10000e+1 + 10000e-50);
																																AddTestCase('addx6364:p16 r:HALF_EVEN (12.34 + 0e-398) rounded', 12.34000000000000, 12.34 + 0e-398);
																																// ulp replacement tests
																																AddTestCase('addx6400:p16 r:HALF_EVEN (1 + 77e-14)', 1.00000000000077, 1 + 77e-14);
																																AddTestCase('addx6401:p16 r:HALF_EVEN (1 + 77e-15)', 1.000000000000077, 1 + 77e-15);
																																AddTestCase('addx6402:p16 r:HALF_EVEN (1 + 77e-16) inexact rounded', 1.000000000000008, 1 + 77e-16);
																																AddTestCase('addx6403:p16 r:HALF_EVEN (1 + 77e-17) inexact rounded', 1.000000000000001, 1 + 77e-17);
																																AddTestCase('addx6404:p16 r:HALF_EVEN (1 + 77e-18) inexact rounded', 1.000000000000000, 1 + 77e-18);
																																AddTestCase('addx6405:p16 r:HALF_EVEN (1 + 77e-19) inexact rounded', 1.000000000000000, 1 + 77e-19);
																																AddTestCase('addx6406:p16 r:HALF_EVEN (1 + 77e-99) inexact rounded', 1.000000000000000, 1 + 77e-99);
																																AddTestCase('addx6410:p16 r:HALF_EVEN (10 + 77e-14)', 10.00000000000077, 10 + 77e-14);
																																AddTestCase('addx6411:p16 r:HALF_EVEN (10 + 77e-15) inexact rounded', 10.00000000000008, 10 + 77e-15);
																																AddTestCase('addx6412:p16 r:HALF_EVEN (10 + 77e-16) inexact rounded', 10.00000000000001, 10 + 77e-16);
																																AddTestCase('addx6413:p16 r:HALF_EVEN (10 + 77e-17) inexact rounded', 10.00000000000000, 10 + 77e-17);
																																AddTestCase('addx6414:p16 r:HALF_EVEN (10 + 77e-18) inexact rounded', 10.00000000000000, 10 + 77e-18);
																																AddTestCase('addx6415:p16 r:HALF_EVEN (10 + 77e-19) inexact rounded', 10.00000000000000, 10 + 77e-19);
																																AddTestCase('addx6416:p16 r:HALF_EVEN (10 + 77e-99) inexact rounded', 10.00000000000000, 10 + 77e-99);
																																AddTestCase('addx6420:p16 r:HALF_EVEN (77e-14 + 1)', 1.00000000000077, 77e-14 + 1);
																																AddTestCase('addx6421:p16 r:HALF_EVEN (77e-15 + 1)', 1.000000000000077, 77e-15 + 1);
																																AddTestCase('addx6422:p16 r:HALF_EVEN (77e-16 + 1) inexact rounded', 1.000000000000008, 77e-16 + 1);
																																AddTestCase('addx6423:p16 r:HALF_EVEN (77e-17 + 1) inexact rounded', 1.000000000000001, 77e-17 + 1);
																																AddTestCase('addx6424:p16 r:HALF_EVEN (77e-18 + 1) inexact rounded', 1.000000000000000, 77e-18 + 1);
																																AddTestCase('addx6425:p16 r:HALF_EVEN (77e-19 + 1) inexact rounded', 1.000000000000000, 77e-19 + 1);
																																AddTestCase('addx6426:p16 r:HALF_EVEN (77e-99 + 1) inexact rounded', 1.000000000000000, 77e-99 + 1);
																																AddTestCase('addx6430:p16 r:HALF_EVEN (77e-14 + 10)', 10.00000000000077, 77e-14 + 10);
																																AddTestCase('addx6431:p16 r:HALF_EVEN (77e-15 + 10) inexact rounded', 10.00000000000008, 77e-15 + 10);
																																AddTestCase('addx6432:p16 r:HALF_EVEN (77e-16 + 10) inexact rounded', 10.00000000000001, 77e-16 + 10);
																																AddTestCase('addx6433:p16 r:HALF_EVEN (77e-17 + 10) inexact rounded', 10.00000000000000, 77e-17 + 10);
																																AddTestCase('addx6434:p16 r:HALF_EVEN (77e-18 + 10) inexact rounded', 10.00000000000000, 77e-18 + 10);
																																AddTestCase('addx6435:p16 r:HALF_EVEN (77e-19 + 10) inexact rounded', 10.00000000000000, 77e-19 + 10);
																																AddTestCase('addx6436:p16 r:HALF_EVEN (77e-99 + 10) inexact rounded', 10.00000000000000, 77e-99 + 10);
																																// negative ulps
																																AddTestCase('addx6440:p16 r:HALF_EVEN (1 + -77e-14)', 0.99999999999923, 1 + -77e-14);
																																AddTestCase('addx6441:p16 r:HALF_EVEN (1 + -77e-15)', 0.999999999999923, 1 + -77e-15);
																																AddTestCase('addx6442:p16 r:HALF_EVEN (1 + -77e-16)', 0.9999999999999923, 1 + -77e-16);
																																AddTestCase('addx6443:p16 r:HALF_EVEN (1 + -77e-17) inexact rounded', 0.9999999999999992, 1 + -77e-17);
																																AddTestCase('addx6444:p16 r:HALF_EVEN (1 + -77e-18) inexact rounded', 0.9999999999999999, 1 + -77e-18);
																																AddTestCase('addx6445:p16 r:HALF_EVEN (1 + -77e-19) inexact rounded', 1.000000000000000, 1 + -77e-19);
																																AddTestCase('addx6446:p16 r:HALF_EVEN (1 + -77e-99) inexact rounded', 1.000000000000000, 1 + -77e-99);
																																AddTestCase('addx6450:p16 r:HALF_EVEN (10 + -77e-14)', 9.99999999999923, 10 + -77e-14);
																																AddTestCase('addx6451:p16 r:HALF_EVEN (10 + -77e-15)', 9.999999999999923, 10 + -77e-15);
																																AddTestCase('addx6452:p16 r:HALF_EVEN (10 + -77e-16) inexact rounded', 9.999999999999992, 10 + -77e-16);
																																AddTestCase('addx6453:p16 r:HALF_EVEN (10 + -77e-17) inexact rounded', 9.999999999999999, 10 + -77e-17);
																																AddTestCase('addx6454:p16 r:HALF_EVEN (10 + -77e-18) inexact rounded', 10.00000000000000, 10 + -77e-18);
																																AddTestCase('addx6455:p16 r:HALF_EVEN (10 + -77e-19) inexact rounded', 10.00000000000000, 10 + -77e-19);
																																AddTestCase('addx6456:p16 r:HALF_EVEN (10 + -77e-99) inexact rounded', 10.00000000000000, 10 + -77e-99);
																																AddTestCase('addx6460:p16 r:HALF_EVEN (-77e-14 + 1)', 0.99999999999923, -77e-14 + 1);
																																AddTestCase('addx6461:p16 r:HALF_EVEN (-77e-15 + 1)', 0.999999999999923, -77e-15 + 1);
																																AddTestCase('addx6462:p16 r:HALF_EVEN (-77e-16 + 1)', 0.9999999999999923, -77e-16 + 1);
																																AddTestCase('addx6463:p16 r:HALF_EVEN (-77e-17 + 1) inexact rounded', 0.9999999999999992, -77e-17 + 1);
																																AddTestCase('addx6464:p16 r:HALF_EVEN (-77e-18 + 1) inexact rounded', 0.9999999999999999, -77e-18 + 1);
																																AddTestCase('addx6465:p16 r:HALF_EVEN (-77e-19 + 1) inexact rounded', 1.000000000000000, -77e-19 + 1);
																																AddTestCase('addx6466:p16 r:HALF_EVEN (-77e-99 + 1) inexact rounded', 1.000000000000000, -77e-99 + 1);
																																AddTestCase('addx6470:p16 r:HALF_EVEN (-77e-14 + 10)', 9.99999999999923, -77e-14 + 10);
																																AddTestCase('addx6471:p16 r:HALF_EVEN (-77e-15 + 10)', 9.999999999999923, -77e-15 + 10);
																																AddTestCase('addx6472:p16 r:HALF_EVEN (-77e-16 + 10) inexact rounded', 9.999999999999992, -77e-16 + 10);
																																AddTestCase('addx6473:p16 r:HALF_EVEN (-77e-17 + 10) inexact rounded', 9.999999999999999, -77e-17 + 10);
																																AddTestCase('addx6474:p16 r:HALF_EVEN (-77e-18 + 10) inexact rounded', 10.00000000000000, -77e-18 + 10);
																																AddTestCase('addx6475:p16 r:HALF_EVEN (-77e-19 + 10) inexact rounded', 10.00000000000000, -77e-19 + 10);
																																AddTestCase('addx6476:p16 r:HALF_EVEN (-77e-99 + 10) inexact rounded', 10.00000000000000, -77e-99 + 10);
																																// negative ulps
																																AddTestCase('addx6480:p16 r:HALF_EVEN (-1 + 77e-14)', -0.99999999999923, -1 + 77e-14);
																																AddTestCase('addx6481:p16 r:HALF_EVEN (-1 + 77e-15)', -0.999999999999923, -1 + 77e-15);
																																AddTestCase('addx6482:p16 r:HALF_EVEN (-1 + 77e-16)', -0.9999999999999923, -1 + 77e-16);
																																AddTestCase('addx6483:p16 r:HALF_EVEN (-1 + 77e-17) inexact rounded', -0.9999999999999992, -1 + 77e-17);
																																AddTestCase('addx6484:p16 r:HALF_EVEN (-1 + 77e-18) inexact rounded', -0.9999999999999999, -1 + 77e-18);
																																AddTestCase('addx6485:p16 r:HALF_EVEN (-1 + 77e-19) inexact rounded', -1.000000000000000, -1 + 77e-19);
																																AddTestCase('addx6486:p16 r:HALF_EVEN (-1 + 77e-99) inexact rounded', -1.000000000000000, -1 + 77e-99);
																																AddTestCase('addx6490:p16 r:HALF_EVEN (-10 + 77e-14)', -9.99999999999923, -10 + 77e-14);
																																AddTestCase('addx6491:p16 r:HALF_EVEN (-10 + 77e-15)', -9.999999999999923, -10 + 77e-15);
																																AddTestCase('addx6492:p16 r:HALF_EVEN (-10 + 77e-16) inexact rounded', -9.999999999999992, -10 + 77e-16);
																																AddTestCase('addx6493:p16 r:HALF_EVEN (-10 + 77e-17) inexact rounded', -9.999999999999999, -10 + 77e-17);
																																AddTestCase('addx6494:p16 r:HALF_EVEN (-10 + 77e-18) inexact rounded', -10.00000000000000, -10 + 77e-18);
																																AddTestCase('addx6495:p16 r:HALF_EVEN (-10 + 77e-19) inexact rounded', -10.00000000000000, -10 + 77e-19);
																																AddTestCase('addx6496:p16 r:HALF_EVEN (-10 + 77e-99) inexact rounded', -10.00000000000000, -10 + 77e-99);
																																AddTestCase('addx6500:p16 r:HALF_EVEN (77e-14 + -1)', -0.99999999999923, 77e-14 + -1);
																																AddTestCase('addx6501:p16 r:HALF_EVEN (77e-15 + -1)', -0.999999999999923, 77e-15 + -1);
																																AddTestCase('addx6502:p16 r:HALF_EVEN (77e-16 + -1)', -0.9999999999999923, 77e-16 + -1);
																																AddTestCase('addx6503:p16 r:HALF_EVEN (77e-17 + -1) inexact rounded', -0.9999999999999992, 77e-17 + -1);
																																AddTestCase('addx6504:p16 r:HALF_EVEN (77e-18 + -1) inexact rounded', -0.9999999999999999, 77e-18 + -1);
																																AddTestCase('addx6505:p16 r:HALF_EVEN (77e-19 + -1) inexact rounded', -1.000000000000000, 77e-19 + -1);
																																AddTestCase('addx6506:p16 r:HALF_EVEN (77e-99 + -1) inexact rounded', -1.000000000000000, 77e-99 + -1);
																																AddTestCase('addx6510:p16 r:HALF_EVEN (77e-14 + -10)', -9.99999999999923, 77e-14 + -10);
																																AddTestCase('addx6511:p16 r:HALF_EVEN (77e-15 + -10)', -9.999999999999923, 77e-15 + -10);
																																AddTestCase('addx6512:p16 r:HALF_EVEN (77e-16 + -10) inexact rounded', -9.999999999999992, 77e-16 + -10);
																																AddTestCase('addx6513:p16 r:HALF_EVEN (77e-17 + -10) inexact rounded', -9.999999999999999, 77e-17 + -10);
																																AddTestCase('addx6514:p16 r:HALF_EVEN (77e-18 + -10) inexact rounded', -10.00000000000000, 77e-18 + -10);
																																AddTestCase('addx6515:p16 r:HALF_EVEN (77e-19 + -10) inexact rounded', -10.00000000000000, 77e-19 + -10);
																																AddTestCase('addx6516:p16 r:HALF_EVEN (77e-99 + -10) inexact rounded', -10.00000000000000, 77e-99 + -10);
																																// long operands
																																AddTestCase('addx6521:p16 r:HALF_EVEN (101234562345678000 + 0) rounded', 1.012345623456780e+17, 101234562345678000 + 0);
																																AddTestCase('addx6522:p16 r:HALF_EVEN (0 + 101234562345678000) rounded', 1.012345623456780e+17, 0 + 101234562345678000);
																																AddTestCase('addx6523:p16 r:HALF_EVEN (10123456234567800 + 0) rounded', 1.012345623456780e+16, 10123456234567800 + 0);
																																AddTestCase('addx6524:p16 r:HALF_EVEN (0 + 10123456234567800) rounded', 1.012345623456780e+16, 0 + 10123456234567800);
																																AddTestCase('addx6525:p16 r:HALF_EVEN (10123456234567890 + 0) rounded', 1.012345623456789e+16, 10123456234567890 + 0);
																																AddTestCase('addx6526:p16 r:HALF_EVEN (0 + 10123456234567890) rounded', 1.012345623456789e+16, 0 + 10123456234567890);
																																AddTestCase('addx6527:p16 r:HALF_EVEN (10123456234567891 + 0) inexact rounded', 1.012345623456789e+16, 10123456234567891 + 0);
																																AddTestCase('addx6528:p16 r:HALF_EVEN (0 + 10123456234567891) inexact rounded', 1.012345623456789e+16, 0 + 10123456234567891);
																																AddTestCase('addx6529:p16 r:HALF_EVEN (101234562345678901 + 0) inexact rounded', 1.012345623456789e+17, 101234562345678901 + 0);
																																AddTestCase('addx6530:p16 r:HALF_EVEN (0 + 101234562345678901) inexact rounded', 1.012345623456789e+17, 0 + 101234562345678901);
																																AddTestCase('addx6531:p16 r:HALF_EVEN (10123456234567896 + 0) inexact rounded', 1.012345623456790e+16, 10123456234567896 + 0);
																																AddTestCase('addx6532:p16 r:HALF_EVEN (0 + 10123456234567896) inexact rounded', 1.012345623456790e+16, 0 + 10123456234567896);
																																// verify a query
																																// and using decimal64 bounds...
																																// more zeros, etc.
																															}
																															{
																																use rounding HALF_EVEN;
																																AddTestCase('addx6701:p16 r:HALF_EVEN (5.00 + 1.00e-3)', 5.00100, 5.00 + 1.00e-3);
																																AddTestCase('addx6702:p16 r:HALF_EVEN (00.00 + 0.000)', 0.000, 00.00 + 0.000);
																																AddTestCase('addx6703:p16 r:HALF_EVEN (00.00 + 0e-3)', 0.000, 00.00 + 0e-3);
																																AddTestCase('addx6704:p16 r:HALF_EVEN (0e-3 + 00.00)', 0.000, 0e-3 + 00.00);
																																AddTestCase('addx6710:p16 r:HALF_EVEN (0e+3 + 00.00)', 0.00, 0e+3 + 00.00);
																																AddTestCase('addx6711:p16 r:HALF_EVEN (0e+3 + 00.0)', 0.0, 0e+3 + 00.0);
																																AddTestCase('addx6712:p16 r:HALF_EVEN (0e+3 + 00.)', 0, 0e+3 + 00.);
																																AddTestCase('addx6713:p16 r:HALF_EVEN (0e+3 + 00.e+1)', 0e+1, 0e+3 + 00.e+1);
																																AddTestCase('addx6714:p16 r:HALF_EVEN (0e+3 + 00.e+2)', 0e+2, 0e+3 + 00.e+2);
																																AddTestCase('addx6715:p16 r:HALF_EVEN (0e+3 + 00.e+3)', 0e+3, 0e+3 + 00.e+3);
																																AddTestCase('addx6716:p16 r:HALF_EVEN (0e+3 + 00.e+4)', 0e+3, 0e+3 + 00.e+4);
																																AddTestCase('addx6717:p16 r:HALF_EVEN (0e+3 + 00.e+5)', 0e+3, 0e+3 + 00.e+5);
																																AddTestCase('addx6718:p16 r:HALF_EVEN (0e+3 + -00.0)', 0.0, 0e+3 + -00.0);
																																AddTestCase('addx6719:p16 r:HALF_EVEN (0e+3 + -00.)', 0, 0e+3 + -00.);
																																AddTestCase('addx6731:p16 r:HALF_EVEN (0e+3 + -00.e+1)', 0e+1, 0e+3 + -00.e+1);
																																AddTestCase('addx6720:p16 r:HALF_EVEN (00.00 + 0e+3)', 0.00, 00.00 + 0e+3);
																																AddTestCase('addx6721:p16 r:HALF_EVEN (00.0 + 0e+3)', 0.0, 00.0 + 0e+3);
																																AddTestCase('addx6722:p16 r:HALF_EVEN (00. + 0e+3)', 0, 00. + 0e+3);
																																AddTestCase('addx6723:p16 r:HALF_EVEN (00.e+1 + 0e+3)', 0e+1, 00.e+1 + 0e+3);
																																AddTestCase('addx6724:p16 r:HALF_EVEN (00.e+2 + 0e+3)', 0e+2, 00.e+2 + 0e+3);
																																AddTestCase('addx6725:p16 r:HALF_EVEN (00.e+3 + 0e+3)', 0e+3, 00.e+3 + 0e+3);
																																AddTestCase('addx6726:p16 r:HALF_EVEN (00.e+4 + 0e+3)', 0e+3, 00.e+4 + 0e+3);
																																AddTestCase('addx6727:p16 r:HALF_EVEN (00.e+5 + 0e+3)', 0e+3, 00.e+5 + 0e+3);
																																AddTestCase('addx6728:p16 r:HALF_EVEN (-00.00 + 0e+3)', 0.00, -00.00 + 0e+3);
																																AddTestCase('addx6729:p16 r:HALF_EVEN (-00.0 + 0e+3)', 0.0, -00.0 + 0e+3);
																																AddTestCase('addx6730:p16 r:HALF_EVEN (-00. + 0e+3)', 0, -00. + 0e+3);
																																AddTestCase('addx6732:p16 r:HALF_EVEN (0 + 0)', 0, 0 + 0);
																																AddTestCase('addx6733:p16 r:HALF_EVEN (0 + -0)', 0, 0 + -0);
																																AddTestCase('addx6734:p16 r:HALF_EVEN (-0 + 0)', 0, -0 + 0);
																																AddTestCase('addx6735:p16 r:HALF_EVEN (-0 + -0) -- ieee 854 special case', -0, -0 + -0);
																																AddTestCase('addx6736:p16 r:HALF_EVEN (1 + -1)', 0, 1 + -1);
																																AddTestCase('addx6737:p16 r:HALF_EVEN (-1 + -1)', -2, -1 + -1);
																																AddTestCase('addx6738:p16 r:HALF_EVEN (1 + 1)', 2, 1 + 1);
																																AddTestCase('addx6739:p16 r:HALF_EVEN (-1 + 1)', 0, -1 + 1);
																																AddTestCase('addx6741:p16 r:HALF_EVEN (0 + -1)', -1, 0 + -1);
																																AddTestCase('addx6742:p16 r:HALF_EVEN (-0 + -1)', -1, -0 + -1);
																																AddTestCase('addx6743:p16 r:HALF_EVEN (0 + 1)', 1, 0 + 1);
																																AddTestCase('addx6744:p16 r:HALF_EVEN (-0 + 1)', 1, -0 + 1);
																																AddTestCase('addx6745:p16 r:HALF_EVEN (-1 + 0)', -1, -1 + 0);
																																AddTestCase('addx6746:p16 r:HALF_EVEN (-1 + -0)', -1, -1 + -0);
																																AddTestCase('addx6747:p16 r:HALF_EVEN (1 + 0)', 1, 1 + 0);
																																AddTestCase('addx6748:p16 r:HALF_EVEN (1 + -0)', 1, 1 + -0);
																																AddTestCase('addx6751:p16 r:HALF_EVEN (0.0 + -1)', -1.0, 0.0 + -1);
																																AddTestCase('addx6752:p16 r:HALF_EVEN (-0.0 + -1)', -1.0, -0.0 + -1);
																																AddTestCase('addx6753:p16 r:HALF_EVEN (0.0 + 1)', 1.0, 0.0 + 1);
																																AddTestCase('addx6754:p16 r:HALF_EVEN (-0.0 + 1)', 1.0, -0.0 + 1);
																																AddTestCase('addx6755:p16 r:HALF_EVEN (-1.0 + 0)', -1.0, -1.0 + 0);
																																AddTestCase('addx6756:p16 r:HALF_EVEN (-1.0 + -0)', -1.0, -1.0 + -0);
																																AddTestCase('addx6757:p16 r:HALF_EVEN (1.0 + 0)', 1.0, 1.0 + 0);
																																AddTestCase('addx6758:p16 r:HALF_EVEN (1.0 + -0)', 1.0, 1.0 + -0);
																																AddTestCase('addx6761:p16 r:HALF_EVEN (0 + -1.0)', -1.0, 0 + -1.0);
																																AddTestCase('addx6762:p16 r:HALF_EVEN (-0 + -1.0)', -1.0, -0 + -1.0);
																																AddTestCase('addx6763:p16 r:HALF_EVEN (0 + 1.0)', 1.0, 0 + 1.0);
																																AddTestCase('addx6764:p16 r:HALF_EVEN (-0 + 1.0)', 1.0, -0 + 1.0);
																																AddTestCase('addx6765:p16 r:HALF_EVEN (-1 + 0.0)', -1.0, -1 + 0.0);
																																AddTestCase('addx6766:p16 r:HALF_EVEN (-1 + -0.0)', -1.0, -1 + -0.0);
																																AddTestCase('addx6767:p16 r:HALF_EVEN (1 + 0.0)', 1.0, 1 + 0.0);
																																AddTestCase('addx6768:p16 r:HALF_EVEN (1 + -0.0)', 1.0, 1 + -0.0);
																																AddTestCase('addx6771:p16 r:HALF_EVEN (0.0 + -1.0)', -1.0, 0.0 + -1.0);
																																AddTestCase('addx6772:p16 r:HALF_EVEN (-0.0 + -1.0)', -1.0, -0.0 + -1.0);
																																AddTestCase('addx6773:p16 r:HALF_EVEN (0.0 + 1.0)', 1.0, 0.0 + 1.0);
																																AddTestCase('addx6774:p16 r:HALF_EVEN (-0.0 + 1.0)', 1.0, -0.0 + 1.0);
																																AddTestCase('addx6775:p16 r:HALF_EVEN (-1.0 + 0.0)', -1.0, -1.0 + 0.0);
																																AddTestCase('addx6776:p16 r:HALF_EVEN (-1.0 + -0.0)', -1.0, -1.0 + -0.0);
																																AddTestCase('addx6777:p16 r:HALF_EVEN (1.0 + 0.0)', 1.0, 1.0 + 0.0);
																																AddTestCase('addx6778:p16 r:HALF_EVEN (1.0 + -0.0)', 1.0, 1.0 + -0.0);
																																// specials
																																AddTestCase('addx6780:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6781:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + -1000)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + -1000);
																																AddTestCase('addx6782:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + -1)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + -1);
																																AddTestCase('addx6783:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + -0)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + -0);
																																AddTestCase('addx6784:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + 0)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + 0);
																																AddTestCase('addx6785:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + 1)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + 1);
																																AddTestCase('addx6786:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + 1000)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + 1000);
																																AddTestCase('addx6787:p16 r:HALF_EVEN (-1000 + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, -1000 + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6788:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6789:p16 r:HALF_EVEN (-1 + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, -1 + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6790:p16 r:HALF_EVEN (-0 + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, -0 + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6791:p16 r:HALF_EVEN (0 + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, 0 + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6792:p16 r:HALF_EVEN (1 + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, 1 + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6793:p16 r:HALF_EVEN (1000 + decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, 1000 + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6794:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6800:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6801:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + -1000)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + -1000);
																																AddTestCase('addx6802:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + -1)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + -1);
																																AddTestCase('addx6803:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + -0)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + -0);
																																AddTestCase('addx6804:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + 0)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + 0);
																																AddTestCase('addx6805:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + 1)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + 1);
																																AddTestCase('addx6806:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + 1000)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + 1000);
																																AddTestCase('addx6807:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + decimal.POSITIVE_INFINITY);
																																AddTestCase('addx6808:p16 r:HALF_EVEN (-1000 + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, -1000 + decimal.POSITIVE_INFINITY);
																																AddTestCase('addx6809:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + decimal.POSITIVE_INFINITY) invalid_operation', NaN, decimal.NEGATIVE_INFINITY + decimal.POSITIVE_INFINITY);
																																AddTestCase('addx6810:p16 r:HALF_EVEN (-1 + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, -1 + decimal.POSITIVE_INFINITY);
																																AddTestCase('addx6811:p16 r:HALF_EVEN (-0 + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, -0 + decimal.POSITIVE_INFINITY);
																																AddTestCase('addx6812:p16 r:HALF_EVEN (0 + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, 0 + decimal.POSITIVE_INFINITY);
																																AddTestCase('addx6813:p16 r:HALF_EVEN (1 + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, 1 + decimal.POSITIVE_INFINITY);
																																AddTestCase('addx6814:p16 r:HALF_EVEN (1000 + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, 1000 + decimal.POSITIVE_INFINITY);
																																AddTestCase('addx6815:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY + decimal.POSITIVE_INFINITY);
																																AddTestCase('addx6821:p16 r:HALF_EVEN (NaN + decimal.NEGATIVE_INFINITY)', NaN, NaN + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6822:p16 r:HALF_EVEN (NaN + -1000)', NaN, NaN + -1000);
																																AddTestCase('addx6823:p16 r:HALF_EVEN (NaN + -1)', NaN, NaN + -1);
																																AddTestCase('addx6824:p16 r:HALF_EVEN (NaN + -0)', NaN, NaN + -0);
																																AddTestCase('addx6825:p16 r:HALF_EVEN (NaN + 0)', NaN, NaN + 0);
																																AddTestCase('addx6826:p16 r:HALF_EVEN (NaN + 1)', NaN, NaN + 1);
																																AddTestCase('addx6827:p16 r:HALF_EVEN (NaN + 1000)', NaN, NaN + 1000);
																																AddTestCase('addx6828:p16 r:HALF_EVEN (NaN + decimal.POSITIVE_INFINITY)', NaN, NaN + decimal.POSITIVE_INFINITY);
																																AddTestCase('addx6829:p16 r:HALF_EVEN (NaN + NaN)', NaN, NaN + NaN);
																																AddTestCase('addx6830:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + NaN)', NaN, decimal.NEGATIVE_INFINITY + NaN);
																																AddTestCase('addx6831:p16 r:HALF_EVEN (-1000 + NaN)', NaN, -1000 + NaN);
																																AddTestCase('addx6832:p16 r:HALF_EVEN (-1 + NaN)', NaN, -1 + NaN);
																																AddTestCase('addx6833:p16 r:HALF_EVEN (-0 + NaN)', NaN, -0 + NaN);
																																AddTestCase('addx6834:p16 r:HALF_EVEN (0 + NaN)', NaN, 0 + NaN);
																																AddTestCase('addx6835:p16 r:HALF_EVEN (1 + NaN)', NaN, 1 + NaN);
																																AddTestCase('addx6836:p16 r:HALF_EVEN (1000 + NaN)', NaN, 1000 + NaN);
																																AddTestCase('addx6837:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + NaN)', NaN, decimal.POSITIVE_INFINITY + NaN);
																																AddTestCase('addx6841:p16 r:HALF_EVEN (NaN + decimal.NEGATIVE_INFINITY) invalid_operation', NaN, NaN + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6842:p16 r:HALF_EVEN (NaN + -1000) invalid_operation', NaN, NaN + -1000);
																																AddTestCase('addx6843:p16 r:HALF_EVEN (NaN + -1) invalid_operation', NaN, NaN + -1);
																																AddTestCase('addx6844:p16 r:HALF_EVEN (NaN + -0) invalid_operation', NaN, NaN + -0);
																																AddTestCase('addx6845:p16 r:HALF_EVEN (NaN + 0) invalid_operation', NaN, NaN + 0);
																																AddTestCase('addx6846:p16 r:HALF_EVEN (NaN + 1) invalid_operation', NaN, NaN + 1);
																																AddTestCase('addx6847:p16 r:HALF_EVEN (NaN + 1000) invalid_operation', NaN, NaN + 1000);
																																AddTestCase('addx6848:p16 r:HALF_EVEN (NaN + NaN) invalid_operation', NaN, NaN + NaN);
																																AddTestCase('addx6849:p16 r:HALF_EVEN (NaN + NaN) invalid_operation', NaN, NaN + NaN);
																																AddTestCase('addx6850:p16 r:HALF_EVEN (NaN + NaN) invalid_operation', NaN, NaN + NaN);
																																AddTestCase('addx6851:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + NaN) invalid_operation', NaN, decimal.NEGATIVE_INFINITY + NaN);
																																AddTestCase('addx6852:p16 r:HALF_EVEN (-1000 + NaN) invalid_operation', NaN, -1000 + NaN);
																																AddTestCase('addx6853:p16 r:HALF_EVEN (-1 + NaN) invalid_operation', NaN, -1 + NaN);
																																AddTestCase('addx6854:p16 r:HALF_EVEN (-0 + NaN) invalid_operation', NaN, -0 + NaN);
																																AddTestCase('addx6855:p16 r:HALF_EVEN (0 + NaN) invalid_operation', NaN, 0 + NaN);
																																AddTestCase('addx6856:p16 r:HALF_EVEN (1 + NaN) invalid_operation', NaN, 1 + NaN);
																																AddTestCase('addx6857:p16 r:HALF_EVEN (1000 + NaN) invalid_operation', NaN, 1000 + NaN);
																																AddTestCase('addx6858:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + NaN) invalid_operation', NaN, decimal.POSITIVE_INFINITY + NaN);
																																AddTestCase('addx6859:p16 r:HALF_EVEN (NaN + NaN) invalid_operation', NaN, NaN + NaN);
																																// propagating nans
																																AddTestCase('addx6861:p16 r:HALF_EVEN (NaN + decimal.NEGATIVE_INFINITY)', NaN, NaN + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6862:p16 r:HALF_EVEN (+NaN + -1000)', NaN, +NaN + -1000);
																																AddTestCase('addx6863:p16 r:HALF_EVEN (NaN + 1000)', NaN, NaN + 1000);
																																AddTestCase('addx6864:p16 r:HALF_EVEN (NaN + decimal.POSITIVE_INFINITY)', NaN, NaN + decimal.POSITIVE_INFINITY);
																																AddTestCase('addx6865:p16 r:HALF_EVEN (NaN + +NaN)', NaN, NaN + +NaN);
																																AddTestCase('addx6866:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + NaN)', NaN, decimal.NEGATIVE_INFINITY + NaN);
																																AddTestCase('addx6867:p16 r:HALF_EVEN (-1000 + NaN)', NaN, -1000 + NaN);
																																AddTestCase('addx6868:p16 r:HALF_EVEN (1000 + NaN)', NaN, 1000 + NaN);
																																AddTestCase('addx6869:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + +NaN)', NaN, decimal.POSITIVE_INFINITY + +NaN);
																																AddTestCase('addx6871:p16 r:HALF_EVEN (NaN + decimal.NEGATIVE_INFINITY) invalid_operation', NaN, NaN + decimal.NEGATIVE_INFINITY);
																																AddTestCase('addx6872:p16 r:HALF_EVEN (NaN + -1000) invalid_operation', NaN, NaN + -1000);
																																AddTestCase('addx6873:p16 r:HALF_EVEN (NaN + 1000) invalid_operation', NaN, NaN + 1000);
																																AddTestCase('addx6874:p16 r:HALF_EVEN (NaN + NaN) invalid_operation', NaN, NaN + NaN);
																																AddTestCase('addx6875:p16 r:HALF_EVEN (NaN + NaN) invalid_operation', NaN, NaN + NaN);
																																AddTestCase('addx6876:p16 r:HALF_EVEN (NaN + NaN) invalid_operation', NaN, NaN + NaN);
																																AddTestCase('addx6877:p16 r:HALF_EVEN (decimal.NEGATIVE_INFINITY + +NaN) invalid_operation', NaN, decimal.NEGATIVE_INFINITY + +NaN);
																																AddTestCase('addx6878:p16 r:HALF_EVEN (-1000 + NaN) invalid_operation', NaN, -1000 + NaN);
																																AddTestCase('addx6879:p16 r:HALF_EVEN (1000 + NaN) invalid_operation', NaN, 1000 + NaN);
																																AddTestCase('addx6880:p16 r:HALF_EVEN (decimal.POSITIVE_INFINITY + NaN) invalid_operation', NaN, decimal.POSITIVE_INFINITY + NaN);
																																AddTestCase('addx6881:p16 r:HALF_EVEN (+NaN + +NaN) invalid_operation', NaN, +NaN + +NaN);
																																AddTestCase('addx6882:p16 r:HALF_EVEN (-NaN + NaN)', -NaN, -NaN + NaN);
																																AddTestCase('addx6883:p16 r:HALF_EVEN (-NaN + NaN) invalid_operation', -NaN, -NaN + NaN);
																																AddTestCase('addx6884:p16 r:HALF_EVEN (1000 + -NaN)', -NaN, 1000 + -NaN);
																																AddTestCase('addx6885:p16 r:HALF_EVEN (1000 + -NaN) invalid_operation', -NaN, 1000 + -NaN);
																																// now the case where we can get underflow but the result is normal
																																// [note this can't happen if the operands are also bounded, as we
																																// cannot represent 1e-399, for example]
																																AddTestCase('addx6571:p16 r:HALF_EVEN (1e-383 + 0)', 1e-383, 1e-383 + 0);
																																AddTestCase('addx6573:p16 r:HALF_EVEN (1e-383 + 1e-384)', 1.1e-383, 1e-383 + 1e-384);
																																// here we explore the boundary of rounding a subnormal to nmin
																																// check overflow edge case
																																//               1234567890123456
																																AddTestCase('addx6973:p16 r:HALF_EVEN (9.999999999999999e+384 + 1) inexact rounded', 9.999999999999999e+384, 9.999999999999999e+384 + 1);
																																AddTestCase('addx6974:p16 r:HALF_EVEN (9999999999999999e+369 + 1) inexact rounded', 9.999999999999999e+384, 9999999999999999e+369 + 1);
																																AddTestCase('addx6981:p16 r:HALF_EVEN (9999999999999999e+369 + 4e+368) inexact rounded', 9.999999999999999e+384, 9999999999999999e+369 + 4e+368);
																																AddTestCase('addx6982:p16 r:HALF_EVEN (9999999999999999e+369 + 3e+368) inexact rounded', 9.999999999999999e+384, 9999999999999999e+369 + 3e+368);
																																AddTestCase('addx6983:p16 r:HALF_EVEN (9999999999999999e+369 + 2e+368) inexact rounded', 9.999999999999999e+384, 9999999999999999e+369 + 2e+368);
																																AddTestCase('addx6984:p16 r:HALF_EVEN (9999999999999999e+369 + 1e+368) inexact rounded', 9.999999999999999e+384, 9999999999999999e+369 + 1e+368);
																																AddTestCase('addx6986:p16 r:HALF_EVEN (-9.999999999999999e+384 + -1) inexact rounded', -9.999999999999999e+384, -9.999999999999999e+384 + -1);
																																AddTestCase('addx6987:p16 r:HALF_EVEN (-9999999999999999e+369 + -1) inexact rounded', -9.999999999999999e+384, -9999999999999999e+369 + -1);
																																AddTestCase('addx6994:p16 r:HALF_EVEN (-9999999999999999e+369 + -4e+368) inexact rounded', -9.999999999999999e+384, -9999999999999999e+369 + -4e+368);
																																AddTestCase('addx6995:p16 r:HALF_EVEN (-9999999999999999e+369 + -3e+368) inexact rounded', -9.999999999999999e+384, -9999999999999999e+369 + -3e+368);
																																AddTestCase('addx6996:p16 r:HALF_EVEN (-9999999999999999e+369 + -2e+368) inexact rounded', -9.999999999999999e+384, -9999999999999999e+369 + -2e+368);
																																AddTestCase('addx6997:p16 r:HALF_EVEN (-9999999999999999e+369 + -1e+368) inexact rounded', -9.999999999999999e+384, -9999999999999999e+369 + -1e+368);
																																// and for round down full and subnormal results
																															}
																															{
																																use rounding CEILING;
																																AddTestCase('addx61110:p16 r:CEILING (-1e+2 + +1e-383) rounded inexact', -99.99999999999999, -1e+2 + +1e-383);
																																AddTestCase('addx61111:p16 r:CEILING (-1e+1 + +1e-383) rounded inexact', -9.999999999999999, -1e+1 + +1e-383);
																																AddTestCase('addx61113:p16 r:CEILING (-1 + +1e-383) rounded inexact', -0.9999999999999999, -1 + +1e-383);
																																AddTestCase('addx61114:p16 r:CEILING (-1e-1 + +1e-383) rounded inexact', -0.09999999999999999, -1e-1 + +1e-383);
																																AddTestCase('addx61115:p16 r:CEILING (-1e-2 + +1e-383) rounded inexact', -0.009999999999999999, -1e-2 + +1e-383);
																																AddTestCase('addx61116:p16 r:CEILING (-1e-3 + +1e-383) rounded inexact', -0.0009999999999999999, -1e-3 + +1e-383);
																																AddTestCase('addx61117:p16 r:CEILING (-1e-4 + +1e-383) rounded inexact', -0.00009999999999999999, -1e-4 + +1e-383);
																																AddTestCase('addx61118:p16 r:CEILING (-1e-5 + +1e-383) rounded inexact', -0.000009999999999999999, -1e-5 + +1e-383);
																																AddTestCase('addx61119:p16 r:CEILING (-1e-6 + +1e-383) rounded inexact', -9.999999999999999e-7, -1e-6 + +1e-383);
																																// tests based on gunnar degnbol's edge case
																															}
																															{
																																use rounding HALF_EVEN;
																																AddTestCase('addx61300:p16 r:HALF_EVEN (1e16 + -0.5) inexact rounded', 1.000000000000000e+16, 1e16 + -0.5);
																																AddTestCase('addx61310:p16 r:HALF_EVEN (1e16 + -0.51) inexact rounded', 9999999999999999, 1e16 + -0.51);
																																AddTestCase('addx61311:p16 r:HALF_EVEN (1e16 + -0.501) inexact rounded', 9999999999999999, 1e16 + -0.501);
																																AddTestCase('addx61312:p16 r:HALF_EVEN (1e16 + -0.5001) inexact rounded', 9999999999999999, 1e16 + -0.5001);
																																AddTestCase('addx61313:p16 r:HALF_EVEN (1e16 + -0.50001) inexact rounded', 9999999999999999, 1e16 + -0.50001);
																																AddTestCase('addx61314:p16 r:HALF_EVEN (1e16 + -0.500001) inexact rounded', 9999999999999999, 1e16 + -0.500001);
																																AddTestCase('addx61315:p16 r:HALF_EVEN (1e16 + -0.5000001) inexact rounded', 9999999999999999, 1e16 + -0.5000001);
																																AddTestCase('addx61316:p16 r:HALF_EVEN (1e16 + -0.50000001) inexact rounded', 9999999999999999, 1e16 + -0.50000001);
																																AddTestCase('addx61317:p16 r:HALF_EVEN (1e16 + -0.500000001) inexact rounded', 9999999999999999, 1e16 + -0.500000001);
																																AddTestCase('addx61318:p16 r:HALF_EVEN (1e16 + -0.5000000001) inexact rounded', 9999999999999999, 1e16 + -0.5000000001);
																																AddTestCase('addx61319:p16 r:HALF_EVEN (1e16 + -0.50000000001) inexact rounded', 9999999999999999, 1e16 + -0.50000000001);
																																AddTestCase('addx61320:p16 r:HALF_EVEN (1e16 + -0.500000000001) inexact rounded', 9999999999999999, 1e16 + -0.500000000001);
																																AddTestCase('addx61321:p16 r:HALF_EVEN (1e16 + -0.5000000000001) inexact rounded', 9999999999999999, 1e16 + -0.5000000000001);
																																AddTestCase('addx61322:p16 r:HALF_EVEN (1e16 + -0.50000000000001) inexact rounded', 9999999999999999, 1e16 + -0.50000000000001);
																																AddTestCase('addx61323:p16 r:HALF_EVEN (1e16 + -0.500000000000001) inexact rounded', 9999999999999999, 1e16 + -0.500000000000001);
																																AddTestCase('addx61324:p16 r:HALF_EVEN (1e16 + -0.5000000000000001) inexact rounded', 9999999999999999, 1e16 + -0.5000000000000001);
																																AddTestCase('addx61325:p16 r:HALF_EVEN (1e16 + -0.5000000000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.5000000000000000);
																																AddTestCase('addx61326:p16 r:HALF_EVEN (1e16 + -0.500000000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.500000000000000);
																																AddTestCase('addx61327:p16 r:HALF_EVEN (1e16 + -0.50000000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.50000000000000);
																																AddTestCase('addx61328:p16 r:HALF_EVEN (1e16 + -0.5000000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.5000000000000);
																																AddTestCase('addx61329:p16 r:HALF_EVEN (1e16 + -0.500000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.500000000000);
																																AddTestCase('addx61330:p16 r:HALF_EVEN (1e16 + -0.50000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.50000000000);
																																AddTestCase('addx61331:p16 r:HALF_EVEN (1e16 + -0.5000000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.5000000000);
																																AddTestCase('addx61332:p16 r:HALF_EVEN (1e16 + -0.500000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.500000000);
																																AddTestCase('addx61333:p16 r:HALF_EVEN (1e16 + -0.50000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.50000000);
																																AddTestCase('addx61334:p16 r:HALF_EVEN (1e16 + -0.5000000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.5000000);
																																AddTestCase('addx61335:p16 r:HALF_EVEN (1e16 + -0.500000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.500000);
																																AddTestCase('addx61336:p16 r:HALF_EVEN (1e16 + -0.50000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.50000);
																																AddTestCase('addx61337:p16 r:HALF_EVEN (1e16 + -0.5000) inexact rounded', 1.000000000000000e+16, 1e16 + -0.5000);
																																AddTestCase('addx61338:p16 r:HALF_EVEN (1e16 + -0.500) inexact rounded', 1.000000000000000e+16, 1e16 + -0.500);
																																AddTestCase('addx61339:p16 r:HALF_EVEN (1e16 + -0.50) inexact rounded', 1.000000000000000e+16, 1e16 + -0.50);
																																AddTestCase('addx61340:p16 r:HALF_EVEN (1e16 + -5000000.000010001) inexact rounded', 9999999995000000, 1e16 + -5000000.000010001);
																																AddTestCase('addx61341:p16 r:HALF_EVEN (1e16 + -5000000.000000001) inexact rounded', 9999999995000000, 1e16 + -5000000.000000001);
																																AddTestCase('addx61349:p16 r:HALF_EVEN (9999999999999999 + 0.4) inexact rounded', 9999999999999999, 9999999999999999 + 0.4);
																																AddTestCase('addx61350:p16 r:HALF_EVEN (9999999999999999 + 0.49) inexact rounded', 9999999999999999, 9999999999999999 + 0.49);
																																AddTestCase('addx61351:p16 r:HALF_EVEN (9999999999999999 + 0.499) inexact rounded', 9999999999999999, 9999999999999999 + 0.499);
																																AddTestCase('addx61352:p16 r:HALF_EVEN (9999999999999999 + 0.4999) inexact rounded', 9999999999999999, 9999999999999999 + 0.4999);
																																AddTestCase('addx61353:p16 r:HALF_EVEN (9999999999999999 + 0.49999) inexact rounded', 9999999999999999, 9999999999999999 + 0.49999);
																																AddTestCase('addx61354:p16 r:HALF_EVEN (9999999999999999 + 0.499999) inexact rounded', 9999999999999999, 9999999999999999 + 0.499999);
																																AddTestCase('addx61355:p16 r:HALF_EVEN (9999999999999999 + 0.4999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.4999999);
																																AddTestCase('addx61356:p16 r:HALF_EVEN (9999999999999999 + 0.49999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.49999999);
																																AddTestCase('addx61357:p16 r:HALF_EVEN (9999999999999999 + 0.499999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.499999999);
																																AddTestCase('addx61358:p16 r:HALF_EVEN (9999999999999999 + 0.4999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.4999999999);
																																AddTestCase('addx61359:p16 r:HALF_EVEN (9999999999999999 + 0.49999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.49999999999);
																																AddTestCase('addx61360:p16 r:HALF_EVEN (9999999999999999 + 0.499999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.499999999999);
																																AddTestCase('addx61361:p16 r:HALF_EVEN (9999999999999999 + 0.4999999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.4999999999999);
																																AddTestCase('addx61362:p16 r:HALF_EVEN (9999999999999999 + 0.49999999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.49999999999999);
																																AddTestCase('addx61363:p16 r:HALF_EVEN (9999999999999999 + 0.499999999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.499999999999999);
																																AddTestCase('addx61364:p16 r:HALF_EVEN (9999999999999999 + 0.4999999999999999) inexact rounded', 9999999999999999, 9999999999999999 + 0.4999999999999999);
																																AddTestCase('addx61365:p16 r:HALF_EVEN (9999999999999999 + 0.5000000000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000000000000);
																																AddTestCase('addx61367:p16 r:HALF_EVEN (9999999999999999 + 0.500000000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000000000000);
																																AddTestCase('addx61368:p16 r:HALF_EVEN (9999999999999999 + 0.50000000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000000000000);
																																AddTestCase('addx61369:p16 r:HALF_EVEN (9999999999999999 + 0.5000000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000000000);
																																AddTestCase('addx61370:p16 r:HALF_EVEN (9999999999999999 + 0.500000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000000000);
																																AddTestCase('addx61371:p16 r:HALF_EVEN (9999999999999999 + 0.50000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000000000);
																																AddTestCase('addx61372:p16 r:HALF_EVEN (9999999999999999 + 0.5000000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000000);
																																AddTestCase('addx61373:p16 r:HALF_EVEN (9999999999999999 + 0.500000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000000);
																																AddTestCase('addx61374:p16 r:HALF_EVEN (9999999999999999 + 0.50000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000000);
																																AddTestCase('addx61375:p16 r:HALF_EVEN (9999999999999999 + 0.5000000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000);
																																AddTestCase('addx61376:p16 r:HALF_EVEN (9999999999999999 + 0.500000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000);
																																AddTestCase('addx61377:p16 r:HALF_EVEN (9999999999999999 + 0.50000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000);
																																AddTestCase('addx61378:p16 r:HALF_EVEN (9999999999999999 + 0.5000) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000);
																																AddTestCase('addx61379:p16 r:HALF_EVEN (9999999999999999 + 0.500) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500);
																																AddTestCase('addx61380:p16 r:HALF_EVEN (9999999999999999 + 0.50) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50);
																																AddTestCase('addx61381:p16 r:HALF_EVEN (9999999999999999 + 0.5) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5);
																																AddTestCase('addx61382:p16 r:HALF_EVEN (9999999999999999 + 0.5000000000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000000000001);
																																AddTestCase('addx61383:p16 r:HALF_EVEN (9999999999999999 + 0.500000000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000000000001);
																																AddTestCase('addx61384:p16 r:HALF_EVEN (9999999999999999 + 0.50000000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000000000001);
																																AddTestCase('addx61385:p16 r:HALF_EVEN (9999999999999999 + 0.5000000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000000001);
																																AddTestCase('addx61386:p16 r:HALF_EVEN (9999999999999999 + 0.500000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000000001);
																																AddTestCase('addx61387:p16 r:HALF_EVEN (9999999999999999 + 0.50000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000000001);
																																AddTestCase('addx61388:p16 r:HALF_EVEN (9999999999999999 + 0.5000000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000000001);
																																AddTestCase('addx61389:p16 r:HALF_EVEN (9999999999999999 + 0.500000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500000001);
																																AddTestCase('addx61390:p16 r:HALF_EVEN (9999999999999999 + 0.50000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50000001);
																																AddTestCase('addx61391:p16 r:HALF_EVEN (9999999999999999 + 0.5000001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5000001);
																																AddTestCase('addx61392:p16 r:HALF_EVEN (9999999999999999 + 0.500001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.500001);
																																AddTestCase('addx61393:p16 r:HALF_EVEN (9999999999999999 + 0.50001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.50001);
																																AddTestCase('addx61394:p16 r:HALF_EVEN (9999999999999999 + 0.5001) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.5001);
																																AddTestCase('addx61395:p16 r:HALF_EVEN (9999999999999999 + 0.501) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.501);
																																AddTestCase('addx61396:p16 r:HALF_EVEN (9999999999999999 + 0.51) inexact rounded', 1.000000000000000e+16, 9999999999999999 + 0.51);
																																// more gd edge cases, where difference between the unadjusted
																																// exponents is larger than the maximum precision and one side is 0
																																AddTestCase('addx61420:p16 r:HALF_EVEN (0 + 1.123456789012345)', 1.123456789012345, 0 + 1.123456789012345);
																																AddTestCase('addx61421:p16 r:HALF_EVEN (0 + 1.123456789012345e-1)', 0.1123456789012345, 0 + 1.123456789012345e-1);
																																AddTestCase('addx61422:p16 r:HALF_EVEN (0 + 1.123456789012345e-2)', 0.01123456789012345, 0 + 1.123456789012345e-2);
																																AddTestCase('addx61423:p16 r:HALF_EVEN (0 + 1.123456789012345e-3)', 0.001123456789012345, 0 + 1.123456789012345e-3);
																																AddTestCase('addx61424:p16 r:HALF_EVEN (0 + 1.123456789012345e-4)', 0.0001123456789012345, 0 + 1.123456789012345e-4);
																																AddTestCase('addx61425:p16 r:HALF_EVEN (0 + 1.123456789012345e-5)', 0.00001123456789012345, 0 + 1.123456789012345e-5);
																																AddTestCase('addx61426:p16 r:HALF_EVEN (0 + 1.123456789012345e-6)', 0.000001123456789012345, 0 + 1.123456789012345e-6);
																																AddTestCase('addx61427:p16 r:HALF_EVEN (0 + 1.123456789012345e-7)', 1.123456789012345e-7, 0 + 1.123456789012345e-7);
																																AddTestCase('addx61428:p16 r:HALF_EVEN (0 + 1.123456789012345e-8)', 1.123456789012345e-8, 0 + 1.123456789012345e-8);
																																AddTestCase('addx61429:p16 r:HALF_EVEN (0 + 1.123456789012345e-9)', 1.123456789012345e-9, 0 + 1.123456789012345e-9);
																																AddTestCase('addx61430:p16 r:HALF_EVEN (0 + 1.123456789012345e-10)', 1.123456789012345e-10, 0 + 1.123456789012345e-10);
																																AddTestCase('addx61431:p16 r:HALF_EVEN (0 + 1.123456789012345e-11)', 1.123456789012345e-11, 0 + 1.123456789012345e-11);
																																AddTestCase('addx61432:p16 r:HALF_EVEN (0 + 1.123456789012345e-12)', 1.123456789012345e-12, 0 + 1.123456789012345e-12);
																																AddTestCase('addx61433:p16 r:HALF_EVEN (0 + 1.123456789012345e-13)', 1.123456789012345e-13, 0 + 1.123456789012345e-13);
																																AddTestCase('addx61434:p16 r:HALF_EVEN (0 + 1.123456789012345e-14)', 1.123456789012345e-14, 0 + 1.123456789012345e-14);
																																AddTestCase('addx61435:p16 r:HALF_EVEN (0 + 1.123456789012345e-15)', 1.123456789012345e-15, 0 + 1.123456789012345e-15);
																																AddTestCase('addx61436:p16 r:HALF_EVEN (0 + 1.123456789012345e-16)', 1.123456789012345e-16, 0 + 1.123456789012345e-16);
																																AddTestCase('addx61437:p16 r:HALF_EVEN (0 + 1.123456789012345e-17)', 1.123456789012345e-17, 0 + 1.123456789012345e-17);
																																AddTestCase('addx61438:p16 r:HALF_EVEN (0 + 1.123456789012345e-18)', 1.123456789012345e-18, 0 + 1.123456789012345e-18);
																																AddTestCase('addx61439:p16 r:HALF_EVEN (0 + 1.123456789012345e-19)', 1.123456789012345e-19, 0 + 1.123456789012345e-19);
																																// same, reversed 0
																																AddTestCase('addx61440:p16 r:HALF_EVEN (1.123456789012345 + 0)', 1.123456789012345, 1.123456789012345 + 0);
																																AddTestCase('addx61441:p16 r:HALF_EVEN (1.123456789012345e-1 + 0)', 0.1123456789012345, 1.123456789012345e-1 + 0);
																																AddTestCase('addx61442:p16 r:HALF_EVEN (1.123456789012345e-2 + 0)', 0.01123456789012345, 1.123456789012345e-2 + 0);
																																AddTestCase('addx61443:p16 r:HALF_EVEN (1.123456789012345e-3 + 0)', 0.001123456789012345, 1.123456789012345e-3 + 0);
																																AddTestCase('addx61444:p16 r:HALF_EVEN (1.123456789012345e-4 + 0)', 0.0001123456789012345, 1.123456789012345e-4 + 0);
																																AddTestCase('addx61445:p16 r:HALF_EVEN (1.123456789012345e-5 + 0)', 0.00001123456789012345, 1.123456789012345e-5 + 0);
																																AddTestCase('addx61446:p16 r:HALF_EVEN (1.123456789012345e-6 + 0)', 0.000001123456789012345, 1.123456789012345e-6 + 0);
																																AddTestCase('addx61447:p16 r:HALF_EVEN (1.123456789012345e-7 + 0)', 1.123456789012345e-7, 1.123456789012345e-7 + 0);
																																AddTestCase('addx61448:p16 r:HALF_EVEN (1.123456789012345e-8 + 0)', 1.123456789012345e-8, 1.123456789012345e-8 + 0);
																																AddTestCase('addx61449:p16 r:HALF_EVEN (1.123456789012345e-9 + 0)', 1.123456789012345e-9, 1.123456789012345e-9 + 0);
																																AddTestCase('addx61450:p16 r:HALF_EVEN (1.123456789012345e-10 + 0)', 1.123456789012345e-10, 1.123456789012345e-10 + 0);
																																AddTestCase('addx61451:p16 r:HALF_EVEN (1.123456789012345e-11 + 0)', 1.123456789012345e-11, 1.123456789012345e-11 + 0);
																																AddTestCase('addx61452:p16 r:HALF_EVEN (1.123456789012345e-12 + 0)', 1.123456789012345e-12, 1.123456789012345e-12 + 0);
																																AddTestCase('addx61453:p16 r:HALF_EVEN (1.123456789012345e-13 + 0)', 1.123456789012345e-13, 1.123456789012345e-13 + 0);
																																AddTestCase('addx61454:p16 r:HALF_EVEN (1.123456789012345e-14 + 0)', 1.123456789012345e-14, 1.123456789012345e-14 + 0);
																																AddTestCase('addx61455:p16 r:HALF_EVEN (1.123456789012345e-15 + 0)', 1.123456789012345e-15, 1.123456789012345e-15 + 0);
																																AddTestCase('addx61456:p16 r:HALF_EVEN (1.123456789012345e-16 + 0)', 1.123456789012345e-16, 1.123456789012345e-16 + 0);
																																AddTestCase('addx61457:p16 r:HALF_EVEN (1.123456789012345e-17 + 0)', 1.123456789012345e-17, 1.123456789012345e-17 + 0);
																																AddTestCase('addx61458:p16 r:HALF_EVEN (1.123456789012345e-18 + 0)', 1.123456789012345e-18, 1.123456789012345e-18 + 0);
																																AddTestCase('addx61459:p16 r:HALF_EVEN (1.123456789012345e-19 + 0)', 1.123456789012345e-19, 1.123456789012345e-19 + 0);
																																// same, es on the 0
																																AddTestCase('addx61460:p16 r:HALF_EVEN (1.123456789012345 + 0e-0)', 1.123456789012345, 1.123456789012345 + 0e-0);
																																AddTestCase('addx61461:p16 r:HALF_EVEN (1.123456789012345 + 0e-1)', 1.123456789012345, 1.123456789012345 + 0e-1);
																																AddTestCase('addx61462:p16 r:HALF_EVEN (1.123456789012345 + 0e-2)', 1.123456789012345, 1.123456789012345 + 0e-2);
																																AddTestCase('addx61463:p16 r:HALF_EVEN (1.123456789012345 + 0e-3)', 1.123456789012345, 1.123456789012345 + 0e-3);
																																AddTestCase('addx61464:p16 r:HALF_EVEN (1.123456789012345 + 0e-4)', 1.123456789012345, 1.123456789012345 + 0e-4);
																																AddTestCase('addx61465:p16 r:HALF_EVEN (1.123456789012345 + 0e-5)', 1.123456789012345, 1.123456789012345 + 0e-5);
																																AddTestCase('addx61466:p16 r:HALF_EVEN (1.123456789012345 + 0e-6)', 1.123456789012345, 1.123456789012345 + 0e-6);
																																AddTestCase('addx61467:p16 r:HALF_EVEN (1.123456789012345 + 0e-7)', 1.123456789012345, 1.123456789012345 + 0e-7);
																																AddTestCase('addx61468:p16 r:HALF_EVEN (1.123456789012345 + 0e-8)', 1.123456789012345, 1.123456789012345 + 0e-8);
																																AddTestCase('addx61469:p16 r:HALF_EVEN (1.123456789012345 + 0e-9)', 1.123456789012345, 1.123456789012345 + 0e-9);
																																AddTestCase('addx61470:p16 r:HALF_EVEN (1.123456789012345 + 0e-10)', 1.123456789012345, 1.123456789012345 + 0e-10);
																																AddTestCase('addx61471:p16 r:HALF_EVEN (1.123456789012345 + 0e-11)', 1.123456789012345, 1.123456789012345 + 0e-11);
																																AddTestCase('addx61472:p16 r:HALF_EVEN (1.123456789012345 + 0e-12)', 1.123456789012345, 1.123456789012345 + 0e-12);
																																AddTestCase('addx61473:p16 r:HALF_EVEN (1.123456789012345 + 0e-13)', 1.123456789012345, 1.123456789012345 + 0e-13);
																																AddTestCase('addx61474:p16 r:HALF_EVEN (1.123456789012345 + 0e-14)', 1.123456789012345, 1.123456789012345 + 0e-14);
																																AddTestCase('addx61475:p16 r:HALF_EVEN (1.123456789012345 + 0e-15)', 1.123456789012345, 1.123456789012345 + 0e-15);
																																// next four flag rounded because the 0 extends the result
																																AddTestCase('addx61476:p16 r:HALF_EVEN (1.123456789012345 + 0e-16) rounded', 1.123456789012345, 1.123456789012345 + 0e-16);
																																AddTestCase('addx61477:p16 r:HALF_EVEN (1.123456789012345 + 0e-17) rounded', 1.123456789012345, 1.123456789012345 + 0e-17);
																																AddTestCase('addx61478:p16 r:HALF_EVEN (1.123456789012345 + 0e-18) rounded', 1.123456789012345, 1.123456789012345 + 0e-18);
																																AddTestCase('addx61479:p16 r:HALF_EVEN (1.123456789012345 + 0e-19) rounded', 1.123456789012345, 1.123456789012345 + 0e-19);
																																// sum of two opposite-sign operands is exactly 0 and floor => -0
																															}
																															{
																																use rounding HALF_UP;
																																// exact zeros from zeros
																																AddTestCase('addx61500:p16 r:HALF_UP (0 + 0e-19)', 0e-19, 0 + 0e-19);
																																AddTestCase('addx61501:p16 r:HALF_UP (-0 + 0e-19)', 0e-19, -0 + 0e-19);
																																AddTestCase('addx61502:p16 r:HALF_UP (0 + -0e-19)', 0e-19, 0 + -0e-19);
																																AddTestCase('addx61503:p16 r:HALF_UP (-0 + -0e-19)', -0e-19, -0 + -0e-19);
																																// inexact zeros
																																// some exact zeros from non-zeros
																															}
																															{
																																use rounding HALF_DOWN;
																																// exact zeros from zeros
																																AddTestCase('addx61520:p16 r:HALF_DOWN (0 + 0e-19)', 0e-19, 0 + 0e-19);
																																AddTestCase('addx61521:p16 r:HALF_DOWN (-0 + 0e-19)', 0e-19, -0 + 0e-19);
																																AddTestCase('addx61522:p16 r:HALF_DOWN (0 + -0e-19)', 0e-19, 0 + -0e-19);
																																AddTestCase('addx61523:p16 r:HALF_DOWN (-0 + -0e-19)', -0e-19, -0 + -0e-19);
																																// inexact zeros
																																// some exact zeros from non-zeros
																															}
																															{
																																use rounding HALF_EVEN;
																																// exact zeros from zeros
																																AddTestCase('addx61540:p16 r:HALF_EVEN (0 + 0e-19)', 0e-19, 0 + 0e-19);
																																AddTestCase('addx61541:p16 r:HALF_EVEN (-0 + 0e-19)', 0e-19, -0 + 0e-19);
																																AddTestCase('addx61542:p16 r:HALF_EVEN (0 + -0e-19)', 0e-19, 0 + -0e-19);
																																AddTestCase('addx61543:p16 r:HALF_EVEN (-0 + -0e-19)', -0e-19, -0 + -0e-19);
																																// inexact zeros
																																// some exact zeros from non-zeros
																																// exact zeros from zeros
																																// inexact zeros
																																// some exact zeros from non-zeros
																																// exact zeros from zeros
																																// inexact zeros
																																// some exact zeros from non-zeros
																															}
																															{
																																use rounding CEILING;
																																// exact zeros from zeros
																																AddTestCase('addx61600:p16 r:CEILING (0 + 0e-19)', 0e-19, 0 + 0e-19);
																																AddTestCase('addx61601:p16 r:CEILING (-0 + 0e-19)', 0e-19, -0 + 0e-19);
																																AddTestCase('addx61602:p16 r:CEILING (0 + -0e-19)', 0e-19, 0 + -0e-19);
																																AddTestCase('addx61603:p16 r:CEILING (-0 + -0e-19)', -0e-19, -0 + -0e-19);
																																// inexact zeros
																																// some exact zeros from non-zeros
																																// and the extra-special ugly case; unusual minuses marked by -- *
																															}
																															{
																																use rounding FLOOR;
																																// exact zeros from zeros
																																AddTestCase('addx61620:p16 r:FLOOR (0 + 0e-19)', 0e-19, 0 + 0e-19);
																																AddTestCase('addx61621:p16 r:FLOOR (-0 + 0e-19) -- *', -0e-19, -0 + 0e-19);
																																AddTestCase('addx61622:p16 r:FLOOR (0 + -0e-19) -- *', -0e-19, 0 + -0e-19);
																																AddTestCase('addx61623:p16 r:FLOOR (-0 + -0e-19)', -0e-19, -0 + -0e-19);
																																// inexact zeros
																																// some exact zeros from non-zeros
																																// examples from sql proposal (krishna kulkarni)
																																AddTestCase('addx61701:p16 r:FLOOR (130e-2 + 120e-2)', 2.50, 130e-2 + 120e-2);
																																AddTestCase('addx61702:p16 r:FLOOR (130e-2 + 12e-1)', 2.50, 130e-2 + 12e-1);
																																AddTestCase('addx61703:p16 r:FLOOR (130e-2 + 1e0)', 2.30, 130e-2 + 1e0);
																																AddTestCase('addx61704:p16 r:FLOOR (1e2 + 1e4)', 1.01e+4, 1e2 + 1e4);
																																AddTestCase('addx61705:p16 r:FLOOR (130e-2 - 120e-2)', 0.10, 130e-2 - 120e-2);
																																AddTestCase('addx61706:p16 r:FLOOR (130e-2 - 12e-1)', 0.10, 130e-2 - 12e-1);
																																AddTestCase('addx61707:p16 r:FLOOR (130e-2 - 1e0)', 0.30, 130e-2 - 1e0);
																																AddTestCase('addx61708:p16 r:FLOOR (1e2 - 1e4)', -9.9e+3, 1e2 - 1e4);
																																// gappy coefficients; check residue handling even with full coefficient gap
																															}
																															{
																																use rounding HALF_EVEN;
																																AddTestCase('addx62001:p16 r:HALF_EVEN (1234567890123456 + 1)', 1234567890123457, 1234567890123456 + 1);
																																AddTestCase('addx62002:p16 r:HALF_EVEN (1234567890123456 + 0.6) inexact rounded', 1234567890123457, 1234567890123456 + 0.6);
																																AddTestCase('addx62003:p16 r:HALF_EVEN (1234567890123456 + 0.06) inexact rounded', 1234567890123456, 1234567890123456 + 0.06);
																																AddTestCase('addx62004:p16 r:HALF_EVEN (1234567890123456 + 6e-3) inexact rounded', 1234567890123456, 1234567890123456 + 6e-3);
																																AddTestCase('addx62005:p16 r:HALF_EVEN (1234567890123456 + 6e-4) inexact rounded', 1234567890123456, 1234567890123456 + 6e-4);
																																AddTestCase('addx62006:p16 r:HALF_EVEN (1234567890123456 + 6e-5) inexact rounded', 1234567890123456, 1234567890123456 + 6e-5);
																																AddTestCase('addx62007:p16 r:HALF_EVEN (1234567890123456 + 6e-6) inexact rounded', 1234567890123456, 1234567890123456 + 6e-6);
																																AddTestCase('addx62008:p16 r:HALF_EVEN (1234567890123456 + 6e-7) inexact rounded', 1234567890123456, 1234567890123456 + 6e-7);
																																AddTestCase('addx62009:p16 r:HALF_EVEN (1234567890123456 + 6e-8) inexact rounded', 1234567890123456, 1234567890123456 + 6e-8);
																																AddTestCase('addx62010:p16 r:HALF_EVEN (1234567890123456 + 6e-9) inexact rounded', 1234567890123456, 1234567890123456 + 6e-9);
																																AddTestCase('addx62011:p16 r:HALF_EVEN (1234567890123456 + 6e-10) inexact rounded', 1234567890123456, 1234567890123456 + 6e-10);
																																AddTestCase('addx62012:p16 r:HALF_EVEN (1234567890123456 + 6e-11) inexact rounded', 1234567890123456, 1234567890123456 + 6e-11);
																																AddTestCase('addx62013:p16 r:HALF_EVEN (1234567890123456 + 6e-12) inexact rounded', 1234567890123456, 1234567890123456 + 6e-12);
																																AddTestCase('addx62014:p16 r:HALF_EVEN (1234567890123456 + 6e-13) inexact rounded', 1234567890123456, 1234567890123456 + 6e-13);
																																AddTestCase('addx62015:p16 r:HALF_EVEN (1234567890123456 + 6e-14) inexact rounded', 1234567890123456, 1234567890123456 + 6e-14);
																																AddTestCase('addx62016:p16 r:HALF_EVEN (1234567890123456 + 6e-15) inexact rounded', 1234567890123456, 1234567890123456 + 6e-15);
																																AddTestCase('addx62017:p16 r:HALF_EVEN (1234567890123456 + 6e-16) inexact rounded', 1234567890123456, 1234567890123456 + 6e-16);
																																AddTestCase('addx62018:p16 r:HALF_EVEN (1234567890123456 + 6e-17) inexact rounded', 1234567890123456, 1234567890123456 + 6e-17);
																																AddTestCase('addx62019:p16 r:HALF_EVEN (1234567890123456 + 6e-18) inexact rounded', 1234567890123456, 1234567890123456 + 6e-18);
																																AddTestCase('addx62020:p16 r:HALF_EVEN (1234567890123456 + 6e-19) inexact rounded', 1234567890123456, 1234567890123456 + 6e-19);
																																AddTestCase('addx62021:p16 r:HALF_EVEN (1234567890123456 + 6e-20) inexact rounded', 1234567890123456, 1234567890123456 + 6e-20);
																																// widening second argument at gap
																																AddTestCase('addx62030:p16 r:HALF_EVEN (12345678 + 1)', 12345679, 12345678 + 1);
																																AddTestCase('addx62031:p16 r:HALF_EVEN (12345678 + 0.1)', 12345678.1, 12345678 + 0.1);
																																AddTestCase('addx62032:p16 r:HALF_EVEN (12345678 + 0.12)', 12345678.12, 12345678 + 0.12);
																																AddTestCase('addx62033:p16 r:HALF_EVEN (12345678 + 0.123)', 12345678.123, 12345678 + 0.123);
																																AddTestCase('addx62034:p16 r:HALF_EVEN (12345678 + 0.1234)', 12345678.1234, 12345678 + 0.1234);
																																AddTestCase('addx62035:p16 r:HALF_EVEN (12345678 + 0.12345)', 12345678.12345, 12345678 + 0.12345);
																																AddTestCase('addx62036:p16 r:HALF_EVEN (12345678 + 0.123456)', 12345678.123456, 12345678 + 0.123456);
																																AddTestCase('addx62037:p16 r:HALF_EVEN (12345678 + 0.1234567)', 12345678.1234567, 12345678 + 0.1234567);
																																AddTestCase('addx62038:p16 r:HALF_EVEN (12345678 + 0.12345678)', 12345678.12345678, 12345678 + 0.12345678);
																																AddTestCase('addx62039:p16 r:HALF_EVEN (12345678 + 0.123456789) inexact rounded', 12345678.12345679, 12345678 + 0.123456789);
																																AddTestCase('addx62040:p16 r:HALF_EVEN (12345678 + 0.123456785) inexact rounded', 12345678.12345678, 12345678 + 0.123456785);
																																AddTestCase('addx62041:p16 r:HALF_EVEN (12345678 + 0.1234567850) inexact rounded', 12345678.12345678, 12345678 + 0.1234567850);
																																AddTestCase('addx62042:p16 r:HALF_EVEN (12345678 + 0.1234567851) inexact rounded', 12345678.12345679, 12345678 + 0.1234567851);
																																AddTestCase('addx62043:p16 r:HALF_EVEN (12345678 + 0.12345678501) inexact rounded', 12345678.12345679, 12345678 + 0.12345678501);
																																AddTestCase('addx62044:p16 r:HALF_EVEN (12345678 + 0.123456785001) inexact rounded', 12345678.12345679, 12345678 + 0.123456785001);
																																AddTestCase('addx62045:p16 r:HALF_EVEN (12345678 + 0.1234567850001) inexact rounded', 12345678.12345679, 12345678 + 0.1234567850001);
																																AddTestCase('addx62046:p16 r:HALF_EVEN (12345678 + 0.12345678500001) inexact rounded', 12345678.12345679, 12345678 + 0.12345678500001);
																																AddTestCase('addx62047:p16 r:HALF_EVEN (12345678 + 0.123456785000001) inexact rounded', 12345678.12345679, 12345678 + 0.123456785000001);
																																AddTestCase('addx62048:p16 r:HALF_EVEN (12345678 + 0.1234567850000001) inexact rounded', 12345678.12345679, 12345678 + 0.1234567850000001);
																																AddTestCase('addx62049:p16 r:HALF_EVEN (12345678 + 0.1234567850000000) inexact rounded', 12345678.12345678, 12345678 + 0.1234567850000000);
																																//                               90123456
																															}
																															{
																																use rounding HALF_EVEN;
																																AddTestCase('addx62050:p16 r:HALF_EVEN (12345678 + 0.0234567750000000) inexact rounded', 12345678.02345678, 12345678 + 0.0234567750000000);
																																AddTestCase('addx62051:p16 r:HALF_EVEN (12345678 + 0.0034567750000000) inexact rounded', 12345678.00345678, 12345678 + 0.0034567750000000);
																																AddTestCase('addx62052:p16 r:HALF_EVEN (12345678 + 0.0004567750000000) inexact rounded', 12345678.00045678, 12345678 + 0.0004567750000000);
																																AddTestCase('addx62053:p16 r:HALF_EVEN (12345678 + 0.0000567750000000) inexact rounded', 12345678.00005678, 12345678 + 0.0000567750000000);
																																AddTestCase('addx62054:p16 r:HALF_EVEN (12345678 + 0.0000067750000000) inexact rounded', 12345678.00000678, 12345678 + 0.0000067750000000);
																																AddTestCase('addx62055:p16 r:HALF_EVEN (12345678 + 0.0000007750000000) inexact rounded', 12345678.00000078, 12345678 + 0.0000007750000000);
																																AddTestCase('addx62056:p16 r:HALF_EVEN (12345678 + 0.0000000750000000) inexact rounded', 12345678.00000008, 12345678 + 0.0000000750000000);
																																AddTestCase('addx62057:p16 r:HALF_EVEN (12345678 + 0.0000000050000000) inexact rounded', 12345678.00000000, 12345678 + 0.0000000050000000);
																																AddTestCase('addx62060:p16 r:HALF_EVEN (12345678 + 0.0234567750000001) inexact rounded', 12345678.02345678, 12345678 + 0.0234567750000001);
																																AddTestCase('addx62061:p16 r:HALF_EVEN (12345678 + 0.0034567750000001) inexact rounded', 12345678.00345678, 12345678 + 0.0034567750000001);
																																AddTestCase('addx62062:p16 r:HALF_EVEN (12345678 + 0.0004567750000001) inexact rounded', 12345678.00045678, 12345678 + 0.0004567750000001);
																																AddTestCase('addx62063:p16 r:HALF_EVEN (12345678 + 0.0000567750000001) inexact rounded', 12345678.00005678, 12345678 + 0.0000567750000001);
																																AddTestCase('addx62064:p16 r:HALF_EVEN (12345678 + 0.0000067750000001) inexact rounded', 12345678.00000678, 12345678 + 0.0000067750000001);
																																AddTestCase('addx62065:p16 r:HALF_EVEN (12345678 + 0.0000007750000001) inexact rounded', 12345678.00000078, 12345678 + 0.0000007750000001);
																																AddTestCase('addx62066:p16 r:HALF_EVEN (12345678 + 0.0000000750000001) inexact rounded', 12345678.00000008, 12345678 + 0.0000000750000001);
																																AddTestCase('addx62067:p16 r:HALF_EVEN (12345678 + 0.0000000050000001) inexact rounded', 12345678.00000001, 12345678 + 0.0000000050000001);
																																// far-out residues (full coefficient gap is 16+15 digits)
																																// payload decapitate
																																{
																																	use precision 5;
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
					}
				}
			}
		}
	}
}
test();
