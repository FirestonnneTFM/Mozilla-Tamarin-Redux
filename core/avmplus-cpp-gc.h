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

/* machine generated file via utils/exactgc.as -- do not edit */

namespace avmplus
{
bool AbcEnv::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    if (_xact_cursor == 0) {
        gc->TraceLocation(&m_codeContext);
        gc->TraceLocation(&m_domainEnv);
#ifdef DEBUGGER
        gc->TraceLocation(&m_invocationCounts);
#endif
        m_namedScriptEnvsList.gcTrace(gc);
        gc->TraceLocation(&m_pool);
    }
    const size_t _xact_work_increment = 2000/sizeof(void*);
    const size_t _xact_work_count = m_pool->methodCount();
    if (_xact_cursor * _xact_work_increment >= _xact_work_count)
        return (_xact_cursor == 0);
    size_t _xact_work = _xact_work_increment;
    if ((_xact_cursor + 1) * _xact_work_increment >= _xact_work_count)
        _xact_work = _xact_work_count - (_xact_cursor * _xact_work_increment);
    gc->TraceLocations((m_methods+(_xact_cursor * _xact_work_increment)), _xact_work);
    return true;
}

void AbcEnv::gcTrace(MMgc::GC* gc)
{
    gcTraceSmallAsLarge(gc);
}

#ifdef DEBUGGER

void AbcFile::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    AbcInfo::gcTrace(gc);
    (void)(avmplus_AbcInfo_isExactInterlock != 0);
    source.gcTrace(gc);
    gc->TraceLocation(&sourcemap);
}

bool AbcFile::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

#endif // DEBUGGER

#ifdef DEBUGGER

void AbcInfo::gcTrace(MMgc::GC* gc)
{
    (void)gc;

}

bool AbcInfo::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

#endif // DEBUGGER

void AttributeE4XNode::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    E4XNode::gcTrace(gc);
    (void)(avmplus_E4XNode_isExactInterlock != 0);
    gc->TraceLocation(&m_value);
}

bool AttributeE4XNode::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void CDATAE4XNode::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    E4XNode::gcTrace(gc);
    (void)(avmplus_E4XNode_isExactInterlock != 0);
    gc->TraceLocation(&m_value);
}

bool CDATAE4XNode::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void CommentE4XNode::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    E4XNode::gcTrace(gc);
    (void)(avmplus_E4XNode_isExactInterlock != 0);
    gc->TraceLocation(&m_value);
}

bool CommentE4XNode::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

#ifdef DEBUGGER

void Debugger::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    abcList.gcTrace(gc);
    gc->TraceLocation(&trace_callback);
}

bool Debugger::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

#endif // DEBUGGER

#ifdef DEBUGGER

void DebuggerMethodInfo::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    gc->TraceLocation(&file);
    gc->TraceLocations((localNames+0), local_count);
}

bool DebuggerMethodInfo::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

#endif // DEBUGGER

void Domain::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    m_namedScriptsList.gcTrace(gc);
    gc->TraceLocation(&m_namedScriptsMap);
    gc->TraceLocation(&m_namedTraits);
    gc->TraceLocation(&m_parameterizedTypes);
    gc->TraceLocations((m_bases+0), m_baseCount);
}

bool Domain::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void DomainEnv::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    GlobalMemorySubscriber::gcTrace(gc);
    (void)(avmplus_GlobalMemorySubscriber_isExactInterlock != 0);
    gc->TraceLocation(&m_domain);
    gc->TraceLocation(&m_globalMemoryProviderObject);
    m_namedScriptEnvsList.gcTrace(gc);
    gc->TraceLocation(&m_toplevel);
    gc->TraceLocations((m_bases+0), m_baseCount);
}

bool DomainEnv::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void E4XNode::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    gc->TraceLocation(&m_nameOrAux);
    gc->TraceLocation(&m_parent);
}

bool E4XNode::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void E4XNodeAux::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    gc->TraceLocation(&m_name);
    gc->TraceLocation(&m_notification);
    gc->TraceLocation(&m_ns);
}

bool E4XNodeAux::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ElementE4XNode::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    E4XNode::gcTrace(gc);
    (void)(avmplus_E4XNode_isExactInterlock != 0);
    gc->TraceLocation(&m_attributes);
    gc->TraceLocation(&m_children);
    gc->TraceLocation(&m_namespaces);
}

bool ElementE4XNode::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

bool ExceptionHandlerTable::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    const size_t _xact_work_increment = 2000/sizeof(void*);
    const size_t _xact_work_count = exception_count;
    if (_xact_cursor * _xact_work_increment >= _xact_work_count)
        return (_xact_cursor == 0);
    size_t _xact_work = _xact_work_increment;
    if ((_xact_cursor + 1) * _xact_work_increment >= _xact_work_count)
        _xact_work = _xact_work_count - (_xact_cursor * _xact_work_increment);
    for ( size_t _xact_iter=0 ; _xact_iter < _xact_work; _xact_iter++ )
        exceptions[+_xact_iter+(_xact_cursor * _xact_work_increment)].gcTrace(gc);
    return true;
}

void ExceptionHandlerTable::gcTrace(MMgc::GC* gc)
{
    gcTraceSmallAsLarge(gc);
}

void FunctionEnv::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    MethodEnv::gcTrace(gc);
    (void)(avmplus_MethodEnv_isExactInterlock != 0);
    gc->TraceLocation(&closure);
}

bool FunctionEnv::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void GlobalMemorySubscriber::gcTrace(MMgc::GC* gc)
{
    (void)gc;

}

bool GlobalMemorySubscriber::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void HeapHashtable::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    ht.gcTrace(gc);
}

bool HeapHashtable::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void MethodEnv::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    MethodEnvProcHolder::gcTrace(gc);
    (void)(avmplus_MethodEnvProcHolder_isExactInterlock != 0);
    gc->TraceLocation(&_scope);
    gc->TraceConservativeLocation(&activationOrMCTable);
#ifdef VMCFG_LOOKUP_CACHE
    gc->TraceLocation(&lookup_cache);
#endif
    gc->TraceLocation(&method);
}

bool MethodEnv::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void MethodEnvProcHolder::gcTrace(MMgc::GC* gc)
{
    (void)gc;

}

bool MethodEnvProcHolder::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void MethodInfo::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    MethodInfoProcHolder::gcTrace(gc);
    (void)(avmplus_MethodInfoProcHolder_isExactInterlock != 0);
    gcTraceHook_MethodInfo(gc);
    _activation.gcTrace(gc);
    _declarer.gcTrace(gc);
#ifdef AVMPLUS_SAMPLER
    gc->TraceLocation(&_methodName);
#endif
    gc->TraceLocation(&_msref);
    gc->TraceLocation(&_pool);
}

bool MethodInfo::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void MethodInfoProcHolder::gcTrace(MMgc::GC* gc)
{
    (void)gc;

}

bool MethodInfoProcHolder::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void MethodSignature::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    QCachedItem::gcTrace(gc);
    (void)(avmplus_QCachedItem_isExactInterlock != 0);
    gcTraceHook_MethodSignature(gc);
    gc->TraceLocation(&_returnTraits);
}

bool MethodSignature::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void NamespaceSet::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    gc->TraceLocations((_namespaces+0), count());
}

bool NamespaceSet::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void NativeErrorClass::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
}

bool NativeErrorClass::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void PIE4XNode::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    E4XNode::gcTrace(gc);
    (void)(avmplus_E4XNode_isExactInterlock != 0);
    gc->TraceLocation(&m_value);
}

bool PIE4XNode::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void PoolObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    gcTraceHook_PoolObject(gc);
    gc->TraceLocation(&_abcStrings);
    _classes.gcTrace(gc);
    gc->TraceLocation(&_code);
#ifdef DEBUGGER
    _method_dmi.gcTrace(gc);
#endif
    _method_name_indices.gcTrace(gc);
    _methods.gcTrace(gc);
    _scripts.gcTrace(gc);
    cpool_double.gcTrace(gc);
    cpool_int.gcTrace(gc);
#ifndef AVMPLUS_64BIT
    cpool_int_atoms.gcTrace(gc);
#endif
    cpool_mn_offsets.gcTrace(gc);
    cpool_ns.gcTrace(gc);
    cpool_ns_set.gcTrace(gc);
    cpool_uint.gcTrace(gc);
#ifndef AVMPLUS_64BIT
    cpool_uint_atoms.gcTrace(gc);
#endif
    gc->TraceLocation(&domain);
    m_namedScriptsList.gcTrace(gc);
    gc->TraceLocation(&m_namedScriptsMap);
    gc->TraceLocation(&m_namedTraits);
    metadata_infos.gcTrace(gc);
#ifdef VMCFG_PRECOMP_NAMES
    gc->TraceLocation(&precompNames);
#endif
}

bool PoolObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void QCache::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    gc->TraceLocation(&m_head);
}

bool QCache::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void QCachedItem::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    gc->TraceLocation(&next);
}

bool QCachedItem::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ScopeChain::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    gc->TraceLocation(&_abcEnv);
    gc->TraceLocation(&_defaultXmlNamespace);
    gc->TraceLocation(&_scopeTraits);
    gc->TraceLocation(&_vtable);
    gc->TraceAtoms((_scopes+0), getSize());
}

bool ScopeChain::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ScopeTypeChain::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    gc->TraceLocation(&_traits);
    gc->TraceLocations((_scopes+0), fullsize);
}

bool ScopeTypeChain::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void ScriptEnv::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    MethodEnv::gcTrace(gc);
    (void)(avmplus_MethodEnv_isExactInterlock != 0);
    gc->TraceLocation(&global);
}

bool ScriptEnv::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

#ifdef DEBUGGER

void SourceFile::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    SourceInfo::gcTrace(gc);
    (void)(avmplus_SourceInfo_isExactInterlock != 0);
    functions.gcTrace(gc);
    gc->TraceLocation(&named);
}

bool SourceFile::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

#endif // DEBUGGER

#ifdef DEBUGGER

void SourceInfo::gcTrace(MMgc::GC* gc)
{
    (void)gc;

}

bool SourceInfo::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

#endif // DEBUGGER

#ifdef DEBUGGER

bool StackTrace::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    if (_xact_cursor == 0) {
        gc->TraceLocation(&stringRep);
    }
    const size_t _xact_work_increment = 2000/sizeof(void*);
    const size_t _xact_work_count = depth;
    if (_xact_cursor * _xact_work_increment >= _xact_work_count)
        return (_xact_cursor == 0);
    size_t _xact_work = _xact_work_increment;
    if ((_xact_cursor + 1) * _xact_work_increment >= _xact_work_count)
        _xact_work = _xact_work_count - (_xact_cursor * _xact_work_increment);
    for ( size_t _xact_iter=0 ; _xact_iter < _xact_work; _xact_iter++ )
        elements[+_xact_iter+(_xact_cursor * _xact_work_increment)].gcTrace(gc);
    return true;
}

void StackTrace::gcTrace(MMgc::GC* gc)
{
    gcTraceSmallAsLarge(gc);
}

#endif // DEBUGGER

void TextE4XNode::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    E4XNode::gcTrace(gc);
    (void)(avmplus_E4XNode_isExactInterlock != 0);
    gc->TraceLocation(&m_value);
}

bool TextE4XNode::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void Toplevel::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    gc->TraceLocation(&_abcEnv);
    gc->TraceLocation(&_builtinClasses);
    gc->TraceLocation(&_mainEntryPoint);
    gc->TraceLocation(&arrayClass);
    gc->TraceLocation(&booleanClass);
    gc->TraceLocation(&classClass);
    gc->TraceLocation(&class_ivtable);
    gc->TraceLocation(&doubleVectorClass);
    gc->TraceLocation(&functionClass);
    gc->TraceLocation(&intClass);
    gc->TraceLocation(&intVectorClass);
    gc->TraceLocation(&methodClosureClass);
    gc->TraceLocation(&namespaceClass);
    gc->TraceLocation(&numberClass);
    gc->TraceLocation(&objectClass);
    gc->TraceLocation(&objectVectorClass);
    gc->TraceLocation(&object_cscope);
    gc->TraceLocation(&object_ivtable);
    gc->TraceLocation(&stringClass);
    gc->TraceLocation(&uintClass);
    gc->TraceLocation(&uintVectorClass);
    gc->TraceLocation(&vectorClass);
    gc->TraceLocation(&vectorobj_cscope);
    gc->TraceLocation(&vectorobj_iscope);
}

bool Toplevel::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void Traits::gcTrace(MMgc::GC* gc)
{
    (void)gc;
#ifdef VMCFG_CACHE_GQCN
    gc->TraceLocation(&_fullname);
#endif
    gc->TraceLocation(&_name);
    gc->TraceLocation(&_ns);
    gc->TraceLocation(&base);
    gc->TraceLocation(&init);
    gc->TraceLocation(&itraits);
    gc->TraceLocation(&m_declaringScope);
    gc->TraceLocation(&m_secondary_supertypes);
    m_slotDestroyInfo.gcTrace(gc);
    gc->TraceLocation(&m_supertype_cache);
    gc->TraceLocation(&m_tbref);
    gc->TraceLocation(&m_tmref);
    gc->TraceLocation(&pool);
    gc->TraceLocation(&protectedNamespace);
    gc->TraceLocations((m_primary_supertypes+0), MAX_PRIMARY_SUPERTYPE);
}

bool Traits::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void TraitsBindings::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    QCachedItem::gcTrace(gc);
    (void)(avmplus_QCachedItem_isExactInterlock != 0);
    gcTraceHook_TraitsBindings(gc);
    gc->TraceLocation(&base);
    gc->TraceLocation(&m_bindings);
    gc->TraceLocation(&owner);
}

bool TraitsBindings::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void TraitsMetadata::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    QCachedItem::gcTrace(gc);
    (void)(avmplus_QCachedItem_isExactInterlock != 0);
    gc->TraceLocation(&base);
    gc->TraceLocation(&residingPool);
}

bool TraitsMetadata::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

void TypedVectorClassBase::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    ClassClosure::gcTrace(gc);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    gc->TraceLocation(&m_typeTraits);
}

bool TypedVectorClassBase::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

bool VTable::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    if (_xact_cursor == 0) {
        gc->TraceLocation(&_toplevel);
        gc->TraceLocation(&base);
#ifdef FEATURE_NANOJIT
        imt.gcTrace(gc);
#endif
        gc->TraceLocation(&init);
        gc->TraceLocation(&ivtable);
        gc->TraceLocation(&traits);
    }
    const size_t _xact_work_increment = 2000/sizeof(void*);
    const size_t _xact_work_count = (MMgc::GC::Size(this) - offsetof(VTable, methods)) / sizeof(MethodEnv*);
    if (_xact_cursor * _xact_work_increment >= _xact_work_count)
        return (_xact_cursor == 0);
    size_t _xact_work = _xact_work_increment;
    if ((_xact_cursor + 1) * _xact_work_increment >= _xact_work_count)
        _xact_work = _xact_work_count - (_xact_cursor * _xact_work_increment);
    gc->TraceLocations((methods+(_xact_cursor * _xact_work_increment)), _xact_work);
    return true;
}

void VTable::gcTrace(MMgc::GC* gc)
{
    gcTraceSmallAsLarge(gc);
}

void VectorBaseObject::gcTrace(MMgc::GC* gc)
{
    (void)gc;
    ScriptObject::gcTrace(gc);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    gc->TraceLocation(&m_vecClass);
}

bool VectorBaseObject::gcTraceLarge(MMgc::GC* gc, size_t _xact_cursor)
{
    return gcTraceLargeAsSmall(gc, _xact_cursor);
}

}
