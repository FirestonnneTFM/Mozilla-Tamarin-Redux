/* ***** BEGIN LICENSE BLOCK ***** 
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1 
 *
 * The contents of this file are subject to the Mozilla Public License Version 1.1 (the 
 * "License"); you may not use this file except in compliance with the License. You may obtain 
 * a copy of the License at http://www.mozilla.org/MPL/ 
 * 
 * Software distributed under the License is distributed on an "AS IS" basis, WITHOUT 
 * WARRANTY OF ANY KIND, either express or implied. See the License for the specific 
 * language governing rights and limitations under the License. 
 * 
 * The Original Code is [Open Source Virtual Machine.] 
 * 
 * The Initial Developer of the Original Code is Adobe System Incorporated.  Portions created 
 * by the Initial Developer are Copyright (C)[ 2004-2006 ] Adobe Systems Incorporated. All Rights 
 * Reserved. 
 * 
 * Contributor(s): Adobe AS3 Team
 * 
 * Alternatively, the contents of this file may be used under the terms of either the GNU 
 * General Public License Version 2 or later (the "GPL"), or the GNU Lesser General Public 
 * License Version 2.1 or later (the "LGPL"), in which case the provisions of the GPL or the 
 * LGPL are applicable instead of those above. If you wish to allow use of your version of this 
 * file only under the terms of either the GPL or the LGPL, and not to allow others to use your 
 * version of this file under the terms of the MPL, indicate your decision by deleting provisions 
 * above and replace them with the notice and other provisions required by the GPL or the 
 * LGPL. If you do not delete the provisions above, a recipient may use your version of this file 
 * under the terms of any one of the MPL, the GPL or the LGPL. 
 * 
 ***** END LICENSE BLOCK ***** */


#include "avmplus.h"

namespace avmplus
{
	BEGIN_NATIVE_MAP(DecimalClass)
		NATIVE_METHOD(decimal_private__toString, DecimalClass::decimalToString)
		NATIVE_METHOD(decimal_private__convert, DecimalClass::convert)
		NATIVE_METHOD_FLAGS(decimal_abs,    DecimalClass::abs, 0)
		NATIVE_METHOD_FLAGS(decimal_ceil,   DecimalClass::ceil, 0)
		NATIVE_METHOD_FLAGS(decimal_exp,    DecimalClass::exp, 0)
		NATIVE_METHOD_FLAGS(decimal_floor,  DecimalClass::floor, 0)
		NATIVE_METHOD_FLAGS(decimal_log,    DecimalClass::log, 0)
		NATIVE_METHOD_FLAGS(decimal_log10,    DecimalClass::log10, 0)
		NATIVE_METHOD_FLAGS(decimal_pow,    DecimalClass::pow, 0)
		NATIVE_METHOD_FLAGS(decimal_round,  DecimalClass::round, 0)
		NATIVE_METHOD_FLAGS(decimal_sqrt,   DecimalClass::sqrt, 0)
		NATIVE_METHOD_FLAGS(decimal_private__min,    DecimalClass::min2, 0)
		NATIVE_METHOD_FLAGS(decimal_private__max,    DecimalClass::max2, 0)
		NATIVE_METHODV(decimal_max,     DecimalClass::max)
		NATIVE_METHODV(decimal_min,     DecimalClass::min)
	END_NATIVE_MAP()

	DecimalClass::DecimalClass(VTable* cvtable)
		: ClassClosure(cvtable)
	{
		toplevel()->decimalClass = this;

		// prototype objects are always vanilla objects.
		createVanillaPrototype();
	}

	Atom DecimalClass::construct(int argc, Atom* argv)
	{
		// Number called as constructor creates new Number instance
		// Note: SpiderMonkey returns 0 for new Number() with no args
		if (argc == 0) {
			AvmCore *core = this->core();
			return ((uintptr)core->special_decimal[AvmCore::sd_0]) | kDecimalType;
		}
		else
			return core()->decimalAtom(argv[1], AvmCore::defaultDecimalParam);
		// TODO ArgumentError if argc > 1
	}

	Stringp DecimalClass::convert(DecimalRep *n, int precision, int mode)
	{
		AvmCore* core = this->core();
		char buffer[50];
		int len;

		if (mode == MathUtils::DTOSTR_PRECISION)
		{
			if (precision < 1 || precision > 34) {
				toplevel()->throwRangeError(kInvalidPrecisionError, core->toErrorString(precision), core->toErrorString(1), core->toErrorString(21));
			}
			decNumber tmp;
			decContext ctx;
			decContextDefault(&ctx, DEC_INIT_DECIMAL128);
			ctx.digits = precision;
			decNumberPlus(&tmp, &n->dn, &ctx);
			decNumberToString(&tmp, buffer);
		}
		else
		{
			if (precision < 0 || precision > 34) {
				toplevel()->throwRangeError(kInvalidPrecisionError, core->toErrorString(precision), core->toErrorString(0), core->toErrorString(20));	
			}
			decNumber tmp = n->dn; // copy number
			if (tmp.bits & DECSPECIAL) {
				if (tmp.bits & DECINF) {
					if (tmp.bits & DECNEG)
						strcpy(buffer, "-Infinity");
					else
						strcpy(buffer, "Infinity");
				}
				else strcpy(buffer, "NaN");
			}
			else {
				char digs[50];
				int i, exp;
				// use decNumberPlus to round if needed
				int bptr = 0;
				if (tmp.bits & DECNEG) {
					buffer[bptr++] = '-';
				}
				if (mode == MathUtils::DTOSTR_FIXED) {
					// precision here means digits after the .
					exp = tmp.exponent;
					if ((-exp) > precision && ((tmp.digits + exp + precision) < 34)) {
						// we want fewer digits after . than number has
						decContext ctx;
						decContextDefault(&ctx, DEC_INIT_DECIMAL128);
						ctx.digits = (tmp.digits + exp + precision);
						decNumberPlus(&tmp, &n->dn, &ctx);	// redefine tmp with the requisite number of digits
						exp = tmp.exponent;	// can change when rounding
					}
					tmp.exponent = 0;
					decNumberToString(&tmp, digs);	// get digits in an array
					int pre = tmp.digits + exp;	// digit before '.', could be negative
					if (pre <= 0) {
						buffer[bptr++] = '0';
					} else {
						for (i = 0; i < pre; i++) {
							buffer[bptr++] = (i < tmp.digits) ? digs[i] : '0';
						}
					}
					buffer[bptr++] = '.';
					for (i = pre; i < tmp.digits; i++) {
						if (precision <= 0)
							break;
						buffer[bptr++] = (i < 0)? '0' : digs[i];
						precision--;
					}
					while (precision > 0) {
						buffer[bptr++] = '0';
						precision--;
					}
					buffer[bptr] = 0;
				}
				else { // scientific
					int power10 = tmp.digits + tmp.exponent - 1;
					if ((precision+1) < tmp.digits) {
						decContext ctx;
						decContextDefault(&ctx, DEC_INIT_DECIMAL128);
						ctx.digits = (precision+1);
						decNumberPlus(&tmp, &n->dn, &ctx);	// redefine tmp with the requisite number of digits
					}
					exp = tmp.exponent;
					tmp.exponent = 0;
					decNumberToString(&tmp, digs); // get digits
					buffer[bptr++] = digs[0];
					if (precision > 0) {
						buffer[bptr++] = '.';
						for (i = 1; i < tmp.digits; i++) {
							if (precision <= 0)
								break;
							buffer[bptr++] = digs[i];
							precision--;
						}
						while (precision > 0) {
							buffer[bptr++] = '0';
							precision--;
						}
					}
					buffer[bptr++] = 'E';
					if (power10 < 0) {
						buffer[bptr++] = '-';
						power10 = - power10;
					}
					char ebuf[10];
					int eptr = 0;
					while (power10 > 0) {
						ebuf[eptr] = (char) ((int)'0' + (power10 % 10));
						power10 = power10 / 10;
						eptr++;
					}
					while (eptr > 0) {
						eptr--;
						buffer[bptr++] = ebuf[eptr];
					}
					buffer[bptr] = 0;
				}
			}

		}

		len = strlen(buffer);
		wchar wbuf[50];
		for (int i = 0; i < len; i++) {
			wbuf[i] = buffer[i];
		}
		
		return new (core->GetGC()) String(wbuf,len);
	}
	

	Stringp DecimalClass::decimalToString(DecimalRep *dRep, int radix)
	{
		decNumber *dVal = &dRep->dn;
		AvmCore* core = this->core();

		if (radix == 10 || decNumberIsInfinite(dVal) || decNumberIsNaN(dVal))
			return core->decimalToString(dRep);

		if (radix < 2 || radix > 36)
			toplevel()->throwRangeError(kInvalidRadixError, core->toErrorString(radix));

		// if radix != 10, converts to double and then calls DoubleToStringRadix
		// convertDoubleToStringRadix will convert the integer part of dVal
		// to a string in the specified radix, and it will handle large numbers
		// beyond the range of int/uint.  It will not handle the fractional
		// part.  To properly handle that, MathUtils::convertDoubleToString
		// would have to handle any base.  That's a lot of extra code and complexity for
		// something the ES3 spec says is implementation dependent
		// (i.e. we're not required to do it)
		
		return MathUtils::convertDecimalToStringRadix(core, dVal, radix);
	}

	DecimalRep* DecimalClass::getDecimalRep(decNumber *dn) {
		AvmCore::SpecialDecimalIndex index;
		AvmCore *core = this->core();
		if (core->isSpecialDecimal(dn, index)) {
			return core->special_decimal[index];
		}
		return core->allocDecimal(dn); 
	}

    DecimalRep* DecimalClass::abs(DecimalRep *x) {
        if (!decNumberIsNegative(&x->dn))
            return x;
        decNumber result;
		decNumberAbs(&result, &x->dn, &(core()->defaultDecContext));
        
        return getDecimalRep(&result);
    }

    DecimalRep* DecimalClass::exp(DecimalRep *x) {
        decNumber result;
		decNumberExp(&result, &x->dn, &(core()->defaultDecContext));
        
        return getDecimalRep(&result);
    }

    DecimalRep* DecimalClass::log(DecimalRep *x) {
        decNumber result;
		decNumberLn(&result, &x->dn, &(core()->defaultDecContext));
        
        return getDecimalRep(&result);
    }

    DecimalRep* DecimalClass::log10(DecimalRep *x) {
        decNumber result;
		decNumberLog10(&result, &x->dn, &(core()->defaultDecContext));
        
        return getDecimalRep(&result);
    }

    DecimalRep* DecimalClass::pow(DecimalRep *x, DecimalRep *y) {
        decNumber result;
		// per 262, anything, even NaN to 0 power is 1
		if (decNumberIsZero(&y->dn))
			return core()->special_decimal[AvmCore::sd_1];
		decNumberPower(&result, &x->dn, &y->dn, &(core()->defaultDecContext));
        
        return getDecimalRep(&result);
    }

    DecimalRep* DecimalClass::sqrt(DecimalRep *x) {
        decNumber result;
		decNumberSquareRoot(&result, &x->dn, &(core()->defaultDecContext));
        
        return getDecimalRep(&result);
    }

    DecimalRep* DecimalClass::round(DecimalRep *x, int rnd) {
        decContext ctx;
		decContextDefault(&ctx, DEC_INIT_DECIMAL128); 
		ctx.round = (rounding)rnd;
        decNumber result;
		decNumberToIntegralValue(&result, &x->dn, &ctx);
        
        return getDecimalRep(&result);
    }

    DecimalRep* DecimalClass::ceil(DecimalRep *x) {
        return round(x, DEC_ROUND_CEILING);
    }

    DecimalRep* DecimalClass::floor(DecimalRep *x) {
        return round(x, DEC_ROUND_FLOOR);
    }

	DecimalRep* DecimalClass::min2(DecimalRep *x, DecimalRep *y) {
		decNumber result;
		/* we want different behavior from the 754r spec wrt NaN */
		if (decNumberIsNaN(&x->dn) || decNumberIsNaN(&y->dn))
			return core()->special_decimal[AvmCore::sd_NaN];
		decNumberMin(&result, &x->dn, &y->dn, &(core()->defaultDecContext));
		return getDecimalRep(&result);
	}

	DecimalRep* DecimalClass::max2(DecimalRep *x, DecimalRep *y) {
		decNumber result;
		/* we want different behavior from the 754r spec wrt NaN */
		if (decNumberIsNaN(&x->dn) || decNumberIsNaN(&y->dn))
			return core()->special_decimal[AvmCore::sd_NaN];
		decNumberMax(&result, &x->dn, &y->dn, &(core()->defaultDecContext));
		return getDecimalRep(&result);
	}

	DecimalRep* DecimalClass::min(Atom *argv, int argc) {
		// 754r says that min(x, NaN) is x, which is not what ES3 says for Number.  We model ES3
		AvmCore *core = this->core();
		if (argc == 0) {	// I don't think this possible
			return core->special_decimal[AvmCore::sd_NaN];
		}
		DecimalRep *x = core->special_decimal[AvmCore::sd_Infinity];
		for (int i=0; i < argc; i++) {
			DecimalRep *y = core->decimalNumber(argv[i]);
			if (decNumberIsNaN(&y->dn)) {
				return core->special_decimal[AvmCore::sd_NaN];
			}
			if (decComp(&y->dn, &x->dn) < 0) {
				x = y;
			}
		}
		return x;
	}

	DecimalRep* DecimalClass::max(Atom *argv, int argc) {
		// 754r says that max(x, NaN) is x, which is not what ES3 says for Number.  We model ES3
		AvmCore *core = this->core();
		if (argc == 0) {	// I don't think this possible
			return core->special_decimal[AvmCore::sd_NaN];
		}
		DecimalRep *x = core->special_decimal[AvmCore::sd_NegInfinity];
		for (int i=0; i < argc; i++) {
			DecimalRep *y = core->decimalNumber(argv[i]);
			if (decNumberIsNaN(&y->dn)) {
				return core->special_decimal[AvmCore::sd_NaN];
			} 
			if (decComp(&y->dn, &x->dn) > 0) {
				x = y;
			}
		}
		return x;
	}

}
