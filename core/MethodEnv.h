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
	class MethodEnv : public MMgc::GCObject
	{
		static Atom delegateInvoke(MethodEnv* env, int argc, uint32 *ap);

	public:
		/** vtable for the activation scope inside this method */
		VTable *getActivation();

		/** getter lazily creates table which maps SO->MC */
		WeakKeyHashtable *getMethodClosureTable();

		MethodEnv(void* addr, VTable *vtable);
		MethodEnv(AbstractFunction* method, VTable *vtable);

		Toplevel* toplevel() const
		{
			return vtable->toplevel;
		}

		AbcEnv* abcEnv() const
		{
			return vtable->abcEnv;
		}

		ScriptEnv* getScriptEnv(const Multiname *m) const;

		DomainEnv* domainEnv() const
		{
			return vtable->abcEnv->domainEnv;
		}

		AvmCore* core() const
		{
			return method->pool->core;
		}

		/**
		 * Coerces an array of actual parameters to the types
		 * required by a function's formal parameters, then invokes
		 * the method.  Args are provided as an array of atoms, not
		 * an array of native types.
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
		Atom coerceEnter(Atom thisArg, ArrayObject *a);
		Atom coerceEnter(Atom thisArg, int argc, Atom *argv);
		Atom coerceEnter(int argc, Atom* atomv);

	private:
		Atom endCoerce(int argc, uint32 *ap);
		int  startCoerce(int argc);
		static Atom *unbox1(AvmCore* core, Toplevel* toplevel, Atom in, Traits *t, Atom *argv);
		void unboxCoerceArgs(Atom thisArg, ArrayObject *a, uint32 *argv);
		void unboxCoerceArgs(int argc, Atom* in, uint32 *ap);
		void unboxCoerceArgs(Atom thisArg, int argc, Atom* in, uint32 *argv);

	// helper functions used from compiled code
	public:
		/** null pointer check */
	    void nullcheck(Atom atom);
	    void npe();
		void interrupt();
        void stkover();

		/** returns the instance traits of the factorytype of the passed atom */
		Traits* toClassITraits(Atom atom);

		ArrayObject* createRest(Atom* argv, int argc);
		Atom getpropertylate_i(Atom obj, int index) const;
		Atom getpropertylate_u(Atom obj, uint32 index) const;

#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
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
		ScriptObject* finddefNsset(NamespaceSet* nsset, Stringp name) const;
		ScriptObject* finddefNs(Namespace* ns, Stringp name) const;

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
		
		/**
		 * operator in from ES3
		 */
		Atom in(Atom name, Atom obj) const;
		
		/**
		 * OP_newfunction
		 * see 13.2 creating function objects
		 */
		ClassClosure* newfunction(AbstractFunction *function, 
						 ScopeChain* outer,
						 Atom* scopes) const;

		/**
		 * OP_newclass
		 */

		ClassClosure* newclass(AbstractFunction* cinit,
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
		Atom getdescendantslate(Atom obj, Atom name, bool attr);

		/**
		 * E4X filter operator
		 */
		void checkfilter(Atom obj);

		ScriptObject* coerceAtom2SO(Atom atom, Traits *expected) const;

		/**
		 * same as coerce, but returns coerced undefined instead
		 * of throwing an exception
		 */
		Atom astype(Atom atom, Traits* expected);
		
#ifdef DEBUGGER
		uint64 invocationCount;
		void debugEnter(int argc, uint32 *ap, 
							   Traits**frameTraits, int localCount,
							   CallStackNode* callstack,
							   Atom* framep, volatile sintptr *eip);
		void debugExit(CallStackNode* callstack);
		void sendEnter(int argc, uint32 *ap);
		void sendExit();
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

		ActivationMethodTablePair *getPair() const { return (ActivationMethodTablePair*)(activationOrMCTable&~3); }		
		int getType() const { return activationOrMCTable&3; }
		void setActivationOrMCTable(void *ptr, int type) 
		{
			WB(core()->GetGC(), this, &activationOrMCTable, (uintptr)ptr|type);
		}
	// ------------------------ DATA SECTION BEGIN
	public:
		// pointers are write-once so we don't need WB's
		VTable* const				vtable;		// the vtable for the scope where this env was declared 
		AbstractFunction* const		method;		// runtime independent type info for this method 
		Traits* const				declTraits;
		union {
			AtomMethodProc			impl32;	// pointer to invoke trampoline 
			DoubleMethodProc		implN;
			void*					implV;
		};
	private:
		uintptr_t					activationOrMCTable;
	// ------------------------ DATA SECTION END
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
	};

	class ScriptEnv : public MethodEnv
	{
	public:
		ScriptEnv(AbstractFunction* _method, VTable * _vtable)
			: MethodEnv(_method, _vtable)
		{
		}

		ScriptObject* initGlobal();

	// ------------------------ DATA SECTION BEGIN
	public:
		DRCWB(ScriptObject*) global; // initially null, set after initialization
	// ------------------------ DATA SECTION END
	};

	class FunctionEnv : public MethodEnv
	{
	  public:
		FunctionEnv(AbstractFunction* _method, VTable * _vtable)
			: MethodEnv(_method, _vtable) {}
	// ------------------------ DATA SECTION BEGIN
	  public:
		DRCWB(ClassClosure*) closure;
	// ------------------------ DATA SECTION END
	};
}

#endif // __avmplus_MethodEnv__
