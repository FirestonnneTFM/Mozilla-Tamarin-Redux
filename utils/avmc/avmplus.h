/* -*- tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 2009
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

// replacement for avmplus.h for the eval code.
//
// You also need to define a couple of things on your command line or in your project file:
//
//  AVMC_STANDALONE    (to tweak the evaluator in a couple of places)
//  VMCFG_EVAL         (to enable the evaluator)

#include <assert.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

// The following represent dependencies that eval makes on avmplus.
// We also depend on the opcode table in ActionBlockConstants.h

typedef uint16_t wchar;

#ifdef DEBUG
    #define AvmAssert assert
#else
    #define AvmAssert(x) (void)(0)
#endif

#define MMGC_STATIC_ASSERT(x) enum {}

#define VMPI_sprintf sprintf
#define VMPI_snprintf snprintf
#define VMPI_vsnprintf vsnprintf
#define VMPI_strcpy strcpy
#define VMPI_strlen strlen
#define VMPI_memcmp memcmp
#define VMPI_memcpy memcpy

#include "ActionBlockConstants.h"

inline void *operator new(size_t size, void* p) { return p; }

union double_overlay
{
    double_overlay() {}
    double_overlay(double d) { value=d; }
    double_overlay(uint64_t v) { bits64=v; }
    
    double value;
#if defined VMCFG_BIG_ENDIAN || defined VMCFG_DOUBLE_MSW_FIRST
    struct { uint32_t msw, lsw; } words;
#else
    struct { uint32_t lsw, msw; } words;
#endif
    uint32_t bits32[2];
    uint64_t bits64;
};

class MathUtils
{
public:
    static bool isNaN(double x);
    static bool isInfinite(double x);
    static const double kNaN;
};

class MethodInfo
{
public:
	static const int NEED_ARGUMENTS		= 0x00000001;
	static const int NEED_ACTIVATION	= 0x00000002;
	static const int NEED_REST          = 0x00000004;
	static const int HAS_OPTIONAL       = 0x00000008;
	static const int IGNORE_REST        = 0x00000010;
	static const int NATIVE				= 0x00000020;
	static const int SETS_DXNS			= 0x00000040;
	static const int HAS_PARAM_NAMES	= 0x00000080;
};
