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


#ifndef __avmplus_MathUtils_inlines__
#define __avmplus_MathUtils_inlines__

namespace avmplus
{
    // These methods appear to be unused
    // The implementations of max, min, maxf, and minf do not follow the spec
    // in some cases with signed zero arguments.
    // BEGIN
    REALLY_INLINE double MathUtils::infinity() { return kInfinity; }
    REALLY_INLINE double MathUtils::neg_infinity() { return kNegInfinity; }
    REALLY_INLINE double MathUtils::max(double x, double y) { return (x > y) ? x : y; }
    REALLY_INLINE double MathUtils::min(double x, double y) { return (x < y) ? x : y; }
    REALLY_INLINE double MathUtils::nan() { return kNaN; }

    REALLY_INLINE float  MathUtils::maxf(float x, float y) { return (x > y) ? x : y; }
    REALLY_INLINE float  MathUtils::minf(float x, float y) { return (x < y) ? x : y; }
    // END

#if !defined(WIN32) || !defined(AVMPLUS_IA32)
    REALLY_INLINE double MathUtils::round(double value)
    {
        return MathUtils::floor(value + 0.5);
    }
#endif // !defined(WIN32) || !defined(AVMPLUS_IA32)

    REALLY_INLINE float MathUtils::roundf(float value)
    {
        return MathUtils::floorf(value + 0.5f);
    }

    REALLY_INLINE bool MathUtils::isNaNInline(double d)
    {
#if defined(AVMPLUS_IA32) && !defined(AVMPLUS_SSE2_ALWAYS)
        double_overlay u(d);
        return ((u.bits64 & ~0x8000000000000000ULL) > 0x7ff0000000000000ULL);
#else
        return (d != d);
#endif
    }
}

#endif /* __avmplus__MathUtils__ */
