use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "max.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// max.dectest -- decimal maximum                                     --
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
use precision 9;
use rounding HALF_UP;
// sanity checks
AddTestCase('maxx001:p9 r:HALF_UP (0 + decimal.max(-2,-2))', -2, 0 + decimal.max(-2,-2));
AddTestCase('maxx002:p9 r:HALF_UP (0 + decimal.max(-2,-1))', -1, 0 + decimal.max(-2,-1));
AddTestCase('maxx003:p9 r:HALF_UP (0 + decimal.max(-2,0))', 0, 0 + decimal.max(-2,0));
AddTestCase('maxx004:p9 r:HALF_UP (0 + decimal.max(-2,1))', 1, 0 + decimal.max(-2,1));
AddTestCase('maxx005:p9 r:HALF_UP (0 + decimal.max(-2,2))', 2, 0 + decimal.max(-2,2));
AddTestCase('maxx006:p9 r:HALF_UP (0 + decimal.max(-1,-2))', -1, 0 + decimal.max(-1,-2));
AddTestCase('maxx007:p9 r:HALF_UP (0 + decimal.max(-1,-1))', -1, 0 + decimal.max(-1,-1));
AddTestCase('maxx008:p9 r:HALF_UP (0 + decimal.max(-1,0))', 0, 0 + decimal.max(-1,0));
AddTestCase('maxx009:p9 r:HALF_UP (0 + decimal.max(-1,1))', 1, 0 + decimal.max(-1,1));
AddTestCase('maxx010:p9 r:HALF_UP (0 + decimal.max(-1,2))', 2, 0 + decimal.max(-1,2));
AddTestCase('maxx011:p9 r:HALF_UP (0 + decimal.max(0,-2))', 0, 0 + decimal.max(0,-2));
AddTestCase('maxx012:p9 r:HALF_UP (0 + decimal.max(0,-1))', 0, 0 + decimal.max(0,-1));
AddTestCase('maxx013:p9 r:HALF_UP (0 + decimal.max(0,0))', 0, 0 + decimal.max(0,0));
AddTestCase('maxx014:p9 r:HALF_UP (0 + decimal.max(0,1))', 1, 0 + decimal.max(0,1));
AddTestCase('maxx015:p9 r:HALF_UP (0 + decimal.max(0,2))', 2, 0 + decimal.max(0,2));
AddTestCase('maxx016:p9 r:HALF_UP (0 + decimal.max(1,-2))', 1, 0 + decimal.max(1,-2));
AddTestCase('maxx017:p9 r:HALF_UP (0 + decimal.max(1,-1))', 1, 0 + decimal.max(1,-1));
AddTestCase('maxx018:p9 r:HALF_UP (0 + decimal.max(1,0))', 1, 0 + decimal.max(1,0));
AddTestCase('maxx019:p9 r:HALF_UP (0 + decimal.max(1,1))', 1, 0 + decimal.max(1,1));
AddTestCase('maxx020:p9 r:HALF_UP (0 + decimal.max(1,2))', 2, 0 + decimal.max(1,2));
AddTestCase('maxx021:p9 r:HALF_UP (0 + decimal.max(2,-2))', 2, 0 + decimal.max(2,-2));
AddTestCase('maxx022:p9 r:HALF_UP (0 + decimal.max(2,-1))', 2, 0 + decimal.max(2,-1));
AddTestCase('maxx023:p9 r:HALF_UP (0 + decimal.max(2,0))', 2, 0 + decimal.max(2,0));
AddTestCase('maxx025:p9 r:HALF_UP (0 + decimal.max(2,1))', 2, 0 + decimal.max(2,1));
AddTestCase('maxx026:p9 r:HALF_UP (0 + decimal.max(2,2))', 2, 0 + decimal.max(2,2));
// extended zeros
AddTestCase('maxx030:p9 r:HALF_UP (0 + decimal.max(0,0))', 0, 0 + decimal.max(0,0));
AddTestCase('maxx031:p9 r:HALF_UP (0 + decimal.max(0,-0))', 0, 0 + decimal.max(0,-0));
AddTestCase('maxx032:p9 r:HALF_UP (0 + decimal.max(0,-0.0))', 0, 0 + decimal.max(0,-0.0));
AddTestCase('maxx033:p9 r:HALF_UP (0 + decimal.max(0,0.0))', 0, 0 + decimal.max(0,0.0));
AddTestCase('maxx034:p9 r:HALF_UP (0 + decimal.max(-0,0)) -- note: -0 = 0, but 0 chosen', 0, 0 + decimal.max(-0,0));
AddTestCase('maxx035:p9 r:HALF_UP (0 + decimal.max(-0,-0))', -0, 0 + decimal.max(-0,-0));
AddTestCase('maxx036:p9 r:HALF_UP (0 + decimal.max(-0,-0.0))', -0.0, 0 + decimal.max(-0,-0.0));
AddTestCase('maxx037:p9 r:HALF_UP (0 + decimal.max(-0,0.0))', 0.0, 0 + decimal.max(-0,0.0));
AddTestCase('maxx038:p9 r:HALF_UP (0 + decimal.max(0.0,0))', 0, 0 + decimal.max(0.0,0));
AddTestCase('maxx039:p9 r:HALF_UP (0 + decimal.max(0.0,-0))', 0.0, 0 + decimal.max(0.0,-0));
AddTestCase('maxx040:p9 r:HALF_UP (0 + decimal.max(0.0,-0.0))', 0.0, 0 + decimal.max(0.0,-0.0));
AddTestCase('maxx041:p9 r:HALF_UP (0 + decimal.max(0.0,0.0))', 0.0, 0 + decimal.max(0.0,0.0));
AddTestCase('maxx042:p9 r:HALF_UP (0 + decimal.max(-0.0,0))', 0, 0 + decimal.max(-0.0,0));
AddTestCase('maxx043:p9 r:HALF_UP (0 + decimal.max(-0.0,-0))', -0.0, 0 + decimal.max(-0.0,-0));
AddTestCase('maxx044:p9 r:HALF_UP (0 + decimal.max(-0.0,-0.0))', -0.0, 0 + decimal.max(-0.0,-0.0));
AddTestCase('maxx045:p9 r:HALF_UP (0 + decimal.max(-0.0,0.0))', 0.0, 0 + decimal.max(-0.0,0.0));
AddTestCase('maxx050:p9 r:HALF_UP (0 + decimal.max(-0e1,0e1))', 0e+1, 0 + decimal.max(-0e1,0e1));
AddTestCase('maxx051:p9 r:HALF_UP (0 + decimal.max(-0e2,0e2))', 0e+2, 0 + decimal.max(-0e2,0e2));
AddTestCase('maxx052:p9 r:HALF_UP (0 + decimal.max(-0e2,0e1))', 0e+1, 0 + decimal.max(-0e2,0e1));
AddTestCase('maxx053:p9 r:HALF_UP (0 + decimal.max(-0e1,0e2))', 0e+2, 0 + decimal.max(-0e1,0e2));
AddTestCase('maxx054:p9 r:HALF_UP (0 + decimal.max(0e1,-0e1))', 0e+1, 0 + decimal.max(0e1,-0e1));
AddTestCase('maxx055:p9 r:HALF_UP (0 + decimal.max(0e2,-0e2))', 0e+2, 0 + decimal.max(0e2,-0e2));
AddTestCase('maxx056:p9 r:HALF_UP (0 + decimal.max(0e2,-0e1))', 0e+2, 0 + decimal.max(0e2,-0e1));
AddTestCase('maxx057:p9 r:HALF_UP (0 + decimal.max(0e1,-0e2))', 0e+1, 0 + decimal.max(0e1,-0e2));
AddTestCase('maxx058:p9 r:HALF_UP (0 + decimal.max(0e1,0e1))', 0e+1, 0 + decimal.max(0e1,0e1));
AddTestCase('maxx059:p9 r:HALF_UP (0 + decimal.max(0e2,0e2))', 0e+2, 0 + decimal.max(0e2,0e2));
AddTestCase('maxx060:p9 r:HALF_UP (0 + decimal.max(0e2,0e1))', 0e+2, 0 + decimal.max(0e2,0e1));
AddTestCase('maxx061:p9 r:HALF_UP (0 + decimal.max(0e1,0e2))', 0e+2, 0 + decimal.max(0e1,0e2));
AddTestCase('maxx062:p9 r:HALF_UP (0 + decimal.max(-0e1,-0e1))', -0e+1, 0 + decimal.max(-0e1,-0e1));
AddTestCase('maxx063:p9 r:HALF_UP (0 + decimal.max(-0e2,-0e2))', -0e+2, 0 + decimal.max(-0e2,-0e2));
AddTestCase('maxx064:p9 r:HALF_UP (0 + decimal.max(-0e2,-0e1))', -0e+1, 0 + decimal.max(-0e2,-0e1));
AddTestCase('maxx065:p9 r:HALF_UP (0 + decimal.max(-0e1,-0e2))', -0e+1, 0 + decimal.max(-0e1,-0e2));
// specials
{
	use precision 9;
	AddTestCase('maxx090:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx091:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,-1000))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.POSITIVE_INFINITY,-1000));
	AddTestCase('maxx092:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,-1))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.POSITIVE_INFINITY,-1));
	AddTestCase('maxx093:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,-0))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.POSITIVE_INFINITY,-0));
	AddTestCase('maxx094:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,0))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.POSITIVE_INFINITY,0));
	AddTestCase('maxx095:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,1))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.POSITIVE_INFINITY,1));
	AddTestCase('maxx096:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,1000))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.POSITIVE_INFINITY,1000));
	AddTestCase('maxx097:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx098:p9 r:HALF_UP (0 + decimal.max(-1000,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(-1000,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx099:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx100:p9 r:HALF_UP (0 + decimal.max(-1,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(-1,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx101:p9 r:HALF_UP (0 + decimal.max(-0,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(-0,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx102:p9 r:HALF_UP (0 + decimal.max(0,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(0,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx103:p9 r:HALF_UP (0 + decimal.max(1,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(1,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx104:p9 r:HALF_UP (0 + decimal.max(1000,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(1000,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx105:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx120:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.max(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx121:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,-1000))', -1000, 0 + decimal.max(decimal.NEGATIVE_INFINITY,-1000));
	AddTestCase('maxx122:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,-1))', -1, 0 + decimal.max(decimal.NEGATIVE_INFINITY,-1));
	AddTestCase('maxx123:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,-0))', -0, 0 + decimal.max(decimal.NEGATIVE_INFINITY,-0));
	AddTestCase('maxx124:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,0))', 0, 0 + decimal.max(decimal.NEGATIVE_INFINITY,0));
	AddTestCase('maxx125:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,1))', 1, 0 + decimal.max(decimal.NEGATIVE_INFINITY,1));
	AddTestCase('maxx126:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,1000))', 1000, 0 + decimal.max(decimal.NEGATIVE_INFINITY,1000));
	AddTestCase('maxx127:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx128:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.max(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx129:p9 r:HALF_UP (0 + decimal.max(-1000,decimal.NEGATIVE_INFINITY))', -1000, 0 + decimal.max(-1000,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx130:p9 r:HALF_UP (0 + decimal.max(-1,decimal.NEGATIVE_INFINITY))', -1, 0 + decimal.max(-1,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx131:p9 r:HALF_UP (0 + decimal.max(-0,decimal.NEGATIVE_INFINITY))', -0, 0 + decimal.max(-0,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx132:p9 r:HALF_UP (0 + decimal.max(0,decimal.NEGATIVE_INFINITY))', 0, 0 + decimal.max(0,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx133:p9 r:HALF_UP (0 + decimal.max(1,decimal.NEGATIVE_INFINITY))', 1, 0 + decimal.max(1,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx134:p9 r:HALF_UP (0 + decimal.max(1000,decimal.NEGATIVE_INFINITY))', 1000, 0 + decimal.max(1000,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx135:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY));
	// 2004.08.02 754r chooses number over nan in mixed cases
	AddTestCase('maxx141:p9 r:HALF_UP (0 + decimal.max(NaN,decimal.NEGATIVE_INFINITY))', NaN, 0 + decimal.max(NaN,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx142:p9 r:HALF_UP (0 + decimal.max(NaN,-1000))', NaN, 0 + decimal.max(NaN,-1000));
	AddTestCase('maxx143:p9 r:HALF_UP (0 + decimal.max(NaN,-1))', NaN, 0 + decimal.max(NaN,-1));
	AddTestCase('maxx144:p9 r:HALF_UP (0 + decimal.max(NaN,-0))', NaN, 0 + decimal.max(NaN,-0));
	AddTestCase('maxx145:p9 r:HALF_UP (0 + decimal.max(NaN,0))', NaN, 0 + decimal.max(NaN,0));
	AddTestCase('maxx146:p9 r:HALF_UP (0 + decimal.max(NaN,1))', NaN, 0 + decimal.max(NaN,1));
	AddTestCase('maxx147:p9 r:HALF_UP (0 + decimal.max(NaN,1000))', NaN, 0 + decimal.max(NaN,1000));
	AddTestCase('maxx148:p9 r:HALF_UP (0 + decimal.max(NaN,decimal.POSITIVE_INFINITY))', NaN, 0 + decimal.max(NaN,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx149:p9 r:HALF_UP (0 + decimal.max(NaN,NaN))', NaN, 0 + decimal.max(NaN,NaN));
	AddTestCase('maxx150:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,NaN))', NaN, 0 + decimal.max(decimal.NEGATIVE_INFINITY,NaN));
	AddTestCase('maxx151:p9 r:HALF_UP (0 + decimal.max(-1000,NaN))', NaN, 0 + decimal.max(-1000,NaN));
	AddTestCase('maxx152:p9 r:HALF_UP (0 + decimal.max(-1,NaN))', NaN, 0 + decimal.max(-1,NaN));
	AddTestCase('maxx153:p9 r:HALF_UP (0 + decimal.max(-0,NaN))', NaN, 0 + decimal.max(-0,NaN));
	AddTestCase('maxx154:p9 r:HALF_UP (0 + decimal.max(0,NaN))', NaN, 0 + decimal.max(0,NaN));
	AddTestCase('maxx155:p9 r:HALF_UP (0 + decimal.max(1,NaN))', NaN, 0 + decimal.max(1,NaN));
	AddTestCase('maxx156:p9 r:HALF_UP (0 + decimal.max(1000,NaN))', NaN, 0 + decimal.max(1000,NaN));
	AddTestCase('maxx157:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,NaN))', NaN, 0 + decimal.max(decimal.POSITIVE_INFINITY,NaN));
	AddTestCase('maxx161:p9 r:HALF_UP (0 + decimal.max(NaN,decimal.NEGATIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.max(NaN,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx162:p9 r:HALF_UP (0 + decimal.max(NaN,-1000)) invalid_operation', NaN, 0 + decimal.max(NaN,-1000));
	AddTestCase('maxx163:p9 r:HALF_UP (0 + decimal.max(NaN,-1)) invalid_operation', NaN, 0 + decimal.max(NaN,-1));
	AddTestCase('maxx164:p9 r:HALF_UP (0 + decimal.max(NaN,-0)) invalid_operation', NaN, 0 + decimal.max(NaN,-0));
	AddTestCase('maxx165:p9 r:HALF_UP (0 + decimal.max(NaN,0)) invalid_operation', NaN, 0 + decimal.max(NaN,0));
	AddTestCase('maxx166:p9 r:HALF_UP (0 + decimal.max(NaN,1)) invalid_operation', NaN, 0 + decimal.max(NaN,1));
	AddTestCase('maxx167:p9 r:HALF_UP (0 + decimal.max(NaN,1000)) invalid_operation', NaN, 0 + decimal.max(NaN,1000));
	AddTestCase('maxx168:p9 r:HALF_UP (0 + decimal.max(NaN,NaN)) invalid_operation', NaN, 0 + decimal.max(NaN,NaN));
	AddTestCase('maxx169:p9 r:HALF_UP (0 + decimal.max(NaN,NaN)) invalid_operation', NaN, 0 + decimal.max(NaN,NaN));
	AddTestCase('maxx170:p9 r:HALF_UP (0 + decimal.max(NaN,NaN)) invalid_operation', NaN, 0 + decimal.max(NaN,NaN));
	AddTestCase('maxx171:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,NaN)) invalid_operation', NaN, 0 + decimal.max(decimal.NEGATIVE_INFINITY,NaN));
	AddTestCase('maxx172:p9 r:HALF_UP (0 + decimal.max(-1000,NaN)) invalid_operation', NaN, 0 + decimal.max(-1000,NaN));
	AddTestCase('maxx173:p9 r:HALF_UP (0 + decimal.max(-1,NaN)) invalid_operation', NaN, 0 + decimal.max(-1,NaN));
	AddTestCase('maxx174:p9 r:HALF_UP (0 + decimal.max(-0,NaN)) invalid_operation', NaN, 0 + decimal.max(-0,NaN));
	AddTestCase('maxx175:p9 r:HALF_UP (0 + decimal.max(0,NaN)) invalid_operation', NaN, 0 + decimal.max(0,NaN));
	AddTestCase('maxx176:p9 r:HALF_UP (0 + decimal.max(1,NaN)) invalid_operation', NaN, 0 + decimal.max(1,NaN));
	AddTestCase('maxx177:p9 r:HALF_UP (0 + decimal.max(1000,NaN)) invalid_operation', NaN, 0 + decimal.max(1000,NaN));
	AddTestCase('maxx178:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,NaN)) invalid_operation', NaN, 0 + decimal.max(decimal.POSITIVE_INFINITY,NaN));
	AddTestCase('maxx179:p9 r:HALF_UP (0 + decimal.max(NaN,NaN)) invalid_operation', NaN, 0 + decimal.max(NaN,NaN));
	// propagating nans
	AddTestCase('maxx181:p9 r:HALF_UP (0 + decimal.max(NaN,decimal.NEGATIVE_INFINITY))', NaN, 0 + decimal.max(NaN,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx182:p9 r:HALF_UP (0 + decimal.max(NaN,9))', NaN, 0 + decimal.max(NaN,9));
	AddTestCase('maxx183:p9 r:HALF_UP (0 + decimal.max(-NaN,decimal.POSITIVE_INFINITY))',NaN, 0 + decimal.max(-NaN,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx184:p9 r:HALF_UP (0 + decimal.max(-NaN,NaN))', -NaN, 0 + decimal.max(-NaN,NaN));
	AddTestCase('maxx185:p9 r:HALF_UP (0 + decimal.max(NaN,NaN))', NaN, 0 + decimal.max(NaN,NaN));
	AddTestCase('maxx186:p9 r:HALF_UP (0 + decimal.max(-NaN,-NaN))', -NaN, 0 + decimal.max(-NaN,-NaN));
	AddTestCase('maxx187:p9 r:HALF_UP (0 + decimal.max(NaN,-NaN))', NaN, 0 + decimal.max(NaN,-NaN));
	AddTestCase('maxx188:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,NaN))', NaN, 0 + decimal.max(decimal.NEGATIVE_INFINITY,NaN));
	AddTestCase('maxx189:p9 r:HALF_UP (0 + decimal.max(-9,-NaN))', NaN, 0 + decimal.max(-9,-NaN));
	AddTestCase('maxx190:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,NaN))', NaN, 0 + decimal.max(decimal.POSITIVE_INFINITY,NaN));
	AddTestCase('maxx191:p9 r:HALF_UP (0 + decimal.max(NaN,decimal.NEGATIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.max(NaN,decimal.NEGATIVE_INFINITY));
	AddTestCase('maxx192:p9 r:HALF_UP (0 + decimal.max(NaN,-1)) invalid_operation', NaN, 0 + decimal.max(NaN,-1));
	AddTestCase('maxx193:p9 r:HALF_UP (0 + decimal.max(-NaN,NaN)) invalid_operation', -NaN, 0 + decimal.max(-NaN,NaN));
	AddTestCase('maxx194:p9 r:HALF_UP (0 + decimal.max(NaN,NaN)) invalid_operation', NaN, 0 + decimal.max(NaN,NaN));
	AddTestCase('maxx195:p9 r:HALF_UP (0 + decimal.max(NaN,NaN)) invalid_operation', NaN, 0 + decimal.max(NaN,NaN));
	AddTestCase('maxx196:p9 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,NaN)) invalid_operation', NaN, 0 + decimal.max(decimal.NEGATIVE_INFINITY,NaN));
	AddTestCase('maxx197:p9 r:HALF_UP (0 + decimal.max(0,NaN)) invalid_operation', NaN, 0 + decimal.max(0,NaN));
	AddTestCase('maxx198:p9 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,-NaN)) invalid_operation', -NaN, 0 + decimal.max(decimal.POSITIVE_INFINITY,-NaN));
	AddTestCase('maxx199:p9 r:HALF_UP (0 + decimal.max(NaN,NaN)) invalid_operation', NaN, 0 + decimal.max(NaN,NaN));
	// rounding checks
}
{
	use precision 9;
	AddTestCase('maxx201:p9 r:HALF_UP (0 + decimal.max(12345678000,1)) rounded', 1.23456780e+10, 0 + decimal.max(12345678000,1));
	AddTestCase('maxx202:p9 r:HALF_UP (0 + decimal.max(1,12345678000)) rounded', 1.23456780e+10, 0 + decimal.max(1,12345678000));
	AddTestCase('maxx203:p9 r:HALF_UP (0 + decimal.max(1234567800,1)) rounded', 1.23456780e+9, 0 + decimal.max(1234567800,1));
	AddTestCase('maxx204:p9 r:HALF_UP (0 + decimal.max(1,1234567800)) rounded', 1.23456780e+9, 0 + decimal.max(1,1234567800));
	AddTestCase('maxx205:p9 r:HALF_UP (0 + decimal.max(1234567890,1)) rounded', 1.23456789e+9, 0 + decimal.max(1234567890,1));
	AddTestCase('maxx206:p9 r:HALF_UP (0 + decimal.max(1,1234567890)) rounded', 1.23456789e+9, 0 + decimal.max(1,1234567890));
	AddTestCase('maxx207:p9 r:HALF_UP (0 + decimal.max(1234567891,1)) inexact rounded', 1.23456789e+9, 0 + decimal.max(1234567891,1));
	AddTestCase('maxx208:p9 r:HALF_UP (0 + decimal.max(1,1234567891)) inexact rounded', 1.23456789e+9, 0 + decimal.max(1,1234567891));
	AddTestCase('maxx209:p9 r:HALF_UP (0 + decimal.max(12345678901,1)) inexact rounded', 1.23456789e+10, 0 + decimal.max(12345678901,1));
	AddTestCase('maxx210:p9 r:HALF_UP (0 + decimal.max(1,12345678901)) inexact rounded', 1.23456789e+10, 0 + decimal.max(1,12345678901));
	AddTestCase('maxx211:p9 r:HALF_UP (0 + decimal.max(1234567896,1)) inexact rounded', 1.23456790e+9, 0 + decimal.max(1234567896,1));
	AddTestCase('maxx212:p9 r:HALF_UP (0 + decimal.max(1,1234567896)) inexact rounded', 1.23456790e+9, 0 + decimal.max(1,1234567896));
	AddTestCase('maxx213:p9 r:HALF_UP (0 + decimal.max(-1234567891,1))', 1, 0 + decimal.max(-1234567891,1));
	AddTestCase('maxx214:p9 r:HALF_UP (0 + decimal.max(1,-1234567891))', 1, 0 + decimal.max(1,-1234567891));
	AddTestCase('maxx215:p9 r:HALF_UP (0 + decimal.max(-12345678901,1))', 1, 0 + decimal.max(-12345678901,1));
	AddTestCase('maxx216:p9 r:HALF_UP (0 + decimal.max(1,-12345678901))', 1, 0 + decimal.max(1,-12345678901));
	AddTestCase('maxx217:p9 r:HALF_UP (0 + decimal.max(-1234567896,1))', 1, 0 + decimal.max(-1234567896,1));
	AddTestCase('maxx218:p9 r:HALF_UP (0 + decimal.max(1,-1234567896))', 1, 0 + decimal.max(1,-1234567896));
}
{
	use precision 15;
	AddTestCase('maxx221:p15 r:HALF_UP (0 + decimal.max(12345678000,1))', 12345678000, 0 + decimal.max(12345678000,1));
	AddTestCase('maxx222:p15 r:HALF_UP (0 + decimal.max(1,12345678000))', 12345678000, 0 + decimal.max(1,12345678000));
	AddTestCase('maxx223:p15 r:HALF_UP (0 + decimal.max(1234567800,1))', 1234567800, 0 + decimal.max(1234567800,1));
	AddTestCase('maxx224:p15 r:HALF_UP (0 + decimal.max(1,1234567800))', 1234567800, 0 + decimal.max(1,1234567800));
	AddTestCase('maxx225:p15 r:HALF_UP (0 + decimal.max(1234567890,1))', 1234567890, 0 + decimal.max(1234567890,1));
	AddTestCase('maxx226:p15 r:HALF_UP (0 + decimal.max(1,1234567890))', 1234567890, 0 + decimal.max(1,1234567890));
	AddTestCase('maxx227:p15 r:HALF_UP (0 + decimal.max(1234567891,1))', 1234567891, 0 + decimal.max(1234567891,1));
	AddTestCase('maxx228:p15 r:HALF_UP (0 + decimal.max(1,1234567891))', 1234567891, 0 + decimal.max(1,1234567891));
	AddTestCase('maxx229:p15 r:HALF_UP (0 + decimal.max(12345678901,1))', 12345678901, 0 + decimal.max(12345678901,1));
	AddTestCase('maxx230:p15 r:HALF_UP (0 + decimal.max(1,12345678901))', 12345678901, 0 + decimal.max(1,12345678901));
	AddTestCase('maxx231:p15 r:HALF_UP (0 + decimal.max(1234567896,1))', 1234567896, 0 + decimal.max(1234567896,1));
	AddTestCase('maxx232:p15 r:HALF_UP (0 + decimal.max(1,1234567896))', 1234567896, 0 + decimal.max(1,1234567896));
	AddTestCase('maxx233:p15 r:HALF_UP (0 + decimal.max(-1234567891,1))', 1, 0 + decimal.max(-1234567891,1));
	AddTestCase('maxx234:p15 r:HALF_UP (0 + decimal.max(1,-1234567891))', 1, 0 + decimal.max(1,-1234567891));
	AddTestCase('maxx235:p15 r:HALF_UP (0 + decimal.max(-12345678901,1))', 1, 0 + decimal.max(-12345678901,1));
	AddTestCase('maxx236:p15 r:HALF_UP (0 + decimal.max(1,-12345678901))', 1, 0 + decimal.max(1,-12345678901));
	AddTestCase('maxx237:p15 r:HALF_UP (0 + decimal.max(-1234567896,1))', 1, 0 + decimal.max(-1234567896,1));
	AddTestCase('maxx238:p15 r:HALF_UP (0 + decimal.max(1,-1234567896))', 1, 0 + decimal.max(1,-1234567896));
	// from examples
	AddTestCase('maxx280:p15 r:HALF_UP (0 + decimal.max(3,2))', 3, 0 + decimal.max(3,2));
	AddTestCase('maxx281:p15 r:HALF_UP (0 + decimal.max(-10,3))', 3, 0 + decimal.max(-10,3));
	AddTestCase('maxx282:p15 r:HALF_UP (0 + decimal.max(1.0,1))', 1, 0 + decimal.max(1.0,1));
	AddTestCase('maxx283:p15 r:HALF_UP (0 + decimal.max(1,1.0))', 1, 0 + decimal.max(1,1.0));
	AddTestCase('maxx284:p15 r:HALF_UP (0 + decimal.max(7,NaN))', NaN, 0 + decimal.max(7,NaN));
	// overflow and underflow tests ...
	AddTestCase('maxx330:p15 r:HALF_UP (0 + decimal.max(+1.23456789012345e-0,9e+999999999))', 9e+999999999, 0 + decimal.max(+1.23456789012345e-0,9e+999999999));
	AddTestCase('maxx331:p15 r:HALF_UP (0 + decimal.max(9e+999999999,+1.23456789012345e-0))', 9e+999999999, 0 + decimal.max(9e+999999999,+1.23456789012345e-0));
	AddTestCase('maxx332:p15 r:HALF_UP (0 + decimal.max(+0.100,9e-999999999))', 0.100, 0 + decimal.max(+0.100,9e-999999999));
	AddTestCase('maxx333:p15 r:HALF_UP (0 + decimal.max(9e-999999999,+0.100))', 0.100, 0 + decimal.max(9e-999999999,+0.100));
	AddTestCase('maxx335:p15 r:HALF_UP (0 + decimal.max(-1.23456789012345e-0,9e+999999999))', 9e+999999999, 0 + decimal.max(-1.23456789012345e-0,9e+999999999));
	AddTestCase('maxx336:p15 r:HALF_UP (0 + decimal.max(9e+999999999,-1.23456789012345e-0))', 9e+999999999, 0 + decimal.max(9e+999999999,-1.23456789012345e-0));
	AddTestCase('maxx337:p15 r:HALF_UP (0 + decimal.max(-0.100,9e-999999999))', 9e-999999999, 0 + decimal.max(-0.100,9e-999999999));
	AddTestCase('maxx338:p15 r:HALF_UP (0 + decimal.max(9e-999999999,-0.100))', 9e-999999999, 0 + decimal.max(9e-999999999,-0.100));
	AddTestCase('maxx339:p15 r:HALF_UP (0 + decimal.max(1e-599999999,1e-400000001))', 1e-400000001, 0 + decimal.max(1e-599999999,1e-400000001));
	AddTestCase('maxx340:p15 r:HALF_UP (0 + decimal.max(1e-599999999,1e-400000000))', 1e-400000000, 0 + decimal.max(1e-599999999,1e-400000000));
	AddTestCase('maxx341:p15 r:HALF_UP (0 + decimal.max(1e-600000000,1e-400000000))', 1e-400000000, 0 + decimal.max(1e-600000000,1e-400000000));
	AddTestCase('maxx342:p15 r:HALF_UP (0 + decimal.max(9e-999999998,0.01))', 0.01, 0 + decimal.max(9e-999999998,0.01));
	AddTestCase('maxx343:p15 r:HALF_UP (0 + decimal.max(9e-999999998,0.1))', 0.1, 0 + decimal.max(9e-999999998,0.1));
	AddTestCase('maxx344:p15 r:HALF_UP (0 + decimal.max(0.01,9e-999999998))', 0.01, 0 + decimal.max(0.01,9e-999999998));
	AddTestCase('maxx345:p15 r:HALF_UP (0 + decimal.max(1e599999999,1e400000001))', 1e+599999999, 0 + decimal.max(1e599999999,1e400000001));
	AddTestCase('maxx346:p15 r:HALF_UP (0 + decimal.max(1e599999999,1e400000000))', 1e+599999999, 0 + decimal.max(1e599999999,1e400000000));
	AddTestCase('maxx347:p15 r:HALF_UP (0 + decimal.max(1e600000000,1e400000000))', 1e+600000000, 0 + decimal.max(1e600000000,1e400000000));
	AddTestCase('maxx348:p15 r:HALF_UP (0 + decimal.max(9e999999998,100))', 9e+999999998, 0 + decimal.max(9e999999998,100));
	AddTestCase('maxx349:p15 r:HALF_UP (0 + decimal.max(9e999999998,10))', 9e+999999998, 0 + decimal.max(9e999999998,10));
	AddTestCase('maxx350:p15 r:HALF_UP (0 + decimal.max(100,9e999999998))', 9e+999999998, 0 + decimal.max(100,9e999999998));
	// signs
	AddTestCase('maxx351:p15 r:HALF_UP (0 + decimal.max(1e+777777777,1e+411111111))', 1e+777777777, 0 + decimal.max(1e+777777777,1e+411111111));
	AddTestCase('maxx352:p15 r:HALF_UP (0 + decimal.max(1e+777777777,-1e+411111111))', 1e+777777777, 0 + decimal.max(1e+777777777,-1e+411111111));
	AddTestCase('maxx353:p15 r:HALF_UP (0 + decimal.max(-1e+777777777,1e+411111111))', 1e+411111111, 0 + decimal.max(-1e+777777777,1e+411111111));
	AddTestCase('maxx354:p15 r:HALF_UP (0 + decimal.max(-1e+777777777,-1e+411111111))', -1e+411111111, 0 + decimal.max(-1e+777777777,-1e+411111111));
	AddTestCase('maxx355:p15 r:HALF_UP (0 + decimal.max(1e-777777777,1e-411111111))', 1e-411111111, 0 + decimal.max(1e-777777777,1e-411111111));
	AddTestCase('maxx356:p15 r:HALF_UP (0 + decimal.max(1e-777777777,-1e-411111111))', 1e-777777777, 0 + decimal.max(1e-777777777,-1e-411111111));
	AddTestCase('maxx357:p15 r:HALF_UP (0 + decimal.max(-1e-777777777,1e-411111111))', 1e-411111111, 0 + decimal.max(-1e-777777777,1e-411111111));
	AddTestCase('maxx358:p15 r:HALF_UP (0 + decimal.max(-1e-777777777,-1e-411111111))', -1e-777777777, 0 + decimal.max(-1e-777777777,-1e-411111111));
	// expanded list from min/max 754r purple prose
	// [explicit tests for exponent ordering]
	AddTestCase('maxx401:p15 r:HALF_UP (0 + decimal.max(decimal.POSITIVE_INFINITY,1.1))', decimal.POSITIVE_INFINITY, 0 + decimal.max(decimal.POSITIVE_INFINITY,1.1));
	AddTestCase('maxx402:p15 r:HALF_UP (0 + decimal.max(1.1,1))', 1.1, 0 + decimal.max(1.1,1));
	AddTestCase('maxx403:p15 r:HALF_UP (0 + decimal.max(1,1.0))', 1, 0 + decimal.max(1,1.0));
	AddTestCase('maxx404:p15 r:HALF_UP (0 + decimal.max(1.0,0.1))', 1.0, 0 + decimal.max(1.0,0.1));
	AddTestCase('maxx405:p15 r:HALF_UP (0 + decimal.max(0.1,0.10))', 0.1, 0 + decimal.max(0.1,0.10));
	AddTestCase('maxx406:p15 r:HALF_UP (0 + decimal.max(0.10,0.100))', 0.10, 0 + decimal.max(0.10,0.100));
	AddTestCase('maxx407:p15 r:HALF_UP (0 + decimal.max(0.10,0))', 0.10, 0 + decimal.max(0.10,0));
	AddTestCase('maxx408:p15 r:HALF_UP (0 + decimal.max(0,0.0))', 0, 0 + decimal.max(0,0.0));
	AddTestCase('maxx409:p15 r:HALF_UP (0 + decimal.max(0.0,-0))', 0.0, 0 + decimal.max(0.0,-0));
	AddTestCase('maxx410:p15 r:HALF_UP (0 + decimal.max(0.0,-0.0))', 0.0, 0 + decimal.max(0.0,-0.0));
	AddTestCase('maxx411:p15 r:HALF_UP (0 + decimal.max(0.00,-0.0))', 0.00, 0 + decimal.max(0.00,-0.0));
	AddTestCase('maxx412:p15 r:HALF_UP (0 + decimal.max(0.0,-0.00))', 0.0, 0 + decimal.max(0.0,-0.00));
	AddTestCase('maxx413:p15 r:HALF_UP (0 + decimal.max(0,-0.0))', 0, 0 + decimal.max(0,-0.0));
	AddTestCase('maxx414:p15 r:HALF_UP (0 + decimal.max(0,-0))', 0, 0 + decimal.max(0,-0));
	AddTestCase('maxx415:p15 r:HALF_UP (0 + decimal.max(-0.0,-0))', -0.0, 0 + decimal.max(-0.0,-0));
	AddTestCase('maxx416:p15 r:HALF_UP (0 + decimal.max(-0,-0.100))', -0, 0 + decimal.max(-0,-0.100));
	AddTestCase('maxx417:p15 r:HALF_UP (0 + decimal.max(-0.100,-0.10))', -0.100, 0 + decimal.max(-0.100,-0.10));
	AddTestCase('maxx418:p15 r:HALF_UP (0 + decimal.max(-0.10,-0.1))', -0.10, 0 + decimal.max(-0.10,-0.1));
	AddTestCase('maxx419:p15 r:HALF_UP (0 + decimal.max(-0.1,-1.0))', -0.1, 0 + decimal.max(-0.1,-1.0));
	AddTestCase('maxx420:p15 r:HALF_UP (0 + decimal.max(-1.0,-1))', -1.0, 0 + decimal.max(-1.0,-1));
	AddTestCase('maxx421:p15 r:HALF_UP (0 + decimal.max(-1,-1.1))', -1, 0 + decimal.max(-1,-1.1));
	AddTestCase('maxx423:p15 r:HALF_UP (0 + decimal.max(-1.1,decimal.NEGATIVE_INFINITY))', -1.1, 0 + decimal.max(-1.1,decimal.NEGATIVE_INFINITY));
	// same with operands reversed
	AddTestCase('maxx431:p15 r:HALF_UP (0 + decimal.max(1.1,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.max(1.1,decimal.POSITIVE_INFINITY));
	AddTestCase('maxx432:p15 r:HALF_UP (0 + decimal.max(1,1.1))', 1.1, 0 + decimal.max(1,1.1));
	AddTestCase('maxx433:p15 r:HALF_UP (0 + decimal.max(1.0,1))', 1, 0 + decimal.max(1.0,1));
	AddTestCase('maxx434:p15 r:HALF_UP (0 + decimal.max(0.1,1.0))', 1.0, 0 + decimal.max(0.1,1.0));
	AddTestCase('maxx435:p15 r:HALF_UP (0 + decimal.max(0.10,0.1))', 0.1, 0 + decimal.max(0.10,0.1));
	AddTestCase('maxx436:p15 r:HALF_UP (0 + decimal.max(0.100,0.10))', 0.10, 0 + decimal.max(0.100,0.10));
	AddTestCase('maxx437:p15 r:HALF_UP (0 + decimal.max(0,0.10))', 0.10, 0 + decimal.max(0,0.10));
	AddTestCase('maxx438:p15 r:HALF_UP (0 + decimal.max(0.0,0))', 0, 0 + decimal.max(0.0,0));
	AddTestCase('maxx439:p15 r:HALF_UP (0 + decimal.max(-0,0.0))', 0.0, 0 + decimal.max(-0,0.0));
	AddTestCase('maxx440:p15 r:HALF_UP (0 + decimal.max(-0.0,0.0))', 0.0, 0 + decimal.max(-0.0,0.0));
	AddTestCase('maxx441:p15 r:HALF_UP (0 + decimal.max(-0.0,0.00))', 0.00, 0 + decimal.max(-0.0,0.00));
	AddTestCase('maxx442:p15 r:HALF_UP (0 + decimal.max(-0.00,0.0))', 0.0, 0 + decimal.max(-0.00,0.0));
	AddTestCase('maxx443:p15 r:HALF_UP (0 + decimal.max(-0.0,0))', 0, 0 + decimal.max(-0.0,0));
	AddTestCase('maxx444:p15 r:HALF_UP (0 + decimal.max(-0,0))', 0, 0 + decimal.max(-0,0));
	AddTestCase('maxx445:p15 r:HALF_UP (0 + decimal.max(-0,-0.0))', -0.0, 0 + decimal.max(-0,-0.0));
	AddTestCase('maxx446:p15 r:HALF_UP (0 + decimal.max(-0.100,-0))', -0, 0 + decimal.max(-0.100,-0));
	AddTestCase('maxx447:p15 r:HALF_UP (0 + decimal.max(-0.10,-0.100))', -0.100, 0 + decimal.max(-0.10,-0.100));
	AddTestCase('maxx448:p15 r:HALF_UP (0 + decimal.max(-0.1,-0.10))', -0.10, 0 + decimal.max(-0.1,-0.10));
	AddTestCase('maxx449:p15 r:HALF_UP (0 + decimal.max(-1.0,-0.1))', -0.1, 0 + decimal.max(-1.0,-0.1));
	AddTestCase('maxx450:p15 r:HALF_UP (0 + decimal.max(-1,-1.0))', -1.0, 0 + decimal.max(-1,-1.0));
	AddTestCase('maxx451:p15 r:HALF_UP (0 + decimal.max(-1.1,-1))', -1, 0 + decimal.max(-1.1,-1));
	AddTestCase('maxx453:p15 r:HALF_UP (0 + decimal.max(decimal.NEGATIVE_INFINITY,-1.1))', -1.1, 0 + decimal.max(decimal.NEGATIVE_INFINITY,-1.1));
	// largies
	AddTestCase('maxx460:p15 r:HALF_UP (0 + decimal.max(1000,1e+3))', 1e+3, 0 + decimal.max(1000,1e+3));
	AddTestCase('maxx461:p15 r:HALF_UP (0 + decimal.max(1e+3,1000))', 1e+3, 0 + decimal.max(1e+3,1000));
	AddTestCase('maxx462:p15 r:HALF_UP (0 + decimal.max(1000,-1e+3))', 1000, 0 + decimal.max(1000,-1e+3));
	AddTestCase('maxx463:p15 r:HALF_UP (0 + decimal.max(1e+3,-1000))', 1e+3, 0 + decimal.max(1e+3,-1000));
	AddTestCase('maxx464:p15 r:HALF_UP (0 + decimal.max(-1000,1e+3))', 1e+3, 0 + decimal.max(-1000,1e+3));
	AddTestCase('maxx465:p15 r:HALF_UP (0 + decimal.max(-1e+3,1000))', 1000, 0 + decimal.max(-1e+3,1000));
	AddTestCase('maxx466:p15 r:HALF_UP (0 + decimal.max(-1000,-1e+3))', -1000, 0 + decimal.max(-1000,-1e+3));
	AddTestCase('maxx467:p15 r:HALF_UP (0 + decimal.max(-1e+3,-1000))', -1000, 0 + decimal.max(-1e+3,-1000));
	// rounding (results treated as though plus)
}
{
	use precision 3;
	AddTestCase('maxx470:p3 r:HALF_UP (0 + decimal.max(1,.5))', 1, 0 + decimal.max(1,.5));
	AddTestCase('maxx471:p3 r:HALF_UP (0 + decimal.max(10,5))', 10, 0 + decimal.max(10,5));
	AddTestCase('maxx472:p3 r:HALF_UP (0 + decimal.max(100,50))', 100, 0 + decimal.max(100,50));
	AddTestCase('maxx473:p3 r:HALF_UP (0 + decimal.max(1000,500)) rounded', 1.00e+3, 0 + decimal.max(1000,500));
	AddTestCase('maxx474:p3 r:HALF_UP (0 + decimal.max(10000,5000)) rounded', 1.00e+4, 0 + decimal.max(10000,5000));
	AddTestCase('maxx475:p3 r:HALF_UP (0 + decimal.max(6,.5))', 6, 0 + decimal.max(6,.5));
	AddTestCase('maxx476:p3 r:HALF_UP (0 + decimal.max(66,5))', 66, 0 + decimal.max(66,5));
	AddTestCase('maxx477:p3 r:HALF_UP (0 + decimal.max(666,50))', 666, 0 + decimal.max(666,50));
	AddTestCase('maxx478:p3 r:HALF_UP (0 + decimal.max(6666,500)) rounded inexact', 6.67e+3, 0 + decimal.max(6666,500));
	AddTestCase('maxx479:p3 r:HALF_UP (0 + decimal.max(66666,5000)) rounded inexact', 6.67e+4, 0 + decimal.max(66666,5000));
	AddTestCase('maxx480:p3 r:HALF_UP (0 + decimal.max(33333,5000)) rounded inexact', 3.33e+4, 0 + decimal.max(33333,5000));
	AddTestCase('maxx481:p3 r:HALF_UP (0 + decimal.max(.5,1))', 1, 0 + decimal.max(.5,1));
	AddTestCase('maxx482:p3 r:HALF_UP (0 + decimal.max(.5,10))', 10, 0 + decimal.max(.5,10));
	AddTestCase('maxx483:p3 r:HALF_UP (0 + decimal.max(.5,100))', 100, 0 + decimal.max(.5,100));
	AddTestCase('maxx484:p3 r:HALF_UP (0 + decimal.max(.5,1000)) rounded', 1.00e+3, 0 + decimal.max(.5,1000));
	AddTestCase('maxx485:p3 r:HALF_UP (0 + decimal.max(.5,10000)) rounded', 1.00e+4, 0 + decimal.max(.5,10000));
	AddTestCase('maxx486:p3 r:HALF_UP (0 + decimal.max(.5,6))', 6, 0 + decimal.max(.5,6));
	AddTestCase('maxx487:p3 r:HALF_UP (0 + decimal.max(.5,66))', 66, 0 + decimal.max(.5,66));
	AddTestCase('maxx488:p3 r:HALF_UP (0 + decimal.max(.5,666))', 666, 0 + decimal.max(.5,666));
	AddTestCase('maxx489:p3 r:HALF_UP (0 + decimal.max(.5,6666)) rounded inexact', 6.67e+3, 0 + decimal.max(.5,6666));
	AddTestCase('maxx490:p3 r:HALF_UP (0 + decimal.max(.5,66666)) rounded inexact', 6.67e+4, 0 + decimal.max(.5,66666));
	AddTestCase('maxx491:p3 r:HALF_UP (0 + decimal.max(.5,33333)) rounded inexact', 3.33e+4, 0 + decimal.max(.5,33333));
	// overflow tests
}
{
	use precision 3;
	AddTestCase('maxx501:p3 r:HALF_UP (0 + decimal.max(-9.999e+999999999,0))', 0, 0 + decimal.max(-9.999e+999999999,0));
	// subnormals and underflow
}
{
	use precision 3;
	AddTestCase('maxx510:p3 r:HALF_UP (0 + decimal.max(1.00e-999,0))', 1.00e-999, 0 + decimal.max(1.00e-999,0));
	// next is rounded to nmin
	AddTestCase('maxx530:p3 r:HALF_UP (0 + decimal.max(-1.00e-999,0))', 0, 0 + decimal.max(-1.00e-999,0));
	AddTestCase('maxx531:p3 r:HALF_UP (0 + decimal.max(-0.1e-999,0))', 0, 0 + decimal.max(-0.1e-999,0));
	AddTestCase('maxx532:p3 r:HALF_UP (0 + decimal.max(-0.10e-999,0))', 0, 0 + decimal.max(-0.10e-999,0));
	AddTestCase('maxx533:p3 r:HALF_UP (0 + decimal.max(-0.100e-999,0))', 0, 0 + decimal.max(-0.100e-999,0));
	AddTestCase('maxx534:p3 r:HALF_UP (0 + decimal.max(-0.01e-999,0))', 0, 0 + decimal.max(-0.01e-999,0));
	AddTestCase('maxx535:p3 r:HALF_UP (0 + decimal.max(-0.999e-999,0))', 0, 0 + decimal.max(-0.999e-999,0));
	AddTestCase('maxx536:p3 r:HALF_UP (0 + decimal.max(-0.099e-999,0))', 0, 0 + decimal.max(-0.099e-999,0));
	AddTestCase('maxx537:p3 r:HALF_UP (0 + decimal.max(-0.009e-999,0))', 0, 0 + decimal.max(-0.009e-999,0));
	AddTestCase('maxx538:p3 r:HALF_UP (0 + decimal.max(-0.001e-999,0))', 0, 0 + decimal.max(-0.001e-999,0));
	AddTestCase('maxx539:p3 r:HALF_UP (0 + decimal.max(-0.0009e-999,0))', 0, 0 + decimal.max(-0.0009e-999,0));
	AddTestCase('maxx540:p3 r:HALF_UP (0 + decimal.max(-0.0001e-999,0))', 0, 0 + decimal.max(-0.0001e-999,0));
	// misalignment traps for little-endian
}
{
	use precision 9;
	AddTestCase('maxx551:p9 r:HALF_UP (0 + decimal.max(1.0,0.1))', 1.0, 0 + decimal.max(1.0,0.1));
	AddTestCase('maxx552:p9 r:HALF_UP (0 + decimal.max(0.1,1.0))', 1.0, 0 + decimal.max(0.1,1.0));
	AddTestCase('maxx553:p9 r:HALF_UP (0 + decimal.max(10.0,0.1))', 10.0, 0 + decimal.max(10.0,0.1));
	AddTestCase('maxx554:p9 r:HALF_UP (0 + decimal.max(0.1,10.0))', 10.0, 0 + decimal.max(0.1,10.0));
	AddTestCase('maxx555:p9 r:HALF_UP (0 + decimal.max(100,1.0))', 100, 0 + decimal.max(100,1.0));
	AddTestCase('maxx556:p9 r:HALF_UP (0 + decimal.max(1.0,100))', 100, 0 + decimal.max(1.0,100));
	AddTestCase('maxx557:p9 r:HALF_UP (0 + decimal.max(1000,10.0))', 1000, 0 + decimal.max(1000,10.0));
	AddTestCase('maxx558:p9 r:HALF_UP (0 + decimal.max(10.0,1000))', 1000, 0 + decimal.max(10.0,1000));
	AddTestCase('maxx559:p9 r:HALF_UP (0 + decimal.max(10000,100.0))', 10000, 0 + decimal.max(10000,100.0));
	AddTestCase('maxx560:p9 r:HALF_UP (0 + decimal.max(100.0,10000))', 10000, 0 + decimal.max(100.0,10000));
	AddTestCase('maxx661:p9 r:HALF_UP (0 + decimal.max(100000,1000.0))', 100000, 0 + decimal.max(100000,1000.0));
	AddTestCase('maxx662:p9 r:HALF_UP (0 + decimal.max(1000.0,100000))', 100000, 0 + decimal.max(1000.0,100000));
	AddTestCase('maxx663:p9 r:HALF_UP (0 + decimal.max(1000000,10000.0))', 1000000, 0 + decimal.max(1000000,10000.0));
	AddTestCase('maxx664:p9 r:HALF_UP (0 + decimal.max(10000.0,1000000))', 1000000, 0 + decimal.max(10000.0,1000000));
	// payload decapitate
}
{
	use precision 5;
	AddTestCase('maxx670:p5 r:HALF_UP (0 + decimal.max(11,-NaN)) invalid_operation', -NaN, 0 + decimal.max(11,-NaN));
	// null tests
	AddTestCase('maxx900:p5 r:HALF_UP (0 + decimal.max(10,null)) invalid_operation', 10, 0 + decimal.max(10,null));
	AddTestCase('maxx901:p5 r:HALF_UP (0 + decimal.max(null,10)) invalid_operation', 10, 0 + decimal.max(null,10));
	}
}
test();
