use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "dqDivide.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// dqdivide.dectest -- decquad division                               --
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
use rounding HALF_EVEN;
// sanity checks
AddTestCase("dqdiv001:p9 r:HALF_EVEN (1 / 1)", 1, 1 / 1);
AddTestCase("dqdiv002:p9 r:HALF_EVEN (2 / 1)", 2, 2 / 1);
AddTestCase("dqdiv003:p9 r:HALF_EVEN (1 / 2)", 0.5, 1 / 2);
AddTestCase("dqdiv004:p9 r:HALF_EVEN (2 / 2)", 1, 2 / 2);
AddTestCase("dqdiv005:p9 r:HALF_EVEN (0 / 1)", 0, 0 / 1);
AddTestCase("dqdiv006:p9 r:HALF_EVEN (0 / 2)", 0, 0 / 2);
AddTestCase("dqdiv007:p9 r:HALF_EVEN (1 / 3) inexact rounded", 0.3333333333333333333333333333333333, 1 / 3);
AddTestCase("dqdiv008:p9 r:HALF_EVEN (2 / 3) inexact rounded", 0.6666666666666666666666666666666667, 2 / 3);
AddTestCase("dqdiv009:p9 r:HALF_EVEN (3 / 3)", 1, 3 / 3);
AddTestCase("dqdiv010:p9 r:HALF_EVEN (2.4 / 1)", 2.4, 2.4 / 1);
AddTestCase("dqdiv011:p9 r:HALF_EVEN (2.4 / -1)", -2.4, 2.4 / -1);
AddTestCase("dqdiv012:p9 r:HALF_EVEN (-2.4 / 1)", -2.4, -2.4 / 1);
AddTestCase("dqdiv013:p9 r:HALF_EVEN (-2.4 / -1)", 2.4, -2.4 / -1);
AddTestCase("dqdiv014:p9 r:HALF_EVEN (2.40 / 1)", 2.40, 2.40 / 1);
AddTestCase("dqdiv015:p9 r:HALF_EVEN (2.400 / 1)", 2.400, 2.400 / 1);
AddTestCase("dqdiv016:p9 r:HALF_EVEN (2.4 / 2)", 1.2, 2.4 / 2);
AddTestCase("dqdiv017:p9 r:HALF_EVEN (2.400 / 2)", 1.200, 2.400 / 2);
AddTestCase("dqdiv018:p9 r:HALF_EVEN (2. / 2)", 1, 2. / 2);
AddTestCase("dqdiv019:p9 r:HALF_EVEN (20 / 20)", 1, 20 / 20);
AddTestCase("dqdiv020:p9 r:HALF_EVEN (187 / 187)", 1, 187 / 187);
AddTestCase("dqdiv021:p9 r:HALF_EVEN (5 / 2)", 2.5, 5 / 2);
AddTestCase("dqdiv022:p9 r:HALF_EVEN (50 / 20)", 2.5, 50 / 20);
AddTestCase("dqdiv023:p9 r:HALF_EVEN (500 / 200)", 2.5, 500 / 200);
AddTestCase("dqdiv024:p9 r:HALF_EVEN (50.0 / 20.0)", 2.5, 50.0 / 20.0);
AddTestCase("dqdiv025:p9 r:HALF_EVEN (5.00 / 2.00)", 2.5, 5.00 / 2.00);
AddTestCase("dqdiv026:p9 r:HALF_EVEN (5 / 2.0)", 2.5, 5 / 2.0);
AddTestCase("dqdiv027:p9 r:HALF_EVEN (5 / 2.000)", 2.5, 5 / 2.000);
AddTestCase("dqdiv028:p9 r:HALF_EVEN (5 / 0.20)", 25, 5 / 0.20);
AddTestCase("dqdiv029:p9 r:HALF_EVEN (5 / 0.200)", 25, 5 / 0.200);
AddTestCase("dqdiv030:p9 r:HALF_EVEN (10 / 1)", 10, 10 / 1);
AddTestCase("dqdiv031:p9 r:HALF_EVEN (100 / 1)", 100, 100 / 1);
AddTestCase("dqdiv032:p9 r:HALF_EVEN (1000 / 1)", 1000, 1000 / 1);
AddTestCase("dqdiv033:p9 r:HALF_EVEN (1000 / 100)", 10, 1000 / 100);
AddTestCase("dqdiv035:p9 r:HALF_EVEN (1 / 2)", 0.5, 1 / 2);
AddTestCase("dqdiv036:p9 r:HALF_EVEN (1 / 4)", 0.25, 1 / 4);
AddTestCase("dqdiv037:p9 r:HALF_EVEN (1 / 8)", 0.125, 1 / 8);
AddTestCase("dqdiv038:p9 r:HALF_EVEN (1 / 16)", 0.0625, 1 / 16);
AddTestCase("dqdiv039:p9 r:HALF_EVEN (1 / 32)", 0.03125, 1 / 32);
AddTestCase("dqdiv040:p9 r:HALF_EVEN (1 / 64)", 0.015625, 1 / 64);
AddTestCase("dqdiv041:p9 r:HALF_EVEN (1 / -2)", -0.5, 1 / -2);
AddTestCase("dqdiv042:p9 r:HALF_EVEN (1 / -4)", -0.25, 1 / -4);
AddTestCase("dqdiv043:p9 r:HALF_EVEN (1 / -8)", -0.125, 1 / -8);
AddTestCase("dqdiv044:p9 r:HALF_EVEN (1 / -16)", -0.0625, 1 / -16);
AddTestCase("dqdiv045:p9 r:HALF_EVEN (1 / -32)", -0.03125, 1 / -32);
AddTestCase("dqdiv046:p9 r:HALF_EVEN (1 / -64)", -0.015625, 1 / -64);
AddTestCase("dqdiv047:p9 r:HALF_EVEN (-1 / 2)", -0.5, -1 / 2);
AddTestCase("dqdiv048:p9 r:HALF_EVEN (-1 / 4)", -0.25, -1 / 4);
AddTestCase("dqdiv049:p9 r:HALF_EVEN (-1 / 8)", -0.125, -1 / 8);
AddTestCase("dqdiv050:p9 r:HALF_EVEN (-1 / 16)", -0.0625, -1 / 16);
AddTestCase("dqdiv051:p9 r:HALF_EVEN (-1 / 32)", -0.03125, -1 / 32);
AddTestCase("dqdiv052:p9 r:HALF_EVEN (-1 / 64)", -0.015625, -1 / 64);
AddTestCase("dqdiv053:p9 r:HALF_EVEN (-1 / -2)", 0.5, -1 / -2);
AddTestCase("dqdiv054:p9 r:HALF_EVEN (-1 / -4)", 0.25, -1 / -4);
AddTestCase("dqdiv055:p9 r:HALF_EVEN (-1 / -8)", 0.125, -1 / -8);
AddTestCase("dqdiv056:p9 r:HALF_EVEN (-1 / -16)", 0.0625, -1 / -16);
AddTestCase("dqdiv057:p9 r:HALF_EVEN (-1 / -32)", 0.03125, -1 / -32);
AddTestCase("dqdiv058:p9 r:HALF_EVEN (-1 / -64)", 0.015625, -1 / -64);
// bcdtime
AddTestCase("dqdiv060:p9 r:HALF_EVEN (1 / 7) inexact rounded", 0.1428571428571428571428571428571429, 1 / 7);
AddTestCase("dqdiv061:p9 r:HALF_EVEN (1.2345678 / 1.9876543) inexact rounded", 0.6211179680490717123193907511985359, 1.2345678 / 1.9876543);
//               1234567890123456
AddTestCase("dqdiv067:p9 r:HALF_EVEN (9999999999999999999999999999999999 / 1)", 9999999999999999999999999999999999, 9999999999999999999999999999999999 / 1);
AddTestCase("dqdiv068:p9 r:HALF_EVEN (999999999999999999999999999999999 / 1)", 999999999999999999999999999999999, 999999999999999999999999999999999 / 1);
AddTestCase("dqdiv069:p9 r:HALF_EVEN (99999999999999999999999999999999 / 1)", 99999999999999999999999999999999, 99999999999999999999999999999999 / 1);
AddTestCase("dqdiv070:p9 r:HALF_EVEN (99999999999999999 / 1)", 99999999999999999, 99999999999999999 / 1);
AddTestCase("dqdiv071:p9 r:HALF_EVEN (9999999999999999 / 1)", 9999999999999999, 9999999999999999 / 1);
AddTestCase("dqdiv072:p9 r:HALF_EVEN (999999999999999 / 1)", 999999999999999, 999999999999999 / 1);
AddTestCase("dqdiv073:p9 r:HALF_EVEN (99999999999999 / 1)", 99999999999999, 99999999999999 / 1);
AddTestCase("dqdiv074:p9 r:HALF_EVEN (9999999999999 / 1)", 9999999999999, 9999999999999 / 1);
AddTestCase("dqdiv075:p9 r:HALF_EVEN (999999999999 / 1)", 999999999999, 999999999999 / 1);
AddTestCase("dqdiv076:p9 r:HALF_EVEN (99999999999 / 1)", 99999999999, 99999999999 / 1);
AddTestCase("dqdiv077:p9 r:HALF_EVEN (9999999999 / 1)", 9999999999, 9999999999 / 1);
AddTestCase("dqdiv078:p9 r:HALF_EVEN (999999999 / 1)", 999999999, 999999999 / 1);
AddTestCase("dqdiv079:p9 r:HALF_EVEN (99999999 / 1)", 99999999, 99999999 / 1);
AddTestCase("dqdiv080:p9 r:HALF_EVEN (9999999 / 1)", 9999999, 9999999 / 1);
AddTestCase("dqdiv081:p9 r:HALF_EVEN (999999 / 1)", 999999, 999999 / 1);
AddTestCase("dqdiv082:p9 r:HALF_EVEN (99999 / 1)", 99999, 99999 / 1);
AddTestCase("dqdiv083:p9 r:HALF_EVEN (9999 / 1)", 9999, 9999 / 1);
AddTestCase("dqdiv084:p9 r:HALF_EVEN (999 / 1)", 999, 999 / 1);
AddTestCase("dqdiv085:p9 r:HALF_EVEN (99 / 1)", 99, 99 / 1);
AddTestCase("dqdiv086:p9 r:HALF_EVEN (9 / 1)", 9, 9 / 1);
AddTestCase("dqdiv090:p9 r:HALF_EVEN (0. / 1)", 0, 0. / 1);
AddTestCase("dqdiv091:p9 r:HALF_EVEN (.0 / 1)", 0.0, .0 / 1);
AddTestCase("dqdiv092:p9 r:HALF_EVEN (0.00 / 1)", 0.00, 0.00 / 1);
AddTestCase("dqdiv093:p9 r:HALF_EVEN (0.00e+9 / 1)", 0e+7, 0.00e+9 / 1);
AddTestCase("dqdiv094:p9 r:HALF_EVEN (0.0000e-50 / 1)", 0e-54, 0.0000e-50 / 1);
AddTestCase("dqdiv095:p9 r:HALF_EVEN (1 / 1e-8)", 1e+8, 1 / 1e-8);
AddTestCase("dqdiv096:p9 r:HALF_EVEN (1 / 1e-9)", 1e+9, 1 / 1e-9);
AddTestCase("dqdiv097:p9 r:HALF_EVEN (1 / 1e-10)", 1e+10, 1 / 1e-10);
AddTestCase("dqdiv098:p9 r:HALF_EVEN (1 / 1e-11)", 1e+11, 1 / 1e-11);
AddTestCase("dqdiv099:p9 r:HALF_EVEN (1 / 1e-12)", 1e+12, 1 / 1e-12);
AddTestCase("dqdiv100:p9 r:HALF_EVEN (1 / 1)", 1, 1 / 1);
AddTestCase("dqdiv101:p9 r:HALF_EVEN (1 / 2)", 0.5, 1 / 2);
AddTestCase("dqdiv102:p9 r:HALF_EVEN (1 / 3) inexact rounded", 0.3333333333333333333333333333333333, 1 / 3);
AddTestCase("dqdiv103:p9 r:HALF_EVEN (1 / 4)", 0.25, 1 / 4);
AddTestCase("dqdiv104:p9 r:HALF_EVEN (1 / 5)", 0.2, 1 / 5);
AddTestCase("dqdiv105:p9 r:HALF_EVEN (1 / 6) inexact rounded", 0.1666666666666666666666666666666667, 1 / 6);
AddTestCase("dqdiv106:p9 r:HALF_EVEN (1 / 7) inexact rounded", 0.1428571428571428571428571428571429, 1 / 7);
AddTestCase("dqdiv107:p9 r:HALF_EVEN (1 / 8)", 0.125, 1 / 8);
AddTestCase("dqdiv108:p9 r:HALF_EVEN (1 / 9) inexact rounded", 0.1111111111111111111111111111111111, 1 / 9);
AddTestCase("dqdiv109:p9 r:HALF_EVEN (1 / 10)", 0.1, 1 / 10);
AddTestCase("dqdiv110:p9 r:HALF_EVEN (1 / 1)", 1, 1 / 1);
AddTestCase("dqdiv111:p9 r:HALF_EVEN (2 / 1)", 2, 2 / 1);
AddTestCase("dqdiv112:p9 r:HALF_EVEN (3 / 1)", 3, 3 / 1);
AddTestCase("dqdiv113:p9 r:HALF_EVEN (4 / 1)", 4, 4 / 1);
AddTestCase("dqdiv114:p9 r:HALF_EVEN (5 / 1)", 5, 5 / 1);
AddTestCase("dqdiv115:p9 r:HALF_EVEN (6 / 1)", 6, 6 / 1);
AddTestCase("dqdiv116:p9 r:HALF_EVEN (7 / 1)", 7, 7 / 1);
AddTestCase("dqdiv117:p9 r:HALF_EVEN (8 / 1)", 8, 8 / 1);
AddTestCase("dqdiv118:p9 r:HALF_EVEN (9 / 1)", 9, 9 / 1);
AddTestCase("dqdiv119:p9 r:HALF_EVEN (10 / 1)", 10, 10 / 1);
AddTestCase("dqdiv120:p9 r:HALF_EVEN (3e+1 / 0.001)", 3e+4, 3e+1 / 0.001);
AddTestCase("dqdiv121:p9 r:HALF_EVEN (2.200 / 2)", 1.100, 2.200 / 2);
AddTestCase("dqdiv130:p9 r:HALF_EVEN (12345 / 4.999) inexact rounded", 2469.493898779755951190238047609522, 12345 / 4.999);
AddTestCase("dqdiv131:p9 r:HALF_EVEN (12345 / 4.99) inexact rounded", 2473.947895791583166332665330661323, 12345 / 4.99);
AddTestCase("dqdiv132:p9 r:HALF_EVEN (12345 / 4.9) inexact rounded", 2519.387755102040816326530612244898, 12345 / 4.9);
AddTestCase("dqdiv133:p9 r:HALF_EVEN (12345 / 5)", 2469, 12345 / 5);
AddTestCase("dqdiv134:p9 r:HALF_EVEN (12345 / 5.1) inexact rounded", 2420.588235294117647058823529411765, 12345 / 5.1);
AddTestCase("dqdiv135:p9 r:HALF_EVEN (12345 / 5.01) inexact rounded", 2464.071856287425149700598802395210, 12345 / 5.01);
AddTestCase("dqdiv136:p9 r:HALF_EVEN (12345 / 5.001) inexact rounded", 2468.506298740251949610077984403119, 12345 / 5.001);
// test possibly imprecise results
AddTestCase("dqdiv220:p9 r:HALF_EVEN (391 / 597) inexact rounded", 0.6549413735343383584589614740368509, 391 / 597);
AddTestCase("dqdiv221:p9 r:HALF_EVEN (391 / -597) inexact rounded", -0.6549413735343383584589614740368509, 391 / -597);
AddTestCase("dqdiv222:p9 r:HALF_EVEN (-391 / 597) inexact rounded", -0.6549413735343383584589614740368509, -391 / 597);
AddTestCase("dqdiv223:p9 r:HALF_EVEN (-391 / -597) inexact rounded", 0.6549413735343383584589614740368509, -391 / -597);
// test some cases that are close to exponent overflow
AddTestCase("dqdiv279:p9 r:HALF_EVEN (9.999999999999999999999999999999999e6144 / 1)", 9.999999999999999999999999999999999e+6144, 9.999999999999999999999999999999999e6144 / 1);
// divide into 0 tests
AddTestCase("dqdiv301:p9 r:HALF_EVEN (0 / 7)", 0, 0 / 7);
AddTestCase("dqdiv302:p9 r:HALF_EVEN (0 / 7e-5)", 0e+5, 0 / 7e-5);
AddTestCase("dqdiv303:p9 r:HALF_EVEN (0 / 7e-1)", 0e+1, 0 / 7e-1);
AddTestCase("dqdiv304:p9 r:HALF_EVEN (0 / 7e+1)", 0.0, 0 / 7e+1);
AddTestCase("dqdiv305:p9 r:HALF_EVEN (0 / 7e+5)", 0.00000, 0 / 7e+5);
AddTestCase("dqdiv306:p9 r:HALF_EVEN (0 / 7e+6)", 0.000000, 0 / 7e+6);
AddTestCase("dqdiv307:p9 r:HALF_EVEN (0 / 7e+7)", 0e-7, 0 / 7e+7);
AddTestCase("dqdiv308:p9 r:HALF_EVEN (0 / 70e-5)", 0e+5, 0 / 70e-5);
AddTestCase("dqdiv309:p9 r:HALF_EVEN (0 / 70e-1)", 0e+1, 0 / 70e-1);
AddTestCase("dqdiv310:p9 r:HALF_EVEN (0 / 70e+0)", 0, 0 / 70e+0);
AddTestCase("dqdiv311:p9 r:HALF_EVEN (0 / 70e+1)", 0.0, 0 / 70e+1);
AddTestCase("dqdiv312:p9 r:HALF_EVEN (0 / 70e+5)", 0.00000, 0 / 70e+5);
AddTestCase("dqdiv313:p9 r:HALF_EVEN (0 / 70e+6)", 0.000000, 0 / 70e+6);
AddTestCase("dqdiv314:p9 r:HALF_EVEN (0 / 70e+7)", 0e-7, 0 / 70e+7);
AddTestCase("dqdiv315:p9 r:HALF_EVEN (0 / 700e-5)", 0e+5, 0 / 700e-5);
AddTestCase("dqdiv316:p9 r:HALF_EVEN (0 / 700e-1)", 0e+1, 0 / 700e-1);
AddTestCase("dqdiv317:p9 r:HALF_EVEN (0 / 700e+0)", 0, 0 / 700e+0);
AddTestCase("dqdiv318:p9 r:HALF_EVEN (0 / 700e+1)", 0.0, 0 / 700e+1);
AddTestCase("dqdiv319:p9 r:HALF_EVEN (0 / 700e+5)", 0.00000, 0 / 700e+5);
AddTestCase("dqdiv320:p9 r:HALF_EVEN (0 / 700e+6)", 0.000000, 0 / 700e+6);
AddTestCase("dqdiv321:p9 r:HALF_EVEN (0 / 700e+7)", 0e-7, 0 / 700e+7);
AddTestCase("dqdiv322:p9 r:HALF_EVEN (0 / 700e+77)", 0e-77, 0 / 700e+77);
AddTestCase("dqdiv331:p9 r:HALF_EVEN (0e-3 / 7e-5)", 0e+2, 0e-3 / 7e-5);
AddTestCase("dqdiv332:p9 r:HALF_EVEN (0e-3 / 7e-1)", 0.00, 0e-3 / 7e-1);
AddTestCase("dqdiv333:p9 r:HALF_EVEN (0e-3 / 7e+1)", 0.0000, 0e-3 / 7e+1);
AddTestCase("dqdiv334:p9 r:HALF_EVEN (0e-3 / 7e+5)", 0e-8, 0e-3 / 7e+5);
AddTestCase("dqdiv335:p9 r:HALF_EVEN (0e-1 / 7e-5)", 0e+4, 0e-1 / 7e-5);
AddTestCase("dqdiv336:p9 r:HALF_EVEN (0e-1 / 7e-1)", 0, 0e-1 / 7e-1);
AddTestCase("dqdiv337:p9 r:HALF_EVEN (0e-1 / 7e+1)", 0.00, 0e-1 / 7e+1);
AddTestCase("dqdiv338:p9 r:HALF_EVEN (0e-1 / 7e+5)", 0.000000, 0e-1 / 7e+5);
AddTestCase("dqdiv339:p9 r:HALF_EVEN (0e+1 / 7e-5)", 0e+6, 0e+1 / 7e-5);
AddTestCase("dqdiv340:p9 r:HALF_EVEN (0e+1 / 7e-1)", 0e+2, 0e+1 / 7e-1);
AddTestCase("dqdiv341:p9 r:HALF_EVEN (0e+1 / 7e+1)", 0, 0e+1 / 7e+1);
AddTestCase("dqdiv342:p9 r:HALF_EVEN (0e+1 / 7e+5)", 0.0000, 0e+1 / 7e+5);
AddTestCase("dqdiv343:p9 r:HALF_EVEN (0e+3 / 7e-5)", 0e+8, 0e+3 / 7e-5);
AddTestCase("dqdiv344:p9 r:HALF_EVEN (0e+3 / 7e-1)", 0e+4, 0e+3 / 7e-1);
AddTestCase("dqdiv345:p9 r:HALF_EVEN (0e+3 / 7e+1)", 0e+2, 0e+3 / 7e+1);
AddTestCase("dqdiv346:p9 r:HALF_EVEN (0e+3 / 7e+5)", 0.00, 0e+3 / 7e+5);
// these were 'input rounding'
AddTestCase("dqdiv441:p9 r:HALF_EVEN (12345678000 / 1)", 12345678000, 12345678000 / 1);
AddTestCase("dqdiv442:p9 r:HALF_EVEN (1 / 12345678000) inexact rounded", 8.100000664200054464404466081166219e-11, 1 / 12345678000);
AddTestCase("dqdiv443:p9 r:HALF_EVEN (1234567800 / 1)", 1234567800, 1234567800 / 1);
AddTestCase("dqdiv444:p9 r:HALF_EVEN (1 / 1234567800) inexact rounded", 8.100000664200054464404466081166219e-10, 1 / 1234567800);
AddTestCase("dqdiv445:p9 r:HALF_EVEN (1234567890 / 1)", 1234567890, 1234567890 / 1);
AddTestCase("dqdiv446:p9 r:HALF_EVEN (1 / 1234567890) inexact rounded", 8.100000073710000670761006103925156e-10, 1 / 1234567890);
AddTestCase("dqdiv447:p9 r:HALF_EVEN (1234567891 / 1)", 1234567891, 1234567891 / 1);
AddTestCase("dqdiv448:p9 r:HALF_EVEN (1 / 1234567891) inexact rounded", 8.100000067149000556665214614754629e-10, 1 / 1234567891);
AddTestCase("dqdiv449:p9 r:HALF_EVEN (12345678901 / 1)", 12345678901, 12345678901 / 1);
AddTestCase("dqdiv450:p9 r:HALF_EVEN (1 / 12345678901) inexact rounded", 8.100000073053900658873130042376760e-11, 1 / 12345678901);
AddTestCase("dqdiv451:p9 r:HALF_EVEN (1234567896 / 1)", 1234567896, 1234567896 / 1);
AddTestCase("dqdiv452:p9 r:HALF_EVEN (1 / 1234567896) inexact rounded", 8.100000034344000145618560617422697e-10, 1 / 1234567896);
// high-lows
AddTestCase("dqdiv453:p9 r:HALF_EVEN (1e+1 / 1)", 1e+1, 1e+1 / 1);
AddTestCase("dqdiv454:p9 r:HALF_EVEN (1e+1 / 1.0)", 1e+1, 1e+1 / 1.0);
AddTestCase("dqdiv455:p9 r:HALF_EVEN (1e+1 / 1.00)", 1e+1, 1e+1 / 1.00);
AddTestCase("dqdiv456:p9 r:HALF_EVEN (1e+2 / 2)", 5e+1, 1e+2 / 2);
AddTestCase("dqdiv457:p9 r:HALF_EVEN (1e+2 / 2.0)", 5e+1, 1e+2 / 2.0);
AddTestCase("dqdiv458:p9 r:HALF_EVEN (1e+2 / 2.00)", 5e+1, 1e+2 / 2.00);
// some from ieee discussions
AddTestCase("dqdiv460:p9 r:HALF_EVEN (3e0 / 2e0)", 1.5, 3e0 / 2e0);
AddTestCase("dqdiv461:p9 r:HALF_EVEN (30e-1 / 2e0)", 1.5, 30e-1 / 2e0);
AddTestCase("dqdiv462:p9 r:HALF_EVEN (300e-2 / 2e0)", 1.50, 300e-2 / 2e0);
AddTestCase("dqdiv464:p9 r:HALF_EVEN (3000e-3 / 2e0)", 1.500, 3000e-3 / 2e0);
AddTestCase("dqdiv465:p9 r:HALF_EVEN (3e0 / 20e-1)", 1.5, 3e0 / 20e-1);
AddTestCase("dqdiv466:p9 r:HALF_EVEN (30e-1 / 20e-1)", 1.5, 30e-1 / 20e-1);
AddTestCase("dqdiv467:p9 r:HALF_EVEN (300e-2 / 20e-1)", 1.5, 300e-2 / 20e-1);
AddTestCase("dqdiv468:p9 r:HALF_EVEN (3000e-3 / 20e-1)", 1.50, 3000e-3 / 20e-1);
AddTestCase("dqdiv469:p9 r:HALF_EVEN (3e0 / 200e-2)", 1.5, 3e0 / 200e-2);
AddTestCase("dqdiv470:p9 r:HALF_EVEN (30e-1 / 200e-2)", 1.5, 30e-1 / 200e-2);
AddTestCase("dqdiv471:p9 r:HALF_EVEN (300e-2 / 200e-2)", 1.5, 300e-2 / 200e-2);
AddTestCase("dqdiv472:p9 r:HALF_EVEN (3000e-3 / 200e-2)", 1.5, 3000e-3 / 200e-2);
AddTestCase("dqdiv473:p9 r:HALF_EVEN (3e0 / 2000e-3)", 1.5, 3e0 / 2000e-3);
AddTestCase("dqdiv474:p9 r:HALF_EVEN (30e-1 / 2000e-3)", 1.5, 30e-1 / 2000e-3);
AddTestCase("dqdiv475:p9 r:HALF_EVEN (300e-2 / 2000e-3)", 1.5, 300e-2 / 2000e-3);
AddTestCase("dqdiv476:p9 r:HALF_EVEN (3000e-3 / 2000e-3)", 1.5, 3000e-3 / 2000e-3);
// some reciprocals
AddTestCase("dqdiv480:p9 r:HALF_EVEN (1 / 1.0e+33)", 1e-33, 1 / 1.0e+33);
AddTestCase("dqdiv481:p9 r:HALF_EVEN (1 / 10e+33)", 1e-34, 1 / 10e+33);
AddTestCase("dqdiv482:p9 r:HALF_EVEN (1 / 1.0e-33)", 1e+33, 1 / 1.0e-33);
AddTestCase("dqdiv483:p9 r:HALF_EVEN (1 / 10e-33)", 1e+32, 1 / 10e-33);
// rms discussion table
AddTestCase("dqdiv484:p9 r:HALF_EVEN (0e5 / 1e3)", 0e+2, 0e5 / 1e3);
AddTestCase("dqdiv485:p9 r:HALF_EVEN (0e5 / 2e3)", 0e+2, 0e5 / 2e3);
AddTestCase("dqdiv486:p9 r:HALF_EVEN (0e5 / 10e2)", 0e+3, 0e5 / 10e2);
AddTestCase("dqdiv487:p9 r:HALF_EVEN (0e5 / 20e2)", 0e+3, 0e5 / 20e2);
AddTestCase("dqdiv488:p9 r:HALF_EVEN (0e5 / 100e1)", 0e+4, 0e5 / 100e1);
AddTestCase("dqdiv489:p9 r:HALF_EVEN (0e5 / 200e1)", 0e+4, 0e5 / 200e1);
AddTestCase("dqdiv491:p9 r:HALF_EVEN (1e5 / 1e3)", 1e+2, 1e5 / 1e3);
AddTestCase("dqdiv492:p9 r:HALF_EVEN (1e5 / 2e3)", 5e+1, 1e5 / 2e3);
AddTestCase("dqdiv493:p9 r:HALF_EVEN (1e5 / 10e2)", 1e+2, 1e5 / 10e2);
AddTestCase("dqdiv494:p9 r:HALF_EVEN (1e5 / 20e2)", 5e+1, 1e5 / 20e2);
AddTestCase("dqdiv495:p9 r:HALF_EVEN (1e5 / 100e1)", 1e+2, 1e5 / 100e1);
AddTestCase("dqdiv496:p9 r:HALF_EVEN (1e5 / 200e1)", 5e+1, 1e5 / 200e1);
// tryzeros cases
{
	use rounding HALF_UP;
}
{
	use rounding HALF_UP;
	// focus on trailing zeros issues
	AddTestCase("dqdiv500:p9 r:HALF_UP (1 / 9.9) inexact rounded", 0.1010101010101010101010101010101010, 1 / 9.9);
	AddTestCase("dqdiv501:p9 r:HALF_UP (1 / 9.09) inexact rounded", 0.1100110011001100110011001100110011, 1 / 9.09);
	AddTestCase("dqdiv502:p9 r:HALF_UP (1 / 9.009) inexact rounded", 0.1110001110001110001110001110001110, 1 / 9.009);
	AddTestCase("dqdiv511:p9 r:HALF_UP (1 / 2)", 0.5, 1 / 2);
	AddTestCase("dqdiv512:p9 r:HALF_UP (1.0 / 2)", 0.5, 1.0 / 2);
	AddTestCase("dqdiv513:p9 r:HALF_UP (1.00 / 2)", 0.50, 1.00 / 2);
	AddTestCase("dqdiv514:p9 r:HALF_UP (1.000 / 2)", 0.500, 1.000 / 2);
	AddTestCase("dqdiv515:p9 r:HALF_UP (1.0000 / 2)", 0.5000, 1.0000 / 2);
	AddTestCase("dqdiv516:p9 r:HALF_UP (1.00000 / 2)", 0.50000, 1.00000 / 2);
	AddTestCase("dqdiv517:p9 r:HALF_UP (1.000000 / 2)", 0.500000, 1.000000 / 2);
	AddTestCase("dqdiv518:p9 r:HALF_UP (1.0000000 / 2)", 0.5000000, 1.0000000 / 2);
	AddTestCase("dqdiv519:p9 r:HALF_UP (1.00 / 2.00)", 0.5, 1.00 / 2.00);
	AddTestCase("dqdiv521:p9 r:HALF_UP (2 / 1)", 2, 2 / 1);
	AddTestCase("dqdiv522:p9 r:HALF_UP (2 / 1.0)", 2, 2 / 1.0);
	AddTestCase("dqdiv523:p9 r:HALF_UP (2 / 1.00)", 2, 2 / 1.00);
	AddTestCase("dqdiv524:p9 r:HALF_UP (2 / 1.000)", 2, 2 / 1.000);
	AddTestCase("dqdiv525:p9 r:HALF_UP (2 / 1.0000)", 2, 2 / 1.0000);
	AddTestCase("dqdiv526:p9 r:HALF_UP (2 / 1.00000)", 2, 2 / 1.00000);
	AddTestCase("dqdiv527:p9 r:HALF_UP (2 / 1.000000)", 2, 2 / 1.000000);
	AddTestCase("dqdiv528:p9 r:HALF_UP (2 / 1.0000000)", 2, 2 / 1.0000000);
	AddTestCase("dqdiv529:p9 r:HALF_UP (2.00 / 1.00)", 2, 2.00 / 1.00);
	AddTestCase("dqdiv530:p9 r:HALF_UP (2.40 / 2)", 1.20, 2.40 / 2);
	AddTestCase("dqdiv531:p9 r:HALF_UP (2.40 / 4)", 0.60, 2.40 / 4);
	AddTestCase("dqdiv532:p9 r:HALF_UP (2.40 / 10)", 0.24, 2.40 / 10);
	AddTestCase("dqdiv533:p9 r:HALF_UP (2.40 / 2.0)", 1.2, 2.40 / 2.0);
	AddTestCase("dqdiv534:p9 r:HALF_UP (2.40 / 4.0)", 0.6, 2.40 / 4.0);
	AddTestCase("dqdiv535:p9 r:HALF_UP (2.40 / 10.0)", 0.24, 2.40 / 10.0);
	AddTestCase("dqdiv536:p9 r:HALF_UP (2.40 / 2.00)", 1.2, 2.40 / 2.00);
	AddTestCase("dqdiv537:p9 r:HALF_UP (2.40 / 4.00)", 0.6, 2.40 / 4.00);
	AddTestCase("dqdiv538:p9 r:HALF_UP (2.40 / 10.00)", 0.24, 2.40 / 10.00);
	AddTestCase("dqdiv539:p9 r:HALF_UP (0.9 / 0.1)", 9, 0.9 / 0.1);
	AddTestCase("dqdiv540:p9 r:HALF_UP (0.9 / 0.01)", 9e+1, 0.9 / 0.01);
	AddTestCase("dqdiv541:p9 r:HALF_UP (0.9 / 0.001)", 9e+2, 0.9 / 0.001);
	AddTestCase("dqdiv542:p9 r:HALF_UP (5 / 2)", 2.5, 5 / 2);
	AddTestCase("dqdiv543:p9 r:HALF_UP (5 / 2.0)", 2.5, 5 / 2.0);
	AddTestCase("dqdiv544:p9 r:HALF_UP (5 / 2.00)", 2.5, 5 / 2.00);
	AddTestCase("dqdiv545:p9 r:HALF_UP (5 / 20)", 0.25, 5 / 20);
	AddTestCase("dqdiv546:p9 r:HALF_UP (5 / 20.0)", 0.25, 5 / 20.0);
	AddTestCase("dqdiv547:p9 r:HALF_UP (2.400 / 2)", 1.200, 2.400 / 2);
	AddTestCase("dqdiv548:p9 r:HALF_UP (2.400 / 2.0)", 1.20, 2.400 / 2.0);
	AddTestCase("dqdiv549:p9 r:HALF_UP (2.400 / 2.400)", 1, 2.400 / 2.400);
	AddTestCase("dqdiv550:p9 r:HALF_UP (240 / 1)", 240, 240 / 1);
	AddTestCase("dqdiv551:p9 r:HALF_UP (240 / 10)", 24, 240 / 10);
	AddTestCase("dqdiv552:p9 r:HALF_UP (240 / 100)", 2.4, 240 / 100);
	AddTestCase("dqdiv553:p9 r:HALF_UP (240 / 1000)", 0.24, 240 / 1000);
	AddTestCase("dqdiv554:p9 r:HALF_UP (2400 / 1)", 2400, 2400 / 1);
	AddTestCase("dqdiv555:p9 r:HALF_UP (2400 / 10)", 240, 2400 / 10);
	AddTestCase("dqdiv556:p9 r:HALF_UP (2400 / 100)", 24, 2400 / 100);
	AddTestCase("dqdiv557:p9 r:HALF_UP (2400 / 1000)", 2.4, 2400 / 1000);
	// +ve exponent
	AddTestCase("dqdiv600:p9 r:HALF_UP (2.4e+9 / 2)", 1.2e+9, 2.4e+9 / 2);
	AddTestCase("dqdiv601:p9 r:HALF_UP (2.40e+9 / 2)", 1.20e+9, 2.40e+9 / 2);
	AddTestCase("dqdiv602:p9 r:HALF_UP (2.400e+9 / 2)", 1.200e+9, 2.400e+9 / 2);
	AddTestCase("dqdiv603:p9 r:HALF_UP (2.4000e+9 / 2)", 1.2000e+9, 2.4000e+9 / 2);
	AddTestCase("dqdiv604:p9 r:HALF_UP (24e+8 / 2)", 1.2e+9, 24e+8 / 2);
	AddTestCase("dqdiv605:p9 r:HALF_UP (240e+7 / 2)", 1.20e+9, 240e+7 / 2);
	AddTestCase("dqdiv606:p9 r:HALF_UP (2400e+6 / 2)", 1.200e+9, 2400e+6 / 2);
	AddTestCase("dqdiv607:p9 r:HALF_UP (24000e+5 / 2)", 1.2000e+9, 24000e+5 / 2);
	// more zeros, etc.
	AddTestCase("dqdiv731:p9 r:HALF_UP (5.00 / 1e-3)", 5.00e+3, 5.00 / 1e-3);
	AddTestCase("dqdiv732:p9 r:HALF_UP (00.00 / 0.000) division_undefined", NaN, 00.00 / 0.000);
	AddTestCase("dqdiv733:p9 r:HALF_UP (00.00 / 0e-3) division_undefined", NaN, 00.00 / 0e-3);
	AddTestCase("dqdiv734:p9 r:HALF_UP (0 / -0) division_undefined", NaN, 0 / -0);
	AddTestCase("dqdiv735:p9 r:HALF_UP (-0 / 0) division_undefined", NaN, -0 / 0);
	AddTestCase("dqdiv736:p9 r:HALF_UP (-0 / -0) division_undefined", NaN, -0 / -0);
	AddTestCase("dqdiv741:p9 r:HALF_UP (0 / -1)", -0, 0 / -1);
	AddTestCase("dqdiv742:p9 r:HALF_UP (-0 / -1)", 0, -0 / -1);
	AddTestCase("dqdiv743:p9 r:HALF_UP (0 / 1)", 0, 0 / 1);
	AddTestCase("dqdiv744:p9 r:HALF_UP (-0 / 1)", -0, -0 / 1);
	AddTestCase("dqdiv745:p9 r:HALF_UP (-1 / 0) division_by_zero", decimal.NEGATIVE_INFINITY, -1 / 0);
	AddTestCase("dqdiv746:p9 r:HALF_UP (-1 / -0) division_by_zero", decimal.POSITIVE_INFINITY, -1 / -0);
	AddTestCase("dqdiv747:p9 r:HALF_UP (1 / 0) division_by_zero", decimal.POSITIVE_INFINITY, 1 / 0);
	AddTestCase("dqdiv748:p9 r:HALF_UP (1 / -0) division_by_zero", decimal.NEGATIVE_INFINITY, 1 / -0);
	AddTestCase("dqdiv751:p9 r:HALF_UP (0.0 / -1)", -0.0, 0.0 / -1);
	AddTestCase("dqdiv752:p9 r:HALF_UP (-0.0 / -1)", 0.0, -0.0 / -1);
	AddTestCase("dqdiv753:p9 r:HALF_UP (0.0 / 1)", 0.0, 0.0 / 1);
	AddTestCase("dqdiv754:p9 r:HALF_UP (-0.0 / 1)", -0.0, -0.0 / 1);
	AddTestCase("dqdiv755:p9 r:HALF_UP (-1.0 / 0) division_by_zero", decimal.NEGATIVE_INFINITY, -1.0 / 0);
	AddTestCase("dqdiv756:p9 r:HALF_UP (-1.0 / -0) division_by_zero", decimal.POSITIVE_INFINITY, -1.0 / -0);
	AddTestCase("dqdiv757:p9 r:HALF_UP (1.0 / 0) division_by_zero", decimal.POSITIVE_INFINITY, 1.0 / 0);
	AddTestCase("dqdiv758:p9 r:HALF_UP (1.0 / -0) division_by_zero", decimal.NEGATIVE_INFINITY, 1.0 / -0);
	AddTestCase("dqdiv761:p9 r:HALF_UP (0 / -1.0)", -0e+1, 0 / -1.0);
	AddTestCase("dqdiv762:p9 r:HALF_UP (-0 / -1.0)", 0e+1, -0 / -1.0);
	AddTestCase("dqdiv763:p9 r:HALF_UP (0 / 1.0)", 0e+1, 0 / 1.0);
	AddTestCase("dqdiv764:p9 r:HALF_UP (-0 / 1.0)", -0e+1, -0 / 1.0);
	AddTestCase("dqdiv765:p9 r:HALF_UP (-1 / 0.0) division_by_zero", decimal.NEGATIVE_INFINITY, -1 / 0.0);
	AddTestCase("dqdiv766:p9 r:HALF_UP (-1 / -0.0) division_by_zero", decimal.POSITIVE_INFINITY, -1 / -0.0);
	AddTestCase("dqdiv767:p9 r:HALF_UP (1 / 0.0) division_by_zero", decimal.POSITIVE_INFINITY, 1 / 0.0);
	AddTestCase("dqdiv768:p9 r:HALF_UP (1 / -0.0) division_by_zero", decimal.NEGATIVE_INFINITY, 1 / -0.0);
	AddTestCase("dqdiv771:p9 r:HALF_UP (0.0 / -1.0)", -0, 0.0 / -1.0);
	AddTestCase("dqdiv772:p9 r:HALF_UP (-0.0 / -1.0)", 0, -0.0 / -1.0);
	AddTestCase("dqdiv773:p9 r:HALF_UP (0.0 / 1.0)", 0, 0.0 / 1.0);
	AddTestCase("dqdiv774:p9 r:HALF_UP (-0.0 / 1.0)", -0, -0.0 / 1.0);
	AddTestCase("dqdiv775:p9 r:HALF_UP (-1.0 / 0.0) division_by_zero", decimal.NEGATIVE_INFINITY, -1.0 / 0.0);
	AddTestCase("dqdiv776:p9 r:HALF_UP (-1.0 / -0.0) division_by_zero", decimal.POSITIVE_INFINITY, -1.0 / -0.0);
	AddTestCase("dqdiv777:p9 r:HALF_UP (1.0 / 0.0) division_by_zero", decimal.POSITIVE_INFINITY, 1.0 / 0.0);
	AddTestCase("dqdiv778:p9 r:HALF_UP (1.0 / -0.0) division_by_zero", decimal.NEGATIVE_INFINITY, 1.0 / -0.0);
	// specials
	AddTestCase("dqdiv780:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / decimal.NEGATIVE_INFINITY) invalid_operation", NaN, decimal.POSITIVE_INFINITY / decimal.NEGATIVE_INFINITY);
	AddTestCase("dqdiv781:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / -1000)", decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY / -1000);
	AddTestCase("dqdiv782:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / -1)", decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY / -1);
	AddTestCase("dqdiv783:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / -0)", decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY / -0);
	AddTestCase("dqdiv784:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / 0)", decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY / 0);
	AddTestCase("dqdiv785:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / 1)", decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY / 1);
	AddTestCase("dqdiv786:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / 1000)", decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY / 1000);
	AddTestCase("dqdiv787:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / decimal.POSITIVE_INFINITY) invalid_operation", NaN, decimal.POSITIVE_INFINITY / decimal.POSITIVE_INFINITY);
	AddTestCase("dqdiv789:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / decimal.POSITIVE_INFINITY) invalid_operation", NaN, decimal.NEGATIVE_INFINITY / decimal.POSITIVE_INFINITY);
	AddTestCase("dqdiv795:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / decimal.POSITIVE_INFINITY) invalid_operation", NaN, decimal.POSITIVE_INFINITY / decimal.POSITIVE_INFINITY);
	AddTestCase("dqdiv800:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / decimal.NEGATIVE_INFINITY) invalid_operation", NaN, decimal.NEGATIVE_INFINITY / decimal.NEGATIVE_INFINITY);
	AddTestCase("dqdiv801:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / -1000)", decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY / -1000);
	AddTestCase("dqdiv802:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / -1)", decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY / -1);
	AddTestCase("dqdiv803:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / -0)", decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY / -0);
	AddTestCase("dqdiv804:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / 0)", decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY / 0);
	AddTestCase("dqdiv805:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / 1)", decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY / 1);
	AddTestCase("dqdiv806:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / 1000)", decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY / 1000);
	AddTestCase("dqdiv807:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / decimal.POSITIVE_INFINITY) invalid_operation", NaN, decimal.NEGATIVE_INFINITY / decimal.POSITIVE_INFINITY);
	AddTestCase("dqdiv809:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / decimal.NEGATIVE_INFINITY) invalid_operation", NaN, decimal.NEGATIVE_INFINITY / decimal.NEGATIVE_INFINITY);
	AddTestCase("dqdiv815:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / decimal.NEGATIVE_INFINITY) invalid_operation", NaN, decimal.POSITIVE_INFINITY / decimal.NEGATIVE_INFINITY);
	AddTestCase("dqdiv821:p9 r:HALF_UP (NaN / decimal.NEGATIVE_INFINITY)", NaN, NaN / decimal.NEGATIVE_INFINITY);
	AddTestCase("dqdiv822:p9 r:HALF_UP (NaN / -1000)", NaN, NaN / -1000);
	AddTestCase("dqdiv823:p9 r:HALF_UP (NaN / -1)", NaN, NaN / -1);
	AddTestCase("dqdiv824:p9 r:HALF_UP (NaN / -0)", NaN, NaN / -0);
	AddTestCase("dqdiv825:p9 r:HALF_UP (NaN / 0)", NaN, NaN / 0);
	AddTestCase("dqdiv826:p9 r:HALF_UP (NaN / 1)", NaN, NaN / 1);
	AddTestCase("dqdiv827:p9 r:HALF_UP (NaN / 1000)", NaN, NaN / 1000);
	AddTestCase("dqdiv828:p9 r:HALF_UP (NaN / decimal.POSITIVE_INFINITY)", NaN, NaN / decimal.POSITIVE_INFINITY);
	AddTestCase("dqdiv829:p9 r:HALF_UP (NaN / NaN)", NaN, NaN / NaN);
	AddTestCase("dqdiv830:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / NaN)", NaN, decimal.NEGATIVE_INFINITY / NaN);
	AddTestCase("dqdiv831:p9 r:HALF_UP (-1000 / NaN)", NaN, -1000 / NaN);
	AddTestCase("dqdiv832:p9 r:HALF_UP (-1 / NaN)", NaN, -1 / NaN);
	AddTestCase("dqdiv833:p9 r:HALF_UP (-0 / NaN)", NaN, -0 / NaN);
	AddTestCase("dqdiv834:p9 r:HALF_UP (0 / NaN)", NaN, 0 / NaN);
	AddTestCase("dqdiv835:p9 r:HALF_UP (1 / NaN)", NaN, 1 / NaN);
	AddTestCase("dqdiv836:p9 r:HALF_UP (1000 / NaN)", NaN, 1000 / NaN);
	AddTestCase("dqdiv837:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / NaN)", NaN, decimal.POSITIVE_INFINITY / NaN);
	AddTestCase("dqdiv841:p9 r:HALF_UP (NaN / decimal.NEGATIVE_INFINITY) invalid_operation", NaN, NaN / decimal.NEGATIVE_INFINITY);
	AddTestCase("dqdiv842:p9 r:HALF_UP (NaN / -1000) invalid_operation", NaN, NaN / -1000);
	AddTestCase("dqdiv843:p9 r:HALF_UP (NaN / -1) invalid_operation", NaN, NaN / -1);
	AddTestCase("dqdiv844:p9 r:HALF_UP (NaN / -0) invalid_operation", NaN, NaN / -0);
	AddTestCase("dqdiv845:p9 r:HALF_UP (NaN / 0) invalid_operation", NaN, NaN / 0);
	AddTestCase("dqdiv846:p9 r:HALF_UP (NaN / 1) invalid_operation", NaN, NaN / 1);
	AddTestCase("dqdiv847:p9 r:HALF_UP (NaN / 1000) invalid_operation", NaN, NaN / 1000);
	AddTestCase("dqdiv848:p9 r:HALF_UP (NaN / NaN) invalid_operation", NaN, NaN / NaN);
	AddTestCase("dqdiv849:p9 r:HALF_UP (NaN / NaN) invalid_operation", NaN, NaN / NaN);
	AddTestCase("dqdiv850:p9 r:HALF_UP (NaN / NaN) invalid_operation", NaN, NaN / NaN);
	AddTestCase("dqdiv851:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / NaN) invalid_operation", NaN, decimal.NEGATIVE_INFINITY / NaN);
	AddTestCase("dqdiv852:p9 r:HALF_UP (-1000 / NaN) invalid_operation", NaN, -1000 / NaN);
	AddTestCase("dqdiv853:p9 r:HALF_UP (-1 / NaN) invalid_operation", NaN, -1 / NaN);
	AddTestCase("dqdiv854:p9 r:HALF_UP (-0 / NaN) invalid_operation", NaN, -0 / NaN);
	AddTestCase("dqdiv855:p9 r:HALF_UP (0 / NaN) invalid_operation", NaN, 0 / NaN);
	AddTestCase("dqdiv856:p9 r:HALF_UP (1 / NaN) invalid_operation", NaN, 1 / NaN);
	AddTestCase("dqdiv857:p9 r:HALF_UP (1000 / NaN) invalid_operation", NaN, 1000 / NaN);
	AddTestCase("dqdiv858:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / NaN) invalid_operation", NaN, decimal.POSITIVE_INFINITY / NaN);
	AddTestCase("dqdiv859:p9 r:HALF_UP (NaN / NaN) invalid_operation", NaN, NaN / NaN);
	// propagating nans
	AddTestCase("dqdiv861:p9 r:HALF_UP (NaN / decimal.NEGATIVE_INFINITY)", NaN, NaN / decimal.NEGATIVE_INFINITY);
	AddTestCase("dqdiv862:p9 r:HALF_UP (NaN / 1000)", NaN, NaN / 1000);
	AddTestCase("dqdiv863:p9 r:HALF_UP (NaN / decimal.POSITIVE_INFINITY)", NaN, NaN / decimal.POSITIVE_INFINITY);
	AddTestCase("dqdiv864:p9 r:HALF_UP (NaN / NaN)", NaN, NaN / NaN);
	AddTestCase("dqdiv865:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / NaN)", NaN, decimal.NEGATIVE_INFINITY / NaN);
	AddTestCase("dqdiv866:p9 r:HALF_UP (-1000 / NaN)", NaN, -1000 / NaN);
	AddTestCase("dqdiv867:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / NaN)", NaN, decimal.POSITIVE_INFINITY / NaN);
	AddTestCase("dqdiv871:p9 r:HALF_UP (NaN / decimal.NEGATIVE_INFINITY) invalid_operation", NaN, NaN / decimal.NEGATIVE_INFINITY);
	AddTestCase("dqdiv872:p9 r:HALF_UP (NaN / -1) invalid_operation", NaN, NaN / -1);
	AddTestCase("dqdiv873:p9 r:HALF_UP (NaN / NaN) invalid_operation", NaN, NaN / NaN);
	AddTestCase("dqdiv874:p9 r:HALF_UP (NaN / NaN) invalid_operation", NaN, NaN / NaN);
	AddTestCase("dqdiv875:p9 r:HALF_UP (NaN / NaN) invalid_operation", NaN, NaN / NaN);
	AddTestCase("dqdiv876:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / NaN) invalid_operation", NaN, decimal.NEGATIVE_INFINITY / NaN);
	AddTestCase("dqdiv877:p9 r:HALF_UP (0 / NaN) invalid_operation", NaN, 0 / NaN);
	AddTestCase("dqdiv878:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / NaN) invalid_operation", NaN, decimal.POSITIVE_INFINITY / NaN);
	AddTestCase("dqdiv879:p9 r:HALF_UP (NaN / NaN) invalid_operation", NaN, NaN / NaN);
	AddTestCase("dqdiv881:p9 r:HALF_UP (-NaN / decimal.NEGATIVE_INFINITY)", -NaN, -NaN / decimal.NEGATIVE_INFINITY);
	AddTestCase("dqdiv882:p9 r:HALF_UP (-NaN / 1000)", -NaN, -NaN / 1000);
	AddTestCase("dqdiv883:p9 r:HALF_UP (-NaN / decimal.POSITIVE_INFINITY)", -NaN, -NaN / decimal.POSITIVE_INFINITY);
	AddTestCase("dqdiv884:p9 r:HALF_UP (-NaN / -NaN)", -NaN, -NaN / -NaN);
	AddTestCase("dqdiv885:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / -NaN)", -NaN, decimal.NEGATIVE_INFINITY / -NaN);
	AddTestCase("dqdiv886:p9 r:HALF_UP (-1000 / -NaN)", -NaN, -1000 / -NaN);
	AddTestCase("dqdiv887:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / -NaN)", -NaN, decimal.POSITIVE_INFINITY / -NaN);
	AddTestCase("dqdiv891:p9 r:HALF_UP (-NaN / decimal.NEGATIVE_INFINITY) invalid_operation", -NaN, -NaN / decimal.NEGATIVE_INFINITY);
	AddTestCase("dqdiv892:p9 r:HALF_UP (-NaN / -1) invalid_operation", -NaN, -NaN / -1);
	AddTestCase("dqdiv893:p9 r:HALF_UP (-NaN / NaN) invalid_operation", -NaN, -NaN / NaN);
	AddTestCase("dqdiv894:p9 r:HALF_UP (-NaN / -NaN) invalid_operation", -NaN, -NaN / -NaN);
	AddTestCase("dqdiv895:p9 r:HALF_UP (-NaN / -NaN) invalid_operation", -NaN, -NaN / -NaN);
	AddTestCase("dqdiv896:p9 r:HALF_UP (decimal.NEGATIVE_INFINITY / -NaN) invalid_operation", -NaN, decimal.NEGATIVE_INFINITY / -NaN);
	AddTestCase("dqdiv897:p9 r:HALF_UP (0 / -NaN) invalid_operation", -NaN, 0 / -NaN);
	AddTestCase("dqdiv898:p9 r:HALF_UP (decimal.POSITIVE_INFINITY / -NaN) invalid_operation", -NaN, decimal.POSITIVE_INFINITY / -NaN);
	AddTestCase("dqdiv899:p9 r:HALF_UP (-NaN / -NaN) invalid_operation", -NaN, -NaN / -NaN);
	// various flavours of divide by 0
	AddTestCase("dqdiv901:p9 r:HALF_UP (0 / 0) division_undefined", NaN, 0 / 0);
	AddTestCase("dqdiv902:p9 r:HALF_UP (0.0e5 / 0) division_undefined", NaN, 0.0e5 / 0);
	AddTestCase("dqdiv903:p9 r:HALF_UP (0.000 / 0) division_undefined", NaN, 0.000 / 0);
	AddTestCase("dqdiv904:p9 r:HALF_UP (0.0001 / 0) division_by_zero", decimal.POSITIVE_INFINITY, 0.0001 / 0);
	AddTestCase("dqdiv905:p9 r:HALF_UP (0.01 / 0) division_by_zero", decimal.POSITIVE_INFINITY, 0.01 / 0);
	AddTestCase("dqdiv906:p9 r:HALF_UP (0.1 / 0) division_by_zero", decimal.POSITIVE_INFINITY, 0.1 / 0);
	AddTestCase("dqdiv907:p9 r:HALF_UP (1 / 0) division_by_zero", decimal.POSITIVE_INFINITY, 1 / 0);
	AddTestCase("dqdiv908:p9 r:HALF_UP (1 / 0.0) division_by_zero", decimal.POSITIVE_INFINITY, 1 / 0.0);
	AddTestCase("dqdiv909:p9 r:HALF_UP (10 / 0.0) division_by_zero", decimal.POSITIVE_INFINITY, 10 / 0.0);
	AddTestCase("dqdiv910:p9 r:HALF_UP (1e+100 / 0.0) division_by_zero", decimal.POSITIVE_INFINITY, 1e+100 / 0.0);
	AddTestCase("dqdiv911:p9 r:HALF_UP (1e+100 / 0) division_by_zero", decimal.POSITIVE_INFINITY, 1e+100 / 0);
	AddTestCase("dqdiv921:p9 r:HALF_UP (-0.0001 / 0) division_by_zero", decimal.NEGATIVE_INFINITY, -0.0001 / 0);
	AddTestCase("dqdiv922:p9 r:HALF_UP (-0.01 / 0) division_by_zero", decimal.NEGATIVE_INFINITY, -0.01 / 0);
	AddTestCase("dqdiv923:p9 r:HALF_UP (-0.1 / 0) division_by_zero", decimal.NEGATIVE_INFINITY, -0.1 / 0);
	AddTestCase("dqdiv924:p9 r:HALF_UP (-1 / 0) division_by_zero", decimal.NEGATIVE_INFINITY, -1 / 0);
	AddTestCase("dqdiv925:p9 r:HALF_UP (-1 / 0.0) division_by_zero", decimal.NEGATIVE_INFINITY, -1 / 0.0);
	AddTestCase("dqdiv926:p9 r:HALF_UP (-10 / 0.0) division_by_zero", decimal.NEGATIVE_INFINITY, -10 / 0.0);
	AddTestCase("dqdiv927:p9 r:HALF_UP (-1e+100 / 0.0) division_by_zero", decimal.NEGATIVE_INFINITY, -1e+100 / 0.0);
	AddTestCase("dqdiv928:p9 r:HALF_UP (-1e+100 / 0) division_by_zero", decimal.NEGATIVE_INFINITY, -1e+100 / 0);
	AddTestCase("dqdiv931:p9 r:HALF_UP (0.0001 / -0) division_by_zero", decimal.NEGATIVE_INFINITY, 0.0001 / -0);
	AddTestCase("dqdiv932:p9 r:HALF_UP (0.01 / -0) division_by_zero", decimal.NEGATIVE_INFINITY, 0.01 / -0);
	AddTestCase("dqdiv933:p9 r:HALF_UP (0.1 / -0) division_by_zero", decimal.NEGATIVE_INFINITY, 0.1 / -0);
	AddTestCase("dqdiv934:p9 r:HALF_UP (1 / -0) division_by_zero", decimal.NEGATIVE_INFINITY, 1 / -0);
	AddTestCase("dqdiv935:p9 r:HALF_UP (1 / -0.0) division_by_zero", decimal.NEGATIVE_INFINITY, 1 / -0.0);
	AddTestCase("dqdiv936:p9 r:HALF_UP (10 / -0.0) division_by_zero", decimal.NEGATIVE_INFINITY, 10 / -0.0);
	AddTestCase("dqdiv937:p9 r:HALF_UP (1e+100 / -0.0) division_by_zero", decimal.NEGATIVE_INFINITY, 1e+100 / -0.0);
	AddTestCase("dqdiv938:p9 r:HALF_UP (1e+100 / -0) division_by_zero", decimal.NEGATIVE_INFINITY, 1e+100 / -0);
	AddTestCase("dqdiv941:p9 r:HALF_UP (-0.0001 / -0) division_by_zero", decimal.POSITIVE_INFINITY, -0.0001 / -0);
	AddTestCase("dqdiv942:p9 r:HALF_UP (-0.01 / -0) division_by_zero", decimal.POSITIVE_INFINITY, -0.01 / -0);
	AddTestCase("dqdiv943:p9 r:HALF_UP (-0.1 / -0) division_by_zero", decimal.POSITIVE_INFINITY, -0.1 / -0);
	AddTestCase("dqdiv944:p9 r:HALF_UP (-1 / -0) division_by_zero", decimal.POSITIVE_INFINITY, -1 / -0);
	AddTestCase("dqdiv945:p9 r:HALF_UP (-1 / -0.0) division_by_zero", decimal.POSITIVE_INFINITY, -1 / -0.0);
	AddTestCase("dqdiv946:p9 r:HALF_UP (-10 / -0.0) division_by_zero", decimal.POSITIVE_INFINITY, -10 / -0.0);
	AddTestCase("dqdiv947:p9 r:HALF_UP (-1e+100 / -0.0) division_by_zero", decimal.POSITIVE_INFINITY, -1e+100 / -0.0);
	AddTestCase("dqdiv948:p9 r:HALF_UP (-1e+100 / -0) division_by_zero", decimal.POSITIVE_INFINITY, -1e+100 / -0);
	// examples from sql proposal (krishna kulkarni)
	AddTestCase("dqdiv1021:p9 r:HALF_UP (1e0 / 1e0)", 1, 1e0 / 1e0);
	AddTestCase("dqdiv1022:p9 r:HALF_UP (1e0 / 2e0)", 0.5, 1e0 / 2e0);
	AddTestCase("dqdiv1023:p9 r:HALF_UP (1e0 / 3e0) inexact rounded", 0.3333333333333333333333333333333333, 1e0 / 3e0);
	AddTestCase("dqdiv1024:p9 r:HALF_UP (100e-2 / 1000e-3)", 1, 100e-2 / 1000e-3);
	AddTestCase("dqdiv1025:p9 r:HALF_UP (24e-1 / 2e0)", 1.2, 24e-1 / 2e0);
	AddTestCase("dqdiv1026:p9 r:HALF_UP (2400e-3 / 2e0)", 1.200, 2400e-3 / 2e0);
	AddTestCase("dqdiv1027:p9 r:HALF_UP (5e0 / 2e0)", 2.5, 5e0 / 2e0);
	AddTestCase("dqdiv1028:p9 r:HALF_UP (5e0 / 20e-1)", 2.5, 5e0 / 20e-1);
	AddTestCase("dqdiv1029:p9 r:HALF_UP (5e0 / 2000e-3)", 2.5, 5e0 / 2000e-3);
	AddTestCase("dqdiv1030:p9 r:HALF_UP (5e0 / 2e-1)", 25, 5e0 / 2e-1);
	AddTestCase("dqdiv1031:p9 r:HALF_UP (5e0 / 20e-2)", 25, 5e0 / 20e-2);
	AddTestCase("dqdiv1032:p9 r:HALF_UP (480e-2 / 3e0)", 1.60, 480e-2 / 3e0);
	AddTestCase("dqdiv1033:p9 r:HALF_UP (47e-1 / 2e0)", 2.35, 47e-1 / 2e0);
	// ecmascript bad examples
}
{
	use rounding HALF_DOWN;
	AddTestCase("dqdiv1040:p9 r:HALF_DOWN (5 / 9) inexact rounded", 0.5555555555555555555555555555555556, 5 / 9);
}
{
	use rounding HALF_EVEN;
	AddTestCase("dqdiv1041:p9 r:HALF_EVEN (6 / 11) inexact rounded", 0.5454545454545454545454545454545455, 6 / 11);
	// overflow and underflow tests .. note subnormal results
	// signs
	// 'subnormal' boundary (all hard underflow or overflow in base arithemtic)
	// [no equivalent of 'subnormal' for overflow]
	// randoms
	AddTestCase("dqdiv2010:p9 r:HALF_EVEN (-5231195652931651968034356117118850 / -7243718664422548573203260970.34995) inexact rounded", 722169.9095831284624736051460550680, -5231195652931651968034356117118850 / -7243718664422548573203260970.34995);
	AddTestCase("dqdiv2011:p9 r:HALF_EVEN (-89584669773927.82711237350022515352 / -42077943728529635884.21142627532985) inexact rounded", 0.000002129017291146471565928125887527266, -89584669773927.82711237350022515352 / -42077943728529635884.21142627532985);
	AddTestCase("dqdiv2012:p9 r:HALF_EVEN (-2.828201693360723203806974891946180e-232 / 812596541221823960386384403089240.9) inexact rounded", -3.480450075640521320040055759125120e-265, -2.828201693360723203806974891946180e-232 / 812596541221823960386384403089240.9);
	AddTestCase("dqdiv2013:p9 r:HALF_EVEN (-6442775372761069267502937539408720 / 24904085056.69185465145182606089196) inexact rounded", -258703556388226463687701.4884719589, -6442775372761069267502937539408720 / 24904085056.69185465145182606089196);
	AddTestCase("dqdiv2014:p9 r:HALF_EVEN (5.535520011272625629610079879714705 / -44343664650.57203052003068113531208) inexact rounded", -1.248322630728089308975940533493562e-10, 5.535520011272625629610079879714705 / -44343664650.57203052003068113531208);
	AddTestCase("dqdiv2015:p9 r:HALF_EVEN (65919273712517865964325.99419625010 / -314733354141381737378622515.7789054) inexact rounded", -0.0002094448295521490616379784758911632, 65919273712517865964325.99419625010 / -314733354141381737378622515.7789054);
	AddTestCase("dqdiv2016:p9 r:HALF_EVEN (-7.779172568193197107115275140431129e+759 / -140453015639.3988987652895178782143) inexact rounded", 5.538629792161641534962774244238115e+748, -7.779172568193197107115275140431129e+759 / -140453015639.3988987652895178782143);
	AddTestCase("dqdiv2017:p9 r:HALF_EVEN (644314832597569.0181226067518178797 / -115024585257425.1635759521565201075) inexact rounded", -5.601540150356479257367687450922795, 644314832597569.0181226067518178797 / -115024585257425.1635759521565201075);
	AddTestCase("dqdiv2018:p9 r:HALF_EVEN (6.898640941579611450676592553286870e-47 / -11272429881407851485163914999.25943) inexact rounded", -6.119923578285338689371137648319280e-75, 6.898640941579611450676592553286870e-47 / -11272429881407851485163914999.25943);
	AddTestCase("dqdiv2019:p9 r:HALF_EVEN (-3591344544888727133.30819750163254 / 5329395.423792795661446561090331037) inexact rounded", -673874662941.1968525589460533725290, -3591344544888727133.30819750163254 / 5329395.423792795661446561090331037);
	AddTestCase("dqdiv2020:p9 r:HALF_EVEN (-7.682356781384631313156462724425838e+747 / -6.60375855512219057281922141809940e+703) inexact rounded", 1.163330960279556016678379128875149e+44, -7.682356781384631313156462724425838e+747 / -6.60375855512219057281922141809940e+703);
	AddTestCase("dqdiv2021:p9 r:HALF_EVEN (-4511495596596941820863224.274679699 / 3365395017.263329795449661616090724) inexact rounded", -1340554548115304.904166888018346299, -4511495596596941820863224.274679699 / 3365395017.263329795449661616090724);
	AddTestCase("dqdiv2022:p9 r:HALF_EVEN (5.211164127840931517263639608151299 / 164.5566381356276567012533847006453) inexact rounded", 0.03166790587655228864478260157156510, 5.211164127840931517263639608151299 / 164.5566381356276567012533847006453);
	AddTestCase("dqdiv2023:p9 r:HALF_EVEN (-49891.2243893458830384077684620383 / -47179.9312961860747554053371171530) inexact rounded", 1.057467084386767291602189656430268, -49891.2243893458830384077684620383 / -47179.9312961860747554053371171530);
	AddTestCase("dqdiv2024:p9 r:HALF_EVEN (15065477.47214268488077415462413353 / 4366211.120892953261309529740552596) inexact rounded", 3.450469309661227984244545513441359, 15065477.47214268488077415462413353 / 4366211.120892953261309529740552596);
	AddTestCase("dqdiv2025:p9 r:HALF_EVEN (1.575670269440761846109602429612644e+370 / 653199649324740300.006185482643439) inexact rounded", 2.412233795700359170904588548041481e+352, 1.575670269440761846109602429612644e+370 / 653199649324740300.006185482643439);
	AddTestCase("dqdiv2026:p9 r:HALF_EVEN (-2112422311733448924573432192.620145 / -80067206.03590693153848215848613406) inexact rounded", 26383115089417660175.20102646756574, -2112422311733448924573432192.620145 / -80067206.03590693153848215848613406);
	AddTestCase("dqdiv2027:p9 r:HALF_EVEN (-67096536051279809.32218611548721839 / -869685412881941081664251990181.1049) inexact rounded", 7.715035236584805921278566365231168e-14, -67096536051279809.32218611548721839 / -869685412881941081664251990181.1049);
	AddTestCase("dqdiv2028:p9 r:HALF_EVEN (-58612908548962047.21866913425488972 / -978449597531.3873665583475633831644) inexact rounded", 59903.86085991703091236507859837023, -58612908548962047.21866913425488972 / -978449597531.3873665583475633831644);
	AddTestCase("dqdiv2029:p9 r:HALF_EVEN (-133032412010942.1476864138213319796 / -7.882059293498670705446528648201359e-428) inexact rounded", 1.687787506504433064549515681693715e+441, -133032412010942.1476864138213319796 / -7.882059293498670705446528648201359e-428);
	AddTestCase("dqdiv2030:p9 r:HALF_EVEN (1.83746698338966029492299716360513e+977 / -9.897926608979649951672839879128603e+154) inexact rounded", -1.856416051542212552042390218062458e+822, 1.83746698338966029492299716360513e+977 / -9.897926608979649951672839879128603e+154);
	AddTestCase("dqdiv2031:p9 r:HALF_EVEN (-113742475841399236307128962.1507063 / 8298602.203049834732657567965262989) inexact rounded", -13706221006665137826.16557393919929, -113742475841399236307128962.1507063 / 8298602.203049834732657567965262989);
	AddTestCase("dqdiv2032:p9 r:HALF_EVEN (196.4787574650754152995941808331862 / 929.6553388472318094427422117172394) inexact rounded", 0.2113458066176526651006917922814018, 196.4787574650754152995941808331862 / 929.6553388472318094427422117172394);
	AddTestCase("dqdiv2033:p9 r:HALF_EVEN (71931221465.43867996282803628130350 / 3838685934206426257090718.402248853) inexact rounded", 1.873850132527423413607199513324021e-14, 71931221465.43867996282803628130350 / 3838685934206426257090718.402248853);
	AddTestCase("dqdiv2034:p9 r:HALF_EVEN (488.4282502289651653783596246312885 / -80.68940956806634280078706577953188) inexact rounded", -6.053189047280693318844801899473272, 488.4282502289651653783596246312885 / -80.68940956806634280078706577953188);
	AddTestCase("dqdiv2035:p9 r:HALF_EVEN (9.001764344963921754981762913247394e-162 / -8.585540973667205753734967645386919e-729) inexact rounded", -1.048479574271827326396012573232934e+567, 9.001764344963921754981762913247394e-162 / -8.585540973667205753734967645386919e-729);
	AddTestCase("dqdiv2036:p9 r:HALF_EVEN (-7.404133959409894743706402857145471e-828 / -51.38159929460289711134684843086265) inexact rounded", 1.441008855516029461032061785219773e-829, -7.404133959409894743706402857145471e-828 / -51.38159929460289711134684843086265);
	AddTestCase("dqdiv2037:p9 r:HALF_EVEN (2.967520235574419794048994436040717e-613 / -6252513855.91394894949879262731889) inexact rounded", -4.746123405656409127572998751885338e-623, 2.967520235574419794048994436040717e-613 / -6252513855.91394894949879262731889);
	AddTestCase("dqdiv2038:p9 r:HALF_EVEN (-18826852654824040505.83920366765051 / -6336924877942437992590557460147340) inexact rounded", 2.970976146546494669807886278519194e-15, -18826852654824040505.83920366765051 / -6336924877942437992590557460147340);
	AddTestCase("dqdiv2039:p9 r:HALF_EVEN (-8.101406784809197604949584001735949e+561 / 4.823300306948942821076681658771635e+361) inexact rounded", -1.679639721610839204738445747238987e+200, -8.101406784809197604949584001735949e+561 / 4.823300306948942821076681658771635e+361);
	AddTestCase("dqdiv2040:p9 r:HALF_EVEN (-6.11981977773094052331062585191723e+295 / 1.507610253755339328302779005586534e+238) inexact rounded", -4.059285058911577244044418416044763e+57, -6.11981977773094052331062585191723e+295 / 1.507610253755339328302779005586534e+238);
	AddTestCase("dqdiv2041:p9 r:HALF_EVEN (6.472638850046815880599220534274055e-596 / -4.475233712083047516933911786159972) inexact rounded", -1.446324207062261745520496475778879e-596, 6.472638850046815880599220534274055e-596 / -4.475233712083047516933911786159972);
	AddTestCase("dqdiv2042:p9 r:HALF_EVEN (-84438593330.71277839631144509397112 / -586684596204401664208947.4054879633) inexact rounded", 1.439250218550041228759983937772504e-13, -84438593330.71277839631144509397112 / -586684596204401664208947.4054879633);
	AddTestCase("dqdiv2043:p9 r:HALF_EVEN (9.354533233294022616695815656704369e-24 / 405.500390626135304252144163591746) inexact rounded", 2.306911028827774549740571229736198e-26, 9.354533233294022616695815656704369e-24 / 405.500390626135304252144163591746);
	AddTestCase("dqdiv2044:p9 r:HALF_EVEN (985606423350210.7374876650149957881 / -36811563697.41925681866694859828794) inexact rounded", -26774.36990864119445335813354717711, 985606423350210.7374876650149957881 / -36811563697.41925681866694859828794);
	AddTestCase("dqdiv2045:p9 r:HALF_EVEN (-8.187280774177715706278002247766311e-123 / -38784124393.91212870828430001300068) inexact rounded", 2.110987653356139147357240727794365e-133, -8.187280774177715706278002247766311e-123 / -38784124393.91212870828430001300068);
	AddTestCase("dqdiv2046:p9 r:HALF_EVEN (-4.612203126350070903459245798371657e+912 / 7.971562182727956290901984736800519e+64) inexact rounded", -5.785820922708683237098826662769748e+847, -4.612203126350070903459245798371657e+912 / 7.971562182727956290901984736800519e+64);
	AddTestCase("dqdiv2047:p9 r:HALF_EVEN (4.661015909421485298247928967977089e+888 / -6.360911253323922338737311563845581e+388) inexact rounded", -7.327591478321365980156654539638836e+499, 4.661015909421485298247928967977089e+888 / -6.360911253323922338737311563845581e+388);
	AddTestCase("dqdiv2048:p9 r:HALF_EVEN (9156078172903.257500003260710833030 / 7.189796653262147139071634237964074e-90) inexact rounded", 1.273482215766000994365201545096026e+102, 9156078172903.257500003260710833030 / 7.189796653262147139071634237964074e-90);
	AddTestCase("dqdiv2049:p9 r:HALF_EVEN (-1.710722303327476586373477781276586e-311 / -3167561628260156837329323.729380695) inexact rounded", 5.400754599578613984875752958645655e-336, -1.710722303327476586373477781276586e-311 / -3167561628260156837329323.729380695);
	AddTestCase("dqdiv2050:p9 r:HALF_EVEN (-4.647935210881806238321616345413021e-878 / 209388.5431867744648177308460639582) inexact rounded", -2.219765771394593733140494297388140e-883, -4.647935210881806238321616345413021e-878 / 209388.5431867744648177308460639582);
	AddTestCase("dqdiv2051:p9 r:HALF_EVEN (5958.694728395760992719084781582700 / 4.541510156564315632536353171846096e-746) inexact rounded", 1.312051393253638664947852693005480e+749, 5958.694728395760992719084781582700 / 4.541510156564315632536353171846096e-746);
	AddTestCase("dqdiv2052:p9 r:HALF_EVEN (-7.935732544649702175256699886872093e-489 / -7.433329073664793138998765647467971e+360) inexact rounded", 1.067587949626076917672271619664656e-849, -7.935732544649702175256699886872093e-489 / -7.433329073664793138998765647467971e+360);
	AddTestCase("dqdiv2053:p9 r:HALF_EVEN (-2746650864601157.863589959939901350 / 7.016684945507647528907184694359598e+548) inexact rounded", -3.914456593009309529351254950429932e-534, -2746650864601157.863589959939901350 / 7.016684945507647528907184694359598e+548);
	AddTestCase("dqdiv2054:p9 r:HALF_EVEN (3605149408631197365447953.994569178 / -75614025825649082.78264864428237833) inexact rounded", -47678315.88472693507060063188020532, 3605149408631197365447953.994569178 / -75614025825649082.78264864428237833);
	AddTestCase("dqdiv2055:p9 r:HALF_EVEN (788194320921798404906375214.196349 / -6.222718148433247384932573401976337e-418) inexact rounded", -1.266639918634671803982222244977287e+444, 788194320921798404906375214.196349 / -6.222718148433247384932573401976337e-418);
	AddTestCase("dqdiv2056:p9 r:HALF_EVEN (5620722730534752.758208943447603211 / 6.843552841168538319123000917657759e-139) inexact rounded", 8.213164800485434666629970443739554e+153, 5620722730534752.758208943447603211 / 6.843552841168538319123000917657759e-139);
	AddTestCase("dqdiv2057:p9 r:HALF_EVEN (7304534676713703938102.403949019402 / -576169.3685010935108153023803590835) inexact rounded", -12677756014201995.31969237144394772, 7304534676713703938102.403949019402 / -576169.3685010935108153023803590835);
	AddTestCase("dqdiv2058:p9 r:HALF_EVEN (8067918762.134621639254916786945547 / -8.774771480055536009105596163864758e+954) inexact rounded", -9.194448858836332156766764605125245e-946, 8067918762.134621639254916786945547 / -8.774771480055536009105596163864758e+954);
	AddTestCase("dqdiv2059:p9 r:HALF_EVEN (8.702093454123046507578256899537563e-324 / -5.875399733016018404580201176576293e-401) inexact rounded", -1.481106622452052581470443526957335e+77, 8.702093454123046507578256899537563e-324 / -5.875399733016018404580201176576293e-401);
	AddTestCase("dqdiv2060:p9 r:HALF_EVEN (-41426.01662518451861386352415092356 / 90.00146621684478300510769802013464) inexact rounded", -460.2815750287318692732067709176200, -41426.01662518451861386352415092356 / 90.00146621684478300510769802013464);
	// null tests
	AddTestCase("dqdiv9998:p9 r:HALF_EVEN (10 / null) invalid_operation", Infinity, 10 / null);
	AddTestCase("dqdiv9999:p9 r:HALF_EVEN (null / 10) invalid_operation", 0, null / 10);
	}
}
test();
