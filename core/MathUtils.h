/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */


#ifndef __avmplus_MathUtils__
#define __avmplus_MathUtils__

namespace avmplus
{
#ifdef _MSC_VER
	#undef max
	#undef min
#endif

    /**
     * Data structure for state of fast random number generator.
     */
    struct TRandomFast
    {
        /* Random result and seed for next random result. */
        uint32_t  uValue;

        /* XOR mask for generating the next random value. */
        uint32_t  uXorMask;

        /* This is the number of values which will be generated in the
           /  sequence given the initial value of n. */
        uint32_t  uSequenceLength;
    };
    //
    // Random number generator
    //
    typedef struct TRandomFast *pTRandomFast;

    /**
     * The pure random number generator returns random numbers between zero
     * and this number.  This value is useful to know for scaling random
     * numbers to a desired range.
     */
    #define kRandomPureMax 0x7FFFFFFFL

    /**
     * The MathUtils class is a utility class which supports many
     * common mathematical operations, particularly those defined in
     * ECMAScript's Math class.
     */
    class MathUtils
    {
    public:
        static const double kNaN;
        static const double kInfinity;
        static const double kNegInfinity;
    public:
        static double abs(double value);
        static double acos(double value);
        static double asin(double value);
        static double atan(double value);
        static double atan2(double y, double x);
        static double ceil(double value);
        static double cos(double value);
        static bool equals(double x, double y);
        static double exp(double value);
        static double floor(double value);
        static uint64_t  frexp(double x, int32_t *eptr);
        REALLY_INLINE static double infinity();
        REALLY_INLINE static double neg_infinity();
        /// Return 1 if value is +Infinity, -1 if -Infinity, 0 otherwise.
        static int32_t isInfinite(double value);
        REALLY_INLINE static bool isNaNInline(double value); // only for time critical routines
        static bool isNaN(double value);
        static bool isNegZero(double x);
        static double log(double value);
        REALLY_INLINE static double max(double x, double y);
        REALLY_INLINE static double min(double x, double y);
        static double mod(double x, double y);
        REALLY_INLINE static double nan();
        static int32_t nextPowerOfTwo(int32_t n);
        static double parseInt(Stringp s, int32_t radix=10, bool strict=true);
        static double pow(double x, double y);
        static double powInternal(double x, double y);
        static void initRandom(TRandomFast *seed);
        static double random(TRandomFast *seed);
        static double round(double value);
        static double sin(double value);
        static double sqrt(double value);
        static double tan(double value);
        static double toInt(double value);

        /**
         * Enumeration values for the minimum buffer size required to convert
         * a number to a string.
         */
        enum
        {
            /**
             * The buffer for a 32-bit integer, base 10, needs to be >= 12:
             * -2147483647<NUL> or 4294967294
             */
            kMinSizeForInt32_t_base10_toString  = 12,
            /**
             * The buffer for a 64-bit integer needs to be >= 65:
             * sign, up to 63 (64 w/o sign) bits if base =-=2, NUL
             */
            kMinSizeForInt64_t_toString         = 65,
            /**
             * For security reason, the buffer must be well over 347 characters:
             * Bug 192033: Number.MAX_VALUE is 1.79e+308, so this was 312.
             * Bug 230183: That wasn't big enough.  Number.MIN_VALUE.toPrecision(21)
             * needs 347.  But why be stingy?  There may be other cases that are
             * even bigger, it's hard to say.
             */
             kMinSizeForDouble_base10_toString  = 380,
             /**
              *  Buffer size for converting IEEE-754 double to string
              *  using worst-case radix(2) plus a leading '-' char.
              *  Denormalized (i.e., very small) numbers are  truncated
              *  to "0" so they don't require additional space.
              */
              kMinSizeForDouble_base2_toString  = 1025
        };

        enum UnsignedTreatment
        {
            kTreatAsSigned = 0,
            kTreatAsUnsigned = 1
        };

        /**
         * Convert an integer to a string. Since the conversion happens from
         * right to left, the string is right-aligned in the buffer, and the
         * returned pointer points somewhere into the buffer. It is NULL if
         * the base is out of range (must be between 2 and 36), or the buffer
         * is too small (the debug versions throw an assert if the buffer
         * does not fit). The buffer is NUL-terminated.
         * @param value            the value to convert
         * @param buffer           the buffer to fill
         * @param len              the buffer size; takes the number of characters filled in
         * @param radix            between 2 and 36
         * @param treatAsUnsigned  true for an unsigned conversion
         * @return                 a pointer into the buffer or NULL on errors
         */
        static char* convertIntegerToStringBuffer(intptr_t value,
                                            char *buffer,
                                            int32_t& len,
                                            int32_t radix,
                                            UnsignedTreatment treatAs);
        /**
         * Convert a 32/64-bit integer to a String instance. This method uses an internal
         * buffer of 65 characters (up to 63 bits+sign, or 64 bits, NUL) on the stack.
         * @param core              The AvmCore instance to create strings with
         * @param value             the value to convert (32 or 64 bits depending on platform)
         * @param radix             the conversion radix (2...36)
         * @param treatAsUnsigned   true for an unsigned conversion
         * @return                  the String instance
         */
        static Stringp convertIntegerToStringRadix(AvmCore* core,
                                              intptr_t value,
                                              int32_t  radix,
                                              UnsignedTreatment treatAs);
        /**
         * Convert a 32-bit integer to a String instance with a radix of 10. This
         * method uses a much smaller internal buffer of 12 characters (up to
         * 9 digits+sign or 10 digits, NUL) on the stack.
         * @param core              The AvmCore instance to create strings with
         * @param value             the value to convert (32 bits)
         * @param treatAsUnsigned   true for an unsigned conversion
         * @return                  the String instance
         */
        static Stringp convertIntegerToStringBase10(AvmCore* core,
                                              int32_t  value,
                                              UnsignedTreatment treatAs);

        /**
         * Convert a double to an integer using the given radix.
         * @param core              The AvmCore instance to create strings with
         * @param value             the value to convert
         * @param treatAsUnsigned   true for an unsigned conversion
         * @return                  the String instance
         */
        static Stringp convertDoubleToStringRadix(AvmCore *core,
                                                  double value,
                                                  int32_t radix);
        enum {
            DTOSTR_NORMAL,
            DTOSTR_FIXED,
            DTOSTR_PRECISION,
            DTOSTR_EXPONENTIAL
        };
        static Stringp convertDoubleToString(AvmCore* core,
                                             double value,
                                             int32_t mode = DTOSTR_NORMAL,
                                             int32_t precision = 15);
        static bool convertStringToDouble(Stringp inStr,
                                          double *value,
                                          bool strict=false);
        static double convertStringToNumber(Stringp inStr);
        static int32_t nextDigit(double *value);

        static int32_t doubleToBool(double d) {
            // ecma3/Boolean/e15_6_1.abc
            return d == d && d != 0;
        }
    private:
        static double powerOfTen(int32_t exponent, double value);
        static int32_t roundInt(double x);

    public:
        static void RandomFastInit(pTRandomFast pRandomFast);
        static int32_t RandomPureHasher(int32_t iSeed);
        static int32_t GenerateRandomNumber(pTRandomFast pRandomFast);
        static int32_t Random(int32_t range, pTRandomFast pRandomFast);

    };
}

#if AVMSYSTEM_WIN32
    #include "win32/MathUtilsWin-inlines.h"
#elif AVMSYSTEM_UNIX
    #ifdef SOLARIS
        #include "unix/MathUtilsSolaris-inlines.h"
    #elif AVMSYSTEM_ARM
        #include "arm/MathUtilsUnix-inlines.h"
    #else
        #include "unix/MathUtilsUnix-inlines.h"
    #endif
#elif AVMSYSTEM_MAC
    #include "unix/MathUtilsUnix-inlines.h"
#elif AVMSYSTEM_SYMBIAN
    // No inlines presently defined for the Symbian platform.
#endif
#endif /* __avmplus_MathUtils__ */
