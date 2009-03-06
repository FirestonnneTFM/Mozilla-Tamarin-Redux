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

#ifndef __avmplus_VMPI__
#define __avmplus_VMPI__

//Placeholder Plaform-specific includes
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

#define VMPI_getenv			getenv

#define VMPI_sprintf		sprintf
#define VMPI_snprintf		snprintf

#define VMPI_atoi	atoi
#define VMPI_tolower tolower	
#define VMPI_islower islower	
#define VMPI_toupper toupper	
#define VMPI_isupper isupper	
#define VMPI_isdigit isdigit	
#define VMPI_isalnum isalnum	
#define VMPI_isxdigit isxdigit	
#define VMPI_isspace isspace	
#define VMPI_isgraph isgraph	
#define VMPI_isprint isprint	
#define VMPI_ispunct ispunct	
#define VMPI_iscntrl iscntrl	
#define VMPI_isalpha isalpha
#define VMPI_abort   abort

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include <ctype.h>
#include <limits.h>

#if defined (WIN32)

	#if _MSC_VER > 1000
		#pragma warning(push)
		#pragma warning(disable: 4201)
	#endif

	#include <windows.h>
	#include <malloc.h>
	
	#if _MSC_VER > 1000
		#pragma warning(pop)
	#endif

	#ifdef _MSC_VER
	// MSVC doesn't support inttypes.h or most C99 types directly, so declare them ourself.
	
	#ifdef _ARM_
		// Windows Mobile doesn't provide intptr_t or uintptr_t, so we'll do it ourself
		typedef __int32				intptr_t; 
		typedef unsigned __int32	uintptr_t; 
		#endif
		
		typedef __int8				int8_t;
		typedef __int16				int16_t;
		typedef __int32				int32_t;
		typedef __int64				int64_t;
		typedef unsigned __int8		uint8_t;
		typedef unsigned __int16	uint16_t;
		typedef unsigned __int32	uint32_t; 
		typedef unsigned __int64	uint64_t;
	#else
		#include <inttypes.h>
	#endif

        #ifdef UNDER_CE
		#undef VMPI_abort
                #define VMPI_abort() TerminateProcess(GetCurrentProcess(), 0)
        #endif

#endif /* WIN32 */

#if defined (AVMPLUS_SYMBIAN)

	#include <inttypes.h>

	#include <e32std.h>
	
#endif /* AVMPLUS_SYMBIAN */

#if defined (UNIX)
	#include <inttypes.h>
#endif

#if defined (_MAC)

	#include <inttypes.h>
	#include <alloca.h>

#endif /* AVMPLUS_SYMBIAN */

#if defined (SOLARIS)

	#include <inttypes.h>
	#include <alloca.h>

#endif /* SOLARIS */

// legacy types
namespace avmplus
{
typedef int64_t		int64;
typedef int64_t		sint64;
typedef uint64_t	uint64;
typedef uint32_t	uint32;
typedef int32_t		int32;
typedef int32_t		sint32;
typedef uint16_t	uint16;

typedef int16_t		int16;

typedef int16_t		sint16;
typedef uint8_t		uint8;
typedef int8_t		int8;
typedef int8_t		sint8;
typedef uintptr_t	uintptr;
typedef intptr_t	sintptr;

typedef uint8_t		byte;
};
/* wchar is our version of wchar_t, since wchar_t is different sizes
 on different platforms, but we want to use UTF-16 uniformly. */
typedef uint16_t wchar;

// not ported or needed elsewhere (yet!)
#ifdef WIN32
void VMPI_WriteOnNamedSignal(const char *name, uint32_t *addr);
void *VMPI_OpenAndConnectToNamedPipe(const char *pipe);
FILE *VMPI_HandleToStream(void *handle);
void VMPI_CloseNamedPipe(void *handle);
#endif

#endif /* __avmplus_VMPI__ */
