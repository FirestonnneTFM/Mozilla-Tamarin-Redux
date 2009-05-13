/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 4 -*- */
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

#include "MMgc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifdef MMGC_MEMORY_PROFILER
#include <dlfcn.h>
#include <cxxabi.h>
#endif

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/sysctl.h>

#include <mach/mach.h>
#include <mach/mach_time.h>

#define MAP_ANONYMOUS MAP_ANON

static const int kOSX105 = 9;

size_t VMPI_getVMPageSize()
{
	long v = sysconf(_SC_PAGESIZE);
	if (v == -1) v = 4096; // Mac 10.1 needs this
	return v;
}

bool VMPI_canMergeContiguousRegions()
{
#ifdef MMGC_64BIT		
	return true;
#else
	// this would be nice to keep the region list short but
	// doing so would require additional work to perform de-reserve (region splitting), when
	// that happens turn this back on for 10 5 and up, turning it on effectively disables de-reserve
	// which is why its on for 64 bit (we're we never de-reserve)
	return false;
#endif
}

static int get_major_version()
{
	int mib[2];
	mib[0]=CTL_KERN;
	mib[1]=KERN_OSRELEASE;
	char buf[10];
	size_t siz=sizeof(buf);
	sysctl(mib, 2, &buf, &siz, NULL, 0);
	return strtol(buf, 0, 10);
}

bool VMPI_useVirtualMemory()
{
#ifdef MMGC_64BIT		
	return true;
#else
	return get_major_version() >= kOSX105;
#endif
}

static int get_mmap_fdes(int delta)
{
	// ensure runtime version
	if(get_major_version() >= kOSX105)
		return VM_MAKE_TAG(VM_MEMORY_APPLICATION_SPECIFIC_1+delta);
	else
		return -1;
}

void* VMPI_reserveMemoryRegion(void *address, size_t size)
{
	void *addr = (char*)mmap(address,
							 size,
							 PROT_NONE,
							 MAP_PRIVATE | MAP_ANONYMOUS,
							 get_mmap_fdes(0), 0);
	
	// the man page for mmap documents it returns -1 to signal failure. 
	if (addr == (void *)-1) return NULL;
	
	if(address && address != addr) {
		// fail if we didn't get the right address
		VMPI_releaseMemoryRegion(addr, size);
		return NULL;
	}
	return addr;
}

bool VMPI_releaseMemoryRegion(void* address, size_t size)
{
	int result = munmap(address, size);
	return (result == 0);
}

bool VMPI_commitMemory(void* address, size_t size)
{
	char *got = (char*)mmap(address,
							size,
							PROT_READ | PROT_WRITE,
							MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED,
							get_mmap_fdes(0), 0);
	return (got == address);
}

bool VMPI_decommitMemory(char *address, size_t size)
{
	kern_return_t result = vm_deallocate(mach_task_self(), (vm_address_t)address, size);
	if(result == KERN_SUCCESS) 
	{
		result = vm_map(mach_task_self(), (vm_address_t*)&address, size, 0, FALSE, MEMORY_OBJECT_NULL, 0, FALSE, VM_PROT_NONE, VM_PROT_READ|VM_PROT_WRITE|VM_PROT_EXECUTE, VM_INHERIT_NONE);
	}
	return (result == KERN_SUCCESS);
}

void* VMPI_allocateAlignedMemory(size_t size)
{
	return valloc(size);
}

void VMPI_releaseAlignedMemory(void* address)
{
	free(address);
}

size_t VMPI_getVMPageCount(size_t /*pageSize*/)
{
	size_t private_bytes = 0;
	kern_return_t ret;
	task_t task = mach_task_self();
	
	vm_size_t pagesize = 0;
	ret = host_page_size(mach_host_self(), &pagesize);
	
	vm_address_t addr = VM_MIN_ADDRESS;
	vm_size_t size = 0;
	while (true)
	{
		mach_msg_type_number_t count = VM_REGION_TOP_INFO_COUNT;
		vm_region_top_info_data_t info;
		mach_port_t object_name;
		
		addr += size;
		
#ifdef MMGC_64BIT
		ret = vm_region_64(task, &addr, &size, VM_REGION_TOP_INFO, (vm_region_info_t)&info, &count, &object_name);
#else
		ret = vm_region(task, &addr, &size, VM_REGION_TOP_INFO, (vm_region_info_t)&info, &count, &object_name);
#endif
		
		if (ret != KERN_SUCCESS)
			break;
		private_bytes += info.private_pages_resident;
	}
	return private_bytes;
}

// Call VMPI_getPerformanceFrequency() once to initialize its cache; avoids thread safety issues.
static uint64_t unused_value = VMPI_getPerformanceFrequency();

uint64_t VMPI_getPerformanceFrequency()
{
	// *** NOTE ABOUT THREAD SAFETY ***
	//
	// These statics ought to be safe because they are initialized by a call at startup
	// (see lines above this function), before any AvmCores are created.
	
	static mach_timebase_info_data_t info;
	static uint64_t frequency = 0;
	if ( frequency == 0 ) {
		(void) mach_timebase_info(&info);
		frequency = (uint64_t) ( 1e9 / ((double) info.numer / (double) info.denom) );
	}
	return frequency;
}

uint64_t VMPI_getPerformanceCounter()
{
	return mach_absolute_time();
}

#ifdef MMGC_MEMORY_PROFILER

#ifdef MMGC_PPC

bool VMPI_captureStackTrace(uintptr_t* buffer, size_t len, uint32_t skip) 
{
	register int stackp;
	uintptr_t pc;
	asm("mr %0,r1" : "=r" (stackp));
	while(skip--) {
	    stackp = *(int*)stackp;
	}
	size_t i=0;
	// save space for 0 terminator
	len--;
	while(i<len && stackp) {
	    pc = *((uintptr_t*)stackp+2);
	    buffer[i++]=pc;
	    stackp = *(int*)stackp;
	}
	buffer[i] = 0;
	return true;
}
#endif

#if (defined(MMGC_IA32) || defined(MMGC_AMD64))

bool VMPI_captureStackTrace(uintptr_t* buffer, size_t bufferSize, uint32_t skip) 
{
	void **ebp;
#ifdef MMGC_IA32
	asm("mov %%ebp, %0" : "=r" (ebp));
#else
	asm("mov %%rbp, %0" : "=r" (ebp));
#endif
	
	if (skip)
		--skip;
	
	while(skip-- && *ebp)
	{
		ebp = (void**)(*ebp);
	}
	
	bufferSize--;
	size_t i=0;
	while(i<bufferSize && *ebp)
	{
		buffer[i++] = *((uintptr_t*)ebp+1);
		ebp = (void**)(*ebp);			
	}
	buffer[i] = 0;
	return true;
}
#endif

int parent2child[2];	//pipe to send data from parent to child
int child2parent[2];	//pipe to send data from child to parent

#define PARENT_READ_END		parent2child[0]
#define PARENT_WRITE_END	parent2child[1]
#define CHILD_READ_END		child2parent[0]
#define CHILD_WRITE_END		child2parent[1]

pid_t atos_pid = -1;	//process id for child process executing atos
#define IS_ATOS_RUNNING	(atos_pid > 0) //macro to check whether atos was launched successfully during setup

void VMPI_setupPCResolution()
{
#ifndef _DEBUG
	bool child2parent_open = false;
	
	bool parent2child_open = pipe(parent2child) >= 0;
	if(!parent2child_open)
	{
		goto exit_cleanly;
	}
	
	child2parent_open = pipe(child2parent) >= 0;
	if(!child2parent_open)
	{
		goto exit_cleanly;
	}
	
	pid_t current_pid = getpid();
	
	//fork a child process to launch atos
	if((atos_pid = fork()) == -1) 
	{ 
		goto exit_cleanly;
	}
	
	if(atos_pid == 0) //child process - for atos
	{
		//close unused pipe ends for child process
		close(PARENT_WRITE_END);
		close(CHILD_READ_END);
		
		dup2(PARENT_READ_END, 0); //tie parent's read end to stdin
		dup2(CHILD_WRITE_END, 1); //tie child's write end to stdout
		
		//close duped pipe ends
		close(PARENT_READ_END);
		close(CHILD_WRITE_END);
		
		char pid_str[16];
		sprintf(pid_str, "%u", current_pid);
		
		//Invoke atos in interactive mode
		execl("/usr/bin/atos", "/usr/bin/atos", "-p", pid_str, (char*)0); 
					
		exit(0); //exit child process
	}
	
	//parent process
	
	//close unused pipe ends for parent process
	close(PARENT_READ_END);
	close(CHILD_WRITE_END);
	
	return;
	
exit_cleanly:
	if(parent2child_open)
	{
		close(PARENT_READ_END);
		close(PARENT_WRITE_END);
	}
	
	if(child2parent_open)
	{
		close(CHILD_READ_END);
		close(CHILD_WRITE_END);
	}
#endif
}

void VMPI_desetupPCResolution()
{
#ifndef _DEBUG
	if(IS_ATOS_RUNNING)
	{
		kill(atos_pid, SIGINT); //send a termination signal to 
		
		int status;
		waitpid(atos_pid, &status, 0); //wait for child process to terminate
		
		//close open pipe ends
		close(PARENT_WRITE_END);
		close(CHILD_READ_END);
	}
#endif
}

bool VMPI_getFunctionNameFromPC(uintptr_t pc, char *buffer, size_t bufferSize)
{
#ifdef _DEBUG

	Dl_info dlip;
	int ret = dladdr((void * const)pc, &dlip);
	const char *sym = dlip.dli_sname;
	if(ret != 0 && sym) {
		size_t sz=bufferSize;
		int status=0;
		char *out = (char*) malloc(bufferSize);
		char *ret = abi::__cxa_demangle(sym, out, &sz, &status);
		if(ret) {
			out = ret; // apparently demangle may realloc, so free this instead of out
			VMPI_strncpy(buffer, ret, bufferSize);
		} else {
			VMPI_strncpy(buffer, sym, bufferSize);
		}
		free(out); 
		return true;
	}


#else
	
	if(IS_ATOS_RUNNING)
	{
		char buf[128];
	#ifdef MMGC_64BIT
		VMPI_snprintf(buf, sizeof(buf), "0x%x\n", (uint64_t)pc);
	#else
		VMPI_snprintf(buf, sizeof(buf), "0x%x\n", (uint32_t)pc);
	#endif
		write((PARENT_WRITE_END), buf, strlen(buf)); //send the address to atos

		//start reading into the return buffer i.e. "buffer"
		char* b = buffer;
		size_t readCount = bufferSize-1; //leave space for null character
		
		int r;
		do
		{
			int r  = read(CHILD_READ_END, b, readCount); //read the results from atos
			if(r <= 0)
				break;
			
			b[readCount] = '\0'; //null terminate for strrchr
			char* p = VMPI_strrchr(b, '\n'); //look for a newline character
			
			if(p)
			{
				//replace trailing newline with null character
				//note: the caller is not expecting the buffer to be null terminated
				//but for formatting purposes we don't want to return a string with a 
				//trailing newline
				*p = '\0';
				return true;
			}
			else
			{
				readCount -= r;
				if(readCount == 0) 
				{
					//if we run out of buffer then use the local buffer
					//this data would be thrown away but we want to ensure
					//that the pipe is empty before we return
					b = buf;
					readCount = sizeof(buf) - 1; //leave space for null character
				}
				else
				{
					b += r; //continue read in the current buffer
				}
			}
		}
		while(true);
		
		return (b != buffer); //return true if we atleast have some data
	}

#endif
	
	return false;
}

bool VMPI_getFileAndLineInfoFromPC(uintptr_t pc, char *buffer, size_t bufferSize, uint32_t* lineNumber) 
{
	(void)buffer;
	(void)pc;
	(void)bufferSize;
	(void)lineNumber;
	return false;
}

#endif //MMGC_MEMORY_PROFILER
