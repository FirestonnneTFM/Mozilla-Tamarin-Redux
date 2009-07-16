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

#ifndef __avmplus_win32_platform__
#define __avmplus_win32_platform__

/**
 * We have avmplus.vcproj compiled with the /W4 warning level
 * which is quite picky.  Disable warnings we don't care about.
 */
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
	#pragma warning(default:4265)	// 'class' : class has virtual functions, but destructor is not virtual
	#pragma warning(default:4905)	// wide string literal cast to 'LPSTR'
	#pragma warning(default:4906)	// string literal cast to 'LPWSTR'
	#pragma warning(default:4263)	// 'function' : member function does not override any base class virtual member function
	#pragma warning(default:4264)	// 'virtual_function' : no override available for virtual member function from base 'class'; function is hidden
	#pragma warning(default:4266)	// 'function' : no override available for virtual member function from base 'type'; function is hidden
	#pragma warning(default:4242)   // 'identifier' : conversion from 'type1' to 'type2', possible loss of data
	#pragma warning(default:4263)   // member function does not override any base class virtual member function
	#pragma warning(default:4296)	// expression is always true (false) (Generally, an unsigned variable was used in a comparison operation with zero.)

	// some that might be useful to turn on someday, but would require too much twiddly code tweaking right now
	//	#pragma warning(error:4820) // 'bytes' bytes padding added after construct 'member_name' (MSFT system headers generate zillions of these, sadly)
#endif

#define VMPI_memcpy			memcpy
#define VMPI_memset 		memset	
#define VMPI_memcmp 		memcmp	
#define VMPI_memmove 		memmove	
#define VMPI_memchr			memchr	
#define VMPI_strcmp 		strcmp
#define VMPI_strcat 		strcat
#define VMPI_strchr 		strchr
#define VMPI_strrchr 		strrchr
#define VMPI_strcpy 		strcpy
#define VMPI_strlen 		strlen
#define VMPI_strncat 		strncat
#define VMPI_strncmp 		strncmp
#define VMPI_strncpy 		strncpy
#define VMPI_strtol			strtol
#define VMPI_strstr			strstr

#define VMPI_sprintf		sprintf
#define VMPI_snprintf		_snprintf
#define VMPI_sscanf			sscanf

#define VMPI_atoi			atoi
#define VMPI_tolower 		tolower
#define VMPI_islower 		islower
#define VMPI_toupper 		toupper
#define VMPI_isupper 		isupper
#define VMPI_isdigit 		isdigit
#define VMPI_isalnum 		isalnum
#define VMPI_isxdigit 		isxdigit
#define VMPI_isspace 		isspace
#define VMPI_isgraph 		isgraph
#define VMPI_isprint 		isprint
#define VMPI_ispunct 		ispunct
#define VMPI_iscntrl 		iscntrl
#define VMPI_isalpha 		isalpha
#ifdef UNDER_CE
	#define VMPI_abort() TerminateProcess(GetCurrentProcess(), 0)
#else
	#define VMPI_abort   abort
#endif

#ifdef UNDER_CE
	#define vsnprintf _vsnprintf
#endif

#include <stddef.h>
#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include <ctype.h>
#include <limits.h>

#include <windows.h>
#include <malloc.h>


#ifdef _ARM_
	// Windows Mobile doesn't provide intptr_t or uintptr_t
	typedef __int32				intptr_t; 
	typedef unsigned __int32	uintptr_t; 
#endif

typedef void *maddr_ptr;

#ifdef VMCFG_64BIT
	#include <setjmpex.h>
#else
	#include <setjmp.h>
#endif

#ifndef UNDER_CE
  // Newer versions of the Windows SDK set up the intrinsics slightly differently
  // than VC8. Only include intrin.h if the SDK doesn't declare it.
  #ifndef InterlockedBitTestAndSet
    #include <intrin.h>
  #endif
  #include <emmintrin.h>

  #ifdef VTUNE
    #include "JITProfiling.h"
  #endif
#endif

// Windows doesn't support inttypes.h or most C99 types directly
typedef __int8				int8_t;
typedef __int16				int16_t;
typedef __int32				int32_t;
typedef __int64				int64_t;
typedef unsigned __int8		uint8_t;
typedef unsigned __int16	uint16_t;
typedef unsigned __int32	uint32_t; 
typedef unsigned __int64	uint64_t;

// This must come after all the include files
#if defined _MSC_VER && !defined DEBUG
	#pragma intrinsic(memcmp)
	#pragma intrinsic(memcpy)
	#pragma intrinsic(memset)
	#pragma intrinsic(strlen)
	#pragma intrinsic(strcpy)
	#pragma intrinsic(strcat)
#endif

#ifdef _MSC_VER
    #define REALLY_INLINE __forceinline
#endif // _MSC_VER

#ifdef _DEBUG
typedef struct {
	void *lock;
	vmpi_thread_t owner;	
} vmpi_spin_lock_t;
#else
typedef void *vmpi_spin_lock_t;
#endif

#endif // __avmplus_win32_platform__

