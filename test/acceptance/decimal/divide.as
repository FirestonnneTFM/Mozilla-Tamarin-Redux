use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "divide.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// divide.dectest -- decimal division                                 --
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
// sanity checks
AddTestCase('divx001:p9 r:HALF_UP (1 / 1)', 1, 1 / 1);
AddTestCase('divx002:p9 r:HALF_UP (2 / 1)', 2, 2 / 1);
AddTestCase('divx003:p9 r:HALF_UP (1 / 2)', 0.5, 1 / 2);
AddTestCase('divx004:p9 r:HALF_UP (2 / 2)', 1, 2 / 2);
AddTestCase('divx005:p9 r:HALF_UP (0 / 1)', 0, 0 / 1);
AddTestCase('divx006:p9 r:HALF_UP (0 / 2)', 0, 0 / 2);
AddTestCase('divx007:p9 r:HALF_UP (1 / 3) inexact rounded', 0.333333333, 1 / 3);
AddTestCase('divx008:p9 r:HALF_UP (2 / 3) inexact rounded', 0.666666667, 2 / 3);
AddTestCase('divx009:p9 r:HALF_UP (3 / 3)', 1, 3 / 3);
AddTestCase('divx010:p9 r:HALF_UP (2.4 / 1)', 2.4, 2.4 / 1);
AddTestCase('divx011:p9 r:HALF_UP (2.4 / -1)', -2.4, 2.4 / -1);
AddTestCase('divx012:p9 r:HALF_UP (-2.4 / 1)', -2.4, -2.4 / 1);
AddTestCase('divx013:p9 r:HALF_UP (-2.4 / -1)', 2.4, -2.4 / -1);
AddTestCase('divx014:p9 r:HALF_UP (2.40 / 1)', 2.40, 2.40 / 1);
AddTestCase('divx015:p9 r:HALF_UP (2.400 / 1)', 2.400, 2.400 / 1);
AddTestCase('divx016:p9 r:HALF_UP (2.4 / 2)', 1.2, 2.4 / 2);
AddTestCase('divx017:p9 r:HALF_UP (2.400 / 2)', 1.200, 2.400 / 2);
AddTestCase('divx018:p9 r:HALF_UP (2. / 2)', 1, 2. / 2);
AddTestCase('divx019:p9 r:HALF_UP (20 / 20)', 1, 20 / 20);
AddTestCase('divx020:p9 r:HALF_UP (187 / 187)', 1, 187 / 187);
AddTestCase('divx021:p9 r:HALF_UP (5 / 2)', 2.5, 5 / 2);
AddTestCase('divx022:p9 r:HALF_UP (50 / 20)', 2.5, 50 / 20);
AddTestCase('divx023:p9 r:HALF_UP (500 / 200)', 2.5, 500 / 200);
AddTestCase('divx024:p9 r:HALF_UP (50.0 / 20.0)', 2.5, 50.0 / 20.0);
AddTestCase('divx025:p9 r:HALF_UP (5.00 / 2.00)', 2.5, 5.00 / 2.00);
AddTestCase('divx026:p9 r:HALF_UP (5 / 2.0)', 2.5, 5 / 2.0);
AddTestCase('divx027:p9 r:HALF_UP (5 / 2.000)', 2.5, 5 / 2.000);
AddTestCase('divx028:p9 r:HALF_UP (5 / 0.20)', 25, 5 / 0.20);
AddTestCase('divx029:p9 r:HALF_UP (5 / 0.200)', 25, 5 / 0.200);
AddTestCase('divx030:p9 r:HALF_UP (10 / 1)', 10, 10 / 1);
AddTestCase('divx031:p9 r:HALF_UP (100 / 1)', 100, 100 / 1);
AddTestCase('divx032:p9 r:HALF_UP (1000 / 1)', 1000, 1000 / 1);
AddTestCase('divx033:p9 r:HALF_UP (1000 / 100)', 10, 1000 / 100);
AddTestCase('divx035:p9 r:HALF_UP (1 / 2)', 0.5, 1 / 2);
AddTestCase('divx036:p9 r:HALF_UP (1 / 4)', 0.25, 1 / 4);
AddTestCase('divx037:p9 r:HALF_UP (1 / 8)', 0.125, 1 / 8);
AddTestCase('divx038:p9 r:HALF_UP (1 / 16)', 0.0625, 1 / 16);
AddTestCase('divx039:p9 r:HALF_UP (1 / 32)', 0.03125, 1 / 32);
AddTestCase('divx040:p9 r:HALF_UP (1 / 64)', 0.015625, 1 / 64);
AddTestCase('divx041:p9 r:HALF_UP (1 / -2)', -0.5, 1 / -2);
AddTestCase('divx042:p9 r:HALF_UP (1 / -4)', -0.25, 1 / -4);
AddTestCase('divx043:p9 r:HALF_UP (1 / -8)', -0.125, 1 / -8);
AddTestCase('divx044:p9 r:HALF_UP (1 / -16)', -0.0625, 1 / -16);
AddTestCase('divx045:p9 r:HALF_UP (1 / -32)', -0.03125, 1 / -32);
AddTestCase('divx046:p9 r:HALF_UP (1 / -64)', -0.015625, 1 / -64);
AddTestCase('divx047:p9 r:HALF_UP (-1 / 2)', -0.5, -1 / 2);
AddTestCase('divx048:p9 r:HALF_UP (-1 / 4)', -0.25, -1 / 4);
AddTestCase('divx049:p9 r:HALF_UP (-1 / 8)', -0.125, -1 / 8);
AddTestCase('divx050:p9 r:HALF_UP (-1 / 16)', -0.0625, -1 / 16);
AddTestCase('divx051:p9 r:HALF_UP (-1 / 32)', -0.03125, -1 / 32);
AddTestCase('divx052:p9 r:HALF_UP (-1 / 64)', -0.015625, -1 / 64);
AddTestCase('divx053:p9 r:HALF_UP (-1 / -2)', 0.5, -1 / -2);
AddTestCase('divx054:p9 r:HALF_UP (-1 / -4)', 0.25, -1 / -4);
AddTestCase('divx055:p9 r:HALF_UP (-1 / -8)', 0.125, -1 / -8);
AddTestCase('divx056:p9 r:HALF_UP (-1 / -16)', 0.0625, -1 / -16);
AddTestCase('divx057:p9 r:HALF_UP (-1 / -32)', 0.03125, -1 / -32);
AddTestCase('divx058:p9 r:HALF_UP (-1 / -64)', 0.015625, -1 / -64);
AddTestCase('divx070:p9 r:HALF_UP (999999999 / 1)', 999999999, 999999999 / 1);
AddTestCase('divx071:p9 r:HALF_UP (999999999.4 / 1) inexact rounded', 999999999, 999999999.4 / 1);
AddTestCase('divx072:p9 r:HALF_UP (999999999.5 / 1) inexact rounded', 1.00000000e+9, 999999999.5 / 1);
AddTestCase('divx073:p9 r:HALF_UP (999999999.9 / 1) inexact rounded', 1.00000000e+9, 999999999.9 / 1);
AddTestCase('divx074:p9 r:HALF_UP (999999999.999 / 1) inexact rounded', 1.00000000e+9, 999999999.999 / 1);
{
	use precision 6;
	AddTestCase('divx080:p6 r:HALF_UP (999999999 / 1) inexact rounded', 1.00000e+9, 999999999 / 1);
	AddTestCase('divx081:p6 r:HALF_UP (99999999 / 1) inexact rounded', 1.00000e+8, 99999999 / 1);
	AddTestCase('divx082:p6 r:HALF_UP (9999999 / 1) inexact rounded', 1.00000e+7, 9999999 / 1);
	AddTestCase('divx083:p6 r:HALF_UP (999999 / 1)', 999999, 999999 / 1);
	AddTestCase('divx084:p6 r:HALF_UP (99999 / 1)', 99999, 99999 / 1);
	AddTestCase('divx085:p6 r:HALF_UP (9999 / 1)', 9999, 9999 / 1);
	AddTestCase('divx086:p6 r:HALF_UP (999 / 1)', 999, 999 / 1);
	AddTestCase('divx087:p6 r:HALF_UP (99 / 1)', 99, 99 / 1);
	AddTestCase('divx088:p6 r:HALF_UP (9 / 1)', 9, 9 / 1);
}
{
	use precision 9;
	AddTestCase('divx090:p9 r:HALF_UP (0. / 1)', 0, 0. / 1);
	AddTestCase('divx091:p9 r:HALF_UP (.0 / 1)', 0.0, .0 / 1);
	AddTestCase('divx092:p9 r:HALF_UP (0.00 / 1)', 0.00, 0.00 / 1);
	AddTestCase('divx093:p9 r:HALF_UP (0.00e+9 / 1)', 0e+7, 0.00e+9 / 1);
	AddTestCase('divx094:p9 r:HALF_UP (0.0000e-50 / 1)', 0e-54, 0.0000e-50 / 1);
	AddTestCase('divx095:p9 r:HALF_UP (1 / 1e-8)', 1e+8, 1 / 1e-8);
	AddTestCase('divx096:p9 r:HALF_UP (1 / 1e-9)', 1e+9, 1 / 1e-9);
	AddTestCase('divx097:p9 r:HALF_UP (1 / 1e-10)', 1e+10, 1 / 1e-10);
	AddTestCase('divx098:p9 r:HALF_UP (1 / 1e-11)', 1e+11, 1 / 1e-11);
	AddTestCase('divx099:p9 r:HALF_UP (1 / 1e-12)', 1e+12, 1 / 1e-12);
	AddTestCase('divx100:p9 r:HALF_UP (1 / 1)', 1, 1 / 1);
	AddTestCase('divx101:p9 r:HALF_UP (1 / 2)', 0.5, 1 / 2);
	AddTestCase('divx102:p9 r:HALF_UP (1 / 3) inexact rounded', 0.333333333, 1 / 3);
	AddTestCase('divx103:p9 r:HALF_UP (1 / 4)', 0.25, 1 / 4);
	AddTestCase('divx104:p9 r:HALF_UP (1 / 5)', 0.2, 1 / 5);
	AddTestCase('divx105:p9 r:HALF_UP (1 / 6) inexact rounded', 0.166666667, 1 / 6);
	AddTestCase('divx106:p9 r:HALF_UP (1 / 7) inexact rounded', 0.142857143, 1 / 7);
	AddTestCase('divx107:p9 r:HALF_UP (1 / 8)', 0.125, 1 / 8);
	AddTestCase('divx108:p9 r:HALF_UP (1 / 9) inexact rounded', 0.111111111, 1 / 9);
	AddTestCase('divx109:p9 r:HALF_UP (1 / 10)', 0.1, 1 / 10);
	AddTestCase('divx110:p9 r:HALF_UP (1 / 1)', 1, 1 / 1);
	AddTestCase('divx111:p9 r:HALF_UP (2 / 1)', 2, 2 / 1);
	AddTestCase('divx112:p9 r:HALF_UP (3 / 1)', 3, 3 / 1);
	AddTestCase('divx113:p9 r:HALF_UP (4 / 1)', 4, 4 / 1);
	AddTestCase('divx114:p9 r:HALF_UP (5 / 1)', 5, 5 / 1);
	AddTestCase('divx115:p9 r:HALF_UP (6 / 1)', 6, 6 / 1);
	AddTestCase('divx116:p9 r:HALF_UP (7 / 1)', 7, 7 / 1);
	AddTestCase('divx117:p9 r:HALF_UP (8 / 1)', 8, 8 / 1);
	AddTestCase('divx118:p9 r:HALF_UP (9 / 1)', 9, 9 / 1);
	AddTestCase('divx119:p9 r:HALF_UP (10 / 1)', 10, 10 / 1);
	AddTestCase('divx120:p9 r:HALF_UP (3e+1 / 0.001)', 3e+4, 3e+1 / 0.001);
	AddTestCase('divx121:p9 r:HALF_UP (2.200 / 2)', 1.100, 2.200 / 2);
	AddTestCase('divx130:p9 r:HALF_UP (12345 / 4.999) inexact rounded', 2469.49390, 12345 / 4.999);
	AddTestCase('divx131:p9 r:HALF_UP (12345 / 4.99) inexact rounded', 2473.94790, 12345 / 4.99);
	AddTestCase('divx132:p9 r:HALF_UP (12345 / 4.9) inexact rounded', 2519.38776, 12345 / 4.9);
	AddTestCase('divx133:p9 r:HALF_UP (12345 / 5)', 2469, 12345 / 5);
	AddTestCase('divx134:p9 r:HALF_UP (12345 / 5.1) inexact rounded', 2420.58824, 12345 / 5.1);
	AddTestCase('divx135:p9 r:HALF_UP (12345 / 5.01) inexact rounded', 2464.07186, 12345 / 5.01);
	AddTestCase('divx136:p9 r:HALF_UP (12345 / 5.001) inexact rounded', 2468.50630, 12345 / 5.001);
}
{
	use precision 9;
	// test possibly imprecise results
	AddTestCase('divx220:p9 r:HALF_UP (391 / 597) inexact rounded', 0.654941374, 391 / 597);
	AddTestCase('divx221:p9 r:HALF_UP (391 / -597) inexact rounded', -0.654941374, 391 / -597);
	AddTestCase('divx222:p9 r:HALF_UP (-391 / 597) inexact rounded', -0.654941374, -391 / 597);
	AddTestCase('divx223:p9 r:HALF_UP (-391 / -597) inexact rounded', 0.654941374, -391 / -597);
	// test some cases that are close to exponent overflow
	AddTestCase('divx270:p9 r:HALF_UP (1 / 1e999999999)', 1e-999999999, 1 / 1e999999999);
	AddTestCase('divx271:p9 r:HALF_UP (1 / 0.9e999999999) inexact rounded', 1.11111111e-999999999, 1 / 0.9e999999999);
	AddTestCase('divx272:p9 r:HALF_UP (1 / 0.99e999999999) inexact rounded', 1.01010101e-999999999, 1 / 0.99e999999999);
	AddTestCase('divx273:p9 r:HALF_UP (1 / 0.999999999e999999999) inexact rounded', 1.00000000e-999999999, 1 / 0.999999999e999999999);
	AddTestCase('divx274:p9 r:HALF_UP (9e999999999 / 1)', 9e+999999999, 9e999999999 / 1);
	AddTestCase('divx275:p9 r:HALF_UP (9.9e999999999 / 1)', 9.9e+999999999, 9.9e999999999 / 1);
	AddTestCase('divx276:p9 r:HALF_UP (9.99e999999999 / 1)', 9.99e+999999999, 9.99e999999999 / 1);
	AddTestCase('divx277:p9 r:HALF_UP (9.99999999e999999999 / 1)', 9.99999999e+999999999, 9.99999999e999999999 / 1);
	AddTestCase('divx280:p9 r:HALF_UP (0.1 / 9e-999999999) inexact rounded', 1.11111111e+999999997, 0.1 / 9e-999999999);
	AddTestCase('divx281:p9 r:HALF_UP (0.1 / 99e-999999999) inexact rounded', 1.01010101e+999999996, 0.1 / 99e-999999999);
	AddTestCase('divx282:p9 r:HALF_UP (0.1 / 999e-999999999) inexact rounded', 1.00100100e+999999995, 0.1 / 999e-999999999);
	AddTestCase('divx283:p9 r:HALF_UP (0.1 / 9e-999999998) inexact rounded', 1.11111111e+999999996, 0.1 / 9e-999999998);
	AddTestCase('divx284:p9 r:HALF_UP (0.1 / 99e-999999998) inexact rounded', 1.01010101e+999999995, 0.1 / 99e-999999998);
	AddTestCase('divx285:p9 r:HALF_UP (0.1 / 999e-999999998) inexact rounded', 1.00100100e+999999994, 0.1 / 999e-999999998);
	AddTestCase('divx286:p9 r:HALF_UP (0.1 / 999e-999999997) inexact rounded', 1.00100100e+999999993, 0.1 / 999e-999999997);
	AddTestCase('divx287:p9 r:HALF_UP (0.1 / 9999e-999999997) inexact rounded', 1.00010001e+999999992, 0.1 / 9999e-999999997);
	AddTestCase('divx288:p9 r:HALF_UP (0.1 / 99999e-999999997) inexact rounded', 1.00001000e+999999991, 0.1 / 99999e-999999997);
	// divide into 0 tests
	AddTestCase('divx301:p9 r:HALF_UP (0 / 7)', 0, 0 / 7);
	AddTestCase('divx302:p9 r:HALF_UP (0 / 7e-5)', 0e+5, 0 / 7e-5);
	AddTestCase('divx303:p9 r:HALF_UP (0 / 7e-1)', 0e+1, 0 / 7e-1);
	AddTestCase('divx304:p9 r:HALF_UP (0 / 7e+1)', 0.0, 0 / 7e+1);
	AddTestCase('divx305:p9 r:HALF_UP (0 / 7e+5)', 0.00000, 0 / 7e+5);
	AddTestCase('divx306:p9 r:HALF_UP (0 / 7e+6)', 0.000000, 0 / 7e+6);
	AddTestCase('divx307:p9 r:HALF_UP (0 / 7e+7)', 0e-7, 0 / 7e+7);
	AddTestCase('divx308:p9 r:HALF_UP (0 / 70e-5)', 0e+5, 0 / 70e-5);
	AddTestCase('divx309:p9 r:HALF_UP (0 / 70e-1)', 0e+1, 0 / 70e-1);
	AddTestCase('divx310:p9 r:HALF_UP (0 / 70e+0)', 0, 0 / 70e+0);
	AddTestCase('divx311:p9 r:HALF_UP (0 / 70e+1)', 0.0, 0 / 70e+1);
	AddTestCase('divx312:p9 r:HALF_UP (0 / 70e+5)', 0.00000, 0 / 70e+5);
	AddTestCase('divx313:p9 r:HALF_UP (0 / 70e+6)', 0.000000, 0 / 70e+6);
	AddTestCase('divx314:p9 r:HALF_UP (0 / 70e+7)', 0e-7, 0 / 70e+7);
	AddTestCase('divx315:p9 r:HALF_UP (0 / 700e-5)', 0e+5, 0 / 700e-5);
	AddTestCase('divx316:p9 r:HALF_UP (0 / 700e-1)', 0e+1, 0 / 700e-1);
	AddTestCase('divx317:p9 r:HALF_UP (0 / 700e+0)', 0, 0 / 700e+0);
	AddTestCase('divx318:p9 r:HALF_UP (0 / 700e+1)', 0.0, 0 / 700e+1);
	AddTestCase('divx319:p9 r:HALF_UP (0 / 700e+5)', 0.00000, 0 / 700e+5);
	AddTestCase('divx320:p9 r:HALF_UP (0 / 700e+6)', 0.000000, 0 / 700e+6);
	AddTestCase('divx321:p9 r:HALF_UP (0 / 700e+7)', 0e-7, 0 / 700e+7);
	AddTestCase('divx322:p9 r:HALF_UP (0 / 700e+77)', 0e-77, 0 / 700e+77);
	AddTestCase('divx331:p9 r:HALF_UP (0e-3 / 7e-5)', 0e+2, 0e-3 / 7e-5);
	AddTestCase('divx332:p9 r:HALF_UP (0e-3 / 7e-1)', 0.00, 0e-3 / 7e-1);
	AddTestCase('divx333:p9 r:HALF_UP (0e-3 / 7e+1)', 0.0000, 0e-3 / 7e+1);
	AddTestCase('divx334:p9 r:HALF_UP (0e-3 / 7e+5)', 0e-8, 0e-3 / 7e+5);
	AddTestCase('divx335:p9 r:HALF_UP (0e-1 / 7e-5)', 0e+4, 0e-1 / 7e-5);
	AddTestCase('divx336:p9 r:HALF_UP (0e-1 / 7e-1)', 0, 0e-1 / 7e-1);
	AddTestCase('divx337:p9 r:HALF_UP (0e-1 / 7e+1)', 0.00, 0e-1 / 7e+1);
	AddTestCase('divx338:p9 r:HALF_UP (0e-1 / 7e+5)', 0.000000, 0e-1 / 7e+5);
	AddTestCase('divx339:p9 r:HALF_UP (0e+1 / 7e-5)', 0e+6, 0e+1 / 7e-5);
	AddTestCase('divx340:p9 r:HALF_UP (0e+1 / 7e-1)', 0e+2, 0e+1 / 7e-1);
	AddTestCase('divx341:p9 r:HALF_UP (0e+1 / 7e+1)', 0, 0e+1 / 7e+1);
	AddTestCase('divx342:p9 r:HALF_UP (0e+1 / 7e+5)', 0.0000, 0e+1 / 7e+5);
	AddTestCase('divx343:p9 r:HALF_UP (0e+3 / 7e-5)', 0e+8, 0e+3 / 7e-5);
	AddTestCase('divx344:p9 r:HALF_UP (0e+3 / 7e-1)', 0e+4, 0e+3 / 7e-1);
	AddTestCase('divx345:p9 r:HALF_UP (0e+3 / 7e+1)', 0e+2, 0e+3 / 7e+1);
	AddTestCase('divx346:p9 r:HALF_UP (0e+3 / 7e+5)', 0.00, 0e+3 / 7e+5);
}
{
	use precision 7;
	AddTestCase('divx351:p7 r:HALF_UP (0e-92 / 7e-1)', 0e-91, 0e-92 / 7e-1);
	AddTestCase('divx352:p7 r:HALF_UP (0e-92 / 7e+1)', 0e-93, 0e-92 / 7e+1);
	AddTestCase('divx353:p7 r:HALF_UP (0e-92 / 7e+5)', 0e-97, 0e-92 / 7e+5);
	AddTestCase('divx354:p7 r:HALF_UP (0e-92 / 7e+6)', 0e-98, 0e-92 / 7e+6);
	AddTestCase('divx356:p7 r:HALF_UP (0e-92 / 777e-1)', 0e-91, 0e-92 / 777e-1);
	AddTestCase('divx357:p7 r:HALF_UP (0e-92 / 777e+1)', 0e-93, 0e-92 / 777e+1);
	AddTestCase('divx358:p7 r:HALF_UP (0e-92 / 777e+3)', 0e-95, 0e-92 / 777e+3);
	AddTestCase('divx359:p7 r:HALF_UP (0e-92 / 777e+4)', 0e-96, 0e-92 / 777e+4);
	AddTestCase('divx360:p7 r:HALF_UP (0e-92 / 777e+5)', 0e-97, 0e-92 / 777e+5);
	AddTestCase('divx361:p7 r:HALF_UP (0e-92 / 777e+6)', 0e-98, 0e-92 / 777e+6);
	AddTestCase('divx371:p7 r:HALF_UP (0e-92 / 700e-1)', 0e-91, 0e-92 / 700e-1);
	AddTestCase('divx372:p7 r:HALF_UP (0e-92 / 700e+1)', 0e-93, 0e-92 / 700e+1);
	AddTestCase('divx373:p7 r:HALF_UP (0e-92 / 700e+3)', 0e-95, 0e-92 / 700e+3);
	AddTestCase('divx374:p7 r:HALF_UP (0e-92 / 700e+4)', 0e-96, 0e-92 / 700e+4);
	AddTestCase('divx375:p7 r:HALF_UP (0e-92 / 700e+5)', 0e-97, 0e-92 / 700e+5);
	AddTestCase('divx376:p7 r:HALF_UP (0e-92 / 700e+6)', 0e-98, 0e-92 / 700e+6);
	AddTestCase('divx381:p7 r:HALF_UP (0e+92 / 7e+1)', 0e+91, 0e+92 / 7e+1);
	AddTestCase('divx382:p7 r:HALF_UP (0e+92 / 7e+0)', 0e+92, 0e+92 / 7e+0);
	AddTestCase('divx384:p7 r:HALF_UP (0e+90 / 777e+1)', 0e+89, 0e+90 / 777e+1);
	AddTestCase('divx385:p7 r:HALF_UP (0e+90 / 777e-1)', 0e+91, 0e+90 / 777e-1);
	AddTestCase('divx386:p7 r:HALF_UP (0e+90 / 777e-2)', 0e+92, 0e+90 / 777e-2);
	AddTestCase('divx391:p7 r:HALF_UP (0e+90 / 700e+1)', 0e+89, 0e+90 / 700e+1);
	AddTestCase('divx392:p7 r:HALF_UP (0e+90 / 700e-1)', 0e+91, 0e+90 / 700e-1);
	AddTestCase('divx393:p7 r:HALF_UP (0e+90 / 700e-2)', 0e+92, 0e+90 / 700e-2);
	// input rounding checks
}
{
	use precision 9;
	AddTestCase('divx401:p9 r:HALF_UP (12345678000 / 1) rounded', 1.23456780e+10, 12345678000 / 1);
	AddTestCase('divx402:p9 r:HALF_UP (1 / 12345678000) inexact rounded', 8.10000066e-11, 1 / 12345678000);
	AddTestCase('divx403:p9 r:HALF_UP (1234567800 / 1) rounded', 1.23456780e+9, 1234567800 / 1);
	AddTestCase('divx404:p9 r:HALF_UP (1 / 1234567800) inexact rounded', 8.10000066e-10, 1 / 1234567800);
	AddTestCase('divx405:p9 r:HALF_UP (1234567890 / 1) rounded', 1.23456789e+9, 1234567890 / 1);
	AddTestCase('divx406:p9 r:HALF_UP (1 / 1234567890) inexact rounded', 8.10000007e-10, 1 / 1234567890);
	AddTestCase('divx407:p9 r:HALF_UP (1234567891 / 1) inexact rounded', 1.23456789e+9, 1234567891 / 1);
	AddTestCase('divx408:p9 r:HALF_UP (1 / 1234567891) inexact rounded', 8.10000007e-10, 1 / 1234567891);
	AddTestCase('divx409:p9 r:HALF_UP (12345678901 / 1) inexact rounded', 1.23456789e+10, 12345678901 / 1);
	AddTestCase('divx410:p9 r:HALF_UP (1 / 12345678901) inexact rounded', 8.10000007e-11, 1 / 12345678901);
	AddTestCase('divx411:p9 r:HALF_UP (1234567896 / 1) inexact rounded', 1.23456790e+9, 1234567896 / 1);
	AddTestCase('divx412:p9 r:HALF_UP (1 / 1234567896) inexact rounded', 8.10000003e-10, 1 / 1234567896);
	AddTestCase('divx413:p9 r:HALF_UP (1 / 1234567897) inexact rounded', 8.10000003e-10, 1 / 1234567897);
	AddTestCase('divx414:p9 r:HALF_UP (1 / 1234567898) inexact rounded', 8.10000002e-10, 1 / 1234567898);
	AddTestCase('divx415:p9 r:HALF_UP (1 / 1234567899) inexact rounded', 8.10000001e-10, 1 / 1234567899);
	AddTestCase('divx416:p9 r:HALF_UP (1 / 1234567900) inexact rounded', 8.10000001e-10, 1 / 1234567900);
	AddTestCase('divx417:p9 r:HALF_UP (1 / 1234567901) inexact rounded', 8.10000000e-10, 1 / 1234567901);
	AddTestCase('divx418:p9 r:HALF_UP (1 / 1234567902) inexact rounded', 8.09999999e-10, 1 / 1234567902);
	// some longies
	AddTestCase('divx421:p9 r:HALF_UP (1234567896.000000000000 / 1) inexact rounded', 1.23456790e+9, 1234567896.000000000000 / 1);
	AddTestCase('divx422:p9 r:HALF_UP (1 / 1234567896.000000000000) inexact rounded', 8.10000003e-10, 1 / 1234567896.000000000000);
	AddTestCase('divx423:p9 r:HALF_UP (1234567896.000000000001 / 1) inexact rounded', 1.23456790e+9, 1234567896.000000000001 / 1);
	AddTestCase('divx424:p9 r:HALF_UP (1 / 1234567896.000000000001) inexact rounded', 8.10000003e-10, 1 / 1234567896.000000000001);
	AddTestCase('divx425:p9 r:HALF_UP (1234567896.000000000000000000000000000000000000000009 / 1) inexact rounded', 1.23456790e+9, 1234567896.000000000000000000000000000000000000000009 / 1);
	AddTestCase('divx426:p9 r:HALF_UP (1 / 1234567896.000000000000000000000000000000000000000009) inexact rounded', 8.10000003e-10, 1 / 1234567896.000000000000000000000000000000000000000009);
	AddTestCase('divx427:p9 r:HALF_UP (1234567897.900010000000000000000000000000000000000009 / 1) inexact rounded', 1.23456790e+9, 1234567897.900010000000000000000000000000000000000009 / 1);
	AddTestCase('divx428:p9 r:HALF_UP (1 / 1234567897.900010000000000000000000000000000000000009) inexact rounded', 8.10000002e-10, 1 / 1234567897.900010000000000000000000000000000000000009);
}
{
	use precision 15;
	// still checking...
	AddTestCase('divx441:p15 r:HALF_UP (12345678000 / 1)', 12345678000, 12345678000 / 1);
	AddTestCase('divx442:p15 r:HALF_UP (1 / 12345678000) inexact rounded', 8.10000066420005e-11, 1 / 12345678000);
	AddTestCase('divx443:p15 r:HALF_UP (1234567800 / 1)', 1234567800, 1234567800 / 1);
	AddTestCase('divx444:p15 r:HALF_UP (1 / 1234567800) inexact rounded', 8.10000066420005e-10, 1 / 1234567800);
	AddTestCase('divx445:p15 r:HALF_UP (1234567890 / 1)', 1234567890, 1234567890 / 1);
	AddTestCase('divx446:p15 r:HALF_UP (1 / 1234567890) inexact rounded', 8.10000007371000e-10, 1 / 1234567890);
	AddTestCase('divx447:p15 r:HALF_UP (1234567891 / 1)', 1234567891, 1234567891 / 1);
	AddTestCase('divx448:p15 r:HALF_UP (1 / 1234567891) inexact rounded', 8.10000006714900e-10, 1 / 1234567891);
	AddTestCase('divx449:p15 r:HALF_UP (12345678901 / 1)', 12345678901, 12345678901 / 1);
	AddTestCase('divx450:p15 r:HALF_UP (1 / 12345678901) inexact rounded', 8.10000007305390e-11, 1 / 12345678901);
	AddTestCase('divx451:p15 r:HALF_UP (1234567896 / 1)', 1234567896, 1234567896 / 1);
	AddTestCase('divx452:p15 r:HALF_UP (1 / 1234567896) inexact rounded', 8.10000003434400e-10, 1 / 1234567896);
	// high-lows
	AddTestCase('divx453:p15 r:HALF_UP (1e+1 / 1)', 1e+1, 1e+1 / 1);
	AddTestCase('divx454:p15 r:HALF_UP (1e+1 / 1.0)', 1e+1, 1e+1 / 1.0);
	AddTestCase('divx455:p15 r:HALF_UP (1e+1 / 1.00)', 1e+1, 1e+1 / 1.00);
	AddTestCase('divx456:p15 r:HALF_UP (1e+2 / 2)', 5e+1, 1e+2 / 2);
	AddTestCase('divx457:p15 r:HALF_UP (1e+2 / 2.0)', 5e+1, 1e+2 / 2.0);
	AddTestCase('divx458:p15 r:HALF_UP (1e+2 / 2.00)', 5e+1, 1e+2 / 2.00);
	// some from ieee discussions
	AddTestCase('divx460:p15 r:HALF_UP (3e0 / 2e0)', 1.5, 3e0 / 2e0);
	AddTestCase('divx461:p15 r:HALF_UP (30e-1 / 2e0)', 1.5, 30e-1 / 2e0);
	AddTestCase('divx462:p15 r:HALF_UP (300e-2 / 2e0)', 1.50, 300e-2 / 2e0);
	AddTestCase('divx464:p15 r:HALF_UP (3000e-3 / 2e0)', 1.500, 3000e-3 / 2e0);
	AddTestCase('divx465:p15 r:HALF_UP (3e0 / 20e-1)', 1.5, 3e0 / 20e-1);
	AddTestCase('divx466:p15 r:HALF_UP (30e-1 / 20e-1)', 1.5, 30e-1 / 20e-1);
	AddTestCase('divx467:p15 r:HALF_UP (300e-2 / 20e-1)', 1.5, 300e-2 / 20e-1);
	AddTestCase('divx468:p15 r:HALF_UP (3000e-3 / 20e-1)', 1.50, 3000e-3 / 20e-1);
	AddTestCase('divx469:p15 r:HALF_UP (3e0 / 200e-2)', 1.5, 3e0 / 200e-2);
	AddTestCase('divx470:p15 r:HALF_UP (30e-1 / 200e-2)', 1.5, 30e-1 / 200e-2);
	AddTestCase('divx471:p15 r:HALF_UP (300e-2 / 200e-2)', 1.5, 300e-2 / 200e-2);
	AddTestCase('divx472:p15 r:HALF_UP (3000e-3 / 200e-2)', 1.5, 3000e-3 / 200e-2);
	AddTestCase('divx473:p15 r:HALF_UP (3e0 / 2000e-3)', 1.5, 3e0 / 2000e-3);
	AddTestCase('divx474:p15 r:HALF_UP (30e-1 / 2000e-3)', 1.5, 30e-1 / 2000e-3);
	AddTestCase('divx475:p15 r:HALF_UP (300e-2 / 2000e-3)', 1.5, 300e-2 / 2000e-3);
	AddTestCase('divx476:p15 r:HALF_UP (3000e-3 / 2000e-3)', 1.5, 3000e-3 / 2000e-3);
	// some reciprocals
	AddTestCase('divx480:p15 r:HALF_UP (1 / 1.0e+33)', 1e-33, 1 / 1.0e+33);
	AddTestCase('divx481:p15 r:HALF_UP (1 / 10e+33)', 1e-34, 1 / 10e+33);
	AddTestCase('divx482:p15 r:HALF_UP (1 / 1.0e-33)', 1e+33, 1 / 1.0e-33);
	AddTestCase('divx483:p15 r:HALF_UP (1 / 10e-33)', 1e+32, 1 / 10e-33);
	// rms discussion table
}
{
	use precision 7;
	AddTestCase('divx484:p7 r:HALF_UP (0e5 / 1e3)', 0e+2, 0e5 / 1e3);
	AddTestCase('divx485:p7 r:HALF_UP (0e5 / 2e3)', 0e+2, 0e5 / 2e3);
	AddTestCase('divx486:p7 r:HALF_UP (0e5 / 10e2)', 0e+3, 0e5 / 10e2);
	AddTestCase('divx487:p7 r:HALF_UP (0e5 / 20e2)', 0e+3, 0e5 / 20e2);
	AddTestCase('divx488:p7 r:HALF_UP (0e5 / 100e1)', 0e+4, 0e5 / 100e1);
	AddTestCase('divx489:p7 r:HALF_UP (0e5 / 200e1)', 0e+4, 0e5 / 200e1);
	AddTestCase('divx491:p7 r:HALF_UP (1e5 / 1e3)', 1e+2, 1e5 / 1e3);
	AddTestCase('divx492:p7 r:HALF_UP (1e5 / 2e3)', 5e+1, 1e5 / 2e3);
	AddTestCase('divx493:p7 r:HALF_UP (1e5 / 10e2)', 1e+2, 1e5 / 10e2);
	AddTestCase('divx494:p7 r:HALF_UP (1e5 / 20e2)', 5e+1, 1e5 / 20e2);
	AddTestCase('divx495:p7 r:HALF_UP (1e5 / 100e1)', 1e+2, 1e5 / 100e1);
	AddTestCase('divx496:p7 r:HALF_UP (1e5 / 200e1)', 5e+1, 1e5 / 200e1);
	// tryzeros cases
}
{
	use precision 7;
	{
		use rounding HALF_UP;
		{
			use precision 9;
			{
				use rounding HALF_UP;
				// focus on trailing zeros issues
				{
					use precision 9;
					AddTestCase('divx500:p9 r:HALF_UP (1 / 9.9) inexact rounded', 0.101010101, 1 / 9.9);
				}
				{
					use precision 8;
					AddTestCase('divx501:p8 r:HALF_UP (1 / 9.9) inexact rounded', 0.10101010, 1 / 9.9);
				}
				{
					use precision 7;
					AddTestCase('divx502:p7 r:HALF_UP (1 / 9.9) inexact rounded', 0.1010101, 1 / 9.9);
				}
				{
					use precision 6;
					AddTestCase('divx503:p6 r:HALF_UP (1 / 9.9) inexact rounded', 0.101010, 1 / 9.9);
				}
				{
					use precision 9;
					AddTestCase('divx511:p9 r:HALF_UP (1 / 2)', 0.5, 1 / 2);
					AddTestCase('divx512:p9 r:HALF_UP (1.0 / 2)', 0.5, 1.0 / 2);
					AddTestCase('divx513:p9 r:HALF_UP (1.00 / 2)', 0.50, 1.00 / 2);
					AddTestCase('divx514:p9 r:HALF_UP (1.000 / 2)', 0.500, 1.000 / 2);
					AddTestCase('divx515:p9 r:HALF_UP (1.0000 / 2)', 0.5000, 1.0000 / 2);
					AddTestCase('divx516:p9 r:HALF_UP (1.00000 / 2)', 0.50000, 1.00000 / 2);
					AddTestCase('divx517:p9 r:HALF_UP (1.000000 / 2)', 0.500000, 1.000000 / 2);
					AddTestCase('divx518:p9 r:HALF_UP (1.0000000 / 2)', 0.5000000, 1.0000000 / 2);
					AddTestCase('divx519:p9 r:HALF_UP (1.00 / 2.00)', 0.5, 1.00 / 2.00);
					AddTestCase('divx521:p9 r:HALF_UP (2 / 1)', 2, 2 / 1);
					AddTestCase('divx522:p9 r:HALF_UP (2 / 1.0)', 2, 2 / 1.0);
					AddTestCase('divx523:p9 r:HALF_UP (2 / 1.00)', 2, 2 / 1.00);
					AddTestCase('divx524:p9 r:HALF_UP (2 / 1.000)', 2, 2 / 1.000);
					AddTestCase('divx525:p9 r:HALF_UP (2 / 1.0000)', 2, 2 / 1.0000);
					AddTestCase('divx526:p9 r:HALF_UP (2 / 1.00000)', 2, 2 / 1.00000);
					AddTestCase('divx527:p9 r:HALF_UP (2 / 1.000000)', 2, 2 / 1.000000);
					AddTestCase('divx528:p9 r:HALF_UP (2 / 1.0000000)', 2, 2 / 1.0000000);
					AddTestCase('divx529:p9 r:HALF_UP (2.00 / 1.00)', 2, 2.00 / 1.00);
					AddTestCase('divx530:p9 r:HALF_UP (2.40 / 2)', 1.20, 2.40 / 2);
					AddTestCase('divx531:p9 r:HALF_UP (2.40 / 4)', 0.60, 2.40 / 4);
					AddTestCase('divx532:p9 r:HALF_UP (2.40 / 10)', 0.24, 2.40 / 10);
					AddTestCase('divx533:p9 r:HALF_UP (2.40 / 2.0)', 1.2, 2.40 / 2.0);
					AddTestCase('divx534:p9 r:HALF_UP (2.40 / 4.0)', 0.6, 2.40 / 4.0);
					AddTestCase('divx535:p9 r:HALF_UP (2.40 / 10.0)', 0.24, 2.40 / 10.0);
					AddTestCase('divx536:p9 r:HALF_UP (2.40 / 2.00)', 1.2, 2.40 / 2.00);
					AddTestCase('divx537:p9 r:HALF_UP (2.40 / 4.00)', 0.6, 2.40 / 4.00);
					AddTestCase('divx538:p9 r:HALF_UP (2.40 / 10.00)', 0.24, 2.40 / 10.00);
					AddTestCase('divx539:p9 r:HALF_UP (0.9 / 0.1)', 9, 0.9 / 0.1);
					AddTestCase('divx540:p9 r:HALF_UP (0.9 / 0.01)', 9e+1, 0.9 / 0.01);
					AddTestCase('divx541:p9 r:HALF_UP (0.9 / 0.001)', 9e+2, 0.9 / 0.001);
					AddTestCase('divx542:p9 r:HALF_UP (5 / 2)', 2.5, 5 / 2);
					AddTestCase('divx543:p9 r:HALF_UP (5 / 2.0)', 2.5, 5 / 2.0);
					AddTestCase('divx544:p9 r:HALF_UP (5 / 2.00)', 2.5, 5 / 2.00);
					AddTestCase('divx545:p9 r:HALF_UP (5 / 20)', 0.25, 5 / 20);
					AddTestCase('divx546:p9 r:HALF_UP (5 / 20.0)', 0.25, 5 / 20.0);
					AddTestCase('divx547:p9 r:HALF_UP (2.400 / 2)', 1.200, 2.400 / 2);
					AddTestCase('divx548:p9 r:HALF_UP (2.400 / 2.0)', 1.20, 2.400 / 2.0);
					AddTestCase('divx549:p9 r:HALF_UP (2.400 / 2.400)', 1, 2.400 / 2.400);
					AddTestCase('divx550:p9 r:HALF_UP (240 / 1)', 240, 240 / 1);
					AddTestCase('divx551:p9 r:HALF_UP (240 / 10)', 24, 240 / 10);
					AddTestCase('divx552:p9 r:HALF_UP (240 / 100)', 2.4, 240 / 100);
					AddTestCase('divx553:p9 r:HALF_UP (240 / 1000)', 0.24, 240 / 1000);
					AddTestCase('divx554:p9 r:HALF_UP (2400 / 1)', 2400, 2400 / 1);
					AddTestCase('divx555:p9 r:HALF_UP (2400 / 10)', 240, 2400 / 10);
					AddTestCase('divx556:p9 r:HALF_UP (2400 / 100)', 24, 2400 / 100);
					AddTestCase('divx557:p9 r:HALF_UP (2400 / 1000)', 2.4, 2400 / 1000);
					// +ve exponent
				}
				{
					use precision 5;
					AddTestCase('divx570:p5 r:HALF_UP (2.4e+6 / 2)', 1.2e+6, 2.4e+6 / 2);
					AddTestCase('divx571:p5 r:HALF_UP (2.40e+6 / 2)', 1.20e+6, 2.40e+6 / 2);
					AddTestCase('divx572:p5 r:HALF_UP (2.400e+6 / 2)', 1.200e+6, 2.400e+6 / 2);
					AddTestCase('divx573:p5 r:HALF_UP (2.4000e+6 / 2)', 1.2000e+6, 2.4000e+6 / 2);
					AddTestCase('divx574:p5 r:HALF_UP (24e+5 / 2)', 1.2e+6, 24e+5 / 2);
					AddTestCase('divx575:p5 r:HALF_UP (240e+4 / 2)', 1.20e+6, 240e+4 / 2);
					AddTestCase('divx576:p5 r:HALF_UP (2400e+3 / 2)', 1.200e+6, 2400e+3 / 2);
					AddTestCase('divx577:p5 r:HALF_UP (24000e+2 / 2)', 1.2000e+6, 24000e+2 / 2);
				}
				{
					use precision 6;
					AddTestCase('divx580:p6 r:HALF_UP (2.4e+6 / 2)', 1.2e+6, 2.4e+6 / 2);
					AddTestCase('divx581:p6 r:HALF_UP (2.40e+6 / 2)', 1.20e+6, 2.40e+6 / 2);
					AddTestCase('divx582:p6 r:HALF_UP (2.400e+6 / 2)', 1.200e+6, 2.400e+6 / 2);
					AddTestCase('divx583:p6 r:HALF_UP (2.4000e+6 / 2)', 1.2000e+6, 2.4000e+6 / 2);
					AddTestCase('divx584:p6 r:HALF_UP (24e+5 / 2)', 1.2e+6, 24e+5 / 2);
					AddTestCase('divx585:p6 r:HALF_UP (240e+4 / 2)', 1.20e+6, 240e+4 / 2);
					AddTestCase('divx586:p6 r:HALF_UP (2400e+3 / 2)', 1.200e+6, 2400e+3 / 2);
					AddTestCase('divx587:p6 r:HALF_UP (24000e+2 / 2)', 1.2000e+6, 24000e+2 / 2);
				}
				{
					use precision 7;
					AddTestCase('divx590:p7 r:HALF_UP (2.4e+6 / 2)', 1.2e+6, 2.4e+6 / 2);
					AddTestCase('divx591:p7 r:HALF_UP (2.40e+6 / 2)', 1.20e+6, 2.40e+6 / 2);
					AddTestCase('divx592:p7 r:HALF_UP (2.400e+6 / 2)', 1.200e+6, 2.400e+6 / 2);
					AddTestCase('divx593:p7 r:HALF_UP (2.4000e+6 / 2)', 1.2000e+6, 2.4000e+6 / 2);
					AddTestCase('divx594:p7 r:HALF_UP (24e+5 / 2)', 1.2e+6, 24e+5 / 2);
					AddTestCase('divx595:p7 r:HALF_UP (240e+4 / 2)', 1.20e+6, 240e+4 / 2);
					AddTestCase('divx596:p7 r:HALF_UP (2400e+3 / 2)', 1.200e+6, 2400e+3 / 2);
					AddTestCase('divx597:p7 r:HALF_UP (24000e+2 / 2)', 1.2000e+6, 24000e+2 / 2);
				}
				{
					use precision 9;
					AddTestCase('divx600:p9 r:HALF_UP (2.4e+9 / 2)', 1.2e+9, 2.4e+9 / 2);
					AddTestCase('divx601:p9 r:HALF_UP (2.40e+9 / 2)', 1.20e+9, 2.40e+9 / 2);
					AddTestCase('divx602:p9 r:HALF_UP (2.400e+9 / 2)', 1.200e+9, 2.400e+9 / 2);
					AddTestCase('divx603:p9 r:HALF_UP (2.4000e+9 / 2)', 1.2000e+9, 2.4000e+9 / 2);
					AddTestCase('divx604:p9 r:HALF_UP (24e+8 / 2)', 1.2e+9, 24e+8 / 2);
					AddTestCase('divx605:p9 r:HALF_UP (240e+7 / 2)', 1.20e+9, 240e+7 / 2);
					AddTestCase('divx606:p9 r:HALF_UP (2400e+6 / 2)', 1.200e+9, 2400e+6 / 2);
					AddTestCase('divx607:p9 r:HALF_UP (24000e+5 / 2)', 1.2000e+9, 24000e+5 / 2);
					// long operand triangle
				}
				{
					use precision 33;
					AddTestCase('divx610:p33 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.8131097703792, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 32;
					AddTestCase('divx611:p32 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.813109770379, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 31;
					AddTestCase('divx612:p31 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.81310977038, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 30;
					AddTestCase('divx613:p30 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.8131097704, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 29;
					AddTestCase('divx614:p29 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.813109770, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 28;
					AddTestCase('divx615:p28 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.81310977, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 27;
					AddTestCase('divx616:p27 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.8131098, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 26;
					AddTestCase('divx617:p26 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.813110, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 25;
					AddTestCase('divx618:p25 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.81311, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 24;
					AddTestCase('divx619:p24 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.8131, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 23;
					AddTestCase('divx620:p23 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.813, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 22;
					AddTestCase('divx621:p22 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.81, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 21;
					AddTestCase('divx622:p21 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817797.8, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 20;
					AddTestCase('divx623:p20 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -41011408883796817798, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 19;
					AddTestCase('divx624:p19 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.101140888379681780e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 18;
					AddTestCase('divx625:p18 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.10114088837968178e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 17;
					AddTestCase('divx626:p17 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.1011408883796818e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 16;
					AddTestCase('divx627:p16 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.101140888379682e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 15;
					AddTestCase('divx628:p15 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.10114088837968e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 14;
					AddTestCase('divx629:p14 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.1011408883797e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 13;
					AddTestCase('divx630:p13 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.101140888380e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 12;
					AddTestCase('divx631:p12 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.10114088838e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 11;
					AddTestCase('divx632:p11 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.1011408884e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 10;
					AddTestCase('divx633:p10 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.101140888e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 9;
					AddTestCase('divx634:p9 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.10114089e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 8;
					AddTestCase('divx635:p8 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.1011409e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 7;
					AddTestCase('divx636:p7 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.101141e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 6;
					AddTestCase('divx637:p6 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.10114e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 5;
					AddTestCase('divx638:p5 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.1011e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 4;
					AddTestCase('divx639:p4 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.101e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 3;
					AddTestCase('divx640:p3 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.10e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 2;
					AddTestCase('divx641:p2 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4.1e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
				}
				{
					use precision 1;
					AddTestCase('divx642:p1 r:HALF_UP (-3374988581607586061255542201048 / 82293895124.90045271504836568681) inexact rounded', -4e+19, -3374988581607586061255542201048 / 82293895124.90045271504836568681);
					// more zeros, etc.
				}
				{
					use precision 16;
					{
						use rounding HALF_UP;
						AddTestCase('divx731:p16 r:HALF_UP (5.00 / 1e-3)', 5.00e+3, 5.00 / 1e-3);
						AddTestCase('divx732:p16 r:HALF_UP (00.00 / 0.000) division_undefined', NaN, 00.00 / 0.000);
						AddTestCase('divx733:p16 r:HALF_UP (00.00 / 0e-3) division_undefined', NaN, 00.00 / 0e-3);
						AddTestCase('divx734:p16 r:HALF_UP (0 / -0) division_undefined', NaN, 0 / -0);
						AddTestCase('divx735:p16 r:HALF_UP (-0 / 0) division_undefined', NaN, -0 / 0);
						AddTestCase('divx736:p16 r:HALF_UP (-0 / -0) division_undefined', NaN, -0 / -0);
						AddTestCase('divx741:p16 r:HALF_UP (0 / -1)', -0, 0 / -1);
						AddTestCase('divx742:p16 r:HALF_UP (-0 / -1)', 0, -0 / -1);
						AddTestCase('divx743:p16 r:HALF_UP (0 / 1)', 0, 0 / 1);
						AddTestCase('divx744:p16 r:HALF_UP (-0 / 1)', -0, -0 / 1);
						AddTestCase('divx745:p16 r:HALF_UP (-1 / 0) division_by_zero', decimal.NEGATIVE_INFINITY, -1 / 0);
						AddTestCase('divx746:p16 r:HALF_UP (-1 / -0) division_by_zero', decimal.POSITIVE_INFINITY, -1 / -0);
						AddTestCase('divx747:p16 r:HALF_UP (1 / 0) division_by_zero', decimal.POSITIVE_INFINITY, 1 / 0);
						AddTestCase('divx748:p16 r:HALF_UP (1 / -0) division_by_zero', decimal.NEGATIVE_INFINITY, 1 / -0);
						AddTestCase('divx751:p16 r:HALF_UP (0.0 / -1)', -0.0, 0.0 / -1);
						AddTestCase('divx752:p16 r:HALF_UP (-0.0 / -1)', 0.0, -0.0 / -1);
						AddTestCase('divx753:p16 r:HALF_UP (0.0 / 1)', 0.0, 0.0 / 1);
						AddTestCase('divx754:p16 r:HALF_UP (-0.0 / 1)', -0.0, -0.0 / 1);
						AddTestCase('divx755:p16 r:HALF_UP (-1.0 / 0) division_by_zero', decimal.NEGATIVE_INFINITY, -1.0 / 0);
						AddTestCase('divx756:p16 r:HALF_UP (-1.0 / -0) division_by_zero', decimal.POSITIVE_INFINITY, -1.0 / -0);
						AddTestCase('divx757:p16 r:HALF_UP (1.0 / 0) division_by_zero', decimal.POSITIVE_INFINITY, 1.0 / 0);
						AddTestCase('divx758:p16 r:HALF_UP (1.0 / -0) division_by_zero', decimal.NEGATIVE_INFINITY, 1.0 / -0);
						AddTestCase('divx761:p16 r:HALF_UP (0 / -1.0)', -0e+1, 0 / -1.0);
						AddTestCase('divx762:p16 r:HALF_UP (-0 / -1.0)', 0e+1, -0 / -1.0);
						AddTestCase('divx763:p16 r:HALF_UP (0 / 1.0)', 0e+1, 0 / 1.0);
						AddTestCase('divx764:p16 r:HALF_UP (-0 / 1.0)', -0e+1, -0 / 1.0);
						AddTestCase('divx765:p16 r:HALF_UP (-1 / 0.0) division_by_zero', decimal.NEGATIVE_INFINITY, -1 / 0.0);
						AddTestCase('divx766:p16 r:HALF_UP (-1 / -0.0) division_by_zero', decimal.POSITIVE_INFINITY, -1 / -0.0);
						AddTestCase('divx767:p16 r:HALF_UP (1 / 0.0) division_by_zero', decimal.POSITIVE_INFINITY, 1 / 0.0);
						AddTestCase('divx768:p16 r:HALF_UP (1 / -0.0) division_by_zero', decimal.NEGATIVE_INFINITY, 1 / -0.0);
						AddTestCase('divx771:p16 r:HALF_UP (0.0 / -1.0)', -0, 0.0 / -1.0);
						AddTestCase('divx772:p16 r:HALF_UP (-0.0 / -1.0)', 0, -0.0 / -1.0);
						AddTestCase('divx773:p16 r:HALF_UP (0.0 / 1.0)', 0, 0.0 / 1.0);
						AddTestCase('divx774:p16 r:HALF_UP (-0.0 / 1.0)', -0, -0.0 / 1.0);
						AddTestCase('divx775:p16 r:HALF_UP (-1.0 / 0.0) division_by_zero', decimal.NEGATIVE_INFINITY, -1.0 / 0.0);
						AddTestCase('divx776:p16 r:HALF_UP (-1.0 / -0.0) division_by_zero', decimal.POSITIVE_INFINITY, -1.0 / -0.0);
						AddTestCase('divx777:p16 r:HALF_UP (1.0 / 0.0) division_by_zero', decimal.POSITIVE_INFINITY, 1.0 / 0.0);
						AddTestCase('divx778:p16 r:HALF_UP (1.0 / -0.0) division_by_zero', decimal.NEGATIVE_INFINITY, 1.0 / -0.0);
						// specials
						AddTestCase('divx780:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY / decimal.NEGATIVE_INFINITY);
						AddTestCase('divx781:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / -1000)', decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY / -1000);
						AddTestCase('divx782:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / -1)', decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY / -1);
						AddTestCase('divx783:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / -0)', decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY / -0);
						AddTestCase('divx784:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / 0)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY / 0);
						AddTestCase('divx785:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / 1)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY / 1);
						AddTestCase('divx786:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / 1000)', decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY / 1000);
						AddTestCase('divx787:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / decimal.POSITIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY / decimal.POSITIVE_INFINITY);
						AddTestCase('divx789:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / decimal.POSITIVE_INFINITY) invalid_operation', NaN, decimal.NEGATIVE_INFINITY / decimal.POSITIVE_INFINITY);
						AddTestCase('divx795:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / decimal.POSITIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY / decimal.POSITIVE_INFINITY);
						AddTestCase('divx800:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.NEGATIVE_INFINITY / decimal.NEGATIVE_INFINITY);
						AddTestCase('divx801:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / -1000)', decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY / -1000);
						AddTestCase('divx802:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / -1)', decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY / -1);
						AddTestCase('divx803:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / -0)', decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY / -0);
						AddTestCase('divx804:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / 0)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY / 0);
						AddTestCase('divx805:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / 1)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY / 1);
						AddTestCase('divx806:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / 1000)', decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY / 1000);
						AddTestCase('divx807:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / decimal.POSITIVE_INFINITY) invalid_operation', NaN, decimal.NEGATIVE_INFINITY / decimal.POSITIVE_INFINITY);
						AddTestCase('divx809:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.NEGATIVE_INFINITY / decimal.NEGATIVE_INFINITY);
						AddTestCase('divx815:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY / decimal.NEGATIVE_INFINITY);
						AddTestCase('divx821:p16 r:HALF_UP (NaN / decimal.NEGATIVE_INFINITY)', NaN, NaN / decimal.NEGATIVE_INFINITY);
						AddTestCase('divx822:p16 r:HALF_UP (NaN / -1000)', NaN, NaN / -1000);
						AddTestCase('divx823:p16 r:HALF_UP (NaN / -1)', NaN, NaN / -1);
						AddTestCase('divx824:p16 r:HALF_UP (NaN / -0)', NaN, NaN / -0);
						AddTestCase('divx825:p16 r:HALF_UP (NaN / 0)', NaN, NaN / 0);
						AddTestCase('divx826:p16 r:HALF_UP (NaN / 1)', NaN, NaN / 1);
						AddTestCase('divx827:p16 r:HALF_UP (NaN / 1000)', NaN, NaN / 1000);
						AddTestCase('divx828:p16 r:HALF_UP (NaN / decimal.POSITIVE_INFINITY)', NaN, NaN / decimal.POSITIVE_INFINITY);
						AddTestCase('divx829:p16 r:HALF_UP (NaN / NaN)', NaN, NaN / NaN);
						AddTestCase('divx830:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / NaN)', NaN, decimal.NEGATIVE_INFINITY / NaN);
						AddTestCase('divx831:p16 r:HALF_UP (-1000 / NaN)', NaN, -1000 / NaN);
						AddTestCase('divx832:p16 r:HALF_UP (-1 / NaN)', NaN, -1 / NaN);
						AddTestCase('divx833:p16 r:HALF_UP (-0 / NaN)', NaN, -0 / NaN);
						AddTestCase('divx834:p16 r:HALF_UP (0 / NaN)', NaN, 0 / NaN);
						AddTestCase('divx835:p16 r:HALF_UP (1 / NaN)', NaN, 1 / NaN);
						AddTestCase('divx836:p16 r:HALF_UP (1000 / NaN)', NaN, 1000 / NaN);
						AddTestCase('divx837:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / NaN)', NaN, decimal.POSITIVE_INFINITY / NaN);
						AddTestCase('divx841:p16 r:HALF_UP (NaN / decimal.NEGATIVE_INFINITY) invalid_operation', NaN, NaN / decimal.NEGATIVE_INFINITY);
						AddTestCase('divx842:p16 r:HALF_UP (NaN / -1000) invalid_operation', NaN, NaN / -1000);
						AddTestCase('divx843:p16 r:HALF_UP (NaN / -1) invalid_operation', NaN, NaN / -1);
						AddTestCase('divx844:p16 r:HALF_UP (NaN / -0) invalid_operation', NaN, NaN / -0);
						AddTestCase('divx845:p16 r:HALF_UP (NaN / 0) invalid_operation', NaN, NaN / 0);
						AddTestCase('divx846:p16 r:HALF_UP (NaN / 1) invalid_operation', NaN, NaN / 1);
						AddTestCase('divx847:p16 r:HALF_UP (NaN / 1000) invalid_operation', NaN, NaN / 1000);
						AddTestCase('divx848:p16 r:HALF_UP (NaN / NaN) invalid_operation', NaN, NaN / NaN);
						AddTestCase('divx849:p16 r:HALF_UP (NaN / NaN) invalid_operation', NaN, NaN / NaN);
						AddTestCase('divx850:p16 r:HALF_UP (NaN / NaN) invalid_operation', NaN, NaN / NaN);
						AddTestCase('divx851:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / NaN) invalid_operation', NaN, decimal.NEGATIVE_INFINITY / NaN);
						AddTestCase('divx852:p16 r:HALF_UP (-1000 / NaN) invalid_operation', NaN, -1000 / NaN);
						AddTestCase('divx853:p16 r:HALF_UP (-1 / NaN) invalid_operation', NaN, -1 / NaN);
						AddTestCase('divx854:p16 r:HALF_UP (-0 / NaN) invalid_operation', NaN, -0 / NaN);
						AddTestCase('divx855:p16 r:HALF_UP (0 / NaN) invalid_operation', NaN, 0 / NaN);
						AddTestCase('divx856:p16 r:HALF_UP (1 / NaN) invalid_operation', NaN, 1 / NaN);
						AddTestCase('divx857:p16 r:HALF_UP (1000 / NaN) invalid_operation', NaN, 1000 / NaN);
						AddTestCase('divx858:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / NaN) invalid_operation', NaN, decimal.POSITIVE_INFINITY / NaN);
						AddTestCase('divx859:p16 r:HALF_UP (NaN / NaN) invalid_operation', NaN, NaN / NaN);
						// propagating nans
						AddTestCase('divx861:p16 r:HALF_UP (NaN / decimal.NEGATIVE_INFINITY)', NaN, NaN / decimal.NEGATIVE_INFINITY);
						AddTestCase('divx862:p16 r:HALF_UP (NaN / 1000)', NaN, NaN / 1000);
						AddTestCase('divx863:p16 r:HALF_UP (NaN / decimal.POSITIVE_INFINITY)', NaN, NaN / decimal.POSITIVE_INFINITY);
						AddTestCase('divx864:p16 r:HALF_UP (NaN / NaN)', NaN, NaN / NaN);
						AddTestCase('divx865:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / NaN)', NaN, decimal.NEGATIVE_INFINITY / NaN);
						AddTestCase('divx866:p16 r:HALF_UP (-1000 / NaN)', NaN, -1000 / NaN);
						AddTestCase('divx867:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / NaN)', NaN, decimal.POSITIVE_INFINITY / NaN);
						AddTestCase('divx871:p16 r:HALF_UP (NaN / decimal.NEGATIVE_INFINITY) invalid_operation', NaN, NaN / decimal.NEGATIVE_INFINITY);
						AddTestCase('divx872:p16 r:HALF_UP (NaN / -1) invalid_operation', NaN, NaN / -1);
						AddTestCase('divx873:p16 r:HALF_UP (NaN / NaN) invalid_operation', NaN, NaN / NaN);
						AddTestCase('divx874:p16 r:HALF_UP (NaN / NaN) invalid_operation', NaN, NaN / NaN);
						AddTestCase('divx875:p16 r:HALF_UP (NaN / NaN) invalid_operation', NaN, NaN / NaN);
						AddTestCase('divx876:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / NaN) invalid_operation', NaN, decimal.NEGATIVE_INFINITY / NaN);
						AddTestCase('divx877:p16 r:HALF_UP (0 / NaN) invalid_operation', NaN, 0 / NaN);
						AddTestCase('divx878:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / NaN) invalid_operation', NaN, decimal.POSITIVE_INFINITY / NaN);
						AddTestCase('divx879:p16 r:HALF_UP (NaN / NaN) invalid_operation', NaN, NaN / NaN);
						AddTestCase('divx881:p16 r:HALF_UP (-NaN / decimal.NEGATIVE_INFINITY)', -NaN, -NaN / decimal.NEGATIVE_INFINITY);
						AddTestCase('divx882:p16 r:HALF_UP (-NaN / 1000)', -NaN, -NaN / 1000);
						AddTestCase('divx883:p16 r:HALF_UP (-NaN / decimal.POSITIVE_INFINITY)', -NaN, -NaN / decimal.POSITIVE_INFINITY);
						AddTestCase('divx884:p16 r:HALF_UP (-NaN / -NaN)', -NaN, -NaN / -NaN);
						AddTestCase('divx885:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / -NaN)', -NaN, decimal.NEGATIVE_INFINITY / -NaN);
						AddTestCase('divx886:p16 r:HALF_UP (-1000 / -NaN)', -NaN, -1000 / -NaN);
						AddTestCase('divx887:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / -NaN)', -NaN, decimal.POSITIVE_INFINITY / -NaN);
						AddTestCase('divx891:p16 r:HALF_UP (-NaN / decimal.NEGATIVE_INFINITY) invalid_operation', -NaN, -NaN / decimal.NEGATIVE_INFINITY);
						AddTestCase('divx892:p16 r:HALF_UP (-NaN / -1) invalid_operation', -NaN, -NaN / -1);
						AddTestCase('divx893:p16 r:HALF_UP (-NaN / NaN) invalid_operation', -NaN, -NaN / NaN);
						AddTestCase('divx894:p16 r:HALF_UP (-NaN / -NaN) invalid_operation', -NaN, -NaN / -NaN);
						AddTestCase('divx895:p16 r:HALF_UP (-NaN / -NaN) invalid_operation', -NaN, -NaN / -NaN);
						AddTestCase('divx896:p16 r:HALF_UP (decimal.NEGATIVE_INFINITY / -NaN) invalid_operation', -NaN, decimal.NEGATIVE_INFINITY / -NaN);
						AddTestCase('divx897:p16 r:HALF_UP (0 / -NaN) invalid_operation', -NaN, 0 / -NaN);
						AddTestCase('divx898:p16 r:HALF_UP (decimal.POSITIVE_INFINITY / -NaN) invalid_operation', -NaN, decimal.POSITIVE_INFINITY / -NaN);
						AddTestCase('divx899:p16 r:HALF_UP (-NaN / -NaN) invalid_operation', -NaN, -NaN / -NaN);
						// various flavours of divide by 0
						AddTestCase('divx901:p16 r:HALF_UP (0 / 0) division_undefined', NaN, 0 / 0);
						AddTestCase('divx902:p16 r:HALF_UP (0.0e5 / 0) division_undefined', NaN, 0.0e5 / 0);
						AddTestCase('divx903:p16 r:HALF_UP (0.000 / 0) division_undefined', NaN, 0.000 / 0);
						AddTestCase('divx904:p16 r:HALF_UP (0.0001 / 0) division_by_zero', decimal.POSITIVE_INFINITY, 0.0001 / 0);
						AddTestCase('divx905:p16 r:HALF_UP (0.01 / 0) division_by_zero', decimal.POSITIVE_INFINITY, 0.01 / 0);
						AddTestCase('divx906:p16 r:HALF_UP (0.1 / 0) division_by_zero', decimal.POSITIVE_INFINITY, 0.1 / 0);
						AddTestCase('divx907:p16 r:HALF_UP (1 / 0) division_by_zero', decimal.POSITIVE_INFINITY, 1 / 0);
						AddTestCase('divx908:p16 r:HALF_UP (1 / 0.0) division_by_zero', decimal.POSITIVE_INFINITY, 1 / 0.0);
						AddTestCase('divx909:p16 r:HALF_UP (10 / 0.0) division_by_zero', decimal.POSITIVE_INFINITY, 10 / 0.0);
						AddTestCase('divx910:p16 r:HALF_UP (1e+100 / 0.0) division_by_zero', decimal.POSITIVE_INFINITY, 1e+100 / 0.0);
						AddTestCase('divx911:p16 r:HALF_UP (1e+1000 / 0) division_by_zero', decimal.POSITIVE_INFINITY, 1e+1000 / 0);
						AddTestCase('divx921:p16 r:HALF_UP (-0.0001 / 0) division_by_zero', decimal.NEGATIVE_INFINITY, -0.0001 / 0);
						AddTestCase('divx922:p16 r:HALF_UP (-0.01 / 0) division_by_zero', decimal.NEGATIVE_INFINITY, -0.01 / 0);
						AddTestCase('divx923:p16 r:HALF_UP (-0.1 / 0) division_by_zero', decimal.NEGATIVE_INFINITY, -0.1 / 0);
						AddTestCase('divx924:p16 r:HALF_UP (-1 / 0) division_by_zero', decimal.NEGATIVE_INFINITY, -1 / 0);
						AddTestCase('divx925:p16 r:HALF_UP (-1 / 0.0) division_by_zero', decimal.NEGATIVE_INFINITY, -1 / 0.0);
						AddTestCase('divx926:p16 r:HALF_UP (-10 / 0.0) division_by_zero', decimal.NEGATIVE_INFINITY, -10 / 0.0);
						AddTestCase('divx927:p16 r:HALF_UP (-1e+100 / 0.0) division_by_zero', decimal.NEGATIVE_INFINITY, -1e+100 / 0.0);
						AddTestCase('divx928:p16 r:HALF_UP (-1e+1000 / 0) division_by_zero', decimal.NEGATIVE_INFINITY, -1e+1000 / 0);
						AddTestCase('divx931:p16 r:HALF_UP (0.0001 / -0) division_by_zero', decimal.NEGATIVE_INFINITY, 0.0001 / -0);
						AddTestCase('divx932:p16 r:HALF_UP (0.01 / -0) division_by_zero', decimal.NEGATIVE_INFINITY, 0.01 / -0);
						AddTestCase('divx933:p16 r:HALF_UP (0.1 / -0) division_by_zero', decimal.NEGATIVE_INFINITY, 0.1 / -0);
						AddTestCase('divx934:p16 r:HALF_UP (1 / -0) division_by_zero', decimal.NEGATIVE_INFINITY, 1 / -0);
						AddTestCase('divx935:p16 r:HALF_UP (1 / -0.0) division_by_zero', decimal.NEGATIVE_INFINITY, 1 / -0.0);
						AddTestCase('divx936:p16 r:HALF_UP (10 / -0.0) division_by_zero', decimal.NEGATIVE_INFINITY, 10 / -0.0);
						AddTestCase('divx937:p16 r:HALF_UP (1e+100 / -0.0) division_by_zero', decimal.NEGATIVE_INFINITY, 1e+100 / -0.0);
						AddTestCase('divx938:p16 r:HALF_UP (1e+1000 / -0) division_by_zero', decimal.NEGATIVE_INFINITY, 1e+1000 / -0);
						AddTestCase('divx941:p16 r:HALF_UP (-0.0001 / -0) division_by_zero', decimal.POSITIVE_INFINITY, -0.0001 / -0);
						AddTestCase('divx942:p16 r:HALF_UP (-0.01 / -0) division_by_zero', decimal.POSITIVE_INFINITY, -0.01 / -0);
						AddTestCase('divx943:p16 r:HALF_UP (-0.1 / -0) division_by_zero', decimal.POSITIVE_INFINITY, -0.1 / -0);
						AddTestCase('divx944:p16 r:HALF_UP (-1 / -0) division_by_zero', decimal.POSITIVE_INFINITY, -1 / -0);
						AddTestCase('divx945:p16 r:HALF_UP (-1 / -0.0) division_by_zero', decimal.POSITIVE_INFINITY, -1 / -0.0);
						AddTestCase('divx946:p16 r:HALF_UP (-10 / -0.0) division_by_zero', decimal.POSITIVE_INFINITY, -10 / -0.0);
						AddTestCase('divx947:p16 r:HALF_UP (-1e+100 / -0.0) division_by_zero', decimal.POSITIVE_INFINITY, -1e+100 / -0.0);
						AddTestCase('divx948:p16 r:HALF_UP (-1e+1000 / -0) division_by_zero', decimal.POSITIVE_INFINITY, -1e+1000 / -0);
						// overflow and underflow tests
						{
							use precision 9;
							// overflow and underflow (additional edge tests in multiply.dectest)
							// 'subnormal' results now possible (all hard underflow or overflow in
							// base arithemtic)
							// [no equivalent of 'subnormal' for overflow]
							// sign after overflow and underflow
							// long operand overflow may be a different path
						}
						{
							use precision 3;
							// check for double-rounded subnormals
						}
						{
							use precision 5;
							// a rounding problem in one implementation
							{
								use rounding HALF_UP;
								// unbounded answer to 40 digits:
								//   1.465811965811965811965811965811965811966e+7000
							}
							{
								use rounding HALF_UP;
								// examples from sql proposal (krishna kulkarni)
								{
									use precision 7;
									AddTestCase('divx1021:p7 r:HALF_UP (1e0 / 1e0)', 1, 1e0 / 1e0);
									AddTestCase('divx1022:p7 r:HALF_UP (1e0 / 2e0)', 0.5, 1e0 / 2e0);
									AddTestCase('divx1023:p7 r:HALF_UP (1e0 / 3e0) inexact rounded', 0.3333333, 1e0 / 3e0);
									AddTestCase('divx1024:p7 r:HALF_UP (100e-2 / 1000e-3)', 1, 100e-2 / 1000e-3);
									AddTestCase('divx1025:p7 r:HALF_UP (24e-1 / 2e0)', 1.2, 24e-1 / 2e0);
									AddTestCase('divx1026:p7 r:HALF_UP (2400e-3 / 2e0)', 1.200, 2400e-3 / 2e0);
									AddTestCase('divx1027:p7 r:HALF_UP (5e0 / 2e0)', 2.5, 5e0 / 2e0);
									AddTestCase('divx1028:p7 r:HALF_UP (5e0 / 20e-1)', 2.5, 5e0 / 20e-1);
									AddTestCase('divx1029:p7 r:HALF_UP (5e0 / 2000e-3)', 2.5, 5e0 / 2000e-3);
									AddTestCase('divx1030:p7 r:HALF_UP (5e0 / 2e-1)', 25, 5e0 / 2e-1);
									AddTestCase('divx1031:p7 r:HALF_UP (5e0 / 20e-2)', 25, 5e0 / 20e-2);
									AddTestCase('divx1032:p7 r:HALF_UP (480e-2 / 3e0)', 1.60, 480e-2 / 3e0);
									AddTestCase('divx1033:p7 r:HALF_UP (47e-1 / 2e0)', 2.35, 47e-1 / 2e0);
									// ecmascript bad examples
									{
										use rounding HALF_DOWN;
										{
											use precision 7;
											AddTestCase('divx1050:p7 r:HALF_DOWN (5 / 9) inexact rounded', 0.5555556, 5 / 9);
											{
												use rounding HALF_EVEN;
												AddTestCase('divx1051:p7 r:HALF_EVEN (5 / 11) inexact rounded', 0.4545455, 5 / 11);
												// payload decapitate
												{
													use precision 5;
													AddTestCase('divx1055:p5 r:HALF_EVEN (NaN / 1) invalid_operation', NaN, NaN / 1);
													// null tests
													AddTestCase('divx9998:p5 r:HALF_EVEN (10 / null) invalid_operation', Infinity, 10 / null);
													AddTestCase('divx9999:p5 r:HALF_EVEN (null / 10) invalid_operation', 0, null / 10);
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
