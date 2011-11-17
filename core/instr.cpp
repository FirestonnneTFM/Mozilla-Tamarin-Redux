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

#ifdef PERFM
#define DOPROF
#endif /* PERFM */

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
        // note, you no longer must resolve the traits in order to find the binding!

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
        switch (atomKind(atom))
        {
        case kNamespaceType:
            return toplevel->namespaceClass()->ivtable();
        case kStringType:
            return toplevel->stringClass()->ivtable();
        case kBooleanType:
            return toplevel->booleanClass()->ivtable();
        case kIntptrType:
        case kDoubleType:
            // ISSUE what about int?
            return toplevel->numberClass()->ivtable();
#ifdef VMCFG_FLOAT
        case kSpecialBibopType:
            if( bibopKind(atom) == kBibopFloatType )
                return toplevel->floatClass()->ivtable();
            if( bibopKind(atom) == kBibopFloat4Type )
                return toplevel->float4Class()->ivtable();
            AvmAssertMsg(false,"Unhandled bibop kind");
#endif // VMCFG_FLOAT
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

#ifdef VMCFG_NANOJIT
ScriptObject* finddef_cache(MethodEnv* env, const Multiname* name, uint32_t slot)
{
    AvmAssert(env->method->lookup_cache_size() > 0);
    AvmAssert(slot < (uint32_t)env->method->lookup_cache_size());
    ExactStructContainer<MethodEnv::LookupCache>* cache = env->lookup_cache;
    if (!cache) {
        // todo - do this earlier.  This extra test in the fast path
        // is repugnant but hasn't shown itself to be a problem in practice.
        _nvprof("lookup_cache_bytes", sizeof(*cache) * env->method->lookup_cache_size());
        env->createLookupCache();
        cache = env->lookup_cache;
    }

    // check for valid cache
    AvmCore* core = env->core();
    if (core->lookupCacheIsValid(cache->get(slot).timestamp)) {
        _nvprof("finddef P-fast", 1);
        return cache->get(slot).object;
    }

    // miss
    _nvprof("finddef P-fast", 0);
    ScriptObject* obj = env->finddef(name);
    AvmAssert(obj != NULL); // or else finddef would have thrown an exception.
    cache->get(slot).timestamp = core->lookupCacheTimestamp();
    WBRC(core->gc, cache, &cache->get(slot).object, obj);
    return obj;
}
#endif // VMCFG_NANOJIT

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
        // This code is a bit subtle.  Note that ScriptObject::getSlotObject() will return NULL if the
        // slot is an SST_scriptobject and is NULL, or an SST_atom that is null, undefined, or not
        // an object.  These subsume the test isObject(ctor) in op_construct(), which is inlined here.
        // We once included an extra check, resulting in throwing a different exception when taking this
        // path in interpreted code.  We must emulate this old behavior for backward compatibility.
        // It is unfortunate that CLASS_TYPE and FUNCTION_TYPE expand into references to 'core', otherwise
        // we could push the next line down into the exceptional path.
        AvmCore* core = toplevel->core();
        if (!ctor || (!ctor->traits()->subtypeof(CLASS_TYPE) && !ctor->traits()->subtypeof(FUNCTION_TYPE))) {
            // We know that an exception will be thrown eventually, so now do the version check.
            if (core->currentBugCompatibility()->bugzilla456852a) {
                // Correct behavior is to throw kConstructOfNonFunctionError as op_construct would do.
                if (!ctor) {
                    toplevel->throwTypeError(kConstructOfNonFunctionError);
                }
            } else {
                // Stay compatible with old behavior.
                toplevel->throwTypeError(kNotConstructorError, core->toErrorString(multiname));
            }
        }
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
    {
        ScriptObject* o;
        if (atomKind(obj)==kObjectType)
        {
            o = AvmCore::atomToScriptObject(obj);
        }
        else
        {
#ifdef VMCFG_FLOAT
            if (AvmCore::isFloat4(obj))
            {
                // See FIXME in Toplevel::getproperty for why this is "correct".
                if (multiname->isValidDynamicName())
                {
                    uint32_t index;
                    if (AvmCore::getIndexFromAtom(multiname->getName()->atom(), &index))
                        toplevel->throwTypeError(kConstructOfNonFunctionError);
                }
            }
#endif
            // primitive types are not dynamic, so we can go directly
            // to their __proto__ object
            o = toplevel->toPrototype(obj);
        }
        atomv[0] = o->atom(); // replace receiver
        Atom ctor = o->getMultinameProperty(multiname);
        return op_construct(toplevel, ctor, argc, atomv);
    }
    }
}

/**
 * implements ECMA implicit coersion.  returns the coerced value,
 * or throws a TypeError if coersion is not possible.
 */
// NOTE: parts of this function have been explicitly inlined into BaseExecMgr::unbox1 for
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
#ifdef VMCFG_FLOAT
        case BUILTIN_float:
            return AvmCore::isFloat(atom)?atom:core->floatAtom(atom);  
        case BUILTIN_float4:
            return AvmCore::isFloat4(atom)?atom:core->float4Atom(atom);  
#endif
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

    case kIntptrType:
        actual = core->traits.int_itraits;
        break;

    case kNamespaceType:
        actual = core->traits.namespace_itraits;
        break;

    case kObjectType:
        actual = AvmCore::atomToScriptObject(atom)->traits();
        break;

#ifdef VMCFG_FLOAT
    case kSpecialBibopType:
        AvmAssert(atom != AtomConstants::undefinedAtom);

        if(bibopKind(atom) == kBibopFloatType)
        {
            actual = core->traits.float_itraits;
            break;
        }
        if(bibopKind(atom) == kBibopFloat4Type)
        {
            actual = core->traits.float4_itraits;
            break;
        }
        // fall trhu to default
#endif 
    default:
        // unexpected atom type
        AvmAssert(false);
        return unreachableAtom;
    }

    if (!actual->subtypeof(expected))
    {
        // failed
#ifdef AVMPLUS_VERBOSE
        //core->console << "checktype failed " << expected << " <- " << atom << "\n";
#endif
        toplevel->throwTypeError(kCheckTypeFailedError, core->atomToErrorString(atom), core->toErrorString(expected));
    }

    return atom;
}

#define AssertObjTraits(env,t) \
    AvmAssert(t && !t->isMachineType());\
    AvmAssert(t != env->core()->traits.string_itraits);\
    AvmAssert(t != env->core()->traits.namespace_itraits);

static void throwCheckTypeError(MethodEnv* env, Atom atom, Traits* t)
{
    AvmCore *core = env->core();
        env->toplevel()->throwTypeError(kCheckTypeFailedError,
            core->atomToErrorString(atom),
            core->toErrorString(t));
}

void coerceobj_obj(MethodEnv* caller_env, ScriptObject* obj, Traits* t)
{
    AssertObjTraits(caller_env, t);
    if (obj && !obj->traits()->subtypeof(t))
        throwCheckTypeError(caller_env, obj->atom(), t);
}

void coerceobj_atom(MethodEnv *env, Atom atom, Traits* t)
{
    AssertObjTraits(env, t);
    if (!AvmCore::isNullOrUndefined(atom) &&
            (atomKind(atom) != kObjectType || !atomObj(atom)->traits()->subtypeof(t)))
        throwCheckTypeError(env, atom, t);
}
    
#ifdef VMCFG_FLOAT
#define INTPTRASDOUBLE(v)  ( (double) atomGetIntptr(v) )
template<typename T> T __multiply(T a, T b){ return a * b; }
template<typename T> T __divide(T a, T b){ return a / b; }
template<typename T> T __subtract(T a, T b){ return a - b; }
static double __modulo(double a, double b){ return MathUtils::mod(a,b); }
static float __modulo(float a, float b){ return (float) MathUtils::mod(a,b); }
static float4_t __modulo(float4_t a, float4_t b){ 
    float x= __modulo(f4_x(a), f4_x(b));
    float y= __modulo(f4_y(a), f4_y(b));
    float z= __modulo(f4_z(a), f4_z(b));
    float w= __modulo(f4_w(a), f4_w(b));
    float4_t res = {x, y, z, w};
    return res;
}
template<> float4_t __multiply<float4_t>(float4_t a, float4_t b) { return f4_mul(a,b);}
template<> float4_t __divide<float4_t>  (float4_t a, float4_t b) { return f4_div(a,b);}
template<> float4_t __subtract<float4_t>(float4_t a, float4_t b) { return f4_sub(a,b);}

#define op_generic(name) \
    Atom op_##name(AvmCore* core, Atom lhs, Atom rhs)\
    {\
        tagprof("op_##name val1", lhs);\
        tagprof("op_##name val2", rhs);\
        \
        if (atomIsBothIntptr(lhs,rhs))\
        {\
            double res = __##name( INTPTRASDOUBLE(lhs), INTPTRASDOUBLE(rhs));\
            intptr_t res_int = intptr_t(res);\
            if( atomIsValidIntptrValue(res_int) && res==(double)res_int)\
                return (res_int << 3) | kIntptrType;\
        }\
        \
        lhs = AvmCore::primitive(lhs); \
        rhs = AvmCore::primitive(rhs); \
        \
       if(AvmCore::isFloat4(lhs) || AvmCore::isFloat4(rhs)){\
           return core->float4ToAtom( __##name( AvmCore::float4(lhs), AvmCore::float4(rhs)) );\
        }\
        if(AvmCore::isFloat(lhs) && AvmCore::isFloat(rhs))\
            return core->floatToAtom( __##name(AvmCore::atomToFloat(lhs),AvmCore::atomToFloat(rhs)));\
        else\
            return core->doubleToAtom(__##name( AvmCore::number(lhs), AvmCore::number(rhs)) );\
    }

op_generic(divide);
op_generic(subtract);
op_generic(multiply);
op_generic(modulo);

Atom op_negate(AvmCore* core, Atom val) {
    tagprof("op_negate val1", val);
    val = AvmCore::primitive(val); // slow, but let's get over this...
        
    if(AvmCore::isFloat(val)){
        return core->floatToAtom(-AvmCore::atomToFloat(val));
    }

    if(AvmCore::isFloat4(val)){
        const static float4_t Zero = {-0.0, -0.0, -0.0, -0.0};
        return core->float4ToAtom( f4_sub(Zero, AvmCore::float4(val)) );
    
    }
    if(atomIsIntptr(val)){
        double res = - INTPTRASDOUBLE(val);
        intptr_t res_int = intptr_t(res);
        if( atomIsValidIntptrValue(res_int) && res == (double)res_int)
            return (res_int << 3) | kIntptrType;
    }

    return core->doubleToAtom( - AvmCore::number(val) );
}
#endif

#ifdef VMCFG_FLOAT
template<bool float_enabled> Atom op_add_impl(AvmCore* core, Atom lhs, Atom rhs)
#else
Atom op_add(AvmCore* core, Atom lhs, Atom rhs)
#endif // VMCFG_FLOAT
{
    tagprof("op_add val1", lhs);
    tagprof("op_add val2", rhs);

#ifdef AVMPLUS_64BIT
// since 64-bit int atoms expect exactly 53 bits of precision, we want to shift bit 53+3 up into the sign bit and back down
#  define SIGN_EXTEND(v)       ((intptr_t(v) << 8) >> 8)
#else
#  define SIGN_EXTEND(v)       (intptr_t(v))
#endif

    // integer optimization based on the one from Interpreter.cpp, modified
    // to reduce the # of alu instructions
    if (atomIsBothIntptr(lhs,rhs))
    {
        // Subtract off one of the type tags so result will be properly tagged.
        // Sign-extend 53-bit intptr value on 64-bit platforms.
        intptr_t const sum = SIGN_EXTEND(lhs + rhs - kIntptrType);
        // No overflow occurs if the signs of the arguments are different,
        // or if the sign of the result matches that of the arguments.
        // Rather than isolating the sign bits by masking off the others, we exploit
        // the fact that the comparisons with zero implicitly ignore the other bits.
        if ((lhs ^ rhs) < 0 || (lhs ^ sum) >= 0) {
            // No overflow, sum is correctly tagged atom
            return sum;
        }
        // Both integers, but overflow happens.  Intentionally add these
        // without casting to int32_t.  If the sum of the shifted values overflow,
        // we know the unshifted values will not overflow with a word-sized add.
        return core->allocDouble(double(atomGetIntptr(lhs) + atomGetIntptr(rhs)));
    }

    if (AvmCore::isNumeric(lhs) && AvmCore::isNumeric(rhs))
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
        XMLListObject *l = XMLListObject::create(core->GetGC(), atomObj(lhs)->toplevel()->xmlListClass());
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

#ifdef VMCFG_FLOAT
    // if both are floats, the addition is done on float; if any is float4, addition is done on float4
    if(float_enabled)
    {
        if(AvmCore::isFloat4(lhs) || AvmCore::isFloat4(rhs))
            return core->float4ToAtom( f4_add( AvmCore::float4(lhs), AvmCore::float4(rhs)) );
        if(AvmCore::isFloat(lhs) && AvmCore::isFloat(rhs))
            return core->floatToAtom(AvmCore::singlePrecisionFloat(lhs) + AvmCore::singlePrecisionFloat(rhs));
    }
#endif 
    return core->doubleToAtom(AvmCore::number(lhs) + AvmCore::number(rhs));
}

#ifdef VMCFG_FLOAT
Atom op_add(AvmCore* core, Atom lhs, Atom rhs)
{
   return op_add_impl<true>(core, lhs, rhs);
}

Atom op_add_nofloat(AvmCore* core, Atom lhs, Atom rhs)
{
   return op_add_impl<false>( core, lhs, rhs);
}
#endif // VMCFG_FLOAT


#ifdef VMCFG_FASTPATH_ADD

// Auxilliary predicate for assertions.
// Return true if result of adding lhs and rhs will require
// a kDoubleType atom instead of a kIntptrType atom.
#if defined(VMCFG_FASTPATH_ADD_INLINE) && defined(DEBUG)
static bool addIntptrOverflow(intptr_t lhs, intptr_t rhs)
{
    intptr_t const sum = lhs + rhs;
    if ((lhs ^ rhs) < 0 || (lhs ^ sum) >= 0) {
        // add overflowed, numerical result will not fit in intptr_t
        return true;
    }
    // verify that tagged result will not fit in kIntptrType
    intptr_t const extended = SIGN_EXTEND(sum << kAtomTypeSize) >> kAtomTypeSize;
    return (sum == extended);
}
#endif

// Specialized helper functions called by code generated for the OP_add instruction.
// These take into account operands with known specific types and invariants previously
// established by inline code.

// atom + atom => atom
#ifdef VMCFG_FLOAT
template<bool float_support> Atom op_add_a_aa_impl(AvmCore* core, Atom lhs, Atom rhs)
#else
Atom op_add_a_aa(AvmCore* core, Atom lhs, Atom rhs)
#endif // VMCFG_FLOAT
{
#ifndef VMCFG_FASTPATH_ADD_INLINE
    // Fastpath for intptr+intptr
    if (atomIsBothIntptr(lhs, rhs))
    {
        intptr_t const sum = SIGN_EXTEND(lhs + rhs - kIntptrType);
        if ((lhs ^ rhs) < 0 || (lhs ^ sum) >= 0) {
            // No overflow, sum is correctly tagged atom
            return sum;
        }
        // Overflow, allocate heap double
        return core->allocDouble(double(atomGetIntptr(lhs) + atomGetIntptr(rhs)));
    }
#else
    // Inline code should handle intptr+intptr case, except where result must be double.
    AvmAssert(!atomIsBothIntptr(lhs, rhs) || addIntptrOverflow(atomGetIntptr(lhs), atomGetIntptr(rhs)));
#endif

    if (atomIsIntptr(lhs))
    {
        if (AvmCore::isDouble(rhs))
        {
            return core->doubleToAtom(double(atomGetIntptr(lhs)) + AvmCore::atomToDouble(rhs));
        }
        else if (atomIsIntptr(rhs))
        {
            // We should arrive here only on overflow in inline fastpath.
            return core->doubleToAtom(double(atomGetIntptr(lhs) + double(atomGetIntptr(rhs))));
        }
    }
    else if (AvmCore::isDouble(lhs))
    {
        if (atomIsIntptr(rhs))
        {
            return core->doubleToAtom(AvmCore::atomToDouble(lhs) + double(atomGetIntptr(rhs)));
        }
        else if (AvmCore::isDouble(rhs))
        {
            return core->doubleToAtom(AvmCore::atomToDouble(lhs) + AvmCore::atomToDouble(rhs));
        }
    }

    if (AvmCore::isString(lhs))
    {
        if (AvmCore::isString(rhs))
        {
            // AvmCore::concatStrings() coerces a null argument to the string "null".
            // Here, we know that neither lhs nor rhs are null, so we can concatenate w/o the coercion.
            return String::concatStrings(AvmCore::atomToString(lhs),
                                         AvmCore::atomToString(rhs))->atom();
        }
        else
        {
            goto concat_strings;
        }
    }
    else if (AvmCore::isDate(lhs) || AvmCore::isDate(rhs))
    {
        goto concat_strings;
    }

    if (AvmCore::isXMLorXMLList(lhs) && AvmCore::isXMLorXMLList(rhs))
    {
        XMLListObject *l = XMLListObject::create(core->GetGC(), atomObj(lhs)->toplevel()->xmlListClass());
        l->_append(lhs);
        l->_append(rhs);
        return l->atom();
    }

    lhs = AvmCore::primitive(lhs);
    rhs = AvmCore::primitive(rhs);

    if (!(AvmCore::isString(lhs) || AvmCore::isString(rhs)))
    {
#ifdef VMCFG_FLOAT
        if(float_support){
            if(AvmCore::isFloat4(lhs) || AvmCore::isFloat4(rhs))
                return core->float4ToAtom( f4_add( AvmCore::float4(lhs), AvmCore::float4(rhs)) );
            if(AvmCore::isFloat(lhs) && AvmCore::isFloat(rhs))
                return core->floatToAtom(AvmCore::atomToFloat(lhs) + AvmCore::atomToFloat(rhs));
        }
#endif
        return core->doubleToAtom(AvmCore::number(lhs) + AvmCore::number(rhs));
    }

concat_strings:
    return core->concatStrings(core->string(lhs), core->string(rhs))->atom();
}

// atom + int => atom
#ifdef VMCFG_FLOAT
template<bool float_support> Atom op_add_a_ai_impl(AvmCore* core, Atom lhs, int32_t rhs)
#else
Atom op_add_a_ai(AvmCore* core, Atom lhs, int32_t rhs)
#endif // VMCFG_FLOAT
{
    if (atomIsIntptr(lhs))
    {
#ifndef VMCFG_FASTPATH_ADD_INLINE
    // Fastpath for intptr+int with no overflow
    #ifdef AVMPLUS_64BIT
        // A 32-bit integer is guaranteed convertible to an atom of type kIntptrType.
        intptr_t lhsv = lhs;
        intptr_t rhsv = intptr_t(rhs) << AtomConstants::kAtomTypeSize;
        intptr_t const sum = SIGN_EXTEND(lhsv + rhsv);
        if ((lhsv ^ rhsv) < 0 || (lhsv ^ sum) >= 0) {
            // No overflow, sum is correctly tagged atom
            return sum;
        }
    #else
        intptr_t const lhsv = atomGetIntptr(lhs);
        intptr_t const rhsv = rhs;
        intptr_t const sum = lhsv + rhsv;
        if ((lhsv ^ rhsv) < 0 || (lhsv ^ sum) >= 0) {
            // No overflow
            if (atomIsValidIntptrValue(sum))
                return atomFromIntptrValue(sum);
            else
                return core->allocDouble(double(sum));
        }
    #endif
#else
        // Inline code should handle intptr+int case, except where result must be double.
        // It is allowable for the inline code to punt if the 32-bit int argument is itself too large for an intptr.
        AvmAssert(!atomIsValidIntptrValue(rhs) || addIntptrOverflow(atomGetIntptr(lhs), rhs));
#endif
        return core->doubleToAtom(double(atomGetIntptr(lhs)) + double(rhs));
    }
    else if (AvmCore::isDouble(lhs))
    {
        return core->doubleToAtom(AvmCore::atomToDouble(lhs) + double(rhs));
    } 

    if (AvmCore::isString(lhs) || AvmCore::isDate(lhs)) goto concat_strings;

    lhs = AvmCore::primitive(lhs);

    if (!AvmCore::isString(lhs))
    {
#ifdef VMCFG_FLOAT
        if(float_support && AvmCore::isFloat4(lhs)) {
            float4_t op2 = {(float)rhs, (float)rhs, (float)rhs, (float)rhs};
            return core->float4ToAtom( f4_add( AvmCore::atomToFloat4(lhs), op2) );
        }
#endif // VMCFG_FLOAT
        return core->doubleToAtom(AvmCore::number(lhs) + double(rhs));
    }

 concat_strings:
    // See AvmCore::string()
    Stringp s = MathUtils::convertIntegerToStringBase10(core, rhs, MathUtils::kTreatAsSigned);
    return core->concatStrings(core->string(lhs), s)->atom();
}

// int + atom => atom
#ifdef VMCFG_FLOAT
template<bool float_support> Atom op_add_a_ia_impl(AvmCore* core, int32_t lhs, Atom rhs)
#else
Atom op_add_a_ia(AvmCore* core, int32_t lhs, Atom rhs)
#endif // VMCFG_FLOAT
{
    if (atomIsIntptr(rhs))
    {
#ifndef VMCFG_FASTPATH_ADD_INLINE
    // Fastpath for int+intptr with no overflow
    #ifdef AVMPLUS_64BIT
        // A 32-bit integer is guaranteed convertible to an atom of type kIntptrType.
        intptr_t lhsv = intptr_t(lhs) << AtomConstants::kAtomTypeSize;
        intptr_t rhsv = rhs;
        intptr_t const sum = SIGN_EXTEND(lhsv + rhsv);
        if ((lhsv ^ rhsv) < 0 || (lhsv ^ sum) >= 0) {
            // No overflow, sum is correctly tagged atom
            return sum;
        }
    #else
        intptr_t const lhsv = lhs;
        intptr_t const rhsv = atomGetIntptr(rhs);
        intptr_t const sum = lhsv + rhsv;
        if ((lhsv ^ rhsv) < 0 || (lhsv ^ sum) >= 0) {
            // No overflow
            if (atomIsValidIntptrValue(sum))
                return atomFromIntptrValue(sum);
            else
                return core->allocDouble(double(sum));
        }
    #endif
#else
        // Inline code should handle int+intptr case, except where result must be double.
        // It is allowable for the inline code to punt if the 32-bit int argument is itself too large for an intptr.
        AvmAssert(!atomIsValidIntptrValue(lhs) || addIntptrOverflow(lhs, atomGetIntptr(rhs)));
#endif
        return core->doubleToAtom(double(lhs) + double(atomGetIntptr(rhs)));
    }
    else if (AvmCore::isDouble(rhs))
    {
        return core->doubleToAtom(double(lhs) + AvmCore::atomToDouble(rhs));
    }

    if (AvmCore::isString(rhs) || AvmCore::isDate(rhs)) goto concat_strings;

    rhs = AvmCore::primitive(rhs);

    if (!AvmCore::isString(rhs))
    {
#ifdef VMCFG_FLOAT
        if( float_support && AvmCore::isFloat4(rhs)) {
            float4_t op1 = {(float)lhs, (float)lhs, (float)lhs, (float)lhs};
            return core->float4ToAtom( f4_add( op1, AvmCore::atomToFloat4(rhs)) );
        }
#endif
        return core->doubleToAtom(double(lhs) + AvmCore::number(rhs));
    }

concat_strings:
    // See AvmCore::string()
    Stringp s = MathUtils::convertIntegerToStringBase10(core, lhs, MathUtils::kTreatAsSigned);
    return core->concatStrings(s, core->string(rhs))->atom();
}

// atom + double => atom
#ifdef VMCFG_FLOAT
template<bool float_support> Atom op_add_a_ad_impl(AvmCore* core, Atom lhs, double rhs)
#else
Atom op_add_a_ad(AvmCore* core, Atom lhs, double rhs)
#endif // VMCFG_FLOAT
{
    if (AvmCore::isDouble(lhs))
    {
        return core->doubleToAtom(AvmCore::atomToDouble(lhs) + rhs);
    }
    else if (atomIsIntptr(lhs))
    {
        return core->doubleToAtom(double(atomGetIntptr(lhs)) + rhs);
    }

    if (AvmCore::isString(lhs) || AvmCore::isDate(lhs)) goto concat_strings;

    lhs = AvmCore::primitive(lhs);

    if (!AvmCore::isString(lhs))
    {
#ifdef VMCFG_FLOAT
        if(float_support && AvmCore::isFloat4(lhs)) {
            float4_t op2 = {(float)rhs, (float)rhs, (float)rhs, (float)rhs};
            return core->float4ToAtom( f4_add( AvmCore::atomToFloat4(lhs), op2) );
        }
#endif // VMCFG_FLOAT
        return core->doubleToAtom(AvmCore::number(lhs) + rhs);
    }

concat_strings:
    // See AvmCore::string()
    Stringp s = core->doubleToString(rhs);
    return core->concatStrings(core->string(lhs), s)->atom();
}

// double + atom => atom
#ifdef VMCFG_FLOAT
template<bool float_support> Atom op_add_a_da_impl(AvmCore* core, double lhs, Atom rhs)
#else
Atom op_add_a_da(AvmCore* core, double lhs, Atom rhs)
#endif
{
    if (AvmCore::isDouble(rhs))
    {
        return core->doubleToAtom(lhs + AvmCore::atomToDouble(rhs));
    }
    else if (atomIsIntptr(rhs))
    {
        return core->doubleToAtom(lhs + double(atomGetIntptr(rhs)));
    }

    if (AvmCore::isString(rhs) || AvmCore::isDate(rhs)) goto concat_strings;

    rhs = AvmCore::primitive(rhs);

    if (!AvmCore::isString(rhs))
    {
#ifdef VMCFG_FLOAT
        if(float_support && AvmCore::isFloat4(rhs)) {
            float4_t op1 = {(float)lhs, (float)lhs, (float)lhs, (float)lhs};
            return core->float4ToAtom( f4_add( op1, AvmCore::atomToFloat4(rhs)) );
        }
#endif // VMCFG_FLOAT
        return core->doubleToAtom(lhs + AvmCore::number(rhs));
    }

concat_strings:
    // See AvmCore::string()
    Stringp s = core->doubleToString(lhs);
    return core->concatStrings(s, core->string(rhs))->atom();
}


#ifdef VMCFG_FLOAT
Atom op_add_a_aa(AvmCore* core, Atom lhs, Atom rhs){
    return op_add_a_aa_impl<true>(core, lhs, rhs);
}
Atom op_add_a_aa_nofloat(AvmCore* core, Atom lhs, Atom rhs){
    return op_add_a_aa_impl<false>(core, lhs, rhs);                     
}
Atom op_add_a_ai(AvmCore* core, Atom lhs, int32_t rhs){
    return op_add_a_ai_impl<true>(core, lhs, rhs);
}
Atom op_add_a_ai_nofloat(AvmCore* core, Atom lhs, int32_t rhs){
    return op_add_a_ai_impl<false>(core, lhs, rhs);                     
}
Atom op_add_a_ia(AvmCore* core, int32_t lhs, Atom rhs){
    return op_add_a_ia_impl<true>(core, lhs, rhs);
}
Atom op_add_a_ia_nofloat(AvmCore* core, int32_t lhs, Atom rhs){
    return op_add_a_ia_impl<false>(core, lhs, rhs);                     
}
Atom op_add_a_ad(AvmCore* core, Atom lhs, double rhs){
    return op_add_a_ad_impl<true>(core, lhs, rhs);
}
Atom op_add_a_ad_nofloat(AvmCore* core, Atom lhs, double rhs){
    return op_add_a_ad_impl<false>(core, lhs, rhs);                     
}
Atom op_add_a_da(AvmCore* core, double lhs, Atom rhs){
    return op_add_a_da_impl<true>(core, lhs, rhs);
}
Atom op_add_a_da_nofloat(AvmCore* core, double lhs, Atom rhs){
    return op_add_a_da_impl<false>(core, lhs, rhs);                     
}
#endif /* VMCFG_FLOAT */

#endif /* VMCFG_FASTPATH_ADD */

void FASTCALL mop_rangeCheckFailed(MethodEnv* env)
{
    env->toplevel()->throwRangeError(kInvalidRangeError);
}

// note: all of the mop_xxx load/store functions assume
// that the caller has done range checking, and the address
// is safe for its intended use...
int32_t FASTCALL mop_lix8(const void* addr)
{
    // loads a signed byte, sign-extends
    return *(const int8_t*)(addr);
}

int32_t FASTCALL mop_liz8(const void* addr)
{
    // loads an unsigned byte, zero-extends
    return *(const uint8_t*)(addr);
}

int32_t FASTCALL mop_lix16(const void* addr)
{
    // loads an signed short, sign-extends
#if defined(VMCFG_UNALIGNED_INT_ACCESS) && defined(VMCFG_LITTLE_ENDIAN)
    return *(const int16_t*)(addr);
#else
    const uint8_t* u = (const uint8_t*)addr;
    return int16_t((uint16_t(u[1]) << 8) | uint16_t(u[0]));
#endif
}

int32_t FASTCALL mop_liz16(const void* addr)
{
    // loads an unsigned short, zero-extends
#if defined(VMCFG_UNALIGNED_INT_ACCESS) && defined(VMCFG_LITTLE_ENDIAN)
    return *(const uint16_t*)(addr);
#else
    const uint8_t* u = (const uint8_t*)addr;
    return (uint16_t(u[1]) << 8) |
            uint16_t(u[0]);
#endif
}

int32_t FASTCALL mop_li32(const void* addr)
{
#if defined(VMCFG_UNALIGNED_INT_ACCESS) && defined(VMCFG_LITTLE_ENDIAN)
    return *(const int32_t*)(addr);
#else
    const uint8_t* u = (const uint8_t*)addr;
    return (uint32_t(u[3]) << 24) |
           (uint32_t(u[2]) << 16) |
           (uint32_t(u[1]) << 8) |
           uint32_t(u[0]);
#endif
}

double FASTCALL mop_lf32(const void* addr)
{
#if defined(VMCFG_UNALIGNED_FP_ACCESS) && defined(VMCFG_LITTLE_ENDIAN)
    return *(const float*)(addr);
#else
    union {
        uint32_t a;
        float b;
    };
    const uint8_t* u = (const uint8_t*)addr;

    // Bugzilla 569691: Do not try to be clever here by loading from
    // '*(uint32_t*)u' into 'a', even if both VMCFG_UNALIGNED_INT_ACCESS and
    // VMCFG_LITTLE_ENDIAN are set - gcc may emit code that loads directly
    // from the ARM VFP register, and that requires VMCFG_UNALIGNED_FP_ACCESS.

    a = (uint32_t(u[3]) << 24) |
        (uint32_t(u[2]) << 16) |
        (uint32_t(u[1]) << 8) |
        uint32_t(u[0]);

    return b;
#endif
}

double FASTCALL mop_lf64(const void* addr)
{
#if defined(VMCFG_UNALIGNED_FP_ACCESS) && defined(VMCFG_LITTLE_ENDIAN)
    return *(const double*)(addr);
#else
    // The layout in memory is little-endian with the least significant
    // word first.
    const uint8_t* u = (const uint8_t*)addr;
    double_overlay d;

    // Bugzilla 685441: Do not copy 32-bit blocks here for some ARM platforms
    // to avoid unaligned memory access, even though VMCFG_UNALIGNED_INT_ACCESS
    // is turned on.
    d.words.lsw = ((uint64_t(u[3]) << 24) |
                   (uint64_t(u[2]) << 16) |
                   (uint64_t(u[1]) << 8) |
                   (uint64_t(u[0])));
    d.words.msw = ((uint32_t(u[7]) << 24) |
                   (uint32_t(u[6]) << 16) |
                   (uint32_t(u[5]) << 8) |
                   (uint32_t(u[4])));
    return d.value;
#endif
}

void FASTCALL mop_si8(void* addr, int32_t value)
{
    *(uint8_t*)(addr) = uint8_t(value);
}

void FASTCALL mop_si16(void* addr, int32_t value)
{
#if defined(VMCFG_UNALIGNED_INT_ACCESS) && defined(VMCFG_LITTLE_ENDIAN)
    *(uint16_t*)(addr) = uint16_t(value);
#else
    uint8_t* u = (uint8_t*)addr;
    u[0] = uint8_t(value);
    u[1] = uint8_t(value >> 8);
#endif
}

void FASTCALL mop_si32(void* addr, int32_t value)
{
#if defined(VMCFG_UNALIGNED_INT_ACCESS) && defined(VMCFG_LITTLE_ENDIAN)
    *(int32_t*)(addr) = int32_t(value);
#else
    uint8_t* u = (uint8_t*)addr;
    u[0] = uint8_t(value);
    u[1] = uint8_t(value >> 8);
    u[2] = uint8_t(value >> 16);
    u[3] = uint8_t(value >> 24);
#endif
}

void mop_sf32(void* addr, double value)
{
#if defined(VMCFG_UNALIGNED_FP_ACCESS) && defined(VMCFG_LITTLE_ENDIAN)
    *(float*)(addr) = float(value);
#else
    union {
        float a;
        uint32_t b;
    };
    a = float(value);
    uint8_t* u = (uint8_t*)addr;

    // Bugzilla 569691: Do not try to be clever here by storing from 'b' into
    // '*(uint32_t*)u', even if both VMCFG_UNALIGNED_INT_ACCESS and
    // VMCFG_LITTLE_ENDIAN are set - gcc will emit code that stores directly
    // from the ARM VFP register, and that requires VMCFG_UNALIGNED_FP_ACCESS.

    u[0] = uint8_t(b);
    u[1] = uint8_t(b >> 8);
    u[2] = uint8_t(b >> 16);
    u[3] = uint8_t(b >> 24);
#endif
}

void mop_sf64(void* addr, double value)
{
#if defined(VMCFG_UNALIGNED_FP_ACCESS) && defined(VMCFG_LITTLE_ENDIAN)
    *(double*)(addr) = value;
#else
    double_overlay d(value);
    uint8_t* u = (uint8_t*)addr;

    // Bugzilla 685441: Do not copy 32-bit blocks here for some ARM platforms
    // to avoid unaligned memory access, even though VMCFG_UNALIGNED_INT_ACCESS
    // is turned on.
    u[0] = uint8_t(d.words.lsw);
    u[1] = uint8_t(d.words.lsw >> 8);
    u[2] = uint8_t(d.words.lsw >> 16);
    u[3] = uint8_t(d.words.lsw >> 24);
    u[4] = uint8_t(d.words.msw);
    u[5] = uint8_t(d.words.msw >> 8);
    u[6] = uint8_t(d.words.msw >> 16);
    u[7] = uint8_t(d.words.msw >> 24);
#endif
}

} // namespace avmplus
