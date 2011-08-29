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


#ifndef __avmplus_d2a__
#define __avmplus_d2a__

namespace avmplus
{
    // Double-to-string conversion utilities.
    //
    // See d2a.cpp for most documentation.

    class D2A
    {
    public:
        D2A(double value, bool fixedPrecision, int32_t minPrecision=0);

        int32_t nextDigit();
        int32_t expBase10() { return base10Exp; }

        double   value;             // Double value for quick work when e and mantissa are small.
        int32_t  e;
        uint64_t mantissa;          // On input, value = mantissa*2^e;  Only last 53 bits are used.
        int32_t  mantissaPrec;      // The number of bits of precision that are present in the mantissa.
        int32_t  base10Exp;         // The (derived) base 10 exponent of value.
        bool     finished;          // Set to true when we've output all relevant digits.
        bool     bFastEstimateOk;   // Use double, rather than BigInteger math.

    private:
        bool lowOk;             // For IEEE unbiased rounding, this is true when mantissa is even.  When true, use >= in mMinus test instead of >
        bool highOk;            // Ditto, but for mPlus test.

        // If !bFastEstimateOk, use these.
        BigInteger r;           // On initialization, input double <value> = r / s.  After each nextDigit() call, r = r % s.
        BigInteger s;
        BigInteger mPlus;       // When (r+mPlus) > s, we have generated all relevant digits.  Just return 0 for remaining nextDigit requests.
        BigInteger mMinus;      // When (r < mMins), we have generated all relevant digits.  Just return 0 form remaining nextDigit requests.

        // If bFastEstimateOk, use these - same as above, but integer value stored in double.
        double      dr;
        double      ds;
        double      dMPlus;
        double      dMMinus;

        // Estimate base 10 exponent of number, scale r,s,mPlus,mMinus appropriately.
        // Returns result of fixup_ExponentEstimate(est).
        int32_t scale();
        
        // Used by scale to adjust for possible off-by-one error in the base 10 exponent estimate.
        // Returns exact base10 exponent of number.
        int32_t fixup_ExponentEstimate(int32_t expEst);
    };
}

#endif /* __avmplus_d2a__ */
