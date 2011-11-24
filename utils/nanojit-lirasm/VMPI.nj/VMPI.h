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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2007
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

/*
 * Stub VMPI implementation to support standalone nanojit repository.
 *
 * Really only works if you *don't* have a busted-up C library.
 */

#ifndef __VMPI_h__
#define __VMPI_h__

#if defined(HAVE_CONFIG_H) && defined(NANOJIT_CENTRAL)
#include "config.h"
#endif

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>

#if defined(AVMPLUS_UNIX) || defined(AVMPLUS_OS2)
#include <unistd.h>
#include <sys/mman.h>
#endif

#ifdef AVMPLUS_WIN32
#if ! defined(_STDINT_H)
typedef signed char int8_t;
typedef signed short int16_t;
typedef signed int int32_t;
typedef signed __int64 int64_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned __int64 uint64_t;
#endif
#else
#include <stdint.h>
#include <inttypes.h>
#endif

#define VMPI_abort abort
#define VMPI_strlen strlen
#define VMPI_strcat strcat
#define VMPI_strcmp strcmp
#define VMPI_strncat strncat
#define VMPI_strcpy strcpy
#define VMPI_sprintf sprintf
#ifdef _MSC_VER
#   define VMPI_snprintf sprintf_s
#else
#   define VMPI_snprintf snprintf
#endif
#define VMPI_vfprintf vfprintf
#define VMPI_memset memset
#define VMPI_memcmp memcmp
#define VMPI_isdigit isdigit
#define VMPI_getDate()

extern size_t VMPI_getVMPageSize();

extern void VMPI_setPageProtection(void *address,
                                   size_t size,
                                   bool executableFlag,
                                   bool writeableFlag);

//  Keep this warning-set relatively in sync with platform/win32/win32-platform.h in tamarin.

#ifdef _MSC_VER
    #pragma warning(disable:4201) // nonstandard extension used : nameless struct/union
    #pragma warning(disable:4512) // assignment operator could not be generated
    #pragma warning(disable:4511) // can't generate copy ctor
    #pragma warning(disable:4127) // conditional expression is constant - appears to be compiler noise primarily
    #pragma warning(disable:4611) // interaction between _setjmp and destruct
    #pragma warning(disable:4725) // instruction may be inaccurate on some Pentiums
    #pragma warning(disable:4611) // interaction between '_setjmp' and C++ object destruction is non-portable
    #pragma warning(disable:4251) // X needs to have dll-interface to be used by clients of class Y

    // enable some that are off even in /W4 mode, but are still handy
    #pragma warning(default:4265)   // 'class' : class has virtual functions, but destructor is not virtual
    #pragma warning(default:4905)   // wide string literal cast to 'LPSTR'
    #pragma warning(default:4906)   // string literal cast to 'LPWSTR'
    #pragma warning(default:4263)   // 'function' : member function does not override any base class virtual member function
    #pragma warning(default:4264)   // 'virtual_function' : no override available for virtual member function from base 'class'; function is hidden
    #pragma warning(default:4266)   // 'function' : no override available for virtual member function from base 'type'; function is hidden
    #pragma warning(default:4242)   // 'identifier' : conversion from 'type1' to 'type2', possible loss of data
    #pragma warning(default:4263)   // member function does not override any base class virtual member function
    #pragma warning(default:4296)   // expression is always true (false) (Generally, an unsigned variable was used in a comparison operation with zero.)
#endif

// This part defined in avmshell.h but similarly required for a warning-free nanojit experience.
#ifdef _MSC_VER
#pragma warning(disable:4996)       // 'scanf' was declared deprecated
#endif

// This part is inhibited manually by the CFLAGS in the tamarin configury.
#ifdef _MSC_VER
#pragma warning(disable:4291)       // presence of a 'new' operator in nanojit/Allocator.h without matching 'delete'
#endif

#define _MM_SHUFFLE(x, y, z, w)  ((w << 6) | (z << 4) | (y << 2) | x)

#define SOFT_FLOAT4
#define REALLY_INLINE inline
#ifdef SOFT_FLOAT4
#include <math.h>
/**
 * Float4 support, no intrinsics
 */
typedef 
struct float4_t {
    float x, y, z, w;
} float4_t;

REALLY_INLINE float4_t f4_add(const float4_t& x1, const float4_t& x2) 
{ 
    float4_t retval = { x1.x + x2.x, x1.y + x2.y, x1.z + x2.z, x1.w + x2.w };
    return retval;
}

REALLY_INLINE float4_t f4_sub(const float4_t& x1, const float4_t& x2) 
{ 
    float4_t retval = { x1.x - x2.x, x1.y - x2.y, x1.z - x2.z, x1.w - x2.w };
    return retval;
}

REALLY_INLINE float4_t f4_mul(const float4_t& x1, const float4_t& x2) 
{ 
    float4_t retval = { x1.x * x2.x, x1.y * x2.y, x1.z * x2.z, x1.w * x2.w };
    return retval;
}

REALLY_INLINE float4_t f4_div(const float4_t& x1, const float4_t& x2) 
{ 
    float4_t retval = { x1.x / x2.x, x1.y / x2.y, x1.z / x2.z, x1.w / x2.w };
    return retval;
}

REALLY_INLINE int32_t f4_eq_i(const float4_t x1, const float4_t& x2)
{
    return (x1.x == x2.x) && (x1.y == x2.y) && (x1.z == x2.z) && (x1.w == x2.w);
}

// in hardware: vdupq_n_f32/ _mm_set_ps1
REALLY_INLINE float4_t f4_setall(float v) 
{ 
    float4_t retval = {v, v, v, v};
    return retval;
}

// in hardware: vdupq_n_f32, or _mm_sqrt_ps
REALLY_INLINE float4_t f4_sqrt(const float4_t& v) 
{ 
    float4_t retval = { sqrtf(v.x), sqrtf(v.y), sqrtf(v.z), sqrtf(v.w)};
    return retval;
}

REALLY_INLINE float f4_x(const float4_t& v) { return v.x; }
REALLY_INLINE float f4_y(const float4_t& v) { return v.y; }
REALLY_INLINE float f4_z(const float4_t& v) { return v.z; }
REALLY_INLINE float f4_w(const float4_t& v) { return v.w; }

#elif defined AVMPLUS_ARM 
#include <arm_neon.h>

typedef float32x4_t              float4_t;

#define f4_mul              vmulq_f32
#define f4_add              vaddq_f32
#define f4_sub              vsubq_f32
inline float32x4_t f4_div(float32x4_t a,float32x4_t b)  {
      /* get an initial estimate of 1/b.*/     
      float32x4_t reciprocal = vrecpeq_f32(b); 

      /* use a couple Newton-Raphson steps to refine the estimate. */
      reciprocal = vmulq_f32(vrecpsq_f32(b, reciprocal), reciprocal);
      reciprocal = vmulq_f32(vrecpsq_f32(b, reciprocal), reciprocal);
       /* and finally, compute a/b = a*(1/b)*/
      float32x4_t result = vmulq_f32(a,reciprocal);
      return result;
}

inline bool f4_eq_i(float32x4_t a, float32x4_t b){
    uint32x2_t res = vreinterpret_u32_u16( vmovn_u32(vceqq_f32(a, b)) );
    return vget_lane_u32(res, 0) == 0xffffffff && vget_lane_u32(res, 1) == 0xffffffff;
}
#define f4_x(v)            ((float)vgetq_lane_f32(v,0))
#define f4_y(v)            ((float)vgetq_lane_f32(v,1))
#define f4_z(v)            ((float)vgetq_lane_f32(v,2))
#define f4_w(v)            ((float)vgetq_lane_f32(v,3))
#define f4_ith(v,i)        ((float)vgetq_lane_f32(v,i))
#define f4_shuffle(v,i)    v;(void)i;AvmAssert(false);  // TODO! fix/implement shuffle

///////// LIRASM_ONLY INTINSICS ////////
#define f4_sqrt vsqrtq_f32
#define f4_setall       vdupq_n_f32
#else
#include <xmmintrin.h>
#include <emmintrin.h>

typedef __m128 float4_t;
#define f4_mul              _mm_mul_ps
#define f4_add              _mm_add_ps
#define f4_sub              _mm_sub_ps
#define f4_div              _mm_div_ps
#define f4_eq_i(a,b)        ( _mm_movemask_epi8( _mm_castps_si128 (_mm_cmpneq_ps( (a) , (b)))  ) == 0 )
#define f4_x(v)            _mm_cvtss_f32(v)
#define f4_y(v)            _mm_cvtss_f32(_mm_shuffle_ps(v,v,_MM_SHUFFLE(1,1,1,1)))
#define f4_z(v)            _mm_cvtss_f32(_mm_shuffle_ps(v,v,_MM_SHUFFLE(2,2,2,2)))
#define f4_w(v)            _mm_cvtss_f32(_mm_shuffle_ps(v,v,_MM_SHUFFLE(3,3,3,3)))
#define f4_ith(v,i)        _mm_cvtss_f32(_mm_shuffle_ps(v,v,_MM_SHUFFLE(i,i,i,i)))
#define f4_shuffle(v,i)    _mm_shuffle_ps(v,v,i)


#define f4_setall             _mm_set_ps1
#define f4_sqrt 	_mm_sqrt_ps
#endif // SOFTFLOAT/ARM/x86


#endif
