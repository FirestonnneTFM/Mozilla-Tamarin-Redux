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
 *   leon.sha@sun.com
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
#include "Interpreter.h"

#ifdef VMCFG_NANOJIT
#include "CodegenLIR.h"

namespace avmplus {

#ifdef VMCFG_COMPILEPOLICY
BaseExecMgr::JitInterpRuleSet::JitInterpRuleSet(MMgc::GC* gc)
    : jit(gc,0)
    , interp(gc,0)
{
}

BaseExecMgr::JitInterpRuleSet::~JitInterpRuleSet()
{
    while(!jit.isEmpty())
        mmfx_delete( jit.removeLast() );

    while(!interp.isEmpty())
        mmfx_delete( interp.removeLast() );
}

bool BaseExecMgr::prepPolicyRules()
{
    bool allgood = true;
    if (config.compilePolicyRules)
    {
        AvmAssert(_ruleSet == NULL);
        _ruleSet = new (core->gc) JitInterpRuleSet(core->gc);
        const char* s = config.compilePolicyRules;
        while(*s)
        {
            s = (*s == '\"' || *s == ',') ? s+1 : s;
            if (!*s)
                break;

            MethodRecognizer* r = NULL;
            if (!VMPI_strncmp(s, "jit=", 4))
            {
                s += 4;
                r = MethodRecognizer::parse(&s, ',');
                if (r != NULL) _ruleSet->jit.add( r );
                #ifdef AVMPLUS_VERBOSE
                    if (core->isVerbose(VB_execpolicy))
                        core->console << "execpolicy override - jit " << r << "\n";
                #endif
            }
            else if (!VMPI_strncmp(s, "interp=", 7))
            {
                s += 7;
                r = MethodRecognizer::parse(&s, ',');
                if (r != NULL) _ruleSet->interp.add( r );
                #ifdef AVMPLUS_VERBOSE
                    if (core->isVerbose(VB_execpolicy))
                        core->console << "execpolicy override - interp " << r << "\n";
                #endif
            }
            else
            {
                // bad option
                #ifdef AVMPLUS_VERBOSE
                core->console << "execpolicy ignoring invalid rule " << s << "\n";
                #endif
                allgood = false;
            }
            if (*s) s++;
        }
    }
    return allgood;
}

// Attempt to match rules based on MethodInfo and the # of the currently processed method
// Process rules until a match, this means that conflicting rules are resolved by first match wins.
bool BaseExecMgr::ruleMatch(PolicyRuleSet* rules, const MethodInfo* m) const
{
    bool match = false;
    for(uint32_t i=0,n=rules->length(); !match && i<n; i++)
    {
        MethodRecognizer* r = rules->get(i);
        match = r->matches(m);
    }
    return match;
}
#endif /* VMCFG_COMPILEPOLICY */

bool BaseExecMgr::isJitEnabled() const
{
    Runmode runmode = config.runmode;
    return runmode == RM_mixed || runmode == RM_jit_all;
}

/**
 * Run JIT Eagerly if forcing compilation of all methods, or if the method
 * is not a static initializer and we have not detected a fast-fail condition
 * prior to invocation.  See bug 601794.
 */
bool BaseExecMgr::shouldJitFirst(const AbcEnv* abc_env, const MethodInfo* m, MethodSignaturep ms) const
{
    (void)abc_env; // squash compiler warning

    Runmode runmode = config.runmode;
    bool jitWouldFail = CodegenLIR::jitWillFail(ms);
    bool willJit = false;

    if (runmode == RM_jit_all)
    {
        willJit = true;
    }
    else if (runmode == RM_interp_all)
    {
        willJit = false;
    }
    else
    {
        AvmAssert( runmode == RM_mixed );

        // Some large methods with large frame sizes may cause the JIT to blow up.
        // These cases would result in JIT failure during the assembly phase anyhow,
        // so we will preemptively avoid compiling them.  See bug 601794.
        if (jitWouldFail)
        {
            willJit = false;
        }
        #ifdef VMCFG_OSR
        else if (OSR::isSupported(abc_env, m, ms))
        {
            willJit = false;
        }
        #endif
        else
        {
            willJit = !m->isStaticInit();
        }
    }

    #ifdef VMCFG_COMPILEPOLICY
    // allow our policy rules to override the default policy
    if (_ruleSet)
    {
        // if we're planning to jit, make sure we don't match a jit rule (i.e user specifically
        // wants to jit the method) before searching the interp matches.
        // Similarly if we're planning to interp, search jit rules provided no interp rule matches
        if (willJit)
        {
            if ( !ruleMatch(&_ruleSet->jit, m) )
                willJit = ruleMatch(&_ruleSet->interp, m) ? false : true;
        }
        else
        {
            if ( !ruleMatch(&_ruleSet->interp, m) )
                willJit = ruleMatch(&_ruleSet->jit, m) ? true : false;
        }

    }
    #endif /* VMCFG_COMPILEPOLICY */
    return willJit;
}

void BaseExecMgr::setJit(MethodInfo* m, GprMethodProc p)
{
    // Mark method as been JIT compiled.
    m->_isInterpImpl = 0;
    m->_isJitImpl = 1;
    m->_apply_fastpath = 1;
    m->_implGPR = p;
    m->_invoker = InvokerCompiler::canCompileInvoker(m)
        ? jitInvokerNext
        : invokeGeneric;
#ifdef AVMPLUS_VERBOSE
    if (m->pool()->isVerbose(VB_execpolicy))
        core->console << "execpolicy jit (" << m->unique_method_id() << ") " << m << "\n";
#endif
}

Atom BaseExecMgr::jitInvokerNext(MethodEnv* env, int argc, Atom* args)
{
    // Install stub to compile on next call.
    env->method->_invoker = jitInvokerNow;
    return invokeGeneric(env, argc, args);
}

// First call after compiling method; compile a custom invoker and run it.
Atom BaseExecMgr::jitInvokerNow(MethodEnv* env, int argc, Atom* args)
{
    AtomMethodProc invoker = InvokerCompiler::compile(env->method);
    if (!invoker) {
#ifdef AVMPLUS_VERBOSE
        if (env->method->pool()->isVerbose(VB_execpolicy))
            env->core()->console << "execpolicy generic-invoker " << env->method
                                 << " invoker-jit-failed\n";
#endif
        invoker = invokeGeneric; // Fail: install generic invoker.
    } else {
#ifdef AVMPLUS_VERBOSE
        if (env->method->pool()->isVerbose(VB_execpolicy))
            env->core()->console << "execpolicy jit-invoker " << env->method << "\n";
#endif
    }
    env->method->_invoker = invoker;
    STACKADJUST(); // align stack for 32-bit Windows and MSVC compiler
    Atom ret = invoker(env, argc, args);
    STACKRESTORE();
    return ret;
}

void BaseExecMgr::verifyJit(MethodInfo* m, MethodSignaturep ms,
        Toplevel *toplevel, AbcEnv* abc_env, OSR *osr)
{
    CodegenLIR jit(m, ms, toplevel, osr);
    PERFM_NTPROF_BEGIN("verify & IR gen");
    verifyCommon(m, ms, toplevel, abc_env, &jit);
    PERFM_NTPROF_END("verify & IR gen");
    GprMethodProc code = jit.emitMD();
    if (code) {
        setJit(m, code);
    } else if (config.jitordie) {
        jit.~CodegenLIR(); // Explicit cleanup since destructor won't run otherwise.
        Exception* e = new (core->GetGC())
                Exception(core, core->newStringLatin1("JIT failed")->atom());
        e->flags |= Exception::EXIT_EXCEPTION;
#ifdef AVMPLUS_VERBOSE
        if (m->pool()->isVerbose(VB_execpolicy))
            core->console << "execpolicy die " << m << " method-jit-failed\n";
#endif
        core->throwException(e);
    } else {
        // Mark it as interpreted and limp along.
#ifdef AVMPLUS_VERBOSE
        if (m->pool()->isVerbose(VB_execpolicy))
            core->console << "execpolicy interp " << m << " method-jit-failed\n";
#endif
        setInterp(m, ms, false);
        // Blacklist method so we don't attempt to compile it again.
        m->setHasFailedJit();
    }
}

uintptr_t BaseExecMgr::initInterpGPR(MethodEnv* env, int argc, uint32_t* ap)
{
    initObj(env, (ScriptObject*) atomPtr(((uintptr_t*)ap)[0]));
    return interpGPR(env, argc, ap);
}

double BaseExecMgr::initInterpFPR(MethodEnv* env, int argc, uint32_t* ap)
{
    initObj(env, (ScriptObject*) atomPtr(((uintptr_t*)ap)[0]));
    return interpFPR(env, argc, ap);
}

// Transition from JIT code to the interpreter.
uintptr_t BaseExecMgr::interpGPR(MethodEnv* env, int argc, uint32_t *ap)
{
    AvmAssert(exec(env)->isJitEnabled());
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
    AvmAssert(exec(env)->isJitEnabled());
    Atom* const atomv = (Atom*)ap;
    MethodSignaturep ms = env->method->getMethodSignature();
    ms->boxArgs(env->core(), argc, (uint32_t *)ap, atomv);
    Atom a = interpBoxed(env, argc, atomv);
    return AvmCore::number_d(a);
}

void BaseExecMgr::setNative(MethodInfo* m, GprMethodProc p)
{
    m->_implGPR = p;
    if (isJitEnabled() && InvokerCompiler::canCompileInvoker(m))
        m->_invoker = jitInvokerNext;
    else
        m->_invoker = invokeGeneric;
#ifdef AVMPLUS_VERBOSE
    if (m->pool()->isVerbose(VB_execpolicy))
        core->console<< "execpolicy native " << m << "\n";
#endif

}

//
// Interface Method Dispatching
//
// Below is code to implement interface method dispatching;  this includes
// setting up IMT tables, plus the dispatchers.
//

// Get the disp_id for an ImtEntry binding.  We don't call
// AvmCore::bindingToMethodId() because it will assert inapproppriately.
REALLY_INLINE uint32_t getRawDispID(Binding b)
{
    return uint32_t(uintptr_t(b))>>3;
}

// An ImtThunkEntry node represents a concrete method in an IMT.  dispatchImt()
// uses these to search for and then invoke an early bound interface method call.
struct ImtThunkEntry
{
    uintptr_t iid;
    uintptr_t disp_id; // only needs to be uint32_t, is this size for alignment purposes
};

static void sortImtThunkEntries(ImtThunkEntry* map, uint32_t count)
{
    // Intervals suggested by http://www.research.att.com/~njas/sequences/A108870.
    // We'll never get anywhere near the upper limits but it's probably cheaper than extending algorithmically.
    static const uint32_t k_shellsort_intervals[] = { 1, 4, 9, 20, 46, 103, 233, 525, 1182, 2660, 5985, 13467, 30301,
                                        68178, 153401, 345152, 776591, 1747331, 3931496, 8845866, 19903198,
                                        44782196, 100759940, 226709866, 510097200, 1147718700 };

    // Simple ShellSort -- the list rarely gets larger than 100 or so, so this is efficient and compact.
    if (count <= 1)
        return;

    ImtThunkEntry* beg = map;
    ImtThunkEntry* end = map + count;   // One past end!

    int32_t interval_idx = 0;
    while (count > k_shellsort_intervals[interval_idx+1])
        ++interval_idx;

    while (interval_idx >= 0) {
        const int32_t interval = k_shellsort_intervals[interval_idx--];
        for (ImtThunkEntry* i = beg + interval; i < end; i++) {
            ImtThunkEntry temp = *i;
            ImtThunkEntry* j = i;
            ImtThunkEntry* nj = j - interval;
            while ((nj >= beg) && nj->iid > temp.iid) {
                AvmAssert(j >= beg && j < end);
                AvmAssert(nj >= beg && nj < end);
                *j = *nj;
                j = nj;
                nj = j - interval;
            }
            AvmAssert(j >= beg && j < end);
            *j = temp;
        }
    }
}

// An IMT slot representing more than one colliding method will contain
// one of these.  The code pointer will point to dispatchImt(), and the
// table of collding ImtEntries is allocated just past the end of the object.
// see ImtThunkEnv::entries() to see how it is accessed.
//
// We have manually written tracers here because the class is defined in
// a cpp file; generated tracers require the class to be visible because
// the tracer will be in a different file.

class ImtThunkEnv : public MethodEnvProcHolder
{
private:
    ImtThunkEnv(VTable*);
    ImtThunkEnv(uint32_t imtMapCount);
public:
    virtual bool gcTrace(MMgc::GC* gc, size_t cursor);

    static ImtThunkEnv* create(MMgc::GC* gc, VTable* v);
    static ImtThunkEnv* create(MMgc::GC* gc, uint32_t imtMapCount);

    struct ImtThunkEntry* entries() const;

// ------------------------ DATA SECTION BEGIN
public:
    union {
        VTable*   vtable;
        uint32_t  imtMapCount;
    };
// ------------------------ DATA SECTION END
};

REALLY_INLINE ImtThunkEnv* ImtThunkEnv::create(MMgc::GC* gc, VTable* v)
{
    return new (gc, MMgc::kExact) ImtThunkEnv(v);
}

REALLY_INLINE ImtThunkEnv* ImtThunkEnv::create(MMgc::GC* gc, uint32_t imtMapCount)
{
    return new (gc, MMgc::kExact, imtMapCount * sizeof(ImtThunkEntry)) ImtThunkEnv(imtMapCount);
}

REALLY_INLINE ImtThunkEnv::ImtThunkEnv(VTable* v)
    : vtable(v)
{}

REALLY_INLINE ImtThunkEnv::ImtThunkEnv(uint32_t c)
    : imtMapCount(c)
{}

REALLY_INLINE struct ImtThunkEntry* ImtThunkEnv::entries() const
{
    return (struct ImtThunkEntry*)(this+1);
}

bool ImtThunkEnv::gcTrace(MMgc::GC* gc, size_t cursor) {
    (void)cursor;
    gc->TraceConservativeLocation((uintptr_t*)&vtable);
    return false;
}

// Build the initial IMT for this vtable, if JIT is enabled.
void BaseExecMgr::notifyVTableResolved(VTable* vtable)
{
    if (isJitEnabled()) {
        GC* gc = core->gc;
        // fixme: do we need one of these per unique vtable?
        ImtThunkEnv* ite = ImtThunkEnv::create(gc, vtable);
        ite->_implGPR = (GprMethodProc) resolveImt;
        for (uint32_t i=0; i < ImtHolder::IMT_SIZE; i++) {
            // they all share the same ImtThunkEnv for now
            // (lazily replaced in resolveImt by an inherited or new one)
            WB(gc, vtable, &vtable->imt.entries[i], ite);
        }
    }
}

// An ImtEntry is a single node used during IMT resoltion; these are allocated
// when setting up the table, then freed explicitly.  We use GC allocation for
// these to guard against the possibility of an exception being thrown during
// the exceution of resolveImt().
class ImtEntry: public MMgc::GCObject
{
public:
    inline ImtEntry(ImtEntry* n, uintptr_t iid, uint32_t d) : next(n), iid(iid), disp_id(d) { }
    ImtEntry* const next;
    uintptr_t const iid;
    uintptr_t const disp_id;
};

ImtEntry* BaseExecMgr::buildImtEntries(VTable* vtable, uint32_t slot, uint32_t& count)
{
    count = 0;

    Traitsp traits = vtable->traits;
    AvmAssert(!traits->isInterface());

    // First check to see if we added any interfaces.  If not, we can just inherit.
    // do this first, since it's pretty common and allows us to skip lots of hashtable lookups
    // and memory allocations.
    if (!traits->implementsNewInterfaces())
        return NULL;

    ImtEntry* map = NULL;
    MMgc::GC* gc = vtable->traits->core->GetGC();
    TraitsBindingsp tb = traits->getTraitsBindings();
    for (InterfaceIterator ifc_iter(traits); ifc_iter.hasNext();) {
        Traits* ifc = ifc_iter.next();

        TraitsBindingsp ifcd = ifc->getTraitsBindings();
        StTraitsBindingsIterator iter(ifcd);
        while (iter.next()) {
            const Stringp name = iter.key();
            if (name == NULL)
                continue;

            const Namespacep ns = iter.ns();
            const Binding iBinding = iter.value();

            // taking some liberties here in the name of compact code...
            // the opaque AvmCore accessors aren't flexible enough here,
            // rely on knowledge of current Binding structure
            const uint32_t iDispID = getRawDispID(iBinding);
            const BindingKind ibk = AvmCore::bindingKind(iBinding);
            Binding cBinding = BIND_NONE;

            MethodInfo* v0 = ((1<<ibk) & ((1<<BKIND_METHOD)|(1<<BKIND_GET)|(1<<BKIND_GETSET))) ?
                                ifcd->getMethod(iDispID) :
                                NULL;

            if (v0 && ImtHolder::hashIID(v0) == slot) {
                if (cBinding == BIND_NONE)
                    cBinding = tb->findBinding(name, ns);
                AvmAssert(cBinding != BIND_NONE);
                map = new (gc) ImtEntry(map, ImtHolder::getIID(v0), getRawDispID(cBinding));
                ++count;
            }

            MethodInfo* v1 = ((1<<ibk) & ((1<<BKIND_SET)|(1<<BKIND_GETSET))) ?
                                ifcd->getMethod(iDispID+1) :
                                NULL;
            if (v1 && ImtHolder::hashIID(v1) == slot) {
                if (cBinding == BIND_NONE)
                    cBinding = tb->findBinding(name, ns);
                AvmAssert(cBinding != BIND_NONE);
                map = new (gc) ImtEntry(map, ImtHolder::getIID(v1), getRawDispID(cBinding)+1);
                ++count;
            }
        } // while iter.next()
    } // for ... ifc_iter.hasNext()

    AvmAssert(map != NULL);
    return map;
}

// Search for the concrete method to invoke for the requested IID.
// FIXME: bug 563007
//   Research suggests that linear searches are best for up to 4 entries, binary
// search best for 4...10, and lookup-table best for larger sizes. Lookup tables
// are impractical here, since our iid values aren't consecutive but rather
// arbitrary integers, so we just use linear-and-binary. Furthermore, profiling
// suggested that separate linear search wasn't a measurable gain, so we
// always do a binary search, in the name of simplicity.
// http://www.sagecertification.org/events/javavm02/full_papers/zendra/zendra_html/index.html
//   Some counter-research suggests a much higher threshold
// where binary search is faster:
// http://schani.wordpress.com/2010/04/30/linear-vs-binary-search/
REALLY_INLINE MethodEnv* findMethod(ImtThunkEnv* ite, uintptr_t iid, ScriptObject* obj)
{
    AvmAssert(ite->imtMapCount > 1);
    const ImtThunkEntry* const m = ite->entries();
    uint32_t lo = 0;
    uint32_t hi = ite->imtMapCount;
    while (lo < hi) {
        uint32_t const mid = (lo + hi) >> 1;
        if (m[mid].iid < iid)
            lo = mid + 1;
        else
            hi = mid;
    }
    AvmAssert((lo < ite->imtMapCount) && (m[lo].iid == iid));
    uintptr_t disp_id = m[lo].disp_id;
    return obj->vtable->methods[disp_id];
}

// called the first time a method is called via an interface type.
// The job of this stub is to replace the imt[] slot with a pointer
// to a concrete stub.  There are two cases:
// a) only one concrete method was hashed to this slot.  The concrete
//    MethodEnv* pointer is placed in the slot, and further calls are
//    done with no overhead.
// b) more than one method hashed to this slot.  imt[] is updated to
//    point to ::dispatchImt(), which uses the incoming iid parameter
//    to choose which concrete MethodEnv to call.
/*static*/ GprImtThunkProcRetType BaseExecMgr::resolveImt(ImtThunkEnv* ite, int argc, uint32_t* ap, uintptr_t iid)
{
    ite = BaseExecMgr::resolveImtSlot(ite, iid);
    return (*ite->_implImtGPR)(ite, argc, ap, iid);
}

// called when a method is called through an interface type.  iid
// indicates which interface method is being called.  This method
// is installed when more than one concrete method have hashed to the
// same imt[] slot; this method picks the one matching iid and calls it.
/*static*/ GprImtThunkProcRetType BaseExecMgr::dispatchImt(ImtThunkEnv* ite, int argc, uint32_t* ap, uintptr_t iid)
{
    MethodEnv* const env = findMethod(ite, iid, *(ScriptObject**)ap);
    STACKADJUST(); // align stack for 32-bit Windows and MSVC compiler
    GprImtThunkProcRetType r = (*env->_implGPR)(env, argc, ap);
    STACKRESTORE();
    return r;
}

ImtThunkEnv* BaseExecMgr::resolveImtSlot(ImtThunkEnv* ite, uintptr_t iid)
{
    uint32_t slot = ImtHolder::hashIID(iid);
    VTable* vtable = ite->vtable;
    BaseExecMgr* exec = BaseExecMgr::exec(vtable);
    if (!exec->resolveImtSlotSelf(vtable, slot))
        exec->resolveImtSlotFull(vtable, slot);
    return vtable->imt.entries[slot]; // get the fresh, new one
}

// Copy the imt thunk from the base vtable - callers must make sure
// that the stub can be copied from the base class - i.e. resolveImtSlotFromBase
// or resolveImtSlotSelf must have already been called successfully on the base vtable.
void BaseExecMgr::resolveImtSlotFromBase(VTable* vtable, uint32_t slot)
{
    AvmCore* core = vtable->traits->core;
    MMgc::GC* gc = core->GetGC();
    VTable* base = vtable->base;

    // Copy down imt stub from base class.
    ImtThunkEnv* ite = base->imt.entries[slot];
    AvmAssert(ite != NULL);

    // If base->imt[i] is really an IMT thunk, use it.
    // BUT, it might be a plain MethodEnv* from a single-entry case, in which case
    // we want to use our own MethodEnv at the same disp-id. Alas, we don't have the disp-id
    // handy at this point, since we didn't build the ImtEntry chain. Rather than build it in
    // all cases, let's compare vs our parent's method list; linear search, but I'm guessing that's
    // still a net win vs. doing the ImtEntry chain building. (Our base's TB is most likely still
    // in the cache since we used it inside buildImtEntries.)
    TraitsBindingsp tb = base->traits->getTraitsBindings();
    for (uint32_t j = 0; j < tb->methodCount; ++j) {
        if (ite == (ImtThunkEnv*)base->methods[j]) {
            ite = (ImtThunkEnv*)vtable->methods[j];
            break;
        }
    }
    WB(gc, vtable, &vtable->imt.entries[slot], ite);
}

// Returns false if we need to copy the imt stub from base,
// otherwise returns true.
bool BaseExecMgr::resolveImtSlotSelf(VTable* vtable, uint32_t slot)
{
    AvmAssert(vtable->linked);
    AvmAssert(vtable->base != NULL); // Only Object and activation objects have null base, and neither has interfaces
    AvmAssert(!vtable->traits->isInterface());
    AvmAssert(exec(vtable)->isJitEnabled());

    ImtThunkEnv* ite;
    uint32_t imtMapCount = 0;

    ImtEntry* imtMap = buildImtEntries(vtable, slot, imtMapCount);
    if (!imtMap) {
        return false;
    } else {
        MMgc::GC* gc = core->GetGC();

        AvmAssert(imtMapCount > 0);
        if (imtMapCount == 1) {
            ite = (ImtThunkEnv*) vtable->methods[imtMap->disp_id];
            gc->Free(imtMap);
        } else {
            ite = ImtThunkEnv::create(gc, imtMapCount);
            ite->_implGPR = (GprMethodProc) dispatchImt;
            ImtThunkEntry* m = ite->entries();
            ImtEntry* e = imtMap;
            while (e) {
                m->iid = e->iid;
                m->disp_id = e->disp_id;
                ++m;
                ImtEntry* t = e;
                e = e->next;
                gc->Free(t);
            }
            sortImtThunkEntries(ite->entries(), ite->imtMapCount);
        }
        WB(gc, vtable, &vtable->imt.entries[slot], ite);
    }
    return true;
}

void BaseExecMgr::resolveImtSlotFull(VTable* vtable, uint32_t slot)
{
    MMgc::GC* gc = core->GetGC();
    GCList<VTable> work_stack(gc, kListInitialCapacity);

    work_stack.add(vtable);

    // Walk up the base VTables until we find one where the slot
    // can be resolved without copying it from its base.
    VTable* cur = vtable->base;
    while (cur->imt.entries[slot]->_implImtGPR == resolveImt &&
            !resolveImtSlotSelf(cur, slot)) {
        work_stack.add(cur);
        cur = cur->base;
    }

    // Work backwards through the base types, copying
    // the imt stub down as we go.
    uint32_t size = work_stack.length();
    for (uint32_t i = 0; i < size; ++i) {
        cur = work_stack[size-i-1];
        resolveImtSlotFromBase(cur, slot);
    }
}

} // namespace avmplus
#endif // VMCFG_NANOJIT
