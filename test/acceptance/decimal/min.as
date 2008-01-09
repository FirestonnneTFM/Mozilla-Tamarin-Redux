use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "min.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// min.dectest -- decimal minimum                                     --
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
AddTestCase('mnmx001:p9 r:HALF_UP (0 + decimal.min(-2,-2))', -2, 0 + decimal.min(-2,-2));
AddTestCase('mnmx002:p9 r:HALF_UP (0 + decimal.min(-2,-1))', -2, 0 + decimal.min(-2,-1));
AddTestCase('mnmx003:p9 r:HALF_UP (0 + decimal.min(-2,0))', -2, 0 + decimal.min(-2,0));
AddTestCase('mnmx004:p9 r:HALF_UP (0 + decimal.min(-2,1))', -2, 0 + decimal.min(-2,1));
AddTestCase('mnmx005:p9 r:HALF_UP (0 + decimal.min(-2,2))', -2, 0 + decimal.min(-2,2));
AddTestCase('mnmx006:p9 r:HALF_UP (0 + decimal.min(-1,-2))', -2, 0 + decimal.min(-1,-2));
AddTestCase('mnmx007:p9 r:HALF_UP (0 + decimal.min(-1,-1))', -1, 0 + decimal.min(-1,-1));
AddTestCase('mnmx008:p9 r:HALF_UP (0 + decimal.min(-1,0))', -1, 0 + decimal.min(-1,0));
AddTestCase('mnmx009:p9 r:HALF_UP (0 + decimal.min(-1,1))', -1, 0 + decimal.min(-1,1));
AddTestCase('mnmx010:p9 r:HALF_UP (0 + decimal.min(-1,2))', -1, 0 + decimal.min(-1,2));
AddTestCase('mnmx011:p9 r:HALF_UP (0 + decimal.min(0,-2))', -2, 0 + decimal.min(0,-2));
AddTestCase('mnmx012:p9 r:HALF_UP (0 + decimal.min(0,-1))', -1, 0 + decimal.min(0,-1));
AddTestCase('mnmx013:p9 r:HALF_UP (0 + decimal.min(0,0))', 0, 0 + decimal.min(0,0));
AddTestCase('mnmx014:p9 r:HALF_UP (0 + decimal.min(0,1))', 0, 0 + decimal.min(0,1));
AddTestCase('mnmx015:p9 r:HALF_UP (0 + decimal.min(0,2))', 0, 0 + decimal.min(0,2));
AddTestCase('mnmx016:p9 r:HALF_UP (0 + decimal.min(1,-2))', -2, 0 + decimal.min(1,-2));
AddTestCase('mnmx017:p9 r:HALF_UP (0 + decimal.min(1,-1))', -1, 0 + decimal.min(1,-1));
AddTestCase('mnmx018:p9 r:HALF_UP (0 + decimal.min(1,0))', 0, 0 + decimal.min(1,0));
AddTestCase('mnmx019:p9 r:HALF_UP (0 + decimal.min(1,1))', 1, 0 + decimal.min(1,1));
AddTestCase('mnmx020:p9 r:HALF_UP (0 + decimal.min(1,2))', 1, 0 + decimal.min(1,2));
AddTestCase('mnmx021:p9 r:HALF_UP (0 + decimal.min(2,-2))', -2, 0 + decimal.min(2,-2));
AddTestCase('mnmx022:p9 r:HALF_UP (0 + decimal.min(2,-1))', -1, 0 + decimal.min(2,-1));
AddTestCase('mnmx023:p9 r:HALF_UP (0 + decimal.min(2,0))', 0, 0 + decimal.min(2,0));
AddTestCase('mnmx025:p9 r:HALF_UP (0 + decimal.min(2,1))', 1, 0 + decimal.min(2,1));
AddTestCase('mnmx026:p9 r:HALF_UP (0 + decimal.min(2,2))', 2, 0 + decimal.min(2,2));
// extended zeros
AddTestCase('mnmx030:p9 r:HALF_UP (0 + decimal.min(0,0))', 0, 0 + decimal.min(0,0));
AddTestCase('mnmx031:p9 r:HALF_UP (0 + decimal.min(0,-0))', -0, 0 + decimal.min(0,-0));
AddTestCase('mnmx032:p9 r:HALF_UP (0 + decimal.min(0,-0.0))', -0.0, 0 + decimal.min(0,-0.0));
AddTestCase('mnmx033:p9 r:HALF_UP (0 + decimal.min(0,0.0))', 0.0, 0 + decimal.min(0,0.0));
AddTestCase('mnmx034:p9 r:HALF_UP (0 + decimal.min(-0,0))', -0, 0 + decimal.min(-0,0));
AddTestCase('mnmx035:p9 r:HALF_UP (0 + decimal.min(-0,-0))', -0, 0 + decimal.min(-0,-0));
AddTestCase('mnmx036:p9 r:HALF_UP (0 + decimal.min(-0,-0.0))', -0, 0 + decimal.min(-0,-0.0));
AddTestCase('mnmx037:p9 r:HALF_UP (0 + decimal.min(-0,0.0))', -0, 0 + decimal.min(-0,0.0));
AddTestCase('mnmx038:p9 r:HALF_UP (0 + decimal.min(0.0,0))', 0.0, 0 + decimal.min(0.0,0));
AddTestCase('mnmx039:p9 r:HALF_UP (0 + decimal.min(0.0,-0))', -0, 0 + decimal.min(0.0,-0));
AddTestCase('mnmx040:p9 r:HALF_UP (0 + decimal.min(0.0,-0.0))', -0.0, 0 + decimal.min(0.0,-0.0));
AddTestCase('mnmx041:p9 r:HALF_UP (0 + decimal.min(0.0,0.0))', 0.0, 0 + decimal.min(0.0,0.0));
AddTestCase('mnmx042:p9 r:HALF_UP (0 + decimal.min(-0.0,0))', -0.0, 0 + decimal.min(-0.0,0));
AddTestCase('mnmx043:p9 r:HALF_UP (0 + decimal.min(-0.0,-0))', -0, 0 + decimal.min(-0.0,-0));
AddTestCase('mnmx044:p9 r:HALF_UP (0 + decimal.min(-0.0,-0.0))', -0.0, 0 + decimal.min(-0.0,-0.0));
AddTestCase('mnmx045:p9 r:HALF_UP (0 + decimal.min(-0.0,0.0))', -0.0, 0 + decimal.min(-0.0,0.0));
AddTestCase('mnmx046:p9 r:HALF_UP (0 + decimal.min(0e1,-0e1))', -0e+1, 0 + decimal.min(0e1,-0e1));
AddTestCase('mnmx047:p9 r:HALF_UP (0 + decimal.min(-0e1,0e2))', -0e+1, 0 + decimal.min(-0e1,0e2));
AddTestCase('mnmx048:p9 r:HALF_UP (0 + decimal.min(0e2,0e1))', 0e+1, 0 + decimal.min(0e2,0e1));
AddTestCase('mnmx049:p9 r:HALF_UP (0 + decimal.min(0e1,0e2))', 0e+1, 0 + decimal.min(0e1,0e2));
AddTestCase('mnmx050:p9 r:HALF_UP (0 + decimal.min(-0e3,-0e2))', -0e+3, 0 + decimal.min(-0e3,-0e2));
AddTestCase('mnmx051:p9 r:HALF_UP (0 + decimal.min(-0e2,-0e3))', -0e+3, 0 + decimal.min(-0e2,-0e3));
// specials
{
	use precision 9;
	AddTestCase('mnmx090:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx091:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,-1000))', -1000, 0 + decimal.min(decimal.POSITIVE_INFINITY,-1000));
	AddTestCase('mnmx092:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,-1))', -1, 0 + decimal.min(decimal.POSITIVE_INFINITY,-1));
	AddTestCase('mnmx093:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,-0))', -0, 0 + decimal.min(decimal.POSITIVE_INFINITY,-0));
	AddTestCase('mnmx094:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,0))', 0, 0 + decimal.min(decimal.POSITIVE_INFINITY,0));
	AddTestCase('mnmx095:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,1))', 1, 0 + decimal.min(decimal.POSITIVE_INFINITY,1));
	AddTestCase('mnmx096:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,1000))', 1000, 0 + decimal.min(decimal.POSITIVE_INFINITY,1000));
	AddTestCase('mnmx097:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.min(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx098:p9 r:HALF_UP (0 + decimal.min(-1000,decimal.POSITIVE_INFINITY))', -1000, 0 + decimal.min(-1000,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx099:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx100:p9 r:HALF_UP (0 + decimal.min(-1,decimal.POSITIVE_INFINITY))', -1, 0 + decimal.min(-1,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx101:p9 r:HALF_UP (0 + decimal.min(-0,decimal.POSITIVE_INFINITY))', -0, 0 + decimal.min(-0,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx102:p9 r:HALF_UP (0 + decimal.min(0,decimal.POSITIVE_INFINITY))', 0, 0 + decimal.min(0,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx103:p9 r:HALF_UP (0 + decimal.min(1,decimal.POSITIVE_INFINITY))', 1, 0 + decimal.min(1,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx104:p9 r:HALF_UP (0 + decimal.min(1000,decimal.POSITIVE_INFINITY))', 1000, 0 + decimal.min(1000,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx105:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.min(decimal.POSITIVE_INFINITY,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx120:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx121:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,-1000))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.NEGATIVE_INFINITY,-1000));
	AddTestCase('mnmx122:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,-1))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.NEGATIVE_INFINITY,-1));
	AddTestCase('mnmx123:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,-0))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.NEGATIVE_INFINITY,-0));
	AddTestCase('mnmx124:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,0))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.NEGATIVE_INFINITY,0));
	AddTestCase('mnmx125:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,1))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.NEGATIVE_INFINITY,1));
	AddTestCase('mnmx126:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,1000))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.NEGATIVE_INFINITY,1000));
	AddTestCase('mnmx127:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.NEGATIVE_INFINITY,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx128:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.NEGATIVE_INFINITY,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx129:p9 r:HALF_UP (0 + decimal.min(-1000,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(-1000,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx130:p9 r:HALF_UP (0 + decimal.min(-1,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(-1,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx131:p9 r:HALF_UP (0 + decimal.min(-0,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(-0,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx132:p9 r:HALF_UP (0 + decimal.min(0,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(0,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx133:p9 r:HALF_UP (0 + decimal.min(1,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(1,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx134:p9 r:HALF_UP (0 + decimal.min(1000,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(1000,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx135:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.POSITIVE_INFINITY,decimal.NEGATIVE_INFINITY));
	// 2004.08.02 754r chooses number over nan in mixed cases
	AddTestCase('mnmx141:p9 r:HALF_UP (0 + decimal.min(NaN,decimal.NEGATIVE_INFINITY))', NaN, 0 + decimal.min(NaN,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx142:p9 r:HALF_UP (0 + decimal.min(NaN,-1000))', NaN, 0 + decimal.min(NaN,-1000));
	AddTestCase('mnmx143:p9 r:HALF_UP (0 + decimal.min(NaN,-1))', NaN, 0 + decimal.min(NaN,-1));
	AddTestCase('mnmx144:p9 r:HALF_UP (0 + decimal.min(NaN,-0))', NaN, 0 + decimal.min(NaN,-0));
	AddTestCase('mnmx145:p9 r:HALF_UP (0 + decimal.min(NaN,0))', NaN, 0 + decimal.min(NaN,0));
	AddTestCase('mnmx146:p9 r:HALF_UP (0 + decimal.min(NaN,1))', NaN, 0 + decimal.min(NaN,1));
	AddTestCase('mnmx147:p9 r:HALF_UP (0 + decimal.min(NaN,1000))', NaN, 0 + decimal.min(NaN,1000));
	AddTestCase('mnmx148:p9 r:HALF_UP (0 + decimal.min(NaN,decimal.POSITIVE_INFINITY))', NaN, 0 + decimal.min(NaN,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx149:p9 r:HALF_UP (0 + decimal.min(NaN,NaN))', NaN, 0 + decimal.min(NaN,NaN));
	AddTestCase('mnmx150:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,NaN))', NaN, 0 + decimal.min(decimal.NEGATIVE_INFINITY,NaN));
	AddTestCase('mnmx151:p9 r:HALF_UP (0 + decimal.min(-1000,NaN))', NaN, 0 + decimal.min(-1000,NaN));
	AddTestCase('mnmx152:p9 r:HALF_UP (0 + decimal.min(-1,-NaN))', NaN, 0 + decimal.min(-1,-NaN));
	AddTestCase('mnmx153:p9 r:HALF_UP (0 + decimal.min(-0,NaN))', NaN, 0 + decimal.min(-0,NaN));
	AddTestCase('mnmx154:p9 r:HALF_UP (0 + decimal.min(0,-NaN))', NaN, 0 + decimal.min(0,-NaN));
	AddTestCase('mnmx155:p9 r:HALF_UP (0 + decimal.min(1,NaN))', NaN, 0 + decimal.min(1,NaN));
	AddTestCase('mnmx156:p9 r:HALF_UP (0 + decimal.min(1000,NaN))', NaN, 0 + decimal.min(1000,NaN));
	AddTestCase('mnmx157:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,NaN))',NaN, 0 + decimal.min(decimal.POSITIVE_INFINITY,NaN));
	AddTestCase('mnmx161:p9 r:HALF_UP (0 + decimal.min(NaN,decimal.NEGATIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.min(NaN,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx162:p9 r:HALF_UP (0 + decimal.min(NaN,-1000)) invalid_operation', NaN, 0 + decimal.min(NaN,-1000));
	AddTestCase('mnmx163:p9 r:HALF_UP (0 + decimal.min(NaN,-1)) invalid_operation', NaN, 0 + decimal.min(NaN,-1));
	AddTestCase('mnmx164:p9 r:HALF_UP (0 + decimal.min(NaN,-0)) invalid_operation', NaN, 0 + decimal.min(NaN,-0));
	AddTestCase('mnmx165:p9 r:HALF_UP (0 + decimal.min(-NaN,0)) invalid_operation', -NaN, 0 + decimal.min(-NaN,0));
	AddTestCase('mnmx166:p9 r:HALF_UP (0 + decimal.min(-NaN,1)) invalid_operation', -NaN, 0 + decimal.min(-NaN,1));
	AddTestCase('mnmx167:p9 r:HALF_UP (0 + decimal.min(NaN,1000)) invalid_operation', NaN, 0 + decimal.min(NaN,1000));
	AddTestCase('mnmx168:p9 r:HALF_UP (0 + decimal.min(NaN,NaN)) invalid_operation', NaN, 0 + decimal.min(NaN,NaN));
	AddTestCase('mnmx169:p9 r:HALF_UP (0 + decimal.min(NaN,NaN)) invalid_operation', NaN, 0 + decimal.min(NaN,NaN));
	AddTestCase('mnmx170:p9 r:HALF_UP (0 + decimal.min(NaN,NaN)) invalid_operation', NaN, 0 + decimal.min(NaN,NaN));
	AddTestCase('mnmx171:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,NaN)) invalid_operation', NaN, 0 + decimal.min(decimal.NEGATIVE_INFINITY,NaN));
	AddTestCase('mnmx172:p9 r:HALF_UP (0 + decimal.min(-1000,NaN)) invalid_operation', NaN, 0 + decimal.min(-1000,NaN));
	AddTestCase('mnmx173:p9 r:HALF_UP (0 + decimal.min(-1,NaN)) invalid_operation', NaN, 0 + decimal.min(-1,NaN));
	AddTestCase('mnmx174:p9 r:HALF_UP (0 + decimal.min(-0,NaN)) invalid_operation', NaN, 0 + decimal.min(-0,NaN));
	AddTestCase('mnmx175:p9 r:HALF_UP (0 + decimal.min(0,NaN)) invalid_operation', NaN, 0 + decimal.min(0,NaN));
	AddTestCase('mnmx176:p9 r:HALF_UP (0 + decimal.min(1,NaN)) invalid_operation', NaN, 0 + decimal.min(1,NaN));
	AddTestCase('mnmx177:p9 r:HALF_UP (0 + decimal.min(1000,NaN)) invalid_operation', NaN, 0 + decimal.min(1000,NaN));
	AddTestCase('mnmx178:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,NaN)) invalid_operation', NaN, 0 + decimal.min(decimal.POSITIVE_INFINITY,NaN));
	AddTestCase('mnmx179:p9 r:HALF_UP (0 + decimal.min(NaN,NaN)) invalid_operation', NaN, 0 + decimal.min(NaN,NaN));
	// propagating nans
	AddTestCase('mnmx181:p9 r:HALF_UP (0 + decimal.min(NaN,decimal.NEGATIVE_INFINITY))', NaN, 0 + decimal.min(NaN,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx182:p9 r:HALF_UP (0 + decimal.min(-NaN,9990))', NaN, 0 + decimal.min(-NaN,9990));
	AddTestCase('mnmx183:p9 r:HALF_UP (0 + decimal.min(NaN,decimal.POSITIVE_INFINITY))', NaN, 0 + decimal.min(NaN,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx184:p9 r:HALF_UP (0 + decimal.min(NaN,NaN))', NaN, 0 + decimal.min(NaN,NaN));
	AddTestCase('mnmx185:p9 r:HALF_UP (0 + decimal.min(NaN,-NaN))', NaN, 0 + decimal.min(NaN,-NaN));
	AddTestCase('mnmx186:p9 r:HALF_UP (0 + decimal.min(-NaN,NaN))', -NaN, 0 + decimal.min(-NaN,NaN));
	AddTestCase('mnmx187:p9 r:HALF_UP (0 + decimal.min(-NaN,NaN))', -NaN, 0 + decimal.min(-NaN,NaN));
	AddTestCase('mnmx188:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,NaN))', NaN, 0 + decimal.min(decimal.NEGATIVE_INFINITY,NaN));
	AddTestCase('mnmx189:p9 r:HALF_UP (0 + decimal.min(-9999,-NaN))', NaN, 0 + decimal.min(-9999,-NaN));
	AddTestCase('mnmx190:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,NaN))',NaN, 0 + decimal.min(decimal.POSITIVE_INFINITY,NaN));
	AddTestCase('mnmx191:p9 r:HALF_UP (0 + decimal.min(NaN,decimal.NEGATIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.min(NaN,decimal.NEGATIVE_INFINITY));
	AddTestCase('mnmx192:p9 r:HALF_UP (0 + decimal.min(NaN,-11)) invalid_operation', NaN, 0 + decimal.min(NaN,-11));
	AddTestCase('mnmx193:p9 r:HALF_UP (0 + decimal.min(-NaN,NaN)) invalid_operation', -NaN, 0 + decimal.min(-NaN,NaN));
	AddTestCase('mnmx194:p9 r:HALF_UP (0 + decimal.min(NaN,NaN)) invalid_operation', NaN, 0 + decimal.min(NaN,NaN));
	AddTestCase('mnmx195:p9 r:HALF_UP (0 + decimal.min(NaN,NaN)) invalid_operation', NaN, 0 + decimal.min(NaN,NaN));
	AddTestCase('mnmx196:p9 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,NaN)) invalid_operation', NaN, 0 + decimal.min(decimal.NEGATIVE_INFINITY,NaN));
	AddTestCase('mnmx197:p9 r:HALF_UP (0 + decimal.min(088,NaN)) invalid_operation', NaN, 0 + decimal.min(088,NaN));
	AddTestCase('mnmx198:p9 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,-NaN)) invalid_operation', -NaN, 0 + decimal.min(decimal.POSITIVE_INFINITY,-NaN));
	AddTestCase('mnmx199:p9 r:HALF_UP (0 + decimal.min(NaN,NaN)) invalid_operation', NaN, 0 + decimal.min(NaN,NaN));
	// rounding checks -- chosen is rounded, or not
}
{
	use precision 9;
	AddTestCase('mnmx201:p9 r:HALF_UP (0 + decimal.min(-12345678000,1)) rounded', -1.23456780e+10, 0 + decimal.min(-12345678000,1));
	AddTestCase('mnmx202:p9 r:HALF_UP (0 + decimal.min(1,-12345678000)) rounded', -1.23456780e+10, 0 + decimal.min(1,-12345678000));
	AddTestCase('mnmx203:p9 r:HALF_UP (0 + decimal.min(-1234567800,1)) rounded', -1.23456780e+9, 0 + decimal.min(-1234567800,1));
	AddTestCase('mnmx204:p9 r:HALF_UP (0 + decimal.min(1,-1234567800)) rounded', -1.23456780e+9, 0 + decimal.min(1,-1234567800));
	AddTestCase('mnmx205:p9 r:HALF_UP (0 + decimal.min(-1234567890,1)) rounded', -1.23456789e+9, 0 + decimal.min(-1234567890,1));
	AddTestCase('mnmx206:p9 r:HALF_UP (0 + decimal.min(1,-1234567890)) rounded', -1.23456789e+9, 0 + decimal.min(1,-1234567890));
	AddTestCase('mnmx207:p9 r:HALF_UP (0 + decimal.min(-1234567891,1)) inexact rounded', -1.23456789e+9, 0 + decimal.min(-1234567891,1));
	AddTestCase('mnmx208:p9 r:HALF_UP (0 + decimal.min(1,-1234567891)) inexact rounded', -1.23456789e+9, 0 + decimal.min(1,-1234567891));
	AddTestCase('mnmx209:p9 r:HALF_UP (0 + decimal.min(-12345678901,1)) inexact rounded', -1.23456789e+10, 0 + decimal.min(-12345678901,1));
	AddTestCase('mnmx210:p9 r:HALF_UP (0 + decimal.min(1,-12345678901)) inexact rounded', -1.23456789e+10, 0 + decimal.min(1,-12345678901));
	AddTestCase('mnmx211:p9 r:HALF_UP (0 + decimal.min(-1234567896,1)) inexact rounded', -1.23456790e+9, 0 + decimal.min(-1234567896,1));
	AddTestCase('mnmx212:p9 r:HALF_UP (0 + decimal.min(1,-1234567896)) inexact rounded', -1.23456790e+9, 0 + decimal.min(1,-1234567896));
	AddTestCase('mnmx213:p9 r:HALF_UP (0 + decimal.min(1234567891,1))', 1, 0 + decimal.min(1234567891,1));
	AddTestCase('mnmx214:p9 r:HALF_UP (0 + decimal.min(1,1234567891))', 1, 0 + decimal.min(1,1234567891));
	AddTestCase('mnmx215:p9 r:HALF_UP (0 + decimal.min(12345678901,1))', 1, 0 + decimal.min(12345678901,1));
	AddTestCase('mnmx216:p9 r:HALF_UP (0 + decimal.min(1,12345678901))', 1, 0 + decimal.min(1,12345678901));
	AddTestCase('mnmx217:p9 r:HALF_UP (0 + decimal.min(1234567896,1))', 1, 0 + decimal.min(1234567896,1));
	AddTestCase('mnmx218:p9 r:HALF_UP (0 + decimal.min(1,1234567896))', 1, 0 + decimal.min(1,1234567896));
}
{
	use precision 15;
	AddTestCase('mnmx221:p15 r:HALF_UP (0 + decimal.min(-12345678000,1))', -12345678000, 0 + decimal.min(-12345678000,1));
	AddTestCase('mnmx222:p15 r:HALF_UP (0 + decimal.min(1,-12345678000))', -12345678000, 0 + decimal.min(1,-12345678000));
	AddTestCase('mnmx223:p15 r:HALF_UP (0 + decimal.min(-1234567800,1))', -1234567800, 0 + decimal.min(-1234567800,1));
	AddTestCase('mnmx224:p15 r:HALF_UP (0 + decimal.min(1,-1234567800))', -1234567800, 0 + decimal.min(1,-1234567800));
	AddTestCase('mnmx225:p15 r:HALF_UP (0 + decimal.min(-1234567890,1))', -1234567890, 0 + decimal.min(-1234567890,1));
	AddTestCase('mnmx226:p15 r:HALF_UP (0 + decimal.min(1,-1234567890))', -1234567890, 0 + decimal.min(1,-1234567890));
	AddTestCase('mnmx227:p15 r:HALF_UP (0 + decimal.min(-1234567891,1))', -1234567891, 0 + decimal.min(-1234567891,1));
	AddTestCase('mnmx228:p15 r:HALF_UP (0 + decimal.min(1,-1234567891))', -1234567891, 0 + decimal.min(1,-1234567891));
	AddTestCase('mnmx229:p15 r:HALF_UP (0 + decimal.min(-12345678901,1))', -12345678901, 0 + decimal.min(-12345678901,1));
	AddTestCase('mnmx230:p15 r:HALF_UP (0 + decimal.min(1,-12345678901))', -12345678901, 0 + decimal.min(1,-12345678901));
	AddTestCase('mnmx231:p15 r:HALF_UP (0 + decimal.min(-1234567896,1))', -1234567896, 0 + decimal.min(-1234567896,1));
	AddTestCase('mnmx232:p15 r:HALF_UP (0 + decimal.min(1,-1234567896))', -1234567896, 0 + decimal.min(1,-1234567896));
	AddTestCase('mnmx233:p15 r:HALF_UP (0 + decimal.min(1234567891,1))', 1, 0 + decimal.min(1234567891,1));
	AddTestCase('mnmx234:p15 r:HALF_UP (0 + decimal.min(1,1234567891))', 1, 0 + decimal.min(1,1234567891));
	AddTestCase('mnmx235:p15 r:HALF_UP (0 + decimal.min(12345678901,1))', 1, 0 + decimal.min(12345678901,1));
	AddTestCase('mnmx236:p15 r:HALF_UP (0 + decimal.min(1,12345678901))', 1, 0 + decimal.min(1,12345678901));
	AddTestCase('mnmx237:p15 r:HALF_UP (0 + decimal.min(1234567896,1))', 1, 0 + decimal.min(1234567896,1));
	AddTestCase('mnmx238:p15 r:HALF_UP (0 + decimal.min(1,1234567896))', 1, 0 + decimal.min(1,1234567896));
	// from examples
	AddTestCase('mnmx280:p15 r:HALF_UP (0 + decimal.min(3,2))', 2, 0 + decimal.min(3,2));
	AddTestCase('mnmx281:p15 r:HALF_UP (0 + decimal.min(-10,3))', -10, 0 + decimal.min(-10,3));
	AddTestCase('mnmx282:p15 r:HALF_UP (0 + decimal.min(1.0,1))', 1.0, 0 + decimal.min(1.0,1));
	AddTestCase('mnmx283:p15 r:HALF_UP (0 + decimal.min(1,1.0))', 1.0, 0 + decimal.min(1,1.0));
	AddTestCase('mnmx284:p15 r:HALF_UP (0 + decimal.min(7,NaN))', NaN, 0 + decimal.min(7,NaN));
	// overflow and underflow tests .. subnormal results [inputs] now allowed
	AddTestCase('mnmx330:p15 r:HALF_UP (0 + decimal.min(-1.23456789012345e-0,-9e+999999999))', -9e+999999999, 0 + decimal.min(-1.23456789012345e-0,-9e+999999999));
	AddTestCase('mnmx331:p15 r:HALF_UP (0 + decimal.min(-9e+999999999,-1.23456789012345e-0))', -9e+999999999, 0 + decimal.min(-9e+999999999,-1.23456789012345e-0));
	AddTestCase('mnmx332:p15 r:HALF_UP (0 + decimal.min(-0.100,-9e-999999999))', -0.100, 0 + decimal.min(-0.100,-9e-999999999));
	AddTestCase('mnmx333:p15 r:HALF_UP (0 + decimal.min(-9e-999999999,-0.100))', -0.100, 0 + decimal.min(-9e-999999999,-0.100));
	AddTestCase('mnmx335:p15 r:HALF_UP (0 + decimal.min(+1.23456789012345e-0,-9e+999999999))', -9e+999999999, 0 + decimal.min(+1.23456789012345e-0,-9e+999999999));
	AddTestCase('mnmx336:p15 r:HALF_UP (0 + decimal.min(-9e+999999999,1.23456789012345e-0))', -9e+999999999, 0 + decimal.min(-9e+999999999,1.23456789012345e-0));
	AddTestCase('mnmx337:p15 r:HALF_UP (0 + decimal.min(+0.100,-9e-999999999))', -9e-999999999, 0 + decimal.min(+0.100,-9e-999999999));
	AddTestCase('mnmx338:p15 r:HALF_UP (0 + decimal.min(-9e-999999999,0.100))', -9e-999999999, 0 + decimal.min(-9e-999999999,0.100));
	AddTestCase('mnmx339:p15 r:HALF_UP (0 + decimal.min(-1e-599999999,-1e-400000001))', -1e-400000001, 0 + decimal.min(-1e-599999999,-1e-400000001));
	AddTestCase('mnmx340:p15 r:HALF_UP (0 + decimal.min(-1e-599999999,-1e-400000000))', -1e-400000000, 0 + decimal.min(-1e-599999999,-1e-400000000));
	AddTestCase('mnmx341:p15 r:HALF_UP (0 + decimal.min(-1e-600000000,-1e-400000000))', -1e-400000000, 0 + decimal.min(-1e-600000000,-1e-400000000));
	AddTestCase('mnmx342:p15 r:HALF_UP (0 + decimal.min(-9e-999999998,-0.01))', -0.01, 0 + decimal.min(-9e-999999998,-0.01));
	AddTestCase('mnmx343:p15 r:HALF_UP (0 + decimal.min(-9e-999999998,-0.1))', -0.1, 0 + decimal.min(-9e-999999998,-0.1));
	AddTestCase('mnmx344:p15 r:HALF_UP (0 + decimal.min(-0.01,-9e-999999998))', -0.01, 0 + decimal.min(-0.01,-9e-999999998));
	AddTestCase('mnmx345:p15 r:HALF_UP (0 + decimal.min(-1e599999999,-1e400000001))', -1e+599999999, 0 + decimal.min(-1e599999999,-1e400000001));
	AddTestCase('mnmx346:p15 r:HALF_UP (0 + decimal.min(-1e599999999,-1e400000000))', -1e+599999999, 0 + decimal.min(-1e599999999,-1e400000000));
	AddTestCase('mnmx347:p15 r:HALF_UP (0 + decimal.min(-1e600000000,-1e400000000))', -1e+600000000, 0 + decimal.min(-1e600000000,-1e400000000));
	AddTestCase('mnmx348:p15 r:HALF_UP (0 + decimal.min(-9e999999998,-100))', -9e+999999998, 0 + decimal.min(-9e999999998,-100));
	AddTestCase('mnmx349:p15 r:HALF_UP (0 + decimal.min(-9e999999998,-10))', -9e+999999998, 0 + decimal.min(-9e999999998,-10));
	AddTestCase('mnmx350:p15 r:HALF_UP (0 + decimal.min(-100,-9e999999998))', -9e+999999998, 0 + decimal.min(-100,-9e999999998));
	// signs
	AddTestCase('mnmx351:p15 r:HALF_UP (0 + decimal.min(-1e+777777777,-1e+411111111))', -1e+777777777, 0 + decimal.min(-1e+777777777,-1e+411111111));
	AddTestCase('mnmx352:p15 r:HALF_UP (0 + decimal.min(-1e+777777777,+1e+411111111))', -1e+777777777, 0 + decimal.min(-1e+777777777,+1e+411111111));
	AddTestCase('mnmx353:p15 r:HALF_UP (0 + decimal.min(+1e+777777777,-1e+411111111))', -1e+411111111, 0 + decimal.min(+1e+777777777,-1e+411111111));
	AddTestCase('mnmx354:p15 r:HALF_UP (0 + decimal.min(+1e+777777777,+1e+411111111))', 1e+411111111, 0 + decimal.min(+1e+777777777,+1e+411111111));
	AddTestCase('mnmx355:p15 r:HALF_UP (0 + decimal.min(-1e-777777777,-1e-411111111))', -1e-411111111, 0 + decimal.min(-1e-777777777,-1e-411111111));
	AddTestCase('mnmx356:p15 r:HALF_UP (0 + decimal.min(-1e-777777777,+1e-411111111))', -1e-777777777, 0 + decimal.min(-1e-777777777,+1e-411111111));
	AddTestCase('mnmx357:p15 r:HALF_UP (0 + decimal.min(+1e-777777777,-1e-411111111))', -1e-411111111, 0 + decimal.min(+1e-777777777,-1e-411111111));
	AddTestCase('mnmx358:p15 r:HALF_UP (0 + decimal.min(+1e-777777777,+1e-411111111))', 1e-777777777, 0 + decimal.min(+1e-777777777,+1e-411111111));
	// expanded list from min/max 754r purple prose
	// [explicit tests for exponent ordering]
	AddTestCase('mnmx401:p15 r:HALF_UP (0 + decimal.min(decimal.POSITIVE_INFINITY,1.1))', 1.1, 0 + decimal.min(decimal.POSITIVE_INFINITY,1.1));
	AddTestCase('mnmx402:p15 r:HALF_UP (0 + decimal.min(1.1,1))', 1, 0 + decimal.min(1.1,1));
	AddTestCase('mnmx403:p15 r:HALF_UP (0 + decimal.min(1,1.0))', 1.0, 0 + decimal.min(1,1.0));
	AddTestCase('mnmx404:p15 r:HALF_UP (0 + decimal.min(1.0,0.1))', 0.1, 0 + decimal.min(1.0,0.1));
	AddTestCase('mnmx405:p15 r:HALF_UP (0 + decimal.min(0.1,0.10))', 0.10, 0 + decimal.min(0.1,0.10));
	AddTestCase('mnmx406:p15 r:HALF_UP (0 + decimal.min(0.10,0.100))', 0.100, 0 + decimal.min(0.10,0.100));
	AddTestCase('mnmx407:p15 r:HALF_UP (0 + decimal.min(0.10,0))', 0, 0 + decimal.min(0.10,0));
	AddTestCase('mnmx408:p15 r:HALF_UP (0 + decimal.min(0,0.0))', 0.0, 0 + decimal.min(0,0.0));
	AddTestCase('mnmx409:p15 r:HALF_UP (0 + decimal.min(0.0,-0))', -0, 0 + decimal.min(0.0,-0));
	AddTestCase('mnmx410:p15 r:HALF_UP (0 + decimal.min(0.0,-0.0))', -0.0, 0 + decimal.min(0.0,-0.0));
	AddTestCase('mnmx411:p15 r:HALF_UP (0 + decimal.min(0.00,-0.0))', -0.0, 0 + decimal.min(0.00,-0.0));
	AddTestCase('mnmx412:p15 r:HALF_UP (0 + decimal.min(0.0,-0.00))', -0.00, 0 + decimal.min(0.0,-0.00));
	AddTestCase('mnmx413:p15 r:HALF_UP (0 + decimal.min(0,-0.0))', -0.0, 0 + decimal.min(0,-0.0));
	AddTestCase('mnmx414:p15 r:HALF_UP (0 + decimal.min(0,-0))', -0, 0 + decimal.min(0,-0));
	AddTestCase('mnmx415:p15 r:HALF_UP (0 + decimal.min(-0.0,-0))', -0, 0 + decimal.min(-0.0,-0));
	AddTestCase('mnmx416:p15 r:HALF_UP (0 + decimal.min(-0,-0.100))', -0.100, 0 + decimal.min(-0,-0.100));
	AddTestCase('mnmx417:p15 r:HALF_UP (0 + decimal.min(-0.100,-0.10))', -0.10, 0 + decimal.min(-0.100,-0.10));
	AddTestCase('mnmx418:p15 r:HALF_UP (0 + decimal.min(-0.10,-0.1))', -0.1, 0 + decimal.min(-0.10,-0.1));
	AddTestCase('mnmx419:p15 r:HALF_UP (0 + decimal.min(-0.1,-1.0))', -1.0, 0 + decimal.min(-0.1,-1.0));
	AddTestCase('mnmx420:p15 r:HALF_UP (0 + decimal.min(-1.0,-1))', -1, 0 + decimal.min(-1.0,-1));
	AddTestCase('mnmx421:p15 r:HALF_UP (0 + decimal.min(-1,-1.1))', -1.1, 0 + decimal.min(-1,-1.1));
	AddTestCase('mnmx423:p15 r:HALF_UP (0 + decimal.min(-1.1,decimal.NEGATIVE_INFINITY))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(-1.1,decimal.NEGATIVE_INFINITY));
	// same with operands reversed
	AddTestCase('mnmx431:p15 r:HALF_UP (0 + decimal.min(1.1,decimal.POSITIVE_INFINITY))', 1.1, 0 + decimal.min(1.1,decimal.POSITIVE_INFINITY));
	AddTestCase('mnmx432:p15 r:HALF_UP (0 + decimal.min(1,1.1))', 1, 0 + decimal.min(1,1.1));
	AddTestCase('mnmx433:p15 r:HALF_UP (0 + decimal.min(1.0,1))', 1.0, 0 + decimal.min(1.0,1));
	AddTestCase('mnmx434:p15 r:HALF_UP (0 + decimal.min(0.1,1.0))', 0.1, 0 + decimal.min(0.1,1.0));
	AddTestCase('mnmx435:p15 r:HALF_UP (0 + decimal.min(0.10,0.1))', 0.10, 0 + decimal.min(0.10,0.1));
	AddTestCase('mnmx436:p15 r:HALF_UP (0 + decimal.min(0.100,0.10))', 0.100, 0 + decimal.min(0.100,0.10));
	AddTestCase('mnmx437:p15 r:HALF_UP (0 + decimal.min(0,0.10))', 0, 0 + decimal.min(0,0.10));
	AddTestCase('mnmx438:p15 r:HALF_UP (0 + decimal.min(0.0,0))', 0.0, 0 + decimal.min(0.0,0));
	AddTestCase('mnmx439:p15 r:HALF_UP (0 + decimal.min(-0,0.0))', -0, 0 + decimal.min(-0,0.0));
	AddTestCase('mnmx440:p15 r:HALF_UP (0 + decimal.min(-0.0,0.0))', -0.0, 0 + decimal.min(-0.0,0.0));
	AddTestCase('mnmx441:p15 r:HALF_UP (0 + decimal.min(-0.0,0.00))', -0.0, 0 + decimal.min(-0.0,0.00));
	AddTestCase('mnmx442:p15 r:HALF_UP (0 + decimal.min(-0.00,0.0))', -0.00, 0 + decimal.min(-0.00,0.0));
	AddTestCase('mnmx443:p15 r:HALF_UP (0 + decimal.min(-0.0,0))', -0.0, 0 + decimal.min(-0.0,0));
	AddTestCase('mnmx444:p15 r:HALF_UP (0 + decimal.min(-0,0))', -0, 0 + decimal.min(-0,0));
	AddTestCase('mnmx445:p15 r:HALF_UP (0 + decimal.min(-0,-0.0))', -0, 0 + decimal.min(-0,-0.0));
	AddTestCase('mnmx446:p15 r:HALF_UP (0 + decimal.min(-0.100,-0))', -0.100, 0 + decimal.min(-0.100,-0));
	AddTestCase('mnmx447:p15 r:HALF_UP (0 + decimal.min(-0.10,-0.100))', -0.10, 0 + decimal.min(-0.10,-0.100));
	AddTestCase('mnmx448:p15 r:HALF_UP (0 + decimal.min(-0.1,-0.10))', -0.1, 0 + decimal.min(-0.1,-0.10));
	AddTestCase('mnmx449:p15 r:HALF_UP (0 + decimal.min(-1.0,-0.1))', -1.0, 0 + decimal.min(-1.0,-0.1));
	AddTestCase('mnmx450:p15 r:HALF_UP (0 + decimal.min(-1,-1.0))', -1, 0 + decimal.min(-1,-1.0));
	AddTestCase('mnmx451:p15 r:HALF_UP (0 + decimal.min(-1.1,-1))', -1.1, 0 + decimal.min(-1.1,-1));
	AddTestCase('mnmx453:p15 r:HALF_UP (0 + decimal.min(decimal.NEGATIVE_INFINITY,-1.1))', decimal.NEGATIVE_INFINITY, 0 + decimal.min(decimal.NEGATIVE_INFINITY,-1.1));
	// largies
	AddTestCase('mnmx460:p15 r:HALF_UP (0 + decimal.min(1000,1e+3))', 1000, 0 + decimal.min(1000,1e+3));
	AddTestCase('mnmx461:p15 r:HALF_UP (0 + decimal.min(1e+3,1000))', 1000, 0 + decimal.min(1e+3,1000));
	AddTestCase('mnmx462:p15 r:HALF_UP (0 + decimal.min(1000,-1e+3))', -1e+3, 0 + decimal.min(1000,-1e+3));
	AddTestCase('mnmx463:p15 r:HALF_UP (0 + decimal.min(1e+3,-1000))', -1000, 0 + decimal.min(1e+3,-1000));
	AddTestCase('mnmx464:p15 r:HALF_UP (0 + decimal.min(-1000,1e+3))', -1000, 0 + decimal.min(-1000,1e+3));
	AddTestCase('mnmx465:p15 r:HALF_UP (0 + decimal.min(-1e+3,1000))', -1e+3, 0 + decimal.min(-1e+3,1000));
	AddTestCase('mnmx466:p15 r:HALF_UP (0 + decimal.min(-1000,-1e+3))', -1e+3, 0 + decimal.min(-1000,-1e+3));
	AddTestCase('mnmx467:p15 r:HALF_UP (0 + decimal.min(-1e+3,-1000))', -1e+3, 0 + decimal.min(-1e+3,-1000));
	// rounding (results treated as though plus)
}
{
	use precision 3;
	AddTestCase('mnmx470:p3 r:HALF_UP (0 + decimal.min(1,5))', 1, 0 + decimal.min(1,5));
	AddTestCase('mnmx471:p3 r:HALF_UP (0 + decimal.min(10,50))', 10, 0 + decimal.min(10,50));
	AddTestCase('mnmx472:p3 r:HALF_UP (0 + decimal.min(100,500))', 100, 0 + decimal.min(100,500));
	AddTestCase('mnmx473:p3 r:HALF_UP (0 + decimal.min(1000,5000)) rounded', 1.00e+3, 0 + decimal.min(1000,5000));
	AddTestCase('mnmx474:p3 r:HALF_UP (0 + decimal.min(10000,50000)) rounded', 1.00e+4, 0 + decimal.min(10000,50000));
	AddTestCase('mnmx475:p3 r:HALF_UP (0 + decimal.min(6,50))', 6, 0 + decimal.min(6,50));
	AddTestCase('mnmx476:p3 r:HALF_UP (0 + decimal.min(66,500))', 66, 0 + decimal.min(66,500));
	AddTestCase('mnmx477:p3 r:HALF_UP (0 + decimal.min(666,5000))', 666, 0 + decimal.min(666,5000));
	AddTestCase('mnmx478:p3 r:HALF_UP (0 + decimal.min(6666,50000)) rounded inexact', 6.67e+3, 0 + decimal.min(6666,50000));
	AddTestCase('mnmx479:p3 r:HALF_UP (0 + decimal.min(66666,500000)) rounded inexact', 6.67e+4, 0 + decimal.min(66666,500000));
	AddTestCase('mnmx480:p3 r:HALF_UP (0 + decimal.min(33333,500000)) rounded inexact', 3.33e+4, 0 + decimal.min(33333,500000));
	AddTestCase('mnmx481:p3 r:HALF_UP (0 + decimal.min(75401,1))', 1, 0 + decimal.min(75401,1));
	AddTestCase('mnmx482:p3 r:HALF_UP (0 + decimal.min(75402,10))', 10, 0 + decimal.min(75402,10));
	AddTestCase('mnmx483:p3 r:HALF_UP (0 + decimal.min(75403,100))', 100, 0 + decimal.min(75403,100));
	AddTestCase('mnmx484:p3 r:HALF_UP (0 + decimal.min(75404,1000)) rounded', 1.00e+3, 0 + decimal.min(75404,1000));
	AddTestCase('mnmx485:p3 r:HALF_UP (0 + decimal.min(75405,10000)) rounded', 1.00e+4, 0 + decimal.min(75405,10000));
	AddTestCase('mnmx486:p3 r:HALF_UP (0 + decimal.min(75406,6))', 6, 0 + decimal.min(75406,6));
	AddTestCase('mnmx487:p3 r:HALF_UP (0 + decimal.min(75407,66))', 66, 0 + decimal.min(75407,66));
	AddTestCase('mnmx488:p3 r:HALF_UP (0 + decimal.min(75408,666))', 666, 0 + decimal.min(75408,666));
	AddTestCase('mnmx489:p3 r:HALF_UP (0 + decimal.min(75409,6666)) rounded inexact', 6.67e+3, 0 + decimal.min(75409,6666));
	AddTestCase('mnmx490:p3 r:HALF_UP (0 + decimal.min(75410,66666)) rounded inexact', 6.67e+4, 0 + decimal.min(75410,66666));
	AddTestCase('mnmx491:p3 r:HALF_UP (0 + decimal.min(75411,33333)) rounded inexact', 3.33e+4, 0 + decimal.min(75411,33333));
	// overflow tests
}
{
	use precision 3;
	AddTestCase('mnmx500:p3 r:HALF_UP (0 + decimal.min(9.999e+999999999,0))', 0, 0 + decimal.min(9.999e+999999999,0));
	// subnormals and underflow
}
{
	use precision 3;
	AddTestCase('mnmx510:p3 r:HALF_UP (0 + decimal.min(1.00e-999,0))', 0, 0 + decimal.min(1.00e-999,0));
	AddTestCase('mnmx511:p3 r:HALF_UP (0 + decimal.min(0.1e-999,0))', 0, 0 + decimal.min(0.1e-999,0));
	AddTestCase('mnmx512:p3 r:HALF_UP (0 + decimal.min(0.10e-999,0))', 0, 0 + decimal.min(0.10e-999,0));
	AddTestCase('mnmx513:p3 r:HALF_UP (0 + decimal.min(0.100e-999,0))', 0, 0 + decimal.min(0.100e-999,0));
	AddTestCase('mnmx514:p3 r:HALF_UP (0 + decimal.min(0.01e-999,0))', 0, 0 + decimal.min(0.01e-999,0));
	AddTestCase('mnmx515:p3 r:HALF_UP (0 + decimal.min(0.999e-999,0))', 0, 0 + decimal.min(0.999e-999,0));
	AddTestCase('mnmx516:p3 r:HALF_UP (0 + decimal.min(0.099e-999,0))', 0, 0 + decimal.min(0.099e-999,0));
	AddTestCase('mnmx517:p3 r:HALF_UP (0 + decimal.min(0.009e-999,0))', 0, 0 + decimal.min(0.009e-999,0));
	AddTestCase('mnmx518:p3 r:HALF_UP (0 + decimal.min(0.001e-999,0))', 0, 0 + decimal.min(0.001e-999,0));
	AddTestCase('mnmx519:p3 r:HALF_UP (0 + decimal.min(0.0009e-999,0))', 0, 0 + decimal.min(0.0009e-999,0));
	AddTestCase('mnmx520:p3 r:HALF_UP (0 + decimal.min(0.0001e-999,0))', 0, 0 + decimal.min(0.0001e-999,0));
	AddTestCase('mnmx530:p3 r:HALF_UP (0 + decimal.min(-1.00e-999,0))', -1.00e-999, 0 + decimal.min(-1.00e-999,0));
	// next is rounded to nmin
	// misalignment traps for little-endian
}
{
	use precision 9;
	AddTestCase('mnmx551:p9 r:HALF_UP (0 + decimal.min(1.0,0.1))', 0.1, 0 + decimal.min(1.0,0.1));
	AddTestCase('mnmx552:p9 r:HALF_UP (0 + decimal.min(0.1,1.0))', 0.1, 0 + decimal.min(0.1,1.0));
	AddTestCase('mnmx553:p9 r:HALF_UP (0 + decimal.min(10.0,0.1))', 0.1, 0 + decimal.min(10.0,0.1));
	AddTestCase('mnmx554:p9 r:HALF_UP (0 + decimal.min(0.1,10.0))', 0.1, 0 + decimal.min(0.1,10.0));
	AddTestCase('mnmx555:p9 r:HALF_UP (0 + decimal.min(100,1.0))', 1.0, 0 + decimal.min(100,1.0));
	AddTestCase('mnmx556:p9 r:HALF_UP (0 + decimal.min(1.0,100))', 1.0, 0 + decimal.min(1.0,100));
	AddTestCase('mnmx557:p9 r:HALF_UP (0 + decimal.min(1000,10.0))', 10.0, 0 + decimal.min(1000,10.0));
	AddTestCase('mnmx558:p9 r:HALF_UP (0 + decimal.min(10.0,1000))', 10.0, 0 + decimal.min(10.0,1000));
	AddTestCase('mnmx559:p9 r:HALF_UP (0 + decimal.min(10000,100.0))', 100.0, 0 + decimal.min(10000,100.0));
	AddTestCase('mnmx560:p9 r:HALF_UP (0 + decimal.min(100.0,10000))', 100.0, 0 + decimal.min(100.0,10000));
	AddTestCase('mnmx561:p9 r:HALF_UP (0 + decimal.min(100000,1000.0))', 1000.0, 0 + decimal.min(100000,1000.0));
	AddTestCase('mnmx562:p9 r:HALF_UP (0 + decimal.min(1000.0,100000))', 1000.0, 0 + decimal.min(1000.0,100000));
	AddTestCase('mnmx563:p9 r:HALF_UP (0 + decimal.min(1000000,10000.0))', 10000.0, 0 + decimal.min(1000000,10000.0));
	AddTestCase('mnmx564:p9 r:HALF_UP (0 + decimal.min(10000.0,1000000))', 10000.0, 0 + decimal.min(10000.0,1000000));
	// null tests
	AddTestCase('mnm900:p9 r:HALF_UP (0 + decimal.min(10,null)) invalid_operation', 0, 0 + decimal.min(10,null));
	AddTestCase('mnm901:p9 r:HALF_UP (0 + decimal.min(null,10)) invalid_operation', 0, 0 + decimal.min(null,10));
	}
}
test();
