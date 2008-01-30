use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "remainder.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// remainder.dectest -- decimal remainder                             --
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
AddTestCase('remx001:p9 r:HALF_UP (1 % 1)', 0, 1 % 1);
AddTestCase('remx002:p9 r:HALF_UP (2 % 1)', 0, 2 % 1);
AddTestCase('remx003:p9 r:HALF_UP (1 % 2)', 1, 1 % 2);
AddTestCase('remx004:p9 r:HALF_UP (2 % 2)', 0, 2 % 2);
AddTestCase('remx005:p9 r:HALF_UP (0 % 1)', 0, 0 % 1);
AddTestCase('remx006:p9 r:HALF_UP (0 % 2)', 0, 0 % 2);
AddTestCase('remx007:p9 r:HALF_UP (1 % 3)', 1, 1 % 3);
AddTestCase('remx008:p9 r:HALF_UP (2 % 3)', 2, 2 % 3);
AddTestCase('remx009:p9 r:HALF_UP (3 % 3)', 0, 3 % 3);
AddTestCase('remx010:p9 r:HALF_UP (2.4 % 1)', 0.4, 2.4 % 1);
AddTestCase('remx011:p9 r:HALF_UP (2.4 % -1)', 0.4, 2.4 % -1);
AddTestCase('remx012:p9 r:HALF_UP (-2.4 % 1)', -0.4, -2.4 % 1);
AddTestCase('remx013:p9 r:HALF_UP (-2.4 % -1)', -0.4, -2.4 % -1);
AddTestCase('remx014:p9 r:HALF_UP (2.40 % 1)', 0.40, 2.40 % 1);
AddTestCase('remx015:p9 r:HALF_UP (2.400 % 1)', 0.400, 2.400 % 1);
AddTestCase('remx016:p9 r:HALF_UP (2.4 % 2)', 0.4, 2.4 % 2);
AddTestCase('remx017:p9 r:HALF_UP (2.400 % 2)', 0.400, 2.400 % 2);
AddTestCase('remx018:p9 r:HALF_UP (2. % 2)', 0, 2. % 2);
AddTestCase('remx019:p9 r:HALF_UP (20 % 20)', 0, 20 % 20);
AddTestCase('remx020:p9 r:HALF_UP (187 % 187)', 0, 187 % 187);
AddTestCase('remx021:p9 r:HALF_UP (5 % 2)', 1, 5 % 2);
AddTestCase('remx022:p9 r:HALF_UP (5 % 2.0)', 1.0, 5 % 2.0);
AddTestCase('remx023:p9 r:HALF_UP (5 % 2.000)', 1.000, 5 % 2.000);
AddTestCase('remx024:p9 r:HALF_UP (5 % 0.200)', 0.000, 5 % 0.200);
AddTestCase('remx025:p9 r:HALF_UP (5 % 0.200)', 0.000, 5 % 0.200);
AddTestCase('remx030:p9 r:HALF_UP (1 % 2)', 1, 1 % 2);
AddTestCase('remx031:p9 r:HALF_UP (1 % 4)', 1, 1 % 4);
AddTestCase('remx032:p9 r:HALF_UP (1 % 8)', 1, 1 % 8);
AddTestCase('remx033:p9 r:HALF_UP (1 % 16)', 1, 1 % 16);
AddTestCase('remx034:p9 r:HALF_UP (1 % 32)', 1, 1 % 32);
AddTestCase('remx035:p9 r:HALF_UP (1 % 64)', 1, 1 % 64);
AddTestCase('remx040:p9 r:HALF_UP (1 % -2)', 1, 1 % -2);
AddTestCase('remx041:p9 r:HALF_UP (1 % -4)', 1, 1 % -4);
AddTestCase('remx042:p9 r:HALF_UP (1 % -8)', 1, 1 % -8);
AddTestCase('remx043:p9 r:HALF_UP (1 % -16)', 1, 1 % -16);
AddTestCase('remx044:p9 r:HALF_UP (1 % -32)', 1, 1 % -32);
AddTestCase('remx045:p9 r:HALF_UP (1 % -64)', 1, 1 % -64);
AddTestCase('remx050:p9 r:HALF_UP (-1 % 2)', -1, -1 % 2);
AddTestCase('remx051:p9 r:HALF_UP (-1 % 4)', -1, -1 % 4);
AddTestCase('remx052:p9 r:HALF_UP (-1 % 8)', -1, -1 % 8);
AddTestCase('remx053:p9 r:HALF_UP (-1 % 16)', -1, -1 % 16);
AddTestCase('remx054:p9 r:HALF_UP (-1 % 32)', -1, -1 % 32);
AddTestCase('remx055:p9 r:HALF_UP (-1 % 64)', -1, -1 % 64);
AddTestCase('remx060:p9 r:HALF_UP (-1 % -2)', -1, -1 % -2);
AddTestCase('remx061:p9 r:HALF_UP (-1 % -4)', -1, -1 % -4);
AddTestCase('remx062:p9 r:HALF_UP (-1 % -8)', -1, -1 % -8);
AddTestCase('remx063:p9 r:HALF_UP (-1 % -16)', -1, -1 % -16);
AddTestCase('remx064:p9 r:HALF_UP (-1 % -32)', -1, -1 % -32);
AddTestCase('remx065:p9 r:HALF_UP (-1 % -64)', -1, -1 % -64);
AddTestCase('remx066:p9 r:HALF_UP (999999999 % 1)', 0, 999999999 % 1);
AddTestCase('remx067:p9 r:HALF_UP (999999999.4 % 1)', 0.4, 999999999.4 % 1);
AddTestCase('remx068:p9 r:HALF_UP (999999999.5 % 1)', 0.5, 999999999.5 % 1);
AddTestCase('remx069:p9 r:HALF_UP (999999999.9 % 1)', 0.9, 999999999.9 % 1);
AddTestCase('remx070:p9 r:HALF_UP (999999999.999 % 1)', 0.999, 999999999.999 % 1);
{
	use precision 6;
	AddTestCase('remx071:p6 r:HALF_UP (999999999 % 1) ', 0, 999999999 % 1);
	AddTestCase('remx072:p6 r:HALF_UP (99999999 % 1) ', 0, 99999999 % 1);
	AddTestCase('remx073:p6 r:HALF_UP (9999999 % 1) ', 0, 9999999 % 1);
	AddTestCase('remx074:p6 r:HALF_UP (999999 % 1)', 0, 999999 % 1);
	AddTestCase('remx075:p6 r:HALF_UP (99999 % 1)', 0, 99999 % 1);
	AddTestCase('remx076:p6 r:HALF_UP (9999 % 1)', 0, 9999 % 1);
	AddTestCase('remx077:p6 r:HALF_UP (999 % 1)', 0, 999 % 1);
	AddTestCase('remx078:p6 r:HALF_UP (99 % 1)', 0, 99 % 1);
	AddTestCase('remx079:p6 r:HALF_UP (9 % 1)', 0, 9 % 1);
}
{
	use precision 9;
	AddTestCase('remx080:p9 r:HALF_UP (0. % 1)', 0, 0. % 1);
	AddTestCase('remx081:p9 r:HALF_UP (.0 % 1)', 0.0, .0 % 1);
	AddTestCase('remx082:p9 r:HALF_UP (0.00 % 1)', 0.00, 0.00 % 1);
	AddTestCase('remx083:p9 r:HALF_UP (0.00e+9 % 1)', 0, 0.00e+9 % 1);
	AddTestCase('remx084:p9 r:HALF_UP (0.00e+3 % 1)', 0, 0.00e+3 % 1);
	AddTestCase('remx085:p9 r:HALF_UP (0.00e+2 % 1)', 0, 0.00e+2 % 1);
	AddTestCase('remx086:p9 r:HALF_UP (0.00e+1 % 1)', 0.0, 0.00e+1 % 1);
	AddTestCase('remx087:p9 r:HALF_UP (0.00e+0 % 1)', 0.00, 0.00e+0 % 1);
	AddTestCase('remx088:p9 r:HALF_UP (0.00e-0 % 1)', 0.00, 0.00e-0 % 1);
	AddTestCase('remx089:p9 r:HALF_UP (0.00e-1 % 1)', 0.000, 0.00e-1 % 1);
	AddTestCase('remx090:p9 r:HALF_UP (0.00e-2 % 1)', 0.0000, 0.00e-2 % 1);
	AddTestCase('remx091:p9 r:HALF_UP (0.00e-3 % 1)', 0.00000, 0.00e-3 % 1);
	AddTestCase('remx092:p9 r:HALF_UP (0.00e-4 % 1)', 0.000000, 0.00e-4 % 1);
	AddTestCase('remx093:p9 r:HALF_UP (0.00e-5 % 1)', 0e-7, 0.00e-5 % 1);
	AddTestCase('remx094:p9 r:HALF_UP (0.00e-6 % 1)', 0e-8, 0.00e-6 % 1);
	AddTestCase('remx095:p9 r:HALF_UP (0.0000e-50 % 1)', 0e-54, 0.0000e-50 % 1);
	// various flavours of remainder by 0
}
{
	use precision 9;
	AddTestCase('remx101:p9 r:HALF_UP (0 % 0) division_undefined', NaN, 0 % 0);
	AddTestCase('remx102:p9 r:HALF_UP (0 % -0) division_undefined', NaN, 0 % -0);
	AddTestCase('remx103:p9 r:HALF_UP (-0 % 0) division_undefined', NaN, -0 % 0);
	AddTestCase('remx104:p9 r:HALF_UP (-0 % -0) division_undefined', NaN, -0 % -0);
	AddTestCase('remx105:p9 r:HALF_UP (0.0e5 % 0) division_undefined', NaN, 0.0e5 % 0);
	AddTestCase('remx106:p9 r:HALF_UP (0.000 % 0) division_undefined', NaN, 0.000 % 0);
	// [some think this next group should be division_by_zero exception, but
	// ieee 854 is explicit that it is invalid operation .. for
	// remainder-near, anyway]
	AddTestCase('remx107:p9 r:HALF_UP (0.0001 % 0) invalid_operation', NaN, 0.0001 % 0);
	AddTestCase('remx108:p9 r:HALF_UP (0.01 % 0) invalid_operation', NaN, 0.01 % 0);
	AddTestCase('remx109:p9 r:HALF_UP (0.1 % 0) invalid_operation', NaN, 0.1 % 0);
	AddTestCase('remx110:p9 r:HALF_UP (1 % 0) invalid_operation', NaN, 1 % 0);
	AddTestCase('remx111:p9 r:HALF_UP (1 % 0.0) invalid_operation', NaN, 1 % 0.0);
	AddTestCase('remx112:p9 r:HALF_UP (10 % 0.0) invalid_operation', NaN, 10 % 0.0);
	AddTestCase('remx113:p9 r:HALF_UP (1e+100 % 0.0) invalid_operation', NaN, 1e+100 % 0.0);
	AddTestCase('remx114:p9 r:HALF_UP (1e+1000 % 0) invalid_operation', NaN, 1e+1000 % 0);
	AddTestCase('remx115:p9 r:HALF_UP (0.0001 % -0) invalid_operation', NaN, 0.0001 % -0);
	AddTestCase('remx116:p9 r:HALF_UP (0.01 % -0) invalid_operation', NaN, 0.01 % -0);
	AddTestCase('remx119:p9 r:HALF_UP (0.1 % -0) invalid_operation', NaN, 0.1 % -0);
	AddTestCase('remx120:p9 r:HALF_UP (1 % -0) invalid_operation', NaN, 1 % -0);
	AddTestCase('remx121:p9 r:HALF_UP (1 % -0.0) invalid_operation', NaN, 1 % -0.0);
	AddTestCase('remx122:p9 r:HALF_UP (10 % -0.0) invalid_operation', NaN, 10 % -0.0);
	AddTestCase('remx123:p9 r:HALF_UP (1e+100 % -0.0) invalid_operation', NaN, 1e+100 % -0.0);
	AddTestCase('remx124:p9 r:HALF_UP (1e+1000 % -0) invalid_operation', NaN, 1e+1000 % -0);
	// and zeros on left
	AddTestCase('remx130:p9 r:HALF_UP (0 % 1)', 0, 0 % 1);
	AddTestCase('remx131:p9 r:HALF_UP (0 % -1)', 0, 0 % -1);
	AddTestCase('remx132:p9 r:HALF_UP (0.0 % 1)', 0.0, 0.0 % 1);
	AddTestCase('remx133:p9 r:HALF_UP (0.0 % -1)', 0.0, 0.0 % -1);
	AddTestCase('remx134:p9 r:HALF_UP (-0 % 1)', -0, -0 % 1);
	AddTestCase('remx135:p9 r:HALF_UP (-0 % -1)', -0, -0 % -1);
	AddTestCase('remx136:p9 r:HALF_UP (-0.0 % 1)', -0.0, -0.0 % 1);
	AddTestCase('remx137:p9 r:HALF_UP (-0.0 % -1)', -0.0, -0.0 % -1);
	// 0.5ers
	AddTestCase('remx143:p9 r:HALF_UP (0.5 % 2)', 0.5, 0.5 % 2);
	AddTestCase('remx144:p9 r:HALF_UP (0.5 % 2.1)', 0.5, 0.5 % 2.1);
	AddTestCase('remx145:p9 r:HALF_UP (0.5 % 2.01)', 0.50, 0.5 % 2.01);
	AddTestCase('remx146:p9 r:HALF_UP (0.5 % 2.001)', 0.500, 0.5 % 2.001);
	AddTestCase('remx147:p9 r:HALF_UP (0.50 % 2)', 0.50, 0.50 % 2);
	AddTestCase('remx148:p9 r:HALF_UP (0.50 % 2.01)', 0.50, 0.50 % 2.01);
	AddTestCase('remx149:p9 r:HALF_UP (0.50 % 2.001)', 0.500, 0.50 % 2.001);
	// steadies
	AddTestCase('remx150:p9 r:HALF_UP (1 % 1)', 0, 1 % 1);
	AddTestCase('remx151:p9 r:HALF_UP (1 % 2)', 1, 1 % 2);
	AddTestCase('remx152:p9 r:HALF_UP (1 % 3)', 1, 1 % 3);
	AddTestCase('remx153:p9 r:HALF_UP (1 % 4)', 1, 1 % 4);
	AddTestCase('remx154:p9 r:HALF_UP (1 % 5)', 1, 1 % 5);
	AddTestCase('remx155:p9 r:HALF_UP (1 % 6)', 1, 1 % 6);
	AddTestCase('remx156:p9 r:HALF_UP (1 % 7)', 1, 1 % 7);
	AddTestCase('remx157:p9 r:HALF_UP (1 % 8)', 1, 1 % 8);
	AddTestCase('remx158:p9 r:HALF_UP (1 % 9)', 1, 1 % 9);
	AddTestCase('remx159:p9 r:HALF_UP (1 % 10)', 1, 1 % 10);
	AddTestCase('remx160:p9 r:HALF_UP (1 % 1)', 0, 1 % 1);
	AddTestCase('remx161:p9 r:HALF_UP (2 % 1)', 0, 2 % 1);
	AddTestCase('remx162:p9 r:HALF_UP (3 % 1)', 0, 3 % 1);
	AddTestCase('remx163:p9 r:HALF_UP (4 % 1)', 0, 4 % 1);
	AddTestCase('remx164:p9 r:HALF_UP (5 % 1)', 0, 5 % 1);
	AddTestCase('remx165:p9 r:HALF_UP (6 % 1)', 0, 6 % 1);
	AddTestCase('remx166:p9 r:HALF_UP (7 % 1)', 0, 7 % 1);
	AddTestCase('remx167:p9 r:HALF_UP (8 % 1)', 0, 8 % 1);
	AddTestCase('remx168:p9 r:HALF_UP (9 % 1)', 0, 9 % 1);
	AddTestCase('remx169:p9 r:HALF_UP (10 % 1)', 0, 10 % 1);
	// some differences from remaindernear
	AddTestCase('remx171:p9 r:HALF_UP (0.4 % 1.020)', 0.400, 0.4 % 1.020);
	AddTestCase('remx172:p9 r:HALF_UP (0.50 % 1.020)', 0.500, 0.50 % 1.020);
	AddTestCase('remx173:p9 r:HALF_UP (0.51 % 1.020)', 0.510, 0.51 % 1.020);
	AddTestCase('remx174:p9 r:HALF_UP (0.52 % 1.020)', 0.520, 0.52 % 1.020);
	AddTestCase('remx175:p9 r:HALF_UP (0.6 % 1.020)', 0.600, 0.6 % 1.020);
	// more flavours of remainder by 0
	AddTestCase('remx201:p9 r:HALF_UP (0 % 0) division_undefined', NaN, 0 % 0);
	AddTestCase('remx202:p9 r:HALF_UP (0.0e5 % 0) division_undefined', NaN, 0.0e5 % 0);
	AddTestCase('remx203:p9 r:HALF_UP (0.000 % 0) division_undefined', NaN, 0.000 % 0);
	AddTestCase('remx204:p9 r:HALF_UP (0.0001 % 0) invalid_operation', NaN, 0.0001 % 0);
	AddTestCase('remx205:p9 r:HALF_UP (0.01 % 0) invalid_operation', NaN, 0.01 % 0);
	AddTestCase('remx206:p9 r:HALF_UP (0.1 % 0) invalid_operation', NaN, 0.1 % 0);
	AddTestCase('remx207:p9 r:HALF_UP (1 % 0) invalid_operation', NaN, 1 % 0);
	AddTestCase('remx208:p9 r:HALF_UP (1 % 0.0) invalid_operation', NaN, 1 % 0.0);
	AddTestCase('remx209:p9 r:HALF_UP (10 % 0.0) invalid_operation', NaN, 10 % 0.0);
	AddTestCase('remx210:p9 r:HALF_UP (1e+100 % 0.0) invalid_operation', NaN, 1e+100 % 0.0);
	AddTestCase('remx211:p9 r:HALF_UP (1e+1000 % 0) invalid_operation', NaN, 1e+1000 % 0);
	// some differences from remaindernear
	AddTestCase('remx231:p9 r:HALF_UP (-0.4 % 1.020)', -0.400, -0.4 % 1.020);
	AddTestCase('remx232:p9 r:HALF_UP (-0.50 % 1.020)', -0.500, -0.50 % 1.020);
	AddTestCase('remx233:p9 r:HALF_UP (-0.51 % 1.020)', -0.510, -0.51 % 1.020);
	AddTestCase('remx234:p9 r:HALF_UP (-0.52 % 1.020)', -0.520, -0.52 % 1.020);
	AddTestCase('remx235:p9 r:HALF_UP (-0.6 % 1.020)', -0.600, -0.6 % 1.020);
	// high xs
	AddTestCase('remx240:p9 r:HALF_UP (1e+2 % 1.00)', 0.00, 1e+2 % 1.00);
	// test some cases that are close to exponent overflow
	AddTestCase('remx270:p9 r:HALF_UP (1 % 1e999999999)', 1, 1 % 1e999999999);
	AddTestCase('remx271:p9 r:HALF_UP (1 % 0.9e999999999)', 1, 1 % 0.9e999999999);
	AddTestCase('remx272:p9 r:HALF_UP (1 % 0.99e999999999)', 1, 1 % 0.99e999999999);
	AddTestCase('remx273:p9 r:HALF_UP (1 % 0.999999999e999999999)', 1, 1 % 0.999999999e999999999);
	AddTestCase('remx274:p9 r:HALF_UP (9e999999999 % 1) division_impossible', NaN, 9e999999999 % 1);
	AddTestCase('remx275:p9 r:HALF_UP (9.9e999999999 % 1) division_impossible', NaN, 9.9e999999999 % 1);
	AddTestCase('remx276:p9 r:HALF_UP (9.99e999999999 % 1) division_impossible', NaN, 9.99e999999999 % 1);
	AddTestCase('remx277:p9 r:HALF_UP (9.99999999e999999999 % 1) division_impossible', NaN, 9.99999999e999999999 % 1);
	AddTestCase('remx280:p9 r:HALF_UP (0.1 % 9e-999999999) division_impossible', NaN, 0.1 % 9e-999999999);
	AddTestCase('remx281:p9 r:HALF_UP (0.1 % 99e-999999999) division_impossible', NaN, 0.1 % 99e-999999999);
	AddTestCase('remx282:p9 r:HALF_UP (0.1 % 999e-999999999) division_impossible', NaN, 0.1 % 999e-999999999);
	AddTestCase('remx283:p9 r:HALF_UP (0.1 % 9e-999999998) division_impossible', NaN, 0.1 % 9e-999999998);
	AddTestCase('remx284:p9 r:HALF_UP (0.1 % 99e-999999998) division_impossible', NaN, 0.1 % 99e-999999998);
	AddTestCase('remx285:p9 r:HALF_UP (0.1 % 999e-999999998) division_impossible', NaN, 0.1 % 999e-999999998);
	AddTestCase('remx286:p9 r:HALF_UP (0.1 % 999e-999999997) division_impossible', NaN, 0.1 % 999e-999999997);
	AddTestCase('remx287:p9 r:HALF_UP (0.1 % 9999e-999999997) division_impossible', NaN, 0.1 % 9999e-999999997);
	AddTestCase('remx288:p9 r:HALF_UP (0.1 % 99999e-999999997) division_impossible', NaN, 0.1 % 99999e-999999997);
	// remx3xx are from diagbigdecimal
	AddTestCase('remx301:p9 r:HALF_UP (1 % 3)', 1, 1 % 3);
	AddTestCase('remx302:p9 r:HALF_UP (5 % 5)', 0, 5 % 5);
	AddTestCase('remx303:p9 r:HALF_UP (13 % 10)', 3, 13 % 10);
	AddTestCase('remx304:p9 r:HALF_UP (13 % 50)', 13, 13 % 50);
	AddTestCase('remx305:p9 r:HALF_UP (13 % 100)', 13, 13 % 100);
	AddTestCase('remx306:p9 r:HALF_UP (13 % 1000)', 13, 13 % 1000);
	AddTestCase('remx307:p9 r:HALF_UP (.13 % 1)', 0.13, .13 % 1);
	AddTestCase('remx308:p9 r:HALF_UP (0.133 % 1)', 0.133, 0.133 % 1);
	AddTestCase('remx309:p9 r:HALF_UP (0.1033 % 1)', 0.1033, 0.1033 % 1);
	AddTestCase('remx310:p9 r:HALF_UP (1.033 % 1)', 0.033, 1.033 % 1);
	AddTestCase('remx311:p9 r:HALF_UP (10.33 % 1)', 0.33, 10.33 % 1);
	AddTestCase('remx312:p9 r:HALF_UP (10.33 % 10)', 0.33, 10.33 % 10);
	AddTestCase('remx313:p9 r:HALF_UP (103.3 % 1)', 0.3, 103.3 % 1);
	AddTestCase('remx314:p9 r:HALF_UP (133 % 10)', 3, 133 % 10);
	AddTestCase('remx315:p9 r:HALF_UP (1033 % 10)', 3, 1033 % 10);
	AddTestCase('remx316:p9 r:HALF_UP (1033 % 50)', 33, 1033 % 50);
	AddTestCase('remx317:p9 r:HALF_UP (101.0 % 3)', 2.0, 101.0 % 3);
	AddTestCase('remx318:p9 r:HALF_UP (102.0 % 3)', 0.0, 102.0 % 3);
	AddTestCase('remx319:p9 r:HALF_UP (103.0 % 3)', 1.0, 103.0 % 3);
	AddTestCase('remx320:p9 r:HALF_UP (2.40 % 1)', 0.40, 2.40 % 1);
	AddTestCase('remx321:p9 r:HALF_UP (2.400 % 1)', 0.400, 2.400 % 1);
	AddTestCase('remx322:p9 r:HALF_UP (2.4 % 1)', 0.4, 2.4 % 1);
	AddTestCase('remx323:p9 r:HALF_UP (2.4 % 2)', 0.4, 2.4 % 2);
	AddTestCase('remx324:p9 r:HALF_UP (2.400 % 2)', 0.400, 2.400 % 2);
	AddTestCase('remx325:p9 r:HALF_UP (1 % 0.3)', 0.1, 1 % 0.3);
	AddTestCase('remx326:p9 r:HALF_UP (1 % 0.30)', 0.10, 1 % 0.30);
	AddTestCase('remx327:p9 r:HALF_UP (1 % 0.300)', 0.100, 1 % 0.300);
	AddTestCase('remx328:p9 r:HALF_UP (1 % 0.3000)', 0.1000, 1 % 0.3000);
	AddTestCase('remx329:p9 r:HALF_UP (1.0 % 0.3)', 0.1, 1.0 % 0.3);
	AddTestCase('remx330:p9 r:HALF_UP (1.00 % 0.3)', 0.10, 1.00 % 0.3);
	AddTestCase('remx331:p9 r:HALF_UP (1.000 % 0.3)', 0.100, 1.000 % 0.3);
	AddTestCase('remx332:p9 r:HALF_UP (1.0000 % 0.3)', 0.1000, 1.0000 % 0.3);
	AddTestCase('remx333:p9 r:HALF_UP (0.5 % 2)', 0.5, 0.5 % 2);
	AddTestCase('remx334:p9 r:HALF_UP (0.5 % 2.1)', 0.5, 0.5 % 2.1);
	AddTestCase('remx335:p9 r:HALF_UP (0.5 % 2.01)', 0.50, 0.5 % 2.01);
	AddTestCase('remx336:p9 r:HALF_UP (0.5 % 2.001)', 0.500, 0.5 % 2.001);
	AddTestCase('remx337:p9 r:HALF_UP (0.50 % 2)', 0.50, 0.50 % 2);
	AddTestCase('remx338:p9 r:HALF_UP (0.50 % 2.01)', 0.50, 0.50 % 2.01);
	AddTestCase('remx339:p9 r:HALF_UP (0.50 % 2.001)', 0.500, 0.50 % 2.001);
	AddTestCase('remx340:p9 r:HALF_UP (0.5 % 0.5000001)', 0.5000000, 0.5 % 0.5000001);
	AddTestCase('remx341:p9 r:HALF_UP (0.5 % 0.50000001)', 0.50000000, 0.5 % 0.50000001);
	AddTestCase('remx342:p9 r:HALF_UP (0.5 % 0.500000001)', 0.500000000, 0.5 % 0.500000001);
	AddTestCase('remx343:p9 r:HALF_UP (0.5 % 0.5000000001) rounded', 0.500000000, 0.5 % 0.5000000001);
	AddTestCase('remx344:p9 r:HALF_UP (0.5 % 0.50000000001) rounded', 0.500000000, 0.5 % 0.50000000001);
	AddTestCase('remx345:p9 r:HALF_UP (0.5 % 0.4999999)', 1e-7, 0.5 % 0.4999999);
	AddTestCase('remx346:p9 r:HALF_UP (0.5 % 0.49999999)', 1e-8, 0.5 % 0.49999999);
	AddTestCase('remx347:p9 r:HALF_UP (0.5 % 0.499999999)', 1e-9, 0.5 % 0.499999999);
	AddTestCase('remx348:p9 r:HALF_UP (0.5 % 0.4999999999)', 1e-10, 0.5 % 0.4999999999);
	AddTestCase('remx349:p9 r:HALF_UP (0.5 % 0.49999999999)', 1e-11, 0.5 % 0.49999999999);
	AddTestCase('remx350:p9 r:HALF_UP (0.5 % 0.499999999999)', 1e-12, 0.5 % 0.499999999999);
	AddTestCase('remx351:p9 r:HALF_UP (0.03 % 7)', 0.03, 0.03 % 7);
	AddTestCase('remx352:p9 r:HALF_UP (5 % 2)', 1, 5 % 2);
	AddTestCase('remx353:p9 r:HALF_UP (4.1 % 2)', 0.1, 4.1 % 2);
	AddTestCase('remx354:p9 r:HALF_UP (4.01 % 2)', 0.01, 4.01 % 2);
	AddTestCase('remx355:p9 r:HALF_UP (4.001 % 2)', 0.001, 4.001 % 2);
	AddTestCase('remx356:p9 r:HALF_UP (4.0001 % 2)', 0.0001, 4.0001 % 2);
	AddTestCase('remx357:p9 r:HALF_UP (4.00001 % 2)', 0.00001, 4.00001 % 2);
	AddTestCase('remx358:p9 r:HALF_UP (4.000001 % 2)', 0.000001, 4.000001 % 2);
	AddTestCase('remx359:p9 r:HALF_UP (4.0000001 % 2)', 1e-7, 4.0000001 % 2);
	AddTestCase('remx360:p9 r:HALF_UP (1.2 % 0.7345)', 0.4655, 1.2 % 0.7345);
	AddTestCase('remx361:p9 r:HALF_UP (0.8 % 12)', 0.8, 0.8 % 12);
	AddTestCase('remx362:p9 r:HALF_UP (0.8 % 0.2)', 0.0, 0.8 % 0.2);
	AddTestCase('remx363:p9 r:HALF_UP (0.8 % 0.3)', 0.2, 0.8 % 0.3);
	AddTestCase('remx364:p9 r:HALF_UP (0.800 % 12)', 0.800, 0.800 % 12);
	AddTestCase('remx365:p9 r:HALF_UP (0.800 % 1.7)', 0.800, 0.800 % 1.7);
	AddTestCase('remx366:p9 r:HALF_UP (2.400 % 2)', 0.400, 2.400 % 2);
}
{
	use precision 6;
	AddTestCase('remx371:p6 r:HALF_UP (2.400 % 2)', 0.400, 2.400 % 2);
}
{
	use precision 3;
	// long operand, rounded, case
	AddTestCase('remx372:p3 r:HALF_UP (12345678900000 % 12e+12) inexact rounded', 3.46e+11, 12345678900000 % 12e+12);
	//                  12000000000000
}
{
	use precision 5;
	AddTestCase('remx381:p5 r:HALF_UP (12345 % 1)', 0, 12345 % 1);
	AddTestCase('remx382:p5 r:HALF_UP (12345 % 1.0001)', 0.7657, 12345 % 1.0001);
	AddTestCase('remx383:p5 r:HALF_UP (12345 % 1.001)', 0.668, 12345 % 1.001);
	AddTestCase('remx384:p5 r:HALF_UP (12345 % 1.01)', 0.78, 12345 % 1.01);
	AddTestCase('remx385:p5 r:HALF_UP (12345 % 1.1)', 0.8, 12345 % 1.1);
	AddTestCase('remx386:p5 r:HALF_UP (12355 % 4)', 3, 12355 % 4);
	AddTestCase('remx387:p5 r:HALF_UP (12345 % 4)', 1, 12345 % 4);
	AddTestCase('remx388:p5 r:HALF_UP (12355 % 4.0001)', 2.6912, 12355 % 4.0001);
	AddTestCase('remx389:p5 r:HALF_UP (12345 % 4.0001)', 0.6914, 12345 % 4.0001);
	AddTestCase('remx390:p5 r:HALF_UP (12345 % 4.9)', 1.9, 12345 % 4.9);
	AddTestCase('remx391:p5 r:HALF_UP (12345 % 4.99)', 4.73, 12345 % 4.99);
	AddTestCase('remx392:p5 r:HALF_UP (12345 % 4.999)', 2.469, 12345 % 4.999);
	AddTestCase('remx393:p5 r:HALF_UP (12345 % 4.9999)', 0.2469, 12345 % 4.9999);
	AddTestCase('remx394:p5 r:HALF_UP (12345 % 5)', 0, 12345 % 5);
	AddTestCase('remx395:p5 r:HALF_UP (12345 % 5.0001)', 4.7532, 12345 % 5.0001);
	AddTestCase('remx396:p5 r:HALF_UP (12345 % 5.001)', 2.532, 12345 % 5.001);
	AddTestCase('remx397:p5 r:HALF_UP (12345 % 5.01)', 0.36, 12345 % 5.01);
	AddTestCase('remx398:p5 r:HALF_UP (12345 % 5.1)', 3.0, 12345 % 5.1);
}
{
	use precision 9;
	// the nasty division-by-1 cases
	AddTestCase('remx401:p9 r:HALF_UP (0.5 % 1)', 0.5, 0.5 % 1);
	AddTestCase('remx402:p9 r:HALF_UP (0.55 % 1)', 0.55, 0.55 % 1);
	AddTestCase('remx403:p9 r:HALF_UP (0.555 % 1)', 0.555, 0.555 % 1);
	AddTestCase('remx404:p9 r:HALF_UP (0.5555 % 1)', 0.5555, 0.5555 % 1);
	AddTestCase('remx405:p9 r:HALF_UP (0.55555 % 1)', 0.55555, 0.55555 % 1);
	AddTestCase('remx406:p9 r:HALF_UP (0.555555 % 1)', 0.555555, 0.555555 % 1);
	AddTestCase('remx407:p9 r:HALF_UP (0.5555555 % 1)', 0.5555555, 0.5555555 % 1);
	AddTestCase('remx408:p9 r:HALF_UP (0.55555555 % 1)', 0.55555555, 0.55555555 % 1);
	AddTestCase('remx409:p9 r:HALF_UP (0.555555555 % 1)', 0.555555555, 0.555555555 % 1);
	// specials
	AddTestCase('remx680:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY % decimal.NEGATIVE_INFINITY);
	AddTestCase('remx681:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % -1000) invalid_operation', NaN, decimal.POSITIVE_INFINITY % -1000);
	AddTestCase('remx682:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % -1) invalid_operation', NaN, decimal.POSITIVE_INFINITY % -1);
	AddTestCase('remx683:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % 0) invalid_operation', NaN, decimal.POSITIVE_INFINITY % 0);
	AddTestCase('remx684:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % -0) invalid_operation', NaN, decimal.POSITIVE_INFINITY % -0);
	AddTestCase('remx685:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % 1) invalid_operation', NaN, decimal.POSITIVE_INFINITY % 1);
	AddTestCase('remx686:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % 1000) invalid_operation', NaN, decimal.POSITIVE_INFINITY % 1000);
	AddTestCase('remx687:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % decimal.POSITIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY % decimal.POSITIVE_INFINITY);
	AddTestCase('remx688:p9 r:HALF_UP (-1000 % decimal.POSITIVE_INFINITY)', -1000, -1000 % decimal.POSITIVE_INFINITY);
	AddTestCase('remx689:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY % decimal.POSITIVE_INFINITY) invalid_operation', NaN, decimal.NEGATIVE_INFINITY % decimal.POSITIVE_INFINITY);
	AddTestCase('remx691:p9 r:HALF_UP (-1 % decimal.POSITIVE_INFINITY)', -1, -1 % decimal.POSITIVE_INFINITY);
	AddTestCase('remx692:p9 r:HALF_UP (0 % decimal.POSITIVE_INFINITY)', 0, 0 % decimal.POSITIVE_INFINITY);
	AddTestCase('remx693:p9 r:HALF_UP (-0 % decimal.POSITIVE_INFINITY)', -0, -0 % decimal.POSITIVE_INFINITY);
	AddTestCase('remx694:p9 r:HALF_UP (1 % decimal.POSITIVE_INFINITY)', 1, 1 % decimal.POSITIVE_INFINITY);
	AddTestCase('remx695:p9 r:HALF_UP (1000 % decimal.POSITIVE_INFINITY)', 1000, 1000 % decimal.POSITIVE_INFINITY);
	AddTestCase('remx696:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % decimal.POSITIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY % decimal.POSITIVE_INFINITY);
	AddTestCase('remx700:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY % decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.NEGATIVE_INFINITY % decimal.NEGATIVE_INFINITY);
	AddTestCase('remx701:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY % -1000) invalid_operation', NaN, decimal.NEGATIVE_INFINITY % -1000);
	AddTestCase('remx702:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY % -1) invalid_operation', NaN, decimal.NEGATIVE_INFINITY % -1);
	AddTestCase('remx703:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY % -0) invalid_operation', NaN, decimal.NEGATIVE_INFINITY % -0);
	AddTestCase('remx704:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY % 0) invalid_operation', NaN, decimal.NEGATIVE_INFINITY % 0);
	AddTestCase('remx705:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY % 1) invalid_operation', NaN, decimal.NEGATIVE_INFINITY % 1);
	AddTestCase('remx706:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY % 1000) invalid_operation', NaN, decimal.NEGATIVE_INFINITY % 1000);
	AddTestCase('remx707:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY % decimal.POSITIVE_INFINITY) invalid_operation', NaN, decimal.NEGATIVE_INFINITY % decimal.POSITIVE_INFINITY);
	AddTestCase('remx708:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY % decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.NEGATIVE_INFINITY % decimal.NEGATIVE_INFINITY);
	AddTestCase('remx709:p9 r:HALF_UP (-1000 % decimal.POSITIVE_INFINITY)', -1000, -1000 % decimal.POSITIVE_INFINITY);
	AddTestCase('remx710:p9 r:HALF_UP (-1 % decimal.NEGATIVE_INFINITY)', -1, -1 % decimal.NEGATIVE_INFINITY);
	AddTestCase('remx711:p9 r:HALF_UP (-0 % decimal.NEGATIVE_INFINITY)', -0, -0 % decimal.NEGATIVE_INFINITY);
	AddTestCase('remx712:p9 r:HALF_UP (0 % decimal.NEGATIVE_INFINITY)', 0, 0 % decimal.NEGATIVE_INFINITY);
	AddTestCase('remx713:p9 r:HALF_UP (1 % decimal.NEGATIVE_INFINITY)', 1, 1 % decimal.NEGATIVE_INFINITY);
	AddTestCase('remx714:p9 r:HALF_UP (1000 % decimal.NEGATIVE_INFINITY)', 1000, 1000 % decimal.NEGATIVE_INFINITY);
	AddTestCase('remx715:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % decimal.NEGATIVE_INFINITY) invalid_operation', NaN, decimal.POSITIVE_INFINITY % decimal.NEGATIVE_INFINITY);
	AddTestCase('remx721:p9 r:HALF_UP (NaN % decimal.NEGATIVE_INFINITY)', NaN, NaN % decimal.NEGATIVE_INFINITY);
	AddTestCase('remx722:p9 r:HALF_UP (NaN % -1000)', NaN, NaN % -1000);
	AddTestCase('remx723:p9 r:HALF_UP (NaN % -1)', NaN, NaN % -1);
	AddTestCase('remx724:p9 r:HALF_UP (NaN % -0)', NaN, NaN % -0);
	AddTestCase('remx725:p9 r:HALF_UP (-NaN % 0)', -NaN, -NaN % 0);
	AddTestCase('remx726:p9 r:HALF_UP (NaN % 1)', NaN, NaN % 1);
	AddTestCase('remx727:p9 r:HALF_UP (NaN % 1000)', NaN, NaN % 1000);
	AddTestCase('remx728:p9 r:HALF_UP (NaN % decimal.POSITIVE_INFINITY)', NaN, NaN % decimal.POSITIVE_INFINITY);
	AddTestCase('remx729:p9 r:HALF_UP (NaN % -NaN)', NaN, NaN % -NaN);
	AddTestCase('remx730:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY % NaN)', NaN, decimal.NEGATIVE_INFINITY % NaN);
	AddTestCase('remx731:p9 r:HALF_UP (-1000 % NaN)', NaN, -1000 % NaN);
	AddTestCase('remx732:p9 r:HALF_UP (-1 % NaN)', NaN, -1 % NaN);
	AddTestCase('remx733:p9 r:HALF_UP (-0 % -NaN)', -NaN, -0 % -NaN);
	AddTestCase('remx734:p9 r:HALF_UP (0 % NaN)', NaN, 0 % NaN);
	AddTestCase('remx735:p9 r:HALF_UP (1 % -NaN)', -NaN, 1 % -NaN);
	AddTestCase('remx736:p9 r:HALF_UP (1000 % NaN)', NaN, 1000 % NaN);
	AddTestCase('remx737:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % NaN)', NaN, decimal.POSITIVE_INFINITY % NaN);
	AddTestCase('remx741:p9 r:HALF_UP (NaN % decimal.NEGATIVE_INFINITY) invalid_operation', NaN, NaN % decimal.NEGATIVE_INFINITY);
	AddTestCase('remx742:p9 r:HALF_UP (NaN % -1000) invalid_operation', NaN, NaN % -1000);
	AddTestCase('remx743:p9 r:HALF_UP (-NaN % -1) invalid_operation', -NaN, -NaN % -1);
	AddTestCase('remx744:p9 r:HALF_UP (NaN % -0) invalid_operation', NaN, NaN % -0);
	AddTestCase('remx745:p9 r:HALF_UP (NaN % 0) invalid_operation', NaN, NaN % 0);
	AddTestCase('remx746:p9 r:HALF_UP (NaN % 1) invalid_operation', NaN, NaN % 1);
	AddTestCase('remx747:p9 r:HALF_UP (NaN % 1000) invalid_operation', NaN, NaN % 1000);
	AddTestCase('remx749:p9 r:HALF_UP (NaN % NaN) invalid_operation', NaN, NaN % NaN);
	AddTestCase('remx750:p9 r:HALF_UP (NaN % NaN) invalid_operation', NaN, NaN % NaN);
	AddTestCase('remx751:p9 r:HALF_UP (NaN % NaN) invalid_operation', NaN, NaN % NaN);
	AddTestCase('remx752:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY % NaN) invalid_operation', NaN, decimal.NEGATIVE_INFINITY % NaN);
	AddTestCase('remx753:p9 r:HALF_UP (-1000 % NaN) invalid_operation', NaN, -1000 % NaN);
	AddTestCase('remx754:p9 r:HALF_UP (-1 % NaN) invalid_operation', NaN, -1 % NaN);
	AddTestCase('remx755:p9 r:HALF_UP (-0 % NaN) invalid_operation', NaN, -0 % NaN);
	AddTestCase('remx756:p9 r:HALF_UP (0 % NaN) invalid_operation', NaN, 0 % NaN);
	AddTestCase('remx757:p9 r:HALF_UP (1 % NaN) invalid_operation', NaN, 1 % NaN);
	AddTestCase('remx758:p9 r:HALF_UP (1000 % NaN) invalid_operation', NaN, 1000 % NaN);
	AddTestCase('remx759:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % -NaN) invalid_operation', -NaN, decimal.POSITIVE_INFINITY % -NaN);
	// propaging nans
	AddTestCase('remx760:p9 r:HALF_UP (NaN % NaN)', NaN, NaN % NaN);
	AddTestCase('remx761:p9 r:HALF_UP (NaN % NaN) invalid_operation', NaN, NaN % NaN);
	AddTestCase('remx762:p9 r:HALF_UP (NaN % NaN) invalid_operation', NaN, NaN % NaN);
	AddTestCase('remx763:p9 r:HALF_UP (NaN % NaN) invalid_operation', NaN, NaN % NaN);
	AddTestCase('remx764:p9 r:HALF_UP (15 % NaN)', NaN, 15 % NaN);
	AddTestCase('remx765:p9 r:HALF_UP (NaN % NaN)', NaN, NaN % NaN);
	AddTestCase('remx766:p9 r:HALF_UP (decimal.POSITIVE_INFINITY % NaN)', NaN, decimal.POSITIVE_INFINITY % NaN);
	AddTestCase('remx767:p9 r:HALF_UP (NaN % decimal.NEGATIVE_INFINITY)', NaN, NaN % decimal.NEGATIVE_INFINITY);
	AddTestCase('remx768:p9 r:HALF_UP (0 % NaN)', NaN, 0 % NaN);
	AddTestCase('remx769:p9 r:HALF_UP (NaN % -0)', NaN, NaN % -0);
	// test some cases that are close to exponent overflow
	AddTestCase('remx770:p9 r:HALF_UP (1 % 1e999999999)', 1, 1 % 1e999999999);
	AddTestCase('remx771:p9 r:HALF_UP (1 % 0.9e999999999)', 1, 1 % 0.9e999999999);
	AddTestCase('remx772:p9 r:HALF_UP (1 % 0.99e999999999)', 1, 1 % 0.99e999999999);
	AddTestCase('remx773:p9 r:HALF_UP (1 % 0.999999999e999999999)', 1, 1 % 0.999999999e999999999);
	AddTestCase('remx774:p9 r:HALF_UP (9e999999999 % 1) division_impossible', NaN, 9e999999999 % 1);
	AddTestCase('remx775:p9 r:HALF_UP (9.9e999999999 % 1) division_impossible', NaN, 9.9e999999999 % 1);
	AddTestCase('remx776:p9 r:HALF_UP (9.99e999999999 % 1) division_impossible', NaN, 9.99e999999999 % 1);
	AddTestCase('remx777:p9 r:HALF_UP (9.99999999e999999999 % 1) division_impossible', NaN, 9.99999999e999999999 % 1);
	// long operand checks
}
{
	use precision 9;
	AddTestCase('remx801:p9 r:HALF_UP (12345678000 % 100)', 0, 12345678000 % 100);
	AddTestCase('remx802:p9 r:HALF_UP (1 % 12345678000)', 1, 1 % 12345678000);
	AddTestCase('remx803:p9 r:HALF_UP (1234567800 % 10)', 0, 1234567800 % 10);
	AddTestCase('remx804:p9 r:HALF_UP (1 % 1234567800)', 1, 1 % 1234567800);
	AddTestCase('remx805:p9 r:HALF_UP (1234567890 % 10)', 0, 1234567890 % 10);
	AddTestCase('remx806:p9 r:HALF_UP (1 % 1234567890)', 1, 1 % 1234567890);
	AddTestCase('remx807:p9 r:HALF_UP (1234567891 % 10)', 1, 1234567891 % 10);
	AddTestCase('remx808:p9 r:HALF_UP (1 % 1234567891)', 1, 1 % 1234567891);
	AddTestCase('remx809:p9 r:HALF_UP (12345678901 % 100)', 1, 12345678901 % 100);
	AddTestCase('remx810:p9 r:HALF_UP (1 % 12345678901)', 1, 1 % 12345678901);
	AddTestCase('remx811:p9 r:HALF_UP (1234567896 % 10)', 6, 1234567896 % 10);
	AddTestCase('remx812:p9 r:HALF_UP (1 % 1234567896)', 1, 1 % 1234567896);
}
{
	use precision 15;
	AddTestCase('remx821:p15 r:HALF_UP (12345678000 % 100)', 0, 12345678000 % 100);
	AddTestCase('remx822:p15 r:HALF_UP (1 % 12345678000)', 1, 1 % 12345678000);
	AddTestCase('remx823:p15 r:HALF_UP (1234567800 % 10)', 0, 1234567800 % 10);
	AddTestCase('remx824:p15 r:HALF_UP (1 % 1234567800)', 1, 1 % 1234567800);
	AddTestCase('remx825:p15 r:HALF_UP (1234567890 % 10)', 0, 1234567890 % 10);
	AddTestCase('remx826:p15 r:HALF_UP (1 % 1234567890)', 1, 1 % 1234567890);
	AddTestCase('remx827:p15 r:HALF_UP (1234567891 % 10)', 1, 1234567891 % 10);
	AddTestCase('remx828:p15 r:HALF_UP (1 % 1234567891)', 1, 1 % 1234567891);
	AddTestCase('remx829:p15 r:HALF_UP (12345678901 % 100)', 1, 12345678901 % 100);
	AddTestCase('remx830:p15 r:HALF_UP (1 % 12345678901)', 1, 1 % 12345678901);
	AddTestCase('remx831:p15 r:HALF_UP (1234567896 % 10)', 6, 1234567896 % 10);
	AddTestCase('remx832:p15 r:HALF_UP (1 % 1234567896)', 1, 1 % 1234567896);
	// worries from divideint
}
{
	use precision 8;
	AddTestCase('remx840:p8 r:HALF_UP (100000000.0 % 1) ', 0, 100000000.0 % 1);
	AddTestCase('remx841:p8 r:HALF_UP (100000000.4 % 1) ', 0.4, 100000000.4 % 1);
	AddTestCase('remx842:p8 r:HALF_UP (100000000.5 % 1) ', 0.5, 100000000.5 % 1);
	AddTestCase('remx843:p8 r:HALF_UP (100000000.9 % 1) ', 0.9, 100000000.9 % 1);
	AddTestCase('remx844:p8 r:HALF_UP (100000000.999 % 1) ', 0.999, 100000000.999 % 1);
}
{
	use precision 6;
	AddTestCase('remx850:p6 r:HALF_UP (100000003 % 5) ', 3, 100000003 % 5);
	AddTestCase('remx851:p6 r:HALF_UP (10000003 % 5) ', 3, 10000003 % 5);
	AddTestCase('remx852:p6 r:HALF_UP (1000003 % 5)', 3, 1000003 % 5);
	AddTestCase('remx853:p6 r:HALF_UP (100003 % 5)', 3, 100003 % 5);
	AddTestCase('remx854:p6 r:HALF_UP (10003 % 5)', 3, 10003 % 5);
	AddTestCase('remx855:p6 r:HALF_UP (1003 % 5)', 3, 1003 % 5);
	AddTestCase('remx856:p6 r:HALF_UP (103 % 5)', 3, 103 % 5);
	AddTestCase('remx857:p6 r:HALF_UP (13 % 5)', 3, 13 % 5);
	AddTestCase('remx858:p6 r:HALF_UP (1 % 5)', 1, 1 % 5);
	// vladimir's cases
	AddTestCase('remx860:p6 r:HALF_UP (123.0e1 % 10000000000000000)', 1230, 123.0e1 % 10000000000000000);
	AddTestCase('remx861:p6 r:HALF_UP (1230 % 10000000000000000)', 1230, 1230 % 10000000000000000);
	AddTestCase('remx862:p6 r:HALF_UP (12.3e2 % 10000000000000000)', 1230, 12.3e2 % 10000000000000000);
	AddTestCase('remx863:p6 r:HALF_UP (1.23e3 % 10000000000000000)', 1230, 1.23e3 % 10000000000000000);
	AddTestCase('remx864:p6 r:HALF_UP (123e1 % 10000000000000000)', 1230, 123e1 % 10000000000000000);
	AddTestCase('remx870:p6 r:HALF_UP (123e1 % 1000000000000000)', 1230, 123e1 % 1000000000000000);
	AddTestCase('remx871:p6 r:HALF_UP (123e1 % 100000000000000)', 1230, 123e1 % 100000000000000);
	AddTestCase('remx872:p6 r:HALF_UP (123e1 % 10000000000000)', 1230, 123e1 % 10000000000000);
	AddTestCase('remx873:p6 r:HALF_UP (123e1 % 1000000000000)', 1230, 123e1 % 1000000000000);
	AddTestCase('remx874:p6 r:HALF_UP (123e1 % 100000000000)', 1230, 123e1 % 100000000000);
	AddTestCase('remx875:p6 r:HALF_UP (123e1 % 10000000000)', 1230, 123e1 % 10000000000);
	AddTestCase('remx876:p6 r:HALF_UP (123e1 % 1000000000)', 1230, 123e1 % 1000000000);
	AddTestCase('remx877:p6 r:HALF_UP (123e1 % 100000000)', 1230, 123e1 % 100000000);
	AddTestCase('remx878:p6 r:HALF_UP (1230 % 100000000)', 1230, 1230 % 100000000);
	AddTestCase('remx879:p6 r:HALF_UP (123e1 % 10000000)', 1230, 123e1 % 10000000);
	AddTestCase('remx880:p6 r:HALF_UP (123e1 % 1000000)', 1230, 123e1 % 1000000);
	AddTestCase('remx881:p6 r:HALF_UP (123e1 % 100000)', 1230, 123e1 % 100000);
	AddTestCase('remx882:p6 r:HALF_UP (123e1 % 10000)', 1230, 123e1 % 10000);
	AddTestCase('remx883:p6 r:HALF_UP (123e1 % 1000)', 230, 123e1 % 1000);
	AddTestCase('remx884:p6 r:HALF_UP (123e1 % 100)', 30, 123e1 % 100);
	AddTestCase('remx885:p6 r:HALF_UP (123e1 % 10)', 0, 123e1 % 10);
	AddTestCase('remx886:p6 r:HALF_UP (123e1 % 1)', 0, 123e1 % 1);
	AddTestCase('remx889:p6 r:HALF_UP (123e1 % 20000000000000000)', 1230, 123e1 % 20000000000000000);
	AddTestCase('remx890:p6 r:HALF_UP (123e1 % 2000000000000000)', 1230, 123e1 % 2000000000000000);
	AddTestCase('remx891:p6 r:HALF_UP (123e1 % 200000000000000)', 1230, 123e1 % 200000000000000);
	AddTestCase('remx892:p6 r:HALF_UP (123e1 % 20000000000000)', 1230, 123e1 % 20000000000000);
	AddTestCase('remx893:p6 r:HALF_UP (123e1 % 2000000000000)', 1230, 123e1 % 2000000000000);
	AddTestCase('remx894:p6 r:HALF_UP (123e1 % 200000000000)', 1230, 123e1 % 200000000000);
	AddTestCase('remx895:p6 r:HALF_UP (123e1 % 20000000000)', 1230, 123e1 % 20000000000);
	AddTestCase('remx896:p6 r:HALF_UP (123e1 % 2000000000)', 1230, 123e1 % 2000000000);
	AddTestCase('remx897:p6 r:HALF_UP (123e1 % 200000000)', 1230, 123e1 % 200000000);
	AddTestCase('remx899:p6 r:HALF_UP (123e1 % 20000000)', 1230, 123e1 % 20000000);
	AddTestCase('remx900:p6 r:HALF_UP (123e1 % 2000000)', 1230, 123e1 % 2000000);
	AddTestCase('remx901:p6 r:HALF_UP (123e1 % 200000)', 1230, 123e1 % 200000);
	AddTestCase('remx902:p6 r:HALF_UP (123e1 % 20000)', 1230, 123e1 % 20000);
	AddTestCase('remx903:p6 r:HALF_UP (123e1 % 2000)', 1230, 123e1 % 2000);
	AddTestCase('remx904:p6 r:HALF_UP (123e1 % 200)', 30, 123e1 % 200);
	AddTestCase('remx905:p6 r:HALF_UP (123e1 % 20)', 10, 123e1 % 20);
	AddTestCase('remx906:p6 r:HALF_UP (123e1 % 2)', 0, 123e1 % 2);
	AddTestCase('remx909:p6 r:HALF_UP (123e1 % 50000000000000000)', 1230, 123e1 % 50000000000000000);
	AddTestCase('remx910:p6 r:HALF_UP (123e1 % 5000000000000000)', 1230, 123e1 % 5000000000000000);
	AddTestCase('remx911:p6 r:HALF_UP (123e1 % 500000000000000)', 1230, 123e1 % 500000000000000);
	AddTestCase('remx912:p6 r:HALF_UP (123e1 % 50000000000000)', 1230, 123e1 % 50000000000000);
	AddTestCase('remx913:p6 r:HALF_UP (123e1 % 5000000000000)', 1230, 123e1 % 5000000000000);
	AddTestCase('remx914:p6 r:HALF_UP (123e1 % 500000000000)', 1230, 123e1 % 500000000000);
	AddTestCase('remx915:p6 r:HALF_UP (123e1 % 50000000000)', 1230, 123e1 % 50000000000);
	AddTestCase('remx916:p6 r:HALF_UP (123e1 % 5000000000)', 1230, 123e1 % 5000000000);
	AddTestCase('remx917:p6 r:HALF_UP (123e1 % 500000000)', 1230, 123e1 % 500000000);
	AddTestCase('remx919:p6 r:HALF_UP (123e1 % 50000000)', 1230, 123e1 % 50000000);
	AddTestCase('remx920:p6 r:HALF_UP (123e1 % 5000000)', 1230, 123e1 % 5000000);
	AddTestCase('remx921:p6 r:HALF_UP (123e1 % 500000)', 1230, 123e1 % 500000);
	AddTestCase('remx922:p6 r:HALF_UP (123e1 % 50000)', 1230, 123e1 % 50000);
	AddTestCase('remx923:p6 r:HALF_UP (123e1 % 5000)', 1230, 123e1 % 5000);
	AddTestCase('remx924:p6 r:HALF_UP (123e1 % 500)', 230, 123e1 % 500);
	AddTestCase('remx925:p6 r:HALF_UP (123e1 % 50)', 30, 123e1 % 50);
	AddTestCase('remx926:p6 r:HALF_UP (123e1 % 5)', 0, 123e1 % 5);
	AddTestCase('remx929:p6 r:HALF_UP (123e1 % 90000000000000000)', 1230, 123e1 % 90000000000000000);
	AddTestCase('remx930:p6 r:HALF_UP (123e1 % 9000000000000000)', 1230, 123e1 % 9000000000000000);
	AddTestCase('remx931:p6 r:HALF_UP (123e1 % 900000000000000)', 1230, 123e1 % 900000000000000);
	AddTestCase('remx932:p6 r:HALF_UP (123e1 % 90000000000000)', 1230, 123e1 % 90000000000000);
	AddTestCase('remx933:p6 r:HALF_UP (123e1 % 9000000000000)', 1230, 123e1 % 9000000000000);
	AddTestCase('remx934:p6 r:HALF_UP (123e1 % 900000000000)', 1230, 123e1 % 900000000000);
	AddTestCase('remx935:p6 r:HALF_UP (123e1 % 90000000000)', 1230, 123e1 % 90000000000);
	AddTestCase('remx936:p6 r:HALF_UP (123e1 % 9000000000)', 1230, 123e1 % 9000000000);
	AddTestCase('remx937:p6 r:HALF_UP (123e1 % 900000000)', 1230, 123e1 % 900000000);
	AddTestCase('remx939:p6 r:HALF_UP (123e1 % 90000000)', 1230, 123e1 % 90000000);
	AddTestCase('remx940:p6 r:HALF_UP (123e1 % 9000000)', 1230, 123e1 % 9000000);
	AddTestCase('remx941:p6 r:HALF_UP (123e1 % 900000)', 1230, 123e1 % 900000);
	AddTestCase('remx942:p6 r:HALF_UP (123e1 % 90000)', 1230, 123e1 % 90000);
	AddTestCase('remx943:p6 r:HALF_UP (123e1 % 9000)', 1230, 123e1 % 9000);
	AddTestCase('remx944:p6 r:HALF_UP (123e1 % 900)', 330, 123e1 % 900);
	AddTestCase('remx945:p6 r:HALF_UP (123e1 % 90)', 60, 123e1 % 90);
	AddTestCase('remx946:p6 r:HALF_UP (123e1 % 9)', 6, 123e1 % 9);
	AddTestCase('remx950:p6 r:HALF_UP (123e1 % 10000000000000000)', 1230, 123e1 % 10000000000000000);
	AddTestCase('remx951:p6 r:HALF_UP (123e1 % 100000000000000000)', 1230, 123e1 % 100000000000000000);
	AddTestCase('remx952:p6 r:HALF_UP (123e1 % 1000000000000000000)', 1230, 123e1 % 1000000000000000000);
	AddTestCase('remx953:p6 r:HALF_UP (123e1 % 10000000000000000000)', 1230, 123e1 % 10000000000000000000);
	AddTestCase('remx954:p6 r:HALF_UP (123e1 % 100000000000000000000)', 1230, 123e1 % 100000000000000000000);
	AddTestCase('remx955:p6 r:HALF_UP (123e1 % 1000000000000000000000)', 1230, 123e1 % 1000000000000000000000);
	AddTestCase('remx956:p6 r:HALF_UP (123e1 % 10000000000000000000000)', 1230, 123e1 % 10000000000000000000000);
	AddTestCase('remx957:p6 r:HALF_UP (123e1 % 100000000000000000000000)', 1230, 123e1 % 100000000000000000000000);
	AddTestCase('remx958:p6 r:HALF_UP (123e1 % 1000000000000000000000000)', 1230, 123e1 % 1000000000000000000000000);
	AddTestCase('remx959:p6 r:HALF_UP (123e1 % 10000000000000000000000000)', 1230, 123e1 % 10000000000000000000000000);
	AddTestCase('remx960:p6 r:HALF_UP (123e1 % 19999999999999999)', 1230, 123e1 % 19999999999999999);
	AddTestCase('remx961:p6 r:HALF_UP (123e1 % 199999999999999990)', 1230, 123e1 % 199999999999999990);
	AddTestCase('remx962:p6 r:HALF_UP (123e1 % 1999999999999999999)', 1230, 123e1 % 1999999999999999999);
	AddTestCase('remx963:p6 r:HALF_UP (123e1 % 19999999999999999990)', 1230, 123e1 % 19999999999999999990);
	AddTestCase('remx964:p6 r:HALF_UP (123e1 % 199999999999999999999)', 1230, 123e1 % 199999999999999999999);
	AddTestCase('remx965:p6 r:HALF_UP (123e1 % 1999999999999999999990)', 1230, 123e1 % 1999999999999999999990);
	AddTestCase('remx966:p6 r:HALF_UP (123e1 % 19999999999999999999999)', 1230, 123e1 % 19999999999999999999999);
	AddTestCase('remx967:p6 r:HALF_UP (123e1 % 199999999999999999999990)', 1230, 123e1 % 199999999999999999999990);
	AddTestCase('remx968:p6 r:HALF_UP (123e1 % 1999999999999999999999999)', 1230, 123e1 % 1999999999999999999999999);
	AddTestCase('remx969:p6 r:HALF_UP (123e1 % 19999999999999999999999990)', 1230, 123e1 % 19999999999999999999999990);
	AddTestCase('remx970:p6 r:HALF_UP (1e1 % 10000000000000000)', 10, 1e1 % 10000000000000000);
	AddTestCase('remx971:p6 r:HALF_UP (1e1 % 100000000000000000)', 10, 1e1 % 100000000000000000);
	AddTestCase('remx972:p6 r:HALF_UP (1e1 % 1000000000000000000)', 10, 1e1 % 1000000000000000000);
	AddTestCase('remx973:p6 r:HALF_UP (1e1 % 10000000000000000000)', 10, 1e1 % 10000000000000000000);
	AddTestCase('remx974:p6 r:HALF_UP (1e1 % 100000000000000000000)', 10, 1e1 % 100000000000000000000);
	AddTestCase('remx975:p6 r:HALF_UP (1e1 % 1000000000000000000000)', 10, 1e1 % 1000000000000000000000);
	AddTestCase('remx976:p6 r:HALF_UP (1e1 % 10000000000000000000000)', 10, 1e1 % 10000000000000000000000);
	AddTestCase('remx977:p6 r:HALF_UP (1e1 % 100000000000000000000000)', 10, 1e1 % 100000000000000000000000);
	AddTestCase('remx978:p6 r:HALF_UP (1e1 % 1000000000000000000000000)', 10, 1e1 % 1000000000000000000000000);
	AddTestCase('remx979:p6 r:HALF_UP (1e1 % 10000000000000000000000000)', 10, 1e1 % 10000000000000000000000000);
	AddTestCase('remx980:p6 r:HALF_UP (123e1 % 1000e999999) -- 123e+1 internally', 1.23e+3, 123e1 % 1000e999999);
	// overflow and underflow tests [from divide]
}
{
	use precision 9;
	AddTestCase('remx990:p9 r:HALF_UP (+1.23456789012345e-0 % 9e+999999999) inexact rounded', 1.23456789, +1.23456789012345e-0 % 9e+999999999);
	AddTestCase('remx991:p9 r:HALF_UP (9e+999999999 % +0.23456789012345e-0) division_impossible', NaN, 9e+999999999 % +0.23456789012345e-0);
	AddTestCase('remx992:p9 r:HALF_UP (+0.100 % 9e+999999999)', 0.100, +0.100 % 9e+999999999);
	AddTestCase('remx993:p9 r:HALF_UP (9e-999999999 % +9.100)', 9e-999999999, 9e-999999999 % +9.100);
	AddTestCase('remx995:p9 r:HALF_UP (-1.23456789012345e-0 % 9e+999999999) inexact rounded', -1.23456789, -1.23456789012345e-0 % 9e+999999999);
	AddTestCase('remx996:p9 r:HALF_UP (9e+999999999 % -0.83456789012345e-0) division_impossible', NaN, 9e+999999999 % -0.83456789012345e-0);
	AddTestCase('remx997:p9 r:HALF_UP (-0.100 % 9e+999999999)', -0.100, -0.100 % 9e+999999999);
	AddTestCase('remx998:p9 r:HALF_UP (9e-999999999 % -9.100)', 9e-999999999, 9e-999999999 % -9.100);
	// null tests
	AddTestCase('remx1000:p9 r:HALF_UP (10 % null) invalid_operation', NaN, 10 % null);
	AddTestCase('remx1001:p9 r:HALF_UP (null % 10) invalid_operation', 0, null % 10);
	}
}
test();
