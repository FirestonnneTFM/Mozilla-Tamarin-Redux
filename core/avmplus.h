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


#ifndef __avmplus__
#define __avmplus__

/*! \mainpage AVM+ Documentation
 *
 * \section intro Introduction
 *
 * AVM+ is the ActionScript Virtual Machine
 *
 * AVM+ offers an order of magnitude performance increase over
 * the "Classic AVM" in Flash Player 7.  Our performance target is 10X.
 *
 * AVM+ implements ActionScript 3.0, the new version of the ActionScript
 * language that is compliant with the ECMAScript Edition 4 standard.
 *
 * AVM+ is also built for modularity.  It will be part of the Flash Player,
 * but is a self-contained module which can be incorporated into other
 * programs with ease.  It may also be submitted to the ECMA standards
 * organization as a reference implementation of ECMAScript Edition 4.
 *
 * \section usage Using This Document
 *
 * This documentation is a reference manual for C++ developers working
 * with AVM+, either in the context of the Flash Player or in another
 * application.  It can be useful for developers enhancing AVM+
 * itself, or for developer who wish to understand its internals
 * in order to better interface with it.
 *
 * \section begin Where To Begin
 *
 * The avmplus::AvmCore class is the main entry point of the
 * AVM+ virtual machine, and is probably a good place to start
 * when trying to comprehend the codebase.
 *
 * \section contact Who To Contact
 *
 * For questions about AVM+, please contact:
 *
 * Gary Grossman (ggrossman@macromedia.com)<br>
 * Edwin Smith (edsmith@macromedia.com)<br>
 * Jeff Dyer (jdyer@macromedia.com)
 */
 
// Needed for memset, memcpy et al.
#include <string.h>

#include "avmbuild.h"

#if defined(_MAC)
#include <alloca.h>
#endif

#ifdef UNIX
	#ifndef AVMPLUS_SYMBIAN
		#include <stdint.h>
	#endif
	#ifdef HAVE_ALLOCA_H
		#include <alloca.h>
	#else // HAVE_ALLOCA_H
		#include <stdlib.h>
	#endif // HAVE_ALLOCA_H
#endif // UNIX

#ifdef WIN32
	#include <windows.h>
	#include <malloc.h>
	#include <math.h>
	#ifdef AVMPLUS_ARM
		typedef unsigned int uintptr_t;
	#else
		#ifdef AVMPLUS_AMD64
			#include <setjmpex.h>
		#endif
		// Newer versions of the Windows SDK set up the intrinsics slightly differently
		// than VC8. Only include intrin.h if the SDK doesn't declare it.
		#ifndef InterlockedBitTestAndSet
			#include <intrin.h>
		#endif
		#include <emmintrin.h>
		#ifdef VTUNE
			#include "JITProfiling.h"
		#endif
	#endif // AVMPLUS_ARM
#endif // WIN32

#include <stdarg.h>

#include "avmsetjmp.h"

#include "avmplusTypes.h"
#include "avmplusVersion.h"
#include "AvmDebug.h"
#include "AtomConstants.h"
#include "ActionBlockConstants.h"
#include "AvmError.h"
#include "ErrorConstants.h"
#include "NativeObjectHelpers.h"

using namespace avmplus::AtomConstants;
using namespace avmplus::ActionBlockConstants;
using namespace avmplus::ErrorConstants;

/**
 * Incomplete class definitions for everything in AVM+
 */
namespace avmplus
{
	class AbcGen;
	class AbcEnv;
	class AbcParser;
	class AbstractFunction;
	class Accessor;
	class ArrayClass;
	class ArrayObject;
	class Atan2Method;
	class AtomArray;
	class AvmCore;
	class BooleanClass;
	class BufferGuard;
	class BuiltinTraits;
	class CallStackNode;
	class ClassClass;
	class ClassClosure;
	class Closure;
	class CodeContext;	
	class Console;
	class Date;
	class DateClass;
	class DateObject;
	class Debugger;
	class Domain;
	class DomainEnv;
	class E4XNode;
	class ErrorClass;
	class ErrorObject;
	class Exception;
	class ExceptionFrame;
	class ExceptionHandler;
	class ExceptionHandlerTable;
	class FrameState;
	class GrowableBuffer;
	class Hashtable;
	class HeapMultiname;
	class IntVectorObject;
	class DoubleVectorObject;
	class UIntVectorObject;
	class ObjectVectorObject;
	class Java;
	class MathClass;
	class MathUtils;
	class MethodClosure;
	class MethodEnv;
	class MethodInfo;
	class Multiname;
	class Namespace;
	class NamespaceSet;
	class NamespaceClass;
	class NativeMethod;
	class NativeClassFactory;
	class NativeInitializer;
	class NativeScriptFactory;
	struct NativeMethodInfo;
	class NumberClass;
	class IntClass;
	class UIntClass;
	class OSDep;
	class ObjectClass;
	class OutputStream;
	class PoolObject;
	class PrintWriter;
	class Profiler;
	class RegExpClass;
	class RegExpObject;
	class Sampler;
	class ScopeChain;
	class ScopeTypeChain;
	class ScriptBuffer;
	class ScriptEnv;
	class ScriptObject;
	class StackTrace;
	class StringBuffer;
	class StringClass;
	class String;
	class Toplevel;
	class Traits;
#ifdef AVMPLUS_TRAITS_CACHE
	class TraitsBindings;
	class TraitsMetadata;
#endif
	class WordcodeTranslator;
	class WordcodeEmitter;
	class UnicodeUtils;
	class Value;
	class Verifier; 
	class VTable; 
	class VoidClass;
	class XMLClass;
	class XMLListClass;
	class XMLObject;
	class XMLListObject;
	class QNameClass;
	class QNameObject;
	class XMLParser;
	class XMLTag;

	struct NativeClassInfo;
	struct NativeScriptInfo;
	struct NativeMethodInfo;
	struct WordOpcodeAttr;

	typedef Traits* Traitsp;
	// Stringp and Namespacep should be const, but RCObject doens't allow it yet
	typedef String* Stringp;
	typedef Namespace* Namespacep;
	typedef const NamespaceSet* NamespaceSetp;
#ifdef AVMPLUS_TRAITS_CACHE
	typedef const TraitsBindings* TraitsBindingsp;
	typedef const TraitsMetadata* TraitsMetadatap;
#endif

	typedef const NativeScriptInfo* NativeScriptInfop;
	typedef const NativeClassInfo* NativeClassInfop;
	typedef const NativeMethodInfo* NativeMethodInfop;
	#define AVMTHUNK_NativeClassInfop_DEFINED
}

namespace avmplus
{
	typedef avmplus::AbcEnv* AvmInstance;
	typedef avmplus::ScriptObject* AvmObject;
	typedef avmplus::String* AvmString;
	typedef avmplus::Namespace* AvmNamespace;
	typedef avmplus::Atom AvmBox;
	typedef avmplus::MethodEnv* AvmMethodEnv;
	typedef uint32_t AvmBoolArg;

	#define AvmThunkRetType_AvmObject		(error ??? illegal) /* all Objects are return as AvmBox */
	typedef AvmBox AvmThunkRetType_AvmBoolArg;
	typedef AvmBox AvmThunkRetType_int32_t;
	typedef AvmBox AvmThunkRetType_uint32_t;
	typedef AvmBox AvmThunkRetType_AvmNamespace;
	typedef AvmBox AvmThunkRetType_AvmBox;
	typedef AvmBox AvmThunkRetType_AvmString;
	typedef AvmBox AvmThunkRetType_void;
	typedef double AvmThunkRetType_double;

	#define AVMTHUNK_CALLTYPE	 /* could be used to declare custom call type (eg __fastcall) */

	typedef AvmThunkRetType_AvmBox (*AvmThunkNativeThunker)(AvmMethodEnv env, uint32_t argc, const AvmBox* argv);
}

#include "MMgc.h"

// disambiguate some common types, without opening all of MMgc namespace
using MMgc::GC;
using MMgc::GCObject;
using MMgc::GCFinalizedObject;
using MMgc::GCHeap;

#define MMGC_SUBCLASS_DECL : public GCObject

#ifdef AVMPLUS_TRAITS_CACHE
#include "QCache.h"
#endif
#include "GrowableBuffer.h"
#include "MathUtils.h"
#include "UnicodeUtils.h"
#include "OSDep.h"
#include "OutputStream.h"
#include "ScriptBuffer.h"
#include "avmplusList.h"
#include "avmplusStack.h"
#include "SortedIntMap.h"
#include "BitSet.h"
#include "AvmPlusScriptableObject.h"
#include "Namespace.h"
#include "StringObject.h"
#include "MultinameHashtable.h"
#include "PrintWriter.h"
#include "BuiltinTraits.h"
#include "NamespaceSet.h"
#include "Multiname.h"
#include "Sampler.h"
#include "AvmCore.h"
#include "AtomWriteBarrier.h"
#include "avmplusHashtable.h"
#include "CodeContext.h"
#include "AbstractFunction.h"
#include "PoolObject.h"
#include "AbcEnv.h"
#include "Traits.h"
#include "TraitsIterator.h"
#include "VTable.h"
#include "MethodEnv.h"
#include "ScopeChain.h"
#include "ScriptObject.h"
#include "avmplusProfiler.h"
#include "StringBuffer.h"
#include "AtomArray.h"
#include "wopcodes.h"
#include "WordcodeTranslator.h"
#include "WordcodeEmitter.h"
#include "Verifier.h"
#include "NativeFunction.h"
#include "ClassClosure.h"
#include "ClassClass.h"
#include "FunctionClass.h"
#include "MethodClosure.h"
#include "StackTrace.h"
#include "Exception.h"
#include "MethodInfo.h"
#include "NamespaceClass.h"
#include "ArrayObject.h"
#include "MethodClosure.h"
#include "BooleanClass.h"
#include "NumberClass.h"
#include "IntClass.h"
#include "ArrayClass.h"
#include "VectorClass.h"
#include "StringClass.h"
#include "Date.h"
#include "DateClass.h"
#include "DateObject.h"
#include "Domain.h"
#include "DomainEnv.h"
#include "ObjectClass.h"
#include "ErrorClass.h"
#include "MathClass.h"
#include "Toplevel.h"
#include "AbcParser.h"
#include "RegExpObject.h"
#include "RegExpClass.h"
#include "XMLClass.h"
#include "XMLListClass.h"
#include "XMLObject.h"
#include "XMLListObject.h"
#include "XMLParser16.h"
#include "Interpreter.h"
#include "avmplusDebugger.h"
#include "E4XNode.h"
#include "AbcGen.h"

#endif /* __avmplus__ */ 
