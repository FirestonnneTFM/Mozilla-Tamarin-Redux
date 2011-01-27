/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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
    class GC_CPP_EXACT(MethodEnv, MethodEnvProcHolder)
    {
        friend class CodegenLIR;
        friend class BaseExecMgr;

    protected:
        MethodEnv(MethodInfo* method, ScopeChain* scope);
        
    public:
        static MethodEnv* create(MMgc::GC* gc, MethodInfo* method, ScopeChain* scope);

        /** vtable for the activation scope inside this method */
        ScriptObject* newUninitializedActivation();
        ScriptObject* newActivation();

        /** getter lazily creates table which maps SO->MC */
        WeakKeyHashtable *getMethodClosureTable();

        AbcEnv* abcEnv() const;
        AvmCore* core() const;
        CodeContext* codeContext() const;
        DomainEnv* domainEnv() const;
        ScopeChain* scope() const;
        MethodEnv* super_init() const;
        Toplevel* toplevel() const;
        Stringp traitsName() const;
        Namespacep traitsNs() const;

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
        Atom coerceEnter(int32_t argc, Atom* argv);

        // Called from the interpreter
        void nullcheck(Atom atom);    // null pointer check

    private:
        MethodSignaturep get_ms();
        void FASTCALL nullcheckfail(Atom atom);
        VTable* getActivationVTable();
        VTable* buildActivationVTable();

    // helper functions used from compiled code
    public:
        void argcError(int32_t argc); // never returns; throws argument count error

        ArrayObject* createRest(Atom* argv, int32_t argc);
        Atom getpropertylate_i(Atom obj, int32_t index) const;
        Atom getpropertylate_u(Atom obj, uint32_t index) const;
        /*bool*/ int32_t haspropertylate_i(Atom obj, int32_t index) const;
        /*bool*/ int32_t haspropertylate_u(Atom obj, uint32_t index) const;

#if defined VMCFG_NANOJIT || defined VMCFG_AOT
        void setpropertyHelper(Atom obj, /* not const */ Multiname *multi, Atom value, VTable *vtable, Atom index);
        void initpropertyHelper(Atom obj, /* not const */ Multiname *multi, Atom value, VTable *vtable, Atom index);
        Atom getpropertyHelper(Atom obj, /* not const */ Multiname *multi, VTable *vtable, Atom index);
        Atom delpropertyHelper(Atom obj, /* not const */ Multiname *multi, Atom index);

        void initMultinameLateForDelete(Multiname& name, Atom index);
        ArrayObject* createArgumentsHelper(int32_t argc, uint32_t *ap);
        ArrayObject* createRestHelper(int32_t argc, uint32_t *ap);
#endif

        ScriptObject* newcatch(Traits *traits);
        /**
         * used for defining and resolving imported definitions.
         */
        ScriptObject* finddef(const Multiname* name) const;

        /**
         * implementation of object initializers
         */
        ScriptObject* op_newobject(Atom* sp, int32_t argc) const;

        /** Implementation of OP_nextname */
        Atom nextname(Atom objAtom, int32_t index) const;

        /** Implementation of OP_nextvalue */
        Atom nextvalue(Atom objAtom, int32_t index) const;

        /** Implementation of OP_hasnext */
        int32_t hasnext(Atom objAtom, int32_t index) const;

        /** Implementation of OP_hasnext2 */
        int32_t hasnextproto(Atom& objAtom, int& index) const;

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
        void setpropertylate_i(Atom obj, int32_t index, Atom value) const;
        void setpropertylate_u(Atom obj, uint32_t index, Atom value) const;

        /** same as callproperty but only considers the bindings in given vtable */
        Atom callsuper(const Multiname* name, int32_t argc, Atom* atomv) const;

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
                          int32_t extraScopes,
                          const Multiname* multiname,
                          bool strict,
                          Atom* withBase);

        /** Like findproperty, but ignoring all lexical and 'this' scopes.  Returns NULL if
         *  property could not be found; caller should signal strict error or return the
         *  target_global as appropriate.
         */
        Atom findglobalproperty(Atom target_global, const Multiname* multiname);

        Namespace* internRtns(Atom ns);

        /** Creates the arguments array */
        ArrayObject* createArguments(Atom *atomv, int32_t argc);

        /**
         * E4X descendants operator (..)
         */
        Atom getdescendants(Atom obj, const Multiname* multiname);

        /**
         * E4X filter operator
         */
        void checkfilter(Atom obj);

#ifdef DEBUGGER
        void debugEnter(const uint8_t* frame_sst,
                        CallStackNode* callstack,
                        FramePtr framep,
                        volatile intptr_t *eip);

        void debugEnterInner();

        void debugExit(CallStackNode* callstack);

        ArrayObject *getLexicalScopes();
#endif

    private:
        Atom findWithProperty(Atom obj, const Multiname* multiname);

        class ActivationMethodTablePair : public MMgc::GCObject
        {
        public:
            ActivationMethodTablePair(VTable *a, WeakKeyHashtable*wkh);
        // ------------------------ DATA SECTION BEGIN
        public:
            VTable* const activation;
            WeakKeyHashtable* const methodTable;
        // ------------------------ DATA SECTION END
        };

        // low 2 bits of activationOrMCTable
        enum { kActivation=0, kMethodTable, kActivationMethodTablePair };

        ActivationMethodTablePair* getPair() const;
        int32_t getType() const;
        void setActivationOrMCTable(void *ptr, int32_t type);

    public:

#ifdef DEBUGGER
        uint64_t invocationCount() const;
#endif

    protected:
        VTable* vtable() const;

#ifdef VMCFG_LOOKUP_CACHE
    public:
        // LookupCache is part of an ExactStructContainer<> array, hence the gcTrace method.
        class LookupCache
        {
        public:
            uint32_t timestamp;
            DRCWB(ScriptObject*) object;
            
            REALLY_INLINE void gcTrace(MMgc::GC* gc)
            {
                gc->TraceLocation(&object);
            }
        };

        // Populate lookup_cache, which should be NULL at the time of the call.
        void createLookupCache();
        
        // Clear out the lookup cache elements
        static void cleanLookupCache(ExactStructContainer<LookupCache>* self);
#endif

    // ------------------------ DATA SECTION BEGIN
        GC_DATA_BEGIN(MethodEnv)

    public:
        MethodInfo* const           GC_POINTER(method);
    protected:
        // pointers are write-once so we don't need WB's
        ScopeChain* const           GC_POINTER(_scope);
    private:
        uintptr_t                   GC_CONSERVATIVE(activationOrMCTable);
    public:
#ifdef VMCFG_LOOKUP_CACHE
        DWB(ExactStructContainer<LookupCache>*)
                                    GC_POINTER_IFDEF(lookup_cache, VMCFG_LOOKUP_CACHE);
#endif

        GC_DATA_END(MethodEnv)
    // ------------------------ DATA SECTION END
    };

    class GC_CPP_EXACT(ScriptEnv, MethodEnv)
    {
        ScriptEnv(MethodInfo* _method, ScopeChain* _scope);
    public:
        REALLY_INLINE static ScriptEnv* create(MMgc::GC* gc, MethodInfo* _method, ScopeChain* _scope)
        {
            return new (gc, MMgc::kExact) ScriptEnv(_method, _scope);
        }

        ScriptObject* initGlobal();
        static ScopeChain* createScriptScope(const ScopeTypeChain* stc, VTable* _vtable, AbcEnv* _abcEnv);

    // ------------------------ DATA SECTION BEGIN
        GC_DATA_BEGIN(ScriptEnv)
        
    public:
        DRCWB(ScriptObject*) GC_POINTER(global); // initially null, set after initialization
        
        GC_DATA_END(ScriptEnv)
    // ------------------------ DATA SECTION END
    };

    class GC_CPP_EXACT(FunctionEnv, MethodEnv)
    {
        FunctionEnv(MethodInfo* _method, ScopeChain* _scope);

    public:
        REALLY_INLINE static FunctionEnv* create(MMgc::GC* gc, MethodInfo* _method, ScopeChain* _scope)
        {
            return new (gc, MMgc::kExact) FunctionEnv(_method, _scope);
        }

    // ------------------------ DATA SECTION BEGIN
        GC_DATA_BEGIN(FunctionEnv)
        
    public:
        DRCWB(ClassClosure*) GC_POINTER(closure);
        
        GC_DATA_END(FunctionEnv)
    // ------------------------ DATA SECTION END
    };
}

#endif // __avmplus_MethodEnv__
