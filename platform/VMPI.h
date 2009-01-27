
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

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include <ctype.h>
#include <limits.h>

#if defined (WIN32)

	#include <windows.h>
	#include <malloc.h>
	
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

/* wchar is our version of wchar_t, since wchar_t is different sizes
 on different platforms, but we want to use UTF-16 uniformly. */
typedef unsigned short wchar;

#endif /* __avmplus_VMPI__ */
