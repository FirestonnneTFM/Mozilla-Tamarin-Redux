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
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
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

#ifndef __avmplus_AbcEnv__
#define __avmplus_AbcEnv__


namespace avmplus
{
    // runtime info associated with a pool
    class GC_CPP_EXACT(AbcEnv, MMgc::GCFinalizedObject)
    {
        friend class DomainMgr;

        #ifdef VMCFG_NANOJIT
        friend class CodegenLIR;
        friend class MopsRangeCheckFilter;
        #endif

        AbcEnv(PoolObject* _pool, CodeContext * _codeContext);
        
    public:
        static AbcEnv* create(MMgc::GC* gc, PoolObject* builtinPool, CodeContext* builtinCodeContext);
        
        ~AbcEnv();

        AvmCore* core() const;
        PoolObject* pool() const;
        DomainEnv* domainEnv() const;
        CodeContext* codeContext() const;

        MethodEnv* getMethod(uint32_t i) const;
        void setMethod(uint32_t i, MethodEnv* env);

#ifdef DEBUGGER
        uint64_t& invocationCount(uint32_t i);
#endif

        static size_t calcExtra(PoolObject* pool);

    // ------------------------ DATA SECTION BEGIN
    GC_DATA_BEGIN(AbcEnv)
        
    private:
        GCList<ScriptEnv>           GC_STRUCTURE( m_namedScriptEnvsList ); // list of ScriptEnvs, corresponds to pool->m_namedScriptsList
    private:
        PoolObject* const           GC_POINTER( m_pool );
        DomainEnv* const            GC_POINTER( m_domainEnv );           // Same as m_codeContext->domainEnv(); replicated here solely for efficiency in jitted code
        CodeContext* const          GC_POINTER( m_codeContext );
#ifdef DEBUGGER
        DWB(uint64_t*)              GC_POINTER_IFDEF( m_invocationCounts, DEBUGGER );    // actual size will hold pool->methodCount methods, only allocated if debugger exists
#endif
        AvmCore* const              m_core;
        MethodEnv*                  GC_POINTERS(m_methods, 1, "m_pool->methodCount()");  // actual size will hold pool->methodCount methods
        
    GC_DATA_END(AbcEnv)
    // ------------------------ DATA SECTION END
    };

}

#endif // __avmplus_AbcEnv__
