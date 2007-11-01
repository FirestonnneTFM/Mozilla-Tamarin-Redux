use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "dqMax.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// dqmax.dectest -- decquad maxnum                                    --
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
AddTestCase("dqmax001:p9 r:HALF_EVEN (decimal.max(-2,-2))", -2, decimal.max(-2,-2));
AddTestCase("dqmax002:p9 r:HALF_EVEN (decimal.max(-2,-1))", -1, decimal.max(-2,-1));
AddTestCase("dqmax003:p9 r:HALF_EVEN (decimal.max(-2,0))", 0, decimal.max(-2,0));
AddTestCase("dqmax004:p9 r:HALF_EVEN (decimal.max(-2,1))", 1, decimal.max(-2,1));
AddTestCase("dqmax005:p9 r:HALF_EVEN (decimal.max(-2,2))", 2, decimal.max(-2,2));
AddTestCase("dqmax006:p9 r:HALF_EVEN (decimal.max(-1,-2))", -1, decimal.max(-1,-2));
AddTestCase("dqmax007:p9 r:HALF_EVEN (decimal.max(-1,-1))", -1, decimal.max(-1,-1));
AddTestCase("dqmax008:p9 r:HALF_EVEN (decimal.max(-1,0))", 0, decimal.max(-1,0));
AddTestCase("dqmax009:p9 r:HALF_EVEN (decimal.max(-1,1))", 1, decimal.max(-1,1));
AddTestCase("dqmax010:p9 r:HALF_EVEN (decimal.max(-1,2))", 2, decimal.max(-1,2));
AddTestCase("dqmax011:p9 r:HALF_EVEN (decimal.max(0,-2))", 0, decimal.max(0,-2));
AddTestCase("dqmax012:p9 r:HALF_EVEN (decimal.max(0,-1))", 0, decimal.max(0,-1));
AddTestCase("dqmax013:p9 r:HALF_EVEN (decimal.max(0,0))", 0, decimal.max(0,0));
AddTestCase("dqmax014:p9 r:HALF_EVEN (decimal.max(0,1))", 1, decimal.max(0,1));
AddTestCase("dqmax015:p9 r:HALF_EVEN (decimal.max(0,2))", 2, decimal.max(0,2));
AddTestCase("dqmax016:p9 r:HALF_EVEN (decimal.max(1,-2))", 1, decimal.max(1,-2));
AddTestCase("dqmax017:p9 r:HALF_EVEN (decimal.max(1,-1))", 1, decimal.max(1,-1));
AddTestCase("dqmax018:p9 r:HALF_EVEN (decimal.max(1,0))", 1, decimal.max(1,0));
AddTestCase("dqmax019:p9 r:HALF_EVEN (decimal.max(1,1))", 1, decimal.max(1,1));
AddTestCase("dqmax020:p9 r:HALF_EVEN (decimal.max(1,2))", 2, decimal.max(1,2));
AddTestCase("dqmax021:p9 r:HALF_EVEN (decimal.max(2,-2))", 2, decimal.max(2,-2));
AddTestCase("dqmax022:p9 r:HALF_EVEN (decimal.max(2,-1))", 2, decimal.max(2,-1));
AddTestCase("dqmax023:p9 r:HALF_EVEN (decimal.max(2,0))", 2, decimal.max(2,0));
AddTestCase("dqmax025:p9 r:HALF_EVEN (decimal.max(2,1))", 2, decimal.max(2,1));
AddTestCase("dqmax026:p9 r:HALF_EVEN (decimal.max(2,2))", 2, decimal.max(2,2));
// extended zeros
AddTestCase("dqmax030:p9 r:HALF_EVEN (decimal.max(0,0))", 0, decimal.max(0,0));
AddTestCase("dqmax031:p9 r:HALF_EVEN (decimal.max(0,-0))", 0, decimal.max(0,-0));
AddTestCase("dqmax032:p9 r:HALF_EVEN (decimal.max(0,-0.0))", 0, decimal.max(0,-0.0));
AddTestCase("dqmax033:p9 r:HALF_EVEN (decimal.max(0,0.0))", 0, decimal.max(0,0.0));
AddTestCase("dqmax034:p9 r:HALF_EVEN (decimal.max(-0,0)) -- note: -0 = 0, but 0 chosen", 0, decimal.max(-0,0));
AddTestCase("dqmax035:p9 r:HALF_EVEN (decimal.max(-0,-0))", -0, decimal.max(-0,-0));
AddTestCase("dqmax036:p9 r:HALF_EVEN (decimal.max(-0,-0.0))", -0.0, decimal.max(-0,-0.0));
AddTestCase("dqmax037:p9 r:HALF_EVEN (decimal.max(-0,0.0))", 0.0, decimal.max(-0,0.0));
AddTestCase("dqmax038:p9 r:HALF_EVEN (decimal.max(0.0,0))", 0, decimal.max(0.0,0));
AddTestCase("dqmax039:p9 r:HALF_EVEN (decimal.max(0.0,-0))", 0.0, decimal.max(0.0,-0));
AddTestCase("dqmax040:p9 r:HALF_EVEN (decimal.max(0.0,-0.0))", 0.0, decimal.max(0.0,-0.0));
AddTestCase("dqmax041:p9 r:HALF_EVEN (decimal.max(0.0,0.0))", 0.0, decimal.max(0.0,0.0));
AddTestCase("dqmax042:p9 r:HALF_EVEN (decimal.max(-0.0,0))", 0, decimal.max(-0.0,0));
AddTestCase("dqmax043:p9 r:HALF_EVEN (decimal.max(-0.0,-0))", -0.0, decimal.max(-0.0,-0));
AddTestCase("dqmax044:p9 r:HALF_EVEN (decimal.max(-0.0,-0.0))", -0.0, decimal.max(-0.0,-0.0));
AddTestCase("dqmax045:p9 r:HALF_EVEN (decimal.max(-0.0,0.0))", 0.0, decimal.max(-0.0,0.0));
AddTestCase("dqmax050:p9 r:HALF_EVEN (decimal.max(-0e1,0e1))", 0e+1, decimal.max(-0e1,0e1));
AddTestCase("dqmax051:p9 r:HALF_EVEN (decimal.max(-0e2,0e2))", 0e+2, decimal.max(-0e2,0e2));
AddTestCase("dqmax052:p9 r:HALF_EVEN (decimal.max(-0e2,0e1))", 0e+1, decimal.max(-0e2,0e1));
AddTestCase("dqmax053:p9 r:HALF_EVEN (decimal.max(-0e1,0e2))", 0e+2, decimal.max(-0e1,0e2));
AddTestCase("dqmax054:p9 r:HALF_EVEN (decimal.max(0e1,-0e1))", 0e+1, decimal.max(0e1,-0e1));
AddTestCase("dqmax055:p9 r:HALF_EVEN (decimal.max(0e2,-0e2))", 0e+2, decimal.max(0e2,-0e2));
AddTestCase("dqmax056:p9 r:HALF_EVEN (decimal.max(0e2,-0e1))", 0e+2, decimal.max(0e2,-0e1));
AddTestCase("dqmax057:p9 r:HALF_EVEN (decimal.max(0e1,-0e2))", 0e+1, decimal.max(0e1,-0e2));
AddTestCase("dqmax058:p9 r:HALF_EVEN (decimal.max(0e1,0e1))", 0e+1, decimal.max(0e1,0e1));
AddTestCase("dqmax059:p9 r:HALF_EVEN (decimal.max(0e2,0e2))", 0e+2, decimal.max(0e2,0e2));
AddTestCase("dqmax060:p9 r:HALF_EVEN (decimal.max(0e2,0e1))", 0e+2, decimal.max(0e2,0e1));
AddTestCase("dqmax061:p9 r:HALF_EVEN (decimal.max(0e1,0e2))", 0e+2, decimal.max(0e1,0e2));
AddTestCase("dqmax062:p9 r:HALF_EVEN (decimal.max(-0e1,-0e1))", -0e+1, decimal.max(-0e1,-0e1));
AddTestCase("dqmax063:p9 r:HALF_EVEN (decimal.max(-0e2,-0e2))", -0e+2, decimal.max(-0e2,-0e2));
AddTestCase("dqmax064:p9 r:HALF_EVEN (decimal.max(-0e2,-0e1))", -0e+1, decimal.max(-0e2,-0e1));
AddTestCase("dqmax065:p9 r:HALF_EVEN (decimal.max(-0e1,-0e2))", -0e+1, decimal.max(-0e1,-0e2));
// specials
AddTestCase("dqmax090:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax091:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,-1000))", decimal.POSITIVE_INFINITY, decimal.max(decimal.POSITIVE_INFINITY,-1000));
AddTestCase("dqmax092:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,-1))", decimal.POSITIVE_INFINITY, decimal.max(decimal.POSITIVE_INFINITY,-1));
AddTestCase("dqmax093:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,-0))", decimal.POSITIVE_INFINITY, decimal.max(decimal.POSITIVE_INFINITY,-0));
AddTestCase("dqmax094:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,0))", decimal.POSITIVE_INFINITY, decimal.max(decimal.POSITIVE_INFINITY,0));
AddTestCase("dqmax095:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,1))", decimal.POSITIVE_INFINITY, decimal.max(decimal.POSITIVE_INFINITY,1));
AddTestCase("dqmax096:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,1000))", decimal.POSITIVE_INFINITY, decimal.max(decimal.POSITIVE_INFINITY,1000));
AddTestCase("dqmax097:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax098:p9 r:HALF_EVEN (decimal.max(-1000,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(-1000,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax099:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax100:p9 r:HALF_EVEN (decimal.max(-1,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(-1,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax101:p9 r:HALF_EVEN (decimal.max(-0,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(-0,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax102:p9 r:HALF_EVEN (decimal.max(0,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(0,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax103:p9 r:HALF_EVEN (decimal.max(1,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(1,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax104:p9 r:HALF_EVEN (decimal.max(1000,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(1000,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax105:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax120:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.max(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax121:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,-1000))", -1000, decimal.max(decimal.NEGATIVE_INFINITY,-1000));
AddTestCase("dqmax122:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,-1))", -1, decimal.max(decimal.NEGATIVE_INFINITY,-1));
AddTestCase("dqmax123:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,-0))", -0, decimal.max(decimal.NEGATIVE_INFINITY,-0));
AddTestCase("dqmax124:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,0))", 0, decimal.max(decimal.NEGATIVE_INFINITY,0));
AddTestCase("dqmax125:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,1))", 1, decimal.max(decimal.NEGATIVE_INFINITY,1));
AddTestCase("dqmax126:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,1000))", 1000, decimal.max(decimal.NEGATIVE_INFINITY,1000));
AddTestCase("dqmax127:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax128:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY))", decimal.NEGATIVE_INFINITY, decimal.max(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax129:p9 r:HALF_EVEN (decimal.max(-1000,decimal.NEGATIVE_INFINITY))", -1000, decimal.max(-1000,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax130:p9 r:HALF_EVEN (decimal.max(-1,decimal.NEGATIVE_INFINITY))", -1, decimal.max(-1,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax131:p9 r:HALF_EVEN (decimal.max(-0,decimal.NEGATIVE_INFINITY))", -0, decimal.max(-0,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax132:p9 r:HALF_EVEN (decimal.max(0,decimal.NEGATIVE_INFINITY))", 0, decimal.max(0,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax133:p9 r:HALF_EVEN (decimal.max(1,decimal.NEGATIVE_INFINITY))", 1, decimal.max(1,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax134:p9 r:HALF_EVEN (decimal.max(1000,decimal.NEGATIVE_INFINITY))", 1000, decimal.max(1000,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax135:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY));
// 2004.08.02 754r chooses number over nan in mixed cases
AddTestCase("dqmax141:p9 r:HALF_EVEN (decimal.max(NaN,decimal.NEGATIVE_INFINITY))", NaN, decimal.max(NaN,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax142:p9 r:HALF_EVEN (decimal.max(NaN,-1000))", NaN, decimal.max(NaN,-1000));
AddTestCase("dqmax143:p9 r:HALF_EVEN (decimal.max(NaN,-1))", NaN, decimal.max(NaN,-1));
AddTestCase("dqmax144:p9 r:HALF_EVEN (decimal.max(NaN,-0))", NaN, decimal.max(NaN,-0));
AddTestCase("dqmax145:p9 r:HALF_EVEN (decimal.max(NaN,0))", NaN, decimal.max(NaN,0));
AddTestCase("dqmax146:p9 r:HALF_EVEN (decimal.max(NaN,1))", NaN, decimal.max(NaN,1));
AddTestCase("dqmax147:p9 r:HALF_EVEN (decimal.max(NaN,1000))", NaN, decimal.max(NaN,1000));
AddTestCase("dqmax148:p9 r:HALF_EVEN (decimal.max(NaN,decimal.POSITIVE_INFINITY))", NaN, decimal.max(NaN,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax149:p9 r:HALF_EVEN (decimal.max(NaN,NaN))", NaN, decimal.max(NaN,NaN));
AddTestCase("dqmax150:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,NaN))", NaN, decimal.max(decimal.NEGATIVE_INFINITY,NaN));
AddTestCase("dqmax151:p9 r:HALF_EVEN (decimal.max(-1000,NaN))", NaN, decimal.max(-1000,NaN));
AddTestCase("dqmax152:p9 r:HALF_EVEN (decimal.max(-1,NaN))", NaN, decimal.max(-1,NaN));
AddTestCase("dqmax153:p9 r:HALF_EVEN (decimal.max(-0,NaN))", NaN, decimal.max(-0,NaN));
AddTestCase("dqmax154:p9 r:HALF_EVEN (decimal.max(0,NaN))", NaN, decimal.max(0,NaN));
AddTestCase("dqmax155:p9 r:HALF_EVEN (decimal.max(1,NaN))", NaN, decimal.max(1,NaN));
AddTestCase("dqmax156:p9 r:HALF_EVEN (decimal.max(1000,NaN))", NaN, decimal.max(1000,NaN));
AddTestCase("dqmax157:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,NaN))", NaN, decimal.max(decimal.POSITIVE_INFINITY,NaN));
AddTestCase("dqmax161:p9 r:HALF_EVEN (decimal.max(NaN,decimal.NEGATIVE_INFINITY)) invalid_operation", NaN, decimal.max(NaN,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax162:p9 r:HALF_EVEN (decimal.max(NaN,-1000)) invalid_operation", NaN, decimal.max(NaN,-1000));
AddTestCase("dqmax163:p9 r:HALF_EVEN (decimal.max(NaN,-1)) invalid_operation", NaN, decimal.max(NaN,-1));
AddTestCase("dqmax164:p9 r:HALF_EVEN (decimal.max(NaN,-0)) invalid_operation", NaN, decimal.max(NaN,-0));
AddTestCase("dqmax165:p9 r:HALF_EVEN (decimal.max(NaN,0)) invalid_operation", NaN, decimal.max(NaN,0));
AddTestCase("dqmax166:p9 r:HALF_EVEN (decimal.max(NaN,1)) invalid_operation", NaN, decimal.max(NaN,1));
AddTestCase("dqmax167:p9 r:HALF_EVEN (decimal.max(NaN,1000)) invalid_operation", NaN, decimal.max(NaN,1000));
AddTestCase("dqmax168:p9 r:HALF_EVEN (decimal.max(NaN,NaN)) invalid_operation", NaN, decimal.max(NaN,NaN));
AddTestCase("dqmax169:p9 r:HALF_EVEN (decimal.max(NaN,NaN)) invalid_operation", NaN, decimal.max(NaN,NaN));
AddTestCase("dqmax170:p9 r:HALF_EVEN (decimal.max(NaN,NaN)) invalid_operation", NaN, decimal.max(NaN,NaN));
AddTestCase("dqmax171:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,NaN)) invalid_operation", NaN, decimal.max(decimal.NEGATIVE_INFINITY,NaN));
AddTestCase("dqmax172:p9 r:HALF_EVEN (decimal.max(-1000,NaN)) invalid_operation", NaN, decimal.max(-1000,NaN));
AddTestCase("dqmax173:p9 r:HALF_EVEN (decimal.max(-1,NaN)) invalid_operation", NaN, decimal.max(-1,NaN));
AddTestCase("dqmax174:p9 r:HALF_EVEN (decimal.max(-0,NaN)) invalid_operation", NaN, decimal.max(-0,NaN));
AddTestCase("dqmax175:p9 r:HALF_EVEN (decimal.max(0,NaN)) invalid_operation", NaN, decimal.max(0,NaN));
AddTestCase("dqmax176:p9 r:HALF_EVEN (decimal.max(1,NaN)) invalid_operation", NaN, decimal.max(1,NaN));
AddTestCase("dqmax177:p9 r:HALF_EVEN (decimal.max(1000,NaN)) invalid_operation", NaN, decimal.max(1000,NaN));
AddTestCase("dqmax178:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,NaN)) invalid_operation", NaN, decimal.max(decimal.POSITIVE_INFINITY,NaN));
AddTestCase("dqmax179:p9 r:HALF_EVEN (decimal.max(NaN,NaN)) invalid_operation", NaN, decimal.max(NaN,NaN));
// propagating nans
AddTestCase("dqmax181:p9 r:HALF_EVEN (decimal.max(NaN,decimal.NEGATIVE_INFINITY))", NaN, decimal.max(NaN,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax182:p9 r:HALF_EVEN (decimal.max(NaN,9))", NaN, decimal.max(NaN,9));
AddTestCase("dqmax183:p9 r:HALF_EVEN (decimal.max(-NaN,decimal.POSITIVE_INFINITY))", NaN, decimal.max(-NaN,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax184:p9 r:HALF_EVEN (decimal.max(-NaN,NaN))", -NaN, decimal.max(-NaN,NaN));
AddTestCase("dqmax185:p9 r:HALF_EVEN (decimal.max(NaN,NaN))", NaN, decimal.max(NaN,NaN));
AddTestCase("dqmax186:p9 r:HALF_EVEN (decimal.max(-NaN,-NaN))", -NaN, decimal.max(-NaN,-NaN));
AddTestCase("dqmax187:p9 r:HALF_EVEN (decimal.max(NaN,-NaN))", NaN, decimal.max(NaN,-NaN));
AddTestCase("dqmax188:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,NaN))", NaN, decimal.max(decimal.NEGATIVE_INFINITY,NaN));
AddTestCase("dqmax189:p9 r:HALF_EVEN (decimal.max(-9,-NaN))", NaN, decimal.max(-9,-NaN));
AddTestCase("dqmax190:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,NaN))", NaN, decimal.max(decimal.POSITIVE_INFINITY,NaN));
AddTestCase("dqmax191:p9 r:HALF_EVEN (decimal.max(NaN,decimal.NEGATIVE_INFINITY)) invalid_operation", NaN, decimal.max(NaN,decimal.NEGATIVE_INFINITY));
AddTestCase("dqmax192:p9 r:HALF_EVEN (decimal.max(NaN,-1)) invalid_operation", NaN, decimal.max(NaN,-1));
AddTestCase("dqmax193:p9 r:HALF_EVEN (decimal.max(-NaN,NaN)) invalid_operation", -NaN, decimal.max(-NaN,NaN));
AddTestCase("dqmax194:p9 r:HALF_EVEN (decimal.max(NaN,NaN)) invalid_operation", NaN, decimal.max(NaN,NaN));
AddTestCase("dqmax195:p9 r:HALF_EVEN (decimal.max(NaN,NaN)) invalid_operation", NaN, decimal.max(NaN,NaN));
AddTestCase("dqmax196:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,NaN)) invalid_operation", NaN, decimal.max(decimal.NEGATIVE_INFINITY,NaN));
AddTestCase("dqmax197:p9 r:HALF_EVEN (decimal.max(0,NaN)) invalid_operation", NaN, decimal.max(0,NaN));
AddTestCase("dqmax198:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,-NaN)) invalid_operation", -NaN, decimal.max(decimal.POSITIVE_INFINITY,-NaN));
AddTestCase("dqmax199:p9 r:HALF_EVEN (decimal.max(NaN,NaN)) invalid_operation", NaN, decimal.max(NaN,NaN));
// old rounding checks
AddTestCase("dqmax221:p9 r:HALF_EVEN (decimal.max(12345678000,1))", 12345678000, decimal.max(12345678000,1));
AddTestCase("dqmax222:p9 r:HALF_EVEN (decimal.max(1,12345678000))", 12345678000, decimal.max(1,12345678000));
AddTestCase("dqmax223:p9 r:HALF_EVEN (decimal.max(1234567800,1))", 1234567800, decimal.max(1234567800,1));
AddTestCase("dqmax224:p9 r:HALF_EVEN (decimal.max(1,1234567800))", 1234567800, decimal.max(1,1234567800));
AddTestCase("dqmax225:p9 r:HALF_EVEN (decimal.max(1234567890,1))", 1234567890, decimal.max(1234567890,1));
AddTestCase("dqmax226:p9 r:HALF_EVEN (decimal.max(1,1234567890))", 1234567890, decimal.max(1,1234567890));
AddTestCase("dqmax227:p9 r:HALF_EVEN (decimal.max(1234567891,1))", 1234567891, decimal.max(1234567891,1));
AddTestCase("dqmax228:p9 r:HALF_EVEN (decimal.max(1,1234567891))", 1234567891, decimal.max(1,1234567891));
AddTestCase("dqmax229:p9 r:HALF_EVEN (decimal.max(12345678901,1))", 12345678901, decimal.max(12345678901,1));
AddTestCase("dqmax230:p9 r:HALF_EVEN (decimal.max(1,12345678901))", 12345678901, decimal.max(1,12345678901));
AddTestCase("dqmax231:p9 r:HALF_EVEN (decimal.max(1234567896,1))", 1234567896, decimal.max(1234567896,1));
AddTestCase("dqmax232:p9 r:HALF_EVEN (decimal.max(1,1234567896))", 1234567896, decimal.max(1,1234567896));
AddTestCase("dqmax233:p9 r:HALF_EVEN (decimal.max(-1234567891,1))", 1, decimal.max(-1234567891,1));
AddTestCase("dqmax234:p9 r:HALF_EVEN (decimal.max(1,-1234567891))", 1, decimal.max(1,-1234567891));
AddTestCase("dqmax235:p9 r:HALF_EVEN (decimal.max(-12345678901,1))", 1, decimal.max(-12345678901,1));
AddTestCase("dqmax236:p9 r:HALF_EVEN (decimal.max(1,-12345678901))", 1, decimal.max(1,-12345678901));
AddTestCase("dqmax237:p9 r:HALF_EVEN (decimal.max(-1234567896,1))", 1, decimal.max(-1234567896,1));
AddTestCase("dqmax238:p9 r:HALF_EVEN (decimal.max(1,-1234567896))", 1, decimal.max(1,-1234567896));
// from examples
AddTestCase("dqmax280:p9 r:HALF_EVEN (decimal.max(3,2))", 3, decimal.max(3,2));
AddTestCase("dqmax281:p9 r:HALF_EVEN (decimal.max(-10,3))", 3, decimal.max(-10,3));
AddTestCase("dqmax282:p9 r:HALF_EVEN (decimal.max(1.0,1))", 1, decimal.max(1.0,1));
AddTestCase("dqmax283:p9 r:HALF_EVEN (decimal.max(1,1.0))", 1, decimal.max(1,1.0));
AddTestCase("dqmax284:p9 r:HALF_EVEN (decimal.max(7,NaN))", NaN, decimal.max(7,NaN));
// expanded list from min/max 754r purple prose
// [explicit tests for exponent ordering]
AddTestCase("dqmax401:p9 r:HALF_EVEN (decimal.max(decimal.POSITIVE_INFINITY,1.1))", decimal.POSITIVE_INFINITY, decimal.max(decimal.POSITIVE_INFINITY,1.1));
AddTestCase("dqmax402:p9 r:HALF_EVEN (decimal.max(1.1,1))", 1.1, decimal.max(1.1,1));
AddTestCase("dqmax403:p9 r:HALF_EVEN (decimal.max(1,1.0))", 1, decimal.max(1,1.0));
AddTestCase("dqmax404:p9 r:HALF_EVEN (decimal.max(1.0,0.1))", 1.0, decimal.max(1.0,0.1));
AddTestCase("dqmax405:p9 r:HALF_EVEN (decimal.max(0.1,0.10))", 0.1, decimal.max(0.1,0.10));
AddTestCase("dqmax406:p9 r:HALF_EVEN (decimal.max(0.10,0.100))", 0.10, decimal.max(0.10,0.100));
AddTestCase("dqmax407:p9 r:HALF_EVEN (decimal.max(0.10,0))", 0.10, decimal.max(0.10,0));
AddTestCase("dqmax408:p9 r:HALF_EVEN (decimal.max(0,0.0))", 0, decimal.max(0,0.0));
AddTestCase("dqmax409:p9 r:HALF_EVEN (decimal.max(0.0,-0))", 0.0, decimal.max(0.0,-0));
AddTestCase("dqmax410:p9 r:HALF_EVEN (decimal.max(0.0,-0.0))", 0.0, decimal.max(0.0,-0.0));
AddTestCase("dqmax411:p9 r:HALF_EVEN (decimal.max(0.00,-0.0))", 0.00, decimal.max(0.00,-0.0));
AddTestCase("dqmax412:p9 r:HALF_EVEN (decimal.max(0.0,-0.00))", 0.0, decimal.max(0.0,-0.00));
AddTestCase("dqmax413:p9 r:HALF_EVEN (decimal.max(0,-0.0))", 0, decimal.max(0,-0.0));
AddTestCase("dqmax414:p9 r:HALF_EVEN (decimal.max(0,-0))", 0, decimal.max(0,-0));
AddTestCase("dqmax415:p9 r:HALF_EVEN (decimal.max(-0.0,-0))", -0.0, decimal.max(-0.0,-0));
AddTestCase("dqmax416:p9 r:HALF_EVEN (decimal.max(-0,-0.100))", -0, decimal.max(-0,-0.100));
AddTestCase("dqmax417:p9 r:HALF_EVEN (decimal.max(-0.100,-0.10))", -0.100, decimal.max(-0.100,-0.10));
AddTestCase("dqmax418:p9 r:HALF_EVEN (decimal.max(-0.10,-0.1))", -0.10, decimal.max(-0.10,-0.1));
AddTestCase("dqmax419:p9 r:HALF_EVEN (decimal.max(-0.1,-1.0))", -0.1, decimal.max(-0.1,-1.0));
AddTestCase("dqmax420:p9 r:HALF_EVEN (decimal.max(-1.0,-1))", -1.0, decimal.max(-1.0,-1));
AddTestCase("dqmax421:p9 r:HALF_EVEN (decimal.max(-1,-1.1))", -1, decimal.max(-1,-1.1));
AddTestCase("dqmax423:p9 r:HALF_EVEN (decimal.max(-1.1,decimal.NEGATIVE_INFINITY))", -1.1, decimal.max(-1.1,decimal.NEGATIVE_INFINITY));
// same with operands reversed
AddTestCase("dqmax431:p9 r:HALF_EVEN (decimal.max(1.1,decimal.POSITIVE_INFINITY))", decimal.POSITIVE_INFINITY, decimal.max(1.1,decimal.POSITIVE_INFINITY));
AddTestCase("dqmax432:p9 r:HALF_EVEN (decimal.max(1,1.1))", 1.1, decimal.max(1,1.1));
AddTestCase("dqmax433:p9 r:HALF_EVEN (decimal.max(1.0,1))", 1, decimal.max(1.0,1));
AddTestCase("dqmax434:p9 r:HALF_EVEN (decimal.max(0.1,1.0))", 1.0, decimal.max(0.1,1.0));
AddTestCase("dqmax435:p9 r:HALF_EVEN (decimal.max(0.10,0.1))", 0.1, decimal.max(0.10,0.1));
AddTestCase("dqmax436:p9 r:HALF_EVEN (decimal.max(0.100,0.10))", 0.10, decimal.max(0.100,0.10));
AddTestCase("dqmax437:p9 r:HALF_EVEN (decimal.max(0,0.10))", 0.10, decimal.max(0,0.10));
AddTestCase("dqmax438:p9 r:HALF_EVEN (decimal.max(0.0,0))", 0, decimal.max(0.0,0));
AddTestCase("dqmax439:p9 r:HALF_EVEN (decimal.max(-0,0.0))", 0.0, decimal.max(-0,0.0));
AddTestCase("dqmax440:p9 r:HALF_EVEN (decimal.max(-0.0,0.0))", 0.0, decimal.max(-0.0,0.0));
AddTestCase("dqmax441:p9 r:HALF_EVEN (decimal.max(-0.0,0.00))", 0.00, decimal.max(-0.0,0.00));
AddTestCase("dqmax442:p9 r:HALF_EVEN (decimal.max(-0.00,0.0))", 0.0, decimal.max(-0.00,0.0));
AddTestCase("dqmax443:p9 r:HALF_EVEN (decimal.max(-0.0,0))", 0, decimal.max(-0.0,0));
AddTestCase("dqmax444:p9 r:HALF_EVEN (decimal.max(-0,0))", 0, decimal.max(-0,0));
AddTestCase("dqmax445:p9 r:HALF_EVEN (decimal.max(-0,-0.0))", -0.0, decimal.max(-0,-0.0));
AddTestCase("dqmax446:p9 r:HALF_EVEN (decimal.max(-0.100,-0))", -0, decimal.max(-0.100,-0));
AddTestCase("dqmax447:p9 r:HALF_EVEN (decimal.max(-0.10,-0.100))", -0.100, decimal.max(-0.10,-0.100));
AddTestCase("dqmax448:p9 r:HALF_EVEN (decimal.max(-0.1,-0.10))", -0.10, decimal.max(-0.1,-0.10));
AddTestCase("dqmax449:p9 r:HALF_EVEN (decimal.max(-1.0,-0.1))", -0.1, decimal.max(-1.0,-0.1));
AddTestCase("dqmax450:p9 r:HALF_EVEN (decimal.max(-1,-1.0))", -1.0, decimal.max(-1,-1.0));
AddTestCase("dqmax451:p9 r:HALF_EVEN (decimal.max(-1.1,-1))", -1, decimal.max(-1.1,-1));
AddTestCase("dqmax453:p9 r:HALF_EVEN (decimal.max(decimal.NEGATIVE_INFINITY,-1.1))", -1.1, decimal.max(decimal.NEGATIVE_INFINITY,-1.1));
// largies
AddTestCase("dqmax460:p9 r:HALF_EVEN (decimal.max(1000,1e+3))", 1e+3, decimal.max(1000,1e+3));
AddTestCase("dqmax461:p9 r:HALF_EVEN (decimal.max(1e+3,1000))", 1e+3, decimal.max(1e+3,1000));
AddTestCase("dqmax462:p9 r:HALF_EVEN (decimal.max(1000,-1e+3))", 1000, decimal.max(1000,-1e+3));
AddTestCase("dqmax463:p9 r:HALF_EVEN (decimal.max(1e+3,-1000))", 1e+3, decimal.max(1e+3,-1000));
AddTestCase("dqmax464:p9 r:HALF_EVEN (decimal.max(-1000,1e+3))", 1e+3, decimal.max(-1000,1e+3));
AddTestCase("dqmax465:p9 r:HALF_EVEN (decimal.max(-1e+3,1000))", 1000, decimal.max(-1e+3,1000));
AddTestCase("dqmax466:p9 r:HALF_EVEN (decimal.max(-1000,-1e+3))", -1000, decimal.max(-1000,-1e+3));
AddTestCase("dqmax467:p9 r:HALF_EVEN (decimal.max(-1e+3,-1000))", -1000, decimal.max(-1e+3,-1000));
// misalignment traps for little-endian
AddTestCase("dqmax471:p9 r:HALF_EVEN (decimal.max(1.0,0.1))", 1.0, decimal.max(1.0,0.1));
AddTestCase("dqmax472:p9 r:HALF_EVEN (decimal.max(0.1,1.0))", 1.0, decimal.max(0.1,1.0));
AddTestCase("dqmax473:p9 r:HALF_EVEN (decimal.max(10.0,0.1))", 10.0, decimal.max(10.0,0.1));
AddTestCase("dqmax474:p9 r:HALF_EVEN (decimal.max(0.1,10.0))", 10.0, decimal.max(0.1,10.0));
AddTestCase("dqmax475:p9 r:HALF_EVEN (decimal.max(100,1.0))", 100, decimal.max(100,1.0));
AddTestCase("dqmax476:p9 r:HALF_EVEN (decimal.max(1.0,100))", 100, decimal.max(1.0,100));
AddTestCase("dqmax477:p9 r:HALF_EVEN (decimal.max(1000,10.0))", 1000, decimal.max(1000,10.0));
AddTestCase("dqmax478:p9 r:HALF_EVEN (decimal.max(10.0,1000))", 1000, decimal.max(10.0,1000));
AddTestCase("dqmax479:p9 r:HALF_EVEN (decimal.max(10000,100.0))", 10000, decimal.max(10000,100.0));
AddTestCase("dqmax480:p9 r:HALF_EVEN (decimal.max(100.0,10000))", 10000, decimal.max(100.0,10000));
AddTestCase("dqmax481:p9 r:HALF_EVEN (decimal.max(100000,1000.0))", 100000, decimal.max(100000,1000.0));
AddTestCase("dqmax482:p9 r:HALF_EVEN (decimal.max(1000.0,100000))", 100000, decimal.max(1000.0,100000));
AddTestCase("dqmax483:p9 r:HALF_EVEN (decimal.max(1000000,10000.0))", 1000000, decimal.max(1000000,10000.0));
AddTestCase("dqmax484:p9 r:HALF_EVEN (decimal.max(10000.0,1000000))", 1000000, decimal.max(10000.0,1000000));
// subnormals
AddTestCase("dqmax510:p9 r:HALF_EVEN (decimal.max(1.00e-6143,0))", 1.00e-6143, decimal.max(1.00e-6143,0));
AddTestCase("dqmax530:p9 r:HALF_EVEN (decimal.max(-1.00e-6143,0))", 0, decimal.max(-1.00e-6143,0));
AddTestCase("dqmax531:p9 r:HALF_EVEN (decimal.max(-0.1e-6143,0))", 0, decimal.max(-0.1e-6143,0));
AddTestCase("dqmax532:p9 r:HALF_EVEN (decimal.max(-0.10e-6143,0))", 0, decimal.max(-0.10e-6143,0));
AddTestCase("dqmax533:p9 r:HALF_EVEN (decimal.max(-0.100e-6143,0))", 0, decimal.max(-0.100e-6143,0));
AddTestCase("dqmax534:p9 r:HALF_EVEN (decimal.max(-0.01e-6143,0))", 0, decimal.max(-0.01e-6143,0));
AddTestCase("dqmax535:p9 r:HALF_EVEN (decimal.max(-0.999e-6143,0))", 0, decimal.max(-0.999e-6143,0));
AddTestCase("dqmax536:p9 r:HALF_EVEN (decimal.max(-0.099e-6143,0))", 0, decimal.max(-0.099e-6143,0));
AddTestCase("dqmax537:p9 r:HALF_EVEN (decimal.max(-0.009e-6143,0))", 0, decimal.max(-0.009e-6143,0));
AddTestCase("dqmax538:p9 r:HALF_EVEN (decimal.max(-0.001e-6143,0))", 0, decimal.max(-0.001e-6143,0));
AddTestCase("dqmax539:p9 r:HALF_EVEN (decimal.max(-0.0009e-6143,0))", 0, decimal.max(-0.0009e-6143,0));
AddTestCase("dqmax540:p9 r:HALF_EVEN (decimal.max(-0.0001e-6143,0))", 0, decimal.max(-0.0001e-6143,0));
// null tests
AddTestCase("dqmax900:p9 r:HALF_EVEN (decimal.max(10,null)) invalid_operation", 10, decimal.max(10,null));
AddTestCase("dqmax901:p9 r:HALF_EVEN (decimal.max(null,10)) invalid_operation", 10, decimal.max(null,10));
}
test();
