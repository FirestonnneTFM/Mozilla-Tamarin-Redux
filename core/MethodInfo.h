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

#ifndef __avmplus_MethodInfo__
#define __avmplus_MethodInfo__


#ifdef verify
#undef verify
#endif

namespace avmplus
{
	typedef Atom (*AtomMethodProc)(MethodEnv*, int, uint32 *);
	typedef double (*DoubleMethodProc)(MethodEnv*, int, uint32 *);

#ifdef DEBUGGER
	class AbcFile;
	class DebuggerMethodInfo : public MMgc::GCObject
	{
	public:
		inline explicit DebuggerMethodInfo(int32_t _local_count, uint32_t _codeSize, int32_t _max_scopes) :
			firstSourceLine(0),
			lastSourceLine(0),
			offsetInAbc(0),
			local_count(_local_count), 
			codeSize(_codeSize), 
			max_scopes(_max_scopes) {}

		DWB(AbcFile*)			file;				// the abc file from which this method came
		int32_t					firstSourceLine;	// source line number where function starts
		int32_t					lastSourceLine;		// source line number where function ends
		int32_t					offsetInAbc;		// offset in abc file
		uint32_t				codeSize;			// abc size pre-jit, native size post jit
		const int32_t			local_count;		// FIXME: merge with localCount above; this one may be visible to a debugger?
		const int32_t			max_scopes;			// FIXME: merge with maxScopeDepth above; this one is not used by the VM but may be visible to a debugger?
		Stringp					localNames[1];		// array of names for args and locals in framep order, written with explicit WBRC (actually local_count)
	};
#endif

	/**
	 * MethodInfo is the base class for all functions that
	 * can be executed by the VM: Actionscript functions,
	 * native functions, etc.
	 */
#ifdef AVMPLUS_TRAITS_MEMTRACK
	class MethodInfo : public MMgc::GCFinalizedObject
#else
	class MethodInfo : public MMgc::GCObject
#endif
	{
	public:
		/** @name flags from .abc - limited to a BYTE */
		/*@{*/
		/** need arguments[0..argc] */
		static const int NEED_ARGUMENTS		= 0x00000001;

		/** need activation object */
		static const int NEED_ACTIVATION	= 0x00000002;

		/** need arguments[param_count+1..argc] */		
		static const int NEED_REST          = 0x00000004;

		/** has optional parameters */
		static const int HAS_OPTIONAL       = 0x00000008;

		/** allow extra args, but dont capture them */
		static const int IGNORE_REST        = 0x00000010;

		/** method is native */
		static const int NATIVE				= 0x00000020;

		/** method sets default namespace */
		static const int SETS_DXNS			= 0x00000040;

		/** method has table for parameter names */
		static const int HAS_PARAM_NAMES	= 0x00000080;

		/*@}*/

		/** @name internal flags - upper 3 BYTES available */
		/*@{*/
		static const int UNUSED_0x00000100	= 0x00000100;
		static const int UNUSED_0x00000200	= 0x00000200;
		static const int UNUSED_0x00000400	= 0x00000400;
		static const int UNUSED_0x00000800	= 0x00000800;
		static const int UNUSED_0x00001000	= 0x00001000;
		static const int UNUSED_0x00002000	= 0x00002000;

		// set iff this is a getter
		static const int IS_GETTER			= 0x00004000;

		// set iff this is a setter
		static const int IS_SETTER			= 0x00008000;

		static const int OVERRIDE           = 0x00010000;

		static const int NON_INTERRUPTABLE	= 0x00020000;

		static const int UNBOX_THIS         = 0x00040000;

		static const int NEEDS_CODECONTEXT  = 0x00080000;

		static const int HAS_EXCEPTIONS		= 0x00100000;

#ifdef AVMPLUS_VERBOSE
		static const int VERBOSE_VERIFY		= 0x00200000;
#endif

		static const int NEEDS_DXNS			= 0x00400000;

		static const int VERIFIED			= 0x00800000;

#ifdef AVMPLUS_VERIFYALL
		static const int VERIFY_PENDING		= 0x01000000;
#endif

		/** indicates method is final, no overrides allowed */
		static const int FINAL				= 0x02000000;

		/** indicates the function is a method, that pushes the
		    receiver object onto the scope chain at method entry */
		static const int NEED_CLOSURE       = 0x04000000;

		/** set to indicate that a function has no bytecode body. */
		static const int ABSTRACT_METHOD	= 0x08000000;

		static const int UNUSED_0x10000000      = 0x10000000;

		/**
		 * set once the signature types have been resolved and
		 * override signatures have been checked.
		 */
		static const int LINKED             = 0x20000000;

		/**
		 * set to indictate that a function has been 
		 * recommended to be interpreted. 
		 */
		static const int SUGGEST_INTERP		= 0x40000000;

		/**
		 * set to indicate that a function has been compiled
		 * to native code by the jit compiler.
		 */
		static const int JIT_IMPL			= 0x80000000;

		/*@}*/

	public:

		uintptr iid() const
		{
			return ((uintptr)this)>>3;
		}

		bool usesCallerContext() const;

		// Builtin + non-native functions always need the dxns code emitted 
		// Builtin + native functions have flags to specify if they need the dxns code
		bool usesDefaultXmlNamespace() const;

		void initParamTypes(int count);
		void initDefaultValues(int count);

		void resolveSignature(const Toplevel* toplevel);

		bool argcOk(int argc)
		{
			return argc >= param_count-optional_count && 
				(argc <= param_count || allowExtraArgs());
		}

    public:
		MethodInfo(int _method_id, const NativeMethodInfo* native_info);
#if defined FEATURE_NANOJIT
		MethodInfo(void* tramp);
#endif

		static Atom verifyEnter(MethodEnv* env, int argc, uint32* ap);

#ifdef DEBUGGER
		static AvmBox debugEnterExitWrapper32(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
		static double debugEnterExitWrapperN(AvmMethodEnv env, uint32_t argc, AvmBox* argv);

		void initDMI(int32_t local_count, uint32_t codeSize, int32_t max_scopes);

		void boxLocals(void* src, int srcPos, Traits** traitArr, Atom* dest, int destPos, int length);
		void unboxLocals(Atom* src, int srcPos, Traits** traitArr, void* dest, int destPos, int length);

		void setFile(AbcFile* file);
		void setRegName(int index, Stringp name);

		inline Stringp getLocalName(int index) const { return getRegName(index+param_count); }
		inline Stringp getArgName(int index) const { return getRegName(index); }

		AbcFile* file() const;
		int32_t firstSourceLine() const;
		int32_t lastSourceLine() const;
		int32_t offsetInAbc() const;
		uint32_t codeSize() const;
		int32_t local_count() const;
		int32_t max_scopes() const;

		void updateSourceLines(int32_t linenum, int32_t offset);

	private:
		Stringp getRegName(int index) const;
#endif

	public:

		void verify(Toplevel* toplevel);
        void setInterpImpl();

	public:
		
		void setParamType(int index, Traits* t);
		void setDefaultValue(int index, Atom defaultValue);
		void makeIntoPrototypeFunction(const Toplevel* toplevel);

		Traits* paramTraits(int index) const {
			AvmAssert(index >= 0 && index <= param_count);
			return m_types[index];
		}

		Atom getDefaultValue(int i) const {
			return m_values[i];
		}

		void setReturnType(Traits* t) {
			m_returnType = t;
		}

		Traits* returnTraits() const {
			return m_returnType;
		}

		int requiredParamCount() const {
			return param_count-optional_count;
		}

		int allowExtraArgs() const {
			return isFlagSet(NEED_REST|NEED_ARGUMENTS|IGNORE_REST);
		}

		int hasMethodBody() const {
			return !isFlagSet(ABSTRACT_METHOD);
		}

		int isFlagSet(int f) const {
			return (flags & f);
		}

		int hasExceptions() const {
			return flags & HAS_EXCEPTIONS;
		}

		int setsDxns() const {
			return flags & SETS_DXNS;
		}

		int isNative() const {
			return flags & NATIVE;
		}

		bool makeMethodOf(Traits* type);

#ifdef AVMPLUS_VERIFYALL
		int isVerified() const {
			return flags & VERIFIED;
		}
#endif

		void boxArgs(int argc, uint32 *ap, Atom* out);

#ifdef AVMPLUS_TRAITS_MEMTRACK
	protected:
		virtual ~MethodInfo();
#endif

	public:

#if VMCFG_METHOD_NAMES
		Stringp FASTCALL getMethodName() const;
#endif		

#ifdef AVMPLUS_VERBOSE
		Stringp format(AvmCore* core) const;
#endif
#ifdef DEBUGGER
		uint32 size() const;
#endif

	public:

		inline AvmThunkNativeThunker thunker() const { AvmAssert(isNative()); return _native.thunker; }
		inline AvmThunkNativeMethodHandler handler_method() const { AvmAssert(isNative()); return _native.handler.method; }
		inline AvmThunkNativeFunctionHandler handler_function() const { AvmAssert(isNative()); return _native.handler.function; }

		inline const uint8_t* abc_body_pos() const { AvmAssert(!isNative()); return _abc.body_pos; }
		inline void set_abc_body_pos(const uint8_t* p) { AvmAssert(!isNative()); _abc.body_pos = p; }
		inline void set_abc_body_pos_wb(MMgc::GC* gc, const uint8_t* p) { AvmAssert(!isNative()); WB(gc, this, &_abc.body_pos, p); }

		inline ExceptionHandlerTable* abc_exceptions() const { AvmAssert(!isNative()); return _abc.exceptions; }
		inline void set_abc_exceptions(MMgc::GC* gc, ExceptionHandlerTable* e) { AvmAssert(!isNative()); WB(gc, this, &_abc.exceptions, e); }

		inline uint32_t abc_frame_size() const { AvmAssert(!isNative()); return _abc.frameSize; }
		inline uint32_t abc_local_count() const { AvmAssert(!isNative()); return _abc.localCount; }
		inline uint32_t abc_max_scope_depth() const { AvmAssert(!isNative()); return _abc.maxScopeDepth; }

		inline void set_abc_frame_info(uint32_t frameSize, uint32_t localCount, uint32_t maxScopeDepth)
		{
			AvmAssert(!isNative()); 
		#ifdef AVMPLUS_64BIT
			_abc.frameSize = frameSize;
		#else
			// The interpreter wants this to be padded to a doubleword boundary because
			// it allocates two objects in a single alloca() request - the frame and
			// auxiliary storage, in that order - and wants the second object to be
			// doubleword aligned.
			_abc.frameSize = (frameSize + 1) & ~1;
		#endif
			_abc.frameSize = frameSize;
			_abc.localCount = localCount;
			_abc.maxScopeDepth = maxScopeDepth;
		}

	#ifdef AVMPLUS_WORD_CODE

		inline ExceptionHandlerTable* word_code_exceptions() const { AvmAssert(!isNative()); return _abc.word_code.exceptions; }
		inline void set_word_code_exceptions(MMgc::GC* gc, ExceptionHandlerTable* e) { AvmAssert(!isNative()); WB(gc, this, &_abc.word_code.exceptions, e); }

		inline const uintptr_t* word_code_start() const { AvmAssert(!isNative()); return _abc.word_code.codeStart; }
		inline void set_word_code_start(MMgc::GC* gc, MMgc::GCObject* anchor, const uintptr_t* start) 
		{ 
			AvmAssert(!isNative()); 
			_abc.word_code.codeStart = start; 
			WB(gc, this, &_abc.word_code.code_anchor, anchor);
		}

		inline int word_code_cache_size() const { AvmAssert(!isNative()); return _abc.word_code.cache_size; }
		inline void set_word_code_cache_size(int s) { AvmAssert(!isNative()); _abc.word_code.cache_size = s; }
	
	#else

		inline const uint8_t* abc_code_start() const { AvmAssert(!isNative()); return _abc.abc_codeStart; }
		inline void set_abc_code_start(const uint8_t* p) { AvmAssert(!isNative()); _abc.abc_codeStart = p; }
	
	#endif

	private:
		struct NativeInfo
		{
			AvmThunkNativeThunker thunker;
			AvmThunkNativeHandler handler;
		};

		struct AbcInfo
		{
			const uint8_t*			body_pos;
			ExceptionHandlerTable*	exceptions;		// we write this once, in Verifier, with an explicit WB.  so no DWB.
			uint32_t				frameSize;			// total size of frame in number of Atoms
			uint32_t				localCount;			// maximum number of local registers
			uint32_t				maxScopeDepth;		// maximum depth of local scope stack
	#ifdef AVMPLUS_WORD_CODE
			struct 
			{
				MMgc::GCObject*			code_anchor;	// The object that contains the code pointed to by body_pos, written with explicit WB
				const uintptr_t*		codeStart;		// pointer to first instruction
				// We write this once, in WordcodeTranslator, with an explicit WB.  so no DWB.
				// The contents are the same as the 'exceptions' structure above, except the 'from', 'to', and 'target' fields.
				ExceptionHandlerTable*	exceptions;
				int						cache_size;     // Number of items in lookup cache
			} word_code;
	#else
			const uint8_t*		abc_codeStart;			// pointer to first instruction
	#endif
		};

	// ------------------------ DATA SECTION BEGIN
	public:
		// these are most-frequently accessed so put at offset zero
		union 
		{
			AtomMethodProc impl32;
			DoubleMethodProc implN;
		};
		DWB(Traits*)		declaringTraits;
		DWB(Traits*)		activationTraits;
		DWB(PoolObject*)	pool;
	private:
		DWB(Traits*)		m_returnType;
		DWB(Traits**)		m_types;		// actual length will be 1+param_count
		DWB(Atom*)			m_values;		// default values for any optional params. size = optional_count
#ifdef DEBUGGER
		DebuggerMethodInfo*			m_dmi;			// written with explicit DWB
#endif
	public:
		const byte*	abc_info_pos;			// pointer to abc MethodInfo record 
		int			param_count;		// number of declared parameters including optionals 
		int			optional_count;		// last optional_count params are optional 
		int			restOffset;			// offset to first rest arg, including the instance parameter. this is sum(sizeof(paramType(0..N)))
		int			flags;				// see bitmask defs above 
		const int	method_id;
	private:
		union 
		{
			NativeInfo	_native;		// stuff used only for Native methods (formerly in NativeMethod)
			AbcInfo		_abc;			// stuff used only for bytecode methods (formerly in MethodInfo)
		};
	// ------------------------ DATA SECTION END
	};
}

#endif /* __avmplus_MethodInfo__ */
