use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "inexact.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// inexact.dectest -- decimal inexact and rounded edge cases          --
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
AddTestCase('inx001:p9 r:HALF_UP (1 + 1)', 2, 1 + 1);
AddTestCase('inx002:p9 r:HALF_UP (123456789 + 0)', 123456789, 123456789 + 0);
AddTestCase('inx003:p9 r:HALF_UP (123456789 + 0.0) rounded', 123456789, 123456789 + 0.0);
AddTestCase('inx004:p9 r:HALF_UP (123456789 + 0.00) rounded', 123456789, 123456789 + 0.00);
AddTestCase('inx005:p9 r:HALF_UP (123456789 + 1)', 123456790, 123456789 + 1);
AddTestCase('inx006:p9 r:HALF_UP (123456789 + 0.1) inexact rounded', 123456789, 123456789 + 0.1);
AddTestCase('inx007:p9 r:HALF_UP (123456789 + 0.01) inexact rounded', 123456789, 123456789 + 0.01);
AddTestCase('inx008:p9 r:HALF_UP (123456789 + 0.001) inexact rounded', 123456789, 123456789 + 0.001);
AddTestCase('inx009:p9 r:HALF_UP (123456789 + 0.000001) inexact rounded', 123456789, 123456789 + 0.000001);
AddTestCase('inx010:p9 r:HALF_UP (123456789 + 0.000000001) inexact rounded', 123456789, 123456789 + 0.000000001);
AddTestCase('inx011:p9 r:HALF_UP (123456789 + 0.000000000001) inexact rounded', 123456789, 123456789 + 0.000000000001);
AddTestCase('inx012:p9 r:HALF_UP (123456789 + 0.9) inexact rounded', 123456790, 123456789 + 0.9);
AddTestCase('inx013:p9 r:HALF_UP (123456789 + 0.09) inexact rounded', 123456789, 123456789 + 0.09);
AddTestCase('inx014:p9 r:HALF_UP (123456789 + 0.009) inexact rounded', 123456789, 123456789 + 0.009);
AddTestCase('inx015:p9 r:HALF_UP (123456789 + 0.000009) inexact rounded', 123456789, 123456789 + 0.000009);
AddTestCase('inx016:p9 r:HALF_UP (123456789 + 0.000000009) inexact rounded', 123456789, 123456789 + 0.000000009);
AddTestCase('inx017:p9 r:HALF_UP (123456789 + 0.000000000009) inexact rounded', 123456789, 123456789 + 0.000000000009);
AddTestCase('inx021:p9 r:HALF_UP (1 + -1)', 0, 1 + -1);
AddTestCase('inx022:p9 r:HALF_UP (123456789 + -0)', 123456789, 123456789 + -0);
AddTestCase('inx023:p9 r:HALF_UP (123456789 + -0.0) rounded', 123456789, 123456789 + -0.0);
AddTestCase('inx024:p9 r:HALF_UP (123456789 + -0.00) rounded', 123456789, 123456789 + -0.00);
AddTestCase('inx025:p9 r:HALF_UP (123456789 + -1)', 123456788, 123456789 + -1);
AddTestCase('inx026:p9 r:HALF_UP (123456789 + -0.1) inexact rounded', 123456789, 123456789 + -0.1);
AddTestCase('inx027:p9 r:HALF_UP (123456789 + -0.01) inexact rounded', 123456789, 123456789 + -0.01);
AddTestCase('inx028:p9 r:HALF_UP (123456789 + -0.001) inexact rounded', 123456789, 123456789 + -0.001);
AddTestCase('inx029:p9 r:HALF_UP (123456789 + -0.000001) inexact rounded', 123456789, 123456789 + -0.000001);
AddTestCase('inx030:p9 r:HALF_UP (123456789 + -0.000000001) inexact rounded', 123456789, 123456789 + -0.000000001);
AddTestCase('inx031:p9 r:HALF_UP (123456789 + -0.000000000001) inexact rounded', 123456789, 123456789 + -0.000000000001);
AddTestCase('inx032:p9 r:HALF_UP (123456789 + -0.9) inexact rounded', 123456788, 123456789 + -0.9);
AddTestCase('inx033:p9 r:HALF_UP (123456789 + -0.09) inexact rounded', 123456789, 123456789 + -0.09);
AddTestCase('inx034:p9 r:HALF_UP (123456789 + -0.009) inexact rounded', 123456789, 123456789 + -0.009);
AddTestCase('inx035:p9 r:HALF_UP (123456789 + -0.000009) inexact rounded', 123456789, 123456789 + -0.000009);
AddTestCase('inx036:p9 r:HALF_UP (123456789 + -0.000000009) inexact rounded', 123456789, 123456789 + -0.000000009);
AddTestCase('inx037:p9 r:HALF_UP (123456789 + -0.000000000009) inexact rounded', 123456789, 123456789 + -0.000000000009);
AddTestCase('inx042:p9 r:HALF_UP (0 + 123456789)', 123456789, 0 + 123456789);
AddTestCase('inx043:p9 r:HALF_UP (0.0 + 123456789) rounded', 123456789, 0.0 + 123456789);
AddTestCase('inx044:p9 r:HALF_UP (0.00 + 123456789) rounded', 123456789, 0.00 + 123456789);
AddTestCase('inx045:p9 r:HALF_UP (1 + 123456789)', 123456790, 1 + 123456789);
AddTestCase('inx046:p9 r:HALF_UP (0.1 + 123456789) inexact rounded', 123456789, 0.1 + 123456789);
AddTestCase('inx047:p9 r:HALF_UP (0.01 + 123456789) inexact rounded', 123456789, 0.01 + 123456789);
AddTestCase('inx048:p9 r:HALF_UP (0.001 + 123456789) inexact rounded', 123456789, 0.001 + 123456789);
AddTestCase('inx049:p9 r:HALF_UP (0.000001 + 123456789) inexact rounded', 123456789, 0.000001 + 123456789);
AddTestCase('inx050:p9 r:HALF_UP (0.000000001 + 123456789) inexact rounded', 123456789, 0.000000001 + 123456789);
AddTestCase('inx051:p9 r:HALF_UP (0.000000000001 + 123456789) inexact rounded', 123456789, 0.000000000001 + 123456789);
AddTestCase('inx052:p9 r:HALF_UP (0.9 + 123456789) inexact rounded', 123456790, 0.9 + 123456789);
AddTestCase('inx053:p9 r:HALF_UP (0.09 + 123456789) inexact rounded', 123456789, 0.09 + 123456789);
AddTestCase('inx054:p9 r:HALF_UP (0.009 + 123456789) inexact rounded', 123456789, 0.009 + 123456789);
AddTestCase('inx055:p9 r:HALF_UP (0.000009 + 123456789) inexact rounded', 123456789, 0.000009 + 123456789);
AddTestCase('inx056:p9 r:HALF_UP (0.000000009 + 123456789) inexact rounded', 123456789, 0.000000009 + 123456789);
AddTestCase('inx057:p9 r:HALF_UP (0.000000000009 + 123456789) inexact rounded', 123456789, 0.000000000009 + 123456789);
AddTestCase('inx062:p9 r:HALF_UP (-0 + 123456789)', 123456789, -0 + 123456789);
AddTestCase('inx063:p9 r:HALF_UP (-0.0 + 123456789) rounded', 123456789, -0.0 + 123456789);
AddTestCase('inx064:p9 r:HALF_UP (-0.00 + 123456789) rounded', 123456789, -0.00 + 123456789);
AddTestCase('inx065:p9 r:HALF_UP (-1 + 123456789)', 123456788, -1 + 123456789);
AddTestCase('inx066:p9 r:HALF_UP (-0.1 + 123456789) inexact rounded', 123456789, -0.1 + 123456789);
AddTestCase('inx067:p9 r:HALF_UP (-0.01 + 123456789) inexact rounded', 123456789, -0.01 + 123456789);
AddTestCase('inx068:p9 r:HALF_UP (-0.001 + 123456789) inexact rounded', 123456789, -0.001 + 123456789);
AddTestCase('inx069:p9 r:HALF_UP (-0.000001 + 123456789) inexact rounded', 123456789, -0.000001 + 123456789);
AddTestCase('inx070:p9 r:HALF_UP (-0.000000001 + 123456789) inexact rounded', 123456789, -0.000000001 + 123456789);
AddTestCase('inx071:p9 r:HALF_UP (-0.000000000001 + 123456789) inexact rounded', 123456789, -0.000000000001 + 123456789);
AddTestCase('inx072:p9 r:HALF_UP (-0.9 + 123456789) inexact rounded', 123456788, -0.9 + 123456789);
AddTestCase('inx073:p9 r:HALF_UP (-0.09 + 123456789) inexact rounded', 123456789, -0.09 + 123456789);
AddTestCase('inx074:p9 r:HALF_UP (-0.009 + 123456789) inexact rounded', 123456789, -0.009 + 123456789);
AddTestCase('inx075:p9 r:HALF_UP (-0.000009 + 123456789) inexact rounded', 123456789, -0.000009 + 123456789);
AddTestCase('inx076:p9 r:HALF_UP (-0.000000009 + 123456789) inexact rounded', 123456789, -0.000000009 + 123456789);
AddTestCase('inx077:p9 r:HALF_UP (-0.000000000009 + 123456789) inexact rounded', 123456789, -0.000000000009 + 123456789);
// some boundaries
AddTestCase('inx081:p9 r:HALF_UP (999999999 + 0)', 999999999, 999999999 + 0);
AddTestCase('inx082:p9 r:HALF_UP (0.999999999 + 0.000000000)', 0.999999999, 0.999999999 + 0.000000000);
AddTestCase('inx083:p9 r:HALF_UP (999999999 + 1) rounded', 1.00000000e+9, 999999999 + 1);
AddTestCase('inx084:p9 r:HALF_UP (0.999999999 + 0.000000001) rounded', 1.00000000, 0.999999999 + 0.000000001);
AddTestCase('inx085:p9 r:HALF_UP (999999999 + 2) inexact rounded', 1.00000000e+9, 999999999 + 2);
AddTestCase('inx086:p9 r:HALF_UP (0.999999999 + 0.000000002) inexact rounded', 1.00000000, 0.999999999 + 0.000000002);
AddTestCase('inx087:p9 r:HALF_UP (999999999 + 3) inexact rounded', 1.00000000e+9, 999999999 + 3);
AddTestCase('inx089:p9 r:HALF_UP (0.999999999 + 0.000000003) inexact rounded', 1.00000000, 0.999999999 + 0.000000003);
// minus, plus, and subtract all assumed to work like add.
// multiply
{
	use precision 8;
	AddTestCase('inx101:p8 r:HALF_UP (1000 * 1000)', 1000000, 1000 * 1000);
	AddTestCase('inx102:p8 r:HALF_UP (9000 * 9000)', 81000000, 9000 * 9000);
	AddTestCase('inx103:p8 r:HALF_UP (9999 * 9999)', 99980001, 9999 * 9999);
	AddTestCase('inx104:p8 r:HALF_UP (1000 * 10000)', 10000000, 1000 * 10000);
	AddTestCase('inx105:p8 r:HALF_UP (10000 * 10000) rounded', 1.0000000e+8, 10000 * 10000);
	AddTestCase('inx106:p8 r:HALF_UP (10001 * 10000) rounded', 1.0001000e+8, 10001 * 10000);
	AddTestCase('inx107:p8 r:HALF_UP (10001 * 10001) inexact rounded', 1.0002000e+8, 10001 * 10001);
	AddTestCase('inx108:p8 r:HALF_UP (10101 * 10001) inexact rounded', 1.0102010e+8, 10101 * 10001);
	AddTestCase('inx109:p8 r:HALF_UP (10001 * 10101) inexact rounded', 1.0102010e+8, 10001 * 10101);
	// divide
}
{
	use precision 4;
	AddTestCase('inx201:p4 r:HALF_UP (1000 / 1000)', 1, 1000 / 1000);
	AddTestCase('inx202:p4 r:HALF_UP (1000 / 1)', 1000, 1000 / 1);
	AddTestCase('inx203:p4 r:HALF_UP (1000 / 2)', 500, 1000 / 2);
	AddTestCase('inx204:p4 r:HALF_UP (1000 / 3) inexact rounded', 333.3, 1000 / 3);
	AddTestCase('inx205:p4 r:HALF_UP (1000 / 4)', 250, 1000 / 4);
	AddTestCase('inx206:p4 r:HALF_UP (1000 / 5)', 200, 1000 / 5);
	AddTestCase('inx207:p4 r:HALF_UP (1000 / 6) inexact rounded', 166.7, 1000 / 6);
	AddTestCase('inx208:p4 r:HALF_UP (1000 / 7) inexact rounded', 142.9, 1000 / 7);
	AddTestCase('inx209:p4 r:HALF_UP (1000 / 8)', 125, 1000 / 8);
	AddTestCase('inx210:p4 r:HALF_UP (1000 / 9) inexact rounded', 111.1, 1000 / 9);
	AddTestCase('inx211:p4 r:HALF_UP (1000 / 10)', 100, 1000 / 10);
	AddTestCase('inx220:p4 r:HALF_UP (1 / 1)', 1, 1 / 1);
	AddTestCase('inx221:p4 r:HALF_UP (1 / 2)', 0.5, 1 / 2);
	AddTestCase('inx222:p4 r:HALF_UP (1 / 4)', 0.25, 1 / 4);
	AddTestCase('inx223:p4 r:HALF_UP (1 / 8)', 0.125, 1 / 8);
	AddTestCase('inx224:p4 r:HALF_UP (1 / 16)', 0.0625, 1 / 16);
	AddTestCase('inx225:p4 r:HALF_UP (1 / 32)', 0.03125, 1 / 32);
	AddTestCase('inx226:p4 r:HALF_UP (1 / 64) inexact rounded', 0.01563, 1 / 64);
	AddTestCase('inx227:p4 r:HALF_UP (1 / 128) inexact rounded', 0.007813, 1 / 128);
}
{
	use precision 5;
	AddTestCase('inx230:p5 r:HALF_UP (1 / 1)', 1, 1 / 1);
	AddTestCase('inx231:p5 r:HALF_UP (1 / 2)', 0.5, 1 / 2);
	AddTestCase('inx232:p5 r:HALF_UP (1 / 4)', 0.25, 1 / 4);
	AddTestCase('inx233:p5 r:HALF_UP (1 / 8)', 0.125, 1 / 8);
	AddTestCase('inx234:p5 r:HALF_UP (1 / 16)', 0.0625, 1 / 16);
	AddTestCase('inx235:p5 r:HALF_UP (1 / 32)', 0.03125, 1 / 32);
	AddTestCase('inx236:p5 r:HALF_UP (1 / 64)', 0.015625, 1 / 64);
	AddTestCase('inx237:p5 r:HALF_UP (1 / 128)', 0.0078125, 1 / 128);
}
{
	use precision 3;
	AddTestCase('inx240:p3 r:HALF_UP (1 / 1)', 1, 1 / 1);
	AddTestCase('inx241:p3 r:HALF_UP (1 / 2)', 0.5, 1 / 2);
	AddTestCase('inx242:p3 r:HALF_UP (1 / 4)', 0.25, 1 / 4);
	AddTestCase('inx243:p3 r:HALF_UP (1 / 8)', 0.125, 1 / 8);
	AddTestCase('inx244:p3 r:HALF_UP (1 / 16)', 0.0625, 1 / 16);
	AddTestCase('inx245:p3 r:HALF_UP (1 / 32) inexact rounded', 0.0313, 1 / 32);
	AddTestCase('inx246:p3 r:HALF_UP (1 / 64) inexact rounded', 0.0156, 1 / 64);
	AddTestCase('inx247:p3 r:HALF_UP (1 / 128) inexact rounded', 0.00781, 1 / 128);
}
{
	use precision 2;
	AddTestCase('inx250:p2 r:HALF_UP (1 / 1)', 1, 1 / 1);
	AddTestCase('inx251:p2 r:HALF_UP (1 / 2)', 0.5, 1 / 2);
	AddTestCase('inx252:p2 r:HALF_UP (1 / 4)', 0.25, 1 / 4);
	AddTestCase('inx253:p2 r:HALF_UP (1 / 8) inexact rounded', 0.13, 1 / 8);
	AddTestCase('inx254:p2 r:HALF_UP (1 / 16) inexact rounded', 0.063, 1 / 16);
	AddTestCase('inx255:p2 r:HALF_UP (1 / 32) inexact rounded', 0.031, 1 / 32);
	AddTestCase('inx256:p2 r:HALF_UP (1 / 64) inexact rounded', 0.016, 1 / 64);
	AddTestCase('inx257:p2 r:HALF_UP (1 / 128) inexact rounded', 0.0078, 1 / 128);
}
{
	use precision 1;
	AddTestCase('inx260:p1 r:HALF_UP (1 / 1)', 1, 1 / 1);
	AddTestCase('inx261:p1 r:HALF_UP (1 / 2)', 0.5, 1 / 2);
	AddTestCase('inx262:p1 r:HALF_UP (1 / 4) inexact rounded', 0.3, 1 / 4);
	AddTestCase('inx263:p1 r:HALF_UP (1 / 8) inexact rounded', 0.1, 1 / 8);
	AddTestCase('inx264:p1 r:HALF_UP (1 / 16) inexact rounded', 0.06, 1 / 16);
	AddTestCase('inx265:p1 r:HALF_UP (1 / 32) inexact rounded', 0.03, 1 / 32);
	AddTestCase('inx266:p1 r:HALF_UP (1 / 64) inexact rounded', 0.02, 1 / 64);
	AddTestCase('inx267:p1 r:HALF_UP (1 / 128) inexact rounded', 0.008, 1 / 128);
	// power
}
{
	use precision 4;
	AddTestCase('inx301:p4 r:HALF_UP (0 + decimal.pow(0.5,2))', 0.25, 0 + decimal.pow(0.5,2));
	AddTestCase('inx302:p4 r:HALF_UP (0 + decimal.pow(0.5,4))', 0.0625, 0 + decimal.pow(0.5,4));
	AddTestCase('inx303:p4 r:HALF_UP (0 + decimal.pow(0.5,8)) inexact rounded', 0.003906, 0 + decimal.pow(0.5,8));
	AddTestCase('inx304:p4 r:HALF_UP (0 + decimal.pow(0.5,16)) inexact rounded', 0.00001526, 0 + decimal.pow(0.5,16));
	AddTestCase('inx305:p4 r:HALF_UP (0 + decimal.pow(0.5,32)) inexact rounded', 2.328e-10, 0 + decimal.pow(0.5,32));
	// compare, divideinteger, and remainder are always exact
	// rescale
}
{
	use precision 4;
	// long operands cause rounding too
}
{
	use precision 9;
	}
}
test();
