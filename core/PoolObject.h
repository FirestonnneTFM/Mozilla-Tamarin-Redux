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

#ifdef VMCFG_PRECOMP_NAMES

    /* This should not be a root because it can be large and root scanning is atomic,
     * leading to uncontrollable GC pauses for large roots.
     *
     * The use of HeapMultiname guarantees correct write barrier behavior for the parts
     * of multinames.  The object itself is anchored in a PoolObject.
     */
    class PrecomputedMultinames : public MMgc::GCFinalizedObject
    {
    public:
        PrecomputedMultinames(PoolObject* pool);
        ~PrecomputedMultinames();
        uint32_t nNames;                        // Number of elements
        HeapMultiname multinames[1];            // Allocated size is MAX(1,nName)
    };

#endif  // VMCFG_PRECOMP_NAMES

    /**
     * The PoolObject class is a container for the pool of resources
     * decoded from an ABC file: the constant pool, the methods
     * defined in the ABC, the classes defined in the ABC, and so on.
     */
    class PoolObject : public MMgc::GCFinalizedObject
    {
        friend class AbcParser;

    public:
        AvmCore *core;

        int32_t getAPI();

        /** constants */
        List<int32_t> cpool_int;
        List<uint32_t> cpool_uint;
        List<double*, LIST_GCObjects> cpool_double; // explicitly specify LIST_GCObject b/c these are GC-allocated ptrs
        List<Namespacep> cpool_ns;
        List<NamespaceSetp> cpool_ns_set;

#ifndef AVMPLUS_64BIT
        // lists to keep int/uint atoms "sticky".
        // @todo this can/should go away when we convert to 64-bit Box atoms.
        List<Atom, LIST_GCObjects> cpool_int_atoms;
        List<Atom, LIST_GCObjects> cpool_uint_atoms;
#endif

        List<uint32_t> cpool_mn_offsets;

        /** metadata -- ptrs into ABC, not gc-allocated */
        List<const uint8_t*> metadata_infos;

        /** domain */
        DWB(Domain*) domain;

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

#ifdef VMCFG_PRECOMP_NAMES
    private:
        DWB(PrecomputedMultinames*) precompNames;   // a GCFinalizedObject
    public:
        void initPrecomputedMultinames();
        const Multiname* precomputedMultiname(int32_t index);
#endif

        #ifdef VMCFG_NANOJIT
        CodeMgr* codeMgr;
        #endif

        PoolObject(AvmCore* core, ScriptBuffer& sb, const uint8_t* startpos, uint32_t api);
        ~PoolObject();

        // search metadata record at meta_pos for name, return true if present
        bool hasMetadataName(const uint8_t* meta_pos, const String* name);
        const uint8_t* getMetadataInfoPos(uint32_t index);

        /** deferred parsing */
        void parseMultiname(const uint8_t *pos, Multiname& m) const;

        Traits* resolveTypeName(uint32_t index, const Toplevel* toplevel, bool allowVoid=false);
        Traits* resolveTypeName(const byte*& pc, const Toplevel* toplevel, bool allowVoid=false);

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
#if VMCFG_METHOD_NAMES
        Stringp getMethodInfoName(uint32_t i);
#endif

        void dynamicizeStrings();

    private:
        friend class DomainMgr;
        DWB(MultinameHashtable*)                    m_namedTraits;
        DWB(MultinameHashtable*)                    m_namedScriptsMap;
        List<MethodInfo*>                           m_namedScriptsList;           // list of MethodInfo* for the scripts

    private:
        union ConstantStringData
        {
            Stringp     str;
            const uint8_t* abcPtr;
        };
        class ConstantStrings : public MMgc::GCRoot
        {
        public:
            ConstantStrings(MMgc::GC* gc);
            ~ConstantStrings();
            void setup(uint32_t size);
            ConstantStringData* data;
        };
        DWB(ScriptBufferImpl*)                      _code;
        const uint8_t * const                       _abcStart;
        // start of static ABC string data
        const uint8_t *                             _abcStringStart;
        // points behind end of ABC string data - see AbcParser.cpp
        const uint8_t *                             _abcStringEnd;
        ConstantStrings                             _abcStrings;
        List<Traits*, LIST_GCObjects>               _classes;
        List<Traits*, LIST_GCObjects>               _scripts;
        List<MethodInfo*, LIST_GCObjects>           _methods;
#ifdef DEBUGGER
        List<DebuggerMethodInfo*, LIST_GCObjects>   _method_dmi;
#endif
#if VMCFG_METHOD_NAMES
        // only allocated & populated if core->config.methodName is true...
        // if positive, an index into cpool_string; if negative, an index into cpool_mn
        // (always safe because those indices are limited to 30 bits)
        List<int32_t, LIST_NonGCObjects>            _method_name_indices;
#endif
                void                                setupConstantStrings(uint32_t count);
        uint32_t api;

    public:
    #ifdef AVMPLUS_VERBOSE
        bool isVerbose(uint32_t flag);
        uint32_t                    verbose_vb;
    #endif
        // @todo, privatize & make into bitfield (requires API churn)
        bool                        isBuiltin;  // true if this pool is baked into the player.  used to control whether callees will set their context.

    #ifdef VMCFG_AOT
        const AOTInfo* aotInfo;
    #endif
    };
}

#endif /* __avmplus_PoolObject__ */
