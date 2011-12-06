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

#ifndef __avmplus_Coder__
#define __avmplus_Coder__

namespace avmplus
{
    /**
     * CodegenDriver defines the interface by which CodeWriters may call back
     * to their top-level driver, e.g. CodegenLIR calling back to Verifier.
     */
    class CodegenDriver {
    public:
        virtual ~CodegenDriver() {}

        virtual const uint8_t* getTryFrom() const = 0;
        virtual const uint8_t* getTryTo() const = 0;
        virtual bool hasFrameState(const uint8_t* pc) const = 0;
        virtual int getBlockCount() const = 0;
        virtual bool hasReachableExceptions() const = 0;
        virtual FrameState* getFrameState(const uint8_t* pc) const = 0;
    };

    class CodeWriter {
    public:

        CodeWriter();
        virtual ~CodeWriter();

        virtual void write(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, Traits *type);
        virtual void writeOp1(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd1, Traits *type);
        virtual void writeOp2(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd1, uint32_t opd2, Traits* type);
        virtual void writeMethodCall(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, MethodInfo*, uintptr_t disp_id, uint32_t argc, Traits* type);
        virtual void writeNip(const FrameState* state, const uint8_t *pc, uint8_t offset);
        virtual void writeCheckNull(const FrameState* state, uint32_t index);
        virtual void writeCoerce(const FrameState* state, uint32_t index, Traits* type);
        virtual void writeCoerceToNumeric(const FrameState* state, uint32_t index);
        virtual void writeCoerceToFloat4(const FrameState* state, uint32_t index1, uint32_t index2, uint32_t index3, uint32_t index4);
        virtual void writePrologue(const FrameState* state, const uint8_t *pc, CodegenDriver*);
        virtual void writeEpilogue(const FrameState* state);
        virtual void writeBlockStart(const FrameState* state);
        virtual void writeOpcodeVerified(const FrameState* state, const uint8_t *pc, AbcOpcode opcode);
        virtual void writeFixExceptionsAndLabels(const FrameState* state, const uint8_t *pc);
        virtual void cleanup();

        // convenience functions
        void write(const FrameState* state, const uint8_t *pc, AbcOpcode opcode);
        void writeOp1(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd1);
        void writeOp2(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd1, uint32_t opd2);
    };

#if defined FEATURE_TEEWRITER
    class TeeWriter : public CodeWriter {
    public:
        CodeWriter* coder1;  // deleted elsewhere
        CodeWriter* coder2;

        TeeWriter(CodeWriter* coder1, CodeWriter* coder2);
        ~TeeWriter();
        void write(const FrameState* state, const uint8_t* pc, AbcOpcode opcode, Traits *type);
        void writeOp1(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd1, Traits* type);
        void writeOp2(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd1, uint32_t opd2, Traits* type);
        void writeMethodCall(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, MethodInfo*, uintptr_t disp_id, uint32_t argc, Traits* type);
        void writeNip(const FrameState* state, const uint8_t *pc, uint8_t offset);
        void writeCheckNull(const FrameState* state, uint32_t index);
        void writeCoerce(const FrameState* state, uint32_t index, Traits *type);
        void writeCoerceToNumeric(const FrameState* state, uint32_t index);
        void writeCoerceToFloat4(const FrameState* state, uint32_t index1, uint32_t index2, uint32_t index3, uint32_t index4);
        void writePrologue(const FrameState* state, const uint8_t *pc, CodegenDriver*);
        void writeEpilogue(const FrameState* state);
        void writeBlockStart(const FrameState* state);
        void writeOpcodeVerified(const FrameState* state, const uint8_t *pc, AbcOpcode opcode);
        void writeFixExceptionsAndLabels(const FrameState* state, const uint8_t *pc);
        void cleanup();
    };
#endif // FEATURE_TEEWRITER

    class NullWriter : public CodeWriter {
    public:
        CodeWriter* coder;       // the next leg of the pipeline

        NullWriter(CodeWriter* coder);
        ~NullWriter();
        void write(const FrameState* state, const uint8_t* pc, AbcOpcode opcode, Traits *type);
        void writeOp1(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd1, Traits *type);
        void writeOp2(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd1, uint32_t opd2, Traits* type);
        void writeMethodCall(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, MethodInfo*, uintptr_t disp_id, uint32_t argc, Traits* type);
        void writeNip(const FrameState* state, const uint8_t *pc, uint8_t offset);
        void writeCheckNull(const FrameState* state, uint32_t index);
        void writeCoerceToNumeric(const FrameState* state, uint32_t index);
        void writeCoerceToFloat4(const FrameState* state, uint32_t index1, uint32_t index2, uint32_t index3, uint32_t index4);
        void writeCoerce(const FrameState* state, uint32_t index, Traits *type);
        void writePrologue(const FrameState* state, const uint8_t *pc, CodegenDriver*);
        void writeEpilogue(const FrameState* state);
        void writeBlockStart(const FrameState* state);
        void writeOpcodeVerified(const FrameState* state, const uint8_t *pc, AbcOpcode opcode);
        void writeFixExceptionsAndLabels(const FrameState* state, const uint8_t *pc);
        void cleanup();
    };

    /**
     * helper class for building the layout of a lookup cache, used during
     * jit compilation or wordcode translation.
     */
    class LookupCacheBuilder
    {
        // entry i has an imm30 value that represents the multiname whose entry in the MethodEnv's lookup cache is 'i'
        uint32_t* caches;

        // number of entries in 'caches'
        int num_caches;

    public:
        // next free entry in 'caches'
        int next_cache;

    public:
        LookupCacheBuilder();

        /** allocate a new cache slot or reuse an existing one with the same imm30 */
        uint32_t allocateCacheSlot(uint32_t imm30);

        void cleanup();
    };
}
#endif  /* __avmplus_Coder__ */
