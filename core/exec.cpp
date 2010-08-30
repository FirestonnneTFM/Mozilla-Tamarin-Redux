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
 * Portions created by the Initial Developer are Copyright (C) 2010
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

#include "avmplus.h"
#include "../vprof/vprof.h"
#include "Interpreter.h"

namespace avmplus {

BaseExecMgr* BaseExecMgr::exec(VTable* vtable)
{
    return (BaseExecMgr*) vtable->core()->exec;
}

BaseExecMgr* BaseExecMgr::exec(MethodEnv* env)
{
    return (BaseExecMgr*) env->core()->exec;
}

BaseExecMgr::BaseExecMgr(AvmCore* core)
    : core(core)
    , config(core->config)
#ifdef VMCFG_VERIFYALL
    , verifyFunctionQueue(core->gc, 0)
    , verifyTraitsQueue(core->gc, 0)
#endif
{
#ifdef SUPERWORD_PROFILING
    WordcodeTranslator::swprofStart();
#endif
}

BaseExecMgr::~BaseExecMgr()
{
#ifdef SUPERWORD_PROFILING
    WordcodeTranslator::swprofStop();
#endif
}

// Called when MethodInfo is constructed.
void BaseExecMgr::init(MethodInfo* m, const NativeMethodInfo* native_info)
{
#ifndef MEMORY_INFO
    MMGC_STATIC_ASSERT(offsetof(MethodInfo, _implGPR) == 0);
#endif

    if (native_info) {
        m->_native.thunker = native_info->thunker;
        #ifdef VMCFG_INDIRECT_NATIVE_THUNKS
        m->_native.handler = native_info->handler;
        #endif
    } else {
        #ifdef VMCFG_VERIFYALL
        if (config.verifyonly && m->isNative())
            m->_hasMethodBody = 0;
        #endif
    }
    m->_implGPR = NULL;
    m->_invoker = NULL;
    if (m->isResolved() && !config.verifyall) {
        // notifyMethodResolved() won't be called; this method is
        // a synthetic init method that returns void.  So install
        // verify trampolines now.
        m->_implGPR = verifyEnterGPR;
        m->_invoker = verifyInvoke;
    }
}

#ifdef VMCFG_METHODENV_IMPL32

// Stub that is invoked when a methodenv is called the first time.
// Copy the invoker pointer from the underlying method, then call there.
uintptr_t BaseExecMgr::delegateInvoke(MethodEnv* env, int32_t argc, uint32_t *ap)
{
    env->_implGPR = env->method->_implGPR;
    return (*env->_implGPR)(env, argc, ap);
}

// Called when MethodInfo is constructed.
void BaseExecMgr::init(MethodEnv* env)
{
    env->_implGPR = delegateInvoke;
}
#else
// Called when MethodEnv is constructed.
void BaseExecMgr::init(MethodEnv*)
{}
#endif

// Called after MethodInfo is resolved.
void BaseExecMgr::notifyMethodResolved(MethodInfo* m, MethodSignaturep ms)
{
    if (!config.verifyall) {
        m->_invoker = verifyInvoke;
        if (ms->returnTraitsBT() == BUILTIN_number)
            m->_implFPR = verifyEnterFPR;
        else
            m->_implGPR = verifyEnterGPR;
    }
}

// True if at least one argument is typed and therefore must
// be coerced on invocation.
static bool hasTypedArgs(MethodSignaturep ms)
{
    int32_t param_count = ms->param_count();
    for (int32_t i = 1; i <= param_count; i++) {
        if (ms->paramTraits(i) != NULL) {
            // at least one parameter is typed; need full coerceEnter
            return true;
        }
    }
    return false;
}

// Initialize the declared slots of the given object by iterating
// through the ABC traits record and assigning to nonzero slots.
void initObj(MethodEnv* env, ScriptObject* obj)
{
    struct InterpInitVisitor: public InitVisitor {
        ScriptObject* obj;
        InterpInitVisitor(ScriptObject* obj) : obj(obj) {}
        ~InterpInitVisitor() {}
        void defaultVal(Atom val, uint32_t slot, Traits*) {
            // Assign the default value.
            // Keep in sync with interpreter INSTR(setslot).
            obj->coerceAndSetSlotAtom(slot, val);
        }
    };
    InterpInitVisitor visitor(obj);
    Traits* t = env->method->declaringTraits();
    const TraitsBindings *tb = t->getTraitsBindings();
    t->visitInitBody(&visitor, env->toplevel(), tb);
}

uintptr_t BaseExecMgr::init_interpGPR(MethodEnv* env, int argc, uint32_t* ap)
{
    initObj(env, (ScriptObject*) atomPtr(((uintptr_t*)ap)[0]));
    return interpGPR(env, argc, ap);
}

double BaseExecMgr::init_interpFPR(MethodEnv* env, int argc, uint32_t* ap)
{
    initObj(env, (ScriptObject*) atomPtr(((uintptr_t*)ap)[0]));
    return interpFPR(env, argc, ap);
}

Atom BaseExecMgr::init_invoke_interp(MethodEnv* env, int argc, Atom* args)
{
    initObj(env, (ScriptObject*) atomPtr(args[0]));
    return invoke_interp(env, argc, args);
}

Atom BaseExecMgr::init_invoke_interp_nocoerce(MethodEnv* env, int argc, Atom* args)
{
    initObj(env, (ScriptObject*) atomPtr(args[0]));
    return invoke_interp_nocoerce(env, argc, args);
}

void BaseExecMgr::setInterp(MethodInfo* m, MethodSignaturep ms)
{
    if (m->isConstructor()) {
        if (ms->returnTraitsBT() == BUILTIN_number)
            m->_implFPR = init_interpFPR;
        else
            m->_implGPR = init_interpGPR;
        m->_isInterpImpl = 1;
        m->_invoker = hasTypedArgs(ms)
            ? init_invoke_interp
            : init_invoke_interp_nocoerce;
    } else {
        setInterpDirectly(m, ms);
    }
}

void BaseExecMgr::setInterpDirectly(MethodInfo* m, MethodSignaturep ms)
{
    if (ms->returnTraitsBT() == BUILTIN_number)
        m->_implFPR = interpFPR;
    else
        m->_implGPR = interpGPR;
    m->_isInterpImpl = 1;
    m->_invoker = hasTypedArgs(ms)
        ? invoke_interp
        : invoke_interp_nocoerce;
}

uintptr_t BaseExecMgr::verifyEnterGPR(MethodEnv* env, int32_t argc, uint32_t* ap)
{
    verifyOnCall(env);
    STACKADJUST(); // align stack for 32-bit Windows and MSVC compiler
    uintptr_t ret = (*env->method->_implGPR)(env, argc, ap);
    STACKRESTORE();
    return ret;
}

double BaseExecMgr::verifyEnterFPR(MethodEnv* env, int32_t argc, uint32_t* ap)
{
    verifyOnCall(env);
    STACKADJUST(); // align stack for 32-bit Windows and MSVC compiler
    double d = (*env->method->_implFPR)(env, argc, ap);
    STACKRESTORE();
    return d;
}

// Entry point when the first call to the method is late bound.
Atom BaseExecMgr::verifyInvoke(MethodEnv* env, int argc, Atom* args)
{
    verifyOnCall(env);
    return (*env->method->_invoker)(env, argc, args);
}

void BaseExecMgr::verifyOnCall(MethodEnv* env)
{
    BaseExecMgr *exec = BaseExecMgr::exec(env);
    AvmAssert(!exec->config.verifyall);  // never verify late in verifyall mode

    #ifdef DEBUGGER
    // Install a fake CallStackNode here, so that if we throw a verify error,
    // we get a stack trace with the method being verified as its top entry.
    CallStackNode callStackNode(env->method);
    #endif

    exec->verifyMethod(env->method, env->toplevel(), env->abcEnv());

    #ifdef VMCFG_METHODENV_IMPL32
    // We got here by calling env->_implGPR, which was pointing to verifyEnterGPR/FPR,
    // but next time we want to call the real code, not verifyEnter again.
    // All other MethodEnv's in their default state will call the target method
    // directly and never go through verifyEnter().  Update the copy in MethodEnv.
    env->_implGPR = env->method->_implGPR;
    #endif
}

// Verify the given method according to its type, with a CodeWriter
// pipeline appropriate to the current execution mode.
void BaseExecMgr::verifyMethod(MethodInfo* m, Toplevel *toplevel, AbcEnv* abc_env)
{
    AvmAssert(m->declaringTraits()->isResolved());
    m->resolveSignature(toplevel);
    PERFM_NTPROF_BEGIN("verify-ticks");
    MethodSignaturep ms = m->getMethodSignature();
    if (m->isNative())
        verifyNative(m, ms);
#ifdef FEATURE_NANOJIT
    else if (shouldJit(m))
        verifyJit(m, ms, toplevel, abc_env);
#endif
    else
        verifyInterp(m, ms, toplevel, abc_env);
    PERFM_NTPROF_END("verify-ticks");
}

void BaseExecMgr::verifyInterp(MethodInfo* m, MethodSignaturep ms, Toplevel *toplevel, AbcEnv* abc_env)
{
#ifdef VMCFG_WORDCODE
    WordcodeEmitter coder(m, toplevel);
#else
    CodeWriter coder;
#endif
    verifyCommon(m, ms, toplevel, abc_env, &coder);
#ifdef AVMPLUS_VERBOSE
# ifdef FEATURE_NANOJIT
    if (m->pool()->isVerbose(VB_execpolicy)) // Currently shouldn't print "unknown", accounting for code evolution.
        core->console << "execpolicy interp " << m << (shouldJit(m) ? " unknown\n" : " jit-policy\n");
# else
    if (m->pool()->isVerbose(VB_execpolicy))
        core->console << "execpolicy interp " << m << "\n";
# endif
#endif
    setInterp(m, ms);
}

// run the verifier, and if an exception is thrown,
// clean up the CodeWriter chain passed in by calling coder->cleanup().
// On normal return the CodeWriters declared here get cleaned via their
// destructors, and passed-in CodeWriters are still valid.
void BaseExecMgr::verifyCommon(MethodInfo* m, MethodSignaturep ms,
        Toplevel* toplevel, AbcEnv* abc_env, CodeWriter* const coder)
{
    CodeWriter* volatile vcoder = coder; // Volatile for setjmp safety.

#ifdef VMCFG_VERIFYALL
    VerifyallWriter verifyall(m, this, vcoder);
    if (config.verifyall)
        vcoder = &verifyall;
#endif

    Verifier verifier(m, ms, toplevel, abc_env); // Does not throw.
    TRY(core, kCatchAction_Rethrow) {
        verifier.verify(vcoder);  // Verify and fill vcoder pipeline.
    }
    CATCH (Exception *exception) {
        verifier.~Verifier();   // Clean up verifier.
        vcoder->cleanup();      // Cleans up all coders.
        core->throwException(exception);
    }
    END_CATCH
    END_TRY
}

#ifdef DEBUGGER
/*static*/
uintptr_t BaseExecMgr::debugEnterExitWrapper32(MethodEnv* env, int32_t argc, uint32_t* argv)
{
    CallStackNode csn(CallStackNode::kEmpty);
    env->debugEnter(/*frame_sst*/NULL, &csn, /*framep*/NULL, /*eip*/NULL);
    GprMethodProc thunk = (GprMethodProc) env->method->_native.thunker;
    const uintptr_t result = thunk(env, argc, argv);
    env->debugExit(&csn);
    return result;
}

/*static*/
double BaseExecMgr::debugEnterExitWrapperN(MethodEnv* env, int32_t argc, uint32_t* argv)
{
    CallStackNode csn(CallStackNode::kEmpty);
    env->debugEnter(/*frame_sst*/NULL, &csn, /*framep*/NULL, /*eip*/NULL);
    const double result = (reinterpret_cast<FprMethodProc>(env->method->_native.thunker))(env, argc, argv);
    env->debugExit(&csn);
    return result;
}
#endif

void BaseExecMgr::verifyNative(MethodInfo* m, MethodSignaturep ms)
{
#ifdef DEBUGGER
    if (core->debugger())
    {
        if (ms->returnTraitsBT() == BUILTIN_number)
            setNative(m, (GprMethodProc) debugEnterExitWrapperN);
        else
            setNative(m, debugEnterExitWrapper32);
    }
    else
#endif
    {
        (void)ms;
        setNative(m, (GprMethodProc) m->_native.thunker);
    }
}

#ifndef FEATURE_NANOJIT

// Install the generic, interpretive invoker for a native method.
// FIXME: Bug 529832 - We could specialize several common cases without JIT compiling.
void BaseExecMgr::setNative(MethodInfo* m, GprMethodProc p)
{
    m->_implGPR = p;
    m->_invoker = invoke_generic;
}

// Without a JIT, we don't need to build any IMTs.
void BaseExecMgr::notifyVTableResolved(VTable*)
{}

#endif


// Only unbox the value (convert atom to native representation), coerce
// must have already happened.
Atom* FASTCALL BaseExecMgr::unbox1(MethodEnv* env, Atom atom, Traits* t, Atom* arg0)
{
    (void)env;
    AvmAssert(atom == env->toplevel()->coerce(atom, t)); // Atom must be correct type already, we're just unboxing it.
    switch (Traits::getBuiltinType(t))
    {
        case BUILTIN_any:
        case BUILTIN_object:
        case BUILTIN_void:
            // My, that was easy.
            break;

        case BUILTIN_boolean:
            atom = (Atom) ((atom>>3) != 0);
            break;

        case BUILTIN_int:
            atom = AvmCore::integer_i(atom);
            break;

        case BUILTIN_uint:
            atom = AvmCore::integer_u(atom);
            break;

        case BUILTIN_number:
        {
            #ifdef AVMPLUS_64BIT
                AvmAssert(sizeof(Atom) == sizeof(double));
                union
                {
                    double d;
                    Atom a;
                };
                d = AvmCore::number_d(atom);
                atom = a;
            #else
                AvmAssert(sizeof(Atom)*2 == sizeof(double));
                union
                {
                    double d;
                    Atom a[2];
                };
                d = AvmCore::number_d(atom);
                arg0[0] = a[0];
                arg0 += 1;
                atom = a[1];    // Fall through, will be handled at end.
            #endif
            break;
        }

        default:
            atom = (Atom)atomPtr(atom);
            break;
    }
    // Every case increments by at least 1.
    arg0[0] = atom;
    return arg0+1;
}

// Coerce and unbox one argument.
// Note that some of these have (partial) guts of avmplus::coerce replicated here, for efficiency.
// If you find bugs here, you might need to update avmplus::coerce as well (and vice versa).
Atom* FASTCALL BaseExecMgr::coerceUnbox1(MethodEnv* env, Atom atom, Traits* t, Atom* args)
{
    // Using computed-gotos here doesn't move the needle appreciably in testing.
    switch (Traits::getBuiltinType(t))
    {
        case BUILTIN_any:
            // My, that was easy.
            break;

        case BUILTIN_boolean:
            atom = AvmCore::boolean(atom);
            break;

        case BUILTIN_int:
            atom = AvmCore::integer(atom);
            break;

        case BUILTIN_uint:
            atom = AvmCore::toUInt32(atom);
            break;

        case BUILTIN_namespace:
            // Coerce undefined -> Namespace should yield null.
            if (AvmCore::isNullOrUndefined(atom))
            {
                atom = 0;
                break;
            }
            if (atomKind(atom) != kNamespaceType)
                goto failure;
            atom = (Atom)atomPtr(atom);
            break;

        case BUILTIN_number:
        {
            #ifdef AVMPLUS_64BIT
                AvmAssert(sizeof(Atom) == sizeof(double));
                union
                {
                    double d;
                    Atom a;
                };
                d = AvmCore::number(atom);
                atom = a;
            #else
                AvmAssert(sizeof(Atom)*2 == sizeof(double));
                union
                {
                    double d;
                    Atom a[2];
                };
                d = AvmCore::number(atom);
                args[0] = a[0];
                args += 1;
                atom = a[1];    // Fall thru, will be handled at end.
            #endif
            break;
        }
        case BUILTIN_object:
            if (atom == undefinedAtom)
                atom = nullObjectAtom;
            break;

        case BUILTIN_string:
            atom = AvmCore::isNullOrUndefined(atom) ? NULL : (Atom)env->core()->string(atom);
            break;

        case BUILTIN_null:
        case BUILTIN_void:
            AvmAssert(!"illegal, should not happen");
            atom = 0;
            break;

        case BUILTIN_date:
        case BUILTIN_math:
        case BUILTIN_methodClosure:
        case BUILTIN_qName:
        case BUILTIN_vector:
        case BUILTIN_vectordouble:
        case BUILTIN_vectorint:
        case BUILTIN_vectoruint:
        case BUILTIN_xml:
        case BUILTIN_xmlList:
            // A few intrinsic final classes can skip subtypeof calls.
            if (AvmCore::isNullOrUndefined(atom))
            {
                atom = 0;
                break;
            }
            else if (atomKind(atom) == kObjectType)
            {
                Traits* actual = AvmCore::atomToScriptObject(atom)->traits();
                AvmAssert(actual->final);
                if (actual == t)
                {
                    atom = (Atom)atomPtr(atom);
                    break;
                }
            }
            // Didn't break? that's a failure.
            goto failure;

        case BUILTIN_array:
        case BUILTIN_class:
        case BUILTIN_error:
        case BUILTIN_function:
        case BUILTIN_none:
        case BUILTIN_regexp:
        case BUILTIN_vectorobj: // Unlike other vector types, vectorobj is NOT final.
            if (AvmCore::isNullOrUndefined(atom))
            {
                atom = 0;
                break;
            }
            else if (atomKind(atom) == kObjectType)
            {
                Traits* actual = AvmCore::atomToScriptObject(atom)->traits();
                if (actual->subtypeof(t))
                {
                    atom = (Atom)atomPtr(atom);
                    break;
                }
            }
            // Didn't break? that's a failure.
            goto failure;
    }
    // Every case increments by at least 1.
    args[0] = atom;
    return args+1;

failure:
    AvmCore* core = env->core();
    env->toplevel()->throwTypeError(kCheckTypeFailedError, core->atomToErrorString(atom), core->toErrorString(t));
    return unreachableAtom;
}

// Coerce an argument to an expected type, but keep it represented as Atom.
// Note that this function is (currently) only used for interpreted functions.
inline Atom coerceAtom(AvmCore* core, Atom atom, Traits* t, Toplevel* toplevel)
{
    switch (Traits::getBuiltinType(t))
    {
    case BUILTIN_number:
        return (atomKind(atom) == kDoubleType) ? atom : core->numberAtom(atom);
    case BUILTIN_int:
        return (atomKind(atom) == kIntptrType) ? atom : core->intAtom(atom);
    case BUILTIN_uint:
        return (atomKind(atom) == kIntptrType && atom >= 0) ? atom : core->uintAtom(atom);
    case BUILTIN_boolean:
        return (atomKind(atom) == kBooleanType) ? atom : AvmCore::booleanAtom(atom);
    case BUILTIN_object:
        return (atom == undefinedAtom) ? nullObjectAtom : atom;
    case BUILTIN_any:
        return atom;
    default:
        return toplevel->coerce(atom, t);
    }
}

inline Atom BaseExecMgr::endCoerce(MethodEnv* env, int32_t argc, uint32_t *ap, MethodSignaturep ms)
{
    // We know we have verified the method, so we can go right into it.
    AvmCore* core = env->core();
    const int32_t bt = ms->returnTraitsBT();
    if (bt == BUILTIN_number)
    {
        STACKADJUST(); // align stack for 32-bit Windows and MSVC compiler
        double d = (*env->method->_implFPR)(env, argc, ap);
        STACKRESTORE();
        return core->doubleToAtom(d);
    }

    STACKADJUST(); // align stack for 32-bit Windows and MSVC compiler
    const Atom i = (*env->method->_implGPR)(env, argc, ap);
    STACKRESTORE();

    switch (bt)
    {
    case BUILTIN_int:
        return core->intToAtom((int32_t)i);
    case BUILTIN_uint:
        return core->uintToAtom((uint32_t)i);
    case BUILTIN_boolean:
        return i ? trueAtom : falseAtom;
    case BUILTIN_any:
    case BUILTIN_object:
    case BUILTIN_void:
        return (Atom)i;
    case BUILTIN_string:
        return ((Stringp)i)->atom();
    case BUILTIN_namespace:
        return ((Namespace*)i)->atom();
    default:
        return ((ScriptObject*)i)->atom();
    }
}

inline void checkArgc(MethodEnv *env, int32_t argc, MethodSignaturep ms)
{
    // Getting toplevel() is slightly more expensive than it used to be (more indirection)...
    // so only extract in the (rare) event of an exception.

    if (!ms->argcOk(argc))
        env->argcError(argc);

    // Should no longer be possible to have mismatched scopes; we should reject any such
    // functions in makeIntoPrototypeFunction().
    AvmAssert(env->method->declaringScope() == env->scope()->scopeTraits());
}

// static
inline size_t BaseExecMgr::startCoerce(MethodEnv *env, int32_t argc, MethodSignaturep ms)
{
    checkArgc(env, argc, ms);

    // Compute the number of rest arguments present.
    const int32_t param_count = ms->param_count();
    const int32_t extra = argc > param_count ? argc - param_count : 0;
    AvmAssert(ms->rest_offset() > 0 && extra >= 0);
    const int32_t rest_offset = ms->rest_offset();
    return rest_offset + sizeof(Atom)*extra;
}

// Specialized to be called from Function.apply().
Atom BaseExecMgr::apply(MethodEnv* env, Atom thisArg, ArrayObject *a)
{
    int32_t argc = a->getLength();
    if (argc == 0)
        return env->coerceEnter(thisArg);

    if (isInterpreted(env)) {
        // Caller will coerce instance if necessary, so make sure it was done.
        AvmAssert(thisArg == coerce(env, thisArg, env->get_ms()->paramTraits(0)));

        // Tail call inhibited by local allocation/deallocation.
        MMgc::GC::AllocaAutoPtr _atomv;
        Atom* atomv = (Atom*)VMPI_alloca(core, _atomv, sizeof(Atom)*(argc+1));
        atomv[0] = thisArg;
        for (int32_t i=0 ; i < argc ; i++ )
            atomv[i+1] = a->getUintProperty(i);
        return env->coerceEnter(argc, atomv);
    }

    // Unverified, JIT, or native method.
    MethodSignaturep ms = env->get_ms();
    const size_t extra_sz = startCoerce(env, argc, ms);
    MMgc::GC::AllocaAutoPtr _ap;
    uint32_t *ap = (uint32_t *)VMPI_alloca(core, _ap, extra_sz);
    unboxCoerceArgs(env, thisArg, a, ap, ms);
    return endCoerce(env, argc, ap, ms);
}

// Specialized to be called from Function.call().
Atom BaseExecMgr::call(MethodEnv* env, Atom thisArg, int argc, Atom *argv)
{
    if (argc == 0)
        return env->coerceEnter(thisArg);

    if (isInterpreted(env)) {
        // Caller will coerce instance if necessary, so make sure it was done.
        AvmAssert(thisArg == coerce(env, thisArg, env->get_ms()->paramTraits(0)));

        // Tail call inhibited by local allocation/deallocation.
        MMgc::GC::AllocaAutoPtr _atomv;
        Atom* atomv = (Atom*)VMPI_alloca(core, _atomv, sizeof(Atom)*(argc+1));
        atomv[0] = thisArg;
        VMPI_memcpy(atomv+1, argv, sizeof(Atom)*argc);
        return env->coerceEnter(argc, atomv);
    }

    // Unverified, JIT, or native method.
    MethodSignaturep ms = env->get_ms();
    const size_t extra_sz = startCoerce(env, argc, ms);
    MMgc::GC::AllocaAutoPtr _ap;
    uint32_t *ap = (uint32_t *)VMPI_alloca(core, _ap, extra_sz);
    unboxCoerceArgs(env, thisArg, argc, argv, ap, ms);
    return endCoerce(env, argc, ap, ms);
}

// Optimization opportunities: since we call interpBoxed() directly, it is
// probably possible to allocate its stack frame here and pass it in.
// If we do so then interpBoxed() should deallocate it.  This affords us
// the optimization of getting rid of alloca() allocation here,
// which means improved tail calls for one.  For another, if the argv
// pointer points into the stack segment s.t. argv+argc+1 equals the
// current stack pointer then the stack may be extended in place
// provided there's space.  But that optimization may equally well
// be performed inside interpBoxed(), and in fact if we alloc temp
// space on the alloca stack here then interpBoxed() would always perform
// that optimization.  So we'd just be moving the decision into interpBoxed().

// note that GCC typically restricts tailcalls to functions with similar signatures
// ("sibcalls") -- see http://www.ddj.com/architect/184401756 for a useful explanation.
// anyway, since we really want interpBoxed to be a tailcall from
// here, be sure to keep it using a compatible signature...
Atom BaseExecMgr::invoke_interp(MethodEnv* env, int32_t argc, Atom* atomv)
{
    // The tail call to interpBoxed is important in order to keep stack consumption down in an
    // interpreter-only configuration, but it's good always.

    AvmAssert(isInterpreted(env));
    AvmCore* core = env->core();
    Toplevel* toplevel = env->toplevel();

    MethodSignaturep ms = env->get_ms();
    checkArgc(env, argc, ms);

    // Caller will coerce instance if necessary, so make sure it was done.
    AvmAssert(atomv[0] == coerce(env, atomv[0], ms->paramTraits(0)));

    const int32_t param_count = ms->param_count();
    const int32_t end = argc >= param_count ? param_count : argc;
    for (int32_t i=1 ; i <= end ; i++ )
        atomv[i] = coerceAtom(core, atomv[i], ms->paramTraits(i), toplevel);
    return interpBoxed(env, argc, atomv);
}

// Specialized copy of invoke_interp() when there are no typed args.
Atom BaseExecMgr::invoke_interp_nocoerce(MethodEnv* env, int32_t argc, Atom* atomv)
{
    // The tail call to interpBoxed is important in order to keep stack consumption down in an
    // interpreter-only configuration, but it's good always.

    MethodSignaturep ms = env->get_ms();
    checkArgc(env, argc, ms);

#ifdef DEBUG
    AvmAssert(isInterpreted(env));
    // caller will coerce instance if necessary, so make sure it was done.
    AvmAssert(atomv[0] == coerce(env, atomv[0], ms->paramTraits(0)));
    const int32_t param_count = ms->param_count();
    const int32_t end = argc >= param_count ? param_count : argc;
    for (int32_t i=1 ; i <= end ; i++ )
        AvmAssert(ms->paramTraits(i) == NULL);
#endif

    return interpBoxed(env, argc, atomv);
}

// Invoker for native or jit code used before we have jit-compiled,
// or after JIT compilation of the invoker has failed.
Atom BaseExecMgr::invoke_generic(MethodEnv *env, int32_t argc, Atom* atomv)
{
    MethodSignaturep ms = env->get_ms();
    const size_t extra_sz = startCoerce(env, argc, ms);
    MMgc::GC::AllocaAutoPtr _ap;
    uint32_t *ap = (uint32_t *)VMPI_alloca(env->core(), _ap, extra_sz);
    unboxCoerceArgs(env, argc, atomv, ap, ms);
    return endCoerce(env, argc, ap, ms);
}

// Convert atoms to native args.  argc is the number of
// args, not counting the instance which is arg[0].  the
// layout is [instance][arg1..argN]
void BaseExecMgr::unboxCoerceArgs(MethodEnv* env, int32_t argc, Atom* in, uint32_t *argv, MethodSignaturep ms)
{
    Atom* args = (Atom*)argv;

    const int32_t param_count = ms->param_count();
    int32_t end = argc >= param_count ? param_count : argc;
    args = unbox1(env, in[0], ms->paramTraits(0), args); // no need to coerce
    for (int32_t i=1; i <= end; i++)
        args = coerceUnbox1(env, in[i], ms->paramTraits(i), args);
    while (end < argc)
        *args++ = in[++end];
}

// Specialized for Function.apply().
void BaseExecMgr::unboxCoerceArgs(MethodEnv* env, Atom thisArg, ArrayObject *a, uint32_t *argv, MethodSignaturep ms)
{
    int32_t argc = a->getLength();

    Atom *args = unbox1(env, thisArg, ms->paramTraits(0), (Atom *) argv);

    const int32_t param_count = ms->param_count();
    int32_t end = argc >= param_count ? param_count : argc;
    for (int32_t i=0; i < end; i++)
        args = coerceUnbox1(env, a->getUintProperty(i), ms->paramTraits(i+1), args);
    while (end < argc)
        *args++ = a->getUintProperty(end++);
}

// Specialized for Function.call().
void BaseExecMgr::unboxCoerceArgs(MethodEnv* env, Atom thisArg, int32_t argc, Atom* in, uint32_t *argv, MethodSignaturep ms)
{
    Atom *args = unbox1(env, thisArg, ms->paramTraits(0), (Atom *) argv);

    const int32_t param_count = ms->param_count();
    int32_t end = argc >= param_count ? param_count : argc;
    for (int32_t i=0; i < end; i++)
        args = coerceUnbox1(env, in[i], ms->paramTraits(i+1), args);
    while (end < argc)
        *args++ = in[end++];
}

// Transition from JIT code to the interpreter.
uintptr_t BaseExecMgr::interpGPR(MethodEnv* env, int argc, uint32_t *ap)
{
    Atom* const atomv = (Atom*)ap;
    MethodSignaturep ms = env->method->getMethodSignature();
    ms->boxArgs(env->core(), argc, (uint32_t *)ap, atomv);
    Atom a = interpBoxed(env, argc, atomv);
    const BuiltinType bt = ms->returnTraitsBT();
    const uint32_t ATOM_MASK = (1U<<BUILTIN_object) | (1U<<BUILTIN_void) | (1U << BUILTIN_any);
    if ((1U<<bt) & ATOM_MASK)
        return a;
    if (bt == BUILTIN_int)
        return AvmCore::integer_i(a);
    if (bt == BUILTIN_uint)
        return AvmCore::integer_u(a);
    if (bt == BUILTIN_boolean)
        return a>>3;
    return a & ~7; // Possibly null pointer.
}

// Transition from JIT code to the interpreter, for a function returning double.
double BaseExecMgr::interpFPR(MethodEnv* env, int argc, uint32_t * ap)
{
    Atom* const atomv = (Atom*)ap;
    MethodSignaturep ms = env->method->getMethodSignature();
    ms->boxArgs(env->core(), argc, (uint32_t *)ap, atomv);
    Atom a = interpBoxed(env, argc, atomv);
    return AvmCore::number_d(a);
}

} // namespace avmplus
