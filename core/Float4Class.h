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
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
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

#ifndef __avmplus_Float4Class__
#define __avmplus_Float4Class__
#ifdef VMCFG_FLOAT

namespace avmplus
{
    /**
     * class Float4
     */
    class GC_AS3_EXACT(Float4Class, ClassClosure)
    {
    protected:
        Float4Class(VTable* cvtable);
    public:
        REALLY_INLINE static Float4Class* create(MMgc::GC* gc, VTable* cvtable)
        {
            return new (gc, MMgc::kExact, cvtable->getExtraSize()) Float4Class(cvtable);
        }

        // this = argv[0]
        // arg1 = argv[1]
        // argN = argv[argc]
        Atom call(int argc, Atom* argv)
        {
            return construct(argc,argv);
        }
        /* Component getters */
        float get_x() { const float* v = reinterpret_cast<const float*>(this); return  v[0]; };
        float get_y() { const float* v = reinterpret_cast<const float*>(this); return  v[1]; };
        float get_z() { const float* v = reinterpret_cast<const float*>(this); return  v[2]; };
        float get_w() { const float* v = reinterpret_cast<const float*>(this); return  v[3]; };

        float4_t isGreater(float4_t x, float4_t y);
        float4_t isGreaterOrEqual(float4_t x, float4_t y);
        float4_t isLess(float4_t x, float4_t y);
        float4_t isLessOrEqual(float4_t x, float4_t y);
        float4_t isEqual(float4_t x, float4_t y);
        float4_t isNotEqual(float4_t x, float4_t y);
        float4_t abs(float4_t x);
        float4_t acos(float4_t x);
        float4_t asin(float4_t x);
        float4_t atan(float4_t x);
        float4_t atan2(float4_t x, float4_t y);
        float4_t ceil(float4_t x);
        float4_t cos(float4_t x);
        float4_t exp(float4_t x);
        float4_t floor(float4_t x);
        float4_t log(float4_t x);
        float4_t min(float4_t x, float4_t y);
        float4_t max(float4_t x, float4_t y);
        float4_t pow(float4_t x, float p );
        float4_t random();
        float4_t reciprocal(float4_t x);
        float4_t round(float4_t x);
        float4_t rsqrt(float4_t x);
        float4_t sin(float4_t x);
        float4_t sqrt(float4_t x);
        float4_t tan(float4_t x);
        float4_t normalize(float4_t x);
        float4_t cross(float4_t x, float4_t y);
        float    dot(float4_t x, float4_t y);
        float    dot2(float4_t x, float4_t y);
        float    dot3(float4_t x, float4_t y);
        float    magnitude(float4_t x);
        float    magnitude2(float4_t x);
        float    magnitude3(float4_t x);
        float    distance(float4_t x, float4_t y);
        float    distance2(float4_t x, float4_t y);
        float    distance3(float4_t x, float4_t y);
 static float4_t fromComponents(float x, float y, float z, float w);
        float4_t _swizzle(float4_t val, int32_t how);

        // ------------------------ DATA SECTION BEGIN
    private:    
        GC_NO_DATA(Float4Class)
        
        DECLARE_SLOTS_Float4Class;
        // ------------------------ DATA SECTION END
    };
}
#endif
#endif /* __avmplus_Float4Class__ */
