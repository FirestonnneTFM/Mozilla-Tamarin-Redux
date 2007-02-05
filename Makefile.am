## Makefile.am -- Process this file with automake to produce Makefile.in

SUBDIRS = MMgc

INCLUDES = \
	-I$(top_srcdir)/avmglue \
	-I$(top_srcdir)/avmplus/MMgc \
	-I$(top_srcdir)/avmplus/codegen \
	-I$(top_srcdir)/avmplus/core \
	-I$(top_srcdir)/avmplus/extensions \
	-I$(top_srcdir)/avmplus/pcre \
	-I$(top_srcdir)/avmplus/shell \
	-I$(top_srcdir)/core \
	-I$(top_srcdir)/platform \
	-I$(top_srcdir)/platform/generic \
	-I$(top_srcdir)/platform/unix \
	-I$(top_srcdir)/saffron/include \
	-I$(top_srcdir)/shared_tcserver 

######################################################################
######################################################################

noinst_LTLIBRARIES = libavmplus.la

libavmplus_la_CXXFLAGS = \
	-DAVMPLUS_CDECL \
	-DAVMPLUS_SHELL \
	-DAVMPLUS_NOVIRTUAL \
	-DCYGWIN \
	-DENABLE_COMPILER 

libavmplus_la_SOURCES = \
	codegen/CodegenMIR.cpp \
	codegen/Ia32Assembler.cpp \
	core/AbcData.cpp \
	core/AbcEnv.cpp \
	core/AbcGen.cpp \
	core/AbcParser.cpp \
	core/AbstractFunction.cpp \
	core/ActionBlockConstants.cpp \
	core/ArrayClass.cpp \
	core/ArrayObject.cpp \
	core/AtomArray.cpp \
	core/AtomConstants.cpp \
	core/AvmCore.cpp \
	core/AvmDebugUnix.cpp \
	core/AvmPlusScriptableObject.cpp \
	core/BigInteger.cpp \
	core/BooleanClass.cpp \
	core/builtin.cpp \
	core/BuiltinTraits.cpp \
	core/ClassClass.cpp \
	core/ClassClosure.cpp \
	core/Date.cpp \
	core/DateClass.cpp \
	core/DateObject.cpp \
	core/Domain.cpp \
	core/DomainEnv.cpp \
	core/DynamicProfiler.cpp \
	core/E4XNode.cpp \
	core/ErrorClass.cpp \
	core/ErrorConstants.cpp \
	core/Exception.cpp \
	core/FrameState.cpp \
	core/FunctionClass.cpp \
	core/GrowableBuffer.cpp \
	core/IntClass.cpp \
	core/Interpreter.cpp \
	core/MathClass.cpp \
	core/MathUtils.cpp \
	core/MethodClosure.cpp \
	core/MethodEnv.cpp \
	core/MethodInfo.cpp \
	core/Multiname.cpp \
	core/MultinameHashtable.cpp \
	core/Namespace.cpp \
	core/NamespaceClass.cpp \
	core/NamespaceSet.cpp \
	core/NativeFunction.cpp \
	core/NumberClass.cpp \
	core/ObjectClass.cpp \
	core/PoolObject.cpp \
	core/PrintWriter.cpp \
	core/RegExpClass.cpp \
	core/RegExpObject.cpp \
	core/ScopeChain.cpp \
	core/ScriptBuffer.cpp \
	core/ScriptObject.cpp \
	core/StackTrace.cpp \
	core/StaticProfiler.cpp \
	core/StringBuffer.cpp \
	core/StringClass.cpp \
	core/StringObject.cpp \
	core/Toplevel.cpp \
	core/Traits.cpp \
	core/UnicodeUtils.cpp \
	core/VTable.cpp \
	core/Verifier.cpp \
	core/XMLClass.cpp \
	core/XMLListClass.cpp \
	core/XMLListObject.cpp \
	core/XMLObject.cpp \
	core/XMLParser16.cpp \
	core/avmplus.cpp \
	core/avmplusDebugger.cpp \
	core/avmplusHashtable.cpp \
	core/avmplusProfiler.cpp \
	core/builtin.cpp \
	core/opcodes.cpp \
	pcre/pcre_chartables.cpp \
	pcre/pcre_compile.cpp \
	pcre/pcre_config.cpp \
	pcre/pcre_exec.cpp \
	pcre/pcre_fullinfo.cpp \
	pcre/pcre_get.cpp \
	pcre/pcre_globals.cpp \
	pcre/pcre_info.cpp \
	pcre/pcre_maketables.cpp \
	pcre/pcre_ord2utf8.cpp \
	pcre/pcre_refcount.cpp \
	pcre/pcre_study.cpp \
	pcre/pcre_tables.cpp \
	pcre/pcre_try_flipped.cpp \
	pcre/pcre_valid_utf8.cpp \
	pcre/pcre_version.cpp \
	pcre/pcre_xclass.cpp \
	platform/unix/DateUnix.cpp \
	platform/unix/MathUtilsUnix.cpp \
	platform/unix/OSDepUnix.cpp 

######################################################################
######################################################################

noinst_PROGRAMS = avmplus

avmplus_CXXFLAGS = \
	-DAVMPLUS_CDECL \
	-DAVMPLUS_SHELL \
	-DCYGWIN \
	-DENABLE_COMPILER 

avmplus_SOURCES = \
	shell/SystemClass.cpp \
	shell/StringBuilderClass.cpp \
	shell/FileClass.cpp \
	shell/TypedArrayClass.cpp \
	shell/FileInputStream.cpp \
	shell/DomainClass.cpp \
	shell/DebugCLI.cpp \
	shell/DataIO.cpp \
	shell/ConsoleOutputStream.cpp \
	shell/ByteArrayGlue.cpp \
	shell/avmshell.cpp \
	extensions/DictionaryGlue.cpp \
	extensions/JavaGlue.cpp \
	platform/unix/unixcpuid.cpp 

avmplus_DEPENDENCIES = \
	libavmplus.la 

avmplus_LDFLAGS = \
	libavmplus.la \
	MMgc/libmmgc.la \
	-lpthread \
	-lz
