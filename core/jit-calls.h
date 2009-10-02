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
 * Portions created by the Initial Developer are Copyright (C) 2008
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

#define ARGMASK(a,n) (nanojit::ARGSIZE_##a << (ARGSIZE_SHIFT*(n)))
#define SIG0(r) ARGMASK(r,0)
#define SIG1(r,a1) (SIG0(r) | ARGMASK(a1,1))
#define SIG2(r,a2,a1) (SIG1(r,a1) | ARGMASK(a2,2))
#define SIG3(r,a3,a2,a1) (SIG2(r,a2,a1) | ARGMASK(a3,3))
#define SIG4(r,a4,a3,a2,a1) (SIG3(r,a3,a2,a1) | ARGMASK(a4,4))
#define SIG5(r,a5,a4,a3,a2,a1) (SIG4(r,a4,a3,a2,a1) | ARGMASK(a5,5))
#define SIG6(r,a6,a5,a4,a3,a2,a1) (SIG5(r,a5,a4,a3,a2,a1) | ARGMASK(a6,6))
#define SIG7(r,a7,a6,a5,a4,a3,a2,a1) (SIG6(r,a6,a5,a4,a3,a2,a1) | ARGMASK(a7,7))
#define SIG8(r,a8,a7,a6,a5,a4,a3,a2,a1) (SIG7(r,a7,a6,a5,a4,a3,a2,a1) | ARGMASK(a8,8))

#define ARGSIZE_A ARGSIZE_P

#define FUNCTIONID(n) &ci_##n

#ifdef NJ_VERBOSE
    #define DEFINE_CALLINFO(f,sig,cse,fold,abi,name) \
        static const CallInfo ci_##name = { f, sig, cse, fold, abi, #name };
#else
    #define DEFINE_CALLINFO(f,sig,cse,fold,abi,name) \
        static const CallInfo ci_##name = { f, sig, cse, fold, abi };
#endif

#if _MSC_VER
    #define ABI_FUNCTION ABI_CDECL
    #define ABI_FAST     ABI_FASTCALL
    #define ABI_METHOD   ABI_THISCALL
#else
    // gcc, probably
    #define ABI_FUNCTION ABI_CDECL
    #define ABI_FAST     ABI_FASTCALL
    #define ABI_METHOD   ABI_CDECL
#endif

#define FUNCTION(f, sig, name) \
    DEFINE_CALLINFO(f,sig,0,0,ABI_FUNCTION,name)
#define FASTFUNCTION(f, sig, name) \
    DEFINE_CALLINFO(f,sig,0,0,ABI_FAST,name)
#define CSEFUNCTION(f, sig, name) \
    DEFINE_CALLINFO(f,sig,1,0,ABI_FUNCTION,name)

#define METHOD(f, sig, name) \
    DEFINE_CALLINFO(f,sig,0,0,ABI_METHOD,name)
#define CSEMETHOD(f, sig, name) \
    DEFINE_CALLINFO(f,sig,1,0,ABI_METHOD,name)

    FUNCTION(CALL_INDIRECT, SIG4(U,P,P,I,P), icalli)
    FUNCTION(CALL_INDIRECT, SIG4(A,P,P,I,P), acalli)
    FUNCTION(CALL_INDIRECT, SIG4(F,P,P,I,P), fcalli)
    FUNCTION(CALL_INDIRECT, SIG5(I,P,P,I,P,P), icallimt)
    FUNCTION(CALL_INDIRECT, SIG5(A,P,P,I,P,P), acallimt)
    FUNCTION(CALL_INDIRECT, SIG5(F,P,P,I,P,P), fcallimt)

    METHOD(ENVADDR(MethodEnv::newActivation), SIG1(P,P), newActivation)
    METHOD(ENVADDR(MethodEnv::newcatch), SIG2(P,P,P), newcatch)
    METHOD(ENVADDR(MethodEnv::newfunction), SIG4(P,P,P,P,P), newfunction)

    Atom callprop_miss(BindingCache&, Atom obj, int argc, Atom* args, MethodEnv*);

    #ifdef DOPROF
    # define PROF_IF(label, expr) bool hit = (expr); _nvprof(label, hit); if (hit)
    #else
    # define PROF_IF(label, expr) if (expr)
    #endif

    // if the cached obj was a ScriptObject, we have a hit when
    // the new object's tag is kObjectType and the cached vtable matches exactly
    #define OBJ_HIT(obj, c)  (atomKind(obj) == kObjectType && atomObj(obj)->vtable == (c).vtable)

    // if the cached obj was a primitive, we only need a matching atom tag for a hit
    #define PRIM_HIT(val, c) (atomKind(val) == c.tag)

    REALLY_INLINE Atom invoke_cached_method(BindingCache& c, Atom obj, int argc, Atom* args) {
        // force arg0 = obj; if caller used OP_callproplex then receiver was null.
        args[0] = obj;
        return c.method->coerceEnter(argc, args);
    }

    template <class T>
    REALLY_INLINE T load_cached_slot(BindingCache& c, Atom obj) {
        return *((T*) (uintptr_t(atomObj(obj)) + c.slot_offset));
    }

    // calling a declared method on a ScriptObject
    Atom callprop_obj_method(BindingCache& c, Atom obj, int argc, Atom* args, MethodEnv* env)
    {
        PROF_IF ("callprop_obj_method hit", OBJ_HIT(obj,c))
            return invoke_cached_method(c, obj, argc, args);
        return callprop_miss(c, obj, argc, args, env);
    }

    // calling a function in a declared slot, specialized for slot type
    template <class T>
    Atom callprop_obj_slot(BindingCache& c, Atom obj, int argc, Atom* args, MethodEnv* env)
    {
        PROF_IF ("callprop_obj_slot hit", OBJ_HIT(obj,c))
            return op_call(env, load_cached_slot<T>(c, obj), argc, args);
        return callprop_miss(c, obj, argc, args, env);
    }

    // calling an unknown binding on an object, i.e. a dynamic property
    Atom callprop_obj_none(BindingCache& c, Atom obj, int argc, Atom* args, MethodEnv* env)
    {
        PROF_IF ("callprop_obj_none hit", OBJ_HIT(obj,c)) {
            // cache hit: access dynamic properties and proto-chain directly
            return call_obj_dynamic(obj, c.name, argc, args);
        }
        return callprop_miss(c, obj, argc, args, env);
    }

    // calling a declared method on a primitive value
    Atom callprop_prim_method(BindingCache& c, Atom prim, int argc, Atom* args, MethodEnv* env)
    {
        PROF_IF ("callprop_prim_method hit", PRIM_HIT(prim, c))
            return invoke_cached_method(c, prim, argc, args);
        return callprop_miss(c, prim, argc, args, env);
    }

    // calling a dynamic property on a primitive's prototype
    Atom callprop_prim_none(BindingCache& c, Atom prim, int argc, Atom* args, MethodEnv* env)
    {
        PROF_IF ("callprop_prim_none hit", PRIM_HIT(prim, c)) {
            // cache hit since all prims are final
            // possible speedup: cached the prototype object itself, or at least
            // get the prototype object using a table lookup with tag as the index
            return call_prim_dynamic(env, prim, c.name, argc, args);
        } 
        return callprop_miss(c, prim, argc, args, env);
    }

    // generic call handler for uncommon cases
    Atom callprop_generic(BindingCache& c, Atom obj, int argc, Atom* args, MethodEnv* env)
    {
        // go back to callprop_miss() after this call in case atom type changes
        // to something allowing a smarter handler
        c.call_handler = callprop_miss;
        Toplevel* toplevel = env->toplevel();
        VTable* vtable = toplevel->toVTable(obj);
        tagprof("callprop_generic obj", obj);
        tagprof("callprop_generic bind", toplevel->getBinding(vtable->traits, c.name));
        return toplevel->callproperty(obj, c.name, argc, args, vtable);
    }

    static const CallCacheHandler callprop_obj_handlers[8] = {
        &callprop_obj_none,     // BKIND_NONE
        &callprop_obj_method,   // BKIND_METHOD
        0,                      // BKIND_VAR (custom handler picked below)
        0,                      // BKIND_CONST
        0,                      // BKIND_unused (impossible)
        &callprop_generic,      // BKIND_GET
        &callprop_generic,      // BKIND_SET (error)
        &callprop_generic       // BKIND_GETSET
    };

    // handlers for ScriptObject slots, indexed by SlotStorageType.  We only 
    // care about slot types that hold something we can call; other cases
    // will be errors, so we use the generic handler for them.
    static const CallCacheHandler callprop_slot_handlers[8] = {
        &callprop_obj_slot<Atom>,           // SST_atom
        &callprop_generic,                  // SST_string
        &callprop_generic,                  // SST_namespace
        &callprop_obj_slot<ScriptObject*>,  // SST_scriptobject
        &callprop_generic,                  // SST_int32
        &callprop_generic,                  // SST_uint32
        &callprop_generic,                  // SST_bool32
        &callprop_generic                   // SST_double
    };

    static const CallCacheHandler callprop_prim_handlers[8] = {
        &callprop_prim_none,    // BKIND_NONE
        &callprop_prim_method,  // BKIND_METHOD
        0,                      // BKIND_VAR (impossible on primitive)
        0,                      // BKIND_CONST (impossible on primitive)
        0,                      // BKIND_unused (impossible)
        &callprop_generic,      // BKIND_GET
        0,                      // BKIND_SET (impossible on primitive)
        0                       // BKIND_GETSET (impossible on primitive)
    };

    // cache handler when cache miss occurs:
    //  - Look up the binding using the Multiname saved in the cache
    //  - save the object vtable (for ScriptObject*) or atom tag (all others)
    //  - pick a handler and save the MethodEnv* or slot_offset
    //  - invoke the new handler, which WILL NOT miss on this first call
    Atom callprop_miss(BindingCache& c, Atom obj, int argc, Atom* args, MethodEnv* env)
    {
        AssertNotNull(obj);
        Toplevel* toplevel = env->toplevel();
        VTable* vtable = toplevel->toVTable(obj);
        Traits* obj_type = vtable->traits;
        Binding b = toplevel->getBinding(obj_type, c.name);
        if (AvmCore::isMethodBinding(b)) {
            // cache the method we will call
            c.method = vtable->methods[AvmCore::bindingToMethodId(b)];
        }
        if (isObjectPtr(obj)) {
            c.vtable = vtable;
            if (AvmCore::isSlotBinding(b)) {
                // precompute the slot offset, then install a cache handler that's
                // specialized for the slot type
                void *slot_ptr, *obj_ptr = atomObj(obj);
                SlotStorageType sst = obj_type->getTraitsBindings()->
                    calcSlotAddrAndSST(AvmCore::bindingToSlotId(b), obj_ptr, slot_ptr);
                c.call_handler = callprop_slot_handlers[sst];
                c.slot_offset = uintptr_t(slot_ptr) - uintptr_t(obj_ptr);
            } else {
                // all other bindings 
                c.call_handler = callprop_obj_handlers[AvmCore::bindingKind(b)];
            }
        } else {
            // must be a primitive: int, bool, string, namespace, or number
            c.call_handler = callprop_prim_handlers[AvmCore::bindingKind(b)];
            c.tag = atomKind(obj);
        }
        return c.call_handler(c, obj, argc, args, env);
    }
    FUNCTION(CALL_INDIRECT, SIG6(A,P,P,A,I,P,P), call_cache_handler)

    // called by jit'd code when an OP_callproperty or callproplex could not be
    // early bound to a property and we must do the property lookup at runtime,
    // AND the multiname has runtime parts, so we couldn't use a BindingCache.
    Atom callprop_late(MethodEnv* caller_env, Atom base, const Multiname* name, int argc, Atom* args) {
        BindingCache c(NULL, name);  // temporary cache, just so we can call the generic handler.
        return callprop_generic(c, base, argc, args, caller_env);
    }
    FUNCTION(FUNCADDR(callprop_late), SIG5(A,P,A,P,I,P), callprop_late)

    // forward decl
    Atom getprop_miss(BindingCache&, MethodEnv*, Atom obj);

    // getting any property (catch-all)
    Atom getprop_generic(BindingCache& c, MethodEnv* env, Atom obj)
    {
        // reinstall miss handler so we don't end up dead-ended here in this handler.
        c.get_handler = getprop_miss;
        Toplevel* toplevel = env->toplevel();
        VTable* vtable = toplevel->toVTable(obj);
        tagprof("getprop_generic obj", obj);
        tagprof("getprop_generic bind", toplevel->getBinding(vtable->traits, c.name));
        return toplevel->getproperty(obj, c.name, vtable);
    }

    // overloaded helpers that convert a raw value to Atom.  helper will be
    // chosen based on the <T> parameter to getprop_obj_slot, below.
    typedef struct _Atom* OpaqueAtom;  // so we dont collide with int32_t
    enum Bool32 {};                    // can't use bool when sizeof(bool) != sizeof(int32_t)
    REALLY_INLINE Atom boxslot(AvmCore*, OpaqueAtom a) { return (Atom)a; }
    REALLY_INLINE Atom boxslot(AvmCore*, String* a) { return a->atom(); }
    REALLY_INLINE Atom boxslot(AvmCore*, Namespace* a) { return a->atom(); }
    REALLY_INLINE Atom boxslot(AvmCore*, ScriptObject* a) { return a->atom(); }
    REALLY_INLINE Atom boxslot(AvmCore* core, int32_t i) { return core->intToAtom(i); }
    REALLY_INLINE Atom boxslot(AvmCore* core, uint32_t u) { return core->uintToAtom(u); }
    REALLY_INLINE Atom boxslot(AvmCore*, Bool32 b) { return ((b != 0)<<3)|kBooleanType; }
    REALLY_INLINE Atom boxslot(AvmCore* core, double d) { return core->doubleToAtom(d); }

    // getting a slot on an object, specialized on slot type to streamline boxing
    template <class T>
    Atom getprop_obj_slot(BindingCache& c, MethodEnv* env, Atom obj)
    {
        PROF_IF ("getprop_obj_slot hit", OBJ_HIT(obj, c)) {
            return boxslot(atomObj(obj)->core(), load_cached_slot<T>(c, obj));
        }
        return getprop_miss(c, env, obj);
    }

    // calling a getter method on an object
    Atom getprop_obj_get(BindingCache& c, MethodEnv* env, Atom obj)
    {
        PROF_IF ("getprop_obj_get hit", OBJ_HIT(obj, c)) {
            return c.method->coerceEnter(obj);
        }
        return getprop_miss(c, env, obj);
    }

    // getting a dynamic property on an object
    Atom getprop_obj_none(BindingCache& c, MethodEnv* env, Atom obj)
    {
        PROF_IF ("getprop_obj_none hit", OBJ_HIT(obj, c)) {
            return atomObj(obj)->getMultinameProperty(c.name);
        }
        return getprop_miss(c, env, obj);
    }

    // getting an object method (method closure creation)
    Atom getprop_obj_method(BindingCache& c, MethodEnv* env, Atom obj)
    {
        PROF_IF ("getprop_obj_method hit", OBJ_HIT(obj, c)) {
            return env->toplevel()->methodClosureClass->create(c.method, obj)->atom();
        }
        return getprop_miss(c, env, obj);
    }

    // getting the result of a getter property on a primitive, e.g. String.length
    Atom getprop_prim_get(BindingCache& c, MethodEnv* env, Atom obj)
    {
        PROF_IF ("getprop_prim_get hit", PRIM_HIT(obj, c)) {
            return c.method->coerceEnter(obj);
        }
        return getprop_miss(c, env, obj);
    }

    // handlers for gets on ScriptObject* objects, indexed by bindingKind(Binding)
    static const GetCacheHandler getprop_obj_handlers[8] = {
        &getprop_obj_none,      // BKIND_NONE
        &getprop_obj_method,    // BKIND_METHOD (method extraction)
        0,                      // BKIND_VAR (will use slot handler table below)
        0,                      // BKIND_CONST (will use slot handler table)
        0,                      // BKIND_unused (impossible)
        &getprop_obj_get,       // BKIND_GET
        &getprop_generic,       // BKIND_SET (error)
        &getprop_obj_get        // BKIND_GETSET
    };

    // handlers for slots on ScriptObject, indexed by SlotStorageType
    static const GetCacheHandler getprop_slot_handlers[8] = {
        &getprop_obj_slot<OpaqueAtom>,      // SST_atom
        &getprop_obj_slot<String*>,         // SST_string
        &getprop_obj_slot<Namespace*>,      // SST_namespace
        &getprop_obj_slot<ScriptObject*>,   // SST_scriptobject
        &getprop_obj_slot<int32_t>,         // SST_int32
        &getprop_obj_slot<uint32_t>,        // SST_uint32
        &getprop_obj_slot<Bool32>,          // SST_bool32
        &getprop_obj_slot<double>           // SST_double
    };

    // handlers when object is primitive, indexed by bindingKind(Binding)
    static const GetCacheHandler getprop_prim_handlers[8] = {
        &getprop_generic,     // BKIND_NONE
        &getprop_generic,     // BKIND_METHOD
        0,                    // BKIND_VAR (impossible on primitive)
        0,                    // BKIND_CONST (impossible on primitive)
        0,                    // BKIND_unused (impossible)
        getprop_prim_get,     // BKIND_GET
        0,                    // BKIND_SET (impossible on primitive)
        0,                    // BKIND_GETSET (impossible on primitive)
    };

    Atom getprop_miss(BindingCache& c, MethodEnv* env, Atom obj)
    {
        // cache handler when cache miss occurs
        AvmAssert(!AvmCore::isNullOrUndefined(obj));
        Toplevel* toplevel = env->toplevel();
        VTable* vtable = toplevel->toVTable(obj);
        Traits* actual_type = vtable->traits;
        Binding b = toplevel->getBinding(actual_type, c.name);
        if (AvmCore::isMethodBinding(b)) {
            c.method = vtable->methods[AvmCore::bindingToMethodId(b)];
        } else if (AvmCore::hasGetterBinding(b)) {
            c.method = vtable->methods[AvmCore::bindingToGetterId(b)];
        }
        if (isObjectPtr(obj)) {
            c.vtable = vtable;
            if (AvmCore::isSlotBinding(b)) {
                // precompute the slot offset, then install a cache handler that's
                // hardwired to read the slot and convert value to Atom.
                void *slot_ptr, *obj_ptr = atomObj(obj);
                const SlotStorageType sst = actual_type->getTraitsBindings()->
                    calcSlotAddrAndSST(AvmCore::bindingToSlotId(b), (void*)obj_ptr, slot_ptr);
                c.get_handler = getprop_slot_handlers[sst];
                c.slot_offset = uintptr_t(slot_ptr) - uintptr_t(obj_ptr);
            }
            else {
                c.get_handler = getprop_obj_handlers[AvmCore::bindingKind(b)];
                if (AvmCore::isMethodBinding(b) &&
                    AvmCore::isXMLorXMLList(obj) &&
                    c.name->contains(actual_type->core->findPublicNamespace())) {
                    // special case for XML objects: dynamic props hide declared methods
                    // dynamic property lookup
                    c.get_handler = getprop_obj_none;
                }
            }
        } else {
            // must be a primitive: int, bool, string, namespace, or number
            c.get_handler = getprop_prim_handlers[AvmCore::bindingKind(b)];
            c.tag = atomKind(obj);
        }
        return c.get_handler(c, env, obj);
    }
    FUNCTION(CALL_INDIRECT, SIG4(A,P,P,P,A), get_cache_handler)

    METHOD(TOPLEVELADDR(Toplevel::getproperty), SIG4(A,P,A,P,P), getproperty)

    CSEMETHOD(TOPLEVELADDR(Toplevel::coerce), SIG3(A,P,A,P), coerce)
    METHOD(ENVADDR(MethodEnv::npe), SIG1(V,P), npe)
    FUNCTION(FUNCADDR(AvmCore::handleInterrupt), SIG1(V,P), handleInterrupt)
    FASTFUNCTION(FUNCADDR(AvmCore::handleStackOverflow), SIG1(V,P), handleStackOverflow)
    METHOD(ENVADDR(MethodEnv::nextname), SIG3(A,P,A,I), nextname)
    METHOD(ENVADDR(MethodEnv::nextvalue), SIG3(A,P,A,I), nextvalue)
    METHOD(ENVADDR(MethodEnv::hasnext), SIG3(I,P,A,I), hasnext)
    METHOD(COREADDR(AvmCore::coerce_s), SIG2(P,P,A), coerce_s)
    METHOD(COREADDR(AvmCore::string), SIG2(P,P,A), string)
    METHOD(TOPLEVELADDR(Toplevel::coerceobj), SIG3(V,P,P,P), coerceobj)
    METHOD(ENVADDR(MethodEnv::coerceAtom2SO), SIG3(P,P,A,P), coerceAtom2SO)
    CSEMETHOD(COREADDR(AvmCore::doubleToString), SIG2(P,P,F), doubleToString)
    CSEMETHOD(COREADDR(AvmCore::uintToString), SIG2(P,P,U), uintToString)
    CSEMETHOD(COREADDR(AvmCore::intToString), SIG2(P,P,I), intToString)
    CSEMETHOD(COREADDR(AvmCore::doubleToAtom), SIG2(A,P,F), doubleToAtom)
    CSEFUNCTION(FUNCADDR(AvmCore::boolean), SIG1(I,A), boolean)
    CSEFUNCTION(FUNCADDR(AvmCore::toUInt32), SIG1(U,A), toUInt32)
    CSEFUNCTION(FUNCADDR(AVMCORE_integer_d), SIG1(I,F), integer_d)
    CSEFUNCTION(FUNCADDR(AvmCore::integer_i), SIG1(I,A), integer_i)
    CSEFUNCTION(FUNCADDR(AvmCore::number_d), SIG1(F,A), number_d)
    CSEFUNCTION(FUNCADDR(AvmCore::integer_u), SIG1(U,A), integer_u)
    CSEFUNCTION(FUNCADDR(AVMCORE_integer), SIG1(I,A), integer)
    CSEFUNCTION(FUNCADDR(AvmCore::number), SIG1(F,A), number)
    METHOD(ENVADDR(MethodEnv::hasnextproto), SIG3(I,P,P,P), hasnextproto)
    METHOD(ENVADDR(MethodEnv::nullcheck), SIG2(V,P,A), nullcheck)
    CSEMETHOD(TOPLEVELADDR(Toplevel::toVTable), SIG2(P,P,A), toVTable)
    METHOD(TOPLEVELADDR(Toplevel::setproperty), SIG5(V,P,A,P,A,P), setproperty)
    METHOD(ENVADDR(MethodEnv::initproperty), SIG5(V,P,A,P,A,P), initproperty)
    METHOD(COREADDR(AvmCore::setDxns), SIG3(V,P,P,P), setDxns)
    METHOD(COREADDR(AvmCore::setDxnsLate), SIG3(V,P,P,A), setDxnsLate)
    FUNCTION(FUNCADDR(AvmCore::istypeAtom), SIG2(A,A,P), istypeAtom)
    CSEMETHOD(TOPLEVELADDR(Toplevel::toClassITraits), SIG2(P,P,A), toClassITraits)
    CSEMETHOD(COREADDR(AvmCore::stricteq), SIG3(A,P,A,A), stricteq)
    METHOD(COREADDR(AvmCore::equals), SIG3(A,P,A,A), equals)
    CSEMETHOD(COREADDR(AvmCore::concatStrings), SIG3(P,P,P,P), concatStrings)
    METHOD(TOPLEVELADDR(Toplevel::add2), SIG3(A,P,A,A), add2)
    CSEMETHOD(COREADDR(AvmCore::EscapeAttributeValue), SIG2(P,P,A), EscapeAttributeValue)
    CSEMETHOD(COREADDR(AvmCore::ToXMLString), SIG2(P,P,A), ToXMLString)
    METHOD(ENVADDR(MethodEnv::delpropertyHelper), SIG4(A,P,A,P,A), delpropertyHelper)
    METHOD(ENVADDR(MethodEnv::internRtns), SIG2(P,P,A), internRtns)
    METHOD(ENVADDR(MethodEnv::delproperty), SIG3(A,P,A,P), delproperty)
    METHOD(ENVADDR(MethodEnv::setpropertyHelper),  SIG6(V,P,A,P,A,P,A), setpropertyHelper)
    METHOD(ENVADDR(MethodEnv::initpropertyHelper), SIG6(V,P,A,P,A,P,A), initpropertyHelper)
    METHOD(ENVADDR(MethodEnv::setpropertylate_u), SIG4(V,P,A,U,A), setpropertylate_u)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_setUintProperty), SIG3(V,P,U,A), DoubleVectorObject_setUintProperty)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_setNativeUintProperty), SIG3(V,P,U,F), DoubleVectorObject_setNativeUintProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_setUintProperty), SIG3(V,P,U,A), IntVectorObject_setUintProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_setUintProperty), SIG3(V,P,U,A), UIntVectorObject_setUintProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_setNativeUintProperty), SIG3(V,P,U,I), IntVectorObject_setNativeUintProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_setNativeUintProperty), SIG3(V,P,U,U), UIntVectorObject_setNativeUintProperty)
    METHOD(ARRAYADDR(ArrayObject::_setUintProperty), SIG3(V,P,U,A), ArrayObject_setUintProperty)
    METHOD(VECTOROBJADDR(ObjectVectorObject::_setUintProperty), SIG3(V,P,U,A), ObjectVectorObject_setUintProperty)
    METHOD(ENVADDR(MethodEnv::setpropertylate_i), SIG4(V,P,A,I,A), setpropertylate_i)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_setIntProperty), SIG3(V,P,I,A), DoubleVectorObject_setIntProperty)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_setNativeIntProperty), SIG3(V,P,I,F), DoubleVectorObject_setNativeIntProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_setIntProperty), SIG3(V,P,I,A), IntVectorObject_setIntProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_setIntProperty), SIG3(V,P,I,A), UIntVectorObject_setIntProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_setNativeIntProperty), SIG3(V,P,I,I), IntVectorObject_setNativeIntProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_setNativeIntProperty), SIG3(V,P,I,U), UIntVectorObject_setNativeIntProperty)
    METHOD(ARRAYADDR(ArrayObject::_setIntProperty), SIG3(V,P,I,A), ArrayObject_setIntProperty)
    METHOD(VECTOROBJADDR(ObjectVectorObject::_setIntProperty), SIG3(V,P,I,A), ObjectVectorObject_setIntProperty)
    METHOD(ENVADDR(MethodEnv::getpropertyHelper), SIG5(A,P,A,P,P,A), getpropertyHelper)
    METHOD(ENVADDR(MethodEnv::getpropertylate_u), SIG3(A,P,A,U), getpropertylate_u)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_getUintProperty), SIG2(A,P,U), DoubleVectorObject_getUintProperty)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_getNativeUintProperty), SIG2(F,P,U), DoubleVectorObject_getNativeUintProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_getUintProperty), SIG2(A,P,U), IntVectorObject_getUintProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_getUintProperty), SIG2(A,P,U), UIntVectorObject_getUintProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_getNativeUintProperty), SIG2(I,P,U), IntVectorObject_getNativeUintProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_getNativeUintProperty), SIG2(U,P,U), UIntVectorObject_getNativeUintProperty)
    METHOD(ARRAYADDR(ArrayObject::_getUintProperty), SIG2(A,P,U), ArrayObject_getUintProperty)
    METHOD(VECTOROBJADDR(ObjectVectorObject::_getUintProperty), SIG2(A,P,U), ObjectVectorObject_getUintProperty)
    METHOD(ENVADDR(MethodEnv::getpropertylate_i), SIG3(A,P,A,I), getpropertylate_i)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_getIntProperty), SIG2(A,P,I), DoubleVectorObject_getIntProperty)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_getNativeIntProperty), SIG2(F,P,I), DoubleVectorObject_getNativeIntProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_getIntProperty), SIG2(A,P,I), IntVectorObject_getIntProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_getIntProperty), SIG2(A,P,I), UIntVectorObject_getIntProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_getNativeIntProperty), SIG2(I,P,I), IntVectorObject_getNativeIntProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_getNativeIntProperty), SIG2(U,P,I), UIntVectorObject_getNativeIntProperty)
    METHOD(ARRAYADDR(ArrayObject::_getIntProperty), SIG2(A,P,I), ArrayObject_getIntProperty)
    METHOD(VECTOROBJADDR(ObjectVectorObject::_getIntProperty), SIG2(A,P,I), ObjectVectorObject_getIntProperty)
    METHOD(ENVADDR(MethodEnv::findproperty), SIG7(A,P,P,P,I,P,B,P), findproperty)
    METHOD(ENVADDR(MethodEnv::checkfilter), SIG2(V,P,A), checkfilter)
    METHOD(ENVADDR(MethodEnv::getdescendants), SIG3(A,P,A,P), getdescendants)
    METHOD(ENVADDR(MethodEnv::newclass), SIG5(P,P,P,P,P,P), newclass)
    METHOD(ENVADDR(MethodEnv::op_newobject), SIG3(P,P,P,I), op_newobject)
    METHOD(TOPLEVELADDR(Toplevel::op_construct), SIG4(A,P,A,I,P), op_construct)
    METHOD(ENVADDR(MethodEnv::callsuper), SIG4(A,P,P,I,P), callsuper)
    METHOD(TOPLEVELADDR(Toplevel::constructprop), SIG5(A,P,P,I,P,P), constructprop)
    METHOD(ENVADDR(MethodEnv::setsuper), SIG4(V,P,A,P,A), setsuper)
    METHOD(ENVADDR(MethodEnv::getsuper), SIG3(A,P,A,P), getsuper)
    METHOD(COREADDR(AvmCore::throwAtom), SIG2(V,P,A), throwAtom)
    CSEFUNCTION(FUNCADDR(MathUtils::mod), SIG2(F,F,F), mod)
    CSEMETHOD(COREADDR(AvmCore::_typeof), SIG2(P,P,A), typeof)
    FUNCTION(FUNCADDR(AvmCore::atomWriteBarrier), SIG4(V,P,P,P,A), atomWriteBarrier)
    METHOD(GCADDR(GC::privateWriteBarrierRC), SIG4(V,P,P,P,P), privateWriteBarrierRC)
    CSEMETHOD(COREADDR(AvmCore::uintToAtom), SIG2(A,P,U), uintToAtom)
    CSEMETHOD(COREADDR(AvmCore::intToAtom), SIG2(A,P,I), intToAtom)
    METHOD(COREADDR(AvmCore::compare), SIG3(A,P,A,A), compare)
    CSEMETHOD(ENVADDR(MethodEnv::createRestHelper), SIG3(P,P,I,P), createRestHelper)
    CSEMETHOD(ENVADDR(MethodEnv::createArgumentsHelper), SIG3(P,P,I,P), createArgumentsHelper)
    METHOD(COREADDR(AvmCore::initMultinameLate), SIG3(V,P,P,A), initMultinameLate)
    METHOD(ENVADDR(MethodEnv::initMultinameLateForDelete), SIG3(V,P,P,A), initMultinameLateForDelete)
    CSEFUNCTION(FUNCADDR(MathUtils::doubleToBool), SIG1(I,F), doubleToBool)
    METHOD(CLASSCLOSUREADDR(ClassClosure::newInstance), SIG1(P,P), newInstance)

    METHOD(EFADDR(ExceptionFrame::endTry), SIG1(V,P), endTry)
    METHOD(EFADDR(ExceptionFrame::beginTry), SIG2(V,P,P), beginTry)
    FUNCTION(SETJMP, SIG2(I,P,I), fsetjmp)
    METHOD(COREADDR(AvmCore::beginCatch), SIG5(P,P,P,P,P,P), beginCatch)

SSE2_ONLY(
    CSEMETHOD(COREADDR(AvmCore::doubleToAtom_sse2), SIG2(A,P,F), doubleToAtom_sse2)
    CSEFUNCTION(FUNCADDR(AvmCore::integer_d_sse2), SIG1(I,F), integer_d_sse2)
)

#ifdef DEBUGGER
    METHOD(ENVADDR(MethodEnv::debugEnter), SIG5(V,P,P,P,P,P), debugEnter)
    METHOD(ENVADDR(MethodEnv::debugExit), SIG2(V,P,P), debugExit)
    METHOD(DEBUGGERADDR(Debugger::debugFile), SIG2(V,P,P), debugFile)
    METHOD(DEBUGGERADDR(Debugger::debugLine), SIG2(V,P,I), debugLine)
    METHOD(COREADDR(AvmCore::sampleCheck), SIG1(V,P), sampleCheck)
#endif

    // MOPS helper functions
    METHOD(ENVADDR(MethodEnv::li8),  SIG2(I,P,I), li8)
    METHOD(ENVADDR(MethodEnv::li16), SIG2(I,P,I), li16)
    METHOD(ENVADDR(MethodEnv::li32), SIG2(I,P,I), li32)
    METHOD(ENVADDR(MethodEnv::lf32), SIG2(F,P,I), lf32)
    METHOD(ENVADDR(MethodEnv::lf64), SIG2(F,P,I), lf64)
    METHOD(ENVADDR(MethodEnv::si8),  SIG3(V,P,I,I), si8)
    METHOD(ENVADDR(MethodEnv::si16), SIG3(V,P,I,I), si16)
    METHOD(ENVADDR(MethodEnv::si32), SIG3(V,P,I,I), si32)
    METHOD(ENVADDR(MethodEnv::sf32), SIG3(V,P,F,I), sf32)
    METHOD(ENVADDR(MethodEnv::sf64), SIG3(V,P,F,I), sf64)

    typedef Atom (*op_call_MethodEnv)(MethodEnv*, Atom, int, Atom*);
    FUNCTION(FUNCADDR((op_call_MethodEnv)&avmplus::op_call<MethodEnv*>), SIG4(A,P,A,I,P), op_call)

    typedef Atom (*op_applytype_MethodEnv)(MethodEnv*, Atom, int, Atom*);
    FUNCTION(FUNCADDR((op_applytype_MethodEnv)&avmplus::op_applytype<MethodEnv*>), SIG4(A,P,A,I,P), op_applytype)

    typedef ArrayObject* (*newarray_MethodEnv)(MethodEnv*, int, Atom*);
    FUNCTION(FUNCADDR((newarray_MethodEnv)&newarray<MethodEnv*>), SIG3(P,P,I,P), newarray)

    typedef Atom (*astype_late_MethodEnv)(MethodEnv*, Atom, Atom);
    CSEFUNCTION(FUNCADDR((astype_late_MethodEnv)&astype_late<MethodEnv*>), SIG3(A,P,A,A), astype_late)
    CSEFUNCTION(FUNCADDR(AvmCore::astype), SIG2(A,A,P), astype)

    typedef Atom (*instanceof_MethodEnv)(MethodEnv*, Atom, Atom);
    FUNCTION(FUNCADDR((instanceof_MethodEnv)&instanceof<MethodEnv*>), SIG3(A,P,A,A), instanceof)

    typedef Atom (*op_in_MethodEnv)(MethodEnv*, Atom, Atom);
    FUNCTION(FUNCADDR((op_in_MethodEnv)&op_in<MethodEnv*>), SIG3(A,P,A,A), op_in)

    CSEFUNCTION(FUNCADDR(finddef_cache), SIG3(P,P,P,U), finddef_cache)
