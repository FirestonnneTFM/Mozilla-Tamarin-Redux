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

#ifndef __avmplus_AbcParser__
#define __avmplus_AbcParser__


namespace avmplus
{
    /**
     * Parser for reading .abc (Actionscript Byte Code) files.
     *
     * ABC content is versioned.  The ABC header stores a version number,
     * the meaning of which is as follows:
     *
     *  46<<16|16   Content recognized by Flash Player "Spicy" and earlier (SWF <= 11)
     *  47<<16|12   Content recognized by Flash Player TBD and earlier (SWF <= 12)
     *  47<<16|13   Content recognized by Flash Player TBD and earlier (SWF <= 13)
     *  ...
     *
     * Starting with the Flash Player after "Spicy", the highest minor ABC version
     * supported always corresponds to the highest SWF version of that
     * player.  Thus every time a Player is shipped we provide the ability to make
     * changes to ABC format and semantics.
     *
     * There is a separate avmfeature for each SWF version starting with SWF12.
     * The feature has to be enabled at build time for that SWF version to be
     * recognized.  The mechanism serves as a check on accidental shipments of
     * code or format changes.
     *
     * A number of flags in the AbcParser structure instance are set based
     * on the version number of the content.  These flags must be checked
     * by the parser and/or verifier and/or interpreter and/or code generator
     * when examining ABC content.  (As a general rule it's expensive to change
     * instruction semantics through versioning, and easier to introduce new
     * instructions, but in principle everything is up for grabs.)  It is *not*
     * appropriate to check the VMCFG_SWFnn flag in general, one should always
     * check the feature flags, which will always be available once introduced.
     *
     * See bugzilla 587977 and dependent/blocking bugs for more information.
     */
    class AbcParser
    {
    public:
        AbcParser(AvmCore* core, ScriptBuffer code,
            Toplevel* toplevel,
            Domain* domain,
            const NativeInitializer* natives);

        /**
         * parse an .abc file
         * @param code
         * @return
         */
        static PoolObject* decodeAbc(AvmCore* core, ScriptBuffer code,
            Toplevel* toplevel,
            Domain* domain,
            const NativeInitializer* natives,
            ApiVersion apiVersion);

        /** return 0 iff the code starts with a known magic number,
          * otherwise an appropriate error code.
          *
          * Store the magic number in *version if version != NULL
          */
        static int canParse(ScriptBuffer code, int* version = NULL);

#if defined(VMCFG_AOT) && defined(DEBUGGER)
        static void addAOTDebugInfo(PoolObject *pool);
#endif

        // If floatSupport is set (introduced in Brannan) then:
        //
        //  - The ABC contains a pool of float values
        //  - OP_pushfloat is an instruction
        //  - OP_coerce_f is an instruction
        //  - The type of OP_add is (Number|String|float) while the type
        //    of OP_subtract, OP_multiply, OP_divide, OP_modulo, OP_negate,
        //    OP_increment, OP_inclocal, OP_decrement, and OP_declocal is
        //    (Number|float).  In older content they were (Number|String)
        //    and (Number) respectively.
        //
        // (Subject to revision)

        /*const*/ unsigned floatSupport:1;

        // If float4Support is set (introduced in Brannan) then:
        //
        // - TBD

        /*const*/ unsigned float4Support:1;
        
    protected:
        PoolObject* parse(ApiVersion apiVersion);
        MethodInfo* resolveMethodInfo(uint32_t index) const;

        #if defined(VMCFG_AOT) || defined(AVMPLUS_VERBOSE)
        void parseTypeName(const uint8_t* &p, Multiname& m) const;
        #endif

        Namespacep parseNsRef(const uint8_t* &pc) const;
        Stringp resolveUtf8(uint32_t index) const;
        Stringp parseName(const uint8_t* &pc) const;
        uint32_t resolveBindingName(const uint8_t*& pc, Multiname& m) const;
        void parseMethodInfos();
        void parseMetadataInfos();
        bool parseInstanceInfos();
        void parseClassInfos();
        bool parseScriptInfos();
        void parseMethodBodies();
        void parseCpool(ApiVersion apiVersion);
        Traits* parseTraits(uint16_t sizeofInstance,
                            uint16_t offsetofSlots,
                            Traits* base,
                            Namespacep ns,
                            Stringp name,
                            MethodInfo* script,
                            TraitsPosPtr traitsPos,
                            TraitsPosType posType,
                            Namespacep protectedNamespace,
                            bool makeFinal=true);

        /**
         * add script to VM-wide table
         */
        void addNamedScript(NamespaceSetp nss, Stringp name, MethodInfo* script);

        /**
         * Adds traits to the VM-wide traits table, for types
         * that can be accessed from multiple abc's.
         * @param name The name of the class
         * @param ns The namespace of the class
         * @param itraits The instance traits of the class
         */
        void addNamedTraits(Namespacep ns, Stringp name, Traits* itraits);
        void addNamedTraits(NamespaceSetp nss, Stringp name, Traits* itraits);

        /**
         * reads in 8 bytes in little endian order and stores in
         * memory as an ieee double, doing endian swapping as needed
         */
        double readDouble(const uint8_t* &p) const;

        /**
         * Reads in 2 bytes and turns them into a 16 bit number.  Always reads in 2 bytes.  Currently
         * only used for version number of the ABC file and for version 11 support.
         */
        int readU16(const uint8_t* p) const;

        /**
         * Read in a 32 bit number that is encoded with a variable number of bytes.  The value can
         * take up 1-5 bytes depending on its value.  0-127 takes 1 byte, 128-16383 takes 2 bytes, etc.
         * The scheme is that if the current uint8_t has the high bit set, then the following uint8_t is also
         * part of the value.
         *
         * Returns the value, and the 2nd argument is set to the number of bytes that were read to get that
         * value.
         */
        int readS32(const uint8_t *&p) const;

        uint32_t readU30(const uint8_t*& p) const;

    // ------------------------ DATA SECTION BEGIN
    private:
        ScriptBuffer                code;
        GCList<Traits>              instances;
        Toplevel* const             toplevel;
        Domain* const               domain;
        AvmCore*                    core;
        PoolObject*                 pool;
        const uint8_t*              pos;
        const NativeInitializer*    natives;
        uint8_t*                    abcStart;
        uint8_t*                    abcEnd; // one past the end, actually
        RCList<String>              metaNames;
        int32_t                     version;
        uint32_t                    classCount;
    // ------------------------ DATA SECTION END
    };

}

#endif // __avmplus_AbcParser__
