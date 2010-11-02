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

#ifndef __avmplus_exec__
#define __avmplus_exec__

namespace avmplus {

/**
 *  Execution manager pure virtual interface.  An execution manager implementation
 *  is responsible for all aspects of AS3 execution, including invocation,
 *  policy decisions for how to execute, when to verify, and when to translate,
 *  if needed.
 *
 *  Although some configurations may only have one concrete implementation,
 *  we use ordinary polymorphism instead of build-time polymorphism, to keep
 *  things simple.
 */
class ExecMgr
{
public:
    virtual ~ExecMgr() {}

    /** Called when a MethodInfo is allocated. */
    virtual void init(MethodInfo*, const NativeMethodInfo*) = 0;

    /** Called when a MethodEnv is allocated. */
    virtual void init(MethodEnv*) = 0;

    /** Called after MethodInfo::resolveSignatures() completes */
    virtual void notifyMethodResolved(MethodInfo*, MethodSignaturep) = 0;

    /** Called after VTable::resolveSignatures() completes. */
    virtual void notifyVTableResolved(VTable*) = 0;

    /** Called after prepareActionPool completes. */
    virtual void notifyAbcPrepared(Toplevel*, AbcEnv*) = 0;

    /** Invoke a function apply-style, by unpacking arguments from an array */
    virtual Atom apply(MethodEnv*, Atom thisArg, ArrayObject* a) = 0;

    /** Invoke a function call-style, with thisArg passed explicitly */
    virtual Atom call(MethodEnv*, Atom thisArg, int32_t argc, Atom* argv) = 0;
};

enum Runmode { RM_mixed, RM_jit_all, RM_interp_all };

// Signature for method invocation when caller coerces arguments
// and boxes results.  Typically the caller is JIT code.
typedef uintptr_t (*GprMethodProc)(MethodEnv*, int32_t, uint32_t *);
typedef double (*FprMethodProc)(MethodEnv*, int32_t, uint32_t *);

// Signature for invocation when callee coerces & boxes;
// the caller is calling an unknown function with an unknown signature.
typedef Atom (*AtomMethodProc)(MethodEnv*, int, Atom*);

// Signature for invoking a method early bound via an interface
// type reference.  JIT code passes in the IID of the interface method
// to enable searching for the correct concrete method.
typedef uintptr_t GprImtThunkProcRetType;
typedef GprImtThunkProcRetType (*GprImtThunkProc)(class ImtThunkEnv*,
        int argc, uint32_t* args, uintptr_t idd);

/**
 * Size of a variable in a JIT stack frame, in bytes.  VARSIZE is large
 * enough to hold double, int, pointers, or Atom on 32-bit or 64-bit cpus.
 * This is an aspect of the JIT implementation, but is defined here because
 * the debugger boxing/unboxing code in MethodInfo needs to know it.
 */
static const size_t VARSIZE = 8;

/**
 * Compute number of bytes needed for the unboxed representation
 * of this argument value when passed on the stack.
 */
int32_t argSize(Traits*);

/**
 * BaseExecMgr implements for all policies, and encapsulates
 * jit+abc, abc-only, and wordcode-only mechanisms.  This could be improved
 * by factoring into multiple implementations.
 *
 * Extends GCFinalizedObject because instances contain GC object references
 * and have a destructor that needs to run.
 */
class BaseExecMgr: public MMgc::GCFinalizedObject
    , /* implements */ public ExecMgr
{
public:
    BaseExecMgr(AvmCore*);
    virtual ~BaseExecMgr();

    // ExecMgr methods:
    void init(MethodInfo*, const NativeMethodInfo*);
    void init(MethodEnv*);
    void notifyMethodResolved(MethodInfo*, MethodSignaturep);
    void notifyVTableResolved(VTable*);
    void notifyAbcPrepared(Toplevel*, AbcEnv*);
    Atom apply(MethodEnv*, Atom thisArg, ArrayObject* a);
    Atom call(MethodEnv*, Atom thisArg, int32_t argc, Atom* argv);

private:
    // Helpers to simply return the current implementation:
    static BaseExecMgr* exec(VTable*);
    static BaseExecMgr* exec(MethodEnv*);

    /** True if method's _isInterpImpl flag is set. */
    static bool isInterpreted(MethodEnv*);

    // Trampolines that verify on first call:
    static uintptr_t verifyEnterGPR(MethodEnv*, int32_t argc, uint32_t* args);
    static double verifyEnterFPR(MethodEnv*, int32_t argc, uint32_t* args);
    static Atom verifyInvoke(MethodEnv*, int32_t argc, Atom* args);
    static void verifyOnCall(MethodEnv*); // helper called by verify trampolines

    // Trampolines to call debugEnter/Exit around native methods:
    static uintptr_t debugEnterExitWrapper32(MethodEnv* env, int32_t argc, uint32_t* argv);
    static double debugEnterExitWrapperN(MethodEnv* env, int32_t argc, uint32_t* argv);

    // Trampoline to set MethodEnv->impl to MethodInfo->impl on first call.
    static uintptr_t delegateInvoke(MethodEnv* env, int32_t argc, uint32_t* ap);

    // Interpreter invocation when called by JIT code.  C++ and Interpreter
    // calls to the interpreter go through one of the invoke_interp variants.
    static uintptr_t interpGPR(MethodEnv* method, int argc, uint32_t *ap);
    static double interpFPR(MethodEnv* method, int argc, uint32_t *ap);

    /** General purpose interpreter invocation. */
    static Atom invokeInterp(MethodEnv* env, int32_t argc, Atom* argv);

    /**
     * Invoke the interpreter for a method that does not need to coerce
     * any arguments, either because there are none, or they're all type *.
     **/
    static Atom invokeInterpNoCoerce(MethodEnv* env, int32_t argc, Atom* argv);

    // Stubs used for invoking interpreted constructor methods; these
    // initialize default values of the new object before invoking the
    // interpreter.  See initObj() in exec.cpp.
    static uintptr_t initInterpGPR(MethodEnv*, int, uint32_t*);
    static double initInterpFPR(MethodEnv*, int, uint32_t*);
    static Atom initInvokeInterp(MethodEnv*, int, Atom*);
    static Atom initInvokeInterpNoCoerce(MethodEnv*, int, Atom*);

    /** Set an object's fields to default values. Called by init stubs. */
    static void initObj(MethodEnv* env, ScriptObject* obj);

    /**
     * Generic interpretive invoker for JIT and native methods that
     * iterates over argument types and coerces each one.
     */
    static Atom invokeGeneric(MethodEnv* env, int32_t argc, Atom* argv);

    /** Invoke a native or jit-compiled method and then box the return value. */
    static Atom endCoerce(MethodEnv*, int32_t argc, uint32_t *ap,
                          MethodSignaturep ms);

    /** Check argc and compute the space required for rest args. */
    static size_t startCoerce(MethodEnv*, int32_t argc, MethodSignaturep ms);

    /** Unbox and coerce arguments for ordinary invocation. */
    static void unboxCoerceArgs(MethodEnv*, int32_t argc, Atom* in,
                                uint32_t *ap, MethodSignaturep ms);

    /** Unbox and coerce arguments for invocation via Function.apply(). */
    static void unboxCoerceArgs(MethodEnv*, Atom thisArg, ArrayObject *a,
                                uint32_t *argv, MethodSignaturep ms);

    /** Unbox and coerce arguments for invocation via Function.call(). */
    static void unboxCoerceArgs(MethodEnv*, Atom thisArg, int32_t argc,
                                Atom* in, uint32_t *argv, MethodSignaturep ms);

    /** Coerce and unbox a single argument. */
    static Atom* FASTCALL coerceUnbox1(MethodEnv*, Atom atom, Traits* t, Atom* args);

    /** Just unbox a single argument that is known to be the correct type already. */
    static Atom* FASTCALL unbox1(MethodEnv*, Atom atom, Traits* t, Atom* args);

    /**
     * Set trampolines and flags for the interpreter, possibly including an
     * initializer trampoline.
     */
    void setInterp(MethodInfo*, MethodSignaturep);

    /** Set trampolines and flags for a native method. */
    void setNative(MethodInfo*, GprMethodProc p);

    /**
     * Verify any kind of method, by sniffing what kind it is and dispatching
     * to the appropriate case.  Called on or before the first invocation of the
     * target method.  Each subcase is responsible for setting up CodeWriters and
     * then ultimately running the verifier by calling verifyCommon().
     */
    void verifyMethod(MethodInfo*, Toplevel*, AbcEnv*);

    /** "Verify" a native method by installing trampolines and flags. */
    void verifyNative(MethodInfo*, MethodSignaturep);

    /** Verify a method and install interpreter trampolines. */
    void verifyInterp(MethodInfo*, MethodSignaturep, Toplevel*, AbcEnv*);

    /**
     * Actually run the verifier with the given CodeWriter chain, and
     * clean up if it throws a VerifyError.
     */
    void verifyCommon(MethodInfo*, MethodSignaturep, Toplevel*, AbcEnv*, CodeWriter*);

    //
    // Support for verifyall mode mainly consists of hooking into the
    // code loading mechanism and verifying early instead of on the first
    // call.  This includes installing trampolines and doing jit-compiltion,
    // if applicable.  verifyall mode supports a "verifyonly" sub-mode whereby
    // no code is actually executed.
    //
    // Verifying early is done in a semi breadth-first order by maintaining
    // two queues:  verifyFunctionQueue, containing MethodInfo's that are
    // resolved and ready to verify, and verifyTraitsQueue, containing types
    // that contain read-to-verify functions
    //
    // Traits are queued when their corresponding OP_newclass or OP_newactivation
    // is encountered while verifying another method.  Functions are added when
    // we encounter OP_newfunction, or when the declaring traits reaches the head
    // of the queue.
    //
    // Methods have their _isVerifyPending flag set when queued, then changed
    // to _isVerified once verified.
    //
    // In verifyall mode we never install the verify-on-first-call trampolines.
    // In verifyonly mode, all execution is stubbed out by a single stub that
    // just returns undefined.
    //

    friend class VerifyallWriter;
    void enqFunction(MethodInfo* f);
    void enqTraits(Traits* t);
    void verifyEarly(Toplevel* toplevel, AbcEnv* abc_env);
    bool isVerified(const MethodInfo*) const;
    bool isVerifyPending(const MethodInfo*) const;
    void setVerified(MethodInfo*) const;
    void setVerifyPending(MethodInfo*) const;

    //
    // Support for JIT Compilation:
    //

    /** Return true if we should eagerly JIT.  False means use interpreter. */
    bool shouldJit(const MethodInfo*, const MethodSignaturep) const;

    /** True if the JIT is enabled */
    bool isJitEnabled() const;

    /** Run the verifier with the JIT attached. */
    void verifyJit(MethodInfo*, MethodSignaturep, Toplevel*, AbcEnv*);

    /** Install JIT code pointers and set MethodInfo::_isJitImpl. */
    void setJit(MethodInfo*, GprMethodProc p);

    /**
     * Invoker called on the first invocation then calls invoke_generic,
     * installs jitInvokerNow yielding a 1-call delay before we try to
     * compile the invoker itself.
     */
    static Atom jitInvokerNext(MethodEnv*, int argc, Atom* args);

    /* Compile now then invoke the compiled invoker. */
    static Atom jitInvokerNow(MethodEnv*, int argc, Atom* args);

    // Support for interface method tables (IMTs).  These enable fast
    // dispatching of an interface method when invoked via an interface-
    // typed reference, when we know the method signature but not the
    // vtable index.  Only applies to call sites in JIT code.
    //
    // Each VTable contains a fixed sized array called the interface
    // method table, each entry points to a concrete MethodEnv, resolveImt(),
    // or dispatchImt().  Initially all entries point to resolveImt().
    //
    // Resolution: All interface methods that the concrete type implements
    // are hashed into the IMT by a unique interface method id (IID).  If an IMT slot
    // has no collisions, then the concrete MethodEnv* for the method implementing
    // that interface method is installed.  Otherwise we install dispatchImt().
    //
    // Dispatching: JIT'd call sites pass the IID of the method they early bound
    // to.  If the called slot contains just a concrete MethodEnv, the IID parameter
    // is ignored.  Otherwise we search a table for the correct concrete
    // method and then invoke it.
    //
    // IIDs are simply the pointer to the interface method's MethodInfo.
    // The IMT itself is declared in class ImtHolder, below.  It is private
    // to the execution mechanism but must be allocated in each VTable instance.
    //

    /**
     * Analyze the implemented types then build the ImtEntry table and
     * install dispatchImt() or a concrete MethodEnv*.
     */
    static class ImtThunkEnv* resolveImtSlot(class ImtThunkEnv*, uintptr_t iid);

    // Helpers for resolveImtSlot():
    void resolveImtSlotFromBase(VTable*, uint32_t slot);
    bool resolveImtSlotSelf(VTable*, uint32_t slot);
    void resolveImtSlotFull(VTable*, uint32_t slot);
    static class ImtEntry* buildImtEntries(VTable* vtable, uint32_t slot, uint32_t& count);

    /** Trampoline to resolve this IMT slot then invoke the proper handler. */
    static GprImtThunkProcRetType resolveImt(class ImtThunkEnv* ite,
                                  int argc, uint32_t* ap, uintptr_t iid);

    /** Trampoline which searches for the method with a matching IID. */
    static GprImtThunkProcRetType dispatchImt(class ImtThunkEnv* ite,
                                  int argc, uint32_t* ap, uintptr_t iid);

private:
    AvmCore* core;
    const struct Config& config;
#ifdef VMCFG_VERIFYALL
    GCList<MethodInfo*> verifyFunctionQueue;
    GCList<Traits*> verifyTraitsQueue;
#endif
};

/**
 * CodeWriter instance to hook into opcodes OP_newfunction, OP_newclass, and
 * OP_newactivation so we can populate verifyFunctionQueue and
 * verifyTraitsQueue in verifyall mode.
 */
class VerifyallWriter : public NullWriter
{
    PoolObject* pool;
    BaseExecMgr* exec;
public:
    VerifyallWriter(MethodInfo*, BaseExecMgr*, CodeWriter*);
    void write(const FrameState*, const uint8_t *pc, AbcOpcode, Traits*);
    void writeOp1(const FrameState*, const uint8_t *pc, AbcOpcode, uint32_t opd1, Traits*);
};

/**
 * Base class for MethodInfo which contains invocation pointers.  These
 * pointers are private to the ExecMgr instance and hence declared here.
 */
class MethodInfoProcHolder : public MMgc::GCObject
{
    friend class ImtThunkEnv;
    friend class InvokerCompiler;
    friend class BaseExecMgr;
    friend class MethodEnv;

protected:
    MethodInfoProcHolder();

private:
    union {
        GprMethodProc _implGPR;
        FprMethodProc _implFPR;
    };
    /** pointer to invoker used when callee must coerce args. */
    AtomMethodProc _invoker;
};

/**
 * Base class for MethodEnv and ImtThunkEnv, containing copies of the
 * trampoline from MethodInfo.  In JIT configurations this saves one
 * load along the call fast path.  Calls from C++ or the Interpreter
 * always go through MethodInfo._invoker.
 */
class MethodEnvProcHolder : public MMgc::GCObject
{
    friend class CodegenLIR;
    friend class BaseExecMgr;

protected:
    MethodEnvProcHolder();
#ifdef VMCFG_METHODENV_IMPL32
private:
    union {
        GprMethodProc   _implGPR;
        FprMethodProc   _implFPR;
        GprImtThunkProc _implImtGPR;
    };
#endif

#ifdef VMCFG_AOT
public:
  inline GprMethodProc implGPR() const { return _implGPR; }
  inline FprMethodProc implFPR() const { return _implFPR; }
#endif
  
};

/**
 * Holder for interface method dispatch table within class VTable,
 * declared here because it is private to the ExecMgr implementation.
 */
class ImtHolder
{
    friend class BaseExecMgr;
    friend class CodegenLIR;

    // IMT_SIZE should be a number that is relatively prime to sizeof(MethodInfo)/8
    // since we use the MethodInfo pointer as the interface method id (IID).
    // smaller = dense table, few large conflict tables
    // larger  = sparse table, many small conflict tables

    #ifdef _DEBUG
    static const uint32_t IMT_SIZE = 3; // Good for testing all code paths.
    #else
    static const uint32_t IMT_SIZE = 7; // Marginally better for speed/size tradeoff.
    #endif

    static uintptr_t getIID(MethodInfo*);    // Return a full IID for the given interface method.
    static uint32_t hashIID(uintptr_t iid);  // Hash the IID into an IMT slot number.
    static uint32_t hashIID(MethodInfo*);    // Hash the method's IID into an IMT slot number.
    class ImtThunkEnv* entries[IMT_SIZE];
};

#if defined(_MSC_VER) && defined(AVMPLUS_IA32)
// These macros are used for dynamically aligning our
// stack before calling into our JITed code.  By aligning our
// stack to an 8 byte boundary before calling into our JITed
// code, we will keep all double access aligned and improve performance.
#define STACKADJUST() \
    __asm \
    { \
        __asm push ecx \
        __asm mov ecx, esp \
        __asm and ecx, 0x4 \
        __asm sub esp, ecx \
        __asm push ecx \
    }

#define STACKRESTORE() \
    __asm \
    { \
        __asm pop ecx \
        __asm add esp, ecx \
        __asm pop ecx \
    }
#else
#define STACKADJUST()
#define STACKRESTORE()
#endif

}
#endif // __avmplus_exec__
