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

#include "avmplus.h"

namespace avmplus
{
    NullWriter::NullWriter(CodeWriter* coder)
        : coder(coder) {
    }

    NullWriter::~NullWriter()
    {}

    void NullWriter::write(const FrameState* state, const uint8_t* pc, AbcOpcode opcode, Traits *type)
    {
        coder->write(state, pc, opcode, type);
    }

    void NullWriter::writeOp1(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd, Traits *type)
    {
        coder->writeOp1(state, pc, opcode, opd, type);
    }

    void NullWriter::writeOp2(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, uint32_t opd1, uint32_t opd2, Traits* type)
    {
        coder->writeOp2(state, pc, opcode, opd1, opd2, type);
    }

    void NullWriter::writeMethodCall(const FrameState* state, const uint8_t *pc, AbcOpcode opcode, MethodInfo* m, uintptr_t disp_id, uint32_t argc, Traits* type)
    {
        coder->writeMethodCall(state, pc, opcode, m, disp_id, argc, type);
    }

    void NullWriter::writeNip(const FrameState* state, const uint8_t *pc)
    {
        coder->writeNip(state, pc);
    }

    void NullWriter::writeCheckNull(const FrameState* state, uint32_t index)
    {
        coder->writeCheckNull(state, index);
    }

    void NullWriter::writeCoerce(const FrameState* state, uint32_t index, Traits *type)
    {
        coder->writeCoerce(state, index, type);
    }

    void NullWriter::writePrologue(const FrameState* state, const uint8_t *pc, CodegenDriver* dr)
    {
        coder->writePrologue(state, pc, dr);
    }

    void NullWriter::writeEpilogue(const FrameState* state)
    {
        coder->writeEpilogue(state);
    }

    void NullWriter::writeBlockStart(const FrameState* state)
    {
        coder->writeBlockStart(state);
    }

    void NullWriter::writeOpcodeVerified(const FrameState* state, const uint8_t* pc, AbcOpcode opcode)
    {
        coder->writeOpcodeVerified(state, pc, opcode);
    }

    void NullWriter::writeFixExceptionsAndLabels(const FrameState* state, const uint8_t* pc)
    {
        coder->writeFixExceptionsAndLabels(state, pc);
    }

    void NullWriter::cleanup()
    {
        coder->cleanup();
    }

    LookupCacheBuilder::LookupCacheBuilder()
    {
        this->next_cache = 0;
        this->caches = NULL;
        this->num_caches = 0;
    }

    void LookupCacheBuilder::cleanup()
    {
        if (caches) {
            mmfx_delete_array(caches);
            caches = NULL;
        }
    }

    // The cache structure is expected to be small in the normal case, so use a
    // linear list.  For some programs, notably classical JS programs, it may however
    // be larger, and we may need a more sophisticated structure.
    uint32_t LookupCacheBuilder::allocateCacheSlot(uint32_t imm30)
    {
        for ( int i=0 ; i < next_cache ; i++ )
            if (caches[i] == imm30)
                return i;
        if (next_cache == num_caches) {
            uint32_t newcap = num_caches + num_caches/2 + 5; // 0 5 12 23 39 66 ...
            uint32_t* new_cache = mmfx_new_array(uint32_t, newcap);
            if (num_caches > 0) {
                VMPI_memcpy(new_cache, caches, sizeof(uint32_t)*num_caches);
                mmfx_delete_array(caches);
            }
            caches = new_cache;
            num_caches = newcap;
        }
        caches[next_cache] = imm30;
        return next_cache++;
    }

    CodeWriter::~CodeWriter()
    { }

    void CodeWriter::write(const FrameState*, const uint8_t *, AbcOpcode, Traits*)
    { }

    void CodeWriter::writeOp1(const FrameState*, const uint8_t *, AbcOpcode, uint32_t, Traits*)
    { }

    void CodeWriter::writeOp2(const FrameState*, const uint8_t *, AbcOpcode, uint32_t, uint32_t, Traits*)
    { }

    void CodeWriter::writeMethodCall(const FrameState*, const uint8_t *, AbcOpcode, MethodInfo*, uintptr_t, uint32_t, Traits*)
    { }

    void CodeWriter::writeNip(const FrameState*, const uint8_t *)
    { }

    void CodeWriter::writeCheckNull(const FrameState*, uint32_t)
    { }

    void CodeWriter::writeCoerce(const FrameState*, uint32_t, Traits*)
    { }

    void CodeWriter::writePrologue(const FrameState*, const uint8_t *, CodegenDriver*)
    { }

    void CodeWriter::writeEpilogue(const FrameState*)
    { }

    void CodeWriter::writeBlockStart(const FrameState*)
    { }

    void CodeWriter::writeOpcodeVerified(const FrameState*, const uint8_t *, AbcOpcode)
    { }

    void CodeWriter::writeFixExceptionsAndLabels(const FrameState*, const uint8_t *)
    { }

    void CodeWriter::cleanup()
    { }
}
