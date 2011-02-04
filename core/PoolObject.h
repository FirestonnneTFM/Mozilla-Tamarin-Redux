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

#ifndef __avmplus_PoolObject__
#define __avmplus_PoolObject__


namespace avmplus
{
#ifdef VMCFG_NANOJIT
    class CodeMgr;
#endif

    // This is intended to be exactly the size of a double in memory.
    // (We use compile-time assertions to verify this.)
    class GCDouble : public MMgc::GCObject
    {
    public:
        double value;
    };

    // Used within ConstantStringContainer
    union ConstantStringData
    {
        Stringp     str;
        const uint8_t* abcPtr;
    };
    
    // Used within PoolObject.
    //
    // The macros for exact tracing fail us here: The interpretation
    // of each element depends on data from the pool, so we can't treat this
    // with GC_STRUCTURES.  Instead there's a hand-written tracer.  No doubt
    // we could concoct a mechanism to handle this case but we should only
    // do so if we see more instances of it.
    
    class ConstantStringContainer : public MMgc::GCTraceableObject
    {
    private:
        ConstantStringContainer(PoolObject* pool) : pool(pool) {}
        
    public:
        REALLY_INLINE static ConstantStringContainer* create(MMgc::GC* gc, size_t extra, PoolObject* pool)
        {
            return new (gc, MMgc::kExact, extra) ConstantStringContainer(pool);
        }

        virtual bool gcTrace(MMgc::GC* gc, size_t cursor);
        
        PoolObject* const pool;
        
        // The real length is max(1,pool->constantStringCount).
        ConstantStringData data[1];
    };

    /**
     * The PoolObject class is a container for the pool of resources
     * decoded from an ABC file: the constant pool, the methods
     * defined in the ABC, the classes defined in the ABC, and so on.
     */
    class GC_CPP_EXACT_WITH_HOOK(PoolObject, MMgc::GCFinalizedObject)
    {
        friend class AbcParser;
        friend class ConstantStringContainer;

        PoolObject(AvmCore* core, ScriptBuffer& sb, const uint8_t* startpos, ApiVersion apiVersion);
        
    public:
        static PoolObject* create(AvmCore* core, ScriptBuffer& sb, const uint8_t* startpos, ApiVersion apiVersion);

        ~PoolObject();

        void gcTraceHook_PoolObject(MMgc::GC* gc);
 
        int32_t getAPI();

        // TODO - group the data members of this class, it's a mess.
        
        GC_DATA_BEGIN(PoolObject)

        AvmCore *core;

        ApiVersion getApiVersion();

        /** constants */
        DataList<int32_t>       GC_STRUCTURE(cpool_int);
        DataList<uint32_t>      GC_STRUCTURE(cpool_uint);
        GCList<GCDouble>        GC_STRUCTURE(cpool_double);
        RCList<Namespace>       GC_STRUCTURE(cpool_ns);
        GCList<NamespaceSet>    GC_STRUCTURE(cpool_ns_set);

#ifndef AVMPLUS_64BIT
        // lists to keep int/uint atoms "sticky".
        // @todo this can/should go away when we convert to 64-bit Box atoms.
        AtomList GC_STRUCTURE_IFNDEF(cpool_int_atoms, AVMPLUS_64BIT);
        AtomList GC_STRUCTURE_IFNDEF(cpool_uint_atoms, AVMPLUS_64BIT);
#endif

        DataList<uint32_t> GC_STRUCTURE(cpool_mn_offsets);

        /** metadata -- ptrs into ABC, not gc-allocated */
        UnmanagedPointerList<const uint8_t*> GC_STRUCTURE(metadata_infos);

        /** domain */
        DWB(Domain*) GC_POINTER(domain);

        /** # of elements in metadata array */
        uint32_t metadataCount;

        /** # of elements in cpool array */
        uint32_t constantCount;
        uint32_t constantIntCount;
        uint32_t constantUIntCount;
        uint32_t constantDoubleCount;
        uint32_t constantStringCount;
        uint32_t constantNsCount;
        uint32_t constantNsSetCount;

    private:
        DWB(ExactStructContainer<HeapMultiname>*) GC_POINTER(precompNames);   // a GCFinalizedObject
    public:
        void initPrecomputedMultinames();
        const Multiname* precomputedMultiname(int32_t index);
        
        static void destroyPrecomputedMultinames(ExactStructContainer<HeapMultiname>* self);


        #ifdef VMCFG_NANOJIT
        CodeMgr* codeMgr;   // Traced by gcTraceHook, above
        #endif

        // search metadata record at meta_pos for name, return true if present
        bool hasMetadataName(const uint8_t* meta_pos, const String* name);
        const uint8_t* getMetadataInfoPos(uint32_t index);

        /** deferred parsing */
        void parseMultiname(const uint8_t *pos, Multiname& m) const;

        Traits* resolveTypeName(uint32_t index, const Toplevel* toplevel, bool allowVoid=false);
        Traits* resolveTypeName(const uint8_t*& pc, const Toplevel* toplevel, bool allowVoid=false);

        void resolveBindingNameNoCheck(uint32_t index, Multiname &m, const Toplevel* toplevel) const;
        void resolveBindingNameNoCheck(const uint8_t* &p, Multiname &m, const Toplevel* toplevel) const;

        Traits* resolveParameterizedType(const Toplevel* toplevel, Traits* base, Traits* type_param) const;

        void parseMultiname(Multiname& m, uint32_t index) const;

        Namespacep getNamespace(int32_t index) const;
        NamespaceSetp getNamespaceSet(int32_t index) const;
        bool hasString(int32_t index) const;
        Stringp getString(int32_t index) const;

        Atom getLegalDefaultValue(const Toplevel* toplevel, uint32_t index, CPoolKind kind, Traits* t);
        static bool isLegalDefaultValue(BuiltinType bt, Atom value);

        int32_t version;

        ScriptBuffer code();
        bool isCodePointer(const uint8_t* pos);

    public:
        uint32_t classCount() const;
        Traits* getClassTraits(uint32_t i) const;

        uint32_t scriptCount() const;
        Traits* getScriptTraits(uint32_t i) const;

        uint32_t methodCount() const;
        MethodInfo* getMethodInfo(uint32_t i) const;
#ifdef DEBUGGER
        DebuggerMethodInfo* getDebuggerMethodInfo(uint32_t i) const;
#endif
        Stringp getMethodInfoName(uint32_t i);

        void dynamicizeStrings();

    private:
        friend class DomainMgr;
        // "loaded" Traits/Scripts are the Traits/ScriptEnvs that are actually
        // defined in this Domain. "cached" Traits/Scripts are the ones that
        // actually should be used for a given name lookup; the cached versions
        // take precedence over the loaded ones (on a freeze-on-first-use basis)
        // to ensure that the types associated with a name can't change as new
        // Domains are loaded. See DomainMgr for more info.
        DWB(MultinameTraitsHashtable*)              GC_POINTER(m_loadedTraits);
        DWB(MultinameTraitsHashtable*)              GC_POINTER(m_cachedTraits);
        DWB(MultinameMethodInfoHashtable*)          GC_POINTER(m_loadedScripts);
        DWB(MultinameMethodInfoHashtable*)          GC_POINTER(m_cachedScripts);

    private:
        DWB(ScriptBufferImpl*)                      GC_POINTER(_code);
        const uint8_t * const                       _abcStart;
        // start of static ABC string data
        const uint8_t *                             _abcStringStart;
        // points behind end of ABC string data - see AbcParser.cpp
        const uint8_t *                             _abcStringEnd;
        DWB(ConstantStringContainer*)               GC_POINTER(_abcStrings);                // The length is constantStringCount
        GCList<Traits>                              GC_STRUCTURE(_classes);
        GCList<Traits>                              GC_STRUCTURE(_scripts);
        GCList<MethodInfo>                          GC_STRUCTURE(_methods);
#ifdef DEBUGGER
        GCList<DebuggerMethodInfo>                  GC_STRUCTURE_IFDEF(_method_dmi, DEBUGGER);
#endif
        // Only allocated & populated if core->config.methodName is true.
        // Indexed by MethodInfo::_method_id, if the value is positive, it's an index into cpool_string;
        // if negative, an index into cpool_mn.
        // Always safe because those indices are limited to 30 bits.
        DataList<int32_t>                           GC_STRUCTURE(_method_name_indices);
                void                                setupConstantStrings(uint32_t count);
        ApiVersion const                            _apiVersion;

    public:
    #ifdef AVMPLUS_VERBOSE
        bool isVerbose(uint32_t flag);
        uint32_t                    verbose_vb;
    #endif
        // @todo, privatize & make into bitfield (requires API churn)
        bool                        isBuiltin;  // true if this pool is baked into the player.  used to control whether callees will set their context.

    #ifdef VMCFG_AOT
        const AOTInfo* aotInfo; // points to non-gc memory
        MMgc::GCRoot *aotRoot;
    #endif
        
        GC_DATA_END(PoolObject)
    };
}

#endif /* __avmplus_PoolObject__ */
