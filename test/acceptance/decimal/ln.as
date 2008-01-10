use decimal;
var SECTION = "Decimal";
var VERSION = "ES4";
var TITLE = "ln.decTest";
var BUGNUMBER = "";
startTest();
{
//----------------------------------------------------------------------
// ln.dectest -- decimal natural logarithm                            --
// copyright (c) ibm corporation, 2005, 2007.  all rights reserved.   --
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
use precision 16;
use rounding HALF_EVEN;
// basics (examples in specification)
{
	use precision 9;
	AddTestCase('lnxs001:p9 r:HALF_EVEN (0 + decimal.log(0))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0));
	AddTestCase('lnxs002:p9 r:HALF_EVEN (0 + decimal.log(1.000))', 0, 0 + decimal.log(1.000));
	AddTestCase('lnxs003:p9 r:HALF_EVEN (0 + decimal.log(2.71828183)) inexact rounded', 1.00000000, 0 + decimal.log(2.71828183));
	AddTestCase('lnxs004:p9 r:HALF_EVEN (0 + decimal.log(10)) inexact rounded', 2.30258509, 0 + decimal.log(10));
	AddTestCase('lnxs005:p9 r:HALF_EVEN (0 + decimal.log(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.log(decimal.POSITIVE_INFINITY));
	// basics
}
{
	use precision 16;
	AddTestCase('lnx0001:p16 r:HALF_EVEN (0 + decimal.log(0))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0));
	AddTestCase('lnx0002:p16 r:HALF_EVEN (0 + decimal.log(1e-9)) inexact rounded', -20.72326583694641, 0 + decimal.log(1e-9));
	AddTestCase('lnx0003:p16 r:HALF_EVEN (0 + decimal.log(0.0007)) inexact rounded', -7.264430222920869, 0 + decimal.log(0.0007));
	AddTestCase('lnx0004:p16 r:HALF_EVEN (0 + decimal.log(0.1)) inexact rounded', -2.302585092994046, 0 + decimal.log(0.1));
	AddTestCase('lnx0005:p16 r:HALF_EVEN (0 + decimal.log(0.7)) inexact rounded', -0.3566749439387324, 0 + decimal.log(0.7));
	AddTestCase('lnx0006:p16 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
	AddTestCase('lnx0007:p16 r:HALF_EVEN (0 + decimal.log(1.000))', 0, 0 + decimal.log(1.000));
	AddTestCase('lnx0008:p16 r:HALF_EVEN (0 + decimal.log(1.5)) inexact rounded', 0.4054651081081644, 0 + decimal.log(1.5));
	AddTestCase('lnx0009:p16 r:HALF_EVEN (0 + decimal.log(2)) inexact rounded', 0.6931471805599453, 0 + decimal.log(2));
	AddTestCase('lnx0010:p16 r:HALF_EVEN (0 + decimal.log(2.718281828459045)) inexact rounded', 0.9999999999999999, 0 + decimal.log(2.718281828459045));
	AddTestCase('lnx0011:p16 r:HALF_EVEN (0 + decimal.log(2.718281828459046)) inexact rounded', 1.000000000000000, 0 + decimal.log(2.718281828459046));
	AddTestCase('lnx0012:p16 r:HALF_EVEN (0 + decimal.log(2.718281828459047)) inexact rounded', 1.000000000000001, 0 + decimal.log(2.718281828459047));
	AddTestCase('lnx0013:p16 r:HALF_EVEN (0 + decimal.log(10)) inexact rounded', 2.302585092994046, 0 + decimal.log(10));
	AddTestCase('lnx0014:p16 r:HALF_EVEN (0 + decimal.log(10.5)) inexact rounded', 2.351375257163478, 0 + decimal.log(10.5));
	AddTestCase('lnx0015:p16 r:HALF_EVEN (0 + decimal.log(9999)) inexact rounded', 9.210240366975849, 0 + decimal.log(9999));
	AddTestCase('lnx0016:p16 r:HALF_EVEN (0 + decimal.log(1e6)) inexact rounded', 13.81551055796427, 0 + decimal.log(1e6));
	AddTestCase('lnx0017:p16 r:HALF_EVEN (0 + decimal.log(1e+9)) inexact rounded', 20.72326583694641, 0 + decimal.log(1e+9));
	AddTestCase('lnx0018:p16 r:HALF_EVEN (0 + decimal.log(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.log(decimal.POSITIVE_INFINITY));
	// notable cases
	// negatives
	AddTestCase('lnx0021:p16 r:HALF_EVEN (0 + decimal.log(-1e-9)) invalid_operation', NaN, 0 + decimal.log(-1e-9));
	AddTestCase('lnx0022:p16 r:HALF_EVEN (0 + decimal.log(-0.0007)) invalid_operation', NaN, 0 + decimal.log(-0.0007));
	AddTestCase('lnx0023:p16 r:HALF_EVEN (0 + decimal.log(-0.1)) invalid_operation', NaN, 0 + decimal.log(-0.1));
	AddTestCase('lnx0024:p16 r:HALF_EVEN (0 + decimal.log(-0.7)) invalid_operation', NaN, 0 + decimal.log(-0.7));
	AddTestCase('lnx0025:p16 r:HALF_EVEN (0 + decimal.log(-1)) invalid_operation', NaN, 0 + decimal.log(-1));
	AddTestCase('lnx0026:p16 r:HALF_EVEN (0 + decimal.log(-1.5)) invalid_operation', NaN, 0 + decimal.log(-1.5));
	AddTestCase('lnx0027:p16 r:HALF_EVEN (0 + decimal.log(-2)) invalid_operation', NaN, 0 + decimal.log(-2));
	AddTestCase('lnx0029:p16 r:HALF_EVEN (0 + decimal.log(-10.5)) invalid_operation', NaN, 0 + decimal.log(-10.5));
	AddTestCase('lnx0028:p16 r:HALF_EVEN (0 + decimal.log(-9999)) invalid_operation', NaN, 0 + decimal.log(-9999));
	AddTestCase('lnx0030:p16 r:HALF_EVEN (0 + decimal.log(-2.718281828459045)) invalid_operation', NaN, 0 + decimal.log(-2.718281828459045));
	AddTestCase('lnx0031:p16 r:HALF_EVEN (0 + decimal.log(-2.718281828459046)) invalid_operation', NaN, 0 + decimal.log(-2.718281828459046));
	AddTestCase('lnx0032:p16 r:HALF_EVEN (0 + decimal.log(-0))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(-0));
	AddTestCase('lnx0033:p16 r:HALF_EVEN (0 + decimal.log(-0e+17))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(-0e+17));
	AddTestCase('lnx0034:p16 r:HALF_EVEN (0 + decimal.log(-0e-17))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(-0e-17));
	// other zeros
	AddTestCase('lnx0041:p16 r:HALF_EVEN (0 + decimal.log(0))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0));
	AddTestCase('lnx0042:p16 r:HALF_EVEN (0 + decimal.log(0e+17))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0e+17));
	AddTestCase('lnx0043:p16 r:HALF_EVEN (0 + decimal.log(0e-17))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0e-17));
	// infinities
	AddTestCase('lnx0045:p16 r:HALF_EVEN (0 + decimal.log(decimal.NEGATIVE_INFINITY)) invalid_operation', NaN, 0 + decimal.log(decimal.NEGATIVE_INFINITY));
	AddTestCase('lnx0046:p16 r:HALF_EVEN (0 + decimal.log(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.log(decimal.POSITIVE_INFINITY));
	// ones
	AddTestCase('lnx0050:p16 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
	AddTestCase('lnx0051:p16 r:HALF_EVEN (0 + decimal.log(1.0))', 0, 0 + decimal.log(1.0));
	AddTestCase('lnx0052:p16 r:HALF_EVEN (0 + decimal.log(1.000000000000000))', 0, 0 + decimal.log(1.000000000000000));
	AddTestCase('lnx0053:p16 r:HALF_EVEN (0 + decimal.log(1.000000000000000000))', 0, 0 + decimal.log(1.000000000000000000));
	// lower precision basics
}
{
	use precision 7;
	AddTestCase('lnx0101:p7 r:HALF_EVEN (0 + decimal.log(0))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0));
	AddTestCase('lnx0102:p7 r:HALF_EVEN (0 + decimal.log(1e-9)) inexact rounded', -20.72327, 0 + decimal.log(1e-9));
	AddTestCase('lnx0103:p7 r:HALF_EVEN (0 + decimal.log(0.0007)) inexact rounded', -7.264430, 0 + decimal.log(0.0007));
	AddTestCase('lnx0104:p7 r:HALF_EVEN (0 + decimal.log(0.1)) inexact rounded', -2.302585, 0 + decimal.log(0.1));
	AddTestCase('lnx0105:p7 r:HALF_EVEN (0 + decimal.log(0.7)) inexact rounded', -0.3566749, 0 + decimal.log(0.7));
	AddTestCase('lnx0106:p7 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
	AddTestCase('lnx0107:p7 r:HALF_EVEN (0 + decimal.log(1.5)) inexact rounded', 0.4054651, 0 + decimal.log(1.5));
	AddTestCase('lnx0108:p7 r:HALF_EVEN (0 + decimal.log(2)) inexact rounded', 0.6931472, 0 + decimal.log(2));
	AddTestCase('lnx0109:p7 r:HALF_EVEN (0 + decimal.log(2.718281828459045)) inexact rounded', 1.000000, 0 + decimal.log(2.718281828459045));
	AddTestCase('lnx0110:p7 r:HALF_EVEN (0 + decimal.log(2.718281828459046)) inexact rounded', 1.000000, 0 + decimal.log(2.718281828459046));
	AddTestCase('lnx0111:p7 r:HALF_EVEN (0 + decimal.log(2.718281828459047)) inexact rounded', 1.000000, 0 + decimal.log(2.718281828459047));
	AddTestCase('lnx0112:p7 r:HALF_EVEN (0 + decimal.log(10)) inexact rounded', 2.302585, 0 + decimal.log(10));
	AddTestCase('lnx0113:p7 r:HALF_EVEN (0 + decimal.log(10.5)) inexact rounded', 2.351375, 0 + decimal.log(10.5));
	AddTestCase('lnx0114:p7 r:HALF_EVEN (0 + decimal.log(9999)) inexact rounded', 9.210240, 0 + decimal.log(9999));
	AddTestCase('lnx0115:p7 r:HALF_EVEN (0 + decimal.log(1e6)) inexact rounded', 13.81551, 0 + decimal.log(1e6));
	AddTestCase('lnx0117:p7 r:HALF_EVEN (0 + decimal.log(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.log(decimal.POSITIVE_INFINITY));
}
{
	use precision 2;
	AddTestCase('lnx0121:p2 r:HALF_EVEN (0 + decimal.log(0))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0));
	AddTestCase('lnx0122:p2 r:HALF_EVEN (0 + decimal.log(1e-9)) inexact rounded', -21, 0 + decimal.log(1e-9));
	AddTestCase('lnx0123:p2 r:HALF_EVEN (0 + decimal.log(0.0007)) inexact rounded', -7.3, 0 + decimal.log(0.0007));
	AddTestCase('lnx0124:p2 r:HALF_EVEN (0 + decimal.log(0.1)) inexact rounded', -2.3, 0 + decimal.log(0.1));
	AddTestCase('lnx0125:p2 r:HALF_EVEN (0 + decimal.log(0.7)) inexact rounded', -0.36, 0 + decimal.log(0.7));
	AddTestCase('lnx0126:p2 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
	AddTestCase('lnx0127:p2 r:HALF_EVEN (0 + decimal.log(1.5)) inexact rounded', 0.41, 0 + decimal.log(1.5));
	AddTestCase('lnx0128:p2 r:HALF_EVEN (0 + decimal.log(2)) inexact rounded', 0.69, 0 + decimal.log(2));
	AddTestCase('lnx0129:p2 r:HALF_EVEN (0 + decimal.log(2.718281828459045)) inexact rounded', 1.0, 0 + decimal.log(2.718281828459045));
	AddTestCase('lnx0130:p2 r:HALF_EVEN (0 + decimal.log(2.718281828459046)) inexact rounded', 1.0, 0 + decimal.log(2.718281828459046));
	AddTestCase('lnx0131:p2 r:HALF_EVEN (0 + decimal.log(2.718281828459047)) inexact rounded', 1.0, 0 + decimal.log(2.718281828459047));
	AddTestCase('lnx0132:p2 r:HALF_EVEN (0 + decimal.log(10)) inexact rounded', 2.3, 0 + decimal.log(10));
	AddTestCase('lnx0133:p2 r:HALF_EVEN (0 + decimal.log(10.5)) inexact rounded', 2.4, 0 + decimal.log(10.5));
	AddTestCase('lnx0134:p2 r:HALF_EVEN (0 + decimal.log(9999)) inexact rounded', 9.2, 0 + decimal.log(9999));
	AddTestCase('lnx0135:p2 r:HALF_EVEN (0 + decimal.log(1e6)) inexact rounded', 14, 0 + decimal.log(1e6));
	AddTestCase('lnx0136:p2 r:HALF_EVEN (0 + decimal.log(1e+9)) inexact rounded', 21, 0 + decimal.log(1e+9));
	AddTestCase('lnx0137:p2 r:HALF_EVEN (0 + decimal.log(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.log(decimal.POSITIVE_INFINITY));
}
{
	use precision 1;
	AddTestCase('lnx0141:p1 r:HALF_EVEN (0 + decimal.log(0))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0));
	AddTestCase('lnx0142:p1 r:HALF_EVEN (0 + decimal.log(1e-9)) inexact rounded', -2e+1, 0 + decimal.log(1e-9));
	AddTestCase('lnx0143:p1 r:HALF_EVEN (0 + decimal.log(0.0007)) inexact rounded', -7, 0 + decimal.log(0.0007));
	AddTestCase('lnx0144:p1 r:HALF_EVEN (0 + decimal.log(0.1)) inexact rounded', -2, 0 + decimal.log(0.1));
	AddTestCase('lnx0145:p1 r:HALF_EVEN (0 + decimal.log(0.7)) inexact rounded', -0.4, 0 + decimal.log(0.7));
	AddTestCase('lnx0146:p1 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
	AddTestCase('lnx0147:p1 r:HALF_EVEN (0 + decimal.log(1.5)) inexact rounded', 0.4, 0 + decimal.log(1.5));
	AddTestCase('lnx0148:p1 r:HALF_EVEN (0 + decimal.log(2)) inexact rounded', 0.7, 0 + decimal.log(2));
	AddTestCase('lnx0149:p1 r:HALF_EVEN (0 + decimal.log(2.718281828459045)) inexact rounded', 1, 0 + decimal.log(2.718281828459045));
	AddTestCase('lnx0150:p1 r:HALF_EVEN (0 + decimal.log(2.718281828459046)) inexact rounded', 1, 0 + decimal.log(2.718281828459046));
	AddTestCase('lnx0151:p1 r:HALF_EVEN (0 + decimal.log(2.718281828459047)) inexact rounded', 1, 0 + decimal.log(2.718281828459047));
	AddTestCase('lnx0152:p1 r:HALF_EVEN (0 + decimal.log(10)) inexact rounded', 2, 0 + decimal.log(10));
	AddTestCase('lnx0153:p1 r:HALF_EVEN (0 + decimal.log(10.5)) inexact rounded', 2, 0 + decimal.log(10.5));
	AddTestCase('lnx0154:p1 r:HALF_EVEN (0 + decimal.log(9999)) inexact rounded', 9, 0 + decimal.log(9999));
	AddTestCase('lnx0155:p1 r:HALF_EVEN (0 + decimal.log(1e6)) inexact rounded', 1e+1, 0 + decimal.log(1e6));
	AddTestCase('lnx0156:p1 r:HALF_EVEN (0 + decimal.log(1e+9)) inexact rounded', 2e+1, 0 + decimal.log(1e+9));
	AddTestCase('lnx0157:p1 r:HALF_EVEN (0 + decimal.log(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.log(decimal.POSITIVE_INFINITY));
	// group low-precision ln(1)s:
}
{
	use precision 1;
	AddTestCase('lnx0161:p1 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
}
{
	use precision 2;
	AddTestCase('lnx0162:p2 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
}
{
	use precision 3;
	AddTestCase('lnx0163:p3 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
}
{
	use precision 4;
	AddTestCase('lnx0164:p4 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
}
{
	use precision 5;
	AddTestCase('lnx0165:p5 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
}
{
	use precision 6;
	AddTestCase('lnx0166:p6 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
}
{
	use precision 7;
	AddTestCase('lnx0167:p7 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
}
{
	use precision 8;
	AddTestCase('lnx0168:p8 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
	// edge-test ln(2) and ln(10) in case of lookasides
}
{
	use precision 33;
	AddTestCase('lnx225:p33 r:HALF_EVEN (0 + decimal.log(2)) inexact rounded', 0.693147180559945309417232121458177, 0 + decimal.log(2));
	AddTestCase('lnx226:p33 r:HALF_EVEN (0 + decimal.log(10)) inexact rounded', 2.30258509299404568401799145468436, 0 + decimal.log(10));
}
{
	use precision 32;
	AddTestCase('lnx227:p32 r:HALF_EVEN (0 + decimal.log(2)) inexact rounded', 0.69314718055994530941723212145818, 0 + decimal.log(2));
	AddTestCase('lnx228:p32 r:HALF_EVEN (0 + decimal.log(10)) inexact rounded', 2.3025850929940456840179914546844, 0 + decimal.log(10));
}
{
	use precision 31;
	AddTestCase('lnx229:p31 r:HALF_EVEN (0 + decimal.log(2)) inexact rounded', 0.6931471805599453094172321214582, 0 + decimal.log(2));
	AddTestCase('lnx230:p31 r:HALF_EVEN (0 + decimal.log(10)) inexact rounded', 2.302585092994045684017991454684, 0 + decimal.log(10));
}
{
	use precision 30;
	AddTestCase('lnx231:p30 r:HALF_EVEN (0 + decimal.log(2)) inexact rounded', 0.693147180559945309417232121458, 0 + decimal.log(2));
	AddTestCase('lnx232:p30 r:HALF_EVEN (0 + decimal.log(10)) inexact rounded', 2.30258509299404568401799145468, 0 + decimal.log(10));
	// extreme input range values
}
{
	use precision 16;
	AddTestCase('lnx0901:p16 r:HALF_EVEN (0 + decimal.log(1e-400)) inexact rounded', -921.0340371976183, 0 + decimal.log(1e-400));
	AddTestCase('lnx0902:p16 r:HALF_EVEN (0 + decimal.log(1e+400)) inexact rounded', 921.0340371976183, 0 + decimal.log(1e+400));
	AddTestCase('lnx0903:p16 r:HALF_EVEN (0 + decimal.log(1e-999999)) inexact rounded', -Infinity, 0 + decimal.log(1e-999999));
	AddTestCase('lnx0904:p16 r:HALF_EVEN (0 + decimal.log(1e+999999)) inexact rounded', Infinity, 0 + decimal.log(1e+999999));
	// randoms
	// p=50, within 0-999
	// p=34, within 0-999
	// p=16, within 0-99
}
{
	use precision 16;
	AddTestCase('lnx1101:p16 r:HALF_EVEN (0 + decimal.log(7.964875261033948)) inexact rounded', 2.075041282352241, 0 + decimal.log(7.964875261033948));
	AddTestCase('lnx1102:p16 r:HALF_EVEN (0 + decimal.log(13.54527396845394)) inexact rounded', 2.606037701870263, 0 + decimal.log(13.54527396845394));
	AddTestCase('lnx1103:p16 r:HALF_EVEN (0 + decimal.log(0.0008026554341331)) inexact rounded', -7.127585034321814, 0 + decimal.log(0.0008026554341331));
	AddTestCase('lnx1104:p16 r:HALF_EVEN (0 + decimal.log(0.0000030582233261)) inexact rounded', -12.69767642300625, 0 + decimal.log(0.0000030582233261));
	AddTestCase('lnx1105:p16 r:HALF_EVEN (0 + decimal.log(0.0004477497509672)) inexact rounded', -7.711276073210766, 0 + decimal.log(0.0004477497509672));
	AddTestCase('lnx1106:p16 r:HALF_EVEN (0 + decimal.log(7.616268622474371)) inexact rounded', 2.030286567675148, 0 + decimal.log(7.616268622474371));
	AddTestCase('lnx1107:p16 r:HALF_EVEN (0 + decimal.log(51.58329925806381)) inexact rounded', 3.943197962309569, 0 + decimal.log(51.58329925806381));
	AddTestCase('lnx1108:p16 r:HALF_EVEN (0 + decimal.log(0.0018197497951263)) inexact rounded', -6.309056262549345, 0 + decimal.log(0.0018197497951263));
	AddTestCase('lnx1109:p16 r:HALF_EVEN (0 + decimal.log(2.956282457072984)) inexact rounded', 1.083932552334575, 0 + decimal.log(2.956282457072984));
	AddTestCase('lnx1110:p16 r:HALF_EVEN (0 + decimal.log(0.3843325579189906)) inexact rounded', -0.9562470649400558, 0 + decimal.log(0.3843325579189906));
	AddTestCase('lnx1111:p16 r:HALF_EVEN (0 + decimal.log(0.0074466329265663)) inexact rounded', -4.899993304919237, 0 + decimal.log(0.0074466329265663));
	AddTestCase('lnx1112:p16 r:HALF_EVEN (0 + decimal.log(0.0003372478532993)) inexact rounded', -7.994692428206378, 0 + decimal.log(0.0003372478532993));
	AddTestCase('lnx1113:p16 r:HALF_EVEN (0 + decimal.log(0.0084792263167809)) inexact rounded', -4.770136069569271, 0 + decimal.log(0.0084792263167809));
	AddTestCase('lnx1114:p16 r:HALF_EVEN (0 + decimal.log(5.926756998151102)) inexact rounded', 1.779477182834305, 0 + decimal.log(5.926756998151102));
	AddTestCase('lnx1115:p16 r:HALF_EVEN (0 + decimal.log(9.025699152180897)) inexact rounded', 2.200075969604119, 0 + decimal.log(9.025699152180897));
	AddTestCase('lnx1116:p16 r:HALF_EVEN (0 + decimal.log(1.910124643533526)) inexact rounded', 0.6471684983238183, 0 + decimal.log(1.910124643533526));
	AddTestCase('lnx1117:p16 r:HALF_EVEN (0 + decimal.log(0.8158922711411020)) inexact rounded', -0.2034729533939387, 0 + decimal.log(0.8158922711411020));
	AddTestCase('lnx1118:p16 r:HALF_EVEN (0 + decimal.log(0.0067080016475322)) inexact rounded', -5.004454189414139, 0 + decimal.log(0.0067080016475322));
	AddTestCase('lnx1119:p16 r:HALF_EVEN (0 + decimal.log(0.0047583242092716)) inexact rounded', -5.347859729601094, 0 + decimal.log(0.0047583242092716));
	AddTestCase('lnx1120:p16 r:HALF_EVEN (0 + decimal.log(0.0386647411641339)) inexact rounded', -3.252827175263113, 0 + decimal.log(0.0386647411641339));
	AddTestCase('lnx1121:p16 r:HALF_EVEN (0 + decimal.log(0.0050226427841761)) inexact rounded', -5.293799032774131, 0 + decimal.log(0.0050226427841761));
	AddTestCase('lnx1122:p16 r:HALF_EVEN (0 + decimal.log(6.927937541637261)) inexact rounded', 1.935562155866906, 0 + decimal.log(6.927937541637261));
	AddTestCase('lnx1123:p16 r:HALF_EVEN (0 + decimal.log(0.0000095745343513)) inexact rounded', -11.55640365579814, 0 + decimal.log(0.0000095745343513));
	AddTestCase('lnx1124:p16 r:HALF_EVEN (0 + decimal.log(1.602465492956538)) inexact rounded', 0.4715433763243936, 0 + decimal.log(1.602465492956538));
	AddTestCase('lnx1125:p16 r:HALF_EVEN (0 + decimal.log(38.98415625087535)) inexact rounded', 3.663155313610213, 0 + decimal.log(38.98415625087535));
	AddTestCase('lnx1126:p16 r:HALF_EVEN (0 + decimal.log(5.343182042276734)) inexact rounded', 1.675821363568112, 0 + decimal.log(5.343182042276734));
	AddTestCase('lnx1127:p16 r:HALF_EVEN (0 + decimal.log(55.89763703245816)) inexact rounded', 4.023522107934110, 0 + decimal.log(55.89763703245816));
	AddTestCase('lnx1128:p16 r:HALF_EVEN (0 + decimal.log(0.7445257810280847)) inexact rounded', -0.2950077988101030, 0 + decimal.log(0.7445257810280847));
	AddTestCase('lnx1129:p16 r:HALF_EVEN (0 + decimal.log(1.631407314946094)) inexact rounded', 0.4894430257201248, 0 + decimal.log(1.631407314946094));
	AddTestCase('lnx1130:p16 r:HALF_EVEN (0 + decimal.log(0.0005462451932602)) inexact rounded', -7.512442611116852, 0 + decimal.log(0.0005462451932602));
	AddTestCase('lnx1131:p16 r:HALF_EVEN (0 + decimal.log(0.0000864173269362)) inexact rounded', -9.356322359017317, 0 + decimal.log(0.0000864173269362));
	AddTestCase('lnx1132:p16 r:HALF_EVEN (0 + decimal.log(5.227161719132849)) inexact rounded', 1.653868438439637, 0 + decimal.log(5.227161719132849));
	AddTestCase('lnx1133:p16 r:HALF_EVEN (0 + decimal.log(60.57078466941998)) inexact rounded', 4.103812675662452, 0 + decimal.log(60.57078466941998));
	AddTestCase('lnx1134:p16 r:HALF_EVEN (0 + decimal.log(0.0992864325333160)) inexact rounded', -2.309746348350318, 0 + decimal.log(0.0992864325333160));
	AddTestCase('lnx1135:p16 r:HALF_EVEN (0 + decimal.log(09.48564268447325)) inexact rounded', 2.249779359074983, 0 + decimal.log(09.48564268447325));
	AddTestCase('lnx1136:p16 r:HALF_EVEN (0 + decimal.log(0.0036106089355634)) inexact rounded', -5.623878840650787, 0 + decimal.log(0.0036106089355634));
	AddTestCase('lnx1137:p16 r:HALF_EVEN (0 + decimal.log(1.805176865587172)) inexact rounded', 0.5906585734593707, 0 + decimal.log(1.805176865587172));
	AddTestCase('lnx1138:p16 r:HALF_EVEN (0 + decimal.log(62.59363259642255)) inexact rounded', 4.136663557220559, 0 + decimal.log(62.59363259642255));
	AddTestCase('lnx1139:p16 r:HALF_EVEN (0 + decimal.log(4.373828261137201)) inexact rounded', 1.475638657912000, 0 + decimal.log(4.373828261137201));
	AddTestCase('lnx1140:p16 r:HALF_EVEN (0 + decimal.log(0.994483524148738)) inexact rounded', -0.005531747794938690, 0 + decimal.log(0.994483524148738));
	// p=7, within 0-9
}
{
	use precision 7;
	AddTestCase('lnx1001:p7 r:HALF_EVEN (0 + decimal.log(0.0912025)) inexact rounded', -2.394673, 0 + decimal.log(0.0912025));
	AddTestCase('lnx1002:p7 r:HALF_EVEN (0 + decimal.log(0.9728626)) inexact rounded', -0.02751242, 0 + decimal.log(0.9728626));
	AddTestCase('lnx1003:p7 r:HALF_EVEN (0 + decimal.log(0.3886032)) inexact rounded', -0.9451965, 0 + decimal.log(0.3886032));
	AddTestCase('lnx1004:p7 r:HALF_EVEN (0 + decimal.log(8.798639)) inexact rounded', 2.174597, 0 + decimal.log(8.798639));
	AddTestCase('lnx1005:p7 r:HALF_EVEN (0 + decimal.log(2.459121)) inexact rounded', 0.8998040, 0 + decimal.log(2.459121));
	AddTestCase('lnx1006:p7 r:HALF_EVEN (0 + decimal.log(2.013193)) inexact rounded', 0.6997220, 0 + decimal.log(2.013193));
	AddTestCase('lnx1007:p7 r:HALF_EVEN (0 + decimal.log(9.064857)) inexact rounded', 2.204405, 0 + decimal.log(9.064857));
	AddTestCase('lnx1008:p7 r:HALF_EVEN (0 + decimal.log(5.796417)) inexact rounded', 1.757240, 0 + decimal.log(5.796417));
	AddTestCase('lnx1009:p7 r:HALF_EVEN (0 + decimal.log(0.1143471)) inexact rounded', -2.168517, 0 + decimal.log(0.1143471));
	AddTestCase('lnx1010:p7 r:HALF_EVEN (0 + decimal.log(0.5341542)) inexact rounded', -0.6270707, 0 + decimal.log(0.5341542));
	AddTestCase('lnx1011:p7 r:HALF_EVEN (0 + decimal.log(6.693781)) inexact rounded', 1.901179, 0 + decimal.log(6.693781));
	AddTestCase('lnx1012:p7 r:HALF_EVEN (0 + decimal.log(0.0081779)) inexact rounded', -4.806320, 0 + decimal.log(0.0081779));
	AddTestCase('lnx1013:p7 r:HALF_EVEN (0 + decimal.log(8.313616)) inexact rounded', 2.117895, 0 + decimal.log(8.313616));
	AddTestCase('lnx1014:p7 r:HALF_EVEN (0 + decimal.log(3.486925)) inexact rounded', 1.249020, 0 + decimal.log(3.486925));
	AddTestCase('lnx1015:p7 r:HALF_EVEN (0 + decimal.log(0.1801401)) inexact rounded', -1.714020, 0 + decimal.log(0.1801401));
	AddTestCase('lnx1016:p7 r:HALF_EVEN (0 + decimal.log(0.5227148)) inexact rounded', -0.6487193, 0 + decimal.log(0.5227148));
	AddTestCase('lnx1017:p7 r:HALF_EVEN (0 + decimal.log(7.818111)) inexact rounded', 2.056443, 0 + decimal.log(7.818111));
	AddTestCase('lnx1018:p7 r:HALF_EVEN (0 + decimal.log(0.0870671)) inexact rounded', -2.441076, 0 + decimal.log(0.0870671));
	AddTestCase('lnx1019:p7 r:HALF_EVEN (0 + decimal.log(8.153966)) inexact rounded', 2.098504, 0 + decimal.log(8.153966));
	AddTestCase('lnx1020:p7 r:HALF_EVEN (0 + decimal.log(2.040975)) inexact rounded', 0.7134276, 0 + decimal.log(2.040975));
	AddTestCase('lnx1021:p7 r:HALF_EVEN (0 + decimal.log(1.481642)) inexact rounded', 0.3931509, 0 + decimal.log(1.481642));
	AddTestCase('lnx1022:p7 r:HALF_EVEN (0 + decimal.log(0.2610123)) inexact rounded', -1.343188, 0 + decimal.log(0.2610123));
	AddTestCase('lnx1023:p7 r:HALF_EVEN (0 + decimal.log(0.466723)) inexact rounded', -0.7620193, 0 + decimal.log(0.466723));
	AddTestCase('lnx1024:p7 r:HALF_EVEN (0 + decimal.log(0.0518756)) inexact rounded', -2.958907, 0 + decimal.log(0.0518756));
	AddTestCase('lnx1025:p7 r:HALF_EVEN (0 + decimal.log(2.056410)) inexact rounded', 0.7209617, 0 + decimal.log(2.056410));
	AddTestCase('lnx1026:p7 r:HALF_EVEN (0 + decimal.log(0.181522)) inexact rounded', -1.706378, 0 + decimal.log(0.181522));
	AddTestCase('lnx1027:p7 r:HALF_EVEN (0 + decimal.log(0.515551)) inexact rounded', -0.6625190, 0 + decimal.log(0.515551));
	AddTestCase('lnx1028:p7 r:HALF_EVEN (0 + decimal.log(8.425089)) inexact rounded', 2.131214, 0 + decimal.log(8.425089));
	AddTestCase('lnx1029:p7 r:HALF_EVEN (0 + decimal.log(2.077091)) inexact rounded', 0.7309684, 0 + decimal.log(2.077091));
	AddTestCase('lnx1030:p7 r:HALF_EVEN (0 + decimal.log(6.212705)) inexact rounded', 1.826596, 0 + decimal.log(6.212705));
	AddTestCase('lnx1031:p7 r:HALF_EVEN (0 + decimal.log(5.729343)) inexact rounded', 1.745601, 0 + decimal.log(5.729343));
	AddTestCase('lnx1032:p7 r:HALF_EVEN (0 + decimal.log(4.831251)) inexact rounded', 1.575105, 0 + decimal.log(4.831251));
	AddTestCase('lnx1033:p7 r:HALF_EVEN (0 + decimal.log(2.029760)) inexact rounded', 0.7079176, 0 + decimal.log(2.029760));
	AddTestCase('lnx1034:p7 r:HALF_EVEN (0 + decimal.log(8.615060)) inexact rounded', 2.153512, 0 + decimal.log(8.615060));
	AddTestCase('lnx1035:p7 r:HALF_EVEN (0 + decimal.log(0.0611511)) inexact rounded', -2.794407, 0 + decimal.log(0.0611511));
	AddTestCase('lnx1036:p7 r:HALF_EVEN (0 + decimal.log(5.195269)) inexact rounded', 1.647748, 0 + decimal.log(5.195269));
	AddTestCase('lnx1037:p7 r:HALF_EVEN (0 + decimal.log(9.617686)) inexact rounded', 2.263604, 0 + decimal.log(9.617686));
	AddTestCase('lnx1038:p7 r:HALF_EVEN (0 + decimal.log(0.0049382)) inexact rounded', -5.310754, 0 + decimal.log(0.0049382));
	AddTestCase('lnx1039:p7 r:HALF_EVEN (0 + decimal.log(2.786840)) inexact rounded', 1.024908, 0 + decimal.log(2.786840));
	AddTestCase('lnx1040:p7 r:HALF_EVEN (0 + decimal.log(0.0091073)) inexact rounded', -4.698679, 0 + decimal.log(0.0091073));
	// from here 3-digit tests are based on reverse exp tests
}
{
	use precision 9;
	{
		use rounding HALF_EVEN;
		AddTestCase('lnx001:p9 r:HALF_EVEN (0 + decimal.log(0))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0));
		AddTestCase('lnx002:p9 r:HALF_EVEN (0 + decimal.log(0.367879441)) inexact rounded', -1.00000000, 0 + decimal.log(0.367879441));
		AddTestCase('lnx003:p9 r:HALF_EVEN (0 + decimal.log(1))', 0, 0 + decimal.log(1));
		AddTestCase('lnx005:p9 r:HALF_EVEN (0 + decimal.log(2.71828183)) inexact rounded', 1.00000000, 0 + decimal.log(2.71828183));
		AddTestCase('lnx006:p9 r:HALF_EVEN (0 + decimal.log(2.00000000)) inexact rounded', 0.693147181, 0 + decimal.log(2.00000000));
		AddTestCase('lnx007:p9 r:HALF_EVEN (0 + decimal.log(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.log(decimal.POSITIVE_INFINITY));
		// tiny edge cases
		{
			use precision 7;
			AddTestCase('lnx011:p7 r:HALF_EVEN (0 + decimal.log(1.105171)) inexact rounded', 0.1000001, 0 + decimal.log(1.105171));
			AddTestCase('lnx012:p7 r:HALF_EVEN (0 + decimal.log(1.010050)) inexact rounded', 0.009999835, 0 + decimal.log(1.010050));
			AddTestCase('lnx013:p7 r:HALF_EVEN (0 + decimal.log(1.000010)) inexact rounded', 0.000009999950, 0 + decimal.log(1.000010));
			AddTestCase('lnx014:p7 r:HALF_EVEN (0 + decimal.log(1.000001)) inexact rounded', 9.999995e-7, 0 + decimal.log(1.000001));
			AddTestCase('lnx015:p7 r:HALF_EVEN (0 + decimal.log(1.000000))', 0, 0 + decimal.log(1.000000));
			// basic e=0, e=1, e=2, e=4, e>=8 cases
		}
		{
			use precision 7;
			AddTestCase('lnx041:p7 r:HALF_EVEN (0 + decimal.log(2.718282)) inexact rounded', 1.000000, 0 + decimal.log(2.718282));
			AddTestCase('lnx042:p7 r:HALF_EVEN (0 + decimal.log(0.3678794)) inexact rounded', -1.000000, 0 + decimal.log(0.3678794));
			AddTestCase('lnx043:p7 r:HALF_EVEN (0 + decimal.log(22026.47)) inexact rounded', 10.00000, 0 + decimal.log(22026.47));
			AddTestCase('lnx044:p7 r:HALF_EVEN (0 + decimal.log(0.00004539993)) inexact rounded', -10.00000, 0 + decimal.log(0.00004539993));
			AddTestCase('lnx045:p7 r:HALF_EVEN (0 + decimal.log(2.688117e+43)) inexact rounded', 100.0000, 0 + decimal.log(2.688117e+43));
			AddTestCase('lnx046:p7 r:HALF_EVEN (0 + decimal.log(3.720076e-44)) inexact rounded', -100.0000, 0 + decimal.log(3.720076e-44));
			AddTestCase('lnx047:p7 r:HALF_EVEN (0 + decimal.log(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.log(decimal.POSITIVE_INFINITY));
			AddTestCase('lnx048:p7 r:HALF_EVEN (0 + decimal.log(0e-389))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0e-389));
			// miscellanea
		}
		{
			use precision 16;
			AddTestCase('lnx055:p16 r:HALF_EVEN (0 + decimal.log(2.717658486884572e-236)) inexact rounded', -542.4103112874415, 0 + decimal.log(2.717658486884572e-236));
		}
		{
			use precision 17;
			AddTestCase('lnx056:p17 r:HALF_EVEN (0 + decimal.log(2.7176584868845721e-236)) inexact rounded', -542.41031128744146, 0 + decimal.log(2.7176584868845721e-236));
		}
		{
			use precision 18;
			AddTestCase('lnx057:p18 r:HALF_EVEN (0 + decimal.log(2.71765848688457211e-236)) inexact rounded', -542.410311287441459, 0 + decimal.log(2.71765848688457211e-236));
		}
		{
			use precision 19;
			AddTestCase('lnx058:p19 r:HALF_EVEN (0 + decimal.log(2.717658486884572112e-236)) inexact rounded', -542.4103112874414592, 0 + decimal.log(2.717658486884572112e-236));
		}
		{
			use precision 20;
			AddTestCase('lnx059:p20 r:HALF_EVEN (0 + decimal.log(2.7176584868845721118e-236)) inexact rounded', -542.41031128744145917, 0 + decimal.log(2.7176584868845721118e-236));
			// inputs ending in ..500.., ..499.., ..100.., ..999.. sequences
		}
		{
			use precision 30;
			AddTestCase('lnx103:p30 r:HALF_EVEN (0 + decimal.log(0.999999910000004049999878500003)) inexact rounded', -8.99999999999999999999997337499e-8, 0 + decimal.log(0.999999910000004049999878500003));
		}
		{
			use precision 29;
			AddTestCase('lnx104:p29 r:HALF_EVEN (0 + decimal.log(0.99999991000000404999987850000)) inexact rounded', -9.0000000000000000000002733750e-8, 0 + decimal.log(0.99999991000000404999987850000));
		}
		{
			use precision 28;
			AddTestCase('lnx105:p28 r:HALF_EVEN (0 + decimal.log(0.9999999100000040499998785000)) inexact rounded', -9.000000000000000000000273375e-8, 0 + decimal.log(0.9999999100000040499998785000));
		}
		{
			use precision 27;
			AddTestCase('lnx106:p27 r:HALF_EVEN (0 + decimal.log(0.999999910000004049999878500)) inexact rounded', -9.00000000000000000000027338e-8, 0 + decimal.log(0.999999910000004049999878500));
		}
		{
			use precision 26;
			AddTestCase('lnx107:p26 r:HALF_EVEN (0 + decimal.log(0.99999991000000404999987850)) inexact rounded', -9.0000000000000000000002734e-8, 0 + decimal.log(0.99999991000000404999987850));
		}
		{
			use precision 25;
			AddTestCase('lnx108:p25 r:HALF_EVEN (0 + decimal.log(0.9999999100000040499998785)) inexact rounded', -9.000000000000000000000273e-8, 0 + decimal.log(0.9999999100000040499998785));
		}
		{
			use precision 24;
			AddTestCase('lnx109:p24 r:HALF_EVEN (0 + decimal.log(0.999999910000004049999879)) inexact rounded', -8.99999999999999995000027e-8, 0 + decimal.log(0.999999910000004049999879));
		}
		{
			use precision 23;
			AddTestCase('lnx110:p23 r:HALF_EVEN (0 + decimal.log(0.99999991000000404999988)) inexact rounded', -8.9999999999999998500003e-8, 0 + decimal.log(0.99999991000000404999988));
		}
		{
			use precision 22;
			AddTestCase('lnx111:p22 r:HALF_EVEN (0 + decimal.log(0.9999999100000040499999)) inexact rounded', -8.999999999999997850000e-8, 0 + decimal.log(0.9999999100000040499999));
		}
		{
			use precision 21;
			AddTestCase('lnx112:p21 r:HALF_EVEN (0 + decimal.log(0.999999910000004050000)) inexact rounded', -8.99999999999998785000e-8, 0 + decimal.log(0.999999910000004050000));
		}
		{
			use precision 20;
			AddTestCase('lnx113:p20 r:HALF_EVEN (0 + decimal.log(0.99999991000000405000)) inexact rounded', -8.9999999999999878500e-8, 0 + decimal.log(0.99999991000000405000));
		}
		{
			use precision 19;
			AddTestCase('lnx114:p19 r:HALF_EVEN (0 + decimal.log(0.9999999100000040500)) inexact rounded', -8.999999999999987850e-8, 0 + decimal.log(0.9999999100000040500));
		}
		{
			use precision 18;
			AddTestCase('lnx115:p18 r:HALF_EVEN (0 + decimal.log(0.999999910000004050)) inexact rounded', -8.99999999999998785e-8, 0 + decimal.log(0.999999910000004050));
			// next is a > 0.5ulp case
		}
        /*
		{
			use precision 17;
			AddTestCase('lnx116:p17 r:HALF_EVEN (0 + decimal.log(0.99999991000000405)) inexact rounded', -8.9999999999999879e-8, 0 + decimal.log(0.99999991000000405));
		}
        */
		{
			use precision 16;
			AddTestCase('lnx117:p16 r:HALF_EVEN (0 + decimal.log(0.9999999100000040)) inexact rounded', -9.000000004999988e-8, 0 + decimal.log(0.9999999100000040));
		}
		{
			use precision 15;
			AddTestCase('lnx118:p15 r:HALF_EVEN (0 + decimal.log(0.999999910000004)) inexact rounded', -9.00000000499999e-8, 0 + decimal.log(0.999999910000004));
		}
		{
			use precision 14;
			AddTestCase('lnx119:p14 r:HALF_EVEN (0 + decimal.log(0.99999991000000)) inexact rounded', -9.0000004050000e-8, 0 + decimal.log(0.99999991000000));
		}
		{
			use precision 13;
			AddTestCase('lnx120:p13 r:HALF_EVEN (0 + decimal.log(0.9999999100000)) inexact rounded', -9.000000405000e-8, 0 + decimal.log(0.9999999100000));
		}
		{
			use precision 12;
			AddTestCase('lnx121:p12 r:HALF_EVEN (0 + decimal.log(0.999999910000)) inexact rounded', -9.00000040500e-8, 0 + decimal.log(0.999999910000));
		}
		{
			use precision 11;
			AddTestCase('lnx122:p11 r:HALF_EVEN (0 + decimal.log(0.99999991000)) inexact rounded', -9.0000004050e-8, 0 + decimal.log(0.99999991000));
		}
		{
			use precision 10;
			AddTestCase('lnx123:p10 r:HALF_EVEN (0 + decimal.log(0.9999999100)) inexact rounded', -9.000000405e-8, 0 + decimal.log(0.9999999100));
		}
		{
			use precision 9;
			AddTestCase('lnx124:p9 r:HALF_EVEN (0 + decimal.log(0.999999910)) inexact rounded', -9.00000041e-8, 0 + decimal.log(0.999999910));
		}
		{
			use precision 8;
			AddTestCase('lnx125:p8 r:HALF_EVEN (0 + decimal.log(0.99999991)) inexact rounded', -9.0000004e-8, 0 + decimal.log(0.99999991));
		}
		{
			use precision 7;
			AddTestCase('lnx126:p7 r:HALF_EVEN (0 + decimal.log(0.9999999)) inexact rounded', -1.000000e-7, 0 + decimal.log(0.9999999));
		}
		{
			use precision 16;
			AddTestCase('lnx126b:p16 r:HALF_EVEN (0 + decimal.log(0.9999999)) inexact rounded', -1.000000050000003e-7, 0 + decimal.log(0.9999999));
		}
		{
			use precision 6;
			AddTestCase('lnx127:p6 r:HALF_EVEN (0 + decimal.log(0.999999)) inexact rounded', -0.00000100000, 0 + decimal.log(0.999999));
		}
		{
			use precision 5;
			AddTestCase('lnx128:p5 r:HALF_EVEN (0 + decimal.log(0.99999)) inexact rounded', -0.000010000, 0 + decimal.log(0.99999));
		}
		{
			use precision 4;
			AddTestCase('lnx129:p4 r:HALF_EVEN (0 + decimal.log(0.9999)) inexact rounded', -0.0001000, 0 + decimal.log(0.9999));
		}
		{
			use precision 3;
			AddTestCase('lnx130:p3 r:HALF_EVEN (0 + decimal.log(0.999)) inexact rounded', -0.00100, 0 + decimal.log(0.999));
		}
		{
			use precision 2;
			AddTestCase('lnx131:p2 r:HALF_EVEN (0 + decimal.log(0.99)) inexact rounded', -0.010, 0 + decimal.log(0.99));
		}
		{
			use precision 1;
			AddTestCase('lnx132:p1 r:HALF_EVEN (0 + decimal.log(0.9)) inexact rounded', -0.1, 0 + decimal.log(0.9));
			// cases near 1              --  1 2345678901234567890
		}
		{
			use precision 20;
			AddTestCase('lnx401:p20 r:HALF_EVEN (0 + decimal.log(2.7182818284589365041)) inexact rounded', 0.99999999999996000000, 0 + decimal.log(2.7182818284589365041));
			AddTestCase('lnx402:p20 r:HALF_EVEN (0 + decimal.log(2.7182818284589636869)) inexact rounded', 0.99999999999997000000, 0 + decimal.log(2.7182818284589636869));
			AddTestCase('lnx403:p20 r:HALF_EVEN (0 + decimal.log(2.7182818284589908697)) inexact rounded', 0.99999999999997999999, 0 + decimal.log(2.7182818284589908697));
			AddTestCase('lnx404:p20 r:HALF_EVEN (0 + decimal.log(2.7182818284590180525)) inexact rounded', 0.99999999999998999998, 0 + decimal.log(2.7182818284590180525));
			AddTestCase('lnx405:p20 r:HALF_EVEN (0 + decimal.log(2.7182818284590452354)) inexact rounded', 1.0000000000000000000, 0 + decimal.log(2.7182818284590452354));
			AddTestCase('lnx406:p20 r:HALF_EVEN (0 + decimal.log(2.7182818284593170635)) inexact rounded', 1.0000000000001000000, 0 + decimal.log(2.7182818284593170635));
			AddTestCase('lnx407:p20 r:HALF_EVEN (0 + decimal.log(2.7182818284595888917)) inexact rounded', 1.0000000000002000000, 0 + decimal.log(2.7182818284595888917));
		}
		{
			use precision 14;
			AddTestCase('lnx411:p14 r:HALF_EVEN (0 + decimal.log(2.7182818284589)) inexact rounded', 0.99999999999995, 0 + decimal.log(2.7182818284589));
			AddTestCase('lnx413:p14 r:HALF_EVEN (0 + decimal.log(2.7182818284590)) inexact rounded', 0.99999999999998, 0 + decimal.log(2.7182818284590));
			AddTestCase('lnx416:p14 r:HALF_EVEN (0 + decimal.log(2.7182818284591)) inexact rounded', 1.0000000000000, 0 + decimal.log(2.7182818284591));
			AddTestCase('lnx417:p14 r:HALF_EVEN (0 + decimal.log(2.7182818284592)) inexact rounded', 1.0000000000001, 0 + decimal.log(2.7182818284592));
			// overflows, including some exp overprecise borderlines
		}
		{
			use precision 7;
			AddTestCase('lnx709:p7 r:HALF_EVEN (0 + decimal.log(9.999999e+384)) inexact rounded', 886.4953, 0 + decimal.log(9.999999e+384));
			AddTestCase('lnx711:p7 r:HALF_EVEN (0 + decimal.log(9.999992e+384)) inexact rounded', 886.4953, 0 + decimal.log(9.999992e+384));
		}
		{
			use precision 16;
			AddTestCase('lnx722:p16 r:HALF_EVEN (0 + decimal.log(9.999999999999999e+384)) inexact rounded', 886.4952608027076, 0 + decimal.log(9.999999999999999e+384));
			AddTestCase('lnx724:p16 r:HALF_EVEN (0 + decimal.log(9.999999999999917e+384)) inexact rounded', 886.4952608027076, 0 + decimal.log(9.999999999999917e+384));
			AddTestCase('lnx726:p16 r:HALF_EVEN (0 + decimal.log(9.999999999999117e+384)) inexact rounded', 886.4952608027075, 0 + decimal.log(9.999999999999117e+384));
			// and more...
		}
		{
			use precision 15;
			AddTestCase('lnx731:p15 r:HALF_EVEN (0 + decimal.log(9.99999999999999e+999)) inexact rounded', 2302.58509299405, 0 + decimal.log(9.99999999999999e+999));
			AddTestCase('lnx733:p15 r:HALF_EVEN (0 + decimal.log(9.99999999999265e+999)) inexact rounded', 2302.58509299404, 0 + decimal.log(9.99999999999265e+999));
			AddTestCase('lnx734:p15 r:HALF_EVEN (0 + decimal.log(9.99999999999264e+999)) inexact rounded', 2302.58509299404, 0 + decimal.log(9.99999999999264e+999));
			// subnormals and underflows for exp, including underflow-to-zero edge point
		}
		{
			use precision 7;
			AddTestCase('lnx751:p7 r:HALF_EVEN (0 + decimal.log(0e-389))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0e-389));
			AddTestCase('lnx758:p7 r:HALF_EVEN (0 + decimal.log(1.000001e-383)) inexact rounded', -881.8901, 0 + decimal.log(1.000001e-383));
			AddTestCase('lnx759:p7 r:HALF_EVEN (0 + decimal.log(9.99991e-384)) inexact rounded', -881.8901, 0 + decimal.log(9.99991e-384));
			AddTestCase('lnx760:p7 r:HALF_EVEN (0 + decimal.log(4.4605e-385)) inexact rounded', -885.0000, 0 + decimal.log(4.4605e-385));
			AddTestCase('lnx761:p7 r:HALF_EVEN (0 + decimal.log(2.221e-386)) inexact rounded', -887.9999, 0 + decimal.log(2.221e-386));
			AddTestCase('lnx762:p7 r:HALF_EVEN (0 + decimal.log(3.01e-387)) inexact rounded', -889.9985, 0 + decimal.log(3.01e-387));
			AddTestCase('lnx763:p7 r:HALF_EVEN (0 + decimal.log(1.7e-388)) inexact rounded', -892.8724, 0 + decimal.log(1.7e-388));
			AddTestCase('lnx764:p7 r:HALF_EVEN (0 + decimal.log(1.5e-388)) inexact rounded', -892.9976, 0 + decimal.log(1.5e-388));
			AddTestCase('lnx765:p7 r:HALF_EVEN (0 + decimal.log(9e-389)) inexact rounded', -893.5084, 0 + decimal.log(9e-389));
			AddTestCase('lnx766:p7 r:HALF_EVEN (0 + decimal.log(1e-389)) inexact rounded', -895.7056, 0 + decimal.log(1e-389));
			AddTestCase('lnx774:p7 r:HALF_EVEN (0 + decimal.log(0e-389))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0e-389));
			// special values
			AddTestCase('lnx820:p7 r:HALF_EVEN (0 + decimal.log(decimal.POSITIVE_INFINITY))', decimal.POSITIVE_INFINITY, 0 + decimal.log(decimal.POSITIVE_INFINITY));
			AddTestCase('lnx821:p7 r:HALF_EVEN (0 + decimal.log(0))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0));
			AddTestCase('lnx822:p7 r:HALF_EVEN (0 + decimal.log(NaN))', NaN, 0 + decimal.log(NaN));
			AddTestCase('lnx823:p7 r:HALF_EVEN (0 + decimal.log(NaN)) invalid_operation', NaN, 0 + decimal.log(NaN));
			// propagating nans
			AddTestCase('lnx824:p7 r:HALF_EVEN (0 + decimal.log(NaN)) invalid_operation', NaN, 0 + decimal.log(NaN));
			AddTestCase('lnx825:p7 r:HALF_EVEN (0 + decimal.log(-NaN)) invalid_operation', -NaN, 0 + decimal.log(-NaN));
			AddTestCase('lnx826:p7 r:HALF_EVEN (0 + decimal.log(NaN))', NaN, 0 + decimal.log(NaN));
			AddTestCase('lnx827:p7 r:HALF_EVEN (0 + decimal.log(-NaN))', -NaN, 0 + decimal.log(-NaN));
			AddTestCase('lnx828:p7 r:HALF_EVEN (0 + decimal.log(NaN))', NaN, 0 + decimal.log(NaN));
			// invalid operations due to restrictions
			// [next two probably skipped by most test harnesses]
		}
		{
			use precision 9;
			AddTestCase('lnx903:p9 r:HALF_EVEN (0 + decimal.log(1)) invalid_context', 0, 0 + decimal.log(1));
			AddTestCase('lnx904:p9 r:HALF_EVEN (0 + decimal.log(0))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0));
			AddTestCase('lnx905:p9 r:HALF_EVEN (0 + decimal.log(1)) invalid_context', 0, 0 + decimal.log(1));
			AddTestCase('lnx906:p9 r:HALF_EVEN (0 + decimal.log(0))', decimal.NEGATIVE_INFINITY, 0 + decimal.log(0));
			// payload decapitate
		}
		{
			use precision 5;
			AddTestCase('lnx910:p5 r:HALF_EVEN (0 + decimal.log(-NaN)) invalid_operation', -NaN, 0 + decimal.log(-NaN));
			// null test
			AddTestCase('lnx900:p5 r:HALF_EVEN (0 + decimal.log(null)) invalid_operation', -Infinity, 0 + decimal.log(null));
			}
		}
	}
}
test();
