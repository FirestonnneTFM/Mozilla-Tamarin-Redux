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

#ifndef __avmplus_MethodInfo__
#define __avmplus_MethodInfo__


#ifdef verify
#undef verify
#endif

namespace avmplus
{
     class ScopeOrTraits
     {
     private:
        static const uintptr_t IS_SCOPE = 0x01;
     private:
        uintptr_t _scopeOrTraits;   // if LSB clr, Traits*   if LSB set, ScopeTypeChain*
     public:
         explicit ScopeOrTraits(Traits* t);
         bool hasScope() const;
         Traits* getTraits() const;
         const ScopeTypeChain* getScope() const;
         void setTraits(MMgc::GC* gc, void* container, Traits* t);
         void setScope(MMgc::GC* gc, void* container, const ScopeTypeChain* s);
     };

#ifdef DEBUGGER
    class AbcFile;
    class DebuggerMethodInfo : public MMgc::GCObject
    {
    private:
        explicit DebuggerMethodInfo(int32_t _local_count, uint32_t _codeSize, int32_t _max_scopes);

    public:

        static DebuggerMethodInfo* create(AvmCore* core, int32_t _local_count, uint32_t _codeSize, int32_t _max_scopes);

        DWB(AbcFile*)           file;               // the abc file from which this method came
        int32_t                 firstSourceLine;    // source line number where function starts
        int32_t                 lastSourceLine;     // source line number where function ends
        int32_t                 offsetInAbc;        // offset in abc file
        uint32_t                codeSize;           // abc size pre-jit, native size post jit
        const int32_t           local_count;        // FIXME: merge with localCount above; this one may be visible to a debugger?
        const int32_t           max_scopes;         // FIXME: merge with maxScopeDepth above; this one is not used by the VM but may be visible to a debugger?
        Stringp                 localNames[1];      // array of names for args and locals in framep order, written with explicit WBRC (actually local_count)
    };
#endif

    class MethodSignature;

    /**
     * MethodInfo is the base class for all functions that
     * can be executed by the VM: Actionscript functions,
     * native functions, etc.
     */
    class MethodInfo : public MethodInfoProcHolder
    {
        friend class CodegenLIR;
        friend class BaseExecMgr;
    public:
        /** @name flags from .abc - limited to a BYTE */
        /*@{*/
        /** need arguments[0..argc] */
        static const int32_t NEED_ARGUMENTS         = 0x00000001;

        /** need activation object */
        static const int32_t NEED_ACTIVATION        = 0x00000002;

        /** need arguments[param_count+1..argc] */
        static const int32_t NEED_REST              = 0x00000004;

        /** has optional parameters */
        static const int32_t HAS_OPTIONAL           = 0x00000008;

        /** allow extra args, but dont capture them */
        static const int32_t IGNORE_REST            = 0x00000010;

        /** method is native */
        static const int32_t NATIVE                 = 0x00000020;

        /** method sets default namespace */
        static const int32_t SETS_DXNS              = 0x00000040;

        /** method has table for parameter names */
        static const int32_t HAS_PARAM_NAMES        = 0x00000080;

        /*@}*/
    private:
        /** @name internal flags - upper 3 BYTES available */
        /*@{*/
        // set iff this is a getter
        static const int32_t IS_GETTER              = 0x00000100;

        // set iff this is a setter
        static const int32_t IS_SETTER              = 0x00000200;

        static const int32_t OVERRIDE               = 0x00000400;

        static const int32_t NON_INTERRUPTIBLE      = 0x00000800;

        static const int32_t UNBOX_THIS             = 0x00001000;

        static const int32_t NEEDS_CODECONTEXT      = 0x00002000;

        static const int32_t HAS_EXCEPTIONS         = 0x00004000;

        static const int32_t NEEDS_DXNS             = 0x00008000;

        static const int32_t VERIFIED               = 0x00010000;

        static const int32_t VERIFY_PENDING         = 0x00020000;

        /** indicates method is final, no overrides allowed */
        static const int32_t FINAL                  = 0x00040000;

        /** indicates the function is a method, that pushes the
            receiver object onto the scope chain at method entry */
        static const int32_t NEED_CLOSURE           = 0x00080000;

        /** set to indicate that a function has no bytecode body. */
        static const int32_t ABSTRACT_METHOD        = 0x00100000;

        /**
         * set once the signature types have been resolved and
         * override signatures have been checked.
         */
        static const int32_t RESOLVED               = 0x00200000;

        /**
         * set to indictate that a function is a static initializer
         */
        static const int32_t STATIC_INIT            = 0x00400000;

        /**
         * set to indicate that a function has been compiled
         * to native code by the jit compiler.
         */
        static const int32_t JIT_IMPL               = 0x00800000;

// begin AVMPLUS_UNCHECKED_HACK
        static const int32_t UNCHECKED              = 0x01000000;

        // Note, this means "makeIntoPrototypeFunction has been called on me",
        // *not* "I am a function on a prototype object".
        static const int32_t PROTOFUNC              = 0x02000000;
// end AVMPLUS_UNCHECKED_HACK

#ifdef VMCFG_AOT
        static const int32_t AOT_COMPILED           = 0x04000000;
#endif

        // Set by isTrivial() if the method is trivial; see isTrivial() below.
        static const int32_t TRIVIAL                = 0x08000000;

        // Set by isTrivial() if the method is not trivial.  We could
        // reuse the AOT_COMPILED flag for this.
        static const int32_t NONTRIVIAL             = 0x10000000;

        // true if execution mechanism is the interpreter (comparing implGPR
        // to known functions is fragile and breaks encapsulation).
        static const int32_t INTERP_IMPL            = 0x20000000;

        // Set by setLazyRest when the verifier discovers that the method's rest array
        // or arguments array can be allocated lazily (usually not at all).  Only makes
        // sense in combination with NEED_REST or NEED_ARGUMENTS.
        static const int32_t LAZY_REST              = 0x40000000;

        // Set by _buildMethodSignature if all fixed or optional parameters
        // to the function are untyped.  (We use this to optimize the 'arguments' 
        // array, see RestArgAnalyzer.)
        static const int32_t ONLY_UNTYPED_PARAMETERS      = 0x80000000;

        /*@}*/

    public:
        // ctor for all normal methods.
        MethodInfo(int32_t _method_id,
                    PoolObject* pool,
                    const uint8_t* abc_info_pos,
                    uint8_t abcFlags,
                    const NativeMethodInfo* native_info);

        // special ctor for the methodinfo generated for slot-initialization when no init method is present
        enum InitMethodStub { kInitMethodStub };
        MethodInfo(InitMethodStub, Traits* declTraits);

#ifdef VMCFG_AOT
        MethodInfo(InitMethodStub, Traits* declTraits, const NativeMethodInfo* native_info);
#endif

        bool usesCallerContext() const;

        // Builtin + non-native functions always need the dxns code emitted
        // Builtin + native functions have flags to specify if they need the dxns code
        bool usesDefaultXmlNamespace() const;

        void resolveSignature(const Toplevel* toplevel);

#ifdef DEBUGGER
    public:
        Atom boxOneLocal(FramePtr src, int32_t srcPos, const uint8_t* sstArr);
        void unboxOneLocal(Atom src, FramePtr dst, int32_t dstPos, const uint8_t* sstArr);

        void boxLocals(FramePtr src, int32_t srcPos, const uint8_t* sstArr, Atom* dest, int32_t destPos, int32_t length);
        void unboxLocals(const Atom* src, int32_t srcPos, const uint8_t* sstArr, FramePtr dest, int32_t destPos, int32_t length);

        void setFile(AbcFile* file);
        void setRegName(int32_t index, Stringp name);

        Stringp getArgName(int32_t index);
        Stringp getLocalName(int32_t index);

        AbcFile* file() const;
        int32_t firstSourceLine() const;
        int32_t lastSourceLine() const;
        int32_t offsetInAbc() const;
        uint32_t codeSize() const;
        int32_t local_count() const;
        int32_t max_scopes() const;

        void updateSourceLines(int32_t linenum, int32_t offset);

    private:
        Stringp getRegName(int32_t index) const;
        DebuggerMethodInfo* dmi() const;
#endif

    public:
        void makeIntoPrototypeFunction(const Toplevel* toplevel, const ScopeTypeChain* fscope);
        bool makeMethodOf(Traits* type);
        bool isConstructor() const;

        int32_t allowExtraArgs() const;
        int32_t hasExceptions() const;
        int32_t hasMethodBody() const;
        int32_t hasOptional() const;
        int32_t isNative() const;
        int32_t isNonInterruptible();
        int32_t isResolved() const;
        int32_t isFinal() const;
        int32_t needActivation() const;
        int32_t needArguments() const;
        int32_t needClosure() const;
        int32_t needRest() const;
        int32_t lazyRest() const;   // Valid only during pass2 of verification or later
        int32_t needRestOrArguments() const;
        int32_t setsDxns() const;
        int32_t isStaticInit() const;
        int32_t isInterpreted() const;
        int32_t unboxThis() const;
        int32_t onlyUntypedParameters() const;

        void setUnboxThis();
        void setStaticInit();
        void setHasExceptions();
        void setLazyRest();
        void setNeedsDxns();
        void setFinal();
        void setOverride();
        void makeNonInterruptible();
        void setKind(TraitKind kind);

#ifdef VMCFG_AOT
        static int32_t compiledMethodFlags();
        int32_t isCompiledMethod() const;
        void setCompiledMethod();
#endif

    public:

#if VMCFG_METHOD_NAMES
        Stringp FASTCALL getMethodNameWithTraits(Traits* declaringTraits, bool includeAllNamespaces = false) const;
        Stringp FASTCALL getMethodName(bool includeAllNamespaces = false) const;
#endif

#ifdef AVMPLUS_VERBOSE
        PrintWriter& print(PrintWriter& prw) const;
#endif
#ifdef DEBUGGER
        /**
         * Basically the same as AvmPlusScriptableObject::bytesUsed().
         */
        uint64_t bytesUsed();
#endif

    public:

        PoolObject* pool() const;
#ifdef VMCFG_INDIRECT_NATIVE_THUNKS
        AvmThunkNativeMethodHandler handler_method() const;
        AvmThunkNativeFunctionHandler handler_function() const;
#endif

        const uint8_t* abc_body_pos() const;
        void set_abc_body_pos(const uint8_t* p);
        uint32_t parse_code_length() const; // Parse code_len from ABC.

        ExceptionHandlerTable* abc_exceptions() const;
        void set_abc_exceptions(MMgc::GC* gc, ExceptionHandlerTable* e);

    #ifdef VMCFG_WORDCODE
        ExceptionHandlerTable* word_code_exceptions() const;
        void set_word_code_exceptions(MMgc::GC* gc, ExceptionHandlerTable* e);
        const uintptr_t* word_code_start() const;
        void set_word_code(MMgc::GC* gc, TranslatedCode* translated_code);
    #endif

    #ifdef VMCFG_LOOKUP_CACHE
        int32_t lookup_cache_size() const;
        void set_lookup_cache_size(int32_t s);
    #endif

        int32_t method_id() const;

        Traits* declaringTraits() const;
        const ScopeTypeChain* declaringScope() const;
        Traits* activationTraits() const;
        const ScopeTypeChain* activationScope() const;

        void init_activationTraits(Traits* t);
        void init_activationScope(const ScopeTypeChain*);

        MethodSignaturep getMethodSignature();
        void update_max_stack(int32_t max_stack);

        /**
         * Determine whether a function is trivial.  A function is (conservatively) trivial
         * if all these conditions hold:
         *
         *   - it always terminates
         *   - it always terminates by returning, never by throwing exceptions
         *     (apart from system errors like stack overflow and out-of-memory)
         *   - it always returns 'undefined'
         *   - it does not update any non-local locations
         *
         * Stronger definitions of triviality are possible - for example, the condition on
         * returning 'undefined' is a hack to avoid dealing with data flow analysis and
         * determining whether RETURNVALUE will throw an exception - and some functions that
         * are trivial by the above definition may still not be recognized by the implementation,
         * obviously.  The only condition is that if isTrivial returns true then the function
         * is trivial by the above definition.
         */
        bool isTrivial();

    private:
        MethodSignature* FASTCALL _getMethodSignature();
        MethodSignature* FASTCALL _buildMethodSignature(const Toplevel* toplevel);
        bool computeIsTrivial();

    private:
        struct NativeInfo
        {
            GprMethodProc thunker;
#ifdef VMCFG_INDIRECT_NATIVE_THUNKS
            AvmThunkNativeHandler handler;
#endif
        };

        struct AbcInfo
        {
            const uint8_t*          body_pos;
            ExceptionHandlerTable*  exceptions;     // we write this once, in Verifier, with an explicit WB.  so no DWB.
    #ifdef VMCFG_LOOKUP_CACHE
            int                     lookup_cache_size;     // Number of items in lookup cache
    #endif
    #ifdef VMCFG_WORDCODE
            struct
            {
                TranslatedCode*         translated_code;    // The object that contains the code pointed to by body_pos, written with explicit WB
                // We write this once, in WordcodeTranslator, with an explicit WB.  so no DWB.
                // The contents are the same as the 'exceptions' structure above, except the 'from', 'to', and 'target' fields.
                ExceptionHandlerTable*  exceptions;
            } word_code;
    #endif
        };

    // ------------------------ DATA SECTION BEGIN
    private:
        DWB(MMgc::GCWeakRef*)   _msref;                     // our MethodSignature
        ScopeOrTraits           _declarer;
        ScopeOrTraits           _activation;
        PoolObject* const       _pool;
        const uint8_t* const    _abc_info_pos;      // pointer to abc MethodInfo record
        int                     _flags;             // see bitmask defs above
        const int               _method_id;
        union
        {
            NativeInfo          _native;            // stuff used only for Native methods (formerly in NativeMethod)
            AbcInfo             _abc;               // stuff used only for bytecode methods (formerly in MethodInfo)
        };
#if VMCFG_METHOD_NAMES && defined(AVMPLUS_SAMPLER)
        mutable DRCWB(Stringp)  _methodName;
#endif
    // ------------------------ DATA SECTION END
    };

    class MethodSignature : public QCachedItem
    {
        friend class MethodInfo;
    public:
    private:
        union AtomOrType
        {
            Traits* paramType;
            Atom defaultValue;
        };

    public:
        Traits* returnTraits() const;
        BuiltinType returnTraitsBT() const;

        int32_t param_count() const;
        int32_t optional_count() const;
        int32_t rest_offset() const;

        int32_t max_stack() const;
        int32_t local_count() const;
        int32_t max_scope() const;
        int32_t frame_size() const;
        int32_t stack_base() const;
        int32_t scope_base() const;

    #ifdef VMCFG_WORDCODE
    #else
        const uint8_t* abc_code_start() const;
    #endif

        int32_t requiredParamCount() const;

        Traits* paramTraits(int32_t i) const;
        BuiltinType paramTraitsBT(int32_t i) const;
        Atom getDefaultValue(int32_t i) const;

        bool argcOk(int32_t argc) const;
        void boxArgs(AvmCore* core, int32_t argc, const uint32_t* ap, Atom* out) const;

    // ------------------------ DATA SECTION BEGIN
    private:
        Traits*     _returnTraits;      // written with explicit WB
    #ifdef VMCFG_WORDCODE
    #else
        const uint8_t*  _abc_code_start; // start of ABC body
    #endif
        int         _param_count;       // number of declared parameters including optionals
        int         _optional_count;    // last optional_count params are optional
        int         _rest_offset;       // offset to first rest arg, including the instance parameter. this is sum(sizeof(paramType(0..N)))
        int         _flags;             // dupe of owner's flags, for convenience
        int         _max_stack;         // abc-only: max stack
        int         _local_count;       // abc-only: maximum number of local registers
        int         _max_scope;         // abc-only: maximum depth of local scope stack
        int         _frame_size;        // abc-only: total size of frame in number of Atoms, derived from other values above
        AtomOrType  _args[1];           // lying, actually 1+param_count+optional_count
    // ------------------------ DATA SECTION END
    };

}

#endif /* __avmplus_MethodInfo__ */
