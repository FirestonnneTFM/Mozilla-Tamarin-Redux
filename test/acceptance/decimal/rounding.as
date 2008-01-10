use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "rounding.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// rounding.dectest -- decimal rounding modes testcases               --
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
// these tests require that implementations take account of residues in
// order to get correct results for some rounding modes.  rather than
// single rounding tests we therefore need tests for most operators.
// [we do assume add/minus/plus/subtract are common paths, however, as
// is rounding of negatives (if the latter works for addition, assume it
// works for the others, too).]
//
// round-for-reround (05up) is tested as a separate block, mostly for
// 'historical' reasons.
//
// underflow subnormal and overflow behaviours are tested under the
// individual operators.
use precision 5;
// addition operators -------------------------------------------------
use rounding HALF_DOWN;
AddTestCase('radx140:p5 r:HALF_DOWN (12345 + -0.1) inexact rounded', 12345, 12345 + -0.1);
AddTestCase('radx141:p5 r:HALF_DOWN (12345 + -0.01) inexact rounded', 12345, 12345 + -0.01);
AddTestCase('radx142:p5 r:HALF_DOWN (12345 + -0.001) inexact rounded', 12345, 12345 + -0.001);
AddTestCase('radx143:p5 r:HALF_DOWN (12345 + -0.00001) inexact rounded', 12345, 12345 + -0.00001);
AddTestCase('radx144:p5 r:HALF_DOWN (12345 + -0.000001) inexact rounded', 12345, 12345 + -0.000001);
AddTestCase('radx145:p5 r:HALF_DOWN (12345 + -0.0000001) inexact rounded', 12345, 12345 + -0.0000001);
AddTestCase('radx146:p5 r:HALF_DOWN (12345 + 0)', 12345, 12345 + 0);
AddTestCase('radx147:p5 r:HALF_DOWN (12345 + 0.0000001) inexact rounded', 12345, 12345 + 0.0000001);
AddTestCase('radx148:p5 r:HALF_DOWN (12345 + 0.000001) inexact rounded', 12345, 12345 + 0.000001);
AddTestCase('radx149:p5 r:HALF_DOWN (12345 + 0.00001) inexact rounded', 12345, 12345 + 0.00001);
AddTestCase('radx150:p5 r:HALF_DOWN (12345 + 0.0001) inexact rounded', 12345, 12345 + 0.0001);
AddTestCase('radx151:p5 r:HALF_DOWN (12345 + 0.001) inexact rounded', 12345, 12345 + 0.001);
AddTestCase('radx152:p5 r:HALF_DOWN (12345 + 0.01) inexact rounded', 12345, 12345 + 0.01);
AddTestCase('radx153:p5 r:HALF_DOWN (12345 + 0.1) inexact rounded', 12345, 12345 + 0.1);
AddTestCase('radx155:p5 r:HALF_DOWN (12346 + 0.49999) inexact rounded', 12346, 12346 + 0.49999);
AddTestCase('radx156:p5 r:HALF_DOWN (12346 + 0.5) inexact rounded', 12346, 12346 + 0.5);
AddTestCase('radx157:p5 r:HALF_DOWN (12346 + 0.50001) inexact rounded', 12347, 12346 + 0.50001);
AddTestCase('radx160:p5 r:HALF_DOWN (12345 + 0.4) inexact rounded', 12345, 12345 + 0.4);
AddTestCase('radx161:p5 r:HALF_DOWN (12345 + 0.49) inexact rounded', 12345, 12345 + 0.49);
AddTestCase('radx162:p5 r:HALF_DOWN (12345 + 0.499) inexact rounded', 12345, 12345 + 0.499);
AddTestCase('radx163:p5 r:HALF_DOWN (12345 + 0.49999) inexact rounded', 12345, 12345 + 0.49999);
AddTestCase('radx164:p5 r:HALF_DOWN (12345 + 0.5) inexact rounded', 12345, 12345 + 0.5);
AddTestCase('radx165:p5 r:HALF_DOWN (12345 + 0.50001) inexact rounded', 12346, 12345 + 0.50001);
AddTestCase('radx166:p5 r:HALF_DOWN (12345 + 0.5001) inexact rounded', 12346, 12345 + 0.5001);
AddTestCase('radx167:p5 r:HALF_DOWN (12345 + 0.501) inexact rounded', 12346, 12345 + 0.501);
AddTestCase('radx168:p5 r:HALF_DOWN (12345 + 0.51) inexact rounded', 12346, 12345 + 0.51);
AddTestCase('radx169:p5 r:HALF_DOWN (12345 + 0.6) inexact rounded', 12346, 12345 + 0.6);
{
	use rounding HALF_EVEN;
	AddTestCase('radx170:p5 r:HALF_EVEN (12345 + -0.1) inexact rounded', 12345, 12345 + -0.1);
	AddTestCase('radx171:p5 r:HALF_EVEN (12345 + -0.01) inexact rounded', 12345, 12345 + -0.01);
	AddTestCase('radx172:p5 r:HALF_EVEN (12345 + -0.001) inexact rounded', 12345, 12345 + -0.001);
	AddTestCase('radx173:p5 r:HALF_EVEN (12345 + -0.00001) inexact rounded', 12345, 12345 + -0.00001);
	AddTestCase('radx174:p5 r:HALF_EVEN (12345 + -0.000001) inexact rounded', 12345, 12345 + -0.000001);
	AddTestCase('radx175:p5 r:HALF_EVEN (12345 + -0.0000001) inexact rounded', 12345, 12345 + -0.0000001);
	AddTestCase('radx176:p5 r:HALF_EVEN (12345 + 0)', 12345, 12345 + 0);
	AddTestCase('radx177:p5 r:HALF_EVEN (12345 + 0.0000001) inexact rounded', 12345, 12345 + 0.0000001);
	AddTestCase('radx178:p5 r:HALF_EVEN (12345 + 0.000001) inexact rounded', 12345, 12345 + 0.000001);
	AddTestCase('radx179:p5 r:HALF_EVEN (12345 + 0.00001) inexact rounded', 12345, 12345 + 0.00001);
	AddTestCase('radx180:p5 r:HALF_EVEN (12345 + 0.0001) inexact rounded', 12345, 12345 + 0.0001);
	AddTestCase('radx181:p5 r:HALF_EVEN (12345 + 0.001) inexact rounded', 12345, 12345 + 0.001);
	AddTestCase('radx182:p5 r:HALF_EVEN (12345 + 0.01) inexact rounded', 12345, 12345 + 0.01);
	AddTestCase('radx183:p5 r:HALF_EVEN (12345 + 0.1) inexact rounded', 12345, 12345 + 0.1);
	AddTestCase('radx185:p5 r:HALF_EVEN (12346 + 0.49999) inexact rounded', 12346, 12346 + 0.49999);
	AddTestCase('radx186:p5 r:HALF_EVEN (12346 + 0.5) inexact rounded', 12346, 12346 + 0.5);
	AddTestCase('radx187:p5 r:HALF_EVEN (12346 + 0.50001) inexact rounded', 12347, 12346 + 0.50001);
	AddTestCase('radx190:p5 r:HALF_EVEN (12345 + 0.4) inexact rounded', 12345, 12345 + 0.4);
	AddTestCase('radx191:p5 r:HALF_EVEN (12345 + 0.49) inexact rounded', 12345, 12345 + 0.49);
	AddTestCase('radx192:p5 r:HALF_EVEN (12345 + 0.499) inexact rounded', 12345, 12345 + 0.499);
	AddTestCase('radx193:p5 r:HALF_EVEN (12345 + 0.49999) inexact rounded', 12345, 12345 + 0.49999);
	AddTestCase('radx194:p5 r:HALF_EVEN (12345 + 0.5) inexact rounded', 12346, 12345 + 0.5);
	AddTestCase('radx195:p5 r:HALF_EVEN (12345 + 0.50001) inexact rounded', 12346, 12345 + 0.50001);
	AddTestCase('radx196:p5 r:HALF_EVEN (12345 + 0.5001) inexact rounded', 12346, 12345 + 0.5001);
	AddTestCase('radx197:p5 r:HALF_EVEN (12345 + 0.501) inexact rounded', 12346, 12345 + 0.501);
	AddTestCase('radx198:p5 r:HALF_EVEN (12345 + 0.51) inexact rounded', 12346, 12345 + 0.51);
	AddTestCase('radx199:p5 r:HALF_EVEN (12345 + 0.6) inexact rounded', 12346, 12345 + 0.6);
}
{
	use rounding HALF_UP;
	AddTestCase('radx200:p5 r:HALF_UP (12345 + -0.1) inexact rounded', 12345, 12345 + -0.1);
	AddTestCase('radx201:p5 r:HALF_UP (12345 + -0.01) inexact rounded', 12345, 12345 + -0.01);
	AddTestCase('radx202:p5 r:HALF_UP (12345 + -0.001) inexact rounded', 12345, 12345 + -0.001);
	AddTestCase('radx203:p5 r:HALF_UP (12345 + -0.00001) inexact rounded', 12345, 12345 + -0.00001);
	AddTestCase('radx204:p5 r:HALF_UP (12345 + -0.000001) inexact rounded', 12345, 12345 + -0.000001);
	AddTestCase('radx205:p5 r:HALF_UP (12345 + -0.0000001) inexact rounded', 12345, 12345 + -0.0000001);
	AddTestCase('radx206:p5 r:HALF_UP (12345 + 0)', 12345, 12345 + 0);
	AddTestCase('radx207:p5 r:HALF_UP (12345 + 0.0000001) inexact rounded', 12345, 12345 + 0.0000001);
	AddTestCase('radx208:p5 r:HALF_UP (12345 + 0.000001) inexact rounded', 12345, 12345 + 0.000001);
	AddTestCase('radx209:p5 r:HALF_UP (12345 + 0.00001) inexact rounded', 12345, 12345 + 0.00001);
	AddTestCase('radx210:p5 r:HALF_UP (12345 + 0.0001) inexact rounded', 12345, 12345 + 0.0001);
	AddTestCase('radx211:p5 r:HALF_UP (12345 + 0.001) inexact rounded', 12345, 12345 + 0.001);
	AddTestCase('radx212:p5 r:HALF_UP (12345 + 0.01) inexact rounded', 12345, 12345 + 0.01);
	AddTestCase('radx213:p5 r:HALF_UP (12345 + 0.1) inexact rounded', 12345, 12345 + 0.1);
	AddTestCase('radx215:p5 r:HALF_UP (12346 + 0.49999) inexact rounded', 12346, 12346 + 0.49999);
	AddTestCase('radx216:p5 r:HALF_UP (12346 + 0.5) inexact rounded', 12347, 12346 + 0.5);
	AddTestCase('radx217:p5 r:HALF_UP (12346 + 0.50001) inexact rounded', 12347, 12346 + 0.50001);
	AddTestCase('radx220:p5 r:HALF_UP (12345 + 0.4) inexact rounded', 12345, 12345 + 0.4);
	AddTestCase('radx221:p5 r:HALF_UP (12345 + 0.49) inexact rounded', 12345, 12345 + 0.49);
	AddTestCase('radx222:p5 r:HALF_UP (12345 + 0.499) inexact rounded', 12345, 12345 + 0.499);
	AddTestCase('radx223:p5 r:HALF_UP (12345 + 0.49999) inexact rounded', 12345, 12345 + 0.49999);
	AddTestCase('radx224:p5 r:HALF_UP (12345 + 0.5) inexact rounded', 12346, 12345 + 0.5);
	AddTestCase('radx225:p5 r:HALF_UP (12345 + 0.50001) inexact rounded', 12346, 12345 + 0.50001);
	AddTestCase('radx226:p5 r:HALF_UP (12345 + 0.5001) inexact rounded', 12346, 12345 + 0.5001);
	AddTestCase('radx227:p5 r:HALF_UP (12345 + 0.501) inexact rounded', 12346, 12345 + 0.501);
	AddTestCase('radx228:p5 r:HALF_UP (12345 + 0.51) inexact rounded', 12346, 12345 + 0.51);
	AddTestCase('radx229:p5 r:HALF_UP (12345 + 0.6) inexact rounded', 12346, 12345 + 0.6);
}
{
	use rounding FLOOR;
	AddTestCase('radx300:p5 r:FLOOR (12345 + -0.1) inexact rounded', 12344, 12345 + -0.1);
	AddTestCase('radx301:p5 r:FLOOR (12345 + -0.01) inexact rounded', 12344, 12345 + -0.01);
	AddTestCase('radx302:p5 r:FLOOR (12345 + -0.001) inexact rounded', 12344, 12345 + -0.001);
	AddTestCase('radx303:p5 r:FLOOR (12345 + -0.00001) inexact rounded', 12344, 12345 + -0.00001);
	AddTestCase('radx304:p5 r:FLOOR (12345 + -0.000001) inexact rounded', 12344, 12345 + -0.000001);
	AddTestCase('radx305:p5 r:FLOOR (12345 + -0.0000001) inexact rounded', 12344, 12345 + -0.0000001);
	AddTestCase('radx306:p5 r:FLOOR (12345 + 0)', 12345, 12345 + 0);
	AddTestCase('radx307:p5 r:FLOOR (12345 + 0.0000001) inexact rounded', 12345, 12345 + 0.0000001);
	AddTestCase('radx308:p5 r:FLOOR (12345 + 0.000001) inexact rounded', 12345, 12345 + 0.000001);
	AddTestCase('radx309:p5 r:FLOOR (12345 + 0.00001) inexact rounded', 12345, 12345 + 0.00001);
	AddTestCase('radx310:p5 r:FLOOR (12345 + 0.0001) inexact rounded', 12345, 12345 + 0.0001);
	AddTestCase('radx311:p5 r:FLOOR (12345 + 0.001) inexact rounded', 12345, 12345 + 0.001);
	AddTestCase('radx312:p5 r:FLOOR (12345 + 0.01) inexact rounded', 12345, 12345 + 0.01);
	AddTestCase('radx313:p5 r:FLOOR (12345 + 0.1) inexact rounded', 12345, 12345 + 0.1);
	AddTestCase('radx315:p5 r:FLOOR (12346 + 0.49999) inexact rounded', 12346, 12346 + 0.49999);
	AddTestCase('radx316:p5 r:FLOOR (12346 + 0.5) inexact rounded', 12346, 12346 + 0.5);
	AddTestCase('radx317:p5 r:FLOOR (12346 + 0.50001) inexact rounded', 12346, 12346 + 0.50001);
	AddTestCase('radx320:p5 r:FLOOR (12345 + 0.4) inexact rounded', 12345, 12345 + 0.4);
	AddTestCase('radx321:p5 r:FLOOR (12345 + 0.49) inexact rounded', 12345, 12345 + 0.49);
	AddTestCase('radx322:p5 r:FLOOR (12345 + 0.499) inexact rounded', 12345, 12345 + 0.499);
	AddTestCase('radx323:p5 r:FLOOR (12345 + 0.49999) inexact rounded', 12345, 12345 + 0.49999);
	AddTestCase('radx324:p5 r:FLOOR (12345 + 0.5) inexact rounded', 12345, 12345 + 0.5);
	AddTestCase('radx325:p5 r:FLOOR (12345 + 0.50001) inexact rounded', 12345, 12345 + 0.50001);
	AddTestCase('radx326:p5 r:FLOOR (12345 + 0.5001) inexact rounded', 12345, 12345 + 0.5001);
	AddTestCase('radx327:p5 r:FLOOR (12345 + 0.501) inexact rounded', 12345, 12345 + 0.501);
	AddTestCase('radx328:p5 r:FLOOR (12345 + 0.51) inexact rounded', 12345, 12345 + 0.51);
	AddTestCase('radx329:p5 r:FLOOR (12345 + 0.6) inexact rounded', 12345, 12345 + 0.6);
}
{
	use rounding CEILING;
	AddTestCase('radx330:p5 r:CEILING (12345 + -0.1) inexact rounded', 12345, 12345 + -0.1);
	AddTestCase('radx331:p5 r:CEILING (12345 + -0.01) inexact rounded', 12345, 12345 + -0.01);
	AddTestCase('radx332:p5 r:CEILING (12345 + -0.001) inexact rounded', 12345, 12345 + -0.001);
	AddTestCase('radx333:p5 r:CEILING (12345 + -0.00001) inexact rounded', 12345, 12345 + -0.00001);
	AddTestCase('radx334:p5 r:CEILING (12345 + -0.000001) inexact rounded', 12345, 12345 + -0.000001);
	AddTestCase('radx335:p5 r:CEILING (12345 + -0.0000001) inexact rounded', 12345, 12345 + -0.0000001);
	AddTestCase('radx336:p5 r:CEILING (12345 + 0)', 12345, 12345 + 0);
	AddTestCase('radx337:p5 r:CEILING (12345 + 0.0000001) inexact rounded', 12346, 12345 + 0.0000001);
	AddTestCase('radx338:p5 r:CEILING (12345 + 0.000001) inexact rounded', 12346, 12345 + 0.000001);
	AddTestCase('radx339:p5 r:CEILING (12345 + 0.00001) inexact rounded', 12346, 12345 + 0.00001);
	AddTestCase('radx340:p5 r:CEILING (12345 + 0.0001) inexact rounded', 12346, 12345 + 0.0001);
	AddTestCase('radx341:p5 r:CEILING (12345 + 0.001) inexact rounded', 12346, 12345 + 0.001);
	AddTestCase('radx342:p5 r:CEILING (12345 + 0.01) inexact rounded', 12346, 12345 + 0.01);
	AddTestCase('radx343:p5 r:CEILING (12345 + 0.1) inexact rounded', 12346, 12345 + 0.1);
	AddTestCase('radx345:p5 r:CEILING (12346 + 0.49999) inexact rounded', 12347, 12346 + 0.49999);
	AddTestCase('radx346:p5 r:CEILING (12346 + 0.5) inexact rounded', 12347, 12346 + 0.5);
	AddTestCase('radx347:p5 r:CEILING (12346 + 0.50001) inexact rounded', 12347, 12346 + 0.50001);
	AddTestCase('radx350:p5 r:CEILING (12345 + 0.4) inexact rounded', 12346, 12345 + 0.4);
	AddTestCase('radx351:p5 r:CEILING (12345 + 0.49) inexact rounded', 12346, 12345 + 0.49);
	AddTestCase('radx352:p5 r:CEILING (12345 + 0.499) inexact rounded', 12346, 12345 + 0.499);
	AddTestCase('radx353:p5 r:CEILING (12345 + 0.49999) inexact rounded', 12346, 12345 + 0.49999);
	AddTestCase('radx354:p5 r:CEILING (12345 + 0.5) inexact rounded', 12346, 12345 + 0.5);
	AddTestCase('radx355:p5 r:CEILING (12345 + 0.50001) inexact rounded', 12346, 12345 + 0.50001);
	AddTestCase('radx356:p5 r:CEILING (12345 + 0.5001) inexact rounded', 12346, 12345 + 0.5001);
	AddTestCase('radx357:p5 r:CEILING (12345 + 0.501) inexact rounded', 12346, 12345 + 0.501);
	AddTestCase('radx358:p5 r:CEILING (12345 + 0.51) inexact rounded', 12346, 12345 + 0.51);
	AddTestCase('radx359:p5 r:CEILING (12345 + 0.6) inexact rounded', 12346, 12345 + 0.6);
	// negatives...
}
{
	use rounding HALF_DOWN;
	AddTestCase('rsux140:p5 r:HALF_DOWN (-12345 + -0.1) inexact rounded', -12345, -12345 + -0.1);
	AddTestCase('rsux141:p5 r:HALF_DOWN (-12345 + -0.01) inexact rounded', -12345, -12345 + -0.01);
	AddTestCase('rsux142:p5 r:HALF_DOWN (-12345 + -0.001) inexact rounded', -12345, -12345 + -0.001);
	AddTestCase('rsux143:p5 r:HALF_DOWN (-12345 + -0.00001) inexact rounded', -12345, -12345 + -0.00001);
	AddTestCase('rsux144:p5 r:HALF_DOWN (-12345 + -0.000001) inexact rounded', -12345, -12345 + -0.000001);
	AddTestCase('rsux145:p5 r:HALF_DOWN (-12345 + -0.0000001) inexact rounded', -12345, -12345 + -0.0000001);
	AddTestCase('rsux146:p5 r:HALF_DOWN (-12345 + 0)', -12345, -12345 + 0);
	AddTestCase('rsux147:p5 r:HALF_DOWN (-12345 + 0.0000001) inexact rounded', -12345, -12345 + 0.0000001);
	AddTestCase('rsux148:p5 r:HALF_DOWN (-12345 + 0.000001) inexact rounded', -12345, -12345 + 0.000001);
	AddTestCase('rsux149:p5 r:HALF_DOWN (-12345 + 0.00001) inexact rounded', -12345, -12345 + 0.00001);
	AddTestCase('rsux150:p5 r:HALF_DOWN (-12345 + 0.0001) inexact rounded', -12345, -12345 + 0.0001);
	AddTestCase('rsux151:p5 r:HALF_DOWN (-12345 + 0.001) inexact rounded', -12345, -12345 + 0.001);
	AddTestCase('rsux152:p5 r:HALF_DOWN (-12345 + 0.01) inexact rounded', -12345, -12345 + 0.01);
	AddTestCase('rsux153:p5 r:HALF_DOWN (-12345 + 0.1) inexact rounded', -12345, -12345 + 0.1);
	AddTestCase('rsux155:p5 r:HALF_DOWN (-12346 + 0.49999) inexact rounded', -12346, -12346 + 0.49999);
	AddTestCase('rsux156:p5 r:HALF_DOWN (-12346 + 0.5) inexact rounded', -12345, -12346 + 0.5);
	AddTestCase('rsux157:p5 r:HALF_DOWN (-12346 + 0.50001) inexact rounded', -12345, -12346 + 0.50001);
	AddTestCase('rsux160:p5 r:HALF_DOWN (-12345 + 0.4) inexact rounded', -12345, -12345 + 0.4);
	AddTestCase('rsux161:p5 r:HALF_DOWN (-12345 + 0.49) inexact rounded', -12345, -12345 + 0.49);
	AddTestCase('rsux162:p5 r:HALF_DOWN (-12345 + 0.499) inexact rounded', -12345, -12345 + 0.499);
	AddTestCase('rsux163:p5 r:HALF_DOWN (-12345 + 0.49999) inexact rounded', -12345, -12345 + 0.49999);
	AddTestCase('rsux164:p5 r:HALF_DOWN (-12345 + 0.5) inexact rounded', -12344, -12345 + 0.5);
	AddTestCase('rsux165:p5 r:HALF_DOWN (-12345 + 0.50001) inexact rounded', -12344, -12345 + 0.50001);
	AddTestCase('rsux166:p5 r:HALF_DOWN (-12345 + 0.5001) inexact rounded', -12344, -12345 + 0.5001);
	AddTestCase('rsux167:p5 r:HALF_DOWN (-12345 + 0.501) inexact rounded', -12344, -12345 + 0.501);
	AddTestCase('rsux168:p5 r:HALF_DOWN (-12345 + 0.51) inexact rounded', -12344, -12345 + 0.51);
	AddTestCase('rsux169:p5 r:HALF_DOWN (-12345 + 0.6) inexact rounded', -12344, -12345 + 0.6);
}
{
	use rounding HALF_EVEN;
	AddTestCase('rsux170:p5 r:HALF_EVEN (-12345 + -0.1) inexact rounded', -12345, -12345 + -0.1);
	AddTestCase('rsux171:p5 r:HALF_EVEN (-12345 + -0.01) inexact rounded', -12345, -12345 + -0.01);
	AddTestCase('rsux172:p5 r:HALF_EVEN (-12345 + -0.001) inexact rounded', -12345, -12345 + -0.001);
	AddTestCase('rsux173:p5 r:HALF_EVEN (-12345 + -0.00001) inexact rounded', -12345, -12345 + -0.00001);
	AddTestCase('rsux174:p5 r:HALF_EVEN (-12345 + -0.000001) inexact rounded', -12345, -12345 + -0.000001);
	AddTestCase('rsux175:p5 r:HALF_EVEN (-12345 + -0.0000001) inexact rounded', -12345, -12345 + -0.0000001);
	AddTestCase('rsux176:p5 r:HALF_EVEN (-12345 + 0)', -12345, -12345 + 0);
	AddTestCase('rsux177:p5 r:HALF_EVEN (-12345 + 0.0000001) inexact rounded', -12345, -12345 + 0.0000001);
	AddTestCase('rsux178:p5 r:HALF_EVEN (-12345 + 0.000001) inexact rounded', -12345, -12345 + 0.000001);
	AddTestCase('rsux179:p5 r:HALF_EVEN (-12345 + 0.00001) inexact rounded', -12345, -12345 + 0.00001);
	AddTestCase('rsux180:p5 r:HALF_EVEN (-12345 + 0.0001) inexact rounded', -12345, -12345 + 0.0001);
	AddTestCase('rsux181:p5 r:HALF_EVEN (-12345 + 0.001) inexact rounded', -12345, -12345 + 0.001);
	AddTestCase('rsux182:p5 r:HALF_EVEN (-12345 + 0.01) inexact rounded', -12345, -12345 + 0.01);
	AddTestCase('rsux183:p5 r:HALF_EVEN (-12345 + 0.1) inexact rounded', -12345, -12345 + 0.1);
	AddTestCase('rsux185:p5 r:HALF_EVEN (-12346 + 0.49999) inexact rounded', -12346, -12346 + 0.49999);
	AddTestCase('rsux186:p5 r:HALF_EVEN (-12346 + 0.5) inexact rounded', -12346, -12346 + 0.5);
	AddTestCase('rsux187:p5 r:HALF_EVEN (-12346 + 0.50001) inexact rounded', -12345, -12346 + 0.50001);
	AddTestCase('rsux190:p5 r:HALF_EVEN (-12345 + 0.4) inexact rounded', -12345, -12345 + 0.4);
	AddTestCase('rsux191:p5 r:HALF_EVEN (-12345 + 0.49) inexact rounded', -12345, -12345 + 0.49);
	AddTestCase('rsux192:p5 r:HALF_EVEN (-12345 + 0.499) inexact rounded', -12345, -12345 + 0.499);
	AddTestCase('rsux193:p5 r:HALF_EVEN (-12345 + 0.49999) inexact rounded', -12345, -12345 + 0.49999);
	AddTestCase('rsux194:p5 r:HALF_EVEN (-12345 + 0.5) inexact rounded', -12344, -12345 + 0.5);
	AddTestCase('rsux195:p5 r:HALF_EVEN (-12345 + 0.50001) inexact rounded', -12344, -12345 + 0.50001);
	AddTestCase('rsux196:p5 r:HALF_EVEN (-12345 + 0.5001) inexact rounded', -12344, -12345 + 0.5001);
	AddTestCase('rsux197:p5 r:HALF_EVEN (-12345 + 0.501) inexact rounded', -12344, -12345 + 0.501);
	AddTestCase('rsux198:p5 r:HALF_EVEN (-12345 + 0.51) inexact rounded', -12344, -12345 + 0.51);
	AddTestCase('rsux199:p5 r:HALF_EVEN (-12345 + 0.6) inexact rounded', -12344, -12345 + 0.6);
}
{
	use rounding HALF_UP;
	AddTestCase('rsux200:p5 r:HALF_UP (-12345 + -0.1) inexact rounded', -12345, -12345 + -0.1);
	AddTestCase('rsux201:p5 r:HALF_UP (-12345 + -0.01) inexact rounded', -12345, -12345 + -0.01);
	AddTestCase('rsux202:p5 r:HALF_UP (-12345 + -0.001) inexact rounded', -12345, -12345 + -0.001);
	AddTestCase('rsux203:p5 r:HALF_UP (-12345 + -0.00001) inexact rounded', -12345, -12345 + -0.00001);
	AddTestCase('rsux204:p5 r:HALF_UP (-12345 + -0.000001) inexact rounded', -12345, -12345 + -0.000001);
	AddTestCase('rsux205:p5 r:HALF_UP (-12345 + -0.0000001) inexact rounded', -12345, -12345 + -0.0000001);
	AddTestCase('rsux206:p5 r:HALF_UP (-12345 + 0)', -12345, -12345 + 0);
	AddTestCase('rsux207:p5 r:HALF_UP (-12345 + 0.0000001) inexact rounded', -12345, -12345 + 0.0000001);
	AddTestCase('rsux208:p5 r:HALF_UP (-12345 + 0.000001) inexact rounded', -12345, -12345 + 0.000001);
	AddTestCase('rsux209:p5 r:HALF_UP (-12345 + 0.00001) inexact rounded', -12345, -12345 + 0.00001);
	AddTestCase('rsux210:p5 r:HALF_UP (-12345 + 0.0001) inexact rounded', -12345, -12345 + 0.0001);
	AddTestCase('rsux211:p5 r:HALF_UP (-12345 + 0.001) inexact rounded', -12345, -12345 + 0.001);
	AddTestCase('rsux212:p5 r:HALF_UP (-12345 + 0.01) inexact rounded', -12345, -12345 + 0.01);
	AddTestCase('rsux213:p5 r:HALF_UP (-12345 + 0.1) inexact rounded', -12345, -12345 + 0.1);
	AddTestCase('rsux215:p5 r:HALF_UP (-12346 + 0.49999) inexact rounded', -12346, -12346 + 0.49999);
	AddTestCase('rsux216:p5 r:HALF_UP (-12346 + 0.5) inexact rounded', -12346, -12346 + 0.5);
	AddTestCase('rsux217:p5 r:HALF_UP (-12346 + 0.50001) inexact rounded', -12345, -12346 + 0.50001);
	AddTestCase('rsux220:p5 r:HALF_UP (-12345 + 0.4) inexact rounded', -12345, -12345 + 0.4);
	AddTestCase('rsux221:p5 r:HALF_UP (-12345 + 0.49) inexact rounded', -12345, -12345 + 0.49);
	AddTestCase('rsux222:p5 r:HALF_UP (-12345 + 0.499) inexact rounded', -12345, -12345 + 0.499);
	AddTestCase('rsux223:p5 r:HALF_UP (-12345 + 0.49999) inexact rounded', -12345, -12345 + 0.49999);
	AddTestCase('rsux224:p5 r:HALF_UP (-12345 + 0.5) inexact rounded', -12345, -12345 + 0.5);
	AddTestCase('rsux225:p5 r:HALF_UP (-12345 + 0.50001) inexact rounded', -12344, -12345 + 0.50001);
	AddTestCase('rsux226:p5 r:HALF_UP (-12345 + 0.5001) inexact rounded', -12344, -12345 + 0.5001);
	AddTestCase('rsux227:p5 r:HALF_UP (-12345 + 0.501) inexact rounded', -12344, -12345 + 0.501);
	AddTestCase('rsux228:p5 r:HALF_UP (-12345 + 0.51) inexact rounded', -12344, -12345 + 0.51);
	AddTestCase('rsux229:p5 r:HALF_UP (-12345 + 0.6) inexact rounded', -12344, -12345 + 0.6);
}
{
	use rounding FLOOR;
	AddTestCase('rsux300:p5 r:FLOOR (-12345 + -0.1) inexact rounded', -12346, -12345 + -0.1);
	AddTestCase('rsux301:p5 r:FLOOR (-12345 + -0.01) inexact rounded', -12346, -12345 + -0.01);
	AddTestCase('rsux302:p5 r:FLOOR (-12345 + -0.001) inexact rounded', -12346, -12345 + -0.001);
	AddTestCase('rsux303:p5 r:FLOOR (-12345 + -0.00001) inexact rounded', -12346, -12345 + -0.00001);
	AddTestCase('rsux304:p5 r:FLOOR (-12345 + -0.000001) inexact rounded', -12346, -12345 + -0.000001);
	AddTestCase('rsux305:p5 r:FLOOR (-12345 + -0.0000001) inexact rounded', -12346, -12345 + -0.0000001);
	AddTestCase('rsux306:p5 r:FLOOR (-12345 + 0)', -12345, -12345 + 0);
	AddTestCase('rsux307:p5 r:FLOOR (-12345 + 0.0000001) inexact rounded', -12345, -12345 + 0.0000001);
	AddTestCase('rsux308:p5 r:FLOOR (-12345 + 0.000001) inexact rounded', -12345, -12345 + 0.000001);
	AddTestCase('rsux309:p5 r:FLOOR (-12345 + 0.00001) inexact rounded', -12345, -12345 + 0.00001);
	AddTestCase('rsux310:p5 r:FLOOR (-12345 + 0.0001) inexact rounded', -12345, -12345 + 0.0001);
	AddTestCase('rsux311:p5 r:FLOOR (-12345 + 0.001) inexact rounded', -12345, -12345 + 0.001);
	AddTestCase('rsux312:p5 r:FLOOR (-12345 + 0.01) inexact rounded', -12345, -12345 + 0.01);
	AddTestCase('rsux313:p5 r:FLOOR (-12345 + 0.1) inexact rounded', -12345, -12345 + 0.1);
	AddTestCase('rsux315:p5 r:FLOOR (-12346 + 0.49999) inexact rounded', -12346, -12346 + 0.49999);
	AddTestCase('rsux316:p5 r:FLOOR (-12346 + 0.5) inexact rounded', -12346, -12346 + 0.5);
	AddTestCase('rsux317:p5 r:FLOOR (-12346 + 0.50001) inexact rounded', -12346, -12346 + 0.50001);
	AddTestCase('rsux320:p5 r:FLOOR (-12345 + 0.4) inexact rounded', -12345, -12345 + 0.4);
	AddTestCase('rsux321:p5 r:FLOOR (-12345 + 0.49) inexact rounded', -12345, -12345 + 0.49);
	AddTestCase('rsux322:p5 r:FLOOR (-12345 + 0.499) inexact rounded', -12345, -12345 + 0.499);
	AddTestCase('rsux323:p5 r:FLOOR (-12345 + 0.49999) inexact rounded', -12345, -12345 + 0.49999);
	AddTestCase('rsux324:p5 r:FLOOR (-12345 + 0.5) inexact rounded', -12345, -12345 + 0.5);
	AddTestCase('rsux325:p5 r:FLOOR (-12345 + 0.50001) inexact rounded', -12345, -12345 + 0.50001);
	AddTestCase('rsux326:p5 r:FLOOR (-12345 + 0.5001) inexact rounded', -12345, -12345 + 0.5001);
	AddTestCase('rsux327:p5 r:FLOOR (-12345 + 0.501) inexact rounded', -12345, -12345 + 0.501);
	AddTestCase('rsux328:p5 r:FLOOR (-12345 + 0.51) inexact rounded', -12345, -12345 + 0.51);
	AddTestCase('rsux329:p5 r:FLOOR (-12345 + 0.6) inexact rounded', -12345, -12345 + 0.6);
}
{
	use rounding CEILING;
	AddTestCase('rsux330:p5 r:CEILING (-12345 + -0.1) inexact rounded', -12345, -12345 + -0.1);
	AddTestCase('rsux331:p5 r:CEILING (-12345 + -0.01) inexact rounded', -12345, -12345 + -0.01);
	AddTestCase('rsux332:p5 r:CEILING (-12345 + -0.001) inexact rounded', -12345, -12345 + -0.001);
	AddTestCase('rsux333:p5 r:CEILING (-12345 + -0.00001) inexact rounded', -12345, -12345 + -0.00001);
	AddTestCase('rsux334:p5 r:CEILING (-12345 + -0.000001) inexact rounded', -12345, -12345 + -0.000001);
	AddTestCase('rsux335:p5 r:CEILING (-12345 + -0.0000001) inexact rounded', -12345, -12345 + -0.0000001);
	AddTestCase('rsux336:p5 r:CEILING (-12345 + 0)', -12345, -12345 + 0);
	AddTestCase('rsux337:p5 r:CEILING (-12345 + 0.0000001) inexact rounded', -12344, -12345 + 0.0000001);
	AddTestCase('rsux338:p5 r:CEILING (-12345 + 0.000001) inexact rounded', -12344, -12345 + 0.000001);
	AddTestCase('rsux339:p5 r:CEILING (-12345 + 0.00001) inexact rounded', -12344, -12345 + 0.00001);
	AddTestCase('rsux340:p5 r:CEILING (-12345 + 0.0001) inexact rounded', -12344, -12345 + 0.0001);
	AddTestCase('rsux341:p5 r:CEILING (-12345 + 0.001) inexact rounded', -12344, -12345 + 0.001);
	AddTestCase('rsux342:p5 r:CEILING (-12345 + 0.01) inexact rounded', -12344, -12345 + 0.01);
	AddTestCase('rsux343:p5 r:CEILING (-12345 + 0.1) inexact rounded', -12344, -12345 + 0.1);
	AddTestCase('rsux345:p5 r:CEILING (-12346 + 0.49999) inexact rounded', -12345, -12346 + 0.49999);
	AddTestCase('rsux346:p5 r:CEILING (-12346 + 0.5) inexact rounded', -12345, -12346 + 0.5);
	AddTestCase('rsux347:p5 r:CEILING (-12346 + 0.50001) inexact rounded', -12345, -12346 + 0.50001);
	AddTestCase('rsux350:p5 r:CEILING (-12345 + 0.4) inexact rounded', -12344, -12345 + 0.4);
	AddTestCase('rsux351:p5 r:CEILING (-12345 + 0.49) inexact rounded', -12344, -12345 + 0.49);
	AddTestCase('rsux352:p5 r:CEILING (-12345 + 0.499) inexact rounded', -12344, -12345 + 0.499);
	AddTestCase('rsux353:p5 r:CEILING (-12345 + 0.49999) inexact rounded', -12344, -12345 + 0.49999);
	AddTestCase('rsux354:p5 r:CEILING (-12345 + 0.5) inexact rounded', -12344, -12345 + 0.5);
	AddTestCase('rsux355:p5 r:CEILING (-12345 + 0.50001) inexact rounded', -12344, -12345 + 0.50001);
	AddTestCase('rsux356:p5 r:CEILING (-12345 + 0.5001) inexact rounded', -12344, -12345 + 0.5001);
	AddTestCase('rsux357:p5 r:CEILING (-12345 + 0.501) inexact rounded', -12344, -12345 + 0.501);
	AddTestCase('rsux358:p5 r:CEILING (-12345 + 0.51) inexact rounded', -12344, -12345 + 0.51);
	AddTestCase('rsux359:p5 r:CEILING (-12345 + 0.6) inexact rounded', -12344, -12345 + 0.6);
	// check cancellation subtractions
	// (the ieee 854 'curious rule' in $6.3)
}
{
	use rounding HALF_UP;
	AddTestCase('rzex021:p5 r:HALF_UP (0 + 0)', 0, 0 + 0);
	AddTestCase('rzex022:p5 r:HALF_UP (0 + -0)', 0, 0 + -0);
	AddTestCase('rzex023:p5 r:HALF_UP (-0 + 0)', 0, -0 + 0);
	AddTestCase('rzex024:p5 r:HALF_UP (-0 + -0)', -0, -0 + -0);
	AddTestCase('rzex025:p5 r:HALF_UP (1 + -1)', 0, 1 + -1);
	AddTestCase('rzex026:p5 r:HALF_UP (-1 + 1)', 0, -1 + 1);
	AddTestCase('rzex027:p5 r:HALF_UP (1.5 + -1.5)', 0.0, 1.5 + -1.5);
	AddTestCase('rzex028:p5 r:HALF_UP (-1.5 + 1.5)', 0.0, -1.5 + 1.5);
	AddTestCase('rzex029:p5 r:HALF_UP (2 + -2)', 0, 2 + -2);
	AddTestCase('rzex030:p5 r:HALF_UP (-2 + 2)', 0, -2 + 2);
}
{
	use rounding HALF_DOWN;
	AddTestCase('rzex031:p5 r:HALF_DOWN (0 + 0)', 0, 0 + 0);
	AddTestCase('rzex032:p5 r:HALF_DOWN (0 + -0)', 0, 0 + -0);
	AddTestCase('rzex033:p5 r:HALF_DOWN (-0 + 0)', 0, -0 + 0);
	AddTestCase('rzex034:p5 r:HALF_DOWN (-0 + -0)', -0, -0 + -0);
	AddTestCase('rzex035:p5 r:HALF_DOWN (1 + -1)', 0, 1 + -1);
	AddTestCase('rzex036:p5 r:HALF_DOWN (-1 + 1)', 0, -1 + 1);
	AddTestCase('rzex037:p5 r:HALF_DOWN (1.5 + -1.5)', 0.0, 1.5 + -1.5);
	AddTestCase('rzex038:p5 r:HALF_DOWN (-1.5 + 1.5)', 0.0, -1.5 + 1.5);
	AddTestCase('rzex039:p5 r:HALF_DOWN (2 + -2)', 0, 2 + -2);
	AddTestCase('rzex040:p5 r:HALF_DOWN (-2 + 2)', 0, -2 + 2);
}
{
	use rounding HALF_EVEN;
	AddTestCase('rzex041:p5 r:HALF_EVEN (0 + 0)', 0, 0 + 0);
	AddTestCase('rzex042:p5 r:HALF_EVEN (0 + -0)', 0, 0 + -0);
	AddTestCase('rzex043:p5 r:HALF_EVEN (-0 + 0)', 0, -0 + 0);
	AddTestCase('rzex044:p5 r:HALF_EVEN (-0 + -0)', -0, -0 + -0);
	AddTestCase('rzex045:p5 r:HALF_EVEN (1 + -1)', 0, 1 + -1);
	AddTestCase('rzex046:p5 r:HALF_EVEN (-1 + 1)', 0, -1 + 1);
	AddTestCase('rzex047:p5 r:HALF_EVEN (1.5 + -1.5)', 0.0, 1.5 + -1.5);
	AddTestCase('rzex048:p5 r:HALF_EVEN (-1.5 + 1.5)', 0.0, -1.5 + 1.5);
	AddTestCase('rzex049:p5 r:HALF_EVEN (2 + -2)', 0, 2 + -2);
	AddTestCase('rzex050:p5 r:HALF_EVEN (-2 + 2)', 0, -2 + 2);
}
{
	use rounding FLOOR;
	AddTestCase('rzex051:p5 r:FLOOR (0 + 0)', 0, 0 + 0);
	AddTestCase('rzex052:p5 r:FLOOR (0 + -0) -- here are two curious', -0, 0 + -0);
	AddTestCase('rzex053:p5 r:FLOOR (-0 + 0) --', -0, -0 + 0);
	AddTestCase('rzex054:p5 r:FLOOR (-0 + -0)', -0, -0 + -0);
	AddTestCase('rzex055:p5 r:FLOOR (1 + -1) -- here are the rest', -0, 1 + -1);
	AddTestCase('rzex056:p5 r:FLOOR (-1 + 1) -- ..', -0, -1 + 1);
	AddTestCase('rzex057:p5 r:FLOOR (1.5 + -1.5) -- ..', -0.0, 1.5 + -1.5);
	AddTestCase('rzex058:p5 r:FLOOR (-1.5 + 1.5) -- ..', -0.0, -1.5 + 1.5);
	AddTestCase('rzex059:p5 r:FLOOR (2 + -2) -- ..', -0, 2 + -2);
	AddTestCase('rzex060:p5 r:FLOOR (-2 + 2) -- ..', -0, -2 + 2);
}
{
	use rounding CEILING;
	AddTestCase('rzex061:p5 r:CEILING (0 + 0)', 0, 0 + 0);
	AddTestCase('rzex062:p5 r:CEILING (0 + -0)', 0, 0 + -0);
	AddTestCase('rzex063:p5 r:CEILING (-0 + 0)', 0, -0 + 0);
	AddTestCase('rzex064:p5 r:CEILING (-0 + -0)', -0, -0 + -0);
	AddTestCase('rzex065:p5 r:CEILING (1 + -1)', 0, 1 + -1);
	AddTestCase('rzex066:p5 r:CEILING (-1 + 1)', 0, -1 + 1);
	AddTestCase('rzex067:p5 r:CEILING (1.5 + -1.5)', 0.0, 1.5 + -1.5);
	AddTestCase('rzex068:p5 r:CEILING (-1.5 + 1.5)', 0.0, -1.5 + 1.5);
	AddTestCase('rzex069:p5 r:CEILING (2 + -2)', 0, 2 + -2);
	AddTestCase('rzex070:p5 r:CEILING (-2 + 2)', 0, -2 + 2);
	// division operators -------------------------------------------------
}
{
	use rounding HALF_DOWN;
	AddTestCase('rdvx201:p5 r:HALF_DOWN (12345 / 1)', 12345, 12345 / 1);
	AddTestCase('rdvx202:p5 r:HALF_DOWN (12345 / 1.0001) inexact rounded', 12344, 12345 / 1.0001);
	AddTestCase('rdvx203:p5 r:HALF_DOWN (12345 / 1.001) inexact rounded', 12333, 12345 / 1.001);
	AddTestCase('rdvx204:p5 r:HALF_DOWN (12345 / 1.01) inexact rounded', 12223, 12345 / 1.01);
	AddTestCase('rdvx205:p5 r:HALF_DOWN (12345 / 1.1) inexact rounded', 11223, 12345 / 1.1);
	AddTestCase('rdvx206:p5 r:HALF_DOWN (12355 / 4) inexact rounded', 3088.7, 12355 / 4);
	AddTestCase('rdvx207:p5 r:HALF_DOWN (12345 / 4) inexact rounded', 3086.2, 12345 / 4);
	AddTestCase('rdvx208:p5 r:HALF_DOWN (12355 / 4.0001) inexact rounded', 3088.7, 12355 / 4.0001);
	AddTestCase('rdvx209:p5 r:HALF_DOWN (12345 / 4.0001) inexact rounded', 3086.2, 12345 / 4.0001);
	AddTestCase('rdvx210:p5 r:HALF_DOWN (12345 / 4.9) inexact rounded', 2519.4, 12345 / 4.9);
	AddTestCase('rdvx211:p5 r:HALF_DOWN (12345 / 4.99) inexact rounded', 2473.9, 12345 / 4.99);
	AddTestCase('rdvx212:p5 r:HALF_DOWN (12345 / 4.999) inexact rounded', 2469.5, 12345 / 4.999);
	AddTestCase('rdvx213:p5 r:HALF_DOWN (12345 / 4.9999) inexact rounded', 2469.0, 12345 / 4.9999);
	AddTestCase('rdvx214:p5 r:HALF_DOWN (12345 / 5)', 2469, 12345 / 5);
	AddTestCase('rdvx215:p5 r:HALF_DOWN (12345 / 5.0001) inexact rounded', 2469.0, 12345 / 5.0001);
	AddTestCase('rdvx216:p5 r:HALF_DOWN (12345 / 5.001) inexact rounded', 2468.5, 12345 / 5.001);
	AddTestCase('rdvx217:p5 r:HALF_DOWN (12345 / 5.01) inexact rounded', 2464.1, 12345 / 5.01);
	AddTestCase('rdvx218:p5 r:HALF_DOWN (12345 / 5.1) inexact rounded', 2420.6, 12345 / 5.1);
}
{
	use rounding HALF_EVEN;
	AddTestCase('rdvx301:p5 r:HALF_EVEN (12345 / 1)', 12345, 12345 / 1);
	AddTestCase('rdvx302:p5 r:HALF_EVEN (12345 / 1.0001) inexact rounded', 12344, 12345 / 1.0001);
	AddTestCase('rdvx303:p5 r:HALF_EVEN (12345 / 1.001) inexact rounded', 12333, 12345 / 1.001);
	AddTestCase('rdvx304:p5 r:HALF_EVEN (12345 / 1.01) inexact rounded', 12223, 12345 / 1.01);
	AddTestCase('rdvx305:p5 r:HALF_EVEN (12345 / 1.1) inexact rounded', 11223, 12345 / 1.1);
	AddTestCase('rdvx306:p5 r:HALF_EVEN (12355 / 4) inexact rounded', 3088.8, 12355 / 4);
	AddTestCase('rdvx307:p5 r:HALF_EVEN (12345 / 4) inexact rounded', 3086.2, 12345 / 4);
	AddTestCase('rdvx308:p5 r:HALF_EVEN (12355 / 4.0001) inexact rounded', 3088.7, 12355 / 4.0001);
	AddTestCase('rdvx309:p5 r:HALF_EVEN (12345 / 4.0001) inexact rounded', 3086.2, 12345 / 4.0001);
	AddTestCase('rdvx310:p5 r:HALF_EVEN (12345 / 4.9) inexact rounded', 2519.4, 12345 / 4.9);
	AddTestCase('rdvx311:p5 r:HALF_EVEN (12345 / 4.99) inexact rounded', 2473.9, 12345 / 4.99);
	AddTestCase('rdvx312:p5 r:HALF_EVEN (12345 / 4.999) inexact rounded', 2469.5, 12345 / 4.999);
	AddTestCase('rdvx313:p5 r:HALF_EVEN (12345 / 4.9999) inexact rounded', 2469.0, 12345 / 4.9999);
	AddTestCase('rdvx314:p5 r:HALF_EVEN (12345 / 5)', 2469, 12345 / 5);
	AddTestCase('rdvx315:p5 r:HALF_EVEN (12345 / 5.0001) inexact rounded', 2469.0, 12345 / 5.0001);
	AddTestCase('rdvx316:p5 r:HALF_EVEN (12345 / 5.001) inexact rounded', 2468.5, 12345 / 5.001);
	AddTestCase('rdvx317:p5 r:HALF_EVEN (12345 / 5.01) inexact rounded', 2464.1, 12345 / 5.01);
	AddTestCase('rdvx318:p5 r:HALF_EVEN (12345 / 5.1) inexact rounded', 2420.6, 12345 / 5.1);
}
{
	use rounding HALF_UP;
	AddTestCase('rdvx401:p5 r:HALF_UP (12345 / 1)', 12345, 12345 / 1);
	AddTestCase('rdvx402:p5 r:HALF_UP (12345 / 1.0001) inexact rounded', 12344, 12345 / 1.0001);
	AddTestCase('rdvx403:p5 r:HALF_UP (12345 / 1.001) inexact rounded', 12333, 12345 / 1.001);
	AddTestCase('rdvx404:p5 r:HALF_UP (12345 / 1.01) inexact rounded', 12223, 12345 / 1.01);
	AddTestCase('rdvx405:p5 r:HALF_UP (12345 / 1.1) inexact rounded', 11223, 12345 / 1.1);
	AddTestCase('rdvx406:p5 r:HALF_UP (12355 / 4) inexact rounded', 3088.8, 12355 / 4);
	AddTestCase('rdvx407:p5 r:HALF_UP (12345 / 4) inexact rounded', 3086.3, 12345 / 4);
	AddTestCase('rdvx408:p5 r:HALF_UP (12355 / 4.0001) inexact rounded', 3088.7, 12355 / 4.0001);
	AddTestCase('rdvx409:p5 r:HALF_UP (12345 / 4.0001) inexact rounded', 3086.2, 12345 / 4.0001);
	AddTestCase('rdvx410:p5 r:HALF_UP (12345 / 4.9) inexact rounded', 2519.4, 12345 / 4.9);
	AddTestCase('rdvx411:p5 r:HALF_UP (12345 / 4.99) inexact rounded', 2473.9, 12345 / 4.99);
	AddTestCase('rdvx412:p5 r:HALF_UP (12345 / 4.999) inexact rounded', 2469.5, 12345 / 4.999);
	AddTestCase('rdvx413:p5 r:HALF_UP (12345 / 4.9999) inexact rounded', 2469.0, 12345 / 4.9999);
	AddTestCase('rdvx414:p5 r:HALF_UP (12345 / 5)', 2469, 12345 / 5);
	AddTestCase('rdvx415:p5 r:HALF_UP (12345 / 5.0001) inexact rounded', 2469.0, 12345 / 5.0001);
	AddTestCase('rdvx416:p5 r:HALF_UP (12345 / 5.001) inexact rounded', 2468.5, 12345 / 5.001);
	AddTestCase('rdvx417:p5 r:HALF_UP (12345 / 5.01) inexact rounded', 2464.1, 12345 / 5.01);
	AddTestCase('rdvx418:p5 r:HALF_UP (12345 / 5.1) inexact rounded', 2420.6, 12345 / 5.1);
}
{
	use rounding FLOOR;
	AddTestCase('rdvx601:p5 r:FLOOR (12345 / 1)', 12345, 12345 / 1);
	AddTestCase('rdvx602:p5 r:FLOOR (12345 / 1.0001) inexact rounded', 12343, 12345 / 1.0001);
	AddTestCase('rdvx603:p5 r:FLOOR (12345 / 1.001) inexact rounded', 12332, 12345 / 1.001);
	AddTestCase('rdvx604:p5 r:FLOOR (12345 / 1.01) inexact rounded', 12222, 12345 / 1.01);
	AddTestCase('rdvx605:p5 r:FLOOR (12345 / 1.1) inexact rounded', 11222, 12345 / 1.1);
	AddTestCase('rdvx606:p5 r:FLOOR (12355 / 4) inexact rounded', 3088.7, 12355 / 4);
	AddTestCase('rdvx607:p5 r:FLOOR (12345 / 4) inexact rounded', 3086.2, 12345 / 4);
	AddTestCase('rdvx608:p5 r:FLOOR (12355 / 4.0001) inexact rounded', 3088.6, 12355 / 4.0001);
	AddTestCase('rdvx609:p5 r:FLOOR (12345 / 4.0001) inexact rounded', 3086.1, 12345 / 4.0001);
	AddTestCase('rdvx610:p5 r:FLOOR (12345 / 4.9) inexact rounded', 2519.3, 12345 / 4.9);
	AddTestCase('rdvx611:p5 r:FLOOR (12345 / 4.99) inexact rounded', 2473.9, 12345 / 4.99);
	AddTestCase('rdvx612:p5 r:FLOOR (12345 / 4.999) inexact rounded', 2469.4, 12345 / 4.999);
	AddTestCase('rdvx613:p5 r:FLOOR (12345 / 4.9999) inexact rounded', 2469.0, 12345 / 4.9999);
	AddTestCase('rdvx614:p5 r:FLOOR (12345 / 5)', 2469, 12345 / 5);
	AddTestCase('rdvx615:p5 r:FLOOR (12345 / 5.0001) inexact rounded', 2468.9, 12345 / 5.0001);
	AddTestCase('rdvx616:p5 r:FLOOR (12345 / 5.001) inexact rounded', 2468.5, 12345 / 5.001);
	AddTestCase('rdvx617:p5 r:FLOOR (12345 / 5.01) inexact rounded', 2464.0, 12345 / 5.01);
	AddTestCase('rdvx618:p5 r:FLOOR (12345 / 5.1) inexact rounded', 2420.5, 12345 / 5.1);
}
{
	use rounding CEILING;
	AddTestCase('rdvx701:p5 r:CEILING (12345 / 1)', 12345, 12345 / 1);
	AddTestCase('rdvx702:p5 r:CEILING (12345 / 1.0001) inexact rounded', 12344, 12345 / 1.0001);
	AddTestCase('rdvx703:p5 r:CEILING (12345 / 1.001) inexact rounded', 12333, 12345 / 1.001);
	AddTestCase('rdvx704:p5 r:CEILING (12345 / 1.01) inexact rounded', 12223, 12345 / 1.01);
	AddTestCase('rdvx705:p5 r:CEILING (12345 / 1.1) inexact rounded', 11223, 12345 / 1.1);
	AddTestCase('rdvx706:p5 r:CEILING (12355 / 4) inexact rounded', 3088.8, 12355 / 4);
	AddTestCase('rdvx707:p5 r:CEILING (12345 / 4) inexact rounded', 3086.3, 12345 / 4);
	AddTestCase('rdvx708:p5 r:CEILING (12355 / 4.0001) inexact rounded', 3088.7, 12355 / 4.0001);
	AddTestCase('rdvx709:p5 r:CEILING (12345 / 4.0001) inexact rounded', 3086.2, 12345 / 4.0001);
	AddTestCase('rdvx710:p5 r:CEILING (12345 / 4.9) inexact rounded', 2519.4, 12345 / 4.9);
	AddTestCase('rdvx711:p5 r:CEILING (12345 / 4.99) inexact rounded', 2474.0, 12345 / 4.99);
	AddTestCase('rdvx712:p5 r:CEILING (12345 / 4.999) inexact rounded', 2469.5, 12345 / 4.999);
	AddTestCase('rdvx713:p5 r:CEILING (12345 / 4.9999) inexact rounded', 2469.1, 12345 / 4.9999);
	AddTestCase('rdvx714:p5 r:CEILING (12345 / 5)', 2469, 12345 / 5);
	AddTestCase('rdvx715:p5 r:CEILING (12345 / 5.0001) inexact rounded', 2469.0, 12345 / 5.0001);
	AddTestCase('rdvx716:p5 r:CEILING (12345 / 5.001) inexact rounded', 2468.6, 12345 / 5.001);
	AddTestCase('rdvx717:p5 r:CEILING (12345 / 5.01) inexact rounded', 2464.1, 12345 / 5.01);
	AddTestCase('rdvx718:p5 r:CEILING (12345 / 5.1) inexact rounded', 2420.6, 12345 / 5.1);
	// [divideinteger and remainder unaffected]
	// multiplication operator --------------------------------------------
}
{
	use rounding HALF_DOWN;
	AddTestCase('rmux201:p5 r:HALF_DOWN (12345 * 1)', 12345, 12345 * 1);
	AddTestCase('rmux202:p5 r:HALF_DOWN (12345 * 1.0001) inexact rounded', 12346, 12345 * 1.0001);
	AddTestCase('rmux203:p5 r:HALF_DOWN (12345 * 1.001) inexact rounded', 12357, 12345 * 1.001);
	AddTestCase('rmux204:p5 r:HALF_DOWN (12345 * 1.01) inexact rounded', 12468, 12345 * 1.01);
	AddTestCase('rmux205:p5 r:HALF_DOWN (12345 * 1.1) inexact rounded', 13579, 12345 * 1.1);
	AddTestCase('rmux206:p5 r:HALF_DOWN (12345 * 4)', 49380, 12345 * 4);
	AddTestCase('rmux207:p5 r:HALF_DOWN (12345 * 4.0001) inexact rounded', 49381, 12345 * 4.0001);
	AddTestCase('rmux208:p5 r:HALF_DOWN (12345 * 4.9) inexact rounded', 60490, 12345 * 4.9);
	AddTestCase('rmux209:p5 r:HALF_DOWN (12345 * 4.99) inexact rounded', 61602, 12345 * 4.99);
	AddTestCase('rmux210:p5 r:HALF_DOWN (12345 * 4.999) inexact rounded', 61713, 12345 * 4.999);
	AddTestCase('rmux211:p5 r:HALF_DOWN (12345 * 4.9999) inexact rounded', 61724, 12345 * 4.9999);
	AddTestCase('rmux212:p5 r:HALF_DOWN (12345 * 5)', 61725, 12345 * 5);
	AddTestCase('rmux213:p5 r:HALF_DOWN (12345 * 5.0001) inexact rounded', 61726, 12345 * 5.0001);
	AddTestCase('rmux214:p5 r:HALF_DOWN (12345 * 5.001) inexact rounded', 61737, 12345 * 5.001);
	AddTestCase('rmux215:p5 r:HALF_DOWN (12345 * 5.01) inexact rounded', 61848, 12345 * 5.01);
	AddTestCase('rmux216:p5 r:HALF_DOWN (12345 * 12) rounded', 1.4814e+5, 12345 * 12);
	AddTestCase('rmux217:p5 r:HALF_DOWN (12345 * 13) inexact rounded', 1.6048e+5, 12345 * 13);
	AddTestCase('rmux218:p5 r:HALF_DOWN (12355 * 12) rounded', 1.4826e+5, 12355 * 12);
	AddTestCase('rmux219:p5 r:HALF_DOWN (12355 * 13) inexact rounded', 1.6061e+5, 12355 * 13);
}
{
	use rounding HALF_EVEN;
	AddTestCase('rmux301:p5 r:HALF_EVEN (12345 * 1)', 12345, 12345 * 1);
	AddTestCase('rmux302:p5 r:HALF_EVEN (12345 * 1.0001) inexact rounded', 12346, 12345 * 1.0001);
	AddTestCase('rmux303:p5 r:HALF_EVEN (12345 * 1.001) inexact rounded', 12357, 12345 * 1.001);
	AddTestCase('rmux304:p5 r:HALF_EVEN (12345 * 1.01) inexact rounded', 12468, 12345 * 1.01);
	AddTestCase('rmux305:p5 r:HALF_EVEN (12345 * 1.1) inexact rounded', 13580, 12345 * 1.1);
	AddTestCase('rmux306:p5 r:HALF_EVEN (12345 * 4)', 49380, 12345 * 4);
	AddTestCase('rmux307:p5 r:HALF_EVEN (12345 * 4.0001) inexact rounded', 49381, 12345 * 4.0001);
	AddTestCase('rmux308:p5 r:HALF_EVEN (12345 * 4.9) inexact rounded', 60490, 12345 * 4.9);
	AddTestCase('rmux309:p5 r:HALF_EVEN (12345 * 4.99) inexact rounded', 61602, 12345 * 4.99);
	AddTestCase('rmux310:p5 r:HALF_EVEN (12345 * 4.999) inexact rounded', 61713, 12345 * 4.999);
	AddTestCase('rmux311:p5 r:HALF_EVEN (12345 * 4.9999) inexact rounded', 61724, 12345 * 4.9999);
	AddTestCase('rmux312:p5 r:HALF_EVEN (12345 * 5)', 61725, 12345 * 5);
	AddTestCase('rmux313:p5 r:HALF_EVEN (12345 * 5.0001) inexact rounded', 61726, 12345 * 5.0001);
	AddTestCase('rmux314:p5 r:HALF_EVEN (12345 * 5.001) inexact rounded', 61737, 12345 * 5.001);
	AddTestCase('rmux315:p5 r:HALF_EVEN (12345 * 5.01) inexact rounded', 61848, 12345 * 5.01);
	AddTestCase('rmux316:p5 r:HALF_EVEN (12345 * 12) rounded', 1.4814e+5, 12345 * 12);
	AddTestCase('rmux317:p5 r:HALF_EVEN (12345 * 13) inexact rounded', 1.6048e+5, 12345 * 13);
	AddTestCase('rmux318:p5 r:HALF_EVEN (12355 * 12) rounded', 1.4826e+5, 12355 * 12);
	AddTestCase('rmux319:p5 r:HALF_EVEN (12355 * 13) inexact rounded', 1.6062e+5, 12355 * 13);
}
{
	use rounding HALF_UP;
	AddTestCase('rmux401:p5 r:HALF_UP (12345 * 1)', 12345, 12345 * 1);
	AddTestCase('rmux402:p5 r:HALF_UP (12345 * 1.0001) inexact rounded', 12346, 12345 * 1.0001);
	AddTestCase('rmux403:p5 r:HALF_UP (12345 * 1.001) inexact rounded', 12357, 12345 * 1.001);
	AddTestCase('rmux404:p5 r:HALF_UP (12345 * 1.01) inexact rounded', 12468, 12345 * 1.01);
	AddTestCase('rmux405:p5 r:HALF_UP (12345 * 1.1) inexact rounded', 13580, 12345 * 1.1);
	AddTestCase('rmux406:p5 r:HALF_UP (12345 * 4)', 49380, 12345 * 4);
	AddTestCase('rmux407:p5 r:HALF_UP (12345 * 4.0001) inexact rounded', 49381, 12345 * 4.0001);
	AddTestCase('rmux408:p5 r:HALF_UP (12345 * 4.9) inexact rounded', 60491, 12345 * 4.9);
	AddTestCase('rmux409:p5 r:HALF_UP (12345 * 4.99) inexact rounded', 61602, 12345 * 4.99);
	AddTestCase('rmux410:p5 r:HALF_UP (12345 * 4.999) inexact rounded', 61713, 12345 * 4.999);
	AddTestCase('rmux411:p5 r:HALF_UP (12345 * 4.9999) inexact rounded', 61724, 12345 * 4.9999);
	AddTestCase('rmux412:p5 r:HALF_UP (12345 * 5)', 61725, 12345 * 5);
	AddTestCase('rmux413:p5 r:HALF_UP (12345 * 5.0001) inexact rounded', 61726, 12345 * 5.0001);
	AddTestCase('rmux414:p5 r:HALF_UP (12345 * 5.001) inexact rounded', 61737, 12345 * 5.001);
	AddTestCase('rmux415:p5 r:HALF_UP (12345 * 5.01) inexact rounded', 61848, 12345 * 5.01);
	AddTestCase('rmux416:p5 r:HALF_UP (12345 * 12) rounded', 1.4814e+5, 12345 * 12);
	AddTestCase('rmux417:p5 r:HALF_UP (12345 * 13) inexact rounded', 1.6049e+5, 12345 * 13);
	AddTestCase('rmux418:p5 r:HALF_UP (12355 * 12) rounded', 1.4826e+5, 12355 * 12);
	AddTestCase('rmux419:p5 r:HALF_UP (12355 * 13) inexact rounded', 1.6062e+5, 12355 * 13);
	// [rmux516 & rmux518] can surprise
}
{
	use rounding FLOOR;
	AddTestCase('rmux601:p5 r:FLOOR (12345 * 1)', 12345, 12345 * 1);
	AddTestCase('rmux602:p5 r:FLOOR (12345 * 1.0001) inexact rounded', 12346, 12345 * 1.0001);
	AddTestCase('rmux603:p5 r:FLOOR (12345 * 1.001) inexact rounded', 12357, 12345 * 1.001);
	AddTestCase('rmux604:p5 r:FLOOR (12345 * 1.01) inexact rounded', 12468, 12345 * 1.01);
	AddTestCase('rmux605:p5 r:FLOOR (12345 * 1.1) inexact rounded', 13579, 12345 * 1.1);
	AddTestCase('rmux606:p5 r:FLOOR (12345 * 4)', 49380, 12345 * 4);
	AddTestCase('rmux607:p5 r:FLOOR (12345 * 4.0001) inexact rounded', 49381, 12345 * 4.0001);
	AddTestCase('rmux608:p5 r:FLOOR (12345 * 4.9) inexact rounded', 60490, 12345 * 4.9);
	AddTestCase('rmux609:p5 r:FLOOR (12345 * 4.99) inexact rounded', 61601, 12345 * 4.99);
	AddTestCase('rmux610:p5 r:FLOOR (12345 * 4.999) inexact rounded', 61712, 12345 * 4.999);
	AddTestCase('rmux611:p5 r:FLOOR (12345 * 4.9999) inexact rounded', 61723, 12345 * 4.9999);
	AddTestCase('rmux612:p5 r:FLOOR (12345 * 5)', 61725, 12345 * 5);
	AddTestCase('rmux613:p5 r:FLOOR (12345 * 5.0001) inexact rounded', 61726, 12345 * 5.0001);
	AddTestCase('rmux614:p5 r:FLOOR (12345 * 5.001) inexact rounded', 61737, 12345 * 5.001);
	AddTestCase('rmux615:p5 r:FLOOR (12345 * 5.01) inexact rounded', 61848, 12345 * 5.01);
	AddTestCase('rmux616:p5 r:FLOOR (12345 * 12) rounded', 1.4814e+5, 12345 * 12);
	AddTestCase('rmux617:p5 r:FLOOR (12345 * 13) inexact rounded', 1.6048e+5, 12345 * 13);
	AddTestCase('rmux618:p5 r:FLOOR (12355 * 12) rounded', 1.4826e+5, 12355 * 12);
	AddTestCase('rmux619:p5 r:FLOOR (12355 * 13) inexact rounded', 1.6061e+5, 12355 * 13);
}
{
	use rounding CEILING;
	AddTestCase('rmux701:p5 r:CEILING (12345 * 1)', 12345, 12345 * 1);
	AddTestCase('rmux702:p5 r:CEILING (12345 * 1.0001) inexact rounded', 12347, 12345 * 1.0001);
	AddTestCase('rmux703:p5 r:CEILING (12345 * 1.001) inexact rounded', 12358, 12345 * 1.001);
	AddTestCase('rmux704:p5 r:CEILING (12345 * 1.01) inexact rounded', 12469, 12345 * 1.01);
	AddTestCase('rmux705:p5 r:CEILING (12345 * 1.1) inexact rounded', 13580, 12345 * 1.1);
	AddTestCase('rmux706:p5 r:CEILING (12345 * 4)', 49380, 12345 * 4);
	AddTestCase('rmux707:p5 r:CEILING (12345 * 4.0001) inexact rounded', 49382, 12345 * 4.0001);
	AddTestCase('rmux708:p5 r:CEILING (12345 * 4.9) inexact rounded', 60491, 12345 * 4.9);
	AddTestCase('rmux709:p5 r:CEILING (12345 * 4.99) inexact rounded', 61602, 12345 * 4.99);
	AddTestCase('rmux710:p5 r:CEILING (12345 * 4.999) inexact rounded', 61713, 12345 * 4.999);
	AddTestCase('rmux711:p5 r:CEILING (12345 * 4.9999) inexact rounded', 61724, 12345 * 4.9999);
	AddTestCase('rmux712:p5 r:CEILING (12345 * 5)', 61725, 12345 * 5);
	AddTestCase('rmux713:p5 r:CEILING (12345 * 5.0001) inexact rounded', 61727, 12345 * 5.0001);
	AddTestCase('rmux714:p5 r:CEILING (12345 * 5.001) inexact rounded', 61738, 12345 * 5.001);
	AddTestCase('rmux715:p5 r:CEILING (12345 * 5.01) inexact rounded', 61849, 12345 * 5.01);
	AddTestCase('rmux716:p5 r:CEILING (12345 * 12) rounded', 1.4814e+5, 12345 * 12);
	AddTestCase('rmux717:p5 r:CEILING (12345 * 13) inexact rounded', 1.6049e+5, 12345 * 13);
	AddTestCase('rmux718:p5 r:CEILING (12355 * 12) rounded', 1.4826e+5, 12355 * 12);
	AddTestCase('rmux719:p5 r:CEILING (12355 * 13) inexact rounded', 1.6062e+5, 12355 * 13);
	// power operator -----------------------------------------------------
}
{
	use rounding HALF_DOWN;
	AddTestCase('rpox201:p5 r:HALF_DOWN (0 + decimal.pow(12345,-5)) inexact rounded', 3.4877e-21, 0 + decimal.pow(12345,-5));
	AddTestCase('rpox202:p5 r:HALF_DOWN (0 + decimal.pow(12345,-4)) inexact rounded', 4.3056e-17, 0 + decimal.pow(12345,-4));
	AddTestCase('rpox203:p5 r:HALF_DOWN (0 + decimal.pow(12345,-3)) inexact rounded', 5.3153e-13, 0 + decimal.pow(12345,-3));
	AddTestCase('rpox204:p5 r:HALF_DOWN (0 + decimal.pow(12345,-2)) inexact rounded', 6.5617e-9, 0 + decimal.pow(12345,-2));
	AddTestCase('rpox205:p5 r:HALF_DOWN (0 + decimal.pow(12345,-1)) inexact rounded', 0.000081004, 0 + decimal.pow(12345,-1));
	AddTestCase('rpox206:p5 r:HALF_DOWN (0 + decimal.pow(12345,0))', 1, 0 + decimal.pow(12345,0));
	AddTestCase('rpox207:p5 r:HALF_DOWN (0 + decimal.pow(12345,1))', 12345, 0 + decimal.pow(12345,1));
	AddTestCase('rpox208:p5 r:HALF_DOWN (0 + decimal.pow(12345,2)) inexact rounded', 1.5240e+8, 0 + decimal.pow(12345,2));
	AddTestCase('rpox209:p5 r:HALF_DOWN (0 + decimal.pow(12345,3)) inexact rounded', 1.8814e+12, 0 + decimal.pow(12345,3));
	AddTestCase('rpox210:p5 r:HALF_DOWN (0 + decimal.pow(12345,4)) inexact rounded', 2.3225e+16, 0 + decimal.pow(12345,4));
	AddTestCase('rpox211:p5 r:HALF_DOWN (0 + decimal.pow(12345,5)) inexact rounded', 2.8672e+20, 0 + decimal.pow(12345,5));
	AddTestCase('rpox212:p5 r:HALF_DOWN (0 + decimal.pow(415,2)) inexact rounded', 1.7222e+5, 0 + decimal.pow(415,2));
	AddTestCase('rpox213:p5 r:HALF_DOWN (0 + decimal.pow(75,3)) inexact rounded', 4.2187e+5, 0 + decimal.pow(75,3));
}
{
	use rounding HALF_EVEN;
	AddTestCase('rpox301:p5 r:HALF_EVEN (0 + decimal.pow(12345,-5)) inexact rounded', 3.4877e-21, 0 + decimal.pow(12345,-5));
	AddTestCase('rpox302:p5 r:HALF_EVEN (0 + decimal.pow(12345,-4)) inexact rounded', 4.3056e-17, 0 + decimal.pow(12345,-4));
	AddTestCase('rpox303:p5 r:HALF_EVEN (0 + decimal.pow(12345,-3)) inexact rounded', 5.3153e-13, 0 + decimal.pow(12345,-3));
	AddTestCase('rpox304:p5 r:HALF_EVEN (0 + decimal.pow(12345,-2)) inexact rounded', 6.5617e-9, 0 + decimal.pow(12345,-2));
	AddTestCase('rpox305:p5 r:HALF_EVEN (0 + decimal.pow(12345,-1)) inexact rounded', 0.000081004, 0 + decimal.pow(12345,-1));
	AddTestCase('rpox306:p5 r:HALF_EVEN (0 + decimal.pow(12345,0))', 1, 0 + decimal.pow(12345,0));
	AddTestCase('rpox307:p5 r:HALF_EVEN (0 + decimal.pow(12345,1))', 12345, 0 + decimal.pow(12345,1));
	AddTestCase('rpox308:p5 r:HALF_EVEN (0 + decimal.pow(12345,2)) inexact rounded', 1.5240e+8, 0 + decimal.pow(12345,2));
	AddTestCase('rpox309:p5 r:HALF_EVEN (0 + decimal.pow(12345,3)) inexact rounded', 1.8814e+12, 0 + decimal.pow(12345,3));
	AddTestCase('rpox310:p5 r:HALF_EVEN (0 + decimal.pow(12345,4)) inexact rounded', 2.3225e+16, 0 + decimal.pow(12345,4));
	AddTestCase('rpox311:p5 r:HALF_EVEN (0 + decimal.pow(12345,5)) inexact rounded', 2.8672e+20, 0 + decimal.pow(12345,5));
	AddTestCase('rpox312:p5 r:HALF_EVEN (0 + decimal.pow(415,2)) inexact rounded', 1.7222e+5, 0 + decimal.pow(415,2));
	AddTestCase('rpox313:p5 r:HALF_EVEN (0 + decimal.pow(75,3)) inexact rounded', 4.2188e+5, 0 + decimal.pow(75,3));
}
{
	use rounding HALF_UP;
	AddTestCase('rpox401:p5 r:HALF_UP (0 + decimal.pow(12345,-5)) inexact rounded', 3.4877e-21, 0 + decimal.pow(12345,-5));
	AddTestCase('rpox402:p5 r:HALF_UP (0 + decimal.pow(12345,-4)) inexact rounded', 4.3056e-17, 0 + decimal.pow(12345,-4));
	AddTestCase('rpox403:p5 r:HALF_UP (0 + decimal.pow(12345,-3)) inexact rounded', 5.3153e-13, 0 + decimal.pow(12345,-3));
	AddTestCase('rpox404:p5 r:HALF_UP (0 + decimal.pow(12345,-2)) inexact rounded', 6.5617e-9, 0 + decimal.pow(12345,-2));
	AddTestCase('rpox405:p5 r:HALF_UP (0 + decimal.pow(12345,-1)) inexact rounded', 0.000081004, 0 + decimal.pow(12345,-1));
	AddTestCase('rpox406:p5 r:HALF_UP (0 + decimal.pow(12345,0))', 1, 0 + decimal.pow(12345,0));
	AddTestCase('rpox407:p5 r:HALF_UP (0 + decimal.pow(12345,1))', 12345, 0 + decimal.pow(12345,1));
	AddTestCase('rpox408:p5 r:HALF_UP (0 + decimal.pow(12345,2)) inexact rounded', 1.5240e+8, 0 + decimal.pow(12345,2));
	AddTestCase('rpox409:p5 r:HALF_UP (0 + decimal.pow(12345,3)) inexact rounded', 1.8814e+12, 0 + decimal.pow(12345,3));
	AddTestCase('rpox410:p5 r:HALF_UP (0 + decimal.pow(12345,4)) inexact rounded', 2.3225e+16, 0 + decimal.pow(12345,4));
	AddTestCase('rpox411:p5 r:HALF_UP (0 + decimal.pow(12345,5)) inexact rounded', 2.8672e+20, 0 + decimal.pow(12345,5));
	AddTestCase('rpox412:p5 r:HALF_UP (0 + decimal.pow(415,2)) inexact rounded', 1.7223e+5, 0 + decimal.pow(415,2));
	AddTestCase('rpox413:p5 r:HALF_UP (0 + decimal.pow(75,3)) inexact rounded', 4.2188e+5, 0 + decimal.pow(75,3));
}
{
	use rounding FLOOR;
	AddTestCase('rpox601:p5 r:FLOOR (0 + decimal.pow(12345,-5)) inexact rounded', 3.4877e-21, 0 + decimal.pow(12345,-5));
	AddTestCase('rpox602:p5 r:FLOOR (0 + decimal.pow(12345,-4)) inexact rounded', 4.3056e-17, 0 + decimal.pow(12345,-4));
	AddTestCase('rpox603:p5 r:FLOOR (0 + decimal.pow(12345,-3)) inexact rounded', 5.3152e-13, 0 + decimal.pow(12345,-3));
	AddTestCase('rpox604:p5 r:FLOOR (0 + decimal.pow(12345,-2)) inexact rounded', 6.5617e-9, 0 + decimal.pow(12345,-2));
	AddTestCase('rpox605:p5 r:FLOOR (0 + decimal.pow(12345,-1)) inexact rounded', 0.000081004, 0 + decimal.pow(12345,-1));
	AddTestCase('rpox606:p5 r:FLOOR (0 + decimal.pow(12345,0))', 1, 0 + decimal.pow(12345,0));
	AddTestCase('rpox607:p5 r:FLOOR (0 + decimal.pow(12345,1))', 12345, 0 + decimal.pow(12345,1));
	AddTestCase('rpox608:p5 r:FLOOR (0 + decimal.pow(12345,2)) inexact rounded', 1.5239e+8, 0 + decimal.pow(12345,2));
	AddTestCase('rpox609:p5 r:FLOOR (0 + decimal.pow(12345,3)) inexact rounded', 1.8813e+12, 0 + decimal.pow(12345,3));
	AddTestCase('rpox610:p5 r:FLOOR (0 + decimal.pow(12345,4)) inexact rounded', 2.3225e+16, 0 + decimal.pow(12345,4));
	AddTestCase('rpox611:p5 r:FLOOR (0 + decimal.pow(12345,5)) inexact rounded', 2.8671e+20, 0 + decimal.pow(12345,5));
	AddTestCase('rpox612:p5 r:FLOOR (0 + decimal.pow(415,2)) inexact rounded', 1.7222e+5, 0 + decimal.pow(415,2));
	AddTestCase('rpox613:p5 r:FLOOR (0 + decimal.pow(75,3)) inexact rounded', 4.2187e+5, 0 + decimal.pow(75,3));
}
{
	use rounding CEILING;
	AddTestCase('rpox701:p5 r:CEILING (0 + decimal.pow(12345,-5)) inexact rounded', 3.4878e-21, 0 + decimal.pow(12345,-5));
	AddTestCase('rpox702:p5 r:CEILING (0 + decimal.pow(12345,-4)) inexact rounded', 4.3057e-17, 0 + decimal.pow(12345,-4));
	AddTestCase('rpox703:p5 r:CEILING (0 + decimal.pow(12345,-3)) inexact rounded', 5.3153e-13, 0 + decimal.pow(12345,-3));
	AddTestCase('rpox704:p5 r:CEILING (0 + decimal.pow(12345,-2)) inexact rounded', 6.5618e-9, 0 + decimal.pow(12345,-2));
	AddTestCase('rpox705:p5 r:CEILING (0 + decimal.pow(12345,-1)) inexact rounded', 0.000081005, 0 + decimal.pow(12345,-1));
	AddTestCase('rpox706:p5 r:CEILING (0 + decimal.pow(12345,0))', 1, 0 + decimal.pow(12345,0));
	AddTestCase('rpox707:p5 r:CEILING (0 + decimal.pow(12345,1))', 12345, 0 + decimal.pow(12345,1));
	AddTestCase('rpox708:p5 r:CEILING (0 + decimal.pow(12345,2)) inexact rounded', 1.5240e+8, 0 + decimal.pow(12345,2));
	AddTestCase('rpox709:p5 r:CEILING (0 + decimal.pow(12345,3)) inexact rounded', 1.8814e+12, 0 + decimal.pow(12345,3));
	AddTestCase('rpox710:p5 r:CEILING (0 + decimal.pow(12345,4)) inexact rounded', 2.3226e+16, 0 + decimal.pow(12345,4));
	AddTestCase('rpox711:p5 r:CEILING (0 + decimal.pow(12345,5)) inexact rounded', 2.8672e+20, 0 + decimal.pow(12345,5));
	AddTestCase('rpox712:p5 r:CEILING (0 + decimal.pow(415,2)) inexact rounded', 1.7223e+5, 0 + decimal.pow(415,2));
	AddTestCase('rpox713:p5 r:CEILING (0 + decimal.pow(75,3)) inexact rounded', 4.2188e+5, 0 + decimal.pow(75,3));
	// underflow subnormal and overflow values vary with rounding mode and sign
}
{
	use rounding CEILING;
}
{
	use rounding FLOOR;
}
{
	use rounding HALF_UP;
}
{
	use rounding HALF_EVEN;
}
{
	use rounding HALF_DOWN;
	// check maximum finite value over a range of precisions
	{
		use precision 1;
	}
	{
		use precision 2;
	}
	{
		use precision 3;
	}
	{
		use precision 4;
	}
	{
		use precision 5;
	}
	{
		use precision 6;
	}
	{
		use precision 7;
	}
	{
		use precision 8;
	}
	{
		use precision 9;
	}
	{
		use precision 10;
		// reprise rounding mode effect (using multiplies so precision directive used)
	}
	{
		use precision 9;
		{
			use rounding HALF_UP;
		}
		{
			use rounding HALF_DOWN;
		}
		{
			use rounding HALF_EVEN;
		}
		{
			use rounding FLOOR;
		}
		{
			use rounding CEILING;
			//--- round-for-reround -----
			{
				use precision 5;
				// basic rounding; really is just 0 and 5 up
				// addition operators -------------------------------------------------
				// [the first few of these check negative residue possibilities; these
				// cases may be implemented as a negative residue in fastpaths]
				// negatives...
				// check cancellation subtractions
				// (the ieee 854 'curious rule' in $6.3)
				// division operators -------------------------------------------------
				// [divideinteger and remainder unaffected]
				// multiplication operator --------------------------------------------
				// power operator -----------------------------------------------------
				// underflow subnormal and overflow values vary with rounding mode and sign
				// [round down gives nmax on first two and .0e... on the next two]
				// reprise rounding mode effect (using multiplies so precision directive used)
			}
			{
				use precision 9;
				}
			}
		}
	}
}
test();
