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

#ifndef __avmplus_MethodEnv__
#define __avmplus_MethodEnv__


namespace avmplus
{
#ifdef AVMPLUS_TRAITS_MEMTRACK
	class MethodEnvProcHolder : public MMgc::GCFinalizedObject
#else
	class MethodEnvProcHolder : public MMgc::GCObject
#endif
	{
		friend class CodegenLIR;

#if VMCFG_METHODENV_IMPL32
	protected:
		inline MethodEnvProcHolder(GprMethodProc p) : _implGPR(p) { }
	public:
		inline GprMethodProc implGPR() const { return _implGPR; }
		inline FprMethodProc implFPR() const { return _implFPR; }
	protected:
		union {
			GprMethodProc _implGPR;
			FprMethodProc _implFPR;
		};
#else
	protected:
		inline MethodEnvProcHolder(MethodInfo* m) : method(m) { }
	public:
		inline GprMethodProc implGPR() const { return method->implGPR(); }
		inline FprMethodProc implFPR() const { return method->implFPR(); }
	public:
		MethodInfo* const method;
#endif
	};
	
	class MethodEnv : public MethodEnvProcHolder
	{
		friend class CodegenLIR;
	#if VMCFG_METHODENV_IMPL32
		friend class MethodInfo;
		static uintptr_t delegateInvoke(MethodEnv* env, int argc, uint32 *ap);
	#endif
	public:
		/** vtable for the activation scope inside this method */
        ScriptObject* newActivation();

		/** getter lazily creates table which maps SO->MC */
		WeakKeyHashtable *getMethodClosureTable();

		MethodEnv(MethodInfo* method, ScopeChain* scope);

#ifdef AVMPLUS_TRAITS_MEMTRACK 
		virtual ~MethodEnv();
#endif

		REALLY_INLINE AbcEnv* abcEnv() const { return _scope->abcEnv(); }
		REALLY_INLINE AvmCore* core() const { return method->pool()->core; }
		REALLY_INLINE CodeContext* codeContext() const { return abcEnv()->codeContext(); }
		REALLY_INLINE DomainEnv* domainEnv() const { return abcEnv()->domainEnv(); }
		REALLY_INLINE ScopeChain* scope() const { return _scope; }
		REALLY_INLINE MethodEnv* super_init() const { AvmAssert(vtable()->base != NULL); return vtable()->base->init; }
		REALLY_INLINE Toplevel* toplevel() const { return vtable()->toplevel(); }
		inline Stringp traitsName() const { return vtable()->traits->name(); }
		inline Namespacep traitsNs() const { return vtable()->traits->ns(); }

		ScriptEnv* getScriptEnv(const Multiname *m) const;

		/**
		 * Coerces an array of actual parameters to the types
		 * required by a function's formal parameters, then invokes
		 * the method.  Args are provided as an array of atoms, not
		 * an array of native types.
		 *
		 * It is not well documented throughout, but it is generally
		 * assumed that argument arrays may /always/ be modified in
		 * place by the callee, thus coerceEnter may modify 'argv'
		 * (though not the ArrayObject 'a', of course).
		 *
		 * @param instance The "this" that the function
		 *                 is being invoked with; may be
		 *                 coerced by this method.
		 * @param argv The array of arguments to coerce
		 * @param argc The number of arguments
		 * @throws Exception May throw an ArgumentError or
		 *         TypeError if an argument cannot be coerced
		 *         to the required type
		 */
		Atom coerceEnter(Atom thisArg);
		Atom coerceEnter(Atom thisArg, ArrayObject* a);
		Atom coerceEnter(Atom thisArg, int argc, Atom* argv);
		Atom coerceEnter(int argc, Atom* argv);

	private:
		MethodSignaturep get_ms();
		inline bool isInterpreted();
		Atom endCoerce(int argc, uint32 *ap, MethodSignaturep ms);
		int  startCoerce(int argc, MethodSignaturep ms);
		Atom coerceUnboxEnter(int argc, Atom* atomv);
		void unboxCoerceArgs(Atom thisArg, ArrayObject *a, uint32 *argv, MethodSignaturep ms);
		void unboxCoerceArgs(int argc, Atom* in, uint32 *ap, MethodSignaturep ms);
		void unboxCoerceArgs(Atom thisArg, int argc, Atom* in, uint32 *argv, MethodSignaturep ms);
		void FASTCALL nullcheckfail(Atom atom);
		Atom* FASTCALL unbox1(Atom atom, Traits* t, Atom* args);

		VTable* getActivationVTable();
		VTable* buildActivationVTable();

	// helper functions used from compiled code
	public:
		/** null pointer check */
	    inline void nullcheck(Atom atom)
		{
			// Shark recommends inlining the isNullOrUndefined call
			if (AvmCore::isNullOrUndefined(atom))
				nullcheckfail(atom);
		}
		
	    void npe();

		ArrayObject* createRest(Atom* argv, int argc);
		Atom getpropertylate_i(Atom obj, int index) const;
		Atom getpropertylate_u(Atom obj, uint32 index) const;

#if defined FEATURE_NANOJIT
		void setpropertyHelper(Atom obj, /* not const */ Multiname *multi, Atom value, VTable *vtable, Atom index);
		void initpropertyHelper(Atom obj, /* not const */ Multiname *multi, Atom value, VTable *vtable, Atom index);
		Atom getpropertyHelper(Atom obj, /* not const */ Multiname *multi, VTable *vtable, Atom index);
		Atom delpropertyHelper(Atom obj, /* not const */ Multiname *multi, Atom index);

		void initMultinameLateForDelete(Multiname& name, Atom index);
		ArrayObject* createArgumentsHelper(int argc, uint32 *ap);
		ArrayObject* createRestHelper(int argc, uint32 *ap);
#endif

		ScriptObject* newcatch(Traits *traits);
		/**
		 * used for defining and resolving imported definitions.
		 */
		ScriptObject* finddef(const Multiname* name) const;

		/**
		 * implementation of object initializers
		 */
		ScriptObject* op_newobject(Atom* sp, int argc) const;

		/** Implementation of OP_nextname */		
		Atom nextname(Atom objAtom, int index) const;

		/** Implementation of OP_nextvalue */
		Atom nextvalue(Atom objAtom, int index) const;

		/** Implementation of OP_hasnext */		
		int hasnext(Atom objAtom, int index) const;

		/** Implementation of OP_hasnext2 */		
		int hasnextproto(Atom& objAtom, int& index) const;
		
		/** Implementation of memory op helpers */
		void mopRangeCheckFailed() const;

		/** Implementations of OP_lXXX */
		int li8(int addr) const;
		int li16(int addr) const;
		int li32(int addr) const;
		double lf32(int addr) const;
		double lf64(int addr) const;

		/** Implementations of OP_sXXX */
		void si8(int value, int addr) const;
		void si16(int value, int addr) const;
		void si32(int value, int addr) const;
		void sf32(double value, int addr) const;
		void sf64(double value, int addr) const;

		/** Implementations of OP_sxXXX */
		// (not actually used anywhere, left here for reference) */
		//inline static int sxi1(int value) { return (value << 31) >> 31; }
		//inline static int sxi8(int value) { return (value << 24) >> 24; }
		//inline static int sxi16(int value) { return (value << 16) >> 16; }

		/**
		 * OP_newfunction
		 * see 13.2 creating function objects
		 */
		ClassClosure* newfunction(MethodInfo *function, 
						 ScopeChain* outer,
						 Atom* scopes) const;

		/**
		 * OP_newclass
		 */

		ClassClosure* newclass(Traits* ctraits,
			          ClassClosure* base,
					  ScopeChain* outer,
					  Atom* scopes) const;

		void initproperty(Atom obj, const Multiname* multiname, Atom value, VTable* vtable) const;
		void setpropertylate_i(Atom obj, int index, Atom value) const;
		void setpropertylate_u(Atom obj, uint32 index, Atom value) const;

		/** same as callproperty but only considers the bindings in given vtable */
		Atom callsuper(const Multiname* name, int argc, Atom* atomv) const;

		Atom delproperty(Atom obj, const Multiname* multiname) const;

		/**
		 * Reads a property from an object, with the property
		 * to retrieve specified by its binding.
		 * The binding was likely retrieved using getBinding.
		 * @param obj Object to retrieve property from
		 * @param b The binding of the property
		 * @param traits The traits of the object
		 */
		Atom getsuper(Atom obj, const Multiname* name) const;

		/**
		 * Write to a property of an object, with the property
		 * to modify specified by its binding.
		 * The binding was likely retrieved using getBinding.
		 * @param obj Object to modify property of
		 * @param b The binding of the property
		 * @param value The new value of the property
		 */
		void setsuper(Atom obj, const Multiname* name, Atom value) const;

		/** Implementation of OP_findproperty */		
		Atom findproperty(ScopeChain* outer, 
						  Atom* scopes,
						  int extraScopes,
						  const Multiname* multiname,
						  bool strict,
						  Atom* withBase);
		
		/** Like findproperty, but ignoring all lexical and 'this' scopes.  Returns NULL if
		 *  property could not be found; caller should signal strict error or return the
		 *  target_global as appropriate.
		 */
		ScriptObject* findglobalproperty(ScriptObject* target_global, const Multiname* multiname);

		Namespace* internRtns(Atom ns);

		/** Creates the arguments array */
		ArrayObject* createArguments(Atom *atomv, int argc);

		/**
		 * E4X descendants operator (..)
		 */
		Atom getdescendants(Atom obj, const Multiname* multiname);

		/**
		 * E4X filter operator
		 */
		void checkfilter(Atom obj);

		ScriptObject* coerceAtom2SO(Atom atom, Traits *expected) const;

#ifdef DEBUGGER
		void debugEnter(Traits** frameTraits, 
						CallStackNode* callstack,
						FramePtr framep, 
						volatile sintptr *eip);

		void debugEnterInner();

		void debugExit(CallStackNode* callstack);
#endif

	private:
		Atom findWithProperty(Atom obj, const Multiname* multiname);
		
		class ActivationMethodTablePair
		{
		public:
			ActivationMethodTablePair(VTable *a, WeakKeyHashtable*wkh) :
				activation(a), methodTable(wkh) {}
		// ------------------------ DATA SECTION BEGIN
		public:
			VTable* const activation;
			WeakKeyHashtable* const methodTable;
		// ------------------------ DATA SECTION END
		};

		// low 2 bits of activationOrMCTable 
		enum { kActivation=0, kMethodTable, kActivationMethodTablePair };
		// and the 3rd bit is a flag for "am I a ScriptEnv"
		enum { kIsScriptEnv = 4 };

		ActivationMethodTablePair* getPair() const { return (ActivationMethodTablePair*)(activationOrMCTable&~7); }		
		int getType() const { return activationOrMCTable&3; }
		void setActivationOrMCTable(void *ptr, int type) 
		{
			AvmAssert((uintptr_t(ptr) & 7) == 0);
			WB(core()->GetGC(), this, &activationOrMCTable, (uintptr_t)ptr | type | (activationOrMCTable & kIsScriptEnv));
		}

	protected:
		inline void setIsScriptEnv() { activationOrMCTable |= kIsScriptEnv; }

	public:
		inline bool isScriptEnv() const { return (activationOrMCTable & kIsScriptEnv) != 0; }

#ifdef DEBUGGER
		uint64_t invocationCount() const;
#endif

	protected:

		inline VTable* vtable() const { return _scope->vtable(); }

	// ------------------------ DATA SECTION BEGIN
#if VMCFG_METHODENV_IMPL32
	public:
		MethodInfo* const method;
#else
	// inherit "method" from MethodEnvProcHolder. yeah, this is ugly,
	// but allows us to eliminate an otherwise-useless field from ImtThunkEnv.
#endif
	protected:
		// pointers are write-once so we don't need WB's
		ScopeChain* const			_scope;			
	private:
		uintptr_t					activationOrMCTable;
	public:
#ifdef AVMPLUS_WORD_CODE
		class LookupCache : public MMgc::GCObject
		{
		public:
			uint32 timestamp;
			DRCWB(ScriptObject*) object;
		};
		DWB(LookupCache*) lookup_cache;
#endif
	// ------------------------ DATA SECTION END
	};

	class ScriptEnv : public MethodEnv
	{
	public:
		ScriptEnv(MethodInfo* _method, VTable* _vtable, AbcEnv* _abcEnv)
			: MethodEnv(_method, createScriptScope(_method->declaringScope(), _vtable, _abcEnv))
		{
			setIsScriptEnv(); 
		}

		ScriptObject* initGlobal();
	
	private:
		static ScopeChain* createScriptScope(const ScopeTypeChain* stc, VTable* _vtable, AbcEnv* _abcEnv);
		
	// ------------------------ DATA SECTION BEGIN
	public:
		DRCWB(ScriptObject*) global; // initially null, set after initialization
	// ------------------------ DATA SECTION END
	};

	class FunctionEnv : public MethodEnv
	{
	  public:
		FunctionEnv(MethodInfo* _method, ScopeChain* _scope)
			: MethodEnv(_method, _scope) 
		{
		}
	// ------------------------ DATA SECTION BEGIN
	  public:
		DRCWB(ClassClosure*) closure;
	// ------------------------ DATA SECTION END
	};

	// probably should go elsewhere, but this is adequate for now.
	#if defined(AVMPLUS_BIG_ENDIAN)
		inline void _swap8(uint8_t& a, uint8_t& b)
		{
			const uint8_t t = a;
			a = b;
			b = t;
		}

		inline void MOPS_SWAP_BYTES(uint16_t* p)
		{
			union {
				uint16_t* pv;
				uint8_t* c;
			};
			pv = p;
			_swap8(c[0], c[1]);
		}
		
		inline void MOPS_SWAP_BYTES(int32_t* p)
		{
			union {
				int32_t* pv;
				uint8_t* c;
			};
			pv = p;
			_swap8(c[0], c[3]);
			_swap8(c[1], c[2]);
		}

		inline void MOPS_SWAP_BYTES(float* p)
		{
			union {
				float* pv;
				uint8_t* c;
			};
			pv = p;
			_swap8(c[0], c[3]);
			_swap8(c[1], c[2]);
		}
		
		inline void MOPS_SWAP_BYTES(double* p)
		{
			union {
				double* pv;
				uint8_t* c;
			};
			pv = p;
			_swap8(c[0], c[7]);
			_swap8(c[1], c[6]);
			_swap8(c[2], c[5]);
			_swap8(c[3], c[4]);
		}
	#elif defined VMCFG_DOUBLE_MSW_FIRST
		inline void MOPS_SWAP_BYTES(uint16_t*) {}
		inline void MOPS_SWAP_BYTES(int32_t*) {}
		inline void MOPS_SWAP_BYTES(float*) {}
		inline void MOPS_SWAP_BYTES(double *p)
		{
			union {
				double* pv;
				uint32_t* w;
			};
			pv = p;
			uint32_t t = w[0];
			w[0] = w[1];
			w[1] = t;
		}
	#else
		#define MOPS_SWAP_BYTES(p) do {} while (0)
	#endif

#if defined FEATURE_NANOJIT
	struct ImtThunkEntry
	{
		uintptr_t iid;
		uintptr_t disp_id; // only needs to be uint32_t, is this size for alignment purposes
	};

	class ImtThunkEnv;

	class ImtThunkEnv : public MethodEnvProcHolder
	{
	public:
#if VMCFG_METHODENV_IMPL32
		inline ImtThunkEnv(GprImtThunkProc p, VTable* v) : 
			MethodEnvProcHolder((GprMethodProc)p), 
			vtable(v) 
		{ 
		}
		inline ImtThunkEnv(GprImtThunkProc p, uint32_t c) : 
			MethodEnvProcHolder((GprMethodProc)p), 
			imtMapCount(c) 
		{ 
		}
#else
		inline ImtThunkEnv(GprImtThunkProc p, VTable* v) : 
			MethodEnvProcHolder((MethodInfo*)&methodProcHolder), 
			vtable(v),
			methodProcHolder((GprMethodProc)p)
		{ 
		}
		inline ImtThunkEnv(GprImtThunkProc p, uint32_t c) : 
			MethodEnvProcHolder((MethodInfo*)&methodProcHolder), 
			imtMapCount(c),
			methodProcHolder((GprMethodProc)p)
		{ 
		}
#endif
		inline GprImtThunkProc implImtGPR() const { return (GprImtThunkProc)this->implGPR(); }
		inline ImtThunkEntry* entries() const { return (ImtThunkEntry*)(this+1); }

	// ------------------------ DATA SECTION BEGIN
	public:
		union 
		{
			VTable* vtable;
			uint32_t imtMapCount;
		};
#if !VMCFG_METHODENV_IMPL32
		MethodInfoProcHolder methodProcHolder;
#endif
	// ------------------------ DATA SECTION END
	};
#endif // FEATURE_NANOJIT

}

#endif // __avmplus_MethodEnv__
