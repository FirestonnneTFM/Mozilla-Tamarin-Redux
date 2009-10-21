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

//
// Non-Inline implementations of functions defined in instr.h
//

#include "avmplus.h"

//#define DOPROF
#include "../vprof/vprof.h"

namespace avmplus
{

template <class E>
Atom callprop_b(E env, Atom base, const Multiname* multiname, int argc, Atom* atomv, VTable* vtable, Binding b)
{
    AssertNotNull(base);
    switch (AvmCore::bindingKind(b))
    {
    case BKIND_METHOD:
        return call_method_binding(base, vtable, b, argc, atomv);

    case BKIND_VAR:
    case BKIND_CONST:
        return call_slot_binding(env, base, b, argc, atomv);

    case BKIND_GET:
    case BKIND_GETSET:
        return op_call(env, call_get_binding(base, vtable, b), argc, atomv);

    case BKIND_SET:
        // read on write-only property
        env->toplevel()->throwReferenceError(kWriteOnlyError, multiname, vtable->traits);
        return unreachableAtom;

    default:
        if (isObjectPtr(base)) {
            return call_obj_dynamic(base, multiname, argc, atomv);
        } else {
            return call_prim_dynamic(env, base, multiname, argc, atomv);
        }
    }
}
template Atom callprop_b(Toplevel*, Atom, const Multiname*, int, Atom*, VTable*, Binding);

/**
 * find the binding for a property given a full multiname reference.  The lookup
 * must produce a single binding, or it's an error.  Note that the name could be
 * bound to the same binding in multiple namespaces.
 */
template <class E>
Binding getBinding(E env, Traits* traits, const Multiname* ref)
{
    Binding b = BIND_NONE;
    if (traits && ref->isBinding())
    {
        if (!traits->isResolved())
            traits->resolveSignatures(env->toplevel());

        TraitsBindingsp tb = traits->getTraitsBindings();
        if (!ref->isNsset())
        {
            b = tb->findBinding(ref->getName(), ref->getNamespace());
        }
        else
        {
            b = tb->findBinding(ref->getName(), ref->getNsset());
            if (b == BIND_AMBIGUOUS)
            {
                // ERROR.  more than one binding is available.  throw exception.
                env->toplevel()->throwTypeError(kAmbiguousBindingError, env->core()->toErrorString(ref));
            }
        }
    }
    return b;
}
template Binding getBinding(const Toplevel*, Traits*, const Multiname*);
template Binding getBinding(Toplevel*, Traits*, const Multiname*);

template <class E>
VTable* toVTable(E env, Atom atom)
{
    if (!AvmCore::isNullOrUndefined(atom))
    {
        if (atomKind(atom) == kObjectType)
            return AvmCore::atomToScriptObject(atom)->vtable;

        Toplevel* toplevel = env->toplevel();
        switch (atom&7)
        {
        case kNamespaceType:
            return toplevel->namespaceClass->ivtable();
        case kStringType:
            return toplevel->stringClass->ivtable();
        case kBooleanType:
            return toplevel->booleanClass->ivtable();
        case kIntegerType:
        case kDoubleType:
            // ISSUE what about int?
            return toplevel->numberClass->ivtable();
        }
    }

    // TypeError in ECMA
    env->toplevel()->throwTypeError(
            (atom == undefinedAtom) ? kConvertUndefinedToObjectError :
                                kConvertNullToObjectError);
    // unreachable
    return NULL;
}
template VTable* toVTable(Toplevel*, Atom);

template <class E>
Atom op_applytype(E env, Atom factory, int argc, Atom* args)
{
    if (AvmCore::isObject(factory))
        return AvmCore::atomToScriptObject(factory)->applyTypeArgs(argc, args);

    env->toplevel()->throwTypeError(kTypeAppOfNonParamType);
    return unreachableAtom;
}
template Atom op_applytype(Toplevel*, Atom, int, Atom*);
template Atom op_applytype(MethodEnv*, Atom, int, Atom*);

template <class E>
Atom astype_late(E caller_env, Atom value, Atom type) {
    Traits* itraits = caller_env->toplevel()->toClassITraits(type);
    return AvmCore::astype(value, itraits);
}
template Atom astype_late(MethodEnv*, Atom, Atom);

template <class E>
Atom instanceof(E caller_env, Atom val, Atom ctor) {
    return caller_env->toplevel()->instanceof(val, ctor);
}
template Atom instanceof(MethodEnv*, Atom, Atom);

template <class E>
Atom op_in(E caller_env, Atom name, Atom obj) {
    return caller_env->toplevel()->in_operator(name, obj);
}
template Atom op_in(MethodEnv*, Atom, Atom);

#ifdef FEATURE_NANOJIT
ScriptObject* finddef_cache(MethodEnv* env, const Multiname* name, uint32_t slot)
{
    AvmAssert(env->method->lookup_cache_size() > 0);
    AvmAssert(slot < (uint32_t)env->method->lookup_cache_size());
    MethodEnv::LookupCache *cache = env->lookup_cache;
    if (!cache) {
        // todo - do this earlier.  This extra test in the fast path
        // is repugnant but hasn't shown itself to be a problem in practice.
        using namespace MMgc;
        size_t nbytes = sizeof(*cache) * env->method->lookup_cache_size();
        _nvprof("lookup_cache_bytes", nbytes);
        AvmCore* core = env->core();
        cache = (MethodEnv::LookupCache*) core->gc->Alloc(nbytes, GC::kContainsPointers | GC::kZero);
        env->lookup_cache = cache;
    }

    // check for valid cache
    AvmCore* core = env->core();
    if (core->lookupCacheIsValid(cache[slot].timestamp)) {
        _nvprof("finddef P-fast", 1);
        return cache[slot].object;
    }

    // miss
    _nvprof("finddef P-fast", 0);
    ScriptObject* obj = env->finddef(name);
    AvmAssert(obj != NULL); // or else finddef would have thrown an exception.
    cache[slot].timestamp = core->lookupCacheTimestamp();
    WBRC(core->gc, cache, &cache[slot].object, obj);
    return obj;
}
#endif // FEATURE_NANOJIT

Atom constructprop(Toplevel* toplevel, const Multiname* multiname, int argc, Atom* atomv, VTable* vtable)
{
    Binding b = getBinding(toplevel, vtable->traits, multiname);
    Atom obj = atomv[0];
    switch (AvmCore::bindingKind(b))
    {
    case BKIND_METHOD:
    {
        // can't invoke method as constructor
        MethodEnv* env = vtable->methods[AvmCore::bindingToMethodId(b)];
        toplevel->throwTypeError(kCannotCallMethodAsConstructor, toplevel->core()->toErrorString(env->method));
    }
    case BKIND_VAR:
    case BKIND_CONST:
    {
        ScriptObject* ctor = AvmCore::atomToScriptObject(obj)->getSlotObject(AvmCore::bindingToSlotId(b));
        AvmCore* core = toplevel->core();
        if (!ctor ||
            (!ctor->traits()->containsInterface(CLASS_TYPE) && !ctor->traits()->containsInterface(FUNCTION_TYPE)))
            toplevel->throwTypeError(kNotConstructorError, core->toErrorString(multiname));
        // inlined equivalent of op_construct
        return ctor->construct(argc, atomv);
    }
    case BKIND_GET:
    case BKIND_GETSET:
    {
        // Invoke the getter
        int m = AvmCore::bindingToGetterId(b);
        MethodEnv *f = vtable->methods[m];
        Atom ctor = f->coerceEnter(obj);
        return op_construct(toplevel, ctor, argc, atomv);
    }
    case BKIND_SET:
    {
        // read on write-only property
        toplevel->throwReferenceError(kWriteOnlyError, multiname, vtable->traits);
    }
    default:
        if ((obj&7)==kObjectType)
        {
            return AvmCore::atomToScriptObject(obj)->constructProperty(multiname, argc, atomv);
        }
        else
        {
            // primitive types are not dynamic, so we can go directly
            // to their __proto__ object
            ScriptObject* proto = toplevel->toPrototype(obj);
            Atom ctor = proto->getMultinameProperty(multiname);
            return op_construct(toplevel, ctor, argc, atomv);
        }
    }
}

/**
 * implements ECMA implicit coersion.  returns the coerced value,
 * or throws a TypeError if coersion is not possible.
 */
// NOTE: parts of this function have been explicitly inlined into MethodEnv::unbox1 for
// efficiency. If you change/fix this method, you may need to change/fix MethodEnv::unbox1 as well.
Atom coerceImpl(const Toplevel* toplevel, Atom atom, Traits* expected)
{
    AvmAssert(expected != NULL);
    AvmAssert(!AvmCore::atomDoesNotNeedCoerce(atom, BuiltinType(expected->builtinType)));

    Traits* actual;
    AvmCore* core = toplevel->core();

    // these types always succeed
    switch (expected->builtinType)
    {
        case BUILTIN_boolean:
            return AvmCore::booleanAtom(atom);
        case BUILTIN_number:
            return core->numberAtom(atom);
        case BUILTIN_string:
            return AvmCore::isNullOrUndefined(atom) ? nullStringAtom : core->string(atom)->atom();
        case BUILTIN_int:
            return core->intAtom(atom);
        case BUILTIN_uint:
            return core->uintAtom(atom);
        case BUILTIN_object:
            return atom == undefinedAtom ? nullObjectAtom : atom;
    }
    // else fall thru

    if (AvmCore::isNullOrUndefined(atom))
        return (expected->builtinType == BUILTIN_void) ? undefinedAtom : nullObjectAtom;

    switch (atomKind(atom))
    {
    case kStringType:
        actual = core->traits.string_itraits;
        break;

    case kBooleanType:
        actual = core->traits.boolean_itraits;
        break;

    case kDoubleType:
        actual = core->traits.number_itraits;
        break;

    case kIntegerType:
        actual = core->traits.int_itraits;
        break;

    case kNamespaceType:
        actual = core->traits.namespace_itraits;
        break;

    case kObjectType:
        actual = AvmCore::atomToScriptObject(atom)->traits();
        break;

    default:
        // unexpected atom type
        AvmAssert(false);
        return unreachableAtom;
    }

    if (!actual->containsInterface(expected))
    {
        // failed
#ifdef AVMPLUS_VERBOSE
        //core->console << "checktype failed " << expected << " <- " << atom << "\n";
#endif
        toplevel->throwTypeError(kCheckTypeFailedError, core->atomToErrorString(atom), core->toErrorString(expected));
    }

    return atom;
}

template <class E>
void coerceobj(E caller_env, ScriptObject* obj, Traits* type) {
	#ifdef DOPROF // Adding this ifdef because this does not compile with Symbian emulator WINSCW compiler (it expects >=3 parameters for _nvprof).
    _nvprof("coerceobj",1);
	#endif // DOPROF
    if (obj && !obj->traits()->containsInterface(type)) {
        AvmCore* core = caller_env->core();
        caller_env->toplevel()->throwTypeError(kCheckTypeFailedError, core->atomToErrorString(obj->atom()), core->toErrorString(type));
    }
}
template void coerceobj(MethodEnv*, ScriptObject*, Traits*);

Atom op_add(AvmCore* core, Atom lhs, Atom rhs)
{
    tagprof("op_add val1", lhs);
    tagprof("op_add val2", rhs);

    // detect integers... less control flow but more registers -- which is better?
    #define IS_BOTH_INTEGER(a,b) ((((a ^ kIntegerType) | (b ^ kIntegerType)) & 7) == 0)
    // integer optimization based on the one from Interpreter.cpp, modified
    // to reduce the # of alu instructions
    if (IS_BOTH_INTEGER(lhs,rhs)) {
        intptr_t sum = lhs + rhs - kIntegerType;
        if ((lhs ^ rhs) < 0 || (lhs ^ sum) >= 0) {
            // no overflow
            return sum;
        }
        // both integers, but overflow happens.  Intentionally add these
        // without casting to int32_t.  If the sum of the shifted values overflow,
        // we know the unshifted values will not overflow with a word-sized add.
        return core->allocDouble(double(atomInt(lhs) + atomInt(rhs)));
    }

    if (AvmCore::isNumber(lhs) && AvmCore::isNumber(rhs))
    {
        // C++ porting note. if either side is undefined NaN then result must be NaN,
        // which is assumed to be taken care of by IEEE 748 double add.
        goto add_numbers;
    }
    
    if (AvmCore::isString(lhs) || AvmCore::isString(rhs) || AvmCore::isDate(lhs) || AvmCore::isDate(rhs))
    {
        goto concat_strings;
    }

    // then look for the more unlikely cases

    // E4X, section 11.4.1, pg 53

    if (AvmCore::isXMLorXMLList(lhs) && AvmCore::isXMLorXMLList(rhs))
    {
        XMLListObject *l = new (core->GetGC()) XMLListObject(atomObj(lhs)->toplevel()->xmlListClass());
        l->_append(lhs);
        l->_append(rhs);
        return l->atom();
    }

    // to catch oddball cases like:
    //   function foo() { };
    //   foo.prototype.valueOf = function() { return new Object(); }
    //   foo.prototype.toString = function() { return 2; }
    //   print( new foo() + 33 ); // should be 35
    //
    // we need to follow the E3 spec:
    // 1. call ToPrimitive() on lhs and rhs, then
    // if L is String || R is String, concat, else add toNumber(lhs) to toNumber(rhs)

    // ToPrimitive() will call [[DefaultValue]], which calls valueOf().  If the result is
    //  a primitive, return that value else call toString() instead.

    // from E3:
    // NOTE No hint is provided in the calls to ToPrimitive in steps 5 and 6. All native ECMAScript objects except Date objects handle
    // the absence of a hint as if the hint Number were given; Date objects handle the absence of a hint as if the hint String were given.
    // Host objects may handle the absence of a hint in some other manner.

    lhs = AvmCore::primitive(lhs); // Date is handled above with the String argument case,  we don't have to check for it here.
    rhs = AvmCore::primitive(rhs);

    if (!(AvmCore::isString(lhs) || AvmCore::isString(rhs)))
    {
        goto add_numbers;
    }
    // else fall thru to concat_strings

concat_strings:
    return core->concatStrings(core->string(lhs), core->string(rhs))->atom();

add_numbers:
    return core->doubleToAtom(AvmCore::number(lhs) + AvmCore::number(rhs));
#undef IS_BOTH_INTEGER
}

} // namespace avmplus
