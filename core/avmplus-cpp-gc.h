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
bool AbcEnv::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    if (_xact_cursor == 0) {
        gc->TraceLocation(&m_codeContext);
        gc->TraceLocation(&m_domainEnv);
#ifdef DEBUGGER
        gc->TraceLocation(&m_invocationCounts);
#endif
        gc->TraceLocation(&m_pool);
    }
    const size_t _xact_work_increment = 2000/sizeof(void*);
    const size_t _xact_work_count = m_pool ? m_pool->methodCount() : 0;
    if (_xact_cursor * _xact_work_increment >= _xact_work_count)
        return false;
    size_t _xact_work = _xact_work_increment;
    bool _xact_more = true;
    if ((_xact_cursor + 1) * _xact_work_increment >= _xact_work_count)
    {
        _xact_work = _xact_work_count - (_xact_cursor * _xact_work_increment);
        _xact_more = false;
    }
    gc->TraceLocations((m_methods+(_xact_cursor * _xact_work_increment)), _xact_work);
    return _xact_more;
}

#ifdef DEBUGGER

bool AbcFile::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    AbcInfo::gcTrace(gc, 0);
    (void)(avmplus_AbcInfo_isExactInterlock != 0);
    source.gcTrace(gc);
    gc->TraceLocation(&sourcemap);
    return false;
}

#endif // DEBUGGER

#ifdef DEBUGGER

bool AbcInfo::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;

    return false;
}

#endif // DEBUGGER

bool AttributeE4XNode::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    E4XNode::gcTrace(gc, 0);
    (void)(avmplus_E4XNode_isExactInterlock != 0);
    gc->TraceLocation(&m_value);
    return false;
}

bool CDATAE4XNode::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    E4XNode::gcTrace(gc, 0);
    (void)(avmplus_E4XNode_isExactInterlock != 0);
    gc->TraceLocation(&m_value);
    return false;
}

bool CommentE4XNode::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    E4XNode::gcTrace(gc, 0);
    (void)(avmplus_E4XNode_isExactInterlock != 0);
    gc->TraceLocation(&m_value);
    return false;
}

#ifdef DEBUGGER

bool Debugger::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    abcList.gcTrace(gc);
    gc->TraceLocation(&trace_callback);
    return false;
}

#endif // DEBUGGER

#ifdef DEBUGGER

bool DebuggerMethodInfo::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    gc->TraceLocation(&file);
    gc->TraceLocations((localNames+0), local_count);
    return false;
}

#endif // DEBUGGER

bool Domain::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    gc->TraceLocation(&m_cachedScripts);
    gc->TraceLocation(&m_cachedTraits);
    gc->TraceLocation(&m_loadedScripts);
    gc->TraceLocation(&m_loadedTraits);
    gc->TraceLocation(&m_parameterizedTypes);
    gc->TraceLocations((m_bases+0), m_baseCount);
    return false;
}

bool DomainEnv::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    gc->TraceLocation(&m_domain);
    gc->TraceLocation(&m_globalMemoryProviderObject);
    gc->TraceLocation(&m_scriptEnvMap);
    gc->TraceLocation(&m_toplevel);
    gc->TraceLocations((m_bases+0), m_baseCount);
    return false;
}

bool E4XNode::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    gc->TraceLocation(&m_nameOrAux);
    gc->TraceLocation(&m_parent);
    return false;
}

bool E4XNodeAux::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    gc->TraceLocation(&m_name);
    gc->TraceLocation(&m_notification);
    gc->TraceLocation(&m_ns);
    return false;
}

bool ElementE4XNode::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    E4XNode::gcTrace(gc, 0);
    (void)(avmplus_E4XNode_isExactInterlock != 0);
    gc->TraceLocation(&m_attributes);
    gc->TraceLocation(&m_children);
    gc->TraceLocation(&m_namespaces);
    return false;
}

bool ExceptionHandlerTable::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    const size_t _xact_work_increment = 2000/sizeof(void*);
    const size_t _xact_work_count = exception_count;
    if (_xact_cursor * _xact_work_increment >= _xact_work_count)
        return false;
    size_t _xact_work = _xact_work_increment;
    bool _xact_more = true;
    if ((_xact_cursor + 1) * _xact_work_increment >= _xact_work_count)
    {
        _xact_work = _xact_work_count - (_xact_cursor * _xact_work_increment);
        _xact_more = false;
    }
    for ( size_t _xact_iter=0 ; _xact_iter < _xact_work; _xact_iter++ )
        exceptions[+_xact_iter+(_xact_cursor * _xact_work_increment)].gcTrace(gc);
    return _xact_more;
}

bool FunctionEnv::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    MethodEnv::gcTrace(gc, 0);
    (void)(avmplus_MethodEnv_isExactInterlock != 0);
    gc->TraceLocation(&closure);
    return false;
}

bool HeapHashtable::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    ht.gcTrace(gc);
    return false;
}

bool MethodEnv::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    MethodEnvProcHolder::gcTrace(gc, 0);
    (void)(avmplus_MethodEnvProcHolder_isExactInterlock != 0);
    gc->TraceLocation(&_scope);
    gc->TraceConservativeLocation(&activationOrMCTable);
#ifdef VMCFG_LOOKUP_CACHE
    gc->TraceLocation(&lookup_cache);
#endif
    gc->TraceLocation(&method);
    return false;
}

bool MethodEnvProcHolder::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;

    return false;
}

bool MethodInfo::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    MethodInfoProcHolder::gcTrace(gc, 0);
    (void)(avmplus_MethodInfoProcHolder_isExactInterlock != 0);
    gcTraceHook_MethodInfo(gc);
    _activation.gcTrace(gc);
    _declarer.gcTrace(gc);
#ifdef AVMPLUS_SAMPLER
    gc->TraceLocation(&_methodName);
#endif
    gc->TraceLocation(&_msref);
    gc->TraceLocation(&_pool);
    return false;
}

bool MethodInfoProcHolder::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;

    return false;
}

bool MethodSignature::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    QCachedItem::gcTrace(gc, 0);
    (void)(avmplus_QCachedItem_isExactInterlock != 0);
    gcTraceHook_MethodSignature(gc);
    gc->TraceLocation(&_returnTraits);
    return false;
}

bool NamespaceSet::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    gc->TraceLocations((_namespaces+0), count());
    return false;
}

bool NativeErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}

bool PIE4XNode::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    E4XNode::gcTrace(gc, 0);
    (void)(avmplus_E4XNode_isExactInterlock != 0);
    gc->TraceLocation(&m_value);
    return false;
}

bool PoolObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
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
    gc->TraceLocation(&m_cachedScripts);
    gc->TraceLocation(&m_cachedTraits);
    gc->TraceLocation(&m_loadedScripts);
    gc->TraceLocation(&m_loadedTraits);
    metadata_infos.gcTrace(gc);
    gc->TraceLocation(&precompNames);
    return false;
}

bool QCache::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    gc->TraceLocation(&m_head);
    return false;
}

bool QCachedItem::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    gc->TraceLocation(&next);
    return false;
}

bool ScopeChain::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    gc->TraceLocation(&_abcEnv);
    gc->TraceLocation(&_defaultXmlNamespace);
    gc->TraceLocation(&_scopeTraits);
    gc->TraceLocation(&_vtable);
    gc->TraceAtoms((_scopes+0), getSize());
    return false;
}

bool ScopeTypeChain::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    gc->TraceLocation(&_traits);
    gc->TraceLocations((_scopes+0), fullsize);
    return false;
}

bool ScriptEnv::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    MethodEnv::gcTrace(gc, 0);
    (void)(avmplus_MethodEnv_isExactInterlock != 0);
    gc->TraceLocation(&global);
    return false;
}

bool ScriptEnvMap::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    ht.gcTrace(gc);
    return false;
}

#ifdef DEBUGGER

bool SourceFile::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    SourceInfo::gcTrace(gc, 0);
    (void)(avmplus_SourceInfo_isExactInterlock != 0);
    functions.gcTrace(gc);
    gc->TraceLocation(&named);
    return false;
}

#endif // DEBUGGER

#ifdef DEBUGGER

bool SourceInfo::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;

    return false;
}

#endif // DEBUGGER

#ifdef DEBUGGER

bool StackTrace::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    if (_xact_cursor == 0) {
        gc->TraceLocation(&stringRep);
    }
    const size_t _xact_work_increment = 2000/sizeof(void*);
    const size_t _xact_work_count = depth;
    if (_xact_cursor * _xact_work_increment >= _xact_work_count)
        return false;
    size_t _xact_work = _xact_work_increment;
    bool _xact_more = true;
    if ((_xact_cursor + 1) * _xact_work_increment >= _xact_work_count)
    {
        _xact_work = _xact_work_count - (_xact_cursor * _xact_work_increment);
        _xact_more = false;
    }
    for ( size_t _xact_iter=0 ; _xact_iter < _xact_work; _xact_iter++ )
        elements[+_xact_iter+(_xact_cursor * _xact_work_increment)].gcTrace(gc);
    return _xact_more;
}

#endif // DEBUGGER

bool TextE4XNode::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    E4XNode::gcTrace(gc, 0);
    (void)(avmplus_E4XNode_isExactInterlock != 0);
    gc->TraceLocation(&m_value);
    return false;
}

bool Toplevel::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
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
    return false;
}

bool Traits::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
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
    return false;
}

bool TraitsBindings::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    QCachedItem::gcTrace(gc, 0);
    (void)(avmplus_QCachedItem_isExactInterlock != 0);
    gcTraceHook_TraitsBindings(gc);
    gc->TraceLocation(&base);
    gc->TraceLocation(&m_bindings);
    gc->TraceLocation(&owner);
    return false;
}

bool TraitsMetadata::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    QCachedItem::gcTrace(gc, 0);
    (void)(avmplus_QCachedItem_isExactInterlock != 0);
    gc->TraceLocation(&base);
    gc->TraceLocation(&residingPool);
    return false;
}

bool TypedVectorClassBase::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    gc->TraceLocation(&m_typeTraits);
    return false;
}

bool VTable::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
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
        return false;
    size_t _xact_work = _xact_work_increment;
    bool _xact_more = true;
    if ((_xact_cursor + 1) * _xact_work_increment >= _xact_work_count)
    {
        _xact_work = _xact_work_count - (_xact_cursor * _xact_work_increment);
        _xact_more = false;
    }
    gc->TraceLocations((methods+(_xact_cursor * _xact_work_increment)), _xact_work);
    return _xact_more;
}

bool VectorBaseObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    gc->TraceLocation(&m_vecClass);
    return false;
}

bool WeakMethodClosure::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    MethodClosure::gcTrace(gc, 0);
    (void)(avmplus_MethodClosure_isExactInterlock != 0);
    gc->TraceLocation(&m_weakSavedThis);
    return false;
}

}
