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

#include "avmplus.h"

#include <stdlib.h>
#include <sys/time.h>
#include <math.h> 

#ifdef AVMPLUS_UNIX
	#include <time.h>
#endif // AVMPLUS_UNIX

#ifdef AVMPLUS_MAC
    #include <malloc/malloc.h>
#endif //AVMPLUS_MAC

#include <sys/mman.h>

#define kMsecPerDay     86400000
#define kMsecPerHour    3600000
#define kMsecPerSecond  1000
#define kMsecPerMinute  60000

#define DIVCLOCK ( CLOCKS_PER_SEC / 1000 )

#define kMicroPerSec 1000000.0

double VMPI_getLocalTimeOffset()
{
	struct tm* t;
	time_t current, localSec, globalSec;

	// The win32 implementation ignores the passed in time
	// and uses current time instead, so to keep similar
	// behaviour we will do the same
	time( &current );

	t = localtime( &current );
	localSec = mktime( t );

	t = gmtime( &current );
	globalSec = mktime( t );

	return double( localSec - globalSec ) * 1000.0;
}

double VMPI_getDate()
{
	struct timeval tv;
	struct timezone tz; // Unused

	gettimeofday(&tv, &tz);
	double v = (tv.tv_sec + (tv.tv_usec/kMicroPerSec)) * kMsecPerSecond;
	double ip;
	::modf(v, &ip); // strip fractional part
	return ip;
}

//time is passed in as milliseconds from UTC.
double VMPI_getDaylightSavingsTA(double newtime)
{
	struct tm *broken_down_time;

	//convert time from milliseconds
	newtime=newtime/kMsecPerSecond;

	time_t time_t_time=(time_t)newtime;

	//pull out a struct tm
	broken_down_time = localtime( &time_t_time );

	if (!broken_down_time)
	{
		return 0;
	}

	if (broken_down_time->tm_isdst > 0)
	{
		//daylight saving is definitely in effect.
		return kMsecPerHour;
	}

	//either daylight saving is not in effect, or we don't know (if tm_isdst is negative).
	return 0;
}


uint64_t VMPI_getTime()
{
	struct timeval tv;
	::gettimeofday(&tv, NULL);
	uint64_t result = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return result;
}


void* VMPI_alloc(size_t size)
{
	return malloc(size);
}

void VMPI_free(void* ptr)
{
	free(ptr);
}

size_t VMPI_size(void *ptr)
{
#ifdef AVMPLUS_MAC
	return malloc_size(ptr);
#else
	(void)ptr;
	return 0;
#endif
}

typedef void (*LoggingFunction)(const char*);

LoggingFunction logFunc = NULL;

void RedirectLogOutput(LoggingFunction func)
{
	logFunc = func;
}

void VMPI_log(const char* message)
{
	if(logFunc)
		logFunc(message);
	else
		printf("%s",message);
}

bool VMPI_isMemoryProfilingEnabled()
{
	//read the mmgc profiling option switch
	const char *env = getenv("MMGC_PROFILE");
	return (env && (VMPI_strncmp(env, "1", 1) == 0));
}

/**
 * SetPageProtection changes the page access protections on a block of pages,
 * to make JIT-ted code executable or not.
 *
 * If executableFlag is true, the memory is made executable and read-only.
 *
 * If executableFlag is false, the memory is made non-executable and
 * read-write.
 */
void VMPI_setPageProtection(void *address,
							size_t size,
							bool executableFlag,
							bool writeableFlag)
{
  int bitmask = sysconf(_SC_PAGESIZE) - 1;
  // mprotect requires that the addresses be aligned on page boundaries
  void *endAddress = (void*) ((char*)address + size);
  void *beginPage = (void*) ((size_t)address & ~bitmask);
  void *endPage   = (void*) (((size_t)endAddress + bitmask) & ~bitmask);
  size_t sizePaged = (size_t)endPage - (size_t)beginPage;
  
  int flags = PROT_READ;
  if (executableFlag) {
	flags |= PROT_EXEC;
  }
  if (writeableFlag) {
	flags |= PROT_WRITE;
  }
  int retval = mprotect((maddr_ptr)beginPage, (unsigned int)sizePaged, flags);
  AvmAssert(retval == 0);
  (void)retval;
}


const char *VMPI_getenv(const char *name)
{
	return getenv(name);
}

// Helper functions for VMPI_callWithRegistersSaved, kept in this file to prevent them from
// being inlined in MMgcPortUnix.cpp / MMgcPortMac.cpp.

// Registers have been flushed; compute a stack pointer and call the user function.
void CallWithRegistersSaved2(void (*fn)(void* stackPointer, void* arg), void* arg, void* buf)
{
	(void)buf;
	volatile int temp = 0;
	fn((void*)((uintptr_t)&temp & ~7), arg);
}

// Do nothing - just called to prevent another call from being a tail call, and to keep some values alive
void CallWithRegistersSaved3(void (*fn)(void* stackPointer, void* arg), void* arg, void* buf)
{
	(void)buf;
	(void)fn;
	(void)arg;
}

// Note: the linux #define provided by the compiler.

uint32_t querySignalMask() {
#if (defined(AVMPLUS_MAC) || defined(linux)) && defined(DEBUG)
	// will save just the 32 signals to avoid exposing sigset_t in ExceptionFrame
	sigset_t set;
	uint32_t mask = 0;
	if (sigprocmask(0, NULL, &set) == -1) {
		VMPI_debugLog("signal mask query failed\n");
		VMPI_debugBreak();
	}

	for (int i = 0; i< 32; i++) {
		if (sigismember(&set, i))
			mask |= (1 << i);
	}
	return mask;
#else
	// will use the setjmp/longjmp calls that do save and restore
	// signal masks, so no need to verify that the signal mask
	// hasn't changed.
	return 0;
#endif
}

void assertSignalMask(uint32_t expected) {
#if (defined(AVMPLUS_MAC) || defined(linux)) && defined(DEBUG)	
	sigset_t current_mask;
	sigemptyset(&current_mask);
		
	if (sigprocmask(0, NULL, &current_mask) == -1)  {
		VMPI_debugLog("signal mask query failed\n");
		VMPI_debugBreak();
	} else {
		for (int i = 0; i< 32; i++) {
			bool result = sigismember(&current_mask, i);
			if (result != (bool)(expected  & (1 << i))) {
				VMPI_debugLog("masks not equal\n");
				VMPI_debugBreak();
			}
		}
	}
#else // do nothing	
	(void)expected;
	// will use the setjmp/longjmp calls that do save and restore
	// signal masks, so no need to verify that the signal mask
	// hasn't changed.

#endif 
}




