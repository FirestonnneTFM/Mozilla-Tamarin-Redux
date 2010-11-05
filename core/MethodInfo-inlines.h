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
 * Portions created by the Initial Developer are Copyright (C) 2009
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

namespace avmplus
{

REALLY_INLINE ScopeOrTraits::ScopeOrTraits(Traits* t) : _scopeOrTraits((uintptr_t)t)
{
}

REALLY_INLINE bool ScopeOrTraits::hasScope() const
{
    return (_scopeOrTraits & IS_SCOPE) != 0;
}

REALLY_INLINE Traits* ScopeOrTraits::getTraits() const
{
    if (!hasScope())
        return (Traits*)(_scopeOrTraits);

    const ScopeTypeChain* sc = (const ScopeTypeChain*)(_scopeOrTraits & ~IS_SCOPE);
    return sc ? sc->traits() : NULL;
}

REALLY_INLINE const ScopeTypeChain* ScopeOrTraits::getScope() const
{
    if (!hasScope())
        return _scopeOrTraits ? ((Traits*)(_scopeOrTraits))->declaringScope() : NULL;

    return ((const ScopeTypeChain*)(_scopeOrTraits & ~IS_SCOPE));
}

REALLY_INLINE void ScopeOrTraits::setTraits(MMgc::GC* gc, void* container, Traits* t)
{
    WB(gc, container, &_scopeOrTraits, uintptr_t(t));
}


REALLY_INLINE void ScopeOrTraits::setScope(MMgc::GC* gc, void* container, const ScopeTypeChain* s)
{
    WB(gc, container, &_scopeOrTraits, uintptr_t(s) | IS_SCOPE);
}

#ifdef DEBUGGER
REALLY_INLINE DebuggerMethodInfo::DebuggerMethodInfo(int32_t _local_count, uint32_t _codeSize, int32_t _max_scopes) :
    firstSourceLine(0),
    lastSourceLine(0),
    offsetInAbc(0),
    codeSize(_codeSize),
    local_count(_local_count),
    max_scopes(_max_scopes)
{}
#endif

REALLY_INLINE uint32_t MethodInfo::hasExceptions() const
{
    return _hasExceptions;
}

REALLY_INLINE uint32_t MethodInfo::hasMethodBody() const
{
    return _hasMethodBody;
}

REALLY_INLINE uint32_t MethodInfo::hasOptional() const
{
    return _hasOptional;
}

REALLY_INLINE uint32_t MethodInfo::isNative() const
{
    return _isNative;
}

REALLY_INLINE uint32_t MethodInfo::isNonInterruptible()
{
    return _isNonInterruptible;
}

REALLY_INLINE uint32_t MethodInfo::isResolved() const
{
    return _isResolved;
}

REALLY_INLINE uint32_t MethodInfo::needActivation() const
{
    return _needActivation;
}

REALLY_INLINE uint32_t MethodInfo::needArguments() const
{
    return _needArguments;
}

REALLY_INLINE uint32_t MethodInfo::needClosure() const
{
    return _needClosure;
}

REALLY_INLINE uint32_t MethodInfo::needRest() const
{
    return _needRest;
}

// This can be called only during pass2 of verification or later, as the attribute
// is computed during pass1 of verification.

REALLY_INLINE uint32_t MethodInfo::lazyRest() const
{
    AvmAssert(needRestOrArguments());
    return _lazyRest;
}

REALLY_INLINE uint32_t MethodInfo::onlyUntypedParameters() const
{
    return _onlyUntypedParameters;
}

REALLY_INLINE uint32_t MethodInfo::needRestOrArguments() const
{
    return _needRest || _needArguments;
}

REALLY_INLINE uint32_t MethodInfo::isFinal() const
{
    return _isFinal;
}

REALLY_INLINE uint32_t MethodInfo::setsDxns() const
{
    return _setsDxns;
}

REALLY_INLINE uint32_t MethodInfo::isStaticInit() const
{
    return _isStaticInit;
}

REALLY_INLINE uint32_t MethodInfo::unboxThis() const
{
    return _unboxThis;
}

REALLY_INLINE void MethodInfo::setUnboxThis()
{
    _unboxThis = 1;
}

REALLY_INLINE void MethodInfo::setStaticInit()
{
    _isStaticInit = 1;
}

REALLY_INLINE void MethodInfo::setHasExceptions()
{
    _hasExceptions = 1;
}

REALLY_INLINE void MethodInfo::setLazyRest()
{
    _lazyRest = 1;
}

REALLY_INLINE void MethodInfo::setNeedsDxns()
{
    _needsDxns = 1;
}

REALLY_INLINE void MethodInfo::setFinal()
{
    _isFinal = 1;
}

REALLY_INLINE void MethodInfo::setOverride()
{
    _isOverride = 1;
}

REALLY_INLINE void MethodInfo::makeNonInterruptible()
{
    _isNonInterruptible = 1;
}

REALLY_INLINE void MethodInfo::setKind(TraitKind kind)
{
    if (kind == TRAIT_Getter)
        _isGetter = 1;
    else if (kind == TRAIT_Setter)
        _isSetter = 1;
}

REALLY_INLINE uint32_t MethodInfo::isInterpreted() const
{
    return _isInterpImpl;
}

#ifdef VMCFG_AOT
REALLY_INLINE uint32_t MethodInfo::isAotCompiled() const
{
    return _isAotCompiled;
}

REALLY_INLINE void MethodInfo::setAotCompiled()
{
    _isAotCompiled = 1;
    _isNative = 1;
    _hasMethodBody = 0;
}
#endif

REALLY_INLINE PoolObject* MethodInfo::pool() const
{
    return _pool;
}

#ifdef VMCFG_INDIRECT_NATIVE_THUNKS
REALLY_INLINE AvmThunkNativeMethodHandler MethodInfo::handler_method() const
{
    AvmAssert(isNative());
    return _native.handler.method;
}

REALLY_INLINE AvmThunkNativeFunctionHandler MethodInfo::handler_function() const
{
    AvmAssert(isNative());
    return _native.handler.function;
}
#endif

REALLY_INLINE const uint8_t* MethodInfo::abc_body_pos() const
{
    AvmAssert(!isNative());
    return _abc.body_pos;
}

REALLY_INLINE void MethodInfo::set_abc_body_pos(const uint8_t* p)
{
    AvmAssert(!isNative());
    _abc.body_pos = p;
}

REALLY_INLINE ExceptionHandlerTable* MethodInfo::abc_exceptions() const
{
#ifdef VMCFG_AOT
    AvmAssert(!isNative()||isAotCompiled());
#else
    AvmAssert(!isNative());
#endif
    return _abc.exceptions;
}

REALLY_INLINE void MethodInfo::set_abc_exceptions(MMgc::GC* gc, ExceptionHandlerTable* e)
{
    AvmAssert(!isNative());
    WB(gc, this, &_abc.exceptions, e);
}

#ifdef VMCFG_WORDCODE

REALLY_INLINE ExceptionHandlerTable* MethodInfo::word_code_exceptions() const
{
    AvmAssert(!isNative());
    return _abc.word_code.exceptions;
}

REALLY_INLINE void MethodInfo::set_word_code_exceptions(MMgc::GC* gc, ExceptionHandlerTable* e)
{
    AvmAssert(!isNative());
    WB(gc, this, &_abc.word_code.exceptions, e);
}

REALLY_INLINE const uintptr_t* MethodInfo::word_code_start() const
{
    AvmAssert(!isNative());
    return _abc.word_code.translated_code->data;
}

REALLY_INLINE void MethodInfo::set_word_code(MMgc::GC* gc, TranslatedCode* translated_code)
{
    AvmAssert(!isNative());
    WB(gc, this, &_abc.word_code.translated_code, translated_code);
}
#endif // VMCFG_WORDCODE

#ifdef VMCFG_LOOKUP_CACHE
REALLY_INLINE int32_t MethodInfo::lookup_cache_size() const
{
    AvmAssert(!isNative());
    return _abc.lookup_cache_size;
}

REALLY_INLINE void MethodInfo::set_lookup_cache_size(int32_t s)
{
    AvmAssert(!isNative());
    _abc.lookup_cache_size = s;
}
#endif

REALLY_INLINE int32_t MethodInfo::method_id() const
{
    return _method_id;
}

REALLY_INLINE Traits* MethodInfo::declaringTraits() const
{
    return _declarer.getTraits();
}

REALLY_INLINE const ScopeTypeChain* MethodInfo::declaringScope() const
{
    return _declarer.getScope();
}

REALLY_INLINE Traits* MethodInfo::activationTraits() const
{
    return _activation.getTraits();
}

REALLY_INLINE const ScopeTypeChain* MethodInfo::activationScope() const
{
    return _activation.getScope();
}


REALLY_INLINE MethodSignaturep MethodInfo::getMethodSignature()
{
    AvmAssert(isResolved());
    AvmAssert(_msref != NULL);
    MethodSignaturep ms;
    if ((ms = (MethodSignaturep)_msref->get()) == NULL)
        ms = _getMethodSignature();
    return ms;
}

REALLY_INLINE Traits* MethodSignature::returnTraits() const
{
    return _returnTraits;
}

REALLY_INLINE BuiltinType MethodSignature::returnTraitsBT() const
{
    return Traits::getBuiltinType(_returnTraits);
}

REALLY_INLINE int32_t MethodSignature::param_count() const
{
    return _param_count;
}

REALLY_INLINE int32_t MethodSignature::optional_count() const
{
    return _optional_count;
}

REALLY_INLINE int32_t MethodSignature::rest_offset() const
{
    return _rest_offset;
}

REALLY_INLINE int32_t MethodSignature::max_stack() const
{
    AvmAssert(!_isNative);
    return _max_stack;
}

REALLY_INLINE int32_t MethodSignature::local_count() const
{
    AvmAssert(!_isNative);
    return _local_count;
}

REALLY_INLINE int32_t MethodSignature::max_scope() const
{
    AvmAssert(!_isNative);
    return _max_scope;
}

REALLY_INLINE int32_t MethodSignature::frame_size() const
{
    AvmAssert(!_isNative);
    return _frame_size;
}

REALLY_INLINE int32_t MethodSignature::stack_base() const
{
    AvmAssert(!_isNative);
    return _local_count + _max_scope;
}

REALLY_INLINE int32_t MethodSignature::scope_base() const
{
    AvmAssert(!_isNative);
    return _local_count;
}

#ifdef VMCFG_WORDCODE
#else
REALLY_INLINE const uint8_t* MethodSignature::abc_code_start() const
{
    return _abc_code_start;
}
#endif

REALLY_INLINE bool MethodSignature::allowExtraArgs() const
{
    return _allowExtraArgs;
}

REALLY_INLINE int32_t MethodSignature::requiredParamCount() const
{
    return _param_count - _optional_count;
}

REALLY_INLINE Traits* MethodSignature::paramTraits(int32_t i) const
{
    AvmAssert(i >= 0 && i <= _param_count);
    return _args[i].paramType;
}

REALLY_INLINE BuiltinType MethodSignature::paramTraitsBT(int32_t i) const
{
    AvmAssert(i >= 0 && i <= _param_count);
    return Traits::getBuiltinType(_args[i].paramType);
}

REALLY_INLINE Atom MethodSignature::getDefaultValue(int32_t i) const
{
    AvmAssert(i >= 0 && i < _optional_count);
    return _args[i+_param_count+1].defaultValue;
}

REALLY_INLINE bool MethodSignature::argcOk(int32_t argc) const
{
    AvmAssert(argc >= 0);
    AvmAssert(_param_count >= _optional_count);
    // The explicit cast to uint32_t is to avoid a compiler warning (GCC 4.4+): 
    // "assuming signed overflow does not occur when assuming that (X + c) < X is always false"
    // (i.e., C compilers are allowed to assume that signed overflow never occurs).
    // In this case, we know that both values are nonnegative, and the result is >= 0, so the cast
    // is safe and simply dodges the warning.
    return uint32_t(argc) >= (uint32_t(_param_count) - uint32_t(_optional_count)) &&
            (argc <= _param_count || _allowExtraArgs);
}

} // namespace avmplus
