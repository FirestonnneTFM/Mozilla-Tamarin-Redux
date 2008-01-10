use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "dqMin.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// dqmin.dectest -- decquad minnum                                    --
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
// we assume that base comparison is tested in compare.dectest, so
// these mainly cover special cases and rounding
use rounding HALF_EVEN;
// sanity checks
AddTestCase("dqmin001:p9 r:HALF_EVEN (decimal.min(-2,-2))", -2, decimal.min(-2,-2));
AddTestCase("dqmin002:p9 r:HALF_EVEN (decimal.min(-2,-1))", -2, decimal.min(-2,-1));
AddTestCase("dqmin003:p9 r:HALF_EVEN (decimal.min(-2,0))", -2, decimal.min(-2,0));
AddTestCase("dqmin004:p9 r:HALF_EVEN (decimal.min(-2,1))", -2, decimal.min(-2,1));
AddTestCase("dqmin005:p9 r:HALF_EVEN (decimal.min(-2,2))", -2, decimal.min(-2,2));
AddTestCase("dqmin006:p9 r:HALF_EVEN (decimal.min(-1,-2))", -2, decimal.min(-1,-2));
AddTestCase("dqmin007:p9 r:HALF_EVEN (decimal.min(-1,-1))", -1, decimal.min(-1,-1));
AddTestCase("dqmin008:p9 r:HALF_EVEN (decimal.min(-1,0))", -1, decimal.min(-1,0));
AddTestCase("dqmin009:p9 r:HALF_EVEN (decimal.min(-1,1))", -1, decimal.min(-1,1));
AddTestCase("dqmin010:p9 r:HALF_EVEN (decimal.min(-1,2))", -1, decimal.min(-1,2));
AddTestCase("dqmin011:p9 r:HALF_EVEN (decimal.min(0,-2))", -2, decimal.min(0,-2));
AddTestCase("dqmin012:p9 r:HALF_EVEN (decimal.min(0,-1))", -1, decimal.min(0,-1));
AddTestCase("dqmin013:p9 r:HALF_EVEN (decimal.min(0,0))", 0, decimal.min(0,0));
AddTestCase("dqmin014:p9 r:HALF_EVEN (decimal.min(0,1))", 0, decimal.min(0,1));
AddTestCase("dqmin015:p9 r:HALF_EVEN (decimal.min(0,2))", 0, decimal.min(0,2));
AddTestCase("dqmin016:p9 r:HALF_EVEN (decimal.min(1,-2))", -2, decimal.min(1,-2));
AddTestCase("dqmin017:p9 r:HALF_EVEN (decimal.min(1,-1))", -1, decimal.min(1,-1));
AddTestCase("dqmin018:p9 r:HALF_EVEN (decimal.min(1,0))", 0, decimal.min(1,0));
AddTestCase("dqmin019:p9 r:HALF_EVEN (decimal.min(1,1))", 1, decimal.min(1,1));
AddTestCase("dqmin020:p9 r:HALF_EVEN (decimal.min(1,2))", 1, decimal.min(1,2));
AddTestCase("dqmin021:p9 r:HALF_EVEN (decimal.min(2,-2))", -2, decimal.min(2,-2));
AddTestCase("dqmin022:p9 r:HALF_EVEN (decimal.min(2,-1))", -1, decimal.min(2,-1));
AddTestCase("dqmin023:p9 r:HALF_EVEN (decimal.min(2,0))", 0, decimal.min(2,0));
AddTestCase("dqmin025:p9 r:HALF_EVEN (decimal.min(2,1))", 1, decimal.min(2,1));
AddTestCase("dqmin026:p9 r:HALF_EVEN (decimal.min(2,2))", 2, decimal.min(2,2));
// extended zeros
AddTestCase("dqmin030:p9 r:HALF_EVEN (decimal.min(0,0))", 0, decimal.min(0,0));
AddTestCase("dqmin031:p9 r:HALF_EVEN (decimal.min(0,-0))", -0, decimal.min(0,-0));
AddTestCase("dqmin032:p9 r:HALF_EVEN (decimal.min(0,-0.0))", -0.0, decimal.min(0,-0.0));
AddTestCase("dqmin033:p9 r:HALF_EVEN (decimal.min(0,0.0))", 0.0, decimal.min(0,0.0));
AddTestCase("dqmin034:p9 r:HALF_EVEN (decimal.min(-0,0))", -0, decimal.min(-0,0));
AddTestCase("dqmin035:p9 r:HALF_EVEN (decimal.min(-0,-0))", -0, decimal.min(-0,-0));
AddTestCase("dqmin036:p9 r:HALF_EVEN (decimal.min(-0,-0.0))", -0, decimal.min(-0,-0.0));
AddTestCase("dqmin037:p9 r:HALF_EVEN (decimal.min(-0,0.0))", -0, decimal.min(-0,0.0));
AddTestCase("dqmin038:p9 r:HALF_EVEN (decimal.min(0.0,0))", 0.0, decimal.min(0.0,0));
AddTestCase("dqmin039:p9 r:HALF_EVEN (decimal.min(0.0,-0))", -0, decimal.min(0.0,-0));
AddTestCase("dqmin040:p9 r:HALF_EVEN (decimal.min(0.0,-0.0))", -0.0, decimal.min(0.0,-0.0));
AddTestCase("dqmin041:p9 r:HALF_EVEN (decimal.min(0.0,0.0))", 0.0, decimal.min(0.0,0.0));
AddTestCase("dqmin042:p9 r:HALF_EVEN (decimal.min(-0.0,0))", -0.0, decimal.min(-0.0,0));
AddTestCase("dqmin043:p9 r:HALF_EVEN (decimal.min(-0.0,-0))", -0, decimal.min(-0.0,-0));
AddTestCase("dqmin044:p9 r:HALF_EVEN (decimal.min(-0.0,-0.0))", -0.0, decimal.min(-0.0,-0.0));
AddTestCase("dqmin045:p9 r:HALF_EVEN (decimal.min(-0.0,0.0))", -0.0, decimal.min(-0.0,0.0));
AddTestCase("dqmin046:p9 r:HALF_EVEN (decimal.min(0e1,-0e1))", -0e+1, decimal.min(0e1,-0e1));
AddTestCase("dqmin047:p9 r:HALF_EVEN (decimal.min(-0e1,0e2))", -0e+1, decimal.min(-0e1,0e2));
AddTestCase("dqmin048:p9 r:HALF_EVEN (decimal.min(0e2,0e1))", 0e+1, decimal.min(0e2,0e1));
AddTestCase("dqmin049:p9 r:HALF_EVEN (decimal.min(0e1,0e2))", 0e+1, decimal.min(0e1,0e2));
AddTestCase("dqmin050:p9 r:HALF_EVEN (decimal.min(-0e3,-0e2))", -0e+3, decimal.min(-0e3,-0e2));
AddTestCase("dqmin051:p9 r:HALF_EVEN (decimal.min(-0e2,-0e3))", -0e+3, decimal.min(-0e2,-0e3));
// specials
AddTestCase("dqmin090:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin091:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,-1000))", -1000, decimal.min(decimal.POSITIVE_INFINITY,-1000));
AddTestCase("dqmin092:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,-1))", -1, decimal.min(decimal.POSITIVE_INFINITY,-1));
AddTestCase("dqmin093:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,-0))", -0, decimal.min(decimal.POSITIVE_INFINITY,-0));
AddTestCase("dqmin094:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,0))", 0, decimal.min(decimal.POSITIVE_INFINITY,0));
AddTestCase("dqmin095:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,1))", 1, decimal.min(decimal.POSITIVE_INFINITY,1));
AddTestCase("dqmin096:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,1000))", 1000, decimal.min(decimal.POSITIVE_INFINITY,1000));
AddTestCase("dqmin097:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.min(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin098:p9 r:HALF_EVEN (decimal.min(-1000,decimal.POSITIVE_INFINITY))", -1000, decimal.min(-1000,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin099:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin100:p9 r:HALF_EVEN (decimal.min(-1,decimal.POSITIVE_INFINITY))", -1, decimal.min(-1,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin101:p9 r:HALF_EVEN (decimal.min(-0,decimal.POSITIVE_INFINITY))", -0, decimal.min(-0,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin102:p9 r:HALF_EVEN (decimal.min(0,decimal.POSITIVE_INFINITY))", 0, decimal.min(0,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin103:p9 r:HALF_EVEN (decimal.min(1,decimal.POSITIVE_INFINITY))", 1, decimal.min(1,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin104:p9 r:HALF_EVEN (decimal.min(1000,decimal.POSITIVE_INFINITY))", 1000, decimal.min(1000,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin105:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.min(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin120:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin121:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,-1000))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.NEGATIVE_INFINITY,-1000));
AddTestCase("dqmin122:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,-1))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.NEGATIVE_INFINITY,-1));
AddTestCase("dqmin123:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,-0))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.NEGATIVE_INFINITY,-0));
AddTestCase("dqmin124:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,0))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.NEGATIVE_INFINITY,0));
AddTestCase("dqmin125:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,1))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.NEGATIVE_INFINITY,1));
AddTestCase("dqmin126:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,1000))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.NEGATIVE_INFINITY,1000));
AddTestCase("dqmin127:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin128:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin129:p9 r:HALF_EVEN (decimal.min(-1000,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(-1000,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin130:p9 r:HALF_EVEN (decimal.min(-1,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(-1,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin131:p9 r:HALF_EVEN (decimal.min(-0,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(-0,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin132:p9 r:HALF_EVEN (decimal.min(0,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(0,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin133:p9 r:HALF_EVEN (decimal.min(1,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(1,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin134:p9 r:HALF_EVEN (decimal.min(1000,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(1000,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin135:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY));
// 2004.08.02 754r chooses number over nan in mixed cases
AddTestCase("dqmin141:p9 r:HALF_EVEN (decimal.min(NaN,decimal.NEGATIVE_INFINITY))", NaN, decimal.min(NaN,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin142:p9 r:HALF_EVEN (decimal.min(NaN,-1000))", NaN, decimal.min(NaN,-1000));
AddTestCase("dqmin143:p9 r:HALF_EVEN (decimal.min(NaN,-1))", NaN, decimal.min(NaN,-1));
AddTestCase("dqmin144:p9 r:HALF_EVEN (decimal.min(NaN,-0))", NaN, decimal.min(NaN,-0));
AddTestCase("dqmin145:p9 r:HALF_EVEN (decimal.min(NaN,0))", NaN, decimal.min(NaN,0));
AddTestCase("dqmin146:p9 r:HALF_EVEN (decimal.min(NaN,1))", NaN, decimal.min(NaN,1));
AddTestCase("dqmin147:p9 r:HALF_EVEN (decimal.min(NaN,1000))", NaN, decimal.min(NaN,1000));
AddTestCase("dqmin148:p9 r:HALF_EVEN (decimal.min(NaN,decimal.POSITIVE_INFINITY))", NaN, decimal.min(NaN,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin149:p9 r:HALF_EVEN (decimal.min(NaN,NaN))", NaN, decimal.min(NaN,NaN));
AddTestCase("dqmin150:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,NaN))", NaN, decimal.min(decimal.NEGATIVE_INFINITY,NaN));
AddTestCase("dqmin151:p9 r:HALF_EVEN (decimal.min(-1000,NaN))", NaN, decimal.min(-1000,NaN));
AddTestCase("dqmin152:p9 r:HALF_EVEN (decimal.min(-1,-NaN))", NaN, decimal.min(-1,-NaN));
AddTestCase("dqmin153:p9 r:HALF_EVEN (decimal.min(-0,NaN))", NaN, decimal.min(-0,NaN));
AddTestCase("dqmin154:p9 r:HALF_EVEN (decimal.min(0,-NaN))", NaN, decimal.min(0,-NaN));
AddTestCase("dqmin155:p9 r:HALF_EVEN (decimal.min(1,NaN))", NaN, decimal.min(1,NaN));
AddTestCase("dqmin156:p9 r:HALF_EVEN (decimal.min(1000,NaN))", NaN, decimal.min(1000,NaN));
AddTestCase("dqmin157:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,NaN))", NaN, decimal.min(decimal.POSITIVE_INFINITY,NaN));
AddTestCase("dqmin161:p9 r:HALF_EVEN (decimal.min(NaN,decimal.NEGATIVE_INFINITY)) invalid_operation", NaN, decimal.min(NaN,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin162:p9 r:HALF_EVEN (decimal.min(NaN,-1000)) invalid_operation", NaN, decimal.min(NaN,-1000));
AddTestCase("dqmin163:p9 r:HALF_EVEN (decimal.min(NaN,-1)) invalid_operation", NaN, decimal.min(NaN,-1));
AddTestCase("dqmin164:p9 r:HALF_EVEN (decimal.min(NaN,-0)) invalid_operation", NaN, decimal.min(NaN,-0));
AddTestCase("dqmin165:p9 r:HALF_EVEN (decimal.min(-NaN,0)) invalid_operation", -NaN, decimal.min(-NaN,0));
AddTestCase("dqmin166:p9 r:HALF_EVEN (decimal.min(-NaN,1)) invalid_operation", -NaN, decimal.min(-NaN,1));
AddTestCase("dqmin167:p9 r:HALF_EVEN (decimal.min(NaN,1000)) invalid_operation", NaN, decimal.min(NaN,1000));
AddTestCase("dqmin168:p9 r:HALF_EVEN (decimal.min(NaN,NaN)) invalid_operation", NaN, decimal.min(NaN,NaN));
AddTestCase("dqmin169:p9 r:HALF_EVEN (decimal.min(NaN,NaN)) invalid_operation", NaN, decimal.min(NaN,NaN));
AddTestCase("dqmin170:p9 r:HALF_EVEN (decimal.min(NaN,NaN)) invalid_operation", NaN, decimal.min(NaN,NaN));
AddTestCase("dqmin171:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,NaN)) invalid_operation", NaN, decimal.min(decimal.NEGATIVE_INFINITY,NaN));
AddTestCase("dqmin172:p9 r:HALF_EVEN (decimal.min(-1000,NaN)) invalid_operation", NaN, decimal.min(-1000,NaN));
AddTestCase("dqmin173:p9 r:HALF_EVEN (decimal.min(-1,NaN)) invalid_operation", NaN, decimal.min(-1,NaN));
AddTestCase("dqmin174:p9 r:HALF_EVEN (decimal.min(-0,NaN)) invalid_operation", NaN, decimal.min(-0,NaN));
AddTestCase("dqmin175:p9 r:HALF_EVEN (decimal.min(0,NaN)) invalid_operation", NaN, decimal.min(0,NaN));
AddTestCase("dqmin176:p9 r:HALF_EVEN (decimal.min(1,NaN)) invalid_operation", NaN, decimal.min(1,NaN));
AddTestCase("dqmin177:p9 r:HALF_EVEN (decimal.min(1000,NaN)) invalid_operation", NaN, decimal.min(1000,NaN));
AddTestCase("dqmin178:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,NaN)) invalid_operation", NaN, decimal.min(decimal.POSITIVE_INFINITY,NaN));
AddTestCase("dqmin179:p9 r:HALF_EVEN (decimal.min(NaN,NaN)) invalid_operation", NaN, decimal.min(NaN,NaN));
// propagating nans
AddTestCase("dqmin181:p9 r:HALF_EVEN (decimal.min(NaN,decimal.NEGATIVE_INFINITY))", NaN, decimal.min(NaN,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin182:p9 r:HALF_EVEN (decimal.min(-NaN,9990))", NaN, decimal.min(-NaN,9990));
AddTestCase("dqmin183:p9 r:HALF_EVEN (decimal.min(NaN,decimal.POSITIVE_INFINITY))", NaN, decimal.min(NaN,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin184:p9 r:HALF_EVEN (decimal.min(NaN,NaN))", NaN, decimal.min(NaN,NaN));
AddTestCase("dqmin185:p9 r:HALF_EVEN (decimal.min(NaN,-NaN))", NaN, decimal.min(NaN,-NaN));
AddTestCase("dqmin186:p9 r:HALF_EVEN (decimal.min(-NaN,NaN))", -NaN, decimal.min(-NaN,NaN));
AddTestCase("dqmin187:p9 r:HALF_EVEN (decimal.min(-NaN,NaN))", -NaN, decimal.min(-NaN,NaN));
AddTestCase("dqmin188:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,NaN))", NaN, decimal.min(decimal.NEGATIVE_INFINITY,NaN));
AddTestCase("dqmin189:p9 r:HALF_EVEN (decimal.min(-9999,-NaN))", NaN, decimal.min(-9999,-NaN));
AddTestCase("dqmin190:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,NaN))", NaN, decimal.min(decimal.POSITIVE_INFINITY,NaN));
AddTestCase("dqmin191:p9 r:HALF_EVEN (decimal.min(NaN,decimal.NEGATIVE_INFINITY)) invalid_operation", NaN, decimal.min(NaN,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmin192:p9 r:HALF_EVEN (decimal.min(NaN,-11)) invalid_operation", NaN, decimal.min(NaN,-11));
AddTestCase("dqmin193:p9 r:HALF_EVEN (decimal.min(-NaN,NaN)) invalid_operation", -NaN, decimal.min(-NaN,NaN));
AddTestCase("dqmin194:p9 r:HALF_EVEN (decimal.min(NaN,NaN)) invalid_operation", NaN, decimal.min(NaN,NaN));
AddTestCase("dqmin195:p9 r:HALF_EVEN (decimal.min(NaN,NaN)) invalid_operation", NaN, decimal.min(NaN,NaN));
AddTestCase("dqmin196:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,NaN)) invalid_operation", NaN, decimal.min(decimal.NEGATIVE_INFINITY,NaN));
AddTestCase("dqmin197:p9 r:HALF_EVEN (decimal.min(088,NaN)) invalid_operation", NaN, decimal.min(088,NaN));
AddTestCase("dqmin198:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,-NaN)) invalid_operation", -NaN, decimal.min(decimal.POSITIVE_INFINITY,-NaN));
AddTestCase("dqmin199:p9 r:HALF_EVEN (decimal.min(NaN,NaN)) invalid_operation", NaN, decimal.min(NaN,NaN));
// old rounding checks
AddTestCase("dqmin221:p9 r:HALF_EVEN (decimal.min(-12345678000,1))", -12345678000, decimal.min(-12345678000,1));
AddTestCase("dqmin222:p9 r:HALF_EVEN (decimal.min(1,-12345678000))", -12345678000, decimal.min(1,-12345678000));
AddTestCase("dqmin223:p9 r:HALF_EVEN (decimal.min(-1234567800,1))", -1234567800, decimal.min(-1234567800,1));
AddTestCase("dqmin224:p9 r:HALF_EVEN (decimal.min(1,-1234567800))", -1234567800, decimal.min(1,-1234567800));
AddTestCase("dqmin225:p9 r:HALF_EVEN (decimal.min(-1234567890,1))", -1234567890, decimal.min(-1234567890,1));
AddTestCase("dqmin226:p9 r:HALF_EVEN (decimal.min(1,-1234567890))", -1234567890, decimal.min(1,-1234567890));
AddTestCase("dqmin227:p9 r:HALF_EVEN (decimal.min(-1234567891,1))", -1234567891, decimal.min(-1234567891,1));
AddTestCase("dqmin228:p9 r:HALF_EVEN (decimal.min(1,-1234567891))", -1234567891, decimal.min(1,-1234567891));
AddTestCase("dqmin229:p9 r:HALF_EVEN (decimal.min(-12345678901,1))", -12345678901, decimal.min(-12345678901,1));
AddTestCase("dqmin230:p9 r:HALF_EVEN (decimal.min(1,-12345678901))", -12345678901, decimal.min(1,-12345678901));
AddTestCase("dqmin231:p9 r:HALF_EVEN (decimal.min(-1234567896,1))", -1234567896, decimal.min(-1234567896,1));
AddTestCase("dqmin232:p9 r:HALF_EVEN (decimal.min(1,-1234567896))", -1234567896, decimal.min(1,-1234567896));
AddTestCase("dqmin233:p9 r:HALF_EVEN (decimal.min(1234567891,1))", 1, decimal.min(1234567891,1));
AddTestCase("dqmin234:p9 r:HALF_EVEN (decimal.min(1,1234567891))", 1, decimal.min(1,1234567891));
AddTestCase("dqmin235:p9 r:HALF_EVEN (decimal.min(12345678901,1))", 1, decimal.min(12345678901,1));
AddTestCase("dqmin236:p9 r:HALF_EVEN (decimal.min(1,12345678901))", 1, decimal.min(1,12345678901));
AddTestCase("dqmin237:p9 r:HALF_EVEN (decimal.min(1234567896,1))", 1, decimal.min(1234567896,1));
AddTestCase("dqmin238:p9 r:HALF_EVEN (decimal.min(1,1234567896))", 1, decimal.min(1,1234567896));
// from examples
AddTestCase("dqmin280:p9 r:HALF_EVEN (decimal.min(3,2))", 2, decimal.min(3,2));
AddTestCase("dqmin281:p9 r:HALF_EVEN (decimal.min(-10,3))", -10, decimal.min(-10,3));
AddTestCase("dqmin282:p9 r:HALF_EVEN (decimal.min(1.0,1))", 1.0, decimal.min(1.0,1));
AddTestCase("dqmin283:p9 r:HALF_EVEN (decimal.min(1,1.0))", 1.0, decimal.min(1,1.0));
AddTestCase("dqmin284:p9 r:HALF_EVEN (decimal.min(7,NaN))", NaN, decimal.min(7,NaN));
// expanded list from min/max 754r purple prose
// [explicit tests for exponent ordering]
AddTestCase("dqmin401:p9 r:HALF_EVEN (decimal.min(decimal.POSITIVE_INFINITY,1.1))", 1.1, decimal.min(decimal.POSITIVE_INFINITY,1.1));
AddTestCase("dqmin402:p9 r:HALF_EVEN (decimal.min(1.1,1))", 1, decimal.min(1.1,1));
AddTestCase("dqmin403:p9 r:HALF_EVEN (decimal.min(1,1.0))", 1.0, decimal.min(1,1.0));
AddTestCase("dqmin404:p9 r:HALF_EVEN (decimal.min(1.0,0.1))", 0.1, decimal.min(1.0,0.1));
AddTestCase("dqmin405:p9 r:HALF_EVEN (decimal.min(0.1,0.10))", 0.10, decimal.min(0.1,0.10));
AddTestCase("dqmin406:p9 r:HALF_EVEN (decimal.min(0.10,0.100))", 0.100, decimal.min(0.10,0.100));
AddTestCase("dqmin407:p9 r:HALF_EVEN (decimal.min(0.10,0))", 0, decimal.min(0.10,0));
AddTestCase("dqmin408:p9 r:HALF_EVEN (decimal.min(0,0.0))", 0.0, decimal.min(0,0.0));
AddTestCase("dqmin409:p9 r:HALF_EVEN (decimal.min(0.0,-0))", -0, decimal.min(0.0,-0));
AddTestCase("dqmin410:p9 r:HALF_EVEN (decimal.min(0.0,-0.0))", -0.0, decimal.min(0.0,-0.0));
AddTestCase("dqmin411:p9 r:HALF_EVEN (decimal.min(0.00,-0.0))", -0.0, decimal.min(0.00,-0.0));
AddTestCase("dqmin412:p9 r:HALF_EVEN (decimal.min(0.0,-0.00))", -0.00, decimal.min(0.0,-0.00));
AddTestCase("dqmin413:p9 r:HALF_EVEN (decimal.min(0,-0.0))", -0.0, decimal.min(0,-0.0));
AddTestCase("dqmin414:p9 r:HALF_EVEN (decimal.min(0,-0))", -0, decimal.min(0,-0));
AddTestCase("dqmin415:p9 r:HALF_EVEN (decimal.min(-0.0,-0))", -0, decimal.min(-0.0,-0));
AddTestCase("dqmin416:p9 r:HALF_EVEN (decimal.min(-0,-0.100))", -0.100, decimal.min(-0,-0.100));
AddTestCase("dqmin417:p9 r:HALF_EVEN (decimal.min(-0.100,-0.10))", -0.10, decimal.min(-0.100,-0.10));
AddTestCase("dqmin418:p9 r:HALF_EVEN (decimal.min(-0.10,-0.1))", -0.1, decimal.min(-0.10,-0.1));
AddTestCase("dqmin419:p9 r:HALF_EVEN (decimal.min(-0.1,-1.0))", -1.0, decimal.min(-0.1,-1.0));
AddTestCase("dqmin420:p9 r:HALF_EVEN (decimal.min(-1.0,-1))", -1, decimal.min(-1.0,-1));
AddTestCase("dqmin421:p9 r:HALF_EVEN (decimal.min(-1,-1.1))", -1.1, decimal.min(-1,-1.1));
AddTestCase("dqmin423:p9 r:HALF_EVEN (decimal.min(-1.1,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.min(-1.1,decimal.NEGATIVE_INFINITY));
// same with operands reversed
AddTestCase("dqmin431:p9 r:HALF_EVEN (decimal.min(1.1,decimal.POSITIVE_INFINITY))", 1.1, decimal.min(1.1,decimal.POSITIVE_INFINITY));
AddTestCase("dqmin432:p9 r:HALF_EVEN (decimal.min(1,1.1))", 1, decimal.min(1,1.1));
AddTestCase("dqmin433:p9 r:HALF_EVEN (decimal.min(1.0,1))", 1.0, decimal.min(1.0,1));
AddTestCase("dqmin434:p9 r:HALF_EVEN (decimal.min(0.1,1.0))", 0.1, decimal.min(0.1,1.0));
AddTestCase("dqmin435:p9 r:HALF_EVEN (decimal.min(0.10,0.1))", 0.10, decimal.min(0.10,0.1));
AddTestCase("dqmin436:p9 r:HALF_EVEN (decimal.min(0.100,0.10))", 0.100, decimal.min(0.100,0.10));
AddTestCase("dqmin437:p9 r:HALF_EVEN (decimal.min(0,0.10))", 0, decimal.min(0,0.10));
AddTestCase("dqmin438:p9 r:HALF_EVEN (decimal.min(0.0,0))", 0.0, decimal.min(0.0,0));
AddTestCase("dqmin439:p9 r:HALF_EVEN (decimal.min(-0,0.0))", -0, decimal.min(-0,0.0));
AddTestCase("dqmin440:p9 r:HALF_EVEN (decimal.min(-0.0,0.0))", -0.0, decimal.min(-0.0,0.0));
AddTestCase("dqmin441:p9 r:HALF_EVEN (decimal.min(-0.0,0.00))", -0.0, decimal.min(-0.0,0.00));
AddTestCase("dqmin442:p9 r:HALF_EVEN (decimal.min(-0.00,0.0))", -0.00, decimal.min(-0.00,0.0));
AddTestCase("dqmin443:p9 r:HALF_EVEN (decimal.min(-0.0,0))", -0.0, decimal.min(-0.0,0));
AddTestCase("dqmin444:p9 r:HALF_EVEN (decimal.min(-0,0))", -0, decimal.min(-0,0));
AddTestCase("dqmin445:p9 r:HALF_EVEN (decimal.min(-0,-0.0))", -0, decimal.min(-0,-0.0));
AddTestCase("dqmin446:p9 r:HALF_EVEN (decimal.min(-0.100,-0))", -0.100, decimal.min(-0.100,-0));
AddTestCase("dqmin447:p9 r:HALF_EVEN (decimal.min(-0.10,-0.100))", -0.10, decimal.min(-0.10,-0.100));
AddTestCase("dqmin448:p9 r:HALF_EVEN (decimal.min(-0.1,-0.10))", -0.1, decimal.min(-0.1,-0.10));
AddTestCase("dqmin449:p9 r:HALF_EVEN (decimal.min(-1.0,-0.1))", -1.0, decimal.min(-1.0,-0.1));
AddTestCase("dqmin450:p9 r:HALF_EVEN (decimal.min(-1,-1.0))", -1, decimal.min(-1,-1.0));
AddTestCase("dqmin451:p9 r:HALF_EVEN (decimal.min(-1.1,-1))", -1.1, decimal.min(-1.1,-1));
AddTestCase("dqmin453:p9 r:HALF_EVEN (decimal.min(decimal.NEGATIVE_INFINITY,-1.1))", decimal.NEGATIVE_INFINITY, decimal.min(decimal.NEGATIVE_INFINITY,-1.1));
// largies
AddTestCase("dqmin460:p9 r:HALF_EVEN (decimal.min(1000,1e+3))", 1000, decimal.min(1000,1e+3));
AddTestCase("dqmin461:p9 r:HALF_EVEN (decimal.min(1e+3,1000))", 1000, decimal.min(1e+3,1000));
AddTestCase("dqmin462:p9 r:HALF_EVEN (decimal.min(1000,-1e+3))", -1e+3, decimal.min(1000,-1e+3));
AddTestCase("dqmin463:p9 r:HALF_EVEN (decimal.min(1e+3,-384))", -384, decimal.min(1e+3,-384));
AddTestCase("dqmin464:p9 r:HALF_EVEN (decimal.min(-384,1e+3))", -384, decimal.min(-384,1e+3));
AddTestCase("dqmin465:p9 r:HALF_EVEN (decimal.min(-1e+3,1000))", -1e+3, decimal.min(-1e+3,1000));
AddTestCase("dqmin466:p9 r:HALF_EVEN (decimal.min(-384,-1e+3))", -1e+3, decimal.min(-384,-1e+3));
AddTestCase("dqmin467:p9 r:HALF_EVEN (decimal.min(-1e+3,-384))", -1e+3, decimal.min(-1e+3,-384));
// misalignment traps for little-endian
AddTestCase("dqmin471:p9 r:HALF_EVEN (decimal.min(1.0,0.1))", 0.1, decimal.min(1.0,0.1));
AddTestCase("dqmin472:p9 r:HALF_EVEN (decimal.min(0.1,1.0))", 0.1, decimal.min(0.1,1.0));
AddTestCase("dqmin473:p9 r:HALF_EVEN (decimal.min(10.0,0.1))", 0.1, decimal.min(10.0,0.1));
AddTestCase("dqmin474:p9 r:HALF_EVEN (decimal.min(0.1,10.0))", 0.1, decimal.min(0.1,10.0));
AddTestCase("dqmin475:p9 r:HALF_EVEN (decimal.min(100,1.0))", 1.0, decimal.min(100,1.0));
AddTestCase("dqmin476:p9 r:HALF_EVEN (decimal.min(1.0,100))", 1.0, decimal.min(1.0,100));
AddTestCase("dqmin477:p9 r:HALF_EVEN (decimal.min(1000,10.0))", 10.0, decimal.min(1000,10.0));
AddTestCase("dqmin478:p9 r:HALF_EVEN (decimal.min(10.0,1000))", 10.0, decimal.min(10.0,1000));
AddTestCase("dqmin479:p9 r:HALF_EVEN (decimal.min(10000,100.0))", 100.0, decimal.min(10000,100.0));
AddTestCase("dqmin480:p9 r:HALF_EVEN (decimal.min(100.0,10000))", 100.0, decimal.min(100.0,10000));
AddTestCase("dqmin481:p9 r:HALF_EVEN (decimal.min(100000,1000.0))", 1000.0, decimal.min(100000,1000.0));
AddTestCase("dqmin482:p9 r:HALF_EVEN (decimal.min(1000.0,100000))", 1000.0, decimal.min(1000.0,100000));
AddTestCase("dqmin483:p9 r:HALF_EVEN (decimal.min(1000000,10000.0))", 10000.0, decimal.min(1000000,10000.0));
AddTestCase("dqmin484:p9 r:HALF_EVEN (decimal.min(10000.0,1000000))", 10000.0, decimal.min(10000.0,1000000));
// subnormals
AddTestCase("dqmin510:p9 r:HALF_EVEN (decimal.min(1.00e-6143,0))", 0, decimal.min(1.00e-6143,0));
AddTestCase("dqmin511:p9 r:HALF_EVEN (decimal.min(0.1e-6143,0))", 0, decimal.min(0.1e-6143,0));
AddTestCase("dqmin512:p9 r:HALF_EVEN (decimal.min(0.10e-6143,0))", 0, decimal.min(0.10e-6143,0));
AddTestCase("dqmin513:p9 r:HALF_EVEN (decimal.min(0.100e-6143,0))", 0, decimal.min(0.100e-6143,0));
AddTestCase("dqmin514:p9 r:HALF_EVEN (decimal.min(0.01e-6143,0))", 0, decimal.min(0.01e-6143,0));
AddTestCase("dqmin515:p9 r:HALF_EVEN (decimal.min(0.999e-6143,0))", 0, decimal.min(0.999e-6143,0));
AddTestCase("dqmin516:p9 r:HALF_EVEN (decimal.min(0.099e-6143,0))", 0, decimal.min(0.099e-6143,0));
AddTestCase("dqmin517:p9 r:HALF_EVEN (decimal.min(0.009e-6143,0))", 0, decimal.min(0.009e-6143,0));
AddTestCase("dqmin518:p9 r:HALF_EVEN (decimal.min(0.001e-6143,0))", 0, decimal.min(0.001e-6143,0));
AddTestCase("dqmin519:p9 r:HALF_EVEN (decimal.min(0.0009e-6143,0))", 0, decimal.min(0.0009e-6143,0));
AddTestCase("dqmin520:p9 r:HALF_EVEN (decimal.min(0.0001e-6143,0))", 0, decimal.min(0.0001e-6143,0));
AddTestCase("dqmin530:p9 r:HALF_EVEN (decimal.min(-1.00e-6143,0))", -1.00e-6143, decimal.min(-1.00e-6143,0));
// null tests
AddTestCase("dqmin900:p9 r:HALF_EVEN (decimal.min(10,null)) invalid_operation", 0, decimal.min(10,null));
AddTestCase("dqmin901:p9 r:HALF_EVEN (decimal.min(null,10)) invalid_operation", 0, decimal.min(null,10));
}
test();
