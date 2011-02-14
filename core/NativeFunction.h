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


#ifndef __avmplus_NativeFunction__
#define __avmplus_NativeFunction__

#ifdef VMCFG_AOT
#include "CdeclThunk.h"
struct AOTInfo;
#endif

namespace avmplus
{
#ifdef _DEBUG
    #define AvmThunk_DEBUG_ONLY(...)    __VA_ARGS__
#else
    #define AvmThunk_DEBUG_ONLY(...)
#endif /* DEBUG */

    // Historically, bools are passed in as int32_t, as some calling conventions
    // would only use a single byte and leave the remainder of the argument word
    // as trash; this was used to ensure it was well-defined. (It's not clear to
    // me if this is still an issue, but easier to maintain the convention than
    // change now.)
    typedef int32_t bool32;

#ifdef VMCFG_INDIRECT_NATIVE_THUNKS
    typedef void (AvmPlusScriptableObject::*AvmThunkNativeMethodHandler)();
    typedef void (*AvmThunkNativeFunctionHandler)(AvmPlusScriptableObject* obj);
#endif

    const uintptr_t kUnboxMask = ~uintptr_t(7);
#ifdef _DEBUG
    extern void FASTCALL check_unbox(MethodEnv* env, bool u);

    REALLY_INLINE uintptr_t _AvmThunkUnbox_AvmReceiver(MethodEnv* env, uintptr_t r)
    {
        check_unbox(env, false);
        AvmAssert((r & ~kUnboxMask) == 0);
        return r;
    }
    #define AvmThunkUnbox_AvmReceiver(t,r)      ((t)(_AvmThunkUnbox_AvmReceiver(env, uintptr_t(r))))

    REALLY_INLINE uintptr_t _AvmThunkUnbox_AvmAtomReceiver(MethodEnv* env, uintptr_t r)
    {
        check_unbox(env, true);
        return r & kUnboxMask;
    }
    #define AvmThunkUnbox_AvmAtomReceiver(t,r)      ((t)(_AvmThunkUnbox_AvmAtomReceiver(env, uintptr_t(r))))
#else
    #define AvmThunkUnbox_AvmReceiver(t,r)      ((t)(uintptr_t(r)))
    #define AvmThunkUnbox_AvmAtomReceiver(t,r)  ((t)(uintptr_t(r) & kUnboxMask))
#endif

    #define AvmThunkUnbox__avmplus_ScriptObject_(r)     ((ScriptObject*)(r))
    #define AvmThunkUnbox_avmplus_bool32(r)             ((r) != 0)
    #define AvmThunkUnbox_int32_t(r)                    int32_t(r)
    #define AvmThunkUnbox_uint32_t(r)                   uint32_t(r)
    #define AvmThunkUnbox_avmplus_Namespace_(r)         ((Namespace*)(r))
    #define AvmThunkUnbox_avmplus_Atom(r)               (r)
    #define AvmThunkUnbox_avmplus_String_(r)            ((String*)(r))
    #define AvmThunkUnbox_void(r)                       (error ??? illegal)
    #define AvmThunkUnbox_double(r)                     AvmThunkUnbox_double_impl(&(r))

    #define AvmThunkArgSize__avmplus_ScriptObject_      1
    #define AvmThunkArgSize_avmplus_bool32              1
    #define AvmThunkArgSize_int32_t                     1
    #define AvmThunkArgSize_uint32_t                    1
    #define AvmThunkArgSize_avmplus_Namespace_          1
    #define AvmThunkArgSize_avmplus_Atom                1
    #define AvmThunkArgSize_avmplus_String_             1
    #define AvmThunkArgSize_void                        (error ??? illegal)
#ifdef AVMPLUS_64BIT
    #define AvmThunkArgSize_double                      1
#else
    #define AvmThunkArgSize_double                      2
#endif

    REALLY_INLINE double AvmThunkUnbox_double_impl(const Atom* b)
    {
    #if defined(AVMPLUS_64BIT)
        MMGC_STATIC_ASSERT(sizeof(Atom) == sizeof(double));
        return *(const double*)b;
    #elif defined(VMCFG_UNALIGNED_FP_ACCESS)
        MMGC_STATIC_ASSERT(sizeof(Atom)*2 == sizeof(double));
        return *(const double*)b;
    #else
        MMGC_STATIC_ASSERT(sizeof(Atom)*2 == sizeof(double));
        double_overlay u;
        u.bits32[0] = b[0];
        u.bits32[1] = b[1];
        return u.value;
    #endif
    }

    // trick, since values are compile-time known we usually don't need to call intToAtom, can statically transform them
    // good for ints and ints currently
    #define AvmThunkCanBeSmallIntAtom(v)    (!((v) & 0xF0000000))
    #define AvmThunkSmallIntAtom(v)         ((((Atom)(v))<<3) | kIntptrType)

    // note, this isn't complete -- only the ones currently needed are defined.
    // expand as necessary. macros to take advantage of the fact that most
    // args are compile-time constants.
    #define AvmThunkCoerce_int32_t_double(v)            double(v)
    #define AvmThunkCoerce_int32_t_uint32_t(v)          uint32_t(v)
    #define AvmThunkCoerce_int32_t_avmplus_Atom(v)      (AvmThunkCanBeSmallIntAtom(v) ? AvmThunkSmallIntAtom(v) : env->core()->intAtom(v))

    #define AvmThunkCoerce_uint32_t_double(v)           double(v)
    #define AvmThunkCoerce_uint32_t_int32_t(v)          int32_t(v)
    #define AvmThunkCoerce_uint32_t_avmplus_Atom(v)     (AvmThunkCanBeSmallIntAtom(v) ? AvmThunkSmallIntAtom(v) : env->core()->intAtom(v))

    #define AvmThunkCoerce_avmplus_bool32_avmplus_Atom(v)       ((v) ? trueAtom : falseAtom)

#ifdef _DEBUG
    REALLY_INLINE double AvmThunkCoerce_avmplus_Atom_double(Atom v) { AvmAssert((v) == undefinedAtom); (void)v; return MathUtils::kNaN; }
    REALLY_INLINE String* AvmThunkCoerce_avmplus_Atom_avmplus_String_(Atom v) { AvmAssert((v) == undefinedAtom || (v) == nullObjectAtom); (void)v; return NULL; }
    REALLY_INLINE ScriptObject* AvmThunkCoerce_avmplus_Atom__avmplus_ScriptObject_(Atom v) { AvmAssert((v) == undefinedAtom || (v) == nullObjectAtom); (void)v; return NULL; }
#else
    #define AvmThunkCoerce_avmplus_Atom_double(v)                   (MathUtils::kNaN)
    #define AvmThunkCoerce_avmplus_Atom_avmplus_String_(v)          (NULL)
    #define AvmThunkCoerce_avmplus_Atom__avmplus_ScriptObject_(v)    (NULL)
#endif

    #define AvmThunkCoerce_avmplus_String__avmplus_Atom(v)          ((v) ? (v)->atom() : nullStringAtom)

    #define AvmThunkGetConstantString(v)        (env->method->pool()->getString(v))

#ifdef VMCFG_INDIRECT_NATIVE_THUNKS
    #define AVMTHUNK_GET_METHOD_HANDLER(env)    ((env)->method->handler_method())
    #define AVMTHUNK_GET_FUNCTION_HANDLER(env)  ((env)->method->handler_function())
#endif

#ifdef VMCFG_INDIRECT_NATIVE_THUNKS
    union AvmThunkNativeHandler
    {
        AvmThunkNativeMethodHandler method;
        AvmThunkNativeFunctionHandler function;
    };
#endif

    struct NativeMethodInfo
    {
    public:
#ifdef VMCFG_INDIRECT_NATIVE_THUNKS
        AvmThunkNativeHandler handler;
#endif
        GprMethodProc thunker;
#ifdef AVMPLUS_STATIC_POINTERS
        int32_t method_id;
#endif
    };

    struct NativeClassInfo
    {
    public:
        CreateClassClosureProc createClassClosure;
#ifdef AVMPLUS_STATIC_POINTERS
        int32_t class_id;
#endif
        uint16_t sizeofClass;
        uint16_t offsetofSlotsClass;
        uint16_t sizeofInstance;
        uint16_t offsetofSlotsInstance;
        bool hasCustomConstruct;
        bool isRestrictedInheritance;
        bool isAbstractBase;
    };


    // ---------------

    class NativeInitializer
    {
    public:
        NativeInitializer(AvmCore* core,
            char const* const* versioned_uris,
            #ifdef VMCFG_AOT
                const AOTInfo *aotInfo,
            #else
                const uint8_t* abcData,
                uint32_t abcDataLen,
            #endif
            uint32_t methodCount,
            uint32_t classCount);

        ~NativeInitializer();

        PoolObject* parseBuiltinABC(Domain* domain);

        const NativeMethodInfo* getNativeInfo(uint32_t i) const { return get_method(i); }

        #ifdef VMCFG_AOT
            bool getCompiledInfo(NativeMethodInfo *info, Multiname &returnTypeName, uint32_t i) const;
            bool hasBuiltins() const { return methodCount || classCount; }
            const AOTInfo* get_aotInfo() const { return aotInfo; }
        #endif

        #ifdef AVMPLUS_STATIC_POINTERS
            void fillInMethods(const NativeMethodInfo* methodEntry);
            void fillInClasses(const NativeClassInfo* classEntry);
            #ifdef VMCFG_AOT
                REALLY_INLINE const NativeClassInfo* get_class(uint32_t i) const
                {
                    return i < classCount ? classes[i] : 0;
                }
            #else
                REALLY_INLINE const NativeClassInfo* get_class(uint32_t i) const { AvmAssert(i < classCount); return classes[i]; }
            #endif
        #else
            typedef void (*FillInProc)(NativeMethodInfo* m, NativeClassInfo* c);
            void fillIn(FillInProc p);
            REALLY_INLINE const NativeClassInfo* get_class(uint32_t i) const { AvmAssert(i < classCount); return &classes[i]; }
        #endif

    private:
        #ifdef AVMPLUS_STATIC_POINTERS
            typedef const NativeMethodInfo* MethodType;
            typedef const NativeClassInfo* ClassType;
            REALLY_INLINE const NativeMethodInfo* get_method(uint32_t i) const { AvmAssert(i < methodCount); return methods[i]; }
        #else
            typedef NativeMethodInfo MethodType;
            typedef NativeClassInfo ClassType;
            REALLY_INLINE const NativeMethodInfo* get_method(uint32_t i) const { AvmAssert(i < methodCount); return &methods[i]; }
        #endif

    private:
        AvmCore* const                          core;
        char const* const*                      versioned_uris;
        const uint8_t* const                    abcData;
        uint32_t const                          abcDataLen;
        MethodType* const                       methods;
        ClassType* const                        classes;
        const uint32_t                          methodCount;
        const uint32_t                          classCount;
        #ifdef VMCFG_AOT
        const AOTInfo*                          aotInfo;
        const AvmThunkNativeFunctionHandler*    compiledMethods;
        const uint32_t                          compiledMethodCount;
        #endif
    };

#ifdef VMCFG_INDIRECT_NATIVE_THUNKS
    #define _NATIVE_METHOD_CAST_PTR(CLS, PTR) \
        reinterpret_cast<AvmThunkNativeMethodHandler>((void(CLS::*)())(PTR))
#endif

#ifdef _DEBUG
    #define AVMTHUNK_NATIVE_CLASS_GLUE(CLS, FQCLS, CREATE_FUNC, ASSERT_FUNC) \
        static ClassClosure* FASTCALL CLS##_createClassClosure(VTable* cvtable) \
        { \
            cvtable->ivtable->createInstanceProc = CREATE_FUNC; \
            FQCLS* cc = new (cvtable->gc(), cvtable->getExtraSize()) FQCLS(cvtable); \
            ASSERT_FUNC(cc->traits(), cc->traits()->itraits); \
            return cc; \
        }
    #define AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(CLS, FQCLS, CREATE_FUNC, ASSERT_FUNC) \
        static ClassClosure* FASTCALL CLS##_createClassClosure(VTable* cvtable) \
        { \
            cvtable->ivtable->createInstanceProc = CREATE_FUNC; \
            FQCLS* cc = FQCLS::create(cvtable->gc(), cvtable); \
            ASSERT_FUNC(cc->traits(), cc->traits()->itraits); \
            return cc; \
        }
#else
    #define AVMTHUNK_NATIVE_CLASS_GLUE(CLS, FQCLS, CREATE_FUNC, ASSERT_FUNC) \
        static ClassClosure* FASTCALL CLS##_createClassClosure(VTable* cvtable) \
        { \
            cvtable->ivtable->createInstanceProc = CREATE_FUNC; \
            FQCLS* cc = new (cvtable->gc(), cvtable->getExtraSize()) FQCLS(cvtable); \
            return cc; \
        }
    #define AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(CLS, FQCLS, CREATE_FUNC, ASSERT_FUNC) \
        static ClassClosure* FASTCALL CLS##_createClassClosure(VTable* cvtable) \
        { \
            cvtable->ivtable->createInstanceProc = CREATE_FUNC; \
            FQCLS* cc = FQCLS::create(cvtable->gc(), cvtable); \
            return cc; \
        }
#endif

#ifdef VMCFG_AOT
    #define AVMTHUNK_DECLARE_NATIVE_INITIALIZER(NAME) \
        extern PoolObject* initBuiltinABC_##NAME(AvmCore* core, Domain* domain); \
        extern const NativeClassInfo NAME##_classEntries[]; \
        extern const NativeMethodInfo NAME##_methodEntries[];
#else
    #define AVMTHUNK_DECLARE_NATIVE_INITIALIZER(NAME) \
        extern PoolObject* initBuiltinABC_##NAME(AvmCore* core, Domain* domain);
#endif

#ifdef AVMPLUS_STATIC_POINTERS

    #define AVMTHUNK_BEGIN_NATIVE_TABLES(NAME)
    #define AVMTHUNK_END_NATIVE_TABLES()

    // ---------------

#ifdef VMCFG_AOT
    #define AVMTHUNK_BEGIN_NATIVE_METHODS(NAME) \
        const NativeMethodInfo NAME##_methodEntries[] = {
#else
    #define AVMTHUNK_BEGIN_NATIVE_METHODS(NAME) \
        static const NativeMethodInfo NAME##_methodEntries[] = {
#endif

#ifdef VMCFG_INDIRECT_NATIVE_THUNKS
    #define _AVMTHUNK_NATIVE_METHOD(CLS, METHID, IMPL) \
        { { _NATIVE_METHOD_CAST_PTR(CLS, &IMPL) }, (GprMethodProc)avmplus::NativeID::METHID##_thunk, avmplus::NativeID::METHID },
#else
    #define _AVMTHUNK_NATIVE_METHOD(CLS, METHID, IMPL) \
        { (GprMethodProc)avmplus::NativeID::METHID##_thunk, avmplus::NativeID::METHID },
#endif

    #define AVMTHUNK_NATIVE_METHOD(METHID, IMPL) \
        _AVMTHUNK_NATIVE_METHOD(ScriptObject, METHID, IMPL)

    #define AVMTHUNK_NATIVE_METHOD_STRING(METHID, IMPL) \
        _AVMTHUNK_NATIVE_METHOD(avmplus::String, METHID, IMPL)

    #define AVMTHUNK_NATIVE_METHOD_NAMESPACE(METHID, IMPL) \
        _AVMTHUNK_NATIVE_METHOD(avmplus::Namespace, METHID, IMPL)

#ifdef VMCFG_AOT
    // AOT build env is ok with designated inits
    #define AVMTHUNK_NATIVE_FUNCTION(METHID, IMPL) \
        { { function: reinterpret_cast<AvmThunkNativeFunctionHandler>(IMPL) }, (GprMethodProc)avmplus::NativeID::METHID##_thunk, avmplus::NativeID::METHID },
    #define AVMTHUNK_END_NATIVE_METHODS() \
        { { NULL }, NULL, -1 } };
#else
#ifdef VMCFG_INDIRECT_NATIVE_THUNKS
    // C++ won't let us auto-init a union to a field other than the first one, nor will it
    // allow us to reliably cast between a pointer-to-function and pointer-to-member-function,
    // thus this inline function to massage the few places that need it.
    REALLY_INLINE AvmThunkNativeMethodHandler _to_method_handler(AvmThunkNativeFunctionHandler function)
    {
        AvmThunkNativeHandler handler;
        // FIXME: this fixes bug 596608 (see also 599931)
        handler.method = NULL;
        handler.function = function;
        return handler.method;
    }

    #define AVMTHUNK_NATIVE_FUNCTION(METHID, IMPL) \
        { { _to_method_handler(reinterpret_cast<AvmThunkNativeFunctionHandler>(IMPL)) }, (GprMethodProc)avmplus::NativeID::METHID##_thunk, avmplus::NativeID::METHID },

    #define AVMTHUNK_END_NATIVE_METHODS() \
        { { NULL }, NULL, -1 } };
#else

    #define AVMTHUNK_NATIVE_FUNCTION(METHID, IMPL) \
        { (GprMethodProc)avmplus::NativeID::METHID##_thunk, avmplus::NativeID::METHID },

    #define AVMTHUNK_END_NATIVE_METHODS() \
        { NULL, -1 } };

#endif
#endif

    // ---------------

    #define AVMTHUNK_BEGIN_NATIVE_CLASSES(NAME) \
        const NativeClassInfo NAME##_classEntries[] = {

    #define AVMTHUNK_NATIVE_CLASS(CLSID, CLS, FQCLS, OFFSETOFSLOTSCLS, INST, OFFSETOFSLOTSINST, CUSTOMCONSTRUCT, RESTRICTEDINHERITANCE, ABSTRACTBASE) \
        { CLS##_createClassClosure,\
          avmplus::NativeID::CLSID,\
          sizeof(FQCLS),\
          OFFSETOFSLOTSCLS,\
          sizeof(INST),\
          OFFSETOFSLOTSINST,\
          CUSTOMCONSTRUCT,\
          RESTRICTEDINHERITANCE,\
          ABSTRACTBASE\
        },

    #define AVMTHUNK_END_NATIVE_CLASSES() \
        { NULL, -1, 0, 0, 0, 0, false, false, false } };

#ifdef VMCFG_AOT
    #define AVMTHUNK_DEFINE_NATIVE_INITIALIZER(NAME)
#else
    #define AVMTHUNK_DEFINE_NATIVE_INITIALIZER(NAME) \
        PoolObject* initBuiltinABC_##NAME(AvmCore* core, Domain* domain) { \
            NativeInitializer ninit(core, \
                avmplus::NativeID::NAME##_versioned_uris, \
                avmplus::NativeID::NAME##_abc_data, \
                avmplus::NativeID::NAME##_abc_length, \
                avmplus::NativeID::NAME##_abc_method_count, \
                avmplus::NativeID::NAME##_abc_class_count); \
            ninit.fillInClasses(NAME##_classEntries); \
            ninit.fillInMethods(NAME##_methodEntries); \
            return ninit.parseBuiltinABC(domain); \
        }
#endif
#else

    #define AVMTHUNK_BEGIN_NATIVE_TABLES(NAME) \
        static void fillIn_##NAME(NativeMethodInfo* m, NativeClassInfo* c) {

    #define AVMTHUNK_END_NATIVE_TABLES() \
        }

    // ---------------

    #define AVMTHUNK_BEGIN_NATIVE_METHODS(NAME)

#ifdef VMCFG_INDIRECT_NATIVE_THUNKS
    #define _AVMTHUNK_NATIVE_METHOD(CLS, METHID, IMPL) \
        m[METHID].handler.method = _NATIVE_METHOD_CAST_PTR(CLS, &IMPL); \
        m[METHID].thunker = (GprMethodProc)avmplus::NativeID::METHID##_thunk;
#else
    #define _AVMTHUNK_NATIVE_METHOD(CLS, METHID, IMPL) \
        m[METHID].thunker = (GprMethodProc)avmplus::NativeID::METHID##_thunk;
#endif

    #define AVMTHUNK_NATIVE_METHOD(METHID, IMPL) \
        _AVMTHUNK_NATIVE_METHOD(ScriptObject, METHID, IMPL)

    #define AVMTHUNK_NATIVE_METHOD_STRING(METHID, IMPL) \
        _AVMTHUNK_NATIVE_METHOD(avmplus::String, METHID, IMPL)

    #define AVMTHUNK_NATIVE_METHOD_NAMESPACE(METHID, IMPL) \
        _AVMTHUNK_NATIVE_METHOD(avmplus::Namespace, METHID, IMPL)

#ifdef VMCFG_INDIRECT_NATIVE_THUNKS
    #define AVMTHUNK_NATIVE_FUNCTION(METHID, IMPL) \
        m[METHID].handler.function = reinterpret_cast<AvmThunkNativeFunctionHandler>(IMPL); \
        m[METHID].thunker = (GprMethodProc)avmplus::NativeID::METHID##_thunk;
#else
    #define AVMTHUNK_NATIVE_FUNCTION(METHID, IMPL) \
        m[METHID].thunker = (GprMethodProc)avmplus::NativeID::METHID##_thunk;
#endif

    #define AVMTHUNK_END_NATIVE_METHODS()

    // ---------------

    #define AVMTHUNK_BEGIN_NATIVE_CLASSES(NAME)

    #define AVMTHUNK_NATIVE_CLASS(CLSID, CLS, FQCLS, OFFSETOFSLOTSCLS, INST, OFFSETOFSLOTSINST, CUSTOMCONSTRUCT, RESTRICTEDINHERITANCE, ABSTRACTBASE) \
        c[CLSID].createClassClosure = CLS##_createClassClosure; \
        c[CLSID].sizeofClass = sizeof(FQCLS); \
        c[CLSID].offsetofSlotsClass = OFFSETOFSLOTSCLS; \
        c[CLSID].sizeofInstance = sizeof(INST); \
        c[CLSID].offsetofSlotsInstance = OFFSETOFSLOTSINST;\
        c[CLSID].hasCustomConstruct = CUSTOMCONSTRUCT;\
        c[CLSID].isRestrictedInheritance = RESTRICTEDINHERITANCE;\
        c[CLSID].isAbstractBase = ABSTRACTBASE;

    #define AVMTHUNK_END_NATIVE_CLASSES()

    #define AVMTHUNK_DEFINE_NATIVE_INITIALIZER(NAME) \
        PoolObject* initBuiltinABC_##NAME(AvmCore* core, Domain* domain) { \
            NativeInitializer ninit(core, \
                avmplus::NativeID::NAME##_versioned_uris, \
                avmplus::NativeID::NAME##_abc_data, \
                avmplus::NativeID::NAME##_abc_length, \
                avmplus::NativeID::NAME##_abc_method_count, \
                avmplus::NativeID::NAME##_abc_class_count); \
            ninit.fillIn(fillIn_##NAME); \
            return ninit.parseBuiltinABC(domain); \
        }

#endif // AVMPLUS_STATIC_POINTERS

    #define AVM_INIT_BUILTIN_ABC_IN_DOMAIN(MAPNAME, CORE, DOMAIN) \
        avmplus::NativeID::initBuiltinABC_##MAPNAME((CORE), (DOMAIN))

    #define AVM_INIT_BUILTIN_ABC(MAPNAME, CORE) \
        avmplus::NativeID::initBuiltinABC_##MAPNAME((CORE), (CORE)->builtinDomain)

}

#endif /* __avmplus_NativeFunction__ */
