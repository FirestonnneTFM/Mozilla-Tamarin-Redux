## Makefile.am -- Process this file with automake to produce Makefile.in

INCLUDES = \
	-I$(top_srcdir)/avmplus/codegen \
	-I$(top_srcdir)/avmplus/core

noinst_LTLIBRARIES = libmmgc.la

if BUILD_DEBUG
libmmgc_la_CXXFLAGS = \
	-fexceptions 
endif

libmmgc_la_SOURCES = \
	FixedAlloc.cpp \
	FixedMalloc.cpp \
	GC.cpp \
	GCAlloc.cpp \
	GCAllocObjectUnix.cpp \
	GCDebugUnix.cpp \
	GCGlobalNew.cpp \
	GCHashtable.cpp \
	GCHeap.cpp \
	GCHeapUnix.cpp \
	GCLargeAlloc.cpp \
	GCMemoryProfiler.cpp \
	GCObject.cpp \
	GCTests.cpp 
