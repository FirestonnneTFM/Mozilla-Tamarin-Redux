use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "dqMultiply.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// dqmultiply.dectest -- decquad multiplication                       --
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
// this set of tests are for decquads only; all arguments are
// representable in a decquad
use rounding HALF_EVEN;
// sanity checks
AddTestCase("dqmul000:p9 r:HALF_EVEN (2 * 2)", 4, 2 * 2);
AddTestCase("dqmul001:p9 r:HALF_EVEN (2 * 3)", 6, 2 * 3);
AddTestCase("dqmul002:p9 r:HALF_EVEN (5 * 1)", 5, 5 * 1);
AddTestCase("dqmul003:p9 r:HALF_EVEN (5 * 2)", 10, 5 * 2);
AddTestCase("dqmul004:p9 r:HALF_EVEN (1.20 * 2)", 2.40, 1.20 * 2);
AddTestCase("dqmul005:p9 r:HALF_EVEN (1.20 * 0)", 0.00, 1.20 * 0);
AddTestCase("dqmul006:p9 r:HALF_EVEN (1.20 * -2)", -2.40, 1.20 * -2);
AddTestCase("dqmul007:p9 r:HALF_EVEN (-1.20 * 2)", -2.40, -1.20 * 2);
AddTestCase("dqmul008:p9 r:HALF_EVEN (-1.20 * 0)", -0.00, -1.20 * 0);
AddTestCase("dqmul009:p9 r:HALF_EVEN (-1.20 * -2)", 2.40, -1.20 * -2);
AddTestCase("dqmul010:p9 r:HALF_EVEN (5.09 * 7.1)", 36.139, 5.09 * 7.1);
AddTestCase("dqmul011:p9 r:HALF_EVEN (2.5 * 4)", 10.0, 2.5 * 4);
AddTestCase("dqmul012:p9 r:HALF_EVEN (2.50 * 4)", 10.00, 2.50 * 4);
AddTestCase("dqmul013:p9 r:HALF_EVEN (1.23456789 * 1.0000000000000000000000000000) rounded", 1.234567890000000000000000000000000, 1.23456789 * 1.0000000000000000000000000000);
AddTestCase("dqmul015:p9 r:HALF_EVEN (2.50 * 4)", 10.00, 2.50 * 4);
AddTestCase("dqmul016:p9 r:HALF_EVEN (9.99999999999999999 * 9.99999999999999999) inexact rounded", 99.99999999999999980000000000000000, 9.99999999999999999 * 9.99999999999999999);
AddTestCase("dqmul017:p9 r:HALF_EVEN (9.99999999999999999 * -9.99999999999999999) inexact rounded", -99.99999999999999980000000000000000, 9.99999999999999999 * -9.99999999999999999);
AddTestCase("dqmul018:p9 r:HALF_EVEN (-9.99999999999999999 * 9.99999999999999999) inexact rounded", -99.99999999999999980000000000000000, -9.99999999999999999 * 9.99999999999999999);
AddTestCase("dqmul019:p9 r:HALF_EVEN (-9.99999999999999999 * -9.99999999999999999) inexact rounded", 99.99999999999999980000000000000000, -9.99999999999999999 * -9.99999999999999999);
// zeros, etc.
AddTestCase("dqmul021:p9 r:HALF_EVEN (0 * 0)", 0, 0 * 0);
AddTestCase("dqmul022:p9 r:HALF_EVEN (0 * -0)", -0, 0 * -0);
AddTestCase("dqmul023:p9 r:HALF_EVEN (-0 * 0)", -0, -0 * 0);
AddTestCase("dqmul024:p9 r:HALF_EVEN (-0 * -0)", 0, -0 * -0);
AddTestCase("dqmul025:p9 r:HALF_EVEN (-0.0 * -0.0)", 0.00, -0.0 * -0.0);
AddTestCase("dqmul026:p9 r:HALF_EVEN (-0.0 * -0.0)", 0.00, -0.0 * -0.0);
AddTestCase("dqmul027:p9 r:HALF_EVEN (-0.0 * -0.0)", 0.00, -0.0 * -0.0);
AddTestCase("dqmul028:p9 r:HALF_EVEN (-0.0 * -0.0)", 0.00, -0.0 * -0.0);
AddTestCase("dqmul030:p9 r:HALF_EVEN (5.00 * 1e-3)", 0.00500, 5.00 * 1e-3);
AddTestCase("dqmul031:p9 r:HALF_EVEN (00.00 * 0.000)", 0.00000, 00.00 * 0.000);
AddTestCase("dqmul032:p9 r:HALF_EVEN (00.00 * 0e-3) -- rhs is 0", 0.00000, 00.00 * 0e-3);
AddTestCase("dqmul033:p9 r:HALF_EVEN (0e-3 * 00.00) -- lhs is 0", 0.00000, 0e-3 * 00.00);
AddTestCase("dqmul034:p9 r:HALF_EVEN (-5.00 * 1e-3)", -0.00500, -5.00 * 1e-3);
AddTestCase("dqmul035:p9 r:HALF_EVEN (-00.00 * 0.000)", -0.00000, -00.00 * 0.000);
AddTestCase("dqmul036:p9 r:HALF_EVEN (-00.00 * 0e-3) -- rhs is 0", -0.00000, -00.00 * 0e-3);
AddTestCase("dqmul037:p9 r:HALF_EVEN (-0e-3 * 00.00) -- lhs is 0", -0.00000, -0e-3 * 00.00);
AddTestCase("dqmul038:p9 r:HALF_EVEN (5.00 * -1e-3)", -0.00500, 5.00 * -1e-3);
AddTestCase("dqmul039:p9 r:HALF_EVEN (00.00 * -0.000)", -0.00000, 00.00 * -0.000);
AddTestCase("dqmul040:p9 r:HALF_EVEN (00.00 * -0e-3) -- rhs is 0", -0.00000, 00.00 * -0e-3);
AddTestCase("dqmul041:p9 r:HALF_EVEN (0e-3 * -00.00) -- lhs is 0", -0.00000, 0e-3 * -00.00);
AddTestCase("dqmul042:p9 r:HALF_EVEN (-5.00 * -1e-3)", 0.00500, -5.00 * -1e-3);
AddTestCase("dqmul043:p9 r:HALF_EVEN (-00.00 * -0.000)", 0.00000, -00.00 * -0.000);
AddTestCase("dqmul044:p9 r:HALF_EVEN (-00.00 * -0e-3) -- rhs is 0", 0.00000, -00.00 * -0e-3);
AddTestCase("dqmul045:p9 r:HALF_EVEN (-0e-3 * -00.00) -- lhs is 0", 0.00000, -0e-3 * -00.00);
// examples from decarith
AddTestCase("dqmul050:p9 r:HALF_EVEN (1.20 * 3)", 3.60, 1.20 * 3);
AddTestCase("dqmul051:p9 r:HALF_EVEN (7 * 3)", 21, 7 * 3);
AddTestCase("dqmul052:p9 r:HALF_EVEN (0.9 * 0.8)", 0.72, 0.9 * 0.8);
AddTestCase("dqmul053:p9 r:HALF_EVEN (0.9 * -0)", -0.0, 0.9 * -0);
AddTestCase("dqmul054:p9 r:HALF_EVEN (654321 * 654321)", 428135971041, 654321 * 654321);
AddTestCase("dqmul060:p9 r:HALF_EVEN (123.45 * 1e7)", 1.2345e+9, 123.45 * 1e7);
AddTestCase("dqmul061:p9 r:HALF_EVEN (123.45 * 1e8)", 1.2345e+10, 123.45 * 1e8);
AddTestCase("dqmul062:p9 r:HALF_EVEN (123.45 * 1e+9)", 1.2345e+11, 123.45 * 1e+9);
AddTestCase("dqmul063:p9 r:HALF_EVEN (123.45 * 1e10)", 1.2345e+12, 123.45 * 1e10);
AddTestCase("dqmul064:p9 r:HALF_EVEN (123.45 * 1e11)", 1.2345e+13, 123.45 * 1e11);
AddTestCase("dqmul065:p9 r:HALF_EVEN (123.45 * 1e12)", 1.2345e+14, 123.45 * 1e12);
AddTestCase("dqmul066:p9 r:HALF_EVEN (123.45 * 1e13)", 1.2345e+15, 123.45 * 1e13);
// test some intermediate lengths
//                    1234567890123456
AddTestCase("dqmul080:p9 r:HALF_EVEN (0.1 * 1230123456456789)", 123012345645678.9, 0.1 * 1230123456456789);
AddTestCase("dqmul084:p9 r:HALF_EVEN (0.1 * 1230123456456789)", 123012345645678.9, 0.1 * 1230123456456789);
AddTestCase("dqmul090:p9 r:HALF_EVEN (1230123456456789 * 0.1)", 123012345645678.9, 1230123456456789 * 0.1);
AddTestCase("dqmul094:p9 r:HALF_EVEN (1230123456456789 * 0.1)", 123012345645678.9, 1230123456456789 * 0.1);
// test some more edge cases and carries
AddTestCase("dqmul101:p9 r:HALF_EVEN (9 * 9)", 81, 9 * 9);
AddTestCase("dqmul102:p9 r:HALF_EVEN (9 * 90)", 810, 9 * 90);
AddTestCase("dqmul103:p9 r:HALF_EVEN (9 * 900)", 8100, 9 * 900);
AddTestCase("dqmul104:p9 r:HALF_EVEN (9 * 9000)", 81000, 9 * 9000);
AddTestCase("dqmul105:p9 r:HALF_EVEN (9 * 90000)", 810000, 9 * 90000);
AddTestCase("dqmul106:p9 r:HALF_EVEN (9 * 900000)", 8100000, 9 * 900000);
AddTestCase("dqmul107:p9 r:HALF_EVEN (9 * 9000000)", 81000000, 9 * 9000000);
AddTestCase("dqmul108:p9 r:HALF_EVEN (9 * 90000000)", 810000000, 9 * 90000000);
AddTestCase("dqmul109:p9 r:HALF_EVEN (9 * 900000000)", 8100000000, 9 * 900000000);
AddTestCase("dqmul110:p9 r:HALF_EVEN (9 * 9000000000)", 81000000000, 9 * 9000000000);
AddTestCase("dqmul111:p9 r:HALF_EVEN (9 * 90000000000)", 810000000000, 9 * 90000000000);
AddTestCase("dqmul112:p9 r:HALF_EVEN (9 * 900000000000)", 8100000000000, 9 * 900000000000);
AddTestCase("dqmul113:p9 r:HALF_EVEN (9 * 9000000000000)", 81000000000000, 9 * 9000000000000);
AddTestCase("dqmul114:p9 r:HALF_EVEN (9 * 90000000000000)", 810000000000000, 9 * 90000000000000);
AddTestCase("dqmul115:p9 r:HALF_EVEN (9 * 900000000000000)", 8100000000000000, 9 * 900000000000000);
//dqmul116 multiply 9 9000000000000000   -> 81000000000000000
//dqmul117 multiply 9 90000000000000000   -> 810000000000000000
//dqmul118 multiply 9 900000000000000000   -> 8100000000000000000
//dqmul119 multiply 9 9000000000000000000   -> 81000000000000000000
//dqmul120 multiply 9 90000000000000000000   -> 810000000000000000000
//dqmul121 multiply 9 900000000000000000000   -> 8100000000000000000000
//dqmul122 multiply 9 9000000000000000000000   -> 81000000000000000000000
//dqmul123 multiply 9 90000000000000000000000   -> 810000000000000000000000
// test some more edge cases without carries
AddTestCase("dqmul131:p9 r:HALF_EVEN (3 * 3)", 9, 3 * 3);
AddTestCase("dqmul132:p9 r:HALF_EVEN (3 * 30)", 90, 3 * 30);
AddTestCase("dqmul133:p9 r:HALF_EVEN (3 * 300)", 900, 3 * 300);
AddTestCase("dqmul134:p9 r:HALF_EVEN (3 * 3000)", 9000, 3 * 3000);
AddTestCase("dqmul135:p9 r:HALF_EVEN (3 * 30000)", 90000, 3 * 30000);
AddTestCase("dqmul136:p9 r:HALF_EVEN (3 * 300000)", 900000, 3 * 300000);
AddTestCase("dqmul137:p9 r:HALF_EVEN (3 * 3000000)", 9000000, 3 * 3000000);
AddTestCase("dqmul138:p9 r:HALF_EVEN (3 * 30000000)", 90000000, 3 * 30000000);
AddTestCase("dqmul139:p9 r:HALF_EVEN (3 * 300000000)", 900000000, 3 * 300000000);
AddTestCase("dqmul140:p9 r:HALF_EVEN (3 * 3000000000)", 9000000000, 3 * 3000000000);
AddTestCase("dqmul141:p9 r:HALF_EVEN (3 * 30000000000)", 90000000000, 3 * 30000000000);
AddTestCase("dqmul142:p9 r:HALF_EVEN (3 * 300000000000)", 900000000000, 3 * 300000000000);
AddTestCase("dqmul143:p9 r:HALF_EVEN (3 * 3000000000000)", 9000000000000, 3 * 3000000000000);
AddTestCase("dqmul144:p9 r:HALF_EVEN (3 * 30000000000000)", 90000000000000, 3 * 30000000000000);
AddTestCase("dqmul145:p9 r:HALF_EVEN (3 * 300000000000000)", 900000000000000, 3 * 300000000000000);
AddTestCase("dqmul146:p9 r:HALF_EVEN (3 * 3000000000000000)", 9000000000000000, 3 * 3000000000000000);
AddTestCase("dqmul147:p9 r:HALF_EVEN (3 * 30000000000000000)", 90000000000000000, 3 * 30000000000000000);
AddTestCase("dqmul148:p9 r:HALF_EVEN (3 * 300000000000000000)", 900000000000000000, 3 * 300000000000000000);
AddTestCase("dqmul149:p9 r:HALF_EVEN (3 * 3000000000000000000)", 9000000000000000000, 3 * 3000000000000000000);
AddTestCase("dqmul150:p9 r:HALF_EVEN (3 * 30000000000000000000)", 90000000000000000000, 3 * 30000000000000000000);
AddTestCase("dqmul151:p9 r:HALF_EVEN (3 * 300000000000000000000)", 900000000000000000000, 3 * 300000000000000000000);
AddTestCase("dqmul152:p9 r:HALF_EVEN (3 * 3000000000000000000000)", 9000000000000000000000, 3 * 3000000000000000000000);
AddTestCase("dqmul153:p9 r:HALF_EVEN (3 * 30000000000000000000000)", 90000000000000000000000, 3 * 30000000000000000000000);
AddTestCase("dqmul263:p9 r:HALF_EVEN (30269.587755640502150977251770554 * 4.8046009735990873395936309640543) inexact rounded", 145433.2908011933696719165119928296, 30269.587755640502150977251770554 * 4.8046009735990873395936309640543);
// test some edge cases with exact rounding
AddTestCase("dqmul301:p9 r:HALF_EVEN (900000000000000000 * 9)", 8100000000000000000, 900000000000000000 * 9);
AddTestCase("dqmul302:p9 r:HALF_EVEN (900000000000000000 * 90)", 81000000000000000000, 900000000000000000 * 90);
AddTestCase("dqmul303:p9 r:HALF_EVEN (900000000000000000 * 900)", 810000000000000000000, 900000000000000000 * 900);
AddTestCase("dqmul304:p9 r:HALF_EVEN (900000000000000000 * 9000)", 8100000000000000000000, 900000000000000000 * 9000);
AddTestCase("dqmul305:p9 r:HALF_EVEN (900000000000000000 * 90000)", 81000000000000000000000, 900000000000000000 * 90000);
AddTestCase("dqmul306:p9 r:HALF_EVEN (900000000000000000 * 900000)", 810000000000000000000000, 900000000000000000 * 900000);
AddTestCase("dqmul307:p9 r:HALF_EVEN (900000000000000000 * 9000000)", 8100000000000000000000000, 900000000000000000 * 9000000);
AddTestCase("dqmul308:p9 r:HALF_EVEN (900000000000000000 * 90000000)", 81000000000000000000000000, 900000000000000000 * 90000000);
AddTestCase("dqmul309:p9 r:HALF_EVEN (900000000000000000 * 900000000)", 810000000000000000000000000, 900000000000000000 * 900000000);
AddTestCase("dqmul310:p9 r:HALF_EVEN (900000000000000000 * 9000000000)", 8100000000000000000000000000, 900000000000000000 * 9000000000);
AddTestCase("dqmul311:p9 r:HALF_EVEN (900000000000000000 * 90000000000)", 81000000000000000000000000000, 900000000000000000 * 90000000000);
AddTestCase("dqmul312:p9 r:HALF_EVEN (900000000000000000 * 900000000000)", 810000000000000000000000000000, 900000000000000000 * 900000000000);
AddTestCase("dqmul313:p9 r:HALF_EVEN (900000000000000000 * 9000000000000)", 8100000000000000000000000000000, 900000000000000000 * 9000000000000);
AddTestCase("dqmul314:p9 r:HALF_EVEN (900000000000000000 * 90000000000000)", 81000000000000000000000000000000, 900000000000000000 * 90000000000000);
AddTestCase("dqmul315:p9 r:HALF_EVEN (900000000000000000 * 900000000000000)", 810000000000000000000000000000000, 900000000000000000 * 900000000000000);
AddTestCase("dqmul316:p9 r:HALF_EVEN (900000000000000000 * 9000000000000000)", 8100000000000000000000000000000000, 900000000000000000 * 9000000000000000);
AddTestCase("dqmul317:p9 r:HALF_EVEN (9000000000000000000 * 9000000000000000) rounded", 8.100000000000000000000000000000000e+34, 9000000000000000000 * 9000000000000000);
AddTestCase("dqmul318:p9 r:HALF_EVEN (90000000000000000000 * 9000000000000000) rounded", 8.100000000000000000000000000000000e+35, 90000000000000000000 * 9000000000000000);
AddTestCase("dqmul319:p9 r:HALF_EVEN (900000000000000000000 * 9000000000000000) rounded", 8.100000000000000000000000000000000e+36, 900000000000000000000 * 9000000000000000);
AddTestCase("dqmul320:p9 r:HALF_EVEN (9000000000000000000000 * 9000000000000000) rounded", 8.100000000000000000000000000000000e+37, 9000000000000000000000 * 9000000000000000);
AddTestCase("dqmul321:p9 r:HALF_EVEN (90000000000000000000000 * 9000000000000000) rounded", 8.100000000000000000000000000000000e+38, 90000000000000000000000 * 9000000000000000);
AddTestCase("dqmul322:p9 r:HALF_EVEN (900000000000000000000000 * 9000000000000000) rounded", 8.100000000000000000000000000000000e+39, 900000000000000000000000 * 9000000000000000);
AddTestCase("dqmul323:p9 r:HALF_EVEN (9000000000000000000000000 * 9000000000000000) rounded", 8.100000000000000000000000000000000e+40, 9000000000000000000000000 * 9000000000000000);
// tryzeros cases
// mixed with zeros
AddTestCase("dqmul541:p9 r:HALF_EVEN (0 * -1)", -0, 0 * -1);
AddTestCase("dqmul542:p9 r:HALF_EVEN (-0 * -1)", 0, -0 * -1);
AddTestCase("dqmul543:p9 r:HALF_EVEN (0 * 1)", 0, 0 * 1);
AddTestCase("dqmul544:p9 r:HALF_EVEN (-0 * 1)", -0, -0 * 1);
AddTestCase("dqmul545:p9 r:HALF_EVEN (-1 * 0)", -0, -1 * 0);
AddTestCase("dqmul546:p9 r:HALF_EVEN (-1 * -0)", 0, -1 * -0);
AddTestCase("dqmul547:p9 r:HALF_EVEN (1 * 0)", 0, 1 * 0);
AddTestCase("dqmul548:p9 r:HALF_EVEN (1 * -0)", -0, 1 * -0);
AddTestCase("dqmul551:p9 r:HALF_EVEN (0.0 * -1)", -0.0, 0.0 * -1);
AddTestCase("dqmul552:p9 r:HALF_EVEN (-0.0 * -1)", 0.0, -0.0 * -1);
AddTestCase("dqmul553:p9 r:HALF_EVEN (0.0 * 1)", 0.0, 0.0 * 1);
AddTestCase("dqmul554:p9 r:HALF_EVEN (-0.0 * 1)", -0.0, -0.0 * 1);
AddTestCase("dqmul555:p9 r:HALF_EVEN (-1.0 * 0)", -0.0, -1.0 * 0);
AddTestCase("dqmul556:p9 r:HALF_EVEN (-1.0 * -0)", 0.0, -1.0 * -0);
AddTestCase("dqmul557:p9 r:HALF_EVEN (1.0 * 0)", 0.0, 1.0 * 0);
AddTestCase("dqmul558:p9 r:HALF_EVEN (1.0 * -0)", -0.0, 1.0 * -0);
AddTestCase("dqmul561:p9 r:HALF_EVEN (0 * -1.0)", -0.0, 0 * -1.0);
AddTestCase("dqmul562:p9 r:HALF_EVEN (-0 * -1.0)", 0.0, -0 * -1.0);
AddTestCase("dqmul563:p9 r:HALF_EVEN (0 * 1.0)", 0.0, 0 * 1.0);
AddTestCase("dqmul564:p9 r:HALF_EVEN (-0 * 1.0)", -0.0, -0 * 1.0);
AddTestCase("dqmul565:p9 r:HALF_EVEN (-1 * 0.0)", -0.0, -1 * 0.0);
AddTestCase("dqmul566:p9 r:HALF_EVEN (-1 * -0.0)", 0.0, -1 * -0.0);
AddTestCase("dqmul567:p9 r:HALF_EVEN (1 * 0.0)", 0.0, 1 * 0.0);
AddTestCase("dqmul568:p9 r:HALF_EVEN (1 * -0.0)", -0.0, 1 * -0.0);
AddTestCase("dqmul571:p9 r:HALF_EVEN (0.0 * -1.0)", -0.00, 0.0 * -1.0);
AddTestCase("dqmul572:p9 r:HALF_EVEN (-0.0 * -1.0)", 0.00, -0.0 * -1.0);
AddTestCase("dqmul573:p9 r:HALF_EVEN (0.0 * 1.0)", 0.00, 0.0 * 1.0);
AddTestCase("dqmul574:p9 r:HALF_EVEN (-0.0 * 1.0)", -0.00, -0.0 * 1.0);
AddTestCase("dqmul575:p9 r:HALF_EVEN (-1.0 * 0.0)", -0.00, -1.0 * 0.0);
AddTestCase("dqmul576:p9 r:HALF_EVEN (-1.0 * -0.0)", 0.00, -1.0 * -0.0);
AddTestCase("dqmul577:p9 r:HALF_EVEN (1.0 * 0.0)", 0.00, 1.0 * 0.0);
AddTestCase("dqmul578:p9 r:HALF_EVEN (1.0 * -0.0)", -0.00, 1.0 * -0.0);
// specials
AddTestCase("dqmul580:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * decimal.NEGATIVE_INFINITY)", decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul581:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * -1000)", decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY * -1000);
AddTestCase("dqmul582:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * -1)", decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY * -1);
AddTestCase("dqmul583:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * -0) invalid_operation", NaN, decimal.POSITIVE_INFINITY * -0);
AddTestCase("dqmul584:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * 0) invalid_operation", NaN, decimal.POSITIVE_INFINITY * 0);
AddTestCase("dqmul585:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * 1)", decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY * 1);
AddTestCase("dqmul586:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * 1000)", decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY * 1000);
AddTestCase("dqmul587:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * decimal.POSITIVE_INFINITY)", decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul588:p9 r:HALF_EVEN (-1000 * decimal.POSITIVE_INFINITY)", decimal.NEGATIVE_INFINITY, -1000 * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul589:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * decimal.POSITIVE_INFINITY)", decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul590:p9 r:HALF_EVEN (-1 * decimal.POSITIVE_INFINITY)", decimal.NEGATIVE_INFINITY, -1 * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul591:p9 r:HALF_EVEN (-0 * decimal.POSITIVE_INFINITY) invalid_operation", NaN, -0 * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul592:p9 r:HALF_EVEN (0 * decimal.POSITIVE_INFINITY) invalid_operation", NaN, 0 * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul593:p9 r:HALF_EVEN (1 * decimal.POSITIVE_INFINITY)", decimal.POSITIVE_INFINITY, 1 * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul594:p9 r:HALF_EVEN (1000 * decimal.POSITIVE_INFINITY)", decimal.POSITIVE_INFINITY, 1000 * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul595:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * decimal.POSITIVE_INFINITY)", decimal.POSITIVE_INFINITY, decimal.POSITIVE_INFINITY * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul600:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * decimal.NEGATIVE_INFINITY)", decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul601:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * -1000)", decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY * -1000);
AddTestCase("dqmul602:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * -1)", decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY * -1);
AddTestCase("dqmul603:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * -0) invalid_operation", NaN, decimal.NEGATIVE_INFINITY * -0);
AddTestCase("dqmul604:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * 0) invalid_operation", NaN, decimal.NEGATIVE_INFINITY * 0);
AddTestCase("dqmul605:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * 1)", decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY * 1);
AddTestCase("dqmul606:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * 1000)", decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY * 1000);
AddTestCase("dqmul607:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * decimal.POSITIVE_INFINITY)", decimal.NEGATIVE_INFINITY, decimal.NEGATIVE_INFINITY * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul608:p9 r:HALF_EVEN (-1000 * decimal.POSITIVE_INFINITY)", decimal.NEGATIVE_INFINITY, -1000 * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul609:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * decimal.NEGATIVE_INFINITY)", decimal.POSITIVE_INFINITY, decimal.NEGATIVE_INFINITY * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul610:p9 r:HALF_EVEN (-1 * decimal.NEGATIVE_INFINITY)", decimal.POSITIVE_INFINITY, -1 * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul611:p9 r:HALF_EVEN (-0 * decimal.NEGATIVE_INFINITY) invalid_operation", NaN, -0 * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul612:p9 r:HALF_EVEN (0 * decimal.NEGATIVE_INFINITY) invalid_operation", NaN, 0 * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul613:p9 r:HALF_EVEN (1 * decimal.NEGATIVE_INFINITY)", decimal.NEGATIVE_INFINITY, 1 * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul614:p9 r:HALF_EVEN (1000 * decimal.NEGATIVE_INFINITY)", decimal.NEGATIVE_INFINITY, 1000 * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul615:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * decimal.NEGATIVE_INFINITY)", decimal.NEGATIVE_INFINITY, decimal.POSITIVE_INFINITY * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul621:p9 r:HALF_EVEN (NaN * decimal.NEGATIVE_INFINITY)", NaN, NaN * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul622:p9 r:HALF_EVEN (NaN * -1000)", NaN, NaN * -1000);
AddTestCase("dqmul623:p9 r:HALF_EVEN (NaN * -1)", NaN, NaN * -1);
AddTestCase("dqmul624:p9 r:HALF_EVEN (NaN * -0)", NaN, NaN * -0);
AddTestCase("dqmul625:p9 r:HALF_EVEN (NaN * 0)", NaN, NaN * 0);
AddTestCase("dqmul626:p9 r:HALF_EVEN (NaN * 1)", NaN, NaN * 1);
AddTestCase("dqmul627:p9 r:HALF_EVEN (NaN * 1000)", NaN, NaN * 1000);
AddTestCase("dqmul628:p9 r:HALF_EVEN (NaN * decimal.POSITIVE_INFINITY)", NaN, NaN * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul629:p9 r:HALF_EVEN (NaN * NaN)", NaN, NaN * NaN);
AddTestCase("dqmul630:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * NaN)", NaN, decimal.NEGATIVE_INFINITY * NaN);
AddTestCase("dqmul631:p9 r:HALF_EVEN (-1000 * NaN)", NaN, -1000 * NaN);
AddTestCase("dqmul632:p9 r:HALF_EVEN (-1 * NaN)", NaN, -1 * NaN);
AddTestCase("dqmul633:p9 r:HALF_EVEN (-0 * NaN)", NaN, -0 * NaN);
AddTestCase("dqmul634:p9 r:HALF_EVEN (0 * NaN)", NaN, 0 * NaN);
AddTestCase("dqmul635:p9 r:HALF_EVEN (1 * NaN)", NaN, 1 * NaN);
AddTestCase("dqmul636:p9 r:HALF_EVEN (1000 * NaN)", NaN, 1000 * NaN);
AddTestCase("dqmul637:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * NaN)", NaN, decimal.POSITIVE_INFINITY * NaN);
AddTestCase("dqmul641:p9 r:HALF_EVEN (NaN * decimal.NEGATIVE_INFINITY) invalid_operation", NaN, NaN * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul642:p9 r:HALF_EVEN (NaN * -1000) invalid_operation", NaN, NaN * -1000);
AddTestCase("dqmul643:p9 r:HALF_EVEN (NaN * -1) invalid_operation", NaN, NaN * -1);
AddTestCase("dqmul644:p9 r:HALF_EVEN (NaN * -0) invalid_operation", NaN, NaN * -0);
AddTestCase("dqmul645:p9 r:HALF_EVEN (NaN * 0) invalid_operation", NaN, NaN * 0);
AddTestCase("dqmul646:p9 r:HALF_EVEN (NaN * 1) invalid_operation", NaN, NaN * 1);
AddTestCase("dqmul647:p9 r:HALF_EVEN (NaN * 1000) invalid_operation", NaN, NaN * 1000);
AddTestCase("dqmul648:p9 r:HALF_EVEN (NaN * NaN) invalid_operation", NaN, NaN * NaN);
AddTestCase("dqmul649:p9 r:HALF_EVEN (NaN * NaN) invalid_operation", NaN, NaN * NaN);
AddTestCase("dqmul650:p9 r:HALF_EVEN (NaN * NaN) invalid_operation", NaN, NaN * NaN);
AddTestCase("dqmul651:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * NaN) invalid_operation", NaN, decimal.NEGATIVE_INFINITY * NaN);
AddTestCase("dqmul652:p9 r:HALF_EVEN (-1000 * NaN) invalid_operation", NaN, -1000 * NaN);
AddTestCase("dqmul653:p9 r:HALF_EVEN (-1 * NaN) invalid_operation", NaN, -1 * NaN);
AddTestCase("dqmul654:p9 r:HALF_EVEN (-0 * NaN) invalid_operation", NaN, -0 * NaN);
AddTestCase("dqmul655:p9 r:HALF_EVEN (0 * NaN) invalid_operation", NaN, 0 * NaN);
AddTestCase("dqmul656:p9 r:HALF_EVEN (1 * NaN) invalid_operation", NaN, 1 * NaN);
AddTestCase("dqmul657:p9 r:HALF_EVEN (1000 * NaN) invalid_operation", NaN, 1000 * NaN);
AddTestCase("dqmul658:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * NaN) invalid_operation", NaN, decimal.POSITIVE_INFINITY * NaN);
AddTestCase("dqmul659:p9 r:HALF_EVEN (NaN * NaN) invalid_operation", NaN, NaN * NaN);
// propagating nans
AddTestCase("dqmul661:p9 r:HALF_EVEN (NaN * decimal.NEGATIVE_INFINITY)", NaN, NaN * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul662:p9 r:HALF_EVEN (NaN * 999)", NaN, NaN * 999);
AddTestCase("dqmul663:p9 r:HALF_EVEN (NaN * decimal.POSITIVE_INFINITY)", NaN, NaN * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul664:p9 r:HALF_EVEN (NaN * NaN)", NaN, NaN * NaN);
AddTestCase("dqmul665:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * NaN)", NaN, decimal.NEGATIVE_INFINITY * NaN);
AddTestCase("dqmul666:p9 r:HALF_EVEN (-999 * NaN)", NaN, -999 * NaN);
AddTestCase("dqmul667:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * NaN)", NaN, decimal.POSITIVE_INFINITY * NaN);
AddTestCase("dqmul671:p9 r:HALF_EVEN (NaN * decimal.NEGATIVE_INFINITY) invalid_operation", NaN, NaN * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul672:p9 r:HALF_EVEN (NaN * -11) invalid_operation", NaN, NaN * -11);
AddTestCase("dqmul673:p9 r:HALF_EVEN (NaN * NaN) invalid_operation", NaN, NaN * NaN);
AddTestCase("dqmul674:p9 r:HALF_EVEN (NaN * NaN) invalid_operation", NaN, NaN * NaN);
AddTestCase("dqmul675:p9 r:HALF_EVEN (NaN * NaN) invalid_operation", NaN, NaN * NaN);
AddTestCase("dqmul676:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * NaN) invalid_operation", NaN, decimal.NEGATIVE_INFINITY * NaN);
AddTestCase("dqmul677:p9 r:HALF_EVEN (088 * NaN) invalid_operation", NaN, 088 * NaN);
AddTestCase("dqmul678:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * NaN) invalid_operation", NaN, decimal.POSITIVE_INFINITY * NaN);
AddTestCase("dqmul679:p9 r:HALF_EVEN (NaN * NaN) invalid_operation", NaN, NaN * NaN);
AddTestCase("dqmul681:p9 r:HALF_EVEN (-NaN * decimal.NEGATIVE_INFINITY)", -NaN, -NaN * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul682:p9 r:HALF_EVEN (-NaN * 999)", -NaN, -NaN * 999);
AddTestCase("dqmul683:p9 r:HALF_EVEN (-NaN * decimal.POSITIVE_INFINITY)", -NaN, -NaN * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul684:p9 r:HALF_EVEN (-NaN * -NaN)", -NaN, -NaN * -NaN);
AddTestCase("dqmul685:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * -NaN)", -NaN, decimal.NEGATIVE_INFINITY * -NaN);
AddTestCase("dqmul686:p9 r:HALF_EVEN (-999 * -NaN)", -NaN, -999 * -NaN);
AddTestCase("dqmul687:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * -NaN)", -NaN, decimal.POSITIVE_INFINITY * -NaN);
AddTestCase("dqmul691:p9 r:HALF_EVEN (-NaN * decimal.NEGATIVE_INFINITY) invalid_operation", -NaN, -NaN * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul692:p9 r:HALF_EVEN (-NaN * -11) invalid_operation", -NaN, -NaN * -11);
AddTestCase("dqmul693:p9 r:HALF_EVEN (-NaN * NaN) invalid_operation", -NaN, -NaN * NaN);
AddTestCase("dqmul694:p9 r:HALF_EVEN (-NaN * -NaN) invalid_operation", -NaN, -NaN * -NaN);
AddTestCase("dqmul695:p9 r:HALF_EVEN (-NaN * -NaN) invalid_operation", -NaN, -NaN * -NaN);
AddTestCase("dqmul696:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * -NaN) invalid_operation", -NaN, decimal.NEGATIVE_INFINITY * -NaN);
AddTestCase("dqmul697:p9 r:HALF_EVEN (088 * -NaN) invalid_operation", -NaN, 088 * -NaN);
AddTestCase("dqmul698:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * -NaN) invalid_operation", -NaN, decimal.POSITIVE_INFINITY * -NaN);
AddTestCase("dqmul699:p9 r:HALF_EVEN (-NaN * -NaN) invalid_operation", -NaN, -NaN * -NaN);
AddTestCase("dqmul701:p9 r:HALF_EVEN (-NaN * decimal.NEGATIVE_INFINITY)", -NaN, -NaN * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul702:p9 r:HALF_EVEN (-NaN * 999)", -NaN, -NaN * 999);
AddTestCase("dqmul703:p9 r:HALF_EVEN (-NaN * decimal.POSITIVE_INFINITY)", -NaN, -NaN * decimal.POSITIVE_INFINITY);
AddTestCase("dqmul704:p9 r:HALF_EVEN (-NaN * -NaN)", -NaN, -NaN * -NaN);
AddTestCase("dqmul705:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * -NaN)", -NaN, decimal.NEGATIVE_INFINITY * -NaN);
AddTestCase("dqmul706:p9 r:HALF_EVEN (-999 * -NaN)", -NaN, -999 * -NaN);
AddTestCase("dqmul707:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * -NaN)", -NaN, decimal.POSITIVE_INFINITY * -NaN);
AddTestCase("dqmul711:p9 r:HALF_EVEN (-NaN * decimal.NEGATIVE_INFINITY) invalid_operation", -NaN, -NaN * decimal.NEGATIVE_INFINITY);
AddTestCase("dqmul712:p9 r:HALF_EVEN (-NaN * -11) invalid_operation", -NaN, -NaN * -11);
AddTestCase("dqmul713:p9 r:HALF_EVEN (-NaN * NaN) invalid_operation", -NaN, -NaN * NaN);
AddTestCase("dqmul714:p9 r:HALF_EVEN (-NaN * -NaN) invalid_operation", -NaN, -NaN * -NaN);
AddTestCase("dqmul715:p9 r:HALF_EVEN (-NaN * -NaN) invalid_operation", -NaN, -NaN * -NaN);
AddTestCase("dqmul716:p9 r:HALF_EVEN (decimal.NEGATIVE_INFINITY * -NaN) invalid_operation", -NaN, decimal.NEGATIVE_INFINITY * -NaN);
AddTestCase("dqmul717:p9 r:HALF_EVEN (088 * -NaN) invalid_operation", -NaN, 088 * -NaN);
AddTestCase("dqmul718:p9 r:HALF_EVEN (decimal.POSITIVE_INFINITY * -NaN) invalid_operation", -NaN, decimal.POSITIVE_INFINITY * -NaN);
AddTestCase("dqmul719:p9 r:HALF_EVEN (-NaN * -NaN) invalid_operation", -NaN, -NaN * -NaN);
// overflow and underflow tests .. note subnormal results
// signs
// 'subnormal' boundary (all hard underflow or overflow in base arithemtic)
// [no equivalent of 'subnormal' for overflow]
AddTestCase("dqmul840:p9 r:HALF_EVEN (40.0e-5982 * 40e-164)", 1.6000e-6143, 40.0e-5982 * 40e-164);
// long operand overflow may be a different path
// check for double-rounded subnormals
// now explore the case where we get a normal result with underflow
// prove operands are exact
AddTestCase("dqmul906:p9 r:HALF_EVEN (9.999999999999999999999999999999999e-6143 * 1)", 9.999999999999999999999999999999999e-6143, 9.999999999999999999999999999999999e-6143 * 1);
AddTestCase("dqmul907:p9 r:HALF_EVEN (1 * 0.09999999999999999999999999999999999)", 0.09999999999999999999999999999999999, 1 * 0.09999999999999999999999999999999999);
// the next rounds to nmin
// hugest
AddTestCase("dqmul909:p9 r:HALF_EVEN (9999999999999999999999999999999999 * 9999999999999999999999999999999999) inexact rounded", 9.999999999999999999999999999999998e+67, 9999999999999999999999999999999999 * 9999999999999999999999999999999999);
// examples from sql proposal (krishna kulkarni)
{
	use rounding HALF_UP;
	AddTestCase("dqmul1001:p9 r:HALF_UP (130e-2 * 120e-2)", 1.5600, 130e-2 * 120e-2);
	AddTestCase("dqmul1002:p9 r:HALF_UP (130e-2 * 12e-1)", 1.560, 130e-2 * 12e-1);
	AddTestCase("dqmul1003:p9 r:HALF_UP (130e-2 * 1e0)", 1.30, 130e-2 * 1e0);
	AddTestCase("dqmul1004:p9 r:HALF_UP (1e2 * 1e4)", 1e+6, 1e2 * 1e4);
	// null tests
	AddTestCase("dqmul990:p9 r:HALF_UP (10 * null) invalid_operation", 0, 10 * null);
	AddTestCase("dqmul991:p9 r:HALF_UP (null * 10) invalid_operation", 0, null * 10);
	}
}
test();
