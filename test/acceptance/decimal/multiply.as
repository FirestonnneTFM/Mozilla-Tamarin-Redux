use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "multiply.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// multiply.dectest -- decimal multiplication                         --
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
// sanity checks (as base, above)
AddTestCase('mulx000:p9 r:HALF_UP (2 * 2)', 4, 2 * 2);
AddTestCase('mulx001:p9 r:HALF_UP (2 * 3)', 6, 2 * 3);
AddTestCase('mulx002:p9 r:HALF_UP (5 * 1)', 5, 5 * 1);
AddTestCase('mulx003:p9 r:HALF_UP (5 * 2)', 10, 5 * 2);
AddTestCase('mulx004:p9 r:HALF_UP (1.20 * 2)', 2.40, 1.20 * 2);
AddTestCase('mulx005:p9 r:HALF_UP (1.20 * 0)', 0.00, 1.20 * 0);
AddTestCase('mulx006:p9 r:HALF_UP (1.20 * -2)', -2.40, 1.20 * -2);
AddTestCase('mulx007:p9 r:HALF_UP (-1.20 * 2)', -2.40, -1.20 * 2);
AddTestCase('mulx008:p9 r:HALF_UP (-1.20 * 0)', -0.00, -1.20 * 0);
AddTestCase('mulx009:p9 r:HALF_UP (-1.20 * -2)', 2.40, -1.20 * -2);
AddTestCase('mulx010:p9 r:HALF_UP (5.09 * 7.1)', 36.139, 5.09 * 7.1);
AddTestCase('mulx011:p9 r:HALF_UP (2.5 * 4)', 10.0, 2.5 * 4);
AddTestCase('mulx012:p9 r:HALF_UP (2.50 * 4)', 10.00, 2.50 * 4);
AddTestCase('mulx013:p9 r:HALF_UP (1.23456789 * 1.00000000) rounded', 1.23456789, 1.23456789 * 1.00000000);
AddTestCase('mulx014:p9 r:HALF_UP (9.999999999 * 9.999999999) inexact rounded', 100.000000, 9.999999999 * 9.999999999);
AddTestCase('mulx015:p9 r:HALF_UP (2.50 * 4)', 10.00, 2.50 * 4);
{
	use precision 6;
	AddTestCase('mulx016:p6 r:HALF_UP (2.50 * 4)', 10.00, 2.50 * 4);
	AddTestCase('mulx017:p6 r:HALF_UP (9.999999999 * 9.999999999) inexact rounded', 100.000, 9.999999999 * 9.999999999);
	AddTestCase('mulx018:p6 r:HALF_UP (9.999999999 * -9.999999999) inexact rounded', -100.000, 9.999999999 * -9.999999999);
	AddTestCase('mulx019:p6 r:HALF_UP (-9.999999999 * 9.999999999) inexact rounded', -100.000, -9.999999999 * 9.999999999);
	AddTestCase('mulx020:p6 r:HALF_UP (-9.999999999 * -9.999999999) inexact rounded', 100.000, -9.999999999 * -9.999999999);
	// 1999.12.21: next one is a edge case if intermediate longs are used
}
{
	use precision 15;
	AddTestCase('mulx059:p15 r:HALF_UP (999999999999 * 9765625) inexact rounded', 9.76562499999023e+18, 999999999999 * 9765625);
}
{
	use precision 30;
	AddTestCase('mulx160:p30 r:HALF_UP (999999999999 * 9765625)', 9765624999990234375, 999999999999 * 9765625);
}
{
	use precision 9;
	//---
	// zeros, etc.
	AddTestCase('mulx021:p9 r:HALF_UP (0 * 0)', 0, 0 * 0);
	AddTestCase('mulx022:p9 r:HALF_UP (0 * -0)', -0, 0 * -0);
	AddTestCase('mulx023:p9 r:HALF_UP (-0 * 0)', -0, -0 * 0);
	AddTestCase('mulx024:p9 r:HALF_UP (-0 * -0)', 0, -0 * -0);
	AddTestCase('mulx025:p9 r:HALF_UP (-0.0 * -0.0)', 0.00, -0.0 * -0.0);
	AddTestCase('mulx026:p9 r:HALF_UP (-0.0 * -0.0)', 0.00, -0.0 * -0.0);
	AddTestCase('mulx027:p9 r:HALF_UP (-0.0 * -0.0)', 0.00, -0.0 * -0.0);
	AddTestCase('mulx028:p9 r:HALF_UP (-0.0 * -0.0)', 0.00, -0.0 * -0.0);
	AddTestCase('mulx030:p9 r:HALF_UP (5.00 * 1e-3)', 0.00500, 5.00 * 1e-3);
	AddTestCase('mulx031:p9 r:HALF_UP (00.00 * 0.000)', 0.00000, 00.00 * 0.000);
	AddTestCase('mulx032:p9 r:HALF_UP (00.00 * 0e-3) -- rhs is 0', 0.00000, 00.00 * 0e-3);
	AddTestCase('mulx033:p9 r:HALF_UP (0e-3 * 00.00) -- lhs is 0', 0.00000, 0e-3 * 00.00);
	AddTestCase('mulx034:p9 r:HALF_UP (-5.00 * 1e-3)', -0.00500, -5.00 * 1e-3);
	AddTestCase('mulx035:p9 r:HALF_UP (-00.00 * 0.000)', -0.00000, -00.00 * 0.000);
	AddTestCase('mulx036:p9 r:HALF_UP (-00.00 * 0e-3) -- rhs is 0', -0.00000, -00.00 * 0e-3);
	AddTestCase('mulx037:p9 r:HALF_UP (-0e-3 * 00.00) -- lhs is 0', -0.00000, -0e-3 * 00.00);
	AddTestCase('mulx038:p9 r:HALF_UP (5.00 * -1e-3)', -0.00500, 5.00 * -1e-3);
	AddTestCase('mulx039:p9 r:HALF_UP (00.00 * -0.000)', -0.00000, 00.00 * -0.000);
	AddTestCase('mulx040:p9 r:HALF_UP (00.00 * -0e-3) -- rhs is 0', -0.00000, 00.00 * -0e-3);
	AddTestCase('mulx041:p9 r:HALF_UP (0e-3 * -00.00) -- lhs is 0', -0.00000, 0e-3 * -00.00);
	AddTestCase('mulx042:p9 r:HALF_UP (-5.00 * -1e-3)', 0.00500, -5.00 * -1e-3);
	AddTestCase('mulx043:p9 r:HALF_UP (-00.00 * -0.000)', 0.00000, -00.00 * -0.000);
	AddTestCase('mulx044:p9 r:HALF_UP (-00.00 * -0e-3) -- rhs is 0', 0.00000, -00.00 * -0e-3);
	AddTestCase('mulx045:p9 r:HALF_UP (-0e-3 * -00.00) -- lhs is 0', 0.00000, -0e-3 * -00.00);
	// examples from decarith
	AddTestCase('mulx050:p9 r:HALF_UP (1.20 * 3)', 3.60, 1.20 * 3);
	AddTestCase('mulx051:p9 r:HALF_UP (7 * 3)', 21, 7 * 3);
	AddTestCase('mulx052:p9 r:HALF_UP (0.9 * 0.8)', 0.72, 0.9 * 0.8);
	AddTestCase('mulx053:p9 r:HALF_UP (0.9 * -0)', -0.0, 0.9 * -0);
	AddTestCase('mulx054:p9 r:HALF_UP (654321 * 654321) inexact rounded', 4.28135971e+11, 654321 * 654321);
	AddTestCase('mulx060:p9 r:HALF_UP (123.45 * 1e7)', 1.2345e+9, 123.45 * 1e7);
	AddTestCase('mulx061:p9 r:HALF_UP (123.45 * 1e8)', 1.2345e+10, 123.45 * 1e8);
	AddTestCase('mulx062:p9 r:HALF_UP (123.45 * 1e+9)', 1.2345e+11, 123.45 * 1e+9);
	AddTestCase('mulx063:p9 r:HALF_UP (123.45 * 1e10)', 1.2345e+12, 123.45 * 1e10);
	AddTestCase('mulx064:p9 r:HALF_UP (123.45 * 1e11)', 1.2345e+13, 123.45 * 1e11);
	AddTestCase('mulx065:p9 r:HALF_UP (123.45 * 1e12)', 1.2345e+14, 123.45 * 1e12);
	AddTestCase('mulx066:p9 r:HALF_UP (123.45 * 1e13)', 1.2345e+15, 123.45 * 1e13);
	// test some intermediate lengths
}
{
	use precision 9;
	AddTestCase('mulx080:p9 r:HALF_UP (0.1 * 123456789)', 12345678.9, 0.1 * 123456789);
	AddTestCase('mulx081:p9 r:HALF_UP (0.1 * 1234567891) inexact rounded', 123456789, 0.1 * 1234567891);
	AddTestCase('mulx082:p9 r:HALF_UP (0.1 * 12345678912) inexact rounded', 1.23456789e+9, 0.1 * 12345678912);
	AddTestCase('mulx083:p9 r:HALF_UP (0.1 * 12345678912345) inexact rounded', 1.23456789e+12, 0.1 * 12345678912345);
	AddTestCase('mulx084:p9 r:HALF_UP (0.1 * 123456789)', 12345678.9, 0.1 * 123456789);
}
{
	use precision 8;
	AddTestCase('mulx085:p8 r:HALF_UP (0.1 * 12345678912) inexact rounded', 1.2345679e+9, 0.1 * 12345678912);
	AddTestCase('mulx086:p8 r:HALF_UP (0.1 * 12345678912345) inexact rounded', 1.2345679e+12, 0.1 * 12345678912345);
}
{
	use precision 7;
	AddTestCase('mulx087:p7 r:HALF_UP (0.1 * 12345678912) inexact rounded', 1.234568e+9, 0.1 * 12345678912);
	AddTestCase('mulx088:p7 r:HALF_UP (0.1 * 12345678912345) inexact rounded', 1.234568e+12, 0.1 * 12345678912345);
}
{
	use precision 9;
	AddTestCase('mulx090:p9 r:HALF_UP (123456789 * 0.1)', 12345678.9, 123456789 * 0.1);
	AddTestCase('mulx091:p9 r:HALF_UP (1234567891 * 0.1) inexact rounded', 123456789, 1234567891 * 0.1);
	AddTestCase('mulx092:p9 r:HALF_UP (12345678912 * 0.1) inexact rounded', 1.23456789e+9, 12345678912 * 0.1);
	AddTestCase('mulx093:p9 r:HALF_UP (12345678912345 * 0.1) inexact rounded', 1.23456789e+12, 12345678912345 * 0.1);
	AddTestCase('mulx094:p9 r:HALF_UP (123456789 * 0.1)', 12345678.9, 123456789 * 0.1);
}
{
	use precision 8;
	AddTestCase('mulx095:p8 r:HALF_UP (12345678912 * 0.1) inexact rounded', 1.2345679e+9, 12345678912 * 0.1);
	AddTestCase('mulx096:p8 r:HALF_UP (12345678912345 * 0.1) inexact rounded', 1.2345679e+12, 12345678912345 * 0.1);
}
{
	use precision 7;
	AddTestCase('mulx097:p7 r:HALF_UP (12345678912 * 0.1) inexact rounded', 1.234568e+9, 12345678912 * 0.1);
	AddTestCase('mulx098:p7 r:HALF_UP (12345678912345 * 0.1) inexact rounded', 1.234568e+12, 12345678912345 * 0.1);
	// test some more edge cases and carries
}
{
	use precision 33;
	AddTestCase('mulx101:p33 r:HALF_UP (9 * 9)', 81, 9 * 9);
	AddTestCase('mulx102:p33 r:HALF_UP (9 * 90)', 810, 9 * 90);
	AddTestCase('mulx103:p33 r:HALF_UP (9 * 900)', 8100, 9 * 900);
	AddTestCase('mulx104:p33 r:HALF_UP (9 * 9000)', 81000, 9 * 9000);
	AddTestCase('mulx105:p33 r:HALF_UP (9 * 90000)', 810000, 9 * 90000);
	AddTestCase('mulx106:p33 r:HALF_UP (9 * 900000)', 8100000, 9 * 900000);
	AddTestCase('mulx107:p33 r:HALF_UP (9 * 9000000)', 81000000, 9 * 9000000);
	AddTestCase('mulx108:p33 r:HALF_UP (9 * 90000000)', 810000000, 9 * 90000000);
	AddTestCase('mulx109:p33 r:HALF_UP (9 * 900000000)', 8100000000, 9 * 900000000);
	AddTestCase('mulx110:p33 r:HALF_UP (9 * 9000000000)', 81000000000, 9 * 9000000000);
	AddTestCase('mulx111:p33 r:HALF_UP (9 * 90000000000)', 810000000000, 9 * 90000000000);
	AddTestCase('mulx112:p33 r:HALF_UP (9 * 900000000000)', 8100000000000, 9 * 900000000000);
	AddTestCase('mulx113:p33 r:HALF_UP (9 * 9000000000000)', 81000000000000, 9 * 9000000000000);
	AddTestCase('mulx114:p33 r:HALF_UP (9 * 90000000000000)', 810000000000000, 9 * 90000000000000);
	AddTestCase('mulx115:p33 r:HALF_UP (9 * 900000000000000)', 8100000000000000, 9 * 900000000000000);
	AddTestCase('mulx116:p33 r:HALF_UP (9 * 9000000000000000)', 81000000000000000, 9 * 9000000000000000);
	AddTestCase('mulx117:p33 r:HALF_UP (9 * 90000000000000000)', 810000000000000000, 9 * 90000000000000000);
	AddTestCase('mulx118:p33 r:HALF_UP (9 * 900000000000000000)', 8100000000000000000, 9 * 900000000000000000);
	AddTestCase('mulx119:p33 r:HALF_UP (9 * 9000000000000000000)', 81000000000000000000, 9 * 9000000000000000000);
	AddTestCase('mulx120:p33 r:HALF_UP (9 * 90000000000000000000)', 810000000000000000000, 9 * 90000000000000000000);
	AddTestCase('mulx121:p33 r:HALF_UP (9 * 900000000000000000000)', 8100000000000000000000, 9 * 900000000000000000000);
	AddTestCase('mulx122:p33 r:HALF_UP (9 * 9000000000000000000000)', 81000000000000000000000, 9 * 9000000000000000000000);
	AddTestCase('mulx123:p33 r:HALF_UP (9 * 90000000000000000000000)', 810000000000000000000000, 9 * 90000000000000000000000);
	// test some more edge cases without carries
	AddTestCase('mulx131:p33 r:HALF_UP (3 * 3)', 9, 3 * 3);
	AddTestCase('mulx132:p33 r:HALF_UP (3 * 30)', 90, 3 * 30);
	AddTestCase('mulx133:p33 r:HALF_UP (3 * 300)', 900, 3 * 300);
	AddTestCase('mulx134:p33 r:HALF_UP (3 * 3000)', 9000, 3 * 3000);
	AddTestCase('mulx135:p33 r:HALF_UP (3 * 30000)', 90000, 3 * 30000);
	AddTestCase('mulx136:p33 r:HALF_UP (3 * 300000)', 900000, 3 * 300000);
	AddTestCase('mulx137:p33 r:HALF_UP (3 * 3000000)', 9000000, 3 * 3000000);
	AddTestCase('mulx138:p33 r:HALF_UP (3 * 30000000)', 90000000, 3 * 30000000);
	AddTestCase('mulx139:p33 r:HALF_UP (3 * 300000000)', 900000000, 3 * 300000000);
	AddTestCase('mulx140:p33 r:HALF_UP (3 * 3000000000)', 9000000000, 3 * 3000000000);
	AddTestCase('mulx141:p33 r:HALF_UP (3 * 30000000000)', 90000000000, 3 * 30000000000);
	AddTestCase('mulx142:p33 r:HALF_UP (3 * 300000000000)', 900000000000, 3 * 300000000000);
	AddTestCase('mulx143:p33 r:HALF_UP (3 * 3000000000000)', 9000000000000, 3 * 3000000000000);
	AddTestCase('mulx144:p33 r:HALF_UP (3 * 30000000000000)', 90000000000000, 3 * 30000000000000);
	AddTestCase('mulx145:p33 r:HALF_UP (3 * 300000000000000)', 900000000000000, 3 * 300000000000000);
	AddTestCase('mulx146:p33 r:HALF_UP (3 * 3000000000000000)', 9000000000000000, 3 * 3000000000000000);
	AddTestCase('mulx147:p33 r:HALF_UP (3 * 30000000000000000)', 90000000000000000, 3 * 30000000000000000);
	AddTestCase('mulx148:p33 r:HALF_UP (3 * 300000000000000000)', 900000000000000000, 3 * 300000000000000000);
	AddTestCase('mulx149:p33 r:HALF_UP (3 * 3000000000000000000)', 9000000000000000000, 3 * 3000000000000000000);
	AddTestCase('mulx150:p33 r:HALF_UP (3 * 30000000000000000000)', 90000000000000000000, 3 * 30000000000000000000);
	AddTestCase('mulx151:p33 r:HALF_UP (3 * 300000000000000000000)', 900000000000000000000, 3 * 300000000000000000000);
	AddTestCase('mulx152:p33 r:HALF_UP (3 * 3000000000000000000000)', 9000000000000000000000, 3 * 3000000000000000000000);
	AddTestCase('mulx153:p33 r:HALF_UP (3 * 30000000000000000000000)', 90000000000000000000000, 3 * 30000000000000000000000);
}
{
	use precision 9;
	// test some cases that are close to exponent overflow/underflow
	AddTestCase('mulx170:p9 r:HALF_UP (1 * 9e999999999)', 9e+999999999, 1 * 9e999999999);
	AddTestCase('mulx171:p9 r:HALF_UP (1 * 9.9e999999999)', 9.9e+999999999, 1 * 9.9e999999999);
	AddTestCase('mulx172:p9 r:HALF_UP (1 * 9.99e999999999)', 9.99e+999999999, 1 * 9.99e999999999);
	AddTestCase('mulx173:p9 r:HALF_UP (9e999999999 * 1)', 9e+999999999, 9e999999999 * 1);
	AddTestCase('mulx174:p9 r:HALF_UP (9.9e999999999 * 1)', 9.9e+999999999, 9.9e999999999 * 1);
	AddTestCase('mulx176:p9 r:HALF_UP (9.99e999999999 * 1)', 9.99e+999999999, 9.99e999999999 * 1);
	AddTestCase('mulx177:p9 r:HALF_UP (1 * 9.99999999e999999999)', 9.99999999e+999999999, 1 * 9.99999999e999999999);
	AddTestCase('mulx178:p9 r:HALF_UP (9.99999999e999999999 * 1)', 9.99999999e+999999999, 9.99999999e999999999 * 1);
	AddTestCase('mulx180:p9 r:HALF_UP (0.1 * 9e-999999998)', 9e-999999999, 0.1 * 9e-999999998);
	AddTestCase('mulx181:p9 r:HALF_UP (0.1 * 99e-999999998)', 9.9e-999999998, 0.1 * 99e-999999998);
	AddTestCase('mulx182:p9 r:HALF_UP (0.1 * 999e-999999998)', 9.99e-999999997, 0.1 * 999e-999999998);
	AddTestCase('mulx183:p9 r:HALF_UP (0.1 * 9e-999999998)', 9e-999999999, 0.1 * 9e-999999998);
	AddTestCase('mulx184:p9 r:HALF_UP (0.1 * 99e-999999998)', 9.9e-999999998, 0.1 * 99e-999999998);
	AddTestCase('mulx185:p9 r:HALF_UP (0.1 * 999e-999999998)', 9.99e-999999997, 0.1 * 999e-999999998);
	AddTestCase('mulx186:p9 r:HALF_UP (0.1 * 999e-999999997)', 9.99e-999999996, 0.1 * 999e-999999997);
	AddTestCase('mulx187:p9 r:HALF_UP (0.1 * 9999e-999999997)', 9.999e-999999995, 0.1 * 9999e-999999997);
	AddTestCase('mulx188:p9 r:HALF_UP (0.1 * 99999e-999999997)', 9.9999e-999999994, 0.1 * 99999e-999999997);
	AddTestCase('mulx190:p9 r:HALF_UP (1 * 9e-999999998)', 9e-999999998, 1 * 9e-999999998);
	AddTestCase('mulx191:p9 r:HALF_UP (1 * 99e-999999998)', 9.9e-999999997, 1 * 99e-999999998);
	AddTestCase('mulx192:p9 r:HALF_UP (1 * 999e-999999998)', 9.99e-999999996, 1 * 999e-999999998);
	AddTestCase('mulx193:p9 r:HALF_UP (9e-999999998 * 1)', 9e-999999998, 9e-999999998 * 1);
	AddTestCase('mulx194:p9 r:HALF_UP (99e-999999998 * 1)', 9.9e-999999997, 99e-999999998 * 1);
	AddTestCase('mulx195:p9 r:HALF_UP (999e-999999998 * 1)', 9.99e-999999996, 999e-999999998 * 1);
	AddTestCase('mulx196:p9 r:HALF_UP (1e-599999999 * 1e-400000000)', 1e-999999999, 1e-599999999 * 1e-400000000);
	AddTestCase('mulx197:p9 r:HALF_UP (1e-600000000 * 1e-399999999)', 1e-999999999, 1e-600000000 * 1e-399999999);
	AddTestCase('mulx198:p9 r:HALF_UP (1.2e-599999999 * 1.2e-400000000)', 1.44e-999999999, 1.2e-599999999 * 1.2e-400000000);
	AddTestCase('mulx199:p9 r:HALF_UP (1.2e-600000000 * 1.2e-399999999)', 1.44e-999999999, 1.2e-600000000 * 1.2e-399999999);
	AddTestCase('mulx201:p9 r:HALF_UP (1e599999999 * 1e400000000)', 1e+999999999, 1e599999999 * 1e400000000);
	AddTestCase('mulx202:p9 r:HALF_UP (1e600000000 * 1e399999999)', 1e+999999999, 1e600000000 * 1e399999999);
	AddTestCase('mulx203:p9 r:HALF_UP (1.2e599999999 * 1.2e400000000)', 1.44e+999999999, 1.2e599999999 * 1.2e400000000);
	AddTestCase('mulx204:p9 r:HALF_UP (1.2e600000000 * 1.2e399999999)', 1.44e+999999999, 1.2e600000000 * 1.2e399999999);
	// long operand triangle
}
{
	use precision 33;
	AddTestCase('mulx246:p33 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.290801193369671916511992830, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 32;
	AddTestCase('mulx247:p32 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.29080119336967191651199283, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 31;
	AddTestCase('mulx248:p31 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.2908011933696719165119928, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 30;
	AddTestCase('mulx249:p30 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.290801193369671916511993, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 29;
	AddTestCase('mulx250:p29 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.29080119336967191651199, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 28;
	AddTestCase('mulx251:p28 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.2908011933696719165120, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 27;
	AddTestCase('mulx252:p27 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.290801193369671916512, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 26;
	AddTestCase('mulx253:p26 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.29080119336967191651, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 25;
	AddTestCase('mulx254:p25 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.2908011933696719165, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 24;
	AddTestCase('mulx255:p24 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.290801193369671917, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 23;
	AddTestCase('mulx256:p23 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.29080119336967192, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 22;
	AddTestCase('mulx257:p22 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.2908011933696719, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 21;
	AddTestCase('mulx258:p21 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.290801193369672, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 20;
	AddTestCase('mulx259:p20 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.29080119336967, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 19;
	AddTestCase('mulx260:p19 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.2908011933697, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 18;
	AddTestCase('mulx261:p18 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.290801193370, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 17;
	AddTestCase('mulx262:p17 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.29080119337, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 16;
	AddTestCase('mulx263:p16 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.2908011934, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 15;
	AddTestCase('mulx264:p15 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.290801193, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 14;
	AddTestCase('mulx265:p14 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.29080119, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 13;
	AddTestCase('mulx266:p13 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.2908012, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 12;
	AddTestCase('mulx267:p12 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.290801, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 11;
	AddTestCase('mulx268:p11 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.29080, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 10;
	AddTestCase('mulx269:p10 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.2908, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 9;
	AddTestCase('mulx270:p9 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.291, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 8;
	AddTestCase('mulx271:p8 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.29, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 7;
	AddTestCase('mulx272:p7 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433.3, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 6;
	AddTestCase('mulx273:p6 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 145433, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 5;
	AddTestCase('mulx274:p5 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 1.4543e+5, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 4;
	AddTestCase('mulx275:p4 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 1.454e+5, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 3;
	AddTestCase('mulx276:p3 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 1.45e+5, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 2;
	AddTestCase('mulx277:p2 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 1.5e+5, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
}
{
	use precision 1;
	AddTestCase('mulx278:p1 r:HALF_UP (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded', 1e+5, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
	// test some edge cases with exact rounding
}
{
	use precision 9;
	AddTestCase('mulx301:p9 r:HALF_UP (9 * 9)', 81, 9 * 9);
	AddTestCase('mulx302:p9 r:HALF_UP (9 * 90)', 810, 9 * 90);
	AddTestCase('mulx303:p9 r:HALF_UP (9 * 900)', 8100, 9 * 900);
	AddTestCase('mulx304:p9 r:HALF_UP (9 * 9000)', 81000, 9 * 9000);
	AddTestCase('mulx305:p9 r:HALF_UP (9 * 90000)', 810000, 9 * 90000);
	AddTestCase('mulx306:p9 r:HALF_UP (9 * 900000)', 8100000, 9 * 900000);
	AddTestCase('mulx307:p9 r:HALF_UP (9 * 9000000)', 81000000, 9 * 9000000);
	AddTestCase('mulx308:p9 r:HALF_UP (9 * 90000000)', 810000000, 9 * 90000000);
	AddTestCase('mulx309:p9 r:HALF_UP (9 * 900000000) rounded', 8.10000000e+9, 9 * 900000000);
	AddTestCase('mulx310:p9 r:HALF_UP (9 * 9000000000) rounded', 8.10000000e+10, 9 * 9000000000);
	AddTestCase('mulx311:p9 r:HALF_UP (9 * 90000000000) rounded', 8.10000000e+11, 9 * 90000000000);
	AddTestCase('mulx312:p9 r:HALF_UP (9 * 900000000000) rounded', 8.10000000e+12, 9 * 900000000000);
	AddTestCase('mulx313:p9 r:HALF_UP (9 * 9000000000000) rounded', 8.10000000e+13, 9 * 9000000000000);
	AddTestCase('mulx314:p9 r:HALF_UP (9 * 90000000000000) rounded', 8.10000000e+14, 9 * 90000000000000);
	AddTestCase('mulx315:p9 r:HALF_UP (9 * 900000000000000) rounded', 8.10000000e+15, 9 * 900000000000000);
	AddTestCase('mulx316:p9 r:HALF_UP (9 * 9000000000000000) rounded', 8.10000000e+16, 9 * 9000000000000000);
	AddTestCase('mulx317:p9 r:HALF_UP (9 * 90000000000000000) rounded', 8.10000000e+17, 9 * 90000000000000000);
	AddTestCase('mulx318:p9 r:HALF_UP (9 * 900000000000000000) rounded', 8.10000000e+18, 9 * 900000000000000000);
	AddTestCase('mulx319:p9 r:HALF_UP (9 * 9000000000000000000) rounded', 8.10000000e+19, 9 * 9000000000000000000);
	AddTestCase('mulx320:p9 r:HALF_UP (9 * 90000000000000000000) rounded', 8.10000000e+20, 9 * 90000000000000000000);
	AddTestCase('mulx321:p9 r:HALF_UP (9 * 900000000000000000000) rounded', 8.10000000e+21, 9 * 900000000000000000000);
	AddTestCase('mulx322:p9 r:HALF_UP (9 * 9000000000000000000000) rounded', 8.10000000e+22, 9 * 9000000000000000000000);
	AddTestCase('mulx323:p9 r:HALF_UP (9 * 90000000000000000000000) rounded', 8.10000000e+23, 9 * 90000000000000000000000);
	// fastpath breakers
}
{
	use precision 29;
	AddTestCase('mulx330:p29 r:HALF_UP (1.491824697641270317824852952837224 * 1.105170918075647624811707826490246514675628614562883537345747603) inexact rounded', 1.6487212707001281468486507878, 1.491824697641270317824852952837224 * 1.105170918075647624811707826490246514675628614562883537345747603);
	// tryzeros cases
}
{
	use precision 7;
	{
		use rounding HALF_UP;
		// mixed with zeros
		{
			use precision 9;
			AddTestCase('mulx541:p9 r:HALF_UP (0 * -1)', -0, 0 * -1);
			AddTestCase('mulx542:p9 r:HALF_UP (-0 * -1)', 0, -0 * -1);
			AddTestCase('mulx543:p9 r:HALF_UP (0 * 1)', 0, 0 * 1);
			AddTestCase('mulx544:p9 r:HALF_UP (-0 * 1)', -0, -0 * 1);
			AddTestCase('mulx545:p9 r:HALF_UP (-1 * 0)', -0, -1 * 0);
			AddTestCase('mulx546:p9 r:HALF_UP (-1 * -0)', 0, -1 * -0);
			AddTestCase('mulx547:p9 r:HALF_UP (1 * 0)', 0, 1 * 0);
			AddTestCase('mulx548:p9 r:HALF_UP (1 * -0)', -0, 1 * -0);
			AddTestCase('mulx551:p9 r:HALF_UP (0.0 * -1)', -0.0, 0.0 * -1);
			AddTestCase('mulx552:p9 r:HALF_UP (-0.0 * -1)', 0.0, -0.0 * -1);
			AddTestCase('mulx553:p9 r:HALF_UP (0.0 * 1)', 0.0, 0.0 * 1);
			AddTestCase('mulx554:p9 r:HALF_UP (-0.0 * 1)', -0.0, -0.0 * 1);
			AddTestCase('mulx555:p9 r:HALF_UP (-1.0 * 0)', -0.0, -1.0 * 0);
			AddTestCase('mulx556:p9 r:HALF_UP (-1.0 * -0)', 0.0, -1.0 * -0);
			AddTestCase('mulx557:p9 r:HALF_UP (1.0 * 0)', 0.0, 1.0 * 0);
			AddTestCase('mulx558:p9 r:HALF_UP (1.0 * -0)', -0.0, 1.0 * -0);
			AddTestCase('mulx561:p9 r:HALF_UP (0 * -1.0)', -0.0, 0 * -1.0);
			AddTestCase('mulx562:p9 r:HALF_UP (-0 * -1.0)', 0.0, -0 * -1.0);
			AddTestCase('mulx563:p9 r:HALF_UP (0 * 1.0)', 0.0, 0 * 1.0);
			AddTestCase('mulx564:p9 r:HALF_UP (-0 * 1.0)', -0.0, -0 * 1.0);
			AddTestCase('mulx565:p9 r:HALF_UP (-1 * 0.0)', -0.0, -1 * 0.0);
			AddTestCase('mulx566:p9 r:HALF_UP (-1 * -0.0)', 0.0, -1 * -0.0);
			AddTestCase('mulx567:p9 r:HALF_UP (1 * 0.0)', 0.0, 1 * 0.0);
			AddTestCase('mulx568:p9 r:HALF_UP (1 * -0.0)', -0.0, 1 * -0.0);
			AddTestCase('mulx571:p9 r:HALF_UP (0.0 * -1.0)', -0.00, 0.0 * -1.0);
			AddTestCase('mulx572:p9 r:HALF_UP (-0.0 * -1.0)', 0.00, -0.0 * -1.0);
			AddTestCase('mulx573:p9 r:HALF_UP (0.0 * 1.0)', 0.00, 0.0 * 1.0);
			AddTestCase('mulx574:p9 r:HALF_UP (-0.0 * 1.0)', -0.00, -0.0 * 1.0);
			AddTestCase('mulx575:p9 r:HALF_UP (-1.0 * 0.0)', -0.00, -1.0 * 0.0);
			AddTestCase('mulx576:p9 r:HALF_UP (-1.0 * -0.0)', 0.00, -1.0 * -0.0);
			AddTestCase('mulx577:p9 r:HALF_UP (1.0 * 0.0)', 0.00, 1.0 * 0.0);
			AddTestCase('mulx578:p9 r:HALF_UP (1.0 * -0.0)', -0.00, 1.0 * -0.0);
			// specials
			AddTestCase('mulx580:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx581:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * -1000)', decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY * -1000);
			AddTestCase('mulx582:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * -1)', decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY * -1);
			AddTestCase('mulx583:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * -0) invalid_operation', NaN, decimal.POSITIVE_INFINITY * -0);
			AddTestCase('mulx584:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * 0) invalid_operation', NaN, decimal.POSITIVE_INFINITY * 0);
			AddTestCase('mulx585:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * 1)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY * 1);
			AddTestCase('mulx586:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * 1000)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY * 1000);
			AddTestCase('mulx587:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx588:p9 r:HALF_UP (-1000 * decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, -1000 * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx589:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx590:p9 r:HALF_UP (-1 * decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, -1 * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx591:p9 r:HALF_UP (-0 * decimal.POSITIVE_INFINITY) invalid_operation', NaN, -0 * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx592:p9 r:HALF_UP (0 * decimal.POSITIVE_INFINITY) invalid_operation', NaN, 0 * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx593:p9 r:HALF_UP (1 * decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, 1 * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx594:p9 r:HALF_UP (1000 * decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, 1000 * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx595:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * decimal.POSITIVE_INFINITY)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx600:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * decimal.NEGATIVE_INFINITY)', decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx601:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * -1000)', decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY * -1000);
			AddTestCase('mulx602:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * -1)', decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY * -1);
			AddTestCase('mulx603:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * -0) invalid_operation', NaN, decimal.NEGATIVE_INFINITY * -0);
			AddTestCase('mulx604:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * 0) invalid_operation', NaN, decimal.NEGATIVE_INFINITY * 0);
			AddTestCase('mulx605:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * 1)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY * 1);
			AddTestCase('mulx606:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * 1000)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY * 1000);
			AddTestCase('mulx607:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx608:p9 r:HALF_UP (-1000 * decimal.POSITIVE_INFINITY)', decimal.NEGATIVE_INFINITY, -1000 * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx609:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * decimal.NEGATIVE_INFINITY)', decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx610:p9 r:HALF_UP (-1 * decimal.NEGATIVE_INFINITY)', decimal.POSITIVE_INFINITY, -1 * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx611:p9 r:HALF_UP (-0 * decimal.NEGATIVE_INFINITY) invalid_operation', NaN, -0 * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx612:p9 r:HALF_UP (0 * decimal.NEGATIVE_INFINITY) invalid_operation', NaN, 0 * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx613:p9 r:HALF_UP (1 * decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, 1 * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx614:p9 r:HALF_UP (1000 * decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, 1000 * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx615:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * decimal.NEGATIVE_INFINITY)', decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx621:p9 r:HALF_UP (NaN * decimal.NEGATIVE_INFINITY)', NaN, NaN * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx622:p9 r:HALF_UP (NaN * -1000)', NaN, NaN * -1000);
			AddTestCase('mulx623:p9 r:HALF_UP (NaN * -1)', NaN, NaN * -1);
			AddTestCase('mulx624:p9 r:HALF_UP (NaN * -0)', NaN, NaN * -0);
			AddTestCase('mulx625:p9 r:HALF_UP (NaN * 0)', NaN, NaN * 0);
			AddTestCase('mulx626:p9 r:HALF_UP (NaN * 1)', NaN, NaN * 1);
			AddTestCase('mulx627:p9 r:HALF_UP (NaN * 1000)', NaN, NaN * 1000);
			AddTestCase('mulx628:p9 r:HALF_UP (NaN * decimal.POSITIVE_INFINITY)', NaN, NaN * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx629:p9 r:HALF_UP (NaN * NaN)', NaN, NaN * NaN);
			AddTestCase('mulx630:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * NaN)', NaN, decimal.NEGATIVE_INFINITY * NaN);
			AddTestCase('mulx631:p9 r:HALF_UP (-1000 * NaN)', NaN, -1000 * NaN);
			AddTestCase('mulx632:p9 r:HALF_UP (-1 * NaN)', NaN, -1 * NaN);
			AddTestCase('mulx633:p9 r:HALF_UP (-0 * NaN)', NaN, -0 * NaN);
			AddTestCase('mulx634:p9 r:HALF_UP (0 * NaN)', NaN, 0 * NaN);
			AddTestCase('mulx635:p9 r:HALF_UP (1 * NaN)', NaN, 1 * NaN);
			AddTestCase('mulx636:p9 r:HALF_UP (1000 * NaN)', NaN, 1000 * NaN);
			AddTestCase('mulx637:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * NaN)', NaN, decimal.POSITIVE_INFINITY * NaN);
			AddTestCase('mulx641:p9 r:HALF_UP (NaN * decimal.NEGATIVE_INFINITY) invalid_operation', NaN, NaN * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx642:p9 r:HALF_UP (NaN * -1000) invalid_operation', NaN, NaN * -1000);
			AddTestCase('mulx643:p9 r:HALF_UP (NaN * -1) invalid_operation', NaN, NaN * -1);
			AddTestCase('mulx644:p9 r:HALF_UP (NaN * -0) invalid_operation', NaN, NaN * -0);
			AddTestCase('mulx645:p9 r:HALF_UP (NaN * 0) invalid_operation', NaN, NaN * 0);
			AddTestCase('mulx646:p9 r:HALF_UP (NaN * 1) invalid_operation', NaN, NaN * 1);
			AddTestCase('mulx647:p9 r:HALF_UP (NaN * 1000) invalid_operation', NaN, NaN * 1000);
			AddTestCase('mulx648:p9 r:HALF_UP (NaN * NaN) invalid_operation', NaN, NaN * NaN);
			AddTestCase('mulx649:p9 r:HALF_UP (NaN * NaN) invalid_operation', NaN, NaN * NaN);
			AddTestCase('mulx650:p9 r:HALF_UP (NaN * NaN) invalid_operation', NaN, NaN * NaN);
			AddTestCase('mulx651:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * NaN) invalid_operation', NaN, decimal.NEGATIVE_INFINITY * NaN);
			AddTestCase('mulx652:p9 r:HALF_UP (-1000 * NaN) invalid_operation', NaN, -1000 * NaN);
			AddTestCase('mulx653:p9 r:HALF_UP (-1 * NaN) invalid_operation', NaN, -1 * NaN);
			AddTestCase('mulx654:p9 r:HALF_UP (-0 * NaN) invalid_operation', NaN, -0 * NaN);
			AddTestCase('mulx655:p9 r:HALF_UP (0 * NaN) invalid_operation', NaN, 0 * NaN);
			AddTestCase('mulx656:p9 r:HALF_UP (1 * NaN) invalid_operation', NaN, 1 * NaN);
			AddTestCase('mulx657:p9 r:HALF_UP (1000 * NaN) invalid_operation', NaN, 1000 * NaN);
			AddTestCase('mulx658:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * NaN) invalid_operation', NaN, decimal.POSITIVE_INFINITY * NaN);
			AddTestCase('mulx659:p9 r:HALF_UP (NaN * NaN) invalid_operation', NaN, NaN * NaN);
			// propagating nans
			AddTestCase('mulx661:p9 r:HALF_UP (NaN * decimal.NEGATIVE_INFINITY)', NaN, NaN * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx662:p9 r:HALF_UP (NaN * 999)', NaN, NaN * 999);
			AddTestCase('mulx663:p9 r:HALF_UP (NaN * decimal.POSITIVE_INFINITY)', NaN, NaN * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx664:p9 r:HALF_UP (NaN * NaN)', NaN, NaN * NaN);
			AddTestCase('mulx665:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * NaN)', NaN, decimal.NEGATIVE_INFINITY * NaN);
			AddTestCase('mulx666:p9 r:HALF_UP (-999 * NaN)', NaN, -999 * NaN);
			AddTestCase('mulx667:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * NaN)', NaN, decimal.POSITIVE_INFINITY * NaN);
			AddTestCase('mulx671:p9 r:HALF_UP (NaN * decimal.NEGATIVE_INFINITY) invalid_operation', NaN, NaN * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx672:p9 r:HALF_UP (NaN * -11) invalid_operation', NaN, NaN * -11);
			AddTestCase('mulx673:p9 r:HALF_UP (NaN * NaN) invalid_operation', NaN, NaN * NaN);
			AddTestCase('mulx674:p9 r:HALF_UP (NaN * NaN) invalid_operation', NaN, NaN * NaN);
			AddTestCase('mulx675:p9 r:HALF_UP (NaN * NaN) invalid_operation', NaN, NaN * NaN);
			AddTestCase('mulx676:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * NaN) invalid_operation', NaN, decimal.NEGATIVE_INFINITY * NaN);
			AddTestCase('mulx677:p9 r:HALF_UP (088 * NaN) invalid_operation', NaN, 088 * NaN);
			AddTestCase('mulx678:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * NaN) invalid_operation', NaN, decimal.POSITIVE_INFINITY * NaN);
			AddTestCase('mulx679:p9 r:HALF_UP (NaN * NaN) invalid_operation', NaN, NaN * NaN);
			AddTestCase('mulx681:p9 r:HALF_UP (-NaN * decimal.NEGATIVE_INFINITY)', -NaN, -NaN * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx682:p9 r:HALF_UP (-NaN * 999)', -NaN, -NaN * 999);
			AddTestCase('mulx683:p9 r:HALF_UP (-NaN * decimal.POSITIVE_INFINITY)', -NaN, -NaN * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx684:p9 r:HALF_UP (-NaN * -NaN)', -NaN, -NaN * -NaN);
			AddTestCase('mulx685:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * -NaN)', -NaN, decimal.NEGATIVE_INFINITY * -NaN);
			AddTestCase('mulx686:p9 r:HALF_UP (-999 * -NaN)', -NaN, -999 * -NaN);
			AddTestCase('mulx687:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * -NaN)', -NaN, decimal.POSITIVE_INFINITY * -NaN);
			AddTestCase('mulx691:p9 r:HALF_UP (-NaN * decimal.NEGATIVE_INFINITY) invalid_operation', -NaN, -NaN * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx692:p9 r:HALF_UP (-NaN * -11) invalid_operation', -NaN, -NaN * -11);
			AddTestCase('mulx693:p9 r:HALF_UP (-NaN * NaN) invalid_operation', -NaN, -NaN * NaN);
			AddTestCase('mulx694:p9 r:HALF_UP (-NaN * -NaN) invalid_operation', -NaN, -NaN * -NaN);
			AddTestCase('mulx695:p9 r:HALF_UP (-NaN * -NaN) invalid_operation', -NaN, -NaN * -NaN);
			AddTestCase('mulx696:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * -NaN) invalid_operation', -NaN, decimal.NEGATIVE_INFINITY * -NaN);
			AddTestCase('mulx697:p9 r:HALF_UP (088 * -NaN) invalid_operation', -NaN, 088 * -NaN);
			AddTestCase('mulx698:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * -NaN) invalid_operation', -NaN, decimal.POSITIVE_INFINITY * -NaN);
			AddTestCase('mulx699:p9 r:HALF_UP (-NaN * -NaN) invalid_operation', -NaN, -NaN * -NaN);
			AddTestCase('mulx701:p9 r:HALF_UP (-NaN * decimal.NEGATIVE_INFINITY)', -NaN, -NaN * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx702:p9 r:HALF_UP (-NaN * 999)', -NaN, -NaN * 999);
			AddTestCase('mulx703:p9 r:HALF_UP (-NaN * decimal.POSITIVE_INFINITY)', -NaN, -NaN * decimal.POSITIVE_INFINITY);
			AddTestCase('mulx704:p9 r:HALF_UP (-NaN * -NaN)', -NaN, -NaN * -NaN);
			AddTestCase('mulx705:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * -NaN)', -NaN, decimal.NEGATIVE_INFINITY * -NaN);
			AddTestCase('mulx706:p9 r:HALF_UP (-999 * -NaN)', -NaN, -999 * -NaN);
			AddTestCase('mulx707:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * -NaN)', -NaN, decimal.POSITIVE_INFINITY * -NaN);
			AddTestCase('mulx711:p9 r:HALF_UP (-NaN * decimal.NEGATIVE_INFINITY) invalid_operation', -NaN, -NaN * decimal.NEGATIVE_INFINITY);
			AddTestCase('mulx712:p9 r:HALF_UP (-NaN * -11) invalid_operation', -NaN, -NaN * -11);
			AddTestCase('mulx713:p9 r:HALF_UP (-NaN * NaN) invalid_operation', -NaN, -NaN * NaN);
			AddTestCase('mulx714:p9 r:HALF_UP (-NaN * -NaN) invalid_operation', -NaN, -NaN * -NaN);
			AddTestCase('mulx715:p9 r:HALF_UP (-NaN * -NaN) invalid_operation', -NaN, -NaN * -NaN);
			AddTestCase('mulx716:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY * -NaN) invalid_operation', -NaN, decimal.NEGATIVE_INFINITY * -NaN);
			AddTestCase('mulx717:p9 r:HALF_UP (088 * -NaN) invalid_operation', -NaN, 088 * -NaN);
			AddTestCase('mulx718:p9 r:HALF_UP (decimal.POSITIVE_INFINITY * -NaN) invalid_operation', -NaN, decimal.POSITIVE_INFINITY * -NaN);
			AddTestCase('mulx719:p9 r:HALF_UP (-NaN * -NaN) invalid_operation', -NaN, -NaN * -NaN);
			// overflow and underflow tests .. note subnormal results
			AddTestCase('mulx740:p9 r:HALF_UP (1e-599999999 * 1e-400000000)', 1e-999999999, 1e-599999999 * 1e-400000000);
			AddTestCase('mulx743:p9 r:HALF_UP (9e-999999998 * 0.1)', 9e-999999999, 9e-999999998 * 0.1);
			AddTestCase('mulx746:p9 r:HALF_UP (1e599999999 * 1e400000000)', 1e+999999999, 1e599999999 * 1e400000000);
			AddTestCase('mulx749:p9 r:HALF_UP (9e999999998 * 10)', 9.0e+999999999, 9e999999998 * 10);
			// signs
			// 'subnormal' boundary (all hard underflow or overflow in base arithemtic)
		}
		{
			use precision 9;
			// [no equivalent of 'subnormal' for overflow]
			// 'subnormal' test edge condition at higher precisions
			// following testcases [through mulx800] not yet run against code
			// test subnormals rounding
		}
		{
			use precision 5;
			{
				use rounding HALF_EVEN;
				AddTestCase('mulx801:p5 r:HALF_EVEN (1.0000e-999 * 1)', 1.0000e-999, 1.0000e-999 * 1);
				AddTestCase('mulx836:p5 r:HALF_EVEN (40.0e-501 * 40e-501)', 1.6000e-999, 40.0e-501 * 40e-501);
				// squares
				AddTestCase('mulx846:p5 r:HALF_EVEN (40e-501 * 40e-501)', 1.600e-999, 40e-501 * 40e-501);
				// cubes
				AddTestCase('mulx856:p5 r:HALF_EVEN (10e-668 * 100e-334)', 1.000e-999, 10e-668 * 100e-334);
				// test derived from result of 0.099 ** 999 at 15 digits with unlimited exponent
				{
					use precision 19;
					// long operand overflow may be a different path
				}
				{
					use precision 3;
					// check for double-rounded subnormals
				}
				{
					use precision 5;
					AddTestCase('mulx891:p5 r:HALF_EVEN (1.2345e-39 * 1.234e-40) inexact rounded', 1.5234e-79, 1.2345e-39 * 1.234e-40);
					AddTestCase('mulx892:p5 r:HALF_EVEN (1.23456e-39 * 1.234e-40) inexact rounded', 1.5234e-79, 1.23456e-39 * 1.234e-40);
					// now explore the case where we get a normal result with underflow
				}
				{
					use precision 16;
					{
						use rounding HALF_UP;
						// prove operands are exact
						AddTestCase('mulx906:p16 r:HALF_UP (9.999999999999999e-383 * 1)', 9.999999999999999e-383, 9.999999999999999e-383 * 1);
						AddTestCase('mulx907:p16 r:HALF_UP (1 * 0.09999999999999999)', 0.09999999999999999, 1 * 0.09999999999999999);
						// the next rounds to nmin
						// examples from sql proposal (krishna kulkarni)
					}
					{
						use rounding HALF_UP;
						// payload decapitate
						{
							use precision 5;
							AddTestCase('mulx1010:p5 r:HALF_UP (11 * -NaN) invalid_operation', -NaN, 11 * -NaN);
							// null tests
							AddTestCase('mulx990:p5 r:HALF_UP (10 * null) invalid_operation', 0, 10 * null);
							AddTestCase('mulx991:p5 r:HALF_UP (null * 10) invalid_operation', 0, null * 10);
							}
						}
					}
				}
			}
		}
	}
}
test();
